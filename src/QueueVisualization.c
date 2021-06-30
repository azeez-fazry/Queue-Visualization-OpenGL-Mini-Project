/*
 * QueueVisualization.c
 *
 *  Created on: May 28, 2021, 6:36:30 PM
 *      Author: AZEEZ FAZRY
 *         Git: github.com/azeez-fazry
 *
 */

#include <GL/glut.h>

int i = 0, x = -1, y = -1;
GLfloat angle = -20.0, xaxis = 1.0, yaxis = 1.0, zaxis = 0.0;

void init() {
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 400.0, 0.0, 400.0);
	glMatrixMode(GL_MODELVIEW);
}

void key(unsigned char key, int a, int b) {
	if (key == 'b') {
		angle += 10;
		insert();
	}
	if (key == 'B') {
		angle -= 10;
		insert();
	}

	if (key == 'z') {

		delt();
		if (y < 5 && y <= x) {
			printf("%d deleted sucessfully\n", y + 1);
		}

	}

	if (key == 'c') {
		x++;

		if (x > 4) {
			char r1[] = "Queue Overflow";
			glColor3f(1.0, 0.0, 1.0);
			glRasterPos3f(1.0, -1.5, 0.2);
			for (i = 0; r1[i] != '\0'; i++)
				glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, r1[i]);

		}

		if (x <= 4) {
			char str3[] = "inserted sucessfully";
			glColor3f(0.0, 1.0, 1.0);
			glRasterPos3f(-4.0, -1.2, 0.2);
			for (i = 0; str3[i] != '\0'; i++)
				glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str3[i]);
		}
		if (x < 5) {
			printf("%d inserted sucessfully\n", x + 1);
		}
		if (x >= 5) {
			printf("queue overflow \n");
		}
		if (x > 4)
			x = 4;
		insert();
	}

	glutPostRedisplay();
}

void display1(void) {
	glLoadIdentity();
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	char str[] = "Implementation Of Queue";
	char str1[] =
			"FrontEnd                                                                                                                           Rear End";
	glColor3f(1.0, 1.0, 0.0);
	glRasterPos3f(-1.0, 1.8, 0.2);
	for (i = 0; str[i] != '\0'; i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str[i]);
	glColor3f(0.0, 0.0, 1.0);
	glRasterPos3f(-4.2, 0.04, 0.2);
	for (i = 0; str1[i] != '\0'; i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str1[i]);

	glFlush();

}

void myReshape(int w, int h) {
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	if (w <= h)
		glOrtho(-2.0, 2.0, -2.0 * (GLfloat) h / (GLfloat) w,
				2.0 * (GLfloat) h / (GLfloat) w, 10.0, -10.0);
	else
		glOrtho(-2.0 * (GLfloat) w / (GLfloat) h,
				2.0 * (GLfloat) w / (GLfloat) h, -2.0, 2.0, -10.0, 10.0);
	glMatrixMode(GL_MODELVIEW);
}

void submenu(GLint option) {
	switch (option) {
	case 1:
		xaxis = 1.0;
		yaxis = 0.0;
		zaxis = 0.0;
		break;
	case 2:
		xaxis = 0.0;
		yaxis = 1.0;
		zaxis = 0.0;
		break;
	case 3:
		xaxis = 0.0;
		yaxis = 0.0;
		zaxis = 1.0;
		break;
	case 4:
		xaxis = 1.0;
		yaxis = 1.0;
		zaxis = 0.0;
	}
	glutPostRedisplay();
}

void menu(GLint option) {
	switch (option) {
	case 1:
		x++;
		if (x > 4) {
			char r1[] = "Queue Overflow";
			glColor3f(1.0, 0.0, 1.0);
			glRasterPos3f(1.0, -1.5, 0.2);
			for (i = 0; r1[i] != '\0'; i++)
				glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, r1[i]);
		}
		if (x <= 4) {
			char str3[] = "inserted sucessfully";
			glColor3f(0.0, 1.0, 1.0);
			glRasterPos3f(-4.0, -1.2, 0.2);
			for (i = 0; str3[i] != '\0'; i++)
				glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str3[i]);
		}
		if (x > 4)
			x = 4;
		insert();
		break;
	case 2:
		delt();
		break;
	}
	glutPostRedisplay();
}

void mouse(int btn, int state, int x, int y) {
	if (btn == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
		int id = glutGetWindow();
		glutDestroyWindow(id);

		glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
		glutInitWindowSize(1366, 738);
		glutInitWindowPosition(0, 0);
		glutCreateWindow("queue operation");

		glutKeyboardFunc(key);
		glutDisplayFunc(display1);
		glutReshapeFunc(myReshape);
		int id1 = glutCreateMenu(submenu);
		glutAddMenuEntry("X-axis", 1);
		glutAddMenuEntry("Y-axis", 2);
		glutAddMenuEntry("Z-axis", 3);
		glutAddMenuEntry("Normal", 4);
		glutCreateMenu(menu);
		glutAddMenuEntry("Insert", 1);
		glutAddMenuEntry("Delete", 2);
		glutAddSubMenu("view of cube", id1);

		glutAttachMenu(GLUT_RIGHT_BUTTON);
		initGL();
		glFlush();

	}
}

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
	strokeString(15, 365, 0.2, 0.2, "CITY ENGINEERING COLLEGE", 6);
	strokeString(13, 335, 0.1, 0.1,
			"DEPARTMENT OF COMPUTER SCIENCE AND ENGINEERING", 4);
	strokeString(100, 300, 0.1, 0.1, "AN OPENGL MINI PROJECT ON", 2);
	glColor3f(0, 1, 1);
	strokeString(60, 240, 0.2, 0.2, "QUEUE VISUALIZATION", 6);
	glColor3f(1, 1, 0);
	glColor3f(1, 0, 0);
	strokeString(10, 200, 0.06, 0.06, "Under the guidance of:", 2);
	strokeString(250, 200, 0.06, 0.06, "By:", 2);
	glColor3f(1, 1, 0);
	strokeString(10, 180, 0.08, 0.08, "Mrs. NANDINI S.B.", 2);
	strokeString(250, 180, 0.08, 0.08, "AZEEZ MOHAMED FAZRY", 2);
	glColor3f(1, 0, 0);
	strokeString(10, 160, 0.08, 0.08, "(Asst. Professor, Dept. of CSE)", 2);
	strokeString(250, 160, 0.08, 0.08, "1CE18CS010", 2);
	glColor3f(1, 0, 0);

	glutMouseFunc(mouse);
	glFlush();
}

int main(int argc, char **argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(1366, 738);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Visualization of Queue - Azeez Fazry");
	glutDisplayFunc(display);
	init();
	glutMainLoop();
	return 0;
}
