#include <windows.h>
#ifdef __APPLE_CC__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

static int a = 5,i;
int flag = 1,a1=0,a2=0,a3=0;
double htx = -0.5, hty = -0.4, htz = 0.0, hsx = 0.5, hsy = 0.5, hsz = 0.5;
double x=0,xx=-2.5,r1=0.8,g1=0.8,posx = 0, posy = 0, posz = 2, eyex = 0, eyey = 0, eyez = 0, upx = 0, upy = 1, upz = 0;

static void idle(void)
{
    glutPostRedisplay();
}

void specialKey(int key, int, int)
{
    switch (key)
    {
    case GLUT_KEY_LEFT:
        x = (x - 0.1);
        if(x<-1)
        {
            x = 3.5;
        }
        break;
    case GLUT_KEY_RIGHT:
        x = (x + 0.1);
        if(x>3.5)
        {
            x = x-3.5;
        }
        break;

        //camera angle
    case GLUT_KEY_F1:
        posx += 0.01;
        break;
    case GLUT_KEY_F2:
        posx -= 0.01;
        break;
    case GLUT_KEY_F3:
        posy += 0.01;
        break;
    case GLUT_KEY_F4:
        posy -= 0.01;
        break;
    case GLUT_KEY_F5:
        posz += 0.01;
        break;
    case GLUT_KEY_F6:
        posz -= 0.01;
        break;

     //Car rotation
    case GLUT_KEY_F7:
         a1=1;
         a2=0;
         a3=0;
        (a += 5);
        break;
    case GLUT_KEY_F8:
         a1=1;
         a2=0;
         a3=0;
        (a -= 5);
        break;
    case GLUT_KEY_F9:
         a2=1;
         a1=0;
         a3=0;
        (a += 5);
        break;
    case GLUT_KEY_F10:
         a2=1;
         a1=0;
         a3=0;
        (a -= 5);
        break;
    case GLUT_KEY_F11:
         a3=1;
         a2=0;
         a1=0;
        (a += 5);
        break;
    case GLUT_KEY_F12:
         a3=1;
         a2=0;
         a1=0;
        (a -= 5);
        break;

    default:
        return;
    }
    glutPostRedisplay();
}

void keyboardFunc( unsigned char key, int x, int y )
{
    switch( key )
    {

        //signal light
    case 'g':
    case 'G':
        flag=1;
        g1=1.0;
        r1=0.8;
        break;

    case 'r':
    case 'R':
        flag=0;
        r1=1.0;
        g1=0.8;
        break;

    /// 3D house scaling
    case 'h':
    case 'H':
        hsx += 0.01;
        break;
    case 'b':
    case 'B':
        hsx -= 0.01;
        break;

    case 'k':
    case 'K':
        hsy += 0.05;
        break;
    case 'm':
    case 'M':
        hsy -= 0.05;
        break;

    case 'j':
    case 'J':
        hsz += 0.01;
        break;
    case 'n':
    case 'N':
        hsz -= 0.01;
        break;


    /// 3D house translated
    case 'a':
    case 'A':
        htx += 0.02;
        break;
    case 'z':
    case 'Z':
        htx -= 0.02;
        break;

    case 's':
    case 'S':
        htz += 0.02;
        break;
    case 'x':
    case 'X':
        htz -= 0.02;
        break;

    case 'd':
    case 'D':
        hty += 0.02;
        break;
    case 'c':
    case 'C':
        hty -= 0.02;
        break;
    };

}



///2 clouds....................
void cloud()
{
    glColor3f (1, 1, 1); //first cloud
    glPushMatrix();
    glTranslatef(0.5, 1.8, 0);
    glutSolidSphere(0.1,36,2);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0.4, 1.75, 0);
    glutSolidSphere(0.1,36,2);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0.3, 1.8, 0);
    glutSolidSphere(0.1,36,2);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0.5, 1.9, 0);
    glutSolidSphere(0.1,36,2);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0.35, 1.88, 0);
    glutSolidSphere(0.1,36,2);
    glPopMatrix();

    //second cloud
    glPushMatrix();
    glTranslatef(1.2, 1.8, 0);
    glutSolidSphere(0.1,36,2);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(1.3, 1.85, 0);
    glutSolidSphere(0.1,36,2);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(1.25, 1.75, 0);
    glutSolidSphere(0.1,36,2);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(1.4, 1.8, 0);
    glutSolidSphere(0.1,36,2);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(1.35, 1.73, 0);
    glutSolidSphere(0.1,36,2);
    glPopMatrix();


}



/// 3D tree.................
void tree()
{
    glBegin(GL_QUADS);
    glColor3f(0.3,0.2,0.14);  ///koyari
    //back
    glVertex3f(-0.3,-0.3,1.45);
    glVertex3f(-0.25,-0.3,1.45);
    glVertex3f(-0.25,0,1.45);
    glVertex3f(-0.3,0,1.45);
    //left
    glVertex3f(-0.3,-0.3,1.5);
    glVertex3f(-0.3,-0.3,1.45);
    glVertex3f(-0.3,0,1.45);
    glVertex3f(-0.3,0,1.5);
    //right
    glVertex3f(-0.25,-0.3,1.5);
    glVertex3f(-0.25,-0.3,1.45);
    glVertex3f(-0.25,0,1.45);
    glVertex3f(-0.25,0,1.5);
    //bottom
    glVertex3f(-0.3,-0.3,1.5);
    glVertex3f(-0.25,-0.3,1.5);
    glVertex3f(-0.25,-0.3,1.45);
    glVertex3f(-0.3,-0.3,1.45);
    //top
    glVertex3f(-0.3,0,1.5);
    glVertex3f(-0.25,0,1.5);
    glVertex3f(-0.25,0,1.45);
    glVertex3f(-0.3,0,1.45);
    //front
    glVertex3f(-0.3,-0.3,1.5);
    glVertex3f(-0.25,-0.3,1.5);
    glVertex3f(-0.25,0,1.5);
    glVertex3f(-0.3,0,1.5);

    glEnd();

    //leaves
    glColor3f(0.0,0.5,0.0);  ///deep green
    glPushMatrix();
    glTranslatef(-0.3, -0.05, 1.4);
    glutSolidSphere(0.1,36,2);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-0.2, 0.05, 1.4);
    glutSolidSphere(0.1,36,2);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-0.4, -0.03, 1.4);
    glutSolidSphere(0.1,36,2);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-0.35, 0.1, 1.4);
    glutSolidSphere(0.1,36,2);
    glPopMatrix();

}


