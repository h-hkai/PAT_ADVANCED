#include <bits/stdc++.h>

using namespace std;

int main() {
    int s1, s2, n, temp;
    cin >> s1 >> s2 >> n;
    map<int, int> m;
    int address, next;
    char data;
    int flag = 0;
    for (int i = 0; i < n; ++i) {
        cin >> address >> data >> next;
        if (m[next] != 0 && next == -1) {
            cout << "-1" << endl;
            return 0;
        } else if (m[next] != 0 && flag == 0) {
            temp = next;
            flag = 1;
        }
        m[next] = address;
    }
    cout << setw(5) << setfill('0') << temp << endl;
    return 0;
}