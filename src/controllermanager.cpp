#include "controllermanager.h"

ControllerManager::ControllerManager()
{
    mDeviceThread        = new DeviceThread();
    mJoystick            = new Joystick();
    mControlDevice       = ControlDevice::getSingletonPtr();

    isClose              = false;
    mCurrentSpeedX       = 0;
    mCurrentSpeedY       = 0;

    //Joystick--------------------------
    lPosJoyX             = 0;
    lPosJoyY             = 0;
    enableJoystick       = true;
    pidX		 = 0;
    pidY		 = 0;
    fKey                 = 1;
    //Joystick--------------------------

    mCurrentPositionX    = 0;
    mCurrentPositionY    = 0;

    mTrackingCenterX = 0;
    mTrackingCenterY = 0;

    mTrackingCenterX_rec = 0;
    mTrackingCenterY_rec = 0;

    mCorrectionTrackX    = 0.f;
    mCorrectionTrackY    = 0.f;

    mTrackingX           = 0;
    mTrackingY           = 0;

    mCorrectionX         = 0;
    mCorrectionY         = 0;
    isPositionReached    = false;
    isCorrectionPosition = true;

    mPositionEncoderX    = 0;
    mPositionEncoderY    = 0;

    mTrackingVelocityX   = 0.0f;
    mTrackingVelocityY   = 0.0f;

    mTracking_res_x      = 0;
    mTracking_res_y      = 0;

    int_part_x           = 0.0;
    diff_part_x          = 0.0;
    int_part_y           = 0.0;
    diff_part_y          = 0.0;

    mAmmunitionCounter  = 0;

    mBurstShort          = 2;
    mBurstLong           = 6;
    mBurstType           = SHORT_BURST;
    mLastFireType        = SINGLE_FIRE;
    mFireType            = SINGLE_FIRE;
    mWeaponType          = WEAPON_KORD;
    mSpeedBarrage        = 5500;
    mMode                = MODE_SEMI_AUTO;
    mAutoType            = AUTO_TYPE_ORDER;
    mWindX               = 0;
    mWindY               = 0;

    //Zala AS
    enabled_as           = true;
    //Zala AS

    mPermission          = false;
    isFire               = false;
    isConnectedDevice    = false;
    isStop               = false;
    setPermission(mPermission);

    mRange               = 100;
    isNewRange           = false;

    mStabilization       = false;
    mTracking            = false;
    mTypeTracking        = 0;

    mVoltageExternalBu = 0;
    mVoltageBatteryBu  = 0;

    isBarrageLeft    = false;
    mIndexCurrentAim = 0;

    mWidthBarrage     = 100;
    mDensityBarrage   = 50.0f;
    isnewParamBarrage = false;
    isResetFire       = true;
    isFirstAimByCoord = false;

    mKeyState = new JoyKeyState();
    mKeyState->keyCameraNarrow = false;
    mKeyState->keyCameraThermal = false;
    mKeyState->keyCameraWide = false;
    mKeyState->keyFire = false;
    mKeyState->keyRange = false;

    mJustCfg[ 0] = CfgManager::getSingletonPtr()->getJust(1, WEAPON_KORD);
    mJustCfg[ 1] = CfgManager::getSingletonPtr()->getJust(2, WEAPON_KORD);
    mJustCfg[ 2] = CfgManager::getSingletonPtr()->getJust(3, WEAPON_KORD);
    mJustCfg[ 3] = CfgManager::getSingletonPtr()->getJust(4, WEAPON_KORD);

    mAmendmentX = 0;
    mAmendmentY = 0;

    mThermo = 15;
    mPressure = 750;

    mCameraMode = WIDE_FORMAT;

    mAimType = HOME;

    //init timers
    mTimerEncoder = new QTimer(this);
    connect(mTimerEncoder, SIGNAL(timeout()), SLOT(queryEncoders()));

//    connect(mJoystick,     SIGNAL(newLogMsg(QString)),              SIGNAL(newLogMsg(QString)));
//    connect(mDeviceThread, SIGNAL(newLogMsg(QString)),              SIGNAL(newLogMsg(QString)));
    connect(mDeviceThread, SIGNAL(newConnectedDevice(bool)),        SLOT(setConnectedDevice(bool)));
    connect(mDeviceThread, SIGNAL(newSpeedEncoderX(long)),          SLOT(setSpeedEncoderX(long)));
    connect(mDeviceThread, SIGNAL(newSpeedEncoderY(long)),          SLOT(setSpeedEncoderY(long)));
    connect(mDeviceThread, SIGNAL(newPositionEncoderX(long)),       SLOT(setPositionEncoderX(long)));
    connect(mDeviceThread, SIGNAL(newPositionEncoderY(long)),       SLOT(setPositionEncoderY(long)));
    connect(mDeviceThread, SIGNAL(newThermo(long)),                 SLOT(setThermo(long)));
    connect(mDeviceThread, SIGNAL(newPressure(long, bool)),         SLOT(setPressure(long, bool)));
    connect(mDeviceThread, SIGNAL(newAmmunitionCounter(long,bool)), SLOT(setAmmunitionCounter(long,bool)));
    connect(mDeviceThread, SIGNAL(newRange(long)),                  SLOT(setRange(long)));
    connect(mDeviceThread, SIGNAL(newAchievementPosition(bool)),    SLOT(setAchievementPosition(bool)));
    connect(mDeviceThread, SIGNAL(newVoltageExternal(long)),        SLOT(setVoltageExternal(long)));
    connect(mDeviceThread, SIGNAL(newVoltageBattery(long)),         SLOT(setVoltageExternal(long)));
    connect(mDeviceThread, SIGNAL(newClose()),                      SLOT(close()));
    connect(mDeviceThread, SIGNAL(newResBoltNotch(int)),            SLOT(setResBoltNotch(int)));

    connect(mControlDevice, SIGNAL(newQueryVoltage()), SLOT(queryVoltage()));
    connect(mControlDevice, SIGNAL(newVoltageBu(int)), SLOT(setVoltageBu(int)));



    //get keys state
    std::vector<Key> keys = mControlDevice->getKeysState();
    for (unsigned int i = 0; i < keys.size(); ++i)
    {
        if (keys[i].id == KEY_PERMISSION)
        {
            if (keys[i].state == 0)
                setPermission(false);
            else
                setPermission(true);
        }
    }
    flagEsc = false;
    mTimerEncoder->start(250);
    mDeviceThread->start();
    mControlDevice->start();
    mJoystick->open();
    is_load_enabled = true;
    shotCounter = 0;
    need_exit = false;
    lightEnabled = true;

    readShotTimes();
}

ControllerManager::~ControllerManager()
{
    stopExecution();
    msleep(200);
    writeShotTimes();
    delete mTimerEncoder;
    delete mKeyState;
    delete mControlDevice;
    delete mJoystick;
    delete mDeviceThread;
    wait(1000);
}

void ControllerManager::closeDevice()
{
    //ACTION_TO_ZERO
    mMutexConnectedDevice.lock();
    if (!isConnectedDevice)
    {
        mMutexConnectedDevice.unlock();
        close();
    }
    else
    {
        mMutexConnectedDevice.unlock();
        emit newLogMsg(tr("Platform Shutdown"));
        Action *close_action = new Action(ACTION_TYPE_CLOSE, 0);
        ActionList::getSingletonPtr()->setAction(close_action);
        msleep(1000);
    }
}

void ControllerManager::setPause(bool state)
{
    mMutexStoped.lock();
    isStop = state;
    mMutexStoped.unlock();
}

void ControllerManager::setMode(Mode pMode)
{
    mMutexMode.lock();
    mMode = pMode;
    mMutexMode.unlock();
    mMutexTracking.lock();
    mTrackingCenterX = 0;
    mTrackingCenterY = 0;
    mMutexTracking.unlock();
}

void ControllerManager::setStandbyMode()
{
    msleep(300); // ???
    Action *action = new Action(ACTION_TYPE_STAND_BY_MODE, 0);
    ActionList::getSingletonPtr()->setAction(action);
}

void ControllerManager::setOperationMode()
{
    Action *action = new Action(ACTION_TYPE_OPERATION_MODE, 0);
    ActionList::getSingletonPtr()->setAction(action);
}

void ControllerManager::setPositionDeviceDrive(long pPositionX, long pPositionY,
                                               bool waitAchievementPosition)
{
    Action *lActionPositionX = new Action(ACTION_TYPE_POSITION_X, pPositionX);
    Action *lActionPositionY = new Action(ACTION_TYPE_POSITION_Y, pPositionY);
    ActionList::getSingletonPtr()->setAction(lActionPositionX);
    ActionList::getSingletonPtr()->setAction(lActionPositionY);
    emit newReset();
    //is wait achievement
    if (waitAchievementPosition)
    {
        isPositionReached = false;
        msleep(50);
        while (!isPositionReached)
        {
            queryAchievementPosition();
            msleep(100);
        }
    }
}

