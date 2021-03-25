#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    int count = 0;
    char in[50], out[50];
    double temp, sum = 0.0;
    for (int i = 0; i < n; ++i) {
        scanf("%s", in);
        sscanf(in, "%lf", &temp);
        sprintf(out, "%.2f", temp);
        bool isLegal = false;
        for (int j = 0; j < strlen(in); ++j) {
            if (in[j] != out[j]) {
                isLegal = true;
            }
        }
        if (isLegal || temp > 1000 || temp < -1000) {
            printf("ERROR: %s is not a legal number\n", in);
        } else {
            sum += temp;
            count++;
        }
    }
    if (count == 1)
        printf("The average of 1 number is %.2f", sum);
    else if (count > 1) {
        double average = sum / count;
        printf("The average of %d numbers is %.2f", count, average);
    } else {
        printf("The average of 0 numbers is Undefined");
    }

    return 0;
}