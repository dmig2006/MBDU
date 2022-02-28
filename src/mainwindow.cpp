#include "mainwindow.h"
#include "ui_mainwindow.h"   

/* Для создания окна,QWidget и QMainWindow являются родителями*/
MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this); //Создаем реальное окно, создается в ручную
    QPalette palette = ui->powerSupplyInfo->palette(); // подключаем использование цветового оформления
    palette.setColor(QPalette::WindowText, Qt::red);// текст красного цвета
    QIntValidator *range_validator = new QIntValidator(0, 2600, this);  // на переменную range_validator создается и настриавается виджет QIntValidator
    QIntValidator *pressure_validator = new QIntValidator(400, 800, this); // на переменную pressure_validator создается и настриавается виджет QIntValidator
    QIntValidator *temperature_validator = new QIntValidator(-45, 70, this); // на переменную *temperature_validator создается и настриавается виджет QIntValidator
    QIntValidator *wind_validator = new QIntValidator(-20, 20, this);// на переменную *wind_validator создается и настриавается виджет QIntValidator
    ui->rangeInput->setValidator(range_validator);
    ui->pressureInput->setValidator(pressure_validator);
    ui->temperatureInput->setValidator(temperature_validator);
    ui->windXInput->setValidator(wind_validator);
    ui->windYInput->setValidator(wind_validator);

    ui -> temperatureInput -> setAlignment(Qt::AlignCenter);
    ui -> pressureInput -> setAlignment(Qt::AlignCenter);
    ui -> rangeInput -> setAlignment(Qt::AlignCenter);
    ui -> windXInput -> setAlignment(Qt::AlignCenter);
    ui -> windYInput -> setAlignment(Qt::AlignCenter);

    ui -> menuBar -> hide();
    ui -> graphicsView ->hide();
    ui -> h264Button -> hide();
    ui -> mjpegButton -> hide();
    ui -> compressionTitle -> hide();
    ui -> compressionLabel -> hide();

/*
    movie = new QMovie("://res/images/123.gif");
    movie -> start();
    ui -> label_movie -> setMovie(movie);

    animationStartPause(true);
*/
    mControllerManager = new ControllerManager(); // mControllerManager содержит выделение динамической пати под виджет ControllerManager

    mVideoWidget = new VideoWidget(this); // mVideoWidget содержит колличество динамической памяти для VideoWidget
    mVideoWidget->setGeometry(5, 35, 1420, 1080); //рисуем окно для mVideoWidget

    mOptWidget = new OptWidget(this); // OptWidget содержит колличество динамической памяти для mOptWidget
    mOptWidget->setGeometry(5, 35, 1420, 1080); //прорисовка окна для mOptWidget
    mOptWidget->setControllerManager(mControllerManager); // переход из mOptWidget к setControllerManager

    mPlathormDir = new PlathormDir(this); // mPlathormDir содержит колличество динамической памяти для PlathormDir
    mPlathormDir->setGeometry(1380, 780, 430, 230); //прорисовка окна для mPlathormDir
	
	// осуществляется работа со звуковым сигналом
    mSoundSignalDialog = new SoundSignalDialog(this);
    mSoundSignalDialog->setControllerManager(mControllerManager);
    mSoundSignalDialog->hide(); //плавномерное удаление с экрана mSoundSignalDialog 

    /*Работа с виджетом Beeper*/
    mBeeper = new Beeper(this);
    mBeeper->start();  //выполнение потока путем вызова


    mTypeTracking = 0;
    mLogId = 1;
    isVideo = false;
    isFilter = true;

    isOptRange = false;
    mLogID = 0;
   // isTracking = false;

//    mTimer = new QTimer; // Таймер для пакетов 900
//    filtrTimer = new QTimer; //Пакеты 1210
//    timerD = new QTimer; //Таймер дискретизации пид

    
//    mPIDx  = new PID;
//    mPIDy  = new PID;
    mPID   = new PID;
    mPID -> page_pid = false;
//    mPIDx  -> setGeometry(820,0,180,650);
//    mPIDy  -> setGeometry(820,0,180,650);
    mPID   -> setGeometry(1470,0,180,720);

    mUdpServer = new qudpserver;
    mUdpClient = new qudpserver;

//ZALA_CLASS
    mTrackingZala = new TrackingZala();
    mTrackingZala -> setControllerManager(mControllerManager);
    mTrackingZala -> setOptWidget(mOptWidget);
    mTrackingZala -> setPID(mPID);
    mTrackingZala -> setVideoWidget(mVideoWidget);
    connect(mTrackingZala, SIGNAL(newLogMsg(QString)), SLOT(appendLog(QString)));

    inversia_stabilization = true;
//ZALA_CLASS

//VIRTUAL_KEYBOARD
    mVirtualKeyboard = new VirtualKeyboard(this);
    mVirtualKeyboard -> setGeometry(1400,660,518, 400);
    mVirtualKeyboard -> setTrackingZala(mTrackingZala);
    mVirtualKeyboard -> setControllerManager(mControllerManager);

    ui -> rangeInput -> installEventFilter(this);
    ui -> temperatureInput -> installEventFilter(this);
    ui -> windXInput -> installEventFilter(this);
    ui -> windYInput -> installEventFilter(this);
    ui -> pressureInput -> installEventFilter(this);
    ui -> LogWidget -> hide();

    flagTemp = true;
    flagPressure = true;
    flagRange = true;
    flagWindX = true;
    flagWindY = true;

    connect (mVirtualKeyboard, SIGNAL(newDataCorrection(long,long,long,long,long)),
             this, SLOT(getData(long,long,long,long,long)));
//    connect(mVirtualKeyboard, SIGNAL(newDataCorrection(long)), this, SLOT(data(long)));
    connect(mVirtualKeyboard, SIGNAL(newChar(QString)), this, SLOT(strData(QString)));
    connect (mVirtualKeyboard, SIGNAL(newExit()), this, SLOT(closeAll()));
//VIRTUAL_KEYBOARD

//ASYS
    player = new QMediaPlayer(this);//, QMediaPlayer::StreamPlayback);
    QGraphicsScene *scene = new QGraphicsScene;
    ui -> graphicsView->setScene(scene);
    scene->setSceneRect(0,10,1378,1038);
    QGraphicsVideoItem *item = new QGraphicsVideoItem;
    QSizeF th(10,10);
    th.scale(1378,1038,Qt::IgnoreAspectRatio);
    item->setSize(th);
    player->setVideoOutput(item);
    ui->graphicsView->scene()->addItem(item);
//ASYS

//SERVICE
    mService = new serviceWidget(this);
    mService -> setGeometry(1410,0,500, 630);
    mService -> setControllerManager(mControllerManager);
    connect(mService, SIGNAL(newAdjustment()), this, SLOT(adjustmentDialog()));
    connect(mService, SIGNAL(newSound()), this, SLOT(soundDialog()));
    connect(mService, SIGNAL(newStandByMode()), this, SLOT(standByMode()));
    connect(mService, SIGNAL(newOperationMode()), this, SLOT(operationMode()));
    connect(mService, SIGNAL(newH264()), this, SLOT(h264Picture()));
    connect(mService, SIGNAL(newMJPEG()), this, SLOT(mjpegPicture()));
//SERVICE


/*
    spMotorX = 0.0f;
    spMotorY = 0.0f;
    spRezult = 0.0f;
    countX  = 0;
    countY  = 0;

    mPIDx -> pid.Zona =  0.0f;    mPIDy -> pid.Zona =  0.0f;
    mPIDx -> pid.Tmls =  40.0f;   mPIDy -> pid.Tmls =  40.0f;
    mPIDx -> pid.Pves =  1.00f;   mPIDy -> pid.Pves =  1.00f;
    mPIDx -> pid.Dves =  1.00f;   mPIDy -> pid.Dves =  1.00f;
    mPIDx -> pid.MaxU =  4250.0f; mPIDy -> pid.MaxU =  4250.0;
    mPIDx -> pid.MinU = -4250.0f; mPIDy -> pid.MinU = -4250.0f;
    mPIDx -> pid.Pkff =  40.00f;  mPIDy -> pid.Pkff = 40.00f;
    mPIDx -> pid.Ikff =   9.0f;   mPIDy -> pid.Ikff =  9.0f;
    mPIDx -> pid.Dkff = 1200.0f;  mPIDy -> pid.Dkff =  1100.0f;


    server = new QSimpleServer; //выделение памяти для класса QSimpleServer
*/
//    t_indi_ac = false;
//    flag_konstr = false;
//    flag_acTrack = false;
//    invers = false;
//    setMessage( ui -> acTarget_zala,"НЕТ",safe); //вывод сообщения что слежения нет
//    setMessage( ui -> ac_target_zala,"НЕТ",safe);
//    indikator_ac = false; //флаг для просмотра включения слежения

    qRegisterMetaType <CameraMode> ("CameraMode");
    qRegisterMetaType <BurstType> ("BurstType");
    qRegisterMetaType <FireType> ("FireType");
    qRegisterMetaType <Mode> ("Mode");
    qRegisterMetaType <Cocking> ("Cocking");
    qRegisterMetaType <AimType> ("AimType");

    connect(mControllerManager, SIGNAL(newRange(int)),                   SLOT(setRange(int)));
    connect(mControllerManager, SIGNAL(newJust(long,long)),              SLOT(setJustCross(long,long)));
    connect(mControllerManager, SIGNAL(newCorrectionCross(long,long)),   SLOT(setCorrectionCross(long,long)));
    connect(mControllerManager, SIGNAL(newSpeedX(float)),                SLOT(setSpeedX(float)));
    connect(mControllerManager, SIGNAL(newSpeedY(float)),                SLOT(setSpeedY(float)));
    connect(mControllerManager, SIGNAL(newPositionX(long)),              SLOT(setPositionX(long)));
    connect(mControllerManager, SIGNAL(newPositionY(long)),              SLOT(setPositionY(long)));
    connect(mControllerManager, SIGNAL(newVoltageBu(float)),             SLOT(setVoltageBu(float)));
    connect(mControllerManager, SIGNAL(newThermo(int)),                  SLOT(setThermo(int)));
    connect(mControllerManager, SIGNAL(newPressure(int,bool)),           SLOT(setPressure(int/*, bool*/)));
    connect(mControllerManager, SIGNAL(newVoltageExternal(float)),       SLOT(setVoltage(float)));
    connect(mControllerManager, SIGNAL(newPermission(bool)),             SLOT(setPermission(bool)));
    connect(mControllerManager, SIGNAL(newAmmunitionCounter(int)),       SLOT(setAmmunitionCounter(int)));
    connect(mControllerManager, SIGNAL(newFire(bool)),                   SLOT(setFire(bool)));
    connect(mControllerManager, SIGNAL(newBurstType(BurstType)),         SLOT(setBurstType(BurstType)));
    connect(mControllerManager, SIGNAL(newFireType(FireType)),           SLOT(setFireType(FireType)));
    connect(mControllerManager, SIGNAL(newStabilization(bool)),          SLOT(setStabilization(bool)));
    connect(mControllerManager, SIGNAL(newLastSaved(long,long,int,int)), SLOT(setLastSaved(long,long,int,int)));
    connect(mControllerManager, SIGNAL(newAutoMode(bool)),               SLOT(setAutoMode(bool)));
    connect(mControllerManager, SIGNAL(newMode(Mode)),                   SLOT(setMode(Mode)));
    connect(mControllerManager, SIGNAL(newLogMsg(QString)),              SLOT(appendLog(QString)));

    connect(mControllerManager, SIGNAL(newInversia(bool)),  mOptWidget,  SLOT(inversia(bool)));

    //Babayan
    connect(mUdpServer,         SIGNAL(newLogMsg(QString)),              SLOT(appendLog(QString)));
    connect(mUdpClient,         SIGNAL(newLogMsg(QString)),              SLOT(appendLog(QString)));
    connect(mUdpServer,         SIGNAL(sendUdpParcel(UDP_Parcel)),       SLOT(reciveUdpParcel(UDP_Parcel)));
    //Babayan


    connect(mControllerManager, SIGNAL(newResetLastSaved()),             SLOT(resetLastSaved()));
    //connect(mControllerManager, SIGNAL(newCameraMode(CameraMode)),       SLOT(setCameraMode(CameraMode)));
    //Выбор рамки
    connect(mControllerManager, SIGNAL(setCamera_AC(CameraMode)), this, SLOT(setCameraMode_AC(CameraMode)));

   // connect(mControllerManager, SIGNAL(newCloseTracking()),              SLOT(closeTracking()));

    //ZALA
    //Включение автосоправождения
    connect(mControllerManager, SIGNAL (newTrack(bool)),                 SLOT (acTrack(bool)));
    //блокировка поворотной платформы
    connect(mControllerManager, SIGNAL(newTrack(bool)),mOptWidget,       SLOT(setBlockPP(bool)));
    //абсолютное перемещение рамки
//    connect(mOptWidget, SIGNAL(move_Ac_Target(long,long)),               SLOT(move_Ac_Target(long,long)));

    //connect(thread, SIGNAL(move_Ac_Target1(long,long)), this, SLOT(move_Ac_Target(long,long)));

    //Получение координат
//    connect(server, SIGNAL(FrameReady(can_frame*)), this,                SLOT(getKoordinatAc(can_frame*)));

//    connect(server, SIGNAL(newLogMsg(QString)),                          SLOT(appendLog(QString)));
    //ZALA

    connect(mControllerManager, SIGNAL(newClose()),                      SLOT(closeAll()));
    connect(mControllerManager, SIGNAL(newCocking(Cocking)),             SLOT(setCocking(Cocking)));
    connect(mControllerManager, SIGNAL(newReset()),                      SLOT(resetBeep()));
//    connect(mControllerManager, SIGNAL(newAimType(AimType)),             SLOT(setAimType(AimType)));
    connect(mControllerManager, SIGNAL(newAimType(AimType)), mTrackingZala, SLOT(setAimType(AimType)));
    connect(mControllerManager, SIGNAL(setConnectedPlathorm(bool)),      SLOT(setActivatePlathorm(bool)));
    connect(mVideoWidget, SIGNAL(newLogMsg(QString)), SLOT(appendLog(QString)));
    connect(mBeeper, SIGNAL(newLogMsg(QString)), SLOT(appendLog(QString)));

    connect(mSoundSignalDialog, SIGNAL(testPlay(BeepState)),     SLOT(testBeep(BeepState)));
    connect(mSoundSignalDialog, SIGNAL(newBeepState(BeepState)), SLOT(setBeepState(BeepState)));
    connect(mSoundSignalDialog, SIGNAL(closed()),                SLOT(enableInterface()));

//    connect(ui->actionSound_signal, SIGNAL(triggered()), SLOT(showSoundSignalDialog()));

