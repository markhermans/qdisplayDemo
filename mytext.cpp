#include "mytext.h"
#include "stdio.h"
#include <QFont>
#include <QPointF>

MyText::MyText(const QString &text, int pixelSize)
{
    QFont f1;

    f1.setFamily("Courier");
    f1.setPixelSize(pixelSize);
    setPlainText(text);
    setFont(f1);
    setFlags(QGraphicsItem::ItemIsSelectable);

    Selected = false;
    DefaultTextColor = QColor(255,255,255,255);
    setDefaultTextColor(QColor(255,255,255,255));
}

void MyText::setSelected(bool select)
{
    Selected = select;
}

bool MyText::isSelected()
{
    return Selected;
}
