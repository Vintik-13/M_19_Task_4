/*Задание 4. Разработка детектора PNG-файла

Что нужно сделать
Разработайте программу, которая получает на вход, в стандартный ввод, путь к файлу.
На выходе программа должна определить, является ли данный файл PNG-изображением.
Данная процедура не просто должна смотреть на расширение файла, но и произвести 
минимальный анализ его внутренностей, в бинарном режиме.

Внутренности валидного бинарного файла начинаются со специального 8-байтового заголовка.
Нас будут интересовать первые четыре байта. Первый байт всегда имеет значение −119
(число со знаком минус), а следующие — это просто символы ‘P’, ‘N’, ‘G’, расположенные
друг за другом. Обратите внимание, что все они в верхнем регистре.
По результатам проверки пути и внутренностей требуется сообщить пользователю о результате
проверки в стандартный вывод.*/

#include <iostream>
#include <fstream>
#include <string>

//Проверка первых 4 bytes
bool valid_bytes(std::string& file) {

    std::ifstream ifs;
	ifs.open(file);
	char bit_1, bit_2, bit_3, bit_4;

	if (ifs.is_open()) {
		ifs.read(&bit_1, sizeof(char));
		ifs.read(&bit_2, sizeof(char));
		ifs.read(&bit_3, sizeof(char));
		ifs.read(&bit_4, sizeof(char));

		if ((int)bit_1 == -119 && bit_2 == 'P' && bit_3 == 'N' && bit_4 == 'G')
			return true;
		else
			return false;
	}
	else {

		std::cout << "File opening error" << std::endl;
		return false;
	}		
}

//Проверка расширения .png
bool valid_chek(std::string& file) {	

	if ((file.rfind("png") == file.size() - 3) && valid_bytes(file))
		return true;
	else false;
}

int main()
{
	/*std::cout << "Enter the path to the .png file: ";
	std::string path;
	std::getline(std::cin, path);*/
    std::string path = "D:\\Skillbox\\Module_19\\free-png.ru-322.png";

	if (valid_chek(path))
		std::cout << "PNG - YES";
	else
		std::cout << "PNG - NO";
}

