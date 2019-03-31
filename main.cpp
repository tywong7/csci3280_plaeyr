#include "ui3280player.h"
#include "appinit.h"
#include "qicon.h"
#include "qtextcodec.h"
#include "qapplication.h"
#include "edit_form.h"
#include "videoplayer.h"
#pragma comment( lib, "Winmm.lib" )
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setFont(QFont("Microsoft Yahei", 9));
    a.setWindowIcon(QIcon(":/main.ico"));
    QTextCodec *codec = QTextCodec::codecForName("utf-8");
    QTextCodec::setCodecForLocale(codec);

    AppInit::Instance()->start();

    UI3280Player w;
    w.show();

    return a.exec();
}
