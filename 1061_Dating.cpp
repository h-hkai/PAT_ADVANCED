#include <bits/stdc++.h>

using namespace std;

int main() {
    string str1, str2, str3, str4;
    cin >> str1 >> str2 >> str3 >> str4;
    string week[7] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};
    int i = 0, j = 0, hour;
    string day;
    while (i < str1.length() && i < str2.length()) {
        if (str1[i] == str2[i] && (str1[i] >= 'A' && str1[i] <= 'G')) {
            day = week[str1[i] - 'A'];
            break;
        }
        i++;
    }
    i = i + 1;
    while (i < str1.length() && i < str2.length()) {
        if (str1[i] == str2[i]) {
            if (str1[i] >= 'A' && str1[i] <= 'N') {
                hour = str1[i] - 'A' + 10;
                break;
            } else if (isdigit(str1[i])) {
                hour = str1[i] - '0';
                break;
            }
        }
        i++;
    }
    while (j < str3.length() && j < str4.length()) {
        if (str3[j] == str4[j] && isalpha(str3[j])) break;
        j++;
    }
    cout << day;
    printf(" %02d:%02d\n", hour, j);
    return 0;
}