//    connect(ui->actionAdjustment,   SIGNAL(triggered()), SLOT(showAdjustmentDialog()));

    connect(mVideoWidget, SIGNAL(resetCamera()), SLOT(resetCamera()));

    //connect(this, SIGNAL(n_off_Joystick_MW(bool)), mJoystick, SLOT(n_off_Joystick(bool))); //зануление джойстика
    connect (mControllerManager, SIGNAL(invertCrossColor()), mOptWidget, SLOT(invertCrossColor()) );
    connect (mControllerManager, SIGNAL(closePID()), mPID, SLOT(closePid()));
    //ZALA
// Выборы видеорежимов
//    connect(ui -> actionNormal_mode,                SIGNAL(triggered()),                SLOT(normalVideo_mode()));
//    connect(ui -> actionPicture_in_picture,         SIGNAL(triggered()),                SLOT(pictureInPicture_mode()));
//    connect(ui -> actionSmall_picture_in_picture,   SIGNAL(triggered()),                SLOT(smallPictureInPicture_mode()));
//    connect(ui -> actionHorizontal_line,            SIGNAL(triggered()),                SLOT(horizontalLine_mode()));
//    connect(ui -> actionVertical_line,              SIGNAL(triggered()),                SLOT(verticalLine_mode()));
//    connect(ui -> actionDigital_stabilization,      SIGNAL(triggered()),                SLOT(degitalStabilization_mode()));

    //connect(mPIDx, SIGNAL(readVarPid(float,float,float,float,float,float,float)), this, SLOT(read_var_pid(float,float,float,float,float,float,float)));
    //ZALA

//    connect (ui -> actionPID,  SIGNAL(triggered()), SLOT(pid_vkl()));

    //connect(mPID, SIGNAL(newLog(QString)),this,SLOT(appendLog(QString)));
   // connect(mPID, SIGNAL(readPidX(float,float,float,float,float,float,float,float,float)),
   //         this, SLOT(read_var_pid(float,float,float,float,float,float,float)));

    setFireType(SINGLE_FIRE);
    setBurstType(SHORT_BURST);
    setMode(MODE_SEMI_AUTO);
    setStabilization(false);
    setFire(false);
    setCameraMode_AC(WIDE_FORMAT);
    setPermission(false);
    mControllerManager->start();
    appendLog(tr("Application is runing"));

    is_ctrl_pressed = false;
    is_s_pressed = false;
    is_t_pressed = false;
    isBeepIpa = false;

    is_low_cu_voltage = false;
    is_low_rp_voltage = false;
    is_inverted_enable = false;

    is_first_beep = true;

    is_wiper_working = false;
    cur_weapon = WEAPON_KORD;

    flagActivate = false;
    flagInversia = true;
    flagPid = false;

    is_p = false;
    is_i = false;
    is_d = false;

//Babayan
    mUdpServer->start();
    trig_f11 = false;
    trig_f12 = false;
//    setMessage( ui -> ac_target_4,"Z",unsafe);
//Babayan

    setActivatePlathorm(true);
    paintNormal();
/*
    spRezult = acos(0.5);
    spRezult = spRezult * (180/acos((long double) -1));
    spRezult = 180.765432 + spRezult;
    ui -> SpR -> setText(QString::number(spRezult));
*/
}

MainWindow::~MainWindow()
{
    delete mBeeper;
    delete mSoundSignalDialog;
    delete mPlathormDir;
    delete mOptWidget;
    delete mVideoWidget;
    delete mControllerManager;

//    delete server; // Освобождение памяти qsimpleserver
//    delete mTimer; //Удаление Таймера
//    delete filtrTimer; //Удаление Таймера
//    delete mPIDx;
//    delete mPIDy;
    delete mPID;
    delete mTrackingZala;
    delete mVirtualKeyboard;

    delete player;
//    delete timerD;
    delete ui;

//SERVICE
    delete mService;
//SERVICE


//    delete movie;
}

void MainWindow::closeAll()
{    
    mVirtualKeyboard -> close();
    mVideoWidget->close();
    mOptWidget->close();
    close();
}
/*
void MainWindow::closeTracking()
{
    if (!mOptWidget)
        return;

    mOptWidget->setVisibleOptRange(false);
    ui->rangeInput->setEnabled(true);
    isOptRange = false;
    isTracking = false;
    setTracking(false, 1);
    mOptWidget->setVisibleTracking(false);
    ui->actionStand_by_mode->setEnabled(true);
    ui->actionOperation_mode->setEnabled(true);
    mControllerManager->setMode(MODE_SEMI_AUTO);
}
*/
void MainWindow::keyReleaseEvent(QKeyEvent *event)
{
    if (event->modifiers() != Qt::ControlModifier)
        is_ctrl_pressed = false;
    switch (event->key())
    {
        case Qt::Key_S:
            is_s_pressed = false;
            break;
        case Qt::Key_T:
            is_t_pressed = false;
            break;
        case Qt::Key_P:
             is_p = false;
             break;
         case Qt::Key_I:
             is_i = false;
             break;
         case Qt::Key_D:
             is_d = false;
             break;
         default:
            QWidget::keyReleaseEvent(event);
    }
}

bool MainWindow::eventFilter(QObject *object, QEvent *event)
{
    if (object == ui -> rangeInput && event -> type() == QEvent::MouseButtonPress)
    {
        QMouseEvent *mouseEvent = dynamic_cast<QMouseEvent*>(event);
        if (mouseEvent != 0 && mouseEvent -> button() == Qt::LeftButton)
        {
            mVirtualKeyboard -> delChar();

            flagTemp = false;
            flagPressure = false;
            flagRange = true;
            flagWindX = false;
            flagWindY = false;

            mVirtualKeyboard -> setFocus();
            mVirtualKeyboard -> show();
        }
    }
    else
        if (object == ui -> temperatureInput && event -> type() == QEvent::MouseButtonPress)
        {
            QMouseEvent *mouseEvent = dynamic_cast<QMouseEvent*>(event);
            if (mouseEvent != 0 && mouseEvent -> button() == Qt::LeftButton)
            {
                mVirtualKeyboard -> delChar();

                flagTemp = true;
                flagPressure = false;
                flagRange = false;
                flagWindX = false;
                flagWindY = false;

                mVirtualKeyboard -> setFocus();
                mVirtualKeyboard -> show();
            }
        }
        else
            if (object == ui -> windXInput && event -> type() == QEvent::MouseButtonPress)
            {
                QMouseEvent *mouseEvent = dynamic_cast<QMouseEvent*>(event);
                if (mouseEvent != 0 && mouseEvent -> button() == Qt::LeftButton)
                {
                    mVirtualKeyboard -> delChar();

                    flagTemp = false;
                    flagPressure = false;
                    flagRange = false;
                    flagWindX = true;
                    flagWindY = false;

                    mVirtualKeyboard -> setFocus();
                    mVirtualKeyboard -> show();
                }
            }
            else
                if (object == ui -> windYInput && event -> type() == QEvent::MouseButtonPress)
                {
                    QMouseEvent *mouseEvent = dynamic_cast<QMouseEvent*>(event);
                    if (mouseEvent != 0 && mouseEvent -> button() == Qt::LeftButton)
                    {
                        mVirtualKeyboard -> delChar();

                        flagTemp = false;
                        flagPressure = false;
                        flagRange = false;
                        flagWindX = false;
                        flagWindY = true;

                        mVirtualKeyboard -> setFocus();
                        mVirtualKeyboard -> show();
                    }
                }
                else
                    if (object == ui -> pressureInput && event -> type() == QEvent::MouseButtonPress)
                    {
                        QMouseEvent *mouseEvent = dynamic_cast<QMouseEvent*>(event);
                        if (mouseEvent != 0 && mouseEvent -> button() == Qt::LeftButton)
                        {
                            mVirtualKeyboard -> delChar();

                            flagTemp = false;
                            flagPressure = true;
                            flagRange = false;
                            flagWindX = false;
                            flagWindY = false;

                            mVirtualKeyboard -> setFocus();
                            mVirtualKeyboard -> show();
                        }
                    }
    return(QMainWindow::eventFilter(object, event));
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    static char videoType;
    if (event->modifiers() == Qt::ControlModifier)
    {
        is_ctrl_pressed = true;
        if (is_s_pressed && is_t_pressed)
        {
            flagPid = true;
            mPID -> close();            
            closeAll();
        }
    }
    else
    {
        is_ctrl_pressed = false;
    }
    switch (event->key())
    {
        case Qt::Key_S:
            is_s_pressed = true;
            resetBeep();
            if (is_ctrl_pressed && is_t_pressed)
            {
                flagPid = true;
                mPID -> close();
                closeAll();
            }
            break;
        case Qt::Key_T:
            is_t_pressed = true;
            resetBeep();
            if (is_ctrl_pressed && is_s_pressed)
            {
                flagPid = true;
                mPID -> close();
                closeAll();
            }
            break;
        case Qt::Key_Escape:
            resetBeep();
            mControllerManager->closeAutoMode();
/*            if (mOptWidget && isTracking) {
                mOptWidget->setVisibleOptRange(false);
                ui->rangeInput->setEnabled(true);
                isOptRange = false;
                //setTracking(true, 1);
                mControllerManager->resetCorrectionTracking();
                ui->actionStand_by_mode->setEnabled(true);
                ui->actionOperation_mode->setEnabled(true);
                mOptWidget->setVisibleTracking(false);
                mControllerManager->setMode(MODE_SEMI_AUTO);
                mControllerManager->setFlagEsc();
            }
*/          break;
        case Qt::Key_F1:
            resetBeep();
            if (mOptWidget)
            {
                if (!isOptRange)
                {
                    mOptWidget->setVisibleOptRange(true);
                    ui->rangeInput->setEnabled(false);
                    isOptRange= true;
                }
                else
                {
                    mOptWidget->setVisibleOptRange(false);
                    ui->rangeInput->setEnabled(true);
                    isOptRange= false;
                }
            }
            break;
        case Qt::Key_F2:
            resetBeep();
            if (mOptWidget && isOptRange)
                mOptWidget->optRangeUp();
            break;
        case Qt::Key_F3:
            resetBeep();
            if (mOptWidget && isOptRange)
                mOptWidget->optRangeDown();
            break;
        case Qt::Key_F4:
            resetBeep();
            if (!mOptWidget->getFilter())
            {
                mOptWidget->setFilter(true);
                appendLog(tr("Filter enabled"));
            }
            else
            {
                mOptWidget->setFilter(false);
                appendLog(tr("Filter disabled"));
            }
            break;
        case Qt::Key_F5:
            //Babayan
            //mUdpClient->sendUdpTest();
            mOptWidget->setPixmapOptEnabled();
            break;

        case Qt::Key_F6:/*Возвращае поворотную платформу в нулевое положение*/
            {
                Action *close_action = new Action(ACTION_TO_ZERO,0);
                ActionList::getSingletonPtr()->setAction(close_action);
            }
            break;

        case Qt::Key_F7:
            inversia();
            break;

        case Qt::Key_F8:
            if (!invers)
            {
//                appendLog("Normal mode");
                mTrackingZala -> inversiaModeAc(true);
                invers = true;
                break;
            }
            else
            {
//                appendLog("Normal mode");
                mTrackingZala -> inversiaModeAc(false);
                invers = false;
                break;
            }

/*По клавише F9 изменение камерыpid*/
        case Qt::Key_F9:
            videoType++;
            if (videoType > 3) videoType = 0;
            switch (videoType)
            {
                case 0:
                    setCameraMode_AC(WIDE_FORMAT);
               // mControllerManager -> setCamera(WIDE_FORMAT);
               /* txf.can_dlc = 4;
                txf.can_id = 1211;
                txf.data[0] =0b00000100;
                txf.data[1] =0b00000000;
                txf.data[2] =0b00000000;
                txf.data[3] =0b00000000;
//                    appendLog("Normal mode");
                server->FramesToBytes(&txf);
    */
//        mTrackingZala -> normalMode();
                    break;
            case 1:
            setCameraMode_AC(NARROW_FORMAT);
              //  mControllerManager ->setCamera(NARROW_FORMAT);
               /* txf.can_dlc = 4;
                txf.can_id = 1211;
                txf.data[0] =0b00000110;
                txf.data[1] =0b00000000;
                txf.data[2] =0b00000000;
                txf.data[3] =0b00000000;
//                    appendLog("Picture in Picture");
                server->FramesToBytes(&txf);
               */
//        mTrackingZala -> pictureInPicture();
         break;
            case 2:
            setCameraMode_AC(THERMAL);
             //   mControllerManager -> setCamera(THERMAL);
               /* txf.can_dlc = 4;
                txf.can_id = 1211;
                txf.data[0] =0b00001111;
                txf.data[1] =0b00000000;
                txf.data[2] =0b00000000;
                txf.data[3] =0b00000000;
//                    appendLog("Small picture in picture");
                server->FramesToBytes(&txf);
               */
//        mTrackingZala->smallPictureInPicture();
         break;
            case 3:
            setCameraMode_AC(ZOOM_THERMAL);
           //     mControllerManager -> setCamera(ZOOM_THERMAL);
/*
                txf.can_dlc = 4;
                txf.can_id = 1211;
                txf.data[0] =0b00001101;
                txf.data[1] =0b00000000;
                txf.data[2] =0b00000000;
                txf.data[3] =0b00000000;
//                    appendLog("Horizontal line");
                server->FramesToBytes(&txf);
*///		mTrackingZala->horizontalLine();
                break;
            case 4:

               /* txf.can_dlc = 4;
                txf.can_id = 1211;
                txf.data[0] =0b00001110;
                txf.data[1] =0b00000000;
                txf.data[2] =0b00000000;
                txf.data[3] =0b00000000;
//                    appendLog("Vertical line");
                server->FramesToBytes(&txf);
              *///mTrackingZala -> verticalLine();
          break;
    }
        break;


        case Qt::Key_F11:                   //Включения обработки координат от Бабаяна
            if (!trig_f11) trig_f11 = true; //используется в MainWindow::reciveUdpParcel(UDP_Parcel udpReciveParcel)
            else           trig_f11 = false;//используется в MainWindow::reciveUdpParcel(UDP_Parcel udpReciveParcel)

            if ((trig_f11) & (!mControllerManager->enabled_as))
            {
                //setMessage( ui -> ac_target_4,"V",unsafe);
            }
            else
            {
                //setMessage( ui -> ac_target_4,"Z",unsafe);
                //udpRecive.x    = 0;
                //udpRecive.y    = 0;
            }
            //mControllerManager -> enableJoystick = false; //Выключение джойстика
            //appendLog("Джойстик заблокирован");
            break;
            /*Перемещение относительно центра рамки, по стрелки вверх*/
                   case Qt::Key_Up:
                       if (!(mControllerManager -> enabled_as))
                       {
                   /*        txf.can_dlc = 4;	//Длина поля данных в байтах
                           txf.can_id = 1212;  //0x05e5 функция включения адресс
                           txf.data[0] = static_cast<int8_t>(0); //коордианата x постоянна
                           txf.data[1] = static_cast<int8_t>(1); //координата y изменяется на +1
                           txf.data[2] = 0x00;
                           txf.data[3] = 0x80;
                           server->FramesToBytes(&txf);
   */                       mTrackingZala -> upMove();
                       }
   //			appendLog("up");
                       break;

            /*Перемещение относительно центра рамки, по стрелке вниз*/
                   case Qt::Key_Down:
                       if (!(mControllerManager -> enabled_as))
                       {
                          /* txf.can_dlc = 4;	//Длина поля данных в байтах
                           txf.can_id = 1212;  //0x05e5 функция включения адресс
                           txf.data[0] = static_cast<int8_t>(0); //коордианата x постоянна
                           txf.data[1] = static_cast<int8_t>(-1); //координата y изменяется на -1
                           txf.data[2] = 0x00;
                           txf.data[3] = 0x80;
                           server->FramesToBytes(&txf);
   */			mTrackingZala -> downMove();
            }
   //	                appendLog("down");
           break;

           /*Перемещение относительно центра рамки,по стрелке влево*/
                   case Qt::Key_Left:
                       if (!(mControllerManager -> enabled_as))
                       {
                          /* txf.can_dlc = 4;	//Длина поля данных в байтах
                           txf.can_id = 1212;  //0x05e5 функция включения адресс
                           txf.data[0] = static_cast<int8_t>(-1); //коордианата x изменяется на -1
                           txf.data[1] = static_cast<int8_t>(0); //координата y постоянна
                           txf.data[2] = 0x00;
                           txf.data[3] = 0x80;
                           server->FramesToBytes(&txf);
                           */ mTrackingZala -> leftMove();
           }
   //			appendLog("left");
           break;

           /*Перемещение относительно центра рамки,по стрелке вправо*/
                   case Qt::Key_Right:
                       if (!(mControllerManager -> enabled_as))
                       {/*
                           txf.can_dlc = 4;	//Длина поля данных в байтах
                           txf.can_id = 1212;  //0x05e5 функция включения адресс
                           txf.data[0] = static_cast<int8_t>(1); //коордианата x изменяется на +1
                           txf.data[1] = static_cast<int8_t>(0); //координата y постоянна
                           txf.data[2] = 0x00;
                           txf.data[3] = 0x80;
                           server->FramesToBytes(&txf);
   */			mTrackingZala -> rightMove();
                       }
   //			  appendLog("right");
           break;

    case Qt::Key_P:
        is_p = true;
        if (is_i && is_d)
        {
            mPID -> show();
            is_p = false;
        }

    break;

    case Qt::Key_I:
        is_i = true;
        if (is_p && is_d)
        {
            mPID->show();
            is_i = false;
        }
    break;

case Qt::Key_D:
        is_d = true;
        if (is_p && is_i)
        {
            mPID->show();
            is_d = false;
        }
    break;
/*
    case Qt::Key_Alt:
        mControllerManager -> enabled_as = false;
        acTrack(true);
        break;

    case Qt::Key_Shift:
        mControllerManager -> enabled_as = true;
        acTrack(false);
        break;
*/
     }
}

