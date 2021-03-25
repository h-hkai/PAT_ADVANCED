#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
    int t;
    long long p;
    cin >> t >> p;
    int c;
    vector<int> v;
    for (int i = 0; i < t; ++i) {
        cin >> c;
        v.push_back(c);
    }
    sort(v.begin(), v.end());
    int temp = 0, result = 0;
    for (int i = 0; i < t; ++i) {
        for (int j = i+result; j < t; ++j) {
            if (v[j] <= v[i]*p) {
                temp = j - i + 1;
                if (temp > result) 
                    result = temp;
            } else {
                break;
            }
        }
    }
    cout << result << endl;
    return 0;
}