///Roads......................
void road()
{
    //road
    glTranslatef(-0.5, -0.4, 0);
    glScalef(0.5,0.5,0.5);
    glRotatef(6, 1, 0, 0);

    // main road
    glColor3f(0.2,0.2,0.2);        /// black
    glBegin(GL_QUADS);
    glVertex3f (-2.0, 0.1, 1.4);
    glVertex3f (4.4, 0.1, 1.4);
    glVertex3f (4.4, 0.1, 0.3);
    glVertex3f (-2.0, 0.1, 0.3);
    glEnd();

    // lower road border yellow
    glColor3f(1.0,1.0,0.0);     ///yellow
    glBegin(GL_QUADS);
    glVertex3f (-2.0, 0.1, 1.4);
    glVertex3f (4.4, 0.1, 1.4);
    glVertex3f (4.4, 0.1, 1.45);
    glVertex3f (-2.0, 0.1, 1.45);
    glEnd();

    // upper road border yellow
    glColor3f(1.0,1.0,0.0);    ///yellow
    glBegin(GL_QUADS);
    glVertex3f (-2.0, 0.1, 0.3);
    glVertex3f (-2.0, 0.1, 0.35);
    glVertex3f (4.4, 0.1, 0.35);
    glVertex3f (4.4, 0.1, 0.3);
    glEnd();

    // small road border white #1
    glColor3f(1.0,1.0,1.0);  ///white
    glBegin(GL_QUADS);
    glVertex3f (-2.0, 0.1, 0.83);
    glVertex3f (-2.0, 0.1, 0.87);
    glVertex3f (-1.5, 0.1, 0.87);
    glVertex3f (-1.5, 0.1, 0.83);
    glEnd();

    // small road border white #2
    glColor3f(1.0,1.0,1.0);
    glBegin(GL_QUADS);
    glVertex3f (-1.0, 0.1, 0.83);
    glVertex3f (-1.0, 0.1, 0.87);
    glVertex3f (-0.5, 0.1, 0.87);
    glVertex3f (-0.5, 0.1, 0.83);
    glEnd();

    // small road border white #3
    glColor3f(1.0,1.0,1.0);
    glBegin(GL_QUADS);
    glVertex3f (0.0, 0.1, 0.83);
    glVertex3f (0.0, 0.1, 0.87);
    glVertex3f (0.5, 0.1, 0.87);
    glVertex3f (0.5, 0.1, 0.83);
    glEnd();

    // small road border white #4
    glColor3f(1.0,1.0,1.0);
    glBegin(GL_QUADS);
    glVertex3f (1.0, 0.1, 0.83);
    glVertex3f (1.0, 0.1, 0.87);
    glVertex3f (1.5, 0.1, 0.87);
    glVertex3f (1.5, 0.1, 0.83);
    glEnd();

    // small road border white #5
    glColor3f(1.0,1.0,1.0);
    glBegin(GL_QUADS);
    glVertex3f (2.0, 0.1, 0.83);
    glVertex3f (2.0, 0.1, 0.87);
    glVertex3f (2.5, 0.1, 0.87);
    glVertex3f (2.5, 0.1, 0.83);
    glEnd();


    // small road border white #6-1
    glColor3f(1.0,1.0,1.0);
    glBegin(GL_QUADS);
    glVertex3f (3.0, 0.1, 0.43);
    glVertex3f (3.0, 0.1, 0.47);
    glVertex3f (3.5, 0.1, 0.47);
    glVertex3f (3.5, 0.1, 0.43);
    glEnd();

    // small road border white #6-2
    glColor3f(1.0,1.0,1.0);
    glBegin(GL_QUADS);
    glVertex3f (3.0, 0.1, 0.53);
    glVertex3f (3.0, 0.1, 0.57);
    glVertex3f (3.5, 0.1, 0.57);
    glVertex3f (3.5, 0.1, 0.53);
    glEnd();

    // small road border white #6-3
    glColor3f(1.0,1.0,1.0);
    glBegin(GL_QUADS);
    glVertex3f (3.0, 0.1, 0.63);
    glVertex3f (3.0, 0.1, 0.67);
    glVertex3f (3.5, 0.1, 0.67);
    glVertex3f (3.5, 0.1, 0.63);
    glEnd();

    // small road border white #6-4
    glColor3f(1.0,1.0,1.0);
    glBegin(GL_QUADS);
    glVertex3f (3.0, 0.1, 0.73);
    glVertex3f (3.0, 0.1, 0.77);
    glVertex3f (3.5, 0.1, 0.77);
    glVertex3f (3.5, 0.1, 0.73);
    glEnd();

    // small road border white #6-5
    glColor3f(1.0,1.0,1.0);
    glBegin(GL_QUADS);
    glVertex3f (3.0, 0.1, 0.83);
    glVertex3f (3.0, 0.1, 0.87);
    glVertex3f (3.5, 0.1, 0.87);
    glVertex3f (3.5, 0.1, 0.83);
    glEnd();

    // small road border white #6-6
    glColor3f(1.0,1.0,1.0);
    glBegin(GL_QUADS);
    glVertex3f (3.0, 0.1, 0.93);
    glVertex3f (3.0, 0.1, 0.97);
    glVertex3f (3.5, 0.1, 0.97);
    glVertex3f (3.5, 0.1, 0.93);
    glEnd();

    // small road border white #6-7
    glColor3f(1.0,1.0,1.0);
    glBegin(GL_QUADS);
    glVertex3f (3.0, 0.1, 1.03);
    glVertex3f (3.0, 0.1, 1.07);
    glVertex3f (3.5, 0.1, 1.07);
    glVertex3f (3.5, 0.1, 1.03);
    glEnd();

    // small road border white #6-8
    glColor3f(1.0,1.0,1.0);
    glBegin(GL_QUADS);
    glVertex3f (3.0, 0.1, 1.13);
    glVertex3f (3.0, 0.1, 1.17);
    glVertex3f (3.5, 0.1, 1.17);
    glVertex3f (3.5, 0.1, 1.13);
    glEnd();

    // small road border white #6-9
    glColor3f(1.0,1.0,1.0);
    glBegin(GL_QUADS);
    glVertex3f (3.0, 0.1, 1.23);
    glVertex3f (3.0, 0.1, 1.27);
    glVertex3f (3.5, 0.1, 1.27);
    glVertex3f (3.5, 0.1, 1.23);
    glEnd();


    // small road border white #7
    glColor3f(1.0,1.0,1.0);
    glBegin(GL_QUADS);
    glVertex3f (4.0, 0.1, 0.83);
    glVertex3f (4.0, 0.1, 0.87);
    glVertex3f (4.5, 0.1, 0.87);
    glVertex3f (4.5, 0.1, 0.83);
    glEnd();
}



