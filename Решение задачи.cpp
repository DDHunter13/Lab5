#include <iostream>
#include <locale.h>
#include <string>
#include <algorithm>

class Data {
private:
		// Предмет в виде строки
		std::string item;

public:
		// Вывод содержимого
		std::string get_item() {
			return item;
		}

		// Вставка предмета
		void set_item(std::string r_item) {
			item = r_item;
		}

		// Удаление предмета
		void delete_item() {
			item = ' ';
		}

		// Поиск предмета


		// Контсруктор
		Data() {
			item = ' ';
		}

		// Деструктор
		~Data() {
			std::cout << "Item has been destroyed" << std::endl;
		}
};

int main() {
	Data items[10];
}
