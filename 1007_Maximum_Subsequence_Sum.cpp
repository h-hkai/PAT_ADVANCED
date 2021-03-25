#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> arr;
    for (int i = 0; i < n; ++i) {
        int num;
        cin >> num;
        arr.push_back(num);
    }

    int sum = -1, left = 0, right = n - 1;
    int temp = 0, tempLeft = 0;
    for (int i = 0; i < n; ++i) {
        temp += arr[i];
        if (temp < 0) {
            temp = 0;
            tempLeft = i + 1;
        } else if (temp > sum) {
            sum = temp;
            left = tempLeft;
            right = i;
        }
    }

    if (sum < 0) sum = 0;
    cout << sum << " " << arr[left] << " " << arr[right];

    return 0;
}