#include<GL/glut.h>
#include<math.h>
#include<iostream>
#include <stdio.h>
#include <stdlib.h>
#include "FreeImage.h"
#define DEPTH 4
#define PI 3.1415926

GLfloat xRot_triangle = 0.0f;
GLfloat yRot_triangle = 0.0f;
using namespace std;

//定义两个纹理对象编号
GLuint texname;
GLuint texreflect;

/* 函数load_texture
* 读取一个BMP文件作为纹理
* 如果失败，返回0，如果成功，返回纹理编号
*/
GLuint load_texture(const char* file_name)
{
    GLint width, height, total_bytes;
    GLubyte* pixels = 0;
    GLuint last_texture_ID = 0, texture_ID = 0;

    FreeImage_Initialise(TRUE);
    //加载图片
    FIBITMAP* JPEG = FreeImage_Load(FIF_BMP, file_name, 0);
    //获取影像的宽高，都以像素为单位
    width = FreeImage_GetWidth(JPEG);
    height = FreeImage_GetHeight(JPEG);
    pixels = (GLubyte*)FreeImage_GetBits(JPEG);


    // 分配一个新的纹理编号
    glGenTextures(1, &texture_ID);
    if (texture_ID == 0)
    {
        //free(pixels);
        FreeImage_Unload(JPEG);
        return 0;
    }

    // 绑定新的纹理，载入纹理并设置纹理参数
    // 在绑定前，先获得原来绑定的纹理编号，以便在最后进行恢复
    GLint lastTextureID = last_texture_ID;
    glGetIntegerv(GL_TEXTURE_BINDING_2D, &lastTextureID);
    glBindTexture(GL_TEXTURE_2D, texture_ID);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0,
        GL_BGR_EXT, GL_UNSIGNED_BYTE, pixels);
    glBindTexture(GL_TEXTURE_2D, lastTextureID);  //恢复之前的纹理绑定
    //free(pixels);
    FreeImage_Unload(JPEG);
    return texture_ID;
}
void namecard(void)
{
    glBindTexture(GL_TEXTURE_2D, texname);
    glBegin(GL_QUADS);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f, 0.0f, 1.0f);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, 2.0f, 1.0f);
    glTexCoord2f(0.0f, 0.0f); glVertex3f(1.0f, 2.0f, 1.0f);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(1.0f, 0.0f, 1.0f);
    glEnd();

    /*glBindTexture(GL_TEXTURE_2D, texreflect);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 0.0f); glVertex3f(-4.5f, -2.5f, 1.0f);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(-3.5f, -2.5f, 1.0f);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(-3.5f, -2.5f, 2.0f);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(-4.5f, -2.5f, 2.0f);
    glEnd();*/

}

void some2Ds() {
    glBegin(GL_POLYGON);
    glColor3f(1.0f, 1.0f,
        0.0f);
    glVertex3f(0.5f, 0.0f, 0.5f);
    glVertex3f(1.5f, 0.0f, 0.5f);
    glVertex3f(2.0f, 1.0f, 0.5f);
    glVertex3f(1.5f, 2.0f, 0.5f);
    glVertex3f(0.5f, 2.0f, 0.5f);
    glVertex3f(0.0f, 1.0f, 0.5f);
    glEnd();

    //    glBegin(GL_TRIANGLES);
    //    glColor3f(0.0f, 0.0f,1.0f);
    //    glVertex3f(-0.3f,-0.3f, 0.0f);
    //    glVertex3f(0.3f,-0.3f, 0.0f);
    //    glVertex3f(0.0f,0.2f, 0.0f);
    //    glColor3f(1.0f, 0.0f,0.0f);
    //    glVertex3f(-0.3f,0.2f, 0.0f);
    //    glColor3f(0.0f, 1.0f,0.0f);
    //    glVertex3f(0.3f,0.2f, 0.0f);
    //    glColor3f(0.0f, 0.0f,1.0f);
    //    glVertex3f(0.0f,-0.3f, 0.0f);
    //    glEnd();
}