/// 3D house...................
void house()
{
    ///back
    // rectangle
    glColor3f(0.0,0.2,0.2);         /// blue
    glBegin(GL_QUADS);
        glVertex3f (-2.3, -0.3, -1.0);
        glVertex3f (-1.3, -0.3, -1.0);
        glVertex3f (-1.3, 1.1, -1.0);
        glVertex3f (-2.3, 1.1, -1.0);
    glEnd();

    // triangle
    glColor3f(0.5,0.0,0.0);        /// red
    glBegin(GL_TRIANGLES);
        glVertex3f (-1.3, 1.1, -1.0);
        glVertex3f (-2.3, 1.1, -1.0);
        glVertex3f (-1.76, 1.5, -1.25);
    glEnd();

    ///front
    // rectangle
    glColor3f(0.0,0.2,0.2);        /// blue
    glBegin(GL_QUADS);
        glVertex3f (-2.3, -0.3, -1.5);
        glVertex3f (-1.3, -0.3, -1.5);
        glVertex3f (-1.3, 1.1, -1.5);
        glVertex3f (-2.3, 1.1, -1.5);
    glEnd();

    // triangle
    glColor3f(0.5,0.0,0.0);        /// red
    glBegin(GL_TRIANGLES);
        glVertex3f (-1.3, 1.1, -1.5);
        glVertex3f (-2.3, 1.1, -1.5);
        glVertex3f (-1.76, 1.5, -1.25);
    glEnd();

    ///left
    // rectangle
    glColor3f(0.0,0.2,0.2);         /// blue
    glBegin(GL_QUADS);
        glVertex3f (-2.3, -0.3, -1.0);
        glVertex3f (-2.3, -0.3, -1.5);
        glVertex3f (-2.3, 1.1, -1.5);
        glVertex3f (-2.3, 1.1, -1.0);
    glEnd();

    // triangle
    glColor3f(0.5,0.0,0.0);       /// red
    glBegin(GL_TRIANGLES);
        glVertex3f (-2.3, 1.1, -1.5);
        glVertex3f (-2.3, 1.1, -1.0);
        glVertex3f (-1.76, 1.5, -1.25);
    glEnd();

    ///right
    // rectangle
    glColor3f(0.0,0.3,0.3);         /// blue
    glBegin(GL_QUADS);
        glVertex3f (-1.3, -0.3, -1.0);
        glVertex3f (-1.3, -0.3, -1.5);
        glVertex3f (-1.3, 1.08, -1.5);
        glVertex3f (-1.3, 1.08, -1.0);
    glEnd();

    // triangle
    glColor3f(0.5,0.0,0.0);       /// red
    glBegin(GL_TRIANGLES);
        glVertex3f (-1.3, 1.1, -1.5);
        glVertex3f (-1.3, 1.1, -1.0);
        glVertex3f (-1.76, 1.5, -1.25);
    glEnd();

    ///buttom
    // rectangle
    glColor3f(0.0,0.3,0.3);         /// blue
    glBegin(GL_QUADS);
        glVertex3f (-2.3, -0.3, -1.0);
        glVertex3f (-2.3, -0.3, -1.5);
        glVertex3f (-1.3, -0.3, -1.5);
        glVertex3f (-1.3, -0.3, -1.0);
    glEnd();

    ///door of house
    // black colored door
    glColor3f(0.0,0.0,0.0);        /// black
    glBegin(GL_QUADS);
        glVertex3f (-2.3, -0.3, -1.5);
        glVertex3f (-1.9, -0.3, -1.5);
        glVertex3f (-1.9, 0.85, -1.5);
        glVertex3f (-2.3, 0.85, -1.5);
    glEnd();

    //door lock
    glColor3f(1.0, 0.0, 0.0); ///red
    glPushMatrix();
        glTranslatef(-2.22, 0.25, -1.5);
        glutSolidSphere(0.05,36,2);
    glPopMatrix();
}


