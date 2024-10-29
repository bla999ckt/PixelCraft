#include "stdio.h"
#include "stdbool.h"
#include "math.h"
#include "GL/glut.h"
#include "string.h"
#include "time.h"

float bekgronAlpha = 0.1f; // Initial alpha value for bekgron
int bekgronIncreasing = 1; // Flag for bekgron transparency direction
// Window dimensions
const int screenWidth = 600;
const int screenHeight = 600;
const int difficultyScreenWidth = 400;
const int difficultyScreenHeight = 200;
// Paddle dimensions
const int paddleWidth = 100;
const int paddleHeight = 20;
// Ball properties
const float ballRadius = 10.0;
float ballX = screenWidth / 2.0;
float ballY = screenHeight / 2.0;
float ballSpeedX = 2.0;
float ballSpeedY = 2.0;
bool gameOver = false;
// Paddle properties
float paddleX = (screenWidth - paddleWidth) / 2.0;
const float paddleY = 20.0;
// Bricks properties
const int brickRows = 5;
const int brickColumns = 10;
const int brickWidth = 55;
const int brickHeight = 30;
bool bricks[5][10] = {{true, true, true, true, true, true, true, true, true, true},
{true, true, true, true, true, true, true, true, true, true},
{true, true, true, true, true, true, true, true, true, true},
{true, true, true, true, true, true, true, true, true, true},
{true, true, true, true, true, true, true, true, true, true}};
bool gameWon = false;
bool gameFailed = false;
int score = 0;
bool difficultySelected = false;
bool easyMode = false;
bool hardMode = false;
// Global variable to store the start time
time_t startTime;
// Function to initialize the timer
void initTimer() {
startTime = time(NULL);
}
// Function to get the elapsed time in seconds
int getElapsedTime() {
return difftime(time(NULL), startTime);
}
// Function declarations
void drawHardBackground();
void drawEasyBackground();
void drawRectangle(float x, float y, float width, float height);
void drawDifficultyPopup();
void drawPopup(const char* message);
void drawPaddle();
void drawBall();
void drawBrick(float x, float y);
void drawBricks();
void draw();
void drawCircle(float x, float y, float radius) {
glBegin(GL_TRIANGLE_FAN);
glColor3f(1.0, 1.0, 0.0);
glVertex2f(x, y);
for (int i = 0; i <= 360; i++) {
float angle = 2.0 * M_PI * i / 360.0;
glVertex2f(x + radius * cos(angle), y + radius * sin(angle));
}
glEnd();
}
void drawawan()
{
 glBegin(GL_POLYGON);
 glVertex2f(1, -4);
 glVertex2f(2, -5);
 glVertex2f(4, -5);
 glVertex2f(5, -4);
 glVertex2f(5, -2);
 glVertex2f(4, -1);
 glVertex2f(2, -1);
 glVertex2f(1, -2);
  glEnd();
}
void drawSquare()
{
glBegin(GL_POLYGON);
glVertex2f(-5, 5);
glVertex2f(5, 5);
glVertex2f(5, -5);
glVertex2f(-5, -5);
glEnd();
}
void drawCloud()
{
glBegin(GL_POLYGON);
glVertex2f(3, 3);
glVertex2f(6, 5);
glVertex2f(9, 6);
glVertex2f(12, 6);
glVertex2f(15, 5);
glVertex2f(18, 3);
glEnd();
}
void drawCloud2()
{
glBegin(GL_POLYGON);
glVertex2f(3, 3);
glVertex2f(6, 5);
glVertex2f(9, 6);
glVertex2f(9.5, 5.2);
glVertex2f(8.6, 4.3);
glVertex2f(6.7, 3.7);
glVertex2f(4.4, 3.2);
glEnd();
}
// Function to draw the background for easy mode
void drawEasyBackground() {
    glClearColor(0.18431372549, 0.03529411764, 0.14901960784, 1); // Background color
    glColor3f(0.0406, 0.223, 0.290); // Element color
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 100, 0, 100);
    glClear(GL_COLOR_BUFFER_BIT);

    glColor4f(0.8, 0.2, 0.47,0.05); // pinkWhite color
     glPushMatrix();
     glTranslatef(13, 45, 0);
     glScalef(18, 10, 0); // Scale factor adjusted for better visibility
     drawSquare();
     glPopMatrix();
     glFlush();
    //langit
     glColor4f(0.8, 0.2, 0.47,0.05); // pinkWhite color
     glPushMatrix();
     glTranslatef(13, 50, 0);
     glScalef(18, 10, 0); // Scale factor adjusted for better visibility
     drawSquare();
     glPopMatrix();
     glFlush();
    //langit 1
     glColor4f(0.8, 0.2, 0.47,0.05); // pinkWhite color
     glPushMatrix();
     glTranslatef(13, 35, 0);
     glScalef(18, 10, 0); // Scale factor adjusted for better visibility
     drawSquare();
     glPopMatrix();
     glFlush();
    //lanigit 2
     glColor4f(0.8, 0.2, 0.47,0.05); // pinkWhite color
     glPushMatrix();
     glTranslatef(13, 30, 0);
     glScalef(18, 10, 0); // Scale factor adjusted for better visibility
     drawSquare();
     glPopMatrix();
     glFlush();
    //langit 3
     glColor4f(0.8, 0.2, 0.47,0.05); // pinkWhite color
     glPushMatrix();
     glTranslatef(13, 25, 0);
     glScalef(18, 10, 0); // Scale factor adjusted for better visibility
     drawSquare();
     glPopMatrix();
     glFlush();
    // langit 4
     glColor4f(0.8, 0.2, 0.47,0.05); // pinkWhite color
     glPushMatrix();
     glTranslatef(13, 25, 0);
     glScalef(18, 10, 0); // Scale factor adjusted for better visibility
     drawSquare();
     glPopMatrix();
     glFlush();
    //langit 5
     glColor4f(0.8, 0.2, 0.47,0.8); // pinkWhite color
     glPushMatrix();
     glTranslatef(13, 15, 0);
     glScalef(18, 10, 0); // Scale factor adjusted for better visibility
     drawSquare();
     glPopMatrix();
     glFlush();
    //langit 6 that was not there initially
     glColor3ub(204, 255, 229); // lightgreen
     glPushMatrix();
     glTranslatef(-8, 70, 0);
     glScalef(2.5, 2.5, 0); // Scale factor adjusted for better visibility
     drawawan();
     glPopMatrix();
     glFlush(); //awan 1
    glColor3ub(204, 255, 229); // lightgreen
     glPushMatrix();
     glTranslatef(3, 64, 0);
     glScalef(1, 1, 0); // Scale factor adjusted for better visibility
     drawawan();
     glPopMatrix();
     glFlush(); //awan 2

    glColor3ub(204, 255, 229); // lightgreen
     glPushMatrix();
     glTranslatef(4, 65, 0);
     glScalef(2.5, 2.5, 0); // Scale factor adjusted for better visibility
     drawawan();
     glPopMatrix();
     glFlush(); //awan 3
    glColor3ub(204, 255, 229); // lightgreen
     glPushMatrix();
     glTranslatef(10, 67, 0);
     glScalef(1.5, 1.5, 0); // Scale factor adjusted for better visibility
     drawawan();
     glPopMatrix();
     glFlush();
    //awan 4
    glColor3ub(204, 255, 229); // lightgreen
     glPushMatrix();
     glTranslatef(15, 64, 0);
     glScalef(1, 1, 0); // Scale factor adjusted for better visibility
     drawawan();
     glPopMatrix();
     glFlush(); //awan5
    glColor3ub(204, 255, 229); // lightgreen
     glPushMatrix();
     glTranslatef(18, 62, 0);
     glScalef(1, 1, 0); // Scale factor adjusted for better visibility
     drawawan();
     glPopMatrix();
     glFlush();
    //awan 6
    glColor3ub(204, 255, 229); // lightgreen
     glPushMatrix();
     glTranslatef(20, 70, 0);
     glScalef(2.5, 2.5, 0); // Scale factor adjusted for better visibility
     drawawan();
     glPopMatrix();
     glFlush(); //awan1a
    glColor3ub(204, 255, 229); // lightgreen
     glPushMatrix();
     glTranslatef(29, 68, 0);
     glScalef(1, 1, 0); // Scale factor adjusted for better visibility
     drawawan();
     glPopMatrix();
     glFlush(); //awan2a
    glColor3ub(204, 255, 229); // lightgreen
     glPushMatrix();
     glTranslatef(29, 65, 0);
     glScalef(2.5, 2.5, 0); // Scale factor adjusted for better visibility
     drawawan();
     glPopMatrix();
     glFlush(); //awan3a
    glColor3ub(204, 255, 229); // lightgreen
     glPushMatrix();
     glTranslatef(39, 67, 0);
     glScalef(1.5, 1.5, 0); // Scale factor adjusted for better visibility
     drawawan();
     glPopMatrix();
     glFlush(); //awan4a
    glColor3ub(204, 255, 229); // lightgreen
     glPushMatrix();
     glTranslatef(35, 64, 0);
     glScalef(1, 1, 0); // Scale factor adjusted for better visibility
     drawawan();
     glPopMatrix();
     glFlush(); //awan5a
    glColor3ub(204, 255, 229); // lightgreen
     glPushMatrix();
     glTranslatef(43, 62, 0);
     glScalef(1, 1, 0); // Scale factor adjusted for better visibility
     drawawan();
     glPopMatrix();
     glFlush();//awan6a
    glColor3ub(204, 255, 229); // lightgreen
     glPushMatrix();
     glTranslatef(45, 70, 0);
     glScalef(2.5, 2.5, 0); // Scale factor adjusted for better visibility
     drawawan();
     glPopMatrix();
     glFlush(); //awan1b
    glColor3ub(204, 255, 229); // lightgreen
     glPushMatrix();
     glTranslatef(49, 68, 0);
     glScalef(1, 1, 0); // Scale factor adjusted for better visibility
     drawawan();
     glPopMatrix();
     glFlush(); //awan2b


    glColor3ub(204, 255, 229); // lightgreen
     glPushMatrix();
     glTranslatef(55, 65, 0);
     glScalef(2.5, 2.5, 0); // Scale factor adjusted for better visibility
     drawawan();
     glPopMatrix();
     glFlush();//awan3b

    glColor3ub(204, 255, 229); // lightgreen
     glPushMatrix();
     glTranslatef(64, 67, 0);
     glScalef(1.5, 1.5, 0); // Scale factor adjusted for better visibility
     drawawan();
     glPopMatrix();
     glFlush(); //awan4b


    glColor3ub(204, 255, 229); // lightgreen
     glPushMatrix();
     glTranslatef(55, 62, 0);
     glScalef(1, 1, 0); // Scale factor adjusted for better visibility
     drawawan();
     glPopMatrix();
     glFlush(); //awan5b


    glColor3ub(204, 255, 229); // lightgreen
     glPushMatrix();
     glTranslatef(79, 70, 0);
     glScalef(2.5, 2.5, 0); // Scale factor adjusted for better visibility
     drawawan();
     glPopMatrix();
     glFlush(); //awan1c
    glColor3ub(204, 255, 229); // lightgreen
     glPushMatrix();
     glTranslatef(88, 68, 0);
     glScalef(1, 1, 0); // Scale factor adjusted for better visibility
     drawawan();
     glPopMatrix();
     glFlush(); //awan2c
     glColor3ub(204, 255, 229); // lightgreen
     glPushMatrix();
     glTranslatef(73, 65, 0);
     glScalef(2.5, 2.5, 0); // Scale factor adjusted for better visibility
     drawawan();
     glPopMatrix();
     glFlush(); //awan3c


    glColor3ub(204, 255, 229); // lightgreen
     glPushMatrix();
     glTranslatef(68, 67, 0);
     glScalef(1.5, 1.5, 0); // Scale factor adjusted for better visibility
     drawawan();
     glPopMatrix();
     glFlush(); //awan4c

    glColor3ub(204, 255, 229); // lightgreen
     glPushMatrix();
     glTranslatef(76, 62, 0);
     glScalef(1, 1, 0); // Scale factor adjusted for better visibility
     drawawan();
     glPopMatrix();
     glFlush(); //awan5c

    glColor3ub(204, 255, 229); // lightgreen
     glPushMatrix();
     glTranslatef(90, 62, 0);
     glScalef(1, 1, 0); // Scale factor adjusted for better visibility
     drawawan();
     glPopMatrix();
     glFlush(); //awan6c


    glColor3ub(204, 255, 229); // lightgreen
     glPushMatrix();
     glTranslatef(92, 66, 0);
     glScalef(2.5, 2.5, 0); // Scale factor adjusted for better visibility
     drawawan();
     glPopMatrix();
     glFlush(); //awanbesar
     glColor3ub(204, 255, 229); // lightgreen
     glPushMatrix();
     glTranslatef(13, 10, 0);
     glScalef(18, 10, 0); // Scale factor adjusted for better visibility
     drawSquare();
     glPopMatrix();
     glFlush(); //awantutup



    glColor3ub(255, 209, 220); // White color
     glPushMatrix();
     glTranslatef(-10, 50, 0);
     glScalef(2.5, 2.5, 0); // Scale factor adjusted for better visibility
     drawawan();
     glPopMatrix();
     glFlush(); //awan1d
    glColor3ub(255, 209, 220); // babypink
     glPushMatrix();
     glTranslatef(8, 42, 0);
     glScalef(1, 1, 0); // Scale factor adjusted for better visibility
     drawawan();
     glPopMatrix();
     glFlush(); //awan2d

    glColor3ub(255, 209, 220); // babypink
     glPushMatrix();
     glTranslatef(-2, 44, 0);
     glScalef(2.5, 2.5, 0); // Scale factor adjusted for better visibility
     drawawan();
     glPopMatrix();
     glFlush(); //awan3d


    glColor3ub(255, 209, 220); // babypink
     glPushMatrix();
     glTranslatef(10, 39.6, 0);
     glScalef(1.5, 1.5, 0); // Scale factor adjusted for better visibility
     drawawan();
     glPopMatrix();
     glFlush(); //awan4d


    glColor3ub(255, 209, 220); // babypink
     glPushMatrix();
     glTranslatef(16, 35, 0);
     glScalef(1, 1, 0); // Scale factor adjusted for better visibility
     drawawan();
     glPopMatrix();
     glFlush();//awan5d

    glColor3ub(255, 209, 220); // babypink
     glPushMatrix();
     glTranslatef(19, 37, 0);
     glScalef(1, 1, 0); // Scale factor adjusted for better visibility
     drawawan();
     glPopMatrix();
     glFlush();//awan6d

    glColor3ub(255, 209, 220); // babypink
     glPushMatrix();
     glTranslatef(21, 40, 0);
     glScalef(2.5, 2.5, 0); // Scale factor adjusted for better visibility
     drawawan();
     glPopMatrix();
     glFlush();//awan1ad

    glColor3ub(255, 209, 220); // babypink
     glPushMatrix();
     glTranslatef(30, 32, 0);
     glScalef(1, 1, 0); // Scale factor adjusted for better visibility
     drawawan();
     glPopMatrix();
     glFlush(); //awan2ad
    glColor3ub(255, 209, 220); // babypink
     glPushMatrix();
     glTranslatef(32, 34.5, 0);
     glScalef(2.5, 2.5, 0); // Scale factor adjusted for better visibility
     drawawan();
     glPopMatrix();
     glFlush(); //awan3ad

    glColor3ub(255, 209, 220); // babypink
     glPushMatrix();
     glTranslatef(39, 36, 0);
     glScalef(1.5, 1.5, 0); // Scale factor adjusted for better visibility
     drawawan();
     glPopMatrix();
     glFlush(); //awan4ad
    glColor3ub(255, 209, 220); // babypink
     glPushMatrix();
     glTranslatef(44, 37, 0);
     glScalef(1, 1, 0); // Scale factor adjusted for better visibility
     drawawan();
     glPopMatrix();
     glFlush(); //awan5ad

    glColor3ub(255, 209, 220); // babypink
     glPushMatrix();
     glTranslatef(46, 35, 0);
     glScalef(1, 1, 0); // Scale factor adjusted for better visibility
     drawawan();
     glPopMatrix();
     glFlush(); //awan6ad


    glColor3ub(255, 209, 220); // babypink
     glPushMatrix();
     glTranslatef(48, 40, 0);
     glScalef(2.5, 2.5, 0); // Scale factor adjusted for better visibility
     drawawan();
     glPopMatrix();
     glFlush(); //awan1bd


    glColor3ub(255, 209, 220); // babypink
     glPushMatrix();
     glTranslatef(57, 38, 0);
     glScalef(1, 1, 0); // Scale factor adjusted for better visibility
     drawawan();
     glPopMatrix();
     glFlush(); //awan2bd

    glColor3ub(255, 209, 220); // babypink
     glPushMatrix();
     glTranslatef(58.9, 45, 0);
     glScalef(2.5, 2.5, 0); // Scale factor adjusted for better visibility
     drawawan();
     glPopMatrix();
     glFlush(); //awan3bd

    glColor3ub(255, 209, 220); // babypink
     glPushMatrix();
     glTranslatef(67, 47, 0);
     glScalef(1.5, 1.5, 0); // Scale factor adjusted for better visibility
     drawawan();
     glPopMatrix();
     glFlush(); //awan4bd


    glColor3ub(255, 209, 220); // babypink
     glPushMatrix();
     glTranslatef(52, 42, 0);
     glScalef(1, 1, 0); // Scale factor adjusted for better visibility
     drawawan();
     glPopMatrix();
     glFlush(); //awan5bd


    glColor3ub(255, 209, 220); // babypink
     glPushMatrix();
     glTranslatef(74, 42, 0);
     glScalef(1, 1, 0); // Scale factor adjusted for better visibility
     drawawan();
     glPopMatrix();
     glFlush(); //awan6bd


    glColor3ub(255, 209, 220); // babypink
     glPushMatrix();
     glTranslatef(86, 50, 0);
     glScalef(2.5, 2.5, 0); // Scale factor adjusted for better visibility
     drawawan();
     glPopMatrix();
     glFlush(); //awan1cd
    glColor3ub(255, 209, 220); // babypink
     glPushMatrix();
     glTranslatef(97, 48, 0);
     glScalef(1, 1, 0); // Scale factor adjusted for better visibility
     drawawan();
     glPopMatrix();
     glFlush(); //awan2cd


    glColor3ub(255, 209, 220); // babypink
     glPushMatrix();
     glTranslatef(77, 45, 0);
     glScalef(2.5, 2.5, 0); // Scale factor adjusted for better visibility
     drawawan();
     glPopMatrix();
     glFlush(); //awan3cd
    glColor3ub(255, 209, 220); // babypink
     glPushMatrix();
     glTranslatef(72, 43, 0);
     glScalef(1.5, 1.5, 0); // Scale factor adjusted for better visibility
     drawawan();
     glPopMatrix();
     glFlush(); //awan4cd
    glColor3ub(255, 209, 220); // babypink
     glPushMatrix();
     glTranslatef(79, 42, 0);
     glScalef(1, 1, 0); // Scale factor adjusted for better visibility
     drawawan();
     glPopMatrix();
     glFlush(); //awan5cd


    glColor3ub(255, 209, 220); // babypink
     glPushMatrix();
     glTranslatef(92, 48, 0);
     glScalef(2.5, 2.5, 0); // Scale factor adjusted for better visibility
     drawawan();
     glPopMatrix();
     glFlush();//awanbesard
     glColor3ub(255, 209, 220); // babypink
     glPushMatrix();
     glTranslatef(85, 1, 0);
     glScalef(3, 7.8, 0); // Scale factor adjusted for better visibility
     drawSquare();
     glPopMatrix();
     glFlush(); //awantutupd1
     glColor3ub(255, 209, 220); // babypink
     glPushMatrix();
     glTranslatef(59.7, 2.7, 0);
     glScalef(3.5, 6.3, 0); // Scale factor adjusted for better visibility
     drawSquare();
     glPopMatrix();
     glFlush(); //awantutupd2

     glColor3ub(255, 209, 220); // babypink
     glPushMatrix();
     glTranslatef(0, 8, 0);
     glScalef(3, 6, 0); // Scale factor adjusted for better visibility
     drawSquare();
     glPopMatrix();
     glFlush(); //awantutupd3

     glColor3ub(255, 209, 220); // babypink
     glPushMatrix();
     glTranslatef(35, 2, 0);
     glScalef(2, 5.5, 0); // Scale factor adjusted for better visibility
     drawSquare();
     glPopMatrix();
     glFlush(); //awantutupd4

     glColor3ub(255, 209, 220); // babypink
     glPushMatrix();
     glTranslatef(22, 2, 0);
     glScalef(2, 6.3, 0); // Scale factor adjusted for better visibility
     drawSquare();
     glPopMatrix();
     glFlush(); //awantutupd5


     glColor3ub(161,161,206); // bluishpurple
     glPushMatrix();
     glTranslatef(-1, 1, 0);
     glScalef(2, 4, 0); // Scale factor adjusted for better visibility
     drawSquare();
     glPopMatrix();
     glFlush(); //city1
     glColor3ub(161,161,206); // bluishpurple
     glPushMatrix();
     glTranslatef(5, 13, 0);
     glScalef(2, 0.1, 0); // Scale factor adjusted for better visibility
     drawSquare();
     glPopMatrix();
     glFlush(); //city2
     glColor3ub(161,161,206); // bluishpurple
     glPushMatrix();
     glTranslatef(5, 8, 0);
     glScalef(2, 0.1, 0); // Scale factor adjusted for better visibility
     drawSquare();
     glPopMatrix();
     glFlush(); //city3
     glColor3ub(161,161,206); // bluishpurple
     glPushMatrix();
     glTranslatef(15, 4, 0);
     glScalef(0.5, 5, 0); // Scale factor adjusted for better visibility
     drawSquare();
     glPopMatrix();
     glFlush(); //city 4

     glColor3ub(161,161,206); // bluishpurple
     glPushMatrix();
     glTranslatef(30, 4, 0);
     glScalef(1, 2, 0); // Scale factor adjusted for better visibility
     drawSquare();
     glPopMatrix();
     glFlush(); //city 5

     glColor3ub(161,161,206); // bluishpurple
     glPushMatrix();
     glTranslatef(35, 10, 0);
     glScalef(2, 0.1, 0); // Scale factor adjusted for better visibility
     drawSquare();
     glPopMatrix();
     glFlush(); //city 6

     glColor3ub(161,161,206); // bluishpurple
     glPushMatrix();
     glTranslatef(46, 4, 0);
     glScalef(1, 4, 0); // Scale factor adjusted for better visibility
     drawSquare();
     glPopMatrix();
     glFlush(); //city 7

     glColor3ub(161,161,206); // bluishpurple
     glPushMatrix();
     glTranslatef(52, 3, 0);
     glScalef(1, 2, 0); // Scale factor adjusted for better visibility
     drawSquare();
     glPopMatrix();
     glFlush(); //city 8

     glColor3ub(161,161,206); // bluishpurple
     glPushMatrix();
     glTranslatef(64, 4, 0);
     glScalef(0.8, 6, 0); // Scale factor adjusted for better visibility
     drawSquare();
     glPopMatrix();
     glFlush(); //city 9


     glColor3ub(161,161,206); // bluishpurple
     glPushMatrix();
     glTranslatef(20, 4, 0);
     glScalef(2, 1, 0); // Scale factor adjusted for better visibility
     drawSquare();
     glPopMatrix();
     glFlush(); //city24ab

     glColor3ub(161,161,206); // bluishpurple
     glPushMatrix();
     glTranslatef(53, 20, 0);
     glScalef(2, 0.1, 0); // Scale factor adjusted for better visibility
     drawSquare();
     glPopMatrix();
     glFlush(); //city10
     glColor3ub(161,161,206); // bluishpurple
     glPushMatrix();
     glTranslatef(70, 4, 0);
     glScalef(2, 1, 0); // Scale factor adjusted for better visibility
     drawSquare();
     glPopMatrix();
     glFlush(); //city11

     glColor3ub(161,161,206); // bluishpurple
     glPushMatrix();
     glTranslatef(73, 4, 0);
     glScalef(0.4, 5, 0); // Scale factor adjusted for better visibility
     drawSquare();
     glPopMatrix();
     glFlush(); //city12
     glColor3ub(161,161,206); // bluishpurple
     glPushMatrix();
     glTranslatef(87, 4, 0);
     glScalef(1.4, 4, 0); // Scale factor adjusted for better visibility
     drawSquare();
     glPopMatrix();
     glFlush(); //city13

     glColor3ub(161,161,206); // bluishpurple
     glPushMatrix();
     glTranslatef(95, 6, 0);
     glScalef(1, 1.4, 0); // Scale factor adjusted for better visibility
     drawSquare();
     glPopMatrix();
     glFlush(); //city14

     glColor3ub(161,161,206); // bluishpurple
     glPushMatrix();
     glTranslatef(100, 4, 0);
     glScalef(0.5, 5, 0); // Scale factor adjusted for better visibility
     drawSquare();
     glPopMatrix();
     glFlush(); //city15
     glColor3ub(204, 102, 153); // midmagenta
     glPushMatrix();
     glTranslatef(1, -1, 0);
     glScalef(0.2, 2, 0); // Scale factor adjusted for better visibility
     drawSquare();
     glPopMatrix();
     glFlush(); //city16

     glColor3ub(204, 102, 153); // midmagenta
     glPushMatrix();
     glTranslatef(5, -1, 0);
     glScalef(1, 0.8, 0); // Scale factor adjusted for better visibility
     drawSquare();
     glPopMatrix();
     glFlush(); //city17

     glColor3ub(204, 102, 153); // midmagenta
     glPushMatrix();
     glTranslatef(9, -1, 0);
     glScalef(0.7, 1.5, 0); // Scale factor adjusted for better visibility
     drawSquare();
     glPopMatrix();
     glFlush();//city18
     glColor3ub(204, 102, 153); // midmagenta
     glPushMatrix();
     glTranslatef(12, -1, 0);
     glScalef(1, 1, 0); // Scale factor adjusted for better visibility
     drawSquare();
     glPopMatrix();
     glFlush(); //city19
     glColor3ub(204, 102, 153); // midmagenta
     glPushMatrix();
     glTranslatef(17, -1, 0);
     glScalef(0.3, 1.2, 0); // Scale factor adjusted for better visibility
     drawSquare();
     glPopMatrix();
     glFlush(); //city20

     glColor3ub(204, 102, 153); // midmagenta
     glPushMatrix();
     glTranslatef(20, -1, 0);
     glScalef(0.2, 1.2, 0); // Scale factor adjusted for better visibility
     drawSquare();
     glPopMatrix();
     glFlush(); //city21

     glColor3ub(204, 102, 153); // midmagenta
     glPushMatrix();
     glTranslatef(17, 3, 0);
     glScalef(1, 0.05, 0); // Scale factor adjusted for better visibility
     drawSquare();
     glPopMatrix();
     glFlush(); //city22

     glColor3ub(204, 102, 153); // midmagenta
     glPushMatrix();
     glTranslatef(23, -1, 0);
     glScalef(0.21, 1, 0); // Scale factor adjusted for better visibility
     drawSquare();
     glPopMatrix();
     glFlush(); //city23

     glColor3ub(204, 102, 153); // midmagenta
     glPushMatrix();
     glTranslatef(28, -1, 0);
     glScalef(1, 0.5, 0); // Scale factor adjusted for better visibility
     drawSquare();
     glPopMatrix();
     glFlush(); //city24

     glColor3ub(204, 102, 153); // midmagenta
     glPushMatrix();
     glTranslatef(98, -1, 0);
     glScalef(0.2, 2, 0); // Scale factor adjusted for better visibility
     drawSquare();
     glPopMatrix();
     glFlush(); //city16a
     glColor3ub(204, 102, 153); // midmagenta
     glPushMatrix();
     glTranslatef(87, -1, 0);
     glScalef(1, 0.8, 0); // Scale factor adjusted for better visibility
     drawSquare();
     glPopMatrix();
     glFlush(); //city17a

     glColor3ub(204, 102, 153); // midmagenta
     glPushMatrix();
     glTranslatef(89, -1, 0);
     glScalef(0.7, 1.5, 0); // Scale factor adjusted for better visibility
     drawSquare();
     glPopMatrix();
     glFlush(); //city18a

     glColor3ub(204, 102, 153); // midmagenta
     glPushMatrix();
     glTranslatef(92, -1, 0);
     glScalef(1, 1, 0); // Scale factor adjusted for better visibility
     drawSquare();
     glPopMatrix();
     glFlush(); //city19a

     glColor3ub(204, 102, 153); // midmagenta
     glPushMatrix();
     glTranslatef(96, -1, 0);
     glScalef(0.3, 1.2, 0); // Scale factor adjusted for better visibility
     drawSquare();
     glPopMatrix();
     glFlush();//city 20a

     glColor3ub(204, 102, 153); // midmagenta
     glPushMatrix();
     glTranslatef(94, -1, 0);
     glScalef(0.2, 1.2, 0); // Scale factor adjusted for better visibility
     drawSquare();
     glPopMatrix();
     glFlush(); //city21a
     glColor3ub(204, 102, 153); // midmagenta
     glPushMatrix();
     glTranslatef(80, 3, 0);
     glScalef(1, 0.05, 0); // Scale factor adjusted for better visibility
     drawSquare();
     glPopMatrix();
     glFlush(); //city22a

     glColor3ub(204, 102, 153); // midmagenta
     glPushMatrix();
     glTranslatef(76, -1, 0);
     glScalef(0.21, 1, 0); // Scale factor adjusted for better visibility
     drawSquare();
     glPopMatrix();
     glFlush(); //city23a

     glColor3ub(204, 102, 153); // midmagenta
     glPushMatrix();
     glTranslatef(100, -1, 0);
     glScalef(1, 0.5, 0); // Scale factor adjusted for better visibility
     drawSquare();
     glPopMatrix();
     glFlush(); //city24a

     glColor3ub(204, 102, 153); // midmagenta
     glPushMatrix();
     glTranslatef(72, -1, 0);
     glScalef(1, 0.5, 0); // Scale factor adjusted for better visibility
     drawSquare();
     glPopMatrix();
     glFlush(); //city24c
    glFlush(); //end of hard level background
    glLoadIdentity();
    gluOrtho2D(0, screenWidth, 0, screenHeight);
}

