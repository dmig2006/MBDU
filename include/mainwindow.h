#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QListWidgetItem>
#include <QValidator>
#include <QLabel>
#include <iostream>
#include <math.h>
#include <vector>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <QMovie>

#include "burstlength_dialog.h"
#include "ammunition_dialog.h"
#include "automodetype_dialog.h"
#include "burstlength_dialog.h"
#include "soundsignal_dialog.h"
#include "targeteditor_dialog.h"
#include "adjustment_dialog.h"

#include "videowidget.h"
#include "optwidget.h"
#include "plathormdir.h"
#include "controllermanager.h"
#include "action.h"
#include "actionlist.h"
#include "weapon.enum.h"
#include "aim.enum.h"
#include "cfgmanager.h"
#include "beeper.h"

//Zala_Class
    #include "tracking_zala.h"
//Zala_Class

//Virtual KeyBoard
    #include "virtual_keyboard.h"
    #include <QMediaPlayer>
    #include <QVideoWidget>
    #include <QDataStream>

    #include <QGraphicsVideoItem>
    #include <QGraphicsView>
//VirtualKeyBoard

#include "joystick.h"

#include "pid.h"

#include "servicewidget.h"


#include "qsimpleserver.h"
#include "qudpserver.h"
#include <qendian.h>

enum MessageType {
    neutral,
    safe,
    unsafe
};

namespace Ui {
    class MainWindow;
}

Q_DECLARE_METATYPE(CameraMode)
Q_DECLARE_METATYPE(BurstType)
Q_DECLARE_METATYPE(FireType)
Q_DECLARE_METATYPE(Mode)
Q_DECLARE_METATYPE(Cocking)
Q_DECLARE_METATYPE(AimType)

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

    bool trig_f11, trig_f12;
/*    void setConnectedDevice(bool state);
    void setLoadingVideo(bool state);
    void setOperationMode(bool state);

    bool indikator_ac, t_indi_ac, flag_konstr, flag_acTrack, invers, trig_f11, trig_f12;  //flags,triggers
    double spMotorX, spMotorY, spRezult;
    float spAngle;
    int countX, countY;
*/
public slots:
    //ZALA Class
    void acTrack(bool enabled); //Включение режима сопровождения
//    void move_Ac_Target(long x, long y);
    void setCameraMode_AC(CameraMode pCameraMode);
//    void AC_Joystick();
//    void ac_Joystick();
//    void getKoordinatAc(can_frame *frame);
//    void filterIndikator();
//    void time_indi_ac();
//    void readVPx (float pv);
//    void readVPy (float pv);
    //ZALA CLASS

//    void nextTracking();
    void setSpeedX(float pSpeed);
    void setSpeedY(float pSpeed);

    void setPositionX(long pPosition);
    void setPositionY(long pPosition);

    void setVoltageBu(float pVoltageExternal);
    void setThermo(int pThermo);
    void setPressure(int pPressure);
    void setVoltage(float pVoltage);

    void appendLog(QString pStr);
    void setRange(int pRange);
    void setAmmunitionCounter(int pAmmunitionCounter);
    void setPermission(bool state);
    void setBurstType(BurstType pBurstType);
    void setFireType(FireType pFireType);
    void setFire(bool state);
    void setCorrectionCross(long pCorrectionX, long pCorrectionY);
    void setJustCross(long pJutsX, long pJutsY);
    void setStabilization(bool state);
    void setMode(Mode pMode);
    void setCocking(Cocking pCocking);
    void setLastSaved(long pPositionX, long pPositionY, int pRange, int pNumberAim);
    void resetLastSaved();
//    void setTracking(bool state, int pType);
//    void setCameraMode(CameraMode pCameraMode);
//    void closeTracking();
//    void setTargets(std::vector<QRect> pTargets);
    void setAutoMode(bool state);
    void resetBeep();
    void testBeep(BeepState pBeepState);
    void setBeepState(BeepState pBeepState);
    void closeAll();
    void setActivatePlathorm(bool activate);
//    void setAimType(AimType pAimType);

    void on_autoModeButton_clicked();
    void on_editAimButton_clicked();
//    void on_actionAmmunition_triggered();
    void on_actionBurst_length_triggered();
    void on_rangeInput_editingFinished();
//    void on_actionStand_by_mode_triggered();
//    void on_actionOperation_mode_triggered();
    void on_deleteAimButton_clicked();
    void on_windXInput_editingFinished();
    void on_windYInput_editingFinished();
    void on_temperatureInput_editingFinished();
    void on_pressureInput_editingFinished();
    void on_actionClose_triggered();

