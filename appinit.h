#ifndef APPINIT_H
#define APPINIT_H

#include <QObject>
#include <QMutex>
//reference:http://www.qtcn.org/bbs/read-htm-tid-63655-ds-1-page-1.html?fbclid=IwAR3Eg4TgKdLw2rFd4wM4QQNNPRVs9eEnxT62djkBBrwkW2oUYhjoxktxbHE#184041

class AppInit : public QObject
{
    Q_OBJECT
public:
    explicit AppInit(QObject *parent = nullptr);
    static AppInit *Instance() {
        static QMutex mutex;
        if (!self) {
            QMutexLocker locker(&mutex);
            if (!self) {
                self = new AppInit;
            }
        }
        return self;
    }

    void start();

protected:
    bool eventFilter(QObject *obj, QEvent *evt);

private:
    static AppInit *self;

signals:

public slots:
};

#endif // APPINIT_H
