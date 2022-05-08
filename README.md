## README

*This is a Course Project for BUAA Computer Graphic Course*

* File Structures

  * Project is in visual studio project
  * CG1\CG2\CG3 are sample program
  * Principle and effects.pdf
  * two dependent library files of X64
  
* **CG1，CG2，CG3 could run instantly**

  **Press the up, down, left and right arrow keys to rotate the object. CG3 can press F1,F2,F3,F5 to change the density of the spherical mesh (corresponding to the recursive depth of 2345 respectively).**

### Dependent libraries：

* **opengl**（glut）X64

* **freeimage** X64（using visual studio）

  using**visual studio 2022**

### Using Instructions

* Configure the library, rely on the path (freeimage, glut), place freeimage.dll in the root directory (already placed)
* Open project Project1 with three C files: CG1\CG2\CG3
  * CG1 is **rotated color cube** and has 2D graphics in it
  * CG3 is **a three-dimensional sphere drawn by recursive subdivision** 
  * CG2 is **the rest**. Complex scenes with texture maps, environment maps, cube shadows, two light sources, perspective projections, translucent effects
  **Yellow corresponds to CG2, green to CG1, and red to CG3**
* If you want to run one, just comment out the code of the other two files and run it directly

### 食用方法

* 配置好库，依赖路径（freeimage、glut），将FreeImage.dll放入根目录（已放置好）
* 打开项目Project1，其中有三个c文件：CG1\CG2\CG3
  * CG1是**旋转彩色立方体**，并有2D图形在其中
  
  * CG3是利用**递归细分绘制的三维球面**
  
  * CG2是**其余的**。有纹理映射的，环境映射的，立方体阴影的，两个光源的，透视投影的，半透明效果的复杂场景
  
    **黄色对应的是CG2，绿色对应的是CG1，红色对应的是CG3**
* 想要运行哪一个，只需要将其余两个文件的代码全都注释掉，直接运行即可