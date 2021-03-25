#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int m, n, l, t;
int count = 0, rang = 0, total = 0;
vector<vector<vector<int> > > matrix;
vector<vector<vector<int> > > visited;
vector<int> dir = {1, 0, 0, -1, 0, 0, 1, 0};

bool inMatrix(int i, int j, int k) {
    if (i >= 0 && i < l && j >= 0 && j < m && k >= 0 && k < n)
        if (matrix[i][j][k] == 1 && visited[i][j][k] == 0) return true;
    return false;
}

void BFS(int x, int y, int z) {
    visited[x][y][z] = 1;
    count++;
    for (int i = 0; i < 6; ++i) {
        if (inMatrix(x+dir[i], y+dir[i+1], z+dir[i+2]))
            BFS(x+dir[i], y+dir[i+1], z+dir[i+2]);
    }
}

int main() {
    cin >> m >> n >> l >> t;

    matrix = vector<vector<vector<int> > >(l, vector<vector<int> >(m, vector<int>(n, 0)));
    visited = vector<vector<vector<int> > >(l, vector<vector<int> >(m, vector<int>(n, 0)));

    for (int i = 0; i < l; ++i) {
        for (int j = 0; j < m; ++j) {
            for (int k = 0; k < n; ++k) {
                int p;
                cin >> p;
                matrix[i][j][k] = p;
            }
        }
    }
    for (int i = 0; i < l; ++i) {
        for (int j = 0; j < m; ++j) {
            for (int k = 0; k < n; ++k) {
                count = 0;
                if (visited[i][j][k] == 0 && matrix[i][j][k] == 1)
                    BFS(i, j, k);
                if (count >= t) total += count;
            }
        }
    }

    cout << total << endl;
    
    return 0;
}