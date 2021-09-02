#include<windows.h>
#include<stdio.h>
#include <stdlib.h>
#include<gl\glut.h>
#include <iostream>
#include <GL\freeglut.h>
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
unsigned int frontSheet, moral, tq;
int menulist;
double truckfront = 750;
double truckback = 1100;
//double t1 = 800;
//double t2 = 805;
double t3 = 900;
double t4 = 905;
double t5 = 1000;
double t6 = 1005;
double t7 = 1100;
double t8 = 1095;
double t11 = 1060;
double t12 = 1000;
double t13 = 830;
//double t14 = 700;
double t15 = 750;
double t16 = 1080;
double t17 = 800;
double t18 = 780;
double t19 = 1000;
double t20 = 1000;
double t21 = 1050;
double t22 = 1040;
double tb1 = 750;
double tb2 = 800;
double tb3 = 900;
double tw1 = 775;
double tw2 = 800;
double tw3 = 850;
int p = 0;
float yMove = 0.0;
float j = 0;
float m = 0.0;   //megh
int i = 0;
int boat = 0;
int l;
int t = 0;
int z = 1;
int b = 0;
int megh = 1;
int c_w = 615;

double front = 1010;
double back = 1100;

double carfront = 1040;
double carback = 1080;
double fronttraingle = 980;
//double front2 = 600;
//double back2 = 690;
int day = 1;
int tree;
int bus = 1;

double fronttraingle1 = 710;
double front1 = 740;
double back1 = 830;
double carfront1 = 770;
double carback1 = 810;

double fronttraingle2 = 575;
double front2 = 605;
double back2 = 695;
double carfront2 = 635;
double carback2 = 675;

double fronttraingle3 = 400;
double front3 = 430;
double back3 = 520;
double carfront3 = 460;
double carback3 = 500;

double fronttraingle4 = 900;
double front4 = 930;
double back4 = 1020;
double carfront4 = 960;
double carback4 = 1000;

float theta1 = 0.0;
float theta2 = 0.0;
float theta3 = 0.0;

int d = 0;

void draw_pixel(GLint cx, GLint cy)
{
	glBegin(GL_POINTS);
	glVertex2i(cx, cy);
	glEnd();
}

void plotpixels(GLint h, GLint k, GLint x, GLint y)
{
	draw_pixel(x + h, y + k);
	draw_pixel(-x + h, y + k);
	draw_pixel(x + h, -y + k);
	draw_pixel(-x + h, -y + k);
	draw_pixel(y + h, x + k);
	draw_pixel(-y + h, x + k);
	draw_pixel(y + h, -x + k);
	draw_pixel(-y + h, -x + k);
}

void draw_circle(GLint h, GLint k, GLint r)
{
	GLint d = 1 - r, x = 0, y = r;
	while (y > x)
	{
		plotpixels(h, k, x, y);
		if (d < 0) d += 2 * x + 3;
		else
		{
			d += 2 * (x - y) + 5;
			--y;
		}
		++x;
	}
	plotpixels(h, k, x, y);
}
void drawText(float x, float y, int r, int g, int b, int d, const char* string)
{
	int p = strlen(string);
	glColor3f(r, g, b);
	glRasterPos2f(x, y);
	for (int i = 0; i < p; i++) {
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, string[i]);
		for (int k = d; k > 0; k--) {
			glFlush();
		}
	}
}
void circle(GLfloat x, GLfloat y, GLdouble radius) {
	float x2, y2;
	float angle;
	glPointSize(2.0);
	glBegin(GL_TRIANGLE_FAN);
	for (angle = 0.0; angle < 6.3; angle += 0.01)
	{
		x2 = x + sin(angle) * radius;
		y2 = y + cos(angle) * radius;
		glVertex2f(x2, y2);
	}
	glEnd();
}
void treebody(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4)
{
	glBegin(GL_POLYGON);
	glVertex2f(x1, y1);
	glVertex2f(x2, y2);
	glVertex2f(x3, y3);
	glVertex2f(x4, y4);
	glEnd();
}
void background1() {
	if (day == 1) {
		//sky
		glColor3f(.2, .6, .8);
		glBegin(GL_POLYGON);
		glVertex2f(0, 450);
		glVertex2f(0, 700);
		glVertex2f(1100, 700);
		glVertex2f(1100, 450);
		glEnd();
		//sun

		glColor3f(1.0, 0.0, 0.0);
		circle(700, 600, 35);
		if (m < 300)
		{
			//cloud 1

			glColor3f(1.0, 1.0, 1.0);
			circle(160 + m, 625, 20);


			glColor3f(1.0, 1.0, 1.0);
			circle(200 + m, 625, 35);
			circle(225 + m, 625, 35);


			glColor3f(1.0, 1.0, 1.0);
			circle(265 + m, 625, 20);


			//cloud2

			glColor3f(1.0, 1.0, 1.0);
			circle(370 + m, 615, 20);


			glColor3f(1.0, 1.0, 1.0);
			circle(410 + m, 615, 35);
			circle(435 + m, 615, 35);
			circle(470 + m, 615, 35);


			glColor3f(1.0, 1.0, 1.0);
			circle(500 + m, 615, 20);

			if (megh == 1)
			{
				m = m + 0.1;
			}
		}
		else
		{
			m = 0;

			glColor3f(1.0, 1.0, 1.0);
			circle(300 + m, 625, 20);


			glColor3f(1.0, 1.0, 1.0);
			circle(340 + m, 625, 35);
			circle(350 + m, 625, 35);


			glColor3f(1.0, 1.0, 1.0);
			circle(385 + m, 625, 20);

			//cloud2

			glColor3f(1.0, 1.0, 1.0);
			circle(370 + m, 615, 20);

			glColor3f(1.0, 1.0, 1.0);
			circle(410 + m, 615, 35);
			circle(435 + m, 615, 35);
			circle(470 + m, 615, 35);


			glColor3f(1.0, 1.0, 1.0);
			circle(500 + m, 615, 20);

			/*if (megh == 1)
			{
				m = m + 0.1;
			}*/
		}


		//mountains
		glColor3f(0.6, 0.2, 0.0);
		glBegin(GL_POLYGON);
		glVertex2f(0, 450);
		glVertex2f(150, 500);
		glVertex2f(400, 450);
		glEnd();

		glColor3f(0.6, 0.2, 0.0);
		glBegin(GL_POLYGON);
		glVertex2f(700, 450);
		glVertex2f(400, 550);
		glVertex2f(300, 450);
		glEnd();

		glColor3f(0.6, 0.2, 0.0);
		glBegin(GL_POLYGON);
		glVertex2f(670, 450);
		glVertex2f(900, 520);
		glVertex2f(1100, 450);
		glEnd();

		glColor3f(0.6, 0.2, 0.0);
		glBegin(GL_POLYGON);
		glVertex2f(600, 450);
		glVertex2f(680, 500);
		glVertex2f(750, 450);
		glEnd();

		//grass
		glColor3f(0.1, 0.3, 0.2);
		glBegin(GL_POLYGON);
		glVertex2f(0, 100);
		glVertex2f(0, 450);
		glVertex2f(1100, 450);
		glVertex2f(1100, 100);
		glEnd();

		//river
		glColor3f(0.0, 0.4, 1.0);
		glBegin(GL_POLYGON);
		glVertex2f(1100, 0);
		glVertex2f(0, 0);
		glVertex2f(0, 100);
		glVertex2f(1100, 100);
		glEnd();

		//river curve
		glColor3f(0.0, 0.4, 1.0);
		glBegin(GL_POLYGON);
		glVertex2f(0, 0);
		glVertex2f(0, 100);
		glVertex2f(100, 120);
		glVertex2f(0, 120);
		glEnd();

		//river circle
		glColor3f(0.0, 0.4, 1.0);
		circle(100, 30, 100);

		if (boat < 800)
		{
			//boat bigger part
			glColor3f(0.2, 0.0, 0.0);
			glBegin(GL_POLYGON);
			glVertex2f(1100 - boat, 55);
			glVertex2f(1100 - boat, 91);
			glVertex2f(830 - boat, 91);
			glVertex2f(900 - boat, 55);
			glEnd();

			//boat small part
			glColor3f(0.2, 0.0, 0.0);
			glBegin(GL_POLYGON);
			glVertex2f(1100 - boat, 104);
			glVertex2f(1100 - boat, 91);
			glVertex2f(1000 - boat, 91);
			glVertex2f(1000 - boat, 104);
			glEnd();

			if (b == 0)
			{
				boat = boat + 1;
			}
		}
		else
		{
			boat = 0;
			//boat bigger part
			glColor3f(0.2, 0.0, 0.0);
			glBegin(GL_POLYGON);
			glVertex2f(647 - boat, 66);
			glVertex2f(811 - boat, 66);
			glVertex2f(830 - boat, 102);
			glVertex2f(588 - boat, 102);
			glEnd();

			//boat small part
			glColor3f(0.2, 0.0, 0.0);
			glBegin(GL_POLYGON);
			glVertex2f(815 - boat, 102);
			glVertex2f(815 - boat, 114);
			glVertex2f(772 - boat, 114);
			glVertex2f(772 - boat, 102);
			glEnd();
			boat = boat + 1;
		}
	}
	glutPostRedisplay();
}




void background() {
	int l;
	if (day == 1)
	{
		//sky
		glColor3f(.2, .6, .8);
		glBegin(GL_POLYGON);
		glVertex2f(0, 450);
		glVertex2f(0, 700);
		glVertex2f(1100, 700);
		glVertex2f(1100, 450);
		glEnd();
		//sun
		glColor3f(1.0, 0.9, 0.0);
		circle(700, 600, 35);
		if (m < 300)
		{
			//cloud 1

			glColor3f(1.0, 1.0, 1.0);
			circle(160 + m, 625, 20);


			glColor3f(1.0, 1.0, 1.0);
			circle(200 + m, 625, 35);
			circle(225 + m, 625, 35);


			glColor3f(1.0, 1.0, 1.0);
			circle(265 + m, 625, 20);


			//cloud2

			glColor3f(1.0, 1.0, 1.0);
			circle(370 + m, 615, 20);


			glColor3f(1.0, 1.0, 1.0);
			circle(410 + m, 615, 35);
			circle(435 + m, 615, 35);
			circle(470 + m, 615, 35);


			glColor3f(1.0, 1.0, 1.0);
			circle(500 + m, 615, 20);

			if (megh == 1)
			{
				m = m + 0.1;
			}
		}
		else
		{
			m = 0;

			glColor3f(1.0, 1.0, 1.0);
			circle(300 + m, 625, 20);


			glColor3f(1.0, 1.0, 1.0);
			circle(340 + m, 625, 35);
			circle(350 + m, 625, 35);


			glColor3f(1.0, 1.0, 1.0);
			circle(385 + m, 625, 20);

			//cloud2

			glColor3f(1.0, 1.0, 1.0);
			circle(370 + m, 615, 20);

			glColor3f(1.0, 1.0, 1.0);
			circle(410 + m, 615, 35);
			circle(435 + m, 615, 35);
			circle(470 + m, 615, 35);


			glColor3f(1.0, 1.0, 1.0);
			circle(500 + m, 615, 20);


			/*if (megh == 1)
			{
				m = m + 0.1;
			}*/
		}
		//mountains
		glColor3f(0.6, 0.2, 0.0);
		glBegin(GL_POLYGON);
		glVertex2f(0, 450);
		glVertex2f(150, 500);
		glVertex2f(400, 450);
		glEnd();

		glColor3f(0.6, 0.2, 0.0);
		glBegin(GL_POLYGON);
		glVertex2f(700, 450);
		glVertex2f(400, 550);
		glVertex2f(300, 450);
		glEnd();

		glColor3f(0.6, 0.2, 0.0);
		glBegin(GL_POLYGON);
		glVertex2f(670, 450);
		glVertex2f(900, 520);
		glVertex2f(1100, 450);
		glEnd();

		glColor3f(0.6, 0.2, 0.0);
		glBegin(GL_POLYGON);
		glVertex2f(600, 450);
		glVertex2f(680, 500);
		glVertex2f(750, 450);
		glEnd();

		//grass
		glColor3f(0.5, 1.0, 0.2);
		glBegin(GL_POLYGON);
		glVertex2f(0, 100);
		glVertex2f(0, 450);
		glVertex2f(1100, 450);
		glVertex2f(1100, 100);
		glEnd();

		//river
		glColor3f(0.0, 0.4, 1.0);
		glBegin(GL_POLYGON);
		glVertex2f(1100, 0);
		glVertex2f(0, 0);
		glVertex2f(0, 100);
		glVertex2f(1100, 100);
		glEnd();

		//river curve
		glColor3f(0.0, 0.4, 1.0);
		glBegin(GL_POLYGON);
		glVertex2f(0, 0);
		glVertex2f(0, 100);
		glVertex2f(100, 120);
		glVertex2f(0, 120);
		glEnd();

		//river circle
		glColor3f(0.0, 0.4, 1.0);
		circle(100, 30, 100);

		if (boat < 800)
		{
			//boat bigger part
			glColor3f(0.2, 0.0, 0.0);
			glBegin(GL_POLYGON);
			glVertex2f(1100 - boat, 55);
			glVertex2f(1100 - boat, 91);
			glVertex2f(830 - boat, 91);
			glVertex2f(900 - boat, 55);
			glEnd();

			//boat small part
			glColor3f(0.2, 0.0, 0.0);
			glBegin(GL_POLYGON);
			glVertex2f(1100 - boat, 104);
			glVertex2f(1100 - boat, 91);
			glVertex2f(1000 - boat, 91);
			glVertex2f(1000 - boat, 104);
			glEnd();

			if (b == 0)
			{
				boat = boat + 1;
			}
		}
		else
		{
			boat = 0;
			//boat bigger part
			glColor3f(0.2, 0.0, 0.0);
			glBegin(GL_POLYGON);
			glVertex2f(647 - boat, 66);
			glVertex2f(811 - boat, 66);
			glVertex2f(830 - boat, 102);
			glVertex2f(588 - boat, 102);
			glEnd();

			//boat small part
			glColor3f(0.2, 0.0, 0.0);
			glBegin(GL_POLYGON);
			glVertex2f(815 - boat, 102);
			glVertex2f(815 - boat, 114);
			glVertex2f(772 - boat, 114);
			glVertex2f(772 - boat, 102);
			glEnd();
			boat = boat + 1;
		}
	}
	glutPostRedisplay();
}

void draw_object()
{
	glColor3f(0.3, 0.0, 0.0);
	treebody(540, 160, 540, 580, 580, 580, 580, 160);

	glColor3f(0.3, 0.0, 0.0);
	treebody(220, 160, 220, 580, 260, 580, 260, 160);

	//glColor3f(0.3, 0.0, 0.0);
	//treebody(45, 160, 45, 280, 55, 280, 55, 160);

	//glColor3f(0.0, 0.5, 0.0);
	//circle(65, 280, 30);
	//circle(35, 280, 30);
	//circle(50, 280, 30);
	//circle(58, 300, 30);
	//circle(43, 300, 30);
	//circle(50, 250, 10);

	glColor3f(0.3, 0.0, 0.0);
	treebody(90, 160, 90, 400, 130, 400, 130, 160);

	glColor3f(0.3, 0.0, 0.0);
	treebody(360, 160, 360, 400, 400, 400, 400, 160);

	glColor3f(0.3, 0.0, 0.0);
	treebody(670, 160, 670, 400, 710, 400, 710, 160);

	glColor3f(0.0, 0.5, 0.0);
	circle(560, 490, 50);//midddle tree
	circle(480, 490, 50);
	circle(640, 490, 50);
	circle(520, 550, 50);
	circle(600, 550, 50);

	circle(240, 490, 50);//left tree
	circle(160, 490, 50);
	circle(320, 490, 50);
	circle(200, 550, 50);
	circle(280, 550, 50);

	circle(110, 350, 40);
	circle(70, 350, 40);
	circle(160, 350, 40);
	circle(90, 390, 40);
	circle(130, 390, 40);

	circle(690, 350, 50);
	circle(640, 350, 50);
	circle(740, 350, 50);
	circle(670, 390, 50);
	circle(710, 390, 50);

	circle(380, 350, 50);
	circle(430, 350, 50);
	circle(330, 350, 50);
	circle(355, 390, 50);
	circle(405, 390, 50);

}

void lion()
{

	glColor3f(255, 69, 0);     //body
	glBegin(GL_POLYGON);
	glVertex3f(450, 191, 0);
	glVertex3f(560, 191, 0);
	glVertex3f(560, 250, 0);
	glVertex3f(450, 250, 0);
	glEnd();
	glColor3f(0.8, 0.0, 0.0);
	glBegin(GL_POLYGON);          //head
	glVertex3f(415, 200, 0);
	glVertex3f(440, 200, 0);
	glVertex3f(460, 220, 0);
	glVertex3f(460, 250, 0);
	glVertex3f(440, 270, 0);
	glVertex3f(415, 270, 0);
	glVertex3f(395, 250, 0);
	glVertex3f(395, 220, 0);
	glEnd();

	glColor3f(255, 69, 0);
	circle(427, 235, 25);        //inside head

	glColor3f(255, 69, 0);
	circle(450, 250, 15);        //ear right

	glColor3f(255, 69, 0);
	circle(405, 250, 15);        //ear left

	glColor3f(0, 0, 0);
	circle(420, 243, 5);        //eye left

	glColor3f(0, 0, 0);
	circle(435, 243, 5);        //eye right

	glColor3f(1, 1, 1);
	circle(420.5, 244, 3);       //eye inside left

	glColor3f(1, 1, 1);
	circle(435.5, 244, 3);       //eye inside right

	glColor3f(0, 0, 0);
	circle(420.7, 244.3, 1);       //inside black eye left

	glColor3f(0, 0, 0);
	circle(435.7, 244.3, 1);       //inside black eye right

	glColor3f(3, 0, 3);             //nose
	glBegin(GL_POLYGON);
	glVertex3f(427, 220, 0);
	glVertex3f(415, 235, 0);
	glVertex3f(440, 235, 0);
	glEnd();
	glColor3f(255, 69, 0);          //tail
	glBegin(GL_POLYGON);
	glVertex3f(561, 240, 0);
	glVertex3f(585, 240, 0);
	glVertex3f(585, 250, 0);
	glVertex3f(561, 250, 0);
	glEnd();
	glColor3f(255, 69, 0);
	glBegin(GL_POLYGON);
	glVertex3f(450, 160, 0);          //first leg
	glVertex3f(465, 160, 0);
	glVertex3f(465, 190, 0);
	glVertex3f(450, 190, 0);
	glEnd();
	glColor3f(255, 69, 0);
	glBegin(GL_POLYGON);                //second leg
	glVertex3f(560, 160, 0);
	glVertex3f(545, 160, 0);
	glVertex3f(545, 190, 0);
	glVertex3f(560, 190, 0);
	glEnd();


}
void elephant()
{

	glColor3f(0.50, 0.50, 0.50);
	circle(800, 265, 70);        //body

	glColor3f(0.50, 0.50, 0.50);
	circle(675, 260, 50);        //head

	/*glColor3f(0, 0, 0);
	circle(660, 270, 7);        //eye left

	glColor3f(0, 0, 0);
	circle(690, 270, 7);        //eye right*/

	glColor3f(1, 1, 1);
	circle(660, 270, 7);       //eye inside left

	glColor3f(1, 1, 1);
	circle(690, 270, 7);       //eye inside right

	glColor3f(0, 0, 0);
	circle(660.4, 270.4, 4);       //inside black eye left

	glColor3f(0, 0, 0);
	circle(690.4, 270.4, 4);       //inside black eye right

	//glColor3f(0.30, 0.30, 0.30);  
	//circle(730, 290, 30);       //ear1

	//glColor3f(0.30, 0.30, 0.30);
	//circle(620, 290, 30);       //ear2

	glColor3f(0.30, 0.30, 0.30);     //trunk
	glBegin(GL_POLYGON);
	glVertex3f(665, 160, 0);
	glVertex3f(685, 160, 0);
	glVertex3f(685, 250, 0);
	glVertex3f(665, 250, 0);
	glEnd();

	glColor3f(1, 1, 1);             //tusk1
	glBegin(GL_POLYGON);
	glVertex3f(645, 235, 0);
	glVertex3f(665, 235, 0);
	glVertex3f(655, 200, 0);
	glEnd();
	glColor3f(1, 1, 1);             //tusk2
	glBegin(GL_POLYGON);
	glVertex3f(685, 235, 0);
	glVertex3f(705, 235, 0);
	glVertex3f(695, 200, 0);
	glEnd();

	glColor3f(0.30, 0.30, 0.30);
	glBegin(GL_POLYGON);
	glVertex3f(760, 160, 0);          //first leg
	glVertex3f(780, 160, 0);
	glVertex3f(780, 230, 0);
	glVertex3f(760, 230, 0);
	glEnd();
	glColor3f(0.30, 0.30, 0.30);
	glBegin(GL_POLYGON);                //second leg
	glVertex3f(820, 160, 0);
	glVertex3f(840, 160, 0);
	glVertex3f(840, 230, 0);
	glVertex3f(820, 230, 0);
	glEnd();

	glColor3f(0.30, 0.30, 0.30);
	glBegin(GL_POLYGON);          //ear1
	glVertex3f(715, 270, 0);
	glVertex3f(745, 270, 0);
	glVertex3f(765, 300, 0);
	glVertex3f(730, 330, 0);
	glVertex3f(695, 300, 0);
	glEnd();

	glColor3f(0.30, 0.30, 0.30);
	glBegin(GL_POLYGON);          //ear2
	glVertex3f(600, 270, 0);
	glVertex3f(630, 270, 0);
	glVertex3f(650, 300, 0);
	glVertex3f(615, 330, 0);
	glVertex3f(615, 300, 0);
	glEnd();


}
void giraffe(void)
{

	glColor3f(255, 211, 0);     //body
	glBegin(GL_POLYGON);
	glVertex3f(180, 250, 0);
	glVertex3f(280, 250, 0);
	glVertex3f(280, 330, 0);
	glVertex3f(180, 330, 0);
	glEnd();

	glColor3f(0.8, 0, 0);     //pattern1
	glBegin(GL_POLYGON);
	glVertex3f(190, 315, 0);
	glVertex3f(210, 315, 0);
	glVertex3f(210, 330, 0);
	glVertex3f(190, 320, 0);
	glEnd();
	glColor3f(0.8, 0, 0);     //pattern2
	glBegin(GL_POLYGON);
	glVertex3f(250, 270, 0);
	glVertex3f(265, 280, 0);
	glVertex3f(250, 290, 0);
	glVertex3f(235, 280, 0);
	glEnd();
	glColor3f(0.8, 0, 0);     //pattern3
	glBegin(GL_POLYGON);
	glVertex3f(260, 310, 0);
	glVertex3f(280, 315, 0);
	glVertex3f(260, 330, 0);
	glVertex3f(250, 325, 0);
	glEnd();
	glColor3f(0.8, 0, 0);     //pattern4
	glBegin(GL_POLYGON);
	glVertex3f(220, 295, 0);
	glVertex3f(235, 300, 0);
	glVertex3f(225, 310, 0);
	glVertex3f(210, 305, 0);
	glEnd();
	glColor3f(0.8, 0, 0);     //pattern5
	glBegin(GL_POLYGON);
	glVertex3f(195, 260, 0);
	glVertex3f(220, 263, 0);
	glVertex3f(200, 280, 0);
	glVertex3f(188, 285, 0);
	glEnd();
	glColor3f(0.8, 0, 0);     //pattern6
	glBegin(GL_POLYGON);
	glVertex3f(270, 250, 0);
	glVertex3f(280, 255, 0);
	glVertex3f(278, 260, 0);
	glVertex3f(266, 258, 0);
	glEnd();
	glColor3f(255, 211, 0);             //neck
	glBegin(GL_POLYGON);
	glVertex3f(280, 331, 0);
	glVertex3f(250, 331, 0);
	glVertex3f(300, 450, 0);
	glEnd();
	glColor3f(0.8, 0, 0);     //pattern1n
	glBegin(GL_POLYGON);
	glVertex3f(275, 365, 0);
	glVertex3f(282, 370, 0);
	glVertex3f(270, 375, 0);
	glVertex3f(265, 369, 0);
	glEnd();
	glColor3f(0.8, 0, 0);     //pattern2n
	glBegin(GL_POLYGON);
	glVertex3f(270, 340, 0);
	glVertex3f(280, 345, 0);
	glVertex3f(278, 350, 0);
	glVertex3f(266, 348, 0);
	glEnd();
	glColor3f(0.8, 0, 0);     //pattern3n
	glBegin(GL_POLYGON);
	glVertex3f(285, 390, 0);
	glVertex3f(290, 395, 0);
	glVertex3f(287, 400, 0);
	glVertex3f(281, 398, 0);
	glEnd();
	glColor3f(0.8, 0, 0);     //pattern4n
	glBegin(GL_POLYGON);
	glVertex3f(289, 410, 0);
	glVertex3f(293, 415, 0);
	glVertex3f(290, 417, 0);
	glVertex3f(285, 416, 0);
	glEnd();
	glColor3f(255, 211, 0);             //face
	glBegin(GL_POLYGON);
	glVertex3f(300, 450, 0);
	glVertex3f(315, 480, 0);
	glVertex3f(360, 440, 0);
	glEnd();
	glColor3f(255, 211, 0);             //ear
	glBegin(GL_POLYGON);
	glVertex3f(313, 470, 0);
	glVertex3f(315, 480, 0);
	glVertex3f(290, 475, 0);
	glEnd();
	glColor3f(0, 0, 0);
	circle(318, 465, 4);                //eye
	glColor3f(1, 1, 1);
	circle(318.5, 465.5, 2);           //eye white

	glColor3f(255, 211, 0);             //back leg1
	glBegin(GL_POLYGON);
	glVertex3f(180, 249, 0);
	glVertex3f(200, 249, 0);
	glVertex3f(190, 160, 0);
	glEnd();
	//glFlush();
	glColor3f(255, 211, 0);             //back leg2
	glBegin(GL_POLYGON);
	glVertex3f(200, 249, 0);
	glVertex3f(220, 249, 0);
	glVertex3f(210, 160, 0);
	glEnd();
	//glFlush();
	glColor3f(255, 211, 0);             //front leg1
	glBegin(GL_POLYGON);
	glVertex3f(280, 249, 0.0);
	glVertex3f(260, 249, 0.0);
	glVertex3f(270, 160, 0.0);
	glEnd();
	//glFlush();
	glColor3f(255, 211, 0);             //front leg2
	glBegin(GL_POLYGON);
	glVertex3f(260, 249, 0.0);
	glVertex3f(240, 249, 0.0);
	glVertex3f(250, 160, 0.0);
	glEnd();

	glColor3f(0.3, 0.0, 0.0);             //horn1
	glBegin(GL_LINES);
	glVertex2d(315, 480);
	glVertex2d(310, 520);
	glEnd();

	glColor3f(0.3, 0.0, 0.0);             //horn2
	glBegin(GL_LINES);
	glVertex2d(315, 480);
	glVertex2d(330, 520);
	glEnd();

	glColor3f(0.3, 0.0, 0.0);             //tail
	glBegin(GL_LINES);
	glVertex2d(180, 330);
	glVertex2d(160, 290);
	glEnd();
	//glFlush();

}


void drawobject1() {

	glColor3f(0.3, 0.0, 0.0);
	treebody(540, 160, 540, 580, 580, 580, 580, 160);//tree2

	glColor3f(0.3, 0.0, 0.0);
	treebody(220, 160, 220, 580, 260, 580, 260, 160);

	//glColor3f(0.3, 0.0, 0.0);
	//treebody(45, 170, 45, 280, 55, 280, 55, 170);

	/*glColor3f(0.0, 0.5, 0.0);
	circle(65, 280, 30);
	circle(35, 280, 30);
	circle(50, 280, 30);
	circle(58, 300, 30);
	circle(43, 300, 30);*/
	//circle(50, 250, 10);

	glColor3f(0.3, 0.0, 0.0);
	treebody(90, 160, 90, 400, 130, 400, 130, 160);

	glColor3f(0.3, 0.0, 0.0);
	treebody(360, 160, 360, 400, 400, 400, 400, 160);

	glColor3f(0.3, 0.0, 0.0);
	treebody(670, 160, 670, 190, 710, 190, 710, 160);

	//win5();

	//glColor3f(0.3, 0.0, 0.0);
	//treebody(730, 190, 730, 220, 900, 220, 900, 190);

	glColor3f(0.0, 0.5, 0.0);
	circle(560, 490, 50);//midddle tree
	circle(480, 490, 50);
	circle(640, 490, 50);
	circle(520, 550, 50);
	circle(600, 550, 50);

	circle(240, 490, 50);//left tree
	circle(160, 490, 50);
	circle(320, 490, 50);
	circle(200, 550, 50);
	circle(280, 550, 50);

	circle(110, 350, 40);
	circle(70, 350, 40);
	circle(160, 350, 40);
	circle(90, 390, 40);
	circle(130, 390, 40);

	//circle(900, 200, 50);
	//circle(900, 250, 50);
	//circle(900, 150, 50);
	//circle(920, 225, 50);
	//circle(920, 175, 50);

	circle(380, 350, 50);
	circle(430, 350, 50);
	circle(330, 350, 50);
	circle(355, 390, 50);
	circle(405, 390, 50);
}

