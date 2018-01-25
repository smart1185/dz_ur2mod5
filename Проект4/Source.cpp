#include <stdio.h>
#include <iostream>
#include <locale.h>
#include <time.h>
#include <Windows.h>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	int  N;
	srand(time(NULL));

	do
	{
		cout << "\t\tВведите номер задания: ";
		cin >> N;
		cout << endl;
		switch (N)
		{
		case 1:
			/*1.Массив предназначен для хранения значений весов двадцати человек. С помощью датчика случайных чисел
			заполнить массив целыми значениями, лежащими в диапазоне от 50 до 100 включительно*/
		{
			int a[20];
			for (int i = 0; i < 20; i++)
			{
				a[i] = rand() % 51 + 50;
				cout << "[" << i << "]=" << a[i] << endl;
			}
			cout << endl;
		}
		break;

		case 2:
			/*2.	Заполнить массив из восьми элементов таким образом, чтобы значения элементов при просмотре
			массива слева направо образовывали:
a.	убывающую последовательность;
b.	возрастающую последовательность
*/
		{
			int a[8] = { 1,3,4,6,7,9,11,13 };
			cout << "Убывающая: ";
			for (int i = 8 - 1; i >= 0; i--)
			{
				cout << a[i] << " ";
			}
			cout << endl;
			cout << "Возростающая: ";
			for (int i = 0; i < 8; i++)
			{
				cout << a[i] << " ";
			}
			cout << endl;
		}
		break;

		case 3:
			/*3.Ввести целочисленный массив, состоящий из 10 элементов. Поменять местами максимальный и первый элементы.*/
		{
			const int size = 10;
			int a[size], temp, max = 0;
			cout << "До замены: " << endl;
			for (int i = 0; i < size; i++)
			{
				a[i] = rand() % 99;
				if (a[i] > a[max])

				{
					max = i;
				}
				cout << "[" << i << "]=" << a[i] << endl;
			}

			cout << endl;
			temp = a[0];
			a[0] = a[max];
			a[max] = temp;
			cout << "После замены: " << endl;

			for (int i = 0; i < size; i++)
			{
				cout << "[" << i << "]=" << a[i] << endl;
			}

		}
		break;

		case 4:
			/*4.Задан массив, состоящий из 15 элементов вещественного типа. Определить количество элементов,
			значения которых больше первого элемента.*/
		{
			const int size = 15;
			float a[size];
			int cnt = 0;

			for (int i = 0; i < size; i++)
			{
				a[i] = rand() % 99 * 0.22;

				if (a[i] > a[0])
				{
					cnt++;
					SetConsoleTextAttribute(hConsole, 12);
				}
				cout << "[" << i << "]=" << a[i] << endl;
				SetConsoleTextAttribute(hConsole, 7);
			}
			cout << endl;
			cout << "количество элементов, значения которых больше первого элемента = " << cnt << endl;
		}
		break;

		case 5:
			/*5.Ввести целочисленный массив, состоящий из 15 элементов. Определить сумму и разность максимального
			и минимального  элементов*/
		{
			const int size = 15;
			int a[size], max = 0, min = 0;

			for (int i = 0; i < size; i++)
			{
				a[i] = rand() % 99;
				if (a[i] > a[max])

				{
					max = i;
				}
				if (a[i] < a[min])
				{
					min = i;
				}

				cout << "[" << i << "]=" << a[i] << endl;
			}

			int sum = a[max] + a[min];
			int razn = a[max] - a[min];
			cout << "Максимальный элемент: [" << max << "]=" << a[max] << "\t" << "Минимальный элемент: [" << min << "]=" << a[min] << endl;
			cout << "Сумма элементов: " << sum << "\t" << "Разность элементов: " << razn << endl;
		}
		break;

		case 6:
			/*6.Ввести целочисленный массив, состоящий из 17 элементов. Заменить элементы кратные трем на сумму
			нечетных по значению элементов*/
		{
			const int size = 17;
			int a[size], sum = 0;
			cout << "До замены: " << endl;
			for (int i = 0; i < size; i++)
			{
				a[i] = rand() % 99;
				if (a[i] % 3 == 0)
					SetConsoleTextAttribute(hConsole, 12);
				cout << "[" << i << "]=" << a[i] << endl;
				SetConsoleTextAttribute(hConsole, 7);
			}
			cout << endl;
			cout << "Нечетные элементы: ";

			for (int i = 0; i < size; i++)
			{
				if (a[i] % 2 != 0)
				{
					cout << a[i] << " ";
					sum += a[i];
				}
			}
			cout << endl;
			cout << "Сумма нечетных элементов = " << sum << endl;
			cout << endl;
			cout << "После замены:" << endl;
			for (int i = 0; i < size; i++)
			{
				if (a[i] % 3 == 0)
				{
					a[i] = sum;
					SetConsoleTextAttribute(hConsole, 14);
				}
				cout << "[" << i << "]=" << a[i] << endl;
				SetConsoleTextAttribute(hConsole, 7);
			}
		}
		break;


		case 7:
			/*7.Ввести массив, состоящий из 15 элементов целого типа. Определить количество отрицательных,
			произведение положительных и количество нулевых элементов*/
		{
			const int size = 15;
			int a[size], cnt = 0, proizv = 1, cnt1 = 0;

			for (int i = 0; i < size; i++)
			{
				a[i] = -10 + rand() % 20;

				if (a[i] < 0)
				{
					cnt++;
					SetConsoleTextAttribute(hConsole, 14);
				}
				if (a[i] == 0)
				{
					cnt1++;
					SetConsoleTextAttribute(hConsole, 12);
				}
				if (a[i] > 0)
				{
					proizv *= a[i];
				}

				cout << "[" << i << "]=" << a[i] << endl;
				SetConsoleTextAttribute(hConsole, 7);
			}
			SetConsoleTextAttribute(hConsole, 14);
			cout << "Количество отрицательных элементов: " << cnt << endl;
			SetConsoleTextAttribute(hConsole, 7);
			cout << "Произведение положительных элементов: " << proizv << endl;
			SetConsoleTextAttribute(hConsole, 12);
			cout << "Количество нулевых элементов: " << cnt1 << endl;
			SetConsoleTextAttribute(hConsole, 7);
		}
		break;

		case 8:
			/*8.Дан массив − 19 элементов целого типа. Найти сумму элементов, расположенных до первого отрицательного
			элемента. Если отрицательных элементов нет, то выдать соответствующее сообщение.*/
		{
			const int size = 19;
			int a[size], sum = 0, index = 0;
			for (int i = 0; i < size; i++)
			{
				a[i] = -1 + rand() % 20;
				if (a[i] < 0)
				{
					SetConsoleTextAttribute(hConsole, 12);
				}
				cout << "[" << i << "]=" << a[i] << endl;
				SetConsoleTextAttribute(hConsole, 7);
			}
			for (int i = 0; i < size; i++)
			{
				if (a[i] < 0)
				{
					index = i;
					break;
				}
			}

			if (index == 0)
			{
				cout << "Отрицательных элементов нет" << endl;
			}
			else if (index > 0)
			{
				for (int i = 0; i < index; i++)
				{
					sum += a[i];
				}
				cout << "Сумма до первого отрицательного элемента : " << sum << endl;
			}

		}
		break;

		case 9:
			/*9.В заданном массиве М(12) действительных чисел увеличить минимальный элемент в три раза и поменять
			местами с последним*/
		{
			float m[12], x3, temp;
			int min = 0;
			cout << "До замены: " << endl;
			for (int i = 0; i < 12; i++)
			{
				m[i] = rand() % 99 * 0.22;
				if (m[i] < m[min])
				{
					min = i;
				}
				cout << "[" << i << "]=" << m[i] << endl;
			}
			cout << endl;
			cout << "Минимальный элемент = " << m[min] << endl;
			x3 = m[min] * 3;
			cout << m[min] << "* 3 = " << x3 << endl;
			temp = m[11];
			m[11] = x3;
			m[min] = temp;
			cout << endl;

			cout << "После замены: " << endl;
			for (int i = 0; i < 12; i++)
			{
				cout << "[" << i << "]=" << m[i] << endl;
			}
		}
		break;

		case 10:
			/*10. Дан массив М(15) вещественных чисел. Расположить элементы в обратном порядке*/
		{
			const int size = 15;
			float m[size], n[size];
			cout << "До замены: " << endl;
			for (int i = 0; i < size; i++)
			{
				m[i] = rand() % 99 * 0.22;
				cout << "[" << i << "]=" << m[i] << endl;
			}
			cout << endl;
			cout << "После замены: " << endl;
			for (int i = 0; i < size; i++)
			{
				n[i] = m[size - i - 1];
				cout << "[" << i << "]=" << n[i] << endl;
			}
		}
		break;
		default: {cout << "Задания с таким номером не существует" << endl; }
		}
	} while (N > 0 && N < 11);
	cout << "\t\t\t\t\tКОНЕЦ." << endl;
	system("pause");
}