/*
void MainWindow::nextTracking()
{
    if (!mOptWidget)
        return;
    if (!isTracking) {
        mOptWidget->setNullRect();
        setTracking(true, 1);
        mOptWidget->setVisibleTracking(false);
        ui->actionStand_by_mode->setEnabled(false);
        ui->actionOperation_mode->setEnabled(false);
        mControllerManager->setMode(MODE_SEMI_AUTO);
        mControllerManager->setTracking(true);
    } else {
        mOptWidget->setNullRect();
        setTracking(false, 1);
        mOptWidget->setVisibleTracking(false);
        ui->actionStand_by_mode->setEnabled(true);
        ui->actionOperation_mode->setEnabled(true);
        mControllerManager->setMode(MODE_SEMI_AUTO);
        mControllerManager->setTracking(false);
    }
}
*/
void MainWindow::appendLog(QString pStr)
{
    QListWidgetItem *newItem = new QListWidgetItem;
    QString num;
    num.setNum(mLogId);
    newItem->setText(num + QString("> ") + pStr);
    ui->LogWidget->insertItem(1, newItem);
    mLogId++;
}
/*
void MainWindow::setTracking(bool state, int pType)
{
    if (mOptWidget) {
        mOptWidget->setTracking(state);
        mOptWidget->setTypeTracking(pType);
    }
    isTracking = state;
    if (state) {
        if (pType == 0) {
            ui->tracking->setText(tr("DETECTOR"));
        } else {
            ui->tracking->setText(tr("ON"));
        }
    } else {
        mControllerManager->resetCorrectionTracking();
        ui->tracking->setText(tr("OFF"));
    }
}
*/
/*
void MainWindow::setTargets(std::vector<QRect> pTargets)
{
     mOptWidget->setTargets(pTargets);
}
*/
void MainWindow::setCocking(Cocking pCocking)
{
    switch (pCocking)
    {
        case COCKING_LOAD:
            setMessage(ui->cocking, tr("LOADING"));
            setInterfaceInteractivity(false);
            mOptWidget->setCocking(true);
            break;
        case COCKING_COMPLETED:
            setMessage(ui->cocking, tr("COMPLETED"));
            setInterfaceInteractivity(true);
            mOptWidget->setCocking(false);
            break;
        case COCKING_ERROR:
            setMessage(ui->cocking, tr("ERROR"), unsafe);
            setInterfaceInteractivity(true);
            mOptWidget->setCocking(false);
            break;
    }
}

void MainWindow::setAutoMode(bool state)
{
    if (AimList::getSingletonPtr()->size() > 0)
    {
        ui->deleteAimButton->setEnabled(state);
        ui->editAimButton->setEnabled(state);
        ui->autoModeButton->setEnabled(state);
    }
}

void MainWindow::setSpeedX(float pSpeed)
{
    if (pSpeed >= 59.98)
        pSpeed = 60.0;
    if (pSpeed <= -59.98)
        pSpeed = -60.0;
    ui->horizontalSpeed->setText(QString::number(pSpeed, 'f', 2));
}

void MainWindow::setSpeedY(float pSpeed)
{
    if (pSpeed >= 59.98)
        pSpeed = 60.0;
    if (pSpeed <= -59.98)
        pSpeed = -60.0;
    ui->verticalSpeed->setText(QString::number(pSpeed, 'f', 2));
}

void MainWindow::setPositionX(long pPosition)
{
    mOptWidget->setPositionEncoderX(pPosition);
    float angle = 0.0f;
    angle = static_cast<float>(pPosition) / DEGREE_TO_CENTIDEGREE
            - (((int)(static_cast<float>(pPosition) / DEGREE_TO_CENTIDEGREE) / 360) * 360);
    if (angle < 0.0f)
        angle += 360.0f;
    mPlathormDir->setAngle(angle);
    ui->horizontalAngle->setText(QString::number(angle, 'f', 2)
                                 + QString(QChar(0x00b0)));
}

void MainWindow::setPositionY(long pPosition)
{
    mOptWidget->setPositionEncoderY(pPosition);
    ui->verticalAngleSlider->setValue(pPosition);
    if (pPosition >= 5998)
        pPosition = 6000;
    if (pPosition <= -1998)
        pPosition = -2000;
    float angle = static_cast<double>(pPosition) / DEGREE_TO_CENTIDEGREE;
    ui->verticalAngle->setText(QString::number(angle, 'f', 2)
                               + QString(QChar(0x00b0)));
}

void MainWindow::setVoltageBu(float pVoltageExternal)
{
    if (pVoltageExternal < 20.0)
    {
        setMessage(ui->controlUnitVoltage,
                   QString::number(pVoltageExternal, 'f', 1),
                   unsafe);
        appendLog(tr("WARNING!! LOW CU VOLTAGE"));
        setMessage(ui->powerSupplyInfo, tr("WARNING!! LOW VOLTAGE"), unsafe);
        is_low_cu_voltage = true;
        mBeeper->setBatteryBeepFlag(true, is_first_beep);
        is_first_beep = false;
    }
    else
        if (!is_low_rp_voltage)
        {
            setMessage(ui->controlUnitVoltage,
                       QString::number(pVoltageExternal, 'f', 1),
                       neutral);
            is_low_cu_voltage = false;
            ui->powerSupplyInfo->clear();
            mBeeper->setBatteryBeepFlag(false, false);
            is_first_beep = true;
        }
        else
            if (is_low_rp_voltage)
            {
                is_first_beep = false;
                is_low_cu_voltage = false;
                setMessage(ui->controlUnitVoltage,
                        QString::number(pVoltageExternal, 'f', 1),
                        neutral);
            }
}

void MainWindow::setThermo(int pThermo)
{
    ui->temperatureInput->setText(QString::number(pThermo));
}

void MainWindow::setPressure(int pPressure)
{
    ui->pressureInput->setText(QString::number(pPressure));
}

void MainWindow::setVoltage(float pVoltage)
{
    if (pVoltage < 22.0)
    {
        setMessage(ui->rotatingPlatformVoltage,
                   QString::number(pVoltage, 'f', 1),
                   unsafe);
        appendLog(tr("WARNING!! LOW RP VOLTAGE"));
        setMessage(ui->powerSupplyInfo, tr("WARNING!! LOW VOLTAGE"), unsafe);
        is_low_rp_voltage = true;
        mBeeper->setBatteryBeepFlag(true, is_first_beep);
        is_first_beep = false;
    }
    else
        if (!is_low_cu_voltage)
        {
            setMessage(ui->rotatingPlatformVoltage,
                       QString::number(pVoltage, 'f', 1),
                       neutral);
            is_low_rp_voltage = false;
            ui->powerSupplyInfo->clear();
            mBeeper->setBatteryBeepFlag(false, false);
            is_first_beep = true;
        }
        else
            if (is_low_cu_voltage)
            {
                is_first_beep = false;
                is_low_rp_voltage = false;
                setMessage(ui->rotatingPlatformVoltage,
                        QString::number(pVoltage, 'f', 1),
                        neutral);
            }
}

void MainWindow::setRange(int pRange)
{
    ui->rangeInput->setText(QString::number(pRange));
    mOptWidget->setRange(pRange);
}

void MainWindow::setAmmunitionCounter(int pAmmunitionCounter)
{
    if (pAmmunitionCounter >= 0)
        ui->ammunition->setText(QString::number(pAmmunitionCounter));
}

void MainWindow::setPermission(bool state)
{
    if (state)
        setMessage(ui->fireResolution, tr("ARM"), unsafe);
    else
        setMessage(ui->fireResolution, tr("SAFE"), safe);
}

void MainWindow::setBurstType(BurstType pBurstType)
{
    if (mControllerManager->getFireType() == TURN_FIRE)
        switch (pBurstType)
        {
            case SHORT_BURST:
                ui->burstType->setText(tr("SHORT"));
                break;
            case LONG_BURST:
                ui->burstType->setText(tr("LONG"));
                break;
        }
}

void MainWindow::setFireType(FireType pFireType)
{
    switch (pFireType)
    {
        case SINGLE_FIRE:
            ui->fireType->setText(tr("CONT."));
            ui->burstType->setText("---");
            break;
        case TURN_FIRE:
            ui->fireType->setText(tr("BURST"));
            BurstType pBurstType = mControllerManager->getBurstType();
            switch (pBurstType)
            {
                case SHORT_BURST:
                    ui->burstType->setText(tr("SHORT"));
                    break;
                case LONG_BURST:
                    ui->burstType->setText(tr("LONG"));
                    break;
            }
            break;
    }
}

void MainWindow::setCorrectionCross(long pCorrectionX, long pCorrectionY)
{
    if (mOptWidget)
        mOptWidget->setCorrectionCross(pCorrectionX, pCorrectionY);
}

void MainWindow::setJustCross(long pJutsX, long pJutsY)
{
    if (mOptWidget)
        mOptWidget->setJustCross(pJutsX, pJutsY);
}

void MainWindow::setStabilization(bool state)
{
    if (state)
        ui->stabilization->setText(tr("ON"));
    else
        ui->stabilization->setText(tr("OFF"));
    mOptWidget->setStabilization(state);
}

void MainWindow::setFire(bool state)
{
    if (state)
        setMessage(ui->fire, tr("YES"), unsafe);
    else
        setMessage(ui->fire, tr("NO"), safe);
}

void MainWindow::setMode(Mode pMode)
{
    switch (pMode)
    {
        case MODE_AUTO:
            //ui->mode->setText(tr("AUTO"));
            break;
        case MODE_SEMI_AUTO:
            //ui->mode->setText(tr("SEMI AUTO"));
            break;
        case MODE_TRACKING:
            break;
    }
}

void MainWindow::setLastSaved(long pPositionX, long pPositionY, int pRange,  int pNumberAim)
{
    float x = static_cast<float>(pPositionX) / DEGREE_TO_CENTIDEGREE;
    float y = static_cast<float>(pPositionY) / DEGREE_TO_CENTIDEGREE;
    if (x < 0.0f)
        x += 360.0f;
    if (AimList::getSingletonPtr()->size() > 0)
    {
        ui->editAimButton->setEnabled(true);
        ui->deleteAimButton->setEnabled(true);
    }
    else
    {
        ui->editAimButton->setEnabled(false);
        ui->deleteAimButton->setEnabled(false);
    }
    ui->horizontalAimCoordinate->setText(tr("hor.: ") + QString::number(x, 'f', 2)
                                         + QChar(0x00b0));
    ui->verticalAimCoordinate->setText(tr("ver.: ") + QString::number(-y, 'f', 2)
                                       + QChar(0x00b0));
    ui->aimDistance->setText(QString::number(pRange) + tr(" m"));
    ui->aimNumber->setText(QString::number(pNumberAim));
}

void MainWindow::on_actionBurst_length_triggered()
{
    mControllerManager->setPause(true);
    setInterfaceInteractivity(false);
    mBurstLengthDialog.setControllerManager(mControllerManager);
    mBurstLengthDialog.exec();
    setInterfaceInteractivity(true);
    mControllerManager->setPause(false);
}

