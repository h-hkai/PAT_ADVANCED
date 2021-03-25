#include <bits/stdc++.h>

using namespace std;

struct User {
    int id;
    int rank;
    int total_score = 0;
    int NumOfPerfect = 0;
    bool shown = false;
    vector<int> problems;
};

bool cmp(User a, User b) {
    if (a.total_score != b.total_score)
        return a.total_score > b.total_score;
    else if (a.NumOfPerfect != b.NumOfPerfect)
        return a.NumOfPerfect > b.NumOfPerfect;
    else
        return a.id < b.id;
}

int main() {
    int n, k, m;
    cin >> n >> k >> m;
    vector<int> score(k + 1);
    for (int i = 1; i <= k; ++i) cin >> score[i];
    vector<User> users(n + 1);
    int user_id, pro_id, pso;
    for (int i = 1; i <= n; ++i) users[i].problems.resize(k + 1, -1);
    for (int i = 0; i < m; ++i) {
        cin >> user_id >> pro_id >> pso;
        users[user_id].id = user_id;
        int temp = users[user_id].problems[pro_id];
        users[user_id].problems[pro_id] = max(pso, temp);
        if (pso != -1)
            users[user_id].shown = true;
        else if (users[user_id].problems[pro_id] == -1)
            users[user_id].problems[pro_id] = -2;
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= k; ++j) {
            if (users[i].problems[j] != -1 && users[i].problems[j] != -2)
                users[i].total_score += users[i].problems[j];
            if (users[i].problems[j] == score[j]) users[i].NumOfPerfect++;
        }
    }
    sort(users.begin() + 1, users.end(), cmp);

    for (int i = 1; i <= n; ++i) {
        users[i].rank = i;
        if (i != 1 && users[i].total_score == users[i - 1].total_score)
            users[i].rank = users[i - 1].rank;
    }
    for (int i = 1; i <= n; ++i) {
        if (users[i].shown) {
            printf("%d %05d %d", users[i].rank, users[i].id,
                   users[i].total_score);
            for (int j = 1; j <= k; ++j) {
                if (users[i].problems[j] != -1 && users[i].problems[j] != -2)
                    printf(" %d", users[i].problems[j]);
                else if (users[i].problems[j] == -1)
                    printf(" -");
                else
                    printf(" 0");
            }
            printf("\n");
        }
    }
    return 0;
}