
import math


def dragForce(dragCoefficient, density, velocity, surfaceArea):
    force = .5 * dragCoefficient * density * (velocity**2) * surfaceArea
    return force
    ''' DRAG FORCE EQUATION
	d = force in newtons(N)
	c = drag coefficient
	ρ = density of the fluid / gas
	v = velocity of the projectile
	a = surface area
	'''


def circleArea(radius):
    area = math.pi * (radius**2)
    return area


def findForce(masss, acceleration):
    '''
        f = force in newtons (N)
        m = mass in kilograms (kg)
        a = acceleration (m/s2)
        '''
    force = mass * acceleration
    return force


def computeVerticalComponent(angleRadians, total):
    return total * math.cos(angleRadians)
    '''/***********************************************
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
	 ***********************************************/'''


def computeHorizontalComponent(angleRadians, total):
    '''/***********************************************
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
     ***********************************************/'''
    return total * math.sin(angleRandians)


def computeTotalComponent(x, y):
    '''/************************************************
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
    ***********************************************/'''
    return math.sqrt((x**2) + (y**2))


def radiansFromDegrees(degrees):
    '''/*************************************************
    * RADIANS FROM DEGREES
    * Convert degrees to radians:
    *     radians / 2pi = degrees / 360
    * INPUT
    *     d : degrees from 0 to 360
    * OUTPUT
    *     r : radians from 0 to 2pi
    **************************************************/'''
    return degrees * (math.pi / 180)


def getAngleFromComponents(x, y):
    return math.atan(x * y)


'''
def getLinearInterpolation(position1, position2, yValue):
	component1 = position2.getMetersY() - position1.getMetersY()
	component2 = position2.getMetersX() - position1.getMetersX()
	component3 = yValue - position1.getMetersY()

	# Calculate solution as the X value
	solution = component3 / (component1 / component2) + position1.getMetersX()
	return solution'''


def computeAcceleration(f, m):
    '''/**************************************************
    * COMPUTE ACCELERATION
    * Find the acceleration given a thrust and mass.
    * This will be done using Newton's second law of motion:
    *     f = m * a
    * INPUT
    *     f : force, in Newtons (kg * m / s^2)
    *     m : mass, in kilograms
    * OUTPUT
    *     a : acceleration, in meters/second^2
    ***************************************************/'''
    return f / m


def getDragCoefficient(speed):
    machSpeed = speed / 343

    if (machSpeed >= 5):
        dragCoefficient = .2656

    elif (machSpeed >= 2.890):
        dragCoefficient = .2306

    elif (machSpeed >= 2.870):
        dragCoefficient = .2297

    elif (machSpeed >= 1.990):
        dragCoefficient = .2897

    elif (machSpeed >= 1.530):
        dragCoefficient = .3663

    elif (machSpeed >= 1.240):
        dragCoefficient = .4064

    elif (machSpeed >= 1.060):
        dragCoefficient = .4483

    elif (machSpeed >= 1.020):
        dragCoefficient = .4335

    elif (machSpeed >= 1.000):
        dragCoefficient = .4258

    elif (machSpeed >= .980):
        dragCoefficient = .4002

    elif (machSpeed >= .960):
        dragCoefficient = .3287

    elif (machSpeed >= .920):
        dragCoefficient = .3010

    elif (machSpeed >= .890):
        dragCoefficient = .2597

    elif (machSpeed >= .700):
        dragCoefficient = .2031

    elif (machSpeed >= .500):
        dragCoefficient = .1659

    elif (machSpeed >= .300):
        dragCoefficient = .1629
    else:
        dragCoefficient = 0

    return dragCoefficient


def getAirDensity(altitude):

    if (altitude >= 80000):
        return 0.0000185

    elif (altitude >= 70000):
        return 0.0000828

    elif (altitude >= 60000):
        return 0.0003097

    elif (altitude >= 50000):
        return 0.0010270

    elif (altitude >= 40000):
        return 0.0039960

    elif (altitude >= 30000):
        return 0.0184100

    elif (altitude >= 25000):
        return 0.0400800

    elif (altitude >= 20000):
        return 0.0889100

    elif (altitude >= 15000):
        return 0.1948000

    elif (altitude >= 10000):
        return 0.4135000

    elif (altitude >= 9000):
        return 0.4671000

    elif (altitude >= 8000):
        return 0.5258000

    elif (altitude >= 7000):
        return 0.5900000

    elif (altitude >= 6000):
        return 0.6601000

    elif (altitude >= 5000):
        return 0.7364000

    elif (altitude >= 4000):
        return 0.8194000

    elif (altitude >= 3000):
        return 0.9093000

    elif (altitude >= 2000):
        return 1.0070000

    elif (altitude >= 1000):
        return 1.1120000
    else:
        return 1.2250000


def computeDistance(s, v, a, t):
    '''/***************************************************
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
     **************************************************/'''
    return s + v * t + .5 * a * (t**2)


print(getAirDensity(5000))


'''
distance = 0
time = 0
t = .01
gravity = -9.8 #m/s squared

speed = 827   #m/s
weight = 46.7 #kg
diameter = 154.89 #mm

angle = float(input("What is the angle of the howitzer where 0 is up ? " ))
angle = 10

radians = radiansFromDegrees(angle)

y = 0
x = 0
dx = computeHorizontalComponent(radians, speed)
dy = computeHorizontalComponent(radians, speed)
surfaceArea = circleArea(154.89 * 1000)

ddxThrust = computeHorizontalComponent(radians, dragForce(getDragCoefficient(dx), getAirDensity(y), dx, surfaceArea))
ddyThrust = computeVerticalComponent(radians, dragForce(getDragCoefficient(dy), getAirDensity(y), dy, surfaceArea))


ddx = computeAcceleration(ddxThrust, weight)
ddy = computeAcceleration(ddyThrust, weight) + gravity



while (position.getMetersY() >= 0):
    dx = computeHorizontalComponent(radians, speed);
    dy = computeHorizontalComponent(radians, speed);

    x = computeDistance(x, dx, ddx, t);
    y = computeDistance(y, dy, ddy, t);

    time += t

distance = x

print(f"Distance : {distance}m     Hang Time : {time}s")
'''
