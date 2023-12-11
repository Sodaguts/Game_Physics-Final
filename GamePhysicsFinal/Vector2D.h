#pragma once
#include <math.h>
#include <iostream>

struct Vector2D 
{
	float x, y;
	Vector2D() 
	{
		x = 0;
		y = 0;
	}
	Vector2D(float num) 
	{
		x = num;
		y = num;
	}
	Vector2D(float _x, float _y) 
	{
		x = _x;
		y = _y;
	}
	Vector2D(int _x, int _y) 
	{
		x = _x;
		y = _y;
	}

	//Math Stuff
	Vector2D operator+=(const Vector2D other) 
	{
		return Vector2D(this->x += other.x, this->y += other.y);
	}

	Vector2D operator-=(const Vector2D other) 
	{
		return Vector2D(this->x -= other.x, this->y -= other.y);
	}
	Vector2D operator*=(const Vector2D other) 
	{
		return Vector2D(this->x *= other.x, this->y *= other.y);
	}
	friend Vector2D operator+(const Vector2D a, const Vector2D b) 
	{
		return a + b;
	}
	friend Vector2D operator-(const Vector2D a, const Vector2D b) 
	{
		return a - b;
	}

	float Magnitude();
	Vector2D Normalize();

	float SqrMagnitude() 
	{
		return (x * x) + (y * y);
	}

	float Distance(const Vector2D other) 
	{
		return std::sqrt(((other.x - x) * (other.x - x)) + ((other.y - y) * (other.y - y)));
	}
	
	void print() 
	{
		std::cout << "(" << this->x << "," << this->y << ")\n";
	}

};
