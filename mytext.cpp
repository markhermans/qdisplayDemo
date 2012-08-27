#include "mytext.h"
#include "stdio.h"
#include <QFont>
#include <QPointF>

MyText::MyText(const QString &text, int pixelSize)
{
    QFont f1;

    SymbolRef1 = (MySym*)NULL;
    SymbolRef2 = (MySym*)NULL;
    SymbolRef3 = (MySym*)NULL;
    SymbolSelector = false;
    SymbolMover    = false;
    Action = 0; // no action

    f1.setFamily("Courier");
    f1.setPixelSize(pixelSize);
    setPlainText(text);
    setFont(f1);
    setFlags(QGraphicsItem::ItemIsSelectable);

    Pressed = false;
    Selected = false;
    DefaultTextColor = QColor(255,255,255,255);
    setDefaultTextColor(QColor(255,255,255,255));
}

void MyText::setSelected(bool select)
{
    Selected = select;
}

void MyText::setSymbol(MySym *sym1, MySym *sym2, MySym *sym3)
{
    SymbolRef1 = sym1;
    SymbolRef2 = sym2;
    SymbolRef3 = sym3;
}

void MyText::setSymbolSelector(bool selector)
{
    SymbolSelector = selector;
}

void MyText::setSymbolMover(bool mover)
{
    SymbolMover = mover;
}

void MyText::setAction(int action)
{
    Action = action;
}

bool MyText::isSelected()
{
    return Selected;
}

void MyText::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    Pressed = true;
    if (SymbolMover && Action != 0)
    {
        if (Action == 1) // left
        {
            QPointF pos;
            if (SymbolRef1->isSelected())
            {
                pos = SymbolRef1->pos();
                SymbolRef1->setPos(pos.rx()-10, pos.ry());
            }
            if (SymbolRef2->isSelected())
            {
                pos = SymbolRef2->pos();
                SymbolRef2->setPos(pos.rx()-10, pos.ry());
            }
            if (SymbolRef3->isSelected())
            {
                pos = SymbolRef3->pos();
                SymbolRef3->setPos(pos.rx()-10, pos.ry());
            }
        }
        if (Action == 2) // right
        {
            QPointF pos;
            if (SymbolRef1->isSelected())
            {
                pos = SymbolRef1->pos();
                SymbolRef1->setPos(pos.rx()+10, pos.ry());
            }
            if (SymbolRef2->isSelected())
            {
                pos = SymbolRef2->pos();
                SymbolRef2->setPos(pos.rx()+10, pos.ry());
            }
            if (SymbolRef3->isSelected())
            {
                pos = SymbolRef3->pos();
                SymbolRef3->setPos(pos.rx()+10, pos.ry());
            }
        }
        if (Action == 3) // up
        {
            QPointF pos;
            if (SymbolRef1->isSelected())
            {
                pos = SymbolRef1->pos();
                SymbolRef1->setPos(pos.rx(), pos.ry()-10);
            }
            if (SymbolRef2->isSelected())
            {
                pos = SymbolRef2->pos();
                SymbolRef2->setPos(pos.rx(), pos.ry()-10);
            }
            if (SymbolRef3->isSelected())
            {
                pos = SymbolRef3->pos();
                SymbolRef3->setPos(pos.rx(), pos.ry()-10);
            }
        }
        if (Action == 4) // down
        {
            QPointF pos;
            if (SymbolRef1->isSelected())
            {
                pos = SymbolRef1->pos();
                SymbolRef1->setPos(pos.rx(), pos.ry()+10);
            }
            if (SymbolRef2->isSelected())
            {
                pos = SymbolRef2->pos();
                SymbolRef2->setPos(pos.rx(), pos.ry()+10);
            }
            if (SymbolRef3->isSelected())
            {
                pos = SymbolRef3->pos();
                SymbolRef3->setPos(pos.rx(), pos.ry()+10);
            }
        }
        if (Action == 5) // rotate
        {
            QPointF pos;
            if (SymbolRef1->isSelected())
            {
                pos = SymbolRef1->pos();
                SymbolRef1->rotate(15);
            }
            if (SymbolRef2->isSelected())
            {
                pos = SymbolRef2->pos();
                SymbolRef2->rotate(15);
            }
            if (SymbolRef3->isSelected())
            {
                pos = SymbolRef3->pos();
                SymbolRef3->rotate(15);
            }
        }
    }
    update();
    QGraphicsTextItem::mousePressEvent(event);
}

