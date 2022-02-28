#include "servicewidget.h"
#include "ui_servicewidget.h"

serviceWidget::serviceWidget(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::serviceWidget)
{
    ui->setupUi(this);

    flagMode = true;

// Ammuniotion
    QIntValidator *validator;
    validator = new QIntValidator(0, 1000, this);
    ui->ammunitionInput->setValidator(validator);
    flagAmmunition = true;
// Ammunition

//BurstLength
    QIntValidator *short_burst_validator = new QIntValidator(1, 5, this);
    QIntValidator *long_burst_validator = new QIntValidator(6, 50, this);
    QIntValidator *single_shot_time_validator = new QIntValidator(50, 200, this);

    ui->shortBurstLengthInput->setValidator(short_burst_validator);
    ui->longBurstLengthInput->setValidator(long_burst_validator);
    ui->singleShotTimeInput->setValidator(single_shot_time_validator);
//BurstLength

//Virtual Keyboard
    ui -> ammunitionInput -> installEventFilter(this);
    ui -> shortBurstLengthInput -> installEventFilter(this);
    ui -> longBurstLengthInput -> installEventFilter(this);
    ui -> singleShotTimeInput -> installEventFilter(this);

    flagAmmunition = true;
    flagShort = true;
    flagLong = true;
    flagSingle = true;
//VirtualKeyboard
}

serviceWidget::~serviceWidget()
{
    delete ui;
}

void serviceWidget::setControllerManager(ControllerManager *pControllerManager)
{
    mControllerManager = pControllerManager;
    ui->ammunitionInput->setText(QString::number(mControllerManager->getAmmunitionCounter()));

    ui->shortBurstLengthInput->setText(QString::number(mControllerManager->getShortBurst()));
    ui->longBurstLengthInput->setText(QString::number(mControllerManager->getLongBurst()));
    ui->singleShotTimeInput->setText(QString::number(mControllerManager->getShotTime()));
}

void serviceWidget::textCompression(QString pstr)
{
    ui ->compressionValueLabel->setText(pstr);
}

