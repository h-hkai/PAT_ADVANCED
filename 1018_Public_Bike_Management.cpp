#include <bits/stdc++.h>

using namespace std;

const int inf = 0x7fffffff;

vector<int> path, tempPath;
vector<int> preVertex[505];
vector<int> currentNumOfBikes(505);
int minNeed = inf, minBack = inf;
int Cmax, n, Sp, m;

void DFS(int node) {
    tempPath.push_back(node);
    // 说明这时已经找到了一条路径
    if (node == 0) {
        int need = 0, back = 0;
        for (int i = tempPath.size() - 2; i >= 0; --i) {
            int id = tempPath[i];
            if (currentNumOfBikes[id] + back < Cmax / 2) {
                need += Cmax / 2 - currentNumOfBikes[id] - back;
                back = 0;
            } else {
                back += currentNumOfBikes[id] - Cmax / 2;
            }
        }
        if (need < minNeed) {
            minNeed = need;
            minBack = back;
            path = tempPath;
        } else if (need == minNeed && back < minBack) {
            minBack = back;
            path = tempPath;
        }
        tempPath.pop_back();
        return;
    }
    for (int it : preVertex[node]) DFS(it);
    tempPath.pop_back();
}

int main() {
    cin >> Cmax >> n >> Sp >> m;
    for (int i = 1; i <= n; ++i) cin >> currentNumOfBikes[i];
    vector<vector<int> > grap(n + 1, vector<int>(n + 1, inf));
    int v1, v2, t;
    for (int i = 0; i < m; ++i) {
        cin >> v1 >> v2 >> t;
        grap[v1][v2] = grap[v2][v1] = t;
    }
    vector<bool> visited(n + 1, false);
    vector<int> dis(n + 1, inf);
    dis[0] = 0;
    // Dijkstra寻找最短路
    for (int i = 0; i <= n; ++i) {
        int u = -1, minDis = inf;
        for (int j = 0; j <= n; ++j) {
            if (visited[j] == false && dis[j] < minDis) {
                u = j;
                minDis = dis[j];
            }
        }
        // 当前的连通分量已经遍历完
        if (u == -1) break;
        visited[u] = true;
        // 更新与当前最短路联通的下一个节点的距离
        for (int j = 0; j <= n; ++j) {
            if (visited[j] == false && grap[u][j] != inf) {
                if (minDis + grap[u][j] < dis[j]) {
                    dis[j] = minDis + grap[u][j];
                    preVertex[j].clear();
                    preVertex[j].push_back(u);
                } else if (minDis + grap[u][j] == dis[j]) {
                    preVertex[j].push_back(u);
                }
            }
        }
    }

    DFS(Sp);
    cout << minNeed << " 0";
    for (int i = path.size() - 2; i >= 0; --i) cout << "->" << path[i];
    cout << " " << minBack << endl;

    return 0;
}