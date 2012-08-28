#ifndef MYTEXT_H
#define MYTEXT_H

#include <QGraphicsTextItem>
#include <QString>
#include "mysym.h"

class MyText : public QGraphicsTextItem
{
public:
    MyText(const QString & text, int pixelSize = 17);

    bool Pressed;
    bool Selected;
    QColor DefaultTextColor;
    QColor SelectedColor;

    void setSelected(bool select);
    bool isSelected();

    void doPressTxt();
    void doReleaseTxt();

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
};

#endif // MYTEXT_H
