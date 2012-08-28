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

    moveButton = new QPushButton(tr("&Move"));
    connect(moveButton, SIGNAL(clicked()), this, SLOT(move()));

    threadButton = new QPushButton(tr("&Start Thread"));
    connect(threadButton, SIGNAL(clicked()), this, SLOT(startOrStopThread()));

    QVBoxLayout *vlayout = new QVBoxLayout;
    vlayout->addWidget(view);
    setLayout(vlayout);

    fg->setPos(100,125);

    // top labels
    baseX = 75;
    baseY = 0;
    offsetX = 88;
    t1_T->setPos(baseX, baseY);
    t2_T->setPos(baseX+offsetX, baseY);
    t3_T->setPos(baseX+2*offsetX, baseY);
    t4_T->setPos(baseX+3*offsetX, baseY);
    t5_T->setPos(baseX+4*offsetX, baseY);

    // left side labels
    baseX = 0;
    baseY = 78; //100;
    offsetY = 60; //61;
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
    baseY = 685;
    offsetX = 88;
    t1_B->setPos(baseX, baseY);
    t2_B->setPos(baseX+offsetX, baseY);
    t3_B->setPos(baseX+2*offsetX, baseY);
    t4_B->setPos(baseX+3*offsetX, baseY);
    t5_B->setPos(baseX+4*offsetX, baseY);

    // right side labels
    baseX = 514;
    baseY = 78;
    offsetY = 60;
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
    if ((evt->key() != 0x50) &&   // button 0
        (evt->key() != 0x4f) &&   // button 1
        (evt->key() != 0x4e) &&   // button 2
        (evt->key() != 0x49) &&   // button 5
        (evt->key() != 0x1000015) &&  // button 10
        (evt->key() != 0x42) &&       // button 11
        (evt->key() != 0x41) &&       // button 12
        (evt->key() != 0x1000014) &&  // button 13
        (evt->key() != 0x1000012))    // button 14
    {
        QWidget::keyReleaseEvent(evt);
        return;
    }

	if (evt->key() == 0x49)
	{
		MainWindow::close();
		return;
	}

    QList<QGraphicsItem *> syms = scene->items();

	MySym  *symItem1, *symItem2, *symItem3;
	symItem1 = (MySym *)syms[32];
	symItem2 = (MySym *)syms[33];
	symItem3 = (MySym *)syms[34];

    switch (evt->key())
    {
        case 0x50:
			symItem1->toggleSelect();
		break;
        case 0x4f:
			symItem2->toggleSelect();
		break;
        case 0x4e:
			symItem3->toggleSelect();
		break;
        case 0x1000015: // left
			if (symItem1->isSelected())
				symItem1->moveLeft();
			if (symItem2->isSelected())
				symItem2->moveLeft();
			if (symItem3->isSelected())
				symItem3->moveLeft();
		break;
        case 0x42:      // right
			if (symItem1->isSelected())
				symItem1->moveRight();
			if (symItem2->isSelected())
				symItem2->moveRight();
			if (symItem3->isSelected())
				symItem3->moveRight();
		break;
        case 0x41:      // up
			if (symItem1->isSelected())
				symItem1->moveUp();
			if (symItem2->isSelected())
				symItem2->moveUp();
			if (symItem3->isSelected())
				symItem3->moveUp();
		break;
        case 0x1000014: // down
			if (symItem1->isSelected())
				symItem1->moveDown();
			if (symItem2->isSelected())
				symItem2->moveDown();
			if (symItem3->isSelected())
				symItem3->moveDown();
		break;
        case 0x1000012: // rotate
			if (symItem1->isSelected())
				symItem1->moveRotate();
			if (symItem2->isSelected())
				symItem2->moveRotate();
			if (symItem3->isSelected())
				symItem3->moveRotate();
		break;

		default:
		   NULL;
    }
}
