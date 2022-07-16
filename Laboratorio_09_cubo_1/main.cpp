#include <stdio.h>
#include <stdarg.h>
#include <math.h>
#define GL_GLEXT_PROTOTYPES
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

void controles(int, int, int);

double rotate_y = 0;
double rotate_x = 0;

void display(){
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	glRotatef(rotate_x, 1.0, 0.0, 0.0);
	glRotatef(rotate_y, 0.0, 1.0, 0.0);

	// CARA FRONTAL DEL CUBO
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.0, 0.0); glVertex3f(0.5, -0.5, -0.5); // P1 es rojo
	glColor3f(0.0, 1.0, 0.0); glVertex3f(0.5, 0.5, -0.5); // P2 es verde
	glColor3f(0.0, 0.0, 1.0); glVertex3f(-0.5, 0.5, -0.5); // P3 es azul
	glColor3f(1.0, 0.0, 1.0); glVertex3f(-0.5, -0.5, -0.5); // P4 es morado
	glEnd();

	// LADO TRASERO: 
	glBegin(GL_POLYGON);
	glColor3f(-1.0, 1.0, -1.6);
	glVertex3f(0.5, -0.5, 0.5);
	glVertex3f(0.5, 0.5, 0.5);
	glVertex3f(-0.5, 0.5, 0.5);
	glVertex3f(-0.5, -0.5, 0.5);
	glEnd();

	// LADO DERECHO:
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.5, 0.1);
	glVertex3f(0.5, -0.5, -0.5);
	glVertex3f(0.5, 0.5, -0.5);
	glVertex3f(0.5, 0.5, 0.5);
	glVertex3f(0.5, -0.5, 0.5);
	glEnd();

	// LADO IZQUIERDO: 
	glBegin(GL_POLYGON);
	glColor3f(1.0, -2.8, 1.0);
	glVertex3f(-0.5, -0.5, 0.5);
	glVertex3f(-0.5, 0.5, 0.5);
	glVertex3f(-0.5, 0.5, -0.5);
	glVertex3f(-0.5, -0.5, -0.5);
	glEnd();
	
	// LADO SUPERIOR: 
	glBegin(GL_POLYGON);
	glColor3f(1.0, -4.0, -1.0);
	glVertex3f(0.5, 0.5, 0.5);
	glVertex3f(0.5, 0.5, -0.5);
	glVertex3f(-0.5, 0.5, -0.5);
	glVertex3f(-0.5, 0.5, 0.5);
	glEnd();

	// LADO INFERIOR: 
	glBegin(GL_POLYGON);
	glColor3f(1.0, -3.8, -1.0);
	glVertex3f(0.5, -0.5, -0.5);
	glVertex3f(0.5, -0.5, 0.5);
	glVertex3f(-0.5, -0.5, 0.5);
	glVertex3f(-0.5, -0.5, -0.5);
	glEnd();

	glFlush();
	glutSwapBuffers();
}


void controles(int key, int x, int y){
	if (key == GLUT_KEY_RIGHT)
		rotate_y += 5;
	else if (key == GLUT_KEY_LEFT)
		rotate_y -= 5;
	else if (key == GLUT_KEY_UP)
		rotate_x += 5;

	else if (key == GLUT_KEY_DOWN)
		rotate_x -= 5;
	glutPostRedisplay();
}

int main(int argc, char* argv[]){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutCreateWindow("Cubo");
	glEnable(GL_DEPTH_TEST);

	glutDisplayFunc(display); glutSpecialFunc(controles);
	glutMainLoop();
	return 0;
}