void ControllerManager::setSpeedDeviceDrive(long pSpeedX, long pSpeedY)
{
    if (pSpeedX != mCurrentSpeedX || pSpeedY != mCurrentSpeedY)
    {
        Action *action_speed_x;
        Action *action_speed_y;
        action_speed_x = new Action(ACTION_TYPE_SPEED_X, pSpeedX);
        action_speed_y = new Action(ACTION_TYPE_SPEED_Y, pSpeedY);
        mCurrentSpeedX = pSpeedX;
        mCurrentSpeedY = pSpeedY;
        ActionList::getSingletonPtr()->setAction(action_speed_x);
        ActionList::getSingletonPtr()->setAction(action_speed_y);
        emit newReset();
    }
}

void ControllerManager::setTracking(bool enabled)
{
    mTracking = enabled;
}

void ControllerManager::setZoomTermo(int pState)
{
    Action *action = new Action(ACTION_TYPE_ZOOM_THERMO, pState);
    ActionList::getSingletonPtr()->setAction(action);
}

void ControllerManager::setBurstType(BurstType burst_type)
{
    mBurstType = burst_type;
    emit newBurstType(mBurstType);
}

void ControllerManager::setJust(long pJustX, long pJustY)
{
    mMutexCamera.lock();
    CameraMode lCameraMode = mCameraMode;
    mMutexCamera.unlock();
    mMutexJust.lock();
    switch (lCameraMode)
    {
        case WIDE_FORMAT:
            mJustCfg[mWeaponType * 4 + 0].JustX = pJustX;
            mJustCfg[mWeaponType * 4 + 0].JustY = pJustY;
            break;
        case NARROW_FORMAT:
            mJustCfg[mWeaponType * 4 + 1].JustX = pJustX;
            mJustCfg[mWeaponType * 4 + 1].JustY = pJustY;
            break;
        case THERMAL:
            mJustCfg[mWeaponType * 4 + 2].JustX = pJustX;
            mJustCfg[mWeaponType * 4 + 2].JustY = pJustY;
            break;
        case ZOOM_THERMAL:
            mJustCfg[mWeaponType * 4 + 3].JustX = pJustX;
            mJustCfg[mWeaponType * 4 + 3].JustY = pJustY;
            break;
    }
    mMutexJust.unlock();
    emit newCorrectionCross(0, 0);
    emit newJust(-pJustX, pJustY);
}

void ControllerManager::setCorrectionTracking(int x, int y)
{
    mMutexTracking.lock();
    mCorrectionTrackX += x;
    mCorrectionTrackY += y;
    mMutexTracking.unlock();
}

void ControllerManager::setFireType(FireType fire_type)
{
    mFireType = fire_type;
    emit newFireType(mFireType);
}

void ControllerManager::setCenterMassTracking(int x, int y)
{
    long mTracking_res_x_int;
    long mTracking_res_y_int;
    double k_p = 1.25;
    double k_int = 65.0;
    mMutexTracking.lock();
    long lX = x - DEFAULT_WIDTH / 2;
    long lY = y - DEFAULT_HEIGHT / 2;
    mMutexTracking.unlock();
    mMutexCamera.lock();
    CameraMode lCameraMode = mCameraMode;
    mMutexCamera.unlock();
    mMutexTracking.lock();

    switch (lCameraMode)
    {
        case NARROW_FORMAT:
            mTrackingCenterX = static_cast<long>(static_cast<double>(-lX)
                                                 * ANGLE_NARROW_X
                                                 / static_cast<double>(DEFAULT_WIDTH)
                                                 * DEGREE_TO_CENTIDEGREE);
            mTrackingCenterY = static_cast<long>(static_cast<double>(-lY)
                                                 * ANGLE_NARROW_Y
                                                 / static_cast<double>(DEFAULT_HEIGHT)
                                                 * DEGREE_TO_CENTIDEGREE);
            break;
        case WIDE_FORMAT:
            mTrackingCenterX = static_cast<long>(static_cast<double>(-lX)
                                                 * ANGLE_WIDE_X
                                                 / static_cast<double>(DEFAULT_WIDTH)
                                                 * DEGREE_TO_CENTIDEGREE);
            mTrackingCenterY = static_cast<long>(static_cast<double>(-lY)
                                                 * ANGLE_WIDE_Y
                                                 / static_cast<double>(DEFAULT_HEIGHT)
                                                 * DEGREE_TO_CENTIDEGREE);
            break;
        case THERMAL:
            mTrackingCenterX = static_cast<long>(static_cast<double>(-lX)
                                                 * ANGLE_THERMAL_X
                                                 / static_cast<double>(DEFAULT_WIDTH)
                                                 * DEGREE_TO_CENTIDEGREE);
            mTrackingCenterY = static_cast<long>(static_cast<double>(-lY)
                                                 * ANGLE_THERMAL_Y
                                                 / static_cast<double>(DEFAULT_HEIGHT)
                                                 * DEGREE_TO_CENTIDEGREE);
            break;
        case ZOOM_THERMAL:
            mTrackingCenterX = static_cast<long>(static_cast<double>(-lX)
                                                 * ANGLE_ZOOM_THERMAL_X
                                                 / static_cast<double>(DEFAULT_WIDTH)
                                                 * DEGREE_TO_CENTIDEGREE);
            mTrackingCenterY = static_cast<long>(static_cast<double>(-lY)
                                                 * ANGLE_ZOOM_THERMAL_Y
                                                 / static_cast<double>(DEFAULT_HEIGHT)
                                                 * DEGREE_TO_CENTIDEGREE);
            break;
    }

    mTracking_res_x = mTrackingCenterX;
    mTracking_res_y = mTrackingCenterY;

    lX += (int)mCorrectionTrackX;
    lY += (int)mCorrectionTrackY;

    switch (lCameraMode)
    {
        case NARROW_FORMAT:
            mTrackingCenterX = static_cast<long>(static_cast<double>(-lX)
                                                 * ANGLE_NARROW_X
                                                 / static_cast<double>(DEFAULT_WIDTH)
                                                 * DEGREE_TO_CENTIDEGREE);
            mTrackingCenterY = static_cast<long>(static_cast<double>(-lY)
                                                 * ANGLE_NARROW_Y
                                                 / static_cast<double>(DEFAULT_HEIGHT)
                                                 * DEGREE_TO_CENTIDEGREE);
            break;
        case WIDE_FORMAT:
            mTrackingCenterX = static_cast<long>(static_cast<double>(-lX)
                                                 * ANGLE_WIDE_X
                                                 / static_cast<double>(DEFAULT_WIDTH)
                                                 * DEGREE_TO_CENTIDEGREE);
            mTrackingCenterY = static_cast<long>(static_cast<double>(-lY)
                                                 * ANGLE_WIDE_Y
                                                 / static_cast<double>(DEFAULT_HEIGHT)
                                                 * DEGREE_TO_CENTIDEGREE);
            break;
        case THERMAL:
            mTrackingCenterX = static_cast<long>(static_cast<double>(-lX)
                                                 * ANGLE_THERMAL_X
                                                 / static_cast<double>(DEFAULT_WIDTH)
                                                 * DEGREE_TO_CENTIDEGREE);
            mTrackingCenterY = static_cast<long>(static_cast<double>(-lY)
                                                 * ANGLE_THERMAL_Y
                                                 / static_cast<double>(DEFAULT_HEIGHT)
                                                 * DEGREE_TO_CENTIDEGREE);
            break;
        case ZOOM_THERMAL:
            mTrackingCenterX = static_cast<long>(static_cast<double>(-lX)
                                                 * ANGLE_ZOOM_THERMAL_X
                                                 / static_cast<double>(DEFAULT_WIDTH)
                                                 * DEGREE_TO_CENTIDEGREE);
            mTrackingCenterY = static_cast<long>(static_cast<double>(-lY)
                                                 * ANGLE_ZOOM_THERMAL_Y
                                                 / static_cast<double>(DEFAULT_HEIGHT)
                                                 * DEGREE_TO_CENTIDEGREE);
            break;
    }

    mTracking_res_x_int = mTrackingCenterX;
    mTracking_res_y_int = mTrackingCenterY;

    switch (lCameraMode)
    {
        case NARROW_FORMAT:
            mTrackingCenterX = static_cast<long>(-k_p * static_cast<double>(lX)
                                                 * ANGLE_NARROW_X
                                                 / static_cast<double>(DEFAULT_WIDTH)
                                                 * DEGREE_TO_CENTIDEGREE);
            mTrackingCenterY = static_cast<long>(-k_p * static_cast<double>(lY)
                                                 * ANGLE_NARROW_Y
                                                 / static_cast<double>(DEFAULT_HEIGHT)
                                                 * DEGREE_TO_CENTIDEGREE);
            break;
        case WIDE_FORMAT:
            mTrackingCenterX = static_cast<long>(-k_p * static_cast<double>(lX)
                                                 * ANGLE_WIDE_X
                                                 / static_cast<double>(DEFAULT_WIDTH)
                                                 * DEGREE_TO_CENTIDEGREE);
            mTrackingCenterY = static_cast<long>(-k_p * static_cast<double>(lY)
                                                 * ANGLE_WIDE_Y
                                                 / static_cast<double>(DEFAULT_HEIGHT)
                                                 * DEGREE_TO_CENTIDEGREE);
            break;
        case THERMAL:
            mTrackingCenterX = static_cast<long>(-k_p * static_cast<double>(lX)
                                                 * ANGLE_THERMAL_X
                                                 / static_cast<double>(DEFAULT_WIDTH)
                                                 * DEGREE_TO_CENTIDEGREE);
            mTrackingCenterY = static_cast<long>(-k_p * static_cast<double>(lY)
                                                 * ANGLE_THERMAL_Y
                                                 / static_cast<double>(DEFAULT_HEIGHT)
                                                 * DEGREE_TO_CENTIDEGREE);
            break;
        case ZOOM_THERMAL:
            mTrackingCenterX = static_cast<long>(-k_p * static_cast<double>(lX)
                                                 * ANGLE_ZOOM_THERMAL_X
                                                 / static_cast<double>(DEFAULT_WIDTH)
                                                 * DEGREE_TO_CENTIDEGREE);
            mTrackingCenterY = static_cast<long>(-k_p * static_cast<double>(lY)
                                                 * ANGLE_ZOOM_THERMAL_Y
                                                 / static_cast<double>(DEFAULT_HEIGHT)
                                                 * DEGREE_TO_CENTIDEGREE);
            break;
    }

    int_part_x += mTracking_res_x_int / k_int;
    int_part_y += mTracking_res_y_int / k_int;
    mTrackingCenterX += int_part_x;
    mTrackingCenterY += int_part_y;

    switch (lCameraMode)
    {
        case NARROW_FORMAT:
            if (mTrackingCenterX > MAX_SPEED_NARROW_FORMAT_X)
                mTrackingCenterX = MAX_SPEED_NARROW_FORMAT_X;
            if (mTrackingCenterX < -MAX_SPEED_NARROW_FORMAT_X)
                mTrackingCenterX = -MAX_SPEED_NARROW_FORMAT_X;
            if (mTrackingCenterY > MAX_SPEED_NARROW_FORMAT_Y)
                mTrackingCenterY = MAX_SPEED_NARROW_FORMAT_Y;
            if (mTrackingCenterY < -MAX_SPEED_NARROW_FORMAT_Y)
                mTrackingCenterY = -MAX_SPEED_NARROW_FORMAT_Y;
            break;
        case WIDE_FORMAT:
            if (mTrackingCenterX > MAX_SPEED_WIDE_FORMAT_X)
                mTrackingCenterX = MAX_SPEED_WIDE_FORMAT_X;
            if (mTrackingCenterX < -MAX_SPEED_WIDE_FORMAT_X)
                mTrackingCenterX = -MAX_SPEED_WIDE_FORMAT_X;
            if (mTrackingCenterY > MAX_SPEED_WIDE_FORMAT_Y)
                mTrackingCenterY = MAX_SPEED_WIDE_FORMAT_Y;
            if (mTrackingCenterY < -MAX_SPEED_WIDE_FORMAT_Y)
                mTrackingCenterY = -MAX_SPEED_WIDE_FORMAT_Y;
            break;
        case THERMAL:
            if (mTrackingCenterX > MAX_SPEED_THERMAL_X)
                mTrackingCenterX = MAX_SPEED_THERMAL_X;
            if (mTrackingCenterX < -MAX_SPEED_THERMAL_X)
                mTrackingCenterX = -MAX_SPEED_THERMAL_X;
            if (mTrackingCenterY > MAX_SPEED_THERMAL_Y)
                mTrackingCenterY = MAX_SPEED_THERMAL_Y;
            if (mTrackingCenterY < -MAX_SPEED_THERMAL_Y)
                mTrackingCenterY = -MAX_SPEED_THERMAL_Y;
            break;
        case ZOOM_THERMAL:
            if (mTrackingCenterX > MAX_SPEED_ZOOM_THERMAL_X)
                mTrackingCenterX = MAX_SPEED_ZOOM_THERMAL_X;
            if (mTrackingCenterX < -MAX_SPEED_ZOOM_THERMAL_X)
                mTrackingCenterX = -MAX_SPEED_ZOOM_THERMAL_X;
            if (mTrackingCenterY > MAX_SPEED_ZOOM_THERMAL_X)
                mTrackingCenterY = MAX_SPEED_ZOOM_THERMAL_X;
            if (mTrackingCenterY < -MAX_SPEED_ZOOM_THERMAL_X)
                mTrackingCenterY = -MAX_SPEED_ZOOM_THERMAL_X;
            break;
    }


    if (abs(mTrackingCenterX) > abs(mTrackingCenterX_rec))
        mTrackingCenterX = (mTrackingCenterX - mTrackingCenterX_rec) / 2;
    if (abs(mTrackingCenterY) > abs(mTrackingCenterY_rec))
        mTrackingCenterY = (mTrackingCenterY + mTrackingCenterY_rec) / 2;

    mTrackingCenterX = static_cast<long>(static_cast<double>(mTrackingCenterX)
                                         * 425.0 / DEGREE_TO_CENTIDEGREE / 6.0);
    mTrackingCenterY = static_cast<long>(static_cast<double>(mTrackingCenterY)
                                         * 512.5 / DEGREE_TO_CENTIDEGREE / 6.0);

    mMutexTracking.unlock();
}