protected:
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);
    bool eventFilter(QObject *object, QEvent *event);

private:
    Ui::MainWindow *ui;
    ControllerManager *mControllerManager;
    VideoWidget *mVideoWidget;
//    TestWidget *mVideoWidget;
    OptWidget   *mOptWidget;
    PlathormDir *mPlathormDir;
    SoundSignalDialog *mSoundSignalDialog;
    Beeper      *mBeeper;
//    can_frame txf;
    Joystick *mJoystick;
//    QSimpleServer *server;
//    QTimer *mTimer, *filtrTimer, *timerD;
//    PID *mPIDx, *mPIDy, *mPID;
    PID *mPID;

//ZALA_CLASS
    TrackingZala *mTrackingZala;
//ZALA_CLASS

// VIRTUAL_KEYBOARD
    VirtualKeyboard *mVirtualKeyboard;
    QString str_1;
    bool flagTemp, flagPressure, flagRange;
    bool flagWindX,flagWindY;

    QMediaPlayer *player;
    serviceWidget *mService;

// VIRTUAL_KEYBOARD

    qudpserver *mUdpServer, *mUdpClient;
    UDP_Parcel udpRecive;
    AdjustmentDialog ad;
    BurstLengthDialog mBurstLengthDialog;
    AmmunitionDialog mAmmunitionDialog;
    AutoModeTypeDialog mAutoModeTypeDialog;
    TargetEditorDialog mTargetEditorDialog;
//    QMovie *movie;


    bool isVideo;
    int  mLogId;
    int  mTypeTracking;
    bool isOptRange;
    bool isFilter;
    int  mLogID;
    bool isTracking;
    bool is_low_cu_voltage;
    bool is_low_rp_voltage;
    bool is_inverted_enable;
    bool is_ctrl_pressed;
    bool is_s_pressed;
    bool is_t_pressed;
    int  mPositionMouseX;
    int  mPositionMouseY;
    bool isBeepIpa;
    bool is_first_beep;
    bool is_cocking_in_progress;
    bool is_wiper_working;
    CameraMode cur_camera;
    WeaponType cur_weapon;

    bool invers,inversia_stabilization;
    bool flagInversia;
    bool flagActivate;
    bool flagPid;

    bool is_p;
    bool is_i;
    bool is_d;


    void setMessage(QLabel *label, QString msg = "",
                    enum MessageType m_type = neutral);
    void setInterfaceInteractivity(bool interactive);
//
    float angleAir(double spX, double spY, double spR);

    void paintNormal();
    void paintInversia();

    void setConnectedDevice(bool state);
    void setLoadingVideo(bool state);
    void setOperationMode(bool state);

//    void animationStartPause(bool pFlag);

signals:
    //void n_off_Joystick_MW (bool Enebled); // сигнал на зануление джойствика
    void readPageX(float b1, float b2, float b3, float b4, float b5, float b6, float b7, float b8, float b9);
    void readPageY(float b1, float b2, float b3, float b4, float b5, float b6, float b7, float b8, float b9);

private slots:
    void enableInterface();
    void resetCamera();

    // Virtual keyboard
        void getData(long pRange, long pThermo, long pPressure,
                     long pWindX, long pWindY);
        void strData(QString pStr);
    // Virtual KeyBoard

     void reciveUdpParcel (UDP_Parcel udpReciveParcel);

//     void on_actionSound_signal_triggered();
//     void on_actionAdjustment_triggered();

     void on_actionNormal_mode_triggered();
     void on_actionPicture_in_picture_triggered();
     void on_actionSmall_picture_in_picture_triggered();
     void on_actionHorizontal_line_triggered();
     void on_actionVertical_line_triggered();
     void on_actionDigital_stabilization_triggered();

     void on_actionPID_triggered();

     void inversia();

//SERVICE
     void adjustmentDialog();
     void soundDialog();
     void standByMode();
     void operationMode();

     void mjpegPicture();
     void h264Picture();
//SERVICE

     void on_inversiaButton_clicked();
     void on_ReturnButton_clicked();
     void on_digitalStabilization_clicked();
     void on_filtrButton_clicked();
     void on_modePictureButton_clicked();
//     void on_h264Button_clicked();
     void on_mjpegButton_clicked();
     void on_serviceButton_clicked();
     void on_exitButton_clicked();
};

#endif // MAINWINDOW_H
