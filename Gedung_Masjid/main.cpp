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

glBegin(GL_POLYGON);
glColor3f(0.3,0.1,0.0);
glVertex3f(-5,-4,16.1);
glVertex3f(-5,-10,16.1);              //PINTU TIANG KIRI DEPAN 3D
glVertex3f(-4,-10,16.1);
glVertex3f(-4,-4,16.1);

glEnd();

glBegin(GL_POLYGON);
glColor3f(0.3,0.1,0.0);
glVertex3f(-5,-4,16.1);
glVertex3f(-5,-10,16.1);
glVertex3f(-5,-10,15.1);
glVertex3f(-5,-4,15.1);
glEnd();

glBegin(GL_POLYGON);
glColor3f(0.3,0.1,0.0);
glVertex3f(-4,-4,16.1);
glVertex3f(-4,-10,16.1);
glVertex3f(-4,-10,15.1);
glVertex3f(-4,-4,15.1);
glEnd();

glBegin(GL_POLYGON);
glColor3f(0.3,0.1,0.0);
glVertex3f(4,-4,16.1);
glVertex3f(5,-4,16.1);
glVertex3f(1.0,-1.0,16.1);             //ATAP KANAN PINTU SEGITIGA
glVertex3f(0.0,-1.0,16.1);

glEnd();

glBegin(GL_POLYGON);
glVertex3f(5,-4,16.1);
glVertex3f(1.0,-1.0,16.1);
glVertex3f(1.0,-1.0,15.1);
glVertex3f(5,-4,15.1);

glEnd();

glBegin(GL_POLYGON);
glVertex3f(4,-4,16.1);
glVertex3f(0.0,-1.0,16.1);
glVertex3f(0.0,-1.0,15.1);
glVertex3f(4,-4,15.1);
glEnd();

glBegin(GL_POLYGON);
glColor3f(0.3,0.1,0.0);
glVertex3f(-4,-4,16.1);
glVertex3f(-5,-4,16.1);
glVertex3f(-1.0,-1.0,16.1);              //ATAP KIRI PINTU SEGITIGA
glVertex3f(0.0,-1.0,16.1);

glEnd();

glBegin(GL_POLYGON);
glColor3f(0.3,0.1,0.0);
glVertex3f(-4,-4,16.1);
glVertex3f(0.0,-1.0,16.1);
glVertex3f(0.0,-1.0,15.1);
glVertex3f(-4,-4,15.1);
glEnd();

glBegin(GL_POLYGON);
glColor3f(0.3,0.1,0.0);
glVertex3f(-5,-4,16.1);
glVertex3f(-1.0,-1.0,16.1);
glVertex3f(-1.0,-1.0,15.1);
glVertex3f(-5,-4,15.1);
glEnd();

glBegin(GL_TRIANGLES);
glColor3f(1.0,1.0,1.0);
glVertex3f(0.0,-1.0,15.1);              //PINTU SEGITIGA DEPAN
glVertex3f(-5,-4,15.1);
glVertex3f(5,-4,15.1);
glEnd();


//PEMBENTUKAN JENDELA DINDING KIRI
glBegin(GL_QUADS);
glColor3f(0.8,0.8,0.8);
glVertex3f(-15.2,-4,13.1);
glVertex3f(-15.2,-9,13.1);                 //DINDING KIRI KACA 1
glVertex3f(-15.2,-9,9.1);
glVertex3f(-15.2,-4,9.1);
glEnd();

glBegin(GL_QUADS);
glColor3f(0.48,0.46,0.46);
glVertex3f(-15.2,-2,13.1);
glVertex3f(-15.2,-2.5,13.1);               //ventilasi
glVertex3f(-15.2,-2.5,9.1);
glVertex3f(-15.2,-2,9.1);
glEnd();

glBegin(GL_QUADS);
glColor3f(0.8,0.8,0.8);
glVertex3f(-15.2,-4,7.1);
glVertex3f(-15.2,-9,7.1);                 //DINDING KIRI KACA 2
glVertex3f(-15.2,-9,3.1);
glVertex3f(-15.2,-4,3.1);
glEnd();

glBegin(GL_QUADS);
glColor3f(0.48,0.46,0.46);
glVertex3f(-15.2,-2,7.1);
glVertex3f(-15.2,-2.5,7.1);               //ventilasi
glVertex3f(-15.2,-2.5,3.1);
glVertex3f(-15.2,-2,3.1);
glEnd();

glBegin(GL_QUADS);
glColor3f(0.8,0.8,0.8);
glVertex3f(-15.2,-4,-7.1);
glVertex3f(-15.2,-9,-7.1);                //DINDING KIRI KACA 3
glVertex3f(-15.2,-9,-3.1);
glVertex3f(-15.2,-4,-3.1);
glEnd();

