#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) cin >> v[i];
    sort(v.begin(), v.end(), [](int x, int y) -> bool { return x > y; });
    int mid = sqrt(n) + 1;
    int row, col;
    for (int i = mid; i >= 1; --i) {
        if (n % i == 0) {
            row = i;
            col = n / i;
            break;
        }
    }
    if (row < col) {
        int temp = row;
        row = col;
        col = temp;
    }
    vector<vector<int> > matrix(row, vector<int>(col, 0));
    vector<vector<int> > visited = matrix;
    int posX = 0, posY = -1, i = 0;
    int dirs[5] = {0, 1, 0, -1, 0};
    while (i < n) {
        for (int j = 0; j < 4; ++j) {
            while (i < n) {
                int curX = posX + dirs[j];
                int curY = posY + dirs[j + 1];
                if (curX >= 0 && curX < row && curY >= 0 && curY < col &&
                    visited[curX][curY] == 0) {
                    visited[curX][curY] = 1;
                    posX = curX;
                    posY = curY;
                    matrix[posX][posY] = v[i];
                    ++i;
                } else
                    break;
            }
        }
    }
    for (int i = 0; i < row; ++i) {
        cout << matrix[i][0];
        for (int j = 1; j < col; ++j) {
            cout << " " << matrix[i][j];
        }
        cout << endl;
    }
    return 0;
}