// Function to draw the background for hard mode
void drawHardBackground() {
    glClearColor(0.18431372549, 0.03529411764, 0.14901960784, 1); // Background color
    glColor3f(0.0406, 0.223, 0.290); // Element color
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 100, 0, 100);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor4f(1, 0.7058823529411765, 0.9058823529411765,0.02);
    glPushMatrix();
    glTranslatef(20, 45, 0);
    glScalef(18, 10, 0);
    drawSquare();
    glPopMatrix();
    glFlush();
    glColor4f(0.8, 0.2, 0.47,0.05);
    glPushMatrix();
    glTranslatef(13, 35, 0);
    glScalef(18, 10, 0);
    drawSquare();
    glPopMatrix();
    glFlush();
    glColor4f(0.8, 0.2, 0.47,0.05);
    glPushMatrix();
    glTranslatef(13, 25, 0);
    glScalef(18, 10, 0);
    drawSquare();
    glPopMatrix();
    glFlush();
    //sky 2
    glColor4f(0.8, 0.2, 0.47,0.05);
    glPushMatrix();
    glTranslatef(13, 15, 0);
    glScalef(18, 10, 0);
    drawSquare();
    glPopMatrix();
    glFlush();
    // sky 3
    glColor4f(0.8, 0.2, 0.47,0.05);
    glPushMatrix();
    glTranslatef(13, 5, 0);
    glScalef(18, 10, 0);
    drawSquare();
    glPopMatrix();
    glFlush();
    //sky 4
    glColor4f(0.8, 0.2, 0.47,0.05);
    glPushMatrix();
    glTranslatef(13, 0, 0);
    glScalef(18, 10, 0);
    drawSquare();
    glPopMatrix();
    glFlush();
    //sky5
    glColor4f(0.8, 0.2, 0.47,0.05);
    glPushMatrix();
    glTranslatef(13, -5, 0);
    glScalef(18, 10, 0);
    drawSquare();
    glPopMatrix();
    glFlush();
    //sky 6
    glColor4f(0.8, 0.2, 0.47,0.05);
    glPushMatrix();
    glTranslatef(13, -10, 0);
    glScalef(18, 10, 0);
    drawSquare();
    glPopMatrix();
    glFlush();
    //sky 7
    glColor4f(0.8, 0.2, 0.47,0.05);
    glPushMatrix();
    glTranslatef(13, -13, 0);
    glScalef(18, 10, 0);
    drawSquare();
    glPopMatrix();
    glFlush(); //sky 8
    glColor4f(0.8, 0.2, 0.47,0.05);
    glPushMatrix();
    glTranslatef(13, -17, 0);
    glScalef(18, 10, 0);
    drawSquare();
    glPopMatrix();
    glFlush();
    //sky 9
    glColor4f(0.9254901960784314, 0.49019607843137253, 1,0.07);
    glPushMatrix();
    glTranslatef(13, -50 ,0);
    glScalef(18, 10, 0);
    drawSquare();
    glPopMatrix();
    glFlush();
    //sky 10
    glColor4f(0.996078431372549, 0.7137254901960784, 0.9019607843137255,0.00234);
    glPushMatrix();
    glTranslatef(13, -30 ,0);
    glScalef(18, 10, 0);
    drawSquare();
    glPopMatrix();
    glFlush();
    //sky11
    drawCircle(50, 90, 5.0);
    glColor3ub(139, 132, 212);
    glPushMatrix();
    glTranslatef(0, 32, 0);
    glScalef(1, 1.5, 0);
    drawCloud();
    glColor4f(0.7450980392156862, 0.5176470588235295, 0.8313725490196079,0.5);
    drawCloud2();
    glPopMatrix();
    glFlush(); //cloud1
    glColor3ub(138,134,209);
    glPushMatrix();
    glTranslatef(5, 26.9, 0);
    glScalef(1.9, 3.2, 0);
    drawCloud();
    glColor4f(0.7450980392156862, 0.5176470588235295, 0.8313725490196079,0.5);
    drawCloud2();
    glPopMatrix();
    glFlush();
    //cloud 2
    glColor3ub(138,134,209);
    glPushMatrix();
    glTranslatef(-5, 34.5, 0);
    glScalef(1, 0.66, 0);
    drawCloud();
    glColor4f(0.7450980392156862, 0.5176470588235295, 0.8313725490196079,0.5);
    drawCloud2();
    glPopMatrix();
    glFlush(); //cloud 3
    glColor3ub(139, 132, 212);
    glPushMatrix();
    glTranslatef(27, 32, 0);
    glScalef(1, 1.5, 0);
    drawCloud();
    glColor4f(0.7450980392156862, 0.5176470588235295, 0.8313725490196079,0.5);
    drawCloud2();
    glPopMatrix();
    glFlush();
    //cloud 4
    glColor3ub(138,134,209);
    glPushMatrix();
    glTranslatef(35, 34.5, 0);
    glScalef(1, 0.66, 0);
    drawCloud();
    glColor4f(0.7450980392156862, 0.5176470588235295, 0.8313725490196079,0.5);
    drawCloud2();
    glPopMatrix();
    glFlush(); //cloud 5
    glColor3ub(139, 132, 212);
    glPushMatrix();
    glTranslatef(45, 80, 0);
    glScalef(1, 1.5, 0);
    drawCloud();
    glColor4f(0.7450980392156862, 0.5176470588235295, 0.8313725490196079,0.5);
    drawCloud2();
    glPopMatrix();
    glFlush();
    //cloud 6
    glColor3ub(138,134,209);
    glPushMatrix();
    glTranslatef(50, 74.9, 0);
    glScalef(1.9, 3.2, 0);
    drawCloud();
    glColor4f(0.7450980392156862, 0.5176470588235295, 0.8313725490196079,0.5);
    drawCloud2();
    glPopMatrix();
    glFlush();
    //cloud 7
    glColor3ub(138,134,209);
    glPushMatrix();
    glTranslatef(40, 82.5, 0);
    glScalef(1, 0.66, 0);
    drawCloud();
    glColor4f(0.7450980392156862, 0.5176470588235295, 0.8313725490196079,0.5);
    drawCloud2();
    glPopMatrix();
    glFlush();
    //cloud 8
    glColor3ub(139, 132, 212);
    glPushMatrix();
    glTranslatef(72, 80, 0);
    glScalef(1, 1.5, 0);
    drawCloud();
    glColor4f(0.7450980392156862, 0.5176470588235295, 0.8313725490196079,0.5);
    drawCloud2();
    glPopMatrix();
    glFlush();
    //cloud 9
    glColor3ub(138,134,209);
    glPushMatrix();
    glTranslatef(79, 82.5, 0);
    glScalef(1, 0.66, 0);
    drawCloud();
    glColor4f(0.7450980392156862, 0.5176470588235295, 0.8313725490196079,0.5);
    drawCloud2();
    glPopMatrix();
    glFlush();
    //cloud 10
    glColor3ub(52, 24, 72);
    glPushMatrix();
    glTranslatef(-1, 1, 0);
    glScalef(2, 4, 0);
    drawSquare();
    glPopMatrix();
    glFlush(); //city1
    glColor3ub(52, 24, 72);
    glPushMatrix();
    glTranslatef(5, 13, 0);
    glScalef(2, 0.1, 0);
    drawSquare();
    glPopMatrix();
    glFlush();
    //city 2
    glColor3ub(52, 24, 72);
    glPushMatrix();
    glTranslatef(5, 8, 0);
    glScalef(2, 0.1, 0);
    drawSquare();
    glPopMatrix();
    glFlush();
    //city 3
    glColor3ub(52, 24, 72);
    glPushMatrix();
    glTranslatef(15, 4, 0);
    glScalef(0.5, 5, 0);
    drawSquare();
    glPopMatrix();
    glFlush();
    //city 4
    glColor3ub(52, 24, 72);
    glPushMatrix();
    glTranslatef(30, 4, 0);
    glScalef(1, 2, 0);
    drawSquare();
    glPopMatrix();
    glFlush();
    //city 5
    glColor3ub(52, 24, 72);
    glPushMatrix();
    glTranslatef(35, 10, 0);
    glScalef(2, 0.1, 0);
    drawSquare();
    glPopMatrix();
    glFlush();
    //city 6
    glColor3ub(52, 24, 72);
    glPushMatrix();
    glTranslatef(46, 4, 0);
    glScalef(1, 4, 0);
    drawSquare();
    glPopMatrix();
    glFlush();
    //city 7
    glColor3ub(52, 24, 72);
    glPushMatrix();
    glTranslatef(52, 3, 0);
    glScalef(1, 2, 0);
    drawSquare();
    glPopMatrix();
    glFlush();
    //city8
    glColor3ub(52, 24, 72);
    glPushMatrix();
    glTranslatef(64, 4, 0);
    glScalef(0.8, 6, 0);
    drawSquare();
    glPopMatrix();
    glFlush();
    //city 9
    glColor3ub(52, 24, 72);
    glPushMatrix();
    glTranslatef(53, 20, 0);
    glScalef(2, 0.1, 0);
    drawSquare();
    glPopMatrix();
    glFlush();
    //city 10
    glColor3ub(52, 24, 72);
    glPushMatrix();
    glTranslatef(70, 4, 0);
    glScalef(2, 1, 0);
    drawSquare();
    glPopMatrix();
    glFlush();
    //city 11
    glColor3ub(52, 24, 72);
    glPushMatrix();
    glTranslatef(73, 4, 0);
    glScalef(0.4, 5, 0);
    drawSquare();
    glPopMatrix();
    glFlush();
    //city12
    glColor3ub(52, 24, 72);
    glPushMatrix();
    glTranslatef(87, 4, 0);
    glScalef(1.4, 4, 0);
    drawSquare();
    glPopMatrix();
    glFlush();
    //city 13
    glColor3ub(52, 24, 72);
    glPushMatrix();
    glTranslatef(95, 6, 0);
    glScalef(1, 1.4, 0);
    drawSquare();
    glPopMatrix();
    glFlush();
    //city 14
    glColor3ub(52, 24, 72);
    glPushMatrix();
    glTranslatef(100, 4, 0);
    glScalef(0.5, 5, 0);
    drawSquare();
    glPopMatrix();
    glFlush();
    //city 15
    glColor3ub(113, 93, 127);
    glPushMatrix();
    glTranslatef(88, -1, 0);
    glScalef(0.2, 2, 0);
    drawSquare();
    glPopMatrix();
    glFlush();
    //city 16
    glColor3ub(113, 93, 127);
    glPushMatrix();
    glTranslatef(77, -1, 0);
    glScalef(1, 0.8, 0);
    drawSquare();
    glPopMatrix();
    glFlush(); //city 17
    glColor3ub(113, 93, 127);
    glPushMatrix();
    glTranslatef(79, -1, 0);
    glScalef(0.7, 1.5, 0);
    drawSquare();
    glPopMatrix();
    glFlush();
    //city 18
    glColor3ub(113, 93, 127);
    glPushMatrix();
    glTranslatef(82, -1, 0);
    glScalef(1, 1, 0);
    drawSquare();
    glPopMatrix();
    glFlush();
    //city 19
    glColor3ub(113, 93, 127);
    glPushMatrix();
    glTranslatef(86, -1, 0);
    glScalef(0.3, 1.2, 0);
    drawSquare();
    glPopMatrix();
    glFlush();
    //city 20
    glColor3ub(113, 93, 127);
    glPushMatrix();
    glTranslatef(84, -1, 0);
    glScalef(0.2, 1.2, 0);
    drawSquare();
    glPopMatrix();
    glFlush();
    //city 21
    glColor3ub(113, 93, 127);
    glPushMatrix();
    glTranslatef(71, 3, 0);
    glScalef(1, 0.05, 0);
    drawSquare();
    glPopMatrix();
    glFlush();
    //city 22
    glColor3ub(113, 93, 127);
    glPushMatrix();
    glTranslatef(66, 2, 0);
    glScalef(0.21, 1, 0);
    drawSquare();
    glPopMatrix();
    glFlush();
    //city 23
    glColor3ub(113, 93, 127);
    glPushMatrix();
    glTranslatef(90, 1, 0);
    glScalef(1, 0.5, 0);
    drawSquare();
    glPopMatrix();
    glFlush();
    //city 24
    glColor3ub(113, 93, 127);
    glPushMatrix();
    glTranslatef(35, 2, 0);
    glScalef(1, 0.5, 0);
    drawSquare();
    glPopMatrix();
    glFlush();
    //city 25
    glColor3ub(113, 93, 127);
    glPushMatrix();
    glTranslatef(11, 2, 0);
    glScalef(0.21, 1, 0);
    drawSquare();
    glPopMatrix();
    glFlush();
    // city 26
    glColor3ub(113, 93, 127);
    glPushMatrix();
    glTranslatef(15, 6, 0);
    glScalef(1, 0.05, 0);
    drawSquare();
    glPopMatrix();
    glFlush();
    //city 27
    glColor3ub(113, 93, 127);
    glPushMatrix();
    glTranslatef(29, 2, 0);
    glScalef(0.2, 1.2, 0);
    drawSquare();
    glPopMatrix();
    glFlush();
    //city 28
    glColor3ub(103, 93, 127);
    glPushMatrix();
    glTranslatef(31, 2, 0);
    glScalef(0.3, 1.2, 0);
    drawSquare();
    glPopMatrix();
    glFlush();
    //city 29
    glColor3ub(113, 93, 127);
    glPushMatrix();
    glTranslatef(27, 2, 0);
    glScalef(1, 1, 0);
    drawSquare();
    glPopMatrix();
    glFlush();
    //city 30
    glColor3ub(113, 93, 127);
    glPushMatrix();
    glTranslatef(24, 2, 0);
    glScalef(0.7, 1.5, 0);
    drawSquare();
    glPopMatrix();
    glFlush();
    //city31
    glColor3ub(113, 93, 127);
    glPushMatrix();
    glTranslatef(22, 2, 0);
    glScalef(1, 0.8, 0);
    drawSquare();
    glPopMatrix();
    glFlush();
    //city 32
    glColor3ub(113, 93, 127);
    glPushMatrix();
    glTranslatef(33, 2, 0);
    glScalef(0.2, 2, 0);
    drawSquare();
    glPopMatrix();
    glFlush();

    glLoadIdentity();
    gluOrtho2D(0, screenWidth, 0, screenHeight);
}

