#include <iostream>
#include <string>
#include <algorithm>



class Data {

private:
	std::string *item = NULL;
	std::string *newitem = NULL;
	std::string Error = "Error";
	std::string Simple;
	int number;
	int size = 10;
	int flag = 0;

public:
		// Вывод содержимого
	std::string get_item(const int num) {
		if ((num > size - 1) || (num < 0)) {
			std::cout << "Outside the bounds of the array" << std::endl;
			return Error;
		}
		return item[num];
	}

		// Вставка предмета
	void set_item(const std::string *r_item) {
		item[number++] = *r_item;
		if (number == size) {
			size *= 2;
			newitem = new std::string[size];
			for (int i = 0; i < size / 2; ++i) {
				newitem[i] = item[i];
			}
			std::swap(item, newitem);
			delete[] newitem;
		}
	}	
	
		// Поиск предмета
	int find_item(const std::string *f_item) {
		for (int i = 0; i < size; ++i) {
			if (item[i] == *f_item) {
				return 1;
			}
		}
		return 0;
	}

		// Удаление первого найденного предмета
	int first_delete_item(const std::string *f_d_item) {
		for (int i = 0; i < size; ++i) {
			if (item[i] == *f_d_item) {
				for (int j = i; j < size - 1; ++j) {
					item[j] = item[j + 1];
				}
				item[size - 1] = Simple;
				--number;
				flag = 1;
				return 1;
			}
		}
		return 0;
	}

	// Удаление всех найденных предметов
	int delete_item(const std::string *d_item) {
		flag = 0;
		while (first_delete_item(d_item) == 1);
		return flag;
	}

		// Контсруктор
	Data() {
		// Предметы в виде строк
		item = new std::string[size];
		// Номер для размещения нового предмета в массиве
		number = 0;	
	}

		// Деструктор
	~Data() {
		delete[] item;
		std::cout << "Data has been destroyed" << std::endl;
	}

};
