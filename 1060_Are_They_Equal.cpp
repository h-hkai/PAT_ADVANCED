#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    string a, b, tempA, tempB;
    cin >> n >> a >> b;
    int expA, expB;
    int cntA = a.length(), cntB = b.length();
    for (int i = 0; i < a.length(); ++i) {
        if (a[i] == '.') {
            cntA = i;
            break;
        }
    }
    for (int i = 0; i < b.length(); ++i) {
        if (b[i] == '.') {
            cntB = i;
            break;
        }
    }

    int pA = 0, pB = 0;
    while (a[pA] == '0' || a[pA] == '.') pA++;
    while (b[pB] == '0' || b[pB] == '.') pB++;

    if (cntA < pA)
        expA = cntA - pA + 1;
    else
        expA = cntA - pA;
    if (pA == a.length()) expA = 0;

    if (cntB < pB)
        expB = cntB - pB + 1;
    else
        expB = cntB - pB;
    if (pB == b.length()) expB = 0;

    int indexA = 0, indexB = 0;
    while (indexA < n) {
        if (a[pA] != '.' && pA < a.length())
            tempA += a[pA++];
        else
            tempA += '0';
        indexA++;
    }
    while (indexB < n) {
        if (b[pB] != '.' && pB < b.length())
            tempB += b[pB++];
        else
            tempB += '0';
        indexB++;
    }
    if (tempA == tempB && expA == expB) {
        cout << "YES 0." << tempA << "*10^" << expA << endl;
    } else {
        cout << "NO 0." << tempA << "*10^" << expA << " 0." << tempB << "*10^"
             << expB << endl;
    }
    return 0;
}