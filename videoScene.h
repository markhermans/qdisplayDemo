/****************************************************************************
****************************************************************************/

#ifndef VIDEOSCENE_H
#define VIDEOSCENE_H

#include <QGraphicsScene>
#include <phonon/Phonon>


class VideoScene : public QGraphicsScene
{
    Q_OBJECT

public:
    VideoScene(QWidget *parent, QString filename);

    void setScaleToRect(const QRectF & rect, qreal zoomX, qreal zoomY);
    void setPos(qreal x, qreal y);
    void initialize();

private slots:
    void play();
    void pause();

private:
    QGraphicsPixmapItem *bg;
    QGraphicsPixmapItem *fg;

    Phonon::MediaObject *m_MediaObject;
    Phonon::AudioOutput *m_AudioOutput;
	Phonon::VideoWidget *m_VideoWidget;

    QGraphicsProxyWidget *videoProxy;
};

#endif
