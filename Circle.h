#pragma once

#include <iostream>
#include <iomanip>
#include <Windows.h>

class Circle
{

private:

	float m_x;
	float m_y;
	float m_radius;

public:

	Circle();							// ����������� �� ���������
	Circle(float, float, float);		// ����������� ��� ��������� ��������� ������
	Circle(const Circle &);				// ����������� �����������
	~Circle();


	void setX(float x) { m_x = x; };
	void setY(float y) { m_y = y; };
	void setRadius(float radius) { m_radius = radius; };
	float getX() { return m_x; };
	float getY() { return m_y; };
	float getRadius() { return m_radius; };
	bool dotInBorders(float, float);	// ����� �� �������

};

Circle::Circle(): m_x{ 0 }, m_y{ 0 }, m_radius{ 1 }
{

	std::cout << std::endl;
	std::cout << "�������� ����������� �� ���������!" << std::endl;
	std::cout << std::endl;

}

Circle::Circle(float inputX, float inputY, float inputRadius)
	: m_x{ inputX }, m_y{ inputY }, m_radius{ inputRadius }
{

	std::cout << std::endl;
	std::cout << "�������� ����������� ��� ��������� ��������� ��������!" << std::endl;
	std::cout << std::endl;

}

Circle::Circle(const Circle &circle)
	: m_x{ circle.m_x }, m_y{ circle.m_y }, m_radius{ circle.m_radius }
{

	std::cout << std::endl;
	std::cout << "�������� ����������� �����������!" << std::endl;
	std::cout << std::endl;

}

Circle::~Circle()
{

	std::cout << std::endl;
	std::cout << "�������� ����������!" << std::endl;
	std::cout << std::endl;

}

bool Circle::dotInBorders(float inputX, float inputY)
{

	if ((pow(inputX - m_x, 2) + pow(inputY - m_y, 2)) <= pow(m_radius, 2))
	{

		return 1;

	}

	return 0;

}


