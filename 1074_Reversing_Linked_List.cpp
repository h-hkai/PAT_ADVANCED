#include <bits/stdc++.h>

using namespace std;

int main() {
    int start, n, k;
    cin >> start >> n >> k;
    int address, val, next;
    int date[100005], nextNode[100005], list[100005], ans[100005];
    for (int i = 0; i < n; ++i) {
        cin >> address;
        cin >> date[address] >> nextNode[address];
    }
    int first = start, index = 0;
    while (first != -1) {
        list[index++] = first;
        first = nextNode[first];
    }
    for (int i = 0; i < index; ++i) ans[i] = list[i];
    for (int i = 0; i < index - index % k; ++i)
        ans[i] = list[i / k * k + k - i % k - 1];
    for (int i = 0; i < index - 1; ++i) {
        printf("%05d %d %05d\n", ans[i], date[ans[i]], ans[i + 1]);
    }
    printf("%05d %d -1\n", ans[index - 1], date[ans[index - 1]]);

    return 0;
}