/// 3D car................
void car()
{
    //car functions
    glTranslatef(xx, -0.4, 0);
    glScalef(0.42,0.42,0.42);
    glRotatef(a, a1, a2, a3);

    /// car back
    glColor3f(0.0,0.0,1.0);        /// blue
    glBegin(GL_POLYGON);
        glVertex3f (0.2, 0.2, 0.70);
        glVertex3f (0.2, 0.6, 0.70);
        glVertex3f (0.7, 0.6, 0.70);
        glVertex3f (0.65, 1.0, 0.70);
        glVertex3f (1.05, 1.0, 0.70);
        glVertex3f (1.29, 0.6, 0.70);
        glVertex3f (1.52, 0.6, 0.70);
        glVertex3f (1.52, 0.2, 0.70);
    glEnd();

    // front windows #1
    glColor3f(0.2,0.2,0.2);        /// black
    glBegin(GL_POLYGON);
        glVertex3f (0.48, 0.6, 0.70);
        glVertex3f (0.82, 0.6, 0.70);
        glVertex3f (0.82, 0.95, 0.70);
        glVertex3f (0.67, 0.95, 0.70);
    glEnd();

    // front windows #2
    glColor3f(0.2,0.2,0.2);        /// black
    glBegin(GL_POLYGON);
        glVertex3f (0.86, 0.6, 0.70);
        glVertex3f (1.23, 0.6, 0.70);
        glVertex3f (1.04, 0.95, 0.70);
        glVertex3f (0.86, 0.95, 0.70);
    glEnd();


    // wheels #1
    glColor3f(0.0, 0.0, 0.0); ///deep black
    glPushMatrix();
        glTranslatef(1.2, 0.2, 0.70);
        glutSolidSphere(0.14,36,2);
    glPopMatrix();

    // wheels #2
    glColor3f(0.0, 0.0, 0.0); ///deep black
    glPushMatrix();
        glTranslatef(0.5, 0.2, 0.70);
        glutSolidSphere(0.14,36,2);
    glPopMatrix();

    // min wheels #1
    glColor3f(0.9, 0.9, 0.9); ///ghiye
    glPushMatrix();
        glTranslatef(1.2, 0.2, 0.70);
        glutSolidSphere(0.08,36,2);
    glPopMatrix();

    // min wheels #2
    glColor3f(0.9, 0.9, 0.9); ///ghiye
    glPushMatrix();
        glTranslatef(0.5, 0.2, 0.70);
        glutSolidSphere(0.08,36,2);
    glPopMatrix();



    /// car left
    glColor3f(0.0,0.0,1.0);        /// blue
    glBegin(GL_QUADS);
        glVertex3f (0.2, 0.6, 0.70);
        glVertex3f (0.2, 0.6, 1.10);
        glVertex3f (0.2, 0.2, 1.10);
        glVertex3f (0.2, 0.2, 0.70);
    glEnd();

    /// car top1
    glColor3f(0.0,0.0,1.0);        /// blue
    glBegin(GL_QUADS);
        glVertex3f (0.2, 0.6, 0.70);
        glVertex3f (0.7, 0.6, 0.70);
        glVertex3f (0.7, 0.6, 1.10);
        glVertex3f (0.2, 0.6, 1.10);
    glEnd();

    /// car top2
    glColor3f(0.0,0.0,1.0);        /// blue
    glBegin(GL_QUADS);
        glVertex3f (0.65, 1.0, 1.10);
        glVertex3f (0.65, 1.0, 0.70);
        glVertex3f (0.45, 0.6, 0.70);
        glVertex3f (0.45, 0.6, 1.10);
    glEnd();

    /// car top2 windows
    glColor3f(0.2,0.2,0.2);        /// black
    glBegin(GL_QUADS);
        glVertex3f (0.65, 0.95, 1.05);
        glVertex3f (0.65, 0.95, 0.75);
        glVertex3f (0.45, 0.6, 0.75);
        glVertex3f (0.45, 0.6, 1.05);
    glEnd();

    /// car top3
    glColor3f(0.0,0.0,1.0);        /// red
    glBegin(GL_QUADS);
        glVertex3f (0.65, 1.0, 1.10);
        glVertex3f (0.65, 1.0, 0.70);
        glVertex3f (1.05, 1.0, 0.70);
        glVertex3f (1.05, 1.0, 1.10);
    glEnd();

    /// car top4
    glColor3f(0.0,0.0,1.0);        /// blue
    glBegin(GL_QUADS);
        glVertex3f (1.05, 1.0, 0.70);
        glVertex3f (1.05, 1.0, 1.10);
        glVertex3f (1.29, 0.6, 1.10);
        glVertex3f (1.29, 0.6, 0.70);
    glEnd();

    /// car top4 windows
    glColor3f(0.2,0.2,0.2);        /// black
    glBegin(GL_QUADS);
        glVertex3f (1.05, 0.95, 1.05);
        glVertex3f (1.05, 0.95, 0.75);
        glVertex3f (1.27, 0.6, 0.75);
        glVertex3f (1.27, 0.6, 1.05);
    glEnd();

    /// car top5
    glColor3f(0.0,0.0,1.0);        /// blue
    glBegin(GL_QUADS);
        glVertex3f (1.29, 0.6, 0.70);
        glVertex3f (1.29, 0.6, 1.10);
        glVertex3f (1.52, 0.6, 1.10);
        glVertex3f (1.52, 0.6, 0.70);
    glEnd();


    /// car right
    glColor3f(0.0,0.0,1.0);        /// blue
    glBegin(GL_QUADS);
        glVertex3f (1.52, 0.6, 0.70);
        glVertex3f (1.52, 0.6, 1.10);
        glVertex3f (1.52, 0.2, 1.10);
        glVertex3f (1.52, 0.2, 0.70);
    glEnd();

    /// car bottom
    glColor3f(0.3,0.3,0.3);        /// red
    glBegin(GL_QUADS);
        glVertex3f (0.2, 0.2, 0.70);
        glVertex3f (1.52, 0.2, 0.70);
        glVertex3f (1.52, 0.2, 1.10);
        glVertex3f (0.2, 0.2, 1.10);
    glEnd();


    /// car front
    glColor3f(0.0,0.0,1.0);        /// blue
    glBegin(GL_POLYGON);
        glVertex3f (0.2, 0.2, 1.10);
        glVertex3f (0.2, 0.6, 1.10);
        glVertex3f (0.7, 0.6, 1.10);
        glVertex3f (0.65, 1.0, 1.10);
        glVertex3f (1.05, 1.0, 1.10);
        glVertex3f (1.29, 0.6, 1.10);
        glVertex3f (1.52, 0.6, 1.10);
        glVertex3f (1.52, 0.2, 1.10);
    glEnd();

    // front windows #1
    glColor3f(0.2,0.2,0.2);        /// black
    glBegin(GL_POLYGON);
        glVertex3f (0.48, 0.6, 1.10);
        glVertex3f (0.82, 0.6, 1.10);
        glVertex3f (0.82, 0.95, 1.10);
        glVertex3f (0.67, 0.95, 1.10);
    glEnd();

    // front windows #2
    glColor3f(0.2,0.2,0.2);        /// black
    glBegin(GL_POLYGON);
        glVertex3f (0.86, 0.6, 1.10);
        glVertex3f (1.23, 0.6, 1.10);
        glVertex3f (1.04, 0.95, 1.10);
        glVertex3f (0.86, 0.95, 1.10);
    glEnd();


    // wheels #1
    glColor3f(0.0, 0.0, 0.0); ///deep black
    glPushMatrix();
        glTranslatef(1.2, 0.2, 1.20);
        glutSolidSphere(0.14,36,2);
    glPopMatrix();

    // wheels #2
    glColor3f(0.0, 0.0, 0.0); ///deep black
    glPushMatrix();
        glTranslatef(0.5, 0.2, 1.20);
        glutSolidSphere(0.14,36,2);
    glPopMatrix();

    // min wheels #1
    glColor3f(0.9, 0.9, 0.9); ///ghiye
    glPushMatrix();
        glTranslatef(1.2, 0.2, 1.20);
        glutSolidSphere(0.08,36,2);
    glPopMatrix();

    // min wheels #2
    glColor3f(0.9, 0.9, 0.9); ///ghiye
    glPushMatrix();
        glTranslatef(0.5, 0.2, 1.20);
        glutSolidSphere(0.08,36,2);
    glPopMatrix();
}


