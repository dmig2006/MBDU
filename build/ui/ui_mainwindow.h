/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action;
    QAction *actionStand_by_mode;
    QAction *actionOperation_mode;
    QAction *actionBurst_length;
    QAction *actionAmmunition;
    QAction *actionClose;
    QAction *actionSound_signal;
    QAction *actionAdjustment;
    QAction *action_2;
    QAction *actionNormal_mode;
    QAction *actionPicture_in_picture;
    QAction *actionSmall_picture_in_picture;
    QAction *actionHorizontal_line;
    QAction *actionVertical_line;
    QAction *actionDigital_stabilization;
    QAction *actionPID;
    QWidget *centralWidget;
    QSlider *verticalAngleSlider;
    QListWidget *LogWidget;
    QLabel *rotatingPlatformVoltageLabel;
    QLabel *powerSupplyInfo;
    QLabel *controlUnitVoltageLabel;
    QFrame *line_3;
    QLabel *fireLabel;
    QLabel *fire;
    QLabel *fireResolutionLabel;
    QLabel *fireTypeLabel;
    QLabel *burstTypeLabel;
    QLabel *cockingLabel;
    QLabel *fireResolution;
    QLabel *fireType;
    QLabel *burstType;
    QLabel *cocking;
    QLabel *horizontalSpeed;
    QLabel *verticalSpeed;
    QPushButton *deleteAimButton;
    QPushButton *editAimButton;
    QPushButton *autoModeButton;
    QLabel *rangeLabel;
    QLabel *temperatureLabel;
    QLabel *pressureLabel;
    QLabel *windLabel;
    QLineEdit *rangeInput;
    QLabel *rangeMeasurementUnit;
    QLineEdit *temperatureInput;
    QLabel *temperatureMeasurementUnit;
    QLabel *pressureMeasurementUnit;
    QLabel *windXArrowLabel;
    QLabel *windYArrowLabel;
    QLabel *windXMeasurementUnit;
    QLabel *windYMeasurementUnit;
    QFrame *line_1;
    QLabel *controlUnitVoltage;
    QLabel *rotatingPlatformVoltage;
    QLabel *horizontalSpeedLabel;
    QLabel *verticalSpeedLabel;
    QFrame *line_2;
    QLabel *controlUnitVoltageMeasurementUnit;
    QLabel *rotatingPlatformVoltageMeasurementUnit;
    QPushButton *filtrButton;
    QPushButton *digitalStabilization;
    QPushButton *inversiaButton;
    QPushButton *modePictureButton;
    QPushButton *ReturnButton;
    QFrame *line_4;
    QLabel *aimNumberLabel;
    QLabel *aimCoordinatesLabel;
    QLabel *aimNumber;
    QLabel *aimDistanceLabel;
    QLabel *horizontalAimCoordinate;
    QLabel *verticalAimCoordinate;
    QLabel *aimDistance;
    QLabel *weaponType;
    QFrame *line_6;
    QFrame *line_5;
    QLabel *ammunition;
    QLabel *verticalAngle;
    QLabel *horizontalAngleLabel;
    QLabel *horizontalAngle;
    QLabel *verticalAngleLabel;
    QLabel *camera;
    QLabel *stabilization;
    QLabel *cameraLabel;
    QLabel *stabilizationLabel;
    QLineEdit *pressureInput;
    QLineEdit *windXInput;
    QLineEdit *windYInput;
    QFrame *line_7;
    QFrame *line_8;
    QFrame *line_9;
    QPushButton *h264Button;
    QPushButton *mjpegButton;
    QLabel *compressionTitle;
    QLabel *compressionLabel;
    QGraphicsView *graphicsView;
    QPushButton *exitButton;
    QPushButton *serviceButton;
    QMenuBar *menuBar;
    QMenu *stationMenu;
    QMenu *powerConsuptionMenu;
    QMenu *armamentMenu;
    QMenu *alertMenu;
    QMenu *menuMode_video;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->setWindowModality(Qt::WindowModal);
        MainWindow->setEnabled(true);
        MainWindow->resize(1920, 1080);
        MainWindow->setContextMenuPolicy(Qt::NoContextMenu);
        MainWindow->setAcceptDrops(false);
        MainWindow->setAutoFillBackground(false);
        MainWindow->setStyleSheet(QLatin1String("QWidget#widget{\n"
"     border-style: solid;\n"
"     border-width: 1px;\n"
"     border-radius: 10px;\n"
"	 border-color: rgb(205, 205, 205);\n"
"     padding: 6px;\n"
" }\n"
"QGroupBox {\n"
"     border-style: solid;\n"
"     border-width: 1px;\n"
"     border-radius: 10px;\n"
"	 border-color: rgb(205, 205, 205);\n"
"     padding: 6px;\n"
" }\n"
"QListView{\n"
"     border-style: solid;\n"
"     border-width: 1px;\n"
"     border-radius: 10px;\n"
"	 border-color: rgb(205, 205, 205);\n"
"     padding: 6px;\n"
" }"));
        MainWindow->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        MainWindow->setAnimated(false);
        MainWindow->setDocumentMode(false);
        MainWindow->setTabShape(QTabWidget::Triangular);
        MainWindow->setDockNestingEnabled(false);
        MainWindow->setUnifiedTitleAndToolBarOnMac(true);
        action = new QAction(MainWindow);
        action->setObjectName(QStringLiteral("action"));
        action->setEnabled(false);
        actionStand_by_mode = new QAction(MainWindow);
        actionStand_by_mode->setObjectName(QStringLiteral("actionStand_by_mode"));
        actionStand_by_mode->setCheckable(true);
        actionStand_by_mode->setChecked(false);
        actionStand_by_mode->setEnabled(true);
        actionStand_by_mode->setAutoRepeat(false);
        actionOperation_mode = new QAction(MainWindow);
        actionOperation_mode->setObjectName(QStringLiteral("actionOperation_mode"));
        actionOperation_mode->setCheckable(true);
        actionOperation_mode->setChecked(true);
        actionOperation_mode->setEnabled(true);
        actionOperation_mode->setAutoRepeat(false);
        actionBurst_length = new QAction(MainWindow);
        actionBurst_length->setObjectName(QStringLiteral("actionBurst_length"));
        actionAmmunition = new QAction(MainWindow);
        actionAmmunition->setObjectName(QStringLiteral("actionAmmunition"));
        actionClose = new QAction(MainWindow);
        actionClose->setObjectName(QStringLiteral("actionClose"));
        actionSound_signal = new QAction(MainWindow);
        actionSound_signal->setObjectName(QStringLiteral("actionSound_signal"));
        actionAdjustment = new QAction(MainWindow);
        actionAdjustment->setObjectName(QStringLiteral("actionAdjustment"));
        action_2 = new QAction(MainWindow);
        action_2->setObjectName(QStringLiteral("action_2"));
        action_2->setEnabled(false);
        actionNormal_mode = new QAction(MainWindow);
        actionNormal_mode->setObjectName(QStringLiteral("actionNormal_mode"));
        actionNormal_mode->setEnabled(true);
        actionNormal_mode->setAutoRepeat(true);
        actionPicture_in_picture = new QAction(MainWindow);
        actionPicture_in_picture->setObjectName(QStringLiteral("actionPicture_in_picture"));
        actionSmall_picture_in_picture = new QAction(MainWindow);
        actionSmall_picture_in_picture->setObjectName(QStringLiteral("actionSmall_picture_in_picture"));
        actionHorizontal_line = new QAction(MainWindow);
        actionHorizontal_line->setObjectName(QStringLiteral("actionHorizontal_line"));
        actionVertical_line = new QAction(MainWindow);
        actionVertical_line->setObjectName(QStringLiteral("actionVertical_line"));
        actionDigital_stabilization = new QAction(MainWindow);
        actionDigital_stabilization->setObjectName(QStringLiteral("actionDigital_stabilization"));
        actionPID = new QAction(MainWindow);
        actionPID->setObjectName(QStringLiteral("actionPID"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalAngleSlider = new QSlider(centralWidget);
        verticalAngleSlider->setObjectName(QStringLiteral("verticalAngleSlider"));
        verticalAngleSlider->setEnabled(false);
        verticalAngleSlider->setGeometry(QRect(1385, -20, 29, 1101));
        verticalAngleSlider->setCursor(QCursor(Qt::ArrowCursor));
        verticalAngleSlider->setAutoFillBackground(false);
        verticalAngleSlider->setStyleSheet(QLatin1String("QSlider#verticalSlider{\n"
"	color: rgb(255, 255, 255);\n"
"}"));
        verticalAngleSlider->setMinimum(-2000);
        verticalAngleSlider->setMaximum(6000);
        verticalAngleSlider->setPageStep(1);
        verticalAngleSlider->setValue(2000);
        verticalAngleSlider->setSliderPosition(2000);
        verticalAngleSlider->setTracking(true);
        verticalAngleSlider->setOrientation(Qt::Vertical);
        verticalAngleSlider->setTickPosition(QSlider::NoTicks);
        LogWidget = new QListWidget(centralWidget);
        LogWidget->setObjectName(QStringLiteral("LogWidget"));
        LogWidget->setGeometry(QRect(20, 870, 221, 161));
        LogWidget->setFocusPolicy(Qt::ClickFocus);
        LogWidget->setSelectionMode(QAbstractItemView::SingleSelection);
        LogWidget->setViewMode(QListView::ListMode);
        LogWidget->setSelectionRectVisible(false);
        rotatingPlatformVoltageLabel = new QLabel(centralWidget);
        rotatingPlatformVoltageLabel->setObjectName(QStringLiteral("rotatingPlatformVoltageLabel"));
        rotatingPlatformVoltageLabel->setGeometry(QRect(1643, 330, 31, 20));
        QFont font;
        font.setFamily(QStringLiteral("Sans"));
        font.setPointSize(12);
        rotatingPlatformVoltageLabel->setFont(font);
        rotatingPlatformVoltageLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        powerSupplyInfo = new QLabel(centralWidget);
        powerSupplyInfo->setObjectName(QStringLiteral("powerSupplyInfo"));
        powerSupplyInfo->setGeometry(QRect(1740, 304, 41, 41));
        QFont font1;
        font1.setPointSize(7);
        powerSupplyInfo->setFont(font1);
        powerSupplyInfo->setAlignment(Qt::AlignCenter);
        controlUnitVoltageLabel = new QLabel(centralWidget);
        controlUnitVoltageLabel->setObjectName(QStringLiteral("controlUnitVoltageLabel"));
        controlUnitVoltageLabel->setGeometry(QRect(1642, 300, 31, 20));
        QFont font2;
        font2.setPointSize(12);
        controlUnitVoltageLabel->setFont(font2);
        controlUnitVoltageLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        line_3 = new QFrame(centralWidget);
        line_3->setObjectName(QStringLiteral("line_3"));
        line_3->setGeometry(QRect(1674, 540, 3, 191));
        line_3->setFrameShape(QFrame::VLine);
        line_3->setFrameShadow(QFrame::Sunken);
        fireLabel = new QLabel(centralWidget);
        fireLabel->setObjectName(QStringLiteral("fireLabel"));
        fireLabel->setGeometry(QRect(1720, 80, 90, 20));
        fireLabel->setFont(font2);
        fireLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        fire = new QLabel(centralWidget);
        fire->setObjectName(QStringLiteral("fire"));
        fire->setGeometry(QRect(1830, 80, 71, 20));
        fire->setFont(font2);
        fireResolutionLabel = new QLabel(centralWidget);
        fireResolutionLabel->setObjectName(QStringLiteral("fireResolutionLabel"));
        fireResolutionLabel->setGeometry(QRect(1689, 110, 131, 20));
        fireResolutionLabel->setFont(font2);
        fireResolutionLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        fireTypeLabel = new QLabel(centralWidget);
        fireTypeLabel->setObjectName(QStringLiteral("fireTypeLabel"));
        fireTypeLabel->setGeometry(QRect(1689, 140, 131, 20));
        fireTypeLabel->setFont(font2);
        fireTypeLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        burstTypeLabel = new QLabel(centralWidget);
        burstTypeLabel->setObjectName(QStringLiteral("burstTypeLabel"));
        burstTypeLabel->setGeometry(QRect(1730, 170, 90, 20));
        burstTypeLabel->setFont(font2);
        burstTypeLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        cockingLabel = new QLabel(centralWidget);
        cockingLabel->setObjectName(QStringLiteral("cockingLabel"));
        cockingLabel->setGeometry(QRect(1730, 200, 90, 20));
        cockingLabel->setFont(font2);
        cockingLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        fireResolution = new QLabel(centralWidget);
        fireResolution->setObjectName(QStringLiteral("fireResolution"));
        fireResolution->setGeometry(QRect(1830, 110, 71, 20));
        fireResolution->setFont(font2);
        fireType = new QLabel(centralWidget);
        fireType->setObjectName(QStringLiteral("fireType"));
        fireType->setGeometry(QRect(1830, 140, 71, 20));
        fireType->setFont(font2);
        burstType = new QLabel(centralWidget);
        burstType->setObjectName(QStringLiteral("burstType"));
        burstType->setGeometry(QRect(1830, 170, 71, 20));
        burstType->setFont(font2);
        cocking = new QLabel(centralWidget);
        cocking->setObjectName(QStringLiteral("cocking"));
        cocking->setGeometry(QRect(1830, 200, 71, 20));
        cocking->setFont(font2);
        horizontalSpeed = new QLabel(centralWidget);
        horizontalSpeed->setObjectName(QStringLiteral("horizontalSpeed"));
        horizontalSpeed->setGeometry(QRect(1500, 1000, 50, 20));
        horizontalSpeed->setFont(font2);
        horizontalSpeed->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        verticalSpeed = new QLabel(centralWidget);
        verticalSpeed->setObjectName(QStringLiteral("verticalSpeed"));
        verticalSpeed->setGeometry(QRect(1590, 1000, 41, 20));
        verticalSpeed->setFont(font2);
        verticalSpeed->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        deleteAimButton = new QPushButton(centralWidget);
        deleteAimButton->setObjectName(QStringLiteral("deleteAimButton"));
        deleteAimButton->setEnabled(false);
        deleteAimButton->setGeometry(QRect(1424, 610, 221, 51));
        deleteAimButton->setFont(font2);
        deleteAimButton->setLocale(QLocale(QLocale::Russian, QLocale::Russia));
        editAimButton = new QPushButton(centralWidget);
        editAimButton->setObjectName(QStringLiteral("editAimButton"));
        editAimButton->setEnabled(false);
        editAimButton->setGeometry(QRect(1424, 540, 221, 51));
        editAimButton->setFont(font2);
        autoModeButton = new QPushButton(centralWidget);
        autoModeButton->setObjectName(QStringLiteral("autoModeButton"));
        autoModeButton->setGeometry(QRect(1424, 684, 221, 51));
        autoModeButton->setFont(font2);
        rangeLabel = new QLabel(centralWidget);
        rangeLabel->setObjectName(QStringLiteral("rangeLabel"));
        rangeLabel->setGeometry(QRect(1411, 73, 121, 21));
        rangeLabel->setFont(font2);
        temperatureLabel = new QLabel(centralWidget);
        temperatureLabel->setObjectName(QStringLiteral("temperatureLabel"));
        temperatureLabel->setGeometry(QRect(1410, 25, 121, 21));
        temperatureLabel->setFont(font2);
        pressureLabel = new QLabel(centralWidget);
        pressureLabel->setObjectName(QStringLiteral("pressureLabel"));
        pressureLabel->setGeometry(QRect(1431, 118, 101, 25));
        pressureLabel->setFont(font2);
        windLabel = new QLabel(centralWidget);
        windLabel->setObjectName(QStringLiteral("windLabel"));
        windLabel->setGeometry(QRect(1445, 168, 61, 25));
        windLabel->setFont(font2);
        rangeInput = new QLineEdit(centralWidget);
        rangeInput->setObjectName(QStringLiteral("rangeInput"));
        rangeInput->setGeometry(QRect(1544, 64, 61, 41));
        rangeInput->setFont(font2);
        rangeInput->setFocusPolicy(Qt::ClickFocus);
        rangeMeasurementUnit = new QLabel(centralWidget);
        rangeMeasurementUnit->setObjectName(QStringLiteral("rangeMeasurementUnit"));
        rangeMeasurementUnit->setGeometry(QRect(1610, 72, 21, 25));
        rangeMeasurementUnit->setFont(font2);
        temperatureInput = new QLineEdit(centralWidget);
        temperatureInput->setObjectName(QStringLiteral("temperatureInput"));
        temperatureInput->setGeometry(QRect(1544, 15, 61, 41));
        temperatureInput->setFont(font2);
        temperatureInput->setFocusPolicy(Qt::ClickFocus);
        temperatureInput->setLayoutDirection(Qt::LeftToRight);
        temperatureInput->setStyleSheet(QStringLiteral(""));
        temperatureMeasurementUnit = new QLabel(centralWidget);
        temperatureMeasurementUnit->setObjectName(QStringLiteral("temperatureMeasurementUnit"));
        temperatureMeasurementUnit->setGeometry(QRect(1610, 25, 21, 21));
        temperatureMeasurementUnit->setFont(font2);
        pressureMeasurementUnit = new QLabel(centralWidget);
        pressureMeasurementUnit->setObjectName(QStringLiteral("pressureMeasurementUnit"));
        pressureMeasurementUnit->setGeometry(QRect(1610, 118, 64, 25));
        pressureMeasurementUnit->setFont(font2);
        windXArrowLabel = new QLabel(centralWidget);
        windXArrowLabel->setObjectName(QStringLiteral("windXArrowLabel"));
        windXArrowLabel->setGeometry(QRect(1504, 169, 40, 25));
        QFont font3;
        font3.setPointSize(16);
        windXArrowLabel->setFont(font3);
        windXArrowLabel->setAlignment(Qt::AlignCenter);
        windYArrowLabel = new QLabel(centralWidget);
        windYArrowLabel->setObjectName(QStringLiteral("windYArrowLabel"));
        windYArrowLabel->setGeometry(QRect(1516, 218, 21, 25));
        windYArrowLabel->setFont(font3);
        windYArrowLabel->setAlignment(Qt::AlignCenter);
        windXMeasurementUnit = new QLabel(centralWidget);
        windXMeasurementUnit->setObjectName(QStringLiteral("windXMeasurementUnit"));
        windXMeasurementUnit->setGeometry(QRect(1610, 170, 31, 25));
        windXMeasurementUnit->setFont(font2);
        windYMeasurementUnit = new QLabel(centralWidget);
        windYMeasurementUnit->setObjectName(QStringLiteral("windYMeasurementUnit"));
        windYMeasurementUnit->setGeometry(QRect(1609, 217, 31, 25));
        windYMeasurementUnit->setFont(font2);
        line_1 = new QFrame(centralWidget);
        line_1->setObjectName(QStringLiteral("line_1"));
        line_1->setGeometry(QRect(1790, 1000, 3, 20));
        line_1->setFrameShape(QFrame::VLine);
        line_1->setFrameShadow(QFrame::Sunken);
        controlUnitVoltage = new QLabel(centralWidget);
        controlUnitVoltage->setObjectName(QStringLiteral("controlUnitVoltage"));
        controlUnitVoltage->setGeometry(QRect(1678, 300, 30, 20));
        controlUnitVoltage->setFont(font2);
        controlUnitVoltage->setAlignment(Qt::AlignCenter);
        rotatingPlatformVoltage = new QLabel(centralWidget);
        rotatingPlatformVoltage->setObjectName(QStringLiteral("rotatingPlatformVoltage"));
        rotatingPlatformVoltage->setGeometry(QRect(1680, 330, 30, 20));
        rotatingPlatformVoltage->setFont(font2);
        rotatingPlatformVoltage->setAlignment(Qt::AlignCenter);
        horizontalSpeedLabel = new QLabel(centralWidget);
        horizontalSpeedLabel->setObjectName(QStringLiteral("horizontalSpeedLabel"));
        horizontalSpeedLabel->setGeometry(QRect(1480, 1000, 20, 20));
        horizontalSpeedLabel->setFont(font2);
        verticalSpeedLabel = new QLabel(centralWidget);
        verticalSpeedLabel->setObjectName(QStringLiteral("verticalSpeedLabel"));
        verticalSpeedLabel->setGeometry(QRect(1570, 1000, 20, 20));
        verticalSpeedLabel->setFont(font2);
        line_2 = new QFrame(centralWidget);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setGeometry(QRect(1557, 1000, 3, 20));
        line_2->setFrameShape(QFrame::VLine);
        line_2->setFrameShadow(QFrame::Sunken);
        controlUnitVoltageMeasurementUnit = new QLabel(centralWidget);
        controlUnitVoltageMeasurementUnit->setObjectName(QStringLiteral("controlUnitVoltageMeasurementUnit"));
        controlUnitVoltageMeasurementUnit->setGeometry(QRect(1708, 300, 20, 20));
        controlUnitVoltageMeasurementUnit->setFont(font2);
        controlUnitVoltageMeasurementUnit->setAlignment(Qt::AlignCenter);
        rotatingPlatformVoltageMeasurementUnit = new QLabel(centralWidget);
        rotatingPlatformVoltageMeasurementUnit->setObjectName(QStringLiteral("rotatingPlatformVoltageMeasurementUnit"));
        rotatingPlatformVoltageMeasurementUnit->setGeometry(QRect(1710, 330, 20, 20));
        rotatingPlatformVoltageMeasurementUnit->setFont(font2);
        rotatingPlatformVoltageMeasurementUnit->setAlignment(Qt::AlignCenter);
        filtrButton = new QPushButton(centralWidget);
        filtrButton->setObjectName(QStringLiteral("filtrButton"));
        filtrButton->setGeometry(QRect(1424, 380, 221, 51));
        filtrButton->setFont(font2);
        filtrButton->setStyleSheet(QStringLiteral(""));
        digitalStabilization = new QPushButton(centralWidget);
        digitalStabilization->setObjectName(QStringLiteral("digitalStabilization"));
        digitalStabilization->setGeometry(QRect(1684, 380, 211, 51));
        digitalStabilization->setFont(font2);
        digitalStabilization->setStyleSheet(QStringLiteral(""));
        inversiaButton = new QPushButton(centralWidget);
        inversiaButton->setObjectName(QStringLiteral("inversiaButton"));
        inversiaButton->setGeometry(QRect(1684, 450, 211, 51));
        inversiaButton->setStyleSheet(QLatin1String("QPushButton#inversiaButton\n"
"{\n"
"    background-color:#D4D4D4;\n"
"	image: url(://res/images/Moon.png);\n"
"	border: 2px outset #a0a0a0;\n"
"	border-radius: 4px;\n"
"}\n"
"    QPushButton#inversiaButton:pressed\n"
"{\n"
"	background-color: #D4D4D4;\n"
"	image: url(://res/images/Moon.png);\n"
"    border: 2px inset #a0a0a0;\n"
"    border-radius: 4px;\n"
"}"));
        modePictureButton = new QPushButton(centralWidget);
        modePictureButton->setObjectName(QStringLiteral("modePictureButton"));
        modePictureButton->setGeometry(QRect(1424, 450, 221, 51));
        modePictureButton->setFont(font2);
        ReturnButton = new QPushButton(centralWidget);
        ReturnButton->setObjectName(QStringLiteral("ReturnButton"));
        ReturnButton->setGeometry(QRect(1800, 840, 111, 61));
        QFont font4;
        font4.setPointSize(18);
        ReturnButton->setFont(font4);
        line_4 = new QFrame(centralWidget);
        line_4->setObjectName(QStringLiteral("line_4"));
        line_4->setGeometry(QRect(1429, 1028, 471, 3));
        line_4->setFrameShape(QFrame::HLine);
        line_4->setFrameShadow(QFrame::Sunken);
        aimNumberLabel = new QLabel(centralWidget);
        aimNumberLabel->setObjectName(QStringLiteral("aimNumberLabel"));
        aimNumberLabel->setGeometry(QRect(1694, 546, 131, 20));
        QFont font5;
        font5.setPointSize(12);
        font5.setBold(false);
        font5.setItalic(false);
        font5.setWeight(50);
        aimNumberLabel->setFont(font5);
        aimNumberLabel->setAlignment(Qt::AlignCenter);
        aimCoordinatesLabel = new QLabel(centralWidget);
        aimCoordinatesLabel->setObjectName(QStringLiteral("aimCoordinatesLabel"));
        aimCoordinatesLabel->setGeometry(QRect(1704, 592, 121, 20));
        aimCoordinatesLabel->setFont(font5);
        aimCoordinatesLabel->setAlignment(Qt::AlignCenter);
        aimNumber = new QLabel(centralWidget);
        aimNumber->setObjectName(QStringLiteral("aimNumber"));
        aimNumber->setGeometry(QRect(1844, 550, 71, 20));
        aimNumber->setFont(font5);
        aimNumber->setAlignment(Qt::AlignCenter);
        aimDistanceLabel = new QLabel(centralWidget);
        aimDistanceLabel->setObjectName(QStringLiteral("aimDistanceLabel"));
        aimDistanceLabel->setGeometry(QRect(1697, 667, 121, 20));
        aimDistanceLabel->setFont(font5);
        aimDistanceLabel->setAlignment(Qt::AlignCenter);
        horizontalAimCoordinate = new QLabel(centralWidget);
        horizontalAimCoordinate->setObjectName(QStringLiteral("horizontalAimCoordinate"));
        horizontalAimCoordinate->setGeometry(QRect(1844, 596, 71, 20));
        horizontalAimCoordinate->setFont(font5);
        horizontalAimCoordinate->setAlignment(Qt::AlignCenter);
        verticalAimCoordinate = new QLabel(centralWidget);
        verticalAimCoordinate->setObjectName(QStringLiteral("verticalAimCoordinate"));
        verticalAimCoordinate->setGeometry(QRect(1844, 625, 71, 20));
        verticalAimCoordinate->setFont(font5);
        verticalAimCoordinate->setAlignment(Qt::AlignCenter);
        aimDistance = new QLabel(centralWidget);
        aimDistance->setObjectName(QStringLiteral("aimDistance"));
        aimDistance->setGeometry(QRect(1844, 670, 71, 20));
        aimDistance->setFont(font5);
        aimDistance->setAlignment(Qt::AlignCenter);
        weaponType = new QLabel(centralWidget);
        weaponType->setObjectName(QStringLiteral("weaponType"));
        weaponType->setGeometry(QRect(1730, 710, 51, 20));
        weaponType->setFont(font2);
        weaponType->setAlignment(Qt::AlignCenter);
        line_6 = new QFrame(centralWidget);
        line_6->setObjectName(QStringLiteral("line_6"));
        line_6->setGeometry(QRect(1422, 256, 491, 3));
        line_6->setFrameShape(QFrame::HLine);
        line_6->setFrameShadow(QFrame::Sunken);
        line_5 = new QFrame(centralWidget);
        line_5->setObjectName(QStringLiteral("line_5"));
        line_5->setGeometry(QRect(1785, 685, 3, 50));
        line_5->setFrameShape(QFrame::VLine);
        line_5->setFrameShadow(QFrame::Sunken);
        ammunition = new QLabel(centralWidget);
        ammunition->setObjectName(QStringLiteral("ammunition"));
        ammunition->setGeometry(QRect(1790, 710, 51, 20));
        ammunition->setFont(font2);
        ammunition->setAlignment(Qt::AlignCenter);
        verticalAngle = new QLabel(centralWidget);
        verticalAngle->setObjectName(QStringLiteral("verticalAngle"));
        verticalAngle->setGeometry(QRect(1822, 1000, 61, 21));
        verticalAngle->setFont(font2);
        verticalAngle->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        horizontalAngleLabel = new QLabel(centralWidget);
        horizontalAngleLabel->setObjectName(QStringLiteral("horizontalAngleLabel"));
        horizontalAngleLabel->setGeometry(QRect(1696, 1000, 20, 20));
        horizontalAngleLabel->setFont(font2);
        horizontalAngleLabel->setAlignment(Qt::AlignCenter);
        horizontalAngle = new QLabel(centralWidget);
        horizontalAngle->setObjectName(QStringLiteral("horizontalAngle"));
        horizontalAngle->setGeometry(QRect(1719, 1002, 61, 20));
        horizontalAngle->setFont(font2);
        horizontalAngle->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        verticalAngleLabel = new QLabel(centralWidget);
        verticalAngleLabel->setObjectName(QStringLiteral("verticalAngleLabel"));
        verticalAngleLabel->setGeometry(QRect(1802, 1000, 20, 20));
        verticalAngleLabel->setFont(font2);
        verticalAngleLabel->setAlignment(Qt::AlignCenter);
        camera = new QLabel(centralWidget);
        camera->setObjectName(QStringLiteral("camera"));
        camera->setGeometry(QRect(1580, 330, 61, 20));
        camera->setFont(font2);
        stabilization = new QLabel(centralWidget);
        stabilization->setObjectName(QStringLiteral("stabilization"));
        stabilization->setGeometry(QRect(1580, 300, 61, 20));
        stabilization->setFont(font2);
        cameraLabel = new QLabel(centralWidget);
        cameraLabel->setObjectName(QStringLiteral("cameraLabel"));
        cameraLabel->setGeometry(QRect(1499, 330, 81, 20));
        cameraLabel->setFont(font2);
        stabilizationLabel = new QLabel(centralWidget);
        stabilizationLabel->setObjectName(QStringLiteral("stabilizationLabel"));
        stabilizationLabel->setGeometry(QRect(1430, 300, 140, 20));
        stabilizationLabel->setFont(font2);
        pressureInput = new QLineEdit(centralWidget);
        pressureInput->setObjectName(QStringLiteral("pressureInput"));
        pressureInput->setGeometry(QRect(1544, 112, 61, 41));
        pressureInput->setFont(font2);
        pressureInput->setFocusPolicy(Qt::ClickFocus);
        windXInput = new QLineEdit(centralWidget);
        windXInput->setObjectName(QStringLiteral("windXInput"));
        windXInput->setGeometry(QRect(1544, 160, 61, 41));
        windXInput->setFont(font2);
        windXInput->setFocusPolicy(Qt::ClickFocus);
        windYInput = new QLineEdit(centralWidget);
        windYInput->setObjectName(QStringLiteral("windYInput"));
        windYInput->setGeometry(QRect(1544, 210, 61, 41));
        windYInput->setFont(font2);
        windYInput->setFocusPolicy(Qt::ClickFocus);
        line_7 = new QFrame(centralWidget);
        line_7->setObjectName(QStringLiteral("line_7"));
        line_7->setGeometry(QRect(1433, 360, 481, 3));
        line_7->setFrameShape(QFrame::HLine);
        line_7->setFrameShadow(QFrame::Sunken);
        line_8 = new QFrame(centralWidget);
        line_8->setObjectName(QStringLiteral("line_8"));
        line_8->setGeometry(QRect(1420, 517, 481, 3));
        line_8->setFrameShape(QFrame::HLine);
        line_8->setFrameShadow(QFrame::Sunken);
        line_9 = new QFrame(centralWidget);
        line_9->setObjectName(QStringLiteral("line_9"));
        line_9->setGeometry(QRect(1420, 750, 481, 3));
        line_9->setFrameShape(QFrame::HLine);
        line_9->setFrameShadow(QFrame::Sunken);
        h264Button = new QPushButton(centralWidget);
        h264Button->setObjectName(QStringLiteral("h264Button"));
        h264Button->setGeometry(QRect(868, 300, 91, 61));
        h264Button->setFont(font2);
        mjpegButton = new QPushButton(centralWidget);
        mjpegButton->setObjectName(QStringLiteral("mjpegButton"));
        mjpegButton->setGeometry(QRect(1810, 760, 91, 61));
        mjpegButton->setFont(font2);
        compressionTitle = new QLabel(centralWidget);
        compressionTitle->setObjectName(QStringLiteral("compressionTitle"));
        compressionTitle->setGeometry(QRect(1060, 280, 71, 20));
        compressionTitle->setFont(font2);
        compressionTitle->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        compressionLabel = new QLabel(centralWidget);
        compressionLabel->setObjectName(QStringLiteral("compressionLabel"));
        compressionLabel->setGeometry(QRect(1060, 320, 71, 20));
        compressionLabel->setFont(font2);
        compressionLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        graphicsView = new QGraphicsView(centralWidget);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setGeometry(QRect(10, 10, 1380, 1040));
        exitButton = new QPushButton(centralWidget);
        exitButton->setObjectName(QStringLiteral("exitButton"));
        exitButton->setGeometry(QRect(1684, 20, 211, 51));
        exitButton->setFont(font2);
        exitButton->setStyleSheet(QLatin1String("QPushButton#exitButton\n"
"{\n"
"    background-color:#D4D4D4;\n"
"	image: url(://res/images/OFF_PNG.png);\n"
"	border: 2px outset #a0a0a0;\n"
"	border-radius: 4px;\n"
"}\n"
"    QPushButton#exitButton:pressed\n"
"{\n"
"	background-color: #D4D4D4;\n"
"	image: url(://res/images/OFF_PNG.png);\n"
"    border: 2px inset #a0a0a0;\n"
"    border-radius: 4px;\n"
"}\n"
""));
        serviceButton = new QPushButton(centralWidget);
        serviceButton->setObjectName(QStringLiteral("serviceButton"));
        serviceButton->setGeometry(QRect(1793, 277, 111, 61));
        serviceButton->setFont(font2);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1920, 27));
        stationMenu = new QMenu(menuBar);
        stationMenu->setObjectName(QStringLiteral("stationMenu"));
        stationMenu->setTearOffEnabled(false);
        stationMenu->setSeparatorsCollapsible(false);
        powerConsuptionMenu = new QMenu(menuBar);
        powerConsuptionMenu->setObjectName(QStringLiteral("powerConsuptionMenu"));
        armamentMenu = new QMenu(menuBar);
        armamentMenu->setObjectName(QStringLiteral("armamentMenu"));
        alertMenu = new QMenu(menuBar);
        alertMenu->setObjectName(QStringLiteral("alertMenu"));
        menuMode_video = new QMenu(menuBar);
        menuMode_video->setObjectName(QStringLiteral("menuMode_video"));
        MainWindow->setMenuBar(menuBar);

        menuBar->addAction(stationMenu->menuAction());
        menuBar->addAction(powerConsuptionMenu->menuAction());
        menuBar->addAction(armamentMenu->menuAction());
        menuBar->addAction(alertMenu->menuAction());
        menuBar->addAction(menuMode_video->menuAction());
        stationMenu->addAction(actionAdjustment);
        stationMenu->addAction(actionClose);
        powerConsuptionMenu->addAction(actionStand_by_mode);
        powerConsuptionMenu->addAction(actionOperation_mode);
        armamentMenu->addAction(actionBurst_length);
        armamentMenu->addAction(actionAmmunition);
        alertMenu->addAction(actionSound_signal);
        menuMode_video->addAction(actionNormal_mode);
        menuMode_video->addAction(actionPicture_in_picture);
        menuMode_video->addAction(actionSmall_picture_in_picture);
        menuMode_video->addAction(actionHorizontal_line);
        menuMode_video->addAction(actionVertical_line);
        menuMode_video->addAction(actionDigital_stabilization);

        retranslateUi(MainWindow);
        QObject::connect(action, SIGNAL(changed()), MainWindow, SLOT(close()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "\320\234\320\221\320\224\320\243", Q_NULLPTR));
