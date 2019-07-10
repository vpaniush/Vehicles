#include<iostream>
#include<string>
#include "Header.h"
using namespace std;

void PrintAll(Vehicle **arr, int p, int s)
{
	for (int i = 0; i < p + s; i++)
	{
		arr[i]->Print();
	}
}

void SortByName(Vehicle **arr, int p, int s)
{
	Vehicle*v;
	for (int i = 0; i < p + s; i++)
	{
		for (int j = 0; j < p + s - i - 1; j++)
		{
			if (arr[j]->GetName() > arr[j + 1]->GetName())
			{
				v = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = v;
			}
		}
	}
	PrintAll(arr, p, s);
}

void SortByType(Vehicle **arr, int p, int s)
{
	Vehicle*v;
	for (int i = 0; i < p + s; i++)
	{
		for (int j = 0; j < p + s - i - 1; j++)
		{
			if (arr[j]->GetType() > arr[j + 1]->GetType())
			{
				v = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = v;
			}
		}
	}
	PrintAll(arr, p, s);
}

void SortByCapacity(Vehicle **arr, int p, int s)
{
	Vehicle*v;
	for (int i = 0; i < p + s; i++)
	{
		for (int j = 0; j < p + s - i - 1; j++)
		{
			if (arr[j]->GetCapacity() > arr[j + 1]->GetCapacity())
			{
				v = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = v;
			}
		}
	}
	PrintAll(arr, p, s);
}

int main()
{
	int p;
	cout << "Enter the number of planes: ";
	cin >> p;
	Plane*pl = new Plane[p];
	for (int i = 0; i < p; i++)
	{
		pl[i].EnterFields();
	}

	int s;
	cout << "Enter the number of ships: ";
	cin >> s;
	Ship*sh = new Ship[s];
	for (int i = 0; i < s; i++)
	{
		sh[i].EnterFields();
	}

	Vehicle **arr = new Vehicle*[p + s];
	for (int i = 0; i < p; i++)
	{
		arr[i] = &pl[i];
		arr[i]->Print();
	}
	for (int i = p; i < p + s; i++)
	{
		arr[i] = &sh[i - p];
		arr[i]->Print();
	}
	cout << endl;

	int k;
	cout << "Choose criterion:" << endl;
	cout << "1.Sort by name" << endl;
	cout << "2.Sort by type" << endl;
	cout << "3.Sort by capacity" << endl;
	cin >> k;
	switch (k)
	{
	case 1: SortByName(arr, p, s);
		break;
	case 2: SortByType(arr, p, s);
		break;
	case 3: SortByCapacity(arr, p, s);
	default:
		break;
	}

	delete[]arr;
	system("pause");
	return 0;
}