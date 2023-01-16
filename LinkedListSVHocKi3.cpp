#include <iostream>
#include <string>

using namespace std;

struct SV {
    string _strMaSV;
    string _strHoTen;
    float _fDiemGiuaKy;
    float _fDiemCuoiKy;
    SV* _pNext;
};
struct List {
    SV* _pHead;
    SV* _pTail;
};

void khoiTaoList(List &_list);
SV* khoiTaoSinhVien(string ten, string mssv, float diemGiuaKy, float diemCuoiKy);

#pragma region cau a
void selectionSort(List &_list);
void themSinhVien(List &_list, string ten, string mssv, float diemGiuaKy, float diemCuoiKy);
#pragma endregion

#pragma region cau b
int soLuongThiDau(List , float diemChuan);
#pragma endregion
// #pragma region cau d
// SV* searchPre(List _list, SV* _sinhVien);
// void removeHead(List &_list);
// void removeAll(List &_list, char _data);
// void remove(List &_list, char _data);
// #pragma endregion

void xuat(List _list);

int main() {
    List list;
    khoiTaoList(list);
	#pragma region insert data
    themSinhVien(list, "Nguyen Thien An", "47.01.104.023", 6.5, 9.5);
    themSinhVien(list, "Pham Thi Anh Giau", "47.01.104.320", 9.5, 5);
    themSinhVien(list, "Huynh Tuan Kiet", "47.01.104.893", 1.2, 7.5);
    themSinhVien(list, "Nguyen Thi Truc", "47.01.104.423", 5.6, 2.5);
    themSinhVien(list, "Pham Thuy Van Anh", "47.01.104.093", 0, 8.4);
    themSinhVien(list, "Huynh Tran Thu An", "47.01.104.133", 0, 4.2);
    themSinhVien(list, "Nguyen Ngoc Mai", "47.01.104.300", 5.5, 6.5);
    themSinhVien(list, "Pham Tran Tan Ky", "47.01.104.003", 1.5, 10);
    themSinhVien(list, "Tran Thanh Truc", "47.01.104.029", 4.2, 0.5);
    themSinhVien(list, "Pham Tran Minh An", "47.01.104.090", 10, 10);
	#pragma endregion
    // removeAll(list, 'Y');
    xuat(list);
    cout << "------------------------------------" << endl;
	cout << "So sinh vien dau mon CTDL la: " << soLuongThiDau(list, 4);
    return 0;
}

void khoiTaoList(List &_list) {
    _list._pHead = NULL;
    _list._pTail = NULL;
}
SV* khoiTaoSinhVien(string ten, string mssv, float diemGiuaKy, float diemCuoiKy) {
    SV* p = new SV;
    p->_pNext = NULL;
    p->_strHoTen = ten;
    p->_strMaSV = mssv;
    p->_fDiemGiuaKy = diemGiuaKy;
    p->_fDiemCuoiKy = diemCuoiKy;
    return p;
}

#pragma region cau a
void selectionSort(List &_list) {
	SV *pMin, *pFirst, *pSecond;
	for (pFirst = _list._pHead; pFirst != NULL; pFirst = pFirst->_pNext) {
		pMin = pFirst;
		for (pSecond = pFirst->_pNext; pSecond != NULL; pSecond = pSecond->_pNext)
			if (pSecond->_strMaSV.compare(pMin->_strMaSV) < 0)
				pMin = pSecond;
		swap(pMin->_strHoTen, pFirst->_strHoTen);
		swap(pMin->_strMaSV, pFirst->_strMaSV);
		swap(pMin->_fDiemGiuaKy, pFirst->_fDiemGiuaKy);
		swap(pMin->_fDiemCuoiKy, pFirst->_fDiemCuoiKy);
	}
}

void themSinhVien(List &_list, string ten, string mssv, float _fDiemGiuaKy, float _fDiemCuoiKy) {
    SV* p = khoiTaoSinhVien(ten, mssv, _fDiemGiuaKy, _fDiemCuoiKy);
	if (_list._pHead == NULL)
		_list._pHead = _list._pTail = p;
	else {
		p->_pNext = _list._pHead;
		_list._pHead = p;
	}
	selectionSort(_list);
}
#pragma endregion

#pragma region cau b
int soLuongThiDau(List l, float diemChuan) {
	int count = 0;
	for (SV* pWalker = l._pHead; pWalker != NULL; pWalker = pWalker->_pNext)
		if ((pWalker->_fDiemGiuaKy + pWalker->_fDiemCuoiKy) / 2 >= diemChuan)
			count++;
    return count;
}
#pragma endregion

// #pragma region cau d
// SV* searchPre(List _list, SV* _sinhVien) {
// 	SV* pSearchPre = _list._pHead;
// 	if (pSearchPre == _sinhVien)
// 		return NULL;
// 	for (; pSearchPre != NULL && pSearchPre->_pNext != _sinhVien; pSearchPre = pSearchPre->_pNext);
// 	return pSearchPre;
// }
// void removeHead(List &_list) {
// 	if (_list._pHead != NULL) {
// 		SV* pRemove = _list._pHead;
// 		_list._pHead = _list._pHead->_pNext;
// 		delete pRemove;
// 		if (_list._pHead == NULL)
// 			_list._pTail = NULL;
// 	}
// }
// void removeAll(List &_list, char _data) {
// 	for (SV* pWalker = _list._pHead; pWalker != NULL; pWalker = pWalker->_pNext) {
// 		if (pWalker->_cLoai == _data) {
// 			SV* pTemp = pWalker;
// 			pWalker = searchPre(_list, pWalker);
// 			remove(_list, pTemp->_cLoai);
// 			if (pWalker == NULL) pWalker = _list._pHead;
// 		}
// 	}
// 	if (_list._pHead->_cLoai == _data)
//         removeHead(_list);
// }
// void remove(List &_list, char _data) {
// 	SV* pWalker = _list._pHead, *pTemp = NULL;
// 	if (pWalker == _list._pHead && pWalker != NULL && pWalker->_cLoai == _data) {
// 		removeHead(_list);
// 		return;
// 	}
// 	for (; pWalker != NULL && pWalker->_cLoai != _data; pWalker = pWalker->_pNext)
// 		pTemp = pWalker;
// 	if (pWalker == NULL)
// 		return;
// 	if (pTemp != NULL) {
// 		if (pWalker == _list._pTail) {
// 			_list._pTail = pTemp;
// 			_list._pTail->_pNext = NULL;
// 		}
// 		pTemp->_pNext = pWalker->_pNext;
// 		delete pWalker;
// 	}
// }
// #pragma endregion

void xuat(List _list) {
    for (SV *p = _list._pHead; p != NULL; p = p->_pNext) {
        cout << "------------------------------------" << endl;
        cout << "Ho va ten: " << p->_strHoTen << endl;
        cout << "MSSV: " << p->_strMaSV << endl;
        cout << "Diem giua ky: "<< p->_fDiemGiuaKy << endl;
        cout << "Diem cuoi ky: "<< p->_fDiemCuoiKy << endl;
    }
}