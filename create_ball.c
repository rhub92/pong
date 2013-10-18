#include "create_ball.h"

/*******************************************
Subroutine Name: createBall
Author: 2/c Ryan Hub
Function: assigns the ball its dimensions based off of the values passed
Inputs: int xPos- the x-coordinate of the ball's position
		int yPos- the y-coordinate of the ball's position
		int xVel- the x-coordinate of the ball's velocity
		int yVel- the y-coordinate of the ball's velocity
		unsigned char radius- the radius of the ball
returns: ball- the dimensions of the ball
*******************************************/
ball_t createBall(int xPos, int yPos, int xVel, int yVel, unsigned char radius) {
	ball_t ball;
	ball.location.x = xPos;
	ball.location.y = yPos;
	ball.velocity.x = xVel;
	ball.velocity.y = yVel;
	ball.radius = radius;
	return ball;
}



/*******************************************
Subroutine Name: right_collision_detector
Author: 2/c Ryan Hub
Function: Determines if the ball has hit the right side of the screen
Inputs: int xPos- the ball's x position
		int radius- the ball's radius
returns: char- Either TRUE or FALSE
*******************************************/
char right_collision_detector(int xPos, unsigned char radius) {
	if (xPos - radius > WINDOW_WIDTH) {
		return TRUE;
	} else {
		return FALSE;
	}
}

/*******************************************
Subroutine Name: left_collision_detector
Author: 2/c Ryan Hub
Function: Determines if the ball has hit the left side of the screen
Inputs: int xPos- the ball's x position
		int radius- the ball's radius
returns: char- Either TRUE or FALSE
*******************************************/
char left_collision_detector(int xPos, unsigned char radius) {
	if (xPos + radius < 0) {
		return TRUE;
	} else {
		return FALSE;
	}
}


/*******************************************
Subroutine Name: up_collision_detector
Author: 2/c Ryan Hub
Function: Determines if the ball has hit the top of the screen
Inputs: int yPos- the ball's y position
		int radius- the ball's radius
returns: char- Either TRUE or FALSE
*******************************************/
char up_collision_detector(int yPos, unsigned char radius) {
	if (yPos - radius > WINDOW_HEIGHT) {
		return TRUE;
	} else {
		return FALSE;
	}
}


/*******************************************
Subroutine Name: down_collision_detector
Author: 2/c Ryan Hub
Function: Determines if the ball has hit the bottom of the screen
Inputs: int yPos- the ball's y position
		int radius- the ball's radius
returns: char- Either TRUE or FALSE
*******************************************/
char down_collision_detector(int yPos, unsigned char radius) {
	if (yPos + radius < 0) {
		return TRUE;
	} else {
		return FALSE;
	}

}


/*******************************************
Subroutine Name: moveBall
Author: 2/c Ryan Hub
Function: changes the position of the ball based on its velocity
Inputs: ball_t ball- the current dimensions of the ball
returns: ball_t ball- the new dimensions of the ball
*******************************************/
ball_t moveBall(ball_t ball) {
		ball.location.x += ball.velocity.x;
		ball.location.y += ball.velocity.y;

		if(left_collision_detector(ball.location.x, ball.radius) == TRUE || right_collision_detector(ball.location.x, ball.radius) == TRUE) {
			ball.velocity.x = -ball.velocity.x;
		}
		if(up_collision_detector(ball.location.y, ball.radius) == TRUE || down_collision_detector(ball.location.y, ball.radius) == TRUE) {
			ball.velocity.y = -ball.velocity.y;
		}

	return ball;
}


