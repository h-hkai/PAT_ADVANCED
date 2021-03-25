#include <bits/stdc++.h>

using namespace std;

struct Mouse {
    int weight;
    int index0;
    int index;
    int rank;
};

bool cmp(Mouse a, Mouse b) { return a.index0 < b.index0; }

int main() {
    int Np, Ng, temp;
    cin >> Np >> Ng;
    vector<int> weight(Np);
    vector<Mouse> mouses(Np);
    queue<Mouse> que;
    for (int i = 0; i < Np; ++i) cin >> weight[i];
    for (int i = 0; i < Np; ++i) {
        cin >> temp;
        mouses[i] = {weight[temp], temp, i, 0};
        que.push(mouses[i]);
    }
    while (!que.empty()) {
        int size = que.size();
        if (size == 1) {
            Mouse tempMouse = que.front();
            mouses[tempMouse.index].rank = 1;
            break;
        }
        int group = size / Ng;
        if (size % Ng != 0) group += 1;
        int cnt = 0, maxn = -1;
        Mouse maxWeightMouse;
        for (int i = 0; i < size; ++i) {
            Mouse tempMouse = que.front();
            mouses[tempMouse.index].rank = group + 1;
            que.pop();
            cnt++;
            if (tempMouse.weight > maxn) {
                maxn = tempMouse.weight;
                maxWeightMouse = tempMouse;
            }
            if (cnt == Ng || i == size - 1) {
                cnt = 0;
                maxn = -1;
                que.push(maxWeightMouse);
            }
        }
    }
    sort(mouses.begin(), mouses.end(), cmp);
    for (int i = 0; i < Np; ++i) {
        if (i == 0)
            cout << mouses[i].rank;
        else
            cout << " " << mouses[i].rank;
    }
    return 0;
}