void drawobject2() {
	glColor3f(0.3, 0.0, 0.0);
	treebody(540, 160, 540, 190, 580, 190, 580, 160); //tree2

	//glColor3f(0.3, 0.0, 0.0);
	//treebody(600, 200, 580, 230, 800, 350, 800, 320); //tree2-1

	glColor3f(0.3, 0.0, 0.0);
	treebody(220, 160, 220, 580, 260, 580, 260, 160); //tree4

	//(0.3, 0.0, 0.0);
	//treebody(45, 170, 45, 280, 55, 280, 55, 170); //tree6

	/*glColor3f(0.0, 0.5, 0.0);
	circle(65, 280, 30);
	circle(35, 280, 30);
	circle(50, 280, 30);
	circle(58, 300, 30);
	circle(43, 300, 30);*/
	//circle(50, 250, 10); //t6

	glColor3f(0.3, 0.0, 0.0);
	treebody(90, 160, 90, 400, 130, 400, 130, 160); //tree5

	glColor3f(0.3, 0.0, 0.0);
	treebody(360, 160, 360, 400, 400, 400, 400, 160); //tree3

	glColor3f(0.3, 0.0, 0.0);
	treebody(670, 160, 670, 190, 710, 190, 710, 160); //tree1

	glColor3f(0.3, 0.0, 0.0);
	treebody(730, 190, 730, 220, 900, 220, 900, 190); //tree1-1

	glColor3f(0.0, 0.5, 0.0);
	//circle(750, 380, 50);
	//circle(750, 370, 50);
	//circle(770, 360, 50);
	//circle(790, 300, 50);
	//circle(790, 300, 50);  //t2

	circle(240, 490, 50);
	circle(160, 490, 50);
	circle(320, 490, 50);
	circle(200, 550, 50);
	circle(280, 550, 50);  //t4

	circle(110, 350, 40);
	circle(70, 350, 40);
	circle(160, 350, 40);
	circle(90, 390, 40);
	circle(130, 390, 40);  //t5

	circle(900, 200, 40);
	circle(900, 250, 40);
	circle(900, 150, 40);
	circle(920, 225, 40);
	circle(920, 175, 40); //t1

	circle(380, 350, 50);
	circle(430, 350, 50);
	circle(330, 350, 50);
	circle(355, 390, 50);
	circle(405, 390, 50); //t3
}


void drawobject3() {
	glColor3f(0.3, 0.0, 0.0);
	treebody(540, 160, 540, 190, 580, 190, 580, 160); //tree2

	glColor3f(0.3, 0.0, 0.0);
	treebody(600, 200, 580, 230, 800, 350, 800, 320); //tree2-1

	glColor3f(0.3, 0.0, 0.0);
	treebody(220, 160, 220, 580, 260, 580, 260, 160); //tree4

	//glColor3f(0.3, 0.0, 0.0);
	//treebody(45, 170, 45, 280, 55, 280, 55, 170); //tree6

	/*glColor3f(0.0, 0.5, 0.0);
	circle(65, 280, 30);
	circle(35, 280, 30);
	circle(50, 280, 30);
	circle(58, 300, 30);
	circle(43, 300, 30);*/
	//circle(50, 250, 10); //t6

	glColor3f(0.3, 0.0, 0.0);
	treebody(90, 160, 90, 400, 130, 400, 130, 160); //tree5

	glColor3f(0.3, 0.0, 0.0);
	treebody(360, 160, 360, 190, 400, 190, 400, 160); //tree3

	//glColor3f(0.3, 0.0, 0.0);
	//treebody(400, 200, 380, 230, 500, 350, 520, 320); //tree3-1

	glColor3f(0.3, 0.0, 0.0);
	treebody(670, 160, 670, 190, 710, 190, 710, 160); //tree1

	glColor3f(0.3, 0.0, 0.0);
	treebody(730, 190, 730, 220, 900, 220, 900, 190); //tree1-1

	glColor3f(0.0, 0.5, 0.0);
	circle(750, 380, 50);
	circle(750, 370, 50);
	circle(770, 360, 50);
	circle(790, 300, 50);
	circle(790, 300, 50);  //t2

	circle(240, 490, 60);
	circle(160, 490, 60);
	circle(320, 490, 60);
	circle(200, 550, 60);
	circle(280, 550, 60);  //t4

	circle(110, 350, 40);
	circle(70, 350, 40);
	circle(160, 350, 40);
	circle(90, 390, 40);
	circle(130, 390, 40);  //t5

	circle(900, 200, 50);
	circle(900, 250, 50);
	circle(900, 150, 50);
	circle(920, 225, 50);
	circle(920, 175, 50); //t1

	//circle(480, 380, 50);
	//circle(490, 350, 50);
	//circle(500, 360, 50);
	//circle(520, 300, 50);
	//circle(540, 300, 50); //t3
}
void drawobject4() {
	glColor3f(0.3, 0.0, 0.0);
	treebody(540, 160, 540, 190, 580, 190, 580, 160); //tree2

	glColor3f(0.3, 0.0, 0.0);
	treebody(600, 200, 580, 230, 800, 350, 800, 320); //tree2-1

	glColor3f(0.3, 0.0, 0.0);
	treebody(220, 160, 220, 190, 260, 190, 260, 160); //tree4

	glColor3f(0.3, 0.0, 0.0);
	treebody(220, 160, 220, 580, 260, 580, 260, 160); //tree4

	glColor3f(0.0, 0.5, 0.0);
	circle(240, 490, 60);
	circle(160, 490, 60);
	circle(320, 490, 60);
	circle(200, 550, 60);
	circle(280, 550, 60);

	//glColor3f(0.3, 0.0, 0.0);
	//treebody(45, 170, 45, 280, 55, 280, 55, 170); //tree6

	/*glColor3f(0.0, 0.5, 0.0);
	circle(65, 280, 30);
	circle(35, 280, 30);
	circle(50, 280, 30);
	circle(58, 300, 30);
	circle(43, 300, 30);*/
	//circle(50, 250, 10); //t6

	glColor3f(0.3, 0.0, 0.0);
	treebody(90, 160, 90, 400, 130, 400, 130, 160); //tree5

	glColor3f(0.3, 0.0, 0.0);
	treebody(360, 160, 360, 190, 400, 190, 400, 160); //tree3

	glColor3f(0.3, 0.0, 0.0);
	treebody(400, 200, 380, 230, 500, 350, 520, 320); //tree3-1

	glColor3f(0.3, 0.0, 0.0);
	treebody(670, 160, 670, 190, 710, 190, 710, 160); //tree1

	glColor3f(0.3, 0.0, 0.0);
	treebody(730, 190, 730, 220, 900, 220, 900, 190); //tree1-1

	glColor3f(0.0, 0.5, 0.0);
	circle(750, 380, 50);
	circle(750, 370, 50);
	circle(770, 360, 50);
	circle(790, 300, 50);
	circle(790, 300, 50);  //t2

	//circle(240, 490, 60);
	//circle(160, 490, 60);
	//circle(320, 490, 60);
	//circle(200, 550, 60);
	//circle(280, 550, 60);  //t4

	circle(110, 350, 40);
	circle(70, 350, 40);
	circle(160, 350, 40);
	circle(90, 390, 40);
	circle(130, 390, 40);  //t5

	circle(900, 200, 50);
	circle(900, 250, 50);
	circle(900, 150, 50);
	circle(920, 225, 50);
	circle(920, 175, 50); //t1

	circle(480, 380, 50);
	circle(490, 350, 50);
	circle(500, 360, 50);
	circle(520, 300, 50);
	circle(540, 300, 50); //t3
}
void drawobject5() {
	glColor3f(0.3, 0.0, 0.0);
	treebody(540, 160, 540, 190, 580, 190, 580, 160); //tree2 

	glColor3f(0.3, 0.0, 0.0);
	treebody(600, 200, 580, 230, 800, 350, 800, 320); //tree2-1

	glColor3f(0.3, 0.0, 0.0);
	treebody(220, 160, 220, 190, 260, 190, 260, 160); //tree4

	//glColor3f(0.3, 0.0, 0.0);
	//treebody(270, 200, 240, 220, 470, 310, 460, 280); //tree4-1

	//glColor3f(0.3, 0.0, 0.0);
	//treebody(45, 170, 45, 280, 55, 280, 55, 170); //tree6

	/*glColor3f(0.0, 0.5, 0.0);
	circle(65, 280, 30);
	circle(35, 280, 30);
	circle(50, 280, 30);
	circle(58, 300, 30);
	circle(43, 300, 30);*/
	//circle(50, 250, 10); //t6

	glColor3f(0.3, 0.0, 0.0);
	treebody(90, 160, 90, 400, 130, 400, 130, 160); //tree5

	glColor3f(0.3, 0.0, 0.0);
	treebody(360, 160, 360, 190, 400, 190, 400, 160); //tree3

	glColor3f(0.3, 0.0, 0.0);
	treebody(400, 200, 380, 230, 500, 350, 520, 320); //tree3-1

	glColor3f(0.3, 0.0, 0.0);
	treebody(670, 160, 670, 190, 710, 190, 710, 160); //tree1

	glColor3f(0.3, 0.0, 0.0);
	treebody(730, 190, 730, 220, 900, 220, 900, 190); //tree1-1



	glColor3f(0.0, 0.5, 0.0);
	circle(750, 380, 50);
	circle(750, 370, 50);
	circle(770, 360, 50);
	circle(790, 300, 50);
	circle(790, 300, 50);  //t2 

	/*glColor3f(0.0, 0.5, 0.0);
	circle(440, 230, 60);
	circle(440, 320, 60);
	circle(440, 250, 60);
	circle(420, 300, 60);
	circle(420, 350, 60); */ //t4

	circle(110, 350, 40);
	circle(70, 350, 40);
	circle(160, 350, 40);
	circle(90, 390, 40);
	circle(130, 390, 40);  //t5

	circle(900, 200, 50);
	circle(900, 250, 50);
	circle(900, 150, 50);
	circle(920, 225, 50);
	circle(920, 175, 50); //t1

	circle(480, 380, 50);
	circle(490, 350, 50);
	circle(500, 360, 50);
	circle(520, 300, 50);
	circle(540, 300, 50); //t3 
}

void drawobject6() {
	glColor3f(0.3, 0.0, 0.0);
	treebody(540, 160, 540, 190, 580, 190, 580, 160); //tree2 

	glColor3f(0.3, 0.0, 0.0);
	treebody(600, 200, 580, 230, 800, 350, 800, 320); //tree2-1

	glColor3f(0.3, 0.0, 0.0);
	treebody(220, 160, 220, 190, 260, 190, 260, 160); //tree4

	//glColor3f(0.3, 0.0, 0.0);
	//treebody(270, 200, 240, 220, 470, 310, 460, 280); //tree4-1

	//glColor3f(0.3, 0.0, 0.0);
	//treebody(45, 170, 45, 280, 55, 280, 55, 170); //tree6

	/*glColor3f(0.0, 0.5, 0.0);
	circle(65, 280, 30);
	circle(35, 280, 30);
	circle(50, 280, 30);
	circle(58, 300, 30);
	circle(43, 300, 30);*/
	//circle(50, 250, 10); //t6

	glColor3f(0.3, 0.0, 0.0);
	treebody(90, 160, 90, 300, 130, 300, 130, 160); //tree5
	//glColor3f(0.3, 0.0, 0.0);
	//treebody(140, 200, 130, 220, 230, 310, 230, 280);

	glColor3f(0.3, 0.0, 0.0);
	treebody(360, 160, 360, 190, 400, 190, 400, 160); //tree3

	glColor3f(0.3, 0.0, 0.0);
	treebody(400, 200, 380, 230, 500, 350, 520, 320); //tree3-1

	glColor3f(0.3, 0.0, 0.0);
	treebody(670, 160, 670, 190, 710, 190, 710, 160); //tree1

	glColor3f(0.3, 0.0, 0.0);
	treebody(730, 190, 730, 220, 900, 220, 900, 190); //tree1-1



	glColor3f(0.0, 0.5, 0.0);
	circle(750, 380, 50);
	circle(750, 370, 50);
	circle(770, 360, 50);
	circle(790, 300, 50);
	circle(790, 300, 50);  //t2 

	/*glColor3f(0.0, 0.5, 0.0);
	circle(440, 230, 60);
	circle(440, 320, 60);
	circle(440, 250, 60);
	circle(420, 300, 60);
	circle(420, 350, 60);*/  //t4

	/*circle(230, 270, 40);
	circle(230, 320, 40);
	circle(230, 250, 40);
	circle(200, 300, 40);
	circle(200, 350, 40);*/  //t5

	circle(900, 200, 50);
	circle(900, 250, 50);
	circle(900, 150, 50);
	circle(920, 225, 50);
	circle(920, 175, 50); //t1

	circle(480, 380, 50);
	circle(490, 350, 50);
	circle(500, 360, 50);
	circle(520, 300, 50);
	circle(540, 300, 50); //t3 
}
void drawobject7() {
	glColor3f(0.3, 0.0, 0.0);
	treebody(540, 160, 540, 190, 580, 190, 580, 160); //tree2

	glColor3f(0.3, 0.0, 0.0);
	treebody(600, 200, 580, 230, 800, 350, 800, 320); //tree2-1

	glColor3f(0.3, 0.0, 0.0);
	treebody(220, 160, 220, 300, 260, 300, 260, 160); //tree4

	/*glColor3f(0.3, 0.0, 0.0);
	treebody(220, 160, 220, 580, 260, 580, 260, 160); //tree4

	glColor3f(0.0, 0.5, 0.0);
	circle(240, 490, 60);
	circle(160, 490, 60);
	circle(320, 490, 60);
	circle(200, 550, 60);
	circle(280, 550, 60);*/

	//glColor3f(0.3, 0.0, 0.0);
	//treebody(45, 170, 45, 280, 55, 280, 55, 170); //tree6

	/*glColor3f(0.0, 0.5, 0.0);
	circle(65, 280, 30);
	circle(35, 280, 30);
	circle(50, 280, 30);
	circle(58, 300, 30);
	circle(43, 300, 30);*/
	//circle(50, 250, 10); //t6

	glColor3f(0.3, 0.0, 0.0);
	treebody(90, 160, 90, 400, 130, 400, 130, 160); //tree5

	glColor3f(0.3, 0.0, 0.0);
	treebody(360, 160, 360, 190, 400, 190, 400, 160); //tree3

	glColor3f(0.3, 0.0, 0.0);
	treebody(400, 200, 380, 230, 500, 350, 520, 320); //tree3-1

	glColor3f(0.3, 0.0, 0.0);
	treebody(670, 160, 670, 190, 710, 190, 710, 160); //tree1

	glColor3f(0.3, 0.0, 0.0);
	treebody(730, 190, 730, 220, 900, 220, 900, 190); //tree1-1

	glColor3f(0.0, 0.5, 0.0);
	circle(750, 380, 50);
	circle(750, 370, 50);
	circle(770, 360, 50);
	circle(790, 300, 50);
	circle(790, 300, 50);  //t2

	//circle(240, 490, 60);
	//circle(160, 490, 60);
	//circle(320, 490, 60);
	//circle(200, 550, 60);
	//circle(280, 550, 60);  //t4

	circle(110, 350, 40);
	circle(70, 350, 40);
	circle(160, 350, 40);
	circle(90, 390, 40);
	circle(130, 390, 40);  //t5

	circle(900, 200, 50);
	circle(900, 250, 50);
	circle(900, 150, 50);
	circle(920, 225, 50);
	circle(920, 175, 50); //t1

	circle(480, 380, 50);
	circle(490, 350, 50);
	circle(500, 360, 50);
	circle(520, 300, 50);
	circle(540, 300, 50); //t3
}
void drawobject8() {
	glColor3f(0.3, 0.0, 0.0);
	treebody(540, 160, 540, 190, 580, 190, 580, 160); //tree2 

	glColor3f(0.3, 0.0, 0.0);
	treebody(600, 200, 580, 230, 800, 350, 800, 320); //tree2-1

	glColor3f(0.3, 0.0, 0.0);
	treebody(220, 160, 220, 190, 260, 190, 260, 160); //tree4

	glColor3f(0.3, 0.0, 0.0);
	treebody(270, 200, 240, 220, 470, 310, 460, 280); //tree4-1

	//glColor3f(0.3, 0.0, 0.0);
	//treebody(45, 170, 45, 280, 55, 280, 55, 170); //tree6

	/*glColor3f(0.0, 0.5, 0.0);
	circle(65, 280, 30);
	circle(35, 280, 30);
	circle(50, 280, 30);
	circle(58, 300, 30);
	circle(43, 300, 30);*/
	//circle(50, 250, 10); //t6

	glColor3f(0.3, 0.0, 0.0);
	treebody(90, 160, 90, 300, 130, 300, 130, 160); //tree5
	glColor3f(0.3, 0.0, 0.0);
	treebody(140, 200, 130, 220, 230, 310, 230, 280);

	glColor3f(0.3, 0.0, 0.0);
	treebody(360, 160, 360, 190, 400, 190, 400, 160); //tree3

	glColor3f(0.3, 0.0, 0.0);
	treebody(400, 200, 380, 230, 500, 350, 520, 320); //tree3-1

	glColor3f(0.3, 0.0, 0.0);
	treebody(670, 160, 670, 190, 710, 190, 710, 160); //tree1

	glColor3f(0.3, 0.0, 0.0);
	treebody(730, 190, 730, 220, 900, 220, 900, 190); //tree1-1



	glColor3f(0.0, 0.5, 0.0);
	circle(750, 380, 50);
	circle(750, 370, 50);
	circle(770, 360, 50);
	circle(790, 300, 50);
	circle(790, 300, 50);  //t2 

	glColor3f(0.0, 0.5, 0.0);
	circle(440, 230, 60);
	circle(440, 320, 60);
	circle(440, 250, 60);
	circle(420, 300, 60);
	circle(420, 350, 60);  //t4

	circle(230, 270, 40);
	circle(230, 320, 40);
	circle(230, 250, 40);
	circle(200, 300, 40);
	circle(200, 350, 40);  //t5

	circle(900, 200, 50);
	circle(900, 250, 50);
	circle(900, 150, 50);
	circle(920, 225, 50);
	circle(920, 175, 50); //t1

	circle(480, 380, 50);
	circle(490, 350, 50);
	circle(500, 360, 50);
	circle(520, 300, 50);
	circle(540, 300, 50); //t3 
}
void smallpieces() {
	glColor3f(0.3, 0.0, 0.0);
	treebody(540, 160, 540, 190, 580, 190, 580, 160);//tree2

	glColor3f(0.3, 0.0, 0.0);
	treebody(670, 160, 670, 190, 710, 190, 710, 160);//tree1

	glColor3f(0.3, 0.0, 0.0);
	treebody(360, 160, 360, 190, 400, 190, 400, 160);//tree3

}
void smallpieces1() {
	glColor3f(0.3, 0.0, 0.0);
	treebody(90, 160, 90, 280, 130, 280, 130, 160);

	glColor3f(0.3, 0.0, 0.0);
	treebody(220, 160, 220, 280, 260, 280, 260, 160);

}

void houses() {
	//home front side
	glColor3f(1.0, .7, .5);
	glBegin(GL_POLYGON);
	glVertex2f(880, 360);
	glVertex2f(876, 400);
	glVertex2f(876, 400);
	glVertex2f(955, 390);
	glVertex2f(960, 340);
	glEnd();

	//home front side
	glColor3f(1.0, .7, .5);
	glBegin(GL_POLYGON);
	glVertex2f(880, 360);
	glVertex2f(876, 400);
	glVertex2f(955, 390);
	glVertex2f(960, 340);
	glEnd();

	//home top
	glColor3f(1.0, 1.0, .2);
	glBegin(GL_POLYGON);
	glVertex2f(867, 400);
	glVertex2f(881, 435);
	glVertex2f(974, 435);
	glVertex2f(952, 384);
	glEnd();

	//home right
	glColor3f(1.0, .7, .5);
	glBegin(GL_POLYGON);
	glVertex2f(960, 340);
	glVertex2f(955, 390);
	glVertex2f(974, 435);
	glVertex2f(996, 404);
	glVertex2f(996, 350);
	glEnd();

	//left window
	/*glColor3f(1.0, 0.0, .2);
	glBegin(GL_POLYGON);
	glVertex2f(988, 370);
	glVertex2f(988, 380);
	glVertex2f(998, 380);
	glVertex2f(998, 370);
	glEnd();*/

	//door
	glColor3f(1.0, 0.0, .2);
	glBegin(GL_POLYGON);
	glVertex2f(908, 352);
	glVertex2f(908, 380);
	glVertex2f(920, 380);
	glVertex2f(920, 352);
	glEnd();

	//right window
	glColor3f(1.0, 0.0, .2);
	glBegin(GL_POLYGON);
	glVertex2f(934, 365);
	glVertex2f(934, 375);
	glVertex2f(944, 375);
	glVertex2f(944, 365);
	glEnd();

	//most right window
	//left window
	glColor3f(1.0, 0.0, .2);
	glBegin(GL_POLYGON);
	glVertex2f(973, 372);
	glVertex2f(973, 386);
	glVertex2f(987, 386);
	glVertex2f(987, 372);
	glEnd();


	//home front side
	glColor3f(0.5, .7, 1.0);
	glBegin(GL_POLYGON);
	glVertex2f(880, 260);
	glVertex2f(876, 300);
	glVertex2f(955, 290);
	glVertex2f(960, 240);
	glEnd();


	//home top
	glColor3f(1.0, 1.0, .2);
	glBegin(GL_POLYGON);
	glVertex2f(867, 300);
	glVertex2f(881, 335);
	glVertex2f(974, 335);
	glVertex2f(952, 284);
	glEnd();


	//home right
	glColor3f(0.5, .7, 1.0);
	glBegin(GL_POLYGON);
	glVertex2f(960, 240);
	glVertex2f(955, 290);
	glVertex2f(974, 335);
	glVertex2f(996, 304);
	glVertex2f(996, 250);
	glEnd();


	//left window
	/*glColor3f(1.0, 0.0, .2);
	glBegin(GL_POLYGON);
	glVertex2f(988, 270);
	glVertex2f(988, 280);
	glVertex2f(998, 280);
	glVertex2f(998, 270);
	glEnd();*/




	//door
	glColor3f(1.0, 0.0, .2);
	glBegin(GL_POLYGON);
	glVertex2f(908, 252);
	glVertex2f(908, 280);
	glVertex2f(920, 280);
	glVertex2f(920, 252);
	glEnd();

	glColor3f(1.0, 0.0, .2);
	glBegin(GL_POLYGON);
	glVertex2f(934, 265);
	glVertex2f(934, 275);
	glVertex2f(944, 275);
	glVertex2f(944, 265);
	glEnd();



	glColor3f(1.0, 0.0, .2);
	glBegin(GL_POLYGON);
	glVertex2f(973, 272);
	glVertex2f(973, 286);
	glVertex2f(987, 286);
	glVertex2f(987, 272);
	glEnd();
	glutPostRedisplay();
}




float theta = 0.0;

void drawTreeUp1()
{
	glColor3f(0.3, 0.0, 0.0);
	glBegin(GL_POLYGON);
	glVertex2f(670, 160);
	glVertex2f(670, 400);
	glVertex2f(710, 400);
	glVertex2f(710, 160);
	glEnd();

	glColor3f(0.0, 0.5, 0.0);
	circle(690, 350, 50);
	circle(640, 350, 50);
	circle(740, 350, 50);
	circle(670, 390, 50);
	circle(710, 390, 50);
}


void drawTreeUp2()
{
	glColor3f(0.3, 0.0, 0.0);
	treebody(540, 160, 540, 580, 580, 580, 580, 160);

	glColor3f(0.0, 0.5, 0.0);
	circle(560, 490, 50);//midddle tree
	circle(480, 490, 50);
	circle(640, 490, 50);
	circle(520, 550, 50);
	circle(600, 550, 50);
}
void drawTreeUp3() {
	glColor3f(0.3, 0.0, 0.0);
	treebody(360, 160, 360, 400, 400, 400, 400, 160);

	glColor3f(0.0, 0.5, 0.0);
	circle(380, 350, 50);
	circle(430, 350, 50);
	circle(330, 350, 50);
	circle(355, 390, 50);
	circle(405, 390, 50);


}
void drawTreeUp4() {
	glColor3f(0.3, 0.0, 0.0);
	treebody(220, 160, 220, 580, 260, 580, 260, 160); //tree4

	glColor3f(0.0, 0.5, 0.0);
	circle(240, 490, 60);
	circle(160, 490, 60);
	circle(320, 490, 60);
	circle(200, 550, 60);
	circle(280, 550, 60);

}
void drawTreeUp5() {
	glColor3f(0.3, 0.0, 0.0);
	treebody(90, 160, 90, 400, 130, 400, 130, 160);//tree5

	glColor3f(0.0, 0.5, 0.0);
	circle(110, 350, 40);
	circle(70, 350, 40);
	circle(160, 350, 40);
	circle(90, 390, 40);
	circle(130, 390, 40);

}
void drawTreeUp6() {
	glColor3f(0.3, 0.0, 0.0);
	treebody(300, 160, 300, 580, 340, 580, 340, 160); //tree4

	glColor3f(0.0, 0.5, 0.0);
	circle(240, 490, 60);
	circle(320, 490, 60);
	circle(400, 490, 60);
	circle(280, 550, 60);
	circle(360, 550, 60);

}
void drawTreeUp7() {
	glColor3f(0.3, 0.0, 0.0);
	treebody(130, 160, 130, 400, 160, 400, 160, 160);//tree5

	glColor3f(0.0, 0.5, 0.0);
	circle(150, 350, 40);
	circle(120, 350, 40);
	circle(200, 350, 40);
	circle(140, 390, 40);
	circle(180, 390, 40);

}


void drawTreeDown1()
{
	glColor3f(0.3, 0.0, 0.0);
	glBegin(GL_POLYGON);
	glVertex2f(730, 190);
	glVertex2f(730, 220);
	glVertex2f(900, 220);
	glVertex2f(900, 190);
	glEnd();

	glColor3f(0.0, 0.5, 0.0);
	circle(900, 200, 40);
	circle(900, 250, 40);
	circle(900, 150, 40);
	circle(920, 225, 40);
	circle(920, 175, 40);
}

void drawTreeDown2() {
	glColor3f(0.3, 0.0, 0.0);
	treebody(600, 200, 580, 230, 800, 350, 800, 320); //tree2-1

	glColor3f(0.0, 0.5, 0.0);
	circle(750, 380, 50);
	circle(750, 370, 50);
	circle(770, 360, 50);
	circle(790, 300, 50);
	circle(790, 300, 50);
}

void drawTreeDown3() {
	glColor3f(0.3, 0.0, 0.0);
	treebody(400, 200, 380, 230, 500, 350, 520, 320);

	glColor3f(0.0, 0.5, 0.0);
	circle(480, 380, 50);
	circle(490, 350, 50);
	circle(500, 360, 50);
	circle(520, 300, 50);
	circle(540, 300, 50); //t3
}

void drawTreeDown4() {
	glColor3f(0.3, 0.0, 0.0);
	treebody(270, 200, 240, 220, 470, 310, 460, 280);
	//glColor3f(0.3, 0.0, 0.0);
	//treebody(260, 210, 240, 240, 360, 250, 320, 260);
	//treebody(220, 210, 180, 250, 230, 350, 280, 400);
	glColor3f(0.0, 0.5, 0.0);
	circle(440, 230, 60);
	circle(440, 320, 60);
	circle(440, 250, 60);
	circle(420, 300, 60);
	circle(420, 350, 60);
	/*glColor3f(0.0, 0.5, 0.0);
	circle(170, 175, 50);
	circle(170, 195, 50);
	circle(170, 155, 50);
	circle(160, 185, 50);
	circle(160, 165, 50);*/
}
void drawTreeDown5() {
	glColor3f(0.3, 0.0, 0.0);
	treebody(140, 200, 130, 220, 230, 310, 230, 280);

	glColor3f(0.0, 0.5, 0.0);
	circle(230, 270, 40);
	circle(230, 320, 40);
	circle(230, 250, 40);
	circle(200, 300, 40);
	circle(200, 350, 40);
}


void treefall1() {
	//glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glPushMatrix();
	//drawAxeDown(550,450);
	if (theta >= 0.0 && theta < 300.0)
	{
		drawTreeUp1();
		theta += 0.01;
	}

	else if (theta >= 300.0)
	{
		glPushMatrix();
		glTranslatef(0.0, -10.0, 0.0);
		drawTreeDown1();
		glPopMatrix();
		theta += 0.01;
		//(TEXT("Axe.wav"),  NULL, SND_FILENAME | SND_ASYNC);
	}
	/*if (theta > 100.0)
	{
		theta = 0.0;
	}*/
	//displayHelp("Press T", 1000, 100);
	glutPostRedisplay();
}

