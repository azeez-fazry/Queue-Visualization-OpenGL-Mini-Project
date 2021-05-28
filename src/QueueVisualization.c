/*
 * QueueVisualization.c
 *
 *  Created on: May 28, 2021, 6:36:30 PM
 *      Author: AZEEZ FAZRY
 *         Git: github.com/azeez-fazry
 *
 */

#include <GL/glut.h>

void display() {

}

int main(int argc, char **argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(1366, 738);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Queue Visualization - AzeezFazry");

	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}
