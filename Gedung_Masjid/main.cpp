#include<GL/gl.h>
#include<GL/glu.h>
#include<GL/glut.h>
#include <math.h>

void display();
void init();
void reshape(int, int);
void keyboard(unsigned char, int, int); //+1
void lingkaran(int xp, int yp, int r, int n);
float a,x,y;

//main program
int main (int argc, char** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode( GLUT_DOUBLE | GLUT_DEPTH );
    glutInitWindowPosition(150, 100);   //Mengatur sumbu x dan y
    glutInitWindowSize(600, 600);       //Mengatur lebar dan tinggi jendela
    glutCreateWindow("FINAL GRAFKOM KELOMPOK 6");
    glutDisplayFunc(display);           //Memanggil fungsi display
    glutReshapeFunc(reshape);           //Memanggil fungsi reshape
    glutKeyboardFunc(keyboard);
    init();
    glutMainLoop();                      //looping program utama
}void init(){
    glEnable(GL_DEPTH_TEST);
    glClearColor(0.0,0.0,0.0, 1.0);
}

void display(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

//PEMBENTUKAN DINDING
glBegin(GL_QUADS);
glColor3f(0.0,0.1,0.1);
glVertex3f(-15,2,15);
glVertex3f(-15,-10,15);                 //DINDING DEPAN
glVertex3f(15,-10,15);
glVertex3f(15,2,15);
glEnd();

glBegin(GL_QUADS);
glVertex3f(-15,2,-15);
glVertex3f(-15,-10,-15);                //DINDING BELAKANG
glVertex3f(15,-10,-15);
glVertex3f(15,2,-15);
glEnd();

glBegin(GL_QUADS);
glVertex3f(-15,2,15);
glVertex3f(-15,-10,15);                 //DINDING KIRI
glVertex3f(-15,-10,-15);
glVertex3f(-15,2,-15);
glEnd();

glBegin(GL_QUADS);
glVertex3f(15,2,15);
glVertex3f(15,-10,15);                  //DINDING KANAN
glVertex3f(15,-10,-15);
glVertex3f(15,2,-15);
glEnd();

glBegin(GL_QUADS);
glColor3f(0.0,0.1,0.1);
glVertex3f(-15,2,15);
glVertex3f(-15,2,-15);                 //DINDING ATAS/ATAP
glVertex3f(15,2,-15);
glVertex3f(15,2,15);
glEnd();

glBegin(GL_QUADS);
glColor3f(0.8,0.8,0.8);                //DINDING BAWAH ATAU TANAH
glVertex3f(-40,-10.2,30);
glVertex3f(-40,-10.2,-30);
glVertex3f(40,-10.2,-30);
glVertex3f(40,-10.2,30);
glEnd();

//PEMBENTUKAN KUBAH
glBegin(GL_QUADS);
glColor3ub(255,178,102);
glVertex3f(-15,15.1,15);
glVertex3f(-15,15.1,10);
glVertex3f(-10,15.1,10);
glVertex3f(-10,15.1,15);
glEnd();

glPushMatrix();
glTranslatef(0, 1, 0);
glutSolidSphere(8, 100, 100);
glScaled (1.5,1.5,1.5);
glPopMatrix();

//Esy Anugerah
//PEMBENTUKAN GARIS DINDING
glBegin(GL_QUADS);
glColor3f(0.8,0.8,0.8);
glVertex3f(-15,2,15.1);
glVertex3f(-15,1.8,15.1);              //GARIS DINDING ATAS DEPAN
glVertex3f(15,1.8,15.1);
glVertex3f(15,2,15.1);
glEnd();

glBegin(GL_QUADS);
glColor3f(0.8,0.8,0.8);
glVertex3f(-15,-9.8,15.1);
glVertex3f(-15,-10,15.1);              //GARIS DINDING BAWAH DEPAN
glVertex3f(15,-10,15.1);
glVertex3f(15,-9.8,15.1);
glEnd();

glBegin(GL_QUADS);
glColor3f(0.8,0.8,0.8);
glVertex3f(-15,2,-15.1);
glVertex3f(-15,1.8,-15.1);             //GARIS DINDING ATAS BELAKANG
glVertex3f(15,1.8,-15.1);
glVertex3f(15,2,-15.1);
glEnd();

glBegin(GL_QUADS);
glColor3f(0.8,0.8,0.8);
glVertex3f(-15,-9.8,-15.1);
glVertex3f(-15,-10,-15.1);             //GARIS DINDING BAWAH BELAKANG
glVertex3f(15,-10,-15.1);
glVertex3f(15,-9.8,-15.1);
glEnd();

glBegin(GL_QUADS);
glColor3f(0.8,0.8,0.8);
glVertex3f(-15.1,2,15);
glVertex3f(-15.1,1.8,15);              //GARIS DINDING KIRI ATAS
glVertex3f(-15.1,1.8,-15);
glVertex3f(-15.1,2,-15);
glEnd();

glBegin(GL_QUADS);
glColor3f(0.8,0.8,0.8);
glVertex3f(-15.1,-9.8,15);
glVertex3f(-15.1,-10,15);              //GARIS DINDING KIRI BAWAH
glVertex3f(-15.1,-10,-15);
glVertex3f(-15.1,-9.8,-15);
glEnd();

glBegin(GL_QUADS);
glColor3f(0.8,0.8,0.8);
glVertex3f(15.1,2,15);
glVertex3f(15.1,1.8,15);               //GARIS DINDING KANAN ATAS
glVertex3f(15.1,1.8,-15);
glVertex3f(15.1,2,-15);
glEnd();

glBegin(GL_QUADS);
glColor3f(0.8,0.8,0.8);
glVertex3f(15.1,-9.8,15);
glVertex3f(15.1,-10,15);               //GARIS DINDING KANAN BAWAH
glVertex3f(15.1,-10,-15);
glVertex3f(15.1,-9.8,-15);
glEnd();

glBegin(GL_QUADS);
glColor3f(0.8,0.8,0.8);
glVertex3f(-15.1,2,15.2);
glVertex3f(-15.1,-10,15.2);           //GARIS DINDING DEPAN KIRI
glVertex3f(-14.9,-10,15.2);
glVertex3f(-14.9,2,15.2);
glEnd();

glBegin(GL_QUADS);
glColor3f(0.8,0.8,0.8);
glVertex3f(15.1,2,15.2);
glVertex3f(15.1,-10,15.2);            //GARIS DINDING DEPAN KANAN
glVertex3f(14.9,-10,15.2);
glVertex3f(14.9,2,15.2);
glEnd();

glBegin(GL_QUADS);
glColor3f(0.8,0.8,0.8);
glVertex3f(-15.1,2,-15.2);
glVertex3f(-15.1,-10,-15.2);          //GARIS DINDING BELAKANG KIRI
glVertex3f(-14.9,-10,-15.2);
glVertex3f(-14.9,2,-15.2);
glEnd();

glBegin(GL_QUADS);
glColor3f(0.8,0.8,0.8);
glVertex3f(15.1,2,-15.2);
glVertex3f(15.1,-10,-15.2);           //GARIS DINDING BELAKANG KANAN
glVertex3f(14.9,-10,-15.2);
glVertex3f(14.9,2,-15.2);
glEnd();

glBegin(GL_QUADS);
glVertex3f(-15.2,2,15.1);
glVertex3f(-15.2,-10,15.1);           //GARIS DINDING KIRI DEPAN
glVertex3f(-15.2,-10,14.9);
glVertex3f(-15.2,2,14.9);
glEnd();

glBegin(GL_QUADS);
glVertex3f(-15.2,2,-15.1);
glVertex3f(-15.2,-10,-15.1);          //GARIS DINDING KIRI BELAKANG
glVertex3f(-15.2,-10,-14.9);
glVertex3f(-15.2,2,-14.9);
glEnd();

glBegin(GL_QUADS);
glVertex3f(15.2,2,15.1);
glVertex3f(15.2,-10,15.1);           //GARIS DINDING KANAN DEPAN
glVertex3f(15.2,-10,14.9);
glVertex3f(15.2,2,14.9);
glEnd();

glBegin(GL_QUADS);
glVertex3f(15.2,2,-15.1);
glVertex3f(15.2,-10,-15.1);         //GARIS DINDING KANAN DEPAN
glVertex3f(15.2,-10,-14.9);
glVertex3f(15.2,2,-14.9);
glEnd();


//PEMBENTUKAN PINTU
glBegin(GL_QUADS);
glColor3f(1.0,1.0,1.0);
glVertex3f(-11,-4,15.1);
glVertex3f(-11,-10,15.1);              //PINTU KIRI DEPAN
glVertex3f(-7,-10,15.1);
glVertex3f(-7,-4,15.1);
glEnd();

glBegin(GL_QUADS);
glColor3f(1.0,1.0,1.0);
glVertex3f(11,-4,15.1);
glVertex3f(11,-10,15.1);              //PINTU KANAN DEPAN
glVertex3f(7,-10,15.1);
glVertex3f(7,-4,15.1);
glEnd();

glBegin(GL_QUADS);
glColor3f(1.0,1.0,1.0);
glVertex3f(5,-4,15.1);
glVertex3f(5,-10,15.1);               //PINTU TENGAH DEPAN
glVertex3f(-5,-10,15.1);
glVertex3f(-5,-4,15.1);
glEnd();

glBegin(GL_POLYGON);
glColor3f(0.3,0.1,0.0);
glVertex3f(5,-4,16.1);
glVertex3f(5,-10,16.1);               //PINTU TIANG KANAN DEPAN 3D
glVertex3f(4,-10,16.1);
glVertex3f(4,-4,16.1);
glEnd();

glBegin(GL_POLYGON);
glColor3f(0.3,0.1,0.0);
glVertex3f(5,-4,16.1);
glVertex3f(5,-10,16.1);
glVertex3f(5,-10,15.1);
glVertex3f(5,-4,15.1);
glEnd();

glBegin(GL_POLYGON);
glColor3f(0.3,0.1,0.0);
glVertex3f(4,-4,16.1);
glVertex3f(4,-10,16.1);
glVertex3f(4,-10,15.1);
glVertex3f(4,-4,15.1);
glEnd();


glFlush();
glutSwapBuffers();
}