glBegin(GL_QUADS);
glColor3f(0.48,0.46,0.46);
glVertex3f(-15.2,-2,-7.1);
glVertex3f(-15.2,-2.5,-7.1);              //ventilasi
glVertex3f(-15.2,-2.5,-3.1);
glVertex3f(-15.2,-2,-3.1);
glEnd();

glBegin(GL_QUADS);
glColor3f(0.8,0.8,0.8);
glVertex3f(-15.2,-4,-13.1);
glVertex3f(-15.2,-9,-13.1);              //DINDING KIRI KACA 4
glVertex3f(-15.2,-9,-9.1);
glVertex3f(-15.2,-4,-9.1);
glEnd();

glBegin(GL_QUADS);
glColor3f(0.48,0.46,0.46);
glVertex3f(-15.2,-2,-13.1);
glVertex3f(-15.2,-2.5,-13.1);            //ventilasi
glVertex3f(-15.2,-2.5,-9.1);
glVertex3f(-15.2,-2,-9.1);
glEnd();


//PEMBENTUKAN JENDELA DINDING KANAN
glBegin(GL_QUADS);
glColor3f(0.8,0.8,0.8);
glVertex3f(15.2,-4,13.1);
glVertex3f(15.2,-9,13.1);                 //DINDING KANAN KACA 1
glVertex3f(15.2,-9,9.1);
glVertex3f(15.2,-4,9.1);
glEnd();

glBegin(GL_QUADS);
glColor3f(0.48,0.46,0.46);
glVertex3f(15.2,-2,13.1);
glVertex3f(15.2,-2.5,13.1);               //ventilasi
glVertex3f(15.2,-2.5,9.1);
glVertex3f(15.2,-2,9.1);
glEnd();

glBegin(GL_QUADS);
glColor3f(0.8,0.8,0.8);
glVertex3f(15.2,-4,7.1);
glVertex3f(15.2,-9,7.1);                  //DINDING KANAN KACA 2
glVertex3f(15.2,-9,3.1);
glVertex3f(15.2,-4,3.1);
glEnd();

glBegin(GL_QUADS);
glColor3f(0.48,0.46,0.46);
glVertex3f(15.2,-2,7.1);
glVertex3f(15.2,-2.5,7.1);                 //ventilasi
glVertex3f(15.2,-2.5,3.1);
glVertex3f(15.2,-2,3.1);
glEnd();

glBegin(GL_QUADS);
glColor3f(0.8,0.8,0.8);
glVertex3f(15.2,-4,-7.1);
glVertex3f(15.2,-9,-7.1);                  //DINDING KANAN KACA 3
glVertex3f(15.2,-9,-3.1);
glVertex3f(15.2,-4,-3.1);
glEnd();

glBegin(GL_QUADS);
glColor3f(0.48,0.46,0.46);
glVertex3f(15.2,-2,-7.1);
glVertex3f(15.2,-2.5,-7.1);                //ventilasi
glVertex3f(15.2,-2.5,-3.1);
glVertex3f(15.2,-2,-3.1);
glEnd();

glBegin(GL_QUADS);
glColor3f(0.8,0.8,0.8);
glVertex3f(15.2,-4,-13.1);
glVertex3f(15.2,-9,-13.1);                 //DINDING KANAN KACA 4
glVertex3f(15.2,-9,-9.1);
glVertex3f(15.2,-4,-9.1);
glEnd();

glBegin(GL_QUADS);
glColor3f(0.48,0.46,0.46);
glVertex3f(15.2,-2,-13.1);
glVertex3f(15.2,-2.5,-13.1);              //ventilasi
glVertex3f(15.2,-2.5,-9.1);
glVertex3f(15.2,-2,-9.1);
glEnd();

//PEMBENTUKAN DINDING PILAR
glBegin(GL_QUADS);
glColor3f(0.8,0.8,0.8);
glVertex3f(-15,2.1,15);
glVertex3f(-15,2.1,10);                  //PILAR DEPAN KIRI
glVertex3f(-10,2.1,10);
glVertex3f(-10,2.1,15);
glEnd();

glBegin(GL_QUADS);
glColor3f(0.8,0.8,0.8);
glVertex3f(-15,15.1,15);
glVertex3f(-15,15.1,10);                //PILAR DEPAN KIRI KEATAS
glVertex3f(-10,15.1,10);
glVertex3f(-10,15.1,15);
glEnd();