void treefall2() {
	//glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glPushMatrix();
	//drawAxeDown(550,450);
	if (theta >= 0.0 && theta < 400.0)
	{
		drawTreeUp2();
		theta += 0.2;
	}

	else if (theta >= 400.0)
	{
		glPushMatrix();
		glTranslatef(0.0, -10.0, 0.0);
		drawTreeDown2();
		glPopMatrix();
		theta += 0.2;
		//(TEXT("Axe.wav"),  NULL, SND_FILENAME | SND_ASYNC);
	}
	/*if (theta > 100.0)
	{
		theta = 0.0;
	}*/
	//displayHelp("Press T", 1000, 100);
	glutPostRedisplay();
}

void treefall3() {
	//glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glPushMatrix();
	//drawAxeDown(550,450);
	if (theta >= 0.0 && theta < 550.0)
	{
		drawTreeUp3();
		theta += 0.2;
	}

	else if (theta >= 550.0)
	{
		glPushMatrix();
		glTranslatef(0.0, -10.0, 0.0);
		drawTreeDown3();
		glPopMatrix();
		theta += 0.2;
		//(TEXT("Axe.wav"),  NULL, SND_FILENAME | SND_ASYNC);
	}
	/*if (theta > 100.0)
	{
		theta = 0.0;
	}*/
	//displayHelp("Press T", 1000, 100);
	glutPostRedisplay();
}

void treefall4() {
	//glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glPushMatrix();
	//drawAxeDown(550,450);
	if (theta >= 0.0 && theta < 100.0)
	{
		drawTreeUp4();
		theta += 0.01;
	}

	else if (theta >= 100.0)
	{
		glPushMatrix();
		glTranslatef(0.0, -10.0, 0.0);
		drawTreeDown4();
		glPopMatrix();
		theta += 0.01;
		//(TEXT("Axe.wav"),  NULL, SND_FILENAME | SND_ASYNC);
	}
	//if (theta > 100.0)
	//{
	//	theta = 0.0;
	//}
	//displayHelp("Press T", 1000, 100);
	glutPostRedisplay();
}
void treefall5() {
	//glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glPushMatrix();
	//drawAxeDown(550,450);
	if (theta >= 0.0 && theta < 100.0)
	{
		drawTreeUp5();
		theta += 0.1;
	}

	else if (theta >= 100.0)
	{
		glPushMatrix();
		//glTranslatef(0.0, -10.0, 0.0);
		drawTreeDown5();
		glPopMatrix();
		theta += 0.1;
	}
	//glutPostRedisplay();
}


void cutter(float x, float y)
{
	//Draws the face
	float radius = 35.0;
	glColor3f(1.0, 0.90, 0.85);

	glBegin(GL_POLYGON);
	for (float i = 0; i < 360; i += 0.1)
		glVertex2f(cos(i) * radius + x, sin(i) * radius + y + 150);
	glEnd();

	radius = 6.0;
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_POLYGON);
	for (float i = 0; i < 360; i++)
		glVertex2f(cos(i) * radius + x + 20, sin(i) * radius + y + 160);
	glEnd();

	radius = 3.0;
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_POLYGON);
	for (float i = 0; i < 360; i++)
		glVertex2f(cos(i) * radius + x + 20, sin(i) * radius + y + 160);
	glEnd();


	//Hair of the woodcutter
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_POLYGON);
	glVertex2f(x - 35, y + 150);
	glVertex2f(x - 35, y + 170);
	glVertex2f(x - 25, y + 195);
	glVertex2f(x + 40, y + 195);
	glVertex2f(x + 35, y + 175);
	glVertex2f(x + 20, y + 170);
	glEnd();


	//Draws the neck of the woodcutter
	glColor3f(1.0, 0.90, 0.85);
	glBegin(GL_POLYGON);
	glVertex2f(x - 10.0, y + 100.0);
	glVertex2f(x - 10.0, y + 120.0);
	glVertex2f(x + 10.0, y + 120.0);
	glVertex2f(x + 10.0, y + 100.0);
	glEnd();


	//Draws the left hand of woodcutter
	/*glBegin(GL_POLYGON);
	glVertex2f(x + 10, y + 90);
	glVertex2f(x + 10, y + 100);
	glVertex2f(x + 50, y + 85);
	glVertex2f(x + 50, y + 75);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2f(x + 50, y + 75);
	glVertex2f(x + 50, y + 85);
	glVertex2f(x + 75, y + 105);
	glVertex2f(x + 75, y + 95);
	glEnd();*/

	// Draws the left hand of woodcutter
	glBegin(GL_POLYGON);
	glVertex2f(x + 10, y + 90);
	glVertex2f(x + 10, y + 100);
	glVertex2f(x + 50, y + 85);
	glVertex2f(x + 50, y + 75);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2f(x + 50, y + 75);
	glVertex2f(x + 50, y + 85);
	glVertex2f(x + 75, y + 115);
	glVertex2f(x + 75, y + 105);
	glEnd();




	//Draws the red shirt of woodcutter
	glColor3f(0.8, 0.0, 0.0);
	glBegin(GL_POLYGON);
	glVertex2f(x - 25, y);
	glVertex2f(x - 25, y + 75);
	glVertex2f(x - 10, y + 100);
	glVertex2f(x + 10, y + 100);
	glVertex2f(x + 25, y + 75);
	glVertex2f(x + 25, y);
	glEnd();



	//Draws the left leg of the wood cutter
	glColor3f(1.0, 0.90, 0.85);
	glBegin(GL_POLYGON);
	glVertex2f(x - 15, y - 75);
	glVertex2f(x - 15, y);
	glVertex2f(x - 5, y);
	glVertex2f(x - 5, y - 75);
	glEnd();


	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_POLYGON);
	glVertex2f(x - 15, y - 75);
	glVertex2f(x - 5, y - 65);
	glVertex2f(x + 15, y - 70);
	glVertex2f(x + 15, y - 75);
	glEnd();

	//Draws the right leg of the woodcutter

	glColor3f(1.0, 0.90, 0.85);
	glBegin(GL_POLYGON);
	glVertex2f(x + 10, y - 75);
	glVertex2f(x + 10, y);
	glVertex2f(x + 20, y);
	glVertex2f(x + 20, y - 75);
	glEnd();


	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_POLYGON);
	glVertex2f(x + 10, y - 75);
	glVertex2f(x + 20, y - 65);
	glVertex2f(x + 40, y - 70);
	glVertex2f(x + 40, y - 75);
	glEnd();

	//Draws the shoes of woodcutter



	//Draws the trousers of the woodcutter
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_POLYGON);
	glVertex2f(x - 25, y);
	glVertex2f(x - 25, y + 25);
	glVertex2f(x + 25, y + 25);
	glVertex2f(x + 25, y);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2f(x - 25, y - 30);
	glVertex2f(x - 25, y);
	glVertex2f(x - 2, y);
	glVertex2f(x - 2, y - 30);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2f(x + 4, y - 30);
	glVertex2f(x + 4, y);
	glVertex2f(x + 25, y);
	glVertex2f(x + 25, y - 30);
	glEnd();



	//Draws the right hand of the woodcutter
	glColor3f(1.0, 0.90, 0.85);
	glBegin(GL_POLYGON);
	glVertex2f(x, y + 70);
	glVertex2f(x, y + 80);
	glVertex2f(x + 55, y + 65);
	glVertex2f(x + 55, y + 55);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2f(x + 55, y + 55);
	glVertex2f(x + 55, y + 65);
	glVertex2f(x + 80, y + 95);
	glVertex2f(x + 80, y + 85);
	glEnd();


	//Draws the mouth of the woodcutter
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_LINE_STRIP);
	glVertex2f(x + 25, y + 125);
	glVertex2f(x + 10, y + 125);
	glVertex2f(x + 10, y + 127);
	glEnd();

	//Draws the Nose of the woodcutter

	glBegin(GL_LINE_STRIP);
	glVertex2f(x + 32, y + 140);
	glVertex2f(x + 32, y + 150);
	glVertex2f(x + 34, y + 155);
	glEnd();

	glBegin(GL_LINE_STRIP);
	glVertex2f(x - 10, y + 160);
	glVertex2f(x - 20, y + 160);
	glVertex2f(x - 20, y + 140);
	glVertex2f(x - 10, y + 140);
	glEnd();

	glBegin(GL_LINES);
	glVertex2f(x - 20, y + 150);
	glVertex2f(x - 10, y + 150);
	glEnd();


	//Draws the axe
	glColor3f(0.8456, 0.684, 0.4424);
	glBegin(GL_POLYGON);
	glVertex2f(x - 95, y + 95);
	glVertex2f(x - 95, y + 105);
	glVertex2f(x + 95, y + 105);
	glVertex2f(x + 95, y + 95);
	glEnd();


	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_POLYGON);
	glVertex2f(x - 90, y + 65);
	glVertex2f(x - 90, y + 115);
	glVertex2f(x - 60, y + 115);
	glVertex2f(x - 60, y + 65);
	glEnd();

	//Draws the Right palm
	glColor3f(1.0, 0.90, 0.85);
	glBegin(GL_POLYGON);
	glVertex2f(x + 80, y + 85);
	glVertex2f(x + 80, y + 105);
	glVertex2f(x + 90, y + 105);
	glVertex2f(x + 90, y + 95);
	glEnd();

	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_LINES);
	glVertex2f(x + 80, y + 105);
	glVertex2f(x + 80, y + 100);
	glVertex2f(x + 82.5, y + 105);
	glVertex2f(x + 82.5, y + 100);
	glVertex2f(x + 85, y + 105);
	glVertex2f(x + 85, y + 100);
	glVertex2f(x + 87, y + 105);
	glVertex2f(x + 87, y + 100);
	glVertex2f(x + 89.5, y + 105);
	glVertex2f(x + 89.5, y + 100);
	glEnd();

	//Draws the left palm
	glColor3f(1.0, 0.90, 0.85);
	glBegin(GL_POLYGON);
	glVertex2f(x + 65, y + 95);
	glVertex2f(x + 65, y + 105);
	glVertex2f(x + 75, y + 105);
	glVertex2f(x + 75, y + 95);
	glEnd();

	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_LINES);
	glVertex2f(x + 65, y + 105);
	glVertex2f(x + 65, y + 100);
	glVertex2f(x + 67.5, y + 105);
	glVertex2f(x + 67.5, y + 100);
	glVertex2f(x + 70, y + 105);
	glVertex2f(x + 70, y + 100);
	glVertex2f(x + 72.5, y + 105);
	glVertex2f(x + 72.5, y + 100);
	glVertex2f(x + 74.5, y + 105);
	glVertex2f(x + 74.5, y + 100);
	glEnd();

}
void cutter2(float x, float y)
{
	//Draws the face
	float radius = 35.0;
	glColor3f(1.0, 0.90, 0.85);

	glBegin(GL_POLYGON);
	for (float i = 0; i < 360; i += 0.1)
		glVertex2f(cos(i) * radius + x, sin(i) * radius + y + 150);
	glEnd();

	radius = 6.0;
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_POLYGON);
	for (float i = 0; i < 360; i++)
		glVertex2f(cos(i) * radius + x + 20, sin(i) * radius + y + 160);
	glEnd();

	radius = 3.0;
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_POLYGON);
	for (float i = 0; i < 360; i++)
		glVertex2f(cos(i) * radius + x + 20, sin(i) * radius + y + 160);
	glEnd();


	//Hair of the woodcutter
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_POLYGON);
	glVertex2f(x - 35, y + 150);
	glVertex2f(x - 35, y + 170);
	glVertex2f(x - 25, y + 195);
	glVertex2f(x + 40, y + 195);
	glVertex2f(x + 35, y + 175);
	glVertex2f(x + 20, y + 170);
	glEnd();


	//Draws the neck of the woodcutter
	glColor3f(1.0, 0.90, 0.85);
	glBegin(GL_POLYGON);
	glVertex2f(x - 10.0, y + 100.0);
	glVertex2f(x - 10.0, y + 120.0);
	glVertex2f(x + 10.0, y + 120.0);
	glVertex2f(x + 10.0, y + 100.0);
	glEnd();


	//Draws the left hand of woodcutter
	/*glBegin(GL_POLYGON);
	glVertex2f(x + 10, y + 90);
	glVertex2f(x + 10, y + 100);
	glVertex2f(x + 50, y + 85);
	glVertex2f(x + 50, y + 75);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2f(x + 50, y + 75);
	glVertex2f(x + 50, y + 85);
	glVertex2f(x + 75, y + 105);
	glVertex2f(x + 75, y + 95);
	glEnd();*/

	// Draws the left hand of woodcutter
	glBegin(GL_POLYGON);
	glVertex2f(x + 10, y + 90);
	glVertex2f(x + 10, y + 100);
	glVertex2f(x + 50, y + 85);
	glVertex2f(x + 50, y + 75);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2f(x + 50, y + 75);
	glVertex2f(x + 50, y + 85);
	glVertex2f(x + 75, y + 115);
	glVertex2f(x + 75, y + 105);
	glEnd();




	//Draws the red shirt of woodcutter
	glColor3f(0.8, 0.0, 0.0);
	glBegin(GL_POLYGON);
	glVertex2f(x - 25, y);
	glVertex2f(x - 25, y + 75);
	glVertex2f(x - 10, y + 100);
	glVertex2f(x + 10, y + 100);
	glVertex2f(x + 25, y + 75);
	glVertex2f(x + 25, y);
	glEnd();



	//Draws the left leg of the wood cutter
	glColor3f(1.0, 0.90, 0.85);
	glBegin(GL_POLYGON);
	glVertex2f(x - 15, y - 75);
	glVertex2f(x - 15, y);
	glVertex2f(x - 5, y);
	glVertex2f(x - 5, y - 75);
	glEnd();


	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_POLYGON);
	glVertex2f(x - 15, y - 75);
	glVertex2f(x - 5, y - 65);
	glVertex2f(x + 15, y - 70);
	glVertex2f(x + 15, y - 75);
	glEnd();

	//Draws the right leg of the woodcutter

	glColor3f(1.0, 0.90, 0.85);
	glBegin(GL_POLYGON);
	glVertex2f(x + 10, y - 75);
	glVertex2f(x + 10, y);
	glVertex2f(x + 20, y);
	glVertex2f(x + 20, y - 75);
	glEnd();


	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_POLYGON);
	glVertex2f(x + 10, y - 75);
	glVertex2f(x + 20, y - 65);
	glVertex2f(x + 40, y - 70);
	glVertex2f(x + 40, y - 75);
	glEnd();

	//Draws the shoes of woodcutter



	//Draws the trousers of the woodcutter
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_POLYGON);
	glVertex2f(x - 25, y);
	glVertex2f(x - 25, y + 25);
	glVertex2f(x + 25, y + 25);
	glVertex2f(x + 25, y);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2f(x - 25, y - 30);
	glVertex2f(x - 25, y);
	glVertex2f(x - 2, y);
	glVertex2f(x - 2, y - 30);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2f(x + 4, y - 30);
	glVertex2f(x + 4, y);
	glVertex2f(x + 25, y);
	glVertex2f(x + 25, y - 30);
	glEnd();



	//Draws the right hand of the woodcutter
	glColor3f(1.0, 0.90, 0.85);
	glBegin(GL_POLYGON);
	glVertex2f(x, y + 70);
	glVertex2f(x, y + 80);
	glVertex2f(x + 55, y + 65);
	glVertex2f(x + 55, y + 55);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2f(x + 55, y + 55);
	glVertex2f(x + 55, y + 65);
	glVertex2f(x + 80, y + 95);
	glVertex2f(x + 80, y + 85);
	glEnd();


	//Draws the mouth of the woodcutter
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_LINE_STRIP);
	glVertex2f(x + 25, y + 125);
	glVertex2f(x + 10, y + 125);
	glVertex2f(x + 10, y + 127);
	glEnd();

	//Draws the Nose of the woodcutter

	glBegin(GL_LINE_STRIP);
	glVertex2f(x + 32, y + 140);
	glVertex2f(x + 32, y + 150);
	glVertex2f(x + 34, y + 155);
	glEnd();

	glBegin(GL_LINE_STRIP);
	glVertex2f(x - 10, y + 160);
	glVertex2f(x - 20, y + 160);
	glVertex2f(x - 20, y + 140);
	glVertex2f(x - 10, y + 140);
	glEnd();

	glBegin(GL_LINES);
	glVertex2f(x - 20, y + 150);
	glVertex2f(x - 10, y + 150);
	glEnd();


	//Draws the axe
	/*glColor3f(0.8456, 0.684, 0.4424);
	glBegin(GL_POLYGON);
	glVertex2f(x - 95, y + 95);
	glVertex2f(x - 95, y + 105);
	glVertex2f(x + 95, y + 105);
	glVertex2f(x + 95, y + 95);
	glEnd();*/


	/*glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_POLYGON);
	glVertex2f(x - 90, y + 65);
	glVertex2f(x - 90, y + 115);
	glVertex2f(x - 60, y + 115);
	glVertex2f(x - 60, y + 65);
	glEnd();*/

	//Draws the Right palm
	glColor3f(1.0, 0.90, 0.85);
	glBegin(GL_POLYGON);
	glVertex2f(x + 80, y + 85);
	glVertex2f(x + 80, y + 105);
	glVertex2f(x + 90, y + 105);
	glVertex2f(x + 90, y + 95);
	glEnd();

	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_LINES);
	glVertex2f(x + 80, y + 105);
	glVertex2f(x + 80, y + 100);
	glVertex2f(x + 82.5, y + 105);
	glVertex2f(x + 82.5, y + 100);
	glVertex2f(x + 85, y + 105);
	glVertex2f(x + 85, y + 100);
	glVertex2f(x + 87, y + 105);
	glVertex2f(x + 87, y + 100);
	glVertex2f(x + 89.5, y + 105);
	glVertex2f(x + 89.5, y + 100);
	glEnd();

	//Draws the left palm
	glColor3f(1.0, 0.90, 0.85);
	glBegin(GL_POLYGON);
	glVertex2f(x + 65, y + 95);
	glVertex2f(x + 65, y + 105);
	glVertex2f(x + 75, y + 105);
	glVertex2f(x + 75, y + 95);
	glEnd();

	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_LINES);
	glVertex2f(x + 65, y + 105);
	glVertex2f(x + 65, y + 100);
	glVertex2f(x + 67.5, y + 105);
	glVertex2f(x + 67.5, y + 100);
	glVertex2f(x + 70, y + 105);
	glVertex2f(x + 70, y + 100);
	glVertex2f(x + 72.5, y + 105);
	glVertex2f(x + 72.5, y + 100);
	glVertex2f(x + 74.5, y + 105);
	glVertex2f(x + 74.5, y + 100);
	glEnd();

}
void drawAxeUp(float x, float y)
{
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_POLYGON);
	glVertex2f(x + 250, y + 330);
	glVertex2f(x + 285, y + 345);
	glVertex2f(x + 310, y + 315);
	glVertex2f(x + 290, y + 295);
	glEnd();

	glColor3f(0.8456, 0.684, 0.4424);
	glBegin(GL_POLYGON);
	glVertex2f(x + 180, y + 300);
	glVertex2f(x + 180, y + 310);
	glVertex2f(x + 285, y + 340);
	glVertex2f(x + 285, y + 330);
	glEnd();
}
void drawAxeUp1(float x, float y)
{
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_POLYGON);
	glVertex2f(x + 110, y + 320);
	glVertex2f(x + 135, y + 325);
	glVertex2f(x + 160, y + 295);
	glVertex2f(x + 150, y + 275);
	glEnd();

	glColor3f(0.8456, 0.684, 0.4424);
	glBegin(GL_POLYGON);
	glVertex2f(x + 70, y + 290);
	glVertex2f(x + 70, y + 300);
	glVertex2f(x + 145, y + 330);
	glVertex2f(x + 145, y + 320);
	glEnd();
}

void drawAxeDown(float x, float y)
{
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_POLYGON);
	glVertex2f(x + 240, y + 295);
	glVertex2f(x + 250, y + 325);
	glVertex2f(x + 260, y + 325);
	glVertex2f(x + 265, y + 295);
	glEnd();

	glColor3f(0.8456, 0.684, 0.4424);
	glBegin(GL_POLYGON);
	glVertex2f(x + 180, y + 310);
	glVertex2f(x + 180, y + 320);
	glVertex2f(x + 265, y + 320);
	glVertex2f(x + 265, y + 310);
	glEnd();
}
void drawAxeDown1(float x, float y)
{
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_POLYGON);
	glVertex2f(x + 120, y + 285);
	glVertex2f(x + 120, y + 315);
	glVertex2f(x + 140, y + 315);
	glVertex2f(x + 145, y + 285);
	glEnd();

	glColor3f(0.8456, 0.684, 0.4424);
	glBegin(GL_POLYGON);
	glVertex2f(x + 60, y + 300);
	glVertex2f(x + 60, y + 310);
	glVertex2f(x + 145, y + 310);
	glVertex2f(x + 145, y + 300);
	glEnd();
}

void mydisplaySecondWindow1()
{
	if (j < 20)
	{
		cutter(110 + j, 200 + yMove);
		j += 0.1;
		//displayHelp("A to Stop", 1000, 100);
		//displayHelp("W to up", 1000, 70);
		//displayHelp("S to down", 1000, 40);
	}
	else
	{
		cutter(110 + j, 200 + yMove);
		//displayHelp("D to Move", 1000, 100);
		//displayHelp("W to up", 1000, 70);
		//displayHelp("S to down", 1000, 40);
	}
	glutPostRedisplay();

}
void mydisplaySecondWindow2()
{
	if (j < 20)
	{
		cutter(70 + j, 200 + yMove);
		j += 0.1;
		//displayHelp("A to Stop", 1000, 100);
		//displayHelp("W to up", 1000, 70);
		//displayHelp("S to down", 1000, 40);
	}
	else
	{
		cutter(70 + j, 200 + yMove);
		//displayHelp("D to Move", 1000, 100);
		//displayHelp("W to up", 1000, 70);
		//displayHelp("S to down", 1000, 40);
	}
	glutPostRedisplay();

}

void mydisplaySecondWindow3()
{
	if (j < 1200)
	{
		cutter(200 + j, 200 + yMove);
		j += 0.1;
		//displayHelp("A to Stop", 1000, 100);
		//displayHelp("W to up", 1000, 70);
		//displayHelp("S to down", 1000, 40);
	}
	else
	{
		cutter(200 + j, 200 + yMove);
		//displayHelp("D to Move", 1000, 100);
		//displayHelp("W to up", 1000, 70);
		//displayHelp("S to down", 1000, 40);
	}
	glutPostRedisplay();

}


void axe() {
	i = 0;
	//mydisplaySecondWindow();
	glPushMatrix();
	//drawAxeDown(550,450);
	if (theta1 >= 0.0 && theta1 < 50.0)
	{
		drawAxeUp(0, 0);
		theta1 += 1.0;
	}
	else if (theta1 >= 50.0)
	{
		glPushMatrix();
		glTranslatef(0.0, -10.0, 0.0);
		drawAxeDown(0, 0);
		glPopMatrix();
		theta1 += 1.0;
		//(TEXT("Axe.wav"),  NULL, SND_FILENAME | SND_ASYNC);
	}
	if (theta1 > 100.0)
	{
		theta1 = 1.0;
	}
	//displayHelp("Press T", 1000, 100);
	glutPostRedisplay();
}

void axe1() {
	i = 0;


	//mydisplaySecondWindow();
	glPushMatrix();
	//drawAxeDown(550,450);
	if (theta1 >= 0.0 && theta1 < 50.0)
	{
		drawAxeUp1(0, 0);
		theta1 += 1.0;
	}
	else if (theta1 >= 50.0)
	{
		glPushMatrix();
		glTranslatef(0.0, -10.0, 0.0);
		drawAxeDown1(0, 0);
		glPopMatrix();
		theta1 += 1.0;
		//(TEXT("Axe.wav"),  NULL, SND_FILENAME | SND_ASYNC);
	}
	if (theta1 > 100.0)
	{
		theta1 = 1.0;
	}
	//displayHelp("Press T", 1000, 100);
	glutPostRedisplay();
}
void axe2() {
	i = 0;
	//mydisplaySecondWindow();
	glPushMatrix();
	//drawAxeDown(550,450);
	if (theta2 >= 0.0 && theta2 < 50.0)
	{
		drawAxeUp1(0, 0);
		theta2 += 1.0;
	}
	else if (theta2 >= 50.0)
	{
		glPushMatrix();
		glTranslatef(0.0, -10.0, 0.0);
		drawAxeDown1(0, 0);
		glPopMatrix();
		theta2 += 1.0;
		//(TEXT("Axe.wav"),  NULL, SND_FILENAME | SND_ASYNC);
	}
	/*if (theta2 > 100.0)
	{
		theta2 = 1.0;
	}*/
	//displayHelp("Press T", 1000, 100);
	glutPostRedisplay();
}
void truvk(int x) {
	if (tb1 > x) {
		//glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glColor3f(0.1, 0.5, 0.8);
		glBegin(GL_POLYGON);
		glVertex2f(truckfront, 160);
		glVertex2f(truckfront, 200);
		glVertex2f(truckback, 200);
		glVertex2f(truckback, 160);
		glEnd();

		/*glColor3f(0.0, 0.0, 0.0);
		glBegin(GL_POLYGON);
		glVertex2f(t1, 160);
		glVertex2f(t1, 300);
		glVertex2f(t2, 300);
		glVertex2f(t2, 160);
		glEnd();*/

		glColor3f(0.0, 0.0, 0.0);
		glBegin(GL_POLYGON);
		glVertex2f(t3, 160);
		glVertex2f(t3, 300);
		glVertex2f(t4, 300);
		glVertex2f(t4, 160);
		glEnd();

		glColor3f(0.0, 0.0, 0.0);
		glBegin(GL_POLYGON);
		glVertex2f(t5, 160);
		glVertex2f(t5, 300);
		glVertex2f(t6, 300);
		glVertex2f(t6, 160);
		glEnd();

		glColor3f(0.0, 0.0, 0.0);
		glBegin(GL_POLYGON);
		glVertex2f(t7, 160);
		glVertex2f(t7, 300);
		glVertex2f(t8, 300);
		glVertex2f(t8, 160);
		glEnd();

		/*glColor3f(0.0, 0.0, 0.0);
		glBegin(GL_POLYGON);
		glVertex2f(t9, 160);
		glVertex2f(t9, 300);
		glVertex2f(t10, 300);
		glVertex2f(t10, 160);
		glEnd();*/

		glColor3f(0.0, 0.0, 0.0);
		circle(t11, 155, 30);
		glColor3f(0.0, 0.0, 0.0);
		circle(t12, 155, 30);
		glColor3f(0.0, 0.0, 0.0);
		circle(t13, 155, 30);
		//glColor3f(0.0, 0.0, 0.0);
		//circle(t14, 155, 30);
		glColor3f(0.0, 0.0, 1.0);
		//treebody(250, 160, 250, 300, 300, 300, 300, 160);
		glBegin(GL_POLYGON);
		glVertex2f(tb1, 200);
		glVertex2f(tb1, 280);
		glVertex2f(tb2, 350);
		glVertex2f(tb3, 350);
		glVertex2f(tb3, 200);
		glVertex2f(tb2, 200);
		glEnd();
		glColor3f(1.0, 1.0, 1.0);
		glBegin(GL_POLYGON);
		glVertex2f(tw1, 280);
		glVertex2f(tw2, 320);
		glVertex2f(tw3, 320);
		glVertex2f(tw3, 280);
		//glVertex2f(400, 200);
		//glVertex2f(300, 200);
		glEnd();
		if (z == 1)
		{
			truckfront = truckfront - 1;
			truckback = truckback - 1;
			//t1 = t1 - 1;
			//t2 = t2 - 1;
			t3 = t3 - 1;
			t4 = t4 - 1;
			t5 = t5 - 1;
			t6 = t6 - 1;
			t7 = t7 - 1;
			t8 = t8 - 1;
			//t9 = t9 - 1;
			//t10 = t10 - 1;
			t11 = t11 - 1;
			t12 = t12 - 1;
			t13 = t13 - 1;
			//t14 = t14 - 1;
			tb1 = tb1 - 1;
			tb2 = tb2 - 1;
			tb3 = tb3 - 1;
			tw1 = tw1 - 1;
			tw2 = tw2 - 1;
			tw3 = tw3 - 1;
		}

	}
	else {
		glColor3f(0.1, 0.5, 0.8);
		glBegin(GL_POLYGON);
		glVertex2f(truckfront, 160);
		glVertex2f(truckfront, 200);
		glVertex2f(truckback, 200);
		glVertex2f(truckback, 160);
		glEnd();

		/*glColor3f(0.0, 0.0, 0.0);
		glBegin(GL_POLYGON);
		glVertex2f(t1, 160);
		glVertex2f(t1, 300);
		glVertex2f(t2, 300);
		glVertex2f(t2, 160);
		glEnd();*/

		glColor3f(0.0, 0.0, 0.0);
		glBegin(GL_POLYGON);
		glVertex2f(t3, 160);
		glVertex2f(t3, 300);
		glVertex2f(t4, 300);
		glVertex2f(t4, 160);
		glEnd();

		glColor3f(0.0, 0.0, 0.0);
		glBegin(GL_POLYGON);
		glVertex2f(t5, 160);
		glVertex2f(t5, 300);
		glVertex2f(t6, 300);
		glVertex2f(t6, 160);
		glEnd();

		glColor3f(0.0, 0.0, 0.0);
		glBegin(GL_POLYGON);
		glVertex2f(t7, 160);
		glVertex2f(t7, 300);
		glVertex2f(t8, 300);
		glVertex2f(t8, 160);
		glEnd();

		/*glColor3f(0.0, 0.0, 0.0);
		glBegin(GL_POLYGON);
		glVertex2f(t9, 160);
		glVertex2f(t9, 300);
		glVertex2f(t10, 300);
		glVertex2f(t10, 160);
		glEnd();*/

		glColor3f(0.0, 0.0, 0.0);
		circle(t11, 155, 30);
		glColor3f(0.0, 0.0, 0.0);
		circle(t12, 155, 30);
		glColor3f(0.0, 0.0, 0.0);
		circle(t13, 155, 30);
		//glColor3f(0.0, 0.0, 0.0);
		//circle(t14, 155, 30);
		glColor3f(0.0, 0.0, 1.0);
		//treebody(250, 160, 250, 300, 300, 300, 300, 160);
		glBegin(GL_POLYGON);
		glVertex2f(tb1, 200);
		glVertex2f(tb1, 280);
		glVertex2f(tb2, 350);
		glVertex2f(tb3, 350);
		glVertex2f(tb3, 200);
		glVertex2f(tb2, 200);
		glEnd();
		glColor3f(1.0, 1.0, 1.0);
		glBegin(GL_POLYGON);
		glVertex2f(tw1, 280);
		glVertex2f(tw2, 320);
		glVertex2f(tw3, 320);
		glVertex2f(tw3, 280);
		//glVertex2f(400, 200);
		//glVertex2f(300, 200);
		glEnd();
		/*if (z == 1)
		{
			truckfront = truckfront - 1;
			truckback = truckback - 1;
			t1 = t1 - 1;
			t2 = t2 - 1;
			t3 = t3 - 1;
			t4 = t4 - 1;
			t5 = t5 - 1;
			t6 = t6 - 1;
			t7 = t7 - 1;
			t8 = t8 - 1;
			//t9 = t9 - 1;
			//t10 = t10 - 1;
			t11 = t11 - 1;
			t12 = t12 - 1;
			t13 = t13 - 1;
			t14 = t14 - 1;
			tb1 = tb1 - 1;
			tb2 = tb2 - 1;
			tb3 = tb3 - 1;
			tw1 = tw1 - 1;
			tw2 = tw2 - 1;
			tw3 = tw3 - 1;
		}*/

	}
	glutPostRedisplay();
	glFlush();
}

