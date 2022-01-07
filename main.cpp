#include<iostream>
using namespace std;
#include <GL/gl.h>
#include <GL/glut.h>
#include <windows.h>
#include<math.h>
#include<mmsystem.h>
#define PI 3.1416

float _angle = 30.0f;
float _cameraAngle = 0.0f;
int _lcloudMove=1;
int _rcloudMove=1;

float _move_sun = 0.0f;
float _move_cloud_1 = 1440.0f;
float _move_cloud_2 = 1440.0f;

float moveBird= 0.0;
int birdStatus=0;

float moveCloud = 400;
int cloudStatus=0;

float rainx = 10;
float rainy = -2400;
//float rainy = 00;
int rainStatus=0;

float flowerx=-2500;

float humany=780;
float humanMove=280;

char humanStatus=0;


double _red= 0.59;
double _green= 0.87;
double _blue= 0.85;

double _red2= 1.00;
double _green2= 0.90;
double _blue2= 0.00;

double _red3= 0.3;
double _green3= 0.3;
double _blue3= 0.3;

double _red4= 1.0;
double _green4= 1.0;
double _blue4= 1.0;

int sunXaxis=200;
int sunYaxis=100;
int sunRadius=60;

int cloud1a=440;
int cloud1b=110;
int cloud1c=470;
int cloud1d=108;
int cloud1e=490;
int cloud1f=110;

int cloud2a=0;
int cloud2b=80;
int cloud2c=20;
int cloud2d=81;
int cloud2e=40;
int cloud2f=80;

int cloud3a=840;
int cloud3b=40;
int cloud3c=864;
int cloud3d=38;
int cloud3e=884;
int cloud3f=40;

float _dayWhite1 = 1.0;
float _dayWhite2 = 0.9;

float _nightWhite1 = 0.8;
float _nightWhite2 = 0.7;


int is;
GLint xs;
GLint ys;
GLint radiuss;
GLint twicePis;
int triangleAmounts;
void init (void)
{
/* select clearing (background) color */
glClearColor (1.0,1.0,1.0,0.0);
//glClearColor (0.59, 0.87, 0.85, 0.0);
/* initialize viewing values */
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
glOrtho(0.0, 1440.0, 800.0, 0.0, -10.0, 10.0);
}


void moveBirds(int value) {
    if(birdStatus==0){
        moveBird = 0.0;
        glutPostRedisplay();
    }
    else{
        if(moveBird <-1400)
        {
             moveBird = 1400;
        }
        moveBird=moveBird-8;

        glutPostRedisplay();
        glutTimerFunc(100, moveBirds, 0);
    }

}

void moveClouds(int value) {
    if(cloudStatus==0){
        moveCloud = 400;
        glutPostRedisplay();
    }
    else{
        if(moveCloud < -800)
        {
             moveCloud = 1500;
        }
        moveCloud=moveCloud-3;

        glutPostRedisplay();
        glutTimerFunc(100, moveClouds, 0);
    }

}


void rain(int value) {
    if(rainStatus==0){
        rainy = -2400;
        glutPostRedisplay();
    }
    else{
        if(rainy > -120){
        rainy = -1500;
        }

        rainy=rainy+30;
        //printf("%.2f ",rainy);

        glutPostRedisplay();
        glutTimerFunc(100, rain, 0);
    }

}

void moveHuman(int value) {
    if (humanStatus==1){
        if(humanMove > 0)
        {
            humany=humany-3;
            humanMove=humanMove-3;
            glutPostRedisplay();
            glutTimerFunc(100, moveHuman, 0);
        }
    }

}





Sky()
{
    glBegin(GL_QUADS);
	glColor3d(_red, _green, _blue);
	glVertex2i(0,0);
	glVertex2i(1440,0);
	glVertex2i(1440,800);
	glVertex2i(0,800);
	glEnd();
}


Sun ()
{
    glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	//sun
    //int is;
	xs=sunXaxis;
	ys= sunYaxis;
	radiuss =sunRadius;
	triangleAmounts = 500;
	twicePis = 100 * PI;
	glBegin(GL_TRIANGLE_FAN);
	glColor3d(_red2, _green2, _blue2);
    glVertex2f(xs, ys);
    for(is = 0; is <= triangleAmounts; is++)
    {
        glVertex2f(xs+(radiuss*cos(is*twicePis/triangleAmounts)), ys+(radiuss*sin(is*twicePis/triangleAmounts)));
    }
	glEnd();
}

Cloud()
{
    //Cloud
	//01
	int xC,yC,radiusC,triangleAmountC,twicePiC;

    xC= moveCloud+cloud1a, yC= cloud1b, radiusC = 22;
    triangleAmountC = 500;
    twicePiC = 200 * PI;
	glBegin(GL_TRIANGLE_FAN);
	glColor3d(_red4,_green4,_blue4);
    glVertex2f(xC, yC);
    for(int iC = 0; iC <= triangleAmountC;iC++) {
    glVertex2f(
                xC + (radiusC * cos(iC *  twicePiC / triangleAmountC)),
            yC + (radiusC * sin(iC * twicePiC / triangleAmountC))
        );
    }
	glEnd();

    xC= moveCloud+cloud1c, yC= cloud1d, radiusC = 25;
    triangleAmountC = 500;
    twicePiC = 100 * PI;
	glBegin(GL_TRIANGLE_FAN);
	glColor3d(_red4,_green4,_blue4);
    glVertex2f(xC, yC);
    for(int iC = 0; iC <= triangleAmountC;iC++) {
        glVertex2f(
                xC + (radiusC * cos(iC *  twicePiC / triangleAmountC)),
            yC + (radiusC * sin(iC * twicePiC / triangleAmountC))
        );
    }
	glEnd();

	xC= moveCloud+cloud1e, yC= cloud1f, radiusC = 22;
    triangleAmountC = 500;
    twicePiC = 100 * PI;
	glBegin(GL_TRIANGLE_FAN);
	glColor3d(_red4,_green4,_blue4);
    glVertex2f(xC, yC);
    for(int iC = 0; iC <= triangleAmountC;iC++) {
        glVertex2f(
                xC + (radiusC * cos(iC *  twicePiC / triangleAmountC)),
            yC + (radiusC * sin(iC * twicePiC / triangleAmountC))
        );
    }
	glEnd();

    //02
    xC= moveCloud+cloud2a, yC= cloud2b, radiusC = 18;
    triangleAmountC = 500;
    twicePiC = 100 * PI;
	glBegin(GL_TRIANGLE_FAN);
	glColor3d(_red4,_green4,_blue4);
    glVertex2f(xC, yC);
    for(int iC = 0; iC <= triangleAmountC;iC++) {
    glVertex2f(
                xC + (radiusC * cos(iC *  twicePiC / triangleAmountC)),
            yC + (radiusC * sin(iC * twicePiC / triangleAmountC))
        );
    }
	glEnd();

    xC= moveCloud+cloud2c, yC= cloud2d, radiusC = 22;
    triangleAmountC = 500;
    twicePiC = 100 * PI;
	glBegin(GL_TRIANGLE_FAN);
	glColor3d(_red4,_green4,_blue4);
    glVertex2f(xC, yC);
    for(int iC = 0; iC <= triangleAmountC;iC++) {
        glVertex2f(
                xC + (radiusC * cos(iC *  twicePiC / triangleAmountC)),
            yC + (radiusC * sin(iC * twicePiC / triangleAmountC))
        );
    }
	glEnd();

	xC= moveCloud+cloud2e, yC= cloud2f, radiusC = 20;
    triangleAmountC = 500;
    twicePiC = 100 * PI;
	glBegin(GL_TRIANGLE_FAN);
	glColor3d(_red4,_green4,_blue4);
    glVertex2f(xC, yC);
    for(int iC = 0; iC <= triangleAmountC;iC++) {
        glVertex2f(
                xC + (radiusC * cos(iC *  twicePiC / triangleAmountC)),
            yC + (radiusC * sin(iC * twicePiC / triangleAmountC))
        );
    }
	glEnd();
    //Cloud End

    xC= moveCloud+cloud3a, yC= cloud3b, radiusC = 20;
    triangleAmountC = 500;
    twicePiC = 100 * PI;
	glBegin(GL_TRIANGLE_FAN);
	glColor3d(_red4,_green4,_blue4);
    glVertex2f(xC, yC);
    for(int iC = 0; iC <= triangleAmountC;iC++) {
    glVertex2f(
                xC + (radiusC * cos(iC *  twicePiC / triangleAmountC)),
            yC + (radiusC * sin(iC * twicePiC / triangleAmountC))
        );
    }
	glEnd();

    xC= moveCloud+cloud3c, yC= cloud3d, radiusC = 25;
    triangleAmountC = 500;
    twicePiC = 100 * PI;
	glBegin(GL_TRIANGLE_FAN);
	glColor3d(_red4,_green4,_blue4);
    glVertex2f(xC, yC);
    for(int iC = 0; iC <= triangleAmountC;iC++) {
        glVertex2f(
                xC + (radiusC * cos(iC *  twicePiC / triangleAmountC)),
            yC + (radiusC * sin(iC * twicePiC / triangleAmountC))
        );
    }
	glEnd();

	xC= moveCloud+cloud3e, yC= cloud3f, radiusC = 20;
    triangleAmountC = 500;
    twicePiC = 100 * PI;
	glBegin(GL_TRIANGLE_FAN);
	glColor3d(_red4,_green4,_blue4);
    glVertex2f(xC, yC);
    for(int iC = 0; iC <= triangleAmountC;iC++) {
        glVertex2f(
                xC + (radiusC * cos(iC *  twicePiC / triangleAmountC)),
            yC + (radiusC * sin(iC * twicePiC / triangleAmountC))
        );
    }
	glEnd();
}



