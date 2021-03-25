#include <iostream>
#include <string>

using namespace std;

int main() {
    int D, N, count;
    cin >> D >> N;
    if (N == 1) {
        cout << D << endl;
        return 0;
    }
    string ans = to_string(D) + "1";
    string str = ans + " ";
    for (int i = 3; i <= N; ++i) {
        count = 1;
        ans = "";
        for (int j = 1; j < str.length(); ++j) {
            if (str[j] == str[j - 1])
                count++;
            else {
                ans += str[j - 1] + to_string(count);
                count = 1;
            }
        }
        str = ans + " ";
    }
    cout << ans << endl;
    return 0;
}