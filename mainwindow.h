/****************************************************************************
****************************************************************************/

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QDialog>
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

private slots:
    void move();
    void about();
    void startOrStopThread();

private:
    Thread threadA;
    QTimer *timer;

    void createActions();
    void createStatusBar();

    QGraphicsView *view;
    QGraphicsScene *scene;

    QPushButton *moveButton;
    QPushButton *threadButton;
    QPushButton *closeButton;
};

#endif
