#include <bits/stdc++.h>

using namespace std;

vector<int> praseString(string str) {
    int pos1 = str.find('.');
    int pos2 = str.find('.', pos1 + 1);
    string num1, num2, num3;
    num1 = str.substr(0, pos1);
    num2 = str.substr(pos1 + 1, pos2 - pos1 - 1);
    num3 = str.substr(pos2 + 1);
    vector<int> res;
    res.push_back(stoi(num1));
    res.push_back(stoi(num2));
    res.push_back(stoi(num3));
    return res;
}

int main() {
    string num1, num2;
    cin >> num1 >> num2;
    vector<int> v1 = praseString(num1);
    vector<int> v2 = praseString(num2);
    int galleon, sickle, knut, add;
    knut = (v1[2] + v2[2]) % 29;
    add = (v1[2] + v2[2]) / 29;
    sickle = (v1[1] + v2[1] + add) % 17;
    add = (v1[1] + v2[1] + add) / 17;
    galleon = v1[0] + v2[0] + add;
    cout << galleon << "." << sickle << "." << knut << endl;
    return 0;
}