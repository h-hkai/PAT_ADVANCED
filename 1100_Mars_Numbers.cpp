#include<iostream>
#include<string>

using namespace std;

string lowDigit[13] = {"tret", "jan", "feb", "mar", "apr", "may", 
                        "jun", "jly", "aug", "sep", "oct", "nov", "dec"};
string highDigit[13] = {"###", "tam", "hel", "maa", "huh", "tou", "kes",
                        "hei", "elo", "syy", "lok", "mer", "jou"};

void MarToEarth(string str) {
    int len = str.length();
    int t1 = 0, t2 = 0;
    string s1 = str.substr(0, 3), s2;
    if (len > 4) s2 = str.substr(4, 3);
    for (int i = 1; i < 13; ++i) {
        if (lowDigit[i] == s1 || lowDigit[i] == s2) t2 = i;
        if (highDigit[i] == s1) t1 = i;
    }
    cout << t1*13 + t2 << endl;
}

void EarthToMar(string str) {
    int n = stoi(str);
    int low = n % 13;
    int high = n / 13;
    if (high) cout << highDigit[high];
    if ((high) && (low)) cout << " ";
    if (low || n == 0) cout << lowDigit[low] << endl;
}

int main() {
    int n;
    cin >> n;
    getchar();
    string num;
    for (int i = 0; i < n; ++i) {
        getline(cin, num);
        if (num[0] >= '0' && num[0] <= '9') EarthToMar(num);
        else MarToEarth(num);
    }

    return 0;
}