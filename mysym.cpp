#include "mysym.h"
#include "stdio.h"

MySym::MySym(int id)
{
    SymID = id;
    Pressed = false;
    Selected = false;
//    setFlag(QGraphicsItem::ItemIsSelectable);
}

QRectF MySym::boundingRect() const
{
    return QRectF(0,0,27,27);
}

void MySym::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QRectF rec = boundingRect();
    QBrush brush(Qt::blue);

    if (Selected)
    {
        brush.setColor(QColor(255,0,0,255));
    }
    else
    {
        brush.setColor(QColor(255,0,0,40));
    }
    painter->fillRect(rec,brush);
    if (SymID == 1)
    {
        painter->drawText(10,17,"1");

    }
    else if (SymID == 2)
    {
        painter->drawText(10,17,"2");

    }
    else
    {
        painter->drawText(10,17,"3");
    }
    painter->drawRect(rec);
}

void MySym::setSelected(bool select)
{
    Selected = select;
    update();
}

bool MySym::isSelected()
{
    return Selected;
}

void MySym::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    Pressed = true;
    update();
    QGraphicsItem::mousePressEvent(event);
}

void MySym::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    Pressed = false;
    update();
    QGraphicsItem::mouseReleaseEvent(event);
}