Bird(){
    glBegin(GL_POLYGON);  //Bird-1
    glColor3d(_red3,_green3,_blue3);
    glVertex2f(100.0+moveBird,100.0);
    glVertex2f(90.0+moveBird,80.0);
    glVertex2f(120.0+moveBird,100.0);
    glVertex2f(130.0+moveBird,80.0);
    glEnd();



    glBegin(GL_TRIANGLES);
    glColor3d(_red3,_green3,_blue3);
	glVertex2f(110.0+moveBird,93.0);
	glVertex2f(140.0+moveBird,100.0);
	glVertex2f(85.0+moveBird,100.0);
	glEnd();


	glBegin(GL_POLYGON);  //Bird-2
    glColor3d(_red3,_green3,_blue3);
    glVertex2f(80.0+moveBird,130.0);
    glVertex2f(70.0+moveBird,110.0);
    glVertex2f(90.0+moveBird,130.0);
    glVertex2f(100.0+moveBird,110.0);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3d(_red3,_green3,_blue3);
	glVertex2f(85.0+moveBird,123.0);
	glVertex2f(110.0+moveBird,130.0);
	glVertex2f(65.0+moveBird,130.0);
	glEnd();

/*glBegin(GL_POLYGON);  //Bird-3
    glColor3d(0.0,0.0,0.0);
    glVertex2f(1300.0+moveBird,60.0);
    glVertex2f(1280.0+moveBird,40.0);
    glVertex2f(1340.0+moveBird,60.0);
    glVertex2f(1360.0+moveBird,40.0);
    glEnd();



    glBegin(GL_TRIANGLES);
    glColor3d(0.0,0.0,0.0);
	glVertex2f(1310.0+moveBird,53.0);
	glVertex2f(1370.0+moveBird,65.0);
	glVertex2f(1270.0+moveBird,65.0);
	glEnd();*/


	glBegin(GL_POLYGON);  //Bird-3
    glColor3d(_red3,_green3,_blue3);
    glVertex2f(1200.0+moveBird,40.0);
    glVertex2f(1190.0+moveBird,20.0);
    glVertex2f(1220.0+moveBird,40.0);
    glVertex2f(1230.0+moveBird,20.0);
    glEnd();


    glBegin(GL_TRIANGLES);
    glColor3d(_red3,_green3,_blue3);
	glVertex2f(1210.0+moveBird,33.0);
	glVertex2f(1240.0+moveBird,40.0);
	glVertex2f(1185.0+moveBird,40.0);
	glEnd();


	glBegin(GL_POLYGON);  //Bird-4
    glColor3d(_red3,_green3,_blue3);
    glVertex2f(1250.0+moveBird,60.0);
    glVertex2f(1240.0+moveBird,40.0);
    glVertex2f(1260.0+moveBird,60.0);
    glVertex2f(1270.0+moveBird,40.0);
    glEnd();


    glBegin(GL_TRIANGLES);
    glColor3d(_red3,_green3,_blue3);
	glVertex2f(1255.0+moveBird,53.0);
	glVertex2f(1280.0+moveBird,60.0);
	glVertex2f(1235.0+moveBird,60.0);
	glEnd();


	glBegin(GL_POLYGON);  //Bird-5
    glColor3d(_red3,_green3,_blue3);
    glVertex2f(1300.0+moveBird,80.0);
    glVertex2f(1295.0+moveBird,60.0);
    glVertex2f(1310.0+moveBird,80.0);
    glVertex2f(1320.0+moveBird,60.0);
    glEnd();


    glBegin(GL_TRIANGLES);
    glColor3d(_red3,_green3,_blue3);
	glVertex2f(1310.0+moveBird,73.0);
	glVertex2f(1325.0+moveBird,80.0);
	glVertex2f(1290.0+moveBird,80.0);
	glEnd();


}


void Field ()
{
    //field
	glBegin(GL_QUADS);
	glColor3ub(0, 160, 97);
	glVertex2i(0,400);
	glVertex2i(1440,400);
	glVertex2i(1440,800);
	glVertex2i(0,800);
	glEnd();
}
void TriangleTrees ()
{
    //01
    glLineWidth(10);
	glBegin(GL_LINES);              // Each set of 4 vertices form a quad
	glColor3f(0.0f, 0.0f, 0.0f); // Red
	glVertex2i(48,300);    // x, y
	glVertex2i(48,400);    // x, y
	glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(0, 93, 79);
	glVertex2i(48, 280);    // x, y
	glVertex2i(18, 368);
	glVertex2i(78, 368);
	glEnd();

    //02
    glPushMatrix();
	glTranslated(70,0,0);
    glLineWidth(10);
	glBegin(GL_LINES);              // Each set of 4 vertices form a quad
	glColor3f(0.0f, 0.0f, 0.0f); // Red
	glVertex2i(48,300);    // x, y
	glVertex2i(48,400);    // x, y
	glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(0, 93, 79);
	glVertex2i(48, 280);    // x, y
	glVertex2i(18, 368);
	glVertex2i(78, 368);
	glEnd();
	glPopMatrix();

	//03
	glPushMatrix();
	glTranslated(140,0,0);
    glLineWidth(10);
	glBegin(GL_LINES);              // Each set of 4 vertices form a quad
	glColor3f(0.0f, 0.0f, 0.0f); // Red
	glVertex2i(48,300);    // x, y
	glVertex2i(48,400);    // x, y
	glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(0, 93, 79);
	glVertex2i(48, 280);    // x, y
	glVertex2i(18, 368);
	glVertex2i(78, 368);
	glEnd();
	glPopMatrix();

	//04
	glPushMatrix();
	glTranslated(1100,0,0);
    glLineWidth(10);
	glBegin(GL_LINES);              // Each set of 4 vertices form a quad
	glColor3f(0.0f, 0.0f, 0.0f); // Red
	glVertex2i(48,300);    // x, y
	glVertex2i(48,400);    // x, y
	glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(0, 93, 79);
	glVertex2i(48, 280);    // x, y
	glVertex2i(18, 368);
	glVertex2i(78, 368);
	glEnd();
	glPopMatrix();

	//05
	glPushMatrix();
	glTranslated(1170,0,0);
    glLineWidth(10);
	glBegin(GL_LINES);              // Each set of 4 vertices form a quad
	glColor3f(0.0f, 0.0f, 0.0f); // Red
	glVertex2i(48,300);    // x, y
	glVertex2i(48,400);    // x, y
	glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(0, 93, 79);
	glVertex2i(48, 280);    // x, y
	glVertex2i(18, 368);
	glVertex2i(78, 368);
	glEnd();
	glPopMatrix();

	//06
	glPushMatrix();
	glTranslated(1240,0,0);
    glLineWidth(10);
	glBegin(GL_LINES);              // Each set of 4 vertices form a quad
	glColor3f(0.0f, 0.0f, 0.0f); // Red
	glVertex2i(48,300);    // x, y
	glVertex2i(48,400);    // x, y
	glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(0, 93, 79);
	glVertex2i(48, 280);    // x, y
	glVertex2i(18, 368);
	glVertex2i(78, 368);
	glEnd();
	glPopMatrix();

	//07
	glPushMatrix();
	glTranslated(1310,0,0);
    glLineWidth(10);
	glBegin(GL_LINES);              // Each set of 4 vertices form a quad
	glColor3f(0.0f, 0.0f, 0.0f); // Red
	glVertex2i(48,300);    // x, y
	glVertex2i(48,400);    // x, y
	glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(0, 93, 79);
	glVertex2i(48, 280);    // x, y
	glVertex2i(18, 368);
	glVertex2i(78, 368);
	glEnd();
	glPopMatrix();

}
void RedSun ()
{
    //RED sun
    int is2;
	GLint xs2=681;
	GLint ys2=235;
	GLint radiuss2 =100;
	int triangleAmounts2 = 700;
	GLint twicePis2 = 1000 * PI;
	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(255, 0 , 26);
    glVertex2f(xs2, ys2);
    for(is2 = 0; is2 <= triangleAmounts2; is2++)
    {
        glVertex2f(xs2+(radiuss2*cos(is2*twicePis2/triangleAmounts2)), ys2+(radiuss2*sin(is2*twicePis2/triangleAmounts2)));
    }
	glEnd();
}

void SmallTreeBack ()
{
     //Back trees left
	xs=250;
	ys= 540;
	radiuss =50;
	triangleAmounts = 500;
	twicePis = 100 * PI;
	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(0, 93, 79);
    glVertex2f(xs, ys);
    for(is = 0; is <= triangleAmounts; is++)
    {
        glVertex2f(xs+(radiuss*cos(is*twicePis/triangleAmounts)), ys+(radiuss*sin(is*twicePis/triangleAmounts)));
    }
	glEnd();

	xs=270;
	ys= 500;
	radiuss =50;
	triangleAmounts = 500;
	twicePis = 100 * PI;
	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(0, 93, 79);
    glVertex2f(xs, ys);
    for(is = 0; is <= triangleAmounts; is++)
    {
        glVertex2f(xs+(radiuss*cos(is*twicePis/triangleAmounts)), ys+(radiuss*sin(is*twicePis/triangleAmounts)));
    }
	glEnd();

	xs=330;
	ys= 500;
	radiuss =50;
	triangleAmounts = 500;
	twicePis = 100 * PI;
	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(0, 93, 79);
    glVertex2f(xs, ys);
    for(is = 0; is <= triangleAmounts; is++)
    {
        glVertex2f(xs+(radiuss*cos(is*twicePis/triangleAmounts)), ys+(radiuss*sin(is*twicePis/triangleAmounts)));
    }
	glEnd();
	// Back tree left end

    //Back trees right
	xs=1110;
	ys= 540;
	radiuss =50;
	triangleAmounts = 500;
	twicePis = 100 * PI;
	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(0, 93, 79);
    glVertex2f(xs, ys);
    for(is = 0; is <= triangleAmounts; is++)
    {
        glVertex2f(xs+(radiuss*cos(is*twicePis/triangleAmounts)), ys+(radiuss*sin(is*twicePis/triangleAmounts)));
    }
	glEnd();

	xs=1160;
	ys= 560;
	radiuss =40;
	triangleAmounts = 500;
	twicePis = 100 * PI;
	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(0, 93, 79);
    glVertex2f(xs, ys);
    for(is = 0; is <= triangleAmounts; is++)
    {
        glVertex2f(xs+(radiuss*cos(is*twicePis/triangleAmounts)), ys+(radiuss*sin(is*twicePis/triangleAmounts)));
    }
	glEnd();

	xs=920;
	ys= 500;
	radiuss =50;
	triangleAmounts = 500;
	twicePis = 100 * PI;
	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(0, 93, 79);
    glVertex2f(xs, ys);
    for(is = 0; is <= triangleAmounts; is++)
    {
        glVertex2f(xs+(radiuss*cos(is*twicePis/triangleAmounts)), ys+(radiuss*sin(is*twicePis/triangleAmounts)));
    }
	glEnd();
	// Back right tree end

}

