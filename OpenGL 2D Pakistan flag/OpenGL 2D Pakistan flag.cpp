
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
	glutCreateWindow("Android/Robot");
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
	glClearColor(1.0, 1.0, 1.0, 0.0); // (red, green, blue, alpha), used by glClear

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

void drawBox(float topLeftX, float topLeftY, float width, float height) {
	glBegin(GL_QUADS);
	glVertex3f(topLeftX, topLeftY, 0.0);
	glVertex3f(topLeftX + width, topLeftY, 0.0);
	glVertex3f(topLeftX + width, topLeftY + height, 0.0);
	glVertex3f(topLeftX, topLeftY + height, 0.0);
	glEnd();
}


void display(void) {
	glClear(GL_COLOR_BUFFER_BIT);

	
	glFlush();
}