/*
void MainWindow::on_actionAmmunition_triggered()
{
    mControllerManager->setPause(true);
    setInterfaceInteractivity(false);
    mAmmunitionDialog.setControllerManager(mControllerManager);
    mAmmunitionDialog.exec();
    setInterfaceInteractivity(true);
    mControllerManager->setPause(false);
}
*/
void MainWindow::on_editAimButton_clicked()
{
    mControllerManager->setPause(true);
    setInterfaceInteractivity(false);

    TargetEditorDialog mTargetEditorDialog(this);
    mTargetEditorDialog.setControllerManager(mControllerManager);


    if (flagInversia)
    {
        //appendLog("NORMA");
        mTargetEditorDialog.setStyleSheet(COLOR_FON_NORMA);
        mTargetEditorDialog.colorInversia(true);
    }
    else
    {
        //appendLog("INVERSIA");
        mTargetEditorDialog.setStyleSheet(COLOR_FON_INVERSIA);
        mTargetEditorDialog.colorInversia(false);
    }

    mTargetEditorDialog.exec();

    setInterfaceInteractivity(true);
    mControllerManager->setPause(false);
}

void MainWindow::on_autoModeButton_clicked()
{
    mControllerManager->setPause(true);
    setInterfaceInteractivity(false);
    mAutoModeTypeDialog.setControllerManager(mControllerManager);
    mAutoModeTypeDialog.exec();
    setInterfaceInteractivity(true);
    mControllerManager->setPause(false);
}

void MainWindow::on_rangeInput_editingFinished()
{
/*
    long lRange = ui->rangeInput->text().toLong();
    mControllerManager->setRange(lRange);
*/
}
/*
void MainWindow::on_actionStand_by_mode_triggered()
{
    mVideoWidget->setOperationMode(false, false);
    mControllerManager->setStandbyMode();

//    animationStartPause(true);

    ui->actionStand_by_mode->setChecked(true);
    ui->actionOperation_mode->setChecked(false);
    mOptWidget->setOperationMode(false);
}
*/
/*
void MainWindow::on_actionOperation_mode_triggered()
{
    mVideoWidget->setOperationMode(true, false);
    mControllerManager->setOperationMode();

//    animationStartPause(false);

    ui->actionOperation_mode->setChecked(true);
    ui->actionStand_by_mode->setChecked(false);
    mOptWidget->setOperationMode(true);
}
*/
void MainWindow::on_deleteAimButton_clicked()
{
    int size = AimList::getSingletonPtr()->size();
    Aim *LastAim = 0;
    AimList::getSingletonPtr()->remove(size - 1);
    LastAim = AimList::getSingletonPtr()->get(size - 2);
    if (!LastAim)
    {
        resetLastSaved();
    }
    else
    {
        setLastSaved(LastAim->mPositionX, LastAim->mPositionY,
                     LastAim->mRange, LastAim->mTarget);
    }
}

void MainWindow::resetLastSaved()
{
    ui->horizontalAimCoordinate->setText("---");
    ui->verticalAimCoordinate->setText("---");
    ui->aimDistance->setText("---");
    ui->aimNumber->setText("---");
    ui->editAimButton->setEnabled(false);
    ui->deleteAimButton->setEnabled(false);
}

void MainWindow::on_windXInput_editingFinished()
{
/*
    long lWind = ui->windXInput->text().toLong();
    mControllerManager->setWindX(lWind);
*/
}

void MainWindow::on_windYInput_editingFinished()
{
/*
    long lWind = ui->windYInput->text().toLong();
    mControllerManager->setWindY(lWind);
*/
}

void MainWindow::on_temperatureInput_editingFinished()
{
/*
    long lTemperature = ui->temperatureInput->text().toLong();
    mControllerManager->setThermo(lTemperature);
*/
}

void MainWindow::on_pressureInput_editingFinished()
{
/*
    long lPressure = ui->pressureInput->text().toLong();
    mControllerManager->setPressure(lPressure, false);
*/
}

void MainWindow::on_actionClose_triggered()
{
    mControllerManager->closeDevice();
    QApplication::exit(149);
}
/*
void MainWindow::setCameraMode(CameraMode pCameraMode)
{
    if (mOptWidget && mVideoWidget)
    {
        mOptWidget->setCameraMode(pCameraMode);
        mVideoWidget->setCameraMode(pCameraMode);
//        setTracking(false, 1);
    }

    cur_camera = pCameraMode;
    switch (pCameraMode)
    {
        case NARROW_FORMAT:
            ui->camera->setText(tr("NFOV"));
            break;
        case WIDE_FORMAT:
            ui->camera->setText(tr("WFOV"));
            break;
        case THERMAL:
            ui->camera->setText(tr("IR"));
            break;
        case ZOOM_THERMAL:
            ui->camera->setText(tr("IR(X2)"));
            break;
    }
}
*/
/*
void MainWindow::showSoundSignalDialog()
{
    setInterfaceInteractivity(false);
    mSoundSignalDialog->show();
}
*/
/*
void MainWindow::showAdjustmentDialog()
{
    mControllerManager->setPause(true);
    setInterfaceInteractivity(false);
    ad.setControllerManager(mControllerManager);
    ad.exec();
    setInterfaceInteractivity(true);
    mControllerManager->setPause(false);
}
*/
void MainWindow::enableInterface()
{
    setInterfaceInteractivity(true);
}

void MainWindow::resetCamera()
{
    mOptWidget->setCameraMode(cur_camera);
}

void MainWindow::getData(long pRange, long pThermo, long pPressure, long pWindX, long pWindY)
{
    ui -> rangeInput -> setText(QString::number(pRange));
    ui -> temperatureInput -> setText(QString::number(pThermo));
    ui -> pressureInput -> setText(QString::number(pPressure));
    ui -> windXInput -> setText(QString::number(pWindX));
    ui -> windYInput -> setText(QString::number(pWindY));

    mControllerManager->setRange(pRange);
    mControllerManager->setThermo(pThermo);
    mControllerManager->setPressure(pPressure, false);
    mControllerManager->setWindX(pWindX);
    mControllerManager->setWindY(pWindY);

    ui->centralWidget->setFocus();
}

void MainWindow::strData(QString pStr)
{
    if (flagPressure)
    {
        mVirtualKeyboard -> getCorrections(pStr, 3);
//        qDebug() << pStr + "Pressure";
        ui -> pressureInput -> setText(pStr);
    }
    else
        if (flagRange)
        {
            mVirtualKeyboard -> getCorrections(pStr, 1);
//            qDebug() << pStr + "range";
            ui -> rangeInput -> setText(pStr);
        }
        else
            if (flagTemp)
            {
                mVirtualKeyboard -> getCorrections(pStr, 2);
//                qDebug() << pStr + "temperature";
                ui -> temperatureInput -> setText(pStr);
            }
            else
                if (flagWindX)
                {
                    mVirtualKeyboard -> getCorrections(pStr, 4);
 //                   qDebug() << pStr + "WindX";
                    ui -> windXInput -> setText(pStr);
                }
                else
                    if (flagWindY)
                    {
                        mVirtualKeyboard -> getCorrections(pStr, 5);
 //                       qDebug() << pStr + "windY";
                        ui -> windYInput -> setText(pStr);
                    }
}

void MainWindow::resetBeep()
{
    mBeeper->resetBeep();
}

void MainWindow::testBeep(BeepState pBeepState)
{
    mBeeper->testPlay(pBeepState);
}

void MainWindow::setBeepState(BeepState pBeepState)
{
    mBeeper->setBeepState(pBeepState);
    mBeeper->setBeepSignal((bool)pBeepState.is_beep_enabled);
}

/*Выбор рамки*/
/*
void MainWindow::setAimType(AimType pAimtype)
{
    mOptWidget->setAimType(pAimtype);
    switch (pAimtype)
    {
    case HOME:
        txf.can_dlc = 4;
        txf.can_id = 1211;
        txf.data[0] =0b00011110;
        txf.data[1] =0b00000000;
        txf.data[2] =0b00000000;
        txf.data[3] =0b00000000; //присвоили значение 00011110
        //appendLog("Рамка большая");
        break;
    case CAR:
        txf.can_dlc = 4;
        txf.can_id = 1211;
        txf.data[0] =0b00011111;
        txf.data[1] =0b00000000;
        txf.data[2] =0b00000000;
        txf.data[3] =0b00000000;
        //appendLog("Рамка маленькая");

    default:
        break;
    }

    server->FramesToBytes(&txf);

}
*/
void MainWindow::setActivatePlathorm(bool activate)
{
    if (!activate)
    {
        mPlathormDir->setAngle(0);
        setPositionX(0);
        setPositionY(0);
        setSpeedX(0);
        setSpeedY(0);
        ActionList::getSingletonPtr()->clear();
        ui->editAimButton->setEnabled(false);
        ui->deleteAimButton->setEnabled(false);
        if (mControllerManager->isStabilization())
            setStabilization(false);
/*        if (isTracking) {
//            setTracking(false, 1);
            mOptWidget->setVisibleTracking(false);
            mControllerManager->setTracking(false);
        }
*/        mControllerManager->closeAutoMode();
        //Устанавливаем значения по умолчанию для поправок
        ui->pressureInput->setText("750");
        ui->rangeInput->setText("100");
        ui->temperatureInput->setText("15");
        ui->windXInput->setText("0");
        ui->windYInput->setText("0");
        mControllerManager->setPressure(750, false);
        mControllerManager->setRange(100);
        mControllerManager->setThermo(15);
        mControllerManager->setWindX(0);
        mControllerManager->setWindY(0);
        AimList::getSingletonPtr()->clear();
        resetLastSaved();
        ui->camera->setText(tr("WFOV"));
//        mControllerManager->setCamera(WIDE_FORMAT);
        setBurstType(SHORT_BURST);
        setFireType(SINGLE_FIRE);
        setAutoMode(false);
//        setMode(MODE_SEMI_AUTO);
//        isTracking = false;
        setMessage(ui->rotatingPlatformVoltage, "--.-");
    }
    mVideoWidget->setOperationMode(activate, !activate);
    ui->powerConsuptionMenu->setEnabled(activate);
    ui->armamentMenu->setEnabled(activate);
    ui->autoModeButton->setEnabled(activate);
    ui->rangeInput->setEnabled(activate);
    ui->pressureInput->setEnabled(activate);
    ui->temperatureInput->setEnabled(activate);
    ui->windXInput->setEnabled(activate);
    ui->windYInput->setEnabled(activate);
    ui->actionAdjustment->setEnabled(activate);
    ui->alertMenu->setEnabled(activate);

    flagActivate = activate;

//    ui ->editAimButton->setEnabled(true);
//    flagActivate = false;
    //  flagActivate = true;
}


void MainWindow::setMessage(QLabel *label, QString msg, MessageType m_type)
{
    QPalette palette = label->palette();
    switch (m_type)
    {
        case neutral:
            palette.setColor(QPalette::WindowText, Qt::black);
            break;
        case safe:
            palette.setColor(QPalette::WindowText, Qt::green);
            break;
        case unsafe:
            palette.setColor(QPalette::WindowText, Qt::red);
            break;
    }
    label->setPalette(palette);
    label->setText(msg);
}

