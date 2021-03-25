#include <bits/stdc++.h>

using namespace std;

struct People {
    char name[10];
    int age;
    int netWorth;
};

bool cmp(People a, People b) {
    if (a.netWorth != b.netWorth)
        return a.netWorth > b.netWorth;
    else if (a.age != b.age)
        return a.age < b.age;
    else
        return (strcmp(a.name, b.name) < 0);
}

int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    vector<People> v(n);
    for (int i = 0; i < n; ++i)
        scanf("%s%d%d", v[i].name, &v[i].age, &v[i].netWorth);
    sort(v.begin(), v.end(), cmp);
    vector<People> temp;
    vector<int> nums(205, 0);
    for (int i = 0; i < n; ++i) {
        if (nums[v[i].age] < 100) {
            temp.push_back(v[i]);
            nums[v[i].age]++;
        }
    }
    int m, Amin, Amax, cnt = 1;
    while (cnt <= k) {
        scanf("%d%d%d", &m, &Amin, &Amax);
        vector<People> res;
        for (int i = 0; i < temp.size(); ++i) {
            if (temp[i].age >= Amin && temp[i].age <= Amax)
                res.push_back(temp[i]);
        }
        printf("Case #%d:\n", cnt++);
        for (int i = 0; i < res.size() && i < m; ++i) {
            printf("%s %d %d\n", res[i].name, res[i].age, res[i].netWorth);
        }
        if (res.empty()) printf("None\n");
    }

    return 0;
}