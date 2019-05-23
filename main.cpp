#include<iostream>
using namespace std;

#define delimiter "\n----------------------------------\n"

void FillRand(int** Arr, const int m, const int n);
void Print(int** Arr, const int m, const int n);

void Push_row_back(int *** Arr, int& m, const int n);
void Push_row_front(int *** Arr, int& m, const int n);
void Insert_row(int *** Arr, int& m, const int n, int index);
void Pop_row_back(int *** Arr, int& m, const int n);
void Pop_row_front(int *** Arr, int& m, const int n);
void Erase_row(int *** Arr, int& m, const int n, int index);

int** Push_col_back(int** Arr, const int m, int& n);
int** Push_col_front(int** Arr, const int m, int& n);
int** Insert_col(int** Arr, const int m, int& n, int index);
int** Pop_col_back(int** Arr, int m, int& n);
int** Pop_col_front(int** Arr, const int m, int& n);
int** Erase_col(int** Arr, const int m, int& n, int index);

void main()
{
	setlocale(LC_ALL, "rus");

	// Двумерный динамический массив:
	int m; //Количество строк двумерногог масива;
	int n; //Количество элементов строки (столбцов);
	cout << "Введите количество строк: "; cin >> m;
	cout << "Введите количество элементов строки (столбцов): "; cin >> n;
	//	Объявленипе ДДМ:
	//1) Создаём массив указателей:
	int** Arr = new int*[m];
	// 2) Выдиляем пымять под строки:
	for (int i = 0; i < m; i++)
	{
		Arr[i] = new int[n];
	}

	// Обращенние к элементам ДДМ:
	FillRand(Arr, m, n);
	Print(Arr, m, n);
	cout << delimiter << endl;
	Push_row_back(&Arr, m, n);
	Print(Arr, m, n);
	cout << delimiter << endl;
	Push_row_front(&Arr, m, n);
	Print(Arr, m, n);

	int index;
	cout << delimiter << endl;
	cout << "....? "; cin >> index;
	Insert_row(&Arr, m, n, index);
	Print(Arr, m, n);
	cout << delimiter << endl;
	Pop_row_back(&Arr, m, n);
	Print(Arr, m, n);
	cout << delimiter << endl;
	Pop_row_front(&Arr, m, n);
	Print(Arr, m, n);
	cout << delimiter << endl;
	cout << "Введите индекс удаляемой строки: "; cin >> index;
	Erase_row(&Arr, m, n, index);
	Print(Arr, m, n);

	cout << delimiter << endl;
	Push_col_back(Arr, m, n);
	Print(Arr, m, n);
	cout << delimiter << endl;
	Push_col_front(Arr, m, n);
	Print(Arr, m, n);
	cout << delimiter << endl;
	cout << "....? "; cin >> index;
	Insert_col(Arr, m, n, index);
	Print(Arr, m, n);
	cout << delimiter << endl;
	Pop_col_back(Arr, m, n);
	Print(Arr, m, n);
	cout << delimiter << endl;
	Pop_col_front(Arr, m, n);
	Print(Arr, m, n);
	cout << delimiter << endl;
	Erase_col(Arr, m, n, index);
	Print(Arr, m, n);
	//		Удаление ДДМ:
	//1) Удаляем строки:
	for (int i = 0; i < m; i++)
	{
		delete[] Arr[i];
	}
	//2) Удаление массива указателей:
	delete[] Arr;
}

void FillRand(int** Arr, const int m, const int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			Arr[i][j] = rand() % 100;
		}
	}
}

void Print(int** Arr, const int m, const int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << Arr[i][j] << "\t";
		}
		cout << endl;
	}
}

void Push_row_back(int *** Arr, int& m, const int n)
{
	int** Buffer = new int*[m + 1];

	for (int i = 0; i < m; i++)
	{
		Buffer[i] = (*Arr)[i];
	}
	delete[](*Arr);
	(*Arr) = Buffer;
	(*Arr)[m] = new int[n + 1]{};
	m++;
	//return (*Arr);
}

