#include <cmath>
#include "position.cpp"


float convertSpeedtoHorizontal(double speed, double angle)
{
	return speed * cos(angle);
}

float getAngleFromComponents(double speedX, double speedY)
{
	return atan(speedX * speedY);
}

float getSpeedFromComponents(float speedX, float speedY)
{
	float speed = sqrt(speedX * speedX + speedY * speedY);
	return speed;
}

float getLinearInterpolation(Position position1, Position position2, float yValue)
{
	float component1 = position2.getMetersY() - position1.getMetersY();
	float component2 = position2.getMetersX() - position1.getMetersX();
	float component3 = yValue - position1.getMetersY();
	
	// Calculate solution as the X value
	float solution = component3 / (component1 / component2) + position1.getMetersX();
	return solution;
}