void ControllerManager::setVelocityTracking(float x, float y)
{
    mMutexTracking.lock();
    mTrackingVelocityX = x;
    mTrackingVelocityY = y;
    mMutexTracking.unlock();
}

void ControllerManager::setWindX(long pWindX)
{
    mWindX = pWindX;
    correctionToFire();
}

void ControllerManager::setWindY(long pWindY)
{
    mWindY = pWindY;
    correctionToFire();
}

void ControllerManager::setWeapon(WeaponType pWeaponType)
{
    mWeaponType = pWeaponType;
    mTrackingAmendment.setWeaponType(pWeaponType);
}

void ControllerManager::setShortBurst(long pBurstShort)
{
    mBurstShort = pBurstShort;
}

void ControllerManager::setLongBurst(long pBurstLong)
{
    mBurstLong = pBurstLong;
}

void ControllerManager::setParamBarrage(long pWidthBarrage, float pDensityBarrage)
{
    mWidthBarrage = pWidthBarrage;
    mDensityBarrage = pDensityBarrage;
    isnewParamBarrage = true;
}

void ControllerManager::setTypeTracking(int pType)
{
    mMutexTracking.lock();
    mTypeTracking = pType;
    mMutexTracking.unlock();
}

void ControllerManager::setPermission(bool state)
{
    mMutexPermission.lock();
    mPermission = state;
    mMutexPermission.unlock();
    emit newPermission(state);
}

void ControllerManager::setAutoType(AutoType pAutoType)
{
    mAutoType = pAutoType;
}

void ControllerManager::setDisplayLastAim(Aim *lAim)
{
    if (lAim)
        emit newLastSaved(lAim->mPositionX, lAim->mPositionY,
                          lAim->mRange, lAim->mTarget);
    else
        emit newResetLastSaved();
}

void ControllerManager::setFlagEsc()
{
    flagEsc = true;
}
/*
void ControllerManager::setCamera(CameraMode pCameraMode)
{
    mMutexCamera.lock();
    mMutexMode.lock();
//    if (mMode != MODE_TRACKING)
//    {
        mCameraMode = pCameraMode;
        switch (mCameraMode)
        {
            case NARROW_FORMAT:
                break;
            case WIDE_FORMAT:
                break;
            case THERMAL:
                setZoomTermo(0);
                break;
            case ZOOM_THERMAL:
                setZoomTermo(1);
                break;
        }
//        emit newCameraMode(pCameraMode);
//        emit setCamera_AC(pCameraMode);
//    }
    mMutexMode.unlock();
    mMutexCamera.unlock();
}
*/
void ControllerManager::setShotTime(int s_time)
{
    if (shot_times.find(mWeaponType) != shot_times.end())
    {
        if (shot_times[mWeaponType] != s_time)
        {
            shot_times[mWeaponType] = s_time;
            is_shot_times_changed = true;
        }
    }
    else
    {
        shot_times.insert(std::pair<WeaponType, int>(mWeaponType, s_time));
        is_shot_times_changed = true;
    }
}

Mode ControllerManager::getMode()
{
    return mMode;
}

FireType ControllerManager::getFireType()
{
    return mFireType;
}

long ControllerManager::getUnitPositionX(long pPosition)
{
    int numberOfRotations = 0;
    long lUnitX = 0;
    numberOfRotations = pPosition / 36000;
    lUnitX = pPosition - numberOfRotations * 36000;
     return lUnitX;
}

long ControllerManager::getDeltaX(long pTargetPosition, long pPosition)
{
    long lDelta = pTargetPosition - pPosition;
    if (lDelta < -18000)
        lDelta += 36000;
    else if (lDelta > 18000)
        lDelta -= 36000;
    return lDelta;
}

