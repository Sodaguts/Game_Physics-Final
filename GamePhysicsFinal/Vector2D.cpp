#include "Vector2D.h"

Vector2D Vector2D::Normalize() 
{
	float magnitude = this->Magnitude();
	if (magnitude == 0)
	{
		return Vector2D();
	}
	else
	{
		Vector2D normalizedVector;
		normalizedVector.x = x / magnitude;
		normalizedVector.y = y / magnitude;
		return normalizedVector;
	}
}

float Vector2D::Magnitude() 
{
	float xSquared = x * x;
	float ySquared = y * y;
	return std::abs(std::sqrt(x + y));
}