void serviceWidget::colorInversia(bool pInversia)
{
    if (pInversia)
    {
        ui -> exitButton -> setStyleSheet(COLOR_BUTTON_NORMA_ACTIVATE);
        ui -> modeButton -> setStyleSheet(COLOR_BUTTON_NORMA_ACTIVATE);
        ui -> soundButton -> setStyleSheet(COLOR_BUTTON_NORMA_ACTIVATE);
        ui -> adjustmentButton -> setStyleSheet(COLOR_BUTTON_NORMA_ACTIVATE);
        ui -> applyBurstLength -> setStyleSheet(COLOR_BUTTON_NORMA_ACTIVATE);
        ui -> applyAmmunition -> setStyleSheet(COLOR_BUTTON_NORMA_ACTIVATE);

        ui -> mjpegButton -> setStyleSheet(COLOR_BUTTON_ON_NORMA);
        ui -> h264Button -> setStyleSheet(COLOR_BUTTON_ON_NORMA);

        ui -> ammunitionInput -> setStyleSheet(COLOR_EDIT_NORMA_ACTIVATE);
        ui -> shortBurstLengthInput -> setStyleSheet(COLOR_EDIT_NORMA_ACTIVATE);
        ui -> longBurstLengthInput -> setStyleSheet(COLOR_EDIT_NORMA_ACTIVATE);
        ui -> singleShotTimeInput -> setStyleSheet(COLOR_EDIT_NORMA_ACTIVATE);

        ui -> ammunitionTitleLabel -> setStyleSheet(COLOR_LABEL_NORMA);
        ui -> ammunitionValue -> setStyleSheet(COLOR_LABEL_NORMA);
        ui -> formatVideoTitleLabel -> setStyleSheet(COLOR_LABEL_NORMA);
        ui -> compressionTitle -> setStyleSheet(COLOR_LABEL_NORMA);
        ui -> compressionValueLabel -> setStyleSheet(COLOR_LABEL_NORMA);
        ui -> burstlengthTitleLabel -> setStyleSheet(COLOR_LABEL_NORMA);
        ui -> shortLabel -> setStyleSheet(COLOR_LABEL_NORMA);
        ui -> longLabel -> setStyleSheet(COLOR_LABEL_NORMA);
        ui -> singleFireLabel -> setStyleSheet(COLOR_LABEL_NORMA);
        ui -> shortUnitLabel -> setStyleSheet(COLOR_LABEL_NORMA);
        ui -> longUnitLabel -> setStyleSheet(COLOR_LABEL_NORMA);
        ui -> singleFireUnitLabel -> setStyleSheet(COLOR_LABEL_NORMA);

        ui -> line -> setStyleSheet(COLOR_LINE_NORMA);
        ui -> line_2 -> setStyleSheet(COLOR_LINE_NORMA);
        ui -> line_3 -> setStyleSheet(COLOR_LINE_NORMA);
        ui -> line_4 -> setStyleSheet(COLOR_LINE_NORMA);
        ui -> line_5 -> setStyleSheet(COLOR_LINE_NORMA);
        ui -> line_6 -> setStyleSheet(COLOR_LINE_NORMA);
        ui -> line_7 -> setStyleSheet(COLOR_LINE_NORMA);

    }
    else
    {
        ui -> exitButton -> setStyleSheet(COLOR_BUTTON_INVERSIA_ACTIVATE);
        ui -> modeButton -> setStyleSheet(COLOR_BUTTON_INVERSIA_ACTIVATE);
        ui -> soundButton -> setStyleSheet(COLOR_BUTTON_INVERSIA_ACTIVATE);
        ui -> adjustmentButton -> setStyleSheet(COLOR_BUTTON_INVERSIA_ACTIVATE);
        ui -> applyBurstLength -> setStyleSheet(COLOR_BUTTON_INVERSIA_ACTIVATE);
        ui -> applyAmmunition -> setStyleSheet(COLOR_BUTTON_INVERSIA_ACTIVATE);
        ui -> mjpegButton -> setStyleSheet(COLOR_BUTTON_INVERSIA_ACTIVATE);
        ui -> h264Button -> setStyleSheet(COLOR_BUTTON_INVERSIA_ACTIVATE);

        ui -> ammunitionInput -> setStyleSheet(COLOR_EDIT_INVERSIA_ACTIVATE);
        ui -> shortBurstLengthInput -> setStyleSheet(COLOR_EDIT_INVERSIA_ACTIVATE);
        ui -> longBurstLengthInput -> setStyleSheet(COLOR_EDIT_INVERSIA_ACTIVATE);
        ui -> singleShotTimeInput -> setStyleSheet(COLOR_EDIT_INVERSIA_ACTIVATE);

        ui -> ammunitionTitleLabel -> setStyleSheet(COLOR_LABEL_INVERSIA);
        ui -> ammunitionValue -> setStyleSheet(COLOR_LABEL_INVERSIA);
        ui -> formatVideoTitleLabel -> setStyleSheet(COLOR_LABEL_INVERSIA);
        ui -> compressionTitle -> setStyleSheet(COLOR_LABEL_INVERSIA);
        ui -> compressionValueLabel -> setStyleSheet(COLOR_LABEL_INVERSIA);
        ui -> burstlengthTitleLabel -> setStyleSheet(COLOR_LABEL_INVERSIA);
        ui -> shortLabel -> setStyleSheet(COLOR_LABEL_INVERSIA);
        ui -> longLabel -> setStyleSheet(COLOR_LABEL_INVERSIA);
        ui -> singleFireLabel -> setStyleSheet(COLOR_LABEL_INVERSIA);
        ui -> shortUnitLabel -> setStyleSheet(COLOR_LABEL_INVERSIA);
        ui -> longUnitLabel -> setStyleSheet(COLOR_LABEL_INVERSIA);
        ui -> singleFireUnitLabel -> setStyleSheet(COLOR_LABEL_INVERSIA);

        ui -> line -> setStyleSheet(COLOR_LINE_INVERSIA);
        ui -> line_2 -> setStyleSheet(COLOR_LINE_INVERSIA);
        ui -> line_3 -> setStyleSheet(COLOR_LINE_INVERSIA);
        ui -> line_4 -> setStyleSheet(COLOR_LINE_INVERSIA);
        ui -> line_5 -> setStyleSheet(COLOR_LINE_INVERSIA);
        ui -> line_6 -> setStyleSheet(COLOR_LINE_INVERSIA);
        ui -> line_7 -> setStyleSheet(COLOR_LINE_INVERSIA);
    }
}

void serviceWidget::setVirtualKeyboard(VirtualKeyboard *pVirtualKeyboard)
{
    mVirtualKeyboard = pVirtualKeyboard;
}

void serviceWidget::changeEvent(QEvent *event)
{

    QDialog::changeEvent(event);
    switch (event->type())
    {
        case QEvent::LanguageChange:
            ui->retranslateUi(this);
            break;
        default:
            break;
    }

}

void serviceWidget::closeEvent(QCloseEvent *event)
{
    mControllerManager->setPause(false);
    event->accept();
}