void MyText::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    printf("mytext: mouse release\n");
    Pressed = false;
    if (!SymbolSelector)
    {
        update();
        QGraphicsTextItem::mouseReleaseEvent(event);
        return;
    }

    if (Selected)
    {
        Selected = false;
        setDefaultTextColor(QColor(255,255,255,255));
    }
    else
    {
        Selected = true;
        setDefaultTextColor(QColor(0,255,0,255));
    }

    if (SymbolRef1 && SymbolSelector)
        SymbolRef1->setSelected(Selected);

    update();
    QGraphicsTextItem::mouseReleaseEvent(event);
}

void MyText::doPressTxt()
{
    Pressed = true;
    if (SymbolMover && Action != 0)
    {
        if (Action == 1) // left
        {
            QPointF pos;
            if (SymbolRef1->isSelected())
            {
                pos = SymbolRef1->pos();
                SymbolRef1->setPos(pos.rx()-10, pos.ry());
            }
            if (SymbolRef2->isSelected())
            {
                pos = SymbolRef2->pos();
                SymbolRef2->setPos(pos.rx()-10, pos.ry());
            }
            if (SymbolRef3->isSelected())
            {
                pos = SymbolRef3->pos();
                SymbolRef3->setPos(pos.rx()-10, pos.ry());
            }
        }
        if (Action == 2) // right
        {
            QPointF pos;
            if (SymbolRef1->isSelected())
            {
                pos = SymbolRef1->pos();
                SymbolRef1->setPos(pos.rx()+10, pos.ry());
            }
            if (SymbolRef2->isSelected())
            {
                pos = SymbolRef2->pos();
                SymbolRef2->setPos(pos.rx()+10, pos.ry());
            }
            if (SymbolRef3->isSelected())
            {
                pos = SymbolRef3->pos();
                SymbolRef3->setPos(pos.rx()+10, pos.ry());
            }
        }
        if (Action == 3) // up
        {
            QPointF pos;
            if (SymbolRef1->isSelected())
            {
                pos = SymbolRef1->pos();
                SymbolRef1->setPos(pos.rx(), pos.ry()-10);
            }
            if (SymbolRef2->isSelected())
            {
                pos = SymbolRef2->pos();
                SymbolRef2->setPos(pos.rx(), pos.ry()-10);
            }
            if (SymbolRef3->isSelected())
            {
                pos = SymbolRef3->pos();
                SymbolRef3->setPos(pos.rx(), pos.ry()-10);
            }
        }
        if (Action == 4) // down
        {
            QPointF pos;
            if (SymbolRef1->isSelected())
            {
                pos = SymbolRef1->pos();
                SymbolRef1->setPos(pos.rx(), pos.ry()+10);
            }
            if (SymbolRef2->isSelected())
            {
                pos = SymbolRef2->pos();
                SymbolRef2->setPos(pos.rx(), pos.ry()+10);
            }
            if (SymbolRef3->isSelected())
            {
                pos = SymbolRef3->pos();
                SymbolRef3->setPos(pos.rx(), pos.ry()+10);
            }
        }
        if (Action == 5) // rotate
        {
            QPointF pos;
            if (SymbolRef1->isSelected())
            {
                pos = SymbolRef1->pos();
                SymbolRef1->rotate(15);
            }
            if (SymbolRef2->isSelected())
            {
                pos = SymbolRef2->pos();
                SymbolRef2->rotate(15);
            }
            if (SymbolRef3->isSelected())
            {
                pos = SymbolRef3->pos();
                SymbolRef3->rotate(15);
            }
        }
    }
    update();
}

void MyText::doReleaseTxt()
{
    Pressed = false;
    if (!SymbolSelector)
    {
        update();
        return;
    }

    if (Selected)
    {
        Selected = false;
        setDefaultTextColor(QColor(255,255,255,255));
    }
    else
    {
        Selected = true;
        setDefaultTextColor(QColor(0,255,0,255));
    }

    if (SymbolRef1 && SymbolSelector)
        SymbolRef1->setSelected(Selected);

    update();
}
