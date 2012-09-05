/****************************************************************************
****************************************************************************/

#ifndef TARGETSCENE_H
#define TARGETSCENE_H

#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QKeyEvent>

#include "mytext.h"
#include "mysym.h"

class TargetScene : public QGraphicsScene
{
    Q_OBJECT

public:
    TargetScene();

    void initialize();

private slots:
    void doSymbolSelect();
    void moveUp();
    void moveDown();
    void moveLeft();
    void moveRight();
    void moveRotate();

private:
//    QGraphicsScene *scene;
    QGraphicsPixmapItem *bg;
    QGraphicsPixmapItem *fg;

    MyText *t1_T;
    MyText *t2_T;
    MyText *t3_T;
    MyText *t4_T;
    MyText *t5_T;

    MyText *t1_L;
    MyText *t2_L;
    MyText *t3_L;
    MyText *t4_L;
    MyText *t5_L;
    MyText *t6_L;
    MyText *t7_L;
    MyText *t8_L;
    MyText *t9_L;
    MyText *t10_L;

    MyText *t1_B;
    MyText *t2_B;
    MyText *t3_B;
    MyText *t4_B;
    MyText *t5_B;

    MyText *t1_R;
    MyText *t2_R;
    MyText *t3_R;
    MyText *t4_R;
    MyText *t5_R;
    MyText *t6_R;
    MyText *t7_R;
    MyText *t8_R;
    MyText *t9_R;
    MyText *t10_R;

	MySym *sym1;
	MySym *sym2;
	MySym *sym3;
};

#endif
