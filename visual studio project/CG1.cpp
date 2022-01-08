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
//    glutCreateWindow("homework"); //创建窗口
//
//    glutIdleFunc(&myAnim);  // 不断调用显示函数，达到动画效果
//    glutDisplayFunc(&display);
//    glutSpecialFunc(SpecialKeys);
//    glutMainLoop();// 调用函数来绘制
//
//    return 0;
//}
//
//void display(void)
//{
//    glClear(GL_COLOR_BUFFER_BIT);
//    // 设置立方体的八个顶点坐标
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
//    // 设置绘制六个面时顶点的顺序
//    static const GLint index[][4] = {
//            0, 1, 5, 4,
//            1, 2, 6, 5,
//            0, 4, 7, 3,
//            7, 6, 2, 3
//    };
//    glLoadIdentity();//初始化
//    
//    glPushMatrix();
//    glRotatef(xRot_triangle, 1.0f, 0.0f, 0.0f);
//    glRotatef(yRot_triangle, 0.0f, 1.0f, 0.0f);
//
//    some2Ds();
//    glRotatef(angle, 1, 1, 1);//沿着3轴旋转一次
//
//    // 绘制六个面
//    glBegin(GL_QUADS);
//    for (unsigned int i = 0; i < 4; i++)
//        for (unsigned int j = 0; j < 4; j++) {
//            // 每个顶点的RGB颜色值和其顶点位置坐标一致
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
//        xRot_triangle += 5.0f;//通过调整等号右边的数字的大小，控制每点一次                      按键，模型旋转的角度。
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