void ShahidMinar()
{
    //Middle 3
    glBegin(GL_QUADS); //Begin quadrilateral coordinates
	glColor3d(_dayWhite2,_dayWhite2,_dayWhite2);
	glVertex2i(604,163);
	glVertex2i(622,163);
	glVertex2i(622,377);
	glVertex2i(604,377);
	glEnd(); //End quadrilateral coordinates

    glBegin(GL_QUADS);
	glColor3d(_dayWhite1,_dayWhite1,_dayWhite1);
	glVertex2i(604,163);
	glVertex2i(618,163);
	glVertex2i(618,377);
	glVertex2i(604,377);
	glEnd();

	glPushMatrix();
	glTranslated(72,0,0);
    glBegin(GL_QUADS);
	glColor3d(_dayWhite1,_dayWhite1,_dayWhite1);
	glVertex2i(604,163);
	glVertex2i(618,163);
	glVertex2i(618,377);
	glVertex2i(604,377);
	glEnd(); //End quadrilateral coordinate
	glPopMatrix();


	glPushMatrix();
	glTranslated(144,0,0);
    glBegin(GL_QUADS);
	glColor3d(_dayWhite2,_dayWhite2,_dayWhite2);
	glVertex2i(600,163);
	glVertex2i(618,163);
	glVertex2i(618,377);
	glVertex2i(600,377);
	glEnd(); //End quadrilateral coordinate
	glPopMatrix();

	glPushMatrix();
	glTranslated(144,0,0);
    glBegin(GL_QUADS);
	glColor3d(_dayWhite1,_dayWhite1,_dayWhite1);
	glVertex2i(604,163);
	glVertex2i(618,163);
	glVertex2i(618,377);
	glVertex2i(604,377);
	glEnd(); //End quadrilateral coordinate
	glPopMatrix();
    // Middle 3 end
     glPushMatrix();
	glBegin(GL_QUADS);
	glColor3d(_dayWhite2,_dayWhite2,_dayWhite2);
	glVertex2i(604,163);
	glVertex2i(622,163);
	glVertex2i(610,66);
	glVertex2i(602,66);
	glEnd(); //End quadrilateral coordinates
    glPopMatrix();

    glPushMatrix();
	glBegin(GL_QUADS);
	glColor3d(_dayWhite1,_dayWhite1,_dayWhite1);
    glTranslated(0,-5,0);
	glVertex2i(604,163);
	glVertex2i(618,163);
	glVertex2i(609,66);
	glVertex2i(602,66);
	glEnd(); //End quadrilateral coordinates
    glPopMatrix();

    glPushMatrix();
    glTranslated(72,0,0);
	glBegin(GL_QUADS); //Begin quadrilateral coordinates
	glColor3d(_dayWhite1,_dayWhite1,_dayWhite1);
	glVertex2i(604,163);
	glVertex2i(618,163);
	glVertex2i(616,66);
	glVertex2i(606,66);
	glEnd(); //End quadrilateral coordinates
    glPopMatrix();

     glPushMatrix();
    glTranslated(144,0,0);
	glBegin(GL_QUADS); //Begin quadrilateral coordinates
	glColor3d(_dayWhite2,_dayWhite2,_dayWhite2);
	glVertex2i(600,163);
	glVertex2i(618,163);
	glVertex2i(620,66);
	glVertex2i(610,66);
	glEnd(); //End quadrilateral coordinates
    glPopMatrix();

    glPushMatrix();
    glTranslated(144,0,0);
	glBegin(GL_QUADS); //Begin quadrilateral coordinates
	glColor3d(_dayWhite1,_dayWhite1,_dayWhite1);
	glVertex2i(604,163);
	glVertex2i(618,163);
	glVertex2i(620,66);
	glVertex2i(612,66);
	glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslated(0,-5,0);
	glBegin(GL_QUADS);
	glColor3d(_dayWhite2,.9,.9);
	glVertex2i(602,66);
	glVertex2i(765,66);
	glVertex2i(765,71);
	glVertex2i(602,71);

	glEnd();
    glPopMatrix();

    glPushMatrix();
	glBegin(GL_QUADS);
	glColor3d(_dayWhite1,_dayWhite1,_dayWhite1);
	glVertex2i(602,66);
	glVertex2i(765,66);
	glVertex2i(765,71);
	glVertex2i(602,71);
	glEnd();
    glPopMatrix();

     //minar left 1
    glPushMatrix();
	glBegin(GL_QUADS);
	glColor3d(_dayWhite1,_dayWhite1,_dayWhite1);
	glVertex2i(512,377);
	glVertex2i(512,173);
	glVertex2i(521,175);
	glVertex2i(521,377);
	glEnd(); //End quadrilateral coordinates
    glPopMatrix();

    glPushMatrix();
	glBegin(GL_QUADS); //Begin quadrilateral coordinates
	glColor3d(_dayWhite1,_dayWhite1,_dayWhite1);
	glVertex2i(555,377);
	glVertex2i(555,181);
	glVertex2i(548,181);
	glVertex2i(548,377);
	glEnd(); //End quadrilateral coordinates
    glPopMatrix();

    glPushMatrix();
	glBegin(GL_QUADS); //Begin quadrilateral coordinates
	glColor3d(_dayWhite2,_dayWhite2,_dayWhite2);
	glVertex2i(512,377);
	glVertex2i(512,173);
	glVertex2i(505,175);
	glVertex2i(505,377);
	glEnd(); //End quadrilateral coordinates
    glPopMatrix();

    glPushMatrix();
	glBegin(GL_QUADS); //Begin quadrilateral coordinates
	glColor3d(_dayWhite2,_dayWhite2,_dayWhite2);
	glVertex2i(548,377);
    glVertex2i(548,181);
    glVertex2i(542,181);
    glVertex2i(542,377);
	glEnd(); //End quadrilateral coordinates
    glPopMatrix();

    //top
    glPushMatrix();
	glBegin(GL_QUADS); //Begin quadrilateral coordinates
	glColor3d(_dayWhite1,_dayWhite1,_dayWhite1);
	glVertex2i(512,173);
	glVertex2i(512,183);
	glVertex2i(555,191);
	glVertex2i(555,181);
	glEnd(); //End quadrilateral coordinates
    glPopMatrix();

    //minar left 2
    glPushMatrix();
	glBegin(GL_QUADS); //Begin quadrilateral coordinates
	glColor3d(_dayWhite1,_dayWhite1,_dayWhite1);
	glVertex2i(440,377);
	glVertex2i(440,220);
	glVertex2i(449,222);
	glVertex2i(449,377);
	glEnd(); //End quadrilateral coordinates
    glPopMatrix();

    glPushMatrix();
	glBegin(GL_QUADS); //Begin quadrilateral coordinates
	glColor3d(_dayWhite1,_dayWhite1,_dayWhite1);
	glVertex2i(483,377);
	glVertex2i(483,228);
	glVertex2i(476,228);
	glVertex2i(476,377);
	glEnd(); //End quadrilateral coordinates
    glPopMatrix();

    glPushMatrix();
	glBegin(GL_QUADS); //Begin quadrilateral coordinates
	glColor3d(_dayWhite2,_dayWhite2,_dayWhite2);
	glVertex2i(440,377);
	glVertex2i(440,220);
	glVertex2i(433,222);
	glVertex2i(433,377);
	glEnd(); //End quadrilateral coordinates
    glPopMatrix();

    glPushMatrix();
	glBegin(GL_QUADS); //Begin quadrilateral coordinates
	glColor3d(_dayWhite2,_dayWhite2,_dayWhite2);
	glVertex2i(476,377);
    glVertex2i(476,228);
    glVertex2i(470,228);
    glVertex2i(470,377);
	glEnd(); //End quadrilateral coordinates
    glPopMatrix();

    //top
    glPushMatrix();
	glBegin(GL_QUADS); //Begin quadrilateral coordinates
	glColor3d(_dayWhite1,_dayWhite1,_dayWhite1);
	glVertex2i(440,220);
	glVertex2i(440,230);
	glVertex2i(483,238);
	glVertex2i(483,228);
	glEnd(); //End quadrilateral coordinates
    glPopMatrix();


     //minar Right 1
    glPushMatrix();
	glBegin(GL_QUADS); //Begin quadrilateral coordinates
	glColor3d(_dayWhite1,_dayWhite1,_dayWhite1);
	glVertex2i(808,377);
	glVertex2i(808,181);
	glVertex2i(817,181);
	glVertex2i(817,377);
	glEnd(); //End quadrilateral coordinates
    glPopMatrix();

    glPushMatrix();
	glBegin(GL_QUADS); //Begin quadrilateral coordinates
	glColor3d(_dayWhite1,_dayWhite1,_dayWhite1);
	glVertex2i(851,377);
	glVertex2i(851,173);
	glVertex2i(844,175);
	glVertex2i(844,377);
	glEnd(); //End quadrilateral coordinates
    glPopMatrix();

    glPushMatrix();
	glBegin(GL_QUADS); //Begin quadrilateral coordinates
	glColor3d(_dayWhite2,_dayWhite2,_dayWhite2);
	glVertex2i(817,377);
	glVertex2i(817,181);
	glVertex2i(822,181);
	glVertex2i(822,377);
	glEnd(); //End quadrilateral coordinates
    glPopMatrix();

    glPushMatrix();
	glBegin(GL_QUADS); //Begin quadrilateral coordinates
	glColor3d(_dayWhite2,_dayWhite2,_dayWhite2);
	glVertex2i(851,377);
	glVertex2i(851,173);
	glVertex2i(858,175);
	glVertex2i(858,377);
	glEnd(); //End quadrilateral coordinates
    glPopMatrix();

    //top
    glPushMatrix();
	glBegin(GL_QUADS); //Begin quadrilateral coordinates
	glColor3d(_dayWhite1,_dayWhite1,_dayWhite1);
	glVertex2i(851,173);
	glVertex2i(851,183);
	glVertex2i(808,191);
	glVertex2i(808,181);
	glEnd(); //End quadrilateral coordinates
    glPopMatrix();

    //minar Right 2
    glPushMatrix();
	glBegin(GL_QUADS);
	glColor3d(_dayWhite1,_dayWhite1,_dayWhite1);
	glVertex2i(878,377);
	glVertex2i(878,228);
	glVertex2i(887,228);
	glVertex2i(887,377);
	glEnd();
    glPopMatrix();

    glPushMatrix();
	glBegin(GL_QUADS);
	glColor3d(_dayWhite1,_dayWhite1,_dayWhite1);
	glVertex2i(921,377);
	glVertex2i(921,220);
	glVertex2i(914,222);
	glVertex2i(914,377);
	glEnd();
    glPopMatrix();

    glPushMatrix();
	glBegin(GL_QUADS);
	glColor3d(_dayWhite2,_dayWhite2,_dayWhite2);
	glVertex2i(887,377);
	glVertex2i(887,228);
	glVertex2i(892,228);
	glVertex2i(892,377);
	glEnd();
    glPopMatrix();

    glPushMatrix();
	glBegin(GL_QUADS);
	glColor3d(_dayWhite2,_dayWhite2,_dayWhite2);
	glVertex2i(921,377);
	glVertex2i(921,220);
	glVertex2i(928,222);
	glVertex2i(928,377);
	glEnd();
    glPopMatrix();

    //top
    glPushMatrix();
	glBegin(GL_QUADS);
	glColor3d(_dayWhite1,_dayWhite1,_dayWhite1);
	glVertex2i(921,220);
	glVertex2i(921,230);
	glVertex2i(878,238);
	glVertex2i(878,228);
	glEnd();
    glPopMatrix();
}

