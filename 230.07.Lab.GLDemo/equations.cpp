

#include <cmath>
#include "position.cpp"
#define _USE_MATH_DEFINES   // For defining Pi
#include <cassert>      // for ASSERT
#include "uiInteract.h" // for INTERFACE
#include "uiDraw.h"     // for RANDOM and DRAW*
#include "ground.h"     // for GROUND
#include "position.h"   // for POSITION
using namespace std;


double dragForce(double c, double p, double v, double a) {

	/* DRAG FORCE EQUATION

	d = force in newtons(N)
	c = drag coefficient
	ρ = density of the fluid / gas
	v = velocity of the projectile
	a = surface area
	*/

	double d = .5 * c * p * (pow(v, 2)) * a;
	return d;
}


double circleArea(double r) {

	/*
	a = area of a circle (m2)
	r = radius of a circle
	*/

	double a = 3.14 * pow(r, 2);
	return a;

}


double findForce(double m, double a) {

	/*
	f = force in newtons (N)
	m = mass in kilograms (kg)
	a = acceleration (m/s2)
	*/

	double f = m * a;
	return f;
}



double computeVerticalComponent(double a, double total) {
	/***********************************************
	 * COMPUTE VERTICAL COMPONENT
	 * Find the vertical component of a velocity or acceleration.
	 * The equation is:
	 *     cos(a) = y / total
	 * This can be expressed graphically:
	 *      x
	 *    +-----
	 *    |   /
	 *  y |  / total
	 *    |a/
	 *    |/
	 * INPUT
	 *     a : angle, in radians
	 *     total : total velocity or acceleration
	 * OUTPUT
	 *     y : the vertical component of the total
	 ***********************************************/
	return total * cos(a);
}
double computeHorizontalComponent(double a, double total) {
	/***********************************************
	 * COMPUTE HORIZONTAL COMPONENT
	 * Find the horizontal component of a velocity or acceleration.
	 * The equation is:
	 *     sin(a) = x / total
	 * This can be expressed graphically:
	 *      x
	 *    +-----
	 *    |   /
	 *  y |  / total
	 *    |a/
	 *    |/
	 * INPUT
	 *     a : angle, in radians
	 *     total : total velocity or acceleration
	 * OUTPUT
	 *     x : the vertical component of the total
	 ***********************************************/
	return total * sin(a);
}

double computeTotalComponent(double x, double y) {
	/************************************************
	* COMPUTE TOTAL COMPONENT
	* Given the horizontal and vertical components of
	* something (velocity or acceleration), determine
	* the total component. To do this, use the Pythagorean Theorem:
	*    x^2 + y^2 = t^2
	* where:
	*      x
	*    +-----
	*    |   /
	*  y |  / total
	*    | /
	*    |/
	* INPUT
	*    x : horizontal component
	*    y : vertical component
	* OUTPUT
	*    total : total component
	***********************************************/
	return sqrt(pow(x, 2) + pow(y, 2));
}
double radiansFromDegrees(double degrees) {
	/*************************************************
	* RADIANS FROM DEGREES
	* Convert degrees to radians:
	*     radians / 2pi = degrees / 360
	* INPUT
	*     d : degrees from 0 to 360
	* OUTPUT
	*     r : radians from 0 to 2pi
	**************************************************/
	return degrees * (M_PI / 180);
}



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