//PILAR DINDING DEPAN KIRI
glBegin(GL_QUADS);
glColor3f(0.8,0.8,0.8);
glVertex3f(-15,2,15);
glVertex3f(-15,15,15);                 //DINDING PILAR DEPAN
glVertex3f(-10,15,15);
glVertex3f(-10,2,15);
glEnd();

glBegin(GL_QUADS);
glColor3f(0.8,0.8,0.8);
glVertex3f(-15,2,10);
glVertex3f(-15,15,10);                 //DINDING PILAR BELAKANG
glVertex3f(-10,15,10);
glVertex3f(-10,2,10);
glEnd();

glBegin(GL_QUADS);
glColor3f(0.8,0.8,0.8);
glVertex3f(-15,2,15);
glVertex3f(-15,15,15);                 //DINDING PILAR KIRI
glVertex3f(-15,15,10);
glVertex3f(-15,2,10);
glEnd();

glBegin(GL_QUADS);
glColor3f(0.8,0.8,0.8);
glVertex3f(-10,2,15);
glVertex3f(-10,15,15);                //DINDING PILAR KANAN
glVertex3f(-10,15,10);
glVertex3f(-10,2,10);
glEnd();

//BOLONG DI PILAR KIRI//PILAR KECIL BAGIAN DEPAN KANAN
//KANAN DEPAN
glBegin(GL_QUADS);
glColor3f(0.48,0.46,0.46);
glVertex3f(-11,15,15);
glVertex3f(-11,20,15);                 //DINDING PILAR DEPAN KANAN
glVertex3f(-10,20,15);
glVertex3f(-10,15,15);
glEnd();

glBegin(GL_QUADS);
glColor3f(0.48,0.46,0.46);
glVertex3f(-11,15,14);
glVertex3f(-11,20,14);                 //DINDING PILAR DEPAN KANAN BAGIAN2
glVertex3f(-10,20,14);
glVertex3f(-10,15,14);
glEnd();

glBegin(GL_QUADS);
glColor3f(0.48,0.46,0.46);
glVertex3f(-11,20,14);
glVertex3f(-11,20,15);
glVertex3f(-11,15,15);                 //DINDING PILAR DEPAN KANAN BAGIAN KIRI
glVertex3f(-11,15,14);
glEnd();

glBegin(GL_QUADS);
glColor3f(0.48,0.46,0.46);
glVertex3f(-10,20,14);
glVertex3f(-10,20,15);
glVertex3f(-10,15,15);                 //DINDING PILAR DEPAN KANAN BAGIAN KANAN
glVertex3f(-10,15,14);
glEnd();

//BELAKANG KANAN
//PILAR KECIL BAGIAN BELAKANG KANAN
glBegin(GL_QUADS);
glColor3f(0.48,0.46,0.46);
glVertex3f(-11,15,10);
glVertex3f(-11,20,10);                 //DINDING PILAR BELAKANG KANAN
glVertex3f(-10,20,10);
glVertex3f(-10,15,10);
glEnd();

glBegin(GL_QUADS);
glColor3f(0.48,0.46,0.46);
glVertex3f(-11,15,11);
glVertex3f(-11,20,11);                 //DINDING PILAR BELAKANG KANAN BAGIAN2
glVertex3f(-10,20,11);
glVertex3f(-10,15,11);
glEnd();

glBegin(GL_QUADS);
glColor3f(0.48,0.46,0.46);
glVertex3f(-11,20,10);
glVertex3f(-11,20,11);
glVertex3f(-11,15,11);                 //DINDING PILAR DEPAN KANAN BAGIAN KIRI
glVertex3f(-11,15,10);
glEnd();

glBegin(GL_QUADS);
glColor3f(0.48,0.46,0.46);
glVertex3f(-10,20,10);
glVertex3f(-10,20,11);
glVertex3f(-10,15,11);                 //DINDING PILAR DEPAN KANAN BAGIAN KANAN
glVertex3f(-10,15,10);
glEnd();

//PILAR KECIL BAGIAN BELAKANG KIRI
glBegin(GL_QUADS);
glColor3f(0.48,0.46,0.46);
glVertex3f(-15,15,10);
glVertex3f(-15,20,10);                 //DINDING BELAKANG PILAR BELAKANG KIRI
glVertex3f(-14,20,10);
glVertex3f(-14,15,10);
glEnd();

glBegin(GL_QUADS);
glColor3f(0.48,0.46,0.46);
glVertex3f(-15,15,11);
glVertex3f(-15,20,11);                 //DINDING DEPAN PILAR BELAKANG KIRI BAGIAN2
glVertex3f(-14,20,11);
glVertex3f(-14,15,11);
glEnd();

