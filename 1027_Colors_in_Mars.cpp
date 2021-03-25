#include <bits/stdc++.h>

using namespace std;

int main() {
    int red, green, blue;
    cin >> red >> green >> blue;
    map<int, char> m;
    m[10] = 'A';
    m[11] = 'B';
    m[12] = 'C';
    string ans = "#";
    int x1 = red / 13;
    if (x1 < 10)
        ans += to_string(x1);
    else
        ans += m[x1];
    int x2 = red % 13;
    if (x2 < 10)
        ans += to_string(x2);
    else
        ans += m[x2];
    int y1 = green / 13;
    if (y1 < 10)
        ans += to_string(y1);
    else
        ans += m[y1];
    int y2 = green % 13;
    if (y2 < 10)
        ans += to_string(y2);
    else
        ans += m[y2];
    int z1 = blue / 13;
    if (z1 < 10)
        ans += to_string(z1);
    else
        ans += m[z1];
    int z2 = blue % 13;
    if (z2 < 10)
        ans += to_string(z2);
    else
        ans += m[z2];
    cout << ans << endl;
    return 0;
}