void truvk1(int x) {
	if (tb1 > x) {
		//glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glColor3f(0.1, 0.5, 0.8);
		glBegin(GL_POLYGON);
		glVertex2f(truckfront, 160);
		glVertex2f(truckfront, 200);
		glVertex2f(truckback, 200);
		glVertex2f(truckback, 160);
		glEnd();

		glColor3f(0.3, 0.0, 0.0);
		glBegin(GL_POLYGON);
		glVertex2f(t15, 200);
		glVertex2f(t15, 240);
		glVertex2f(t16, 240);
		glVertex2f(t16, 200);
		glEnd();

		glColor3f(0.0, 0.5, 0.0);
		circle(t16, 240, 40);
		circle(t11, 260, 30);
		circle(t22, 230, 30);

		/*glColor3f(0.0, 0.0, 0.0);
		glBegin(GL_POLYGON);
		glVertex2f(t1, 160);
		glVertex2f(t1, 300);
		glVertex2f(t2, 300);
		glVertex2f(t2, 160);
		glEnd();*/

		glColor3f(0.0, 0.0, 0.0);
		glBegin(GL_POLYGON);
		glVertex2f(t3, 160);
		glVertex2f(t3, 300);
		glVertex2f(t4, 300);
		glVertex2f(t4, 160);
		glEnd();

		glColor3f(0.0, 0.0, 0.0);
		glBegin(GL_POLYGON);
		glVertex2f(t5, 160);
		glVertex2f(t5, 300);
		glVertex2f(t6, 300);
		glVertex2f(t6, 160);
		glEnd();

		glColor3f(0.0, 0.0, 0.0);
		glBegin(GL_POLYGON);
		glVertex2f(t7, 160);
		glVertex2f(t7, 300);
		glVertex2f(t8, 300);
		glVertex2f(t8, 160);
		glEnd();

		/*glColor3f(0.0, 0.0, 0.0);
		glBegin(GL_POLYGON);
		glVertex2f(t9, 160);
		glVertex2f(t9, 300);
		glVertex2f(t10, 300);
		glVertex2f(t10, 160);
		glEnd();*/

		glColor3f(0.0, 0.0, 0.0);
		circle(t11, 155, 30);
		glColor3f(0.0, 0.0, 0.0);
		circle(t12, 155, 30);
		glColor3f(0.0, 0.0, 0.0);
		circle(t13, 155, 30);
		//glColor3f(0.0, 0.0, 0.0);
		//circle(t14, 155, 30);
		glColor3f(0.0, 0.0, 1.0);
		//treebody(250, 160, 250, 300, 300, 300, 300, 160);
		glBegin(GL_POLYGON);
		glVertex2f(tb1, 200);
		glVertex2f(tb1, 280);
		glVertex2f(tb2, 350);
		glVertex2f(tb3, 350);
		glVertex2f(tb3, 200);
		glVertex2f(tb2, 200);
		glEnd();
		glColor3f(1.0, 1.0, 1.0);
		glBegin(GL_POLYGON);
		glVertex2f(tw1, 280);
		glVertex2f(tw2, 320);
		glVertex2f(tw3, 320);
		glVertex2f(tw3, 280);
		//glVertex2f(400, 200);
		//glVertex2f(300, 200);
		glEnd();
		if (z == 1)
		{
			truckfront = truckfront - 1;
			truckback = truckback - 1;
			//t1 = t1 - 1;
			//t2 = t2 - 1;
			t3 = t3 - 1;
			t4 = t4 - 1;
			t5 = t5 - 1;
			t6 = t6 - 1;
			t7 = t7 - 1;
			t8 = t8 - 1;
			//t9 = t9 - 1;
			//t10 = t10 - 1;
			t11 = t11 - 1;
			t12 = t12 - 1;
			t13 = t13 - 1;
			//t14 = t14 - 1;
			t15 = t15 - 1;
			t16 = t16 - 1;
			t22 = t22 - 1;
			tb1 = tb1 - 1;
			tb2 = tb2 - 1;
			tb3 = tb3 - 1;
			tw1 = tw1 - 1;
			tw2 = tw2 - 1;
			tw3 = tw3 - 1;
		}
	}
	else {
		glColor3f(0.1, 0.5, 0.8);
		glBegin(GL_POLYGON);
		glVertex2f(truckfront, 160);
		glVertex2f(truckfront, 200);
		glVertex2f(truckback, 200);
		glVertex2f(truckback, 160);
		glEnd();

		glColor3f(0.3, 0.0, 0.0);
		glBegin(GL_POLYGON);
		glVertex2f(t15, 200);
		glVertex2f(t15, 240);
		glVertex2f(t16, 240);
		glVertex2f(t16, 200);
		glEnd();

		glColor3f(0.0, 0.5, 0.0);
		circle(t16, 240, 40);
		circle(t11, 260, 30);
		circle(t22, 230, 30);

		/*glColor3f(0.0, 0.0, 0.0);
		glBegin(GL_POLYGON);
		glVertex2f(t1, 160);
		glVertex2f(t1, 300);
		glVertex2f(t2, 300);
		glVertex2f(t2, 160);
		glEnd();*/

		glColor3f(0.0, 0.0, 0.0);
		glBegin(GL_POLYGON);
		glVertex2f(t3, 160);
		glVertex2f(t3, 300);
		glVertex2f(t4, 300);
		glVertex2f(t4, 160);
		glEnd();

		glColor3f(0.0, 0.0, 0.0);
		glBegin(GL_POLYGON);
		glVertex2f(t5, 160);
		glVertex2f(t5, 300);
		glVertex2f(t6, 300);
		glVertex2f(t6, 160);
		glEnd();

		glColor3f(0.0, 0.0, 0.0);
		glBegin(GL_POLYGON);
		glVertex2f(t7, 160);
		glVertex2f(t7, 300);
		glVertex2f(t8, 300);
		glVertex2f(t8, 160);
		glEnd();

		/*glColor3f(0.0, 0.0, 0.0);
		glBegin(GL_POLYGON);
		glVertex2f(t9, 160);
		glVertex2f(t9, 300);
		glVertex2f(t10, 300);
		glVertex2f(t10, 160);
		glEnd();*/

		glColor3f(0.0, 0.0, 0.0);
		circle(t11, 155, 30);
		glColor3f(0.0, 0.0, 0.0);
		circle(t12, 155, 30);
		glColor3f(0.0, 0.0, 0.0);
		circle(t13, 155, 30);
		//glColor3f(0.0, 0.0, 0.0);
		//circle(t14, 155, 30);
		glColor3f(0.0, 0.0, 1.0);
		//treebody(250, 160, 250, 300, 300, 300, 300, 160);
		glBegin(GL_POLYGON);
		glVertex2f(tb1, 200);
		glVertex2f(tb1, 280);
		glVertex2f(tb2, 350);
		glVertex2f(tb3, 350);
		glVertex2f(tb3, 200);
		glVertex2f(tb2, 200);
		glEnd();
		glColor3f(1.0, 1.0, 1.0);
		glBegin(GL_POLYGON);
		glVertex2f(tw1, 280);
		glVertex2f(tw2, 320);
		glVertex2f(tw3, 320);
		glVertex2f(tw3, 280);
		//glVertex2f(400, 200);
		//glVertex2f(300, 200);
		glEnd();
		/*if (z == 1)
		{
			truckfront = truckfront - 1;
			truckback = truckback - 1;
			t1 = t1 - 1;
			t2 = t2 - 1;
			t3 = t3 - 1;
			t4 = t4 - 1;
			t5 = t5 - 1;
			t6 = t6 - 1;
			t7 = t7 - 1;
			t8 = t8 - 1;
			//t9 = t9 - 1;
			//t10 = t10 - 1;
			t11 = t11 - 1;
			t12 = t12 - 1;
			t13 = t13 - 1;
			t14 = t14 - 1;
			t15 = t15 - 1;
			t16 = t16 - 1;
			t22 = t22 - 1;
			tb1 = tb1 - 1;
			tb2 = tb2 - 1;
			tb3 = tb3 - 1;
			tw1 = tw1 - 1;
			tw2 = tw2 - 1;
			tw3 = tw3 - 1;
		}*/

	}
	glutPostRedisplay();
	//glFlush();
}

void truvk2(int x) {
	if (tb1 > x) {
		//glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glColor3f(0.1, 0.5, 0.8);
		glBegin(GL_POLYGON);
		glVertex2f(truckfront, 160);
		glVertex2f(truckfront, 200);
		glVertex2f(truckback, 200);
		glVertex2f(truckback, 160);
		glEnd();

		glColor3f(0.3, 0.0, 0.0);
		glBegin(GL_POLYGON);
		glVertex2f(t15, 200);
		glVertex2f(t15, 240);
		glVertex2f(t16, 240);
		glVertex2f(t16, 200);
		glEnd();

		glColor3f(0.0, 0.5, 0.0);
		circle(t16, 240, 40);
		circle(t11, 260, 30);
		circle(t22, 230, 30);

		glColor3f(0.3, 0.0, 0.0);
		glBegin(GL_POLYGON);
		glVertex2f(t17, 220);
		glVertex2f(t18, 250);
		glVertex2f(t19, 370);
		glVertex2f(t19, 340);
		glEnd();

		//treebody(600, 200, 580, 230, 800, 350, 800, 320); //tree2-1

		glColor3f(0.0, 0.5, 0.0);
		circle(t20, 355, 50);
		circle(t20, 395, 50);
		circle(t20, 325, 50);
		circle(t21, 375, 50);
		circle(t21, 365, 50);

		/*glColor3f(0.0, 0.0, 0.0);
		glBegin(GL_POLYGON);
		glVertex2f(t1, 160);
		glVertex2f(t1, 300);
		glVertex2f(t2, 300);
		glVertex2f(t2, 160);
		glEnd();*/

		glColor3f(0.0, 0.0, 0.0);
		glBegin(GL_POLYGON);
		glVertex2f(t3, 160);
		glVertex2f(t3, 300);
		glVertex2f(t4, 300);
		glVertex2f(t4, 160);
		glEnd();

		glColor3f(0.0, 0.0, 0.0);
		glBegin(GL_POLYGON);
		glVertex2f(t5, 160);
		glVertex2f(t5, 300);
		glVertex2f(t6, 300);
		glVertex2f(t6, 160);
		glEnd();

		glColor3f(0.0, 0.0, 0.0);
		glBegin(GL_POLYGON);
		glVertex2f(t7, 160);
		glVertex2f(t7, 300);
		glVertex2f(t8, 300);
		glVertex2f(t8, 160);
		glEnd();

		/*glColor3f(0.0, 0.0, 0.0);
		glBegin(GL_POLYGON);
		glVertex2f(t9, 160);
		glVertex2f(t9, 300);
		glVertex2f(t10, 300);
		glVertex2f(t10, 160);
		glEnd();*/

		glColor3f(0.0, 0.0, 0.0);
		circle(t11, 155, 30);
		glColor3f(0.0, 0.0, 0.0);
		circle(t12, 155, 30);
		glColor3f(0.0, 0.0, 0.0);
		circle(t13, 155, 30);
		//glColor3f(0.0, 0.0, 0.0);
		//circle(t14, 155, 30);
		glColor3f(0.0, 0.0, 1.0);
		//treebody(250, 160, 250, 300, 300, 300, 300, 160);
		glBegin(GL_POLYGON);
		glVertex2f(tb1, 200);
		glVertex2f(tb1, 280);
		glVertex2f(tb2, 350);
		glVertex2f(tb3, 350);
		glVertex2f(tb3, 200);
		glVertex2f(tb2, 200);
		glEnd();
		glColor3f(1.0, 1.0, 1.0);
		glBegin(GL_POLYGON);
		glVertex2f(tw1, 280);
		glVertex2f(tw2, 320);
		glVertex2f(tw3, 320);
		glVertex2f(tw3, 280);
		//glVertex2f(400, 200);
		//glVertex2f(300, 200);
		glEnd();
		if (z == 1)
		{
			truckfront = truckfront - 1;
			truckback = truckback - 1;
			//t1 = t1 - 1;
			//t2 = t2 - 1;
			t3 = t3 - 1;
			t4 = t4 - 1;
			t5 = t5 - 1;
			t6 = t6 - 1;
			t7 = t7 - 1;
			t8 = t8 - 1;
			//t9 = t9 - 1;
			//t10 = t10 - 1;
			t11 = t11 - 1;
			t12 = t12 - 1;
			t13 = t13 - 1;
			//t14 = t14 - 1;
			t15 = t15 - 1;
			t16 = t16 - 1;
			t17 = t17 - 1;
			t18 = t18 - 1;
			t19 = t19 - 1;
			t20 = t20 - 1;
			t21 = t21 - 1;
			t22 = t22 - 1;
			tb1 = tb1 - 1;
			tb2 = tb2 - 1;
			tb3 = tb3 - 1;
			tw1 = tw1 - 1;
			tw2 = tw2 - 1;
			tw3 = tw3 - 1;
		}
	}
	else {
		glColor3f(0.1, 0.5, 0.8);
		glBegin(GL_POLYGON);
		glVertex2f(truckfront, 160);
		glVertex2f(truckfront, 200);
		glVertex2f(truckback, 200);
		glVertex2f(truckback, 160);
		glEnd();

		glColor3f(0.3, 0.0, 0.0);
		glBegin(GL_POLYGON);
		glVertex2f(t15, 200);
		glVertex2f(t15, 240);
		glVertex2f(t16, 240);
		glVertex2f(t16, 200);
		glEnd();

		glColor3f(0.0, 0.5, 0.0);
		circle(t16, 240, 40);
		circle(t11, 260, 30);
		circle(t22, 230, 30);

		/*glColor3f(0.0, 0.0, 0.0);
		glBegin(GL_POLYGON);
		glVertex2f(t1, 160);
		glVertex2f(t1, 300);
		glVertex2f(t2, 300);
		glVertex2f(t2, 160);
		glEnd();*/

		glColor3f(0.0, 0.0, 0.0);
		glBegin(GL_POLYGON);
		glVertex2f(t3, 160);
		glVertex2f(t3, 300);
		glVertex2f(t4, 300);
		glVertex2f(t4, 160);
		glEnd();

		glColor3f(0.0, 0.0, 0.0);
		glBegin(GL_POLYGON);
		glVertex2f(t5, 160);
		glVertex2f(t5, 300);
		glVertex2f(t6, 300);
		glVertex2f(t6, 160);
		glEnd();

		glColor3f(0.0, 0.0, 0.0);
		glBegin(GL_POLYGON);
		glVertex2f(t7, 160);
		glVertex2f(t7, 300);
		glVertex2f(t8, 300);
		glVertex2f(t8, 160);
		glEnd();

		/*glColor3f(0.0, 0.0, 0.0);
		glBegin(GL_POLYGON);
		glVertex2f(t9, 160);
		glVertex2f(t9, 300);
		glVertex2f(t10, 300);
		glVertex2f(t10, 160);
		glEnd();*/

		glColor3f(0.0, 0.0, 0.0);
		circle(t11, 155, 30);
		glColor3f(0.0, 0.0, 0.0);
		circle(t12, 155, 30);
		glColor3f(0.0, 0.0, 0.0);
		circle(t13, 155, 30);
		//glColor3f(0.0, 0.0, 0.0);
		//circle(t14, 155, 30);
		glColor3f(0.0, 0.0, 1.0);
		//treebody(250, 160, 250, 300, 300, 300, 300, 160);
		glBegin(GL_POLYGON);
		glVertex2f(tb1, 200);
		glVertex2f(tb1, 280);
		glVertex2f(tb2, 350);
		glVertex2f(tb3, 350);
		glVertex2f(tb3, 200);
		glVertex2f(tb2, 200);
		glEnd();
		glColor3f(1.0, 1.0, 1.0);
		glBegin(GL_POLYGON);
		glVertex2f(tw1, 280);
		glVertex2f(tw2, 320);
		glVertex2f(tw3, 320);
		glVertex2f(tw3, 280);
		//glVertex2f(400, 200);
		//glVertex2f(300, 200);
		glEnd();
		/*if (z == 1)
		{
			truckfront = truckfront - 1;
			truckback = truckback - 1;
			t1 = t1 - 1;
			t2 = t2 - 1;
			t3 = t3 - 1;
			t4 = t4 - 1;
			t5 = t5 - 1;
			t6 = t6 - 1;
			t7 = t7 - 1;
			t8 = t8 - 1;
			//t9 = t9 - 1;
			//t10 = t10 - 1;
			t11 = t11 - 1;
			t12 = t12 - 1;
			t13 = t13 - 1;
			t14 = t14 - 1;
			t15 = t15 - 1;
			t16 = t16 - 1;
			t22 = t22 - 1;
			tb1 = tb1 - 1;
			tb2 = tb2 - 1;
			tb3 = tb3 - 1;
			tw1 = tw1 - 1;
			tw2 = tw2 - 1;
			tw3 = tw3 - 1;
		}*/

	}
	glutPostRedisplay();
	//glFlush();
}


