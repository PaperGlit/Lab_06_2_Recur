#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_06_2_Recur/Lab_06_2_Recur.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

void Loop(int* a, int* c, const int size, int i)
{
	if (i < size)
	{
		Assert::AreEqual(c[i], a[i]);
		Loop(a, c, size, i + 1);
	}
}

int TestInitMax(int* a, const int size, int i, int max)
{
	if (i < size)
	{
		if (a[i] % 2 != 0)
		{
			max = a[i];
		}
		InitMax(a, size, i + 1, max);
	}
	else
		return max;
}

int TestInitiMax(int* a, const int size, int i, int max, int imax)
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

void Test(int* a, int* c, const int size, int i, int max, int imax)
{
	if (i < size)
	{
		if (a[i] % 2 != 0 && a[i] > max)
		{
			max = a[i];
			imax = i;
		}
		Test(a, c, size, i + 1, max, imax);
	}
	else
	{
		Assert::AreEqual(max, Max(a, size, 0, 0));
		Assert::AreEqual(imax, iMax(a, size, 0, 0, 0));
		int temp = a[size - 1];
		a[size - 1] = a[imax];
		a[imax] = temp;
		c = Swap(c, size);
		Loop(a, c, size, 0);
	}
}
namespace UnitTestLab062Recur
{
	TEST_CLASS(UnitTestLab062Recur)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			const int n = 10;
			int c[n];
			int* a = c;
			int Low = -10, High = 10;
			Create(c, n, Low, High, 0);
			Test(c, a, n, 0, TestInitMax(c, n, 0, 0), TestInitiMax(c, n, 0, 0, 0));
		}
	};
}