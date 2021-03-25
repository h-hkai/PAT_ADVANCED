#include<iostream>
#include<string>

using namespace std;

bool isPrime(int n) {
    if (n == 0 || n == 1) return false;
    for (int i = 2; i*i < n; ++i) {
        if (n % i == 0) return false;
    }
    return true;
}

int main() {
    int n, k, temp;
    string str, sub;
    cin >> n >> k >> str;
    for (int i = 0; i+k < n; ++i) {
        sub = str.substr(i, k);
        temp = stoi(sub); 
        if (isPrime(temp)) {
            cout << sub << endl;
            return 0;
        }
    }

    cout << "404" << endl;

    return 0;
}