void truvk3(int x) {
	if (tb1 > x) {
		//glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		glColor3f(0.3, 0.0, 0.0);
		glBegin(GL_POLYGON);
		glVertex2f(t15, 200);
		glVertex2f(t15, 240);
		glVertex2f(t16, 240);
		glVertex2f(t16, 200);
		glEnd();

		glColor3f(0.0, 0.5, 0.0);
		circle(t16, 240, 40);
		circle(t11, 260, 30);
		circle(t22, 230, 30);




		glColor3f(0.3, 0.0, 0.0);
		glBegin(GL_POLYGON);
		glVertex2f(t17, 220);
		glVertex2f(t18, 250);
		glVertex2f(t19, 370);
		glVertex2f(t19, 340);
		glEnd();



		glColor3f(0.3, 0.0, 0.0);
		glBegin(GL_POLYGON);
		glVertex2f(t17, 200);
		glVertex2f(t18, 210);
		glVertex2f(t22, 280);
		glVertex2f(t22, 330);
		glEnd();

		glColor3f(0.0, 0.5, 0.0);
		circle(t17, 240, 40);
		circle(t13, 220, 30);
		circle(t13, 240, 30);


		glColor3f(0.1, 0.5, 0.8);
		glBegin(GL_POLYGON);
		glVertex2f(truckfront, 160);
		glVertex2f(truckfront, 200);
		glVertex2f(truckback, 200);
		glVertex2f(truckback, 160);
		glEnd();
		//treebody(600, 200, 580, 230, 800, 350, 800, 320); //tree2-1

		glColor3f(0.0, 0.5, 0.0);
		circle(t20, 355, 50);
		circle(t20, 395, 50);
		circle(t20, 325, 50);
		circle(t21, 375, 50);
		circle(t21, 365, 50);

		/*glColor3f(0.0, 0.0, 0.0);
		glBegin(GL_POLYGON);
		glVertex2f(t1, 160);
		glVertex2f(t1, 300);
		glVertex2f(t2, 300);
		glVertex2f(t2, 160);
		glEnd();*/

		glColor3f(0.0, 0.0, 0.0);
		glBegin(GL_POLYGON);
		glVertex2f(t3, 160);
		glVertex2f(t3, 300);
		glVertex2f(t4, 300);
		glVertex2f(t4, 160);
		glEnd();

		glColor3f(0.0, 0.0, 0.0);
		glBegin(GL_POLYGON);
		glVertex2f(t5, 160);
		glVertex2f(t5, 300);
		glVertex2f(t6, 300);
		glVertex2f(t6, 160);
		glEnd();

		glColor3f(0.0, 0.0, 0.0);
		glBegin(GL_POLYGON);
		glVertex2f(t7, 160);
		glVertex2f(t7, 300);
		glVertex2f(t8, 300);
		glVertex2f(t8, 160);
		glEnd();

		/*glColor3f(0.0, 0.0, 0.0);
		glBegin(GL_POLYGON);
		glVertex2f(t9, 160);
		glVertex2f(t9, 300);
		glVertex2f(t10, 300);
		glVertex2f(t10, 160);
		glEnd();*/

		glColor3f(0.0, 0.0, 0.0);
		circle(t11, 155, 30);
		glColor3f(0.0, 0.0, 0.0);
		circle(t12, 155, 30);
		glColor3f(0.0, 0.0, 0.0);
		circle(t13, 155, 30);
		//glColor3f(0.0, 0.0, 0.0);
		//circle(t14, 155, 30);
		glColor3f(0.0, 0.0, 1.0);
		//treebody(250, 160, 250, 300, 300, 300, 300, 160);
		glBegin(GL_POLYGON);
		glVertex2f(tb1, 200);
		glVertex2f(tb1, 280);
		glVertex2f(tb2, 350);
		glVertex2f(tb3, 350);
		glVertex2f(tb3, 200);
		glVertex2f(tb2, 200);
		glEnd();
		glColor3f(1.0, 1.0, 1.0);
		glBegin(GL_POLYGON);
		glVertex2f(tw1, 280);
		glVertex2f(tw2, 320);
		glVertex2f(tw3, 320);
		glVertex2f(tw3, 280);
		//glVertex2f(400, 200);
		//glVertex2f(300, 200);
		glEnd();
		if (z == 1)
		{
			truckfront = truckfront - 1;
			truckback = truckback - 1;
			//t1 = t1 - 1;
			//t2 = t2 - 1;
			t3 = t3 - 1;
			t4 = t4 - 1;
			t5 = t5 - 1;
			t6 = t6 - 1;
			t7 = t7 - 1;
			t8 = t8 - 1;
			//t9 = t9 - 1;
			//t10 = t10 - 1;
			t11 = t11 - 1;
			t12 = t12 - 1;
			t13 = t13 - 1;
			//t14 = t14 - 1;
			t15 = t15 - 1;
			t16 = t16 - 1;
			t17 = t17 - 1;
			t18 = t18 - 1;
			t19 = t19 - 1;
			t20 = t20 - 1;
			t21 = t21 - 1;
			t22 = t22 - 1;
			tb1 = tb1 - 1;
			tb2 = tb2 - 1;
			tb3 = tb3 - 1;
			tw1 = tw1 - 1;
			tw2 = tw2 - 1;
			tw3 = tw3 - 1;
		}
	}
	else {
		glColor3f(0.1, 0.5, 0.8);
		glBegin(GL_POLYGON);
		glVertex2f(truckfront, 160);
		glVertex2f(truckfront, 200);
		glVertex2f(truckback, 200);
		glVertex2f(truckback, 160);
		glEnd();

		glColor3f(0.3, 0.0, 0.0);
		glBegin(GL_POLYGON);
		glVertex2f(t15, 200);
		glVertex2f(t15, 240);
		glVertex2f(t16, 240);
		glVertex2f(t16, 200);
		glEnd();

		glColor3f(0.0, 0.5, 0.0);
		circle(t16, 240, 40);
		circle(t11, 260, 30);
		circle(t22, 230, 30);

		/*glColor3f(0.0, 0.0, 0.0);
		glBegin(GL_POLYGON);
		glVertex2f(t1, 160);
		glVertex2f(t1, 300);
		glVertex2f(t2, 300);
		glVertex2f(t2, 160);
		glEnd();*/

		glColor3f(0.0, 0.0, 0.0);
		glBegin(GL_POLYGON);
		glVertex2f(t3, 160);
		glVertex2f(t3, 300);
		glVertex2f(t4, 300);
		glVertex2f(t4, 160);
		glEnd();

		glColor3f(0.0, 0.0, 0.0);
		glBegin(GL_POLYGON);
		glVertex2f(t5, 160);
		glVertex2f(t5, 300);
		glVertex2f(t6, 300);
		glVertex2f(t6, 160);
		glEnd();

		glColor3f(0.0, 0.0, 0.0);
		glBegin(GL_POLYGON);
		glVertex2f(t7, 160);
		glVertex2f(t7, 300);
		glVertex2f(t8, 300);
		glVertex2f(t8, 160);
		glEnd();

		/*glColor3f(0.0, 0.0, 0.0);
		glBegin(GL_POLYGON);
		glVertex2f(t9, 160);
		glVertex2f(t9, 300);
		glVertex2f(t10, 300);
		glVertex2f(t10, 160);
		glEnd();*/

		glColor3f(0.0, 0.0, 0.0);
		circle(t11, 155, 30);
		glColor3f(0.0, 0.0, 0.0);
		circle(t12, 155, 30);
		glColor3f(0.0, 0.0, 0.0);
		circle(t13, 155, 30);
		//glColor3f(0.0, 0.0, 0.0);
		//circle(t14, 155, 30);
		glColor3f(0.0, 0.0, 1.0);
		//treebody(250, 160, 250, 300, 300, 300, 300, 160);
		glBegin(GL_POLYGON);
		glVertex2f(tb1, 200);
		glVertex2f(tb1, 280);
		glVertex2f(tb2, 350);
		glVertex2f(tb3, 350);
		glVertex2f(tb3, 200);
		glVertex2f(tb2, 200);
		glEnd();
		glColor3f(1.0, 1.0, 1.0);
		glBegin(GL_POLYGON);
		glVertex2f(tw1, 280);
		glVertex2f(tw2, 320);
		glVertex2f(tw3, 320);
		glVertex2f(tw3, 280);
		//glVertex2f(400, 200);
		//glVertex2f(300, 200);
		glEnd();
		/*if (z == 1)
		{
			truckfront = truckfront - 1;
			truckback = truckback - 1;
			t1 = t1 - 1;
			t2 = t2 - 1;
			t3 = t3 - 1;
			t4 = t4 - 1;
			t5 = t5 - 1;
			t6 = t6 - 1;
			t7 = t7 - 1;
			t8 = t8 - 1;
			//t9 = t9 - 1;
			//t10 = t10 - 1;
			t11 = t11 - 1;
			t12 = t12 - 1;
			t13 = t13 - 1;
			t14 = t14 - 1;
			t15 = t15 - 1;
			t16 = t16 - 1;
			t22 = t22 - 1;
			tb1 = tb1 - 1;
			tb2 = tb2 - 1;
			tb3 = tb3 - 1;
			tw1 = tw1 - 1;
			tw2 = tw2 - 1;
			tw3 = tw3 - 1;
		}*/
	}

	glutPostRedisplay();
	//glFlush();
}
float a1 = 400;
float a2 = 750;
float a3 = 450;
float a4 = 550;
float a5 = 425;
float a6 = 500;
float a7 = 555;
float a8 = 650;
float a9 = 655;
float a10 = 755;
float a11 = 700;
float a12 = 645;
float a13 = 475;
float a14 = 155;
float a15 = 730;
float a16 = 750;
void truck400(int x) {
	if (a1 > x) {

		glColor3f(0.3, 0.0, 0.0);
		glBegin(GL_POLYGON);
		glVertex2f(a1, 160);
		glVertex2f(a1, 180);
		glVertex2f(a11, 350);
		glVertex2f(a11, 320);
		glEnd();

		glColor3f(0.0, 0.5, 0.0);
		circle(a11, 335, 30);
		circle(a11, 360, 30);
		circle(a11, 310, 30);
		circle(a15, 322, 30);
		circle(a15, 347, 30);
		//circle(a15, 245, 20);

		glColor3f(0.3, 0.0, 0.0);
		glBegin(GL_POLYGON);
		glVertex2f(a1, 200);
		glVertex2f(a1, 230);
		glVertex2f(a11, 230);
		glVertex2f(a11, 200);
		glEnd();

		glColor3f(0.0, 0.5, 0.0);
		circle(a11, 215, 30);
		circle(a11, 240, 30);
		circle(a2, 215, 30);
		circle(a15, 245, 20);

		glColor3f(0.1, 0.5, 0.8);
		glBegin(GL_POLYGON);
		glVertex2f(a1, 160);
		glVertex2f(a1, 200);
		glVertex2f(a2, 200);
		glVertex2f(a2, 160);
		glEnd();

		glColor3f(0.0, 0.0, 1.0);
		glBegin(GL_POLYGON);
		glVertex2f(a1, 200);
		glVertex2f(a1, 280);
		glVertex2f(a3, 350);
		glVertex2f(a4, 350);
		glVertex2f(a4, 200);
		glVertex2f(a3, 200);
		glEnd();

		glColor3f(1.0, 1.0, 1.0);
		glBegin(GL_POLYGON);
		glVertex2f(a5, 280);
		glVertex2f(a3, 320);
		glVertex2f(a6, 320);
		glVertex2f(a6, 280);
		glEnd();

		glColor3f(0.0, 0.0, 0.0);
		glBegin(GL_POLYGON);
		glVertex2f(a4, 160);
		glVertex2f(a4, 300);
		glVertex2f(a7, 300);
		glVertex2f(a7, 160);
		glEnd();

		glColor3f(0.0, 0.0, 0.0);
		glBegin(GL_POLYGON);
		glVertex2f(a8, 160);
		glVertex2f(a8, 300);
		glVertex2f(a9, 300);
		glVertex2f(a9, 160);
		glEnd();

		glColor3f(0.0, 0.0, 0.0);
		glBegin(GL_POLYGON);
		glVertex2f(a2, 160);
		glVertex2f(a2, 300);
		glVertex2f(a10, 300);
		glVertex2f(a10, 160);
		glEnd();

		glColor3f(0.0, 0.0, 0.0);
		circle(a12, a14, 30);
		glColor3f(0.0, 0.0, 0.0);
		circle(a11, a14, 30);
		glColor3f(0.0, 0.0, 0.0);
		circle(a13, a14, 30);
		//glColor3f(0.0, 0.0, 0.0);
		if (z == 1) {
			a1 = a1 - 1;
			a2 = a2 - 1;
			a3 = a3 - 1;
			a4 = a4 - 1;
			a5 = a5 - 1;
			a6 = a6 - 1;
			a7 = a7 - 1;
			a8 = a8 - 1;
			a9 = a9 - 1;
			a10 = a10 - 1;
			a11 = a11 - 1;
			a12 = a12 - 1;
			a13 = a13 - 1;
			a15 = a15 - 1;
			a16 = a16 - 1;
		}

	}
	else {
		glColor3f(0.3, 0.0, 0.0);
		glBegin(GL_POLYGON);
		glVertex2f(a1, 160);
		glVertex2f(a1, 180);
		glVertex2f(a11, 350);
		glVertex2f(a11, 320);
		glEnd();

		glColor3f(0.0, 0.5, 0.0);
		circle(a11, 335, 30);
		circle(a11, 360, 30);
		circle(a11, 310, 30);
		circle(a15, 322, 30);
		circle(a15, 347, 30);

		glColor3f(0.3, 0.0, 0.0);
		glBegin(GL_POLYGON);
		glVertex2f(a1, 200);
		glVertex2f(a1, 230);
		glVertex2f(a11, 230);
		glVertex2f(a11, 200);
		glEnd();

		glColor3f(0.0, 0.5, 0.0);
		circle(a11, 215, 30);
		circle(a11, 240, 30);
		circle(a2, 215, 30);
		circle(a15, 245, 20);

		glColor3f(0.1, 0.5, 0.8);
		glBegin(GL_POLYGON);
		glVertex2f(a1, 160);
		glVertex2f(a1, 200);
		glVertex2f(a2, 200);
		glVertex2f(a2, 160);
		glEnd();

		glColor3f(0.0, 0.0, 1.0);
		glBegin(GL_POLYGON);
		glVertex2f(a1, 200);
		glVertex2f(a1, 280);
		glVertex2f(a3, 350);
		glVertex2f(a4, 350);
		glVertex2f(a4, 200);
		glVertex2f(a3, 200);
		glEnd();

		glColor3f(1.0, 1.0, 1.0);
		glBegin(GL_POLYGON);
		glVertex2f(a5, 280);
		glVertex2f(a3, 320);
		glVertex2f(a6, 320);
		glVertex2f(a6, 280);
		glEnd();

		glColor3f(0.0, 0.0, 0.0);
		glBegin(GL_POLYGON);
		glVertex2f(a4, 160);
		glVertex2f(a4, 300);
		glVertex2f(a7, 300);
		glVertex2f(a7, 160);
		glEnd();

		glColor3f(0.0, 0.0, 0.0);
		glBegin(GL_POLYGON);
		glVertex2f(a8, 160);
		glVertex2f(a8, 300);
		glVertex2f(a9, 300);
		glVertex2f(a9, 160);
		glEnd();

		glColor3f(0.0, 0.0, 0.0);
		glBegin(GL_POLYGON);
		glVertex2f(a2, 160);
		glVertex2f(a2, 300);
		glVertex2f(a10, 300);
		glVertex2f(a10, 160);
		glEnd();

		glColor3f(0.0, 0.0, 0.0);
		circle(a12, a14, 30);
		glColor3f(0.0, 0.0, 0.0);
		circle(a11, a14, 30);
		glColor3f(0.0, 0.0, 0.0);
		circle(a13, a14, 30);
	}
	glutPostRedisplay();
}
float b1 = 300;
float b2 = 650;
float b3 = 350;
float b4 = 450;
float b5 = 400;
float b6 = 325;
float b7 = 455;
float b8 = 550;
float b9 = 555;
float b10 = 655;
float b11 = 545;
float b12 = 600;
float b13 = 375;
float b14 = 155;
void truck300(int x) {
	//glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	if (b1 > x) {
		glColor3f(0.1, 0.5, 0.8);
		glBegin(GL_POLYGON);
		glVertex2f(b1, 160);
		glVertex2f(b1, 200);
		glVertex2f(b2, 200);
		glVertex2f(b2, 160);
		glEnd();

		glColor3f(0.0, 0.0, 1.0);
		glBegin(GL_POLYGON);
		glVertex2f(b1, 200);
		glVertex2f(b1, 280);
		glVertex2f(b3, 350);
		glVertex2f(b4, 350);
		glVertex2f(b4, 200);
		glVertex2f(b3, 200);
		glEnd();

		glColor3f(1.0, 1.0, 1.0);
		glBegin(GL_POLYGON);
		glVertex2f(b6, 280);
		glVertex2f(b3, 320);
		glVertex2f(b5, 320);
		glVertex2f(b5, 280);
		glEnd();

		glColor3f(0.0, 0.0, 0.0);
		glBegin(GL_POLYGON);
		glVertex2f(b4, 160);
		glVertex2f(b4, 300);
		glVertex2f(b7, 300);
		glVertex2f(b7, 160);
		glEnd();

		glColor3f(0.0, 0.0, 0.0);
		glBegin(GL_POLYGON);
		glVertex2f(b8, 160);
		glVertex2f(b8, 300);
		glVertex2f(b9, 300);
		glVertex2f(b9, 160);
		glEnd();

		glColor3f(0.0, 0.0, 0.0);
		glBegin(GL_POLYGON);
		glVertex2f(b2, 160);
		glVertex2f(b2, 300);
		glVertex2f(b10, 300);
		glVertex2f(b10, 160);
		glEnd();

		glColor3f(0.0, 0.0, 0.0);
		circle(b11, b14, 30);
		glColor3f(0.0, 0.0, 0.0);
		circle(b12, b14, 30);
		glColor3f(0.0, 0.0, 0.0);
		circle(b13, b14, 30);
		glColor3f(0.0, 0.0, 0.0);
		if (z == 1) {
			b1 = b1 - 1;
			b2 = b2 - 1;
			b3 = b3 - 1;
			b4 = b4 - 1;
			b5 = b5 - 1;
			b6 = b6 - 1;
			b7 = b7 - 1;
			b8 = b8 - 1;
			b9 = b9 - 1;
			b10 = b10 - 1;
			b11 = b11 - 1;
			b12 = b12 - 1;
			b13 = b13 - 1;
		}
	}
	else {
		glColor3f(0.1, 0.5, 0.8);
		glBegin(GL_POLYGON);
		glVertex2f(b1, 160);
		glVertex2f(b1, 200);
		glVertex2f(b2, 200);
		glVertex2f(b2, 160);
		glEnd();

		glColor3f(0.0, 0.0, 1.0);
		glBegin(GL_POLYGON);
		glVertex2f(b1, 200);
		glVertex2f(b1, 280);
		glVertex2f(b3, 350);
		glVertex2f(b4, 350);
		glVertex2f(b4, 200);
		glVertex2f(b3, 200);
		glEnd();

		glColor3f(1.0, 1.0, 1.0);
		glBegin(GL_POLYGON);
		glVertex2f(b6, 280);
		glVertex2f(b3, 320);
		glVertex2f(b5, 320);
		glVertex2f(b5, 280);
		glEnd();

		glColor3f(0.0, 0.0, 0.0);
		glBegin(GL_POLYGON);
		glVertex2f(b4, 160);
		glVertex2f(b4, 300);
		glVertex2f(b7, 300);
		glVertex2f(b7, 160);
		glEnd();

		glColor3f(0.0, 0.0, 0.0);
		glBegin(GL_POLYGON);
		glVertex2f(b8, 160);
		glVertex2f(b8, 300);
		glVertex2f(b9, 300);
		glVertex2f(b9, 160);
		glEnd();

		glColor3f(0.0, 0.0, 0.0);
		glBegin(GL_POLYGON);
		glVertex2f(b2, 160);
		glVertex2f(b2, 300);
		glVertex2f(b10, 300);
		glVertex2f(b10, 160);
		glEnd();

		glColor3f(0.0, 0.0, 0.0);
		circle(b11, b14, 30);
		glColor3f(0.0, 0.0, 0.0);
		circle(b12, b14, 30);
		glColor3f(0.0, 0.0, 0.0);
		circle(b13, b14, 30);
	}
	glutPostRedisplay();
	//glFlush();
}
float c1 = 250;
float c2 = 600;
float c3 = 300;
float c4 = 400;
float c5 = 275;
float c6 = 350;
float c7 = 405;
float c8 = 500;
float c9 = 505;
float c10 = 600;
float c11 = 605;
float c12 = 495;
float c13 = 550;
float c14 = 325;
float c15 = 155;
void truck250(int x) {
	//glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	if (c1 > x) {
		glColor3f(0.1, 0.5, 0.8);
		glBegin(GL_POLYGON);
		glVertex2f(c1, 160);
		glVertex2f(c1, 200);
		glVertex2f(c2, 200);
		glVertex2f(c2, 160);
		glEnd();

		glColor3f(0.0, 0.0, 1.0);
		glBegin(GL_POLYGON);
		glVertex2f(c1, 200);
		glVertex2f(c1, 280);
		glVertex2f(c3, 350);
		glVertex2f(c4, 350);
		glVertex2f(c4, 200);
		glVertex2f(c3, 200);
		glEnd();

		glColor3f(1.0, 1.0, 1.0);
		glBegin(GL_POLYGON);
		glVertex2f(c5, 280);
		glVertex2f(c3, 320);
		glVertex2f(c6, 320);
		glVertex2f(c6, 280);
		glEnd();

		glColor3f(0.0, 0.0, 0.0);
		glBegin(GL_POLYGON);
		glVertex2f(c4, 160);
		glVertex2f(c4, 300);
		glVertex2f(c7, 300);
		glVertex2f(c7, 160);
		glEnd();

		glColor3f(0.0, 0.0, 0.0);
		glBegin(GL_POLYGON);
		glVertex2f(c8, 160);
		glVertex2f(c8, 300);
		glVertex2f(c9, 300);
		glVertex2f(c9, 160);
		glEnd();

		glColor3f(0.0, 0.0, 0.0);
		glBegin(GL_POLYGON);
		glVertex2f(c10, 160);
		glVertex2f(c10, 300);
		glVertex2f(c11, 300);
		glVertex2f(c11, 160);
		glEnd();

		glColor3f(0.0, 0.0, 0.0);
		circle(c12, c15, 30);
		glColor3f(0.0, 0.0, 0.0);
		circle(c13, c15, 30);
		glColor3f(0.0, 0.0, 0.0);
		circle(c14, c15, 30);

		if (z == 1) {
			c1 = c1 - 1;
			c2 = c2 - 1;
			c3 = c3 - 1;
			c4 = c4 - 1;
			c5 = c5 - 1;
			c6 = c6 - 1;
			c7 = c7 - 1;
			c8 = c8 - 1;
			c9 = c9 - 1;
			c10 = c10 - 1;
			c11 = c11 - 1;
			c12 = c12 - 1;
			c13 = c13 - 1;
		}
	}
	else {
		glColor3f(0.1, 0.5, 0.8);
		glBegin(GL_POLYGON);
		glVertex2f(c1, 160);
		glVertex2f(c1, 200);
		glVertex2f(c2, 200);
		glVertex2f(c2, 160);
		glEnd();

		glColor3f(0.0, 0.0, 1.0);
		glBegin(GL_POLYGON);
		glVertex2f(c1, 200);
		glVertex2f(c1, 280);
		glVertex2f(c3, 350);
		glVertex2f(c4, 350);
		glVertex2f(c4, 200);
		glVertex2f(c3, 200);
		glEnd();

		glColor3f(1.0, 1.0, 1.0);
		glBegin(GL_POLYGON);
		glVertex2f(c5, 280);
		glVertex2f(c3, 320);
		glVertex2f(c6, 320);
		glVertex2f(c6, 280);
		glEnd();

		glColor3f(0.0, 0.0, 0.0);
		glBegin(GL_POLYGON);
		glVertex2f(c4, 160);
		glVertex2f(c4, 300);
		glVertex2f(c7, 300);
		glVertex2f(c7, 160);
		glEnd();

		glColor3f(0.0, 0.0, 0.0);
		glBegin(GL_POLYGON);
		glVertex2f(c8, 160);
		glVertex2f(c8, 300);
		glVertex2f(c9, 300);
		glVertex2f(c9, 160);
		glEnd();

		glColor3f(0.0, 0.0, 0.0);
		glBegin(GL_POLYGON);
		glVertex2f(c10, 160);
		glVertex2f(c10, 300);
		glVertex2f(c11, 300);
		glVertex2f(c11, 160);
		glEnd();

		glColor3f(0.0, 0.0, 0.0);
		circle(c12, c15, 30);
		glColor3f(0.0, 0.0, 0.0);
		circle(c13, c15, 30);
		glColor3f(0.0, 0.0, 0.0);
		circle(c14, c15, 30);
	}
	glutPostRedisplay();
	//glFlush();
}
float d1 = 200;
float d2 = 550;
float d3 = 250;
float d4 = 350;
float d5 = 225;
float d6 = 300;
float d7 = 355;
float d8 = 450;
float d9 = 455;
float d10 = 555;
float d11 = 445;
float d12 = 500;
float d13 = 275;
float d14 = 155;
float d15 = 530;
void truck200(int x) {
	//glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	if (d1 > x) {
		glColor3f(0.3, 0.0, 0.0);
		glBegin(GL_POLYGON);
		glVertex2f(d6, 350);
		glVertex2f(d6, 320);
		glVertex2f(d12, 200);
		glVertex2f(d12, 220);
		glEnd();

		glColor3f(0.0, 0.5, 0.0);
		circle(d7, 325, 30);
		circle(d7, 300, 30);
		circle(d7, 275, 30);
		//circle(a15, 322, 30);
		//circle(a15, 347, 30);

		glColor3f(0.3, 0.0, 0.0);
		glBegin(GL_POLYGON);
		glVertex2f(d1, 160);
		glVertex2f(d1, 180);
		glVertex2f(d12, 350);
		glVertex2f(d12, 320);
		glEnd();

		glColor3f(0.0, 0.5, 0.0);
		circle(d12, 335, 30);
		circle(d12, 360, 30);
		circle(d12, 310, 30);
		circle(d15, 322, 30);
		circle(d15, 347, 30);

		glColor3f(0.3, 0.0, 0.0);
		glBegin(GL_POLYGON);
		glVertex2f(d1, 200);
		glVertex2f(d1, 230);
		glVertex2f(d12, 230);
		glVertex2f(d12, 200);
		glEnd();

		glColor3f(0.0, 0.5, 0.0);
		circle(d12, 215, 30);
		circle(d12, 240, 30);
		circle(d2, 215, 30);
		circle(d15, 245, 20);

		glColor3f(0.1, 0.5, 0.8);
		glBegin(GL_POLYGON);
		glVertex2f(d1, 160);
		glVertex2f(d1, 200);
		glVertex2f(d2, 200);
		glVertex2f(d2, 160);
		glEnd();

		glColor3f(0.0, 0.0, 1.0);
		glBegin(GL_POLYGON);
		glVertex2f(d1, 200);
		glVertex2f(d1, 280);
		glVertex2f(d3, 350);
		glVertex2f(d4, 350);
		glVertex2f(d4, 200);
		glVertex2f(d3, 200);
		glEnd();

		glColor3f(1.0, 1.0, 1.0);
		glBegin(GL_POLYGON);
		glVertex2f(d5, 280);
		glVertex2f(d3, 320);
		glVertex2f(d6, 320);
		glVertex2f(d6, 280);
		glEnd();

		glColor3f(0.0, 0.0, 0.0);
		glBegin(GL_POLYGON);
		glVertex2f(d4, 160);
		glVertex2f(d4, 300);
		glVertex2f(d7, 300);
		glVertex2f(d7, 160);
		glEnd();

		glColor3f(0.0, 0.0, 0.0);
		glBegin(GL_POLYGON);
		glVertex2f(d8, 160);
		glVertex2f(d8, 300);
		glVertex2f(d9, 300);
		glVertex2f(d9, 160);
		glEnd();

		glColor3f(0.0, 0.0, 0.0);
		glBegin(GL_POLYGON);
		glVertex2f(d2, 160);
		glVertex2f(d2, 300);
		glVertex2f(d10, 300);
		glVertex2f(d10, 160);
		glEnd();

		glColor3f(0.0, 0.0, 0.0);
		circle(d11, d14, 30);
		glColor3f(0.0, 0.0, 0.0);
		circle(d12, d14, 30);
		glColor3f(0.0, 0.0, 0.0);
		circle(d13, d14, 30);
		if (z == 1) {
			d1 = d1 - 1;
			d2 = d2 - 1;
			d3 = d3 - 1;
			d4 = d4 - 1;
			d5 = d5 - 1;
			d6 = d6 - 1;
			d7 = d7 - 1;
			d8 = d8 - 1;
			d9 = d9 - 1;
			d10 = d10 - 1;
			d11 = d11 - 1;
			d12 = d12 - 1;
			d13 = d13 - 1;
			d15 = d15 - 1;
		}
	}
	else {
		glColor3f(0.3, 0.0, 0.0);
		glBegin(GL_POLYGON);
		glVertex2f(d6, 350);
		glVertex2f(d6, 320);
		glVertex2f(d12, 200);
		glVertex2f(d12, 220);
		glEnd();

		glColor3f(0.0, 0.5, 0.0);
		circle(d7, 325, 30);
		circle(d7, 300, 30);
		circle(d7, 275, 30);

		glColor3f(0.3, 0.0, 0.0);
		glBegin(GL_POLYGON);
		glVertex2f(d1, 160);
		glVertex2f(d1, 180);
		glVertex2f(d12, 350);
		glVertex2f(d12, 320);
		glEnd();

		glColor3f(0.0, 0.5, 0.0);
		circle(d12, 335, 30);
		circle(d12, 360, 30);
		circle(d12, 310, 30);
		circle(d15, 322, 30);
		circle(d15, 347, 30);

		glColor3f(0.3, 0.0, 0.0);
		glBegin(GL_POLYGON);
		glVertex2f(d1, 200);
		glVertex2f(d1, 230);
		glVertex2f(d12, 230);
		glVertex2f(d12, 200);
		glEnd();

		glColor3f(0.0, 0.5, 0.0);
		circle(d12, 215, 30);
		circle(d12, 240, 30);
		circle(d2, 215, 30);
		circle(d15, 245, 20);

		glColor3f(0.1, 0.5, 0.8);
		glBegin(GL_POLYGON);
		glVertex2f(d1, 160);
		glVertex2f(d1, 200);
		glVertex2f(d2, 200);
		glVertex2f(d2, 160);
		glEnd();

		glColor3f(0.0, 0.0, 1.0);
		glBegin(GL_POLYGON);
		glVertex2f(d1, 200);
		glVertex2f(d1, 280);
		glVertex2f(d3, 350);
		glVertex2f(d4, 350);
		glVertex2f(d4, 200);
		glVertex2f(d3, 200);
		glEnd();

		glColor3f(1.0, 1.0, 1.0);
		glBegin(GL_POLYGON);
		glVertex2f(d5, 280);
		glVertex2f(d3, 320);
		glVertex2f(d6, 320);
		glVertex2f(d6, 280);
		glEnd();

		glColor3f(0.0, 0.0, 0.0);
		glBegin(GL_POLYGON);
		glVertex2f(d4, 160);
		glVertex2f(d4, 300);
		glVertex2f(d7, 300);
		glVertex2f(d7, 160);
		glEnd();

		glColor3f(0.0, 0.0, 0.0);
		glBegin(GL_POLYGON);
		glVertex2f(d8, 160);
		glVertex2f(d8, 300);
		glVertex2f(d9, 300);
		glVertex2f(d9, 160);
		glEnd();

		glColor3f(0.0, 0.0, 0.0);
		glBegin(GL_POLYGON);
		glVertex2f(d2, 160);
		glVertex2f(d2, 300);
		glVertex2f(d10, 300);
		glVertex2f(d10, 160);
		glEnd();

		glColor3f(0.0, 0.0, 0.0);
		circle(d11, d14, 30);
		glColor3f(0.0, 0.0, 0.0);
		circle(d12, d14, 30);
		glColor3f(0.0, 0.0, 0.0);
		circle(d13, d14, 30);
	}
	glutPostRedisplay();
	//glFlush();
}
float e1 = 100;
float e2 = 450;
float e3 = 150;
float e4 = 250;
float e5 = 125;
float e6 = 200;
float e7 = 255;
float e8 = 350;
float e9 = 355;
float e10 = 455;
float e11 = 400;
float e12 = 345;
float e13 = 175;
float e14 = 155;
void truck100(int x) {
	//glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	if (d1 > x) {
		glColor3f(0.1, 0.5, 0.8);
		glBegin(GL_POLYGON);
		glVertex2f(e1, 160);
		glVertex2f(e1, 200);
		glVertex2f(e2, 200);
		glVertex2f(e2, 160);
		glEnd();

		glColor3f(0.0, 0.0, 1.0);
		glBegin(GL_POLYGON);
		glVertex2f(e1, 200);
		glVertex2f(e1, 280);
		glVertex2f(e3, 350);
		glVertex2f(e4, 350);
		glVertex2f(e4, 200);
		glVertex2f(e3, 200);
		glEnd();

		glColor3f(1.0, 1.0, 1.0);
		glBegin(GL_POLYGON);
		glVertex2f(e5, 280);
		glVertex2f(e3, 320);
		glVertex2f(e6, 320);
		glVertex2f(e6, 280);
		glEnd();

		glColor3f(0.0, 0.0, 0.0);
		glBegin(GL_POLYGON);
		glVertex2f(e4, 160);
		glVertex2f(e4, 300);
		glVertex2f(e7, 300);
		glVertex2f(e7, 160);
		glEnd();

		glColor3f(0.0, 0.0, 0.0);
		glBegin(GL_POLYGON);
		glVertex2f(e8, 160);
		glVertex2f(e8, 300);
		glVertex2f(e9, 300);
		glVertex2f(e9, 160);
		glEnd();

		glColor3f(0.0, 0.0, 0.0);
		glBegin(GL_POLYGON);
		glVertex2f(e2, 160);
		glVertex2f(e2, 300);
		glVertex2f(e10, 300);
		glVertex2f(e10, 160);
		glEnd();

		glColor3f(0.0, 0.0, 0.0);
		circle(e12, e14, 30);
		glColor3f(0.0, 0.0, 0.0);
		circle(e11, e14, 30);
		glColor3f(0.0, 0.0, 0.0);
		circle(e13, e14, 30);
		glColor3f(0.0, 0.0, 0.0);
		if (z == 1) {
			e1 = e1 - 1;
			e2 = e2 - 1;
			e3 = e3 - 1;
			e4 = e4 - 1;
			e5 = e5 - 1;
			e6 = e6 - 1;
			e7 = e7 - 1;
			e8 = e8 - 1;
			e9 = e9 - 1;
			e10 = e10 - 1;
			e11 = e11 - 1;
			e12 = e12 - 1;
			e13 = e13 - 1;
		}
	}
	else {
		glColor3f(0.1, 0.5, 0.8);
		glBegin(GL_POLYGON);
		glVertex2f(e1, 160);
		glVertex2f(e1, 200);
		glVertex2f(e2, 200);
		glVertex2f(e2, 160);
		glEnd();

		glColor3f(0.0, 0.0, 1.0);
		glBegin(GL_POLYGON);
		glVertex2f(e1, 200);
		glVertex2f(e1, 280);
		glVertex2f(e3, 350);
		glVertex2f(e4, 350);
		glVertex2f(e4, 200);
		glVertex2f(e3, 200);
		glEnd();

		glColor3f(1.0, 1.0, 1.0);
		glBegin(GL_POLYGON);
		glVertex2f(e5, 280);
		glVertex2f(e3, 320);
		glVertex2f(e6, 320);
		glVertex2f(e6, 280);
		glEnd();

		glColor3f(0.0, 0.0, 0.0);
		glBegin(GL_POLYGON);
		glVertex2f(e4, 160);
		glVertex2f(e4, 300);
		glVertex2f(e7, 300);
		glVertex2f(e7, 160);
		glEnd();

		glColor3f(0.0, 0.0, 0.0);
		glBegin(GL_POLYGON);
		glVertex2f(e8, 160);
		glVertex2f(e8, 300);
		glVertex2f(e9, 300);
		glVertex2f(e9, 160);
		glEnd();

		glColor3f(0.0, 0.0, 0.0);
		glBegin(GL_POLYGON);
		glVertex2f(e2, 160);
		glVertex2f(e2, 300);
		glVertex2f(e10, 300);
		glVertex2f(e10, 160);
		glEnd();

		glColor3f(0.0, 0.0, 0.0);
		circle(e12, e14, 30);
		glColor3f(0.0, 0.0, 0.0);
		circle(e11, e14, 30);
		glColor3f(0.0, 0.0, 0.0);
		circle(e13, e14, 30);
	}
	glutPostRedisplay();
	//glFlush();
}
float f1 = 600;
float f2 = 950;
float f3 = 650;
float f4 = 750;
float f5 = 625;
float f6 = 700;
float f7 = 755;
float f8 = 850;
float f9 = 855;
float f10 = 955;
float f11 = 900;
float f12 = 845;
float f13 = 675;
float f14 = 155;
float f15 = 930;

