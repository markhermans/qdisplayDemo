#include "mysym.h"
#include "stdio.h"

MySym::MySym(int id)
{
    SymID = id;
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

void MySym::toggleSelect()
{
    Selected = (Selected == true)?false:true;
    update();
}

bool MySym::isSelected()
{
    return Selected;
}

void MySym::moveLeft()
{
	QPointF pos;

	pos = this->pos();
	this->setPos(pos.rx()-10, pos.ry());
}

void MySym::moveRight()
{
	QPointF pos;

	pos = this->pos();
	this->setPos(pos.rx()+10, pos.ry());
}

void MySym::moveUp()
{
	QPointF pos;

	pos = this->pos();
	this->setPos(pos.rx(), pos.ry()-10);
}

void MySym::moveDown()
{
	QPointF pos;

	pos = this->pos();
	this->setPos(pos.rx(), pos.ry()+10);
}

void MySym::moveRotate()
{
	QPointF pos;

	pos = this->pos();
	this->rotate(15);
}
