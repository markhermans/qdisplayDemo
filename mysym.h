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

    void toggleSelect();
    bool isSelected();

    int SymID;
    bool Pressed;
    bool Selected;
    
protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
};

#endif // MYSYM_H
