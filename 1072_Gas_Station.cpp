#include <bits/stdc++.h>

using namespace std;

const int inf = 999999999;
int grap[1020][1020];
int visited[1020], dist[1020];

int main() {
    int n, m, k, ds;
    cin >> n >> m >> k >> ds;
    fill(grap[0], grap[0] + 1020 * 1020, inf);
    for (int i = 0; i < 1020; ++i) grap[i][i] = 0;
    for (int i = 0; i < k; ++i) {
        string p1, p2;
        int d;
        cin >> p1 >> p2 >> d;
        int v1, v2;
        if (p1[0] == 'G') {
            v1 = stoi(p1.substr(1)) + n;
        } else {
            v1 = stoi(p1);
        }
        if (p2[0] == 'G') {
            v2 = stoi(p2.substr(1)) + n;
        } else {
            v2 = stoi(p2);
        }
        grap[v1][v2] = grap[v2][v1] = d;
        grap[v1][v2] = grap[v2][v1] = min(d, grap[v1][v2]);
    }
    int ansid = -1;
    double ansdist = -1, ansaver = inf;
    for (int i = n + 1; i <= n + m; ++i) {
        double aver = 0, mindist = inf;
        fill(visited, visited + 1020, 0);
        fill(dist, dist + 1020, inf);
        dist[i] = 0;
        for (int j = 0; j < n + m; ++j) {
            int u = -1, minn = inf;
            for (int k = 1; k <= n + m; ++k) {
                if (visited[k] == 0 && dist[k] < minn) {
                    u = k;
                    minn = dist[k];
                }
            }
            if (u == -1) break;
            visited[u] = 1;
            for (int k = 1; k <= n + m; ++k) {
                if (visited[k] == 0 && dist[k] > dist[u] + grap[u][k])
                    dist[k] = dist[u] + grap[u][k];
            }
        }
        for (int j = 1; j <= n; ++j) {
            if (dist[j] > ds) {
                mindist = -1;
                break;
            }
            if (dist[j] < mindist) mindist = dist[j];
            aver += 1.0 * dist[j];
        }
        if (mindist == -1) continue;
        aver = aver / n;
        if (mindist > ansdist) {
            ansdist = mindist;
            ansaver = aver;
            ansid = i;
        } else if (mindist == ansdist && aver < ansaver) {
            ansaver = aver;
            ansid = i;
        }
    }

    if (ansid == -1)
        printf("No Solution\n");
    else
        printf("G%d\n%.1f %.1f\n", ansid - n, ansdist, ansaver);

    return 0;
}