long ControllerManager::getJustX()
{
    long lJustX = 0;
    mMutexCamera.lock();
    CameraMode lCameraMode = mCameraMode;
    mMutexCamera.unlock();
    mMutexJust.lock();
    switch (lCameraMode)
    {
        case WIDE_FORMAT:
            lJustX = mJustCfg[mWeaponType * 4 + 0].JustX;
            break;
        case NARROW_FORMAT:
            lJustX = mJustCfg[mWeaponType * 4 + 1].JustX;
            break;
        case THERMAL:
            lJustX = mJustCfg[mWeaponType * 4 + 2].JustX;
            break;
        case ZOOM_THERMAL:
            lJustX = mJustCfg[mWeaponType * 4 + 3].JustX;
            break;
    }
    mMutexJust.unlock();
    return lJustX;
}

long ControllerManager::getJustY()
{
    long lJustY = 0;
    mMutexCamera.lock();
    CameraMode lCameraMode = mCameraMode;
    mMutexCamera.unlock();
    mMutexJust.lock();
    switch (lCameraMode)
    {
        case WIDE_FORMAT:
            lJustY = mJustCfg[mWeaponType * 4 + 0].JustY;
            break;
        case NARROW_FORMAT:
            lJustY = mJustCfg[mWeaponType * 4 + 1].JustY;
            break;
        case THERMAL:
            lJustY = mJustCfg[mWeaponType * 4 + 2].JustY;
            break;
        case ZOOM_THERMAL:
            lJustY = mJustCfg[mWeaponType * 4 + 3].JustY;
            break;
    }
    mMutexJust.unlock();
    return lJustY;
}

int ControllerManager::getShotTime()
{
    if (shot_times.find(mWeaponType) != shot_times.end())
        return (shot_times[mWeaponType]);
    else
        return -1;
}

void ControllerManager::addBoltNotch()
{
    Action *action = new Action(ACTION_TYPE_BOLT_NOTCH, 0);
    ActionList::getSingletonPtr()->setAction(action);
    emit newCocking(COCKING_LOAD);
}

void ControllerManager::correctionToFire()
{
    calculateAmendment();
    long newPositionX = long(atan((double)getCorrectionLeft() / (double)mRange)
                             * 180.0 * DEGREE_TO_CENTIDEGREE / M_PI)
                        + mAmendmentX;
    long newPositionY = long(atan((double)getCorrectionUp() / (double)mRange)
                             * 180.0 * DEGREE_TO_CENTIDEGREE / M_PI)
                        + mAmendmentY;
    long pJustX = 0;
    long pJustY = 0;
    mMutexCamera.lock();
    CameraMode lCameraMode = mCameraMode;
    mMutexCamera.unlock();
    mMutexJust.lock();
    switch (lCameraMode)
    {
        case WIDE_FORMAT:
            pJustX = mJustCfg[mWeaponType * 4 + 0].JustX;
            pJustY = mJustCfg[mWeaponType * 4 + 0].JustY;
            break;
        case NARROW_FORMAT:
            pJustX = mJustCfg[mWeaponType * 4 + 1].JustX;
            pJustY = mJustCfg[mWeaponType * 4 + 1].JustY;
            break;
        case THERMAL:
            pJustX = mJustCfg[mWeaponType * 4 + 2].JustX;
            pJustY = mJustCfg[mWeaponType * 4 + 2].JustY;
            break;
        case ZOOM_THERMAL:
            pJustX = mJustCfg[mWeaponType * 4 + 3].JustX;
            pJustY = mJustCfg[mWeaponType * 4 + 3].JustY;
            break;
    }
    mMutexJust.unlock();
    emit newJust(-pJustX, pJustY);
    emit newCorrectionCross(INVERT_SPEED_X * newPositionX,
                            INVERT_SPEED_Y * newPositionY);
}

void ControllerManager::saveAim()
{
    // query new range
    mMutexPositionEncoder.lock();
    // add new aim
    mMutexMode.lock();
    if (mMode == MODE_SEMI_AUTO && AimList::getSingletonPtr()->size() < 10)
    {
        mMutexMode.unlock();
        Aim *lAim = new Aim();
        lAim->mActive = true;
        lAim->mState = true;
        lAim->mPositionX = getUnitPositionX(mPositionEncoderX);
        lAim->mPositionY = mPositionEncoderY;
        lAim->mCorrectionX = getCorrectionLeft();
        lAim->mCorrectionY = getCorrectionUp();
        lAim->mRange = mRange;
        lAim->isAlive = true;
        int lTarget = AimList::getSingletonPtr()->getMaxTarget();
        lTarget++;
        lAim->mTarget = lTarget;
        AimList::getSingletonPtr()->push(lAim);
        AimList::getSingletonPtr()->setTarget(lTarget);
        emit newLastSaved(lAim->mPositionX, lAim->mPositionY, lAim->mRange, lAim->mTarget);
    }
    else
    {
        mMutexMode.unlock();
    }
    mMutexPositionEncoder.unlock();
}

void ControllerManager::saveJust()
{
    mMutexJust.lock();
    CfgManager::getSingletonPtr()->setJust(mJustCfg);
    mMutexJust.unlock();
}

void ControllerManager::addFire()
{
    correctionToFire();
    if (mPermission)
    {
        Action *lActionFireType;
        Action *lActionFire;
        mMutexMode.lock();
        mMutexTracking.lock();
        if (mMode == MODE_TRACKING)
        {
            mMutexTracking.unlock();
            mMutexMode.unlock();
            addFireTracking();
            queryAmmunition();
        }
        else
        {
            mMutexTracking.unlock();
            if (mFireType == TURN_FIRE)
            {
                Action *lActionBurst;
                lActionFireType = new Action(ACTION_TYPE_FIRE_TYPE, 1);
                if (mMode == MODE_SEMI_AUTO)
                {
                    setSpeedDeviceDrive(0, 0);
                    moveToCorrection();
                    msleep(50);
                }

                if (mBurstType == LONG_BURST)
                    lActionBurst = new Action(ACTION_TYPE_BURST_LONG,
                                              mBurstLong * 10 * shot_times[mWeaponType]);
                else
                    lActionBurst = new Action(ACTION_TYPE_BURST_SHORT,
                                              mBurstShort * 10 * shot_times[mWeaponType]);
                setSpeedDeviceDrive(0,0);
                ActionList::getSingletonPtr()->setAction(lActionBurst);
                Action *lActionBrake = new Action(ACTION_TYPE_SET_BRAKE, true);
                ActionList::getSingletonPtr()->setAction(lActionBrake);
            }
            else
            {
                lActionFireType = new Action(ACTION_TYPE_FIRE_TYPE, 0);
                isFire = true;
            }
            emit newFire(true);
            lActionFire = new Action(ACTION_TYPE_FIRE, true);
            ActionList::getSingletonPtr()->setAction(lActionFireType);
            ActionList::getSingletonPtr()->setAction(lActionFire);
            if (mFireType == TURN_FIRE)
            {
                if (mMode == MODE_SEMI_AUTO)
                {
                    setSpeedDeviceDrive(0, 0);
                    if (mBurstType == LONG_BURST)
                        msleep(mBurstLong * shot_times[mWeaponType]);
                    else
                        msleep(mBurstShort * shot_times[mWeaponType]);
                    msleep(200);
                    Action *lActionBrake = new Action(ACTION_TYPE_SET_BRAKE, false);
                    ActionList::getSingletonPtr()->setAction(lActionBrake);
                    resetMoveToCorrection();
                }
                else
                {
                    if (mBurstType == LONG_BURST)
                        msleep(mBurstLong * shot_times[mWeaponType]);
                    else
                        msleep(mBurstShort * shot_times[mWeaponType]);
                    Action *lActionBrake = new Action(ACTION_TYPE_SET_BRAKE, false);
                    ActionList::getSingletonPtr()->setAction(lActionBrake);
                    msleep(200);
                }
                queryAmmunition();
                emit newFire(false);
            }
            mMutexMode.unlock();
        }
    }
}

void ControllerManager::resetFire()
{
    mMutexMode.lock();
    if (mFireType != TURN_FIRE && isFire && mMode != MODE_TRACKING)
    {
        mMutexMode.unlock();
        isFire = false;
        Action *lActionFire = new Action(ACTION_TYPE_FIRE, false);
        ActionList::getSingletonPtr()->setAction(lActionFire);
        emit newFire(false);
        queryAmmunition();
    }
    else
    {
        mMutexMode.unlock();
    }
}

