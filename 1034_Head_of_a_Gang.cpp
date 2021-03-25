#include <bits/stdc++.h>

using namespace std;

map<string, int> strToi;
map<int, string> iToStr;
map<string, int> ans;
int countId = 1, k;
vector<bool> visited(1005, false);
int G[2005][2005] = {0};
int weight[2005] = {0};

int strToiFac(string str) {
    if (strToi[str] == 0) {
        strToi[str] = countId;
        iToStr[countId] = str;
        return countId++;
    } else {
        return strToi[str];
    }
}

void dfs(int u, int& head, int& numMember, int& totalWeight) {
    visited[u] = true;
    numMember++;
    if (weight[u] > weight[head]) head = u;
    for (int i = 1; i < countId; ++i) {
        if (G[u][i] > 0) {
            totalWeight += G[u][i];
            G[u][i] = G[i][u] = 0;
            if (!visited[i]) dfs(i, head, numMember, totalWeight);
        }
    }
}

void dfsTrav() {
    for (int i = 1; i < countId; ++i) {
        if (!visited[i]) {
            int head = i, numMember = 0, totalWeight = 0;
            dfs(i, head, numMember, totalWeight);
            if (numMember > 2 && totalWeight > k) ans[iToStr[head]] = numMember;
        }
    }
}

int main() {
    int N;
    cin >> N >> k;
    for (int i = 0; i < N; ++i) {
        string Name1, Name2;
        int Time;
        cin >> Name1 >> Name2 >> Time;
        int id1 = strToiFac(Name1);
        int id2 = strToiFac(Name2);
        weight[id1] += Time;
        weight[id2] += Time;
        G[id1][id2] += Time;
        G[id2][id1] += Time;
    }
    dfsTrav();
    cout << ans.size() << endl;
    for (auto s : ans) cout << s.first << " " << s.second << endl;

    return 0;
}