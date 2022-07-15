/*************************************************************
 * 1. Name:
 *      The Key
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
#include "test.h"
#include "howitzer.h"
#include "Projectile.h"
#include "equations.h"
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
    Demo* pDemo = (Demo*)p;

    //
    // accept input
    //

    // move a large amount
    if (pUI->isRight())
        pDemo->howitzer.angle += 0.05;
    if (pUI->isLeft())
        pDemo->howitzer.angle -= 0.05;

    // move by a little
    if (pUI->isUp())
        pDemo->howitzer.angle += (pDemo->howitzer.angle >= 0 ? -0.003 : 0.003);
    if (pUI->isDown())
        pDemo->howitzer.angle += (pDemo->howitzer.angle >= 0 ? 0.003 : -0.003);

    // fire that gun
    if ((pUI->isSpace()) && (!pDemo->projectile.checkIsMoving())) {

        pDemo->projectile.projectilePath.push_back(pDemo->howitzer.getPosition());
        pDemo->projectile.hangTime = 0.0;
        pDemo->projectile.setVelocity(827);

        
        pDemo->projectile.radians = pDemo->howitzer.angle;
        

        pDemo->projectile.xVelocity.push_back(pDemo->projectile.velocity.back() * sin(pDemo->projectile.radians));
        pDemo->projectile.yVelocity.push_back(pDemo->projectile.velocity.back() * cos(pDemo->projectile.radians));
        cout << pDemo->projectile.radians << endl;
        cout << pDemo->howitzer.angle << endl;
        pDemo->projectile.toggleIsMoving();
        pDemo->howitzer.toggleCanFire();

    }

    // TODO: Make this line of code work without an assertion failure
    //if (pDemo->projectile.position.getPixelsY() <= pDemo->ground.getElevationMeters(pDemo->projectile.position))                                  
    if (pDemo->projectile.position.getMetersY() < 0)
    {
        cout << "hit";
        
        pDemo->projectile.position = pDemo->howitzer.getPosition();
        
        pDemo->projectile.projectilePath.push_back(pDemo->projectile.position);
        pDemo->projectile.setVelocity(0);
        pDemo->projectile.Ax = 0;
        pDemo->projectile.Ay = 0;
        pDemo->howitzer.toggleCanFire();
        pDemo->projectile.toggleIsMoving();
    }








    if (pDemo->projectile.isMoving) {
        pDemo->projectile.Ax = -(1 / (2 * pDemo->projectile.mass)) * pDemo->equations.getDragCoefficient(pDemo->projectile.velocity.back(), pDemo->projectile.projectilePath.back().getMetersY()) * pDemo->equations.getAirDensity(pDemo->projectile.projectilePath.back().getMetersY()) * pDemo->projectile.surfaceArea * pDemo->projectile.velocity.back() * pDemo->projectile.xVelocity.back();
        pDemo->projectile.Ay = -(1 / (2 * pDemo->projectile.mass)) * pDemo->equations.getDragCoefficient(pDemo->projectile.velocity.back(), pDemo->projectile.projectilePath.back().getMetersY()) * pDemo->equations.getAirDensity(pDemo->projectile.projectilePath.back().getMetersY()) * pDemo->projectile.surfaceArea * pDemo->projectile.velocity.back() * pDemo->projectile.yVelocity.back() - pDemo->equations.getGravity(pDemo->projectile.projectilePath.back().getMetersY());
        pDemo->projectile.xVelocity.push_back(pDemo->projectile.xVelocity.back() + pDemo->projectile.Ax * pDemo->projectile.dt);
        pDemo->projectile.yVelocity.push_back(pDemo->projectile.yVelocity.back() + pDemo->projectile.Ay * pDemo->projectile.dt);
        pDemo->projectile.velocity.push_back(pDemo->equations.computeTotalComponent(pDemo->projectile.xVelocity.back(), pDemo->projectile.yVelocity.back()));
        pDemo->projectile.position.setMetersX(pDemo->projectile.projectilePath.back().getMetersX() + pDemo->projectile.xVelocity.back() * pDemo->projectile.dt);
        pDemo->projectile.position.setMetersY(pDemo->projectile.projectilePath.back().getMetersY() + pDemo->projectile.yVelocity.back() * pDemo->projectile.dt);
        pDemo->projectile.projectilePath.push_back(pDemo->projectile.position);
        pDemo->projectile.hangTime += pDemo->projectile.dt;
    }









    //
    // perform all the game logic
    //

    


    


    //
    // draw everything
    //

    ogstream gout(Position(10.0, pDemo->ptUpperRight.getPixelsY() - 20.0));


    // draw the ground first
    pDemo->ground.draw(gout);


    // draw the howitzer
    gout.drawHowitzer(pDemo->howitzer.point, pDemo->howitzer.angle, pDemo->projectile.hangTime);


        
   
    for (int i = 1; i < 20; i++)
        gout.drawProjectile(pDemo->projectile.projectilePath[pDemo->projectile.projectilePath.size() - i], 0.5 * (double)i);
     



    // draw some text on the screen
    gout.setf(ios::fixed | ios::showpoint);
    gout.precision(1);
    gout << "Time since the bullet was fired: "
        << pDemo->projectile.hangTime << "s\n";
    

    
    

    

    

    

    
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
