#include "GL/glew.h"
#include "GL/freeglut.h"
#include <iostream>

int menu_goster = 1;
int animasyon = 1;
float serit = 1;
float sag = 3.0;
float sol = 4.0;
float sag1 = 5.0;
float sol1 = 2.0;
int skor = -1;

void fonk(int key, int x, int y) {
	switch (key)
	{
	case GLUT_KEY_RIGHT:
		serit = 1.0;
		break;
	case GLUT_KEY_LEFT:
		serit = -1.0;
		break;
	}
}

void mouse(int tus, int durum, int x, int y) {
	if (tus == GLUT_LEFT_BUTTON && durum == GLUT_DOWN) {
		menu_goster = 0;
		animasyon = 0;	
	}
}

void timer(int g) {
	if (!menu_goster) {
		if (sol <= -0.6 && sol >= -0.9) {
			skor++;
			if (serit == -1) {
				printf("Game Over\nYour Score : %d", skor/6);
				exit(0);
			}
		}
		sol -= 0.05;

		if (sag <= -0.6 && sag >= -0.9) {
			skor++;
			if (serit == 1) {
				printf("Game Over\nYour Score : %d", skor/6);
				exit(0);
			}
		}
		sag -= 0.05;

		if (sol1 <= -0.6 && sol1 >= -0.9) {
			skor++;
			if (serit == -1) {
				printf("Game Over\nYour Score : %d", skor/6);
				exit(0);
			}
		}
		sol1 -= 0.05;

		if (sag1 <= -0.6 && sag1 >= -0.9) {
			skor++;
			if (serit == 1) {
				printf("Game Over\nYour Score : %d", skor/6);
				exit(0);
			}
		}
		sag1 -= 0.05;
		if (sag < -2.0) sag = 2.0;
		if (sol < -2.0) sol = 2.0;
		if (sag1 < -2.0) sag1 = 2.0;
		if (sol1 < -2.0) sol1 = 2.0;
	}
	if (animasyon) {
		glRotatef(45, 1.0, 1.0, 1.0);
	}
	else {
		glLoadIdentity();
	}
	//printf("sag = %f\nsol = %f\nsag1 = %f\nsol1 = %f\n", sag, sol, sag1, sol1);
	glutPostRedisplay();
	glutTimerFunc(100, timer, 2);
}

