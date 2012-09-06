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
#include "bootScene.h"
#include "mapScene.h"

int selected_textID = 0;
int selected_symID = 0;
bool isTargetSelectVisible = true;
bool isVideoBootVisible = false;
bool isShowMapVisible = false;
bool isFlightVideoVisible = false;

MainWindow::MainWindow(QWidget *parent)
    : QDialog(parent)
{
    qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));

    threadA.someMethod();

    TargetScene *scene = new TargetScene();
    BootScene *scene_videoBoot = new BootScene(this, "./file.mp4");
    MapScene *scene_mapShow = new MapScene("./file.jpg");

    view = new QGraphicsView(scene);
    view->setRenderHint(QPainter::Antialiasing);
    view->setCacheMode(QGraphicsView::CacheBackground);
    view->setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
    view->setDragMode(QGraphicsView::ScrollHandDrag);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    printf("target select size: %f x %f\n", view->sceneRect().width(), view->sceneRect().height());

    videoBoot_view = new QGraphicsView(scene_videoBoot);
    videoBoot_view->setRenderHint(QPainter::Antialiasing);
    videoBoot_view->setCacheMode(QGraphicsView::CacheBackground);
    videoBoot_view->setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
    videoBoot_view->setDragMode(QGraphicsView::ScrollHandDrag);
    videoBoot_view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    videoBoot_view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    showMap_view = new QGraphicsView(scene_mapShow);
    showMap_view->setRenderHint(QPainter::Antialiasing);
    showMap_view->setCacheMode(QGraphicsView::CacheBackground);
    showMap_view->setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
    showMap_view->setDragMode(QGraphicsView::ScrollHandDrag);
    showMap_view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    showMap_view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

//    flightVideo_view = new QGraphicsView(scene_1);
//    flightVideo_view->setRenderHint(QPainter::Antialiasing);
//    flightVideo_view->setCacheMode(QGraphicsView::CacheBackground);
//    flightVideo_view->setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
//    flightVideo_view->setDragMode(QGraphicsView::ScrollHandDrag);
//    flightVideo_view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
//    flightVideo_view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    connect(this, SIGNAL(mainKeyPress()), scene, SLOT(doSymbolSelect()));
    connect(this, SIGNAL(playBootVideo()), scene_videoBoot, SLOT(play()));
    connect(this, SIGNAL(pauseBootVideo()), scene_videoBoot, SLOT(pause()));

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

    view->show();
    videoBoot_view->hide();
    showMap_view->hide();
//    flightVideo_view->hide();


    QHBoxLayout *hlayout = new QHBoxLayout;
    hlayout->addLayout(leftButtonGroup);
    hlayout->addWidget(view);
    hlayout->addWidget(videoBoot_view);
    hlayout->addWidget(showMap_view);
//    hlayout->addWidget(flightVideo_view);
    hlayout->addLayout(rightButtonGroup);
    setLayout(hlayout);

    scene->initialize();
    scene_videoBoot->initialize();

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
    if (isVideoBootVisible)
        return;

    if (isTargetSelectVisible)
    {
        view->hide();
        isTargetSelectVisible = false;
    }
    else if (isShowMapVisible)
    {
        showMap_view->hide();
        isShowMapVisible = false;
    }
    else // (isFlightVideoVisible)
    {
        flightVideo_view->hide();
        isFlightVideoVisible = false;
    }

    isVideoBootVisible = true;
    videoBoot_view->show();
    emit playBootVideo();
}

void MainWindow::doShowMap()
{
    if (isShowMapVisible)
        return;

    if (isVideoBootVisible)
    {
        videoBoot_view->hide();
        emit pauseBootVideo();
        isVideoBootVisible = false;
    }
    else if (isTargetSelectVisible)
    {
        view->hide();
        isTargetSelectVisible = false;
    }
    else // (isFlightVideoVisible)
    {
        flightVideo_view->hide();
        isFlightVideoVisible = false;
    }

    isShowMapVisible = true;
    showMap_view->show();
}


// right buttons
void MainWindow::doTargetSelect()
{
    if (isTargetSelectVisible)
        return;

    if (isVideoBootVisible)
    {
        videoBoot_view->hide();
        emit pauseBootVideo();
        isVideoBootVisible = false;
    }
    else if (isShowMapVisible)
    {
        showMap_view->hide();
        isShowMapVisible = false;
    }
    else // (isFlightVideoVisible)
    {
        flightVideo_view->hide();
        isFlightVideoVisible = false;
    }

    isTargetSelectVisible = true;
    view->show();
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
