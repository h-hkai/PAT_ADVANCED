#include <bits/stdc++.h>

using namespace std;

const int inf = 0x7fffffff;

int n, m, k, t;

struct Player {
    int arriving_time;
    int starting_time = inf;
    int playing_time;
    int isVip;
} players[10005];

struct Table {
    int count = 0;
    int end = 8 * 3600;
    int isVip = 0;
} tables[105];

int parse(string str) {
    int hh = stoi(str.substr(0, 2));
    int mm = stoi(str.substr(3, 2));
    int ss = stoi(str.substr(6, 2));
    return hh * 3600 + mm * 60 + ss;
}

bool cmp1(Player a, Player b) { return a.arriving_time < b.arriving_time; }
bool cmp2(Player a, Player b) { return a.starting_time < b.starting_time; }

// 更新player的开始时间和table的end time
void update(int playerId, int tableId) {
    if (players[playerId].arriving_time <= tables[tableId].end) {
        players[playerId].starting_time = tables[tableId].end;
    } else {
        players[playerId].starting_time = players[playerId].arriving_time;
    }
    tables[tableId].end =
        players[playerId].starting_time + players[playerId].playing_time;
    tables[tableId].count++;
}

int findNextVip(int vipId) {
    vipId++;
    while (vipId < n && players[vipId].isVip == 0) vipId++;
    return vipId;
}

int main() {
    cin >> n;
    string arriving_time;
    int playing_time;
    int isVip;
    for (int i = 0; i < n; ++i) {
        cin >> arriving_time >> playing_time >> isVip;
        players[i].arriving_time = parse(arriving_time);
        players[i].playing_time =
            (playing_time > 120 ? 120 * 60 : playing_time * 60);
        players[i].isVip = isVip;
    }

    sort(players, players + n, cmp1);

    cin >> m >> k;
    for (int i = 0; i < k; ++i) {
        cin >> t;
        tables[t].isVip = 1;
    }

    int i = 0, vipId = -1;
    vipId = findNextVip(vipId);
    while (i < n) {
        int index = -1, minEndTime = inf;
        for (int j = 1; j <= m; ++j) {
            if (tables[j].end < minEndTime) {
                index = j;
                minEndTime = tables[j].end;
            }
        }
        if (tables[index].end >= 21 * 3600) break;
        if (players[i].isVip == 1 && i < vipId) {
            i++;
            continue;
        }
        // 如果是vip table
        if (tables[index].isVip == 1) {
            if (players[i].isVip == 1) {
                update(i, index);
                if (i = vipId) vipId = findNextVip(vipId);
                ++i;
            } else {
                // 考虑所排队列中是否有vip player
                if (vipId < n &&
                    players[vipId].arriving_time <= tables[index].end) {
                    update(vipId, index);
                    vipId = findNextVip(vipId);
                } else {
                    update(i, index);
                    ++i;
                }
            }
        } else {
            if (players[i].isVip == 0) {
                update(i, index);
                ++i;
            } else {
                int vipIndex = -1, minVipEndTime = inf;
                for (int j = 1; j <= m; ++j) {
                    if (tables[j].isVip == 1 && minVipEndTime > tables[j].end) {
                        vipIndex = j;
                        minVipEndTime = tables[j].end;
                    }
                }
                if (vipIndex != -1 &&
                    players[i].arriving_time >= tables[vipIndex].end) {
                    update(i, vipIndex);
                    if (vipId == i) vipId = findNextVip(vipId);
                    ++i;
                } else {
                    update(i, index);
                    if (vipId == i) vipId = findNextVip(vipId);
                    ++i;
                }
            }
        }
    }
    sort(players, players + n, cmp2);
    for (int i = 0; i < n && players[i].starting_time < 21 * 3600; ++i) {
        printf("%02d:%02d:%02d ", players[i].arriving_time / 3600,
               players[i].arriving_time % 3600 / 60,
               players[i].arriving_time % 60);
        printf("%02d:%02d:%02d ", players[i].starting_time / 3600,
               players[i].starting_time % 3600 / 60,
               players[i].starting_time % 60);
        printf("%.01d\n",
               (players[i].starting_time - players[i].arriving_time + 59) / 60);
    }
    for (int i = 1; i <= m; ++i) {
        if (i != 1) cout << " ";
        cout << tables[i].count;
    }
    return 0;
}