void truck600(int x) {
	if (f1 > x) {
		glColor3f(0.3, 0.0, 0.0);
		glBegin(GL_POLYGON);
		glVertex2f(f1, 200);
		glVertex2f(f1, 230);
		glVertex2f(f11, 230);
		glVertex2f(f11, 200);
		glEnd();

		glColor3f(0.0, 0.5, 0.0);
		circle(f11, 215, 30);
		circle(f11, 240, 30);
		circle(f2, 215, 30);
		circle(f15, 245, 20);

		glColor3f(0.1, 0.5, 0.8);
		glBegin(GL_POLYGON);
		glVertex2f(f1, 160);
		glVertex2f(f1, 200);
		glVertex2f(f2, 200);
		glVertex2f(f2, 160);
		glEnd();

		glColor3f(0.0, 0.0, 1.0);
		glBegin(GL_POLYGON);
		glVertex2f(f1, 200);
		glVertex2f(f1, 280);
		glVertex2f(f3, 350);
		glVertex2f(f4, 350);
		glVertex2f(f4, 200);
		glVertex2f(f3, 200);
		glEnd();

		glColor3f(1.0, 1.0, 1.0);
		glBegin(GL_POLYGON);
		glVertex2f(f5, 280);
		glVertex2f(f3, 320);
		glVertex2f(f6, 320);
		glVertex2f(f6, 280);
		glEnd();

		glColor3f(0.0, 0.0, 0.0);
		glBegin(GL_POLYGON);
		glVertex2f(f4, 160);
		glVertex2f(f4, 300);
		glVertex2f(f7, 300);
		glVertex2f(f7, 160);
		glEnd();

		glColor3f(0.0, 0.0, 0.0);
		glBegin(GL_POLYGON);
		glVertex2f(f8, 160);
		glVertex2f(f8, 300);
		glVertex2f(f9, 300);
		glVertex2f(f9, 160);
		glEnd();

		glColor3f(0.0, 0.0, 0.0);
		glBegin(GL_POLYGON);
		glVertex2f(f2, 160);
		glVertex2f(f2, 300);
		glVertex2f(f10, 300);
		glVertex2f(f10, 160);
		glEnd();

		glColor3f(0.0, 0.0, 0.0);
		circle(f12, f14, 30);
		glColor3f(0.0, 0.0, 0.0);
		circle(f11, f14, 30);
		glColor3f(0.0, 0.0, 0.0);
		circle(f13, f14, 30);
		if (z == 1) {
			f1 = f1 - 1;
			f2 = f2 - 1;
			f3 = f3 - 1;
			f4 = f4 - 1;
			f5 = f5 - 1;
			f6 = f6 - 1;
			f7 = f7 - 1;
			f8 = f8 - 1;
			f9 = f9 - 1;
			f10 = f10 - 1;
			f11 = f11 - 1;
			f12 = f12 - 1;
			f13 = f13 - 1;
			f15 = f15 - 1;
		}
	}
	else {
		glColor3f(0.3, 0.0, 0.0);
		glBegin(GL_POLYGON);
		glVertex2f(f1, 200);
		glVertex2f(f1, 230);
		glVertex2f(f11, 230);
		glVertex2f(f11, 200);
		glEnd();

		glColor3f(0.0, 0.5, 0.0);
		circle(f11, 215, 30);
		circle(f11, 240, 30);
		circle(f2, 215, 30);
		circle(f15, 245, 20);


		glColor3f(0.1, 0.5, 0.8);
		glBegin(GL_POLYGON);
		glVertex2f(f1, 160);
		glVertex2f(f1, 200);
		glVertex2f(f2, 200);
		glVertex2f(f2, 160);
		glEnd();

		glColor3f(0.0, 0.0, 1.0);
		glBegin(GL_POLYGON);
		glVertex2f(f1, 200);
		glVertex2f(f1, 280);
		glVertex2f(f3, 350);
		glVertex2f(f4, 350);
		glVertex2f(f4, 200);
		glVertex2f(f3, 200);
		glEnd();

		glColor3f(1.0, 1.0, 1.0);
		glBegin(GL_POLYGON);
		glVertex2f(f5, 280);
		glVertex2f(f3, 320);
		glVertex2f(f6, 320);
		glVertex2f(f6, 280);
		glEnd();

		glColor3f(0.0, 0.0, 0.0);
		glBegin(GL_POLYGON);
		glVertex2f(f4, 160);
		glVertex2f(f4, 300);
		glVertex2f(f7, 300);
		glVertex2f(f7, 160);
		glEnd();

		glColor3f(0.0, 0.0, 0.0);
		glBegin(GL_POLYGON);
		glVertex2f(f8, 160);
		glVertex2f(f8, 300);
		glVertex2f(f9, 300);
		glVertex2f(f9, 160);
		glEnd();

		glColor3f(0.0, 0.0, 0.0);
		glBegin(GL_POLYGON);
		glVertex2f(f2, 160);
		glVertex2f(f2, 300);
		glVertex2f(f10, 300);
		glVertex2f(f10, 160);
		glEnd();

		glColor3f(0.0, 0.0, 0.0);
		circle(f12, f14, 30);
		glColor3f(0.0, 0.0, 0.0);
		circle(f11, f14, 30);
		glColor3f(0.0, 0.0, 0.0);
		circle(f13, f14, 30);
	}
	glutPostRedisplay();
}




void display1(int x) {
	if (fronttraingle > x)

	{

		glColor3f(1.0, 0.0, 0.0);
		circle(carfront, 190, 20);

		glColor3f(1.0, 0.0, 0.0);
		circle(carback, 190, 20);


		glBegin(GL_TRIANGLES);
		glVertex2f(front, 190);
		glVertex2f(fronttraingle, 190);
		glVertex2f(front, 200);
		glEnd();
		glBegin(GL_POLYGON);
		glVertex2f(back, 190);
		glVertex2f(front, 190);
		glVertex2f(front, 240);
		glVertex2f(back, 240);
		glEnd();
		if (z == 1)
		{
			front = front - 0.5;
			back = back - 0.5;
			carfront = carfront - 0.5;
			carback = carback - 0.5;
			fronttraingle = fronttraingle - 0.5;
		}

	}
	else {
		glColor3f(1.0, 0.0, 0.0);
		circle(carfront, 190, 20);

		glColor3f(1.0, 0.0, 0.0);
		circle(carback, 190, 20);


		glBegin(GL_TRIANGLES);
		glVertex2f(front, 190);
		glVertex2f(fronttraingle, 190);
		glVertex2f(front, 200);
		glEnd();
		glBegin(GL_POLYGON);
		glVertex2f(back, 190);
		glVertex2f(front, 190);
		glVertex2f(front, 240);
		glVertex2f(back, 240);
		glEnd();
	}
}



void display2(int x)
{
	if (fronttraingle1 > x)

	{

		glColor3f(1.0, 0.0, 0.0);
		circle(carfront1, 190, 20);


		glColor3f(1.0, 0.0, 0.0);
		circle(carback1, 190, 20);


		glBegin(GL_TRIANGLES);
		glVertex2f(front1, 190);
		glVertex2f(fronttraingle1, 190);
		glVertex2f(front1, 200);
		glEnd();
		glBegin(GL_POLYGON);
		glVertex2f(back1, 190);
		glVertex2f(front1, 190);
		glVertex2f(front1, 240);
		glVertex2f(back1, 240);
		glEnd();
		if (z == 1)
		{
			front1 = front1 - 0.5;
			back1 = back1 - 0.5;
			carfront1 = carfront1 - 0.5;
			carback1 = carback1 - 0.5;
			fronttraingle1 = fronttraingle1 - 0.5;
		}

	}
	else {

		glColor3f(1.0, 0.0, 0.0);
		circle(carfront1, 190, 20);


		glColor3f(1.0, 0.0, 0.0);
		circle(carback1, 190, 20);


		glBegin(GL_TRIANGLES);
		glVertex2f(front1, 190);
		glVertex2f(fronttraingle1, 190);
		glVertex2f(front1, 200);
		glEnd();
		glBegin(GL_POLYGON);
		glVertex2f(back1, 190);
		glVertex2f(front1, 190);
		glVertex2f(front1, 240);
		glVertex2f(back1, 240);
		glEnd();

	}
}



void display3(int x)
{
	if (fronttraingle2 > x)

	{

		glColor3f(1.0, 0.0, 0.0);
		circle(carfront2, 190, 20);

		glColor3f(1.0, 0.0, 0.0);
		circle(carback2, 190, 20);


		glBegin(GL_TRIANGLES);
		glVertex2f(front2, 190);
		glVertex2f(fronttraingle2, 190);
		glVertex2f(front2, 200);
		glEnd();
		glBegin(GL_POLYGON);
		glVertex2f(back2, 190);
		glVertex2f(front2, 190);
		glVertex2f(front2, 240);
		glVertex2f(back2, 240);
		glEnd();
		if (z == 1)
		{
			front2 = front2 - 0.5;
			back2 = back2 - 0.5;
			carfront2 = carfront2 - 0.5;
			carback2 = carback2 - 0.5;
			fronttraingle2 = fronttraingle2 - 0.5;
		}

	}
	else {

		glColor3f(1.0, 0.0, 0.0);
		circle(carfront2, 190, 20);


		glColor3f(1.0, 0.0, 0.0);
		circle(carback2, 190, 20);


		glBegin(GL_TRIANGLES);
		glVertex2f(front2, 190);
		glVertex2f(fronttraingle2, 190);
		glVertex2f(front2, 200);
		glEnd();
		glBegin(GL_POLYGON);
		glVertex2f(back2, 190);
		glVertex2f(front2, 190);
		glVertex2f(front2, 240);
		glVertex2f(back2, 240);
		glEnd();
	}

}


