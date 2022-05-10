//18je0395
//KARAN

#include<bits/stdc++.h>
#include<GL/glut.h>
#include <OpenGL/OpenGL.h>

using namespace std;

int p,x,y,px,py,rx1,ry1,rx2,ry2;
double x_start, x_end, y_start, y_end;
float cx, float cy, float rx, float ry;
int num_segments;

#define PI 3.14

void ellipse(void) 
{ 
    float theta = 2 * 3.1415926 / float(num_segments); 
    float c = cosf(theta); //precalculate the sine and cosine
    float s = sinf(theta);
    float t;

    float x = 1; //we start at angle = 0 
    float y = 0; 

    glBegin(GL_LINE_LOOP); 
    for(int ii = 0; ii < num_segments; ii++) 
    { 
        //apply radius and offset
        glVertex2f(x * rx + cx, y * ry + cy);//output vertex 

        //apply the rotation matrix
        t = x;
        x = c * x - s * y;
        y = s * t + c * y;
    } 
    glEnd(); 
}


void line(void) {
	// clear the buffer to preset values
	glClear(GL_COLOR_BUFFER_BIT);

	double dx = x_end - x_start, dy = yend - y_start, slope = double(dy) / double(dx);				// not needed here
	int steps = max(abs(x_start - x_end), abs(y_start - yend));
	double x = x_start, y = y_start,  xinc = dx / steps, yinc = dy / steps;
	
	for (int k = 0; k <= steps; k++) {
		// plot a point
		glBegin(GL_POINTS);
		glVertex2i(round(x), round(y));
		glEnd();

		x += xinc;
		y += yinc;
	}

	// show as quikly as possible
	glFlush();
}

void init() {
	// set the background color to pink (Red(1) + Green(0) + Blue(1))
	glClearColor(1.0, 0.0, 1.0, 0);
	// set the filling color to blue (Red(0) + Green(0) + Blue(1))
	glColor3f(0.0, 0.0, 1.0);
	gluOrtho2D(0, 640, 0, 480);
}

int main(int argc, char** argv) {

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(700, 700);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("QUIZ-2");
	init();

    num_segments = 50;

    //LEFT glass
    rx = 10, ry = 30, cx = 300, cy = 150;
    glutDisplayFunc(ellipse);

    //RIGHT glass
    rx = 10, ry = 30, cx = 400, cy = 100;
    glutDisplayFunc(ellipse);

    //LEFT support
    x_start = 290, y_start = 150, x_end = 340, y_end = 200;
    glutDisplayFunc(line);

    //RIGHT support
    x_start = 410, y_start = 100, x_end = 460, y_end = 150;
    glutDisplayFunc(line);

    //MIDDLE SUPPORT
    x_start = 310, y_start = 150, x_end = 440, y_end = 150;
    glutDisplayFunc(line);

	glutMainLoop();
	return 0;
}