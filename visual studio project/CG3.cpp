////
//// Created by mawen on 2021/11/2.
////
//#include<GL/glut.h>
//#include<math.h>
//#include<iostream>
//int DEPTH = 3;
//GLfloat xRot_triangle = 0.0f;
//GLfloat yRot_triangle = 0.0f;
//using namespace std;
//
//GLfloat tetrahedron_vertex[][3] = {
//        0.0f,		 0.0f,		 1.0f,
//        0.0f,		 0.942809f, -0.333333f,
//        -0.816497f, -0.471405f, -0.333333f,
//        0.816497f, -0.471405f, -0.333333f
//};
//
//void normalize(GLfloat* v)
//{
//    GLfloat d = sqrt(v[0] * v[0] + v[1] * v[1] + v[2] * v[2]);
//    v[0] /= d; v[1] /= d; v[2] /= d;
//}
//
//void divide_triangle(GLfloat* a, GLfloat* b, GLfloat* c, int depth)
//{
//    if (depth > 0) {
//        GLfloat ab[3], ac[3], bc[3];
//        for (unsigned int i = 0; i < 3; i++)
//            ab[i] = a[i] + b[i];
//        normalize(ab);
//        for (unsigned int i = 0; i < 3; i++)
//            ac[i] = a[i] + c[i];
//        normalize(ac);
//        for (unsigned int i = 0; i < 3; i++)
//            bc[i] = b[i] + c[i];
//        normalize(bc);
//        divide_triangle(a, ab, ac, depth - 1);
//        divide_triangle(b, bc, ab, depth - 1);
//        divide_triangle(c, ac, bc, depth - 1);
//        divide_triangle(ab, bc, ac, depth - 1);
//    }
//    else {
//        glBegin(GL_LINE_LOOP);
//        glColor3f(sqrt(a[0] * a[0]), sqrt(a[1] * a[1]), sqrt(a[2] * a[2]));
//        glVertex3fv(a);
//        glVertex3fv(b);
//        glVertex3fv(c);
//        glEnd();
//    }
//}
//
//void display()
//{
//    glFrontFace(GL_CCW);
//    // ���ò����Ʊ��棬��ʡ����ͬʱ������ֱ��渲����������
//    glCullFace(GL_BACK);
//    glEnable(GL_CULL_FACE);
//    // ���ñ���Ϊ��ɫ
//    glClearColor(1.0, 1.0, 1.0, 1.0);
//    glClear(GL_COLOR_BUFFER_BIT);
//    // ���ص�λ��
//    glLoadIdentity();
//    // ���������λ�ú��ӽ�
//    // �й�gluLookAt��https://blog.csdn.net/Augusdi/article/details/20470813
//    gluLookAt(2, 2, 2, 0.0, 0.0, 0.0, -1, -1, 1);
//
//    glPushMatrix();
//    glRotatef(xRot_triangle, 1.0f, 0.0f, 0.0f);
//    glRotatef(yRot_triangle, 0.0f, 1.0f, 0.0f);
//    // ������ʱ�����еĵ�Χ�ɵ�ƽ��Ϊ����
//    divide_triangle(tetrahedron_vertex[0], tetrahedron_vertex[2], tetrahedron_vertex[1], DEPTH);
//    divide_triangle(tetrahedron_vertex[0], tetrahedron_vertex[3], tetrahedron_vertex[2], DEPTH);
//    divide_triangle(tetrahedron_vertex[0], tetrahedron_vertex[1], tetrahedron_vertex[3], DEPTH);
//    divide_triangle(tetrahedron_vertex[1], tetrahedron_vertex[2], tetrahedron_vertex[3], DEPTH);
//
//    glutSwapBuffers();
//}
//
//// ���ڴ�С����Ӧ������ʹ�ô��ڴ�С�ı�ʱ�Ա���ͼ�εı�������
//// �йش�������Ӧ������http://blog.sina.com.cn/s/blog_5497dc110102w8qh.html
//void reshape(int w, int h)
//{
//    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
//    glMatrixMode(GL_PROJECTION);
//    glLoadIdentity();
//    gluPerspective(60.0, (GLfloat)w / (GLfloat)h, 1.0, 20.0);
//    glMatrixMode(GL_MODELVIEW);
//    glLoadIdentity();
//    gluLookAt(2, 2, 2, 0.0, 0.0, 0.0, -1, -1, 1);
//}
//
//void SpecialKeys(int key, int x, int y) {
//    if (key == GLUT_KEY_F2) {
//        DEPTH = 2;
//    }
//    if (key == GLUT_KEY_F3) {
//        DEPTH = 3;
//    }
//    if (key == GLUT_KEY_F4) {
//        DEPTH = 4;
//    }
//    if (key == GLUT_KEY_F5) {
//        DEPTH = 5;
//    }
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
//
//int main(int argc, char** argv)
//{
//    glutInit(&argc, argv);
//    // ����˫�����RGB��ɫģʽ
//    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
//    // ���ô��ڴ�С��λ�ú�����
//    glutInitWindowSize(500, 500);
//    glutInitWindowPosition(100, 100);
//    glutCreateWindow("sphere");
//    // ���û��ƺ��������ڴ�С����Ӧ����
//    glutDisplayFunc(display);
//    glutReshapeFunc(reshape);
//    glutSpecialFunc(SpecialKeys);
//    // ������ѭ��
//    glutMainLoop();
//    return 0;
//}
