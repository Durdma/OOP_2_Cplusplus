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

		while (!std::cin.good() || std::cin.peek() != '\n')		//�������� �� ��, ��� float
		{

			std::cerr << "������������ ���� ������!!!" << std::endl;
			std::cout << "�������� ���� ������ ���� ������������ ������!!!" << std::endl;
			std::cout << "��������� ����!!!" << std::endl;
			std::cout << std::endl;
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			std::cin >> input_buff;
			std::cout << std::endl;

		}

	}

	else
	{

		while ((!std::cin.good() || std::cin.peek() != '\n') || input_buff <= 0)		//�������� �� ��, ��� float
		{

			std::cerr << "������������ ���� ������!!!" << std::endl;
			std::cout << "�������� ���� ������ ���� ������� ����, ������������� ������������ ������!!!" << std::endl;
			std::cout << "��������� ����!!!" << std::endl;
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

	std::cout << "������� ��������� ������: " << std::endl;

	std::cout << "������� ���������� � ������ �����: ";
	std::cin >> x;

	checkInput(x, 0);

	std::cout << std::endl;

	std::cout << "������� ���������� Y ������ �����: ";
	std::cin >> y;

	checkInput(y, 0);

	std::cout << std::endl;

	std::cout << "������� ������ �����: ";
	std::cin >> radius;

	checkInput(radius, 1);

	std::cout << std::endl;

}

void InputDot(float &x, float &y)
{

	std::cout << "������� ���������� ����������� �����: " << std::endl;

	std::cout << "������� ���������� � ����������� �����: ";
	std::cin >> x;
	std::cout << std::endl;

	checkInput(x, 0);

	std::cout << "������� ���������� Y ����������� �����: ";
	std::cin >> y;
	std::cout << std::endl;

	checkInput(y, 0);

}

void GetResult(const float &dotX, const float &dotY, Circle &circle)
{

	if (circle.dotInBorders(dotX, dotY) == 1)
	{

		std::cout << "����� � ������������ x= " << dotX << " y= " << dotY
			<< " ������ � ���������� � �����������: " << std::endl;
		std::cout << "x= " << circle.getX() << " y= " << circle.getY()
			<< " r= " << circle.getRadius() << std::endl;
		std::cout << std::endl;

		return;

	}

	std::cout << "����� � ������������ x= " << dotX << " y= " << dotY
		<< " �� ������ � ���������� � �����������: " << std::endl;
	std::cout << "x= " << circle.getX() << " y= " << circle.getY()
		<< " r= " << circle.getRadius() << std::endl;
	std::cout << std::endl;


	return;

}

void main()
{

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	std::cout << "���� �� ��������� ����� ���������� ������ x, y - ������������ ����. "
		<< "������ ����� r - ����� ����� ������������ �����."
		<< "����������� ����� �����������" << std::endl << " �������������� ����� � ������������ (x, y) ������� �����."
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