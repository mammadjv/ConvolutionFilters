TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG += qt

QT += core
QT += widgets

LIBS += -lopencv_core
LIBS += -lopencv_highgui
LIBS += -lopencv_imgproc
LIBS += -lpthread

QMAKE_CXXFLAGS+= -fopenmp
QMAKE_LFLAGS +=  -fopenmp

SOURCES += main.cpp \
    imageconvertor.cpp \
    viewframe.cpp \
    convolution_filters.cpp

HEADERS += \
    imageconvertor.h \
    viewframe.h \
    convolution_filters.h

FORMS += \
    viewframe.ui
