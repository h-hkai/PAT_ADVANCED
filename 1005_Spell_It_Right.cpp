#include <iostream>
#include <string>

using namespace std;

void digit_to_En(int x)
{
    switch (x)
    {
    case 1:
        cout << "one";
        break;
    case 2:
        cout << "two";
        break;
    case 3:
        cout << "three";
        break;
    case 4:
        cout << "four";
        break;
    case 5:
        cout << "five";
        break;
    case 6:
        cout << "six"; 
        break;
    case 7 : 
        cout << "seven";
        break;
    case 8:
        cout << "eight";
        break;
    case 9:
        cout << "nine";
        break;
    case 0:
        cout << "zero";
        break;
    default:
        break;
    }

    return ;
}

int main()
{

    string num;
    cin >> num;

    int first_digit = num[0] - '0';

    long sum = 0;
    for (int i = 0; i < num.length(); ++i)
    {
        int n = num[i] - '0';
        sum += n;
    }

    string sum_str = to_string(sum);

    digit_to_En(sum_str[0] - '0');
    for (int i = 1; i < sum_str.length(); ++i) 
    {
        int n = sum_str[i] - '0';
        cout << " ";
        digit_to_En(n);
    }

    return 0;
}