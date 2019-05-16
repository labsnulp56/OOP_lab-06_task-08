#include <iostream>
#include <cstdlib>

using namespace std;

template<typename T> class OrderedArray 
{
private: 
	int size;
	T* arr;
protected:
	void InitArray(T value);
	int OrderedArray<T>::BinarySearch(T* m, int l, int r, int x);
public:
	OrderedArray(int size, T value);
	~OrderedArray();
	T &operator [](int i);
	int OrderedArray<T>::Search(T* m, int x);
};

template<typename T> T & OrderedArray <T>::operator[](int i)
{
	if (i < 0 || i > this->size - 1)
	{
		throw("Індекс виходить за межі масиву \n");

	}
	return arr[i];
}

template<typename T>
int OrderedArray<T>::Search(T * m, int x)
{
	return BinarySearch(m, 0, this->size, x);
}

template<typename T> OrderedArray<T>::OrderedArray(int size, T value)
{
	this->size = size;
	this->arr = new T[this->size];
	this->InitArray(value);
}

template<typename T> OrderedArray<T>::~OrderedArray()
{
	delete[]arr;
}

template<typename T> void OrderedArray<T>::InitArray(T value)
{
	for (int i = 0; i < this->size; i++)
	{
		this->arr[i] = i; 
	}
	cout << "Знаходимо індекс числа 2 = " << Search(arr, 2) << endl;
}

template<typename T> int OrderedArray<T>::BinarySearch(T *m, int l, int r, int x)
{
	if (r >= l)
	{
		int mid = l + (r - l) / 2;
		if (arr[mid] == x)
		{
			return mid;
		}
		if (arr[mid] > x)
		{
			return BinarySearch(this->arr, l, mid - 1, x);
		}
		return BinarySearch(this->arr, mid + 1, r, x);
	}
	return -1;
}

int main()
{
	system("chcp 1251");
	OrderedArray<int>intob(4, 0);
	OrderedArray<double>doubleob(4, 0);
	double a = 2.5;

	cout << "Масив int" << endl;
	for (int i = 0; i < 4; i++)
	{
		cout << intob[i] << " ";
	}
	
	cout << "\nМасив double" << endl;

	for (int i = 0; i < 4; i++)
	{
		doubleob[i] = a;
		a+=.85;
	}

	for (int i = 0; i < 4; i++)
	{
		cout << doubleob[i] << " ";
	}
	cout << "\n";
	system("pause");
	return 0;
	
}