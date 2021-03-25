#include <bits/stdc++.h>

using namespace std;

int charToInt(vector<char>& v) {
    int num = 0;
    for (int i = 0; i < 4; ++i) num = num * 10 + v[i];
    return num;
}

vector<char> intTochar(int n) {
    vector<char> num(4);
    for (int i = 3; i >= 0; --i) {
        num[i] = n % 10;
        n /= 10;
    }
    return num;
}

int main() {
    int n;
    cin >> n;
    if (n == 0) printf("%04d - %04d = %04d\n", 0, 0, 0);
    if (n == 6174) printf("%04d - %04d = %04d\n", 7641, 1467, 6174);
    int last = -1, temp = n;
    while (last != temp) {
        vector<char> v = intTochar(temp);
        sort(v.begin(), v.end(), greater<char>());
        int max = charToInt(v);
        sort(v.begin(), v.end(), less<char>());
        int min = charToInt(v);
        last = temp;
        temp = max - min;
        if (temp == last) break;
        printf("%04d - %04d = %04d\n", max, min, temp);
    }
    return 0;
}