/*
   Jacob Webb
   Program 2
   CSCE 4230 Computer Graphics
   Dr. Renka

   This program uses OpenGL to display a rotating pendulum that will be centered in the glut window.
   There will be a hexagonal bob of radius r that is attached to a rigid wire of length l.


	This can be compiled on the CSE machines with the makefile that is on Dr. Renka's page.
	
	TO COMPILE:***
	This can be compiled on a Apple computer with the following pasted into terminal:

	gcc prog2_Webb.c -L/System/Library/Frameworks -framework GLUT -framework OpenGL
	
	TO USE:***
	"m" will decrease the length of the wire
	"n" will increase the length of the wire
	"." will spawn 3 more line and hexagons of varying color
	The required functionality of "+", "-", "escape", and "space" are activated as stated. 
 
*/
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <stdlib.h>
#include <math.h>//for using sin/cos functions and M_PI

int get_trippy = 1; //lets not get too crazy to start
GLfloat spin_speed = 0.0; //for GLRotatef()
GLfloat spin_direction = 1.0;
GLfloat spin_increment = 2.0;
//Globals ***
GLfloat length_of_wire = 8.0;
GLfloat radius_of_bob = 1.0;

GLfloat Convert_Degrees_To_Radians(float degrees) { //took me ah while to figure out everything was in radians.
   GLfloat to_return = degrees*M_PI/180;
   return to_return;
}

