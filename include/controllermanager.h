#ifndef CONTROLLER_MANAGER
#define CONTROLLER_MANAGER
/*****************************************************************************/
/*** controller                                                            ***/
/*****************************************************************************/
#include <QThread>
#include <QMutex>
#include <QTimer>
#include <QTime>

#include <iostream>
#include <map>
#include <cmath>

#include "cfgmanager.h"
#include "supportmanager.h"
#include "controldevice.h"
#include "aimlist.h"
#include "aim.h"
#include "weapon.enum.h"
#include "aim.enum.h"
#include "actionlist.h"
#include "action.h"
#include "joystick.h"
#include "devicethread.h"
#include "ballistics.h"
#include "tracking.h"
#include "devicethread.h"
#include "view.enum.h"

#ifndef DEGREE_TO_CENTIDEGREE
#define DEGREE_TO_CENTIDEGREE   100.0
#endif

#ifndef MINUTE_TO_CENTIDEGREE
#define MINUTE_TO_CENTIDEGREE   (100.0 / 60.0)
#endif

#define DEGREE_TO_ENCODER_X     773.6
#define DEGREE_TO_ENCODER_Y     182.04

#define MINUTA_TO_ENCODER_X     12.91
#define MINUTA_TO_ENCODER_Y     3.034

#define CORRECTION_POSITION_LEFT_NARROW     0.340
#define CORRECTION_POSITION_UP_NARROW       0.0
#define CORRECTION_POSITION_LEFT_HEAD       0.436
#define CORRECTION_POSITION_UP_HEAD         0.0284
#define CORRECTION_POSITION_LEFT_WHITE      0.340
#define CORRECTION_POSITION_UP_WHITE       -0.0944

#define MAX_VEL_HOR     153.8
#define MAX_VEL_VERT    44.2

#define MAX_SPEED_NARROW_FORMAT_X    100  // 1 degree
#define MAX_SPEED_NARROW_FORMAT_Y    100
#define MAX_SPEED_WIDE_FORMAT_X      600  // 6 degrees
#define MAX_SPEED_WIDE_FORMAT_Y      600
#define MAX_SPEED_THERMAL_X          300  // 3 degrees
#define MAX_SPEED_THERMAL_Y          300
#define MAX_SPEED_ZOOM_THERMAL_X     150  // 1.5 degrees
#define MAX_SPEED_ZOOM_THERMAL_Y     150

#define RES_COCKING_COMPLETED   15

#define FUN_PRESSURE(a)         (int)(((double)a - 410) / 3276.0 * 30 * 57.715 - 77);

#define INVERT_SPEED_Y	 1
#define INVERT_SPEED_X	-1

#define INVERT -1

#define SHOT_TIME_CFG    "config/shot_times.cfg"


//#define COLOR_FON_NORMA                         "background-color:#D4D4D4"

#define COLOR_FON_NORMA                         "background-color: qlineargradient( x1: 0, y1: 0, x2: 0, y2: 1,\
                                                                                    stop: 0 #c8c2c2, stop: 1 #7f7a7a);"

#define COLOR_FON_INVERSIA                      "background-color:#000000"