void ControllerManager::addFireTracking()
{
    correctionToFire();
    long lXDeltaCross = long(atan((double)getCorrectionLeft() / (double)mRange)
                             * 180.0 * DEGREE_TO_CENTIDEGREE / M_PI);
    long lYDeltaCross = long(atan((double)getCorrectionUp() / (double)mRange)
                             * 180.0 * DEGREE_TO_CENTIDEGREE / M_PI);
    long pJustX = 0;
    long pJustY = 0;
    mMutexCamera.lock();
    CameraMode lCameraMode = mCameraMode;
    mMutexCamera.unlock();
    mMutexJust.lock();
    switch (lCameraMode)
    {
        case WIDE_FORMAT:
            pJustX = mJustCfg[mWeaponType * 4 + 0].JustX;
            pJustY = mJustCfg[mWeaponType * 4 + 0].JustY;
            break;
        case NARROW_FORMAT:
            pJustX = mJustCfg[mWeaponType * 4 + 1].JustX;
            pJustY = mJustCfg[mWeaponType * 4 + 1].JustY;
            break;
        case THERMAL:
            pJustX = mJustCfg[mWeaponType * 4 + 2].JustX;
            pJustY = mJustCfg[mWeaponType * 4 + 2].JustY;
            break;
        case ZOOM_THERMAL:
            pJustX = mJustCfg[mWeaponType * 4 + 3].JustX;
            pJustY = mJustCfg[mWeaponType * 4 + 3].JustY;
            break;
    }
    mMutexJust.unlock();
    long lX = pJustX;
    long lY = pJustY;
    long lConvertX = 0;
    long lConvertY = 0;
    switch (lCameraMode)
    {
        case NARROW_FORMAT:
            lConvertX = static_cast<long>(static_cast<double>(lX)
                                          * ANGLE_NARROW_X
                                          * DEGREE_TO_CENTIDEGREE
                                          / DEFAULT_WIDTH);
            lConvertY = static_cast<long>(static_cast<double>(lY)
                                          * ANGLE_NARROW_Y
                                          * DEGREE_TO_CENTIDEGREE
                                          / DEFAULT_HEIGHT);
            break;
        case WIDE_FORMAT:
            lConvertX = static_cast<long>(static_cast<double>(lX)
                                          * ANGLE_WIDE_X
                                          * DEGREE_TO_CENTIDEGREE
                                          / DEFAULT_WIDTH);
            lConvertY = static_cast<long>(static_cast<double>(lY)
                                          * ANGLE_WIDE_Y
                                          * DEGREE_TO_CENTIDEGREE
                                          / DEFAULT_HEIGHT);
            break;
        case THERMAL:
            lConvertX = static_cast<long>(static_cast<double>(lX)
                                          * ANGLE_THERMAL_X
                                          * DEGREE_TO_CENTIDEGREE
                                          / DEFAULT_WIDTH);
            lConvertY = static_cast<long>(static_cast<double>(lY)
                                          * ANGLE_THERMAL_Y
                                          * DEGREE_TO_CENTIDEGREE
                                          / DEFAULT_HEIGHT);
            break;
        case ZOOM_THERMAL:
            lConvertX = static_cast<long>(static_cast<double>(lX)
                                          * ANGLE_ZOOM_THERMAL_X
                                          * DEGREE_TO_CENTIDEGREE
                                          / DEFAULT_WIDTH);
            lConvertY = static_cast<long>(static_cast<double>(lY)
                                          * ANGLE_ZOOM_THERMAL_Y
                                          * DEGREE_TO_CENTIDEGREE
                                          / DEFAULT_HEIGHT);
            break;
    }
    lXDeltaCross -= lConvertX;
    lYDeltaCross -= lConvertY;
    long lPosX1 = 0;
    long lPosY1 = 0;
    long Vx = 0;
    long Vy = 0;
    bool statecalculate = false;
    mMutexTracking.lock();
    mTrackingAmendment.setWeaponType(mWeaponType);
    mTrackingAmendment.setAmendmentBallist(mAmendmentX, mAmendmentY);
    mTrackingAmendment.setRange(mRange);
    mTrackingAmendment.setDelta(lXDeltaCross, -lYDeltaCross);
    Action *lActionBurst;
    if (mBurstType == LONG_BURST)
    {
        mTrackingAmendment.setTimeSpeed((float)mBurstLong * shot_times[mWeaponType] / 1000.f);
        lActionBurst = new Action(ACTION_TYPE_BURST_LONG, mBurstLong * 10 * shot_times[mWeaponType]);
    }
    else
    {
        mTrackingAmendment.setTimeSpeed((float)mBurstShort * shot_times[mWeaponType] / 1000.f);
        lActionBurst = new Action(ACTION_TYPE_BURST_SHORT, mBurstShort * 10 * shot_times[mWeaponType]);
    }
    statecalculate = mTrackingAmendment.getPosTargets(lPosX1, lPosY1, Vx, Vy);
    mTrackingCenterX = 0;
    mTrackingCenterY = 0;
    mTracking = false;
    mTypeTracking = 0;
    mMutexTracking.unlock();
    setSpeedDeviceDrive(0, 0);
    emit newFire(true);
    if (statecalculate)
    {
        setPositionDeviceDrive(-lPosX1, lPosY1, true);
        setSpeedDeviceDrive(Vx, -Vy);
        Action *lActionFireType = new Action(ACTION_TYPE_FIRE_TYPE, 1);
        ActionList::getSingletonPtr()->setAction(lActionBurst);
        ActionList::getSingletonPtr()->setAction(lActionFireType);
        Action *lActionFire = new Action(ACTION_TYPE_FIRE, true);
        ActionList::getSingletonPtr()->setAction(lActionFire);
        if (mBurstType == LONG_BURST)
            msleep(mBurstLong * shot_times[mWeaponType]);
        else
            msleep(mBurstShort * shot_times[mWeaponType]);
        setSpeedDeviceDrive(0, 0);
    }
    else
    {
        setSpeedDeviceDrive(0, 0);
        emit newLogMsg(tr("Error tracking"));
    }
    mCorrectionTrackX = 0;
    mCorrectionTrackY = 0;
   // emit newCloseTracking();
    emit newFire(false);
}

void ControllerManager::switchStabilization()
{
    Action *action = new Action(ACTION_TYPE_SWITCH_STABILIZATION);
    ActionList::getSingletonPtr()->setAction(action);
}

void ControllerManager::switchLight()
{
    bool result;
    if (lightEnabled)
        lightEnabled = false;
    else
        lightEnabled = true;
    result = mControlDevice->switchLight(lightEnabled);
    if (result)
    {
        if (lightEnabled)
            emit newLogMsg(tr("Backlight on"));
        else
            emit newLogMsg(tr("Backlight off"));
    }
    else
    {
        emit newLogMsg(tr("Failed to access backlight"));
    }
}

void ControllerManager::switchWiper(bool is_wiper_working)
{
    Action *action = new Action(ACTION_TYPE_SWITCH_WIPER,
                                static_cast<long>(is_wiper_working));
    ActionList::getSingletonPtr()->setAction(action);
}

void ControllerManager::closeAutoMode()
{
    resetFire();
    mMutexMode.lock();
    mMode = MODE_SEMI_AUTO;
    mMutexMode.unlock();
    isFirstAimByCoord = false;
    mIndexCurrentAim = 0;
    mFireType = mLastFireType;
    newFireType(mFireType);
    emit newAutoMode(true);
    emit newMode(MODE_SEMI_AUTO);
    AimList::getSingletonPtr()->makeAllAimsAlive();
}

void ControllerManager::resetCorrectionTracking()
{
    mCorrectionTrackX = 0;
    mCorrectionTrackY = 0;
    int_part_x = 0;
    diff_part_x = 0;
    int_part_y = 0;
    diff_part_y = 0;
}

void ControllerManager::nextBurstType()
{
    if (mBurstType == SHORT_BURST)
        mBurstType = LONG_BURST;
    else
        mBurstType = SHORT_BURST;
    emit newBurstType(mBurstType);
}

void ControllerManager::nextFireType()
{
    if (mFireType == SINGLE_FIRE)
    {
        mFireType = TURN_FIRE;
        mLastFireType = TURN_FIRE;
    }
    else
    {
        mFireType = SINGLE_FIRE;
        mLastFireType = SINGLE_FIRE;
    }
    emit newFireType(mFireType);
}

void ControllerManager::nextStabilizationType()
{
    mMutexStabilization.lock();
    if (mStabilization)
        mStabilization = false;
    else
        mStabilization = true;
    Action *action = new Action(ACTION_TYPE_STABILIZATION, mStabilization);
    ActionList::getSingletonPtr()->setAction(action);
    emit newStabilization(mStabilization);
    mMutexStabilization.unlock();
}

void ControllerManager::querySensors()
{
    Action *lActiongetTermo = new Action(ACTION_TYPE_GET_TRMO_0, 0);
    Action *lActiongetPressure = new Action(ACTION_TYPE_GET_PRESSURE, 0);
    ActionList::getSingletonPtr()->setAction(lActiongetTermo);
    ActionList::getSingletonPtr()->setAction(lActiongetPressure);
}

void ControllerManager::queryRange()
{
    mMutexRange.lock();
    isNewRange = false;
    mMutexRange.unlock();
    Action *action = new Action(ACTION_TYPE_GET_RANGE, 0);
    ActionList::getSingletonPtr()->setAction(action);
    while (true)
    {
        mMutexRange.lock();
        if (!isNewRange)
        {
            mMutexRange.unlock();
            msleep(200);
        }
        else
        {
            mMutexRange.unlock();
            break;
        }
    }
}

void ControllerManager::queryAmmunition()
{
    Action *lActionAmmunition = new Action(ACTION_TYPE_GET_AMMUNITION_COUNTER, 0);
    ActionList::getSingletonPtr()->setAction(lActionAmmunition);
}


