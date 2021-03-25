#include <bits/stdc++.h>

using namespace std;

vector<int> fa(10005, 0);

int findFather(int x) {
    int a = x;
    while (x != fa[x]) {
        x = fa[x];
    }
    // 路径压缩
    while (a != fa[a]) {
        int z = a;
        a = fa[a];
        fa[z] = x;
    }
    return x;
}

void Union(int x, int y) {
    int faX = findFather(x);
    int faY = findFather(y);
    if (faX < faY)
        fa[faY] = faX;
    else
        fa[faX] = faY;
}

struct Family {
    int index = 0;
    double sum_estate = 0;
    double sum_area = 0;
    double AVGarea = 0;
    double AVGsets = 0;
    bool haveMerged = false;
    set<int> people;
};

bool cmp(Family x, Family y) {
    if (x.AVGarea == y.AVGarea)
        return x.index < y.index;
    else
        return x.AVGarea > y.AVGarea;
}

int main() {
    int n;
    cin >> n;
    Family fam[10005];
    for (int i = 0; i < 10005; ++i) fa[i] = i;
    for (int i = 0; i < n; ++i) {
        int id, father, mather, nums, child, estate, area;
        cin >> id >> father >> mather >> nums;
        set<int> people;
        people.insert(id);
        if (father != -1) {
            people.insert(father);
            Union(id, father);
        }
        if (mather != -1) {
            people.insert(mather);
            Union(id, mather);
        }
        for (int j = 0; j < nums; ++j) {
            cin >> child;
            people.insert(child);
            Union(id, child);
        }
        cin >> estate >> area;
        int index = findFather(id);
        fam[index].sum_estate += estate;
        fam[index].sum_area += area;
        fam[index].index = index;
        for (int p : people) fam[index].people.insert(p);
    }
    vector<Family> ans;
    for (int i = 0; i < 10005; ++i) {
        if (fam[i].sum_estate > 0) {
            int index = findFather(i);
            fam[index].haveMerged = true;
            if (i != index) {
                fam[index].sum_area += fam[i].sum_area;
                fam[index].sum_estate += fam[i].sum_estate;
                fam[index].index = index;
                for (int j : fam[i].people) fam[index].people.insert(j);
            }
        }
    }
    for (int i = 0; i < 10005; ++i) {
        if (fam[i].haveMerged) ans.push_back(fam[i]);
    }
    for (auto& it : ans) {
        it.AVGarea = it.sum_area / it.people.size();
        it.AVGsets = it.sum_estate / it.people.size();
    }
    sort(ans.begin(), ans.end(), cmp);
    cout << ans.size() << endl;
    for (auto it : ans) {
        printf("%04d %d %.3f %.3f\n", it.index, it.people.size(), it.AVGsets,
               it.AVGarea);
    }
    return 0;
}