glBegin(GL_QUADS);
glColor3f(0.48,0.46,0.46);
glVertex3f(-15,20,10);
glVertex3f(-15,20,11);
glVertex3f(-15,15,11);                 //DINDING KIRI PILAR BELAKANG KIRI
glVertex3f(-15,15,10);
glEnd();

glBegin(GL_QUADS);
glColor3f(0.48,0.46,0.46);
glVertex3f(-14,20,10);
glVertex3f(-14,20,11);
glVertex3f(-14,15,11);
glVertex3f(-14,15,10);                  //DINDING KANAN PILAR BELAKANG BAGIAN2
glEnd();

//PILAR KECIL BAGIAN BELAKANG KIRI
glBegin(GL_QUADS);
glColor3f(0.48,0.46,0.46);
glVertex3f(-15,15,14);
glVertex3f(-15,20,14);                  //DINDING BELAKANG PILAR BELAKANG KIRI
glVertex3f(-14,20,14);
glVertex3f(-14,15,14);
glEnd();

glBegin(GL_QUADS);
glColor3f(0.48,0.46,0.46);
glVertex3f(-15,15,15);
glVertex3f(-15,20,15);                  //DINDING DEPAN PILAR BELAKANG KIRI BAGIAN2
glVertex3f(-14,20,15);
glVertex3f(-14,15,15);
glEnd();

glBegin(GL_QUADS);
glColor3f(0.48,0.46,0.46);
glVertex3f(-15,20,14);
glVertex3f(-15,20,15);
glVertex3f(-15,15,15);                  //DINDING KIRI PILAR BELAKANG KIRI
glVertex3f(-15,15,14);
glEnd();

glBegin(GL_QUADS);
glColor3f(0.48,0.46,0.46);
glVertex3f(-14,20,14);
glVertex3f(-14,20,15);
glVertex3f(-14,15,15);
glVertex3f(-14,15,14);                  //DINDING KANAN PILAR BELAKANG BAGIAN2
glEnd();

//PILAR DINDING DEPAN KANAN
glBegin(GL_QUADS);
glColor3f(0.8,0.8,0.8);
glVertex3f(15,2.1,15);
glVertex3f(15,2.1,10);                  //PILAR DEPAN KANAN
glVertex3f(10,2.1,10);
glVertex3f(10,2.1,15);
glEnd();

glBegin(GL_QUADS);
glColor3f(0.8,0.8,0.8);
glVertex3f(15,15.1,15);
glVertex3f(15,15.1,10);                 //PILAR DEPAN KANAN ATAS
glVertex3f(10,15.1,10);
glVertex3f(10,15.1,15);
glEnd();

glBegin(GL_QUADS);
glColor3f(0.8,0.8,0.8);
glVertex3f(15,2,10);
glVertex3f(15,15,10);                   //DINDING PILAR DEPAN
glVertex3f(10,15,10);
glVertex3f(10,2,10);
glEnd();

glBegin(GL_QUADS);
glColor3f(0.8,0.8,0.8);
glVertex3f(15,2,15);
glVertex3f(15,15,15);                   //DINDING PILAR BELAKANG
glVertex3f(10,15,15);
glVertex3f(10,2,15);
glEnd();

glBegin(GL_QUADS);
glColor3f(0.8,0.8,0.8);
glVertex3f(15,2,15);
glVertex3f(15,15,15);                   //DINDING PILAR KIRI
glVertex3f(15,15,10);
glVertex3f(15,2,10);
glEnd();

glBegin(GL_QUADS);
glColor3f(0.8,0.8,0.8);
glVertex3f(10,2,15);
glVertex3f(10,15,15);                   //DINDING PILAR KANAN
glVertex3f(10,15,10);
glVertex3f(10,2,10);
glEnd();

//PILAR DINDING BELAKANG KANAN
glBegin(GL_QUADS);
glColor3f(0.8,0.8,0.8);
glVertex3f(15,2.1,-15);
glVertex3f(15,2.1,-10);                 //PILAR BELAKANG KANAN
glVertex3f(10,2.1,-10);
glVertex3f(10,2.1,-15);
glEnd();

glBegin(GL_QUADS);
glColor3f(0.8,0.8,0.8);
glVertex3f(15,15.1,-15);
glVertex3f(15,15.1,-10);                //PILAR DEPAN KANAN ATAS
glVertex3f(10,15.1,-10);
glVertex3f(10,15.1,-15);
glEnd();

glBegin(GL_QUADS);
glColor3f(0.8,0.8,0.8);
glVertex3f(15,2,-10);
glVertex3f(15,15,-10);                  //DINDING PILAR DEPAN
glVertex3f(10,15,-10);
glVertex3f(10,2,-10);
glEnd();

