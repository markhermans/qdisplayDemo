/****************************************************************************
****************************************************************************/

#ifndef MAPSCENE_H
#define MAPSCENE_H

#include <QGraphicsScene>
#include <QGraphicsPixmapItem>

class MapScene : public QGraphicsScene
{
    Q_OBJECT

public:
    MapScene(QString filename);

    void initialize();

private:
    QGraphicsPixmapItem *bg;
};

#endif