void display() {
	glClear(GL_COLOR_BUFFER_BIT);
	glPointSize(3.0f);
	glLineWidth(3.0f);

	if (menu_goster == 1) {
		/* Menü Ekraný */
		glColor3f(0.0, 0.8, 1.0);
		glBegin(GL_QUADS);
		glVertex3f(0.6, 0.3, 0.3);
		glVertex3f(-0.6, 0.3, 0.3);
		glVertex3f(-0.6, -0.3, 0.3);
		glVertex3f(0.6, -0.3, 0.3);
		glEnd();
		glBegin(GL_QUADS);
		glVertex3f(0.6, 0.3,-0.3);
		glVertex3f(-0.6, 0.3, -0.3);
		glVertex3f(-0.6, -0.3, -0.3);
		glVertex3f(0.6, -0.3, -0.3);
		glEnd();
		glBegin(GL_QUADS);
		glVertex3f(0.6, 0.3, 0.3);
		glVertex3f(-0.6, 0.3, 0.3);
		glVertex3f(-0.6, 0.3, -0.3);
		glVertex3f(0.6, 0.3, -0.3);
		glEnd();
		glBegin(GL_QUADS);
		glVertex3f(0.6, -0.3, 0.3);
		glVertex3f(-0.6, -0.3, 0.3);
		glVertex3f(-0.6, -0.3, -0.3);
		glVertex3f(0.6, -0.3, -0.3);
		glEnd();
		glBegin(GL_QUADS);
		glVertex3f(-0.6, 0.3, 0.3);
		glVertex3f(-0.6, 0.3, -0.3);
		glVertex3f(-0.6, -0.3, -0.3);
		glVertex3f(-0.6, -0.3, 0.3);
		glEnd();
		glBegin(GL_QUADS);
		glVertex3f(-0.6, 0.3, 0.3);
		glVertex3f(-0.6, 0.3, -0.3);
		glVertex3f(-0.6, -0.3, -0.3);
		glVertex3f(-0.6, -0.3, 0.3);
		glEnd();
		/* Oyna Yazýsý */
		{
			// O Harfi
			glColor3f(1.0, 0.4, 0.0);
			glBegin(GL_QUADS);
			glVertex3f(-0.32, 0.28, 0.3);
			glVertex3f(-0.58, 0.28, 0.3);
			glVertex3f(-0.58, -0.28, 0.3);
			glVertex3f(-0.32, -0.28, 0.3);
			glEnd();
			glColor3f(0.0, 0.8, 1.0);
			glBegin(GL_QUADS);
			glVertex3f(-0.36, 0.2, 0.3);
			glVertex3f(-0.54, 0.2, 0.3);
			glVertex3f(-0.54, -0.2, 0.3);
			glVertex3f(-0.36, -0.2, 0.3);
			glEnd();
			// Y harfi
			glColor3f(1.0, 0.4, 0.0);
			glBegin(GL_QUADS);
			glVertex3f(-0.17, -0.28, 0.3);
			glVertex3f(-0.13, -0.28, 0.3);
			glVertex3f(-0.13, 0.0, 0.3);
			glVertex3f(-0.17, 0.0, 0.3);
			glEnd();
			glBegin(GL_QUADS);
			glVertex3f(-0.28, 0.28, 0.3);
			glVertex3f(-0.24, 0.28, 0.3);
			glVertex3f(-0.13, 0.0, 0.3);
			glVertex3f(-0.17, 0.0, 0.3);
			glEnd();
			glBegin(GL_QUADS);
			glVertex3f(-0.06, 0.28, 0.3);
			glVertex3f(-0.02, 0.28, 0.3);
			glVertex3f(-0.13, 0.0, 0.3);
			glVertex3f(-0.17, 0.0, 0.3);
			glEnd();
			// N harfi
			glColor3f(1.0, 0.4, 0.0);
			glBegin(GL_QUADS);
			glVertex3f(0.02, 0.28, 0.3);
			glVertex3f(0.06, 0.28, 0.3);
			glVertex3f(0.06, -0.28, 0.3);
			glVertex3f(0.02, -0.28, 0.3);
			glEnd();
			glBegin(GL_QUADS);
			glVertex3f(0.24, 0.28, 0.3);
			glVertex3f(0.28, 0.28, 0.3);
			glVertex3f(0.28, -0.28, 0.3);
			glVertex3f(0.24, -0.28, 0.3);
			glEnd();
			glBegin(GL_QUADS);
			glVertex3f(0.02, 0.28, 0.3);
			glVertex3f(0.06, 0.28, 0.3);
			glVertex3f(0.28, -0.28, 0.3);
			glVertex3f(0.24, -0.28, 0.3);
			glEnd();
			// A Harfi
			glColor3f(1.0, 0.4, 0.0);
			glBegin(GL_QUADS);
			glVertex3f(0.43, 0.28, 0.3);
			glVertex3f(0.47, 0.28, 0.3);
			glVertex3f(0.36, -0.28, 0.3);
			glVertex3f(0.32, -0.28, 0.3);
			glEnd();
			glBegin(GL_QUADS);
			glVertex3f(0.43, 0.28, 0.3);
			glVertex3f(0.47, 0.28, 0.3);
			glVertex3f(0.58, -0.28, 0.3);
			glVertex3f(0.54, -0.28, 0.3);
			glEnd();
			glBegin(GL_QUADS);
			glVertex3f(0.535, -0.06, 0.3);
			glVertex3f(0.365, -0.06, 0.3);
			glVertex3f(0.365, -0.15, 0.3);
			glVertex3f(0.535, -0.15, 0.3);
			glEnd();
		}
	}
	else {
		/* Yol */
		glColor3f(1.0, 1.0, 1.0);
		glBegin(GL_LINES);
		glVertex2f(0, 1.0);
		glVertex2f(0, -1.0);
		glEnd();

		/* Araba */
		glColor3f(0.0, 0.0, 1.0);
		glBegin(GL_QUADS);
		glVertex2f(0.4 * serit, -0.6);
		glVertex2f(0.4 * serit, -0.9);
		glVertex2f(0.6 * serit, -0.9);
		glVertex2f(0.6 * serit, -0.6);
		glEnd();

		/* Engel Sag */
		glColor3f(1.0, 0.0, 0.0);
		glBegin(GL_QUADS);
		glVertex2f(0.1, sag);
		glVertex2f(0.1, sag + 0.1);
		glVertex2f(0.9, sag + 0.1);
		glVertex2f(0.9, sag);
		glEnd();

		/* Engel Sol */
		glColor3f(1.0, 0.0, 0.0);
		glBegin(GL_QUADS);
		glVertex2f(-0.1, sol);
		glVertex2f(-0.1, sol + 0.1);
		glVertex2f(-0.9, sol + 0.1);
		glVertex2f(-0.9, sol);
		glEnd();

		/* Engel Sag 1 */
		glColor3f(1.0, 0.0, 0.0);
		glBegin(GL_QUADS);
		glVertex2f(0.1, sag1);
		glVertex2f(0.1, sag1 + 0.1);
		glVertex2f(0.9, sag1 + 0.1);
		glVertex2f(0.9, sag1);
		glEnd();

		/* Engel Sol 1 */
		glColor3f(1.0, 0.0, 0.0);
		glBegin(GL_QUADS);
		glVertex2f(-0.1, sol1);
		glVertex2f(-0.1, sol1 + 0.1);
		glVertex2f(-0.9, sol1 + 0.1);
		glVertex2f(-0.9, sol1);
		glEnd();
	}
		
	/* Ekrana Basma Kýsmý */
	glutPostRedisplay();
	glFlush();
}

int main(int argc, char* argv[]) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowSize(600, 600);
	glutCreateWindow("Küp Kaçýyor");
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glEnable(GL_DEPTH);
	glutDisplayFunc(display);
	glutMouseFunc(mouse);
	glutSpecialFunc(fonk);
	glutTimerFunc(100, timer, 2);
	glutMainLoop();
	return 0;
}