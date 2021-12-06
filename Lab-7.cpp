#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;


void TaskVariant()
{
	//подсчет варианта
	int K, N, Z;
	K = 0;
	N = 0;
	cout << "Variant:\n";
	cin >> N;
	for (K = 1; K <= 5; K++)
	{
		Z = (N + (K - 1) * 23) + 902;
		cout << "Z(" << K << ") = " << Z;
		cout << "\n\n";
	}
	cout << "\n\n";
}
void Task913()
{
	//В Двумерном массиве вещественных чисел найти номер строки, для которой
	//    среднеарифметическое значение ее элементов минимально.
	int n, m, sum, max = 0, idx = 0;

	cout << "n="; cin >> n;
	cout << "m="; cin >> m;
	int P = 0, D = m;
	int** a = new int* [n];
	for (int i = 0; i < n; i++)
		a[i] = new int[m];

	for (int i = 0; i < n; i++)
	{

		sum = 0;
		for (int j = 0; j < m; j++)
		{
			a[i][j] = rand() % 9 + 1;
			sum += a[i][j];
			cout << a[i][j] << " ";
			P++;

			if (P == D) { cout << endl; D += D; }

		}
		if (i == 0 || sum < max) { max = sum; idx = i; }
	}

	cout << "number=" << idx + 1 << "\n";

	for (int i = 0; i < n; i++)
		delete[]a[i];
	delete[]a;
	system("pause");
}
void Task936()
{
	int N;
	cin >> N;
	int** A = new int* [N];
	for (int i = 0; i < N; i++) {
		A[i] = new int[N];
		for (int j = 0; j < N; j++)
			cin >> A[i][j];
	}
	for (int i = 0; i < N; i++) {
		printf("%d ", A[i][i]);
	}
	cout << endl;
	for (int i = N - 1; i > -1; i--) {
		printf("%d ", A[i][i]);
	}

	cout << endl;
}
void Task959()
{
	//В Двумерном массиве хранится информация о количестве учеников в каждом классе каждого
	//потока школы с первого по одиннадцатый(в первой строке — информация о первых классах, во
	//второй — о вторых классах и т.д.).В каждом потоке школы имеются четыре класса.Определить
	//общее число учеников 5 - х классов.
	int n;
	int array[11][4] =
	{
	{ 21,21, 21, 21 },
	{ 21,21, 21, 21 },
	{ 21,21, 21, 21 },
	{ 21,21, 21, 21 },
	{ 21,21, 30, 21 },
	{ 21,21, 21, 21 },
	{ 21,21, 21, 21 },
	{ 21,21, 21, 21 },
	{ 21,21, 21, 21 },
	{ 21,21, 21, 21 },
	{ 21,21, 21, 21 },
	};

	//for (int i = 0; i < 11; ++i) { 
	int i = 4;
	n = 0;
	for (int j = 0; j < 4; ++j)
		n += array[i][j];
	cout << "students in " << i << " classes: " << n << " ";
	cout << endl;
	//}
}
void Task982()
{
	//Магическим квадратом порядка n называется квадратная матрица размера n × n, составленная из
	//чисел 1, 2, ..., n2
	//так, что суммы по каждому столбцу, каждой строке и каждой из двух больших
	//диагоналей равны между собой.Построить такой квадрат.Размер его ввести с экрана.Пример
	//магического квадрата порядка 3:
	int n;
	cout << "Enter the size of the magic square - ";
	cin >> n;

	int** matrix = new int* [n];
	for (int i = 0; i < n; ++i)
	{
		matrix[i] = new int[n];
	}

	int square = n * n;
	int i = 0;
	int j = n / 2;

	for (int k = 1; k <= square; ++k)
	{
		matrix[i][j] = k;
		i--;
		j++;
		if (k % n == 0)
		{
			i += 2;
			--j;
		}
		else
		{
			if (j == n)
			{
				j -= n;
			}
			else if (i < 0)
			{
				i += n;
			}
		}
	}

	cout << "\n\nMagical square with dimension - " << n << "\n\n";
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << matrix[i][j] << "\t";
		}
		cout << endl;
	}

	for (i = 0; i < n; i++)
		delete[] matrix[i];
	delete[] matrix;


}
//i = 5;
//
//a = &i;
//
//b = &a;
//
//
//если вы будете печатать i : 5(значение)будет напечатано.
//
//если вы распечатаете a : адрес i будет напечатан.
//
//если вы будете печатать * a : 5(значение)будет напечатано.
//
//Если вы будете печатать b : Адрес A будет напечатан
//
//если вы распечатаете * b : адрес I будет напечатан
//
//если вы будете печатать * *b : 5(значение)будет напечатано.
void Task1005()
{
	//Дана прямоугольная матрица.Найти строку с наибольшей и наименьшей суммой элементов.
	//Вывести на печать найденные строки и суммы их элементов.
	int Ar[20][20]; //обьявление матрицы
	int i, j, min_num = 0, max_num = 0, min = 0, max = 0, sum = 0, m, n; //обьявление переменных
	cout << "Enter the number of rows ";
	cin >> m;
	cout << "Enter the number of columns ";
	cin >> n;
	cout << "Enter a dimension matrix " << m << " on " << n << "\n"; //запрос на ввод матрицы
	for (i = 0; i < m; i++)
	{
		for (j = 0; j < n; j++)
		{
			cin >> Ar[i][j]; //чтение элемента матрицы из потока ввода
			if (i == 0) //если строка первая
			{
				sum += Ar[i][j]; //считаем сумму
				min += Ar[i][j]; //по умолчанию считаем что сумма первой строки минимальная
				max += Ar[i][j]; // она же максимальная
			}
			else sum += Ar[i][j]; //для всех остальных строк просто считаем сумму
		}
		if (sum > max) //если сумма строки больше максимальной
		{
			max = sum;  //максимальному значению присваиваем сумму этой строчки.
			max_num = i; //номер текущей строки присваиваем номеру максимальной строки по умолчанию
		}
		if (sum < min)
		{
			min = sum; //минимальному значению присваиваем сумму этой строчки.
			min_num = i; //номер текущей строки присваиваем номеру минимальной строки по умолчанию
		}
		sum = 0; //перед переходом на новую строку обнуляем сумму
	}
	cout << " matrix \n";
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
			cout << Ar[i][j] << "\t"; // вывод матрицы
		cout << endl;
	}
	i = min_num;
	cout << "\nMinimum Element Sum String  ";
	for (j = 0; j < n; j++) cout << Ar[i][j] << " "; //вывод минимальной строки
	cout << ", sum of its elements = " << min; //и ее суммы
	i = max_num;
	cout << "\nString with maximum element sum  "; //аналогично для максимальной строки
	for (j = 0; j < n; j++) cout << Ar[i][j] << " ";
	cout << ", sum of its elements = " << max << "\n";
	system("pause");
	return;
}


int main()
{
	int Num, i;
	for (i = 0; i <= 8; i++)
	{
		cout << "chose 913, 936, 959, 982, 1005: ";
		cin >> Num;
		switch (Num)
		{
		case 913:
			Task913();
			break;
		case 936:
			Task936();
			break;
		case 959:
			Task959();
			break;
		case 982:
			Task982();
			break;
		case 1005:
			Task1005();
			break;

		case 000:
			TaskVariant();
			break;

		default:
			break;
		}
	}
}