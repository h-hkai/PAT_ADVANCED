#include<iostream>
#include<algorithm>
#include<iomanip>

using namespace std;

int main() {
    double profit = 1.0;
    char arr[3];
    for (int i = 0; i < 3; ++i) {
        char c = 'W';
        double w, t, l, n;
        cin >> w >> t >> l;
        profit *= max(max(w, t), l);
        if (t > w && t > l) c = 'T';
        if (l > w && l > t) c = 'L';
        arr[i] = c;
    }

    cout << arr[0];
    for (int i = 1; i < 3; ++i) {
        cout << " " << arr[i];
    }
    cout << " " << fixed << setprecision(2) << (profit * 0.65 - 1) * 2;

    return 0;
}