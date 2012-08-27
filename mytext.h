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
    MySym *SymbolRef1;
    MySym *SymbolRef2;
    MySym *SymbolRef3;
    bool SymbolSelector;
    bool SymbolMover;
    int Action;

    void setSelected(bool select);
    void setSymbol(MySym *sym1, MySym *sym2 = NULL, MySym *sym3 = NULL);
    void setSymbolSelector(bool selector);
    void setSymbolMover(bool mover);
    void setAction(int action); //1=left,2=right,3=up,4=down,5=rotate
    bool isSelected();

    void doPressTxt();
    void doReleaseTxt();

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
};

#endif // MYTEXT_H
