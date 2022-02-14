#define NOMINMAX

#include <iostream>
#include <iomanip>
#include <Windows.h>
#include <climits>
#include <cmath>

#include "Circle.h"

void checkInput(float &input_buff, const bool flag)
{
	if (flag == 0)
	{

		while (!std::cin.good() || std::cin.peek() != '\n')		//Проверка на то, что float
		{

			std::cerr << "Некорректный ввод данных!!!" << std::endl;
			std::cout << "Вводимое поле должно быть вещественным числом!!!" << std::endl;
			std::cout << "Повторите ввод!!!" << std::endl;
			std::cout << std::endl;
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			std::cin >> input_buff;
			std::cout << std::endl;

		}

	}

	else
	{

		while ((!std::cin.good() || std::cin.peek() != '\n') || input_buff <= 0)		//Проверка на то, что float
		{

			std::cerr << "Некорректный ввод данных!!!" << std::endl;
			std::cout << "Вводимое поле должно быть неравно нулю, положительным вещественным числом!!!" << std::endl;
			std::cout << "Повторите ввод!!!" << std::endl;
			std::cout << std::endl;
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			std::cin >> input_buff;
			std::cout << std::endl;

		}

	}


}

void InputCircle(float &x, float &y, float &radius)
{

	std::cout << "Введите параметры кртуга: " << std::endl;

	std::cout << "Введите координату Х центра круга: ";
	std::cin >> x;

	checkInput(x, 0);

	std::cout << std::endl;

	std::cout << "Введите координату Y центра круга: ";
	std::cin >> y;

	checkInput(y, 0);

	std::cout << std::endl;

	std::cout << "Введите радиус круга: ";
	std::cin >> radius;

	checkInput(radius, 1);

	std::cout << std::endl;

}

void InputDot(float &x, float &y)
{

	std::cout << "Введите координаты проверяемой точки: " << std::endl;

	std::cout << "Введите координату Х проверяемой точки: ";
	std::cin >> x;
	std::cout << std::endl;

	checkInput(x, 0);

	std::cout << "Введите координату Y проверяемой точки: ";
	std::cin >> y;
	std::cout << std::endl;

	checkInput(y, 0);

}

void GetResult(const float &dotX, const float &dotY, Circle &circle)
{

	if (circle.dotInBorders(dotX, dotY) == 1)
	{

		std::cout << "Точка с координатами x= " << dotX << " y= " << dotY
			<< " Входит в окружность с параметрами: " << std::endl;
		std::cout << "x= " << circle.getX() << " y= " << circle.getY()
			<< " r= " << circle.getRadius() << std::endl;
		std::cout << std::endl;

		return;

	}

	std::cout << "Точка с координатами x= " << dotX << " y= " << dotY
		<< " Не входит в окружность с параметрами: " << std::endl;
	std::cout << "x= " << circle.getX() << " y= " << circle.getY()
		<< " r= " << circle.getRadius() << std::endl;
	std::cout << std::endl;


	return;

}

void main()
{

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	std::cout << "Круг на плоскости имеет координаты центра x, y - вещественные поля. "
		<< "Радиус круга r - также задан вещественным полем."
		<< "Реализовать метод проверяющий" << std::endl << " принадлежность точки с координатами (x, y) данному кругу."
		<< std::endl;



	float dotX{};
	float dotY{};
	float x{};
	float y{};
	float r{};

	Circle circle;

	InputDot(dotX, dotY);
	GetResult(dotX, dotY, circle);


	Circle copyCircle(circle);

	InputDot(dotX, dotY);
	GetResult(dotX, dotY, copyCircle);


	InputCircle(x, y, r);
	InputDot(dotX, dotY);

	Circle circleSecond{ x, y, r };

	GetResult(dotX, dotY, circleSecond);


	system("pause");

}