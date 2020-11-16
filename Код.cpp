#include <iostream>
#include <string>
using namespace std;
int main()
{
	setlocale(LC_ALL, "rus");
	bool T;
	string N;
	do  // Проверка строки данных на число
	{
		T = true;
		cout << "Введите количество критериев: ";
		cin >> N;
		for (int i = 0; i < N.length(); i++)
		{
			if ((!isdigit(N[i])) and (N[i] != '-'))
			{
				T = false;
				cout << "Введено не число. Повторите попытку" << endl;
			}
		}
	} while (!T);
	float rows = std::stof(N);  
	float** A = new float* [rows];   // двумерный массив данных попарного сравнения критериев
	float* Sum = new float[rows];   // одномерный массив суммы строк
	for (int i = 0; i < rows; i++)
	{
		A[i] = new float[rows];
	}
	cout << "\nВведите данные для сравнения критериев попарно\n";
	for (int i = 0; i < rows; i++)    // Ввод данных попарного сравнения критериев
	{
		for (int j = 0; j < rows; j++)
		{
			cout << i + 1 << "-й критерий по отношению к  ";
			cout << j + 1 << "-ому критерию: ";
			cin >> A[i][j];
		}
	}
	cout << "\nТаблица данных попарного сравнения критериев: \n";
	for (int i = 0; i < rows; i++)    // Вывод на экран массива данных попарного сравнения критериев
	{
		Sum[i] = 0;
		for (int j = 0; j < rows; j++)
		{
			cout << A[i][j] << "\t";
			Sum[i] += A[i][j];
		}
		cout << endl;
	}
	cout << "\nСумма по строкам!\n";  // Подсчет суммы по строкам данных
	float Sum0(NULL);
	for (int i = 0; i < rows; i++)
	{
		cout << i + 1 << "-й критерий: " << Sum[i] << endl;
		Sum0 = Sum0 + Sum[i];
	}
	cout << "\nОбщая сумма строк!\n"; // Подсчет общей суммы строк данных
	cout << Sum0 << endl;
	cout << "\nСумма всех весовых коэффициентов!\n";
	float Sum0;                       // Вывод суммы всех весовых коэффициентов 
	Sum0 = (Sum0 / Sum0);
	cout << Sum0 << endl;
	cout << "\nВесовые коэффициенты каждого критерия!\n";
	for (int i = 0; i < rows; i++)    // Вывод весовых коэффициентов каждого критерия
	{
		cout << i + 1 << "-й критерий: " << round(Sum[i] / Sum0 * 100) / 100 << endl;
	}
	for (int i = 0; i < rows; i++)    // Освобождение памяти от динамических массивов
	{
		delete[] A[i];
	}
	delete[] A;
	delete[] Sum;
}