void display4(int x)
{
	if (fronttraingle3 > x)

	{

		glColor3f(1.0, 0.0, 0.0);
		circle(carfront3, 190, 20);


		glColor3f(1.0, 0.0, 0.0);
		circle(carback3, 190, 20);


		glBegin(GL_TRIANGLES);
		glVertex2f(front3, 190);
		glVertex2f(fronttraingle3, 190);
		glVertex2f(front3, 200);
		glEnd();
		glBegin(GL_POLYGON);
		glVertex2f(back3, 190);
		glVertex2f(front3, 190);
		glVertex2f(front3, 240);
		glVertex2f(back3, 240);
		glEnd();
		if (z == 1)
		{
			front3 = front3 - 0.5;
			back3 = back3 - 0.5;
			carfront3 = carfront3 - 0.5;
			carback3 = carback3 - 0.5;
			fronttraingle3 = fronttraingle3 - 0.5;
		}

	}
	else {

		glColor3f(1.0, 0.0, 0.0);
		circle(carfront3, 190, 20);


		glColor3f(1.0, 0.0, 0.0);
		circle(carback3, 190, 20);


		glBegin(GL_TRIANGLES);
		glVertex2f(front3, 190);
		glVertex2f(fronttraingle3, 190);
		glVertex2f(front3, 200);
		glEnd();
		glBegin(GL_POLYGON);
		glVertex2f(back3, 190);
		glVertex2f(front3, 190);
		glVertex2f(front3, 240);
		glVertex2f(back3, 240);
		glEnd();
	}
}
void display5(int x)
{
	if (fronttraingle4 > x)

	{

		glColor3f(1.0, 0.0, 0.0);
		circle(carfront4, 190, 20);


		glColor3f(1.0, 0.0, 0.0);
		circle(carback4, 190, 20);


		glBegin(GL_TRIANGLES);
		glVertex2f(front4, 190);
		glVertex2f(fronttraingle4, 190);
		glVertex2f(front4, 200);
		glEnd();
		glBegin(GL_POLYGON);
		glVertex2f(back4, 190);
		glVertex2f(front4, 190);
		glVertex2f(front4, 240);
		glVertex2f(back4, 240);
		glEnd();
		if (z == 1)
		{
			front4 = front4 - 0.5;
			back4 = back4 - 0.5;
			carfront4 = carfront4 - 0.5;
			carback4 = carback4 - 0.5;
			fronttraingle4 = fronttraingle4 - 0.5;
		}

	}
	else {

		glColor3f(1.0, 0.0, 0.0);
		circle(carfront4, 190, 20);


		glColor3f(1.0, 0.0, 0.0);
		circle(carback4, 190, 20);


		glBegin(GL_TRIANGLES);
		glVertex2f(front4, 190);
		glVertex2f(fronttraingle4, 190);
		glVertex2f(front4, 200);
		glEnd();
		glBegin(GL_POLYGON);
		glVertex2f(back4, 190);
		glVertex2f(front4, 190);
		glVertex2f(front4, 240);
		glVertex2f(back4, 240);
		glEnd();
	}
}
void scene2() {
	glColor3f(.5, .25, .12);
	glBegin(GL_POLYGON);
	glVertex2f(830, 200);
	glVertex2f(510, 200);
	glVertex2f(510, 400);
	glVertex2f(830, 400);
	glEnd();

	glColor3f(.1, .1, .1);
	glBegin(GL_LINE_LOOP);
	glVertex2f(830, 200);
	glVertex2f(510, 200);
	glVertex2f(510, 400);
	glVertex2f(830, 400);
	glEnd();

	glLineWidth(3.5);
	glColor3f(.1, .1, .1);
	glBegin(GL_LINES);
	glVertex2f(700, 400);
	glVertex2f(690, 530);
	glEnd();
}
void scene21(int time) {
	glColor3f(.5, .25, .12);
	glBegin(GL_POLYGON);
	glVertex2f(830, 200);
	glVertex2f(510, 200);
	glVertex2f(510, 400);
	glVertex2f(830, 400);
	glEnd();

	glColor3f(.1, .1, .1);
	glBegin(GL_LINE_LOOP);
	glVertex2f(830, 200);
	glVertex2f(510, 200);
	glVertex2f(510, 400);
	glVertex2f(830, 400);
	glEnd();

	glLineWidth(3.5);
	glColor3f(.1, .1, .1);
	glBegin(GL_LINES);
	glVertex2f(700, 400);
	glVertex2f(690, 530);
	glEnd();

}
void scene22(int time) {
	glColor3f(.5, .25, .12);
	glBegin(GL_POLYGON);
	glVertex2f(830, 200);
	glVertex2f(510, 200);
	glVertex2f(510, 400);
	glVertex2f(830, 400);
	glEnd();

	glColor3f(.1, .1, .1);
	glBegin(GL_LINE_LOOP);
	glVertex2f(830, 200);
	glVertex2f(510, 200);
	glVertex2f(510, 400);
	glVertex2f(830, 400);
	glEnd();

	glLineWidth(3.5);
	glColor3f(.1, .1, .1);
	glBegin(GL_LINES);
	glVertex2f(700, 400);
	glVertex2f(690, 530);
	glEnd();

	glLineWidth(3.5);
	glColor3f(.1, .1, .1);
	glBegin(GL_LINES);
	glVertex2f(700, 400);
	glVertex2f(690, 530);
	glVertex2f(650, 400);
	glVertex2f(670, 530);
	glVertex2f(650, 400);
	glVertex2f(700, 448);//ok
	glVertex2f(700, 448);
	glVertex2f(670, 500);
	glVertex2f(665, 500);
	glVertex2f(690, 530);
	glVertex2f(700, 400);
	glVertex2f(660, 450);
	glVertex2f(660, 450);
	glVertex2f(690, 500);
	glVertex2f(690, 500);
	glVertex2f(670, 525);
	glEnd();
}
void scene23() {
	glColor3f(.5, .25, .12);
	glBegin(GL_POLYGON);
	glVertex2f(830, 200);
	glVertex2f(510, 200);
	glVertex2f(510, 400);
	glVertex2f(830, 400);
	glEnd();

	glColor3f(.1, .1, .1);
	glBegin(GL_LINE_LOOP);
	glVertex2f(830, 200);
	glVertex2f(510, 200);
	glVertex2f(510, 400);
	glVertex2f(830, 400);
	glEnd();

	glLineWidth(3.5);
	glColor3f(.1, .1, .1);
	glBegin(GL_LINES);
	glVertex2f(700, 400);
	glVertex2f(690, 530);
	glEnd();

	glLineWidth(3.5);
	glColor3f(.1, .1, .1);
	glBegin(GL_LINES);
	glVertex2f(700, 400);
	glVertex2f(690, 530);
	glVertex2f(650, 400);
	glVertex2f(670, 530);
	glVertex2f(650, 400);
	glVertex2f(700, 448);//ok
	glVertex2f(700, 448);
	glVertex2f(670, 500);
	glVertex2f(665, 500);
	glVertex2f(690, 530);
	glVertex2f(700, 400);
	glVertex2f(660, 450);
	glVertex2f(660, 450);
	glVertex2f(690, 500);
	glVertex2f(690, 500);
	glVertex2f(670, 525);
	glEnd();

}
void scene24(int time) {
	glColor3f(.5, .25, .12);
	glBegin(GL_POLYGON);
	glVertex2f(830, 200);
	glVertex2f(510, 200);
	glVertex2f(510, 400);
	glVertex2f(830, 400);
	glEnd();

	glColor3f(.1, .1, .1);
	glBegin(GL_LINE_LOOP);
	glVertex2f(830, 200);
	glVertex2f(510, 200);
	glVertex2f(510, 400);
	glVertex2f(830, 400);
	glEnd();

	glLineWidth(3.5);
	glColor3f(.1, .1, .1);
	glBegin(GL_LINES);
	glVertex2f(700, 400);
	glVertex2f(690, 530);
	glEnd();

	glLineWidth(3.5);
	glColor3f(.1, .1, .1);
	glBegin(GL_LINES);
	glVertex2f(700, 400);
	glVertex2f(690, 530);
	glVertex2f(650, 400);
	glVertex2f(670, 530);
	glVertex2f(650, 400);
	glVertex2f(700, 448);//ok
	glVertex2f(700, 448);
	glVertex2f(670, 500);
	glVertex2f(665, 500);
	glVertex2f(690, 530);
	glVertex2f(700, 400);
	glVertex2f(660, 450);
	glVertex2f(660, 450);
	glVertex2f(690, 500);
	glVertex2f(690, 500);
	glVertex2f(670, 525);
	glEnd();

	glColor3f(.87, .80, .2);
	glBegin(GL_POLYGON);
	glVertex2f(702, 200);
	glVertex2f(635, 200);
	glVertex2f(635, 240);
	glVertex2f(702, 240);
	glEnd();

	glLineWidth(2);
	glColor3f(.1, .1, .1);
	glBegin(GL_LINE_LOOP);
	glVertex2f(702, 200);
	glVertex2f(635, 200);
	glVertex2f(635, 240);
	glVertex2f(702, 240);
	glEnd();

	///Door cicrle


	glColor3f(.87, .80, .2);
	circle(668, 234, 32);


	///Windows Middle

	///1
	glColor3f(.87, .80, .2);
	glBegin(GL_POLYGON);
	glVertex2f(650, 290);
	glVertex2f(680, 290);
	glVertex2f(680, 310);
	glVertex2f(650, 310);
	glEnd();

	glLineWidth(2);
	glColor3f(.1, .1, .1);
	glBegin(GL_LINE_LOOP);
	glVertex2f(650, 290);
	glVertex2f(680, 290);
	glVertex2f(680, 310);
	glVertex2f(650, 310);
	glEnd();
	//glutPostRedisplay();
}
void scene25() {
	glColor3f(.5, .25, .12);
	glBegin(GL_POLYGON);
	glVertex2f(830, 200);
	glVertex2f(510, 200);
	glVertex2f(510, 400);
	glVertex2f(830, 400);
	glEnd();

	glColor3f(.1, .1, .1);
	glBegin(GL_LINE_LOOP);
	glVertex2f(830, 200);
	glVertex2f(510, 200);
	glVertex2f(510, 400);
	glVertex2f(830, 400);
	glEnd();

	glLineWidth(3.5);
	glColor3f(.1, .1, .1);
	glBegin(GL_LINES);
	glVertex2f(700, 400);
	glVertex2f(690, 530);
	glEnd();

	glLineWidth(3.5);
	glColor3f(.1, .1, .1);
	glBegin(GL_LINES);
	glVertex2f(700, 400);
	glVertex2f(690, 530);
	glVertex2f(650, 400);
	glVertex2f(670, 530);
	glVertex2f(650, 400);
	glVertex2f(700, 448);//ok
	glVertex2f(700, 448);
	glVertex2f(670, 500);
	glVertex2f(665, 500);
	glVertex2f(690, 530);
	glVertex2f(700, 400);
	glVertex2f(660, 450);
	glVertex2f(660, 450);
	glVertex2f(690, 500);
	glVertex2f(690, 500);
	glVertex2f(670, 525);
	glEnd();

	glColor3f(.87, .80, .2);
	glBegin(GL_POLYGON);
	glVertex2f(702, 200);
	glVertex2f(635, 200);
	glVertex2f(635, 240);
	glVertex2f(702, 240);
	glEnd();

	glLineWidth(2);
	glColor3f(.1, .1, .1);
	glBegin(GL_LINE_LOOP);
	glVertex2f(702, 200);
	glVertex2f(635, 200);
	glVertex2f(635, 240);
	glVertex2f(702, 240);
	glEnd();

	///Door cicrle


	glColor3f(.87, .80, .2);
	circle(668, 234, 32);


	///Windows Middle

	///1
	glColor3f(.87, .80, .2);
	glBegin(GL_POLYGON);
	glVertex2f(650, 290);
	glVertex2f(680, 290);
	glVertex2f(680, 310);
	glVertex2f(650, 310);
	glEnd();

	glLineWidth(2);
	glColor3f(.1, .1, .1);
	glBegin(GL_LINE_LOOP);
	glVertex2f(650, 290);
	glVertex2f(680, 290);
	glVertex2f(680, 310);
	glVertex2f(650, 310);
	glEnd();

}
void scene26() {
	glColor3f(.5, .25, .12);
	glBegin(GL_POLYGON);
	glVertex2f(830, 200);
	glVertex2f(510, 200);
	glVertex2f(510, 400);
	glVertex2f(830, 400);
	glEnd();

	glColor3f(.1, .1, .1);
	glBegin(GL_LINE_LOOP);
	glVertex2f(830, 200);
	glVertex2f(510, 200);
	glVertex2f(510, 400);
	glVertex2f(830, 400);
	glEnd();

	glLineWidth(3.5);
	glColor3f(.1, .1, .1);
	glBegin(GL_LINES);
	glVertex2f(700, 400);
	glVertex2f(690, 530);
	glEnd();

	glLineWidth(3.5);
	glColor3f(.1, .1, .1);
	glBegin(GL_LINES);
	glVertex2f(700, 400);
	glVertex2f(690, 530);
	glVertex2f(650, 400);
	glVertex2f(670, 530);
	glVertex2f(650, 400);
	glVertex2f(700, 448);//ok
	glVertex2f(700, 448);
	glVertex2f(670, 500);
	glVertex2f(665, 500);
	glVertex2f(690, 530);
	glVertex2f(700, 400);
	glVertex2f(660, 450);
	glVertex2f(660, 450);
	glVertex2f(690, 500);
	glVertex2f(690, 500);
	glVertex2f(670, 525);
	glEnd();

	glColor3f(.87, .80, .2);
	glBegin(GL_POLYGON);
	glVertex2f(702, 200);
	glVertex2f(635, 200);
	glVertex2f(635, 240);
	glVertex2f(702, 240);
	glEnd();

	glLineWidth(2);
	glColor3f(.1, .1, .1);
	glBegin(GL_LINE_LOOP);
	glVertex2f(702, 200);
	glVertex2f(635, 200);
	glVertex2f(635, 240);
	glVertex2f(702, 240);
	glEnd();

	///Door cicrle

	glColor3f(.87, .80, .2);
	circle(668, 234, 32);


	///Windows Middle

	///1
	glColor3f(.87, .80, .2);
	glBegin(GL_POLYGON);
	glVertex2f(650, 290);
	glVertex2f(680, 290);
	glVertex2f(680, 310);
	glVertex2f(650, 310);
	glEnd();

	glLineWidth(2);
	glColor3f(.1, .1, .1);
	glBegin(GL_LINE_LOOP);
	glVertex2f(650, 290);
	glVertex2f(680, 290);
	glVertex2f(680, 310);
	glVertex2f(650, 310);
	glEnd();

	///2
	glColor3f(.87, .80, .2);
	glBegin(GL_POLYGON);
	glVertex2f(650, 330);
	glVertex2f(680, 330);
	glVertex2f(680, 350);
	glVertex2f(650, 350);
	glEnd();

	glLineWidth(2);
	glColor3f(.1, .1, .1);
	glBegin(GL_LINE_LOOP);
	glVertex2f(650, 330);
	glVertex2f(680, 330);
	glVertex2f(680, 350);
	glVertex2f(650, 350);
	glEnd();

	///3
	glColor3f(.87, .80, .2);
	glBegin(GL_POLYGON);
	glVertex2f(650, 370);
	glVertex2f(680, 370);
	glVertex2f(680, 390);
	glVertex2f(650, 390);
	glEnd();

	glLineWidth(2);
	glColor3f(.1, .1, .1);
	glBegin(GL_LINE_LOOP);
	glVertex2f(650, 370);
	glVertex2f(680, 370);
	glVertex2f(680, 390);
	glVertex2f(650, 390);
	glEnd();

	///WINDOWS Left Near

	//1
	glColor3f(.87, .80, .2);
	glBegin(GL_POLYGON);
	glVertex2f(610, 230);
	glVertex2f(580, 230);
	glVertex2f(580, 250);
	glVertex2f(610, 250);
	glEnd();

	glLineWidth(2);
	glColor3f(.1, .1, .1);
	glBegin(GL_LINE_LOOP);
	glVertex2f(610, 230);
	glVertex2f(580, 230);
	glVertex2f(580, 250);
	glVertex2f(610, 250);
	glEnd();

	//2
	glColor3f(.87, .80, .2);
	glBegin(GL_POLYGON);
	glVertex2f(610, 270);
	glVertex2f(580, 270);
	glVertex2f(580, 290);
	glVertex2f(610, 290);
	glEnd();

	glLineWidth(2);
	glColor3f(.1, .1, .1);
	glBegin(GL_LINE_LOOP);
	glVertex2f(610, 270);
	glVertex2f(580, 270);
	glVertex2f(580, 290);
	glVertex2f(610, 290);
	glEnd();


}
void scene27() {
	glColor3f(.5, .25, .12);
	glBegin(GL_POLYGON);
	glVertex2f(830, 200);
	glVertex2f(510, 200);
	glVertex2f(510, 400);
	glVertex2f(830, 400);
	glEnd();

	glColor3f(.1, .1, .1);
	glBegin(GL_LINE_LOOP);
	glVertex2f(830, 200);
	glVertex2f(510, 200);
	glVertex2f(510, 400);
	glVertex2f(830, 400);
	glEnd();

	glLineWidth(3.5);
	glColor3f(.1, .1, .1);
	glBegin(GL_LINES);
	glVertex2f(700, 400);
	glVertex2f(690, 530);
	glEnd();

	glLineWidth(3.5);
	glColor3f(.1, .1, .1);
	glBegin(GL_LINES);
	glVertex2f(700, 400);
	glVertex2f(690, 530);
	glVertex2f(650, 400);
	glVertex2f(670, 530);
	glVertex2f(650, 400);
	glVertex2f(700, 448);//ok
	glVertex2f(700, 448);
	glVertex2f(670, 500);
	glVertex2f(665, 500);
	glVertex2f(690, 530);
	glVertex2f(700, 400);
	glVertex2f(660, 450);
	glVertex2f(660, 450);
	glVertex2f(690, 500);
	glVertex2f(690, 500);
	glVertex2f(670, 525);
	glEnd();

	glColor3f(.87, .80, .2);
	glBegin(GL_POLYGON);
	glVertex2f(702, 200);
	glVertex2f(635, 200);
	glVertex2f(635, 240);
	glVertex2f(702, 240);
	glEnd();

	glLineWidth(2);
	glColor3f(.1, .1, .1);
	glBegin(GL_LINE_LOOP);
	glVertex2f(702, 200);
	glVertex2f(635, 200);
	glVertex2f(635, 240);
	glVertex2f(702, 240);
	glEnd();

	///Door cicrle


	glColor3f(.87, .80, .2);
	circle(668, 234, 32);


	///Windows Middle

	///1
	glColor3f(.87, .80, .2);
	glBegin(GL_POLYGON);
	glVertex2f(650, 290);
	glVertex2f(680, 290);
	glVertex2f(680, 310);
	glVertex2f(650, 310);
	glEnd();

	glLineWidth(2);
	glColor3f(.1, .1, .1);
	glBegin(GL_LINE_LOOP);
	glVertex2f(650, 290);
	glVertex2f(680, 290);
	glVertex2f(680, 310);
	glVertex2f(650, 310);
	glEnd();

	///2
	glColor3f(.87, .80, .2);
	glBegin(GL_POLYGON);
	glVertex2f(650, 330);
	glVertex2f(680, 330);
	glVertex2f(680, 350);
	glVertex2f(650, 350);
	glEnd();

	glLineWidth(2);
	glColor3f(.1, .1, .1);
	glBegin(GL_LINE_LOOP);
	glVertex2f(650, 330);
	glVertex2f(680, 330);
	glVertex2f(680, 350);
	glVertex2f(650, 350);
	glEnd();

	///3
	glColor3f(.87, .80, .2);
	glBegin(GL_POLYGON);
	glVertex2f(650, 370);
	glVertex2f(680, 370);
	glVertex2f(680, 390);
	glVertex2f(650, 390);
	glEnd();

	glLineWidth(2);
	glColor3f(.1, .1, .1);
	glBegin(GL_LINE_LOOP);
	glVertex2f(650, 370);
	glVertex2f(680, 370);
	glVertex2f(680, 390);
	glVertex2f(650, 390);
	glEnd();

	///WINDOWS Left Near

	//1
	glColor3f(.87, .80, .2);
	glBegin(GL_POLYGON);
	glVertex2f(610, 230);
	glVertex2f(580, 230);
	glVertex2f(580, 250);
	glVertex2f(610, 250);
	glEnd();

	glLineWidth(2);
	glColor3f(.1, .1, .1);
	glBegin(GL_LINE_LOOP);
	glVertex2f(610, 230);
	glVertex2f(580, 230);
	glVertex2f(580, 250);
	glVertex2f(610, 250);
	glEnd();

	//2
	glColor3f(.87, .80, .2);
	glBegin(GL_POLYGON);
	glVertex2f(610, 270);
	glVertex2f(580, 270);
	glVertex2f(580, 290);
	glVertex2f(610, 290);
	glEnd();

	glLineWidth(2);
	glColor3f(.1, .1, .1);
	glBegin(GL_LINE_LOOP);
	glVertex2f(610, 270);
	glVertex2f(580, 270);
	glVertex2f(580, 290);
	glVertex2f(610, 290);
	glEnd();

	//3
	glColor3f(.87, .80, .2);
	glBegin(GL_POLYGON);
	glVertex2f(610, 310);
	glVertex2f(580, 310);
	glVertex2f(580, 330);
	glVertex2f(610, 330);
	glEnd();

	glLineWidth(2);
	glColor3f(.1, .1, .1);
	glBegin(GL_LINE_LOOP);
	glVertex2f(610, 310);
	glVertex2f(580, 310);
	glVertex2f(580, 330);
	glVertex2f(610, 330);
	glEnd();

	//4
	glColor3f(.87, .80, .2);
	glBegin(GL_POLYGON);
	glVertex2f(610, 350);
	glVertex2f(580, 350);
	glVertex2f(580, 370);
	glVertex2f(610, 370);
	glEnd();

	glLineWidth(2);
	glColor3f(.1, .1, .1);
	glBegin(GL_LINE_LOOP);
	glVertex2f(610, 350);
	glVertex2f(580, 350);
	glVertex2f(580, 370);
	glVertex2f(610, 370);
	glEnd();

	///WINDOWS Right Near

	///1
	glColor3f(.87, .80, .2);
	glBegin(GL_POLYGON);
	glVertex2f(760, 230);
	glVertex2f(730, 230);
	glVertex2f(730, 250);
	glVertex2f(760, 250);
	glEnd();

	glLineWidth(2);
	glColor3f(.1, .1, .1);
	glBegin(GL_LINE_LOOP);
	glVertex2f(760, 230);
	glVertex2f(730, 230);
	glVertex2f(730, 250);
	glVertex2f(760, 250);
	glEnd();

	///2
	glColor3f(.87, .80, .2);
	glBegin(GL_POLYGON);
	glVertex2f(760, 270);
	glVertex2f(730, 270);
	glVertex2f(730, 290);
	glVertex2f(760, 290);
	glEnd();

	glLineWidth(2);
	glColor3f(.1, .1, .1);
	glBegin(GL_LINE_LOOP);
	glVertex2f(760, 270);
	glVertex2f(730, 270);
	glVertex2f(730, 290);
	glVertex2f(760, 290);
	glEnd();

	///3
	glColor3f(.87, .80, .2);
	glBegin(GL_POLYGON);
	glVertex2f(760, 310);
	glVertex2f(730, 310);
	glVertex2f(730, 330);
	glVertex2f(760, 330);
	glEnd();

	glLineWidth(2);
	glColor3f(.1, .1, .1);
	glBegin(GL_LINE_LOOP);
	glVertex2f(760, 310);
	glVertex2f(730, 310);
	glVertex2f(730, 330);
	glVertex2f(760, 330);
	glEnd();

	///4
	glColor3f(.87, .80, .2);
	glBegin(GL_POLYGON);
	glVertex2f(760, 350);
	glVertex2f(730, 350);
	glVertex2f(730, 370);
	glVertex2f(760, 370);
	glEnd();

	glLineWidth(2);
	glColor3f(.1, .1, .1);
	glBegin(GL_LINE_LOOP);
	glVertex2f(760, 350);
	glVertex2f(730, 350);
	glVertex2f(730, 370);
	glVertex2f(760, 370);
	glEnd();

	//most right window

	//left window

	/*glColor3f(1.0, 0.0, .2);
	glBegin(GL_POLYGON);
	glVertex2f(873, 370);
	glVertex2f(873, 383);
	glVertex2f(887, 386);
	glVertex2f(887, 372);
	glEnd();*/
}
void scene28() {
	glColor3f(.5, .25, .12);
	glBegin(GL_POLYGON);
	glVertex2f(830, 200);
	glVertex2f(510, 200);
	glVertex2f(510, 400);
	glVertex2f(830, 400);
	glEnd();

	glColor3f(.1, .1, .1);
	glBegin(GL_LINE_LOOP);
	glVertex2f(830, 200);
	glVertex2f(510, 200);
	glVertex2f(510, 400);
	glVertex2f(830, 400);
	glEnd();

	glLineWidth(3.5);
	glColor3f(.1, .1, .1);
	glBegin(GL_LINES);
	glVertex2f(700, 400);
	glVertex2f(690, 530);
	glEnd();

	glLineWidth(3.5);
	glColor3f(.1, .1, .1);
	glBegin(GL_LINES);
	glVertex2f(700, 400);
	glVertex2f(690, 530);
	glVertex2f(650, 400);
	glVertex2f(670, 530);
	glVertex2f(650, 400);
	glVertex2f(700, 448);//ok
	glVertex2f(700, 448);
	glVertex2f(670, 500);
	glVertex2f(665, 500);
	glVertex2f(690, 530);
	glVertex2f(700, 400);
	glVertex2f(660, 450);
	glVertex2f(660, 450);
	glVertex2f(690, 500);
	glVertex2f(690, 500);
	glVertex2f(670, 525);
	glEnd();

	glColor3f(.87, .80, .2);
	glBegin(GL_POLYGON);
	glVertex2f(702, 200);
	glVertex2f(635, 200);
	glVertex2f(635, 240);
	glVertex2f(702, 240);
	glEnd();

	glLineWidth(2);
	glColor3f(.1, .1, .1);
	glBegin(GL_LINE_LOOP);
	glVertex2f(702, 200);
	glVertex2f(635, 200);
	glVertex2f(635, 240);
	glVertex2f(702, 240);
	glEnd();

	///Door cicrle


	glColor3f(.87, .80, .2);
	circle(668, 234, 32);


	///Windows Middle

	///1
	glColor3f(.87, .80, .2);
	glBegin(GL_POLYGON);
	glVertex2f(650, 290);
	glVertex2f(680, 290);
	glVertex2f(680, 310);
	glVertex2f(650, 310);
	glEnd();

	glLineWidth(2);
	glColor3f(.1, .1, .1);
	glBegin(GL_LINE_LOOP);
	glVertex2f(650, 290);
	glVertex2f(680, 290);
	glVertex2f(680, 310);
	glVertex2f(650, 310);
	glEnd();

	///2
	glColor3f(.87, .80, .2);
	glBegin(GL_POLYGON);
	glVertex2f(650, 330);
	glVertex2f(680, 330);
	glVertex2f(680, 350);
	glVertex2f(650, 350);
	glEnd();

	glLineWidth(2);
	glColor3f(.1, .1, .1);
	glBegin(GL_LINE_LOOP);
	glVertex2f(650, 330);
	glVertex2f(680, 330);
	glVertex2f(680, 350);
	glVertex2f(650, 350);
	glEnd();

	///3
	glColor3f(.87, .80, .2);
	glBegin(GL_POLYGON);
	glVertex2f(650, 370);
	glVertex2f(680, 370);
	glVertex2f(680, 390);
	glVertex2f(650, 390);
	glEnd();

	glLineWidth(2);
	glColor3f(.1, .1, .1);
	glBegin(GL_LINE_LOOP);
	glVertex2f(650, 370);
	glVertex2f(680, 370);
	glVertex2f(680, 390);
	glVertex2f(650, 390);
	glEnd();

	///WINDOWS Left Near

	//1
	glColor3f(.87, .80, .2);
	glBegin(GL_POLYGON);
	glVertex2f(610, 230);
	glVertex2f(580, 230);
	glVertex2f(580, 250);
	glVertex2f(610, 250);
	glEnd();

	glLineWidth(2);
	glColor3f(.1, .1, .1);
	glBegin(GL_LINE_LOOP);
	glVertex2f(610, 230);
	glVertex2f(580, 230);
	glVertex2f(580, 250);
	glVertex2f(610, 250);
	glEnd();

	//2
	glColor3f(.87, .80, .2);
	glBegin(GL_POLYGON);
	glVertex2f(610, 270);
	glVertex2f(580, 270);
	glVertex2f(580, 290);
	glVertex2f(610, 290);
	glEnd();

	glLineWidth(2);
	glColor3f(.1, .1, .1);
	glBegin(GL_LINE_LOOP);
	glVertex2f(610, 270);
	glVertex2f(580, 270);
	glVertex2f(580, 290);
	glVertex2f(610, 290);
	glEnd();

	//3
	glColor3f(.87, .80, .2);
	glBegin(GL_POLYGON);
	glVertex2f(610, 310);
	glVertex2f(580, 310);
	glVertex2f(580, 330);
	glVertex2f(610, 330);
	glEnd();

	glLineWidth(2);
	glColor3f(.1, .1, .1);
	glBegin(GL_LINE_LOOP);
	glVertex2f(610, 310);
	glVertex2f(580, 310);
	glVertex2f(580, 330);
	glVertex2f(610, 330);
	glEnd();

	//4
	glColor3f(.87, .80, .2);
	glBegin(GL_POLYGON);
	glVertex2f(610, 350);
	glVertex2f(580, 350);
	glVertex2f(580, 370);
	glVertex2f(610, 370);
	glEnd();

	glLineWidth(2);
	glColor3f(.1, .1, .1);
	glBegin(GL_LINE_LOOP);
	glVertex2f(610, 350);
	glVertex2f(580, 350);
	glVertex2f(580, 370);
	glVertex2f(610, 370);
	glEnd();

	///WINDOWS Right Near

	///1
	glColor3f(.87, .80, .2);
	glBegin(GL_POLYGON);
	glVertex2f(760, 230);
	glVertex2f(730, 230);
	glVertex2f(730, 250);
	glVertex2f(760, 250);
	glEnd();

	glLineWidth(2);
	glColor3f(.1, .1, .1);
	glBegin(GL_LINE_LOOP);
	glVertex2f(760, 230);
	glVertex2f(730, 230);
	glVertex2f(730, 250);
	glVertex2f(760, 250);
	glEnd();

	///2
	glColor3f(.87, .80, .2);
	glBegin(GL_POLYGON);
	glVertex2f(760, 270);
	glVertex2f(730, 270);
	glVertex2f(730, 290);
	glVertex2f(760, 290);
	glEnd();

	glLineWidth(2);
	glColor3f(.1, .1, .1);
	glBegin(GL_LINE_LOOP);
	glVertex2f(760, 270);
	glVertex2f(730, 270);
	glVertex2f(730, 290);
	glVertex2f(760, 290);
	glEnd();

	///3
	glColor3f(.87, .80, .2);
	glBegin(GL_POLYGON);
	glVertex2f(760, 310);
	glVertex2f(730, 310);
	glVertex2f(730, 330);
	glVertex2f(760, 330);
	glEnd();

	glLineWidth(2);
	glColor3f(.1, .1, .1);
	glBegin(GL_LINE_LOOP);
	glVertex2f(760, 310);
	glVertex2f(730, 310);
	glVertex2f(730, 330);
	glVertex2f(760, 330);
	glEnd();

	///4
	glColor3f(.87, .80, .2);
	glBegin(GL_POLYGON);
	glVertex2f(760, 350);
	glVertex2f(730, 350);
	glVertex2f(730, 370);
	glVertex2f(760, 370);
	glEnd();

	glLineWidth(2);
	glColor3f(.1, .1, .1);
	glBegin(GL_LINE_LOOP);
	glVertex2f(760, 350);
	glVertex2f(730, 350);
	glVertex2f(730, 370);
	glVertex2f(760, 370);
	glEnd();
	//most right window
	//left window
	glColor3f(1.0, 0.0, .2);
	glBegin(GL_POLYGON);
	glVertex2f(873, 370);
	glVertex2f(873, 383);
	glVertex2f(887, 386);
	glVertex2f(887, 372);
	glEnd();
	glLineWidth(3.5);
	glColor3f(.1, .1, .1);
	glBegin(GL_LINES);
	glVertex2f(700, 400);
	glVertex2f(690, 530);
	glVertex2f(650, 400);
	glVertex2f(670, 530);
	glVertex2f(650, 400);
	glVertex2f(700, 448);//ok
	glVertex2f(700, 448);
	glVertex2f(670, 500);
	glVertex2f(665, 500);
	glVertex2f(690, 530);
	glVertex2f(700, 400);
	glVertex2f(660, 450);
	glVertex2f(660, 450);
	glVertex2f(690, 500);
	glVertex2f(690, 500);
	glVertex2f(670, 525);
	glEnd();
}
void scene29() {
	glColor3f(.85, .85, .85);
	glBegin(GL_POLYGON);
	glVertex2f(0, 450);
	glVertex2f(0, 700);
	glVertex2f(1100, 700);
	glVertex2f(1100, 450);
	glEnd();

	//sun


	glColor3f(.970, 0.3, .2);
	circle(700, 625, 35);


	if (m < 300)
	{
		//cloud 1


		glColor3f(1.0, 1.0, 1.0);
		circle(160 + m, 625, 20);



		glColor3f(1.0, 1.0, 1.0);
		circle(200 + m, 625, 35);
		circle(225 + m, 625, 35);



		glColor3f(1.0, 1.0, 1.0);
		circle(265 + m, 625, 20);


		//cloud2

		glColor3f(1.0, 1.0, 1.0);
		circle(370 + m, 615, 20);



		glColor3f(1.0, 1.0, 1.0);
		circle(410 + m, 615, 35);
		circle(435 + m, 615, 35);
		circle(470 + m, 615, 35);


		glColor3f(1.0, 1.0, 1.0);
		circle(500 + m, 615, 20);

		m = m + 0.1;
	}

	else
	{
		m = 0;
		//cloud 1

		glColor3f(1.0, 1.0, 1.0);
		circle(160 + m, 625, 20);


		glColor3f(1.0, 1.0, 1.0);
		circle(200 + m, 625, 35);
		circle(225 + m, 625, 35);


		glColor3f(1.0, 1.0, 1.0);
		circle(265 + m, 625, 20);


		//cloud2


		glColor3f(1.0, 1.0, 1.0);
		circle(370 + m, 615, 20);



		glColor3f(1.0, 1.0, 1.0);
		circle(410 + m, 615, 35);
		circle(435 + m, 615, 35);
		circle(470 + m, 615, 35);



		glColor3f(1.0, 1.0, 1.0);
		circle(500 + m, 615, 20);


		m = m + 0.1;

	}

	//grass

	glColor3f(.45, .45, 0.45);
	glBegin(GL_POLYGON);
	glVertex2f(0, 140);
	glVertex2f(0, 450);
	glVertex2f(1100, 450);
	glVertex2f(1100, 140);
	glEnd();

	/* //mountain cicrle 1
	+
	for (l = 0; l <= 100; l++)
	{
		glColor3f(0.6, 0.2, 0.0);
		draw_circle(210 , 370, l);
	}

	///mountain circle 2

	for (l = 0; l <= 100; l++)
	{
		glColor3f(0.6, 0.2, 0.0);
		draw_circle(260, 380, l);
	}

	///mountaincircle 2

	for (l = 0; l <= 100; l++)
	{
		glColor3f(0.6, 0.2, 0.0);
		draw_circle(280 , 400, l);
	}

	///mountain circle 3

	for (l = 0; l <= 180; l++)
	{
		glColor3f(0.6, 0.2, 0.0);
		draw_circle(380 , 280, l);
	} */

	///grass

	glColor3f(.45, .45, 0.45);
	glBegin(GL_POLYGON);
	glVertex2f(0, 100);
	glVertex2f(0, 450);
	glVertex2f(1100, 450);
	glVertex2f(1100, 100);
	glEnd();

	///ROAD

	glColor3f(0.20, 0.20, .20);
	glBegin(GL_POLYGON);
	glVertex2f(1100, 0);
	glVertex2f(0, 0);
	glVertex2f(0, 160);
	glVertex2f(1100, 160);
	glEnd();

	///devider

	glColor3f(1, 1, 1);
	glBegin(GL_POLYGON);
	glVertex2f(950, 40);
	glVertex2f(730, 40);
	glVertex2f(730, 60);
	glVertex2f(950, 60);
	glEnd();

	glColor3f(1, 1, 1);
	glBegin(GL_POLYGON);
	glVertex2f(580, 40);
	glVertex2f(340, 40);
	glVertex2f(340, 60);
	glVertex2f(580, 60);
	glEnd();

	glColor3f(1, 1, 1);
	glBegin(GL_POLYGON);
	glVertex2f(210, 40);
	glVertex2f(40, 40);
	glVertex2f(40, 60);
	glVertex2f(210, 60);
	glEnd();

	///building1 Dark_pink

	glColor3f(.48, .16, .20);
	glBegin(GL_POLYGON);
	glVertex2f(1000, 200);
	glVertex2f(800, 200);
	glVertex2f(800, 500);
	glVertex2f(1000, 500);
	glEnd();

	glColor3f(.1, .1, .1);
	glBegin(GL_LINE_LOOP);
	glVertex2f(1000, 200);
	glVertex2f(800, 200);
	glVertex2f(800, 500);
	glVertex2f(1000, 500);
	glEnd();

	///Antena

	glLineWidth(2);
	glColor3f(.1, .1, .1);
	glBegin(GL_LINES);
	glVertex2f(865, 500);
	glVertex2f(865, 600);
	glEnd();

	glBegin(GL_LINES);
	glVertex2f(850, 530.33);
	glVertex2f(880, 530.33);
	glEnd();

	glBegin(GL_LINES);
	glVertex2f(853, 545.33);
	glVertex2f(877, 545.33);
	glEnd();

	glBegin(GL_LINES);
	glVertex2f(856, 560.33);
	glVertex2f(874, 560.33);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(859, 575.33);
	glVertex2f(871, 575.33);
	glEnd();

	///Door

	glColor3f(1.0, 1.0, .0);
	glBegin(GL_POLYGON);
	glVertex2f(983, 200);
	glVertex2f(963, 200);
	glVertex2f(963, 242);
	glVertex2f(983, 242);
	glEnd();

	glColor3f(.1, .1, .1);
	glBegin(GL_LINE_LOOP);
	glVertex2f(983, 200);
	glVertex2f(963, 200);
	glVertex2f(963, 242);
	glVertex2f(983, 242);
	glEnd();

	///windows Right

	//1
	glColor3f(1.0, 1., .0);
	glBegin(GL_POLYGON);
	glVertex2f(983, 262);
	glVertex2f(963, 262);
	glVertex2f(963, 282);
	glVertex2f(983, 282);
	glEnd();

	glColor3f(.1, .1, .1);
	glBegin(GL_LINE_LOOP);
	glVertex2f(983, 262);
	glVertex2f(963, 262);
	glVertex2f(963, 282);
	glVertex2f(983, 282);
	glEnd();

	//2
	glColor3f(1.0, 1., .0);
	glBegin(GL_POLYGON);
	glVertex2f(983, 302);
	glVertex2f(963, 302);
	glVertex2f(963, 322);
	glVertex2f(983, 322);
	glEnd();

	//3
	glColor3f(1.0, 1., .0);
	glBegin(GL_POLYGON);
	glVertex2f(983, 342);
	glVertex2f(963, 342);
	glVertex2f(963, 362);
	glVertex2f(983, 362);
	glEnd();

	//4
	glColor3f(1.0, 1., .0);
	glBegin(GL_POLYGON);
	glVertex2f(983, 382);
	glVertex2f(963, 382);
	glVertex2f(963, 402);
	glVertex2f(983, 402);
	glEnd();

	//5
	glColor3f(1.0, 1., .0);
	glBegin(GL_POLYGON);
	glVertex2f(983, 422);
	glVertex2f(963, 422);
	glVertex2f(963, 442);
	glVertex2f(983, 442);
	glEnd();

	///windows Middle

	//1
	glColor3f(1.0, 1., .0);
	glBegin(GL_POLYGON);
	glVertex2f(940, 222);
	glVertex2f(900, 222);
	glVertex2f(900, 242);
	glVertex2f(940, 242);
	glEnd();

	//2
	glColor3f(1.0, 1., .0);
	glBegin(GL_POLYGON);
	glVertex2f(940, 262);
	glVertex2f(900, 262);
	glVertex2f(900, 282);
	glVertex2f(940, 282);
	glEnd();

	//3
	glColor3f(1.0, 1., .0);
	glBegin(GL_POLYGON);
	glVertex2f(940, 302);
	glVertex2f(900, 302);
	glVertex2f(900, 322);
	glVertex2f(940, 322);
	glEnd();

	//4
	glColor3f(1.0, 1., .0);
	glBegin(GL_POLYGON);
	glVertex2f(940, 342);
	glVertex2f(900, 342);
	glVertex2f(900, 362);
	glVertex2f(940, 362);
	glEnd();

	//5
	glColor3f(1.0, 1., .0);
	glBegin(GL_POLYGON);
	glVertex2f(940, 382);
	glVertex2f(900, 382);
	glVertex2f(900, 402);
	glVertex2f(940, 402);
	glEnd();

	//5
	glColor3f(1.0, 1., .0);
	glBegin(GL_POLYGON);
	glVertex2f(940, 422);
	glVertex2f(900, 422);
	glVertex2f(900, 442);
	glVertex2f(940, 442);
	glEnd();

	///window Left

	//1
	glColor3f(1.0, 1., .0);
	glBegin(GL_POLYGON);
	glVertex2f(870, 222);
	glVertex2f(830, 222);
	glVertex2f(830, 242);
	glVertex2f(870, 242);
	glEnd();

	//2
	glColor3f(1.0, 1., .0);
	glBegin(GL_POLYGON);
	glVertex2f(870, 262);
	glVertex2f(830, 262);
	glVertex2f(830, 282);
	glVertex2f(870, 282);
	glEnd();

	//3
	glColor3f(1.0, 1., .0);
	glBegin(GL_POLYGON);
	glVertex2f(870, 302);
	glVertex2f(830, 302);
	glVertex2f(830, 322);
	glVertex2f(870, 322);
	glEnd();

	//4
	glColor3f(1.0, 1., .0);
	glBegin(GL_POLYGON);
	glVertex2f(870, 342);
	glVertex2f(830, 342);
	glVertex2f(830, 362);
	glVertex2f(870, 362);
	glEnd();

	//5
	glColor3f(1.0, 1., .0);
	glBegin(GL_POLYGON);
	glVertex2f(870, 382);
	glVertex2f(830, 382);
	glVertex2f(830, 402);
	glVertex2f(870, 402);
	glEnd();

	//6
	glColor3f(1.0, 1., .0);
	glBegin(GL_POLYGON);
	glVertex2f(870, 422);
	glVertex2f(830, 422);
	glVertex2f(830, 442);
	glVertex2f(870, 442);
	glEnd();

	///building2 Brown

	glColor3f(.5, .25, .12);
	glBegin(GL_POLYGON);
	glVertex2f(830, 200);
	glVertex2f(510, 200);
	glVertex2f(510, 400);
	glVertex2f(830, 400);
	glEnd();

	glColor3f(.1, .1, .1);
	glBegin(GL_LINE_LOOP);
	glVertex2f(830, 200);
	glVertex2f(510, 200);
	glVertex2f(510, 400);
	glVertex2f(830, 400);
	glEnd();

	///TOWER

	glLineWidth(3.5);
	glColor3f(.1, .1, .1);
	glBegin(GL_LINES);
	glVertex2f(700, 400);
	glVertex2f(690, 530);
	glVertex2f(650, 400);
	glVertex2f(670, 530);
	glVertex2f(650, 400);
	glVertex2f(700, 448);//ok
	glVertex2f(700, 448);
	glVertex2f(670, 500);
	glVertex2f(665, 500);
	glVertex2f(690, 530);
	glVertex2f(700, 400);
	glVertex2f(660, 450);
	glVertex2f(660, 450);
	glVertex2f(690, 500);
	glVertex2f(690, 500);
	glVertex2f(670, 525);
	glEnd();

	///DOOR

	glColor3f(.87, .80, .2);
	glBegin(GL_POLYGON);
	glVertex2f(702, 200);
	glVertex2f(635, 200);
	glVertex2f(635, 240);
	glVertex2f(702, 240);
	glEnd();

	glLineWidth(2);
	glColor3f(.1, .1, .1);
	glBegin(GL_LINE_LOOP);
	glVertex2f(702, 200);
	glVertex2f(635, 200);
	glVertex2f(635, 240);
	glVertex2f(702, 240);
	glEnd();

	///Door cicrle


	glColor3f(.87, .80, .2);
	circle(668, 234, 32);


	///Windows Middle

	///1
	glColor3f(.87, .80, .2);
	glBegin(GL_POLYGON);
	glVertex2f(650, 290);
	glVertex2f(680, 290);
	glVertex2f(680, 310);
	glVertex2f(650, 310);
	glEnd();

	glLineWidth(2);
	glColor3f(.1, .1, .1);
	glBegin(GL_LINE_LOOP);
	glVertex2f(650, 290);
	glVertex2f(680, 290);
	glVertex2f(680, 310);
	glVertex2f(650, 310);
	glEnd();

	///2
	glColor3f(.87, .80, .2);
	glBegin(GL_POLYGON);
	glVertex2f(650, 330);
	glVertex2f(680, 330);
	glVertex2f(680, 350);
	glVertex2f(650, 350);
	glEnd();

	glLineWidth(2);
	glColor3f(.1, .1, .1);
	glBegin(GL_LINE_LOOP);
	glVertex2f(650, 330);
	glVertex2f(680, 330);
	glVertex2f(680, 350);
	glVertex2f(650, 350);
	glEnd();

	///3
	glColor3f(.87, .80, .2);
	glBegin(GL_POLYGON);
	glVertex2f(650, 370);
	glVertex2f(680, 370);
	glVertex2f(680, 390);
	glVertex2f(650, 390);
	glEnd();

	glLineWidth(2);
	glColor3f(.1, .1, .1);
	glBegin(GL_LINE_LOOP);
	glVertex2f(650, 370);
	glVertex2f(680, 370);
	glVertex2f(680, 390);
	glVertex2f(650, 390);
	glEnd();

	///WINDOWS Left Near

	//1
	glColor3f(.87, .80, .2);
	glBegin(GL_POLYGON);
	glVertex2f(610, 230);
	glVertex2f(580, 230);
	glVertex2f(580, 250);
	glVertex2f(610, 250);
	glEnd();

	glLineWidth(2);
	glColor3f(.1, .1, .1);
	glBegin(GL_LINE_LOOP);
	glVertex2f(610, 230);
	glVertex2f(580, 230);
	glVertex2f(580, 250);
	glVertex2f(610, 250);
	glEnd();

	//2
	glColor3f(.87, .80, .2);
	glBegin(GL_POLYGON);
	glVertex2f(610, 270);
	glVertex2f(580, 270);
	glVertex2f(580, 290);
	glVertex2f(610, 290);
	glEnd();

	glLineWidth(2);
	glColor3f(.1, .1, .1);
	glBegin(GL_LINE_LOOP);
	glVertex2f(610, 270);
	glVertex2f(580, 270);
	glVertex2f(580, 290);
	glVertex2f(610, 290);
	glEnd();

	//3
	glColor3f(.87, .80, .2);
	glBegin(GL_POLYGON);
	glVertex2f(610, 310);
	glVertex2f(580, 310);
	glVertex2f(580, 330);
	glVertex2f(610, 330);
	glEnd();

	glLineWidth(2);
	glColor3f(.1, .1, .1);
	glBegin(GL_LINE_LOOP);
	glVertex2f(610, 310);
	glVertex2f(580, 310);
	glVertex2f(580, 330);
	glVertex2f(610, 330);
	glEnd();

	//4
	glColor3f(.87, .80, .2);
	glBegin(GL_POLYGON);
	glVertex2f(610, 350);
	glVertex2f(580, 350);
	glVertex2f(580, 370);
	glVertex2f(610, 370);
	glEnd();

	glLineWidth(2);
	glColor3f(.1, .1, .1);
	glBegin(GL_LINE_LOOP);
	glVertex2f(610, 350);
	glVertex2f(580, 350);
	glVertex2f(580, 370);
	glVertex2f(610, 370);
	glEnd();

	///WINDOWS Right Near

	///1
	glColor3f(.87, .80, .2);
	glBegin(GL_POLYGON);
	glVertex2f(760, 230);
	glVertex2f(730, 230);
	glVertex2f(730, 250);
	glVertex2f(760, 250);
	glEnd();

	glLineWidth(2);
	glColor3f(.1, .1, .1);
	glBegin(GL_LINE_LOOP);
	glVertex2f(760, 230);
	glVertex2f(730, 230);
	glVertex2f(730, 250);
	glVertex2f(760, 250);
	glEnd();

	///2
	glColor3f(.87, .80, .2);
	glBegin(GL_POLYGON);
	glVertex2f(760, 270);
	glVertex2f(730, 270);
	glVertex2f(730, 290);
	glVertex2f(760, 290);
	glEnd();

	glLineWidth(2);
	glColor3f(.1, .1, .1);
	glBegin(GL_LINE_LOOP);
	glVertex2f(760, 270);
	glVertex2f(730, 270);
	glVertex2f(730, 290);
	glVertex2f(760, 290);
	glEnd();

	///3
	glColor3f(.87, .80, .2);
	glBegin(GL_POLYGON);
	glVertex2f(760, 310);
	glVertex2f(730, 310);
	glVertex2f(730, 330);
	glVertex2f(760, 330);
	glEnd();

	glLineWidth(2);
	glColor3f(.1, .1, .1);
	glBegin(GL_LINE_LOOP);
	glVertex2f(760, 310);
	glVertex2f(730, 310);
	glVertex2f(730, 330);
	glVertex2f(760, 330);
	glEnd();

	///4

	glColor3f(.87, .80, .2);
	glBegin(GL_POLYGON);
	glVertex2f(760, 350);
	glVertex2f(730, 350);
	glVertex2f(730, 370);
	glVertex2f(760, 370);
	glEnd();

	glLineWidth(2);
	glColor3f(.1, .1, .1);
	glBegin(GL_LINE_LOOP);
	glVertex2f(760, 350);
	glVertex2f(730, 350);
	glVertex2f(730, 370);
	glVertex2f(760, 370);
	glEnd();

	///Building3 skyblue

	glColor3f(.8, .8, 1.0);
	glBegin(GL_POLYGON);
	glVertex2f(510, 200);
	glVertex2f(460, 200);
	glVertex2f(460, 530);
	glVertex2f(510, 530);
	glEnd();

	glColor3f(.8, .8, 1.0);
	glBegin(GL_POLYGON);
	glVertex2f(580, 400);
	glVertex2f(510, 400);
	glVertex2f(510, 530);
	glVertex2f(580, 530);
	glEnd();

	glLineWidth(2);
	glColor3f(.1, .1, .1);
	glBegin(GL_LINE_LOOP);
	glVertex2f(510, 200);
	glVertex2f(460, 200);
	glVertex2f(460, 530);
	glVertex2f(580, 530);
	glVertex2f(580, 400);
	glVertex2f(510, 400);
	glEnd();

	///DOOR

	glColor3f(.87, .80, .2);
	glBegin(GL_POLYGON);
	glVertex2f(490, 200);
	glVertex2f(480, 200);
	glVertex2f(480, 240);
	glVertex2f(490, 240);
	glEnd();

	glLineWidth(2);
	glColor3f(.1, .1, .1);
	glBegin(GL_LINE_LOOP);
	glVertex2f(490, 200);
	glVertex2f(480, 200);
	glVertex2f(480, 240);
	glVertex2f(490, 240);
	glEnd();

	///Windows

	//1
	glColor3f(.87, .80, .2);
	glBegin(GL_POLYGON);
	glVertex2f(490, 250);
	glVertex2f(480, 250);
	glVertex2f(480, 260);
	glVertex2f(490, 260);
	glEnd();

	glLineWidth(2);
	glColor3f(.1, .1, .1);
	glBegin(GL_LINE_LOOP);
	glVertex2f(490, 250);
	glVertex2f(480, 250);
	glVertex2f(480, 260);
	glVertex2f(490, 260);
	glEnd();

	///2
	glColor3f(.87, .80, .2);
	glBegin(GL_POLYGON);
	glVertex2f(490, 280);
	glVertex2f(480, 280);
	glVertex2f(480, 290);
	glVertex2f(490, 290);
	glEnd();

	glLineWidth(2);
	glColor3f(.1, .1, .1);
	glBegin(GL_LINE_LOOP);
	glVertex2f(490, 280);
	glVertex2f(480, 280);
	glVertex2f(480, 290);
	glVertex2f(490, 290);
	glEnd();

	///3
	glColor3f(.87, .80, .2);
	glBegin(GL_POLYGON);
	glVertex2f(490, 300);
	glVertex2f(480, 300);
	glVertex2f(480, 310);
	glVertex2f(490, 310);
	glEnd();

	glLineWidth(2);
	glColor3f(.1, .1, .1);
	glBegin(GL_LINE_LOOP);
	glVertex2f(490, 300);
	glVertex2f(480, 300);
	glVertex2f(480, 310);
	glVertex2f(490, 310);
	glEnd();

	///4
	glColor3f(.87, .80, .2);
	glBegin(GL_POLYGON);
	glVertex2f(490, 320);
	glVertex2f(480, 320);
	glVertex2f(480, 330);
	glVertex2f(490, 330);
	glEnd();

	glLineWidth(2);
	glColor3f(.1, .1, .1);
	glBegin(GL_LINE_LOOP);
	glVertex2f(490, 320);
	glVertex2f(480, 320);
	glVertex2f(480, 330);
	glVertex2f(490, 330);
	glEnd();

	///5
	glColor3f(.87, .80, .2);
	glBegin(GL_POLYGON);
	glVertex2f(490, 340);
	glVertex2f(480, 340);
	glVertex2f(480, 350);
	glVertex2f(490, 350);
	glEnd();

	glLineWidth(2);
	glColor3f(.1, .1, .1);
	glBegin(GL_LINE_LOOP);
	glVertex2f(490, 340);
	glVertex2f(480, 340);
	glVertex2f(480, 350);
	glVertex2f(490, 350);
	glEnd();

	///6
	glColor3f(.87, .80, .2);
	glBegin(GL_POLYGON);
	glVertex2f(490, 360);
	glVertex2f(480, 360);
	glVertex2f(480, 370);
	glVertex2f(490, 370);
	glEnd();

	glLineWidth(2);
	glColor3f(.1, .1, .1);
	glBegin(GL_LINE_LOOP);
	glVertex2f(490, 360);
	glVertex2f(480, 360);
	glVertex2f(480, 370);
	glVertex2f(490, 370);
	glEnd();

	///7
	glColor3f(.87, .80, .2);
	glBegin(GL_POLYGON);
	glVertex2f(490, 380);
	glVertex2f(480, 380);
	glVertex2f(480, 390);
	glVertex2f(490, 390);
	glEnd();

	glLineWidth(2);
	glColor3f(.1, .1, .1);
	glBegin(GL_LINE_LOOP);
	glVertex2f(490, 380);
	glVertex2f(480, 380);
	glVertex2f(480, 390);
	glVertex2f(490, 390);
	glEnd();

	///8
	glColor3f(.87, .80, .2);
	glBegin(GL_POLYGON);
	glVertex2f(490, 400);
	glVertex2f(480, 400);
	glVertex2f(480, 410);
	glVertex2f(490, 410);
	glEnd();

	glLineWidth(2);
	glColor3f(.1, .1, .1);
	glBegin(GL_LINE_LOOP);
	glVertex2f(490, 400);
	glVertex2f(480, 400);
	glVertex2f(480, 410);
	glVertex2f(490, 410);
	glEnd();

	///9
	glColor3f(.87, .80, .2);
	glBegin(GL_POLYGON);
	glVertex2f(490, 420);
	glVertex2f(480, 420);
	glVertex2f(480, 430);
	glVertex2f(490, 430);
	glEnd();

	glLineWidth(2);
	glColor3f(.1, .1, .1);
	glBegin(GL_LINE_LOOP);
	glVertex2f(490, 420);
	glVertex2f(480, 420);
	glVertex2f(480, 430);
	glVertex2f(490, 430);
	glEnd();

	///10
	glColor3f(.87, .80, .2);
	glBegin(GL_POLYGON);
	glVertex2f(490, 440);
	glVertex2f(480, 440);
	glVertex2f(480, 450);
	glVertex2f(490, 450);
	glEnd();

	glLineWidth(2);
	glColor3f(.1, .1, .1);
	glBegin(GL_LINE_LOOP);
	glVertex2f(490, 440);
	glVertex2f(480, 440);
	glVertex2f(480, 450);
	glVertex2f(490, 450);
	glEnd();

	///11
	glColor3f(.87, .80, .2);
	glBegin(GL_POLYGON);
	glVertex2f(490, 460);
	glVertex2f(480, 460);
	glVertex2f(480, 470);
	glVertex2f(490, 470);
	glEnd();

	glLineWidth(2);
	glColor3f(.1, .1, .1);
	glBegin(GL_LINE_LOOP);
	glVertex2f(490, 460);
	glVertex2f(480, 460);
	glVertex2f(480, 470);
	glVertex2f(490, 470);
	glEnd();

	///12
	glColor3f(.87, .80, .2);
	glBegin(GL_POLYGON);
	glVertex2f(490, 480);
	glVertex2f(480, 480);
	glVertex2f(480, 490);
	glVertex2f(490, 490);
	glEnd();

	glLineWidth(2);
	glColor3f(.1, .1, .1);
	glBegin(GL_LINE_LOOP);
	glVertex2f(490, 480);
	glVertex2f(480, 480);
	glVertex2f(480, 490);
	glVertex2f(490, 490);
	glEnd();

	///13
	glColor3f(.87, .80, .2);
	glBegin(GL_POLYGON);
	glVertex2f(490, 500);
	glVertex2f(480, 500);
	glVertex2f(480, 510);
	glVertex2f(490, 510);
	glEnd();

	glLineWidth(2);
	glColor3f(.1, .1, .1);
	glBegin(GL_LINE_LOOP);
	glVertex2f(490, 500);
	glVertex2f(480, 500);
	glVertex2f(480, 510);
	glVertex2f(490, 510);
	glEnd();

	///Windows Middle

	///1
	glColor3f(.87, .80, .2);
	glBegin(GL_POLYGON);
	glVertex2f(550, 410);
	glVertex2f(530, 410);
	glVertex2f(530, 430);
	glVertex2f(550, 430);
	glEnd();

	glLineWidth(2);
	glColor3f(.1, .1, .1);
	glBegin(GL_LINE_LOOP);
	glVertex2f(550, 410);
	glVertex2f(530, 410);
	glVertex2f(530, 430);
	glVertex2f(550, 430);
	glEnd();

	///2
	glColor3f(.87, .80, .2);
	glBegin(GL_POLYGON);
	glVertex2f(550, 450);
	glVertex2f(530, 450);
	glVertex2f(530, 470);
	glVertex2f(550, 470);
	glEnd();

	glLineWidth(2);
	glColor3f(.1, .1, .1);
	glBegin(GL_LINE_LOOP);
	glVertex2f(550, 450);
	glVertex2f(530, 450);
	glVertex2f(530, 470);
	glVertex2f(550, 470);
	glEnd();

	///3
	glColor3f(.87, .80, .2);
	glBegin(GL_POLYGON);
	glVertex2f(550, 490);
	glVertex2f(530, 490);
	glVertex2f(530, 510);
	glVertex2f(550, 510);
	glEnd();

	glLineWidth(2);
	glColor3f(.1, .1, .1);
	glBegin(GL_LINE_LOOP);
	glVertex2f(550, 490);
	glVertex2f(530, 490);
	glVertex2f(530, 510);
	glVertex2f(550, 510);
	glEnd();

	///Building4

	glColor3f(.67, .97, .50);
	glBegin(GL_POLYGON);
	glVertex2f(450, 200);
	glVertex2f(330, 200);
	glVertex2f(330, 400);
	glVertex2f(450, 400);
	glEnd();

	glLineWidth(2);
	glColor3f(.1, .1, .1);
	glBegin(GL_LINE_LOOP);
	glVertex2f(450, 200);
	glVertex2f(330, 200);
	glVertex2f(330, 400);
	glVertex2f(450, 400);
	glEnd();

	///DOOr

	glColor3f(.67, .67, .0);
	glBegin(GL_POLYGON);
	glVertex2f(440, 200);
	glVertex2f(420, 200);
	glVertex2f(420, 250);
	glVertex2f(440, 250);
	glEnd();

	glLineWidth(2);
	glColor3f(.1, .1, .1);
	glBegin(GL_LINE_LOOP);
	glVertex2f(440, 200);
	glVertex2f(420, 200);
	glVertex2f(420, 250);
	glVertex2f(440, 250);
	glEnd();

	///windows

	glColor3f(.67, .67, .0);
	glBegin(GL_POLYGON);
	glVertex2f(440, 270);
	glVertex2f(400, 270);
	glVertex2f(400, 285);
	glVertex2f(440, 285);
	glEnd();

	glLineWidth(2);
	glColor3f(.1, .1, .1);
	glBegin(GL_LINE_LOOP);
	glVertex2f(440, 270);
	glVertex2f(400, 270);
	glVertex2f(400, 285);
	glVertex2f(440, 285);
	glEnd();

	///2
	glColor3f(.67, .67, .0);
	glBegin(GL_POLYGON);
	glVertex2f(440, 305);
	glVertex2f(400, 305);
	glVertex2f(400, 320);
	glVertex2f(440, 320);
	glEnd();

	glColor3f(.1, .1, .1);
	glBegin(GL_LINE_LOOP);
	glVertex2f(440, 305);
	glVertex2f(400, 305);
	glVertex2f(400, 320);
	glVertex2f(440, 320);
	glEnd();

	///3
	glColor3f(.67, .67, .0);
	glBegin(GL_POLYGON);
	glVertex2f(440, 340);
	glVertex2f(400, 340);
	glVertex2f(400, 355);
	glVertex2f(440, 355);
	glEnd();

	glColor3f(.1, .1, .1);
	glBegin(GL_LINE_LOOP);
	glVertex2f(440, 340);
	glVertex2f(400, 340);
	glVertex2f(400, 355);
	glVertex2f(440, 355);
	glEnd();

	///4
	glColor3f(.67, .67, .0);
	glBegin(GL_POLYGON);
	glVertex2f(440, 375);
	glVertex2f(400, 375);
	glVertex2f(400, 390);
	glVertex2f(440, 390);
	glEnd();

	glColor3f(.1, .1, .1);
	glBegin(GL_LINE_LOOP);
	glVertex2f(440, 375);
	glVertex2f(400, 375);
	glVertex2f(400, 390);
	glVertex2f(440, 390);
	glEnd();

	///Windows left

	///1

	glColor3f(.67, .67, .0);
	glBegin(GL_POLYGON);
	glVertex2f(350, 235);
	glVertex2f(370, 235);
	glVertex2f(370, 250);
	glVertex2f(350, 250);
	glEnd();

	glColor3f(.1, .1, .1);
	glBegin(GL_LINE_LOOP);
	glVertex2f(350, 235);
	glVertex2f(370, 235);
	glVertex2f(370, 250);
	glVertex2f(350, 250);
	glEnd();

	///2

	glColor3f(.67, .67, .0);
	glBegin(GL_POLYGON);
	glVertex2f(350, 270);
	glVertex2f(370, 270);
	glVertex2f(370, 285);
	glVertex2f(350, 285);
	glEnd();

	glColor3f(.1, .1, .1);
	glBegin(GL_LINE_LOOP);
	glVertex2f(350, 270);
	glVertex2f(370, 270);
	glVertex2f(370, 285);
	glVertex2f(350, 285);
	glEnd();

	///3

	glColor3f(.67, .67, .0);
	glBegin(GL_POLYGON);
	glVertex2f(350, 305);
	glVertex2f(370, 305);
	glVertex2f(370, 320);
	glVertex2f(350, 320);
	glEnd();

	glColor3f(.1, .1, .1);
	glBegin(GL_LINE_LOOP);
	glVertex2f(350, 305);
	glVertex2f(370, 305);
	glVertex2f(370, 320);
	glVertex2f(350, 320);
	glEnd();

	///4

	glColor3f(.67, .67, .0);
	glBegin(GL_POLYGON);
	glVertex2f(350, 340);
	glVertex2f(370, 340);
	glVertex2f(370, 355);
	glVertex2f(350, 355);
	glEnd();

	glColor3f(.1, .1, .1);
	glBegin(GL_LINE_LOOP);
	glVertex2f(350, 340);
	glVertex2f(370, 340);
	glVertex2f(370, 355);
	glVertex2f(350, 355);
	glEnd();

	///5
	glColor3f(.67, .67, .0);
	glBegin(GL_POLYGON);
	glVertex2f(350, 375);
	glVertex2f(370, 375);
	glVertex2f(370, 390);
	glVertex2f(350, 390);
	glEnd();

	glColor3f(.1, .1, .1);
	glBegin(GL_LINE_LOOP);
	glVertex2f(350, 375);
	glVertex2f(370, 375);
	glVertex2f(370, 390);
	glVertex2f(350, 390);
	glEnd();

	if (i < 750)
	{
		//bus

		glColor3f(0.7, 0.0, 0.9);
		glBegin(GL_POLYGON);
		glVertex2f(350 + i, 50);
		glVertex2f(350 + i, 210);
		glVertex2f(722 + i, 210);
		glVertex2f(750 + i, 150);
		glVertex2f(750 + i, 50);
		glEnd();

		glColor3f(1.0, 1.0, 1.0);
		glBegin(GL_POLYGON);
		glVertex2f(650 + i, 150);
		glVertex2f(650 + i, 200);
		glVertex2f(720 + i, 200);
		glVertex2f(745 + i, 150);
		glEnd();

		glColor3f(1.0, 1.0, 1.0);
		glBegin(GL_POLYGON);
		glVertex2f(550 + i, 150);
		glVertex2f(550 + i, 200);
		glVertex2f(625 + i, 200);
		glVertex2f(625 + i, 150);
		glEnd();

		glColor3f(1.0, 1.0, 1.0);
		glBegin(GL_POLYGON);
		glVertex2f(450 + i, 150);
		glVertex2f(450 + i, 200);
		glVertex2f(525 + i, 200);
		glVertex2f(525 + i, 150);
		glEnd();

		glColor3f(1.0, 1.0, 1.0);
		glBegin(GL_POLYGON);
		glVertex2f(375 + i, 150);
		glVertex2f(375 + i, 200);
		glVertex2f(425 + i, 200);
		glVertex2f(425 + i, 150);
		glEnd();


		glColor3f(0.0, 0.0, 0.0);
		circle(450 + i, 50, 30);
		circle(625 + i, 50, 30);


		if (bus == 1)
		{
			i = i + 1;
		}

	}

	else
	{
		i = -400;
		glColor3f(0.7, 0.0, 0.9);
		glBegin(GL_POLYGON);
		glVertex2f(350 + i, 50);
		glVertex2f(350 + i, 275);
		glVertex2f(722 + i, 275);
		glVertex2f(750 + i, 175);
		glVertex2f(750 + i, 50);
		glEnd();

		glColor3f(1.0, 1.0, 1.0);
		glBegin(GL_POLYGON);
		glVertex2f(650 + i, 175);
		glVertex2f(650 + i, 260);
		glVertex2f(720 + i, 260);
		glVertex2f(745 + i, 175);
		glEnd();

		glColor3f(1.0, 1.0, 1.0);
		glBegin(GL_POLYGON);
		glVertex2f(550 + i, 175);
		glVertex2f(550 + i, 260);
		glVertex2f(625 + i, 260);
		glVertex2f(625 + i, 175);
		glEnd();

		glColor3f(1.0, 1.0, 1.0);
		glBegin(GL_POLYGON);
		glVertex2f(450 + i, 175);
		glVertex2f(450 + i, 260);
		glVertex2f(525 + i, 260);

		glVertex2f(525 + i, 175);
		glEnd();

		glColor3f(1.0, 1.0, 1.0);
		glBegin(GL_POLYGON);
		glVertex2f(375 + i, 175);
		glVertex2f(375 + i, 260);
		glVertex2f(425 + i, 260);
		glVertex2f(425 + i, 175);
		glEnd();


		glColor3f(0.0, 0.0, 0.0);
		circle(450 + i, 50, 30);
		circle(625 + i, 50, 30);

		if (bus == 1)
		{
			i = i + 1;
		}
	}
	glutPostRedisplay();
	//glFlush();
}