void MainWindow::setInterfaceInteractivity(bool interactive)
{
    ui->stationMenu->setEnabled(interactive);
    ui->powerConsuptionMenu->setEnabled(interactive);
    ui->armamentMenu->setEnabled(interactive);
    ui->alertMenu->setEnabled(interactive);

    ui->autoModeButton->setEnabled(interactive);
    if (AimList::getSingletonPtr()->size())
    {
        ui->editAimButton->setEnabled(interactive);
        ui->deleteAimButton->setEnabled(interactive);
    }

    ui->rangeInput->setEnabled(interactive);
    ui->temperatureInput->setEnabled(interactive);
    ui->pressureInput->setEnabled(interactive);
    ui->windXInput->setEnabled(interactive);
    ui->windYInput->setEnabled(interactive);
}
/*
float MainWindow::angleAir(double spX, double spY, double spR)
{
    float alpha=0.0f;

//  0...90 angle
    if ((spX > 0) and (spY > 0))
    {
        alpha = acos((spR*spR+spX*spX-spY*spY)/(2*spR*spX));
        alpha = alpha * (180/acos((long double) -1));
    }
    else

//      90...180 angle
        if ((spX < 0) and (spY > 0))
        {
            spX = spX * (-1);
            alpha = acos((spR*spR+spX*spX-spY*spY)/(2*spR*spX));
            alpha = alpha * (180/acos((long double) -1));
            alpha = 180 - alpha;
        }
        else

//          180...270 angl7e
            if ((spX < 0) and (spY < 0))
            {
                spX = spX * (-1);
                spY = spY * (-1);
                alpha = acos((spR*spR+spX*spX-spY*spY)/(2*spR*spX)); //0...90
                alpha = alpha * (180/acos((long double) -1));
                alpha = 180 + alpha;
            }
            else

//              270...360 angle
                if ((spX > 0) and (spY < 0))
                {
                    spY = spY * (-1);
                    alpha = acos((spR*spR+spX*spX-spY*spY)/(2*spR*spX)); //0...90
                    alpha = alpha * (180/acos((long double) -1));
                    alpha = 360 - alpha;
                }
    return alpha;
}
*/
void MainWindow::paintNormal()
{
     ui -> centralWidget->setStyleSheet(COLOR_FON_NORMA);

     //ui -> powerSupplyGroupLabel -> setStyleSheet(COLOR_LABEL_NORMA);
     ui -> controlUnitVoltageLabel -> setStyleSheet(COLOR_LABEL_NORMA);
     ui -> controlUnitVoltage -> setStyleSheet(COLOR_LABEL_NORMA_DATA);
     ui -> controlUnitVoltageMeasurementUnit -> setStyleSheet(COLOR_LABEL_NORMA);
     ui -> rotatingPlatformVoltageLabel -> setStyleSheet(COLOR_LABEL_NORMA);
     ui -> rotatingPlatformVoltage -> setStyleSheet(COLOR_LABEL_NORMA_DATA);
     ui -> rotatingPlatformVoltageMeasurementUnit -> setStyleSheet(COLOR_LABEL_NORMA);
     //ui -> spxLabel -> setStyleSheet(COLOR_LABEL_NORMA);
     //ui -> SpX -> setStyleSheet(COLOR_LABEL_NORMA_DATA);
     //ui -> spyLabel -> setStyleSheet(COLOR_LABEL_NORMA);
     //ui -> SpY -> setStyleSheet(COLOR_LABEL_NORMA_DATA);
     //ui -> sprLabel -> setStyleSheet(COLOR_LABEL_NORMA);
     //ui -> SpR -> setStyleSheet(COLOR_LABEL_NORMA_DATA);
     //ui -> spaLabel -> setStyleSheet(COLOR_LABEL_NORMA);
     //ui -> spA -> setStyleSheet(COLOR_LABEL_NORMA_DATA);
     //ui -> targetFire_1 -> setStyleSheet(COLOR_LABEL_NORMA);
    // ui -> targetFire_2 -> setStyleSheet(COLOR_LABEL_NORMA);
    // ui -> ac_target_zala -> setStyleSheet(COLOR_LABEL_NORMA_DATA);
    // ui -> OX -> setStyleSheet(COLOR_LABEL_NORMA);
    // ui -> koordinataX1 -> setStyleSheet(COLOR_LABEL_NORMA_DATA);
    // ui -> OY -> setStyleSheet(COLOR_LABEL_NORMA);
   //  ui -> koordinataY1 -> setStyleSheet(COLOR_LABEL_NORMA_DATA);
     ui -> powerSupplyInfo -> setStyleSheet(COLOR_LABEL_NORMA);
     
   //  ui -> weaponStateGroupLabel -> setStyleSheet(COLOR_LABEL_NORMA);
     ui -> fireLabel -> setStyleSheet(COLOR_LABEL_NORMA);
     ui -> fire -> setStyleSheet(COLOR_LABEL_NORM_DATA);
     ui -> fireResolutionLabel -> setStyleSheet(COLOR_LABEL_NORMA);
     ui -> fireResolution -> setStyleSheet(COLOR_LABEL_NORM_DATA);
  //   ui -> ac -> setStyleSheet(COLOR_LABEL_NORMA);
  //   ui -> acTarget_zala -> setStyleSheet(COLOR_LABEL_NORMA_DATA);
     ui -> fireTypeLabel -> setStyleSheet(COLOR_LABEL_NORMA);
     ui -> fireType -> setStyleSheet(COLOR_LABEL_NORMA_DATA);
     ui -> burstTypeLabel -> setStyleSheet(COLOR_LABEL_NORMA);
     ui -> burstType -> setStyleSheet(COLOR_LABEL_NORMA_DATA);
     ui -> cockingLabel -> setStyleSheet(COLOR_LABEL_NORMA);
     ui -> cocking -> setStyleSheet(COLOR_LABEL_NORMA_DATA);

   //  ui -> weaponTypeGroupLabel -> setStyleSheet(COLOR_LABEL_NORMA);
     ui -> weaponType -> setStyleSheet(COLOR_LABEL_NORMA_DATA);
   //  ui -> ammunitionGroupLabel -> setStyleSheet(COLOR_LABEL_NORMA);
     ui -> ammunition -> setStyleSheet(COLOR_LABEL_NORMA_DATA);
  //   ui -> speedGroupLabel -> setStyleSheet(COLOR_LABEL_NORMA);
     ui -> horizontalSpeedLabel -> setStyleSheet(COLOR_LABEL_NORMA);
     ui -> horizontalSpeed -> setStyleSheet(COLOR_LABEL_NORMA_DATA);
     ui -> verticalSpeedLabel -> setStyleSheet(COLOR_LABEL_NORMA);
     ui -> verticalSpeed -> setStyleSheet(COLOR_LABEL_NORMA_DATA);

  //   ui -> platformDirectionGroupLabel -> setStyleSheet(COLOR_LABEL_NORMA);
     ui -> horizontalAngleLabel -> setStyleSheet(COLOR_LABEL_NORMA);
     ui -> horizontalAngle -> setStyleSheet(COLOR_LABEL_NORMA_DATA);
     ui -> verticalAngleLabel -> setStyleSheet(COLOR_LABEL_NORMA);
     ui -> verticalAngle -> setStyleSheet(COLOR_LABEL_NORMA_DATA);

     ui -> LogWidget -> setStyleSheet(COLOR_LIST_WIDGET_NORMA);

  //   ui -> correctionsGroupLabel -> setStyleSheet(COLOR_LABEL_NORMA);
     ui -> rangeLabel -> setStyleSheet(COLOR_LABEL_NORMA);
     ui -> rangeMeasurementUnit -> setStyleSheet(COLOR_LABEL_NORMA);
     ui -> temperatureLabel -> setStyleSheet(COLOR_LABEL_NORMA);

     ui -> temperatureMeasurementUnit -> setStyleSheet(COLOR_LABEL_NORMA);
     ui -> pressureLabel -> setStyleSheet(COLOR_LABEL_NORMA);     
     ui -> pressureMeasurementUnit -> setStyleSheet(COLOR_LABEL_NORMA);
     ui -> windLabel -> setStyleSheet(COLOR_LABEL_NORMA);
     ui -> windXArrowLabel -> setStyleSheet(COLOR_LABEL_NORMA);    
     ui -> windXMeasurementUnit -> setStyleSheet(COLOR_LABEL_NORMA);
     ui -> windYArrowLabel -> setStyleSheet(COLOR_LABEL_NORMA);
     ui -> windYMeasurementUnit -> setStyleSheet(COLOR_LABEL_NORMA);

  //   ui -> targetGroupLabel -> setStyleSheet(COLOR_LABEL_NORMA);
     ui -> aimNumberLabel -> setStyleSheet(COLOR_LABEL_NORMA);
     ui -> aimNumber -> setStyleSheet(COLOR_LABEL_NORMA_DATA);
     ui -> aimCoordinatesLabel -> setStyleSheet(COLOR_LABEL_NORMA);
     ui -> horizontalAimCoordinate -> setStyleSheet(COLOR_LABEL_NORMA_DATA);
     ui -> verticalAimCoordinate -> setStyleSheet(COLOR_LABEL_NORMA_DATA);
     ui -> aimDistanceLabel -> setStyleSheet(COLOR_LABEL_NORMA);
     ui -> aimDistance -> setStyleSheet(COLOR_LABEL_NORMA_DATA);

   //  ui -> modeGroupLabel -> setStyleSheet(COLOR_LABEL_NORMA);
   //  ui -> modeLabel -> setStyleSheet(COLOR_LABEL_NORMA);
  //   ui -> mode -> setStyleSheet(COLOR_LABEL_NORMA_DATA);
     ui -> cameraLabel -> setStyleSheet(COLOR_LABEL_NORMA);
     ui -> camera -> setStyleSheet(COLOR_LABEL_NORMA_DATA);
     ui -> stabilizationLabel -> setStyleSheet(COLOR_LABEL_NORMA);
     ui -> stabilization -> setStyleSheet(COLOR_LABEL_NORMA_DATA);
  //   ui -> trackingLabel -> setStyleSheet(COLOR_LABEL_NORMA);
  //   ui -> tracking -> setStyleSheet(COLOR_LABEL_NORMA_DATA);
   //  ui -> ac_target_4 -> setStyleSheet(COLOR_LABEL_NORMA_DATA);
   //  ui -> SpX_2 -> setStyleSheet(COLOR_LABEL_NORMA_DATA);
  //   ui -> SpY_2 -> setStyleSheet(COLOR_LABEL_NORMA_DATA);
  //   ui -> ac_target_3 -> setStyleSheet(COLOR_LABEL_NORMA_DATA);


     ui -> menuBar -> setStyleSheet(COLOR_MENU_BAR_NORMA);
     ui -> stationMenu -> setStyleSheet(COLOR_MENU_NORMA);
     ui -> powerConsuptionMenu -> setStyleSheet(COLOR_MENU_NORMA);
     ui -> armamentMenu -> setStyleSheet(COLOR_MENU_NORMA);
     ui -> alertMenu -> setStyleSheet(COLOR_MENU_NORMA);
     ui -> menuMode_video -> setStyleSheet(COLOR_MENU_NORMA);
//     ui -> menu_PID -> setStyleSheet(COLOR_MENU_NORMA);

     ui -> line_1 -> setStyleSheet(COLOR_LINE_NORMA);
     ui -> line_2 -> setStyleSheet(COLOR_LINE_NORMA);
     ui -> line_3 -> setStyleSheet(COLOR_LINE_NORMA);
     ui -> line_4 -> setStyleSheet(COLOR_LINE_NORMA);
     ui -> line_5 -> setStyleSheet(COLOR_LINE_NORMA);
     ui -> line_6 -> setStyleSheet(COLOR_LINE_NORMA);
     ui -> line_7 -> setStyleSheet(COLOR_LINE_NORMA);
     ui -> line_8 -> setStyleSheet(COLOR_LINE_NORMA);
     ui -> line_9 -> setStyleSheet(COLOR_LINE_NORMA);

     ui -> ReturnButton -> setStyleSheet(COLOR_BUTTON_NORMA_ACTIVATE);
     ui -> h264Button -> setStyleSheet(COLOR_BUTTON_NORMA_ACTIVATE);
     ui -> mjpegButton -> setStyleSheet(COLOR_BUTTON_NORMA_ACTIVATE);
     ui -> compressionTitle->setStyleSheet(COLOR_LABEL_NORMA);
     ui -> compressionLabel -> setStyleSheet(COLOR_LABEL_NORMA_DATA);

     if (flagActivate)
     {
         ui -> temperatureInput -> setStyleSheet(COLOR_EDIT_NORMA_ACTIVATE);
         ui -> rangeInput -> setStyleSheet(COLOR_EDIT_NORMA_ACTIVATE);
         ui -> pressureInput -> setStyleSheet(COLOR_EDIT_NORMA_ACTIVATE);
         ui -> windXInput -> setStyleSheet(COLOR_EDIT_NORMA_ACTIVATE);
         ui -> windYInput -> setStyleSheet(COLOR_EDIT_NORMA_ACTIVATE);
         ui -> deleteAimButton -> setStyleSheet(COLOR_BUTTON_NORMA_ACTIVATE);
         ui -> editAimButton -> setStyleSheet(COLOR_BUTTON_NORMA_ACTIVATE);
         ui -> autoModeButton -> setStyleSheet(COLOR_BUTTON_NORMA_ACTIVATE);
     }
     else
     {
         ui -> temperatureInput -> setStyleSheet(COLOR_BUTTON_NORMA_NO_ACTIVATE);
         ui -> rangeInput -> setStyleSheet(COLOR_BUTTON_NORMA_NO_ACTIVATE);
         ui -> pressureInput -> setStyleSheet(COLOR_BUTTON_NORMA_NO_ACTIVATE);
         ui -> windXInput -> setStyleSheet(COLOR_BUTTON_NORMA_NO_ACTIVATE);
         ui -> windYInput -> setStyleSheet(COLOR_BUTTON_NORMA_NO_ACTIVATE);
         ui -> deleteAimButton -> setStyleSheet(COLOR_BUTTON_NORMA_NO_ACTIVATE);
         ui -> editAimButton -> setStyleSheet(COLOR_BUTTON_NORMA_NO_ACTIVATE);
         ui -> autoModeButton -> setStyleSheet(COLOR_BUTTON_NORMA_NO_ACTIVATE);
     }

     if (inversia_stabilization)
         ui -> digitalStabilization -> setStyleSheet(COLOR_BUTTON_ON_NORMA);
     else
         ui -> digitalStabilization -> setStyleSheet(COLOR_BUTTON_OFF_NORMA);

     if (isFilter)
         ui ->filtrButton -> setStyleSheet(COLOR_BUTTON_ON_NORMA);
     else
         ui-> filtrButton -> setStyleSheet(COLOR_BUTTON_OFF_NORMA);

 //    ui -> filtrButton -> setStyleSheet(COLOR_BUTTON_ON_NORMA);
     ui -> modePictureButton -> setStyleSheet(COLOR_BUTTON_NORMA_ACTIVATE);
     ui -> serviceButton -> setStyleSheet(COLOR_BUTTON_NORMA_ACTIVATE);

     ad.colorInversia(true);
     mBurstLengthDialog.colorInversia(true);
     mAmmunitionDialog.colorInversia(true);
     mAutoModeTypeDialog.colorInversia(true);
     mPID -> colorInversia(true);
     mSoundSignalDialog -> colorInversia(true);
     mTargetEditorDialog.colorInversia(true);

     mService -> setStyleSheet(COLOR_FON_NORMA);
     mService->colorInversia(true);

}

