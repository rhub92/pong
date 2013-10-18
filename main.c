/*******************************************
  * Author: 2/c Ryan Hub
  * Created: 16 Oct 2013
  * Description: This program replicates that of the game pong. It moves a ball around a box
  * and when the ball hits the box the ball changes its direction, so the values of the ball's
  * location remain in the specified box.
*******************************************/

//this is a new comment
#include <msp430.h> 
#include "create_ball.h"

void main(void) {
    WDTCTL = WDTPW | WDTHOLD;	// Stop watchdog timer
    vector2d_t location = {210,210};
    vector2d_t velocity = {30,30};
    unsigned char radius = 5;


    ball_t ball = createBall(location.x, location.y, velocity.x, velocity.y, radius);
    while(1) {
    ball = moveBall(ball);
    }


}


