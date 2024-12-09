#include <iostream>
#include <cmath>

using namespace std;

int countDigits(int num) {
    int count = 0;
    while (num > 0) {
        num /= 10;
        count++;
    }
    return count;
}

bool isArmstrong(int num) {
    int originalNum = num;
    int sum = 0;
    int digits = countDigits(num);

    while (num > 0) {
        int digit = num % 10;
        sum += pow(digit, digits);
        num /= 10;
    }

    return (sum == originalNum);
}

int main() {
    cout << "Armstrong numbers between 1 and 1000 are:" << endl;

    for (int i = 1; i <= 1000; ++i) {
        if (isArmstrong(i)) {
            cout << i << " ";
        }
    }

    cout << endl;

    return 0;
}
