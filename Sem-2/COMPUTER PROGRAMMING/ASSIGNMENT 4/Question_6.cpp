#include <iostream>
#include <cmath>
using namespace std;

int main() {
    for (int i = 1; i <= 1000; i++) {
        int temp = i;
        int digitno = 0;
        while (temp != 0) {
            temp = temp / 10;
            digitno++;
        }
        
        int temp2 = i;
        int res = 0;
        while (temp2 != 0) {
            int k = temp2 % 10;
            res= res+ pow(k, digitno);
            temp2 = temp2 / 10;
        }
        if (res == i){
            cout << i << " ";
        }
    }
    return 0;
}

