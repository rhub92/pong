/*
 * pong.h
 * Author: Todd Branchflower
 * Slightly modified on 16OCT13 to include my "#define" for the
 * window size and true or false if the ball hits the edge of the wall
 * Date: 11 Oct 2013
 * Description: Implements a subset of the pong game
 */



#ifndef _PONG_H
#define _PONG_H


#define WINDOW_WIDTH 300
#define WINDOW_HEIGHT 300
#define TRUE  1
#define FALSE 0

typedef struct {
int x;
int y;
	} vector2d_t;
	
typedef struct {
vector2d_t location;
unsigned char radius;
vector2d_t velocity;
} ball_t;




ball_t createBall(int xPos, int yPos, int xVel, int yVel, unsigned char radius);

ball_t moveBall(ball_t ballToMove);

#endif





