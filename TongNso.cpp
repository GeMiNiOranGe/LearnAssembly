//Tinh tong chuoi so 1 -> n
#include <iostream>
using namespace std;
int main() {
    int iSize, iSum, i = 1;
    cin >> iSize;

Loop:
    if (iSize < i) {
        goto EndLoop;
    }
    iSum = iSum + i;
    i = i + 1;
    goto Loop;
EndLoop:

    cout << iSum << endl;
    return 0;
}