///signal light............
void signal()
{
    //signal
    glTranslatef(-0.61, -0.30, 0);
    glScalef(0.5,0.5,0.5);
    //glRotatef(10, 1.0,1.0,0);

    // lower part
    glColor3f(1.0,0.0,0.0);        /// red
    glBegin(GL_QUADS);
        glVertex3f (4.0, -0.3, -0.5);
        glVertex3f (4.1, -0.3, -0.5);
        glVertex3f (4.1, 1.1, -0.5);
        glVertex3f (4.0, 1.1, -0.5);
    glEnd();

    // upper part
    glColor3f(0.7,0.7,0.7);        /// solid color
    glBegin(GL_QUADS);
        glVertex3f (3.90, 1.1, -0.5);
        glVertex3f (4.15, 1.1, -0.5);
        glVertex3f (4.15, 1.9, -0.5);
        glVertex3f (3.90, 1.9, -0.5);
    glEnd();

    glColor3f(r1, 0.0, 0.0); ///red
    glPushMatrix();
        glTranslatef(4.04, 1.75, -0.5);
        glutSolidSphere(0.08,36,2);
    glPopMatrix();

    glColor3f(0.8, 0.8, 0.0); ///yellow
    glPushMatrix();
        glTranslatef(4.04, 1.52, -0.5);
        glutSolidSphere(0.08,36,2);
    glPopMatrix();

    glColor3f(0.0, g1, 0.0); ///green
    glPushMatrix();
        glTranslatef(4.04, 1.28, -0.5);
        glutSolidSphere(0.08,36,2);
    glPopMatrix();
}


/// Fields............
void field()
{
    //field
    glTranslatef(-0.5, -0.4, 0);
    glScalef(0.5,0.5,0.5);
    glRotatef(10, 1, 1, 0);

    //front
    glColor3f (0.2, 0.8, 0.2);
    glBegin(GL_QUADS);
        glVertex3f (0, 0, 2.5);
        glVertex3f (2.1, 0, 2.5);
        glVertex3f (2.1, 0.1, 2.5);
        glVertex3f (0, 0.1, 2.5);
    glEnd();


    //bottom
    glColor3f (0.2, 0.8, 0.2);
    glBegin(GL_QUADS);
        glVertex3f (0, 0, 2.5);
        glVertex3f (2.1, 0, 2.5);
        glVertex3f (2.1, 0, 0);
        glVertex3f (0, 0, 0);
    glEnd();

    //up
    glColor3f (0.2, 0.8, 0.2);
    glBegin(GL_QUADS);
        glVertex3f (0, 0.1, 2.5);
        glVertex3f (2.1, 0.1, 2.5);
        glVertex3f (2.1, 0.1, 0);
        glVertex3f (0, 0.1, 0);
    glEnd();

    //left
    glColor3f (0.2, 0.8, 0.2);
    glBegin(GL_QUADS);
        glVertex3f (0, 0, 0);
        glVertex3f (0, 0, 2.5);
        glVertex3f (0, 0.1, 2.5);
        glVertex3f (0, 0.1, 0);
    glEnd();

    //right
    glColor3f (0.2, 0.8, 0.2);
    glBegin(GL_QUADS);
        glVertex3f (2.1, 0, 2.5);
        glVertex3f (2.1, 0, 0);
        glVertex3f (2.1, 0.1, 0);
        glVertex3f (2.1, 0.1, 2.5);
    glEnd();

    //back
    glColor3f (0.2, 0.8, 0.2);
    glBegin(GL_QUADS);
        glVertex3f (2.1, 0, 0);
        glVertex3f (2.1, 0.1, 0);
        glVertex3f (0, 0.1, 0);
        glVertex3f (0, 0, 0);
    glEnd();
}


