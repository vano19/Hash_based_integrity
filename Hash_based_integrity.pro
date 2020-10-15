QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

INCLUDEPATH += $$PWD/opencv/sources_builded/install/include

LIBS += $$PWD/opencv/sources_builded/install/x64/mingw/lib/libopencv_highgui430.dll.a
LIBS += $$PWD/opencv/sources_builded/install/x64/mingw/lib/libopencv_imgcodecs430.dll.a
LIBS += $$PWD/opencv/sources_builded/install/x64/mingw/lib/libopencv_core430.dll.a
LIBS += $$PWD/opencv/sources_builded/install/x64/mingw/lib/libopencv_imgproc430.dll.a
LIBS += $$PWD/opencv/sources_builded/install/x64/mingw/lib/libopencv_features2d430.dll.a
LIBS += $$PWD/opencv/sources_builded/install/x64/mingw/lib/libopencv_calib3d430.dll.a

SOURCES += \
    ALGCompression.cpp \
    ALGKey.cpp \
    Definitions.cpp \
    Mainwindow.cpp \
    main.cpp

HEADERS += \
    ALGCompression.h \
    ALGKey.h \
    Definitions.h \
    IAlgorithm.h \
    Mainwindow.h \
    Trace.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Images.qrc