void ControllerManager::close()
{
    isClose = true;
    emit newClose();
    mControlDevice->close();
}

void ControllerManager::queryEncoders()
{
    //query position
    Action *lActiongetPosX = new Action(ACTION_TYPE_GET_ENCODER_POSITION_X, 0);
    Action *lActiongetPosY = new Action(ACTION_TYPE_GET_ENCODER_POSITION_Y, 0);
    ActionList::getSingletonPtr()->setAction(lActiongetPosX);
    ActionList::getSingletonPtr()->setAction(lActiongetPosY);
    //query speed
    Action *lActiongetSpeedX = new Action(ACTION_TYPE_GET_ENCODER_SPEED_X, 0);
    Action *lActiongetSpeedY = new Action(ACTION_TYPE_GET_ENCODER_SPEED_Y, 0);
    ActionList::getSingletonPtr()->setAction(lActiongetSpeedX);
    ActionList::getSingletonPtr()->setAction(lActiongetSpeedY);
}

void ControllerManager::queryVoltage()
{
    Action *lActiongetVoltageBattery = new Action(ACTION_TYPE_GET_VOLTAGE_BATTERY, 0);
    ActionList::getSingletonPtr()->setAction(lActiongetVoltageBattery);
}

void ControllerManager::setPositionEncoderX(long pPosition)
{
    mMutexPositionEncoder.lock();
    mPositionEncoderX = pPosition;
    mMutexTracking.lock();
    mTrackingAmendment.setPositionsX(-mPositionEncoderX,
                                     (float)mTracking_res_x);
    mMutexTracking.unlock();
    mMutexPositionEncoder.unlock();
    emit newPositionX(pPosition);
}

void ControllerManager::setPositionEncoderY(long pPosition)
{
    mMutexPositionEncoder.lock();
    mPositionEncoderY = -pPosition;
    mMutexTracking.lock();
    mTrackingAmendment.setPositionsY(-mPositionEncoderY,
                                     (float)mTracking_res_y);
    mMutexTracking.unlock();
    mMutexPositionEncoder.unlock();
    emit newPositionY(pPosition);
}

void ControllerManager::setSpeedEncoderX(long pSpeed)
{
    mTrackingCenterX_rec = static_cast<long>(static_cast<double>(pSpeed) * 6.0 * DEGREE_TO_CENTIDEGREE / 425.0);
    float speed = static_cast<float>(pSpeed) * 6.0 / 425.0;
    switch (mMode)
    {
        case MODE_SEMI_AUTO:
            emit newSpeedX(speed);
            break;
        case MODE_TRACKING:
            {
                double lim = 0.0;
                switch (mCameraMode)
                {
                    case WIDE_FORMAT:
                        lim = 6.0;
                        break;
                    case NARROW_FORMAT:
                        lim = 1.0;
                        break;
                    case THERMAL:
                        lim = 3.0;
                        break;
                    case ZOOM_THERMAL:
                        lim = 1.5;
                        break;
                }
            if (fabs(speed) < lim)
                emit newSpeedX(speed);
            }
        break;
        case MODE_AUTO:
            if (speed != 0.0)
                emit newSpeedX(-speed);
            break;
    }
}

void ControllerManager::setSpeedEncoderY(long pSpeed)
{
    mTrackingCenterY_rec = static_cast<long>(static_cast<double>(pSpeed) * 6.0
                                             * DEGREE_TO_CENTIDEGREE / 512.5);
    float speed = static_cast<float>(pSpeed) * 6.0 / 512.5;
    switch (mMode)
    {
        case MODE_SEMI_AUTO:
            emit newSpeedY(speed);
            break;
        case MODE_TRACKING:
            {
                double lim = 0.0;
                switch (mCameraMode)
                {
                    case WIDE_FORMAT:
                        lim = 6.0;
                        break;
                    case NARROW_FORMAT:
                        lim = 1.0;
                        break;
                    case THERMAL:
                        lim = 3.0;
                        break;
                    case ZOOM_THERMAL:
                        lim = 1.5;
                        break;
                }
                if (fabs(speed) <= lim)
                    emit newSpeedY(speed);
            }
            break;
        case MODE_AUTO:
            if (speed != 0.0)
                emit newSpeedY(speed);
            break;
    }
}

void ControllerManager::setAmmunitionCounter(long pAmmunitionCounter, bool is_new)
{
    if (pAmmunitionCounter >= 0 && pAmmunitionCounter < 10000)
    {
        mAmmunitionCounter = pAmmunitionCounter;
        emit newAmmunitionCounter((int)mAmmunitionCounter);
        if (is_new)
        {
            Action *action = new Action(ACTION_TYPE_INIT_AMMUNITION_COUNTER,
                                        mAmmunitionCounter );
            ActionList::getSingletonPtr()->setAction(action);
        }
    }
}

void ControllerManager::setConnectedDevice(bool state)
{
    mMutexConnectedDevice.lock();
    isConnectedDevice = state;
    emit setConnectedPlathorm(state);
    mMutexConnectedDevice.unlock();
}

void ControllerManager::setThermo(long pThermo)
{
    mThermo = pThermo;
    emit newThermo((char)pThermo);
    correctionToFire();
}

void ControllerManager::setPressure(long pPressure, bool pcalculate)
{
    if (pcalculate)
        pPressure = FUN_PRESSURE(pPressure);
    if (pPressure < 1000000 && pPressure > 0)
    {
        mPressure = pPressure;
        emit newPressure((int)pPressure, pcalculate);
        correctionToFire();
    }
}

void ControllerManager::setRange(long pRange)
{
    mMutexRange.lock();
    mRange = pRange;
    if (mRange <= 0 || mRange > 100000)
        mRange = 1;
    emit newRange(mRange);
    correctionToFire();
    isNewRange = true;
    isCorrectionPosition = true;
    mMutexRange.unlock();
}

void ControllerManager::setAchievementPosition(bool state)
{
    mMutexAchievementPosition.lock();
    isPositionReached = state;
    mMutexAchievementPosition.unlock();
}

void ControllerManager::setVoltageBu(int pVoltageExternal)
{
    float lVoltageExternal = (float)pVoltageExternal / 10.f;
    if (lVoltageExternal > 0.0f)
        emit newVoltageBu(lVoltageExternal);
}

void ControllerManager::setVoltageExternal(long pVoltage)
{
    float voltage = (float)pVoltage / 1000.0;
    if (voltage > 1)
        emit newVoltageExternal(voltage);
}

void ControllerManager::setResBoltNotch(int pValue)
{
    setAmmunitionCounter((int)mAmmunitionCounter, true);
    if (pValue == RES_COCKING_COMPLETED)
    {
        emit newCocking(COCKING_COMPLETED);
    }
    else
    {
        emit newCocking(COCKING_ERROR);
    }
    is_load_enabled = true;
}

void ControllerManager::run()
{
    correctionToFire();
    setPermission(mPermission);
    while (!need_exit)
    {
        mMutexConnectedDevice.lock();
        mMutexStoped.lock();
        bool stoped = isStop;
        bool connected = isConnectedDevice;
        mMutexStoped.unlock();
        mMutexConnectedDevice.unlock();
        //emit acJoystick();//запуск в потоке на принудительное движение ПП
        msleep(2);
        if (connected && !stoped)
        {
            updateEvent();
            updateJoyKey();
            updateKey();
            if (!enabled_as) emit acJoystick();//запуск в потоке на принудительное движение ПП
        }
        else
        {
            msleep(2000);
        }
    }
}

