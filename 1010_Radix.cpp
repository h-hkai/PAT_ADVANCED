#include<iostream>
#include<algorithm>
#include<cmath>
#include<cctype>

using namespace std;

int arr[26] = {10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20,
                21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 
                31, 32, 33, 34, 35};

int Tochange(char c) {
    int t;
    if (c > '9') {
        t = arr[c-'a'];
    } else {
        t = c - '0';
    }
    return t;
}

long long StrToNum(string s, long long n) {
    int b;
    long long ret = 0;
    long long e = 1;
    reverse(s.begin(), s.end());
    for (int i = 0; i < s.length(); ++i) {
        b = Tochange(s[i]);
        ret += b * e;
        e *= n;
    }
    return ret;
}

void findRedix(string s, long long n) {
    long long temp;
    char c = *max_element(s.begin(), s.end());
    long long low = Tochange(c) + 1;
    long long high = max(low, n);
    while (low <= high) {
        long long mid = (low + high) / 2;
        temp = StrToNum(s, mid);
        if (temp == n) {
            cout << mid;
            return ;
        }
        else if (temp < 0 || temp > n) high = mid - 1;
        else low = mid + 1;
    }
    cout << "Impossible";
}

int main() {
    string N1, N2;
    int tag, redix;

    cin >> N1 >> N2 >> tag >> redix;

    long long num1, num2;
    if (tag == 1) {
        num1 = StrToNum(N1, redix);
        findRedix(N2, num1);
    } else {
        num2 = StrToNum(N2, redix);
        findRedix(N1, num2);
    }

    return 0;
}