/****************************************************************************
**
** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies).
** All rights reserved.
** Contact: Nokia Corporation (qt-info@nokia.com)
**
** This file is part of the examples of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:BSD$
** You may use this file under the terms of the BSD license as follows:
**
** "Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions are
** met:
**   * Redistributions of source code must retain the above copyright
**     notice, this list of conditions and the following disclaimer.
**   * Redistributions in binary form must reproduce the above copyright
**     notice, this list of conditions and the following disclaimer in
**     the documentation and/or other materials provided with the
**     distribution.
**   * Neither the name of Nokia Corporation and its Subsidiary(-ies) nor
**     the names of its contributors may be used to endorse or promote
**     products derived from this software without specific prior written
**     permission.
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
** $QT_END_LICENSE$
**
****************************************************************************/

//! [0]
#include <QApplication>

#include <QDesktopWidget>
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    Q_INIT_RESOURCE(displayDemo);

    QApplication app(argc, argv);

    app.setOrganizationName("Mnemonics, Inc");
    app.setApplicationName("P. O. C.");
    MainWindow mainWin;
#if defined(Q_OS_SYMBIAN)
    mainWin.showMaximized();
#else
    mainWin.show();
#endif
    QDesktopWidget *qdw = app.desktop();
    QRect rect = qdw->screenGeometry(0);
    int dt_w = rect.width();
    int dt_h = rect.height();
    int mw_x = mainWin.geometry().x();
    int mw_y = mainWin.geometry().y();
    int mw_w = mainWin.geometry().width();
    int mw_h = mainWin.geometry().height();
    int cmw_x, cmw_y;

    int diff_w = dt_w - mw_w;
    int diff_h = dt_h - mw_h;

    if (diff_w < 0 )
    {
        cmw_x = 0;
    }
    else
    {
        cmw_x = diff_w / 2;
    }

    if (diff_h < 0 )
    {
        cmw_y = 0;
    }
    else
    {
        cmw_y = diff_h / 2;
    }


    // center mainWin on desktop
    mainWin.setGeometry(cmw_x, cmw_y, mw_w, mw_h);
    printf("Screen size: %dx%d\n", dt_w, dt_h);
    printf("Window position+size: %d,%d + %dx%d\n", cmw_x, cmw_y, mw_w, mw_h);

    return app.exec();
}
//! [0]
