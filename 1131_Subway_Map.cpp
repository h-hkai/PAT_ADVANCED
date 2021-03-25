#include <bits/stdc++.h>

using namespace std;

unordered_map<int, int> lines;
vector<pair<int, int> > trans, tempTrans;
vector<int> grap[10005], past[10005], path, temp, dis(10005);
int n, m, k, start, dest;

void BFS() {
    queue<int> que;
    // 初始化
    for (int i = 0; i < 10005; ++i) {
        past[i].clear();
        dis[i] = INT_MAX;
    }
    que.push(start);
    dis[start] = 0;
    while (!que.empty()) {
        int q = que.front();
        que.pop();
        if (dis[q] > dis[dest]) continue;
        for (int g : grap[q]) {
            if (dis[g] >= dis[q] + 1) {
                if (dis[g] == INT_MAX) que.push(g);
                dis[g] = dis[q] + 1;
                if (dis[g] > dis[q] + 1) past[g].clear();
                past[g].push_back(q);
            }
        }
    }
}

void DFS(int d) {
    path.push_back(d);
    if (d == start) {
        tempTrans.clear();
        tempTrans.push_back({start, -1});
        for (int i = path.size() - 2; i > 0; --i) {
            if (lines[path[i + 1] * 10000 + path[i]] !=
                lines[path[i] * 10000 + path[i - 1]]) {
                tempTrans.push_back(
                    {path[i], lines[path[i] * 10000 + path[i + 1]]});
            }
        }
        tempTrans.push_back({dest, lines[path[1] * 10000 + dest]});
        if (trans.size() > tempTrans.size() || trans.size() == 0) {
            trans = tempTrans;
        }
    }
    for (int p : past[d]) DFS(p);
    path.pop_back();
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> m;
        temp = vector<int>(m);
        for (int j = 0; j < m; ++j) cin >> temp[j];
        for (int j = 1; j < m; ++j) {
            lines[temp[j] * 10000 + temp[j - 1]] = i;
            lines[temp[j - 1] * 10000 + temp[j]] = i;
            grap[temp[j]].push_back(temp[j - 1]);
            grap[temp[j - 1]].push_back(temp[j]);
        }
    }
    cin >> k;
    for (int i = 0; i < k; ++i) {
        cin >> start >> dest;
        //神搜寻找所有的最短路
        BFS();
        path.clear();
        trans.clear();
        DFS(dest);
        cout << dis[dest] << endl;
        for (int i = 0; i < trans.size() - 1; ++i) {
            printf("Take Line#%d from %04d to %04d.\n", trans[i + 1].second,
                   trans[i].first, trans[i + 1].first);
        }
    }

    return 0;
}