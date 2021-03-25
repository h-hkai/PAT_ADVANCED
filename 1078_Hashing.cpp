#include <bits/stdc++.h>

using namespace std;

int isPrime(int x) {
    if (x == 0 || x == 1) return false;
    for (int i = 2; i * i <= x; ++i) {
        if (x % i == 0) return false;
    }
    return true;
}

int main() {
    int Msize, n;
    cin >> Msize >> n;
    while (!isPrime(Msize)) Msize++;

    vector<int> occupied(Msize, 0);
    vector<int> pos(Msize, -1);
    int temp;
    for (int i = 0; i < n; ++i) {
        cin >> temp;
        for (int j = 0; j < Msize; ++j) {
            int index = (j * j + temp) % Msize;
            if (!occupied[index]) {
                pos[i] = index;
                occupied[index] = 1;
                break;
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        if (pos[i] != -1) {
            if (i == 0)
                cout << pos[i];
            else
                cout << " " << pos[i];
        } else {
            if (i == 0)
                cout << "-";
            else
                cout << " "
                     << "-";
        }
    }
    cout << endl;
    return 0;
}