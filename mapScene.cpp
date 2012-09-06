/****************************************************************************
****************************************************************************/

#include <QtGui>

#include "mapScene.h"

MapScene::MapScene(QString filename)
{
    bg = new QGraphicsPixmapItem(QPixmap(filename));

	this->addItem(bg);
}

void MapScene::initialize()
{
	// nothing happening here
}
