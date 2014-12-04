#include <iostream>
#include <locale.h>
#include <string>
#include <algorithm>



class Data {

private:
	std::string *item;
	int number;
	int size = 10;

public:
		// Вывод содержимого
	std::string get_item(const int num) {
		return item[num];
	}

		// Вставка предмета
	void set_item(const std::string *r_item) {
		item[number++] = *r_item;
		if (number == size) {
			size *= 2;
			void *realloc(void *item, size_t size);
		}
	}
	
		// Поиск предмета
	int find_item(const std::string *f_item) {
		for (int i = 0; i < size; ++i) {
			if (item[i] == *f_item) {
				return 0;
			}
		}
		return -1;
	}

		// Удаление первого найденного предмета
	int first_delete_item(const std::string *f_d_item) {
		for (int i = 0; i < size; ++i) {
			if (item[i] == *f_d_item) {
				item[i] = "";
				return 0;
			}
		}
		return -1;
	}

	// Удаление найденных предметов
	int delete_item(const std::string *d_item) {
		int flag = -1;
		for (int i = 0; i < size; ++i) {
			if (item[i] == *d_item) {
				item[i] = "";
				flag = 0;
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
