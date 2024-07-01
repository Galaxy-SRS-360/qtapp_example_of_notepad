QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    dummy_stack_chk_fail.cpp \
    main.cpp \
    mywindow.cpp



HEADERS += \
    mywindow.h

FORMS += \
    mywindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

# Link against SSP libraries and add stack protector
LIBS += -lssp -lssp_nonshared

# Ensure stack protection during linking
QMAKE_CXXFLAGS += -fstack-protector
QMAKE_LDFLAGS += -fstack-protector

RESOURCES += \
    myresource.qrc \
    myresource.qrc \
    myresource.qrc