void Stairs ()
{
    //Floor
    glPushMatrix();
	glBegin(GL_QUADS);
	glColor3d(_dayWhite1,_dayWhite1,_dayWhite1);
	glVertex2i(300,400);
	glVertex2i(1100,400);
	glVertex2i(1100,370);
	glVertex2i(300,370);
	glEnd();
    glPopMatrix();

    //Stairs start
    glPushMatrix();
	glBegin(GL_QUADS);
	glColor3d(_dayWhite2,_dayWhite2,_dayWhite2);
	glVertex2i(300,420);
	glVertex2i(1100,420);
	glVertex2i(1100,400);
	glVertex2i(300,400);
	glEnd();
    glPopMatrix();

    glPushMatrix();
	glBegin(GL_QUADS);
	glColor3d(_dayWhite1,_dayWhite1,_dayWhite1);
	glVertex2i(300,430);
	glVertex2i(1100,430);
	glVertex2i(1100,420);
	glVertex2i(300,420);
	glEnd();
    glPopMatrix();

    glPushMatrix();
	glBegin(GL_QUADS);
	glColor3d(_dayWhite2,_dayWhite2,_dayWhite2);
	glVertex2i(300,450);
	glVertex2i(1100,450);
	glVertex2i(1100,430);
	glVertex2i(300,430);
	glEnd();
    glPopMatrix();

    glPushMatrix();
	glBegin(GL_QUADS);
	glColor3d(_dayWhite1,_dayWhite1,_dayWhite1);
	glVertex2i(300,460);
	glVertex2i(1100,460);
	glVertex2i(1100,450);
	glVertex2i(300,450);
	glEnd();
    glPopMatrix();

    glPushMatrix();
	glBegin(GL_QUADS);
	glColor3d(_dayWhite2,_dayWhite2,_dayWhite2);
	glVertex2i(300,480);
	glVertex2i(1100,480);
	glVertex2i(1100,460);
	glVertex2i(300,460);
	glEnd();
    glPopMatrix();

    glPushMatrix();
	glBegin(GL_QUADS);
	glColor3d(_dayWhite1,_dayWhite1,_dayWhite1);
	glVertex2i(300,490);
	glVertex2i(1100,490);
	glVertex2i(1100,480);
	glVertex2i(300,480);
	glEnd();
    glPopMatrix();

    glPushMatrix();
	glBegin(GL_QUADS);
	glColor3d(_dayWhite2,_dayWhite2,_dayWhite2);
	glVertex2i(300,510);
	glVertex2i(1100,510);
	glVertex2i(1100,490);
	glVertex2i(300,490);
	glEnd();
    glPopMatrix();

    glPushMatrix();
	glBegin(GL_QUADS);
	glColor3d(_dayWhite1,_dayWhite1,_dayWhite1);
	glVertex2i(300,520);
	glVertex2i(1100,520);
	glVertex2i(1100,510);
	glVertex2i(300,510);
	glEnd();
    glPopMatrix();

    glPushMatrix();
	glBegin(GL_QUADS);
	glColor3d(_dayWhite2,_dayWhite2,_dayWhite2);
	glVertex2i(300,540);
	glVertex2i(1100,540);
	glVertex2i(1100,520);
	glVertex2i(300,520);
	glEnd();
    glPopMatrix();

    glPushMatrix();
	glBegin(GL_QUADS);
	glColor3d(_dayWhite1,_dayWhite1,_dayWhite1);
	glVertex2i(300,550);
	glVertex2i(1100,550);
	glVertex2i(1100,540);
	glVertex2i(300,540);
	glEnd();
    glPopMatrix();

    glPushMatrix();
	glBegin(GL_QUADS);
	glColor3d(_dayWhite2,_dayWhite2,_dayWhite2);
	glVertex2i(300,570);
	glVertex2i(1100,570);
	glVertex2i(1100,550);
	glVertex2i(300,550);
	glEnd();
    glPopMatrix();
    // Stairs End
}


