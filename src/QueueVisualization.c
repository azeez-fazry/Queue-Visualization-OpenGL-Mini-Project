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
	strokeString(50, 50, 0.17, 0.17, "Press (Enter) to start the simulation",
			2);
	strokeString(650, 220, 0.15, 0.15, "By:", 2);
	strokeString(10, 220, 0.15, 0.15, "Under the guidance of:", 2);
	glColor3f(1, 1, 0);
	strokeString(650, 180, 0.2, 0.2, "AZEEZ MOHAMED FAZRY", 2);
	strokeString(10, 180, 0.2, 0.2, "Mrs. NANDINI S.B.", 2);
	glColor3f(1, 0, 0);
	strokeString(650, 140, 0.18, 0.18, "1CE18CS010", 2);
	strokeString(10, 140, 0.18, 0.18, "(Asst. Professor, Dept. of CSE)", 2);
	glColor3f(1, 0, 0);

	glutSwapBuffers();
}

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