void display(void) {
   glClear(GL_COLOR_BUFFER_BIT); //clear screen
   glPushMatrix();
   glRotatef(spin_speed, 0.0, 0.0, spin_direction); 
   glColor3f(1.0, 1.0, 1.0); //set our drawing color to white
   
   glPointSize((GLfloat)5.0); //make our pendulum anchor fairly large
   glLineWidth((GLfloat)2.0); //make wire thicker
   
   glBegin(GL_POINTS);
      glVertex2f(0.0, 0.0); //draw the pendulum anchor at the origin
   glEnd();
   
   glBegin(GL_LINES); //lets draw our line
      glVertex2f(0.0, 0.0);
      glVertex2f(0.0, -1*length_of_wire); //draw it straight down.
   glEnd();
   
   glColor3f(0.0, 1.0, 0.0); //I want a green hexagon
   glPolygonMode(GL_FRONT_AND_BACK, GL_LINE); //outline mode, no fill. Looks cooler 
   glBegin(GL_POLYGON); //draw our hexagon
      glVertex2f(radius_of_bob, -length_of_wire); // far right
      glVertex2f(radius_of_bob*cos(Convert_Degrees_To_Radians(60)), -length_of_wire + radius_of_bob *sin(Convert_Degrees_To_Radians(60))); //upper right
      glVertex2f(-radius_of_bob*cos(Convert_Degrees_To_Radians(60)), -length_of_wire + radius_of_bob *sin(Convert_Degrees_To_Radians(60))); //upper left
      glVertex2f(-radius_of_bob, -length_of_wire); //far left
      glVertex2f(-radius_of_bob*cos(Convert_Degrees_To_Radians(60)), -length_of_wire - radius_of_bob * sin(Convert_Degrees_To_Radians(60))); //bottom left
      glVertex2f(radius_of_bob*cos(Convert_Degrees_To_Radians(60)), -length_of_wire - radius_of_bob * sin(Convert_Degrees_To_Radians(60))); //bottom right
   glEnd();

   if(get_trippy == -1) { //extra stuff I did *** ENABLE BY PRESSING '.'

      glBegin(GL_LINES); //lets draw our line
         glVertex2f(0.0, 0.0);
         glVertex2f(0.0, 1*length_of_wire); //draw it straight up.
      glEnd();

      glPolygonMode(GL_FRONT_AND_BACK, GL_LINE); //outline mode, no fill. Looks cooler 
      glBegin(GL_POLYGON); //draw our hexagon
         glVertex2f(radius_of_bob, length_of_wire); // far right
         glVertex2f(radius_of_bob*cos(Convert_Degrees_To_Radians(60)), length_of_wire + radius_of_bob *sin(Convert_Degrees_To_Radians(60))); //upper right
         glVertex2f(-radius_of_bob*cos(Convert_Degrees_To_Radians(60)), length_of_wire + radius_of_bob *sin(Convert_Degrees_To_Radians(60))); //upper left
         glVertex2f(-radius_of_bob, length_of_wire); //far left
         glVertex2f(-radius_of_bob*cos(Convert_Degrees_To_Radians(60)), length_of_wire - radius_of_bob * sin(Convert_Degrees_To_Radians(60))); //bottom left
         glVertex2f(radius_of_bob*cos(Convert_Degrees_To_Radians(60)), length_of_wire - radius_of_bob * sin(Convert_Degrees_To_Radians(60))); //bottom right
      glEnd();

      glColor3f(1.0,0.0,0.0);
      glBegin(GL_LINES);
         glVertex2f(0, 0);
         glVertex2f(length_of_wire, 0); //positive x
      glEnd();
      glColor3f(0.0,0.0,1.0);
      glPolygonMode(GL_FRONT_AND_BACK, GL_LINE); //outline mode, no fill. Looks cooler 
      glBegin(GL_POLYGON); //draw our hexagon
         glVertex2f(length_of_wire, radius_of_bob); //top 
         glVertex2f(length_of_wire - (radius_of_bob * sin(Convert_Degrees_To_Radians(60))), radius_of_bob * cos(Convert_Degrees_To_Radians(60))); //upper right
         glVertex2f(length_of_wire - (radius_of_bob * sin(Convert_Degrees_To_Radians(60))), -radius_of_bob * cos(Convert_Degrees_To_Radians(60))); //upper left
         glVertex2f(length_of_wire, -radius_of_bob); //far left
         glVertex2f(length_of_wire + (radius_of_bob*sin(Convert_Degrees_To_Radians(60))), -radius_of_bob * cos(Convert_Degrees_To_Radians(60))); //bottom left
         glVertex2f(length_of_wire + (radius_of_bob*sin(Convert_Degrees_To_Radians(60))), radius_of_bob * cos(Convert_Degrees_To_Radians(60))); //bottom right
      glEnd();

      glColor3f(0.5, 0.0, 0.5);
      glBegin(GL_LINES);
      glVertex2f(0, 0);
      glVertex2f(-length_of_wire, 0); //negative x
      glEnd();
      glColor3f(0.9,0.2,0.9);
      glPolygonMode(GL_FRONT_AND_BACK, GL_LINE); //outline mode, no fill. Looks cooler 
      glBegin(GL_POLYGON); //draw our hexagon
         glVertex2f(-length_of_wire, radius_of_bob); //top 
         glVertex2f(-length_of_wire - (radius_of_bob * sin(Convert_Degrees_To_Radians(60))), radius_of_bob * cos(Convert_Degrees_To_Radians(60))); //upper right
         glVertex2f(-length_of_wire - (radius_of_bob * sin(Convert_Degrees_To_Radians(60))), -radius_of_bob * cos(Convert_Degrees_To_Radians(60))); //upper left
         glVertex2f(-length_of_wire, -radius_of_bob); //far left
         glVertex2f(-length_of_wire + (radius_of_bob*sin(Convert_Degrees_To_Radians(60))), -radius_of_bob * cos(Convert_Degrees_To_Radians(60))); //bottom left
         glVertex2f(-length_of_wire + (radius_of_bob*sin(Convert_Degrees_To_Radians(60))), radius_of_bob * cos(Convert_Degrees_To_Radians(60))); //bottom right
      glEnd();

      glColor3f(1.0, 0.0, 0.0); //I want a red hexagon
      glPolygonMode(GL_FRONT_AND_BACK, GL_LINE); //outline mode, no fill. Looks cooler 
      glBegin(GL_POLYGON); //draw our hexagon
         glVertex2f(radius_of_bob, length_of_wire); // far right
         glVertex2f(radius_of_bob*cos(Convert_Degrees_To_Radians(60)), length_of_wire + radius_of_bob *sin(Convert_Degrees_To_Radians(60))); //upper right
         glVertex2f(-radius_of_bob*cos(Convert_Degrees_To_Radians(60)), length_of_wire + radius_of_bob *sin(Convert_Degrees_To_Radians(60))); //upper left
         glVertex2f(-radius_of_bob, length_of_wire); //far left
         glVertex2f(-radius_of_bob*cos(Convert_Degrees_To_Radians(60)), length_of_wire - radius_of_bob * sin(Convert_Degrees_To_Radians(60))); //bottom left
         glVertex2f(radius_of_bob*cos(Convert_Degrees_To_Radians(60)), length_of_wire - radius_of_bob * sin(Convert_Degrees_To_Radians(60))); //bottom right
      glEnd();
   } //end of extra stuff I did ***ENABLE BY PRESSING '.'

   glPopMatrix();

   glutSwapBuffers();
}

