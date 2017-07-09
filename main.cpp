#include "mainwindow.h"

#include <QApplication>
#include <QSurfaceFormat>

#include <QVTKOpenGLWidget.h>

int main(int argc, char *argv[])
{
  QSurfaceFormat::setDefaultFormat(QVTKOpenGLWidget::defaultFormat());

  QApplication a(argc, argv);
  MainWindow w;
  w.show();

  return a.exec();
}