/// Background Building......................
void building()
{
    glColor3f(0.7,0.7,0.7);
    glBegin(GL_QUADS);
        //building body
        glVertex3f(-0.50,-0.28,0);
        glVertex3f(0.10,-0.28,0);
        glVertex3f(0.10, 0.65,0);
        glVertex3f(-0.50,0.65,0);
    glEnd();

    // small blocks line 1
    glColor3f(0.8,0.0,0.0);
    glBegin(GL_QUADS);
        glVertex3f(-0.50,0.65,0);
        glVertex3f(-0.46,0.65,0);
        glVertex3f(-0.46,0.62,0);
        glVertex3f(-0.50,0.62,0);
    glEnd();
    glColor3f(0.8,0.0,0.0);
    glBegin(GL_QUADS);
        glVertex3f(-0.45,0.65,0);
        glVertex3f(-0.41,0.65,0);
        glVertex3f(-0.41,0.62,0);
        glVertex3f(-0.45,0.62,0);
    glEnd();
    glColor3f(0.8,0.0,0.0);
    glBegin(GL_QUADS);
        glVertex3f(-0.40,0.65,0);
        glVertex3f(-0.36,0.65,0);
        glVertex3f(-0.36,0.62,0);
        glVertex3f(-0.40,0.62,0);
    glEnd();
    glColor3f(0.8,0.0,0.0);
    glBegin(GL_QUADS);
        glVertex3f(-0.35,0.65,0);
        glVertex3f(-0.31,0.65,0);
        glVertex3f(-0.31,0.62,0);
        glVertex3f(-0.35,0.62,0);
    glEnd();
    glColor3f(0.8,0.0,0.0);
    glBegin(GL_QUADS);
        glVertex3f(-0.30,0.65,0);
        glVertex3f(-0.26,0.65,0);
        glVertex3f(-0.26,0.62,0);
        glVertex3f(-0.30,0.62,0);
    glEnd();
    glColor3f(0.8,0.0,0.0);
    glBegin(GL_QUADS);
        glVertex3f(-0.25,0.65,0);
        glVertex3f(-0.21,0.65,0);
        glVertex3f(-0.21,0.62,0);
        glVertex3f(-0.25,0.62,0);
    glEnd();
    glColor3f(0.8,0.0,0.0);
    glBegin(GL_QUADS);
        glVertex3f(-0.20,0.65,0);
        glVertex3f(-0.16,0.65,0);
        glVertex3f(-0.16,0.62,0);
        glVertex3f(-0.20,0.62,0);
    glEnd();
    glColor3f(0.8,0.0,0.0);
    glBegin(GL_QUADS);
        glVertex3f(-0.15,0.65,0);
        glVertex3f(-0.11,0.65,0);
        glVertex3f(-0.11,0.62,0);
        glVertex3f(-0.15,0.62,0);
    glEnd();
    glColor3f(0.8,0.0,0.0);
    glBegin(GL_QUADS);
        glVertex3f(-0.10,0.65,0);
        glVertex3f(-0.06,0.65,0);
        glVertex3f(-0.06,0.62,0);
        glVertex3f(-0.10,0.62,0);
    glEnd();
    glColor3f(0.8,0.0,0.0);
    glBegin(GL_QUADS);
        glVertex3f(-0.05,0.65,0);
        glVertex3f(-0.01,0.65,0);
        glVertex3f(-0.01,0.62,0);
        glVertex3f(-0.05,0.62,0);
    glEnd();
    glColor3f(0.8,0.0,0.0);
    glBegin(GL_QUADS);
        glVertex3f(0.00,0.65,0);
        glVertex3f(0.04,0.65,0);
        glVertex3f(0.04,0.62,0);
        glVertex3f(0.00,0.62,0);
    glEnd();
    glColor3f(0.8,0.0,0.0);
    glBegin(GL_QUADS);
        glVertex3f(0.05,0.65,0);
        glVertex3f(0.09,0.65,0);
        glVertex3f(0.09,0.62,0);
        glVertex3f(0.05,0.62,0);
    glEnd();

    // small blocks line 2
    glColor3f(0.8,0.0,0.0);
    glBegin(GL_QUADS);
        glVertex3f(-0.49,0.61,0);
        glVertex3f(-0.45,0.61,0);
        glVertex3f(-0.45,0.58,0);
        glVertex3f(-0.49,0.58,0);
    glEnd();
    glColor3f(0.8,0.0,0.0);
    glBegin(GL_QUADS);
        glVertex3f(-0.44,0.61,0);
        glVertex3f(-0.40,0.61,0);
        glVertex3f(-0.40,0.58,0);
        glVertex3f(-0.44,0.58,0);
    glEnd();
    glColor3f(0.8,0.0,0.0);
    glBegin(GL_QUADS);
        glVertex3f(-0.39,0.61,0);
        glVertex3f(-0.35,0.61,0);
        glVertex3f(-0.35,0.58,0);
        glVertex3f(-0.39,0.58,0);
    glEnd();
    glColor3f(0.8,0.0,0.0);
    glBegin(GL_QUADS);
        glVertex3f(-0.34,0.61,0);
        glVertex3f(-0.30,0.61,0);
        glVertex3f(-0.30,0.58,0);
        glVertex3f(-0.34,0.58,0);
    glEnd();
    glColor3f(0.8,0.0,0.0);
    glBegin(GL_QUADS);
        glVertex3f(-0.29,0.61,0);
        glVertex3f(-0.25,0.61,0);
        glVertex3f(-0.25,0.58,0);
        glVertex3f(-0.29,0.58,0);
    glEnd();
    glColor3f(0.8,0.0,0.0);
    glBegin(GL_QUADS);
        glVertex3f(-0.24,0.61,0);
        glVertex3f(-0.20,0.61,0);
        glVertex3f(-0.20,0.58,0);
        glVertex3f(-0.24,0.58,0);
    glEnd();
    glColor3f(0.8,0.0,0.0);
    glBegin(GL_QUADS);
        glVertex3f(-0.19,0.61,0);
        glVertex3f(-0.15,0.61,0);
        glVertex3f(-0.15,0.58,0);
        glVertex3f(-0.19,0.58,0);
    glEnd();
    glColor3f(0.8,0.0,0.0);
    glBegin(GL_QUADS);
        glVertex3f(-0.14,0.61,0);
        glVertex3f(-0.10,0.61,0);
        glVertex3f(-0.10,0.58,0);
        glVertex3f(-0.14,0.58,0);
    glEnd();
    glColor3f(0.8,0.0,0.0);
    glBegin(GL_QUADS);
        glVertex3f(-0.09,0.61,0);
        glVertex3f(-0.05,0.61,0);
        glVertex3f(-0.05,0.58,0);
        glVertex3f(-0.09,0.58,0);
    glEnd();
    glColor3f(0.8,0.0,0.0);
    glBegin(GL_QUADS);
        glVertex3f(-0.04,0.61,0);
        glVertex3f(0.00,0.61,0);
        glVertex3f(0.00,0.58,0);
        glVertex3f(-0.04,0.58,0);
    glEnd();
    glColor3f(0.8,0.0,0.0);
    glBegin(GL_QUADS);
        glVertex3f(0.01,0.61,0);
        glVertex3f(0.05,0.61,0);
        glVertex3f(0.05,0.58,0);
        glVertex3f(0.01,0.58,0);
    glEnd();
    glColor3f(0.8,0.0,0.0);
    glBegin(GL_QUADS);
        glVertex3f(0.06,0.61,0);
        glVertex3f(0.10,0.61,0);
        glVertex3f(0.10,0.58,0);
        glVertex3f(0.06,0.58,0);
    glEnd();

}