void Push_row_front(int *** Arr, int& m, const int n)
{
	int** Buffer = new int*[m + 1];

	for (int i = 0; i < m; i++)
	{
		Buffer[i + 1] = (*Arr)[i];
	}
	delete[](*Arr);
	(*Arr) = Buffer;
	(*Arr)[0] = new int[n] {};
	m++;
	//return (*Arr);
}

void Insert_row(int *** Arr, int& m, const int n, int index)
{
	int** Buffer = new int*[m + 1];

	for (int i = 0; i < index; i++)
	{
		Buffer[i] = (*Arr)[i];
	}
	for (int i = index; i < m; i++)
	{
		Buffer[i + 1] = (*Arr)[i];
	}
	delete[](*Arr);
	(*Arr) = Buffer;
	(*Arr)[index] = new int[n] {};
	m++;
	//return Arr;
}

void Pop_row_back(int *** Arr, int& m, const int n)
{
	int** Buffer = new int*[--m];
	for (int i = 0; i < m; i++)
	{
		Buffer[i] = (*Arr)[i];
	}
	delete[](*Arr);
	(*Arr) = Buffer;
	//return (*Arr);
}

void Pop_row_front(int *** Arr, int& m, const int n)
{
	int** Buffer = new int*[--m];

	for (int i = 0; i < m; i++)
	{
		Buffer[i] = (*Arr)[i + 1];
	}
	delete[](*Arr);
	(*Arr) = Buffer;
	//return (*Arr);
}

void Erase_row(int *** Arr, int& m, const int n, int index)
{
	int** Buffer = new int*[--m];
	for (int i = 0; i < index; i++)
	{
		Buffer[i] = (*Arr)[i];
	}
	for (int i = index; i < m; i++)
	{
		Buffer[i] = (*Arr)[i + 1];
	}
	delete[](*Arr);
	(*Arr) = Buffer;
	//return (*Arr);
}

int** Push_col_back(int** Arr, const int m, int& n)
{
	for (int i = 0; i < m; i++)
	{
		int* Buffer = new int[n + 1]{};
		for (int j = 0; j < n; j++)
		{
			Buffer[j] = Arr[i][j];
		}
		delete[] Arr[i];
		Arr[i] = Buffer;
	}
	n++;
	return Arr;
}

int** Push_col_front(int** Arr, const int m, int& n)
{
	for (int i = 0; i < m; i++)
	{
		int* Buffer = new int[n + 1]{};
		for (int j = 0; j < n; j++)
		{
			Buffer[j + 1] = Arr[i][j];
		}
		delete[] Arr[i];
		Arr[i] = Buffer;
	}
	n++;
	return Arr;
}

int** Insert_col(int** Arr, const int m, int& n, int index)
{
	for (int i = 0; i < m; i++)
	{
		int* Buffer = new int[n + 1]{};
		for (int j = 0; j < index; j++)
		{
			Buffer[j] = Arr[i][j];
		}
		for (int j = index; j < n; j++)
		{
			Buffer[j + 1] = Arr[i][j];
		}
		delete[] Arr[i];
		Arr[i] = Buffer;
	}
	n++;
	return Arr;
}

int** Pop_col_back(int** Arr, int m, int& n)
{
	for (int i = 0; i < m; i++)
	{
		int* Buffer = new int[n] {};
		for (int j = 0; j < n; j++)
		{
			Buffer[j] = Arr[i][j];
		}
		delete[] Arr[i];
		Arr[i] = Buffer;
	}
	n--;
	return Arr;
}

int** Pop_col_front(int** Arr, const int m, int& n)
{
	for (int i = 0; i < m; i++)
	{
		int* Buffer = new int[n] {};
		for (int j = 0; j < n; j++)
		{
			Buffer[j] = Arr[i][j + 1];
		}
		delete[] Arr[i];
		Arr[i] = Buffer;
	}
	n--;
	return Arr;
}

int** Erase_col(int** Arr, const int m, int& n, int index)
{
	for (int i = 0; i < m; i++)
	{
		int* Buffer = new int[n] {};
		for (int j = 0; j < index; j++)
		{
			Buffer[j] = Arr[i][j];
		}
		for (int j = index; j < n; j++)
		{
			Buffer[j] = Arr[i][j + 1];
		}
	}
	n--;
	return Arr;
}