#include <bits/stdc++.h>

using namespace std;

const int inf = 0x7fffffff;
stack<int> shortestPath, leastTimePath;
int eage[505][505], consume[505][505];
int path[505], dis[505], times[505];
int visited[505];
int numOfIntersections[505];

int main() {
    int n, m;
    cin >> n >> m;
    fill(eage[0], eage[0] + 505 * 505, inf);
    fill(consume[0], consume[0] + 505 * 505, inf);
    fill(dis, dis + 505, inf);
    fill(times, times + 505, inf);
    fill(visited, visited + 505, 0);
    fill(numOfIntersections, numOfIntersections + 505, inf);
    for (int i = 0; i < 505; ++i) path[i] = i;
    int v1, v2, one_way, len, t;
    for (int i = 0; i < m; ++i) {
        cin >> v1 >> v2 >> one_way >> len >> t;
        eage[v1][v2] = len;
        consume[v1][v2] = t;
        if (!one_way) {
            eage[v2][v1] = len;
            consume[v2][v1] = t;
        }
    }
    int start, end;
    cin >> start >> end;
    dis[start] = 0;
    times[start] = 0;
    for (int i = 0; i < n; ++i) {
        int minn = inf, vertex = -1;
        for (int j = 0; j < n; ++j) {
            if (visited[j] == 0 && dis[j] < minn) {
                minn = dis[j];
                vertex = j;
            }
        }
        if (vertex == -1) break;
        visited[vertex] = 1;
        for (int j = 0; j < n; ++j) {
            if (visited[j] == 0 && eage[vertex][j] != inf) {
                if (dis[vertex] + eage[vertex][j] < dis[j]) {
                    dis[j] = dis[vertex] + eage[vertex][j];
                    path[j] = vertex;
                    times[j] = times[vertex] + consume[vertex][j];
                } else if (dis[vertex] + eage[vertex][j] == dis[j] &&
                           times[vertex] + consume[vertex][j] < times[j]) {
                    path[j] = vertex;
                    times[j] = times[vertex] + consume[vertex][j];
                }
            }
        }
    }
    int temp = end;
    shortestPath.push(temp);
    while (temp != start) {
        shortestPath.push(path[temp]);
        temp = path[temp];
    }
    fill(times, times + 505, inf);
    fill(visited, visited + 505, 0);
    times[start] = 0;
    numOfIntersections[start] = 1;
    for (int i = 0; i < n; ++i) {
        int minn = inf, vertex = -1;
        for (int j = 0; j < n; ++j) {
            if (visited[j] == 0 && times[j] < minn) {
                minn = times[j];
                vertex = j;
            }
        }
        if (vertex == -1) break;
        visited[vertex] = 1;
        for (int j = 0; j < n; ++j) {
            if (visited[j] == 0 && consume[vertex][j] != inf) {
                if (times[vertex] + consume[vertex][j] < times[j]) {
                    times[j] = times[vertex] + consume[vertex][j];
                    numOfIntersections[j] = numOfIntersections[vertex] + 1;
                    path[j] = vertex;
                } else if (times[vertex] + consume[vertex][j] == times[j] &&
                           numOfIntersections[vertex] + 1 <
                               numOfIntersections[j]) {
                    numOfIntersections[j] = numOfIntersections[vertex] + 1;
                    path[j] = vertex;
                }
            }
        }
    }
    temp = end;
    leastTimePath.push(temp);
    while (temp != start) {
        leastTimePath.push(path[temp]);
        temp = path[temp];
    }

    if (shortestPath != leastTimePath) {
        cout << "Distance = " << dis[end] << ": " << shortestPath.top();
        shortestPath.pop();
        while (!shortestPath.empty()) {
            cout << " -> " << shortestPath.top();
            shortestPath.pop();
        }
        cout << endl;
        cout << "Time = " << times[end] << ": " << leastTimePath.top();
        leastTimePath.pop();
        while (!leastTimePath.empty()) {
            cout << " -> " << leastTimePath.top();
            leastTimePath.pop();
        }
    } else {
        cout << "Distance = " << dis[end] << "; Time = " << times[end] << ": "
             << leastTimePath.top();
        leastTimePath.pop();
        while (!leastTimePath.empty()) {
            cout << " -> " << leastTimePath.top();
            leastTimePath.pop();
        }
    }

    return 0;
}