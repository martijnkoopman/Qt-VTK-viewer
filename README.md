# Qt-VTK-viewer
A CMake project for embedding a VTK 3D view in a Qt window.

![Qt VTK Viewer on Windows](doc/screenshot.png)

## Prerequisites
- Qt 5.x downloaded
- VTK 7.x source downloaded & compiled. See [Build-VTK.md](doc/Build-VTK.md) for a guide to compile VTK.

## Usage
1. Clone or download this repository
2. Open CMakeLists.txt in Qt Creator
3. Configure project
	1. Set build directory
	2. Specify VTK_DIR
4. Build project

Done. Happy coding :)

## A note on QVTKWidget
QVTKWidget is a QWidget provided by VTK, but QWidget has no support for OpenGL. QVTKWidget2 is a QGLWidget provided by VTK that has support for OpenGL. However, QGLWidget is deprecated since Qt version 5.4 and QOpenGLWidget should be used in new code.  QVTKWidget3 is a QOpenGLWidget provided in this repository for that purpose.

## License
This project is licensed under the Apache License 2.0 - see the [LICENSE.md](LICENSE.md) file for details.

## Acknowledgments
- QVTKWidget3 from [custusx.org](http://www.custusx.org/)
- Icons from [icons8.com](https://icons8.com/)