void ControllerManager::updateEvent()
{
    //update joystick
    mJoystick->updateEvent();
    //set new speed

    if (enableJoystick)
    {
         lPosJoyX = mJoystick->getPosX();
         lPosJoyY = mJoystick->getPosY();
    }


    else
    {
        lPosJoyX = 0;
        lPosJoyY =0;
    }


    long lSpeedX = 0;
    long lSpeedY = 0;

    double x = static_cast<double>(abs(lPosJoyX));
    double y = static_cast<double>(abs(lPosJoyY));
    double a_x = 0.0;
    double b_x = 0.0;
    double c_x = 0.0;
    double d_x = 0.0;
    double a_y = 0.0;
    double b_y = 0.0;
    double c_y = 0.0;
    double d_y = 0.0;

    switch (mCameraMode)
    {
        case WIDE_FORMAT:
            a_x = +4.464411243e-15;
            b_x = -5.566500661e-11;
            c_x = +1.029033145e-06;
            d_x = -1.311591964e-03;
            a_y = +5.409815977e-15;
            b_y = -6.745289037e-11;
            c_y = +1.246946046e-06;
            d_y = -1.589340851e-03;
            break;
        case NARROW_FORMAT:
             a_x = +7.545483807e-16;
            b_x = -9.408170214e-12;
            c_x = +1.739210960e-07;
            d_x = -2.216775189e-04;
            a_y = +9.143350964e-16;
            b_y = -1.140048860e-11;
            c_y = +2.107514455e-07;
            d_y = -2.686209923e-04;
            break;
        case THERMAL:
            a_x = +1.949249981e-15;
            b_x = -2.430443960e-11;
            c_x = +4.492961634e-07;
            d_x = -5.726669190e-04;
            a_y = +2.362032318e-15;
             b_y = -2.945126148e-11;
            c_y = +5.444412250e-07;
            d_y = -6.939375340e-04;
            break;
        case ZOOM_THERMAL:
            a_x = +9.746249906e-16;
            b_x = -1.215221979e-11;
            c_x = +2.246480815e-07;
            d_x = -2.863334589e-04;
            a_y = +1.181061590e-15;
            b_y = -1.472563074e-11;
            c_y = +2.722206123e-07;
            d_y = -3.469687662e-04;
            break;
    }
    lSpeedX = static_cast<long>(a_x * x * x * x * x +
                                b_x * x * x * x +
                                c_x * x * x +
                                d_x * x);
    lSpeedY = static_cast<long>(a_y * y * y * y * y +
                                b_y * y * y * y +
                                c_y * y * y +
                                d_y * y);
    if (lPosJoyX < 0)
        lSpeedX = -lSpeedX;
    if (lPosJoyY < 0)
        lSpeedY = -lSpeedY;

    mMutexTracking.lock();
    if (lSpeedX > 0)
        mCorrectionTrackX += 0.35f;
    else
        if (lSpeedX < 0)
            mCorrectionTrackX -= 0.35f;
    if (lSpeedY > 0)
        mCorrectionTrackY += 0.35f;
    else
        if (lSpeedY < 0)
            mCorrectionTrackY -= 0.35f;
    mMutexTracking.unlock();
    mMutexMode.lock();
    Mode lMode = mMode;
    mMutexMode.unlock();
    if (lMode == MODE_SEMI_AUTO)
    {
        if (!is_load_enabled)
        {
            setSpeedDeviceDrive(0,0);
            return;
        }
        msleep(5);
        if (!enabled_as)
        {
//            if ((!lSpeedX) and (!lSpeedY)) setSpeedDeviceDrive(pidX,pidY);
//            else                           setSpeedDeviceDrive(lSpeedX, -lSpeedY);
//        setSpeedDeviceDrive(200,0);
        }

//        else

            setSpeedDeviceDrive(lSpeedX, -lSpeedY);
    }
    if (lMode == MODE_AUTO)
        moveToNextAim();
    if (lMode == MODE_TRACKING)
    {
        mMutexTracking.lock();
        long lSpeedTrackingX = -mTrackingCenterX;
        long lSpeedTrackingY = mTrackingCenterY;
        mMutexTracking.unlock();
        msleep(10);
        setSpeedDeviceDrive(lSpeedTrackingX, lSpeedTrackingY);
    }
}

void ControllerManager::updateKey()
{
    Key pKeyPressed;
    bool state = mControlDevice->getKeyPressed(pKeyPressed);
    if (!state)
        return;
    switch (pKeyPressed.id)
    {
        case KEY_AIM_MODE:
            if (pKeyPressed.state == 1)
            {
                if (!enabled_as)
                {
                    switch (mAimType)
                    {
                        case HOME:
                            mAimType = CAR;
                            break;
                        case CAR:
                            mAimType = HOME;
                            break;
                    }
                        emit newAimType(mAimType);
                }
            }
            break;
        case KEY_SENSORS:
            if (is_load_enabled && pKeyPressed.state == 1)
            {
                querySensors();
                emit newReset();
            }
            break;
        case KEY_TYPE_BURST:
            if (pKeyPressed.state == 1)
            if (mFireType == TURN_FIRE)
            {
                //если установлен режим по очередям
                //меняем тип очереди
                nextBurstType();
                emit newReset();
            }
            break;
        case KEY_BOLT_NOTCH:
            if (is_load_enabled && pKeyPressed.state == 1)
            {
                setSpeedDeviceDrive(0,0);
                addBoltNotch();
                emit newReset();
                is_load_enabled = false;
            }
            break;
        case KEY_PERMISSION:
            if (pKeyPressed.state == 0)
            {
                setPermission(false);
                resetFire();
            }
            else
                setPermission(true);
            emit newReset();
            break;
        case KEY_FIRE_TYPE:
            if (pKeyPressed.state == 1)
                nextFireType();
            emit newReset();
            break;
        case KEY_STABILIZATION:
            if (is_load_enabled && pKeyPressed.state == 1)
            {
                mMutexMode.lock();
                if (mMode != MODE_AUTO)
                nextStabilizationType();
                mMutexMode.unlock();
            }
            emit newReset();
            break;
        case KEY_SAVE_AIM:
            if (is_load_enabled && pKeyPressed.state == 1)
                saveAim();
            emit newReset();
            break;
        case KEY_INVERT:
            if (pKeyPressed.state == 1)
                emit invertCrossColor();
            //newLogMsg("инверсия прицела");
            emit newReset();
            break;
        case KEY_AUTO:
            if (!is_load_enabled || AimList::getSingletonPtr()->size() <= 0)
                break;
            mMutexStabilization.lock();
            mMutexTracking.lock();
            mMutexMode.lock();
            if (pKeyPressed.state == 1 && mMode != MODE_TRACKING)
            {
                if (mAutoType == AUTO_TYPE_COORDINATE)
                {
                    AimList::getSingletonPtr()->sortAims();
                    shotCounter = 0;
                }
                isFirstAimByCoord = true;
                emit newMode(MODE_AUTO);
                mMode = MODE_AUTO;
            }
            mMutexMode.unlock();
            mMutexTracking.unlock();
            mMutexStabilization.unlock();
            emit newReset();
            break;

        /*Включение сопровождения*/
        case KEY_TRACKING://Кнопка слежения
            if (is_load_enabled && pKeyPressed.state == 1)
            {
                if (enabled_as)
                {
                    //newLogMsg("включено сопровождение");
         
                    enabled_as = false;
                    emit newTrack(true);
                }
                else
                {
                    enabled_as = true;
                    emit newTrack(false);
                    //newLogMsg("выключено сопровождение");
                }
                emit newReset();
            }
            break;
    }
}

void ControllerManager::updateJoyKey()
{
    int lKey = 0;
    bool state = mJoystick->getKeyPress(lKey);
    if (state)
    {
        mMutexCamera.lock();
        //CameraMode lCameraMode = mCameraMode;
        mMutexCamera.unlock();
        switch (lKey)
        {
            case KEY_CAMERA_WIDE_FORMAT:
                if (fKey == lKey)       break;
                    emit setCamera_AC(WIDE_FORMAT);
                mCameraMode = WIDE_FORMAT;
                //newLogMsg("Широкий формат вкл");
              //  setCamera(WIDE_FORMAT);
                fKey = lKey;
                correctionToFire();
                emit newReset();
                break;
            case KEY_CAMERA_NARROW_FORMAT:
                //if (lCameraMode == NARROW_FORMAT)
                //break;
                if (fKey == lKey)
                    break;
                fKey = lKey;
                emit setCamera_AC(NARROW_FORMAT);
                mCameraMode = NARROW_FORMAT;
                //newLogMsg("Узкий формат вкл");
//                setCamera(NARROW_FORMAT);
                correctionToFire();
                emit newReset();
                break;
            case KEY_CAMERA_THERMAL:
                //if (lCameraMode == THERMAL)
                //break;
                if (fKey == lKey)
                    break;
                fKey = lKey;
                emit setCamera_AC(THERMAL);
                mCameraMode = THERMAL;
                //newLogMsg("Тепловизионный");
                //setCamera(THERMAL);
                correctionToFire();
                emit newReset();
                break;
            case KEY_CAMERA_ZOOM_THERMAL:
                //if (lCameraMode == ZOOM_THERMAL)
                //break;
                if (fKey == lKey)
                    break;
                fKey = lKey;
                emit setCamera_AC(ZOOM_THERMAL);
                mCameraMode = ZOOM_THERMAL;
                //newLogMsg("2ИК вкл");
               // setCamera(ZOOM_THERMAL);
                correctionToFire();
                emit newReset();
                break;
            case KEY_FIRE:
                if (mKeyState->keyFire)
                    break;
                mKeyState->keyFire = true;
                addFire();
                emit newReset();
                break;
            case KEY_RANGE:
                if (mKeyState->keyRange)
                    break;
                mKeyState->keyRange = true;
                queryRange();
                emit newReset();
                break;
        }
     }
    else
    {
         if (mKeyState->keyFire)
         {
             mKeyState->keyFire = false;
             resetFire();
             emit newReset();
         }
         mKeyState->keyRange = false;
     }
}

void  ControllerManager::calculateAmendment()
{
    Ballistics lBalistics;
    mMutexCamera.lock();
    mMutexCamera.unlock();
    if (lBalistics.calculate(mWeaponType, mRange, mThermo,
                             mPressure, mWindX, mWindY))
    {
        mAmendmentX = lBalistics.getAmendmentX();
        mAmendmentY = lBalistics.getAmendmentY();
    }
    else
    {
        mAmendmentX = 0;
        mAmendmentY = 0;
        emit newLogMsg(tr("Ballistic tables file not found"));
    }
}

