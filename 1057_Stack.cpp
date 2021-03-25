#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    getchar();
    string str;
    stack<int> stk;
    int prt = -1;
    int bucket_count[100] = {0};
    int bucket[100][1000] = {0};
    for (int i = 0; i < n; ++i) {
        getline(cin, str);
        if (str[1] == 'u') {
            int num = stoi(str.substr(5));
            bucket_count[num / 1000]++;
            bucket[num / 1000][num % 1000]++;
            stk.push(num);
        } else if (str[1] == 'o') {
            if (stk.empty())
                cout << "Invalid" << endl;
            else {
                int num = stk.top();
                cout << num << endl;
                bucket_count[num / 1000]--;
                bucket[num / 1000][num % 1000]--;
                stk.pop();
            }
        } else {
            if (stk.empty()) {
                cout << "Invalid" << endl;
            } else {
                int target = (stk.size() + 1) / 2;
                int count = 0;
                for (int i = 0; i < 100; ++i) {
                    if (count + bucket_count[i] >= target) {
                        for (int j = 0; j < 1000; ++j) {
                            if (count + bucket[i][j] >= target) {
                                cout << i * 1000 + j << endl;
                                break;
                            }
                            count += bucket[i][j];
                        }
                        break;
                    }
                    count += bucket_count[i];
                }
            }
        }
    }

    return 0;
}