void reshape(int w, int h){
    glViewport(0,0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(50.0, w / h, 1.0, 400.0);
    glTranslatef(0.0, -5.0, -100.0);
    glMatrixMode(GL_MODELVIEW);
}
void keyboard(unsigned char key, int x, int y)
{
    //program keyboard
    switch (key){
        //zoom out
        case 'w':
        case 'W':
        glTranslatef(0.0, 0.0, -1.0);
        break;

        //zoom in
        case 's':
        case 'S':
        glTranslatef(0.0, 0.0, 1.0);
        break;

        //geser ke atas
        case 'e':
        case 'E':
        glTranslatef(0.0, 1.0, 0.0);
        break;

        //geser ke bawah
        case 'q':
        case 'Q':
        glTranslatef(0.0, -1.0, 0.0);
        break;

        //geser ke kiri
        case 'a':
        case 'A':
        glTranslatef(-1.0, 0.0, 0.0);
        break;

        //geser ke kanan
        case 'd':
        case 'D':
        glTranslatef(1.0, 0.0, 0.0);
        break;

        //putar ke kanan
        case 'c':
        case 'C':
        glRotatef(3.0, 0.0, 1.0, 0.0);
        break;

        //putar ke kiri
        case 'z':
        case 'Z':
        glRotatef(-3.0, 0.0, 1.0, 0.0); //geser ke kiri
        break;

        case '.':
        case '>':
        glRotatef(-3.0, -1.0, 0.0, 0.0); //putar ke atas
        break;

        case ',':
        case '<':
        glRotatef(-3.0, 1.0, 0.0, 0.0); //putar ke bawah
        break;
    }
    display();
}
