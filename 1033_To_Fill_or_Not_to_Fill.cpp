#include <bits/stdc++.h>

using namespace std;

const int inf = 0x7fffffff;

struct Station {
    double price;
    double distance;
} sta[505];

bool cmp(Station a, Station b) { return a.distance < b.distance; }

int main() {
    int n;
    double c, dis, avg;
    cin >> c >> dis >> avg >> n;
    double price, distance;
    for (int i = 1; i <= n; ++i) {
        cin >> price >> distance;
        sta[i].price = price;
        sta[i].distance = distance;
    }
    sta[0] = {0.0, dis};
    sort(sta, sta + n + 1, cmp);
    double nowPrice = 0.0, totalprice = 0.0, leftdis = 0.0, nowdis = 0.0,
           maxdis = 0.0;
    // 如果第一个加油站不在起点的话，则直接结束
    if (sta[0].distance != 0) {
        cout << "The maximum travel distance = 0.00" << endl;
        return 0;
    } else {
        nowPrice = sta[0].price;
    }
    while (nowdis < dis) {
        maxdis = nowdis + c * avg;
        // 用来标记在所能达到的历程内是否有比当前加油站更便宜的汽油
        int flag = 0;
        // 在所能行驶的里程内，最便宜油价的加油站的距离和油价
        // 如果 minPrice = inf 则表示该加油站为最后一个加油站
        double minPirceDis = 0.0, minPrice = inf;
        // 从第二个加油站开始遍历，贪心寻找最便宜的加油站，使整个旅程的价格最低
        for (int i = 1; i <= n && sta[i].distance <= maxdis; ++i) {
            if (sta[i].distance <= nowdis) continue;
            // 在所能达到的历程中找到比当前油价更便宜的加油站
            if (nowPrice > sta[i].price) {
                flag = 1;
                // 在当前加油站加油，使tank中的油刚好能够到达比当前油价便宜的下一个加油站
                totalprice +=
                    (sta[i].distance - nowdis - leftdis) / avg * nowPrice;
                nowdis = sta[i].distance;
                nowPrice = sta[i].price;
                leftdis = 0.0;
                break;
            }
            // 寻找在所能达到的历程中，油价最便宜的加油站
            if (sta[i].price < minPrice) {
                minPrice = sta[i].price;
                minPirceDis = sta[i].distance;
            }
        }
        // 在当前所能达到的历程中，不存在比当前更便宜的加油站时
        if (flag == 0 && minPrice != inf) {
            // 因为不存在比当前油价更能便宜的加油站，所以应该在当前油站加满油箱，到达历程中油价最便宜的那个油站
            totalprice += nowPrice * (c - leftdis / avg);
            // 更新油箱中剩余油量所能行驶的距离
            leftdis = c * avg - (minPirceDis - nowdis);
            nowPrice = minPrice;
            nowdis = minPirceDis;
        }
        // 当前加油站为最后一个加油站,且没有到达目的地
        if (flag == 0 && minPrice == inf) {
            nowdis += c * avg;
            cout << "The maximum travel distance = " << fixed << setprecision(2)
                 << nowdis << endl;
            return 0;
        }
    }
    cout << fixed << setprecision(2) << totalprice << endl;
    return 0;
}