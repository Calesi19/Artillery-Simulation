/*************************************************************
 * 1. Name:
 *      Carlos Lespin and Braxton Meyer
 * 2. Assignment Name:
 *      Lab 08: M777 Howitzer
 * 3. Assignment Description:
 *      Simulate firing the M777 howitzer 15mm artillery piece
 * 4. What was the hardest part? Be as specific as possible.
 *      ??
 * 5. How long did it take for you to complete the assignment?
 *      ??
 *****************************************************************/



#define _USE_MATH_DEFINES   // For defining Pi
#include <cmath> // for squaring certain values
#include <cassert>      // for ASSERT
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


double getAngleFromComponents(double speedX, double speedY)
{
	return atan(speedX * speedY);
}

double getSpeedFromComponents(float speedX, float speedY)
{
	float speed = sqrt(speedX * speedX + speedY * speedY);
	return speed;
}

double getLinearInterpolation(Position position1, Position position2, float yValue)
{
	float component1 = position2.getMetersY() - position1.getMetersY();
	float component2 = position2.getMetersX() - position1.getMetersX();
	float component3 = yValue - position1.getMetersY();

	// Calculate solution as the X value
	float solution = component3 / (component1 / component2) + position1.getMetersX();
	return solution;
}

double computeAcceleration(double f, double m) {
	/**************************************************
	* COMPUTE ACCELERATION
	* Find the acceleration given a thrust and mass.
	* This will be done using Newton's second law of motion:
	*     f = m * a
	* INPUT
	*     f : force, in Newtons (kg * m / s^2)
	*     m : mass, in kilograms
	* OUTPUT
	*     a : acceleration, in meters/second^2
	***************************************************/
	return f / m;
}


double getDragCoefficient(double speed) {
	double machSpeed = speed / 343;
	double dragCoefficient;
	if (machSpeed >= 5) dragCoefficient = .2656;
	else if (machSpeed >= 2.890) dragCoefficient = .2306;
	else if (machSpeed >= 2.870) dragCoefficient = .2297;
	else if (machSpeed >= 1.990) dragCoefficient = .2897;
	else if (machSpeed >= 1.530) dragCoefficient = .3663;
	else if (machSpeed >= 1.240) dragCoefficient = .4064;
	else if (machSpeed >= 1.060) dragCoefficient = .4483;
	else if (machSpeed >= 1.020) dragCoefficient = .4335;
	else if (machSpeed >= 1.000) dragCoefficient = .4258;
	else if (machSpeed >= .980) dragCoefficient = .4002;
	else if (machSpeed >= .960) dragCoefficient = .3287;
	else if (machSpeed >= .920) dragCoefficient = .3010;
	else if (machSpeed >= .890) dragCoefficient = .2597;
	else if (machSpeed >= .700) dragCoefficient = .2031;
	else if (machSpeed >= .500) dragCoefficient = .1659;
	else if (machSpeed >= .300) dragCoefficient = .1629;
	else dragCoefficient = 0;
	return dragCoefficient;
}

double getAirDensity(double altitude) {
	double lapseRate = 0.00650; // K/m
	double standardTemp = 288.16; // K
	double standardPressure = 101.325; // KPa
	double gasConstant = 287; // J/kgK
	double gravAcceleration = 9.81; // m/s squared

	double airDensity = 0.01 * ((pow((1 - ((lapseRate * altitude) / standardTemp)), (gravAcceleration / (gasConstant * lapseRate))) * (standardTemp / (standardTemp - (lapseRate * altitude)))) * standardPressure);

	return airDensity;
}




double computeDistance(double s, double v, double a, double t) {
	/***************************************************
	 * COMPUTE DISTANCE
	 * Apply inertia to compute a new position using the distance equation.
	 * The equation is:
	 *     s = s + v t + 1/2 a t^2
	 * INPUT
	 *     s : original position, in meters
	 *     v : velocity, in meters/second
	 *     a : acceleration, in meters/second^2
	 *     t : time, in seconds
	 * OUTPUT
	 *     s : new position, in meters
	 **************************************************/
	return s + v * t + .5 * a * (pow(t, 2));
}



int main() {

	double angle = 10;
	double distance;
	double time = 0;
	double t = .01;
	double gravity = -9.8; //m/s squared
	double surfaceArea = circleArea(154.89 / 1000);

	double speed = 827;   //m/s
	double weight = 46.7; //kg
	double diameter = 154.89; //mm
	Position position = Position(0, 0);

	//cout << "What is the angle of the howitzer where 0 is up ? " << endl;
	//cin >> angle;
	double radians = radiansFromDegrees(angle);

	while (time < 10) {
		position.addMetersX(computeDistance(position.getMetersX(), computeHorizontalComponent(radians, speed), dragForce(getDragCoefficient(speed), getAirDensity(position.getMetersY()), speed, surfaceArea), t));
		position.addMetersY(computeDistance(position.getMetersY(), computeVerticalComponent(radians, speed), dragForce(getDragCoefficient(speed) + gravity, getAirDensity(position.getMetersY()), speed, surfaceArea), t));
		cout << "X Position: " << position.getMetersX() << endl;
		cout << "Y Position: " << position.getMetersY() << endl;

		speed -= dragForce(getDragCoefficient(speed), getAirDensity(position.getMetersY()), speed, surfaceArea);
		time += t;
	}

	/*
	double y = 0;
	double x = 0;
	double dx = computeHorizontalComponent(radians, speed);
	double dy = computeHorizontalComponent(radians, speed);
	double surfaceArea = circleArea(154.89 * 1000);

	double ddxThrust = computeHorizontalComponent(radians, dragForce(getDragCoefficient(dx), getAirDensity(y), dx, surfaceArea));
	double ddyThrust = computeVerticalComponent(radians, dragForce(getDragCoefficient(dy), getAirDensity(y), dy, surfaceArea));


	// Vertical acceleration due to thrust
	double ddx = computeAcceleration(ddxThrust, weight);
	// Total horizontal acceleration
	double ddy = computeAcceleration(ddyThrust, weight) + gravity;
	// Total vertical acceleration

	//while (position.getMetersY() >= 0) {
	while (time < 10){
		dx = computeHorizontalComponent(radians, speed);
		dy = computeHorizontalComponent(radians, speed);

		x += dx;
		y += dy;

		ddx = dragForce(getDragCoefficient(dx), getAirDensity(y), dx, surfaceArea);
		ddy = dragForce(getDragCoefficient(dy), getAirDensity(y), dx, surfaceArea) + gravity;

		speed = getSpeedFromComponents(ddx, ddy);

		cout << y;
		time += t;
	}

	*/

	distance = position.getMetersX();


	cout << "Distance : " << distance << "m     Hang Time : " << time << "s" << endl;





	return 0;
}