

#include <cmath>
#include "position.cpp"
#define _USE_MATH_DEFINES   // For defining Pi
#include <cassert>      // for ASSERT
#include "uiInteract.h" // for INTERFACE
#include "uiDraw.h"     // for RANDOM and DRAW*
#include "ground.h"     // for GROUND
#include "position.h"   // for POSITION
#include <vector>
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
	return degrees * (3.14/ 180);
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

struct Mapping
{
	double domain;
	double range;
};

inline double linearInterpolation(double d0, double r0, double d1, double r1, double d)
{
	if (d1 - d0 != 0.0)
		return r0 + (r1 - r0) * (d - d0) / (d1 - d0);
	else
		return r0;
}


inline double linearInterpolation(const Mapping& zero, const Mapping& one, double d) {
	return linearInterpolation(zero.domain, zero.range, one.domain, one.range, d);
}



double linearInterpolation(const Mapping mapping[], int numMapping, double domain) {
	// Too small to be on the scale
	if (domain < mapping[0].domain)
		return mapping[0].range;

	// Within the table
	for (int i = 0; i < numMapping - 1; i++)
	{
		assert(mapping[i + 0].domain < mapping[i + 1].domain);
		if (mapping[i + 0].domain <= domain && domain <= mapping[i + 1].domain)
			return linearInterpolation(mapping[i + 0], mapping[i + 1], domain);
	}

	// Too large to be on the scale
	return mapping[numMapping - 1].range;
}

double getSpeedOfSound(double altitude) {
	const Mapping soundSpeedMapping[] =
	{
		{0.0     ,  340.0},
		{1000.0  ,    336.0},
		{2000.0  ,    332.0},
		{3000.0  ,    328.0},
		{4000.0  ,    324.0},
		{5000.0  ,    320.0},
		{6000.0  ,    316.0},
		{7000.0  ,    312.0},
		{8000.0  ,    308.0},
		{9000.0  ,     303.0},
		{10000.0 ,     299.0},
		{15000.0 ,     295.0},
		{20000.0 ,     295.0},
		{25000.0 ,     295.0},
		{30000.0 ,     305.0},
		{40000.0 ,     324.0}
	};

	double speedOfSound = linearInterpolation(soundSpeedMapping, sizeof(soundSpeedMapping) / sizeof(soundSpeedMapping[0]), altitude);

	return speedOfSound;


}



double getDragCoefficient(double speed, double altitude) {
	double machSpeed = speed / getSpeedOfSound(altitude);

	const Mapping dragMapping[] =
	{
		{0.300,	0.1629},
		{0.500,	0.1659},
		{0.700,	0.2031},
		{0.890,	0.2597},
		{0.920,	0.3010},
		{0.960,	0.3287},
		{0.980,	0.4002},
		{1.000,	0.4258},
		{1.020,	0.4335},
		{1.060,	0.4483},
		{1.240,	0.4064},
		{1.530,	0.3663},
		{1.990,	0.2897},
		{2.870,	0.2297},
		{2.890,	0.2306},
		{5.000,	0.2656}
	};


	double dragCoefficient = linearInterpolation(dragMapping, sizeof(dragMapping) / sizeof(dragMapping[0]), machSpeed);
	cout << dragCoefficient << endl;
	return dragCoefficient;

}




double getAirDensity(double altitude) {

	const Mapping densityMapping[] =
	{ //altitude   density
		{0.0, 1.2250000},
		{ 1000,	1.1120000 },
		{ 2000,	1.007000 },
		{ 3000,	0.9093000 },
		{ 4000,	0.8194000 },
		{ 5000,	0.7364000 },
		{ 6000,	0.6601000 },
		{ 7000,	0.5900000 },
		{ 8000,	0.5258000 },
		{ 9000,	0.4671000 },
		{ 10000,	0.4135000 },
		{ 15000,    0.1948000 },
		{ 20000,	0.0889100 },
		{ 25000,	0.0400800 },
		{ 30000,	0.0184100 },
		{ 40000,	0.0039960 },
		{ 50000,	0.0010270 },
		{ 60000,	0.0003097 },
		{ 70000,	0.0000828 },
		{ 80000,	0.0000185 }
	};

	double density = linearInterpolation(densityMapping, sizeof(densityMapping) / sizeof(densityMapping[0]), altitude);
	return density;

}


double getGravity(double altitude) {
	const Mapping gravityMapping[] =
	{
		{0.0, 9.807},
		{1000.0, 9.804},
		{2000.0, 9.801},
		{3000.0, 9.797},
		{4000.0, 9.794},
		{5000.0, 9.791},
		{6000.0, 9.788},
		{7000.0, 9.785},
		{8000.0, 9.782},
		{9000.0, 9.779},
		{10000.0, 9.776},
		{15000.0, 9.761},
		{20000.0, 9.745},
		{25000.0, 9.730},
		{30000.0, 9.715},
		{40000.0, 9.684},
		{50000.0, 9.654},
		{60000.0, 9.624},
		{70000.0, 9.594},
		{80000.0, 9.564}
	};

	double gravity = linearInterpolation(gravityMapping, sizeof(gravityMapping) / sizeof(gravityMapping[0]), altitude);
	return gravity;

}



/*
int physics() {
	double distance;
	double time = 0;
	double dt = .01;

	double velocity = 827;
	double angle = 80;
	double radians = radiansFromDegrees(angle);
	vector<double> V;
	V.push_back(velocity);

	vector<double> x;
	x.push_back(0);
	vector<double> y;
	y.push_back(0);

	vector<double> Vx;
	Vx.push_back(velocity * cos(radians));

	vector<double> Vy;
	Vy.push_back(velocity * sin(radians));


	double Ax;
	double Ay;

	while (y.back() >= 0) {
		Ax = -(1 / (2 * mass)) * getDragCoefficient(V.back(), y.back()) * getAirDensity(y.back()) * surfaceArea * V.back() * Vx.back();
		Ay = -(1 / (2 * mass)) * getDragCoefficient(V.back(), y.back()) * getAirDensity(y.back()) * surfaceArea * V.back() * Vy.back() - getGravity(y.back());
		Vx.push_back(Vx.back() + Ax * dt);
		Vy.push_back(Vy.back() + Ay * dt);
		V.push_back(computeTotalComponent(Vx.back(), Vy.back()));
		x.push_back(x.back() + Vx.back() * dt);
		y.push_back(y.back() + Vy.back() * dt);
		time += dt;
	}

	distance = x.back();
	cout << "Distance:      " << distance << "m       Hang Time : " << time << "s" << endl;
	return 0;
}*/