#include <iostream>
#include <cstdlib>
#include <ctime>


void arr_add(int*& arr, int length, int num) {
	if (num <= 0)
		return;
	int* tmp = new int[length + num]{};
	for (int i = 0; i < length; i++)//копирование из tmp в arr
		tmp[i] = arr[i];
	delete[]arr;
	arr = tmp; //перенаправили обл. памяти arr на ту, где был ранее tmp
}

int main() {
	setlocale(LC_ALL, "Russian");
	int n;

	//Динамическая память 
	/*int* pointer = new int; //направление указателя на произвольный участок динамической памяти размером в 4 байта(т.к int)
	*pointer = 15;//запись в дин.пам числа 15
	std::cout << "pointer = " << pointer << std::endl;
	std::cout << "*pointer = " << * pointer << std::endl;
	delete pointer;//освобождение(очистка) области дин.памяти на которую направ.указатель
	//необходимо во избежение утечки памяти
	pointer = new int;// выделение нового участка дин.памяти
	std::cout << "pointer = " << pointer << std::endl;
	*pointer = 7;
	std::cout << "*pointer = " << *pointer << std::endl;

	delete pointer;*/
	
	//Динамические массивы
	/*std::cout << "Введите размер массива - >\n";
	int size;
	std::cin >> size;
	int* d_arr = new int[size];//выделение дин памяти для хранения массива

	std::cout << "Ввод массива:\n";
	for (int i = 0; i < size; i++) {
		std::cout << "Введите " << i + 1 << "-й элемент ->";
		std::cin >> d_arr[i];
	}
		std::cout << "Итоговый массив:\n";
		for (int i = 0; i < size; i++)
			std::cout << d_arr[i] << ' ';
		std::cout << std::endl;
		delete [] d_arr;*/ //освобождение памяти, выделенной под массив

	//Двумерный динамический массив
	/*int rows, cols;
	std::cout << "Введите размеры двумерного массива:\n";
	std::cin >> rows;
	std::cin >> cols;
	//int* mx = new int[rows][cols]; //данный способ не работает т.к можно исп только одни[]
	//Шаг 1. Создаем указатель основной:указатель на указатель
	int** mx = new int* [rows];//созд указатель на указатель размером в 4 ряда
	for (int i = 0; i < rows; i++)
		mx[i] = new int[cols]; //создание двумерного динам.массива
	//использование массива точно такое же как и у статического
	
	//Освобождение памяти
	for (int i = 0; i < rows; i++)
		delete[] mx[i];
	delete[] mx;*/

	//Задача 1. Увеличение массива на число данное пользователем
	std::cout << "Введите размер массива:\n";
	int size1;
	std::cin >> size1;
	int* arr1 = new int[size1];
	srand(time(NULL));
	std::cout << "Изначальный массив:\n[";
	for (int i = 0; i < size1; i++) {
		arr1[i] = rand() % 11 + 10; //[от 10 до 20 включительно]
		std::cout << arr1[i] << " ,";
		
	}
	std::cout << "\b\b]\nВведите кол-во новых элементов\n";
	std::cin >> n;
	arr_add(arr1, size1, n);
	size1 += n; //у нас длина масисва новая size1 +n
	std::cout << "Итоговый массив:\n";
	for (int i = 0; i < size1; i++)
		std::cout << arr1[i] << " ,";
	std::cout << "\b\b]\n";

	return 0;
}