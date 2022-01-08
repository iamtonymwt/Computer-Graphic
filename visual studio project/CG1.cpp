//#include <GL/glut.h>
//GLfloat xRot_triangle = 0.0f;
//GLfloat yRot_triangle = 0.0f;
//
//void display(void);
//void myAnim(void);
//void some2Ds(void);
//void SpecialKeys(int key, int x, int y);
//float angle = 0.0f;
//
//int main(int argc, char** argv) {
//    glutInit(&argc, argv);
//    glutInitWindowSize(640, 640);
//    glutInitWindowPosition(50, 50);
//    int mode = GLUT_RGB | GLUT_SINGLE;
//    glutInitDisplayMode(mode);
//
//    glutCreateWindow("homework"); //��������
//
//    glutIdleFunc(&myAnim);  // ���ϵ�����ʾ�������ﵽ����Ч��
//    glutDisplayFunc(&display);
//    glutSpecialFunc(SpecialKeys);
//    glutMainLoop();// ���ú���������
//
//    return 0;
//}
//
//void display(void)
//{
//    glClear(GL_COLOR_BUFFER_BIT);
//    // ����������İ˸���������
//    static const GLfloat vertex[][3] = {
//            -0.5f, -0.5f, -0.5f,
//            0.5f, -0.5f, -0.5f,
//            0.5f, 0.5f, -0.5f,
//            -0.5f, 0.5f, -0.5f,
//            -0.5f, -0.5f, 0.5f,
//            0.5f, -0.5f, 0.5f,
//            0.5f, 0.5f, 0.5f,
//            -0.5f, 0.5f, 0.5f
//    };
//    // ���û���������ʱ�����˳��
//    static const GLint index[][4] = {
//            0, 1, 5, 4,
//            1, 2, 6, 5,
//            0, 4, 7, 3,
//            7, 6, 2, 3
//    };
//    glLoadIdentity();//��ʼ��
//    
//    glPushMatrix();
//    glRotatef(xRot_triangle, 1.0f, 0.0f, 0.0f);
//    glRotatef(yRot_triangle, 0.0f, 1.0f, 0.0f);
//
//    some2Ds();
//    glRotatef(angle, 1, 1, 1);//����3����תһ��
//
//    // ����������
//    glBegin(GL_QUADS);
//    for (unsigned int i = 0; i < 4; i++)
//        for (unsigned int j = 0; j < 4; j++) {
//            // ÿ�������RGB��ɫֵ���䶥��λ������һ��
//            glColor3fv(vertex[index[i][j]]);
//            glVertex3fv(vertex[index[i][j]]);
//        }
//    glEnd();
//
//    glFlush();
//}
//
//void some2Ds() {
//    glBegin(GL_POLYGON);
//    glColor3f(1.0f, 1.0f,
//        0.0f);
//    glVertex3f(-0.1f, -0.2f, 0.0f);
//    glVertex3f(0.1f, -0.2f, 0.0f);
//    glVertex3f(0.2f, 0.0f, 0.0f);
//    glVertex3f(0.1f, 0.2f, 0.0f);
//    glVertex3f(-0.1f, 0.2f, 0.0f);
//    glVertex3f(-0.2f, 0.0f, 0.0f);
//    glEnd();
//
//    glBegin(GL_TRIANGLES);
//    glColor3f(0.0f, 0.0f, 1.0f);
//    glVertex3f(-0.3f, -0.3f, 0.0f);
//    glVertex3f(0.3f, -0.3f, 0.0f);
//    glVertex3f(0.0f, 0.2f, 0.0f);
//    glColor3f(1.0f, 0.0f, 0.0f);
//    glVertex3f(-0.3f, 0.2f, 0.0f);
//    glColor3f(0.0f, 1.0f, 0.0f);
//    glVertex3f(0.3f, 0.2f, 0.0f);
//    glColor3f(0.0f, 0.0f, 1.0f);
//    glVertex3f(0.0f, -0.3f, 0.0f);
//    glEnd();
//}
//
//void myAnim(void)
//{
//    angle += 0.01f;
//    if (angle > 360) {
//        angle = 0.0f;
//    }
//    display();
//}
//
//void SpecialKeys(int key, int x, int y) {
//    if (key == GLUT_KEY_UP) {
//        xRot_triangle += 5.0f;//ͨ�������Ⱥ��ұߵ����ֵĴ�С������ÿ��һ��                      ������ģ����ת�ĽǶȡ�
//    }
//    if (key == GLUT_KEY_DOWN) {
//        xRot_triangle -= 5.0f;
//    }
//    if (key == GLUT_KEY_LEFT) {
//        yRot_triangle += 5.0f;
//    }
//    if (key == GLUT_KEY_RIGHT) {
//        yRot_triangle -= 5.0f;
//    }
//    if (xRot_triangle > 356.0f) {
//        xRot_triangle = 0.0f;
//    }
//    if (xRot_triangle < -1.0f) {
//        xRot_triangle = 355.0f;
//    }
//    if (yRot_triangle > 356.0f) {
//        yRot_triangle = 0.0f;
//    }
//    if (yRot_triangle < -1.0f) {
//        yRot_triangle = 355.0f;
//    }
//    glutPostRedisplay();
//
//}
