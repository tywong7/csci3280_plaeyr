#ifndef FLATUI_H
#define FLATUI_H


#include <QObject>
class QSlider;
class QRadioButton;
class QCheckBox;
class QScrollBar;
class QPushButton;
class QLineEdit;
class QProgressBar;
//reference:http://www.qtcn.org/bbs/read-htm-tid-63655-ds-1-page-1.html?fbclid=IwAR3Eg4TgKdLw2rFd4wM4QQNNPRVs9eEnxT62djkBBrwkW2oUYhjoxktxbHE#184041
#ifdef quc
#if (QT_VERSION < QT_VERSION_CHECK(5,7,0))
#include <QtDesigner/QDesignerExportWidget>
#else
#include <QtUiPlugin/QDesignerExportWidget>
#endif

class QDESIGNER_WIDGET_EXPORT FlatUI : public QObject
#else
class FlatUI : public QObject
#endif

{
    Q_OBJECT
public:
    static FlatUI *Instance();
    explicit FlatUI(QObject *parent = nullptr);

private:
    static FlatUI *self;

public:

    void setPushButtonQss(QPushButton *btn, int radius, int padding, const QString &normalColor, const QString &normalTextColor,
                          const QString &hoverColor,
                          const QString &hoverTextColor,
                          const QString &pressedColor,
                          const QString &pressedTextColor);

    void setLineEditQss(QLineEdit *txt,int radius,int borderWidth,const QString &normalColor,const QString &focusColor);

    void setProgressBarQss(QProgressBar *bar,int barHeight,int barRadius,int fontSize, const QString &normalColor,const QString &chunkColor);

    void setSliderQss(QSlider *slider,int sliderHeight,const QString &normalColor, const QString &grooveColor, const QString &handleColor);


};

#endif // FLATUI_H
