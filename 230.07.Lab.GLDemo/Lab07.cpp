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

#include <cassert>      // for ASSERT
#include "uiInteract.h" // for INTERFACE
#include "uiDraw.h"     // for RANDOM and DRAW*
#include "ground.h"     // for GROUND
#include "position.h"   // for POSITION
#include "howitzer.h"
#include "Projectile.h"
#include "equations.h"
#include <Windows.h>
#include <WinUser.h>

using namespace std;

/*************************************************************************
 * Demo
 * Test structure to capture the LM that will move around the screen
 *************************************************************************/
class Demo
{
public:
    Demo(Position ptUpperRight) :
        ptUpperRight(ptUpperRight),
        ground(ptUpperRight)

    {
        howitzer.getPosition().setPixelsX(Position(ptUpperRight).getPixelsX() / 2.0);
        ground.reset(howitzer.getPosition());
        
    }

    Ground ground;                 // the ground
   
    Position  ptUpperRight;        // size of the screen
   
    Howitzer howitzer;
    Projectile projectile;
    Equations equations;
    string centerMessage;


};

/*************************************
 * All the interesting work happens here, when
 * I get called back from OpenGL to draw a frame.
 * When I am finished drawing, then the graphics
 * engine will wait until the proper amount of
 * time has passed and put the drawing on the screen.
 **************************************/
