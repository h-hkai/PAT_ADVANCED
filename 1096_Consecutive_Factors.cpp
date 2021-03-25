#include<iostream>
#include<cmath>

using namespace std;

int main() {
    long N;
    cin >> N;

    int maxn = sqrt(N) + 1;
    long temp = 1, len = 0;
    int startPos = 0;

    for (int i = 2; i <= maxn; ++i) {
        int j;
        for (j = i; j <= maxn; ++j) {
            temp *= j;
            if (N % temp != 0) break;
        }
        if (j - i > len) {
            len = j - i;
            startPos = i;
        }
        temp = 1;
    }

    if (len == 0) cout << 1 << endl << N;
    else {
        cout << len << endl;
        for (int i = 0; i < len; ++i) {
            cout << startPos + i;
            if (i != len-1) cout << '*';
        }
    }

    return 0;
}