/*
    Copyright (c) 2008-2014, SINTEF Department of Medical Technology
    All rights reserved.

    Redistribution and use in source and binary forms, with or without
    modification, are permitted provided that the following conditions are met:

    1. Redistributions of source code must retain the above copyright notice,
       this list of conditions and the following disclaimer.

    2. Redistributions in binary form must reproduce the above copyright notice,
       this list of conditions and the following disclaimer in the documentation
       and/or other materials provided with the distribution.

    3. Neither the name of the copyright holder nor the names of its contributors
       may be used to endorse or promote products derived from this software
       without specific prior written permission.

    THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
    AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
    IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
    DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
    FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
    DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
    SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
    CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
    OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
    OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#ifndef QVTKWIDGET3_H
#define QVTKWIDGET3_H

#include <vtkSmartPointer.h>
#include <vtkGenericOpenGLRenderWindow.h>
#include <vtkEventQtSlotConnect.h>

#include <QVTKInteractorAdapter.h>
#include <QVTKInteractor.h>

#include <QOpenGLWidget>
#include <QSurfaceFormat>

class QVTKWidget3 : public QOpenGLWidget
{
    Q_OBJECT

public:
    QVTKWidget3(QWidget *parent = NULL, Qt::WindowFlags f = 0, QSurfaceFormat format = QSurfaceFormat::defaultFormat());
    virtual ~QVTKWidget3();

    //! Set a custom render window
    virtual void SetRenderWindow(vtkGenericOpenGLRenderWindow*);
    //! Returns the curren render window (creates one if none exists)
    virtual vtkGenericOpenGLRenderWindow* GetRenderWindow();

    //! Returns interactor of the current render window
    virtual QVTKInteractor* GetInteractor();

public slots:
    //! Slot to make this vtk render window current
    virtual void MakeCurrent();
    //! Slot called when vtk wants to know if the context is current
    virtual void IsCurrent(vtkObject* caller, unsigned long vtk_event, void* client_data, void* call_data);
    //! Slot called when vtk wants to frame the window
    virtual void Frame();
    //! Slot called when vtk wants to start the render
    virtual void Start();
    //! Slot called when vtk wants to end the render
    virtual void End();
    //! Slot called when vtk wants to know if a window is direct
    virtual void IsDirect(vtkObject* caller, unsigned long vtk_event, void* client_data, void* call_data);
    //! Slot called when vtk wants to know if a window supports OpenGL
    virtual void SupportsOpenGL(vtkObject* caller, unsigned long vtk_event, void* client_data, void* call_data);

protected:
    //! Initialize handler
    virtual void initializeGL();
    //! Paint handler
    virtual void paintGL();
    //! Resize handler
    virtual void resizeGL(int, int);
    //! Move handler
    virtual void moveEvent(QMoveEvent* event);

    virtual void mousePressEvent(QMouseEvent* event);
    virtual void mouseMoveEvent(QMouseEvent* event);
    virtual void mouseReleaseEvent(QMouseEvent* event);
    virtual void keyPressEvent(QKeyEvent* event);
    virtual void keyReleaseEvent(QKeyEvent* event);
    virtual void enterEvent(QEvent*);
    virtual void leaveEvent(QEvent*);
    virtual void wheelEvent(QWheelEvent*);

    virtual void contextMenuEvent(QContextMenuEvent*);
    virtual void dragEnterEvent(QDragEnterEvent*);
    virtual void dragMoveEvent(QDragMoveEvent*);
    virtual void dragLeaveEvent(QDragLeaveEvent*);
    virtual void dropEvent(QDropEvent*);

    virtual bool focusNextPrevChild(bool);

    // Members
    vtkGenericOpenGLRenderWindow* m_renWin;
    QVTKInteractorAdapter* m_irenAdapter;
    vtkSmartPointer<vtkEventQtSlotConnect> m_connect;

private:
    //! unimplemented operator=
    QVTKWidget3 const& operator=(QVTKWidget3 const&);
    //! unimplemented copy
    QVTKWidget3(const QVTKWidget3&);
};

#endif // QVTKWIDGET3_H
