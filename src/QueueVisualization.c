/*
 * QueueVisualization.c
 *
 *  Created on: May 28, 2021, 6:36:30 PM
 *      Author: AZEEZ FAZRY
 *         Git: https://github.com/azeez-fazry/Queue-Visualization-OpenGL-Mini-Project
 *
 */

#include <GL/glut.h>

int i = 0, x = -1, y = -1;
GLfloat angle = -20.0, xaxis = 1.0, yaxis = 1.0, zaxis = 0.0;

/**
 * Function to set viewport
 */
void init() {
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 400.0, 0.0, 400.0);
	glMatrixMode(GL_MODELVIEW);
}

/**
 * Function to make text in the screen.
 *
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

/**
 * Function to draw 3D cube.
 */
void cube() {
	glScaled(0.5, 0.5, 0.5);
	glRotated(angle, xaxis, yaxis, zaxis);
	glBegin( GL_QUADS);
	// Top face
	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex3f(1.0f, 1.0f, -1.0f);
	glVertex3f(-1.0f, 1.0f, -1.0f);
	glVertex3f(-1.0f, 1.0f, 1.0f);
	glVertex3f(1.0f, 1.0f, 1.0f);
	// Bottom face
	glColor3f(1.0f, 1.0f, 0.0f);
	glVertex3f(1.0f, -1.0f, -1.0f);
	glVertex3f(-1.0f, -1.0f, -1.0f);
	glVertex3f(-1.0f, -1.0f, 1.0f);
	glVertex3f(1.0f, -1.0f, 1.0f);
	// Front face
	glColor3f(1.0f, 0.2f, 0.5f);
	glVertex3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-1.0f, 1.0f, 1.0f);
	glVertex3f(-1.0f, -1.0f, 1.0f);
	glVertex3f(1.0f, -1.0f, 1.0f);
	// Back face
	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex3f(1.0f, -1.0f, -1.0f);
	glVertex3f(-1.0f, -1.0f, -1.0f);
	glVertex3f(-1.0f, 1.0f, -1.0f);
	glVertex3f(1.0f, 1.0f, -1.0f);
	// Left face
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex3f(-1.0f, 1.0f, 1.0f);
	glVertex3f(-1.0f, 1.0f, -1.0f);
	glVertex3f(-1.0f, -1.0f, -1.0f);
	glVertex3f(-1.0f, -1.0f, 1.0f);
	// Right face
	glColor3f(0.0f, 1.0f, 1.0f);
	glVertex3f(1.0f, 1.0f, 1.0f);
	glVertex3f(1.0f, 1.0f, -1.0f);
	glVertex3f(1.0f, -1.0f, -1.0f);
	glVertex3f(1.0f, -1.0f, 1.0f);
	glEnd();
}

/**
 * Insert function. It checks the limit of queue.
 * It checks the number of elements present in the queue
 * through VAR x and y.
 * Shows Overflow message when the queue is filled.
 * y for pop
 * x for push
 */
