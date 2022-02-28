#include "ammunition_dialog.h"
#include "ui_ammunition_dialog.h"

AmmunitionDialog::AmmunitionDialog(QWidget *parent) :
    QDialog(parent), ui(new Ui::AmmunitionDialog)
{
    ui->setupUi(this);
    QIntValidator *validator;
    validator = new QIntValidator(0, 1000, this);
    ui->ammunitionInput->setValidator(validator);
}

AmmunitionDialog::~AmmunitionDialog()
{
    delete ui;
}

void AmmunitionDialog::setControllerManager(ControllerManager *pControllerManager)
{
    mControllerManager = pControllerManager;
    ui->ammunitionInput->setText(QString::number(mControllerManager->getAmmunitionCounter()));
}

void AmmunitionDialog::colorInversia(bool pFlag)
{
    if (pFlag)
    {
        ui -> applyButton -> setStyleSheet(COLOR_BUTTON_NORMA_ACTIVATE);
        ui -> cancelButton -> setStyleSheet(COLOR_BUTTON_NORMA_ACTIVATE);
        ui -> ammunitionInput -> setStyleSheet(COLOR_EDIT_NORMA_ACTIVATE);
        ui -> ammunitionMeasurementUnit -> setStyleSheet(COLOR_LABEL_NORMA);
    }
    else
    {
        ui -> applyButton -> setStyleSheet(COLOR_BUTTON_INVERSIA_ACTIVATE);
        ui -> cancelButton -> setStyleSheet(COLOR_BUTTON_INVERSIA_ACTIVATE);
        ui -> ammunitionInput -> setStyleSheet(COLOR_EDIT_INVERSIA_ACTIVATE);
        ui -> ammunitionMeasurementUnit -> setStyleSheet(COLOR_LABEL_INVERSIA);
    }
}

void AmmunitionDialog::changeEvent(QEvent *event)
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

void AmmunitionDialog::closeEvent(QCloseEvent *event)
{
    mControllerManager->setPause(false);
    event->accept();
}

void AmmunitionDialog::timerEvent(QTimerEvent *)
{
    long lValue = ui->ammunitionInput->text().toLong();
    if (lValue > 0 && lValue < 100000)
        ui->applyButton->setEnabled(true);
    else
        ui->applyButton->setEnabled(false);
}

void AmmunitionDialog::on_applyButton_clicked()
{
    long lValue = ui->ammunitionInput->text().toLong();
    if (lValue > 0 && lValue < 100000)
        mControllerManager->setAmmunitionCounter(lValue, true);
    mControllerManager->setPause(false);
    close();
}

void AmmunitionDialog::on_cancelButton_clicked()
{
    mControllerManager->setPause(false);
    close();
}