void callBack(const Interface* pUI, void* p)
{
    // the first step is to cast the void pointer into a game object. This
    // is the first step of every single callback function in OpenGL. 
    Demo* pSimulation = (Demo*)p;

    // Initialize the gout variable so we can print messages based on the collision logic
    ogstream gout(Position(pSimulation->ptUpperRight.getMetersX() / 2, 500 + pSimulation->ptUpperRight.getMetersY() / 2));


    gout << pSimulation->centerMessage;
    //
    // accept input
    //

    // move a large amount
    if (pUI->isRight())
        pSimulation->howitzer.angle += 0.05;
    if (pUI->isLeft())
        pSimulation->howitzer.angle -= 0.05;

    // move by a little
    if (pUI->isUp())
        pSimulation->howitzer.angle += (pSimulation->howitzer.angle >= 0 ? -0.003 : 0.003);
    if (pUI->isDown())
        pSimulation->howitzer.angle += (pSimulation->howitzer.angle >= 0 ? 0.003 : -0.003);

    // fire that gun
    if ((pUI->isSpace()) && (!pSimulation->projectile.checkIsMoving())) {

        // Reset the collision detection message
        pSimulation->centerMessage = "";


        pSimulation->projectile.projectilePath.push_back(pSimulation->howitzer.getPosition());
        pSimulation->projectile.hangTime = 0.0;
        pSimulation->projectile.setVelocity(827);

        pSimulation->projectile.radians = pSimulation->howitzer.angle;

        pSimulation->projectile.xVelocity.push_back(pSimulation->projectile.velocity.back() * sin(pSimulation->projectile.radians));
        pSimulation->projectile.yVelocity.push_back(pSimulation->projectile.velocity.back() * cos(pSimulation->projectile.radians));
        cout << pSimulation->projectile.radians << endl;
        cout << pSimulation->howitzer.angle << endl;
        pSimulation->projectile.toggleIsMoving();
        pSimulation->howitzer.toggleCanFire();

    }


    //
    // perform all the game logic
    //



    // target collision logic
    Position targetPosition = pSimulation->ground.getTarget();
    if ((pSimulation->projectile.position.getPixelsX() > targetPosition.getPixelsX() - 5) && (pSimulation->projectile.position.getPixelsX() < targetPosition.getPixelsX() + 5))
        if ((pSimulation->projectile.position.getPixelsY() > targetPosition.getPixelsY() - 5) && (pSimulation->projectile.position.getPixelsY() < targetPosition.getPixelsY() + 5))
        {
            pSimulation->projectile.reset(pSimulation->ptUpperRight);
            pSimulation->howitzer.toggleCanFire();
            pSimulation->centerMessage = "Target hit";
        }
    // ground collision logic
    if (pSimulation->projectile.position.getMetersY() <= pSimulation->ground.getElevationMeters(pSimulation->projectile.position))
    {
        pSimulation->projectile.reset(pSimulation->ptUpperRight);
        pSimulation->howitzer.toggleCanFire();
        pSimulation->centerMessage = "Ground hit";
    }

    // wall collision logic
    if (pSimulation->projectile.position.getMetersX() < 0 || pSimulation->projectile.position.getMetersX() > pSimulation->ptUpperRight.getMetersX())
    {
        pSimulation->projectile.reset(pSimulation->ptUpperRight);
        pSimulation->howitzer.toggleCanFire();
        pSimulation->centerMessage = "Out of bounds";
    }

    // physics update logic
    if (pSimulation->projectile.isMoving) {
        pSimulation->projectile.Ax = -(1 / (2 * pSimulation->projectile.mass)) * pSimulation->equations.getDragCoefficient(pSimulation->projectile.velocity.back(), pSimulation->projectile.projectilePath.back().getMetersY()) * pSimulation->equations.getAirDensity(pSimulation->projectile.projectilePath.back().getMetersY()) * pSimulation->projectile.surfaceArea * pSimulation->projectile.velocity.back() * pSimulation->projectile.xVelocity.back();
        pSimulation->projectile.Ay = -(1 / (2 * pSimulation->projectile.mass)) * pSimulation->equations.getDragCoefficient(pSimulation->projectile.velocity.back(), pSimulation->projectile.projectilePath.back().getMetersY()) * pSimulation->equations.getAirDensity(pSimulation->projectile.projectilePath.back().getMetersY()) * pSimulation->projectile.surfaceArea * pSimulation->projectile.velocity.back() * pSimulation->projectile.yVelocity.back() - pSimulation->equations.getGravity(pSimulation->projectile.projectilePath.back().getMetersY());
        pSimulation->projectile.xVelocity.push_back(pSimulation->projectile.xVelocity.back() + pSimulation->projectile.Ax * pSimulation->projectile.dt);
        pSimulation->projectile.yVelocity.push_back(pSimulation->projectile.yVelocity.back() + pSimulation->projectile.Ay * pSimulation->projectile.dt);
        pSimulation->projectile.velocity.push_back(pSimulation->equations.computeTotalComponent(pSimulation->projectile.xVelocity.back(), pSimulation->projectile.yVelocity.back()));
        pSimulation->projectile.position.setMetersX(pSimulation->projectile.projectilePath.back().getMetersX() + pSimulation->projectile.xVelocity.back() * pSimulation->projectile.dt);
        pSimulation->projectile.position.setMetersY(pSimulation->projectile.projectilePath.back().getMetersY() + pSimulation->projectile.yVelocity.back() * pSimulation->projectile.dt);
        pSimulation->projectile.projectilePath.push_back(pSimulation->projectile.position);
        pSimulation->projectile.hangTime += pSimulation->projectile.dt;
    }

    //
    // draw everything
    //

    gout.setPosition(Position(10.0, pSimulation->ptUpperRight.getPixelsY() - 20.0));
    
    // draw the ground first
    pSimulation->ground.draw(gout);


    // draw the howitzer
    gout.drawHowitzer(pSimulation->howitzer.point, pSimulation->howitzer.angle, pSimulation->projectile.hangTime);

    // draw the projectile
    for (int i = 1; i < 20; i++)
        gout.drawProjectile(pSimulation->projectile.projectilePath[pSimulation->projectile.projectilePath.size() - i], 0.5 * (double)i);

    // draw some text on the screen
    gout.setf(ios::fixed | ios::showpoint);
    gout.precision(1);
    gout << "Time since the bullet was fired: "
        << pSimulation->projectile.hangTime << "s\n";

    
    
    

    
    

    

    

    

    
}

double Position::metersFromPixels = 40.0;

/*********************************
 * Initialize the simulation and set it in motion
 *********************************/
#ifdef _WIN32_X
#include <windows.h>
int WINAPI wWinMain(
    _In_ HINSTANCE hInstance,
    _In_opt_ HINSTANCE hPrevInstance,
    _In_ PWSTR pCmdLine,
    _In_ int nCmdShow)
#else // !_WIN32


int main(int argc, char** argv)
#endif // !_WIN32
{
    // Hide Console
    ShowWindow(GetConsoleWindow(), SW_HIDE);

    // Initialize OpenGL
    Position ptUpperRight;
    ptUpperRight.setPixelsX(700.0);
    ptUpperRight.setPixelsY(500.0);
    Position().setZoom(40.0 /* 42 meters equals 1 pixel */);
    Interface ui(0, NULL,
        "Howitzer Simulation",   /* name on the window */
        ptUpperRight);

    // Initialize the demo
    Demo demo(ptUpperRight);

    // set everything into action
    ui.run(callBack, &demo);

    return 0;
}
