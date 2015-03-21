QT += sql

HEADERS += \
    ImageOperate.h \
    FileOperate.h \
    CImg.h \
    BasicDataStructure.h \
    interfaces.h \
    PaintTools.h \
    PolyLine.h \
    MyPreference.h \
    Linelet.h \
    ImageViewer.h \
    imagecompletionui.h \
    LeftWindow.h \
    searchdata.h \
    classification.h \
    buttom.h \
    advancesearchdlg.h \
    propertynamedlg.h \
    ImageProperties.h \
    Connection.h \
    Login.h \
    UserAdd.h \
    UserEdit.h \
    UserInfo.h \
    UserManagement.h \
    Global.h \
    SimplifiedSearch.h \
    MoliProperties.h


SOURCES += \
    ImageOperate.cpp \
    BasicDataStructure.cpp \
    main.cpp \
    PaintTools.cpp \
    PolyLine.cpp \
    MyPreference.cpp \
    ImageViewer.cpp \
    LeftWindow.cpp \
    searchdata.cpp \
    classification.cpp \
    buttom.cpp \
    imagecompletionui.cpp \
    advancesearchdlg.cpp \
    propertynamedlg.cpp \
    ImageProperties.cpp \
    Login.cpp \
    UserAdd.cpp \
    UserEdit.cpp \
    UserInfo.cpp \
    UserManagement.cpp \
    Global.cpp \
    SimplifiedSearch.cpp \
    MoliProperties.cpp


FORMS += \
    RegionCompetition.ui \
    imagecompletionui.ui \
    SceneCompletionWidget.ui \
    CornerWindow.ui \
    LeftWindow.ui \
    ButtomWindow.ui \
    searchdata.ui \
    classification.ui \
    buttom.ui \
    login.ui \
    usermanagement.ui \
    useradd.ui \
    imageproperties.ui \
    advancesearchdlg.ui \
    useredit.ui \
    propertynamedlg.ui \
    SimplifiedSearch.ui \
    MoliProperties.ui

RESOURCES += \
    ImageCompletion.qrc

unix:!macx {
    LIBS += `pkg-config opencv --libs`
}
win32 {
INCLUDEPATH += D:\Application\CMake_Qt_OpenCV_MinGW482\install\include\

LIBS += D:\Application\CMake_Qt_OpenCV_MinGW482\install\lib\libopencv_core244.dll.a\
        D:\Application\CMake_Qt_OpenCV_MinGW482\install\lib\libopencv_highgui244.dll.a\
        D:\Application\CMake_Qt_OpenCV_MinGW482\install\lib\libopencv_imgproc244.dll.a\
}

OTHER_FILES += \
    imageLabelling.ini

include(QtAwesome/QtAwesome.pri)
