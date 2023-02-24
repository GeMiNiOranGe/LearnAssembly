#include <iostream>
using namespace std;
int main()
{
    int diem;
    cin >> diem;
    if (-1 < diem && diem < 5) {
        cout << "yeu";
    }
    else if (4 < diem && diem < 7) {
        cout << "trung binh";
    }
    else if (6 < diem && diem < 9) {
        cout << "kha";
    }
    else if (diem == 9) {
        cout << "gioi";
    }
    else if (diem == 10) {
        cout << "xuat xac";
    }
    else {
        cout << "khong hop le";
    }
    cout << endl;
    system("pause");
    return 0;
}