void spinDisplay(void) {
   spin_speed = spin_speed + spin_increment;
   if (spin_speed > 360.0)
      spin_speed = spin_speed - 360.0;
   glutPostRedisplay();
}

void init(void) {
   glClearColor (0.0, 0.0, 0.0, 0.0);
   glShadeModel (GL_FLAT);
}

void reshape(int w, int h) {
   
   if(w <= h) { //The following is to keep the viewport square if the user creates an oddly shaped window.
      glViewport(0, (GLsizei)(h-w)/2, (GLsizei)w, (GLsizei)w);
   }
   else if(w > h){
      glViewport((GLsizei)(w-h)/2, 0, (GLsizei)h, (GLsizei)h);
   }
   else {
      glViewport(0, 0, (GLsizei) w, (GLsizei) h);
   }
   
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   glOrtho(-1.3*length_of_wire, 1.3*length_of_wire, -1.3*length_of_wire, 1.3*length_of_wire, -1.0, 1.0);
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
}

void mouse(int button, int state, int x, int y) {
   switch (button) {
      case GLUT_LEFT_BUTTON:
         if (state == GLUT_DOWN)
            glutIdleFunc(spinDisplay);
         break;
      case GLUT_MIDDLE_BUTTON:
      case GLUT_RIGHT_BUTTON:
         if (state == GLUT_DOWN)
            glutIdleFunc(NULL);
         break;
      default:
         break;
   }
}

void keyboard(unsigned char key, int x, int y) {
   if(key == '=') {
      if(spin_increment > 0)
         spin_increment = -2.0;
      else
         spin_increment -= 1; //speed up if you keep pressing

      glutIdleFunc(spinDisplay);
   }
   else if(key == '-') {
      if(spin_increment < 0)
         spin_increment = 2.0;
      else
         spin_increment +=1; //speed up if you keep pressing
      glutIdleFunc(spinDisplay);
   }
   else if(key == 32) //Space
      glutIdleFunc(NULL); //Stop spinning plz
   else if(key == 27)
      exit(1);//exit peacefully
   else if(key == '.')
      get_trippy = get_trippy * -1; //wut
   else if(key == 'm' && length_of_wire > 1) { //pressing m DECREASES the length
      if(length_of_wire < 3)
         length_of_wire = length_of_wire-0.1;
      else
         length_of_wire--;
   }
   else if(key == 'n' && length_of_wire < 12) { //pressing n INCREASES the length
      if(length_of_wire > 7)
         length_of_wire = length_of_wire+0.1;
      else
         length_of_wire++;
   }

}


void mymenu(int item_selected) {
   if(item_selected == '+') { //rotate counterclockwise about the positive Z axis
      spin_increment = -2.0;
   }
   else if(item_selected == '-') //rotate clockwise about the -Z axis
      spin_increment = 2.0;
   else if(item_selected == 32) //space stop
      glutIdleFunc(NULL);
   else if(item_selected == 27) //escape
      exit(1);
   else if(item_selected == '.') //Just extra stuff I added. It makes the assignment more interesting
      get_trippy = get_trippy * -1; 
}


void CreateMenu() {
   glutCreateMenu(mymenu);
   glutAddMenuEntry("Press '+' to spin counter-clockwise", '+');
   glutAddMenuEntry("Press '-' to spin clockwise", '-');
   glutAddMenuEntry("Press <space> to stop spinning", 32);
   glutAddMenuEntry("Press <escape> to exit the program", 27);
   glutAddMenuEntry("Press '.' for awesome", '.');
   glutAttachMenu(GLUT_RIGHT_BUTTON); //where to open the menu
}

int main(int argc, char** argv) {
   glutInit(&argc, argv);
   glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
   glutInitWindowSize(500, 500); 
   glutInitWindowPosition(100, 100);
   glutCreateWindow("Program 2 Webb,Jacob");
   init();
   CreateMenu();
   glutDisplayFunc(display); 
   glutReshapeFunc(reshape); 
   glutMouseFunc(mouse);
   glutKeyboardFunc(keyboard);
   glutMainLoop();
   return 0;   
}