void buildingRoof()
{
    glColor3f(0.3,0.2,0.14);
    glBegin(GL_QUADS);
        //building body
        glVertex3f(-0.50,0.70,0);
        glVertex3f(0.10,0.70,0);
        glVertex3f(0.10, 0.65,0);
        glVertex3f(-0.50,0.65,0);
    glEnd();

    // small blocks line for roof
    glColor3f(0.4, 0.85, 1.0);
    glBegin(GL_QUADS);
        glVertex3f(-0.49,0.69,0);
        glVertex3f(-0.47,0.69,0);
        glVertex3f(-0.47,0.66,0);
        glVertex3f(-0.49,0.66,0);
    glEnd();
    glBegin(GL_QUADS);
        glVertex3f(-0.46,0.69,0);
        glVertex3f(-0.44,0.69,0);
        glVertex3f(-0.44,0.66,0);
        glVertex3f(-0.46,0.66,0);
    glEnd();
    glBegin(GL_QUADS);
        glVertex3f(-0.43,0.69,0);
        glVertex3f(-0.41,0.69,0);
        glVertex3f(-0.41,0.66,0);
        glVertex3f(-0.43,0.66,0);
    glEnd();
    glBegin(GL_QUADS);
        glVertex3f(-0.40,0.69,0);
        glVertex3f(-0.38,0.69,0);
        glVertex3f(-0.38,0.66,0);
        glVertex3f(-0.40,0.66,0);
    glEnd();
    glBegin(GL_QUADS);
        glVertex3f(-0.37,0.69,0);
        glVertex3f(-0.35,0.69,0);
        glVertex3f(-0.35,0.66,0);
        glVertex3f(-0.37,0.66,0);
    glEnd();
    glBegin(GL_QUADS);
        glVertex3f(-0.34,0.69,0);
        glVertex3f(-0.32,0.69,0);
        glVertex3f(-0.32,0.66,0);
        glVertex3f(-0.34,0.66,0);
    glEnd();
    glBegin(GL_QUADS);
        glVertex3f(-0.31,0.69,0);
        glVertex3f(-0.29,0.69,0);
        glVertex3f(-0.29,0.66,0);
        glVertex3f(-0.31,0.66,0);
    glEnd();
    glBegin(GL_QUADS);
        glVertex3f(-0.28,0.69,0);
        glVertex3f(-0.26,0.69,0);
        glVertex3f(-0.26,0.66,0);
        glVertex3f(-0.28,0.66,0);
    glEnd();
    glBegin(GL_QUADS);
        glVertex3f(-0.25,0.69,0);
        glVertex3f(-0.23,0.69,0);
        glVertex3f(-0.23,0.66,0);
        glVertex3f(-0.25,0.66,0);
    glEnd();
    glBegin(GL_QUADS);
        glVertex3f(-0.22,0.69,0);
        glVertex3f(-0.20,0.69,0);
        glVertex3f(-0.20,0.66,0);
        glVertex3f(-0.22,0.66,0);
    glEnd();
    glBegin(GL_QUADS);
        glVertex3f(-0.19,0.69,0);
        glVertex3f(-0.17,0.69,0);
        glVertex3f(-0.17,0.66,0);
        glVertex3f(-0.19,0.66,0);
    glEnd();
    glBegin(GL_QUADS);
        glVertex3f(-0.16,0.69,0);
        glVertex3f(-0.14,0.69,0);
        glVertex3f(-0.14,0.66,0);
        glVertex3f(-0.16,0.66,0);
    glEnd();
    glBegin(GL_QUADS);
        glVertex3f(-0.13,0.69,0);
        glVertex3f(-0.11,0.69,0);
        glVertex3f(-0.11,0.66,0);
        glVertex3f(-0.13,0.66,0);
    glEnd();
    glBegin(GL_QUADS);
        glVertex3f(-0.10,0.69,0);
        glVertex3f(-0.08,0.69,0);
        glVertex3f(-0.08,0.66,0);
        glVertex3f(-0.10,0.66,0);
    glEnd();
    glBegin(GL_QUADS);
        glVertex3f(-0.07,0.69,0);
        glVertex3f(-0.05,0.69,0);
        glVertex3f(-0.05,0.66,0);
        glVertex3f(-0.07,0.66,0);
    glEnd();
    glBegin(GL_QUADS);
        glVertex3f(-0.04,0.69,0);
        glVertex3f(-0.02,0.69,0);
        glVertex3f(-0.02,0.66,0);
        glVertex3f(-0.04,0.66,0);
    glEnd();
    glBegin(GL_QUADS);
        glVertex3f(-0.01,0.69,0);
        glVertex3f(0.01,0.69,0);
        glVertex3f(0.01,0.66,0);
        glVertex3f(-0.01,0.66,0);
    glEnd();
    glBegin(GL_QUADS);
        glVertex3f(0.02,0.69,0);
        glVertex3f(0.04,0.69,0);
        glVertex3f(0.04,0.66,0);
        glVertex3f(0.02,0.66,0);
    glEnd();
    glBegin(GL_QUADS);
        glVertex3f(0.05,0.69,0);
        glVertex3f(0.08,0.69,0);
        glVertex3f(0.08,0.66,0);
        glVertex3f(0.05,0.66,0);
    glEnd();
}

