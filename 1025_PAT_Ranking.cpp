#include <bits/stdc++.h>

using namespace std;

struct Node {
    string registration_number;
    int final_rank;
    int location_number;
    int local_rank;
    int grade;
};

bool cmp(Node a, Node b) {
    if (a.grade == b.grade)
        return a.registration_number < b.registration_number;
    return a.grade > b.grade;
}

int main() {
    int n, k;
    cin >> n;
    string registration_number;
    int grade;
    vector<Node> testees;
    for (int i = 1; i <= n; ++i) {
        cin >> k;
        vector<Node> temp(k);
        for (int j = 0; j < k; ++j) {
            cin >> temp[j].registration_number >> temp[j].grade;
            temp[j].location_number = i;
        }
        sort(temp.begin(), temp.end(), cmp);
        int local_rank = 1;
        temp[0].local_rank = 1;
        testees.push_back(temp[0]);
        for (int j = 1; j < k; ++j) {
            local_rank++;
            if (temp[j].grade != temp[j - 1].grade)
                temp[j].local_rank = local_rank;
            else
                temp[j].local_rank = temp[j - 1].local_rank;
            testees.push_back(temp[j]);
        }
    }
    sort(testees.begin(), testees.end(), cmp);
    int final_rank = 1;
    testees[0].final_rank = 1;
    for (int i = 1; i < testees.size(); ++i) {
        final_rank++;
        if (testees[i].grade != testees[i - 1].grade)
            testees[i].final_rank = final_rank;
        else
            testees[i].final_rank = testees[i - 1].final_rank;
    }
    cout << testees.size() << endl;
    for (int i = 0; i < testees.size(); ++i) {
        cout << testees[i].registration_number << " " << testees[i].final_rank
             << " " << testees[i].location_number << " "
             << testees[i].local_rank << endl;
    }
    return 0;
}