glBegin(GL_QUADS);
glColor3f(0.8,0.8,0.8);
glVertex3f(15,2,-15);
glVertex3f(15,15,-15);                  //DINDING PILAR BELAKANG
glVertex3f(10,15,-15);
glVertex3f(10,2,-15);
glEnd();

glBegin(GL_QUADS);
glColor3f(0.8,0.8,0.8);
glVertex3f(15,2,-15);
glVertex3f(15,15,-15);                  //DINDING PILAR KIRI
glVertex3f(15,15,-10);
glVertex3f(15,2,-10);
glEnd();

glBegin(GL_QUADS);
glColor3f(0.8,0.8,0.8);
glVertex3f(10,2,-15);
glVertex3f(10,15,-15);                  //DINDING PILAR KANAN
glVertex3f(10,15,-10);
glVertex3f(10,2,-10);
glEnd();

//PILAR DINIDNG BELAKANG KIRI
glBegin(GL_QUADS);
glColor3f(0.8,0.8,0.8);
glVertex3f(-15,2.1,-15);
glVertex3f(-15,2.1,-10);                //PILAR DEPAN KIRI
glVertex3f(-10,2.1,-10);
glVertex3f(-10,2.1,-15);
glEnd();

glBegin(GL_QUADS);
glColor3f(0.8,0.8,0.8);
glVertex3f(-15,15.1,-15);
glVertex3f(-15,15.1,-10);               //PILAR DEPAN KANAN ATAS
glVertex3f(-10,15.1,-10);
glVertex3f(-10,15.1,-15);
glEnd();

glBegin(GL_QUADS);
glColor3f(0.8,0.8,0.8);
glVertex3f(-15,2,-10);
glVertex3f(-15,15,-10);                //DINDING PILAR DEPAN
glVertex3f(-10,15,-10);
glVertex3f(-10,2,-10);
glEnd();

glBegin(GL_QUADS);
glColor3f(0.8,0.8,0.8);
glVertex3f(-15,2,-15);
glVertex3f(-15,15,-15);                //DINDING PILAR BELAKANG
glVertex3f(-10,15,-15);
glVertex3f(-10,2,-15);
glEnd();

glBegin(GL_QUADS);
glColor3f(0.8,0.8,0.8);
glVertex3f(-15,2,-15);
glVertex3f(-15,15,-15);               //DINDING PILAR KIRI
glVertex3f(-15,15,-10);
glVertex3f(-15,2,-10);
glEnd();

glBegin(GL_QUADS);
glColor3f(0.8,0.8,0.8);
glVertex3f(-10,2,-15);
glVertex3f(-10,15,-15);                //DINDING PILAR KANAN
glVertex3f(-10,15,-10);
glVertex3f(-10,2,-10);
glEnd();

glBegin(GL_QUADS);
glColor3f(0.48,0.46,0.46);
glVertex3f(-15,15.1,15);
glVertex3f(-15,15.1,10);               //PENGGANTI WARNA CONE/ATAP PILAR
glVertex3f(-10,15.1,10);
glVertex3f(-10,15.1,15);
glEnd();

//PEMBENTUKAN ATAP PILAR
glBegin(GL_QUADS);
glColor3f(0.1,0.3,0.1);
glVertex3f(-15,15.1,15);
glVertex3f(-15,15.1,10);
glVertex3f(-10,15.1,10);
glVertex3f(-10,15.1,15);
glEnd();

//PEMBENTUKAN CONE
 glPushMatrix();
 glTranslatef(12.5, 15, 12.5);
 glRotatef(-90, 1, 0, 0);               //CONE DEPAN KANAN
 glutSolidCone(4, 4, 10, 10);
 glPopMatrix();


 glPushMatrix();
 glTranslatef(12.5, 15, -12.5);
 glRotatef(-90, 1, 0, 0);               //CONE BELAKANG KANAN
 glutSolidCone(4, 4, 10, 10);
 glPopMatrix();

 glPushMatrix();
 glTranslatef(-12.5, 20, 12.5);
 glRotatef(-90, 1, 0, 0);               //CONE DEPAN KIRI
 glutSolidCone(4, 4, 10, 10);
 glPopMatrix();

 glPushMatrix();
 glTranslatef(-12.5, 15, -12.5);
 glRotatef(-90, 1, 0, 0);               //CONE BELAKANG KANAN
 glutSolidCone(4, 4, 10, 10);
 glPopMatrix();

 //CONE TOAAAAAAA DEPAN
 glPushMatrix();
 glTranslatef(-12.5, 17.5, 16);
 glRotatef(-180, 1, 0, 0);              //CONE DEPAN KIRI
 glutSolidCone(2, 2, 10, 10);
 glPopMatrix();

 //CONE TOAAAAAAA BELAKANG
 glPushMatrix();
 glTranslatef(-12.5, 17.5, 9);
 glRotatef(-360, 1, 0, 0);              //CONE DEPAN KIRI
 glutSolidCone(2, 2, 10, 10);
 glPopMatrix();

