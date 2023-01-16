#include <iostream>
using namespace std;
int main() {
    int a, b;
    cin >> a >> b;
Loop:
    if (a == b) {
        goto EndLoop;
    }
//     if (a < b) {
//         goto A_Smaller;
//     }
//     else {
//         goto B_Otherwise;
//     }
// A_Smaller:
//     b = b - a;
//     goto EndIf;
// B_Otherwise:
//     a = a - b;
//     goto EndIf;
// EndIf:
    if(a < b)
        goto B;
A:
    a = a - b;
    goto Loop;
B:
    b = b - a;
    goto Loop;
EndLoop:

    cout << "UCLN la : ";
    cout << a << endl;
    system("pause");
    return 0;
}