#include <msp430.h> 
#include "create_ball.h"

void main(void) {
    WDTCTL = WDTPW | WDTHOLD;	// Stop watchdog timer
    vector2d_t location = {150,150};
    vector2d_t velocity = {40,40};
    unsigned char radius = 5;


    ball_t ball = createBall(location.x, location.y, velocity.x, velocity.y, radius);
    while(1) {
    ball = moveBall(ball);
    }


}