void Human(){

glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	//sun
    //int is;
	xs=200;  //human-1
	ys= humany+180;
	radiuss =20;
	triangleAmounts = 500;
	twicePis = 100 * PI;
	glBegin(GL_TRIANGLE_FAN);
	glColor3d(0.25, 0.25, 0.25);
    glVertex2f(xs, ys);
    for(is = 0; is <= triangleAmounts; is++)
    {
        glVertex2f(xs+(radiuss*cos(is*twicePis/triangleAmounts)), ys+(radiuss*sin(is*twicePis/triangleAmounts)));
    }
	glEnd();

    glTranslated(0,humanMove,0);

	glBegin(GL_QUADS);
	glColor3d(0.1, 0.1, 0.1);
    glVertex2f(170.0,700.0);
    glVertex2f(230.0,700.0);
    glVertex2f(230.0,740.0);
    glVertex2f(170.0,740.0);
    glEnd();

    glBegin(GL_QUADS);
	glColor3d(0.8, 0.8, 0.8);
    glVertex2f(170.0,745.0);
    glVertex2f(230.0,745.0);
    glVertex2f(230.0,770.0);
    glVertex2f(170.0,770.0);
    glEnd();

    glLineWidth(10);
	glBegin(GL_LINES);
	glColor3d(0.85, 0.85, 0.85);
    glVertex2f(160.0, 700.0);
    glVertex2f(160.0, 740.0);
    glEnd();

    glLineWidth(10);
	glBegin(GL_LINES);
	glColor3d(0.85, 0.85, 0.85);
    glVertex2f(240.0,700.0);
    glVertex2f(240.0,740.0);
    glEnd();



    glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	//sun
    //int is;
	xs=350;  //human-2
	ys= humany+180;
	radiuss =20;
	triangleAmounts = 500;
	twicePis = 100 * PI;
	glBegin(GL_TRIANGLE_FAN);
	glColor3d(0.25, 0.25, 0.25);
    glVertex2f(xs, ys);
    for(is = 0; is <= triangleAmounts; is++)
    {
        glVertex2f(xs+(radiuss*cos(is*twicePis/triangleAmounts)), ys+(radiuss*sin(is*twicePis/triangleAmounts)));
    }
	glEnd();



	glPushMatrix();
    glTranslated(150,humanMove,0);


	glBegin(GL_QUADS);
	glColor3d(0.0, 0.6, 0.0);
    glVertex2f(170.0,700.0);
    glVertex2f(230.0,700.0);
    glVertex2f(230.0,740.0);
    glVertex2f(170.0,740.0);
    glEnd();

    glBegin(GL_QUADS);
	glColor3d(0.70, 0.70, 0.70);
    glVertex2f(170.0,745.0);
    glVertex2f(230.0,745.0);
    glVertex2f(230.0,770.0);
    glVertex2f(170.0,770.0);
    glEnd();

    glLineWidth(10);
	glBegin(GL_LINES);
	glColor3d(0.70, 0.70, 0.70);
    glVertex2f(160.0, 700.0);
    glVertex2f(160.0, 740.0);
    glEnd();

    glLineWidth(10);
	glBegin(GL_LINES);
	glColor3d(0.70, 0.70, 0.70);
    glVertex2f(240.0,700.0);
    glVertex2f(240.0,740.0);
    glEnd();
    glPopMatrix();




    glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	//sun
    //int is;
	xs=500;  //human-3
	ys= humany+180;
	radiuss =20;
	triangleAmounts = 500;
	twicePis = 100 * PI;
	glBegin(GL_TRIANGLE_FAN);
	glColor3d(0.36, 0.25, 0.2);
    glVertex2f(xs, ys);
    for(is = 0; is <= triangleAmounts; is++)
    {
        glVertex2f(xs+(radiuss*cos(is*twicePis/triangleAmounts)), ys+(radiuss*sin(is*twicePis/triangleAmounts)));
    }
	glEnd();



	glPushMatrix();
    glTranslated(300,humanMove,0);


	glBegin(GL_QUADS);
	glColor3d(0.0, 0.0, 0.6);
    glVertex2f(170.0,700.0);
    glVertex2f(230.0,700.0);
    glVertex2f(230.0,740.0);
    glVertex2f(170.0,740.0);
    glEnd();

    glBegin(GL_QUADS);
	glColor3d(0.9, 0.9, 0.9);
    glVertex2f(170.0,745.0);
    glVertex2f(230.0,745.0);
    glVertex2f(230.0,770.0);
    glVertex2f(170.0,770.0);
    glEnd();

    glLineWidth(10);
	glBegin(GL_LINES);
	glColor3d(0.9, 0.9, 0.9);
    glVertex2f(160.0, 700.0);
    glVertex2f(160.0, 740.0);
    glEnd();

    glLineWidth(10);
	glBegin(GL_LINES);
	glColor3d(0.9, 0.9, 0.9);
    glVertex2f(240.0,700.0);
    glVertex2f(240.0,740.0);
    glEnd();
    glPopMatrix();



    glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	//sun
    //int is;
	xs=650;  //human-4
	ys= humany+180;
	radiuss =20;
	triangleAmounts = 500;
	twicePis = 100 * PI;
	glBegin(GL_TRIANGLE_FAN);
	glColor3d(0.25, 0.25, 0.25);
    glVertex2f(xs, ys);
    for(is = 0; is <= triangleAmounts; is++)
    {
        glVertex2f(xs+(radiuss*cos(is*twicePis/triangleAmounts)), ys+(radiuss*sin(is*twicePis/triangleAmounts)));
    }
	glEnd();



	glPushMatrix();
    glTranslated(450,humanMove,0);


	glBegin(GL_QUADS);
	glColor3d(0.1, 0.1, 0.1);
    glVertex2f(170.0,700.0);
    glVertex2f(230.0,700.0);
    glVertex2f(230.0,740.0);
    glVertex2f(170.0,740.0);
    glEnd();

    glBegin(GL_QUADS);
	glColor3d(0.8, 0.8, 0.8);
    glVertex2f(170.0,745.0);
    glVertex2f(230.0,745.0);
    glVertex2f(230.0,770.0);
    glVertex2f(170.0,770.0);
    glEnd();

    glLineWidth(10);
	glBegin(GL_LINES);
	glColor3d(0.85, 0.85, 0.85);
    glVertex2f(160.0, 700.0);
    glVertex2f(160.0, 740.0);
    glEnd();

    glLineWidth(10);
	glBegin(GL_LINES);
	glColor3d(0.85, 0.85, 0.85);
    glVertex2f(240.0,700.0);
    glVertex2f(240.0,740.0);
    glEnd();
    glPopMatrix();



    glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	//sun
    //int is;
	xs=800;  //human-5
	ys= humany+180;
	radiuss =20;
	triangleAmounts = 500;
	twicePis = 100 * PI;
	glBegin(GL_TRIANGLE_FAN);
	glColor3d(0.36, 0.25, 0.2);
    glVertex2f(xs, ys);
    for(is = 0; is <= triangleAmounts; is++)
    {
        glVertex2f(xs+(radiuss*cos(is*twicePis/triangleAmounts)), ys+(radiuss*sin(is*twicePis/triangleAmounts)));
    }
	glEnd();



	glPushMatrix();
    glTranslated(600,humanMove,0);


	glBegin(GL_QUADS);
	glColor3d(0.5, 0.0, 0.0);
    glVertex2f(170.0,700.0);
    glVertex2f(230.0,700.0);
    glVertex2f(230.0,740.0);
    glVertex2f(170.0,740.0);
    glEnd();

    glBegin(GL_QUADS);
	glColor3d(0.9, 0.9, 0.9);
    glVertex2f(170.0,745.0);
    glVertex2f(230.0,745.0);
    glVertex2f(230.0,770.0);
    glVertex2f(170.0,770.0);
    glEnd();

    glLineWidth(10);
	glBegin(GL_LINES);
	glColor3d(0.9, 0.9, 0.9);
    glVertex2f(160.0, 700.0);
    glVertex2f(160.0, 740.0);
    glEnd();

    glLineWidth(10);
	glBegin(GL_LINES);
	glColor3d(0.9, 0.9, 0.9);
    glVertex2f(240.0,700.0);
    glVertex2f(240.0,740.0);
    glEnd();
    glPopMatrix();


    glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	//sun
    //int is;
	xs=950;  //human-6
	ys= humany+180;
	radiuss =20;
	triangleAmounts = 500;
	twicePis = 100 * PI;
	glBegin(GL_TRIANGLE_FAN);
	glColor3d(0.2, 0.2, 0.2);
    glVertex2f(xs, ys);
    for(is = 0; is <= triangleAmounts; is++)
    {
        glVertex2f(xs+(radiuss*cos(is*twicePis/triangleAmounts)), ys+(radiuss*sin(is*twicePis/triangleAmounts)));
    }
	glEnd();



	glPushMatrix();
    glTranslated(750,humanMove,0);


	glBegin(GL_QUADS);
	glColor3d(0.0, 0.0, 0.6);
    glVertex2f(170.0,700.0);
    glVertex2f(230.0,700.0);
    glVertex2f(230.0,740.0);
    glVertex2f(170.0,740.0);
    glEnd();

    glBegin(GL_QUADS);
	glColor3d(0.70, 0.70, 0.70);
    glVertex2f(170.0,745.0);
    glVertex2f(230.0,745.0);
    glVertex2f(230.0,770.0);
    glVertex2f(170.0,770.0);
    glEnd();

    glLineWidth(10);
	glBegin(GL_LINES);
	glColor3d(0.70, 0.70, 0.70);
    glVertex2f(160.0, 700.0);
    glVertex2f(160.0, 740.0);
    glEnd();

    glLineWidth(10);
	glBegin(GL_LINES);
	glColor3d(0.70, 0.70, 0.70);
    glVertex2f(240.0,700.0);
    glVertex2f(240.0,740.0);
    glEnd();
    glPopMatrix();


    glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	//sun
    //int is;
	xs=1100;  //human-7
	ys= humany+180;
	radiuss =20;
	triangleAmounts = 500;
	twicePis = 100 * PI;
	glBegin(GL_TRIANGLE_FAN);
	glColor3d(0.36, 0.25, 0.2);
    glVertex2f(xs, ys);
    for(is = 0; is <= triangleAmounts; is++)
    {
        glVertex2f(xs+(radiuss*cos(is*twicePis/triangleAmounts)), ys+(radiuss*sin(is*twicePis/triangleAmounts)));
    }
	glEnd();



	glPushMatrix();
    glTranslated(900,humanMove,0);


	glBegin(GL_QUADS);
	glColor3d(0.0, 0.6, 0.0);
    glVertex2f(170.0,700.0);
    glVertex2f(230.0,700.0);
    glVertex2f(230.0,740.0);
    glVertex2f(170.0,740.0);
    glEnd();

    glBegin(GL_QUADS);
	glColor3d(0.8, 0.8, 0.8);
    glVertex2f(170.0,745.0);
    glVertex2f(230.0,745.0);
    glVertex2f(230.0,770.0);
    glVertex2f(170.0,770.0);
    glEnd();

    glLineWidth(10);
	glBegin(GL_LINES);
	glColor3d(0.85, 0.85, 0.85);
    glVertex2f(160.0, 700.0);
    glVertex2f(160.0, 740.0);
    glEnd();

    glLineWidth(10);
	glBegin(GL_LINES);
	glColor3d(0.85, 0.85, 0.85);
    glVertex2f(240.0,700.0);
    glVertex2f(240.0,740.0);
    glEnd();
    glPopMatrix();



    glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	//sun
    //int is;
	xs=1250;  //human-8
	ys= humany+180;
	radiuss =20;
	triangleAmounts = 500;
	twicePis = 100 * PI;
	glBegin(GL_TRIANGLE_FAN);
	glColor3d(0.5, 0.5, 0.5);
    glVertex2f(xs, ys);
    for(is = 0; is <= triangleAmounts; is++)
    {
        glVertex2f(xs+(radiuss*cos(is*twicePis/triangleAmounts)), ys+(radiuss*sin(is*twicePis/triangleAmounts)));
    }
	glEnd();



	glPushMatrix();
    glTranslated(1050,humanMove,0);


	glBegin(GL_QUADS);
	glColor3d(0.1, 0.1, 0.1);
    glVertex2f(170.0,700.0);
    glVertex2f(230.0,700.0);
    glVertex2f(230.0,740.0);
    glVertex2f(170.0,740.0);
    glEnd();

    glBegin(GL_QUADS);
	glColor3d(0.9, 0.9, 0.9);
    glVertex2f(170.0,745.0);
    glVertex2f(230.0,745.0);
    glVertex2f(230.0,770.0);
    glVertex2f(170.0,770.0);
    glEnd();

    glLineWidth(10);
	glBegin(GL_LINES);
	glColor3d(0.9, 0.9, 0.9);
    glVertex2f(160.0, 700.0);
    glVertex2f(160.0, 740.0);
    glEnd();

    glLineWidth(10);
	glBegin(GL_LINES);
	glColor3d(0.9, 0.9, 0.9);
    glVertex2f(240.0,700.0);
    glVertex2f(240.0,740.0);
    glEnd();
    glPopMatrix();



    glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	//sun
    //int is;
	xs=280;  //human-9 upper row
	ys= humany+60;
	radiuss =20;
	triangleAmounts = 500;
	twicePis = 100 * PI;
	glBegin(GL_TRIANGLE_FAN);
	glColor3d(0.7, 0.7, 0.7);
    glVertex2f(xs, ys);
    for(is = 0; is <= triangleAmounts; is++)
    {
        glVertex2f(xs+(radiuss*cos(is*twicePis/triangleAmounts)), ys+(radiuss*sin(is*twicePis/triangleAmounts)));
    }
	glEnd();



	glPushMatrix();
    glTranslated(80,humanMove-120,0);


	glBegin(GL_QUADS);
	glColor3d(0.35, 0.35, 0.35);
    glVertex2f(170.0,700.0);
    glVertex2f(230.0,700.0);
    glVertex2f(230.0,740.0);
    glVertex2f(170.0,740.0);
    glEnd();

    glBegin(GL_QUADS);
	glColor3d(0.9, 0.9, 0.9);
    glVertex2f(170.0,745.0);
    glVertex2f(230.0,745.0);
    glVertex2f(230.0,770.0);
    glVertex2f(170.0,770.0);
    glEnd();

    glLineWidth(10);
	glBegin(GL_LINES);
	glColor3d(0.9, 0.9, 0.9);
    glVertex2f(160.0, 700.0);
    glVertex2f(160.0, 740.0);
    glEnd();

    glLineWidth(10);
	glBegin(GL_LINES);
	glColor3d(0.9, 0.9, 0.9);
    glVertex2f(240.0,700.0);
    glVertex2f(240.0,740.0);
    glEnd();
    glPopMatrix();


    glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	//sun
    //int is;
	xs=430;  //human-10 upper row
	ys= humany+60;
	radiuss =20;
	triangleAmounts = 500;
	twicePis = 100 * PI;
	glBegin(GL_TRIANGLE_FAN);
	glColor3d(0.15, 0.15, 0.15);
    glVertex2f(xs, ys);
    for(is = 0; is <= triangleAmounts; is++)
    {
        glVertex2f(xs+(radiuss*cos(is*twicePis/triangleAmounts)), ys+(radiuss*sin(is*twicePis/triangleAmounts)));
    }
	glEnd();



	glPushMatrix();
    glTranslated(230,humanMove-120,0);


	glBegin(GL_QUADS);
	glColor3d(0.0, 0.0, 0.4);
    glVertex2f(170.0,700.0);
    glVertex2f(230.0,700.0);
    glVertex2f(230.0,740.0);
    glVertex2f(170.0,740.0);
    glEnd();

    glBegin(GL_QUADS);
	glColor3d(0.8, 0.8, 0.8);
    glVertex2f(170.0,745.0);
    glVertex2f(230.0,745.0);
    glVertex2f(230.0,770.0);
    glVertex2f(170.0,770.0);
    glEnd();

    glLineWidth(10);
	glBegin(GL_LINES);
	glColor3d(0.85, 0.85, 0.85);
    glVertex2f(160.0, 700.0);
    glVertex2f(160.0, 740.0);
    glEnd();

    glLineWidth(10);
	glBegin(GL_LINES);
	glColor3d(0.85, 0.85, 0.85);
    glVertex2f(240.0,700.0);
    glVertex2f(240.0,740.0);
    glEnd();
    glPopMatrix();


    glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	//sun
    //int is;
	xs=580;  //human-11 upper row
	ys= humany+60;
	radiuss =20;
	triangleAmounts = 500;
	twicePis = 100 * PI;
	glBegin(GL_TRIANGLE_FAN);
	glColor3d(0.36, 0.25, 0.2);
    glVertex2f(xs, ys);
    for(is = 0; is <= triangleAmounts; is++)
    {
        glVertex2f(xs+(radiuss*cos(is*twicePis/triangleAmounts)), ys+(radiuss*sin(is*twicePis/triangleAmounts)));
    }
	glEnd();



	glPushMatrix();
    glTranslated(380,humanMove-120,0);


	glBegin(GL_QUADS);
	glColor3d(0.5, 0.0, 0.0);
    glVertex2f(170.0,700.0);
    glVertex2f(230.0,700.0);
    glVertex2f(230.0,740.0);
    glVertex2f(170.0,740.0);
    glEnd();

    glBegin(GL_QUADS);
	glColor3d(0.8, 0.8, 0.8);
    glVertex2f(170.0,745.0);
    glVertex2f(230.0,745.0);
    glVertex2f(230.0,770.0);
    glVertex2f(170.0,770.0);
    glEnd();

    glLineWidth(10);
	glBegin(GL_LINES);
	glColor3d(0.85, 0.85, 0.85);
    glVertex2f(160.0, 700.0);
    glVertex2f(160.0, 740.0);
    glEnd();

    glLineWidth(10);
	glBegin(GL_LINES);
	glColor3d(0.85, 0.85, 0.85);
    glVertex2f(240.0,700.0);
    glVertex2f(240.0,740.0);
    glEnd();
    glPopMatrix();



    glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	//sun
    //int is;
	xs=730;  //human-12 upper row
	ys= humany+60;
	radiuss =20;
	triangleAmounts = 500;
	twicePis = 100 * PI;
	glBegin(GL_TRIANGLE_FAN);
	glColor3d(0.7, 0.7, 0.7);
    glVertex2f(xs, ys);
    for(is = 0; is <= triangleAmounts; is++)
    {
        glVertex2f(xs+(radiuss*cos(is*twicePis/triangleAmounts)), ys+(radiuss*sin(is*twicePis/triangleAmounts)));
    }
	glEnd();



	glPushMatrix();
    glTranslated(530,humanMove-120,0);


	glBegin(GL_QUADS);
	glColor3d(0.1, 0.1, 0.1);
    glVertex2f(170.0,700.0);
    glVertex2f(230.0,700.0);
    glVertex2f(230.0,740.0);
    glVertex2f(170.0,740.0);
    glEnd();

    glBegin(GL_QUADS);
	glColor3d(0.9, 0.9, 0.9);
    glVertex2f(170.0,745.0);
    glVertex2f(230.0,745.0);
    glVertex2f(230.0,770.0);
    glVertex2f(170.0,770.0);
    glEnd();

    glLineWidth(10);
	glBegin(GL_LINES);
	glColor3d(0.9, 0.9, 0.9);
    glVertex2f(160.0, 700.0);
    glVertex2f(160.0, 740.0);
    glEnd();

    glLineWidth(10);
	glBegin(GL_LINES);
	glColor3d(0.9, 0.9, 0.9);
    glVertex2f(240.0,700.0);
    glVertex2f(240.0,740.0);
    glEnd();
    glPopMatrix();


    glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	//sun
    //int is;
	xs=880;  //human-13 upper row
	ys= humany+60;
	radiuss =20;
	triangleAmounts = 500;
	twicePis = 100 * PI;
	glBegin(GL_TRIANGLE_FAN);
	glColor3d(0.15, 0.15, 0.15);
    glVertex2f(xs, ys);
    for(is = 0; is <= triangleAmounts; is++)
    {
        glVertex2f(xs+(radiuss*cos(is*twicePis/triangleAmounts)), ys+(radiuss*sin(is*twicePis/triangleAmounts)));
    }
	glEnd();



	glPushMatrix();
    glTranslated(680,humanMove-120,0);


	glBegin(GL_QUADS);
	glColor3d(0.0, 0.0, 0.4);
    glVertex2f(170.0,700.0);
    glVertex2f(230.0,700.0);
    glVertex2f(230.0,740.0);
    glVertex2f(170.0,740.0);
    glEnd();

    glBegin(GL_QUADS);
	glColor3d(0.8, 0.8, 0.8);
    glVertex2f(170.0,745.0);
    glVertex2f(230.0,745.0);
    glVertex2f(230.0,770.0);
    glVertex2f(170.0,770.0);
    glEnd();

    glLineWidth(10);
	glBegin(GL_LINES);
	glColor3d(0.85, 0.85, 0.85);
    glVertex2f(160.0, 700.0);
    glVertex2f(160.0, 740.0);
    glEnd();

    glLineWidth(10);
	glBegin(GL_LINES);
	glColor3d(0.85, 0.85, 0.85);
    glVertex2f(240.0,700.0);
    glVertex2f(240.0,740.0);
    glEnd();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	//sun
    //int is;
	xs=1030;  //human-14 upper row
	ys= humany+60;
	radiuss =20;
	triangleAmounts = 500;
	twicePis = 100 * PI;
	glBegin(GL_TRIANGLE_FAN);
	glColor3d(0.36, 0.25, 0.2);
    glVertex2f(xs, ys);
    for(is = 0; is <= triangleAmounts; is++)
    {
        glVertex2f(xs+(radiuss*cos(is*twicePis/triangleAmounts)), ys+(radiuss*sin(is*twicePis/triangleAmounts)));
    }
	glEnd();



	glPushMatrix();
    glTranslated(830,humanMove-120,0);


	glBegin(GL_QUADS);
	glColor3d(0.0, 0.6, 0.0);
    glVertex2f(170.0,700.0);
    glVertex2f(230.0,700.0);
    glVertex2f(230.0,740.0);
    glVertex2f(170.0,740.0);
    glEnd();

    glBegin(GL_QUADS);
	glColor3d(0.70, 0.70, 0.70);
    glVertex2f(170.0,745.0);
    glVertex2f(230.0,745.0);
    glVertex2f(230.0,770.0);
    glVertex2f(170.0,770.0);
    glEnd();

    glLineWidth(10);
	glBegin(GL_LINES);
	glColor3d(0.70, 0.70, 0.70);
    glVertex2f(160.0, 700.0);
    glVertex2f(160.0, 740.0);
    glEnd();

    glLineWidth(10);
	glBegin(GL_LINES);
	glColor3d(0.70, 0.70, 0.70);
    glVertex2f(240.0,700.0);
    glVertex2f(240.0,740.0);
    glEnd();
    glPopMatrix();


    glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	//sun
    //int is;
	xs=1180;  //human-15 upper row
	ys= humany+60;
	radiuss =20;
	triangleAmounts = 500;
	twicePis = 100 * PI;
	glBegin(GL_TRIANGLE_FAN);
	glColor3d(0.15, 0.15, 0.15);
    glVertex2f(xs, ys);
    for(is = 0; is <= triangleAmounts; is++)
    {
        glVertex2f(xs+(radiuss*cos(is*twicePis/triangleAmounts)), ys+(radiuss*sin(is*twicePis/triangleAmounts)));
    }
	glEnd();



	glPushMatrix();
    glTranslated(980,humanMove-120,0);


	glBegin(GL_QUADS);
	glColor3d(0.35,0.35,0.35);
    glVertex2f(170.0,700.0);
    glVertex2f(230.0,700.0);
    glVertex2f(230.0,740.0);
    glVertex2f(170.0,740.0);
    glEnd();

    glBegin(GL_QUADS);
	glColor3d(0.9, 0.9, 0.9);
    glVertex2f(170.0,745.0);
    glVertex2f(230.0,745.0);
    glVertex2f(230.0,770.0);
    glVertex2f(170.0,770.0);
    glEnd();

    glLineWidth(10);
	glBegin(GL_LINES);
	glColor3d(0.9, 0.9, 0.9);
    glVertex2f(160.0, 700.0);
    glVertex2f(160.0, 740.0);
    glEnd();

    glLineWidth(10);
	glBegin(GL_LINES);
	glColor3d(0.9, 0.9, 0.9);
    glVertex2f(240.0,700.0);
    glVertex2f(240.0,740.0);
    glEnd();
    glPopMatrix();


}