//PEMBENTUKAN MATAHARI
glPushMatrix();
 glColor3f(1.0,1.0,0.2);
 glTranslatef(-30, 25, -20.5);
 glutSolidSphere(4., 100, 100);
 glScaled (1.5,1.5,1.5);
 glPopMatrix();
glEnd();

//PEMBENTUKAN LAMPU KANAN
glBegin(GL_QUADS);
glColor3f(1.0,1.0,1.2);
glVertex3f(-15,15.1,15);
glVertex3f(-15,15.1,10);                // BALON LAMPU KANAN
glVertex3f(-10,15.1,10);
glVertex3f(-10,15.1,15);
glEnd();


glPushMatrix();
glTranslatef(20, -3, 20.5);
glutSolidSphere(1, 100, 100);
glScaled (1.5,1.5,1.5);
glPopMatrix();

glBegin(GL_QUADS);
glColor3f(0.3, 0.1, 0.0);
glVertex3f(20.4,-3.7,21);
glVertex3f(20.4,-10,21);                //TIANG LAMPU SAMPING KANAN
glVertex3f(20.4,-10,20);
glVertex3f(20.4,-3.7,20);
glEnd();

glBegin(GL_QUADS);
glColor3f(0.3, 0.1, 0.0);
glVertex3f(19.4,-3.7,21);
glVertex3f(19.4,-10,21);                //TIANG LAMPU SAMPING KIRI
glVertex3f(19.4,-10,20);
glVertex3f(19.4,-3.7,20);
glEnd();


glBegin(GL_QUADS);
glColor3f(0.3, 0.1, 0.0);
glVertex3f(20.4,-3.7,21);
glVertex3f(20.4,-10,21);                //TIANG LAMPU KANAN DEPAN
glVertex3f(19.4,-10,21);
glVertex3f(19.4,-3.7,21);
glEnd();

glBegin(GL_QUADS);
glColor3f(0.3, 0.1, 0.0);
glVertex3f(20.4,-3.7,20);
glVertex3f(20.4,-10,20);                //TIANG LAMPU KANAN BELAKANG
glVertex3f(19.4,-10,20);
glVertex3f(19.4,-3.7,20);
glEnd();


//PEMBENTUKAN LAMPU KIRI
glBegin(GL_QUADS);
glColor3f(1.0,1.0,1.0);
glVertex3f(-15,15.1,15);
glVertex3f(-15,15.1,10);                 //BALON LAMPU KIRI
glVertex3f(-10,15.1,10);
glVertex3f(-10,15.1,15);
glEnd();

 glPushMatrix();
 glTranslatef(-20, -3, 20.5);
 glutSolidSphere(1., 100, 100);         //PEMBENTUKAN LAMPU KIRI
 glScaled (1.5,1.5,1.5);
 glPopMatrix();

 glBegin(GL_QUADS);
 glColor3f(0.3, 0.1, 0.0);
glVertex3f(-20.4,-3.7,21);
glVertex3f(-20.4,-10,21);              //TIANG LAMPU SAMPING KIRI
glVertex3f(-20.4,-10,20);
glVertex3f(-20.4,-3.7,20);
glEnd();


glBegin(GL_QUADS);
 glColor3f(0.3, 0.1, 0.0);
glVertex3f(-19.4,-3.7,21);
glVertex3f(-19.4,-10,21);              //TIANG LAMPU SAMPING KIRI
glVertex3f(-19.4,-10,20);
glVertex3f(-19.4,-3.7,20);
glEnd();


glBegin(GL_QUADS);
glColor3f(0.3, 0.1, 0.0);
glVertex3f(-20.4,-3.7,21);
glVertex3f(-20.4,-10,21);              //TIANG LAMPU KANAN DEPAN
glVertex3f(-19.4,-10,21);
glVertex3f(-19.4,-3.7,21);
glEnd();

glBegin(GL_QUADS);
glColor3f(0.3,0.1,0.0);
glVertex3f(-20.4,-3.7,20);
glVertex3f(-20.4,-10,20);               //TIANG LAMPU KANAN BELAKANG
glVertex3f(-19.4,-10,20);
glVertex3f(-19.4,-3.7,20);
glEnd();

