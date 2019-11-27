TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp


win32: LIBS += -L$$PWD/../../Desktop/sdlmusica-master/SDL2_mixer-2.0.4/i686-w64-mingw32/lib/ -lSDL2_mixer

INCLUDEPATH += $$PWD/../../Desktop/sdlmusica-master/SDL2_mixer-2.0.4/i686-w64-mingw32/include
DEPENDPATH += $$PWD/../../Desktop/sdlmusica-master/SDL2_mixer-2.0.4/i686-w64-mingw32/include

win32: LIBS += -L$$PWD/../../Desktop/SDL2-2.0.10/i686-w64-mingw32/lib/ -lSDL2

INCLUDEPATH += $$PWD/../../Desktop/SDL2-2.0.10/i686-w64-mingw32/include
DEPENDPATH += $$PWD/../../Desktop/SDL2-2.0.10/i686-w64-mingw32/include

HEADERS += \
    declara_botao.h