void serviceWidget::timerEvent(QTimerEvent *)
{
    long lValue = ui->ammunitionInput->text().toLong();
    if (lValue > 0 && lValue < 100000)
        ui->applyAmmunition->setEnabled(true);
    else
        ui->applyAmmunition->setEnabled(false);
}

bool serviceWidget::eventFilter(QObject *object, QEvent *event)
{
/*    if (object == ui -> ammunitionInput && event -> type() == QEvent::MouseButtonPress)
    {
       QMouseEvent *mouseEvent = dynamic_cast<QMouseEvent*>(event);
        if (mouseEvent != 0 && mouseEvent -> button() == Qt::LeftButton)
        {
            mVirtualKeyboard -> delChar();

            flagAmmunition = false;
            flagShort = false;
            flagLong = false;
            flagSingle = false;

            mVirtualKeyboard -> setFocus();
            mVirtualKeyboard -> show();
        }
    }
    else
        if (object == ui -> shortBurstLengthInput && event -> type() == QEvent::MouseButtonPress)
        {
            QMouseEvent *mouseEvent = dynamic_cast<QMouseEvent*>(event);
            if (mouseEvent != 0 && mouseEvent -> button() == Qt::LeftButton)
            {
                mVirtualKeyboard -> delChar();

                flagAmmunition = false;
                flagShort = false;
                flagLong = false;
                flagSingle = false;

                mVirtualKeyboard -> setFocus();
                mVirtualKeyboard -> show();
            }
        }
        else
            if (object == ui -> longBurstLengthInput && event -> type() == QEvent::MouseButtonPress)
            {
                QMouseEvent *mouseEvent = dynamic_cast<QMouseEvent*>(event);
                if (mouseEvent != 0 && mouseEvent -> button() == Qt::LeftButton)
                {
                    mVirtualKeyboard -> delChar();

                    flagAmmunition = false;
                    flagShort = false;
                    flagLong = false;
                    flagSingle = false;

                    mVirtualKeyboard -> setFocus();
                    mVirtualKeyboard -> show();
                }
            }
            else
                if (object == ui -> singleShotTimeInput && event -> type() == QEvent::MouseButtonPress)
                {
                    QMouseEvent *mouseEvent = dynamic_cast<QMouseEvent*>(event);
                    if (mouseEvent != 0 && mouseEvent -> button() == Qt::LeftButton)
                    {
                        mVirtualKeyboard -> delChar();

                        flagAmmunition = false;
                        flagShort = false;
                        flagLong = false;
                        flagSingle = false;

                        mVirtualKeyboard -> setFocus();
                        mVirtualKeyboard -> show();
                    }
                }
*/    return (QDialog::eventFilter(object, event));
}


void serviceWidget::on_adjustmentButton_clicked()
{
    emit newAdjustment();
}

void serviceWidget::on_exitButton_clicked()
{
    mControllerManager->setPause(false);
    close();
}

void serviceWidget::on_modeButton_clicked()
{
    if (flagMode)
    {
        emit newStandByMode();
        flagMode = false;
        ui -> modeButton -> setText("Дежурный режим");
    }
    else
    {
        emit newOperationMode();
        flagMode = true;
        ui -> modeButton -> setText("Рабочий режим");
    }
}

void serviceWidget::on_soundButton_clicked()
{
    emit newSound();
}

void serviceWidget::on_applyBurstLength_clicked()
{
    int short_burst = ui->shortBurstLengthInput->text().toInt();
    int long_burst = ui->longBurstLengthInput->text().toInt();
    int shot_time = ui->singleShotTimeInput->text().toInt();

    mControllerManager->setShortBurst(short_burst);
    mControllerManager->setLongBurst(long_burst);
    mControllerManager->setShotTime(shot_time);

    mControllerManager->setPause(false);
    close();
}

void serviceWidget::on_applyAmmunition_clicked()
{
    long lValue = ui->ammunitionInput->text().toLong();
    if (lValue > 0 && lValue < 100000)
        mControllerManager->setAmmunitionCounter(lValue, true);
    mControllerManager->setPause(false);
    close();
}

void serviceWidget::on_mjpegButton_clicked()
{
    ui->h264Button->setStyleSheet(COLOR_BUTTON_ON_NORMA);
    emit newMJPEG();
    ui ->mjpegButton->setStyleSheet(COLOR_BUTTON_OFF_NORMA);
}

void serviceWidget::on_h264Button_clicked()
{
    ui->mjpegButton->setStyleSheet(COLOR_BUTTON_ON_NORMA);
    emit newH264();
    ui->h264Button->setStyleSheet(COLOR_BUTTON_OFF_NORMA);
}
