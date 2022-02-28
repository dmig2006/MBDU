#ifndef VIRTUAL_KEYBOARD_H
#define VIRTUAL_KEYBOARD_H

#include <QDialog>

#include "controllermanager.h"
#include "tracking_zala.h"

namespace Ui {
class VirtualKeyboard;
}

class VirtualKeyboard : public QDialog
{
    Q_OBJECT

public:
    explicit VirtualKeyboard(QWidget *parent = 0);
    ~VirtualKeyboard();
    void delChar();
    void getCorrections(QString pStr, int i);
    void setTrackingZala(TrackingZala *pTrackingZala);
    void setControllerManager(ControllerManager *pControllerManager);
    void inversia_Keyboard(bool pFlag);

private slots:
    void on_key_0_clicked();
    void on_key_1_clicked();
    void on_key_2_clicked();
    void on_key_3_clicked();
    void on_key_4_clicked();
    void on_key_5_clicked();
    void on_key_6_clicked();
    void on_key_7_clicked();
    void on_key_8_clicked();
    void on_key_9_clicked();
    void on_key_enter_clicked();
    void on_key_plus_clicked();
    void on_key_minus_clicked();
    void on_key_reside_clicked();
    void on_key_backspace_clicked();
    void on_key_esc_clicked();
    void on_key_left_clicked();
    void on_key_down_clicked();
    void on_key_right_clicked();
    void on_key_up_clicked();

private:
    Ui::VirtualKeyboard *ui;
    TrackingZala *mTrackingZala;
    ControllerManager *mControllerManager;
    QString str;

    long mRange, mThermo, mPressure;
    long mWindX,mWindY;
    long prevRange, prevThermo, prevPressure;
    long prevWindX, prevWindY;
    int pos;
    int mCorrections;

    bool is_ctrl_pressed, is_s_pressed, is_t_pressed;

protected:
        void keyPressEvent(QKeyEvent *event);

signals:
//    void newDataCorrection(long pData);
    void newDataCorrection(long mRange, long mThermo, long mPressure,
                           long mWindX, long mWindY);
    void newChar(QString pStr);
    void newExit();
};

#endif // VIRTUAL_KEYBOARD_H
