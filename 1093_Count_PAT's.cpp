#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main() {
    string str;
    cin >> str;

    int len = str.length();
    vector<int> numOfP(len, 0);
    vector<int> numOfT(len, 0);
    
    int countP = 0;
    int countT = 0;
    int countPAT = 0;
    for (int i = 0; i < len; ++i)
        if (str[i] == 'P') numOfP[i] = ++countP;
        else numOfP[i] = countP;
    for (int i = len-1; i >= 0; --i)
        if (str[i] == 'T') numOfT[i] = ++countT;
        else numOfT[i] = countT;
    for (int i = 0; i < len; ++i)
        if (str[i] == 'A')
            countPAT = (countPAT + numOfP[i] * numOfT[i]) % 1000000007;

    cout << countPAT << endl;
    return 0;
}