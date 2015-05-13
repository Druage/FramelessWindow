#include "framelesswindow.h"

#include <QDebug>
#include <QtMath>

FramelessWindow::FramelessWindow()
    : mousePressed( false )
{

    setFlags( Qt::FramelessWindowHint
              | Qt::MacWindowToolBarButtonHint
              | Qt::WindowMinimizeButtonHint
              | Qt::WindowMaximizeButtonHint );
}

FramelessWindow::~FramelessWindow()
{

}

void FramelessWindow::mouseMoveEvent( QMouseEvent *event )
{
    if ( mousePressed ) {

        QPoint newPoint( x() + ( event->x() - clickPosition.x() ), y() + ( event->y() - clickPosition.y() ) );
        setPosition(newPoint);
    }

    QQuickWindow::mouseMoveEvent( event );

}

void FramelessWindow::mouseReleaseEvent( QMouseEvent *event )
{
    mousePressed = false;

    QQuickWindow::mouseReleaseEvent( event );
}

void FramelessWindow::mousePressEvent( QMouseEvent *event )
{

    mousePressed = true;

    clickPosition.setX( event->x() );
    clickPosition.setY( event->y() );



    QQuickWindow::mousePressEvent( event );
}
