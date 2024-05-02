#include <windows.h>  // for MS Windows
#include <iostream>
#include <GL/glut.h>
#include <math.h>
using namespace std;

#define PI 3.14159265358979323846

GLfloat x, y, radius, twicePi; // for circle
int triangleAmount;

 
GLfloat position_c1 = 1.6f; // for car 1
GLfloat speed_c1 = 0.01f;

GLfloat position_c2 = 2.4f; // for car 2
GLfloat speed_c2 = 0.01f;

GLfloat position_c3 = -0.9f; // for car 3
GLfloat speed_c3 = 0.01f;

GLfloat position_c4 = 0.9f; // for car 4
GLfloat speed_c4 = 0.01f;


int cnt = 0, flag = 0, r = 0;

const char* c;
/* Handler for window-repaint event. Call back when the window first appears and
whenever the window needs to be re-painted. */

void road_footpath() {
    // road
    glBegin(GL_POLYGON);
    glColor3ub(95, 96, 91);
    glVertex2f(-2.0f, 0.5f);
    glVertex2f(2.0f, 0.5f);
    glVertex2f(2.0f, -0.5f);
    glVertex2f(-2.0f, -0.5f);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(95, 96, 91);
    glVertex2f(0.4f, 1.0f);
    glVertex2f(1.4f, 1.0f);
    glVertex2f(1.4f, -1.0f);
    glVertex2f(0.4f, -1.0f);
    glEnd();

    // footpath
    glBegin(GL_POLYGON);
    glColor3ub(176, 191, 189);
    glVertex2f(-2.0f, 0.5f);
    glVertex2f(-2.0f, 0.3f);
    glVertex2f(0.6f, 0.3f);
    glVertex2f(0.6f, 0.5f);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(176, 191, 189);
    glVertex2f(-2.0f, -0.5f);
    glVertex2f(-2.0f, -0.3f);
    glVertex2f(0.6f, -0.3f);
    glVertex2f(0.6f, -0.5f);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(176, 191, 189);
    glVertex2f(2.0f, -0.5f);
    glVertex2f(2.0f, -0.3f);
    glVertex2f(1.2f, -0.3f);
    glVertex2f(1.2f, -0.5f);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(176, 191, 189);
    glVertex2f(2.0f, 0.5f);
    glVertex2f(2.0f, 0.3f);
    glVertex2f(1.2f, 0.3f);
    glVertex2f(1.2f, 0.5f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(176, 191, 189);
    glVertex2f(0.4f, -1.0f);
    glVertex2f(0.6f, -1.0f);
    glVertex2f(0.6f, -0.3f);
    glVertex2f(0.4f, -0.3f);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(176, 191, 189);
    glVertex2f(1.2f, -1.0f);
    glVertex2f(1.4f, -1.0f);
    glVertex2f(1.4f, -0.3f);
    glVertex2f(1.2f, -0.3f);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(176, 191, 189);
    glVertex2f(1.2f, 1.0f);
    glVertex2f(1.4f, 1.0f);
    glVertex2f(1.4f, 0.3f);
    glVertex2f(1.2f, 0.3f);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(176, 191, 189);
    glVertex2f(0.4f, 1.0f);
    glVertex2f(0.6f, 1.0f);
    glVertex2f(0.6f, 0.3f);
    glVertex2f(0.4f, 0.3f);
    glEnd();

    // divider
    glLineWidth(3.0f);
    glBegin(GL_LINES);
    glColor3ub(255, 255, 255);
    glVertex2f(-2.0f, 0.0f);
    glVertex2f(-1.8f, 0.0f);

    glVertex2f(-1.7f, 0.0f);
    glVertex2f(-1.5f, 0.0f);

    glVertex2f(-1.4f, 0.0f);
    glVertex2f(-1.2f, 0.0f);

    glVertex2f(-1.1f, 0.0f);
    glVertex2f(-0.9f, 0.0f);

    glVertex2f(-0.8f, 0.0f);
    glVertex2f(-0.6f, 0.0f);

    glVertex2f(-0.5f, 0.0f);
    glVertex2f(-0.3f, 0.0f);

    glVertex2f(-0.2f, 0.0f);
    glVertex2f(0.0f, 0.0f);

    glVertex2f(1.7f, 0.0f);
    glVertex2f(1.9f, 0.0f);

    glVertex2f(0.9f, 0.8f);
    glVertex2f(0.9f, 0.97f);

    glVertex2f(0.9f, -0.97f);
    glVertex2f(0.9f, -0.8f);
    glEnd();

    // zebra-crossing start
    glLineWidth(5.0f);
    glBegin(GL_LINES);
    glColor3ub(255, 255, 255);
    glVertex2f(0.2f, 0.3f);
    glVertex2f(0.2f, -0.3f);

    glVertex2f(0.4f, -0.3f);
    glVertex2f(0.4f, 0.3f);

    glVertex2f(0.6f, 0.5f);
    glVertex2f(1.2f, 0.5f);

    glVertex2f(0.6f, 0.7f);
    glVertex2f(1.2f, 0.7f);

    glVertex2f(1.4f, 0.3f);
    glVertex2f(1.4f, -0.3f);

    glVertex2f(1.6f, 0.3f);
    glVertex2f(1.6f, -0.3f);

    glVertex2f(0.6f, -0.5f);
    glVertex2f(1.2f, -0.5f);

    glVertex2f(0.6f, -0.7f);
    glVertex2f(1.2f, -0.7f);
    glEnd();

    glLineWidth(10.0f);
    glBegin(GL_LINES);
    glColor3ub(255, 255, 255);
    // left cross
    glVertex2f(0.2f, 0.2f);
    glVertex2f(0.4f, 0.2f);

    glVertex2f(0.2f, 0.1f);
    glVertex2f(0.4f, 0.1f);

    glVertex2f(0.2f, 0.0f);
    glVertex2f(0.4f, 0.0f);

    glVertex2f(0.2f, -0.1f);
    glVertex2f(0.4f, -0.1f);

    glVertex2f(0.2f, -0.2f);
    glVertex2f(0.4f, -0.2f);

    // right cross
    glVertex2f(1.4f, 0.2f);
    glVertex2f(1.6f, 0.2f);

    glVertex2f(1.4f, 0.1f);
    glVertex2f(1.6f, 0.1f);

    glVertex2f(1.4f, 0.0f);
    glVertex2f(1.6f, 0.0f);

    glVertex2f(1.4f, -0.1f);
    glVertex2f(1.6f, -0.1f);

    glVertex2f(1.4f, -0.2f);
    glVertex2f(1.6f, -0.2f);

    // bottom cross
    glVertex2f(0.7f, -0.5f);
    glVertex2f(0.7f, -0.7f);

    glVertex2f(0.8f, -0.5f);
    glVertex2f(0.8f, -0.7f);

    glVertex2f(0.9f, -0.5f);
    glVertex2f(0.9f, -0.7f);

    glVertex2f(1.0f, -0.5f);
    glVertex2f(1.0f, -0.7f);

    glVertex2f(1.1f, -0.5f);
    glVertex2f(1.1f, -0.7f);

    // top cross
    glVertex2f(0.7f, 0.5f);
    glVertex2f(0.7f, 0.7f);

    glVertex2f(0.8f, 0.5f);
    glVertex2f(0.8f, 0.7f);

    glVertex2f(0.9f, 0.5f);
    glVertex2f(0.9f, 0.7f);

    glVertex2f(1.0f, 0.5f);
    glVertex2f(1.0f, 0.7f);

    glVertex2f(1.1f, 0.5f);
    glVertex2f(1.1f, 0.7f);
    glEnd();
    // zebra-crossing end

    // road border
    glLineWidth(3.0f);
    glBegin(GL_LINES);
    glColor3ub(102, 102, 102);
    glVertex2f(-2.0f, 0.5f);
    glVertex2f(0.4f, 0.5f);

    glVertex2f(0.4f, 0.5f);
    glVertex2f(0.4f, 1.0f);

    glVertex2f(1.4f, 1.0f);
    glVertex2f(1.4f, 0.5f);

    glVertex2f(1.4f, 0.5f);
    glVertex2f(2.0f, 0.5f);

    glVertex2f(2.0f, -0.5f);
    glVertex2f(1.4f, -0.5f);

    glVertex2f(1.4f, -0.5f);
    glVertex2f(1.4f, -1.0f);

    glVertex2f(0.4f, -1.0f);
    glVertex2f(0.4f, -0.5f);

    glVertex2f(0.4f, -0.5f);
    glVertex2f(-2.0f, -0.5f);

    glColor3ub(230, 230, 230);
    glVertex2f(-2.0f, 0.3f);
    glVertex2f(0.6f, 0.3f);

    glVertex2f(0.6f, 0.3f);
    glVertex2f(0.6f, 1.0f);

    glVertex2f(1.2f, 1.0f);
    glVertex2f(1.2f, 0.3f);

    glVertex2f(1.2f, 0.3f);
    glVertex2f(2.0f, 0.3f);

    glVertex2f(2.0f, -0.3f);
    glVertex2f(1.2f, -0.3f);

    glVertex2f(1.2f, -0.3f);
    glVertex2f(1.2f, -1.0f);

    glVertex2f(0.6f, -1.0f);
    glVertex2f(0.6f, -0.3f);

    glVertex2f(0.6f, -0.3f);
    glVertex2f(-2.0f, -0.3f);
    glEnd();
}

void traffic_light1() {
    // stand
    glBegin(GL_POLYGON);
    glColor3ub(128, 0, 0);
    glVertex2f(0.45f, 0.38f);
    glVertex2f(0.45f, 0.42f);
    glVertex2f(0.55f, 0.42f);
    glVertex2f(0.55f, 0.38f);
    glEnd();
    glLineWidth(5.0f);
    glBegin(GL_LINES);
    glColor3ub(153, 0, 0);
    glVertex2f(0.55f, 0.4f);
    glVertex2f(0.7f, 0.4f);

    glVertex2f(0.7f, 0.4f);
    glVertex2f(0.7f, 0.15f);
    glEnd();

    //light start
    glBegin(GL_POLYGON);
    glColor3ub(204, 122, 0);
    glVertex2f(0.65f, 0.15f);
    glVertex2f(0.75f, 0.15f);
    glVertex2f(0.75f, -0.05f);
    glVertex2f(0.65f, -0.05f);
    glEnd();
    glLineWidth(3.0f);
    glBegin(GL_LINES);
    glColor3ub(0, 0, 0);
    glVertex2f(0.65f, 0.15f);
    glVertex2f(0.75f, 0.15f);

    glVertex2f(0.75f, 0.15f);
    glVertex2f(0.75f, -0.05f);

    glVertex2f(0.75f, -0.05f);
    glVertex2f(0.65f, -0.05f);

    glVertex2f(0.65f, -0.05f);
    glVertex2f(0.65f, 0.15f);
    // side
    glVertex2f(0.65f, 0.1f);
    glVertex2f(0.6f, 0.1f);

    glVertex2f(0.65f, 0.05f);
    glVertex2f(0.62f, 0.05f);

    glVertex2f(0.65f, 0.0f);
    glVertex2f(0.63f, 0.0f);

    glVertex2f(0.75f, 0.1f);
    glVertex2f(0.8f, 0.1f);

    glVertex2f(0.75f, 0.05f);
    glVertex2f(0.78f, 0.05f);

    glVertex2f(0.75f, 0.0f);
    glVertex2f(0.77f, 0.0f);
    glEnd();

    x = 0.7f; y = 0.1f; radius = .02f; // red
    triangleAmount = 50;
    twicePi = 2.0f * PI;
    glColor3ub(204, 0, 0);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); // center of circle
    for (int i = 0; i <= triangleAmount; i++) {
        glVertex2f(
            x + (radius * cos(i * twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    x = 0.7f; y = 0.05f; radius = .02f; // yellow
    triangleAmount = 50;
    twicePi = 2.0f * PI;
    glColor3ub(255, 204, 0);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); // center of circle
    for (int i = 0; i <= triangleAmount; i++) {
        glVertex2f(
            x + (radius * cos(i * twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    x = 0.7f; y = 0.0f; radius = .02f; // green
    triangleAmount = 50;
    twicePi = 2.0f * PI;
    glColor3ub(0, 128, 0);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); // center of circle
    for (int i = 0; i <= triangleAmount; i++) {
        glVertex2f(
            x + (radius * cos(i * twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();
    // light end
}

void traffic_light2() {
    // stand
    glBegin(GL_POLYGON);
    glColor3ub(128, 0, 0);
    glVertex2f(1.28f, -0.35f);
    glVertex2f(1.32f, -0.35f);
    glVertex2f(1.32f, -0.45f);
    glVertex2f(1.28f, -0.45f);
    glEnd();
    glLineWidth(5.0f);
    glBegin(GL_LINES);
    glColor3ub(153, 0, 0);
    glVertex2f(1.3f, -0.35f);
    glVertex2f(1.3f, -0.2f);

    glVertex2f(1.3f, -0.2f);
    glVertex2f(1.0f, -0.2f);
    glEnd();

    // light start
    glBegin(GL_POLYGON);
    glColor3ub(204, 122, 0);
    glVertex2f(0.9f, -0.1f);
    glVertex2f(1.0f, -0.1f);
    glVertex2f(1.0f, -0.3f);
    glVertex2f(0.9f, -0.3f);
    glEnd();
    glLineWidth(3.0f);
    glBegin(GL_LINES);
    glColor3ub(0, 0, 0);
    glVertex2f(0.9f, -0.1f);
    glVertex2f(1.0f, -0.1f);

    glVertex2f(1.0f, -0.1f);
    glVertex2f(1.0f, -0.3f);

    glVertex2f(1.0f, -0.3f);
    glVertex2f(0.9f, -0.3f);

    glVertex2f(0.9f, -0.3f);
    glVertex2f(0.9f, -0.1f);
    // side
    glVertex2f(0.9f, -0.15f);
    glVertex2f(0.85f, -0.15f);

    glVertex2f(0.9f, -0.2f);
    glVertex2f(0.87f, -0.2f);

    glVertex2f(0.9f, -0.25f);
    glVertex2f(0.88f, -0.25f);

    glVertex2f(1.0f, -0.15f);
    glVertex2f(1.05f, -0.15f);

    glVertex2f(1.0f, -0.2f);
    glVertex2f(1.03f, -0.2f);

    glVertex2f(1.0f, -0.25f);
    glVertex2f(1.02f, -0.25f);
    glEnd();

    x = 0.95f; y = -0.15f; radius = .02f; // red
    triangleAmount = 50;
    twicePi = 2.0f * PI;
    glColor3ub(204, 0, 0);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); // center of circle
    for (int i = 0; i <= triangleAmount; i++) {
        glVertex2f(
            x + (radius * cos(i * twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    x = 0.95f; y = -0.2f; radius = .02f; // yellow
    triangleAmount = 50;
    twicePi = 2.0f * PI;
    glColor3ub(255, 204, 0);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); // center of circle
    for (int i = 0; i <= triangleAmount; i++) {
        glVertex2f(
            x + (radius * cos(i * twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    x = 0.95f; y = -0.25f; radius = .02f; // green
    triangleAmount = 50;
    twicePi = 2.0f * PI;
    glColor3ub(0, 128, 0);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); // center of circle
    for (int i = 0; i <= triangleAmount; i++) {
        glVertex2f(
            x + (radius * cos(i * twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();
    // light end
}

void road_light() {
    glLineWidth(3.0f);
    // left-up
    glBegin(GL_LINES);
    glColor3ub(128, 128, 128);
    glVertex2f(-1.9f, 0.4f);
    glVertex2f(-1.8f, 0.4f);

    glVertex2f(-1.8f, 0.4f);
    glVertex2f(-1.8f, 0.1f);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(191, 191, 191);
    glVertex2f(-1.85f, 0.25f);
    glVertex2f(-1.8f, 0.25f);
    glVertex2f(-1.8f, 0.1f);
    glVertex2f(-1.85f, 0.1f);
    glEnd();
    glPointSize(10.0); //
    glBegin(GL_POINTS);
    glColor3ub(89, 89, 89);
    glVertex2f(-1.9f, 0.4f);
    glEnd();

    for (int i = 0; i < 3; i++) {
        glTranslated(0.6, 0.0, 0.0);
        glBegin(GL_LINES);
        glColor3ub(128, 128, 128);
        glVertex2f(-1.9f, 0.4f);
        glVertex2f(-1.8f, 0.4f);

        glVertex2f(-1.8f, 0.4f);
        glVertex2f(-1.8f, 0.1f);
        glEnd();
        glBegin(GL_POLYGON);
        glColor3ub(191, 191, 191);
        glVertex2f(-1.85f, 0.25f);
        glVertex2f(-1.8f, 0.25f);
        glVertex2f(-1.8f, 0.1f);
        glVertex2f(-1.85f, 0.1f);
        glEnd();
        glBegin(GL_POINTS);
        glColor3ub(89, 89, 89);
        glVertex2f(-1.9f, 0.4f);
        glEnd();
    }

    // left-down
    glBegin(GL_LINES);
    glColor3ub(128, 128, 128);
    glVertex2f(-1.6f, -0.4f);
    glVertex2f(-1.5f, -0.4f);

    glVertex2f(-1.5f, -0.4f);
    glVertex2f(-1.5f, -0.1f);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(191, 191, 191);
    glVertex2f(-1.5f, -0.1f);
    glVertex2f(-1.55f, -0.1f);
    glVertex2f(-1.55f, -0.25f);
    glVertex2f(-1.5f, -0.25f);
    glEnd();
    glBegin(GL_POINTS);
    glColor3ub(89, 89, 89);
    glVertex2f(-1.6f, -0.4f);
    glEnd();

    for (int i = 0; i < 3; i++) {
        glTranslated(-0.6, 0.0, 0.0);
        glBegin(GL_LINES);
        glColor3ub(128, 128, 128);
        glVertex2f(-1.6f, -0.4f);
        glVertex2f(-1.5f, -0.4f);

        glVertex2f(-1.5f, -0.4f);
        glVertex2f(-1.5f, -0.1f);
        glEnd();
        glBegin(GL_POLYGON);
        glColor3ub(191, 191, 191);
        glVertex2f(-1.5f, -0.1f);
        glVertex2f(-1.55f, -0.1f);
        glVertex2f(-1.55f, -0.25f);
        glVertex2f(-1.5f, -0.25f);
        glEnd();
        glBegin(GL_POINTS);
        glColor3ub(89, 89, 89);
        glVertex2f(-1.6f, -0.4f);
        glEnd();
    }

    // right-up
    glBegin(GL_LINES);
    glColor3ub(128, 128, 128);
    glVertex2f(1.4f, 0.4f);
    glVertex2f(1.5f, 0.4f);

    glVertex2f(1.5f, 0.4f);
    glVertex2f(1.5f, 0.1f);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(191, 191, 191);
    glVertex2f(1.5f, 0.1f);
    glVertex2f(1.45f, 0.1f);
    glVertex2f(1.45f, 0.25f);
    glVertex2f(1.5f, 0.25f);
    glEnd();
    glBegin(GL_POINTS);
    glColor3ub(89, 89, 89);
    glVertex2f(1.4f, 0.4f);
    glEnd();

    // right-down
    glBegin(GL_LINES);
    glColor3ub(128, 128, 128);
    glVertex2f(1.7f, -0.4f);
    glVertex2f(1.8f, -0.4f);

    glVertex2f(1.8f, -0.4f);
    glVertex2f(1.8f, -0.1f);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(191, 191, 191);
    glVertex2f(1.8f, -0.1f);
    glVertex2f(1.75f, -0.1f);
    glVertex2f(1.75f, -0.25f);
    glVertex2f(1.8f, -0.25f);
    glEnd();
    glBegin(GL_POINTS);
    glColor3ub(89, 89, 89);
    glVertex2f(1.7f, -0.4f);
    glEnd();

    // bottom-left
    glBegin(GL_LINES);
    glColor3ub(128, 128, 128);
    glVertex2f(0.5f, -0.7f);
    glVertex2f(0.5f, -0.6f);

    glVertex2f(0.5f, -0.6f);
    glVertex2f(0.8f, -0.6f);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(191, 191, 191);
    glVertex2f(0.8f, -0.6f);
    glVertex2f(0.8f, -0.65f);
    glVertex2f(0.65f, -0.65f);
    glVertex2f(0.65f, -0.6f);
    glEnd();
    glBegin(GL_POINTS);
    glColor3ub(89, 89, 89);
    glVertex2f(0.5f, -0.7f);
    glEnd();

    // bottom-right
    glBegin(GL_LINES);
    glColor3ub(128, 128, 128);
    glVertex2f(1.3f, -1.0f);
    glVertex2f(1.3f, -0.9f);

    glVertex2f(1.3f, -0.9f);
    glVertex2f(1.0f, -0.9f);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(191, 191, 191);
    glVertex2f(1.0f, -0.9f);
    glVertex2f(1.0f, -0.95f);
    glVertex2f(1.15f, -0.95f);
    glVertex2f(1.15f, -0.9f);
    glEnd();

    // top-left
    glBegin(GL_LINES);
    glColor3ub(128, 128, 128);
    glVertex2f(0.5f, 0.8f);
    glVertex2f(0.5f, 0.9f);

    glVertex2f(0.5f, 0.9f);
    glVertex2f(0.8f, 0.9f);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(191, 191, 191);
    glVertex2f(0.8f, 0.9f);
    glVertex2f(0.8f, 0.85f);
    glVertex2f(0.65f, 0.85f);
    glVertex2f(0.65f, 0.9f);
    glEnd();
    glBegin(GL_POINTS);
    glColor3ub(89, 89, 89);
    glVertex2f(0.5f, 0.8f);
    glEnd();

    // top-right
    glBegin(GL_LINES);
    glColor3ub(128, 128, 128);
    glVertex2f(1.3f, 0.5f);
    glVertex2f(1.3f, 0.6f);

    glVertex2f(1.3f, 0.6f);
    glVertex2f(1.0f, 0.6f);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(191, 191, 191);
    glVertex2f(1.0f, 0.6f);
    glVertex2f(1.0f, 0.55f);
    glVertex2f(1.15f, 0.55f);
    glVertex2f(1.15f, 0.6f);
    glEnd();
    glBegin(GL_POINTS);
    glColor3ub(89, 89, 89);
    glVertex2f(1.3f, 0.5f);
    glEnd();
}

void car1() {
    glPushMatrix();
    glTranslatef(position_c1, 0.0f, 0.0f);
    glBegin(GL_POLYGON); // body
    glColor3ub(230, 0, 0);
    glVertex2f(-0.2f, 0.25f);
    glVertex2f(0.07f, 0.25f);
    glVertex2f(0.15f, 0.23f);
    glVertex2f(0.17f, 0.2f);
    glVertex2f(0.17f, 0.1f);
    glVertex2f(0.15f, 0.07f);
    glVertex2f(0.07f, 0.05f);
    glVertex2f(-0.2f, 0.05f);
    glVertex2f(-0.22f, 0.07f);
    glVertex2f(-0.22f, 0.23f);
    glEnd();

    glBegin(GL_POLYGON); // window
    glColor3ub(0, 0, 0);
    glVertex2f(0.07f, 0.24f);
    glVertex2f(0.07f, 0.06f);
    glVertex2f(-0.18f, 0.06f);
    glVertex2f(-0.18f, 0.24f);
    glEnd();
    glBegin(GL_POLYGON); // roof
    glColor3ub(230, 0, 0);
    glVertex2f(0.03f, 0.09f);
    glVertex2f(0.03f, 0.21f);
    glVertex2f(-0.15f, 0.21f);
    glVertex2f(-0.15f, 0.09f);
    glEnd();

    glBegin(GL_POLYGON); // light
    glColor3ub(242, 242, 242);
    glVertex2f(0.15f, 0.23f);
    glVertex2f(0.17f, 0.2f);
    glVertex2f(0.14f, 0.2f);
    glVertex2f(0.14f, 0.23f);
    glEnd();
    glBegin(GL_POLYGON); // light
    glColor3ub(242, 242, 242);
    glVertex2f(0.15f, 0.07f);
    glVertex2f(0.17f, 0.1f);
    glVertex2f(0.14f, 0.1f);
    glVertex2f(0.14f, 0.07f);
    glEnd();

    if (flag != 0) {
        glBegin(GL_POLYGON); // head-light
        glColor3ub(255, 255, 204);
        glVertex2f(0.17f, 0.2f);
        glVertex2f(0.14f, 0.23f);
        glVertex2f(0.45f, 0.3f);
        glVertex2f(0.45f, 0.1f);
        glEnd();
        glBegin(GL_POLYGON); // head-light
        glColor3ub(255, 255, 204);
        glVertex2f(0.17f, 0.1f);
        glVertex2f(0.14f, 0.07f);
        glVertex2f(0.45f, 0.0f);
        glVertex2f(0.45f, 0.2f);
        glEnd();
    }

    glBegin(GL_LINES);
    glColor3ub(230, 0, 0);
    glVertex2f(0.07f, 0.24f);
    glVertex2f(0.03f, 0.21f);

    glVertex2f(0.03f, 0.09f);
    glVertex2f(0.07f, 0.06f);

    glVertex2f(-0.18f, 0.06f);
    glVertex2f(-0.15f, 0.09f);

    glVertex2f(-0.15f, 0.21f);
    glVertex2f(-0.18f, 0.24f);

    glVertex2f(-0.06f, 0.24f);
    glVertex2f(-0.06f, 0.21f);

    glVertex2f(-0.06f, 0.09f);
    glVertex2f(-0.06f, 0.06f);
    glEnd();

    glPopMatrix();
}

void car2() {
    glPushMatrix();
    glTranslatef(position_c2, 0.0f, 0.0f);
    glRotatef(180, 0.0f, 0.0f, 0.0f);
    glBegin(GL_POLYGON); // body
    glColor3ub(255, 204, 0);
    glVertex2f(-0.04f, 0.25f);
    glVertex2f(0.07f, 0.25f);
    glVertex2f(0.15f, 0.23f);
    glVertex2f(0.17f, 0.2f);
    glVertex2f(0.17f, 0.1f);
    glVertex2f(0.15f, 0.07f);
    glVertex2f(0.07f, 0.05f);
    glVertex2f(-0.04f, 0.05f);
    glEnd();

    glBegin(GL_POLYGON); // window
    glColor3ub(0, 0, 0);
    glVertex2f(0.07f, 0.24f);
    glVertex2f(0.07f, 0.06f);
    glVertex2f(-0.03f, 0.06f);
    glVertex2f(-0.03f, 0.24f);
    glEnd();
    glBegin(GL_POLYGON); // roof
    glColor3ub(255, 204, 0);
    glVertex2f(0.03f, 0.09f);
    glVertex2f(0.03f, 0.21f);
    glVertex2f(-0.07f, 0.21f);
    glVertex2f(-0.07f, 0.09f);
    glEnd();

    glBegin(GL_POLYGON); // light
    glColor3ub(242, 242, 242);
    glVertex2f(0.15f, 0.23f);
    glVertex2f(0.17f, 0.2f);
    glVertex2f(0.14f, 0.2f);
    glVertex2f(0.14f, 0.23f);
    glEnd();
    glBegin(GL_POLYGON); // light
    glColor3ub(242, 242, 242);
    glVertex2f(0.15f, 0.07f);
    glVertex2f(0.17f, 0.1f);
    glVertex2f(0.14f, 0.1f);
    glVertex2f(0.14f, 0.07f);
    glEnd();

    if (flag != 0) {
        glBegin(GL_POLYGON); // head-light
        glColor3ub(255, 255, 204);
        glVertex2f(0.17f, 0.2f);
        glVertex2f(0.14f, 0.23f);
        glVertex2f(0.45f, 0.3f);
        glVertex2f(0.45f, 0.1f);
        glEnd();
        glBegin(GL_POLYGON); // head-light
        glColor3ub(255, 255, 204);
        glVertex2f(0.17f, 0.1f);
        glVertex2f(0.14f, 0.07f);
        glVertex2f(0.45f, 0.0f);
        glVertex2f(0.45f, 0.2f);
        glEnd();
    }

    glBegin(GL_POLYGON); // lorry
    glColor3ub(242, 242, 242);
    glVertex2f(-0.06f, 0.25f);
    glVertex2f(-0.06f, 0.05f);
    glVertex2f(-0.5f, 0.05f);
    glVertex2f(-0.5f, 0.25f);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(255, 204, 0);
    glVertex2f(0.07f, 0.24f);
    glVertex2f(0.03f, 0.21f);

    glVertex2f(0.03f, 0.09f);
    glVertex2f(0.07f, 0.06f);

    glVertex2f(-0.03f, 0.24f);
    glVertex2f(-0.03f, 0.21f);

    glVertex2f(-0.03f, 0.09f);
    glVertex2f(-0.03f, 0.06f);

    glColor3ub(217, 217, 217);
    glVertex2f(-0.06f, 0.25f);
    glVertex2f(-0.06f, 0.05f);

    glVertex2f(-0.06f, 0.05f);
    glVertex2f(-0.5f, 0.05f);

    glVertex2f(-0.5f, 0.05f);
    glVertex2f(-0.5f, 0.25f);

    glVertex2f(-0.5f, 0.25f);
    glVertex2f(-0.06f, 0.25f);
    glEnd();

    glPopMatrix();
}

void car3() {
    glPushMatrix();
    glTranslatef(0.9, position_c3, 0.0f);
    glRotatef(90, 0.0f, 0.0f, 1.0f);
    glBegin(GL_POLYGON); // body
    glColor3ub(255, 255, 255);
    glVertex2f(-0.13f, 0.25f);
    glVertex2f(0.07f, 0.25f);
    glVertex2f(0.15f, 0.23f);
    glVertex2f(0.17f, 0.2f);
    glVertex2f(0.17f, 0.1f);
    glVertex2f(0.15f, 0.07f);
    glVertex2f(0.07f, 0.05f);
    glVertex2f(-0.13f, 0.05f);
    glVertex2f(-0.15f, 0.07f);
    glVertex2f(-0.15f, 0.23f);
    glEnd();

    glBegin(GL_POLYGON); // window
    glColor3ub(0, 0, 0);
    glVertex2f(0.07f, 0.24f);
    glVertex2f(0.07f, 0.06f);
    glVertex2f(-0.13f, 0.06f);
    glVertex2f(-0.13f, 0.24f);
    glEnd();
    glBegin(GL_POLYGON); // roof
    glColor3ub(255, 255, 255);
    glVertex2f(0.03f, 0.09f);
    glVertex2f(0.03f, 0.21f);
    glVertex2f(-0.1f, 0.21f);
    glVertex2f(-0.1f, 0.09f);
    glEnd();

    glBegin(GL_POLYGON); // light
    glColor3ub(242, 242, 242);
    glVertex2f(0.15f, 0.23f);
    glVertex2f(0.17f, 0.2f);
    glVertex2f(0.14f, 0.2f);
    glVertex2f(0.14f, 0.23f);
    glEnd();
    glBegin(GL_POLYGON); // light
    glColor3ub(242, 242, 242);
    glVertex2f(0.15f, 0.07f);
    glVertex2f(0.17f, 0.1f);
    glVertex2f(0.14f, 0.1f);
    glVertex2f(0.14f, 0.07f);
    glEnd();

    if (flag != 0) {
        glBegin(GL_POLYGON); // head-light
        glColor3ub(255, 255, 204);
        glVertex2f(0.17f, 0.2f);
        glVertex2f(0.14f, 0.23f);
        glVertex2f(0.45f, 0.3f);
        glVertex2f(0.45f, 0.1f);
        glEnd();
        glBegin(GL_POLYGON); // head-light
        glColor3ub(255, 255, 204);
        glVertex2f(0.17f, 0.1f);
        glVertex2f(0.14f, 0.07f);
        glVertex2f(0.45f, 0.0f);
        glVertex2f(0.45f, 0.2f);
        glEnd();
    }

    glBegin(GL_LINES);
    glColor3ub(255, 255, 255);
    glVertex2f(0.07f, 0.24f);
    glVertex2f(0.03f, 0.21f);

    glVertex2f(0.03f, 0.09f);
    glVertex2f(0.07f, 0.06f);

    glVertex2f(-0.13f, 0.06f);
    glVertex2f(-0.1f, 0.09f);

    glVertex2f(-0.1f, 0.21f);
    glVertex2f(-0.13f, 0.24f);

    glVertex2f(-0.03f, 0.24f);
    glVertex2f(-0.03f, 0.21f);

    glVertex2f(-0.03f, 0.09f);
    glVertex2f(-0.03f, 0.06f);
    glEnd();

    glPopMatrix();
}

void car4() {
    glPushMatrix();
    glTranslatef(0.9f, position_c4, 0.0f);
    glRotatef(270, 0.0f, 0.0f, 1.0f);
    glBegin(GL_POLYGON); // body
    glColor3ub(51, 102, 255);
    glVertex2f(-0.13f, 0.25f);
    glVertex2f(0.07f, 0.25f);
    glVertex2f(0.15f, 0.23f);
    glVertex2f(0.17f, 0.2f);
    glVertex2f(0.17f, 0.1f);
    glVertex2f(0.15f, 0.07f);
    glVertex2f(0.07f, 0.05f);
    glVertex2f(-0.13f, 0.05f);
    glVertex2f(-0.15f, 0.07f);
    glVertex2f(-0.15f, 0.23f);
    glEnd();

    glBegin(GL_POLYGON); // window
    glColor3ub(0, 0, 0);
    glVertex2f(0.07f, 0.24f);
    glVertex2f(0.07f, 0.06f);
    glVertex2f(-0.13f, 0.06f);
    glVertex2f(-0.13f, 0.24f);
    glEnd();
    glBegin(GL_POLYGON); // roof
    glColor3ub(51, 102, 255);
    glVertex2f(0.03f, 0.09f);
    glVertex2f(0.03f, 0.21f);
    glVertex2f(-0.1f, 0.21f);
    glVertex2f(-0.1f, 0.09f);
    glEnd();

    glBegin(GL_POLYGON); // light
    glColor3ub(242, 242, 242);
    glVertex2f(0.15f, 0.23f);
    glVertex2f(0.17f, 0.2f);
    glVertex2f(0.14f, 0.2f);
    glVertex2f(0.14f, 0.23f);
    glEnd();
    glBegin(GL_POLYGON); // light
    glColor3ub(242, 242, 242);
    glVertex2f(0.15f, 0.07f);
    glVertex2f(0.17f, 0.1f);
    glVertex2f(0.14f, 0.1f);
    glVertex2f(0.14f, 0.07f);
    glEnd();

    if (flag != 0) {
        glBegin(GL_POLYGON); // head-light
        glColor3ub(255, 255, 204);
        glVertex2f(0.17f, 0.2f);
        glVertex2f(0.14f, 0.23f);
        glVertex2f(0.45f, 0.3f);
        glVertex2f(0.45f, 0.1f);
        glEnd();
        glBegin(GL_POLYGON); // head-light
        glColor3ub(255, 255, 204);
        glVertex2f(0.17f, 0.1f);
        glVertex2f(0.14f, 0.07f);
        glVertex2f(0.45f, 0.0f);
        glVertex2f(0.45f, 0.2f);
        glEnd();
    }

    glBegin(GL_LINES);
    glColor3ub(51, 102, 255);
    glVertex2f(0.07f, 0.24f);
    glVertex2f(0.03f, 0.21f);

    glVertex2f(0.03f, 0.09f);
    glVertex2f(0.07f, 0.06f);

    glVertex2f(-0.13f, 0.06f);
    glVertex2f(-0.1f, 0.09f);

    glVertex2f(-0.1f, 0.21f);
    glVertex2f(-0.13f, 0.24f);

    glVertex2f(-0.03f, 0.24f);
    glVertex2f(-0.03f, 0.21f);

    glVertex2f(-0.03f, 0.09f);
    glVertex2f(-0.03f, 0.06f);
    glEnd();

    glPopMatrix();
}

void river() {
    glBegin(GL_POLYGON);
    glColor3ub(51, 204, 255);
    glVertex2f(-2.0f, -1.0f);
    glVertex2f(-2.0f, -0.55f);
    glVertex2f(0.35f, -0.55f);
    glVertex2f(0.35f, -2.0f);
    glEnd();

    glPushMatrix();
}

void redgreen1() {
    x = 0.7f; y = 0.1f; radius = .02f; // red
    triangleAmount = 50;
    twicePi = 2.0f * PI;
    glColor3ub(255, 51, 51);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); // center of circle
    for (int i = 0; i <= triangleAmount; i++) {
        glVertex2f(
            x + (radius * cos(i * twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    x = 0.95f; y = -0.25f; radius = .02f; // green
    triangleAmount = 50;
    twicePi = 2.0f * PI;
    glColor3ub(0, 255, 0);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); // center of circle
    for (int i = 0; i <= triangleAmount; i++) {
        glVertex2f(
            x + (radius * cos(i * twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();
}

void redgreen2() {
    x = 0.7f; y = 0.0f; radius = .02f; // green
    triangleAmount = 50;
    twicePi = 2.0f * PI;
    glColor3ub(0, 255, 0);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); // center of circle
    for (int i = 0; i <= triangleAmount; i++) {
        glVertex2f(
            x + (radius * cos(i * twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    x = 0.95f; y = -0.15f; radius = .02f; // red
    triangleAmount = 50;
    twicePi = 2.0f * PI;
    glColor3ub(255, 51, 51);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); // center of circle
    for (int i = 0; i <= triangleAmount; i++) {
        glVertex2f(
            x + (radius * cos(i * twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();
}

void day() {
    glClear(GL_COLOR_BUFFER_BIT);         // Clear the color buffer (background)

    // Background
    glBegin(GL_POLYGON);
    glColor3ub(51, 204, 51);
    glVertex2f(2.0f, 1.0f);
    glVertex2f(2.0f, -1.0f);
    glVertex2f(-2.0f, -1.0f);
    glVertex2f(-2.0f, 1.0f);
    glEnd();


    river();

    glBegin(GL_POLYGON);
    glColor3ub(51, 204, 51);
    glVertex2f(0.35f, -0.5f);
    glVertex2f(1.9f, -0.5f);
    glVertex2f(1.9f, -1.0f);
    glVertex2f(0.35f, -1.0f);
    glEnd();
    // Objects
    
    road_footpath();
    car1();
    car2();
    car3();
    car4();
    traffic_light1();
    traffic_light2();
    road_light();

    glPushMatrix();
     
    glPopMatrix();

    if (cnt == 0)
        redgreen2();
    else
        redgreen1();
 
    glFlush();
}

void night() {
    glClear(GL_COLOR_BUFFER_BIT);         // Clear the color buffer (background)

    // Background
    glBegin(GL_POLYGON);
    glColor3ub(41, 163, 41);
    glVertex2f(2.0f, 1.0f);
    glVertex2f(2.0f, -1.0f);
    glVertex2f(-2.0f, -1.0f);
    glVertex2f(-2.0f, 1.0f);
    glEnd();

    river();

    glBegin(GL_POLYGON);
    glColor3ub(41, 163, 41);
    glVertex2f(0.35f, -0.5f);
    glVertex2f(1.9f, -0.5f);
    glVertex2f(1.9f, -1.0f);
    glVertex2f(0.35f, -1.0f);
    glEnd();

    /// road start
    glBegin(GL_POLYGON);
    glColor3ub(77, 77, 77);
    glVertex2f(-2.0f, 0.5f);
    glVertex2f(2.0f, 0.5f);
    glVertex2f(2.0f, -0.5f);
    glVertex2f(-2.0f, -0.5f);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(77, 77, 77);
    glVertex2f(0.4f, 1.0f);
    glVertex2f(1.4f, 1.0f);
    glVertex2f(1.4f, -1.0f);
    glVertex2f(0.4f, -1.0f);
    glEnd();

    // footpath
    glBegin(GL_POLYGON);
    glColor3ub(153, 153, 153);
    glVertex2f(-2.0f, 0.5f);
    glVertex2f(-2.0f, 0.3f);
    glVertex2f(0.6f, 0.3f);
    glVertex2f(0.6f, 0.5f);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(153, 153, 153);
    glVertex2f(-2.0f, -0.5f);
    glVertex2f(-2.0f, -0.3f);
    glVertex2f(0.6f, -0.3f);
    glVertex2f(0.6f, -0.5f);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(153, 153, 153);
    glVertex2f(2.0f, -0.5f);
    glVertex2f(2.0f, -0.3f);
    glVertex2f(1.2f, -0.3f);
    glVertex2f(1.2f, -0.5f);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(153, 153, 153);
    glVertex2f(2.0f, 0.5f);
    glVertex2f(2.0f, 0.3f);
    glVertex2f(1.2f, 0.3f);
    glVertex2f(1.2f, 0.5f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(153, 153, 153);
    glVertex2f(0.4f, -1.0f);
    glVertex2f(0.6f, -1.0f);
    glVertex2f(0.6f, -0.3f);
    glVertex2f(0.4f, -0.3f);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(153, 153, 153);
    glVertex2f(1.2f, -1.0f);
    glVertex2f(1.4f, -1.0f);
    glVertex2f(1.4f, -0.3f);
    glVertex2f(1.2f, -0.3f);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(153, 153, 153);
    glVertex2f(1.2f, 1.0f);
    glVertex2f(1.4f, 1.0f);
    glVertex2f(1.4f, 0.3f);
    glVertex2f(1.2f, 0.3f);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(153, 153, 153);
    glVertex2f(0.4f, 1.0f);
    glVertex2f(0.6f, 1.0f);
    glVertex2f(0.6f, 0.3f);
    glVertex2f(0.4f, 0.3f);
    glEnd();

    // divider
    glLineWidth(3.0f);
    glBegin(GL_LINES);
    glColor3ub(255, 255, 255);
    glVertex2f(-2.0f, 0.0f);
    glVertex2f(-1.8f, 0.0f);

    glVertex2f(-1.7f, 0.0f);
    glVertex2f(-1.5f, 0.0f);

    glVertex2f(-1.4f, 0.0f);
    glVertex2f(-1.2f, 0.0f);

    glVertex2f(-1.1f, 0.0f);
    glVertex2f(-0.9f, 0.0f);

    glVertex2f(-0.8f, 0.0f);
    glVertex2f(-0.6f, 0.0f);

    glVertex2f(-0.5f, 0.0f);
    glVertex2f(-0.3f, 0.0f);

    glVertex2f(-0.2f, 0.0f);
    glVertex2f(0.0f, 0.0f);

    glVertex2f(1.7f, 0.0f);
    glVertex2f(1.9f, 0.0f);

    glVertex2f(0.9f, 0.8f);
    glVertex2f(0.9f, 0.97f);

    glVertex2f(0.9f, -0.97f);
    glVertex2f(0.9f, -0.8f);
    glEnd();

    // zebra-crossing start
    glLineWidth(5.0f);
    glBegin(GL_LINES);
    glColor3ub(255, 255, 255);
    glVertex2f(0.2f, 0.3f);
    glVertex2f(0.2f, -0.3f);

    glVertex2f(0.4f, -0.3f);
    glVertex2f(0.4f, 0.3f);

    glVertex2f(0.6f, 0.5f);
    glVertex2f(1.2f, 0.5f);

    glVertex2f(0.6f, 0.7f);
    glVertex2f(1.2f, 0.7f);

    glVertex2f(1.4f, 0.3f);
    glVertex2f(1.4f, -0.3f);

    glVertex2f(1.6f, 0.3f);
    glVertex2f(1.6f, -0.3f);

    glVertex2f(0.6f, -0.5f);
    glVertex2f(1.2f, -0.5f);

    glVertex2f(0.6f, -0.7f);
    glVertex2f(1.2f, -0.7f);
    glEnd();

    glLineWidth(10.0f);
    glBegin(GL_LINES);
    glColor3ub(255, 255, 255);
    // left cross
    glVertex2f(0.2f, 0.2f);
    glVertex2f(0.4f, 0.2f);

    glVertex2f(0.2f, 0.1f);
    glVertex2f(0.4f, 0.1f);

    glVertex2f(0.2f, 0.0f);
    glVertex2f(0.4f, 0.0f);

    glVertex2f(0.2f, -0.1f);
    glVertex2f(0.4f, -0.1f);

    glVertex2f(0.2f, -0.2f);
    glVertex2f(0.4f, -0.2f);

    // right cross
    glVertex2f(1.4f, 0.2f);
    glVertex2f(1.6f, 0.2f);

    glVertex2f(1.4f, 0.1f);
    glVertex2f(1.6f, 0.1f);

    glVertex2f(1.4f, 0.0f);
    glVertex2f(1.6f, 0.0f);

    glVertex2f(1.4f, -0.1f);
    glVertex2f(1.6f, -0.1f);

    glVertex2f(1.4f, -0.2f);
    glVertex2f(1.6f, -0.2f);

    // bottom cross
    glVertex2f(0.7f, -0.5f);
    glVertex2f(0.7f, -0.7f);

    glVertex2f(0.8f, -0.5f);
    glVertex2f(0.8f, -0.7f);

    glVertex2f(0.9f, -0.5f);
    glVertex2f(0.9f, -0.7f);

    glVertex2f(1.0f, -0.5f);
    glVertex2f(1.0f, -0.7f);

    glVertex2f(1.1f, -0.5f);
    glVertex2f(1.1f, -0.7f);

    // top cross
    glVertex2f(0.7f, 0.5f);
    glVertex2f(0.7f, 0.7f);

    glVertex2f(0.8f, 0.5f);
    glVertex2f(0.8f, 0.7f);

    glVertex2f(0.9f, 0.5f);
    glVertex2f(0.9f, 0.7f);

    glVertex2f(1.0f, 0.5f);
    glVertex2f(1.0f, 0.7f);

    glVertex2f(1.1f, 0.5f);
    glVertex2f(1.1f, 0.7f);
    glEnd();
    // zebra-crossing end

    // road border
    glLineWidth(3.0f);
    glBegin(GL_LINES);
    glColor3ub(102, 102, 102);
    glVertex2f(-2.0f, 0.5f);
    glVertex2f(0.4f, 0.5f);

    glVertex2f(0.4f, 0.5f);
    glVertex2f(0.4f, 1.0f);

    glVertex2f(1.4f, 1.0f);
    glVertex2f(1.4f, 0.5f);

    glVertex2f(1.4f, 0.5f);
    glVertex2f(2.0f, 0.5f);

    glVertex2f(2.0f, -0.5f);
    glVertex2f(1.4f, -0.5f);

    glVertex2f(1.4f, -0.5f);
    glVertex2f(1.4f, -1.0f);

    glVertex2f(0.4f, -1.0f);
    glVertex2f(0.4f, -0.5f);

    glVertex2f(0.4f, -0.5f);
    glVertex2f(-2.0f, -0.5f);

    glColor3ub(230, 230, 230);
    glVertex2f(-2.0f, 0.3f);
    glVertex2f(0.6f, 0.3f);

    glVertex2f(0.6f, 0.3f);
    glVertex2f(0.6f, 1.0f);

    glVertex2f(1.2f, 1.0f);
    glVertex2f(1.2f, 0.3f);

    glVertex2f(1.2f, 0.3f);
    glVertex2f(2.0f, 0.3f);

    glVertex2f(2.0f, -0.3f);
    glVertex2f(1.2f, -0.3f);

    glVertex2f(1.2f, -0.3f);
    glVertex2f(1.2f, -1.0f);

    glVertex2f(0.6f, -1.0f);
    glVertex2f(0.6f, -0.3f);

    glVertex2f(0.6f, -0.3f);
    glVertex2f(-2.0f, -0.3f);
    glEnd();
    /// road end

    car1();
    car2();
    car3();
    car4();
    traffic_light1();
    traffic_light2();

    /// road-light start
    glLineWidth(3.0f);
    // left-up
    glBegin(GL_LINES);
    glColor3ub(128, 128, 128);
    glVertex2f(-1.9f, 0.4f);
    glVertex2f(-1.8f, 0.4f);

    glVertex2f(-1.8f, 0.4f);
    glVertex2f(-1.8f, 0.1f);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(255, 255, 0);
    glVertex2f(-1.85f, 0.25f);
    glVertex2f(-1.8f, 0.25f);
    glVertex2f(-1.8f, 0.1f);
    glVertex2f(-1.85f, 0.1f);
    glEnd();
    glPointSize(10.0); //
    glBegin(GL_POINTS);
    glColor3ub(89, 89, 89);
    glVertex2f(-1.9f, 0.4f);
    glEnd();

    for (int i = 0; i < 3; i++) {
        glTranslated(0.6, 0.0, 0.0);
        glBegin(GL_LINES);
        glColor3ub(128, 128, 128);
        glVertex2f(-1.9f, 0.4f);
        glVertex2f(-1.8f, 0.4f);

        glVertex2f(-1.8f, 0.4f);
        glVertex2f(-1.8f, 0.1f);
        glEnd();
        glBegin(GL_POLYGON);
        glColor3ub(255, 255, 0);
        glVertex2f(-1.85f, 0.25f);
        glVertex2f(-1.8f, 0.25f);
        glVertex2f(-1.8f, 0.1f);
        glVertex2f(-1.85f, 0.1f);
        glEnd();
        glBegin(GL_POINTS);
        glColor3ub(89, 89, 89);
        glVertex2f(-1.9f, 0.4f);
        glEnd();
    }

    // left-down
    glBegin(GL_LINES);
    glColor3ub(128, 128, 128);
    glVertex2f(-1.6f, -0.4f);
    glVertex2f(-1.5f, -0.4f);

    glVertex2f(-1.5f, -0.4f);
    glVertex2f(-1.5f, -0.1f);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(255, 255, 0);
    glVertex2f(-1.5f, -0.1f);
    glVertex2f(-1.55f, -0.1f);
    glVertex2f(-1.55f, -0.25f);
    glVertex2f(-1.5f, -0.25f);
    glEnd();
    glBegin(GL_POINTS);
    glColor3ub(89, 89, 89);
    glVertex2f(-1.6f, -0.4f);
    glEnd();

    for (int i = 0; i < 3; i++) {
        glTranslated(-0.6, 0.0, 0.0);
        glBegin(GL_LINES);
        glColor3ub(128, 128, 128);
        glVertex2f(-1.6f, -0.4f);
        glVertex2f(-1.5f, -0.4f);

        glVertex2f(-1.5f, -0.4f);
        glVertex2f(-1.5f, -0.1f);
        glEnd();
        glBegin(GL_POLYGON);
        glColor3ub(255, 255, 0);
        glVertex2f(-1.5f, -0.1f);
        glVertex2f(-1.55f, -0.1f);
        glVertex2f(-1.55f, -0.25f);
        glVertex2f(-1.5f, -0.25f);
        glEnd();
        glBegin(GL_POINTS);
        glColor3ub(89, 89, 89);
        glVertex2f(-1.6f, -0.4f);
        glEnd();
    }

    // right-up
    glBegin(GL_LINES);
    glColor3ub(128, 128, 128);
    glVertex2f(1.4f, 0.4f);
    glVertex2f(1.5f, 0.4f);

    glVertex2f(1.5f, 0.4f);
    glVertex2f(1.5f, 0.1f);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(255, 255, 0);
    glVertex2f(1.5f, 0.1f);
    glVertex2f(1.45f, 0.1f);
    glVertex2f(1.45f, 0.25f);
    glVertex2f(1.5f, 0.25f);
    glEnd();
    glBegin(GL_POINTS);
    glColor3ub(89, 89, 89);
    glVertex2f(1.4f, 0.4f);
    glEnd();

    // right-down
    glBegin(GL_LINES);
    glColor3ub(128, 128, 128);
    glVertex2f(1.7f, -0.4f);
    glVertex2f(1.8f, -0.4f);

    glVertex2f(1.8f, -0.4f);
    glVertex2f(1.8f, -0.1f);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(255, 255, 0);
    glVertex2f(1.8f, -0.1f);
    glVertex2f(1.75f, -0.1f);
    glVertex2f(1.75f, -0.25f);
    glVertex2f(1.8f, -0.25f);
    glEnd();
    glBegin(GL_POINTS);
    glColor3ub(89, 89, 89);
    glVertex2f(1.7f, -0.4f);
    glEnd();

    // bottom-left
    glBegin(GL_LINES);
    glColor3ub(128, 128, 128);
    glVertex2f(0.5f, -0.7f);
    glVertex2f(0.5f, -0.6f);

    glVertex2f(0.5f, -0.6f);
    glVertex2f(0.8f, -0.6f);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(255, 255, 0);
    glVertex2f(0.8f, -0.6f);
    glVertex2f(0.8f, -0.65f);
    glVertex2f(0.65f, -0.65f);
    glVertex2f(0.65f, -0.6f);
    glEnd();
    glBegin(GL_POINTS);
    glColor3ub(89, 89, 89);
    glVertex2f(0.5f, -0.7f);
    glEnd();

    // bottom-right
    glBegin(GL_LINES);
    glColor3ub(128, 128, 128);
    glVertex2f(1.3f, -1.0f);
    glVertex2f(1.3f, -0.9f);

    glVertex2f(1.3f, -0.9f);
    glVertex2f(1.0f, -0.9f);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(255, 255, 0);
    glVertex2f(1.0f, -0.9f);
    glVertex2f(1.0f, -0.95f);
    glVertex2f(1.15f, -0.95f);
    glVertex2f(1.15f, -0.9f);
    glEnd();

    // top-left
    glBegin(GL_LINES);
    glColor3ub(128, 128, 128);
    glVertex2f(0.5f, 0.8f);
    glVertex2f(0.5f, 0.9f);

    glVertex2f(0.5f, 0.9f);
    glVertex2f(0.8f, 0.9f);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(255, 255, 0);
    glVertex2f(0.8f, 0.9f);
    glVertex2f(0.8f, 0.85f);
    glVertex2f(0.65f, 0.85f);
    glVertex2f(0.65f, 0.9f);
    glEnd();
    glBegin(GL_POINTS);
    glColor3ub(89, 89, 89);
    glVertex2f(0.5f, 0.8f);
    glEnd();

    // top-right
    glBegin(GL_LINES);
    glColor3ub(128, 128, 128);
    glVertex2f(1.3f, 0.5f);
    glVertex2f(1.3f, 0.6f);

    glVertex2f(1.3f, 0.6f);
    glVertex2f(1.0f, 0.6f);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(255, 255, 0);
    glVertex2f(1.0f, 0.6f);
    glVertex2f(1.0f, 0.55f);
    glVertex2f(1.15f, 0.55f);
    glVertex2f(1.15f, 0.6f);
    glEnd();
    glBegin(GL_POINTS);
    glColor3ub(89, 89, 89);
    glVertex2f(1.3f, 0.5f);
    glEnd();
    /// road-light end
 
    glPushMatrix();
    
    glPopMatrix();
 

    glFlush();
}

void update_car1(int value) {
    if (cnt == 0) {
        speed_c1 = 0.01f;
        if (position_c1 > 2.7)
            position_c1 = -2.7f;

        position_c1 += speed_c1;
    }

    else {
        if (position_c1 > 0.0) {
            speed_c1 = 0.0f;
            position_c1 = 0.0;
        }
        position_c1 += speed_c1;
    }

    glutPostRedisplay();
    glutTimerFunc(10, update_car1, 0);
}

void update_car2(int value) {
    if (cnt == 0) {
        speed_c2 = 0.01f;
        if (position_c2 < -2.7)
            position_c2 = 2.7f;

        position_c2 -= speed_c2;
    }
    else {
        if (position_c2 < 1.8) {
            speed_c2 = 0.0f;
            position_c2 = 1.8;
        }
        position_c2 -= speed_c2;
    }

    glutPostRedisplay();
    glutTimerFunc(10, update_car2, 0);
}

void update_car3(int value) {
    if (cnt == 0) {
        if (position_c3 > -0.9) {
            speed_c3 = 0.0f;
            position_c3 = -0.9;
        }
        position_c3 += speed_c3;
    }

    else {
        speed_c3 = 0.01f;
        if (position_c3 > 1.7)
            position_c3 = -1.7f;

        position_c3 += speed_c3;
    }

    glutPostRedisplay();
    glutTimerFunc(10, update_car3, 0);
}

void update_car4(int value) {
    if (cnt == 0) {
        if (position_c4 < 0.9) {
            speed_c4 = 0.0f;
            position_c4 = 0.9;
        }
        position_c4 -= speed_c4;
    }

    else {
        speed_c4 = 0.01f;
        if (position_c4 < -1.7)
            position_c4 = 1.7f;

        position_c4 -= speed_c4;
    }

    glutPostRedisplay();
    glutTimerFunc(10, update_car4, 0);
}

void button(unsigned char key, int x, int y) {

    switch (key) {
    case 'f':
        glutDisplayFunc(day);
        break;

    case 'r':
        cnt++;
        break;

    case 'g':
        cnt = 0;
        break;

    case 'n':
        flag++;
        glutDisplayFunc(night);
        glutPostRedisplay();
       
        break;

    case 'd':
        flag = 0;
        glutDisplayFunc(day);
        glutPostRedisplay();
     
        break;
    }
}

void inigl() {
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f); // Set background color to black and opaque
    gluOrtho2D(-2, 2, -1, 1); // Set range of axis of display (left, right, bottom, top)
}
// Main function: GLUT runs as a console application starting at main()
int main(int argc, char** argv) {
    glutInit(&argc, argv); // Initialize GLUT
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(1430, 800); // Set the window's initial width & height
    glutInitWindowPosition(0, 0); // Set the window position
    glutCreateWindow("test"); // Create a window with the given title

    cout << "Project Title: Traffic Signal In The City \n" << endl;
    cout << "Group Member :" << endl;
    cout << "Khush Vijayvargiya \t 102103020" << endl;
    cout << "Yogesh Rathee \t\t 102103022" << endl;
    cout << "Jagveer Singh \t\t 102103024" << endl;
    glutDisplayFunc(day);
    inigl();
     
    glutTimerFunc(10, update_car1, 0);
    glutTimerFunc(10, update_car2, 0);
    glutTimerFunc(10, update_car3, 0);
    glutTimerFunc(10, update_car4, 0);
   
    glutKeyboardFunc(button);
 

    glutMainLoop();
    return 0;
}