void blend2Ds() {
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    //glBlendFunc(GL_ONE, GL_ONE);
    //glBlendFunc(GL_ONE, GL_ONE);

    glColor4f(1, 0, 0, 0.5);
    glRectf(-1, -1, 0.5, 0.5);
    glColor4f(0, 1, 0, 0.5);
    glRectf(-0.5, -0.5, 1, 1);
}

void frame()
{
    // 绘制三维坐标架
    glColor3f(0.3f, 0.3f, 0.3f);
    glLineWidth(0.75);
    glBegin(GL_LINES);
    glVertex3f(-100.0f, 0.0f, 0.0f);
    glVertex3f(100.0f, 00.0f, 0.0f);
    glVertex3f(0.0f, -100.0f, 0.0f);
    glVertex3f(0.0f, 100.0f, 0.0f);
    glVertex3f(0.0f, 0.0f, -100.0f);
    glVertex3f(0.0f, 0.0f, 100.0f);
    glEnd();
    // 绘制XOY平面
    glColor4f(0.8f, 0.8f, 0.8f, 0.5f);
    glNormal3f(0.0f, 0.0f, 1.0f);
    glBegin(GL_QUADS);
    glVertex3f(8.0f, 8.0f, -0.1f);
    glVertex3f(-8.0f, 8.0f, -0.1f);
    glVertex3f(-8.0f, -8.0f, -0.1f);
    glVertex3f(8.0f, -8.0f, -0.1f);
    glEnd();
}

void normalize(GLfloat* v)
{
    GLfloat d = sqrt(v[0] * v[0] + v[1] * v[1] + v[2] * v[2]);
    v[0] /= d; v[1] /= d; v[2] /= d;
}
void divide_triangle(GLfloat* a, GLfloat* b, GLfloat* c, int depth)
{
    if (depth > 0) {
        GLfloat ab[3], ac[3], bc[3];
        for (unsigned int i = 0; i < 3; i++)
            ab[i] = a[i] + b[i];
        normalize(ab);
        for (unsigned int i = 0; i < 3; i++)
            ac[i] = a[i] + c[i];
        normalize(ac);
        for (unsigned int i = 0; i < 3; i++)
            bc[i] = b[i] + c[i];
        normalize(bc);
        divide_triangle(a, ab, ac, depth - 1);
        divide_triangle(b, bc, ab, depth - 1);
        divide_triangle(c, ac, bc, depth - 1);
        divide_triangle(ab, bc, ac, depth - 1);
    }
    else {
        glBegin(GL_TRIANGLES);
        glNormal3fv(a);
        glVertex3fv(a);
        glNormal3fv(b);
        glVertex3fv(b);
        glNormal3fv(c);
        glVertex3fv(c);
        glEnd();
    }
}
void sphere()
{
    GLfloat tetrahedron_vertex[][3] = {
            0.0f,		 0.0f,		 1.0f,
            0.0f,		 0.942809f, -0.333333f,
            -0.816497f, -0.471405f, -0.333333f,
            0.816497f, -0.471405f, -0.333333f
    };
    glColor3f(1.00f, 0.00f, 0.00f);
    divide_triangle(tetrahedron_vertex[0], tetrahedron_vertex[2], tetrahedron_vertex[1], DEPTH);
    divide_triangle(tetrahedron_vertex[0], tetrahedron_vertex[3], tetrahedron_vertex[2], DEPTH);
    divide_triangle(tetrahedron_vertex[0], tetrahedron_vertex[1], tetrahedron_vertex[3], DEPTH);
    divide_triangle(tetrahedron_vertex[1], tetrahedron_vertex[2], tetrahedron_vertex[3], DEPTH);
}

