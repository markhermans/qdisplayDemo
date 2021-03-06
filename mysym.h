#ifndef MYSYM_H
#define MYSYM_H

#include <QPainter>
#include <QGraphicsItem>

class MySym : public QGraphicsItem
{
public:
    MySym(int id = 0);

    QRectF boundingRect()const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    void setSelected(bool selected);
    void toggleSelect();
    bool isSelected();
    void moveLeft();
    void moveRight();
    void moveUp();
    void moveDown();
    void moveRotate();

    int SymID;
    bool Selected;
};

#endif // MYSYM_H