void MainWindow::paintInversia()
{
    ui -> centralWidget -> setStyleSheet(COLOR_FON_INVERSIA);

 //   ui -> powerSupplyGroupLabel -> setStyleSheet(COLOR_LABEL_INVERSIA);
    ui -> controlUnitVoltageLabel -> setStyleSheet(COLOR_LABEL_INVERSIA);
    ui -> controlUnitVoltage -> setStyleSheet(COLOR_LABEL_INVERSIA_DATA);
    ui -> controlUnitVoltageMeasurementUnit -> setStyleSheet(COLOR_LABEL_INVERSIA);
    ui -> rotatingPlatformVoltageLabel -> setStyleSheet(COLOR_LABEL_INVERSIA);
    ui -> rotatingPlatformVoltage -> setStyleSheet(COLOR_LABEL_INVERSIA_DATA);
    ui ->rotatingPlatformVoltageMeasurementUnit -> setStyleSheet(COLOR_LABEL_INVERSIA);
  //  ui -> spxLabel -> setStyleSheet(COLOR_LABEL_INVERSIA);
 //   ui -> SpX -> setStyleSheet(COLOR_LABEL_INVERSIA_DATA);
 //   ui -> spyLabel -> setStyleSheet(COLOR_LABEL_INVERSIA);
 //   ui -> SpY -> setStyleSheet(COLOR_LABEL_INVERSIA_DATA);
  //  ui -> sprLabel -> setStyleSheet(COLOR_LABEL_INVERSIA);
  //  ui -> SpR -> setStyleSheet(COLOR_LABEL_INVERSIA_DATA);
 //   ui -> spaLabel -> setStyleSheet(COLOR_LABEL_INVERSIA);
//    ui -> spA -> setStyleSheet(COLOR_LABEL_INVERSIA_DATA);
 //   ui -> targetFire_1 -> setStyleSheet(COLOR_LABEL_INVERSIA);
  //  ui -> targetFire_2 -> setStyleSheet(COLOR_LABEL_INVERSIA);
 //   ui -> ac_target_zala -> setStyleSheet(COLOR_LABEL_INVERSIA_DATA);
 //   ui -> OX -> setStyleSheet(COLOR_LABEL_INVERSIA);
 //   ui -> koordinataX1 -> setStyleSheet(COLOR_LABEL_INVERSIA_DATA);
//    ui -> OY -> setStyleSheet(COLOR_LABEL_INVERSIA);
//    ui -> koordinataY1 -> setStyleSheet(COLOR_LABEL_INVERSIA_DATA);
    ui -> powerSupplyInfo -> setStyleSheet(COLOR_LABEL_INVERSIA);

//    ui -> weaponStateGroupLabel -> setStyleSheet(COLOR_LABEL_INVERSIA);
    ui -> fireLabel -> setStyleSheet(COLOR_LABEL_INVERSIA);
    ui -> fire -> setStyleSheet(COLOR_LABEL_INVERS_DATA);
    ui -> fireResolutionLabel -> setStyleSheet(COLOR_LABEL_INVERSIA);
    ui -> fireResolution -> setStyleSheet(COLOR_LABEL_INVERS_DATA);
 //   ui -> ac -> setStyleSheet(COLOR_LABEL_INVERSIA);
 //   ui -> acTarget_zala -> setStyleSheet(COLOR_LABEL_INVERSIA_DATA);
    ui -> fireTypeLabel -> setStyleSheet(COLOR_LABEL_INVERSIA);
    ui -> fireType -> setStyleSheet(COLOR_LABEL_INVERSIA_DATA);
    ui -> burstTypeLabel -> setStyleSheet(COLOR_LABEL_INVERSIA);
    ui -> burstType -> setStyleSheet(COLOR_LABEL_INVERSIA_DATA);
    ui -> cockingLabel -> setStyleSheet(COLOR_LABEL_INVERSIA);
    ui -> cocking -> setStyleSheet(COLOR_LABEL_INVERSIA_DATA);

//    ui -> weaponTypeGroupLabel -> setStyleSheet(COLOR_LABEL_INVERSIA);
    ui -> weaponType -> setStyleSheet(COLOR_LABEL_INVERSIA_DATA);
 //   ui -> ammunitionGroupLabel -> setStyleSheet(COLOR_LABEL_INVERSIA);
    ui -> ammunition -> setStyleSheet(COLOR_LABEL_INVERSIA_DATA);
//    ui -> speedGroupLabel -> setStyleSheet(COLOR_LABEL_INVERSIA);
    ui -> horizontalSpeedLabel -> setStyleSheet(COLOR_LABEL_INVERSIA);
    ui -> horizontalSpeed -> setStyleSheet(COLOR_LABEL_INVERSIA_DATA);
    ui -> verticalSpeedLabel -> setStyleSheet(COLOR_LABEL_INVERSIA);
    ui -> verticalSpeed -> setStyleSheet(COLOR_LABEL_INVERSIA_DATA);

 //   ui -> platformDirectionGroupLabel -> setStyleSheet(COLOR_LABEL_INVERSIA);
    ui -> horizontalAngleLabel -> setStyleSheet(COLOR_LABEL_INVERSIA);
    ui -> horizontalAngle -> setStyleSheet(COLOR_LABEL_INVERSIA_DATA);
    ui -> verticalAngleLabel -> setStyleSheet(COLOR_LABEL_INVERSIA);
    ui -> verticalAngle -> setStyleSheet(COLOR_LABEL_INVERSIA_DATA);

    ui -> LogWidget -> setStyleSheet(COLOR_LIST_WIDGET_INVERSIA);

 //   ui -> correctionsGroupLabel -> setStyleSheet(COLOR_LABEL_INVERSIA);
    ui -> rangeLabel -> setStyleSheet(COLOR_LABEL_INVERSIA);
    ui -> rangeMeasurementUnit -> setStyleSheet(COLOR_LABEL_INVERSIA);
    ui -> temperatureLabel -> setStyleSheet(COLOR_LABEL_INVERSIA);
    ui -> temperatureMeasurementUnit -> setStyleSheet(COLOR_LABEL_INVERSIA);
    ui -> pressureLabel -> setStyleSheet(COLOR_LABEL_INVERSIA);
    ui -> pressureMeasurementUnit -> setStyleSheet(COLOR_LABEL_INVERSIA);
    ui -> windLabel -> setStyleSheet(COLOR_LABEL_INVERSIA);
    ui -> windXArrowLabel -> setStyleSheet(COLOR_LABEL_INVERSIA);
    ui -> windXMeasurementUnit -> setStyleSheet(COLOR_LABEL_INVERSIA);
    ui -> windYArrowLabel -> setStyleSheet(COLOR_LABEL_INVERSIA);
    ui -> windYMeasurementUnit -> setStyleSheet(COLOR_LABEL_INVERSIA);

//    ui -> targetGroupLabel -> setStyleSheet(COLOR_LABEL_INVERSIA);
    ui -> aimNumberLabel -> setStyleSheet(COLOR_LABEL_INVERSIA);
    ui -> aimNumber -> setStyleSheet(COLOR_LABEL_INVERSIA_DATA);
    ui -> aimCoordinatesLabel -> setStyleSheet(COLOR_LABEL_INVERSIA);
    ui -> horizontalAimCoordinate -> setStyleSheet(COLOR_LABEL_INVERSIA_DATA);
    ui -> verticalAimCoordinate -> setStyleSheet(COLOR_LABEL_INVERSIA_DATA);
    ui -> aimDistanceLabel -> setStyleSheet(COLOR_LABEL_INVERSIA);
    ui -> aimDistance -> setStyleSheet(COLOR_LABEL_INVERSIA_DATA);

 //   ui -> modeGroupLabel -> setStyleSheet(COLOR_LABEL_INVERSIA);
 //   ui -> modeLabel -> setStyleSheet(COLOR_LABEL_INVERSIA);
  //  ui -> mode -> setStyleSheet(COLOR_LABEL_INVERSIA_DATA);
    ui -> cameraLabel -> setStyleSheet(COLOR_LABEL_INVERSIA);
    ui -> camera -> setStyleSheet(COLOR_LABEL_INVERSIA_DATA);
    ui -> stabilizationLabel -> setStyleSheet(COLOR_LABEL_INVERSIA);
    ui -> stabilization -> setStyleSheet(COLOR_LABEL_INVERSIA_DATA);
//    ui -> trackingLabel -> setStyleSheet(COLOR_LABEL_INVERSIA);
//    ui -> tracking -> setStyleSheet(COLOR_LABEL_INVERSIA_DATA);
 //   ui -> ac_target_4 -> setStyleSheet(COLOR_LABEL_INVERSIA_DATA);
 //   ui -> SpX_2 -> setStyleSheet(COLOR_LABEL_INVERSIA_DATA);
  //  ui -> SpY_2 -> setStyleSheet(COLOR_LABEL_INVERSIA_DATA);
  //  ui -> ac_target_3 -> setStyleSheet(COLOR_LABEL_INVERSIA_DATA);

    ui -> menuBar -> setStyleSheet(COLOR_MENU_BAR_INVERSIA);
    ui -> stationMenu -> setStyleSheet(COLOR_MENU_INVERSIA);
    ui -> powerConsuptionMenu -> setStyleSheet(COLOR_MENU_INVERSIA);
    ui -> armamentMenu -> setStyleSheet(COLOR_MENU_INVERSIA);
    ui -> alertMenu -> setStyleSheet(COLOR_MENU_INVERSIA);
    ui -> menuMode_video -> setStyleSheet(COLOR_MENU_INVERSIA);
//    ui -> menu_PID -> setStyleSheet(COLOR_MENU_INVERSIA);

    ui -> line_1 -> setStyleSheet(COLOR_LINE_INVERSIA);
    ui -> line_2 -> setStyleSheet(COLOR_LINE_INVERSIA);
    ui -> line_3 -> setStyleSheet(COLOR_LINE_INVERSIA);
    ui -> line_4 -> setStyleSheet(COLOR_LINE_INVERSIA);
    ui -> line_5 -> setStyleSheet(COLOR_LINE_INVERSIA);
    ui -> line_6 -> setStyleSheet(COLOR_LINE_INVERSIA);
    ui -> line_7 -> setStyleSheet(COLOR_LINE_INVERSIA);
    ui -> line_8 -> setStyleSheet(COLOR_LINE_INVERSIA);
    ui -> line_9 -> setStyleSheet(COLOR_LINE_INVERSIA);

    ui -> h264Button -> setStyleSheet(COLOR_BUTTON_INVERSIA_ACTIVATE);
    ui -> mjpegButton -> setStyleSheet(COLOR_BUTTON_INVERSIA_ACTIVATE);
    ui -> compressionTitle->setStyleSheet(COLOR_LABEL_INVERSIA);
    ui -> compressionLabel -> setStyleSheet(COLOR_LABEL_INVERSIA_DATA);


    if (flagActivate)
    {
        ui -> rangeInput -> setStyleSheet(COLOR_EDIT_INVERSIA_ACTIVATE);
        ui -> temperatureInput -> setStyleSheet(COLOR_EDIT_INVERSIA_ACTIVATE);
        ui -> pressureInput -> setStyleSheet(COLOR_EDIT_INVERSIA_ACTIVATE);
        ui -> windXInput -> setStyleSheet(COLOR_EDIT_INVERSIA_ACTIVATE);
        ui -> windYInput -> setStyleSheet(COLOR_EDIT_INVERSIA_ACTIVATE);
        ui -> deleteAimButton -> setStyleSheet(COLOR_BUTTON_INVERSIA_ACTIVATE);
        ui -> editAimButton -> setStyleSheet(COLOR_BUTTON_INVERSIA_ACTIVATE);
        ui -> autoModeButton -> setStyleSheet(COLOR_BUTTON_INVERSIA_ACTIVATE);
    }

    else
    {
        ui -> rangeInput -> setStyleSheet(COLOR_EDIT_INVERSIA_NO_ACTIVATE);
        ui -> temperatureInput -> setStyleSheet(COLOR_EDIT_INVERSIA_NO_ACTIVATE);
        ui -> pressureInput -> setStyleSheet(COLOR_EDIT_INVERSIA_NO_ACTIVATE);
        ui -> windXInput -> setStyleSheet(COLOR_EDIT_INVERSIA_NO_ACTIVATE);
        ui -> windYInput -> setStyleSheet(COLOR_EDIT_INVERSIA_NO_ACTIVATE);
        ui -> deleteAimButton -> setStyleSheet(COLOR_BUTTON_INVERSIA_NO_ACTIVATE);
        ui -> editAimButton -> setStyleSheet(COLOR_BUTTON_INVERSIA_NO_ACTIVATE);
        ui -> autoModeButton -> setStyleSheet(COLOR_BUTTON_INVERSIA_NO_ACTIVATE);
    }

    ui -> ReturnButton -> setStyleSheet(COLOR_BUTTON_INVERSIA_ACTIVATE);
    ui -> modePictureButton -> setStyleSheet(COLOR_BUTTON_INVERSIA_ACTIVATE);
    ui -> serviceButton -> setStyleSheet(COLOR_BUTTON_INVERSIA_ACTIVATE);

    if (inversia_stabilization)
        ui -> digitalStabilization -> setStyleSheet(COLOR_BUTTON_ON_INVERSIA);
    else
        ui -> digitalStabilization -> setStyleSheet(COLOR_BUTTON_OFF_INVERSIA);

    if (isFilter)
        ui ->filtrButton -> setStyleSheet(COLOR_BUTTON_ON_INVERSIA);
    else
        ui-> filtrButton -> setStyleSheet(COLOR_BUTTON_OFF_INVERSIA);


}
/*
void MainWindow::animationStartPause(bool pFlag)
{
    if (pFlag)  ui -> label_movie -> hide();
    else        ui -> label_movie -> show();
}

*/
//вывод экранной формы++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++/
/*
void MainWindow::pid_vkl()
{
    mPID -> show();
   { emit readPageX(mPIDx -> pid.Zona,
                   mPIDx -> pid.Tmls,
                   mPIDx -> pid.Pves,
                   mPIDx -> pid.Dves,
                   mPIDx -> pid.MaxU,
                   mPIDx -> pid.MinU,
                   mPIDx -> pid.Pkff,
                   mPIDx -> pid.Ikff,
                   mPIDx -> pid.Dkff);

    emit readPageY(mPIDy -> pid.Zona,
                   mPIDy -> pid.Tmls,
                   mPIDy -> pid.Pves,
                   mPIDy -> pid.Dves,
                   mPIDy -> pid.MaxU,
                   mPIDy -> pid.MinU,
                   mPIDy -> pid.Pkff,
                   mPIDy -> pid.Ikff,
                   mPIDy -> pid.Dkff);}
}
*/
/*Включение режима сопровождения***XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXx*******/
void MainWindow::acTrack(bool enabled)
{
    if (enabled) //Проверка триггера на включение/отключение сопровождения
    {
        qDebug() << "on_sopr";

        ui -> centralWidget -> setFocus();
        mTrackingZala -> acTrack(true);
/*
        timerD -> start(40);
        flag_acTrack = true;
        txf.can_dlc = 4;        //Длина поля данных в байтах
        txf.can_id  = 1213;  //0x05e5 функция включения адресс
        txf.data[0] =0b00000001;
        txf.data[1] =0b00000000;
        txf.data[2] =0b00000000;
        txf.data[3] =0b00000000; //qToBigEndian(0xa1b2c3d4);
        //appendLog("on AC");
        server->FramesToBytes(&txf);
        connect (mControllerManager, SIGNAL(acJoystick()), this, SLOT(ac_Joystick())); //Если подается сигнал acJoystick(), посылаем пакеты 900
*/

    }
    else
    {
        qDebug() << "off_sopr";
        mTrackingZala -> acTrack(false);
/*        txf.can_dlc = 4;        //Длина поля данных в байтах
        txf.can_id  = 1213;  //0x05e5 функция включения адресс
        txf.data[0] =0b00000000;
        txf.data[1] =0b00000000;
        txf.data[2] =0b00000000;
        txf.data[3] =0b00000000;
        //appendLog("off AC");
        server->FramesToBytes(&txf);
        t_indi_ac = false;

        if (mControllerManager->enabled_as)
        {
            if (flag_acTrack)
            {
                mPIDx->pid_on_off(false, 0);
                mPIDy->pid_on_off(false, 0);
                connect(mPIDx, SIGNAL(readValuePid(float)), this, SLOT(readVPx(float)));
                connect(mPIDy, SIGNAL(readValuePid(float)), this, SLOT(readVPy(float)));
                mTimer -> stop();
                timerD -> stop();
                filtrTimer -> stop();
                flag_acTrack = false;
                mControllerManager -> enabled_as = true;
                setMessage( ui -> acTarget_zala,"НЕТ",safe);
                setMessage( ui -> ac_target_zala,"НЕТ",safe);
                ui -> SpX -> setText("0");
                ui -> SpY -> setText("0");
                ui -> SpR -> setText("0");
                ui -> spA -> setText("0");
                //appendLog("stop PID");
            }
        }
*/    }
}
/*Реакция на принудительное движение платформы, пакеты 900*/
/*
void MainWindow::AC_Joystick()
{
    can_frame txf2;
    txf2.can_dlc = 4;
    txf2.can_id = 900;
    txf2.data[0] =0b00000000;
    txf2.data[1] =0b00000000;
    txf2.data[2] =0b00000000;
    txf2.data[3] =0b00000000;
    server->FramesToBytes(&txf2);
    //appendLog("Посылка 900");
}
*/
/*Функция в которой включается задержка по ней выполняется реакция на принудительное движение платформы*/
/*
void MainWindow::ac_Joystick()
{
    if ((mControllerManager -> lPosJoyX != 0) or (mControllerManager -> lPosJoyY != 0))
    {
        //nnect(mTimer, SIGNAL(timeout()), SLOT(AC_Joystick()));
        if (!(mTimer -> isActive()))
        {
            mTimer -> start(200);
            connect(mTimer, SIGNAL(timeout()), SLOT(AC_Joystick())); // по завершению отчета таймера выполнить слот на получение пакетов 900
            //appendLog("900 ON");

        }
    }
    else
    {
        if (mTimer -> isActive())
        {
            mTimer -> stop();
            //appendLog("900 OFF");
        }

    }
}
*/
/*Функция перемещения рамки целеуказателя, абсолютное перемещение*/
/*
void MainWindow::move_Ac_Target(long x, long y)
{
    //QString prov;
    txf.can_dlc = 4;	//Длина поля данных в байтах
    txf.can_id = 1212;  //0x05e5 функция включения адресс
    txf.data[0] = static_cast<int8_t>(x); //коордианата x
    txf.data[1] = static_cast<int8_t>(y); //координата y
    txf.data[2] = 0x00;
    txf.data[3] = 0x81;
    //appendLog ("move cross");
    //mControllerManager -> newLogMsg("Peredacha X,Y");
    //prov = QString("x=%1 y=%2").arg(txf.data[0]).arg(txf.data[1]);
    //mControllerManager->newLogMsg(prov);

    server->FramesToBytes(&txf);
}
*/
/*Выбор режимов камеры*/
void MainWindow::setCameraMode_AC(CameraMode pCameraMode)
{
    switch (pCameraMode)
    {
        case WIDE_FORMAT:
//            if (pCameraMode == WIDE_FORMAT) break;
            acTrack(false);
            ui->camera->setText(tr("WFOV"));
            mTrackingZala ->setCameraModeAC(WIDE_FORMAT);
/*
            mOptWidget->setCameraMode(pCameraMode);
            txf.can_dlc = 4;	//Длина поля данных в байтах
            txf.can_id = 1028;  //0x05e5 функция включения адресс
            txf.data[0] =0b10100000;
            txf.data[1] =0b00000000;
            txf.data[2] =0b00000000;
            txf.data[3] =0b00000000;
            mControllerManager -> enabled_as = true;
            //appendLog ("WIDE");

            mPIDx -> pid.Zona =  0.0f;    mPIDy -> pid.Zona =  0.0f;
            mPIDx -> pid.Tmls =  40.0f;   mPIDy -> pid.Tmls =  40.0f;
            mPIDx -> pid.Pves =  1.00f;   mPIDy -> pid.Pves =  1.00f;
            mPIDx -> pid.Dves =  1.00f;   mPIDy -> pid.Dves =  1.00f;
            mPIDx -> pid.MaxU =  4250.0f; mPIDy -> pid.MaxU =  4250.0;
            mPIDx -> pid.MinU = -4250.0f; mPIDy -> pid.MinU = -4250.0f;
            mPIDx -> pid.Pkff =  40.00f;  mPIDy -> pid.Pkff = 40.00f;
            mPIDx -> pid.Ikff =   9.0f;   mPIDy -> pid.Ikff =  9.0f;
            mPIDx -> pid.Dkff = 1200.0f;  mPIDy -> pid.Dkff =  1100.0f;
*/
            qDebug() << "WIDE";
            break;
        case NARROW_FORMAT:
//            if (pCameraMode == NARROW_FORMAT) break;
            acTrack(false);
            ui->camera->setText(tr("NFOV"));
            mTrackingZala ->setCameraModeAC(NARROW_FORMAT);
/*
            mOptWidget->setCameraMode(pCameraMode);
            txf.can_dlc = 4;	//Длина поля данных в байтах
            txf.can_id = 1028;  //0x05e5 функция включения адресс
            txf.data[0] =0b10011111;
            txf.data[1] =0b00000000;
            txf.data[2] =0b00000000;
            txf.data[3] =0b00000000;
            mControllerManager -> enabled_as = true;
            //appendLog ("NARR");

            mPIDx -> pid.Zona =  0.0f;     mPIDy -> pid.Zona =  0.0f;
            mPIDx -> pid.Tmls =  40.0f;    mPIDy -> pid.Tmls =  40.0f;
            mPIDx -> pid.Pves =  1.00f;    mPIDy -> pid.Pves =  1.00f;
            mPIDx -> pid.Dves =  1.000f;   mPIDy -> pid.Dves =  1.000f;
            mPIDx -> pid.MaxU =  4250.0f;   mPIDy -> pid.MaxU =  4250.0;
            mPIDx -> pid.MinU = -4250.0f;   mPIDy -> pid.MinU = -4250.0f;
            mPIDx -> pid.Pkff =  2.800f;   mPIDy -> pid.Pkff =  0.500f;
            mPIDx -> pid.Ikff =  200.00f;   mPIDy -> pid.Ikff =  200.000f;
            mPIDx -> pid.Dkff =  180.0f;    mPIDy -> pid.Dkff =  180.0f;
*/
            qDebug()<<"NARROW";
            break;
        case THERMAL:
//            if (pCameraMode == THERMAL) break;
            acTrack(false);
            ui->camera->setText(tr("IR"));
            mTrackingZala -> setCameraModeAC(THERMAL);
/*
            mOptWidget->setCameraMode(pCameraMode);
            txf.can_dlc = 4;	//Длина поля данных в байтах
            txf.can_id = 1028;  //0x05e5 функция включения адресс
            txf.data[0] =0b10110000;
            txf.data[1] =0b00000000;
            txf.data[2] =0b00000000;
            txf.data[3] =0b00000000;
            mControllerManager -> setZoomTermo(0);
            mControllerManager -> enabled_as = true;
            //appendLog ("TERM");

            mPIDx -> pid.Zona =  0.0f;     mPIDy -> pid.Zona =  0.0f;
            mPIDx -> pid.Tmls =  40.0f;    mPIDy -> pid.Tmls =  40.0f;
            mPIDx -> pid.Pves =  1.00f;    mPIDy -> pid.Pves =  1.00f;
            mPIDx -> pid.Dves =  1.000f;   mPIDy -> pid.Dves =  1.000f;
            mPIDx -> pid.MaxU =  4250.0f;   mPIDy -> pid.MaxU =  4250.0;
            mPIDx -> pid.MinU = -4250.0f;   mPIDy -> pid.MinU = -4250.0f;
            mPIDx -> pid.Pkff =  2.800f;   mPIDy -> pid.Pkff =  0.500f;
            mPIDx -> pid.Ikff =  200.00f;   mPIDy -> pid.Ikff =  200.000f;
            mPIDx -> pid.Dkff =  180.0f;    mPIDy -> pid.Dkff =  180.0f;
*/
            qDebug()<<"thermal";
            break;
        case ZOOM_THERMAL:
//            if (pCameraMode == ZOOM_THERMAL) break;
            acTrack(false);
            ui->camera->setText(tr("IR(X2)"));
            mTrackingZala -> setCameraModeAC(ZOOM_THERMAL);
/*
            mOptWidget->setCameraMode(pCameraMode);
            txf.can_dlc = 4;	//Длина поля данных в байтах
            txf.can_id = 1028;  //0x05e5 функция включения адресс
            txf.data[0] =0b10110000;
            txf.data[1] =0b00000000;
            txf.data[2] =0b00000000;
            txf.data[3] =0b00000000;
            mControllerManager -> setZoomTermo(1);
            mControllerManager -> enabled_as = true;
            //appendLog ("ZTRM");

            mPIDx -> pid.Zona =  0.0f;     mPIDy -> pid.Zona =  0.0f;
            mPIDx -> pid.Tmls =  40.0f;    mPIDy -> pid.Tmls =  40.0f;
            mPIDx -> pid.Pves =  1.00f;    mPIDy -> pid.Pves =  1.00f;
            mPIDx -> pid.Dves =  1.000f;   mPIDy -> pid.Dves =  1.000f;
            mPIDx -> pid.MaxU =  4250.0f;   mPIDy -> pid.MaxU =  4250.0;
            mPIDx -> pid.MinU = -4250.0f;   mPIDy -> pid.MinU = -4250.0f;
            mPIDx -> pid.Pkff =  2.800f;   mPIDy -> pid.Pkff =  0.500f;
            mPIDx -> pid.Ikff =  200.00f;   mPIDy -> pid.Ikff =  200.000f;
            mPIDx -> pid.Dkff =  180.0f;    mPIDy -> pid.Dkff =  180.0f;
*/
            qDebug()<<"ZOOM_THARMAL";
            break;
        default:
            break;
     }
//    server->FramesToBytes(&txf);
}

