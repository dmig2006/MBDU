#ifndef SERVICEWIDGET_H
#define SERVICEWIDGET_H

#include <QDialog>
#include <QCloseEvent>
#include <QIntValidator>

#include "controllermanager.h"
#include "virtual_keyboard.h"

#include <QDebug>

namespace Ui {
class serviceWidget;
}

class serviceWidget : public QDialog
{
    Q_OBJECT

public:
    explicit serviceWidget(QWidget *parent = 0);
    ~serviceWidget();
    void setControllerManager(ControllerManager *pControllerManager);
    void textCompression(QString pstr);
    void colorInversia(bool pInversia);
    void setVirtualKeyboard(VirtualKeyboard *pVirtualKeyboard);

protected:
    void changeEvent(QEvent *event);
    void closeEvent(QCloseEvent *event);
    void timerEvent(QTimerEvent *);
    bool eventFilter(QObject *object, QEvent *event);

private slots:
    void on_adjustmentButton_clicked();
    void on_exitButton_clicked();
    void on_modeButton_clicked();
    void on_soundButton_clicked();
    void on_applyBurstLength_clicked();
    void on_applyAmmunition_clicked();

    void on_mjpegButton_clicked();

    void on_h264Button_clicked();

private:
    Ui::serviceWidget *ui;

    ControllerManager *mControllerManager;
    VirtualKeyboard *mVirtualKeyboard;

    bool flagMode;

//Virtual Keyboard;
    bool flagAmmunition;
    bool flagShort;
    bool flagLong;
    bool flagSingle;
//Virtual keyboard

signals:
    void newAdjustment();
    void newSound();
    void newStandByMode();
    void newOperationMode();
    void newMJPEG();
    void newH264();
};

#endif // SERVICEWIDGET_H
