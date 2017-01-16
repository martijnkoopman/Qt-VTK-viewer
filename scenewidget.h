#ifndef SCENEWIDGET_H
#define SCENEWIDGET_H

#include <QVTKWidget2.h>

#include <vtkSmartPointer.h>
#include <vtkRenderer.h>
#include <vtkDataSet.h>

class SceneWidget : public QVTKWidget2
{
    Q_OBJECT
public:
    explicit SceneWidget(QWidget *parent = 0);
    void addDataSet(vtkSmartPointer<vtkDataSet> dataSet);

public slots:
    void zoomToExtent();

private:
    vtkSmartPointer<vtkRenderer> m_renderer;
};

#endif // SCENEWIDGET_H
