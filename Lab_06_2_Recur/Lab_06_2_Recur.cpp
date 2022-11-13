#include <iostream>
#include <time.h>
#include <windows.h>

using namespace std;

void Create(int* a, const int size, const int Low, const int High, int i)
{
	if (i < size)
	{
		a[i] = Low + rand() % (High - Low + 1);
		Create(a, size, Low, High, i + 1);
	}
}

void Print(int* a, const int size, int i)
{
	if (i < 1)
		cout << "Значення масиву : ";
	if (i < size)
	{
		cout << a[i] << " ";
		Print(a, size, i + 1);
	}
	else
		cout << endl;
}

int InitMax(int* a, const int size, int i, int max)
{
	if (i < size)
	{
		if (a[i] % 2 != 0)
			max = a[i];
		InitMax(a, size, i + 1, max);
	}
	else
		return max;
}

int Max(int* a, const int size, int i, int max)
{
	if (i < size)
	{
		if (a[i] % 2 != 0 && a[i] > max)
			max = a[i];
		Max(a, size, i + 1, max);
	}
	else
		return max;
}

int InitiMax(int* a, const int size, int i, int max, int imax)
{
	if (i < size)
	{
		if (a[i] % 2 != 0 && a[i] > max)
		{
			max = a[i];
			imax = i;
		}
		InitiMax(a, size, i + 1, max, imax);
	}
	else
		return imax;
}

int iMax(int* a, const int size, int i, int max, int imax)
{
	if (i < size)
	{
		if (a[i] % 2 != 0 && a[i] > max)
		{
			max = a[i];
			imax = i;
		}
		iMax(a, size, i + 1, max, imax);
	}
	else
		return imax;
}

int* Swap(int* a, const int size)
{
	int imax = iMax(a, size, 0, InitMax(a, size, 0, 0), InitiMax(a, size, 0, 0, 0));
	int temp = a[size - 1];
	a[size - 1] = a[imax];
	a[imax] = temp;
	return a;
}

int main()
{
	SetConsoleOutputCP(1251);
	srand((unsigned)time(NULL));

	int n, Low, High;

	cout << "n = "; cin >> n;
	cout << "min = "; cin >> Low;
	cout << "max = "; cin >> High;

	int* c = new int[n];

	Create(c, n, Low, High, 0);
	Print(c, n, 0);
	cout << "Значення, яке підходить вимогам : " << Max(c, n, 0, InitMax(c, n, 0, 0)) << endl;
	Print(Swap(c, n), n, 0);

	return 0;
}