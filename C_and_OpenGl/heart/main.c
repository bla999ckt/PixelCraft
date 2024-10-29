#include "GLUT/glut.h"
#include "unistd.h"
#include "math.h"

// Global variables
float angle = 0.0;
float t = -180.0;
float transitionFactor = 0.0;
float rotatingHeartAngle = 0.0;
int transitionStep = 0;
int currentStar = 0;

// Function to draw a star
void drawStar(float cx, float cy, float radius, float innerRadius, int numPoints, float scaleFactor)
{
    glBegin(GL_TRIANGLE_FAN);
    glColor3f(1.0, 1.0, 0.0);  // Yellow color
    // Draw star points
    for (int i = 0; i <= numPoints * 2; ++i)
    {
        float currentRadius = scaleFactor * ((i % 2 == 0) ? radius : innerRadius);
        float starAngle = i * M_PI / numPoints;
        float x = cx + currentRadius * cos(starAngle);
        float y = cy + currentRadius * sin(starAngle);
        glVertex2f(x - 4.0, y - 1.0);
    }
    glEnd();
}

// Function to draw stars on the first heart
void drawStarsOnFirstHeart()
{
    for (int i = 0; i <= currentStar; ++i)
    {
        switch (i)
        {
            case 0: drawStar(-1.8, 5.0, 0.2, 0.4, 5, 2.0); break;
            case 1: drawStar(-0.3, 5.5, 0.05, 0.14, 5, 3.0); break;
            case 2: drawStar(-0.5, 4.89, 0.05, 0.14, 5, 3.0); break;
            case 3: drawStar(-1.1, 4.3, 0.05, 0.14, 5, 3.0); break;
            case 4: drawStar(-2.1, 4.1, 0.05, 0.14, 5, 3.0); break;
        }
    }
}

// Function to draw the heart shape
void drawHeart(float offset)
{
    glBegin(GL_LINES);
    // Draw heart shape
    for (float i = -180.0 + offset; i <= t + offset; i += 1.0) {
        float radian = i * 3.14159 / 180.0;
        float x = 16.0 * pow(sin(radian), 3);
        float y = 13.0 * cos(radian) - 5.0 * cos(2 * radian) - 2.0 * cos(3 * radian) - cos(4 * radian);
        float scaleFactor = 0.5;
        float distance = sqrt(x * x + y * y);
        float normalizedDistance = distance / 30.0;
        float redColor = cos(normalizedDistance * 2 * 3.14159) * 1 + 1.3;
        glColor3f(redColor, 0.0, 0.0);
        glVertex2f(0.0, 0.0);
        glVertex2f(scaleFactor * x, scaleFactor * y);
    }
    glEnd();
    t += 1.0;
}

// Function to draw stars
void drawStars()
{
    glBegin(GL_POINTS);
    glColor3f(1.0, 1.0, 0.0);  // Yellow color
    // Draw stars on the first heart
    if (currentStar <= 4) {
        drawStarsOnFirstHeart();
        usleep(100000);  // Introduce a delay before drawing the next star
        currentStar++;
    }
    glEnd();
}

// Function to draw the rotating heart
void drawRotatingHeart()
{
    glBegin(GL_TRIANGLES);
    // Draw rotating heart
    for (float t = 0.0; t <= 2.0 * M_PI; t += 0.01)
    {
        float x1 = 8.0 * pow(sin(t + 0.01), 3);
        float y1 = 6.5 * cos(t + 0.01) - 2.5 * cos(2 * t + 0.01) - 1.0 * cos(3 * t + 0.01) - 0.5 * cos(4 * t + 0.01);
        float distance1 = sqrt(x1 * x1 + y1 * y1);
        float normalizedDistance1 = distance1 / 30.0;
        float redColor1 = cos(normalizedDistance1 * 2 * 3.14159) * 0.3 + 0.4;
        glColor3f(redColor1, 0.0, 0.0);
        glVertex3f(x1, y1, 0.0);
        float x2 = 8.0 * pow(sin(t), 3);
        float y2 = 6.5 * cos(t) - 2.5 * cos(2 * t) - 1.0 * cos(3 * t) - 0.5 * cos(4 * t);
        float distance2 = sqrt(x2 * x2 + y2 * y2);
        float normalizedDistance2 = distance2 / 30.0;
        float redColor2 = cos(normalizedDistance2 * 2 * 3.14159) * 0.3 + 0.4;
        glColor3f(redColor2, 0.0, 0.0);
        glVertex3f(x2, y2, 0.0);
        glVertex3f(0.0, 0.0, 0.0);
    }
    glEnd();
}

// Function to draw the background
void drawBackground()
{
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);  // Black color
    glVertex3f(-20.0, -20.0, -1.0);
    glVertex3f(-20.0, 20.0, -1.0);
    glVertex3f(20.0, 20.0, -1.0);
    glVertex3f(20.0, -20.0, -1.0);
    glEnd();
}

// Display function
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glTranslatef(0.0, 0.0, -30.0);
    if (transitionStep == 0)
    {
        // Draw background and the first heart
        drawBackground();
        drawHeart(-180.0 + angle);
        // Introduce stars on the first heart and draw stars
        if (t > 165.0)
        {
            drawStarsOnFirstHeart();
            drawStars();
        }
    }
    else
    {
        glPushMatrix();
        glRotatef(angle, 0.0, 1.0, 0.0);
        // Draw the rotating heart
        drawRotatingHeart();
        glPopMatrix();
        rotatingHeartAngle = angle;
        glPushMatrix();
        glRotatef(angle, 0.0, 1.0, 0.0);
        // Draw stars around the rotating heart
        drawStar(9.2, 5.0, 0.2, 0.4, 5, 2.0);
        drawStar(7.7, 5.5, 0.05, 0.14, 5, 3.0);
        drawStar(7.9, 4.89, 0.05, 0.14, 5, 3.0);
        drawStar(8.5, 4.3, 0.05, 0.14, 5, 3.0);
        drawStar(9.5, 4.1, 0.05, 0.14, 5, 3.0);
        glPopMatrix();
    }
    glutSwapBuffers();
    angle += 0.5;
    glutPostRedisplay();
}

// Reshape function
void reshape(int width, int height)
{
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, (double)width / (double)height, 0.1, 100.0);
    glMatrixMode(GL_MODELVIEW);
}

// Timer function for transition
void timer(int value)
{
    if (transitionStep == 0)
    {
        // Update transition factor until it reaches 1.0
        transitionFactor += 0.01;
        if (transitionFactor >= 1.0)
        {
            transitionFactor = 1.0;
            transitionStep = 1;
        }
    }
    glutPostRedisplay();
    glutTimerFunc(16, timer, 0);
}

// Main function
int main(int argc, char** argv)
{
    glutInitWindowSize(800, 600);
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutCreateWindow("I LOVE CHINA");
    
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutTimerFunc(0, timer, 0);
    
    glEnable(GL_DEPTH_TEST);
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glutMainLoop();
    return 0;
}

