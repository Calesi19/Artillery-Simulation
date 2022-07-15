#pragma once


#include <cmath>
#define _USE_MATH_DEFINES   // For defining Pi
#include <cassert>      // for ASSERT
#include "uiInteract.h" // for INTERFACE
#include "uiDraw.h"     // for RANDOM and DRAW*
#include "ground.h"     // for GROUND
#include "position.h"   // for POSITION
#include <vector>

class Equations
{
public:
    static double dragForce(double c, double p, double v, double a);

    static double circleArea(double r);

    static double findForce(double m, double a);

    static double computeVerticalComponent(double a, double total);

    static double computeHorizontalComponent(double a, double total);

    static double computeTotalComponent(double x, double y);

    static double radiansFromDegrees(double degrees);

    struct Mapping
    {
        double domain;
        double range;
    };

    static inline double linearInterpolation(double d0, double r0, double d1, double r1, double d);

    static inline double linearInterpolation(const Mapping& zero, const Mapping& one, double d);

    static double linearInterpolation(const Mapping mapping[], int numMapping, double domain);

    // Tables
    static double getSpeedOfSound(double altitude);

    static double getDragCoefficient(double speed, double altitude);

    static double getAirDensity(double altitude);

    static double getGravity(double altitude);

};