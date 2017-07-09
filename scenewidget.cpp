#include "scenewidget.h"

#include <vtkCamera.h>
#include <vtkGenericOpenGLRenderWindow.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkProperty.h>
#include <vtkDataSetMapper.h>

SceneWidget::SceneWidget(QWidget *parent)
  : QVTKOpenGLWidget(parent)
{
  vtkNew<vtkGenericOpenGLRenderWindow> window;
  SetRenderWindow(window.Get());

  // Camera
  vtkSmartPointer<vtkCamera> camera = vtkSmartPointer<vtkCamera>::New();
  camera->SetViewUp(0,1,0);
  camera->SetPosition(0,0,10);
  camera->SetFocalPoint(0,0,0);

  // Renderer
  m_renderer = vtkSmartPointer<vtkRenderer>::New();
  m_renderer->SetActiveCamera(camera);
  m_renderer->SetBackground(0.5, 0.5, 0.5);
  GetRenderWindow()->AddRenderer(m_renderer);
}

void SceneWidget::addDataSet(vtkSmartPointer<vtkDataSet> dataSet)
{
  // Actor
  vtkSmartPointer<vtkActor> actor = vtkSmartPointer<vtkActor>::New();

  // Mapper
  vtkSmartPointer<vtkDataSetMapper> mapper = vtkSmartPointer<vtkDataSetMapper>::New();
  mapper->SetInputData(dataSet);
  actor->SetMapper(mapper);

  m_renderer->AddActor(actor);
  m_renderer->ResetCamera(dataSet->GetBounds());

  renderVTK();
}


void SceneWidget::removeDataSet()
{
  vtkActor *actor = m_renderer->GetActors()->GetLastActor();
  if (actor != nullptr)
  {
    m_renderer->RemoveActor(actor);
  }

  renderVTK();
}

void SceneWidget::zoomToExtent()
{
  // Zoom to extent of last added actor
  vtkSmartPointer<vtkActor> actor = m_renderer->GetActors()->GetLastActor();
  if (actor != nullptr)
  {
    m_renderer->ResetCamera(actor->GetBounds());
  }

  renderVTK();
}