#define COLOR_MENU_BAR_NORMA                    "QMenuBar::item{background-color:#D4D4D4; color:#610404;}\
                                                 QMenuBar::item:selected{background-color:#9CC75B}\
                                                 QMenuBar#menuBar{background-color: disabled;}"

#define COLOR_MENU_BAR_INVERSIA                 "QMenuBar::item{background-color:#000000; color:#FFFFFF;}\
                                                 QMenuBar::item:selected{background-color:#989197;color:#ECD2D2}\
                                                 QMenuBar#menuBar{background-color:#000000}"

#define COLOR_MENU_NORMA                        "QMenu::item{background-color:disabled; #D4D4D4; color:#610404;}\
                                                 QMenu::item:selected{background-color:#9CC75B;}"


#define COLOR_MENU_INVERSIA                     "background-color: #000000; color:#FFFFFF; selection-background-color: #989197; selection-color:#ECD2D2"

#define COLOR_LINE_NORMA                        "default"

#define COLOR_LINE_INVERSIA                     "background-color:#858585"

#define COLOR_LABEL_NORMA                       "QLabel\
                                                 {\
                                                    background-color:disabled;\
                                                    color:#000000;\
                                                 }"


#define COLOR_LABEL_INVERSIA                    "color:#FFFFFF"

#define COLOR_LABEL_NORMA_DATA                  "QLabel\
                                                 {\
                                                    background-color: disabled;\
                                                    color:#610404;\
                                                 }"

#define COLOR_LABEL_NORM_DATA                   "QLabel\
                                                {\
                                                    background-color:disabled;\
                                                }"

#define COLOR_LABEL_INVERSIA_DATA               "QLabel\
                                                 {\
                                                    background-color:disabled;\
                                                    color:#F68080;\
                                                  }"

#define COLOR_LABEL_INVERS_DATA                 "QLabel\
                                                {\
                                                    background-color:disabled;\
                                                }"

//#define COLOR_BUTTON_NORMA_ACTIVATE           "background-color: #D4D4D4; border-style:solid ; border-width: 3px; border-radius: 10px; border-color: blue; color: #610404;"

//#define COLOR_BUTTON_NORMA_NO_ACTIVATE        "background-color: #D4D4D4;  border-radius: 2px; border-color: blue; color: #610404;"

//#define COLOR_BUTTON_NORMA_ACTIVATE           "background-color:#D4D4D4; color:#610404;"

#define COLOR_BUTTON_NORMA_ACTIVATE             "QPushButton\
                                                 {\
                                                    background-color: #D4D4D4;\
                                                    color:#000000;\
                                                    border: 2px outset #a0a0a0;\
                                                    border-radius: 4px;\
                                                    font size: 12px;\
                                                 }\
                                                 QPushButton:pressed\
                                                 {\
                                                    background-color: #D4D4D4;\
                                                    color:#000000;\
                                                    border: 2px inset #a0a0a0;\
                                                    border-radius: 4px;\
                                                 }"



#define COLOR_BUTTON_NORMA_NO_ACTIVATE          "default"

#define COLOR_BUTTON_INVERSIA_ACTIVATE          "QPushButton\
                                                 {\
                                                    background-color: qlineargradient( x1: 0, y1: 0, x2: 0, y2: 1,\
                                                                                       stop: 0 #353434, stop: 1 #2b2929);\
                                                    color:#ECD2D2;\
                                                    border: 2px outset #858585;\
                                                    border-radius: 4px;\
                                                 }\
                                                 QPushButton:pressed\
                                                 {\
                                                    background-color: #989197;\
                                                    color:#ECD2D2;\
                                                    border: 2px inset #858585;\
                                                    border-radius: 4px;\
                                                 }"

#define COLOR_BUTTON_INVERSIA_NO_ACTIVATE       "background-color:#000000; color:#F68080; border-radius:6px"

#define COLOR_EDIT_NORMA_ACTIVATE               "background-color:#FFFFFF; color:#000000"

#define COLOR_EDIT_NORMA_NO_ACTIVATE            "default"

#define COLOR_EDIT_INVERSIA_ACTIVATE            "QLineEdit\
                                                 {\
                                                    background:qlineargradient( x1: 0, y1: 0, x2: 0, y2: 1,\
                                                                                      stop: 0 #353434, stop: 1 #2b2929);\
                                                    border-radius: 4px;\
                                                    color:#ECD2D2;\
                                                 }"

#define COLOR_EDIT_INVERSIA_NO_ACTIVATE         "border-width: 1px; border-style: solid; border-color:#000000; color:#F68080"

#define COLOR_RADIO_BUTTON_NORMA_HORIZONTAL     "QRadioButton::indicator {width: 10px; height:10px;}\
                                                 QRadioButton::indicator::unchecked {background-color:#FFFFFF;}\
                                                 QRadioButton::indicator::checked {background-color:#610404;}\
                                                 QRadioButton#inSavingOrderRadioButton{background-color:disabled;color:#000000}"

#define COLOR_RADIO_BUTTON_NORMA_SAVE           "QRadioButton::indicator {width: 10px; height:10px;}\
                                                 QRadioButton::indicator::unchecked {background-color:#FFFFFF;}\
                                                 QRadioButton::indicator::checked {background-color:#610404;}\
                                                 QRadioButton#inSavingOrderRadioButton{background-color:disabled;color:#000000}"

#define COLOR_RADIO_BUTTON_INVERSIA_HORIZONTAL  "QRadioButton::indicator {width: 10px; height:10px;}\
                                                 QRadioButton::indicator::unchecked {background-color:#989197;}\
                                                 QRadioButton::indicator::checked {background-color:#157704;}\
                                                 QRadioButton#byHorizontalCoordinateRadioButton{background-color:#000000;color:#FFFFFF;}"

#define COLOR_RADIO_BUTTON_INVERSIA_SAVE        "QRadioButton::indicator {width: 10px; height:10px;}\
                                                 QRadioButton::indicator::unchecked {background-color:#989197;}\
                                                 QRadioButton::indicator::checked {background-color:#157704;}\
                                                 QRadioButton#inSavingOrderRadioButton{background-color:#000000;color:#FFFFFF;}"

#define COLOR_GROUPE_BOX_NORMA                  "background-color:#D4D4D4; color:#000000"

#define COLOR_GROUPE_BOX_INVERSIA               "background-color:#000000; color:#FFFFFF;"

#define COLOR_LIST_WIDGET_NORMA                 "background-color:#FFFFFF; color:#610404;"

#define COLOR_LIST_WIDGET_INVERSIA              "background-color:#989197; color:#ECD2D2; border-radius:6px"


#define COLOR_LIST_NORMA                        "QListWidget::indicator {width: 10px; height:10px;}\
                                                 QListWidget::indicator::unchecked {background-color:#958E95;}\
                                                 QListWidget::indicator::checked {background-color:#610404;}\
                                                 QListWidget::item:selected{background-color:#A6A2A5;}\
                                                 QListWidget#listWidget{background-color:#FFFFFF;color:#610404}"

#define COLOR_LIST_INVERSIA                     "QListWidget::indicator {width: 10px; height:10px;}\
                                                 QListWidget::indicator::unchecked {background-color:#FFFFFF;}\
                                                 QListWidget::indicator::checked {background-color:#157704;}\
                                                 QListWidget::item:selected{background-color:#111111;color:#F68080;}\
                                                 QListWidget#listWidget{background-color:#989197;color:#ECD2D2}"

#define COLOR_BUTTON_ON_NORMA                   "background-color: #D4D4D4;\
                                                 color:#000000;\
                                                 border: 2px outset #a0a0a0;\
                                                 border-radius: 4px;"

#define COLOR_BUTTON_OFF_NORMA                  "background-color: #D4D4D4;\
                                                 color:#000000;\
                                                 border: 2px inset #a0a0a0;\
                                                 border-radius: 4px;"


#define COLOR_BUTTON_ON_INVERSIA                "background-color: qlineargradient( x1: 0, y1: 0, x2: 0, y2: 1,\
                                                                                   stop: 0 #353434, stop: 1 #2b2929);\
                                                 color:#ECD2D2;\
                                                 border: 2px outset #858585;\
                                                 border-radius: 4px;"


#define COLOR_BUTTON_OFF_INVERSIA               "background-color: qlineargradient( x1: 0, y1: 0, x2: 0, y2: 1,\
                                                                                    stop: 0 #353434, stop: 1 #2b2929);\
                                                 color:#ECD2D2;\
                                                 border: 2px inset #858585;\
                                                 border-radius: 4px;"

  #define COLOR_LABEL_NORMA_SEE                 "color:#D4D4D4"
  #define COLOR_LABEL_INVERSIA_SEE              "color:#000000"
  #define COLOR_LABEL_NORMA_DATA_SEE            "color:#D4D4D4"
  #define COLOR_LABEL_INVERSIA_DATA_SEE         "color:#000000"

  #define PICTURE_NIGHT_BUTTON                  "QPushButton#inversiaButton\
                                                 {\
                                                    background-color: #D4D4D4;\
                                                    image: url(://res/images/Moon.png);\
                                                    border: 2px outset #a0a0a0;\
                                                    border-radius: 4px;\
                                                 }\
                                                 QPushButton#inversiaButton:pressed\
                                                 {\
                                                    background-color: #D4D4D4;\
                                                    image: url(://res/images/Moon.png);\
                                                    border: 2px inset #a0a0a0;\
                                                    border-radius: 4px;\
                                                 }"

  #define PICTURE_DAY_BUTTON                    "QPushButton#inversiaButton\
                                                 {\
                                                    background-color: qlineargradient( x1: 0, y1: 0, x2: 0, y2: 1,\
                                                                                    stop: 0 #353434, stop: 1 #2b2929);\
                                                    image: url(://res/images/Sun.png);\
                                                    border: 2px outset #858585;\
                                                    border-radius: 4px;\
                                                 }\
                                                 QPushButton#inversiaButton:pressed\
                                                 {\
                                                    background-color: qlineargradient( x1: 0, y1: 0, x2: 0, y2: 1,\
                                                                                       stop: 0 #353434, stop: 1 #2b2929);\
                                                    border: 2px inset #858585;\
                                                    border-radius: 4px;\
                                                 }"

#define PICTURE_OFF_INVERSIA                   "QPushButton#exitButton\
                                                 {\
                                                    background-color: qlineargradient( x1: 0, y1: 0, x2: 0, y2: 1,\
                                                                                    stop: 0 #353434, stop: 1 #2b2929);\
                                                    image: url(://res/images/OFF_PNG_inversia.png);\
                                                    border: 2px outset #858585;\
                                                    border-radius: 4px;\
                                                 }\
                                                 QPushButton#exitButton:pressed\
                                                 {\
                                                    background-color: qlineargradient( x1: 0, y1: 0, x2: 0, y2: 1,\
                                                                                    stop: 0 #353434, stop: 1 #2b2929);\
                                                    image: url(://res/images/OFF_PNG_inversia.png);\
                                                    border: 2px inset #858585;\
                                                    border-radius: 4px;\
                                                 }"

#define PICTURE_OFF_NORMA                      "QPushButton#exitButton\
                                               {\
                                                  background-color: #D4D4D4;\
                                                  image: url(://res/images/OFF_PNG.png);\
                                                  border: 2px outset #a0a0a0;\
                                                  border-radius: 4px;\
                                               }\
                                               QPushButton#exitButton:pressed\
                                               {\
                                                  background-color: #D4D4D4;\
                                                  image: url(://res/images/OFF_PNG.png);\
                                                  border: 2px inset #a0a0a0;\
                                                  border-radius: 4px;\
                                               }"

#define PICTURE_NF_0 "rtsp://192.168.0.4:554/axis-media/media.amp?videocodec=h264&resolution=4CIF&camera=1&compression=0"
#define PICTURE_WF_0 "rtsp://192.168.0.4:554/axis-media/media.amp?videocodec=h264&resolution=4CIF&camera=2&compression=0"
#define PICTURE_TH_0 "rtsp://192.168.0.4:554/axis-media/media.amp?videocodec=h264&resolution=4CIF&camera=3&compression=0"

#define PICTURE_NF_5 "rtsp://192.168.0.4:554/axis-media/media.amp?videocodec=h264&resolution=4CIF&camera=1&compression=50"
#define PICTURE_WF_5 "rtsp://192.168.0.4:554/axis-media/media.amp?videocodec=h264&resolution=4CIF&camera=2&compression=50"
#define PICTURE_TH_5 "rtsp://192.168.0.4:554/axis-media/media.amp?videocodec=h264&resolution=4CIF&camera=3&compression=50"

#define PICTURE_NF_7 "rtsp://192.168.0.4:554/axis-media/media.amp?videocodec=h264&resolution=4CIF&camera=1&compression=70"
#define PICTURE_WF_7 "rtsp://192.168.0.4:554/axis-media/media.amp?videocodec=h264&resolution=4CIF&camera=2&compression=70"
#define PICTURE_TH_7 "rtsp://192.168.0.4:554/axis-media/media.amp?videocodec=h264&resolution=4CIF&camera=3&compression=70"

#define PICTURE_NF_9 "rtsp://192.168.0.4:554/axis-media/media.amp?videocodec=h264&resolution=4CIF&camera=1&compression=90"
#define PICTURE_WF_9 "rtsp://192.168.0.4:554/axis-media/media.amp?videocodec=h264&resolution=4CIF&camera=2&compression=90"
#define PICTURE_TH_9 "rtsp://192.168.0.4:554/axis-media/media.amp?videocodec=h264&resolution=4CIF&camera=3&compression=90"

class ControllerManager : public QThread
{
    Q_OBJECT

public:
    ControllerManager();
    ~ControllerManager();
    void closeDevice();
    void closeSocket();

    void setPause(bool state);
    void setMode(Mode pMode);
    void setStandbyMode();
    void setOperationMode();
    void setPositionDeviceDrive(long pPositionX, long pPositionY,
                                bool waitAchievementPosition);
    void setSpeedDeviceDrive(long pSpeedX, long pSpeedY);
    void setTracking(bool enabled);
    void setZoomTermo(int pState);
    void setBurstType(BurstType burst_type);
    void setJust(long pJustX, long pJustY);
    void setCorrectionTracking(int x, int y);
    void setFireType(FireType fire_type);
    void setCenterMassTracking(int x, int y);
    void setVelocityTracking(float x, float y);
    void setWindX(long pWindX);
    void setWindY(long pWindY);
    void setWeapon(WeaponType  pWeaponType);
    void setShortBurst(long pBurstShort);
    void setLongBurst(long pBurstShort);
    void setParamBarrage(long pWidthBarrage, float pDensityBarrage);
    void setTypeTracking(int pType);
    void setPermission(bool state);
    void setAutoType(AutoType pAutoType);
    void setDisplayLastAim(Aim *lAim);
    void setFlagEsc();
//    void setCamera(CameraMode pCameraMode);
    void setShotTime(int s_time);
    //get metods
    Mode getMode();
    FireType getFireType();
    long getUnitPositionX(long pPosition);
    long getDeltaX(long pTargetPosition, long pPosition);
    long getJustX();
    long getJustY();
    long getPositionEncoderX() const { return mPositionEncoderX; }
    long getPositionEncoderY() const { return mPositionEncoderY; }
    long getAmmunitionCounter() const { return mAmmunitionCounter; }
    long getShortBurst() const { return mBurstShort; }
    long getLongBurst() const { return mBurstLong; }
    bool getPermission() const { return mPermission; }
    BurstType getBurstType() const { return mBurstType; }
    AutoType getAutoType() const { return mAutoType; }
    long getWidthBarrage() const { return mWidthBarrage; }
    float getDensityBarrage() const { return mDensityBarrage; }
    int getTypeTracking() const { return mTypeTracking; }
    WeaponType getWeaponType() const { return mWeaponType; }
    CameraMode getCamera() { return mCameraMode; }
    int getShotTime();
    int getAimsSize() const { return AimList::getSingletonPtr()->size(); }

    bool isStabilization() const { return mStabilization; }
    bool isTracking() const { return mTracking; }

    void addBoltNotch();
    void correctionToFire();
    void saveAim();
    void saveJust();
    void addFire();
    void resetFire();
    void addFireTracking();
    void switchStabilization();
    void switchLight();
    void switchWiper(bool is_wiper_working);
    void closeAutoMode();
    void resetCorrectionTracking();
    void nextBurstType();
    void nextFireType();
    void nextStabilizationType();
    void querySensors();
    void queryRange();
    void queryAmmunition();

    //Joystick----------------------------
    bool         enableJoystick;

    //Zala Aero-------------------------------
    bool enabled_as;
    long pidX,pidY;
    //Joystick-------------------------------
     long lPosJoyX;
     long lPosJoyY;

public slots:
    void close();
    void queryEncoders();
    void queryVoltage();
    void setPositionEncoderX(long pPosition);
    void setPositionEncoderY(long pPosition);
    void setSpeedEncoderX(long pSpeed);
    void setSpeedEncoderY(long pSpeed);
    void setAmmunitionCounter(long pAmmunitionCounter, bool is_new);
    void setConnectedDevice(bool state);
    void setThermo(long pThermo);
    void setPressure(long pPressure, bool pcalculate);
    void setRange(long pRange);
    void setAchievementPosition(bool state);
    void setVoltageBu(int pVoltageExternal);
    void setVoltageExternal(long pVoltage);
    void setResBoltNotch(int pValue);
    void stopExecution();

protected:
    void run();

private:
    void updateEvent();
    void updateKey();
    void updateJoyKey();
    void calculateAmendment();
    void calculateBarrage();
    void queryAchievementPosition();
    void moveToNextAim();
    void moveToCorrection();
    void resetMoveToCorrection();
    float getCorrectionUp();
    float getCorrectionLeft();
    bool readShotTimes();
    bool writeShotTimes();

    AimType       mAimType;
    ControlDevice *mControlDevice;
    DeviceThread  *mDeviceThread;
    Joystick      *mJoystick;
    float         mCorrectionTrackX;
    float         mCorrectionTrackY;
    bool          flagEsc;
    //thread values---------------------------
    bool          isClose;
    QMutex        mMutexPositionEncoder;
    QMutex        mMutexPermission;
    QMutex        mMutexAchievementPosition;
    QMutex        mMutexAutoType;
    QMutex        mMutexMode;
    QMutex        mMutexRange;
    QMutex        mMutexConnectedDevice;
    QMutex        mMutexStoped;
    QMutex        mMutexStabilization;
    QMutex        mMutexTracking;
    QMutex        mMutexJust;
    QMutex        mMutexCamera;

    bool          isConnectedDevice;
    bool          lightEnabled;
    //current speed---------------------------
    long         mCurrentSpeedX;
    long         mCurrentSpeedY;

    //current position-----------------------
    long         mCurrentPositionX;
    long         mCurrentPositionY;
    long         mPositionEncoderX;
    long         mPositionEncoderY;
    bool         isPositionReached;
    bool         isCorrectionPosition;

    long         mTrackingCenterX;
    long         mTrackingCenterY;

    long         mTrackingCenterX_rec;
    long         mTrackingCenterY_rec;

    float        mTrackingVelocityX;
    float        mTrackingVelocityY;

    long         mTracking_res_x;
    long         mTracking_res_y;

    int          mTrackingX;
    int          mTrackingY;

    long         mCorrectionX;
    long         mCorrectionY;

    long         mRange;
    bool         isNewRange;

    float        int_part_x;
    float        diff_part_x;
    float        int_part_y;
    float        diff_part_y;

    JoyKeyState*     mKeyState;

    //ammution and fire----------------------
    long         mAmmunitionCounter;
    bool         isnewAmmunitionCounter;
    //Burst length
    long         mBurstShort;
    long         mBurstLong;
    BurstType    mBurstType;
    FireType     mFireType;
    AutoType     mAutoType;
    WeaponType   mWeaponType;
    Mode         mMode;
    bool         mPermission;
    bool         isResetFire;
    bool         isFire;
    bool         isFirstAimByCoord;
    bool         isStop;
    long         mWidthBarrage;
    float        mDensityBarrage;
    bool         isnewParamBarrage;
    long         mSpeedBarrage;

    JustCfg      mJustCfg[12];

    long         mWindX;
    long         mWindY;

    long         mAmendmentX;
    long         mAmendmentY;

    //tracking------------------------------
    bool         mTracking;
    int          mTypeTracking; // 0 - detector, 1 - match
    Tracking     mTrackingAmendment;
    QTimer*      mTimerEncoder;

    //stabilization-------------------------
    bool         mStabilization;

    //valtage-------------------------------
    int          mVoltageExternalBu;
    int          mVoltageBatteryBu;

    //aims----------------------------------
    bool         isBarrageLeft;
    int          mIndexCurrentAim;

    long         mThermo;
    long         mPressure;
    //ZALA
    int fKey;




    CameraMode   mCameraMode;
    struct timespec time_s;
    struct timespec time_n;

    FireType     mLastFireType;

    long         mSpeedTrackingSmoothX;
    long         mSpeedTrackingSmoothY;

    bool is_load_enabled;
    int shotCounter;

    std::map<WeaponType, int> shot_times;
    bool is_shot_times_changed;
    bool need_exit;

signals:
    void newRange(int range);
    void newJust(long justX, long justY);
    void newCorrectionCross(long x, long y);
    void newSpeedX(float x);
    void newSpeedY(float y);
    void newPositionX(long position);
    void newPositionY(long position);
    void newVoltageBu(float voltageBu);
    void newThermo(int thermo);
    void newPressure(int pressure, bool calc);
    void newVoltageExternal(float voltageExternal);
    void newPermission(bool state);
    void newAmmunitionCounter(int ammunitionCounter);
    void newFire(bool state);
    void newBurstType(BurstType burstType);
    void newFireType(FireType fireType);
    void newStabilization(bool state);
    void newLastSaved(long positionX, long positionY, int range, int numberAim);
    void newAutoMode(bool state);
    void newMode(Mode mode);
    void newLogMsg(QString log);
    void newResetLastSaved();
//    void newCameraMode(CameraMode cameraMode);
//    void newCloseTracking();
    void newClose();

   //ZALA_AS
    void newTrack(bool enabled);
    void setCamera_AC(CameraMode cameraMode);
    void acJoystick();
    void closePID();
   //ZALA_AS

    void newCocking(Cocking cocking);
    void newReset();
    void newAimType(AimType aimType);
    void setConnectedPlathorm(bool activate);
    void invertCrossColor();

    void newInversia(bool pInversia);

};

#endif // CONTROLLER_MANAGER
