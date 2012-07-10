HEADERS += \
    mainwindow.h \
    mThread.h

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    mThread.cpp

RESOURCES += \
        dispDemo.qrc

# install
target.path = C:/Users/MarkHermans/git_projects/poc
sources.files = $$SOURCES $$HEADERS $$RESOURCES $$FORMS dispDemo.pro images
sources.path = C:/Users/MarkHermans/git_projects/poc
INSTALLS += target sources

symbian {
    TARGET.UID3 = 0xA000A643
    include($$PWD/../../symbianpkgrules.pri)
}
maemo5: include($$PWD/../../maemo5pkgrules.pri)
contains(MEEGO_EDITION,harmattan): include($$PWD/../../harmattanpkgrules.pri)
simulator: warning(This example might not fully work on Simulator platform)