/*Функция на получение координат от платы*/
/*
void MainWindow::getKoordinatAc(can_frame *frame)
{
    if ((!mControllerManager->enabled_as) or (trig_f11))
    {
        can_frame txf1;
        txf1 = *frame;
        float x1 = 0 ,y1 = 0;

        if (txf1.can_id == 1210)
        {
            static int16_t x = 0;
            static int16_t y = 0;
            filtrTimer -> start(200); //запуск таймера

            x = (static_cast<int16_t>(txf1.data[1]));
            x <<= 8;
            x |= (static_cast<int16_t>(txf1.data[0]));

            y = (static_cast<int16_t>(txf1.data[3]));
            y <<= 8;
            y |= (static_cast<int16_t>(txf1.data[2]));

            indikator_ac = true;
            flag_konstr  = false;

            if ((udpRecive.flag) and (trig_f11))
            {
                x1 = udpRecive.x;                           // передача координат от Бабаяна
                y1 = udpRecive.y;                           // передача координат от Бабаяна
            }
            if ((!trig_f11))
            {
                x1 = static_cast<float>(x);
                y1 = static_cast<float>(y);
            }

            ui -> koordinataX1 -> setText(QString::number(x));
            ui -> koordinataY1 -> setText(QString::number(y));

            if (mPID->page_pid)
            {
                connect (mPID, SIGNAL (readPidX (float,float,float,float,float,float,float,float,float)),
                         mPIDx,  SLOT (writePidX(float,float,float,float,float,float,float,float,float)));
                connect (mPID,  SIGNAL(readPidY (float,float,float,float,float,float,float,float,float)),
                         mPIDy,   SLOT(writePidY(float,float,float,float,float,float,float,float,float)));
                mPID->page_pid = false;

            }
        }
        
	if (!trig_f11)
	{
		if (txf1.can_id != 1210) connect(filtrTimer, SIGNAL(timeout()),this,SLOT(filterIndikator()));
	}       
        if (indikator_ac) setMessage( ui -> acTarget_zala,"ВЫПОЛНЕН",unsafe);

        if ((!t_indi_ac) and (indikator_ac)) connect (timerD, SIGNAL(timeout()), this, SLOT(time_indi_ac()));
        if (( t_indi_ac) and (indikator_ac))
        {
            if ((x1<=15) and (x1>=-15) and (y1<=15) and (y1>=-15))
            {
                setMessage( ui -> ac_target_zala,"ДА",unsafe);
            }
            else
            {
                setMessage( ui -> ac_target_zala,"НЕТ",safe);

            }
            mPIDx->pid_on_off(indikator_ac, x1);
            connect(mPIDx, SIGNAL(readValuePid(float)), this, SLOT(readVPx(float)));
            //connect(mPIDx, SIGNAL(readVarPid  (float,float,float,float)),
            //mPID,  SLOT  (read_pid_X  (float,float,float,float)));

            mPIDy->pid_on_off(indikator_ac, y1);
            connect(mPIDy, SIGNAL(readValuePid(float)), this, SLOT(readVPy(float)));
            //connect(mPIDy, SIGNAL(readVarPid  (float,float,float,float)),
            //mPID,  SLOT  (read_pid_Y  (float,float,float,float)));

	    spRezult = hypot(spMotorX,spMotorY);
            ui -> SpR -> setText(QString::number(spRezult));
            spAngle = angleAir(spMotorX,spMotorY,spRezult);
            ui -> spA -> setText(QString::number(spAngle));
            
	    t_indi_ac = false;
            timerD -> start(40);
        }
    }

}
*/
/*Функция на фильтрацию пакетов*/
/*
void MainWindow::filterIndikator()
{
    if ((!flag_konstr) and (!trig_f11))
    {
    	flag_konstr  = true;
    	indikator_ac = false;
    	mPIDx->pid_on_off(indikator_ac, 0);
    	mPIDy->pid_on_off(indikator_ac, 0);
    	connect(mPIDx, SIGNAL(readValuePid(float)), this, SLOT(readVPx(float)));
    	connect(mPIDy, SIGNAL(readValuePid(float)), this, SLOT(readVPy(float)));
        setMessage( ui -> acTarget_zala,"НЕТ",safe);
        setMessage( ui -> ac_target_zala,"НЕТ",safe);
    	ui -> koordinataX1 -> setText("0");
    	ui -> koordinataY1 -> setText("0");
        ui -> SpX -> setText("0");
        ui -> SpY -> setText("0");
        ui -> SpR -> setText("0");
        ui -> spA -> setText("0");
        appendLog("FILTR Time");
    }   
}
*/
/*
void MainWindow::time_indi_ac ()
{
	t_indi_ac = true;

}
*/
/*
void MainWindow::readVPx(float pv)
{
    mControllerManager->pidX = static_cast<long>(pv);
    spMotorX = static_cast<double>(pv);
    ui -> SpX -> setText(QString::number(pv));

}
*/
/*
void MainWindow::readVPy(float pv)
{
    mControllerManager->pidY = static_cast<long>(pv);
    spMotorY = static_cast<double>(pv);
    ui -> SpY -> setText(QString::number(pv));
}
*/
void MainWindow::reciveUdpParcel(UDP_Parcel udpReciveParcel)
{
    //appendLog (QString::number(udpReciveParcel.flag).append(" ").append(QString::number(udpReciveParcel.x)).append(" ").append(QString::number(udpReciveParcel.y)));
        udpRecive.flag = udpReciveParcel.flag;
        udpRecive.x    = udpReciveParcel.x;
        udpRecive.y    = udpReciveParcel.y;
        //ui -> SpX_2 -> setText(QString::number(udpRecive.x));
        //ui -> SpY_2 -> setText(QString::number(udpRecive.y));
        if (udpRecive.flag)
        {
          //  setMessage( ui -> ac_target_3,"ok",safe);
        }
        else
        {
            //setMessage( ui -> ac_target_3,"bad",unsafe);
        }
}
/*
void MainWindow::on_actionSound_signal_triggered()
{
    setInterfaceInteractivity(false);
    mSoundSignalDialog->show();
}
*/
/*
void MainWindow::on_actionAdjustment_triggered()
{
    mControllerManager->setPause(true);
    setInterfaceInteractivity(false);
    ad.setControllerManager(mControllerManager);
    ad.exec();
    setInterfaceInteractivity(true);
    mControllerManager->setPause(false);
}
*/
void MainWindow::on_actionPID_triggered()
{
    mPID -> show();
}

