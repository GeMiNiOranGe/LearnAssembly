#include <iostream>
using namespace std;
int main() {
    int count, i;
    cin >> count;
    i = 0;
Loop:
    if (i >= count) {
        goto EndFor;
    }
    if (i % 2 == 0) {
        goto Chan;
    }
    cout << "So thu " << i << " la so le" << endl;
    goto EndIf;
Chan:
    cout << "So thu " << i << " la so chan" << endl;
EndIf:
    i = i + 1;
    goto Loop;
EndFor:
    return 0;
}