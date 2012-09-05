/****************************************************************************
****************************************************************************/

#include <QtGui>
#include <QFont>
#include <iostream>
#include <math.h>

#include "targetScene.h"

TargetScene::TargetScene()
{
//    scene = new QGraphicsScene();

    bg = new QGraphicsPixmapItem(QPixmap(":/images/background_blk.jpg"));
    fg = new QGraphicsPixmapItem(QPixmap(":/images/adi_360_480.jpg"));

    t1_T   = new MyText("QRST");
    t2_T   = new MyText("QRST");
    t3_T   = new MyText("QRST");
    t4_T   = new MyText("QRST");
    t5_T   = new MyText("QRST");

    t1_L   = new MyText("ABCD");
    t2_L   = new MyText("ABCD");
    t3_L   = new MyText("ABCD");
    t4_L   = new MyText("ABCD");
    t5_L   = new MyText("ABCD");
    t6_L   = new MyText("ABCD");
    t7_L   = new MyText("ABCD");
    t8_L   = new MyText("ABCD");
    t9_L   = new MyText("ABCD");
    t10_L  = new MyText("ABCD");

    t1_B   = new MyText("UVWX");
    t2_B   = new MyText("UVWX");
    t3_B   = new MyText("UVWX");
    t4_B   = new MyText("UVWX");
    t5_B   = new MyText("UVWX");

    t1_R   = new MyText("IJKL");
    t2_R   = new MyText("IJKL");
    t3_R   = new MyText("IJKL");
    t4_R   = new MyText("IJKL");
    t5_R   = new MyText("IJKL");
    t6_R   = new MyText("IJKL");
    t7_R   = new MyText("IJKL");
    t8_R   = new MyText("IJKL");
    t9_R   = new MyText("IJKL");
    t10_R  = new MyText("IJKL");


    sym1 = new MySym(1);
    sym2 = new MySym(2);
    sym3 = new MySym(3);
    sym1->setSelected(true);
    sym2->setSelected(false);
    sym3->setSelected(false);

    this->setItemIndexMethod(QGraphicsScene::NoIndex);
    this->addItem(bg);     // 0
    this->addItem(fg);     // 1
    this->addItem(t1_T);   // 2 - 6
    this->addItem(t2_T);
    this->addItem(t3_T);
    this->addItem(t4_T);
    this->addItem(t5_T);

    this->addItem(t1_L);   // 7 - 16
    this->addItem(t2_L);
    this->addItem(t3_L);
    this->addItem(t4_L);   // 10
    this->addItem(t5_L);   // 11
    this->addItem(t6_L);   // 12
    this->addItem(t7_L);
    this->addItem(t8_L);
    this->addItem(t9_L);
    this->addItem(t10_L);

    this->addItem(t1_B);   // 17 - 21
    this->addItem(t2_B);
    this->addItem(t3_B);
    this->addItem(t4_B);
    this->addItem(t5_B);

    this->addItem(t1_R);   // 22 - 31
    this->addItem(t2_R);
    this->addItem(t3_R);
    this->addItem(t4_R);
    this->addItem(t5_R);
    this->addItem(t6_R);
    this->addItem(t7_R);
    this->addItem(t8_R);
    this->addItem(t9_R);
    this->addItem(t10_R);

    this->addItem(sym1);   // 32 - 34
    this->addItem(sym2);
    this->addItem(sym3);
}

void TargetScene::initialize()
{
    int baseX, baseY;
    int offsetX, offsetY;

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
}


void TargetScene::doSymbolSelect()
{
    QList<QGraphicsItem *> syms = this->items();

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


void TargetScene::moveLeft()
{
    QList<QGraphicsItem *> syms = this->items();

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

void TargetScene::moveRight()
{
    QList<QGraphicsItem *> syms = this->items();

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

void TargetScene::moveUp()
{
    QList<QGraphicsItem *> syms = this->items();

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

void TargetScene::moveDown()
{
    QList<QGraphicsItem *> syms = this->items();

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

void TargetScene::moveRotate()
{
    QList<QGraphicsItem *> syms = this->items();

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