void Flowers(){

glMatrixMode(GL_MODELVIEW);//flower-1
	glLoadIdentity();

	//sun
    //int is;
	xs=flowerx+380;
	ys= 430;
	radiuss =30;
	triangleAmounts = 500;
	twicePis = 100 * PI;
	glBegin(GL_TRIANGLE_FAN);
	glColor3d(1.0, 0.5, 0.0);
    glVertex2f(xs, ys);
    for(is = 0; is <= triangleAmounts; is++)
    {
        glVertex2f(xs+(radiuss*cos(is*twicePis/triangleAmounts)), ys+(radiuss*sin(is*twicePis/triangleAmounts)));
    }
	glEnd();



	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	//sun
    //int is;
	xs=flowerx+380;
	ys= 430;
	radiuss =20;
	triangleAmounts = 500;
	twicePis = 100 * PI;
	glBegin(GL_TRIANGLE_FAN);
	glColor3d(0.0, 0.6, 0.0);
    glVertex2f(xs, ys);
    for(is = 0; is <= triangleAmounts; is++)
    {
        glVertex2f(xs+(radiuss*cos(is*twicePis/triangleAmounts)), ys+(radiuss*sin(is*twicePis/triangleAmounts)));
    }
	glEnd();


	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	//sun
    //int is;
	xs=flowerx+380;
	ys= 430;
	radiuss =7;
	triangleAmounts = 500;
	twicePis = 100 * PI;
	glBegin(GL_TRIANGLE_FAN);
	glColor3d(1.0, 0.0, 0.0);
    glVertex2f(xs, ys);
    for(is = 0; is <= triangleAmounts; is++)
    {
        glVertex2f(xs+(radiuss*cos(is*twicePis/triangleAmounts)), ys+(radiuss*sin(is*twicePis/triangleAmounts)));
    }
	glEnd();



	glMatrixMode(GL_MODELVIEW);//flower-2
	glLoadIdentity();

	//sun
    //int is;
	xs=flowerx+280;
	ys= 430;
	radiuss =30;
	triangleAmounts = 500;
	twicePis = 100 * PI;
	glBegin(GL_TRIANGLE_FAN);
	glColor3d(1.0, 0.7, 0.0);
    glVertex2f(xs, ys);
    for(is = 0; is <= triangleAmounts; is++)
    {
        glVertex2f(xs+(radiuss*cos(is*twicePis/triangleAmounts)), ys+(radiuss*sin(is*twicePis/triangleAmounts)));
    }
	glEnd();



	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	//sun
    //int is;
	xs=flowerx+280;
	ys= 430;
	radiuss =20;
	triangleAmounts = 500;
	twicePis = 100 * PI;
	glBegin(GL_TRIANGLE_FAN);
	glColor3d(1.0, 0.4, 0.0);
    glVertex2f(xs, ys);
    for(is = 0; is <= triangleAmounts; is++)
    {
        glVertex2f(xs+(radiuss*cos(is*twicePis/triangleAmounts)), ys+(radiuss*sin(is*twicePis/triangleAmounts)));
    }
	glEnd();


	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	//sun
    //int is;
	xs=flowerx+80;
	ys= 430;
	radiuss =7;
	triangleAmounts = 500;
	twicePis = 100 * PI;
	glBegin(GL_TRIANGLE_FAN);
	glColor3d(0.9, 0.0, 0.0);
    glVertex2f(xs, ys);
    for(is = 0; is <= triangleAmounts; is++)
    {
        glVertex2f(xs+(radiuss*cos(is*twicePis/triangleAmounts)), ys+(radiuss*sin(is*twicePis/triangleAmounts)));
    }
	glEnd();



	glMatrixMode(GL_MODELVIEW);//flower-3
	glLoadIdentity();

	//sun
    //int is;
	xs=flowerx+180;
	ys= 430;
	radiuss =30;
	triangleAmounts = 500;
	twicePis = 100 * PI;
	glBegin(GL_TRIANGLE_FAN);
	glColor3d(0.0, 0.5, 0.0);
    glVertex2f(xs, ys);
    for(is = 0; is <= triangleAmounts; is++)
    {
        glVertex2f(xs+(radiuss*cos(is*twicePis/triangleAmounts)), ys+(radiuss*sin(is*twicePis/triangleAmounts)));
    }
	glEnd();



	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	//sun
    //int is;
	xs=flowerx+180;
	ys= 430;
	radiuss =20;
	triangleAmounts = 500;
	twicePis = 100 * PI;
	glBegin(GL_TRIANGLE_FAN);
	glColor3d(1.0, 0.5, 0.0);
    glVertex2f(xs, ys);
    for(is = 0; is <= triangleAmounts; is++)
    {
        glVertex2f(xs+(radiuss*cos(is*twicePis/triangleAmounts)), ys+(radiuss*sin(is*twicePis/triangleAmounts)));
    }
	glEnd();


	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	//sun
    //int is;
	xs=flowerx+180;
	ys= 430;
	radiuss =7;
	triangleAmounts = 500;
	twicePis = 100 * PI;
	glBegin(GL_TRIANGLE_FAN);
	glColor3d(1.0, 0.0, 0.0);
    glVertex2f(xs, ys);
    for(is = 0; is <= triangleAmounts; is++)
    {
        glVertex2f(xs+(radiuss*cos(is*twicePis/triangleAmounts)), ys+(radiuss*sin(is*twicePis/triangleAmounts)));
    }
	glEnd();


	glMatrixMode(GL_MODELVIEW);//flower-4
	glLoadIdentity();

	//sun
    //int is;
	xs=flowerx+80;
	ys= 430;
	radiuss =30;
	triangleAmounts = 500;
	twicePis = 100 * PI;
	glBegin(GL_TRIANGLE_FAN);
	glColor3d(1.0, 0.7, 0.0);
    glVertex2f(xs, ys);
    for(is = 0; is <= triangleAmounts; is++)
    {
        glVertex2f(xs+(radiuss*cos(is*twicePis/triangleAmounts)), ys+(radiuss*sin(is*twicePis/triangleAmounts)));
    }
	glEnd();



	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	//sun
    //int is;
	xs=flowerx+80;
	ys= 430;
	radiuss =20;
	triangleAmounts = 500;
	twicePis = 100 * PI;
	glBegin(GL_TRIANGLE_FAN);
	glColor3d(1.0, 0.4, 0.0);
    glVertex2f(xs, ys);
    for(is = 0; is <= triangleAmounts; is++)
    {
        glVertex2f(xs+(radiuss*cos(is*twicePis/triangleAmounts)), ys+(radiuss*sin(is*twicePis/triangleAmounts)));
    }
	glEnd();


	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	//sun
    //int is;
	xs=flowerx+80;
	ys= 430;
	radiuss =7;
	triangleAmounts = 500;
	twicePis = 100 * PI;
	glBegin(GL_TRIANGLE_FAN);
	glColor3d(1.0, 0.0, 0.0);
    glVertex2f(xs, ys);
    for(is = 0; is <= triangleAmounts; is++)
    {
        glVertex2f(xs+(radiuss*cos(is*twicePis/triangleAmounts)), ys+(radiuss*sin(is*twicePis/triangleAmounts)));
    }
	glEnd();



	glMatrixMode(GL_MODELVIEW);//flower-5
	glLoadIdentity();

	//sun
    //int is;
	xs=flowerx-20;
	ys= 430;
	radiuss =30;
	triangleAmounts = 500;
	twicePis = 100 * PI;
	glBegin(GL_TRIANGLE_FAN);
	glColor3d(1.0, 0.5, 0.0);
    glVertex2f(xs, ys);
    for(is = 0; is <= triangleAmounts; is++)
    {
        glVertex2f(xs+(radiuss*cos(is*twicePis/triangleAmounts)), ys+(radiuss*sin(is*twicePis/triangleAmounts)));
    }
	glEnd();



	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	//sun
    //int is;
	xs=flowerx-20;
	ys= 430;
	radiuss =20;
	triangleAmounts = 500;
	twicePis = 100 * PI;
	glBegin(GL_TRIANGLE_FAN);
	glColor3d(0.0, 0.6, 0.0);
    glVertex2f(xs, ys);
    for(is = 0; is <= triangleAmounts; is++)
    {
        glVertex2f(xs+(radiuss*cos(is*twicePis/triangleAmounts)), ys+(radiuss*sin(is*twicePis/triangleAmounts)));
    }
	glEnd();


	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	//sun
    //int is;
	xs=flowerx-20;
	ys= 430;
	radiuss =7;
	triangleAmounts = 500;
	twicePis = 100 * PI;
	glBegin(GL_TRIANGLE_FAN);
	glColor3d(1.0, 0.0, 0.0);
    glVertex2f(xs, ys);
    for(is = 0; is <= triangleAmounts; is++)
    {
        glVertex2f(xs+(radiuss*cos(is*twicePis/triangleAmounts)), ys+(radiuss*sin(is*twicePis/triangleAmounts)));
    }
	glEnd();


glMatrixMode(GL_MODELVIEW);//flower-6 second row below
	glLoadIdentity();

	//sun
    //int is;
	xs=flowerx+270;
	ys= 500;
	radiuss =30;
	triangleAmounts = 500;
	twicePis = 100 * PI;
	glBegin(GL_TRIANGLE_FAN);
	glColor3d(0.0, 0.5, 0.0);
    glVertex2f(xs, ys);
    for(is = 0; is <= triangleAmounts; is++)
    {
        glVertex2f(xs+(radiuss*cos(is*twicePis/triangleAmounts)), ys+(radiuss*sin(is*twicePis/triangleAmounts)));
    }
	glEnd();



	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	//sun
    //int is;
	xs=flowerx+270;
	ys= 500;
	radiuss =20;
	triangleAmounts = 500;
	twicePis = 100 * PI;
	glBegin(GL_TRIANGLE_FAN);
	glColor3d(1.0, 0.5, 0.0);
    glVertex2f(xs, ys);
    for(is = 0; is <= triangleAmounts; is++)
    {
        glVertex2f(xs+(radiuss*cos(is*twicePis/triangleAmounts)), ys+(radiuss*sin(is*twicePis/triangleAmounts)));
    }
	glEnd();


	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	//sun
    //int is;
	xs=flowerx+270;
	ys= 500;
	radiuss =7;
	triangleAmounts = 500;
	twicePis = 100 * PI;
	glBegin(GL_TRIANGLE_FAN);
	glColor3d(1.0, 0.0, 0.0);
    glVertex2f(xs, ys);
    for(is = 0; is <= triangleAmounts; is++)
    {
        glVertex2f(xs+(radiuss*cos(is*twicePis/triangleAmounts)), ys+(radiuss*sin(is*twicePis/triangleAmounts)));
    }
	glEnd();


	glMatrixMode(GL_MODELVIEW);//flower-7 second row below
	glLoadIdentity();

	//sun
    //int is;
	xs=flowerx+190;
	ys= 500;
	radiuss =30;
	triangleAmounts = 500;
	twicePis = 100 * PI;
	glBegin(GL_TRIANGLE_FAN);
	glColor3d(1.0, 0.5, 0.0);
    glVertex2f(xs, ys);
    for(is = 0; is <= triangleAmounts; is++)
    {
        glVertex2f(xs+(radiuss*cos(is*twicePis/triangleAmounts)), ys+(radiuss*sin(is*twicePis/triangleAmounts)));
    }
	glEnd();



	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	//sun
    //int is;
	xs=flowerx+190;
	ys= 500;
	radiuss =20;
	triangleAmounts = 500;
	twicePis = 100 * PI;
	glBegin(GL_TRIANGLE_FAN);
	glColor3d(0.0, 0.6, 0.0);
    glVertex2f(xs, ys);
    for(is = 0; is <= triangleAmounts; is++)
    {
        glVertex2f(xs+(radiuss*cos(is*twicePis/triangleAmounts)), ys+(radiuss*sin(is*twicePis/triangleAmounts)));
    }
	glEnd();


	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	//sun
    //int is;
	xs=flowerx+190;
	ys= 500;
	radiuss =7;
	triangleAmounts = 500;
	twicePis = 100 * PI;
	glBegin(GL_TRIANGLE_FAN);
	glColor3d(1.0, 0.0, 0.0);
    glVertex2f(xs, ys);
    for(is = 0; is <= triangleAmounts; is++)
    {
        glVertex2f(xs+(radiuss*cos(is*twicePis/triangleAmounts)), ys+(radiuss*sin(is*twicePis/triangleAmounts)));
    }
	glEnd();


	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	//sun
    //int is;
	xs=flowerx+110;//flower-8 second row below
	ys= 500;
	radiuss =30;
	triangleAmounts = 500;
	twicePis = 100 * PI;
	glBegin(GL_TRIANGLE_FAN);
	glColor3d(1.0, 0.4, 0.0);
    glVertex2f(xs, ys);
    for(is = 0; is <= triangleAmounts; is++)
    {
        glVertex2f(xs+(radiuss*cos(is*twicePis/triangleAmounts)), ys+(radiuss*sin(is*twicePis/triangleAmounts)));
    }
	glEnd();



	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();


	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	//sun
    //int is;
	xs=flowerx+110;
	radiuss =20;
	triangleAmounts = 500;
	twicePis = 100 * PI;
	glBegin(GL_TRIANGLE_FAN);
	glColor3d(0.6, 0.0, 0.0);
    glVertex2f(xs, ys);
    for(is = 0; is <= triangleAmounts; is++)
    {
        glVertex2f(xs+(radiuss*cos(is*twicePis/triangleAmounts)), ys+(radiuss*sin(is*twicePis/triangleAmounts)));
    }
	glEnd();



	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	//sun
    //int is;
	xs=flowerx+110;
	ys= 500;
	radiuss =10;
	triangleAmounts = 500;
	twicePis = 100 * PI;
	glBegin(GL_TRIANGLE_FAN);
	glColor3d(0.6, 0.1, 0.0);
    glVertex2f(xs, ys);
    for(is = 0; is <= triangleAmounts; is++)
    {
        glVertex2f(xs+(radiuss*cos(is*twicePis/triangleAmounts)), ys+(radiuss*sin(is*twicePis/triangleAmounts)));
    }
	glEnd();

	//sun
    //int is;
	xs=flowerx+30;  //flower-9 second row below
	ys= 500;
	radiuss =30;
	triangleAmounts = 500;
	twicePis = 100 * PI;
	glBegin(GL_TRIANGLE_FAN);
	glColor3d(0.0, 0.5, 0.0);
    glVertex2f(xs, ys);
    for(is = 0; is <= triangleAmounts; is++)
    {
        glVertex2f(xs+(radiuss*cos(is*twicePis/triangleAmounts)), ys+(radiuss*sin(is*twicePis/triangleAmounts)));
    }
	glEnd();



	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	//sun
    //int is;
	xs=flowerx+30;
	ys= 500;
	radiuss =20;
	triangleAmounts = 500;
	twicePis = 100 * PI;
	glBegin(GL_TRIANGLE_FAN);
	glColor3d(1.0, 0.5, 0.0);
    glVertex2f(xs, ys);
    for(is = 0; is <= triangleAmounts; is++)
    {
        glVertex2f(xs+(radiuss*cos(is*twicePis/triangleAmounts)), ys+(radiuss*sin(is*twicePis/triangleAmounts)));
    }
	glEnd();


	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	//sun
    //int is;
	xs=flowerx+30;
	ys= 500;
	radiuss =7;
	triangleAmounts = 500;
	twicePis = 100 * PI;
	glBegin(GL_TRIANGLE_FAN);
	glColor3d(1.0, 0.0, 0.0);
    glVertex2f(xs, ys);
    for(is = 0; is <= triangleAmounts; is++)
    {
        glVertex2f(xs+(radiuss*cos(is*twicePis/triangleAmounts)), ys+(radiuss*sin(is*twicePis/triangleAmounts)));
    }
	glEnd();




}



