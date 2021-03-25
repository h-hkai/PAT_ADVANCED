#include <bits/stdc++.h>

using namespace std;

const int inf = 0x7fffffff;

int n, m, s, d;
// 用来存储图的信息
vector<vector<int> > grap(505, vector<int>(505, inf));
// 用来存储图中每条边的花费
vector<vector<int> > cost(505, vector<int>(505, inf));
// 用来标记图中的那个结点是否已经被访问过
vector<bool> visited(505, false);
// 记录每个结点到达起点的位置
vector<int> dis(505, inf);
// 用来存储最短路径的信息
vector<int> path, tempPath;
// 记录每个结点的前驱结点
vector<int> pre[505];
int minCost = inf;

void dfs(int v) {
    tempPath.push_back(v);
    if (v == s) {
        int tempCost = 0;
        int tempDis = 0;
        int len = tempPath.size();
        for (int i = len - 1; i > 0; --i) {
            tempCost += cost[tempPath[i]][tempPath[i - 1]];
        }
        if (minCost > tempCost) {
            minCost = tempCost;
            path = tempPath;
        }
        tempPath.pop_back();
        return;
    }
    for (int it : pre[v]) dfs(it);
    tempPath.pop_back();
}

int main() {
    cin >> n >> m >> s >> d;
    int c1, c2, t, money;
    for (int i = 0; i < m; ++i) {
        cin >> c1 >> c2 >> t >> money;
        grap[c1][c2] = grap[c2][c1] = t;
        cost[c1][c2] = cost[c2][c1] = money;
    }
    dis[s] = 0;
    pre[s].push_back(s);
    // 运用Dijkstra算法寻找每个结点到起点的最小距离。
    for (int i = 0; i < n; ++i) {
        int u = -1, minn = inf;
        for (int j = 0; j < n; ++j) {
            if (visited[j] == false && dis[j] < minn) {
                u = j;
                minn = dis[j];
            }
        }
        // 表明与起点联通的结点已经遍历完毕
        if (u == -1) break;
        visited[u] = true;
        // 寻找与u相连的结点，并更新其最短距离
        for (int j = 0; j < n; ++j) {
            if (visited[j] == false && grap[u][j] != inf) {
                if (dis[j] > dis[u] + grap[u][j]) {
                    dis[j] = dis[u] + grap[u][j];
                    pre[j].clear();
                    pre[j].push_back(u);
                } else if (dis[j] == dis[u] + grap[u][j]) {
                    pre[j].push_back(u);
                }
            }
        }
    }
    dfs(d);

    for (int i = path.size() - 1; i >= 0; --i) cout << path[i] << " ";
    cout << dis[d] << " " << minCost << endl;

    return 0;
}