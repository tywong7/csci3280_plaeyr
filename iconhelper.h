//reference:http://www.qtcn.org/bbs/read-htm-tid-63655-ds-1-page-1.html?fbclid=IwAR3Eg4TgKdLw2rFd4wM4QQNNPRVs9eEnxT62djkBBrwkW2oUYhjoxktxbHE#184041
#ifndef ICONHELPER_H
#define ICONHELPER_H

#include <QtCore>
#include <QtGui>

#if (QT_VERSION > QT_VERSION_CHECK(5,0,0))
#include <QtWidgets>
#endif

#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif


class IconHelper : public QObject
{
    Q_OBJECT

public:
    explicit IconHelper(QObject *parent = nullptr);
    static IconHelper *Instance()
    {
        static QMutex mutex;

        if (!self) {
            QMutexLocker locker(&mutex);

            if (!self) {
                self = new IconHelper;
            }
        }

        return self;
    }
    int testsharing=0;
    void setIcon(QLabel *lab, QChar c, quint32 size = 9);
    void setIcon(QAbstractButton *btn, QChar c, quint32 size = 9);
    QPixmap getPixmap(const QString &color, QChar c, quint32 size = 9,quint32 pixWidth = 10, quint32 pixHeight = 10);
    QPixmap getPixmap(QToolButton *btn, bool normal);


    static void setStyle(QWidget *widget, const QString &type = "left", int borderWidth = 3,
                         const QString &borderColor = "",
                         const QString &normalBgColor = "",
                         const QString &darkBgColor = "",
                         const QString &normalTextColor = "",
                         const QString &darkTextColor = "");

    void setStyle(QWidget *widget, QList<QToolButton *> btns, QList<int> pixChar,
                  quint32 iconSize = 9, quint32 iconWidth = 10, quint32 iconHeight = 10,
                  const QString &type = "left", int borderWidth = 3,
                  const QString &borderColor = "",
                  const QString &normalBgColor = "",
                  const QString &darkBgColor = "",
                  const QString &normalTextColor = "",
                  const QString &darkTextColor = "");


    void setStyle(QFrame *frame, QList<QToolButton *> btns, QList<int> pixChar,
                  quint32 iconSize = 9, quint32 iconWidth = 10, quint32 iconHeight = 10,
                  const QString &normalBgColor = "",
                  const QString &darkBgColor = "",
                  const QString &normalTextColor = "",
                  const QString &darkTextColor = "");

protected:
    bool eventFilter(QObject *watched, QEvent *event);

private:
    static IconHelper *self;
    QFont iconFont;
    QList<QToolButton *> btns;
    QList<QPixmap> pixNormal;
    QList<QPixmap> pixDark;
};
#endif // ICONHELPER_H