void MainWindow::inversia()
{
    //    appendLog("Инверсия");
        if (flagInversia)
        {
            flagInversia = false;

            mOptWidget -> invertCrossColor();

            mPlathormDir->inversia(false);
            paintInversia();

            mVideoWidget -> getFlagInversia(false);

            ad.setStyleSheet(COLOR_FON_INVERSIA);
            ad.colorInversia(false);

            mBurstLengthDialog.setStyleSheet(COLOR_FON_INVERSIA);
            mBurstLengthDialog.colorInversia(false);

            mAmmunitionDialog.setStyleSheet(COLOR_FON_INVERSIA);
            mAmmunitionDialog.colorInversia(false);

            mAutoModeTypeDialog.setStyleSheet(COLOR_FON_INVERSIA);
            mAutoModeTypeDialog.colorInversia(false);

            mPID -> setStyleSheet(COLOR_FON_INVERSIA);
            mPID -> colorInversia(false);

            mSoundSignalDialog -> setStyleSheet(COLOR_FON_INVERSIA);
            mSoundSignalDialog -> colorInversia(false);

            mVirtualKeyboard -> setStyleSheet(COLOR_FON_INVERSIA);
            mVirtualKeyboard -> inversia_Keyboard(false);

            mService ->setStyleSheet(COLOR_FON_INVERSIA);
            mService->colorInversia(false);

            ui -> inversiaButton -> setStyleSheet(PICTURE_DAY_BUTTON);
            ui -> exitButton -> setStyleSheet(PICTURE_OFF_INVERSIA);

        }
        else
        {
            flagInversia = true;

            mOptWidget -> invertCrossColor();

            mPlathormDir->inversia(true);
            paintNormal();

            mVideoWidget -> getFlagInversia(true);

            ad.setStyleSheet(COLOR_FON_NORMA);
            ad.colorInversia(true);

            mBurstLengthDialog.setStyleSheet(COLOR_FON_NORMA);
            mBurstLengthDialog.colorInversia(true);

            mAmmunitionDialog.setStyleSheet(COLOR_FON_NORMA);
            mAmmunitionDialog.colorInversia(true);

            mAutoModeTypeDialog.setStyleSheet(COLOR_FON_NORMA);
            mAutoModeTypeDialog.colorInversia(true);

            mPID -> setStyleSheet(COLOR_FON_NORMA);
            mPID -> colorInversia(true);

            mSoundSignalDialog -> setStyleSheet(COLOR_FON_NORMA);
            mSoundSignalDialog -> colorInversia(true);

            mVirtualKeyboard -> setStyleSheet(COLOR_FON_NORMA);
            mVirtualKeyboard -> inversia_Keyboard(true);

            mService ->setStyleSheet(COLOR_FON_NORMA);
            mService->colorInversia(true);

            ui -> inversiaButton -> setStyleSheet(PICTURE_NIGHT_BUTTON);
            ui -> exitButton -> setStyleSheet(PICTURE_OFF_NORMA);
        }
}

void MainWindow::adjustmentDialog()
{
    mControllerManager->setPause(true);
    setInterfaceInteractivity(false);
    ad.setControllerManager(mControllerManager);
    ad.exec();
    setInterfaceInteractivity(true);
    mControllerManager->setPause(false);
}

void MainWindow::soundDialog()
{
    setInterfaceInteractivity(false);
    mSoundSignalDialog->show();
}

void MainWindow::standByMode()
{
    mVideoWidget->setOperationMode(false, false);
    mControllerManager->setStandbyMode();

//    animationStartPause(true);

    ui->actionStand_by_mode->setChecked(true);
    ui->actionOperation_mode->setChecked(false);
    mOptWidget->setOperationMode(false);
}

void MainWindow::operationMode()
{
    mVideoWidget->setOperationMode(true, false);
    mControllerManager->setOperationMode();

//    animationStartPause(false);

    ui->actionOperation_mode->setChecked(true);
    ui->actionStand_by_mode->setChecked(false);
    mOptWidget->setOperationMode(true);
}

void MainWindow::mjpegPicture()
{
    mVideoWidget->setOperationMode(true, false);
    mVideoWidget -> show();
    player -> stop();

    static char mjpeg;
    mjpeg ++;
    if (mjpeg > 3) mjpeg = 0;
    switch (mjpeg)
    {
    case 0:
        mService ->textCompression("20%");
        mVideoWidget -> pictureCompression(0);
        break;

    case 1:
        mService ->textCompression("50%");
        mVideoWidget -> pictureCompression(1);
        break;

    case 2:
        mService -> textCompression("70%");
        mVideoWidget -> pictureCompression(2);
        break;

    case 3:
        mService -> textCompression("90%");
        mVideoWidget -> pictureCompression(3);
        break;
    }
}

void MainWindow::h264Picture()
{
    mVideoWidget->setOperationMode(false, false);
    mVideoWidget -> hide();
    player->stop();

    static char comprH264;
    comprH264 ++;
    if (comprH264 > 3) comprH264 = 0;
    switch (comprH264)
    {
    case 0:
        mService ->textCompression("20%");
        player->setMedia(QUrl(PICTURE_WF_0));
        break;

    case 1:
        mService ->textCompression("50%");
        player->setMedia(QUrl(PICTURE_WF_5));
        break;

    case 2:
        mService ->textCompression("70%");
        player -> setMedia(QUrl(PICTURE_WF_7));
        break;

    case 3:
        mService ->textCompression("90%");
        player -> setMedia(QUrl(PICTURE_WF_9));
        break;
    }
    player -> play();
}

void MainWindow::on_inversiaButton_clicked()
{
    inversia();
}

void MainWindow::on_ReturnButton_clicked()
{
    Action *close_action = new Action(ACTION_TO_ZERO,0);
    ActionList::getSingletonPtr()->setAction(close_action);
}

void MainWindow::on_digitalStabilization_clicked()
{
    if (inversia_stabilization)
    {
        mTrackingZala -> digitalStabilization();
        if (flagInversia)
        {
            ui -> digitalStabilization -> setStyleSheet(COLOR_BUTTON_OFF_NORMA);
            inversia_stabilization = false;
        }
        else
        {
            ui -> digitalStabilization-> setStyleSheet(COLOR_BUTTON_OFF_INVERSIA);
            inversia_stabilization = false;
        }
    }
    else
    {
        mTrackingZala -> normalMode();
        if (flagInversia)
        {
            ui -> digitalStabilization -> setStyleSheet(COLOR_BUTTON_ON_NORMA);
            inversia_stabilization = true;
        }
        else
        {
            ui -> digitalStabilization -> setStyleSheet(COLOR_BUTTON_ON_INVERSIA);
            inversia_stabilization = true;
        }
    }
}

void MainWindow::on_filtrButton_clicked()
{
    if (isFilter)
    {
        mOptWidget -> setFilter(true);
        if (flagInversia)
        {
            ui -> filtrButton -> setStyleSheet(COLOR_BUTTON_OFF_NORMA);
            isFilter = false;
        }
        else
        {
            ui -> filtrButton -> setStyleSheet(COLOR_BUTTON_OFF_INVERSIA);
            isFilter = false;
        }
//        appendLog(tr("Filter enabled"));
    }
    else
    {
        mOptWidget -> setFilter(false);
        if (flagInversia)
        {
            ui -> filtrButton -> setStyleSheet(COLOR_BUTTON_ON_NORMA);
            isFilter = true;
        }
        else
        {
            ui -> filtrButton -> setStyleSheet(COLOR_BUTTON_ON_INVERSIA);
            isFilter = true;
        }
//        appendLog(tr("Filter disabled"));
    }
}

void MainWindow::on_modePictureButton_clicked()
{
    static char videoType;
    videoType++;
    if (!inversia_stabilization)
    {
        if (!flagInversia) ui -> digitalStabilization -> setStyleSheet(COLOR_BUTTON_ON_INVERSIA);
        else               ui -> digitalStabilization -> setStyleSheet(COLOR_BUTTON_ON_NORMA);

        inversia_stabilization = true;

    }
    if (videoType > 4) videoType = 0;
    switch (videoType)
    {
        case 0:
            mTrackingZala -> normalMode();
            break;

        case 1:
            mTrackingZala -> pictureInPicture();
            break;

        case 2:
            mTrackingZala->smallPictureInPicture();
            break;

        case 3:
            mTrackingZala->horizontalLine();
            break;

        case 4:
           mTrackingZala -> verticalLine();
           break;
    }
}

void MainWindow::on_actionNormal_mode_triggered()
{
    /*    txf.can_dlc = 4;
        txf.can_id = 1211;
        txf.data[0] =0b00000100;
        txf.data[1] =0b00000000;
        txf.data[2] =0b00000000;
        txf.data[3] =0b00000000;
    //    appendLog("Normal mode");
        server->FramesToBytes(&txf);
    */ mTrackingZala -> normalMode();
    if (!inversia_stabilization)
    {
        if (!flagInversia) ui -> digitalStabilization -> setStyleSheet(COLOR_BUTTON_ON_INVERSIA);
        else               ui -> digitalStabilization -> setStyleSheet(COLOR_BUTTON_ON_NORMA);

    }
//    qDebug()<<"normal";
}

void MainWindow::on_actionPicture_in_picture_triggered()
{
    /*    txf.can_dlc = 4;
        txf.can_id = 1211;
        txf.data[0] =0b00000110;
        txf.data[1] =0b00000000;
        txf.data[2] =0b00000000;
        txf.data[3] =0b00000000;
    //    appendLog("Picture in Picture");
        server->FramesToBytes(&txf);
    */ mTrackingZala -> pictureInPicture();
    if (!inversia_stabilization)
    {
        if (!flagInversia) ui -> digitalStabilization -> setStyleSheet(COLOR_BUTTON_ON_INVERSIA);
        else               ui -> digitalStabilization -> setStyleSheet(COLOR_BUTTON_ON_NORMA);

    }
//    qDebug() << "picture in picture";
}

void MainWindow::on_actionSmall_picture_in_picture_triggered()
{
    /*    txf.can_dlc = 4;
        txf.can_id = 1211;
        txf.data[0] =0b00001111;
        txf.data[1] =0b00000000;
        txf.data[2] =0b00000000;
        txf.data[3] =0b00000000;
    //    appendLog("Small in Picture");
        server->FramesToBytes(&txf);
    */ mTrackingZala -> smallPictureInPicture();
    if (!inversia_stabilization)
    {
        if (!flagInversia) ui -> digitalStabilization -> setStyleSheet(COLOR_BUTTON_ON_INVERSIA);
        else               ui -> digitalStabilization -> setStyleSheet(COLOR_BUTTON_ON_NORMA);

    }
//    qDebug() << "SmallPicture";
}

void MainWindow::on_actionHorizontal_line_triggered()
{
    /*    txf.can_dlc = 4;
        txf.can_id = 1211;
        txf.data[0] =0b00001101;
        txf.data[1] =0b00000000;
        txf.data[2] =0b00000000;
        txf.data[3] =0b00000000;
    //    appendLog("Horizontal line");
        server->FramesToBytes(&txf);
    */	mTrackingZala -> horizontalLine();
    if (!inversia_stabilization)
    {
        if (!flagInversia) ui -> digitalStabilization -> setStyleSheet(COLOR_BUTTON_ON_INVERSIA);
        else               ui -> digitalStabilization -> setStyleSheet(COLOR_BUTTON_ON_NORMA);

    }
//    qDebug()<<"Horizontal";
}

void MainWindow::on_actionVertical_line_triggered()
{
    /*    txf.can_dlc = 4;
        txf.can_id = 1211;
        txf.data[0] =0b00001110;
        txf.data[1] =0b00000000;
        txf.data[2] =0b00000000;
        txf.data[3] =0b00000000;
    //    appendLog("Vertikal line");
        server->FramesToBytes(&txf);
    */ mTrackingZala -> verticalLine();
    if (!inversia_stabilization)
    {
        if (!flagInversia) ui -> digitalStabilization -> setStyleSheet(COLOR_BUTTON_ON_INVERSIA);
        else               ui -> digitalStabilization -> setStyleSheet(COLOR_BUTTON_ON_NORMA);

    }
//    qDebug() << "Vertical";
}

void MainWindow::on_actionDigital_stabilization_triggered()
{
    /*    txf.can_dlc = 4;
        txf.can_id = 1211;
        txf.data[0] =0b00000101;
        txf.data[1] =0b00000000;
        txf.data[2] =0b00000000;
        txf.data[3] =0b00000000;
    //    appendLog("Digital Stabilizaton");
        server->FramesToBytes(&txf);
    */mTrackingZala -> digitalStabilization();
//    qDebug() << "digital";
}
/*
void MainWindow::on_h264Button_clicked()
{
    ui->mjpegButton->setStyleSheet(COLOR_BUTTON_ON_NORMA);
    mVideoWidget->setOperationMode(false, false);
    mVideoWidget -> hide();
    player->stop();

    static char comprH264;
    comprH264 ++;
    if (comprH264 > 3) comprH264 = 0;
    switch (comprH264)
    {
    case 0:
        ui -> compressionLabel -> setText("20%");
        player->setMedia(QUrl(PICTURE_WF_0));
        break;

    case 1:
        ui->compressionLabel-> setText("50%");
        player->setMedia(QUrl(PICTURE_WF_5));
        break;

    case 2:
        ui->compressionLabel->setText("70%");
        player -> setMedia(QUrl(PICTURE_WF_7));
        break;

    case 3:
        ui->compressionLabel->setText("90%");
        player -> setMedia(QUrl(PICTURE_WF_9));
        break;
    }
    player -> play();
    ui ->h264Button->setStyleSheet(COLOR_BUTTON_OFF_NORMA);

}
*/

void MainWindow::on_mjpegButton_clicked()
{

    ui->h264Button->setStyleSheet(COLOR_BUTTON_ON_NORMA);
    mVideoWidget->setOperationMode(true, false);
    mVideoWidget -> show();
    player -> stop();

    static char comprH264;
    comprH264 ++;
    if (comprH264 > 3) comprH264 = 0;
    switch (comprH264)
    {
    case 0:
        ui -> compressionLabel -> setText("20%");
        mVideoWidget -> pictureCompression(0);
        break;

    case 1:
        ui -> compressionLabel-> setText("50%");
        mVideoWidget -> pictureCompression(1);
        break;

    case 2:
        ui->compressionLabel->setText("70%");
        mVideoWidget -> pictureCompression(2);
        break;

    case 3:
        ui->compressionLabel->setText("90%");
        mVideoWidget -> pictureCompression(3);
        break;
    }
    ui ->mjpegButton->setStyleSheet(COLOR_BUTTON_OFF_NORMA);
}

void MainWindow::on_serviceButton_clicked()
{
    mService -> show();
}

void MainWindow::on_exitButton_clicked()
{
    mControllerManager->closeDevice();
    QApplication::exit(149);
}
