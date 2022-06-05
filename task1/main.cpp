#include <iostream>
using namespace std;

int N = 5;

void printArr(int* arr, int& n) {
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

// ���������: arr - ������, n - ������ �������,
//			  depth - ������� ������� ��������
void recursiveSort(int* arr, int n, int& depth) {
	bool isSort = false;
	for (int i = 0; i < n - 1; i++) {
		if (arr[i] > arr[i + 1]) {
			isSort = true;
			swap(arr[i], arr[i + 1]);
		}
	}
	if (isSort) {
		depth++;
		cout << "��� ��������: " << depth << ", ������:" << endl;
		printArr(arr, N);
		recursiveSort(arr, n - 1, depth);
	}
}

void sort(int* arr, int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				swap(arr[j], arr[j + 1]);
			}
		}
	}
}

int main() {
	setlocale(LC_ALL, "Russian");
	int n, depth = 0;
	int* arr;

	cout << "������� ������ �������: ";
	cin >> n;
	arr = new int[n];

	cout << "������� �������� �������:" << endl;
	for (int i = 0; i < n; i++) {
		cout << "i = " << i << ": ";
		cin >> arr[i];
	}

	cout << "�������� ������:" << endl;
	printArr(arr, n);
	recursiveSort(arr, n, depth);
	//sort(arr, n);
	cout << "��������������� ������:" << endl;
	printArr(arr, n);
	cout << "������� ��������: " << depth << endl;
	return 0;
}