void insert() {

//	Empty condition
	if (x == 0 && y == 0 || x == 1 && y == 1 || x == 2 && y == 2
			|| x == 3 && y == 3 || x == 4 && y == 4) {
		char str2[] = "Empty Queue";
		glColor3f(1.0, 0.0, 1.0);
		glRasterPos3f(1.0, -1.7, 0.2);
		for (i = 0; str2[i] != '\0'; i++)
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str2[i]);
		glutSwapBuffers();
	}

	if (x == 0 && y == -1) {
		glColor3f(1.0, 1.0, 1.0);
		glRasterPos3f(-2.9, -0.85, 0.2);
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, '1');

		glPushMatrix();
		glTranslatef(-2.8f, 0.0, -5.0);
		cube();
		glPopMatrix();

		glutSwapBuffers();
	}

	if (x == 1 && y == -1) {
		glColor3f(1.0, 1.0, 1.0);
		glRasterPos3f(-2.9, -0.85, 0.2);
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, '1');
		glRasterPos3f(-1.7, -0.85, 0.2);
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, '2');

		glPushMatrix();
		glTranslatef(-2.8f, 0.0, -5.0);
		cube();
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-1.7f, 0.0f, -5.0f);
		cube();
		glPopMatrix();

		glutSwapBuffers();
	}

	if (x == 2 && y == -1) {
		glColor3f(1.0, 1.0, 1.0);
		glRasterPos3f(-2.9, -0.85, 0.2);
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, '1');
		glRasterPos3f(-1.7, -0.85, 0.2);
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, '2');
		glRasterPos3f(-0.6, -0.85, 0.2);
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, '3');

		glPushMatrix();
		glTranslatef(-0.6f, 0.0f, -5.0f);
		cube();
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-2.8f, 0.0, -5.0);
		cube();
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-1.7f, 0.0f, -5.0f);
		cube();
		glPopMatrix();

		glutSwapBuffers();
	}

	if (x == 3 && y == -1) {
		glColor3f(1.0, 1.0, 1.0);
		glRasterPos3f(-2.9, -0.85, 0.2);
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, '1');
		glRasterPos3f(-1.7, -0.85, 0.2);
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, '2');
		glRasterPos3f(-0.6, -0.85, 0.2);
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, '3');
		glRasterPos3f(0.5, -0.85, 0.2);
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, '4');

		glPushMatrix();
		glTranslatef(0.5f, 0.0f, -5.0f);
		cube();
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-0.6f, 0.0f, -5.0f);
		cube();
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-2.8f, 0.0, -5.0);
		cube();
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-1.7f, 0.0f, -5.0f);
		cube();
		glPopMatrix();

		glutSwapBuffers();
	}

	if (x == 4 && y == -1) {
		glColor3f(1.0, 1.0, 1.0);
		glRasterPos3f(-2.9, -0.85, 0.2);
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, '1');
		glRasterPos3f(-1.7, -0.85, 0.2);
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, '2');
		glRasterPos3f(-0.6, -0.85, 0.2);
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, '3');
		glRasterPos3f(0.5, -0.85, 0.2);
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, '4');
		glRasterPos3f(1.5, -0.85, 0.2);
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, '5');

		glPushMatrix();
		glTranslatef(1.6f, 0.0f, -5.0f);
		cube();
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-0.6f, 0.0f, -5.0f);
		cube();
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-2.8f, 0.0, -5.0);
		cube();
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-1.7f, 0.0f, -5.0f);
		cube();
		glPopMatrix();

		glPushMatrix();
		glTranslatef(0.5f, 0.0f, -5.0f);
		cube();
		glPopMatrix();

		glutSwapBuffers();

	}

	if (x == 1 && y == 0) {
		glColor3f(1.0, 1.0, 1.0);
		glRasterPos3f(-2.9, -0.85, 0.2);
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, '2');

		glPushMatrix();
		glTranslatef(-2.8f, 0.0, -5.0);
		cube();
		glPopMatrix();

		glutSwapBuffers();

	}

	if (x == 2 && y == 0) {
		glColor3f(1.0, 1.0, 1.0);
		glRasterPos3f(-2.9, -0.85, 0.2);
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, '2');
		glRasterPos3f(-1.7, -0.85, 0.2);
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, '3');

		glPushMatrix();
		glTranslatef(-2.8f, 0.0, -5.0);
		cube();
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-1.7f, 0.0f, -5.0f);
		cube();
		glPopMatrix();

		glutSwapBuffers();
	}

	if (x == 3 && y == 0) {
		glColor3f(1.0, 1.0, 1.0);
		glRasterPos3f(-2.9, -0.85, 0.2);
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, '2');
		glRasterPos3f(-1.7, -0.85, 0.2);
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, '3');
		glRasterPos3f(-0.6, -0.85, 0.2);
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, '4');

		glPushMatrix();
		glTranslatef(-0.6f, 0.0f, -5.0f);
		cube();
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-2.8f, 0.0, -5.0);
		cube();
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-1.7f, 0.0f, -5.0f);
		cube();
		glPopMatrix();

		glutSwapBuffers();
	}

	if (x == 4 && y == 0) {
		glColor3f(1.0, 1.0, 1.0);
		glRasterPos3f(-2.9, -0.85, 0.2);
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, '2');
		glRasterPos3f(-1.7, -0.85, 0.2);
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, '3');
		glRasterPos3f(-0.6, -0.85, 0.2);
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, '4');
		glRasterPos3f(0.5, -0.85, 0.2);
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, '5');

		glPushMatrix();
		glTranslatef(0.5f, 0.0f, -5.0f);
		cube();
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-0.6f, 0.0f, -5.0f);
		cube();
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-2.8f, 0.0, -5.0);
		cube();
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-1.7f, 0.0f, -5.0f);
		cube();
		glPopMatrix();

		glutSwapBuffers();
	}

	if (x == 2 && y == 1) {
		glColor3f(1.0, 1.0, 1.0);
		glRasterPos3f(-2.9, -0.85, 0.2);
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, '3');

		glPushMatrix();
		glTranslatef(-2.8f, 0.0, -5.0);
		cube();
		glPopMatrix();

		glutSwapBuffers();

	}

	if (x == 3 && y == 1) {
		glColor3f(1.0, 1.0, 1.0);
		glRasterPos3f(-2.9, -0.85, 0.2);
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, '3');
		glRasterPos3f(-1.7, -0.85, 0.2);
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, '4');

		glPushMatrix();
		glTranslatef(-2.8f, 0.0, -5.0);
		cube();
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-1.7f, 0.0f, -5.0f);
		cube();
		glPopMatrix();

		glutSwapBuffers();
	}

	if (x == 4 && y == 1) {
		glColor3f(1.0, 1.0, 1.0);
		glRasterPos3f(-2.9, -0.85, 0.2);
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, '3');
		glRasterPos3f(-1.7, -0.85, 0.2);
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, '4');
		glRasterPos3f(-0.6, -0.85, 0.2);
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, '5');

		glPushMatrix();
		glTranslatef(-0.6f, 0.0f, -5.0f);
		cube();
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-2.8f, 0.0, -5.0);
		cube();
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-1.7f, 0.0f, -5.0f);
		cube();
		glPopMatrix();

		glutSwapBuffers();
	}

	if (x == 3 && y == 2) {
		glColor3f(1.0, 1.0, 1.0);
		glRasterPos3f(-2.9, -0.85, 0.2);
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, '4');

		glPushMatrix();
		glTranslatef(-2.8f, 0.0, -5.0);
		cube();
		glPopMatrix();

		glutSwapBuffers();
	}

	if (x == 4 && y == 2) {
		glColor3f(1.0, 1.0, 1.0);
		glRasterPos3f(-2.9, -0.85, 0.2);
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, '4');
		glRasterPos3f(-1.7, -0.85, 0.2);
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, '5');

		glPushMatrix();
		glTranslatef(-2.8f, 0.0, -5.0);
		cube();
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-1.7f, 0.0f, -5.0f);
		cube();
		glPopMatrix();

		glutSwapBuffers();
	}

	if (x == 4 && y == 3) {
		glColor3f(1.0, 1.0, 1.0);
		glRasterPos3f(-2.9, -0.85, 0.2);
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, '5');

		glPushMatrix();
		glTranslatef(-2.8f, 0.0, -5.0);
		cube();
		glPopMatrix();

		glutSwapBuffers();
	}
}

