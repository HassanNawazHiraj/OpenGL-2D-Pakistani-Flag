
#include <iostream>
#include <GL/freeglut.h>

void init(void);
void display(void);


int main(int argc, char** argv)
{
	//Step#1 Create and initialize glut windowing system
	glutInit(&argc, argv);
	glutInitWindowSize(600, 600);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Pakistani Flag");
	//Step#2 Do Open GL related initializations
	init();
	//Step#3 Register Call back methods or Event Handler methods
	glutDisplayFunc(display);
	//Step#4 Enter in  main loop (an infinite loop listening to registered events and then call their registered methods if any)
	glutMainLoop();
	return 0;
}

void init(void) {
	// select background color
	glClearColor(0.82, 1.0, 0.823, 0.0); // (red, green, blue, alpha), used by glClear
	
	// Define world coordinate frame
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0); // model in real word units 
		// (left, right, bottom, top, near, far)
}

void drawCircle(float cx, float cy, float r, int num_segments) {
	const float PI = 3.14159;
	glBegin(GL_TRIANGLE_FAN);
	for (int i = 0; i < num_segments; i++) {
		float theta = i * (2.0f * PI / num_segments);
		float x = r * cos(theta);
		float y = r * sin(theta);
		glVertex2f(x + cx, y + cy);
	}
	glEnd();
}

void drawStick(float topLeftX, float topLeftY, float width, float height) {
	glBegin(GL_QUADS);
	glVertex3f(topLeftX, topLeftY, 0.0);
	glColor3ub(126, 79, 52);
	glVertex3f(topLeftX + width, topLeftY, 0.0);
	glColor3ub(185, 122, 87);
	glVertex3f(topLeftX + width, topLeftY + height, 0.0);
	glColor3ub(126, 79, 52);
	glVertex3f(topLeftX, topLeftY + height, 0.0);
	glEnd();
}

void drawFlagGreenBox(float topLeftX, float topLeftY, float width, float height) {
	glBegin(GL_QUADS);
	glVertex3f(topLeftX, topLeftY, 0.0);
	glColor3ub(40, 210, 91);
	glVertex3f(topLeftX + width, topLeftY, 0.0);
	glColor3ub(24, 126, 55);
	glVertex3f(topLeftX + width, topLeftY + height, 0.0);
	glColor3ub(152, 235, 176);
	glVertex3f(topLeftX, topLeftY + height, 0.0);
	glEnd();
}

void drawWhiteBox(float topLeftX, float topLeftY, float width, float height) {
	glBegin(GL_QUADS);
	glVertex3f(topLeftX, topLeftY, 0.0);
	glColor3ub(229, 229, 229);
	glVertex3f(topLeftX + width, topLeftY, 0.0);
	glColor3ub(240, 240, 240);
	glVertex3f(topLeftX + width, topLeftY + height, 0.0);
	glColor3ub(193, 193, 193);
	glVertex3f(topLeftX, topLeftY + height, 0.0);
	glEnd();
}

void drawBox(float topLeftX, float topLeftY, float width, float height) {
	glBegin(GL_QUADS);
	glVertex3f(topLeftX, topLeftY, 0.0);
	glVertex3f(topLeftX + width, topLeftY, 0.0);
	glVertex3f(topLeftX + width, topLeftY + height, 0.0);
	glVertex3f(topLeftX, topLeftY + height, 0.0);
	glEnd();
}

void drawStar() {
	glColor3ub(255, 255, 255);
	glLineWidth(4);

	glBegin(GL_LINE_STRIP);
	glVertex3f(-0.001, 0.28, 0);
	glVertex3f(0.01, 0.314, 0.0);
	glVertex3f(0.05, 0.314, 0.0);
	glVertex3f(0.017, 0.336, 0.0);
	glVertex3f(0.03, 0.371, 0.0);
	glVertex3f(-0.002, 0.35, 0.0);
	glVertex3f(-0.032, 0.371, 0.0);
	glVertex3f(-0.022, 0.337, 0.0);
	glVertex3f(-0.05, 0.314, 0.0);
	glVertex3f(-0.013, 0.314, 0.0);
	glVertex3f(-0.001, 0.28, 0);

	glEnd();
}



void drawMoon() {
	glColor3ub(255, 255, 255);
	drawCircle(-0.05, 0.33, 0.11, 80);
	glColor3ub(34, 177, 76);
	drawCircle(-0.01, 0.33, 0.09, 80);
}


void display(void) {
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3ub(185, 122, 87);
	drawStick(-0.4, -0.3, 0.05, 0.8);
	glColor3ub(34, 177, 76);
	drawBox(-0.35, 0.18, 0.6, 0.3);
	glColor3f(1.0, 1.0, 1.0);
	//draw the white on flag
	drawWhiteBox(-0.35, 0.18, 0.1, 0.3);
	drawMoon();
	drawStar();
	//glColor3ub(255, 255, 255);
	//drawBox(-0.05, 0.28, 0.1, 0.1);
		


	
	glFlush();
}