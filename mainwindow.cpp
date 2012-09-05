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

int selected_textID = 0;
int selected_symID = 0;

MainWindow::MainWindow(QWidget *parent)
    : QDialog(parent)
{
    int baseX, baseY;
    int offsetX, offsetY;

    qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));

    threadA.someMethod();

    QGraphicsPixmapItem *bg = new QGraphicsPixmapItem(QPixmap(":/images/background_blk.jpg"));
    QGraphicsPixmapItem *fg = new QGraphicsPixmapItem(QPixmap(":/images/adi_360_480.jpg"));
    MyText *t1_T   = new MyText("QRST");
    MyText *t2_T   = new MyText("QRST");
    MyText *t3_T   = new MyText("QRST");
    MyText *t4_T   = new MyText("QRST");
    MyText *t5_T   = new MyText("QRST");

    MyText *t1_L   = new MyText("ABCD");
    MyText *t2_L   = new MyText("ABCD");
    MyText *t3_L   = new MyText("ABCD");
    MyText *t4_L   = new MyText("ABCD");
    MyText *t5_L   = new MyText("ABCD");
    MyText *t6_L   = new MyText("ABCD");
    MyText *t7_L   = new MyText("ABCD");
    MyText *t8_L   = new MyText("ABCD");
    MyText *t9_L   = new MyText("ABCD");
    MyText *t10_L  = new MyText("ABCD");

    MyText *t1_B   = new MyText("UVWX");
    MyText *t2_B   = new MyText("UVWX");
    MyText *t3_B   = new MyText("UVWX");
    MyText *t4_B   = new MyText("UVWX");
    MyText *t5_B   = new MyText("UVWX");

    MyText *t1_R   = new MyText("IJKL");
    MyText *t2_R   = new MyText("IJKL");
    MyText *t3_R   = new MyText("IJKL");
    MyText *t4_R   = new MyText("IJKL");
    MyText *t5_R   = new MyText("IJKL");
    MyText *t6_R   = new MyText("IJKL");
    MyText *t7_R   = new MyText("IJKL");
    MyText *t8_R   = new MyText("IJKL");
    MyText *t9_R   = new MyText("IJKL");
    MyText *t10_R  = new MyText("IJKL");


    MySym *sym1 = new MySym(1);
    MySym *sym2 = new MySym(2);
    MySym *sym3 = new MySym(3);
    sym1->setSelected(true);
    sym2->setSelected(false);
    sym3->setSelected(false);

    scene = new QGraphicsScene;
    scene->setItemIndexMethod(QGraphicsScene::NoIndex);
    scene->addItem(bg);     // 0
    scene->addItem(fg);     // 1
    scene->addItem(t1_T);   // 2 - 6
    scene->addItem(t2_T);
    scene->addItem(t3_T);
    scene->addItem(t4_T);
    scene->addItem(t5_T);

    scene->addItem(t1_L);   // 7 - 16
    scene->addItem(t2_L);
    scene->addItem(t3_L);
    scene->addItem(t4_L);   // 10
    scene->addItem(t5_L);   // 11
    scene->addItem(t6_L);   // 12
    scene->addItem(t7_L);
    scene->addItem(t8_L);
    scene->addItem(t9_L);
    scene->addItem(t10_L);

    scene->addItem(t1_B);   // 17 - 21
    scene->addItem(t2_B);
    scene->addItem(t3_B);
    scene->addItem(t4_B);
    scene->addItem(t5_B);

    scene->addItem(t1_R);   // 22 - 31
    scene->addItem(t2_R);
    scene->addItem(t3_R);
    scene->addItem(t4_R);
    scene->addItem(t5_R);
    scene->addItem(t6_R);
    scene->addItem(t7_R);
    scene->addItem(t8_R);
    scene->addItem(t9_R);
    scene->addItem(t10_R);

    scene->addItem(sym1);   // 32 - 34
    scene->addItem(sym2);
    scene->addItem(sym3);


    view = new QGraphicsView(scene);
    view->setRenderHint(QPainter::Antialiasing);
    view->setCacheMode(QGraphicsView::CacheBackground);
    view->setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
    view->setDragMode(QGraphicsView::ScrollHandDrag);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);


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
    connect(moveRotateAction, SIGNAL(triggered()), this, SLOT(doMoveRotate()));
    moveRotateButton->addAction(moveRotateAction);

    QPushButton *moveLeftButton = new QPushButton("<-");
    QAction *moveLeftAction = new QAction(tr("<-"), this);
    moveLeftAction->setShortcut(tr("o"));
    connect(moveLeftAction, SIGNAL(triggered()), this, SLOT(doMoveLeft()));
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
    connect(moveUpAction, SIGNAL(triggered()), this, SLOT(doMoveUp()));
    moveUpButton->addAction(moveUpAction);

    QPushButton *moveRightButton = new QPushButton("->");
    QAction *moveRightAction = new QAction(tr("->"), this);
    moveRightAction->setShortcut(tr("b"));
    connect(moveRightAction, SIGNAL(triggered()), this, SLOT(doMoveRight()));
    moveRightButton->addAction(moveRightAction);

    QPushButton *moveDownButton = new QPushButton("V");
    QAction *moveDownAction = new QAction(tr("V"), this);
    moveDownAction->setShortcut(Qt::Key_Down);
    connect(moveDownAction, SIGNAL(triggered()), this, SLOT(doMoveDown()));
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

    fg->setPos(100,125);

    // top labels
    baseX = 75;
    baseY = 25;
    offsetX = 88;
    t1_T->setPos(baseX, baseY);
    t2_T->setPos(baseX+offsetX, baseY);
    t3_T->setPos(baseX+2*offsetX, baseY);
    t4_T->setPos(baseX+3*offsetX, baseY);
    t5_T->setPos(baseX+4*offsetX, baseY);

    // left side labels
    baseX = 0;
    baseY = 112; //100;
    offsetY = 52; //61;
    t1_L->setPos(baseX, baseY);
    t2_L->setPos(baseX, baseY + offsetY);
    t3_L->setPos(baseX, baseY + 2*offsetY);
    t4_L->setPos(baseX, baseY + 3*offsetY);
    t5_L->setPos(baseX, baseY + 4*offsetY);
    t6_L->setPos(baseX, baseY + 5*offsetY);
    t7_L->setPos(baseX, baseY + 6*offsetY);
    t8_L->setPos(baseX, baseY + 7*offsetY);
    t9_L->setPos(baseX, baseY + 8*offsetY);
    t10_L->setPos(baseX, baseY + 9*offsetY);

    // bottom labels
    baseX = 75;
    baseY = 660; //685;
    offsetX = 88;
    t1_B->setPos(baseX, baseY);
    t2_B->setPos(baseX+offsetX, baseY);
    t3_B->setPos(baseX+2*offsetX, baseY);
    t4_B->setPos(baseX+3*offsetX, baseY);
    t5_B->setPos(baseX+4*offsetX, baseY);

    // right side labels
    baseX = 514;
    baseY = 112;
    offsetY = 52;
    t1_R->setPos(baseX, baseY);
    t2_R->setPos(baseX, baseY + offsetY);
    t3_R->setPos(baseX, baseY + 2*offsetY);
    t4_R->setPos(baseX, baseY + 3*offsetY);
    t5_R->setPos(baseX, baseY + 4*offsetY);
    t6_R->setPos(baseX, baseY + 5*offsetY);
    t7_R->setPos(baseX, baseY + 6*offsetY);
    t8_R->setPos(baseX, baseY + 7*offsetY);
    t9_R->setPos(baseX, baseY + 8*offsetY);
    t10_R->setPos(baseX, baseY + 9*offsetY);

    sym1->setPos(250,250);
    sym2->setPos(300,300);
    sym3->setPos(325,225);

