#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int n;
vector<int> bef, pro;

void maxHeapify(vector<int>& a, int start, int end) {
    int dad = start;
    int son = dad * 2 + 1;
    while (son <= end) {
        if (son + 1 <= end && a[son] < a[son+1]) 
            son += 1;
        if (a[dad] > a[son]) return ;
        else {
            swap(a[dad], a[son]);
            dad = son;
            son = dad * 2 + 1;
        }
    }
}

void swap(int &a, int &b) {
    int temp = a;
    a = b; 
    b = temp;
}

int main() {
    cin >> n;

    int temp;
    for (int i = 0; i < n; ++i) {
        cin >> temp;
        bef.push_back(temp);
    }
    for (int i = 0; i < n; ++i) {
        cin >> temp;
        pro.push_back(temp);
    }

    int p1 = 1, p2;
    while (p1 < n && pro[p1-1] < pro[p1]) p1++;
    p2 = p1;
    while (p2 < n && pro[p2] == bef[p2]) p2++;

    if (p2 == n) {
        sort(pro.begin(), pro.begin()+p1+1);
        cout << "Insertion Sort" << endl;
    } else {
        int last = n - 1;
        while (last > 0 && pro[last] >= pro[0]) last--;
        swap(pro[0], pro[last--]);      
        for (int i = last/2; i >= 0; --i) {
            maxHeapify(pro, i, last);
        }
        cout << "Heap Sort" << endl;
    }

    cout << pro[0];
    for (int i = 1; i < n; ++i) 
        cout << " " << pro[i];

    cout << endl;

    return 0;
}