//PEMBENTUKAN KURSI TAMAN
glBegin(GL_QUADS);
glColor3ub(160,82,45);
glVertex3f(-15.0f, -8.2f, 23.0f);
glVertex3f(-9.0f, -8.2f, 19.0f);        //DEPAN
glVertex3f(-9.0f, -7.2f, 19.0f);
glVertex3f(-15.0f, -7.2f, 19.0f);
glEnd();

glBegin(GL_QUADS);
glVertex3f(-15.0f, -8.2f, 23.0f);
glVertex3f(-9.0f, -8.2f, 23.0f);        //BELAKANG
glVertex3f(-9.0f, -7.2f, 23.0f);
glVertex3f(-15.0f, -7.2f, 23.0f);
glEnd();

glBegin(GL_QUADS); //+8
glVertex3f(-15.0f, -8.2f, 19.0f);
glVertex3f(-15.0f, -7.2f, 19.0f);       //KIRI
glVertex3f(-15.0f, -7.2f, 23.0f);
glVertex3f(-15.0f, -8.2f, 23.0f);
glEnd();

glBegin(GL_QUADS);
glVertex3f(-9.0f, -8.2f, 19.0f);
glVertex3f(-9.0f, -7.2f, 19.0f);        //KANAN
glVertex3f(-9.0f, -7.2f, 23.0f);
glVertex3f(-9.0f, -8.2f, 23.0f);
glEnd();

