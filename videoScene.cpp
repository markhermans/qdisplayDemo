/****************************************************************************
****************************************************************************/

#include <QtGui>

#include "videoScene.h"

VideoScene::VideoScene(QWidget *parent, QString filename)
{
    m_VideoWidget = new Phonon::VideoWidget();
    m_AudioOutput = new Phonon::AudioOutput(Phonon::VideoCategory);
    m_MediaObject = new Phonon::MediaObject();
    Phonon::createPath(m_MediaObject, m_AudioOutput);
    Phonon::createPath(m_MediaObject, m_VideoWidget);

    m_MediaObject->setCurrentSource(Phonon::MediaSource(filename));

    bg = new QGraphicsPixmapItem(QPixmap(":/images/background_blk.jpg"));
    fg = new QGraphicsPixmapItem(QPixmap(":/images/adi_360_480.jpg"));

    videoProxy = new QGraphicsProxyWidget();
    videoProxy->setWidget(m_VideoWidget);

    this->addItem(videoProxy);
//    this->addWidget(m_VideoWidget);
}

void VideoScene::setScaleToRect(const QRectF & rect)
{
    qreal w = this->sceneRect().width();
    qreal h = this->sceneRect().height();
    qreal sf_x = rect.width()/w;
    qreal sf_y = rect.height()/h;

    videoProxy->scale(sf_x,sf_y);
}

void VideoScene::initialize()
{
    // nothing going on here
}

void VideoScene::play()
{
	m_MediaObject->play();
}

void VideoScene::pause()
{
	m_MediaObject->pause();
}
