#include<iostream>
#include<string>

using namespace std;

struct Num {
    int sign = 1;
    long long integer;
    long long numerators;
    long long denominators;
    long long originNumer;
};

long long _gcd(long long a, long long b) {
    if (a % b == 0) return b;
    else return _gcd(b, a%b);
}

void coutAns(long long numerators, long long denominators) {
    long long suminteger = numerators / denominators;
    long long sumNumer = numerators % denominators;
    long long gcd = _gcd(sumNumer, denominators);
    if (suminteger != 0) cout << suminteger;
    if (suminteger != 0 && sumNumer != 0) cout << " ";
    if (sumNumer != 0) cout << sumNumer/gcd << "/" << denominators/gcd;
}

void print(Num n) {
    if (n.sign == -1) cout << "(-";
    if (n.integer != 0) cout << n.integer;
    if (n.integer != 0 && n.numerators != 0) cout << " ";
    if (n.numerators != 0) cout << n.numerators << "/" << n.denominators;
    if (n.sign == -1) cout << ")";
    if (n.integer == 0 && n.numerators == 0) cout << 0;
}

void sum(Num n1, Num n2) {
    print(n1);
    cout << " + ";
    print(n2);
    cout << " = ";
    long long sumNumer = n1.sign * n1.originNumer * n2.denominators + 
                   n2.sign * n2.originNumer * n1.denominators;
    long long sumDeno = n1.denominators * n2.denominators;  
    if (sumNumer == 0) cout << 0 << endl;
    else if (sumNumer < 0) {
        cout << "(-";
        sumNumer *= -1;
        coutAns(sumNumer, sumDeno);
        cout << ")" << endl;
    } else {
        coutAns(sumNumer, sumDeno);
        cout << endl;
    }
}

void difference(Num n1, Num n2) {
    print(n1);
    cout << " - ";
    print(n2);
    cout << " = ";
    long long sumNumer = n1.sign * n1.originNumer * n2.denominators - 
                   n2.sign * n2.originNumer * n1.denominators;
    long long sumDeno = n1.denominators * n2.denominators;  
    if (sumNumer == 0) cout << 0 << endl;
    else if (sumNumer < 0) {
        cout << "(-";
        sumNumer *= -1;
        coutAns(sumNumer, sumDeno);
        cout << ")" << endl;
    } else {
        coutAns(sumNumer, sumDeno);
        cout << endl;
    }
}

void product(Num n1, Num n2) {
    print(n1);
    cout << " * ";
    print(n2);
    cout << " = ";
    long long sumNumer = n1.originNumer * n2.originNumer;
    long long sumDeno = n1.denominators * n2.denominators;  
    if (sumNumer == 0) cout << 0 << endl;
    else if (n1.sign*n2.sign < 0) {
        cout << "(-";
        coutAns(sumNumer, sumDeno);
        cout << ")" << endl;
    } else {
        coutAns(sumNumer, sumDeno);
        cout << endl;
    }
}

void quotient(Num n1, Num n2) {
    print(n1);
    cout << " / ";
    print(n2);
    cout << " = ";
    if (n2.originNumer == 0) cout << "Inf" << endl;
    else {
        long long sumNumer = n1.originNumer * n2.denominators;
        long long sumDeno = n1.denominators * n2.originNumer;  
        if (sumNumer == 0) cout << 0 << endl;
        else if (n1.sign*n2.sign < 0) {
            cout << "(-";
            coutAns(sumNumer, sumDeno);
            cout << ")" << endl;
        } else {
            coutAns(sumNumer, sumDeno);
            cout << endl;
        }
    }
}

Num parsing(string s) {
    Num a;
    long long i = 0;
    long long numerators, denominators, gcd;
    string s1, s2;
    if (s[0] == '-') {
        i = 1;
        a.sign = -1;
    } 
    for (; i < s.length(); ++i) {
        if (s[i] == '/') break;
        s1 += s[i];
    }
    ++i;
    for (; i < s.length(); ++i) {
        s2 += s[i];
    }
    numerators = stoi(s1);
    denominators = stoi(s2);
    gcd = _gcd(numerators, denominators);
    a.originNumer = numerators / gcd;
    a.denominators = denominators / gcd;
    a.integer = numerators / denominators;
    a.numerators = a.originNumer % a.denominators;
    return a;
}

int main() {
    string str;
    getline(cin, str);
    long long pos = str.find(' ');
    string num1, num2;
    num1 = str.substr(0, pos);
    num2 = str.substr(pos+1);

    Num n1 = parsing(num1);
    Num n2 = parsing(num2);

    sum(n1, n2);
    difference(n1, n2);
    product(n1, n2);
    quotient(n1, n2);

    return 0;
}