#ifndef QT_NO_STATUSTIP
        MainWindow->setStatusTip(QString());
#endif // QT_NO_STATUSTIP
        action->setText(QApplication::translate("MainWindow", "Adjustment", Q_NULLPTR));
        actionStand_by_mode->setText(QApplication::translate("MainWindow", "\320\224\320\265\320\266\321\203\321\200\320\275\321\213\320\271 \321\200\320\265\320\266\320\270\320\274", Q_NULLPTR));
        actionOperation_mode->setText(QApplication::translate("MainWindow", "\320\240\320\260\320\261\320\276\321\207\320\270\320\271 \321\200\320\265\320\266\320\270\320\274", Q_NULLPTR));
        actionBurst_length->setText(QApplication::translate("MainWindow", "\320\224\320\273\320\270\320\275\320\260 \320\276\321\207\320\265\321\200\320\265\320\264\320\270", Q_NULLPTR));
        actionAmmunition->setText(QApplication::translate("MainWindow", "\320\221\320\276\320\265\320\267\320\260\320\277\320\260\321\201", Q_NULLPTR));
        actionClose->setText(QApplication::translate("MainWindow", "\320\222\321\213\320\272\320\273\321\216\321\207\320\265\320\275\320\270\320\265", Q_NULLPTR));
        actionSound_signal->setText(QApplication::translate("MainWindow", "\320\227\320\262\321\203\320\272\320\276\320\262\320\276\320\271 \321\201\320\270\320\263\320\275\320\260\320\273", Q_NULLPTR));
        actionAdjustment->setText(QApplication::translate("MainWindow", "\320\256\321\201\321\202\320\270\321\200\320\276\320\262\320\272\320\260", Q_NULLPTR));
        action_2->setText(QApplication::translate("MainWindow", "\320\235\320\276\321\200\320\274\320\260\320\273\321\214\320\275\321\213\320\271 \321\200\320\265\320\266\320\270\320\274", Q_NULLPTR));
        actionNormal_mode->setText(QApplication::translate("MainWindow", "\320\235\320\276\321\200\320\274\320\260\320\273\321\214\320\275\321\213\320\271 \321\200\320\265\320\266\320\270\320\274", Q_NULLPTR));
        actionPicture_in_picture->setText(QApplication::translate("MainWindow", "\320\232\320\260\321\200\321\202\320\270\320\275\320\272\320\260 \320\262 \320\272\320\260\321\200\321\202\320\270\320\275\320\272\320\265", Q_NULLPTR));
        actionSmall_picture_in_picture->setText(QApplication::translate("MainWindow", "\320\234\320\260\320\273\320\260\321\217 \320\272\320\260\321\200\321\202\320\270\320\275\320\272\320\260 \320\262 \320\272\320\260\321\200\321\202\320\270\320\275\320\272\320\265", Q_NULLPTR));
        actionHorizontal_line->setText(QApplication::translate("MainWindow", "\320\223\320\276\321\200\320\270\320\267\320\276\320\275\321\202\320\260\320\273\321\214\320\275\320\276\320\265 \321\200\320\260\320\267\320\264\320\265\320\273\320\265\320\275\320\270\320\265", Q_NULLPTR));
        actionVertical_line->setText(QApplication::translate("MainWindow", "\320\222\320\265\321\200\321\202\320\270\320\272\320\260\320\273\321\214\320\275\320\276\320\265 \321\200\320\260\320\267\320\264\320\265\320\273\320\265\320\275\320\270\320\265", Q_NULLPTR));
        actionDigital_stabilization->setText(QApplication::translate("MainWindow", "\320\246\320\270\321\204\321\200\320\276\320\262\320\260\321\217 \321\201\321\202\320\260\320\261\320\270\320\273\320\270\320\267\320\260\321\206\320\270\321\217", Q_NULLPTR));
        actionPID->setText(QApplication::translate("MainWindow", "PID", Q_NULLPTR));
        rotatingPlatformVoltageLabel->setText(QApplication::translate("MainWindow", "\320\237\320\237:", Q_NULLPTR));
        powerSupplyInfo->setText(QString());
        controlUnitVoltageLabel->setText(QApplication::translate("MainWindow", "\320\221\320\243:", Q_NULLPTR));
        fireLabel->setText(QApplication::translate("MainWindow", "\320\236\320\223\320\236\320\235\320\254:", Q_NULLPTR));
        fire->setText(QApplication::translate("MainWindow", "---", Q_NULLPTR));
        fireResolutionLabel->setText(QApplication::translate("MainWindow", "\320\240\320\220\320\227\320\240\320\225\320\250\320\225\320\235\320\230\320\225:", Q_NULLPTR));
        fireTypeLabel->setText(QApplication::translate("MainWindow", "\320\242\320\230\320\237 \320\241\320\242\320\240\320\225\320\233\320\254\320\221\320\253:", Q_NULLPTR));
        burstTypeLabel->setText(QApplication::translate("MainWindow", "\320\236\320\247\320\225\320\240\320\225\320\224\320\254:", Q_NULLPTR));
        cockingLabel->setText(QApplication::translate("MainWindow", "\320\222\320\227\320\222\320\236\320\224:", Q_NULLPTR));
        fireResolution->setText(QApplication::translate("MainWindow", "---", Q_NULLPTR));
        fireType->setText(QApplication::translate("MainWindow", "---", Q_NULLPTR));
        burstType->setText(QApplication::translate("MainWindow", "---", Q_NULLPTR));
        cocking->setText(QApplication::translate("MainWindow", "---", Q_NULLPTR));
        horizontalSpeed->setText(QApplication::translate("MainWindow", "000.00", Q_NULLPTR));
        verticalSpeed->setText(QApplication::translate("MainWindow", "000.00", Q_NULLPTR));
        deleteAimButton->setText(QApplication::translate("MainWindow", "\320\243\320\224\320\220\320\233\320\230\320\242\320\254 \320\246\320\225\320\233\320\254", Q_NULLPTR));
        editAimButton->setText(QApplication::translate("MainWindow", "\320\240\320\225\320\224\320\220\320\232\320\242\320\230\320\240\320\236\320\222\320\220\320\242\320\254 \320\246\320\225\320\233\320\254", Q_NULLPTR));
        autoModeButton->setText(QApplication::translate("MainWindow", "\320\242\320\230\320\237 \320\220\320\222\320\242\320\236\320\240\320\225\320\226\320\230\320\234\320\220", Q_NULLPTR));
        rangeLabel->setText(QApplication::translate("MainWindow", "\320\240\320\220\320\241\320\241\320\242\320\236\320\257\320\235\320\230\320\225:", Q_NULLPTR));
        temperatureLabel->setText(QApplication::translate("MainWindow", "\320\242\320\225\320\234\320\237\320\225\320\240\320\220\320\242\320\243\320\240\320\220:", Q_NULLPTR));
        pressureLabel->setText(QApplication::translate("MainWindow", "\320\224\320\220\320\222\320\233\320\225\320\235\320\230\320\225:", Q_NULLPTR));
        windLabel->setText(QApplication::translate("MainWindow", "\320\222\320\225\320\242\320\225\320\240:", Q_NULLPTR));
        rangeInput->setInputMask(QString());
        rangeInput->setText(QApplication::translate("MainWindow", "100", Q_NULLPTR));
        rangeMeasurementUnit->setText(QApplication::translate("MainWindow", "\320\274.", Q_NULLPTR));
        temperatureInput->setText(QApplication::translate("MainWindow", "15", Q_NULLPTR));
        temperatureMeasurementUnit->setText(QApplication::translate("MainWindow", "\313\232C", Q_NULLPTR));
        pressureMeasurementUnit->setText(QApplication::translate("MainWindow", "\320\274\320\274.\321\200\321\202.\321\201\321\202", Q_NULLPTR));
        windXArrowLabel->setText(QApplication::translate("MainWindow", "\342\206\222", Q_NULLPTR));
        windYArrowLabel->setText(QApplication::translate("MainWindow", "\342\206\223", Q_NULLPTR));
        windXMeasurementUnit->setText(QApplication::translate("MainWindow", "\320\274/\321\201", Q_NULLPTR));
        windYMeasurementUnit->setText(QApplication::translate("MainWindow", "\320\274/\321\201", Q_NULLPTR));
        controlUnitVoltage->setText(QApplication::translate("MainWindow", "--.-", Q_NULLPTR));
        rotatingPlatformVoltage->setText(QApplication::translate("MainWindow", "--.-", Q_NULLPTR));
        horizontalSpeedLabel->setText(QApplication::translate("MainWindow", "\320\223:", Q_NULLPTR));
        verticalSpeedLabel->setText(QApplication::translate("MainWindow", "\320\222:", Q_NULLPTR));
        controlUnitVoltageMeasurementUnit->setText(QApplication::translate("MainWindow", "V", Q_NULLPTR));
        rotatingPlatformVoltageMeasurementUnit->setText(QApplication::translate("MainWindow", "V", Q_NULLPTR));
        filtrButton->setText(QApplication::translate("MainWindow", "\320\244\320\230\320\233\320\254\320\242\320\240\320\220\320\246\320\230\320\257", Q_NULLPTR));
        digitalStabilization->setText(QApplication::translate("MainWindow", "\320\246\320\230\320\244\320\240.\320\241\320\242\320\220\320\221", Q_NULLPTR));
        inversiaButton->setText(QString());
        modePictureButton->setText(QApplication::translate("MainWindow", "\320\224\320\222\320\225 \320\232\320\220\320\234\320\225\320\240\320\253", Q_NULLPTR));
        ReturnButton->setText(QApplication::translate("MainWindow", ">0<", Q_NULLPTR));
        aimNumberLabel->setText(QApplication::translate("MainWindow", "\320\235\320\236\320\234\320\225\320\240 \320\246\320\225\320\233\320\230:", Q_NULLPTR));
        aimCoordinatesLabel->setText(QApplication::translate("MainWindow", "\320\232\320\236\320\236\320\240\320\224\320\230\320\235\320\220\320\242\320\253:", Q_NULLPTR));
        aimNumber->setText(QApplication::translate("MainWindow", "---", Q_NULLPTR));
        aimDistanceLabel->setText(QApplication::translate("MainWindow", "\320\224\320\220\320\233\320\254\320\235\320\236\320\241\320\242\320\254:", Q_NULLPTR));
        horizontalAimCoordinate->setText(QApplication::translate("MainWindow", "---", Q_NULLPTR));
        verticalAimCoordinate->setText(QApplication::translate("MainWindow", "---", Q_NULLPTR));
        aimDistance->setText(QApplication::translate("MainWindow", "---", Q_NULLPTR));
        weaponType->setText(QApplication::translate("MainWindow", "\320\232\320\236\320\240\320\224", Q_NULLPTR));
        ammunition->setText(QApplication::translate("MainWindow", "0", Q_NULLPTR));
        verticalAngle->setText(QApplication::translate("MainWindow", "000.00\302\260", Q_NULLPTR));
        horizontalAngleLabel->setText(QApplication::translate("MainWindow", "\320\223:", Q_NULLPTR));
        horizontalAngle->setText(QApplication::translate("MainWindow", "000.00\302\260", Q_NULLPTR));
        verticalAngleLabel->setText(QApplication::translate("MainWindow", "\320\222:", Q_NULLPTR));
        camera->setText(QApplication::translate("MainWindow", "\320\250\320\227", Q_NULLPTR));
        stabilization->setText(QApplication::translate("MainWindow", "\320\222\320\253\320\232\320\233", Q_NULLPTR));
        cameraLabel->setText(QApplication::translate("MainWindow", "\320\232\320\220\320\234\320\225\320\240\320\220:", Q_NULLPTR));
        stabilizationLabel->setText(QApplication::translate("MainWindow", "\320\241\320\242\320\220\320\221\320\230\320\233\320\230\320\227\320\220\320\246\320\230\320\257:", Q_NULLPTR));
        pressureInput->setText(QApplication::translate("MainWindow", "750", Q_NULLPTR));
        windXInput->setText(QApplication::translate("MainWindow", "0", Q_NULLPTR));
        windYInput->setText(QApplication::translate("MainWindow", "0", Q_NULLPTR));
        h264Button->setText(QApplication::translate("MainWindow", "H264", Q_NULLPTR));
        mjpegButton->setText(QApplication::translate("MainWindow", "MJPEG", Q_NULLPTR));
        compressionTitle->setText(QApplication::translate("MainWindow", "\320\241\320\226\320\220\320\242\320\230\320\225", Q_NULLPTR));
        compressionLabel->setText(QApplication::translate("MainWindow", "20%", Q_NULLPTR));
        exitButton->setText(QString());
        serviceButton->setText(QApplication::translate("MainWindow", "SERVICE", Q_NULLPTR));
        stationMenu->setTitle(QApplication::translate("MainWindow", "\320\232\320\276\320\274\320\277\320\273\320\265\320\272\321\201", Q_NULLPTR));
        powerConsuptionMenu->setTitle(QApplication::translate("MainWindow", "\320\255\320\275\320\265\321\200\320\263\320\276\321\201\320\261\320\265\321\200\320\265\320\266\320\265\320\275\320\270\320\265", Q_NULLPTR));
        armamentMenu->setTitle(QApplication::translate("MainWindow", "\320\222\320\276\320\276\321\200\321\203\320\266\320\265\320\275\320\270\320\265", Q_NULLPTR));
        alertMenu->setTitle(QApplication::translate("MainWindow", "\320\236\320\277\320\276\320\262\320\265\321\211\320\265\320\275\320\270\320\265", Q_NULLPTR));
        menuMode_video->setTitle(QApplication::translate("MainWindow", "\320\222\320\270\320\264\320\265\320\276 \321\200\320\265\320\266\320\270\320\274\321\213", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
