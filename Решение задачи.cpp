#include <iostream>
#include <locale.h>
#include <string>
#include <algorithm>

int size = 10;

class Data {
private:
		// Предметы в виде строк
	std::string *item = new std::string[size];
		// Номер для размещения нового предмета в массиве
	int number = 0;

public:
		// Вывод содержимого
	std::string get_item(const int num) {
		return item[num];
	}

		// Вставка предмета
	void set_item(std::string r_item) {
		item[number++] = r_item;
		if (number == size) {
			size *= 2;
			std::string realloc(std::string *item, const int size);
		}
	}
	
		// Поиск предмета
	void find_item(std::string f_item) {
		for (int i = 0; i < size; ++i) {
			if (item[i] == f_item) {
				std::cout << i << ' ';
			}
		}
		std::cout << std::endl;
	}

		// Удаление предмета
	void delete_item(std::string d_item) {
		for (int i = 0; i < size; ++i) {
			if (item[i] == d_item) {
				item[i] = "";
			}
		}
	}

		// Контсруктор
	Data() {
		for (int k = 0; k < size; ++k) {
			item[k] = " ";
		}
	}

		// Деструктор
	~Data() {
		std::cout << "Data has been destroyed" << std::endl;
	}

};
