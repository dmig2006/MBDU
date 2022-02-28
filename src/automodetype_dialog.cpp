#include "automodetype_dialog.h"
#include "ui_automodetype_dialog.h"

AutoModeTypeDialog::AutoModeTypeDialog(QWidget *parent) :
    QDialog(parent), ui(new Ui::AutoModeTypeDialog)
{
    ui->setupUi(this);
}

AutoModeTypeDialog::~AutoModeTypeDialog()
{
    delete ui;
}

void AutoModeTypeDialog::setControllerManager(ControllerManager *pControllerManager)
{
    mControllerManager = pControllerManager;
    switch (mControllerManager->getAutoType())
    {
        case AUTO_TYPE_ORDER:
            ui->inSavingOrderRadioButton->setChecked(true);
            break;
        case AUTO_TYPE_COORDINATE:
            ui->byHorizontalCoordinateRadioButton->setChecked(true);
            break;
    }
}

void AutoModeTypeDialog::colorInversia(bool pFlag)
{
    if (pFlag)
    {
        ui -> inSavingOrderRadioButton -> setStyleSheet(COLOR_RADIO_BUTTON_NORMA_HORIZONTAL);
        ui -> byHorizontalCoordinateRadioButton -> setStyleSheet(COLOR_RADIO_BUTTON_NORMA_HORIZONTAL);
        ui -> applyButton -> setStyleSheet(COLOR_BUTTON_NORMA_ACTIVATE);
        ui -> cancelButton -> setStyleSheet(COLOR_BUTTON_NORMA_ACTIVATE);

    }
    else
    {
        ui -> inSavingOrderRadioButton -> setStyleSheet(COLOR_RADIO_BUTTON_INVERSIA_SAVE);
        ui -> byHorizontalCoordinateRadioButton -> setStyleSheet(COLOR_RADIO_BUTTON_INVERSIA_HORIZONTAL);
        ui -> applyButton -> setStyleSheet(COLOR_BUTTON_INVERSIA_ACTIVATE);
        ui -> cancelButton -> setStyleSheet(COLOR_BUTTON_INVERSIA_ACTIVATE);
    }
}

void AutoModeTypeDialog::changeEvent(QEvent *event)
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

void AutoModeTypeDialog::closeEvent(QCloseEvent *event)
{
    mControllerManager->setPause(false);
    event->accept();
}

void AutoModeTypeDialog::on_applyButton_clicked()
{
    if (ui->inSavingOrderRadioButton->isChecked())
        mControllerManager->setAutoType(AUTO_TYPE_ORDER);
    if (ui->byHorizontalCoordinateRadioButton->isChecked())
        mControllerManager->setAutoType(AUTO_TYPE_COORDINATE);
    mControllerManager->setPause(false);
    close();
}

void AutoModeTypeDialog::on_cancelButton_clicked()
{
    mControllerManager->setPause(false);
    close();
}
