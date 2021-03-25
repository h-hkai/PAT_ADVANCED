#include<iostream>
#include<algorithm>
#include<cstdio>

using namespace std;

int v[1010][1010];
int visited[1010];
int n, k, m, c;

void dfs(int node) {
    visited[node] = 1;
    for (int i = 1; i <= n; ++i) {
        if (visited[i] == 0 && v[node][i] == 1) {
            dfs(i);
        }
    }
}

int main() {
    
    scanf("%d%d%d", &n, &k, &m);

    int x, y;
    for (int i = 0; i < k; ++i) {
        scanf("%d%d", &x, &y);
        v[x][y] = v[y][x] = 1;
    }

    for (int i = 0; i < m; ++i) {
        int cnt = 0;
        scanf("%d", &c);
        fill(visited, visited+1010, 0);
        visited[c] = 1;
        for (int j = 1; j <= n; ++j) {
            if (visited[j] == 0) {
                dfs(j);
                cnt++;
            }
        }
        cout << cnt-1 << endl;
    }

    return 0;
}