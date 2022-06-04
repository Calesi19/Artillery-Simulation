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
#include <iostream>
//#include "position.h"   // for POSITION
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

	double a = M_PI * pow(r, 2);
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


/*
double getLinearInterpolation(Position position1, Position position2, float yValue)
{
	float component1 = position2.getMetersY() - position1.getMetersY();
	float component2 = position2.getMetersX() - position1.getMetersX();
	float component3 = yValue - position1.getMetersY();

	// Calculate solution as the X value
	float solution = component3 / (component1 / component2) + position1.getMetersX();
	return solution;
}
*/


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



double getSpeedOfSound(double altitude) {

	if (altitude >= 40000) return 324;

	else if (altitude >= 30000) return 305;

	else if (altitude >= 25000) return 295;

	else if (altitude >= 20000) return 295;

	else if (altitude >= 15000) return 295;

	else if (altitude >= 10000) return 299;

	else if (altitude >= 9000) return 303;

	else if (altitude >= 8000) return 308;

	else if (altitude >= 7000) return 312;

	else if (altitude >= 6000) return 316;

	else if (altitude >= 5000) return 320;

	else if (altitude >= 4000) return 324;

	else if (altitude >= 3000) return 328;

	else if (altitude >= 2000) return 332;

	else if (altitude >= 1000) return 336;

	else return 340;

}


double getDragCoefficient(double speed, double altitude) {
	double machSpeed = speed / getSpeedOfSound(altitude);
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

	if (altitude >= 80000) return 0.0000185;

	else if (altitude >= 70000) return 0.0000828;

	else if (altitude >= 60000) return 0.0003097;

	else if (altitude >= 50000) return 0.0010270;

	else if (altitude >= 40000) return 0.0039960;

	else if (altitude >= 30000) return 0.0184100;

	else if (altitude >= 25000) return 0.0400800;

	else if (altitude >= 20000) return 0.0889100;

	else if (altitude >= 15000) return 0.1948000;

	else if (altitude >= 10000) return 0.4135000;

	else if (altitude >= 9000) return 0.4671000;

	else if (altitude >= 8000) return 0.5258000;

	else if (altitude >= 7000) return 0.5900000;

	else if (altitude >= 6000) return 0.6601000;

	else if (altitude >= 5000) return 0.7364000;

	else if (altitude >= 4000) return 0.8194000;

	else if (altitude >= 3000) return 0.9093000;

	else if (altitude >= 2000) return 1.0070000;

	else if (altitude >= 1000) return 1.1120000;

	else return 1.2250000;
}





double getGravity(double altitude) {
	if (altitude < 1000)
		return 9.807;
	else if (altitude < 2000)
		return 9.804;
	else if (altitude < 3000)
		return 9.801;
	else if (altitude < 4000)
		return 9.797;
	else if (altitude < 5000)
		return 9.794;
	else if (altitude < 6000)
		return 9.791;
	else if (altitude < 7000)
		return 9.788;
	else if (altitude < 8000)
		return 9.785;
	else if (altitude < 9000)
		return 9.782;
	else if (altitude < 10000)
		return 9.779;
	else if (altitude < 15000)
		return 9.776;
	else if (altitude < 20000)
		return 9.761;
	else if (altitude < 25000)
		return 9.745;
	else
		return 9.730;
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

	double angle;
	double distance = 0;
	double time = 0;
	double t = .01;

	double speed = 827; //   #m / s
	double weight = 46.7; // #kg
	double diameter = 154.89; //#mm
	double surfaceArea = circleArea((diameter / 2)) / 1000;

	cout << "What is the angle of the howitzer where 0 is up ? " << endl;
	cin >> angle;
	double radians = radiansFromDegrees(angle);
	
	double dx;
	double dy;
	double x = 0;
	double y = 0;
	double ddx;
	double ddy;
	double Thrust;
	double xThrust;
	double yThrust;

	
	while (y >= 0){
		
		//Find forces affecting horizontaland vertical values
		Thrust = computeHorizontalComponent(radians, dragForce(getDragCoefficient(speed, y), getAirDensity(y), speed, surfaceArea));


		//Find the acceleration of the horizontal and vertical values

		dx = computeHorizontalComponent(radians, speed);
		dy = computeHorizontalComponent(radians, speed);

		xThrust = computeHorizontalComponent(radians, Thrust);
		yThrust = computeVerticalComponent(radians, Thrust);

		ddx = computeAcceleration(xThrust, weight);
		ddy = computeAcceleration(yThrust, weight) + getGravity(y);

		dx -= ddx;
		dy -= ddy;

		//Find the distance traveled in t time
		x += computeDistance(x, dx, ddx, t);
		y += computeDistance(y, dy, ddy, t);

		speed = computeTotalComponent(dx, dy);

		time += t;
	}

	distance = x;

	cout << "Distance : " << distance << "m     Hang Time : " << time << "s" << endl;


	return 0;
}