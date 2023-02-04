/*
std::variant бывает удобно применять в разработке парсеров.
Например, есть некоторая универсальная функция, которая может 
возвращать значения разных типов в зависимости от контекста. 
В этом задании вам нужно использовать простую функцию, которая может возвращать число, 
строку или массив чисел.

Вам нужно написать обработку результата этой функции следующим образом:

Если в результате функции содержится int, то вывести число, умноженное на 2.
Если в результате функции содержится строка, то просто вывести её в консоль.
Если в результате функции содержится вектор чисел, то вывести все его элементы в консоль.
*/

#include <variant>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

std::variant<int, std::string, std::vector<int>> get_variant() {
	std::srand(std::time(nullptr));
	int random_variable = std::rand() % 3;

	std::variant<int, std::string, std::vector<int>> result;
	switch (random_variable)
	{
	case 0:
		result = 5;
		break;
	case 1:
		result = "string";
		break;
	case 2:
		result = std::vector<int>{ 1, 2, 3, 4, 5 };
		break;
	default:
		break;
	}
	return result;
}

int main()
{
	auto tmp = get_variant();
	if (std::holds_alternative<int>(tmp))
	{
		std::cout << std::get<int>(tmp) * 2;
	}
	else if (std::holds_alternative<std::string>(tmp))
	{
		std::cout << std::get<std::string>(tmp);
	}
	else if (std::holds_alternative<std::vector<int>>(tmp))
	{
		std::vector<int>(a) = std::get <std::vector<int>>(tmp);
		for (auto i : a)
		{
			std::cout << i;
		}
	}
	
    return 0;
}

