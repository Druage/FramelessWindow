#ifndef FRAMELESSWINDOW_H
#define FRAMELESSWINDOW_H

#include <QQuickWindow>
#include <QPoint>
#include <QDebug>


class Test : public QObject {
    Q_OBJECT
public:
    Test() {}
    ~Test() {}

public slots:
    void handleRefreshRate( qreal rate )
    {
        qDebug() << rate;
    }
};

class FramelessWindow : public QQuickWindow
{
    QPoint clickPosition;
    bool mousePressed;

public:
    FramelessWindow();
    ~FramelessWindow();

private:
    void mousePressEvent( QMouseEvent *event );
    void mouseReleaseEvent( QMouseEvent *event );
    void mouseMoveEvent( QMouseEvent *event );
};

#endif // FRAMELESSWINDOW_H