// Function to draw a rectangle
void drawRectangle(float x, float y, float width, float height) {
glBegin(GL_QUADS);
glVertex2f(x, y);
glVertex2f(x + width, y);
glVertex2f(x + width, y + height);
glVertex2f(x, y + height);
glEnd();
}
// Function to draw the difficulty selection popup
void drawDifficultyPopup() {
glClear(GL_COLOR_BUFFER_BIT);
// Calculate the center position of the difficulty window
float centerX = (screenWidth - difficultyScreenWidth) / 2.0;
float centerY = (screenHeight - difficultyScreenHeight) / 2.0;
// Draw a background rectangle
glColor3f(0.8, 0.8, 0.8);
drawRectangle(centerX, centerY, difficultyScreenWidth, difficultyScreenHeight);
// Draw a border for the window
glColor3f(0.0, 0.0, 0.0);
glLineWidth(2.0);
glBegin(GL_LINE_LOOP);
glVertex2f(centerX + 5, centerY + 5);
glVertex2f(centerX + difficultyScreenWidth - 5, centerY + 5);
glVertex2f(centerX + difficultyScreenWidth - 5, centerY + difficultyScreenHeight - 5);
glVertex2f(centerX + 5, centerY + difficultyScreenHeight - 5);
glEnd();
// Draw the difficulty selection text
glColor3f(0.0, 0.0, 0.0);
glRasterPos2f(centerX + difficultyScreenWidth / 2 - 70, centerY + difficultyScreenHeight / 2 + 20);
const char* message = "*Select difficulty*";
for (int i = 0; i < strlen(message); i++) {
glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, message[i]);
}
// Draw additional instructions
glRasterPos2f(centerX + difficultyScreenWidth / 2 - 85, centerY + difficultyScreenHeight / 2 - 20);
const char* instructions = "Press 'e' for Easy or 'h' for Hard";
for (int i = 0; i < strlen(instructions); i++) {
glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, instructions[i]);
}
glRasterPos2f(centerX + difficultyScreenWidth / 2 - 140, centerY + difficultyScreenHeight / 2 + 70);
const char* instructions2 = "HOW TO PLAY : press 'a' to go left and 'd' to go right." ;
for (int i = 0; i < strlen(instructions2); i++) {
glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, instructions2[i]);
}
glutSwapBuffers();
}
// Function to draw a popup message
void drawPopup(const char* message) {
glColor3f(0.0, 0.0, 0.0);
glRasterPos2f(screenWidth / 2 - 50, screenHeight / 2);
for (int i = 0; i < strlen(message); i++) {
glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, message[i]);
} }
// Function to draw the paddle
void drawPaddle() {
glColor3f(0.0, 0.0, 1.0);
drawRectangle(paddleX, paddleY, paddleWidth, paddleHeight);
}
// Function to draw the ball
void drawBall() {
if (easyMode) {
glColor4ub(254, 169, 8, 255); // RGBA color for easy mode
} else if (hardMode) {
glColor4ub(253, 209, 179, 255); // RGBA color for hard mode
}
glBegin(GL_TRIANGLE_FAN);
glVertex2f(ballX, ballY);
for (int i = 0; i <= 360; i++) {
float angle = 2.0 * M_PI * i / 360.0;
glVertex2f(ballX + ballRadius * cos(angle), ballY + ballRadius * sin(angle));
}
glEnd();
}
// Function to draw a single brick
void drawBrick(float x, float y) {
if (easyMode) {
glColor4ub(248, 174, 67, 255); // RGBA color for bricks in easy mode
} else if (hardMode) {
glColor4ub(248, 135, 125, 255); // RGBA color for bricks in hard mode
}
drawRectangle(x, y, brickWidth, brickHeight);
}
// Function to draw all the bricks
void drawBricks() {
for (int i = 0; i < brickRows; ++i) {
for (int j = 0; j < brickColumns; ++j) {
if (bricks[i][j]) {
drawBrick(j * (brickWidth + 5), screenHeight - (i + 1) * (brickHeight + 5));
}}
} }
void drawTransparentRectangle(float x, float y, float width, float height, float alpha) {
glEnable(GL_BLEND);
glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
glColor4f(0.8, 0.8, 0.8, alpha);
glBegin(GL_QUADS);
glVertex2f(x, y);
glVertex2f(x + width, y);
glVertex2f(x + width, y + height);
glVertex2f(x, y + height);
glEnd();
glDisable(GL_BLEND);
}
// Main drawing function
void draw() {
glClear(GL_COLOR_BUFFER_BIT);
// Check if difficulty is selected
if (!difficultySelected) {
drawDifficultyPopup();
return;
}
// Draw background based on difficulty
if (easyMode) {
drawEasyBackground();
} else if (hardMode) {
drawHardBackground();
}
// Display the paddle, ball, and bricks
drawPaddle();
drawBall();
drawBricks();
// Display the score at the bottom-right corner
glColor3f(1.0, 1.0, 1.0);
glRasterPos2f(screenWidth - 80, 20);
char scoreText[50];
sprintf(scoreText, "Score: %d", score);
for (int i = 0; i < strlen(scoreText); i++) {
glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, scoreText[i]);
}
// Check if the game is won or failed
if (gameWon || gameFailed) {
const char* resultMessage = (gameWon) ? "Congratulations! You Won!" : "Game Over. Better Luck NextTime!";
// Animate the result message by moving it up and down
static float yOffset = 0.5;
// Draw a semi-transparent background for the message
drawTransparentRectangle(screenWidth / 2 - 200, screenHeight / 2 - 40 + yOffset, 400, 80, 0.5);
// Display the result message centered horizontally and aligned with the timer text vertically
glColor3f(0.0, 0.0, 0.0);
glRasterPos2f(screenWidth/ 2 - 170 +strlen(resultMessage) , screenHeight / 2 + 20 + yOffset);
for (int i = 0; i < strlen(resultMessage); i++) {
if (resultMessage[i] == 'B') {
// Move the 'B' to the center of the screen
glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, resultMessage[i]);
continue;
}
glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, resultMessage[i]);
}
// Display the elapsed time when the game is over
char elapsedTimeText[50];
sprintf(elapsedTimeText, "Time Elapsed: %d seconds", getElapsedTime());
glRasterPos2f(screenWidth / 2 -190 , screenHeight / 2 - 20 + yOffset);
for (int i = 0; i < strlen(elapsedTimeText); i++) {
glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, elapsedTimeText[i]);
}
char scoreText[50];
sprintf(scoreText, "Score: %d", score);
glRasterPos2f(screenWidth / 2 +90 , screenHeight / 2 - 20 + yOffset);
for (int i = 0; i < strlen(scoreText); i++) {
glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, scoreText[i]);
}
} else {
// Display the timer at the top-left corner if the game is still ongoing
glColor3f(1.0, 1.0, 1.0);
glRasterPos2f(20, screenHeight - 40);
char timerText[50];
sprintf(timerText, "Time: %d ", getElapsedTime());
for (int i = 0; i < strlen(timerText); i++) {
glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, timerText[i]);
}}
glutSwapBuffers();
}
// Function to handle all updates
void update(int) {
if (!difficultySelected || gameOver) {
glutTimerFunc(16, update, 0);
return;
}
// Update ball position
ballX += ballSpeedX;
ballY += ballSpeedY;
// Ball collisions with walls
if (ballX - ballRadius < 0 || ballX + ballRadius > screenWidth) {
ballSpeedX = -ballSpeedX;
}
if (ballY + ballRadius > screenHeight) {
ballSpeedY = -ballSpeedY;
}
// Ball collision with paddle
if (ballY - ballRadius < paddleY + paddleHeight && ballY - ballRadius > paddleY &&
ballX > paddleX && ballX < paddleX + paddleWidth) {
ballSpeedY = -ballSpeedY;
}
// Ball collisions with bricks
for (int i = 0; i < brickRows; ++i) {
for (int j = 0; j < brickColumns; ++j) {
if (bricks[i][j]) {
float brickX = j * (brickWidth + 5);
float brickY = screenHeight - (i + 1) * (brickHeight + 5);
if (ballX + ballRadius > brickX && ballX - ballRadius < brickX + brickWidth &&
ballY + ballRadius > brickY && ballY - ballRadius < brickY + brickHeight) {
bricks[i][j] = false;
ballSpeedY = -ballSpeedY;
// Increase the score by 2 when a brick is hit
score += 2;
}}}}
// Check for winning condition
bool allBricksCleared = true;
for (int i = 0; i < brickRows; ++i) {
for (int j = 0; j < brickColumns; ++j) {
if (bricks[i][j]) {
allBricksCleared = false;
break;
}}
if (!allBricksCleared) {
break;
}}
// Set game state based on winning condition
if (allBricksCleared) {
gameWon = true;
gameOver = true;
} else if (ballY - ballRadius < 0) {
// If the ball goes below the screen, the game is failed
gameFailed = true;
gameOver = true;
}
// Redraw
glutPostRedisplay();
glutTimerFunc(16, update, 0);
}
// Function to handle keyboard input
void keyboard(unsigned char key, int, int) {
if (!difficultySelected) {
// Difficulty selection
switch (key) {
case 'e':
easyMode = true;
difficultySelected = true;
if (easyMode) {
ballSpeedX = 5.0; // Set a slower speed for easy mode
drawEasyBackground();
}
break;
case 'h':
hardMode = true;
difficultySelected = true;
if (hardMode) {
ballSpeedX = 10.0; // Set a faster speed for hard mode
drawHardBackground();
}
        break;
case 27: // Escape key
exit(0);
break;
}
initTimer(); // Initialize the timer when difficulty is selected
glutPostRedisplay();
return;
}
// Game controls
switch (key) {
case 'a':
paddleX -= 10;
break;
case 'd':
paddleX += 10;
break;
case 27: // Escape key
exit(0);
break;
}
// Bound paddle within the screen
if (paddleX < 0) paddleX = 0;
if (paddleX > screenWidth - paddleWidth) paddleX = screenWidth - paddleWidth;
glutPostRedisplay();
}
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(screenWidth, screenHeight);
    glutCreateWindow("Breakout Game");
    
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, screenWidth, 0, screenHeight);
    
    glutDisplayFunc(draw);
    glutKeyboardFunc(keyboard);
    glutTimerFunc(0, update, 0);
    
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glutMainLoop();
    
    return 0;
}