glBegin(GL_QUADS);
glVertex3f(-15.0f, -8.2f, 19.0f);
glVertex3f(-9.0f, -8.2f, 19.0f);        //ATAS
glVertex3f(-9.0f, -8.2f, 23.0f);
glVertex3f(-15.0f, -8.2f, 23.0f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(160,82,45);
glVertex3f(-9.0f, -6.2f, 19.0f);
glVertex3f(-9.0f, -6.2f, 19.0f);        //BAWAH
glVertex3f(-9.0f, -6.2f, 23.0f);
glVertex3f(-9.0f, -6.2f, 23.0f);
glEnd();

 //PEMBENTUKAN KAKI KURSI BAGIAN KIRI BELAKANG
glBegin(GL_QUADS);
 glVertex3f(-15.0f,-8.2f,19.6f);
 glVertex3f(-14.6f, -8.2f, 19.6f);
 glVertex3f(-14.6f, -10.0f, 19.6f);     //DEPAN
 glVertex3f(-15.0f, -10.0f, 19.6f);
glEnd();

glBegin(GL_QUADS);
 glVertex3f(-15.0f, -8.2f,19.0f);
 glVertex3f(-14.6f, -8.2f,19.0f);
 glVertex3f(-14.6f, -10.0f, 19.0f);     //BELAKANG
 glVertex3f(-15.0f, -10.0f, 19.0f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(160,82,45);
 glVertex3f(-14.6f,-8.2f,19.0f);
 glVertex3f(-14.6f, -8.2f, 19.6f);      //KIRI
 glVertex3f(-14.6f, -10.0f, 19.6f);
 glVertex3f(-14.6f, -10.0f, 19.0f);
glEnd();

glBegin(GL_QUADS);
 glVertex3f(-15.0f,-8.2f,19.0f);
 glVertex3f(-15.0f, -8.2f, 19.6f);       //KANAN
 glVertex3f(-15.0f, -10.0f, 19.6f);
 glVertex3f(-15.0f, -10.0f, 19.0f);
glEnd();

 // KAKI KURSI BAGIAN KIRI DEPAN
glBegin(GL_QUADS);
 glVertex3f(-15.0f,-8.2f,23.0f);
 glVertex3f(-14.6f, -8.2f, 23.0f);      //BELAKANG
 glVertex3f(-14.6f, -10.0f, 23.0f);
 glVertex3f(-15.0f, -10.0f, 23.0f);
glEnd();

glBegin(GL_QUADS);
 glVertex3f(-15.0f,-8.2f,22.6f);
 glVertex3f(-14.6f, -8.2, 22.6f);       //DEPAN
 glVertex3f(-14.6f, -10.0f, 22.6f);
 glVertex3f(-15.0f, -10.0f, 22.6f);
glEnd();

glBegin(GL_QUADS);
 glColor3ub(160,82,45);
 glVertex3f(-14.6f,-8.2f,23.0f);
 glVertex3f(-14.6f, -8.2f, 22.6f);      //KIRI
 glVertex3f(-14.6f, -10.0f, 22.6f);
 glVertex3f(-14.6f, -10.0f, 23.0f);
glEnd();

glBegin(GL_QUADS);
 glVertex3f(-15.0f,-8.2f,23.0f);
 glVertex3f(-15.0f, -8.2f, 22.6f);      //KANAN
 glVertex3f(-15.0f, -10.0f, 22.6f);
 glVertex3f(-15.0f, -10.0f, 23.0f);
glEnd();

// KAKI KURSI BAGIAN KANAN DEPAN
glBegin(GL_QUADS); //+8
 glVertex3f(-9.0f,-8.2f,23.0f);
 glVertex3f(-9.6f, -8.2f, 23.0f);       //BELAKANG
 glVertex3f(-9.6f, -10.0f, 23.0f);
 glVertex3f(-9.0f, -10.0f, 23.0f);
glEnd();

glBegin(GL_QUADS);
 glVertex3f(-9.0f, -8.2f,22.6f);
 glVertex3f(-9.6f, -8.2f, 22.6f);       //DEPAN
 glVertex3f(-9.6f, -10.0f, 22.6f);
 glVertex3f(-9.0f, -10.0f, 22.6f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(160,82,45);
 glVertex3f(-9.6f, -8.2f,23.0f);
 glVertex3f(-9.6f, -8.2f, 22.6f);       //KIRI
 glVertex3f(-9.6f, -10.0f, 22.6f);
 glVertex3f(-9.6f, -10.0f, 23.0f);
glEnd();

glBegin(GL_QUADS); //+8
 glVertex3f(-9.0f, -8.2f,23.0f);
 glVertex3f(-9.0f, -8.2f, 22.6f);       //KANAN
 glVertex3f(-9.0f, -10.0f, 22.6f);
 glVertex3f(-9.0f, -10.0f, 23.0f);
glEnd();

//KAKI KURSI BAGIAN KANAN BELAKNG
glBegin(GL_QUADS);
 glVertex3f(-9.0f, -8.2f,19.0f);
 glVertex3f(-9.6f, -8.2f, 19.0f);       //BELAKANG
 glVertex3f(-9.6f, -10.0f, 19.0f);
 glVertex3f(-9.0f, -10.0f, 19.0f);
glEnd();

glBegin(GL_QUADS);
 glVertex3f(-9.0f, -8.2f,19.6f);
 glVertex3f(-9.6f, -8.2f, 19.6f);       //DEPAN
 glVertex3f(-9.6f, -10.0f, 19.6f);
 glVertex3f(-9.0f, -10.0f, 19.6f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(160,82,45);
 glVertex3f(-9.6f,-8.2f,19.0f);
 glVertex3f(-9.6f, -8.2f, 19.6f);       //KIRI
 glVertex3f(-9.6f, -10.0f, 19.6f);
 glVertex3f(-9.6f, -10.0f, 19.0f);
glEnd();

glBegin(GL_QUADS);
 glVertex3f(-9.0f,-8.2f,19.0f);
 glVertex3f(-9.0f, -8.2f, 19.6f);       //kanan
 glVertex3f(-9.0f, -10.0f, 19.6f);
 glVertex3f(-9.0f, -10.0f, 19.0f);
glEnd();

//SENDERAN KURSI GURU
glBegin(GL_QUADS); //+8
glColor3ub(160,82,45);
 glVertex3f(-15.0f, -5.2f,19.4f);
 glVertex3f(-9.0f, -5.2f, 19.4f);      //DEPAN
 glVertex3f(-9.0f, -7.5f, 19.4f);
 glVertex3f(-15.0f,-7.5f,19.4f);
glEnd();

glBegin(GL_QUADS);
 glVertex3f(-15.0f, -5.2f,20.0f);
 glVertex3f(-9.0f, -5.2f, 20.0f);       //BELAKANG
 glVertex3f(-9.0f, -7.5f, 20.0f);
 glVertex3f(-15.0f, -7.5f,20.0f);
glEnd();

glBegin(GL_QUADS);
 glColor3ub(160,82,45);
 glVertex3f(-15.0f, -5.2f, 20.0f);
 glVertex3f(-15.0f, -7.5f, 20.0f);       //KIRI
 glVertex3f(-15.0f, -7.5f, 19.4f);
 glVertex3f(-15.0f, -5.2f, 19.4f);
glEnd();

glBegin(GL_QUADS);
 glVertex3f(-9.0f, -5.2f, 19.4f);
 glVertex3f(-9.0f, -7.5f, 19.4f);        //KANAN
 glVertex3f(-9.0f, -7.5f, 20.0f);
 glVertex3f(-9.0f, -5.2f, 20.0f);
glEnd();

glBegin(GL_QUADS);
 glVertex3f(-15.0f, -7.5f, 20.0f);
 glVertex3f(-15.0f, -7.5f, 20.4f);      //ATAS
 glVertex3f(-9.0f, -7.5f, 19.4f);
 glVertex3f(-9.0f, -7.5f, 19.0f);
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
