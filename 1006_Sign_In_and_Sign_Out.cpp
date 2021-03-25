#include<iostream>
#include<algorithm>

using namespace std;

typedef struct Person
{
    string num;
    string signIn;
    string signOut;
} person;

person p[1000];

bool Cmpare_in(person a, person b) {
    return a.signIn < b.signIn;
}

bool Cmpare_out(person a, person b) {
    return a.signOut > b.signOut;
}

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        string n, si, so;
        cin >> n >> si >> so;
        p[i].num = n, p[i].signIn = si, p[i].signOut = so;
    }

    sort(p, p+n, Cmpare_in);
    cout << p[0].num;
    sort(p, p+n, Cmpare_out);
    cout << " " << p[0].num;

    return 0;
}