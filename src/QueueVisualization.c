/*
 * QueueVisualization.c
 *
 *  Created on: May 28, 2021, 6:36:30 PM
 *      Author: AZEEZ FAZRY
 *         Git: github.com/azeez-fazry
 *
 */

#include <GL/glut.h>

/*
 * To initial setup for our environment
 */
void init() {
	glClearColor(0, 0, 0, 0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity(); //reset the transformations of the current matrix
	glOrtho(0, 1000, 0, 1000, -1, 1);
	glMatrixMode(GL_MODELVIEW);
}

/*
 * Function to draw strings
 */
void strokeString(float x, float y, float sx, float sy, char *string, int width) {
	char *c;
	glLineWidth(width);
	glPushMatrix();
	glTranslatef(x, y, 0);
	glScalef(sx, sy, 0);
	for (c = string; *c != '\0'; c++) {
		glutStrokeCharacter(GLUT_STROKE_ROMAN, *c);
	}
	glPopMatrix();
}

void display() {
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1, 0, 0);
	strokeString(105, 850, 0.4, 0.4, "CITY ENGINEERING COLLEGE", 4);
	strokeString(100, 750, 0.3, 0.3, "DEPARTMENT OF COMPUTER SCIENCE", 4);
	strokeString(300, 670, 0.3, 0.3, "AND ENGINEERING", 4);
	strokeString(200, 500, 0.3, 0.3, "AN OPENGL MINI PROJECT ON", 2);
	glColor3f(0, 1, 1);
	strokeString(170, 420, 0.5, 0.4, "QUEUE VISUALIZATION", 6);
	glColor3f(1, 1, 0);
	glColor3f(1, 0, 0);
//	strokeString(50, 50, 0.17, 0.17, "Press (Enter) to start the simulation",
//			2);
	strokeString(650, 220, 0.15, 0.15, "By:", 2);
	strokeString(10, 220, 0.15, 0.15, "Under the guidance of:", 2);
	glColor3f(1, 1, 0);
	strokeString(650, 180, 0.2, 0.2, "AZEEZ MOHAMED FAZRY", 2);
	strokeString(10, 180, 0.2, 0.2, "Mrs. NANDINI S.B.", 2);
	glColor3f(1, 0, 0);
	strokeString(650, 140, 0.18, 0.18, "1CE18CS010", 2);
	strokeString(10, 140, 0.18, 0.18, "(Asst. Professor, Dept. of CSE)", 2);
	glColor3f(1, 0, 0);

	button(100, 50, 300, 100, "Start Simulation");

	glutSwapBuffers();
}

/*
 * Functions for button start.
 */
int x1, y1, x2, y2;
int state;
char str[10];

void buttonDraw() {
	glColor3f(0.2, 0.2, 0.8);
	glBegin(GL_POLYGON);
	glVertex2f(x1, y1);
	glVertex2f(x2, y1);
	glVertex2f(x2, y2);
	glVertex2f(x1, y2);
	glEnd();
	if (state == 0) {
		glColor3f(0, 0, 0);
		glBegin(GL_LINES);
		glVertex2f(x1, y1);
		glVertex2f(x2, y1);
		glVertex2f(x2, y1);
		glVertex2f(x2, y2);
		glEnd();
	} else if (state == 1) {
		glColor3f(0, 0, 0);
		glBegin(GL_LINES);
		glVertex2f(x1, y1);
		glVertex2f(x1, y2);
		glVertex2f(x1, y2);
		glVertex2f(x2, y2);
		glEnd();
	}
	glColor3f(1.0, 1.0, 1.0);
	strokeString(x1 + 10, y1 + 10, 0.15, 0.15, str, 2);

}

int insideButton(int x, int y) {
	if (x > x1 && x < x2 && y > y1 && y < y2)
		return 1;
	else
		return 0;
}

void toggleState() {
	/*if(state==1)
	 state=0;
	 else if(state==0)
	 state=1;*/
	state = (state == 1) ? 0 : 1;
}

void button(int x11, int y11, int x22, int y22, char *str1) {
	x1 = x11;
	y1 = y11;
	x2 = x22;
	y2 = y22;
	state = 1;
	strcpy(str, str1);
	buttonDraw();
	toggleState();
}
/*
 * Functions for button end.
 */

int main(int argc, char **argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(1366, 738);
	glutInitWindowPosition(0, 0);

	glutCreateWindow("Queue Visualization - AzeezFazry");
	init();
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}