/**
 * Function to delete cube.
 * It will checks for the pointers x and y
 */
void delt() {
	y++;
	if (y < 5 && y < x) {
		char d1[] = "Deleted Successfully!";
		glColor3f(0.0, 1.0, 1.0);
		glRasterPos3f(1.0, -1.5, 0.2);
		for (i = 0; d1[i] != '\0'; i++)
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, d1[i]);
	}
	if (x < y) {
		if (x == 4 && y >-1) {
			y = x = -1;
		}
	}
	insert();
}

/**
 * Function to get the input from the keyboard.
 */
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
		}

	}

	if (key == 'c') {
		x++;

		if (x > 4) {
			char r1[] = "Queue Overflow!";
			glColor3f(1.0, 0.0, 1.0);
			glRasterPos3f(1.0, -1.5, 0.2);
			for (i = 0; r1[i] != '\0'; i++)
				glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, r1[i]);

		}

		if (x <= 4) {
			char str3[] = "Inserted Successfully!";
			glColor3f(0.0, 1.0, 1.0);
			glRasterPos3f(1.0, -1.5, 0.2);
			for (i = 0; str3[i] != '\0'; i++)
				glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str3[i]);
		}
		if (x > 4)
			x = 4;
		insert();
	}
	glutPostRedisplay();
}

/**
 * Function to display the third window.
 */
void display1(void) {
	glLoadIdentity();
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	char str[] = "Visualization of Queue - Azeez Fazry";
	char str1[] =
			"FrontEnd                                                                                                                         Rear End";
	glColor3f(1.0, 1.0, 0.0);
	glRasterPos3f(-1.0, 1.8, 0.2);
	for (i = 0; str[i] != '\0'; i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str[i]);
	glColor3f(0.0, 0.0, 1.0);
	glRasterPos3f(-2.95, -1.3, 0.2);
	for (i = 0; str1[i] != '\0'; i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str1[i]);
	glFlush();

}

