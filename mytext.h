#ifndef MYTEXT_H
#define MYTEXT_H

#include <QGraphicsTextItem>
#include <QString>

class MyText : public QGraphicsTextItem
{
public:
    MyText(const QString & text, int pixelSize = 17);

    bool Selected;
    QColor DefaultTextColor;
    QColor SelectedColor;

    void setSelected(bool select);
    bool isSelected();
};

#endif // MYTEXT_H