//    fg->rotate(53.13);
//    fg->setPos(384,12);

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


void MainWindow::doSymbolSelect()
{
    QList<QGraphicsItem *> syms = scene->items();

    MySym  *symItem1, *symItem2, *symItem3;
    symItem1 = (MySym *)syms[32];
    symItem2 = (MySym *)syms[33];
    symItem3 = (MySym *)syms[34];

    if (symItem1->isSelected())
    {
        symItem1->setSelected(false);
        symItem2->setSelected(true);
    }
    else if (symItem2->isSelected())
    {
        symItem2->setSelected(false);
        symItem3->setSelected(true);
    }
    else
    {
        symItem3->setSelected(false);
        symItem1->setSelected(true);
    }
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

void MainWindow::doMoveRotate()
{
    QList<QGraphicsItem *> syms = scene->items();

    MySym  *symItem1, *symItem2, *symItem3;
    symItem1 = (MySym *)syms[32];
    symItem2 = (MySym *)syms[33];
    symItem3 = (MySym *)syms[34];

    if (symItem1->isSelected())
        symItem1->moveRotate();
    if (symItem2->isSelected())
        symItem2->moveRotate();
    if (symItem3->isSelected())
        symItem3->moveRotate();
}

void MainWindow::doMoveLeft()
{
    QList<QGraphicsItem *> syms = scene->items();

    MySym  *symItem1, *symItem2, *symItem3;
    symItem1 = (MySym *)syms[32];
    symItem2 = (MySym *)syms[33];
    symItem3 = (MySym *)syms[34];

    if (symItem1->isSelected())
        symItem1->moveLeft();
    if (symItem2->isSelected())
        symItem2->moveLeft();
    if (symItem3->isSelected())
        symItem3->moveLeft();
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

void MainWindow::doMoveUp()
{
    QList<QGraphicsItem *> syms = scene->items();

    MySym  *symItem1, *symItem2, *symItem3;
    symItem1 = (MySym *)syms[32];
    symItem2 = (MySym *)syms[33];
    symItem3 = (MySym *)syms[34];

    if (symItem1->isSelected())
        symItem1->moveUp();
    if (symItem2->isSelected())
        symItem2->moveUp();
    if (symItem3->isSelected())
        symItem3->moveUp();
}

void MainWindow::doMoveRight()
{
    QList<QGraphicsItem *> syms = scene->items();

    MySym  *symItem1, *symItem2, *symItem3;
    symItem1 = (MySym *)syms[32];
    symItem2 = (MySym *)syms[33];
    symItem3 = (MySym *)syms[34];

    if (symItem1->isSelected())
        symItem1->moveRight();
    if (symItem2->isSelected())
        symItem2->moveRight();
    if (symItem3->isSelected())
        symItem3->moveRight();
}

void MainWindow::doMoveDown()
{
    QList<QGraphicsItem *> syms = scene->items();

    MySym  *symItem1, *symItem2, *symItem3;
    symItem1 = (MySym *)syms[32];
    symItem2 = (MySym *)syms[33];
    symItem3 = (MySym *)syms[34];

    if (symItem1->isSelected())
        symItem1->moveDown();
    if (symItem2->isSelected())
        symItem2->moveDown();
    if (symItem3->isSelected())
        symItem3->moveDown();
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
    if (evt->key() != Qt::Key_Up)
    {
        QWidget::keyReleaseEvent(evt);
        return;
    }

    doSymbolSelect();
}