void TreeFront ()
{
    //Front trees right
	xs=1110;
	ys= 370;
	radiuss =50;
	triangleAmounts = 500;
	twicePis = 100 * PI;
	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(0, 143, 58);
    glVertex2f(xs, ys);
    for(is = 0; is <= triangleAmounts; is++)
    {
        glVertex2f(xs+(radiuss*cos(is*twicePis/triangleAmounts)), ys+(radiuss*sin(is*twicePis/triangleAmounts)));
    }
	glEnd();

	xs=1080;
	ys= 420;
	radiuss =50;
	triangleAmounts = 500;
	twicePis = 100 * PI;
	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(0, 143, 58);
    glVertex2f(xs, ys);
    for(is = 0; is <= triangleAmounts; is++)
    {
        glVertex2f(xs+(radiuss*cos(is*twicePis/triangleAmounts)), ys+(radiuss*sin(is*twicePis/triangleAmounts)));
    }
	glEnd();

	xs=1130;
	ys= 420;
	radiuss =50;
	triangleAmounts = 500;
	twicePis = 100 * PI;
	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(0, 143, 58);
    glVertex2f(xs, ys);
    for(is = 0; is <= triangleAmounts; is++)
    {
        glVertex2f(xs+(radiuss*cos(is*twicePis/triangleAmounts)), ys+(radiuss*sin(is*twicePis/triangleAmounts)));
    }
	glEnd();


	glLineWidth(7.5);
	glBegin(GL_LINES);              // Each set of 4 vertices form a quad
	glColor3f(0.0f, 0.0f, 0.0f); // Red
	glVertex2i(1105,420);    // x, y
	glVertex2i(1105,570);    // x, y

	glEnd();

	 //Front trees right
	xs=300;
	ys= 370;
	radiuss =50;
	triangleAmounts = 500;
	twicePis = 100 * PI;
	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(0, 143, 58);
    glVertex2f(xs, ys);
    for(is = 0; is <= triangleAmounts; is++)
    {
        glVertex2f(xs+(radiuss*cos(is*twicePis/triangleAmounts)), ys+(radiuss*sin(is*twicePis/triangleAmounts)));
    }
	glEnd();

	xs=270;
	ys= 420;
	radiuss =50;
	triangleAmounts = 500;
	twicePis = 100 * PI;
	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(0, 143, 58);
    glVertex2f(xs, ys);
    for(is = 0; is <= triangleAmounts; is++)
    {
        glVertex2f(xs+(radiuss*cos(is*twicePis/triangleAmounts)), ys+(radiuss*sin(is*twicePis/triangleAmounts)));
    }
	glEnd();

	xs=330;
	ys= 420;
	radiuss =50;
	triangleAmounts = 500;
	twicePis = 100 * PI;
	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(0, 143, 58);
    glVertex2f(xs, ys);
    for(is = 0; is <= triangleAmounts; is++)
    {
        glVertex2f(xs+(radiuss*cos(is*twicePis/triangleAmounts)), ys+(radiuss*sin(is*twicePis/triangleAmounts)));
    }
	glEnd();


	glLineWidth(7.5);
	glBegin(GL_LINES);              // Each set of 4 vertices form a quad
	glColor3f(0.0f, 0.0f, 0.0f); // Red
	glVertex2i(300,420);    // x, y
	glVertex2i(300,570);    // x, y

	glEnd();

	//flowers bottom left
	xs= 250;
	ys= 510;
	radiuss =5;
	triangleAmounts = 150;
	twicePis = 100 * PI;
	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(255, 171, 0);
    glVertex2f(xs, ys);
    for(is = 0; is <= triangleAmounts; is++)
    {
        glVertex2f(xs+(radiuss*cos(is*twicePis/triangleAmounts)), ys+(radiuss*sin(is*twicePis/triangleAmounts)));
    }
	glEnd();

    xs= 220;
	ys= 550;
	radiuss =5;
	triangleAmounts = 150;
	twicePis = 100 * PI;
	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(255, 171, 0);
    glVertex2f(xs, ys);
    for(is = 0; is <= triangleAmounts; is++)
    {
        glVertex2f(xs+(radiuss*cos(is*twicePis/triangleAmounts)), ys+(radiuss*sin(is*twicePis/triangleAmounts)));
    }
	glEnd();

    xs= 280;
	ys= 540;
	radiuss =5;
	triangleAmounts = 150;
	twicePis = 100 * PI;
	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(255, 171, 0);
    glVertex2f(xs, ys);
    for(is = 0; is <= triangleAmounts; is++)
    {
        glVertex2f(xs+(radiuss*cos(is*twicePis/triangleAmounts)), ys+(radiuss*sin(is*twicePis/triangleAmounts)));
    }
	glEnd();
    //flowers bottom left end

    //flowers bottom right
    xs= 1120;
	ys= 510;
	radiuss =5;
	triangleAmounts = 150;
	twicePis = 100 * PI;
	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(255, 171, 0);
    glVertex2f(xs, ys);
    for(is = 0; is <= triangleAmounts; is++)
    {
        glVertex2f(xs+(radiuss*cos(is*twicePis/triangleAmounts)), ys+(radiuss*sin(is*twicePis/triangleAmounts)));
    }
	glEnd();

    xs= 1140;
	ys= 550;
	radiuss =5;
	triangleAmounts = 150;
	twicePis = 100 * PI;
	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(255, 171, 0);
    glVertex2f(xs, ys);
    for(is = 0; is <= triangleAmounts; is++)
    {
        glVertex2f(xs+(radiuss*cos(is*twicePis/triangleAmounts)), ys+(radiuss*sin(is*twicePis/triangleAmounts)));
    }
	glEnd();
}

