/****************************************************************************
****************************************************************************/

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QDialog>
#include <QKeyEvent>
#include "mThread.h"

QT_BEGIN_NAMESPACE
class QGraphicsView;
class QGraphicsScene;
class QPushButton;
class QTimer;
QT_END_NAMESPACE


class MainWindow : public QDialog
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);

protected:
    void closeEvent(QCloseEvent *event);
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);

private slots:
    void move();
    void about();
    void startOrStopThread();
    void doVideoBoot();        // left buttons
    void doShowMap();
    void doTargetSelect();     // right buttons
    void doVideoFlight();

private:
    Thread threadA;
    QTimer *timer;

    void createActions();
    void createStatusBar();

    QGraphicsView *targetSelect_view;
    QGraphicsView *videoBoot_view;
    QGraphicsView *showMap_view;
    QGraphicsView *videoFlight_view;
    QGraphicsScene *scene;

    QPushButton *moveButton;
    QPushButton *threadButton;
    QPushButton *closeButton;

signals:
    void mainKeyPress();
    void playBootVideo();
    void pauseBootVideo();
    void playFlightVideo();
    void pauseFlightVideo();
};

#endif
