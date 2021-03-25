#include<iostream>
#include<map>
#include<string>
#include<vector>
#include<stack>

using namespace std;
const int Inf = 0x7fffffff;

int findMinDist(vector<int> &dist, vector<bool> &collected) {
    int ret = Inf, j = -1;
    int len = dist.size();
    for (int i = 1; i < len; ++i) {
        if (!collected[i] && ret > dist[i]) {
            ret = dist[i];
            j = i;
        }
    }
    return j;
}

int main() {
    int n, k;
    string start;

    cin >> n >> k >> start;

    map<string, int> EnToNum;
    map<int, string> NumToEn;
    EnToNum[start] = 0;
    NumToEn[0] = start;
    vector<int> happiness(n);
    string name;
    int value;
    for (int i = 1; i < n; ++i) {
        cin >> name >> value;
        EnToNum[name] = i;
        NumToEn[i] = name;
        happiness[i] = value;
    }

    vector<vector<int> > martix(n, vector<int>(n, -1));
    vector<bool> collected(n, false);
    vector<int> path(n, -1);
    string name1, name2;
    int num1, num2, cost;
    for (int i = 0; i < k; ++i) {
        cin >> name1 >> name2 >> cost;
        num1 = EnToNum[name1];
        num2 = EnToNum[name2];
        martix[num1][num2] = cost;
        martix[num2][num1] = cost;
    }

    vector<int> dist(n, Inf);
    dist[0] = 0;
    collected[0] = true;
    for (int i = 1; i < n; ++i) {
        if (martix[0][i] > 0) {
            dist[i] = martix[0][i];
            path[i] = 0;
        }
    }

    int end = EnToNum["ROM"];
    vector<pair<int, int> > backtrack;
    // Dijkstra算法
    while (1) {
        int minVertex = findMinDist(dist, collected);
        if (minVertex == -1) break;
        collected[minVertex] = true;
        for (int i = 0; i < n; ++i) {
            if (martix[minVertex][i] > 0 && !collected[i]) {
                if (dist[minVertex] + martix[minVertex][i] <= dist[i]) {
                    dist[i] = dist[minVertex] + martix[minVertex][i];
                    path[i] = minVertex;
                    if (i == end) {
                        backtrack.push_back({dist[i], minVertex});
                    }
                }
            }
        }
    }

    int count = 0;
    vector<int> Vbacktrack;
    for (int i = 0; i < backtrack.size(); ++i) {
        if (backtrack[i].first == dist[end]) {
            count++;
            Vbacktrack.push_back(backtrack[i].second);
        }
    }

    int maxHappinese = -1, aveHappinese = -1;
    int maxHappVertex;
    for (int i = 0; i < Vbacktrack.size(); ++i) {
        int begin = Vbacktrack[i], temp = happiness[end], numOfVertex = 1;
        while (path[begin] != -1) {
            temp += happiness[begin];
            numOfVertex++;
            begin = path[begin];
        }
        if (temp > maxHappinese) {
            maxHappinese = temp;
            aveHappinese = temp / numOfVertex;
            maxHappVertex = Vbacktrack[i];
        } else if (temp == maxHappinese && aveHappinese < temp/numOfVertex) {
            aveHappinese = temp / numOfVertex;
            maxHappVertex = Vbacktrack[i];
        }
    }

    cout << dist[end] << " " << count << " " << maxHappinese << " " << aveHappinese << endl;

    stack<int> pathToRom;
    pathToRom.push(end);
    while (path[maxHappVertex] != -1) {
        pathToRom.push(maxHappVertex);
        maxHappVertex = path[maxHappVertex];
    }
    cout << start;
    while (!pathToRom.empty()) {
        cout << "->" << NumToEn[pathToRom.top()];
        pathToRom.pop();
    }
    cout << endl;

    return 0;
}