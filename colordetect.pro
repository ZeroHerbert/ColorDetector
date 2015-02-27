#-------------------------------------------------
#
# Project created by QtCreator 2015-02-26T16:02:48
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = colordetect
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
    colordetector.cpp

HEADERS  += widget.h \
    colordetector.h

FORMS    += widget.ui

INCLUDEPATH+=C:\OpenCV\install\include\opencv\
C:\OpenCV\install\include\opencv2\
C:\OpenCV\install\include

LIBS+=C:\OpenCV\lib\libopencv_calib3d249.dll.a\
C:\OpenCV\lib\libopencv_contrib249.dll.a\
C:\OpenCV\lib\libopencv_core249.dll.a\
C:\OpenCV\lib\libopencv_features2d249.dll.a\
C:\OpenCV\lib\libopencv_flann249.dll.a\
C:\OpenCV\lib\libopencv_gpu249.dll.a\
C:\OpenCV\lib\libopencv_highgui249.dll.a\
C:\OpenCV\lib\libopencv_imgproc249.dll.a\
C:\OpenCV\lib\libopencv_legacy249.dll.a\
C:\OpenCV\lib\libopencv_ml249.dll.a\
C:\OpenCV\lib\libopencv_nonfree249.dll.a\
C:\OpenCV\lib\libopencv_objdetect249.dll.a\
C:\OpenCV\lib\libopencv_ocl249.dll.a\
C:\OpenCV\lib\libopencv_video249.dll.a\
C:\OpenCV\lib\libopencv_photo249.dll.a\
C:\OpenCV\lib\libopencv_stitching249.dll.a\
C:\OpenCV\lib\libopencv_superres249.dll.a\
C:\OpenCV\lib\libopencv_ts249.a\
C:\OpenCV\lib\libopencv_videostab249.dll.a