void win1() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	background();
	houses();
	draw_object();
	drawText(900, 10, 0, 0, 0, d, "Press w to view animals");
	glFlush();
}

void win2() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	background();
	houses();
	draw_object();
	lion();
	giraffe();
	elephant();
	drawText(900, 10, 0, 0, 0, d, "Press e to continue");
	glFlush();
}

void win3() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	background();
	houses();
	draw_object();
	display1(900);
	lion();
	giraffe();
	elephant();
	drawText(900, 10, 0, 0, 0, d, "Press r to cut the trees");
	glFlush();
}

void win4() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	background();
	houses();
	smallpieces();
	drawTreeUp4();
	drawTreeUp5();
	treefall1();
	treefall2();
	treefall3();
	display5(275);
	drawText(850, 10, 0, 0, 0, d, "Press t to load the trees inside truck");
	glFlush();
}

void win5() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	background();
	houses();
	drawobject6();
	drawTreeUp4();
	drawTreeUp5();
	drawText(900, 10, 0, 0, 0, d, "Press y to continue");
	truvk(600);
	glFlush();
}
void win6() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	background();
	houses();
	//drawTreeDown1();
	drawTreeDown2();
	drawTreeDown3();
	drawTreeUp4();
	drawTreeUp5();
	truck600(400);
	drawText(900, 10, 0, 0, 0, d, "Press u to continue");
	glFlush();
}

void win7() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	background();
	houses();
	drawTreeUp4();
	drawTreeUp5();
	drawTreeDown3();
	truck400(200);
	drawText(900, 10, 0, 0, 0, d, "Press i to continue");
	glFlush();
}
void win8() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	background();
	houses();
	drawTreeUp4();
	drawTreeUp5();
	//drawTreeDown3();
	truck200(-1100);
	drawText(900, 10, 0, 0, 0, d, "Press o to see the next scene");
	glFlush();
}

void win9() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	background1();
	//houses();
	scene27();
	drawTreeUp4();
	drawTreeUp5();
	drawText(850, 10, 0, 0, 0, d, "Press p to cut down the remaining trees");
	glFlush();
}
void win10() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	background1();
	scene27();
	drawTreeUp6();
	drawTreeUp7();
	mydisplaySecondWindow2();
	drawText(900, 10, 0, 0, 0, d, "Press a to continue");
	glFlush();
}
void win11() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	background1();
	smallpieces1();
	//drawobject6();
	scene27();
	treefall5();
	drawTreeUp4();
	cutter2(20, 200);
	axe1();
	drawText(900, 10, 0, 0, 0, d, "Press s to continue");
	glFlush();
}
void win12() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	background1();
	scene27();
	drawTreeDown5();
	drawTreeUp4();
	mydisplaySecondWindow1();
	drawText(900, 10, 0, 0, 0, d, "Press d to continue");
	glFlush();
}
void win13() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	background1();
	//drawobject6();
	scene27();
	drawTreeDown5();
	smallpieces1();
	treefall4();
	cutter2(110, 200);
	axe();
	drawText(900, 10, 0, 0, 0, d, "Press f for cutter to exit");
	glFlush();
}
void win14() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	background1();
	scene27();
	drawTreeDown5();
	drawTreeDown4();
	smallpieces1();
	mydisplaySecondWindow3();
	drawText(900, 10, 0, 0, 0, d, "Press g to view the city");
	glFlush();
}
void win15() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	background1();
	scene29();
	drawText(900, 10, 1, 1, 1, d, "Press h for moral");
	glFlush();
}
void selectMenu(int n) {
	switch (n) {
	case 1:glutDisplayFunc(win2);
		break;
	case 2:glutDisplayFunc(win15);
		break;
	case 3: exit(0);
		break;
	}
	glutPostRedisplay();
	glFlush();
}
//To create and display menu
void createMenu() {
	menulist = glutCreateMenu(selectMenu);
	glutAddMenuEntry("FOREST VIEW", 1);
	glutAddMenuEntry("CITY VIEW", 2);
	glutAddMenuEntry("EXIT", 3);
	glutAttachMenu(GLUT_RIGHT_BUTTON); //menu appears when right mouse button is clicked
}
void displayFrontSheet()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glEnable(GL_TEXTURE_2D);
	glColor3f(1, 1, 1);
	glBindTexture(GL_TEXTURE_2D, frontSheet);
	glBegin(GL_QUADS);
	glVertex3f(1100, 700, 0);
	glTexCoord2f(0, 0);
	glVertex3f(0, 700, 0);
	glTexCoord2f(0, 1);
	glVertex3f(0, 0, 0);
	glTexCoord2f(1, 1);
	glVertex3f(1100, 0, 0);
	glTexCoord2f(1, 0);
	glEnd();
	glFlush();
	glDisable(GL_TEXTURE_2D);
	glutSwapBuffers();
}
void displayMoral()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glEnable(GL_TEXTURE_2D);
	glColor3f(1, 1, 1);
	glBindTexture(GL_TEXTURE_2D, moral);
	glBegin(GL_QUADS);
	glVertex3f(1100, 700, 0);
	glTexCoord2f(0, 0);
	glVertex3f(0, 700, 0);
	glTexCoord2f(0, 1);
	glVertex3f(0, 0, 0);
	glTexCoord2f(1, 1);
	glVertex3f(1100, 0, 0);
	glTexCoord2f(1, 0);
	glEnd();
	glFlush();
	glDisable(GL_TEXTURE_2D);
	glutSwapBuffers();
}
void displayThankyou()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glEnable(GL_TEXTURE_2D);
	glColor3f(1, 1, 1);
	glBindTexture(GL_TEXTURE_2D, tq);
	glBegin(GL_QUADS);
	glVertex3f(1100, 700, 0);
	glTexCoord2f(0, 0);
	glVertex3f(0, 700, 0);
	glTexCoord2f(0, 1);
	glVertex3f(0, 0, 0);
	glTexCoord2f(1, 1);
	glVertex3f(1100, 0, 0);
	glTexCoord2f(1, 0);
	glEnd();
	glFlush();
	glDisable(GL_TEXTURE_2D);
	glutSwapBuffers();
}
void myinit()
{
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glColor3f(0.0, 0.0, 1.0);
	glPointSize(2.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 1100.0, 0.0, 700.0);
}
void display()
{
	glClearColor(1, 1, 1, 1);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	drawText(500, 150, 0, 1, 0, d, "PRESS 'q' TO START");
	glFlush();
}
void loadFrontSheet(void) {
	glGenTextures(1, &frontSheet);
	glBindTexture(GL_TEXTURE_2D, frontSheet);
	// set the frontSheet wrapping/filtering options (on the currently bound frontSheet object)
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	// load and generate the frontSheet
	int width, height, nrChannels;
	unsigned char* data = stbi_load("intro.jpg", &width, &height, &nrChannels, STBI_rgb_alpha);
	if (data) {
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
	}
	else
	{
		std::cout << "Failed to load " << std::endl;
	}
	stbi_image_free(data);

}
void loadMoral(void)
{
	glGenTextures(1, &moral);
	glBindTexture(GL_TEXTURE_2D, moral);
	// set the bg1 wrapping/filtering options (on the currently bound bg1 object)
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	// load and generate the bg1
	int width, height, nrChannels;
	unsigned char* data = stbi_load("moral1.jpeg", &width, &height, &nrChannels, STBI_rgb_alpha);
	if (data)
	{
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
		//glGenerateMipmap(GL_TEXTURE_2D);
	}
	else
	{
		std::cout << "Failed to load bg1" << std::endl;
	}
	stbi_image_free(data);
}
void loadtq(void)
{
	glGenTextures(1, &tq);
	glBindTexture(GL_TEXTURE_2D, tq);
	// set the bg1 wrapping/filtering options (on the currently bound bg1 object)
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	// load and generate the bg1
	int width, height, nrChannels;
	unsigned char* data = stbi_load("tq.JPG", &width, &height, &nrChannels, STBI_rgb_alpha);
	if (data)
	{
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
		//glGenerateMipmap(GL_TEXTURE_2D);
	}
	else
	{
		std::cout << "Failed to load bg1" << std::endl;
	}
	stbi_image_free(data);
}
void Normalkey(unsigned char k, int x, int y)
{
	switch (k)
	{
	case 'q':glutDisplayFunc(win1);
		break;
	case 'w':glutDisplayFunc(win2);
		break;
	case 'e':glutDisplayFunc(win3);
		break;
	case 'r':glutDisplayFunc(win4);
		break;
	case 't':glutDisplayFunc(win5);
		break;
	case 'y':glutDisplayFunc(win6);
		break;
	case 'u':glutDisplayFunc(win7);
		break;
	case 'i':glutDisplayFunc(win8);
		break;
	case 'o':glutDisplayFunc(win9);
		break;
	case 'p':glutDisplayFunc(win10);
		break;
	case 'a':glutDisplayFunc(win11);
		break;
	case 's':glutDisplayFunc(win12);
		break;
	case 'd':glutDisplayFunc(win13);
		break;
	case 'f':glutDisplayFunc(win14);
		break;
	case 'g':glutDisplayFunc(win15);
		break;
	case 'h':glutDisplayFunc(displayMoral);
		break;
	case'x':glutDisplayFunc(displayThankyou);
		break;
	case'z':exit(0);
		break;
	}
	glutPostRedisplay();
}
int main(int argc, char** argv)
{
	//glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_ALPHA | GLUT_DEPTH);
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(1100.0, 700.0);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Deforesation");
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_BLEND);
	glutDisplayFunc(displayFrontSheet);
	glutKeyboardFunc(Normalkey);
	createMenu();
	loadFrontSheet();
	loadMoral();
	loadtq();
	myinit();
	glutMainLoop();
	return 0;
}