void color_cube(GLfloat size, bool isShaddow)
{
    // 设置立方体的八个顶点坐标
    static const GLfloat vertex[][3] = {
            0.0f, 0.0f, 0.0f,
            size, 0.0f, 0.0f,
            0.0f, size, 0.0f,
            size, size, 0.0f,
            0.0f, 0.0f, size,
            size, 0.0f, size,
            0.0f, size, size,
            size, size, size
    };
    // 设置绘制六个面时顶点的顺序
    static const GLint index[][4] = {
            0, 2, 3, 1,
            //            0, 4, 6, 2,
                        0, 1, 5, 4,
                        4, 5, 7, 6,
                        //            1, 3, 7, 5,
                                    2, 6, 7, 3
    };
    // 指定六个面的法向
    static const GLfloat normal[][3] = {
            0.0f, 0.0f, -1.0f,
            //            -1.0f, 0.0f, 0.0f,
                        0.0f, -1.0f, 0.0f,
                        0.0f, 0.0f, 1.0f,
                        //            1.0f, 0.0f, 0.0f,
                                    0.0f, 1.0f, 0.0f
    };
    // 绘制六个面
    glBegin(GL_QUADS);
    for (unsigned int i = 0; i < 4; i++) {
        glNormal3fv(normal[i]);
        for (unsigned int j = 0; j < 4; j++) {
            // 每个顶点的RGB颜色值和其顶点位置坐标一致
            if (!isShaddow) {
                glColor3f(vertex[index[i][j]][0] / size,
                    vertex[index[i][j]][1] / size, vertex[index[i][j]][2] / size);
            }
            else {
                glColor4f(0.2f, 0.2f, 0.2f, 0.5f);
            }
            glVertex3fv(vertex[index[i][j]]);
        }
    }
    glEnd();
}
void cube_shadow(GLfloat x, GLfloat y, GLfloat z, GLfloat size)
{

    GLfloat m[16] = { 0.0f };
    m[0] = m[5] = m[10] = 1.0f;
    m[11] = -1.0f / z;
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(x, y, z);
    glMultMatrixf(m);
    glTranslatef(-x, -y, -z);
    color_cube(size, true);
    glPopMatrix();
}

void display()
{
    // 设置背景为白色
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    // 加载单位阵
    glLoadIdentity();
    // 设置相机的位置和视角
    gluLookAt(4, 4, 4, 0.0, 0.0, 0.0, 0, 0, 1);

    //旋转
    glPushMatrix();
    //glRotatef(xRot_triangle, 1.0f, 0.0f, 0.0f);
    //glRotatef(yRot_triangle, 0.0f, 1.0f, 0.0f);
    glRotatef(yRot_triangle, 0.0f, 0.0f, 1.0f);

    // 绘制坐标架以及XOY平面
    frame();
    // 平移坐标系，让三个待绘制物品的底部排列在X轴上
    glTranslatef(0.0f, 0.0f, 1.0f);
    // 在中心绘制三维彩色立方体，并绘制简单阴影，在画一些2d图形
    glTranslatef(-1.0f, -1.0f, -1.0f);
    color_cube(2.0f, false);
    cube_shadow(0.0f, 0.0f, 10.0f, 1.5f);
    some2Ds();
    glTranslatef(1.0f, 1.0f, 1.0f);
    // 在左侧（Y轴负半轴）绘制红色球面
    glTranslatef(0.0f, -4.0f, 0.0f);
    sphere();
    glTranslatef(0.0f, 4.0f, 0.0f);
    // 在右侧绘制半透明效果2d
    glTranslatef(0.0f, 4.0f, 0.0f);
    blend2Ds();
    glTranslatef(0.0f, -4.0f, 0.0f);
    // 在前侧画出学号姓名贴图
    glEnable(GL_TEXTURE_2D);    // 启用纹理
    glTranslatef(4.0f, 0.0f, 0.0f);
    namecard();
    glTranslatef(-4.0f, 0.0f, 0.0f);
    glDisable(GL_TEXTURE_2D);   // 关闭纹理
    // 刷新帧缓存
    glutSwapBuffers();
}

// 窗口大小自适应函数，使得窗口大小改变时仍保持图形的比例不变
// 有关窗口自适应函数：http://blog.sina.com.cn/s/blog_5497dc110102w8qh.html
void reshape(int w, int h)
{
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60.0, (GLfloat)w / (GLfloat)h, 1.0, 20.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(4, 4, 4, 0.0, 0.0, 0.0, 0, 0, 1);
}

