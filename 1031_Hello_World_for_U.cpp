#include <bits/stdc++.h>

using namespace std;

int main() {
    string str;
    cin >> str;

    int len = str.length();
    int row = len / 3 + 1;
    int col = len - 2 * row + 2;
    if (col < row) {
        col += 2;
        row -= 1;
    }
    vector<vector<char> > martix(row, vector<char>(col, ' '));
    int i, j;
    for (j = 0, i = 0; j < row; ++j, ++i) martix[j][0] = str[i];
    for (j = 1; j < col; ++j, ++i) martix[row - 1][j] = str[i];
    for (j = row - 2; j >= 0; --j, ++i) martix[j][col - 1] = str[i];
    for (i = 0; i < row; ++i) {
        for (j = 0; j < col; ++j) cout << martix[i][j];
        cout << endl;
    }

    return 0;
}