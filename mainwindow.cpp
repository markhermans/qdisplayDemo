/****************************************************************************
****************************************************************************/

#include <QtGui>
#include <QFont>
#include <iostream>
#include <math.h>

#include "mainwindow.h"
#include "mThread.h"
#include "mytext.h"
#include "mysym.h"
#include "targetScene.h"

int selected_textID = 0;
int selected_symID = 0;

MainWindow::MainWindow(QWidget *parent)
    : QDialog(parent)
{
    qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));

    threadA.someMethod();

    TargetScene *scene = new TargetScene();

    view = new QGraphicsView(scene);
    view->setRenderHint(QPainter::Antialiasing);
    view->setCacheMode(QGraphicsView::CacheBackground);
    view->setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
    view->setDragMode(QGraphicsView::ScrollHandDrag);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    connect(this, SIGNAL(mainKeyPress()), scene, SLOT(doSymbolSelect()));

    // left button group
    QPushButton *videoBootButton = new QPushButton("1");
    QAction *videoBootAction = new QAction(tr("1"), this);
    videoBootAction->setShortcut(tr("j"));
    connect(videoBootAction, SIGNAL(triggered()), this, SLOT(doVideoBoot()));
    videoBootButton->addAction(videoBootAction);

    QPushButton *showMapButton = new QPushButton("3");
    QAction *showMapAction = new QAction(tr("3"), this);
    showMapAction->setShortcut(tr("k"));
    connect(showMapAction, SIGNAL(triggered()), this, SLOT(doShowMap()));
    showMapButton->addAction(showMapAction);

    QPushButton *moveRotateButton = new QPushButton("Ro");
    QAction *moveRotateAction = new QAction(tr("Ro"), this);
    moveRotateAction->setShortcut(tr("n"));
    connect(moveRotateAction, SIGNAL(triggered()), scene, SLOT(moveRotate()));
    moveRotateButton->addAction(moveRotateAction);

    QPushButton *moveLeftButton = new QPushButton("<-");
    QAction *moveLeftAction = new QAction(tr("<-"), this);
    moveLeftAction->setShortcut(tr("o"));
    connect(moveLeftAction, SIGNAL(triggered()), scene, SLOT(moveLeft()));
    moveLeftButton->addAction(moveLeftAction);

    QPushButton *exitAppButton = new QPushButton("Exit");
    QAction *exitAppAction = new QAction(tr("Exit"), this);
    exitAppAction->setShortcut(tr("p"));
    connect(exitAppAction, SIGNAL(triggered()), this, SLOT(close()));
    exitAppButton->addAction(exitAppAction);

    QVBoxLayout *leftButtonGroup = new QVBoxLayout;
    leftButtonGroup->addWidget(videoBootButton);
    leftButtonGroup->addWidget(showMapButton);
    leftButtonGroup->addWidget(moveRotateButton);
    leftButtonGroup->addWidget(moveLeftButton);
    leftButtonGroup->addWidget(exitAppButton);


    // right button group
    QPushButton *targetSelectButton = new QPushButton("2");
    QAction *targetSelectAction = new QAction(tr("2"), this);
    targetSelectAction->setShortcut(Qt::Key_Left);
    connect(targetSelectAction, SIGNAL(triggered()), this, SLOT(doTargetSelect()));
    targetSelectButton->addAction(targetSelectAction);

    QPushButton *flightVideoButton = new QPushButton("4");
    QAction *flightVideoAction = new QAction(tr("4"), this);
    flightVideoAction->setShortcut(Qt::Key_Right);
    connect(flightVideoAction, SIGNAL(triggered()), this, SLOT(doFlightVideo()));
    flightVideoButton->addAction(flightVideoAction);

    QPushButton *moveUpButton = new QPushButton("^");
    QAction *moveUpAction = new QAction(tr("^"), this);
    moveUpAction->setShortcut(tr("a"));
    connect(moveUpAction, SIGNAL(triggered()), scene, SLOT(moveUp()));
    moveUpButton->addAction(moveUpAction);

    QPushButton *moveRightButton = new QPushButton("->");
    QAction *moveRightAction = new QAction(tr("->"), this);
    moveRightAction->setShortcut(tr("b"));
    connect(moveRightAction, SIGNAL(triggered()), scene, SLOT(moveRight()));
    moveRightButton->addAction(moveRightAction);

    QPushButton *moveDownButton = new QPushButton("V");
    QAction *moveDownAction = new QAction(tr("V"), this);
    moveDownAction->setShortcut(Qt::Key_Down);
    connect(moveDownAction, SIGNAL(triggered()), scene, SLOT(moveDown()));
    moveDownButton->addAction(moveDownAction);

    QVBoxLayout *rightButtonGroup = new QVBoxLayout;
    rightButtonGroup->addWidget(targetSelectButton);
    rightButtonGroup->addWidget(flightVideoButton);
    rightButtonGroup->addWidget(moveUpButton);
    rightButtonGroup->addWidget(moveRightButton);
    rightButtonGroup->addWidget(moveDownButton);


//    connect(moveButton, SIGNAL(clicked()), this, SLOT(move()));

    threadButton = new QPushButton(tr("&Start Thread"));
    connect(threadButton, SIGNAL(clicked()), this, SLOT(startOrStopThread()));

    QHBoxLayout *hlayout = new QHBoxLayout;
    hlayout->addLayout(leftButtonGroup);
    hlayout->addWidget(view);
    hlayout->addLayout(rightButtonGroup);
    setLayout(hlayout);

    scene->initialize();

//    timer = new QTimer();
//    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
//    timer->start(100);

    setWindowTitle(tr("A Dialog"));
    QRect myGeometry = this->geometry();
    this->setGeometry(
	myGeometry.x()+325,
	myGeometry.y()+30,
	myGeometry.width(),
	myGeometry.height()+200);
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


// left buttons
void MainWindow::doVideoBoot()
{
    printf("video boot\n");
}

void MainWindow::doShowMap()
{
    printf("show map\n");
}


// right buttons
void MainWindow::doTargetSelect()
{
    printf("target select\n");
}

void MainWindow::doFlightVideo()
{
    printf("flight video\n");
}



void MainWindow::move()
{
    QList<QGraphicsItem *> syms = scene->items();

    printf("have %d items\n", syms.count());

    syms[0]->setSelected(true);

    // interested in text symbols 10-12
    if (syms[10]->isSelected())
    {
        selected_textID = 10;
        selected_symID = 32;
//        sym1->setSelected(true);
    }
    else if (syms[11]->isSelected())
    {
        selected_textID = 11;
        selected_symID = 33;
//        sym2->setSelected(true);
    }
    else if (syms[12]->isSelected())
    {
        selected_textID = 12;
        selected_symID = 34;
//        sym3->setSelected(true);
    }

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

void MainWindow::keyPressEvent(QKeyEvent *evt)
{
    QWidget::keyPressEvent(evt);
}

void MainWindow::keyReleaseEvent(QKeyEvent *evt)
{
    if (evt->key() == Qt::Key_Up)
        emit mainKeyPress();
}
