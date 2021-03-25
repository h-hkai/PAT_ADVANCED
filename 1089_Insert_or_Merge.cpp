#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


int main() {
    int n;
    cin >> n;

    vector<int> init(n);
    vector<int> part(n);
    vector<int> temp(n);

    int t, p, q;
    for (int i = 0; i < n; ++i) {
        cin >> t;
        init[i] = t;
    }
    for (int i = 0; i < n; ++i) {
        cin >> t;
        part[i] = t;
    }
    for (p = 0; p < n-1 && part[p] <= part[p+1]; p++);
    for (q = p+1; init[q] == part[q] && q < n; q++);
    if (q == n) {
        cout << "Insertion Sort" << endl;
        sort(part.begin(), part.begin()+p+2);
        cout << part[0];
        for (int i = 1; i < n; ++i) cout << " " << part[i];
    } else {
        cout << "Merge Sort" << endl;
        int j, k = 1;
        bool flag = true;
        while (flag) {
            flag = false;
            for (int i = 0; i < n; ++i) {
                if (init[i] != part[i]) 
                    flag = true;
            }
            k *= 2;
            for (j = 0; j < n/k; ++j)
                sort(init.begin()+j*k, init.begin()+(j+1)*k);
            sort(init.begin()+(n/k)*k, init.end());
        }
        cout << init[0];
        for (int i = 1; i < n; ++i)
            cout << " " << init[i];
    }

    cout << endl;

    return 0;
}