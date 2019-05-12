#include <iostream>
#include <cstdlib>

using namespace std;

template<class AType = int, int size = 10> class atype {
	AType a[size];
public:
	atype()
	{
		register int i;
		for (i = 0; i < size; i++) a[i] = 0;
	}
	AType &operator[] (int i);
};

template<class AType, int size> AType &atype<AType, size>::operator[](int i)
{
	if (i < 0 || i > size - 1)
	{
		cout << "\n Значення індексу ";
		cout << i << "виходить за межі допустимого діапазону. \n";
		exit(1);
	}
	return a[i];
	}

template<class AType> void show(AType* m, int n)
{
	for (int i = 0; i < n; i++) cout << m[i] << " ";
	cout << endl;
}

template<class AType> AType binarySearch(AType* m, int l, int r, int x)
{
	if (r >= l) {
		int mid = l + (r - l) / 2;
		if (m[mid] == x)
			return mid;
		if (m[mid] > x)
			return binarySearch(m, l, mid - 1, x);
		return binarySearch(m, mid + 1, r, x);
	}
	return -1;
}

template<class AType> void sort(AType* m, int n)
{
	show(m, n);
	AType s;
	for (int i = 1; i <= n - 1; i++) {
		for (int j = 0; j < n - 1; j++) {
			if (m[j] > m[j + 1]) {
				s = m[j + 1];
				m[j + 1] = m[j];
				m[j] = s;
			}
		}
	}
	show(m, n);
}

int main()
{
	system("chcp 1251>nul");
	// Цілочисельний масив
	atype<int, 5> intarray;
	int temp_int = 0;
	for (int i = 0; i < 5; i++) {
		cout << " \n Введіть елемент масиву №" << i;
		cin >> temp_int;
		intarray[i] = temp_int;
	}
	// Символьний масив
	char B[7] = { 'Z', 'B', 'Y', 'A', 'D', 'C', 'X' };
	//сортування масивів 
//	sort(intarray, 5);
//	sort(B, 7);
	int x = 3;
	int result = binarySearch(intarray, 0, 4, x);
	cout << "\n result = " << result << endl;
	system("pause>nul"); 
	return 0;
}