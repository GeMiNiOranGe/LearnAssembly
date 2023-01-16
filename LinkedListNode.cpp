#include <iostream>
#include <algorithm>
#include <ctime>

using namespace std;

struct Node {
	int data;
	Node *pNext;
};
struct List {
	Node *pHead;
	Node *pTail;
};

void initList(List &l);
Node* getNode(int _data);

void addHead(List &l, Node *p);
void addTail(List &l, Node *p);
void insertAt(List l, int _data, int index);

Node* searchPre(List l, Node *q);
Node* search(List l, int _data);

void removeHead(List &l);
void removeTail(List &l);
void removeAll(List &l, int _data);
void remove(List &l, int _data);

void selectionSort(List &l);
int getSize(List l);

void showList(List l) {
	Node* pWalker = l.pHead;
	for (; pWalker != NULL; pWalker = pWalker->pNext) {
		cout << pWalker->data << " ";
	}
}
int random(int minN, int maxN) {
	return minN + rand() % (maxN + 1 - minN);
}

int main() {
    List l;
    initList(l);
    srand((int)time(0));
	const int length = 15;
	const int minData = 1;
	const int maxData = 10;
	int numRemoved = 1/*random(minData, maxData)*/;
	for (int i = 0; i < length; i++) {
		addTail(l, getNode(random(minData, maxData)));
	}
	selectionSort(l);
	showList(l);
	cout << endl;
	cout << "Number will be removed: " << numRemoved << endl;
	removeAll(l, numRemoved);
	showList(l);
	cout << endl << "---------------------------------------------------" << endl;
    return 0;
}

void initList(List &l) {
    l.pHead = NULL;
	l.pTail = NULL;
}
Node* getNode(int _data) {
	Node *p = new Node;
	p->pNext = NULL;
	p->data = _data;
	return p;
}

void addHead(List &l, Node *p) {
	if (l.pHead == NULL) 
		l.pHead = l.pTail = p;
	else {
		p->pNext = l.pHead;
		l.pHead = p;
	}
}
void addTail(List &l, Node *p) {
	if (l.pHead == NULL)
		l.pHead = l.pTail = p;
	else {
		l.pTail->pNext = p;
		l.pTail = p;
	}
}
void insertAt(List l, int _data, int index) {
	if (l.pHead == NULL || index <= 0)
		addHead(l, getNode(_data));
	else if (index > getSize(l))
		addTail(l, getNode(_data));
	else {
		Node* pTemp = l.pHead;
		for (int i = 0; i < index - 1; i++)
			pTemp = pTemp->pNext;
		Node* pAdd = getNode(_data);
		pAdd->pNext = pTemp->pNext;
		pTemp->pNext = pAdd;
	}
}

Node* searchPre(List l, Node *q) {
	Node* p = l.pHead;
	if (p == q)
		return NULL;
	while ((p != NULL) && (p->pNext != q))
		p = p->pNext;
	return p;
}
Node* search(List l, int _data) {
	Node* pSearch = l.pHead;
	for (; pSearch != NULL && pSearch->data != _data; pSearch = pSearch->pNext);
	return pSearch;
}

void removeHead(List &l) {
	if (l.pHead != NULL) {
		Node* pRemove = l.pHead;
		l.pHead = l.pHead->pNext;
		delete pRemove;
		if (l.pHead == NULL)
			l.pTail = NULL;
	}
}
void removeTail(List &l) {
	if (l.pHead == NULL)
		return;
	Node* pRemove = l.pTail;
	l.pTail = searchPre(l, l.pTail);
	delete pRemove;
	if (l.pTail != NULL)
		l.pTail->pNext = NULL;
	else
		l.pHead = NULL;
}
void removeAll(List &l, int _data) {
	for (Node* pWalker = l.pHead; pWalker != NULL; pWalker = pWalker->pNext) {
		if (pWalker->data == _data) {
			Node* pTemp = pWalker;
			pWalker = searchPre(l, pWalker);
			remove(l, pTemp->data);
			if (pWalker == NULL) pWalker = l.pHead;
		}
	}
    if (l.pHead->data == _data)
        removeHead(l);
}
void remove(List &l, int _data) {
	Node* pWalker = l.pHead, *pTemp = NULL;
	if (pWalker == l.pHead && pWalker != NULL && pWalker->data == _data) {
		removeHead(l);
		return;
	}
	for (; pWalker != NULL && pWalker->data != _data; pWalker = pWalker->pNext)
		pTemp = pWalker;
	if (pWalker == NULL)
		return;
	if (pTemp != NULL) {
		if (pWalker == l.pTail) {
			l.pTail = pTemp;
			l.pTail->pNext = NULL;
		}
		pTemp->pNext = pWalker->pNext;
		delete pWalker;
	}
}

void selectionSort(List &l) {
	Node *pMin, *pFirst, *pSecond;
	for (pFirst = l.pHead; pFirst != NULL; pFirst = pFirst->pNext) {
		pMin = pFirst;
		for (pSecond = pFirst->pNext; pSecond != NULL; pSecond = pSecond->pNext)
			if (pSecond->data < pMin->data)
				pMin = pSecond;
		swap(pMin->data, pFirst->data);
	}
}
int getSize(List l) {
	Node *p = l.pHead;
	int iSize = 0;
	for (; p != NULL; p = p->pNext)
		iSize++;
	return iSize;
}