/****************************************************************************
****************************************************************************/

#include <QtGui>

#include "bootScene.h"

BootScene::BootScene(QWidget *parent, QString filename)
{
    m_VideoWidget = new Phonon::VideoWidget();
    m_AudioOutput = new Phonon::AudioOutput(Phonon::VideoCategory);
    m_MediaObject = new Phonon::MediaObject();
    Phonon::createPath(m_MediaObject, m_AudioOutput);
    Phonon::createPath(m_MediaObject, m_VideoWidget);

    m_MediaObject->setCurrentSource(Phonon::MediaSource(filename));

    bg = new QGraphicsPixmapItem(QPixmap(":/images/background_blk.jpg"));
    fg = new QGraphicsPixmapItem(QPixmap(":/images/adi_360_480.jpg"));

    QGraphicsProxyWidget *videoProxy = new QGraphicsProxyWidget();
    videoProxy->setWidget(m_VideoWidget);

    this->addItem(videoProxy);
//    this->addWidget(m_VideoWidget);
}

void BootScene::initialize()
{
    // nothing going on here
}

void BootScene::play()
{
	m_MediaObject->play();
}

void BootScene::pause()
{
	m_MediaObject->pause();
}