void init()
{
    // 设置逆时针排列的点围成的平面为正面
    glFrontFace(GL_CCW);
    // 设置不绘制背面，节省算力同时不会出现背面覆盖正面的情况
//    glCullFace(GL_BACK);
//    glEnable(GL_CULL_FACE);
    // 启用抗锯齿（使线平滑）
    glEnable(GL_BLEND);
    glEnable(GL_LINE_SMOOTH);
    glHint(GL_LINE_SMOOTH_HINT, GL_FASTEST);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    // 设置材质和光照的信息
    // 有关光照与材质：https://blog.csdn.net/timidsmile/article/details/7017197
    GLfloat mat_ambient[4] = { 1.0f, 1.0f, 1.0f, 0.0f };
    GLfloat mat_diffuse[4] = { 1.0f, 1.0f, 1.0f, 0.0f };
    GLfloat mat_specular[4] = { 1.0f, 1.0f, 1.0f, 1.0f };
    GLfloat mat_shininess[4] = { 100.0f };
    GLfloat light_ambient[4] = { 0.2f, 0.2f, 0.2f, 0.0f };
    GLfloat light_diffuse[4] = { 1.0f, 1.0f, 1.0f, 1.0f };
    GLfloat light_specular[4] = { 1.0f, 1.0f, 1.0f, 1.0f };

    GLfloat light_position_0[4] = { 0.0f, -6.0f, 0.0f, 1.0f };
    GLfloat light_position_1[4] = { 0.0f, 0.0f, 6.0f, 1.0f };
    // 设置正向面的材质和光源的光照
    glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);

    glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position_0);

    glLightfv(GL_LIGHT1, GL_AMBIENT, light_ambient);
    glLightfv(GL_LIGHT1, GL_DIFFUSE, light_diffuse);
    glLightfv(GL_LIGHT1, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT1, GL_POSITION, light_position_1);
    // 设置颜色材料，使光照模式下仍然可以显示原本的颜色
    glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
    glEnable(GL_COLOR_MATERIAL);
    // 启用平滑着色功能
    glShadeModel(GL_SMOOTH);
    // 启用光照功能
    glEnable(GL_LIGHTING);
    // 启用0号光源
    glEnable(GL_LIGHT0);
    //启用1号光源
    glEnable(GL_LIGHT1);
    // 启用检测深度
    glEnable(GL_DEPTH_TEST);
    // 环境颜色设置为白色
    glClearColor(1.0, 1.0, 1.0, 1.0);
}

void SpecialKeys(int key, int x, int y) {
    if (key == GLUT_KEY_UP) {
        xRot_triangle += 5.0f;//通过调整等号右边的数字的大小，控制每点一次                      按键，模型旋转的角度。
    }
    if (key == GLUT_KEY_DOWN) {
        xRot_triangle -= 5.0f;
    }
    if (key == GLUT_KEY_LEFT) {
        yRot_triangle += 5.0f;
    }
    if (key == GLUT_KEY_RIGHT) {
        yRot_triangle -= 5.0f;
    }
    if (xRot_triangle > 170.0f) {
        xRot_triangle = 0.0f;
    }
    if (xRot_triangle < -1.0f) {
        xRot_triangle = 355.0f;
    }
    if (yRot_triangle > 30.0f) {
        yRot_triangle = 0.0f;
    }
    if (yRot_triangle < -100.0f) {
        yRot_triangle = 355.0f;
    }
    glutPostRedisplay();
    
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    // 设置双缓冲和RGB颜色模式
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    // 设置窗口大小、位置和名称
    glutInitWindowSize(1000, 505);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("19231007");
    init();
    // 纹理相关
    //glEnable(GL_DEPTH_TEST);
    texreflect = load_texture("reflect.bmp");
    texname = load_texture("xxxxx.bmp");  //加载纹理
    // 设置绘制函数、窗口大小自适应函数
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    //glutSpecialFunc(SpecialKeys);
    // 进入主循环
    glutMainLoop();
    return 0;
}
