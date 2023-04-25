#pragma once

#ifndef QT_CORE_LIB
#error
#endif

struct App;
struct Window;

struct GUI : Object {
    static GUI* gui;
    static App* app;
    static Window* wMain;
    GUI();
};

struct App : GUI {
    static QApplication* qapp;
};

struct Window : GUI {
    QWidget* qwidget;
};