void buildingwin()
{
    glColor3f(0.9, 0.9, 0.9);
    glBegin(GL_QUADS);
        //building body
        glVertex3f(-0.45,0.41,0);
        glVertex3f(-0.25,0.41,0);
        glVertex3f(-0.25, 0.61,0);
        glVertex3f(-0.45,0.61,0);
    glEnd();

    // steps 1
    glColor3f(0.3,0.2,0.14);  ///koyari
    glBegin(GL_QUADS);
        glVertex3f(-0.358,0.41,0);
        glVertex3f(-0.352,0.41,0);
        glVertex3f(-0.352, 0.61,0);
        glVertex3f(-0.358,0.61,0);
    glEnd();

    // steps 2
    glColor3f(0.3,0.2,0.14);  ///koyari
    glBegin(GL_QUADS);
        glVertex3f(-0.45,0.512,0);
        glVertex3f(-0.25,0.512,0);
        glVertex3f(-0.25,0.518,0);
        glVertex3f(-0.45,0.518,0);
    glEnd();
}

void doors()
{
    glColor3f(0.1,0.1,0.1);
    glBegin(GL_QUADS);
        //building body
        glVertex3f(-0.27,-0.28,0);
        glVertex3f(-0.13,-0.28,0);
        glVertex3f(-0.13, 0.05,0);
        glVertex3f(-0.27,0.05,0);
    glEnd();
}

void fullBuilding()
{
    /// building
  glPushMatrix();
  glTranslated(0.0,0.0,0.0);
    building();
  glPopMatrix();
  glPushMatrix();
  glTranslated(0.0,-0.08,0.0);
    building();
  glPopMatrix();
  glPushMatrix();
  glTranslated(0.0,-0.16,0.0);
    building();
  glPopMatrix();
  glPushMatrix();
  glTranslated(0.0,-0.24,0.0);
    building();
  glPopMatrix();
  glPushMatrix();
  glTranslated(0.0,-0.32,0.0);
    building();
  glPopMatrix();
  glPushMatrix();
  glTranslated(0.0,-0.40,0.0);
    building();
  glPopMatrix();
  glPushMatrix();
  glTranslated(0.0,-0.48,0.0);
    building();
  glPopMatrix();
  glPushMatrix();
  glTranslated(0.0,-0.56,0.0);
    building();
  glPopMatrix();
  glPushMatrix();
  glTranslated(0.0,-0.64,0.0);
    building();
  glPopMatrix();
  glPushMatrix();
  glTranslated(0.0,-0.72,0.0);
    building();
  glPopMatrix();
  glPushMatrix();
  glTranslated(0.0,-0.80,0.0);
    building();
  glPopMatrix();
  glPushMatrix();
  glTranslated(0.0,-0.88,0.0);
    building();
  glPopMatrix();

  //window building 1
  glPushMatrix();
  glTranslated(-0.005,0.0,0.0);
    buildingwin();
  glPopMatrix();

  //window building 2
  glPushMatrix();
  glTranslated(0.30,0.0,0.0);
    buildingwin();
  glPopMatrix();

  //window building 3
  glPushMatrix();
  glTranslated(-0.005,-0.30,0.0);
    buildingwin();
  glPopMatrix();

  //window building 4
  glPushMatrix();
  glTranslated(0.30,-0.30,0.0);
    buildingwin();
  glPopMatrix();

  //door building 1
  glPushMatrix();
  glTranslated(0.0,0.0,0.0);
    doors();
  glPopMatrix();

  //building roof
  glPushMatrix();
  glTranslated(0.0,0.0,0.0);
    buildingRoof();
  glPopMatrix();

}

/// Display all object........
void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glPushMatrix();
    glTranslatef(0.0,0.0,0.0);
        fullBuilding();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-1.0,0.0,0.0);
        fullBuilding();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(1.0,0.0,0.0);
        fullBuilding();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0,0.6,0);
    glScalef(3,2.5,2.5);
        field();
    glPopMatrix();

    ///3D  house
    glPushMatrix();
    glTranslatef(htx, hty, htz);
    glScalef(hsx, hsy, hsz);
       house();
    glPopMatrix();

    // signal
    glPushMatrix();
      signal();
    glPopMatrix();

    // road
    glPushMatrix();
        road();
    glPopMatrix();


    //tree
    glPushMatrix();
    glTranslatef(-0.15,0,-1.02);
       tree();
    glPopMatrix();

     // car
    glPushMatrix();
        car();
    glPopMatrix();

    //tree
    glPushMatrix();
    glTranslatef(0.45,-0.08,-0.46);
        tree();
    glPopMatrix();


    glPushMatrix();
    glScalef(1.5,1,1);
    glTranslatef(-2.5 + x,-0.9,0);
        cloud();
    glPopMatrix();

    /// 2 tree

    glPushMatrix();
    glTranslatef(0,0,0.5);
        tree();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.6,0,0.2);
        tree();
    glPopMatrix();

}

void Alldisplay()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glPushMatrix();
        display();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(posx, posy, posz, eyex, eyey, eyez, upx, upy, upz);

    glFlush();
}

void init()
{
    glClearColor (0.4, 0.85, 1.0, 0.0);
    glColor3f(1.0, 1.0, 1.0);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60.0, 4.0/3.0, 1, 20);
}

/// Car Animation............
void CarAnimation(int value) {
    if(flag)
    {
        if(xx<2.30)
            xx += 0.01;
        else
            xx= -2.0;

    }
    else if(flag==0 && xx<0.35)
            xx+=0.01;

    glutPostRedisplay();
    glutTimerFunc(20, CarAnimation, 0);
}


/// Cloud Animation..............
void cloudAnimation(int value) {

        if(x>-0.1 && x<3.5)
            x += 0.005;
        else
            x=0.0;

    glutPostRedisplay();
    glutTimerFunc(25, cloudAnimation, 0);
}


/// Main Function.................
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(80, 80);
    glutInitWindowSize(500, 500);
    glutCreateWindow("3D Car Project");
    glutIdleFunc(idle);
    init();
    glutDisplayFunc(Alldisplay);
    glutSpecialFunc(specialKey);
    glutKeyboardFunc(keyboardFunc);
    glutTimerFunc(1000, CarAnimation, 0);
    glutTimerFunc(1000, cloudAnimation, 0);
    glutMainLoop();
}
