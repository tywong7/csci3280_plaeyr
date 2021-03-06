﻿#include "appinit.h"
#include "qapplication.h"
#include "qevent.h"
#include "qwidget.h"
//reference:http://www.qtcn.org/bbs/read-htm-tid-63655-ds-1-page-1.html?fbclid=IwAR3Eg4TgKdLw2rFd4wM4QQNNPRVs9eEnxT62djkBBrwkW2oUYhjoxktxbHE#184041
#pragma comment( lib, "Winmm.lib" )
AppInit *AppInit::self = nullptr;
AppInit::AppInit(QObject *parent) : QObject(parent)
{
}

bool AppInit::eventFilter(QObject *obj, QEvent *evt)
{
    QWidget *w = (QWidget *)obj;
    if (!w->property("canMove").toBool()) {
        return QObject::eventFilter(obj, evt);
    }

    static QPoint mousePoint;
    static bool mousePressed = false;

    QMouseEvent *event = static_cast<QMouseEvent *>(evt);
    if (event->type() == QEvent::MouseButtonPress) {
        if (event->button() == Qt::LeftButton) {
            mousePressed = true;
            mousePoint = event->globalPos() - w->pos();
            return true;
        }
    } else if (event->type() == QEvent::MouseButtonRelease) {
        mousePressed = false;
        return true;
    } else if (event->type() == QEvent::MouseMove) {
        if (mousePressed && (event->buttons() && Qt::LeftButton)) {
            w->move(event->globalPos() - mousePoint);
            return true;
        }
    }

    return QObject::eventFilter(obj, evt);
}

void AppInit::start()
{
    qApp->installEventFilter(this);
}
