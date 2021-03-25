#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> grap[10005];
    vector<bool> boy(10005, false);
    string v1, v2;
    int num1, num2;
    for (int i = 0; i < M; ++i) {
        cin >> v1 >> v2;
        num1 = abs(stoi(v1));
        num2 = abs(stoi(v2));
        grap[num1].push_back(num2);
        grap[num2].push_back(num1);
        if (v1[0] != '-') boy[num1] = true;
        if (v2[0] != '-') boy[num2] = true;
    }
    int k;
    cin >> k;
    string vstart, vend;
    vector<pair<int, int> > ans;
    for (int i = 0; i < k; ++i) {
        ans.clear();
        cin >> vstart >> vend;
        num1 = abs(stoi(vstart));
        num2 = abs(stoi(vend));
        for (int f1 : grap[num1])
            if (f1 != num2 && f1 != num1 && boy[f1] == boy[num1])
                for (int f2 : grap[f1])
                    if (f2 != num1 && f2 != num2 && boy[f2] == boy[num2])
                        for (int f3 : grap[f2])
                            if (f3 == num2) ans.push_back({f1, f2});
        sort(ans.begin(), ans.end());
        cout << ans.size() << endl;
        for (int i = 0; i < ans.size(); ++i) {
            // printf("%04d %04d\n", i.first, i.second);
            cout.setf(ios::right);
            cout.fill('0');
            cout << setw(4) << ans[i].first << " ";
            cout.setf(ios::right);
            cout.fill('0');
            cout << setw(4) << ans[i].second << endl;
        }
    }
    return 0;
}