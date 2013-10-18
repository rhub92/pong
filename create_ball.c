#include "create_ball.h"


ball_t createBall(int xPos, int yPos, int xVel, int yVel, unsigned char radius) {
	ball_t newball;
	newball.location.x = xPos;
	newball.location.y = yPos;
	newball.velocity.x = xVel;
	newball.velocity.y = yVel;
	newball.radius = radius;
	return newball;
}




char right_collision_detector(int xPos, unsigned char radius) {
	if (xPos + radius > WINDOW_WIDTH) {
		return TRUE;
	} else {
		return FALSE;
	}
}

char left_collision_detector(int xPos, unsigned char radius) {
	if (xPos - radius < 0) {
		return TRUE;
	} else {
		return FALSE;
	}
}

char up_collision_detector(int yPos, unsigned char radius) {
	if (yPos + radius > WINDOW_HEIGHT) {
		return TRUE;
	} else {
		return FALSE;
	}
}


char down_collision_detector(int yPos, unsigned char radius) {
	if (yPos - radius < 0) {
		return TRUE;
	} else {
		return FALSE;
	}

}

ball_t moveBall(ball_t ball) {
		ball.location.x += ball.velocity.x;
		ball.location.y += ball.velocity.y;

		if(left_collision_detector(ball.location.x, ball.radius) == 1 || right_collision_detector(ball.location.x, ball.radius) == 1) {
			ball.velocity.x = -ball.velocity.x;
		}
		if(up_collision_detector(ball.location.y, ball.radius) == TRUE || down_collision_detector(ball.location.y, ball.radius) == TRUE) {
			ball.velocity.y = -ball.velocity.y;
		}

	return ball;
}


