#include <iostream>
#include <time.h>

using namespace std;

int random(int minN, int maxN);

void interchangeSort(int a[], int n);
void selectionSort(int a[], int n);
void insertionSort(int a[], int n);
void bubbleSort(int a[], int n);

void generateArrayRanN(int a[], int count, int minN, int maxN);
void printArray(int a[], int count);

int main() {
    srand((int)time(0));
    const int iSize = 12;
    int a[iSize];
    generateArrayRanN(a, sizeof(a) / sizeof(a[0]), 1, 100);
    printArray(a, sizeof(a) / sizeof(a[0]));
    // bubbleSort(a, sizeof(a) / sizeof(a[0]));
    return 0;
}

int random(int minN, int maxN) {
    return minN + rand() % (maxN + 1 - minN);
}

void interchangeSort(int a[], int n) {
	for(int i = 0; i < n - 1; i++) {
		for(int j = i + 1; j < n; j++)
			if(a[i] > a[j])
				swap(a[i], a[j]);
        printArray(a, n);
	}
}
void selectionSort(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++)
            if (a[j] < a[min_idx])
                min_idx = j;
        swap(a[min_idx], a[i]);
        printArray(a, n);
    }
}
void insertionSort(int a[], int n) {
    for (int i = 1; i < n; i++) {
        int j, key = a[i]; 
        for (j = i - 1; j >= 0 && a[j] > key; j--)
            a[j + 1] = a[j];
        a[j + 1] = key;
        printArray(a, n);
    }
}
void bubbleSort(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++)
            if (a[j] > a[j + 1])
                swap(a[j], a[j + 1]);
        printArray(a, n);
    }
}

void generateArrayRanN(int a[], int count, int minN, int maxN) {
    for (int i = 0; i < count; i++)
        a[i] = random(minN, maxN);
}
void printArray(int a[], int count){
    for (int i = 0; i < count; i++)
        cout << a[i] << " ";
    cout << endl;
}