void rain(){

    glColor3f(_dayWhite1,_dayWhite1,_dayWhite1);
    glLineWidth(1.0);
    for(int j=0;j<2400;j=j+100){
        for(int i=0;i<1440;i=i+50){
        glBegin(GL_LINES);
        glVertex2d(rainx+i, rainy+j);
        glVertex2d(rainx+i-10, rainy+j+20);
        glEnd();
        }
    }
}

void keyboard(unsigned char key, int x, int y)
{
    switch (key)
    {

    case 'f':
        birdStatus=1;
        glutTimerFunc(100, moveBirds, 0);
        break;

    case 'g':
        birdStatus=0;
        break;

    case 'c':
        cloudStatus=1;
        glutTimerFunc(100, moveClouds, 0);
        break;

    case 'v':
        cloudStatus=0;

        break;

    case 'r':
        rainStatus=1;
        glutTimerFunc(100, rain, 0);
        break;

    case 't':
        rainStatus=0;
        break;

    case 'n':
        _red = 0.18;
        _green = 0.18;
        _blue = 0.18;
        _dayWhite1 = 0.92;
        _dayWhite2 = 0.8;
        Sky();

        sunXaxis=1320;
        sunYaxis=65;
        sunRadius=40;
        _red2=1.0;
        _green2=1.0;
        _blue2=1.0;
        Sun();

        _red4=0.7;
        _green4=0.7;
        _blue4=0.7;
        Cloud();

        _red3=0.0;
        _green3=0.0;
        _blue3=0.0;
        Bird();

        cloud1a=320;
        cloud1b=100;
        cloud1c=344;
        cloud1d=98;
        cloud1e=360;
        cloud1f=100;

        cloud2a=-200;
        cloud2b=80;
        cloud2c=-180;
        cloud2d=81;
        cloud2e=-150;
        cloud2f=80;


        cloud3a=620;
        cloud3b=110;
        cloud3c=644;
        cloud3d=108;
        cloud3e=660;
        cloud3f=110;
        Cloud();
        glutPostRedisplay();

        break;
    case 'd':
        _red = 0.59;
        _green = 0.87;
        _blue = 0.85;
        _dayWhite1 = 1.0;
        _dayWhite2 = 0.9;
        Sky();

        cloud1a=440;
        cloud1b=110;
        cloud1c=470;
        cloud1d=108;
        cloud1e=490;
        cloud1f=110;

        cloud2a=0;
        cloud2b=80;
        cloud2c=20;
        cloud2d=81;
        cloud2e=40;
        cloud2f=80;


        cloud3a=840;
        cloud3b=40;
        cloud3c=864;
        cloud3d=38;
        cloud3e=884;
        cloud3f=40;

        _red4=1.0;
        _green4=1.0;
        _blue4=1.0;
        Cloud();

        _red2= 1.00;
        _green2= 0.90;
        _blue2= 0.00;

        sunXaxis=200;
        sunYaxis=100;
        sunRadius=60;
        glutPostRedisplay();

        break;
    case 'k':
        humanStatus=1;
        flowerx=500;
        glutTimerFunc(100, moveHuman, 0);
        glutPostRedisplay();
        break;

    case 'l':
        humanStatus=0;
        flowerx=-2500;
        humany=780;
        humanMove=280;
        glutPostRedisplay();
        break;

    default:
        break;

    }

}



void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();


    Sky();
	Sun();
    Cloud();
    Field ();
    TriangleTrees ();
    RedSun();
    SmallTreeBack();
    Bird();
    Flowers();
    ShahidMinar();
    Stairs();
    TreeFront();
    rain();


    //main floor
    glColor3f (_dayWhite1, _dayWhite1, _dayWhite1);
	glBegin(GL_QUADS);
	glVertex3f(0.00f, 800.0f, 0.0f);
	glVertex3f(200.00f, 564.00f, 0.0f);
	glVertex3f(1216.00f, 564.00f, 0.0f);
	glVertex3f(1440.00f, 800.00f, 0.0f);
	glEnd();
	Flowers();

	Human();

glFlush ();
}
int main(int argc, char** argv)
{
glutInit(&argc, argv);
glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
glutInitWindowSize (1440, 800);
glutInitWindowPosition (0, 0);
glutCreateWindow ("21st February");
glutDisplayFunc(display);
glutKeyboardFunc(keyboard);
init();

glutMainLoop();
return 0; /* ISO C requires main to return int. */
}
