/****************************************************************************
****************************************************************************/

#include <QtGui>
#include <iostream>
#include <math.h>

#include "mainwindow.h"
#include "mThread.h"

MainWindow::MainWindow(QWidget *parent)
    : QDialog(parent)
{
    qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));

    threadA.someMethod();

    QGraphicsPixmapItem *bg = new QGraphicsPixmapItem(QPixmap(":/images/plane.jpg"));
    QGraphicsPixmapItem *fg = new QGraphicsPixmapItem(QPixmap(":/images/gimp.jpg"));
    QGraphicsPixmapItem *fg2 = new QGraphicsPixmapItem(QPixmap(":/images/gimp.jpg"));

    scene = new QGraphicsScene;
    scene->setItemIndexMethod(QGraphicsScene::NoIndex);
    scene->addItem(bg);
    scene->addItem(fg);
    scene->addItem(fg2);

    view = new QGraphicsView(scene);
    view->setRenderHint(QPainter::Antialiasing);
    view->setCacheMode(QGraphicsView::CacheBackground);
    view->setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
    view->setDragMode(QGraphicsView::ScrollHandDrag);

    moveButton = new QPushButton(tr("&Move"));
    connect(moveButton, SIGNAL(clicked()), this, SLOT(move()));

    threadButton = new QPushButton(tr("&Start Thread"));
    connect(threadButton, SIGNAL(clicked()), this, SLOT(startOrStopThread()));

    closeButton = new QPushButton(tr("&Close"));
    connect(closeButton, SIGNAL(clicked()), this, SLOT(close()));

    QHBoxLayout *hlayout = new QHBoxLayout;
    hlayout->addWidget(moveButton);
    hlayout->addWidget(threadButton);
    hlayout->addWidget(closeButton);

    QVBoxLayout *vlayout = new QVBoxLayout;
    vlayout->addWidget(view);
    vlayout->addLayout(hlayout);
    setLayout(vlayout);

    timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer->start(1000/33);

    setWindowTitle(tr("A Dialog"));
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    threadA.stop();
    threadA.wait();
    event->accept();
}

void MainWindow::about()
{
   QMessageBox::about(this, tr("About Application"),
            tr("The <b>Application</b> example demonstrates how to "
               "write modern GUI applications using Qt, with a menu bar, "
               "toolbars, and a status bar."));
}

void MainWindow::move()
{
    QList<QGraphicsItem *> syms = scene->items();

    QPointF pos1 = syms[1]->scenePos();
    float dx = float(qrand() % 11)/10.0;
    float dy = float(qrand() % 18)/10.0;
    syms[1]->setPos(pos1.rx()+dx,pos1.ry()+dy);

    QPointF pos2 = syms[2]->scenePos();
    float dx2 = float(qrand() % 12)/10.0;
    float dy2 = float(qrand() % 9)/10.0;
    syms[2]->setPos(pos2.rx()+dx2,pos2.ry()+dy2);
}

void MainWindow::startOrStopThread()
{
    if (threadA.isRunning())
    {
        threadA.stop();
        threadButton->setText(tr("Start Thread"));
    }
    else
    {
        threadA.start();
        threadButton->setText(tr("Stop Thread"));
    }
}