void ControllerManager::calculateBarrage()
{
    Aim *lAimRight = AimList::getSingletonPtr()->getMaxRight();

    if (!lAimRight)
        return;

    Aim *lAimLeft = new Aim();
    lAimLeft->mPositionY = lAimRight->mPositionY;
    lAimLeft->mActive = lAimRight->mActive;
    lAimLeft->mCorrectionX = lAimRight->mCorrectionX;
    lAimLeft->mCorrectionY = lAimRight->mCorrectionY;
    lAimLeft->mRange = lAimRight->mRange;
    lAimLeft->mState = lAimRight->mState;
    lAimLeft->mTarget = lAimRight->mTarget;
    AimList::getSingletonPtr()->setAimBarrageRight(lAimRight);
    long barragePositionX = long(atan(((double)mWidthBarrage / 2)
                                      / (double)lAimRight->mRange)
                                 * 180.0 * DEGREE_TO_CENTIDEGREE / M_PI) * 2;
    lAimLeft->mPositionX  = -barragePositionX;
    AimList::getSingletonPtr()->setAimBarrageLeft(lAimLeft);
    mSpeedBarrage = long(float(atan(((float)mDensityBarrage / 2)
                                    / (float)lAimRight->mRange)
                               * 180.0 * DEGREE_TO_CENTIDEGREE / M_PI)
                         * 2.0 / 0.07);
    if (mSpeedBarrage > 4250)
        mSpeedBarrage = 4250;
    Action *action = new Action(ACTION_TYPE_SET_VELOCITY_ENABLE, mSpeedBarrage);
    ActionList::getSingletonPtr()->setAction(action);
    isnewParamBarrage = false;
}

void ControllerManager::queryAchievementPosition()
{
    Action *action = new Action(ACTION_TYPE_ACHIEVEMENT_POSITION, 0);
    ActionList::getSingletonPtr()->setAction(action);
}

void ControllerManager::moveToNextAim()
{
    Aim *lAim;
    //***********************************************************************
    //auto type by order
    //***********************************************************************
    if (mAutoType == AUTO_TYPE_ORDER)
    {
        lAim = AimList::getSingletonPtr()->get(mIndexCurrentAim);
        if (lAim)
        {
            //correction to fire
            if (lAim->mActive && lAim->isAlive)
            {
                //new range aim
                mMutexRange.lock();
                mRange = lAim->mRange;
                emit newRange(mRange);
                correctionToFire();
                mMutexRange.unlock();
                long correctionPositionX = -INVERT * (long(atan(lAim->mCorrectionX / lAim->mRange)
                                                * 180.0 * DEGREE_TO_CENTIDEGREE / M_PI) + mAmendmentX);
                long correctionPositionY = INVERT * (long(atan(lAim->mCorrectionY / lAim->mRange)
                                                * 180.0 * DEGREE_TO_CENTIDEGREE / M_PI) + mAmendmentY);
                long DeltaPositionX = 0;
                long UnitPositionX = 0;
                UnitPositionX = getUnitPositionX(mPositionEncoderX);
                DeltaPositionX = -getDeltaX(lAim->mPositionX, UnitPositionX);
                setPositionDeviceDrive(-DeltaPositionX - correctionPositionX,
                                       (mPositionEncoderY - lAim->mPositionY
                                        - correctionPositionY), true);
                mFireType = TURN_FIRE;
                emit newFireType(TURN_FIRE);
                msleep(200);
                if (mPermission)
                    addFire();
                else
                    resetFire();
                msleep(200);
                lAim->isAlive = false;
            }
            mIndexCurrentAim++;
        }
        else
        {
            closeAutoMode();
        }
    }
    //***********************************************************************
    //auto type by coordinats
    //***********************************************************************
    if (mAutoType == AUTO_TYPE_COORDINATE)
    {
        long DeltaPositionX = 0;
        long UnitPositionX = 0;
        UnitPositionX = getUnitPositionX(mPositionEncoderX);
        if (shotCounter < AimList::getSingletonPtr()->sizeActive())
        {
            lAim = AimList::getSingletonPtr()->getAimSortNext(shotCounter);
            ++shotCounter;
            mMutexRange.lock();
            mRange = lAim->mRange;
            emit newRange(mRange);
            correctionToFire();
            mMutexRange.unlock();
            long correctionPositionX = -INVERT * (long(atan(lAim->mCorrectionX
                                                            / lAim->mRange)
                                                       * 180.0
                                                       * DEGREE_TO_CENTIDEGREE
                                                       / M_PI)
                                                  + mAmendmentX);
            long correctionPositionY = INVERT * (long(atan(lAim->mCorrectionY
                                                           / lAim->mRange)
                                                      * 180.0
                                                      * DEGREE_TO_CENTIDEGREE
                                                      / M_PI)
                                                 + mAmendmentY);
            DeltaPositionX = -getDeltaX(lAim->mPositionX, UnitPositionX);
            setPositionDeviceDrive(-DeltaPositionX - correctionPositionX,
                                   (mPositionEncoderY - lAim->mPositionY
                                    - correctionPositionY), true);
            //fire
            emit newFireType(TURN_FIRE);
            mFireType = TURN_FIRE;
            msleep(200);
            if (mPermission)
                addFire();
            else
                resetFire();
            msleep(200);
            lAim->isAlive = false;
        }
        else
        {
            closeAutoMode();
        }
    }
}

void ControllerManager::moveToCorrection()
{
    long newPositionX = long(atan((double)getCorrectionLeft() / (double)mRange)
                             * 180.0 * DEGREE_TO_CENTIDEGREE / M_PI)
                        + mAmendmentX;
    long newPositionY = long(atan((double)getCorrectionUp() / (double)mRange)
                             * 180.0 * DEGREE_TO_CENTIDEGREE / M_PI)
                        + mAmendmentY;
    setPositionDeviceDrive(INVERT_SPEED_X * newPositionX,
                           INVERT_SPEED_Y * newPositionY, true);
}

void ControllerManager::resetMoveToCorrection()
{
    long newPositionX = long(atan((double)getCorrectionLeft() / (double)mRange)
                             * 180.0 * DEGREE_TO_CENTIDEGREE / M_PI) + mAmendmentX;
    long newPositionY = long(atan((double)getCorrectionUp() / (double)mRange)
                             * 180.0 * DEGREE_TO_CENTIDEGREE / M_PI) + mAmendmentY;
    setPositionDeviceDrive(-INVERT_SPEED_X * newPositionX,
                           -INVERT_SPEED_Y * newPositionY, false);
}

float ControllerManager::getCorrectionUp()
{
    float value = 0.0f;
    mMutexCamera.lock();
    CameraMode lCameraMode = mCameraMode;
    mMutexCamera.unlock();
    switch (lCameraMode)
    {
        case NARROW_FORMAT:
            value = CORRECTION_POSITION_UP_NARROW;
            break;
        case WIDE_FORMAT:
            value = CORRECTION_POSITION_UP_WHITE;
            break;
        case THERMAL:
            value = CORRECTION_POSITION_UP_HEAD;
            break;
        case ZOOM_THERMAL:
            value = CORRECTION_POSITION_UP_HEAD;
            break;
    }
    return value;
}

float ControllerManager::getCorrectionLeft()
{
    float value = 0.0f;
    mMutexCamera.lock();
    CameraMode lCameraMode = mCameraMode;
    mMutexCamera.unlock();
    switch (lCameraMode) \
    {
        case NARROW_FORMAT:
            value = CORRECTION_POSITION_LEFT_NARROW;
            break;
        case WIDE_FORMAT:
            value = CORRECTION_POSITION_LEFT_WHITE;
            break;
        case THERMAL:
            value = CORRECTION_POSITION_LEFT_HEAD;
            break;
        case ZOOM_THERMAL:
            value = CORRECTION_POSITION_LEFT_HEAD;
            break;
    }
    return value;
}

bool ControllerManager::readShotTimes()
{
    int kord;

    std::fstream i_file;
    i_file.open(SHOT_TIME_CFG, std::fstream::in);

    if (i_file.is_open())
    {
        i_file >> kord;
        if (i_file.rdstate() & (std::fstream::failbit))
        {
            kord = 70;
            is_shot_times_changed = true;
        }
        else
        {
            is_shot_times_changed = false;
        }
        i_file.close();
    }
    else
    {
        kord = 70;
        is_shot_times_changed = true;
    }

    shot_times.clear();
    shot_times.insert(std::pair<WeaponType, int>(WEAPON_KORD, kord));

    return true;
}

bool ControllerManager::writeShotTimes()
{
    if (!is_shot_times_changed)
        return true;
    
    if (shot_times.empty())
    {
        return false;
    }

    std::fstream o_file;
    o_file.open(SHOT_TIME_CFG, std::fstream::out | std::fstream::trunc);
    if (!o_file.is_open())
    {
        return false;
    }

    o_file << shot_times[WEAPON_KORD];

    o_file.close();

    return true;
}

void ControllerManager::stopExecution()
{
    need_exit = true;
}