/**
 * Reshape function.
 * Used to display the elements when the window
 * is reshaped.
 */
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

/**
 * The menu function, controlled by mouse.
 * Right click.
 * Used to insert and delete elements
 * through mouse
 */
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
			char str3[] = "Inserted Successfully";
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

void initGL() {
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glEnable(GL_DEPTH_TEST);
	glShadeModel(GL_SMOOTH);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-2.0, 2.0, -2.0, 2.0, -10.0, 10.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glutSwapBuffers();
}

/**
 * Mouse function, Uset to change the screen
 * from screen 1 to screen 2.
 */
void mouse(int btn, int state, int x, int y) {
	if (btn == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
		int id = glutGetWindow();
		glutDestroyWindow(id);

		glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
		glutInitWindowSize(1366, 738);
		glutInitWindowPosition(0, 0);
		glutCreateWindow("Visualization of Queue - Azeez Fazry");

		glutKeyboardFunc(key);
		glutReshapeFunc(myReshape);
		glutCreateMenu(menu);
		glutAddMenuEntry("Insert", 1);
		glutAddMenuEntry("Delete", 2);
		glutDisplayFunc(display1);

		glutAttachMenu(GLUT_RIGHT_BUTTON);
		initGL();
		glFlush();

	}
}

// TODO Add description about the queue...
/**
 * Function to display the second window.
 */
void display2(void) {
	glLoadIdentity();
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	char str[] = "Visualization of Queue - Azeez Fazry";
	char str1[] = "What is a Queue Data Structure?";
	char str2[] =
			"A Queue is a linear structure which follows a particular order in which the operations are performed. The order";
	char str3[] =
			"is First In First Out (FIFO). A good example of a queue is any queue of consumers for a resource where the consumer that came first";
	char str4[] = "is served first. ";
	char str5[] =
			"A queue is open at both its ends. One end is always used to insert data (enqueue) and the other is used to remove";
	char str6[] = "data (dequeue).";
	glColor3f(1.0, 1.0, 0.0);
	glRasterPos3f(-1.2, 1.8, 0.2);
	for (i = 0; str[i] != '\0'; i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str[i]);

	glColor3f(1.0, 0.0, 0.0);
	glRasterPos3f(-3.7, 1.4, 0.2);
	for (i = 0; str1[i] != '\0'; i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str1[i]);

	glColor3f(1.0, 0.2, 0.5);
	glRasterPos3f(-2.5, 1.0, 0.2);
	for (i = 0; str2[i] != '\0'; i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str2[i]);

	glRasterPos3f(-3.7, 0.8, 0.2);
	for (i = 0; str3[i] != '\0'; i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str3[i]);

	glRasterPos3f(-3.7, 0.6, 0.2);
	for (i = 0; str4[i] != '\0'; i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str4[i]);

	glRasterPos3f(-2.5, 0.3, 0.2);
	for (i = 0; str5[i] != '\0'; i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str5[i]);

	glRasterPos3f(-3.7, 0.1, 0.2);
	for (i = 0; str6[i] != '\0'; i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str6[i]);

	glutMouseFunc(mouse); // mouse function to create the third window
	glFlush();
}

/**
 * Mouse function, Uset to change the screen
 * from screen 2 to screen 3.
 */
void mouse1(int btn, int state, int x, int y) {
	if (btn == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
		int id = glutGetWindow();
		glutDestroyWindow(id);

		glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
		glutInitWindowSize(1366, 738);
		glutInitWindowPosition(0, 0);
		glutCreateWindow("Visualization of Queue - Azeez Fazry");

		glutDisplayFunc(display2);
		glutReshapeFunc(myReshape);

		initGL();
		glFlush();

	}
}

/**
 * Function that creates the first window.
 */
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
	strokeString(250, 140, 0.08, 0.08, "MAHESH", 2);
	glColor3f(1, 0, 0);
	strokeString(10, 160, 0.08, 0.08, "(Asst. Professor, Dept. of CSE)", 2);
	strokeString(250, 160, 0.08, 0.08, "1CE18CS010", 2);
	strokeString(250, 120, 0.08, 0.08, "1CE18CS040", 2);
	glColor3f(1, 0, 0);

	glutMouseFunc(mouse1); // mouse function to create the second window
	glFlush();
}

/**
 * MAin function.
 */
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
