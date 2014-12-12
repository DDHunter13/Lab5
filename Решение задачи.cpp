#include <iostream>
#include <locale.h>
#include <string>
#include <algorithm>



class Data {

private:
	std::string *item;
	std::string *newitem;
	int number;
	int size = 10;

public:
		// Вывод содержимого
	std::string get_item(const int num) {
		if (num > size - 1) {
			return 0;
		}
		return item[num];
	}

		// Вставка предмета
	void set_item(const std::string *r_item) {
		item[number++] = *r_item;
		if (number == size) {
			newitem = new std::string[size];
			for (int i = 0; i < size ; ++i) {
				newitem[i] = item[i];
			}
			delete[] item;
			size *= 2;
			item = new std::string[size];
			for (int i = 0; i < size / 2; ++i) {
				item[i] = newitem[i];
			}
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
				for (int j = i; j < size + 1; ++j) {
					item[j] = item[j + 1];
				}
				return 1;
			}
		}
		return 0;
	}

	// Удаление найденных предметов
	int delete_item(const std::string *d_item) {
		int flag = 0;
		for (int i = 0; i < size; ++i) {
			if (item[i] == *d_item) {
				for (int j = i; j < size + 1; ++j) {
					item[j] = item[j + 1];
				}
				flag = 1;
				--i;
			}
		}
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
