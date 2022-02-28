#include "adjustment_dialog.h"
#include "ui_adjustment_dialog.h"

AdjustmentDialog::AdjustmentDialog(QWidget *parent) :
    QDialog(parent), ui(new Ui::AdjustmentDialog)
{
    ui->setupUi(this);
    move(500, 30);
}

AdjustmentDialog::~AdjustmentDialog()
{
    delete ui;
}

void AdjustmentDialog::setControllerManager(ControllerManager *pControllerManager)
{
    mControllerManager = pControllerManager;
    mPosX = mControllerManager -> getJustX();
    mPosY = mControllerManager -> getJustY();
}

void AdjustmentDialog::colorInversia(bool pInversia)
{
    if (pInversia)
    {
        ui -> line -> setStyleSheet(COLOR_LINE_NORMA);
        ui -> line_2 -> setStyleSheet(COLOR_LINE_NORMA);
        ui -> line_3 -> setStyleSheet(COLOR_LINE_NORMA);
        ui -> line_4 -> setStyleSheet(COLOR_LINE_NORMA);

        ui -> applyButton -> setStyleSheet(COLOR_BUTTON_NORMA_ACTIVATE);
        ui -> cancelButton -> setStyleSheet(COLOR_BUTTON_NORMA_ACTIVATE);
        ui -> centerButton -> setStyleSheet(COLOR_BUTTON_NORMA_ACTIVATE);
        ui -> leftButton -> setStyleSheet(COLOR_BUTTON_NORMA_ACTIVATE);
        ui -> rightButton -> setStyleSheet(COLOR_BUTTON_NORMA_ACTIVATE);
        ui -> upButton -> setStyleSheet(COLOR_BUTTON_NORMA_ACTIVATE);
        ui -> downButton -> setStyleSheet(COLOR_BUTTON_NORMA_ACTIVATE);


    }
    else
    {
        ui -> line -> setStyleSheet(COLOR_LINE_INVERSIA);
        ui -> line_2 -> setStyleSheet(COLOR_LINE_INVERSIA);
        ui -> line_3 -> setStyleSheet(COLOR_LINE_INVERSIA);
        ui -> line_4 -> setStyleSheet(COLOR_LINE_INVERSIA);

        ui -> applyButton -> setStyleSheet(COLOR_BUTTON_INVERSIA_ACTIVATE);
        ui -> cancelButton -> setStyleSheet(COLOR_BUTTON_INVERSIA_ACTIVATE);
        ui -> centerButton -> setStyleSheet(COLOR_BUTTON_INVERSIA_ACTIVATE);
        ui -> leftButton -> setStyleSheet(COLOR_BUTTON_INVERSIA_ACTIVATE);
        ui -> rightButton -> setStyleSheet(COLOR_BUTTON_INVERSIA_ACTIVATE);
        ui -> upButton -> setStyleSheet(COLOR_BUTTON_INVERSIA_ACTIVATE);
        ui -> downButton -> setStyleSheet(COLOR_BUTTON_INVERSIA_ACTIVATE);
    }
}

void AdjustmentDialog::changeEvent(QEvent *event)
{
    QDialog::changeEvent(event);
    switch (event -> type())
    {
        case QEvent::LanguageChange:
            ui -> retranslateUi(this);
            break;
        default:
            break;
    }
}

void AdjustmentDialog::closeEvent(QCloseEvent *event)
{
    mControllerManager -> setPause(false);
    event -> accept();
}

//UP
void AdjustmentDialog::on_upButton_pressed()
{
    long pJustX = mControllerManager->getJustX();
    long pJustY = mControllerManager->getJustY();
    pJustY -= 1;
    mControllerManager->setJust(pJustX, pJustY);
}

//LEFT
void AdjustmentDialog::on_leftButton_pressed()
{
    long pJustX = mControllerManager->getJustX();
    long pJustY = mControllerManager->getJustY();
    pJustX += 1;
    mControllerManager->setJust(pJustX, pJustY);
}

//DOWN
void AdjustmentDialog::on_downButton_pressed()
{
    long pJustX = mControllerManager->getJustX();
    long pJustY = mControllerManager->getJustY();
    pJustY += 1;
    mControllerManager->setJust(pJustX, pJustY);
}

//RIGHT
void AdjustmentDialog::on_rightButton_pressed()
{
    long pJustX = mControllerManager->getJustX();
    long pJustY = mControllerManager->getJustY();
    pJustX -= 1;
    mControllerManager->setJust(pJustX, pJustY);
}

//CENTER
void AdjustmentDialog::on_centerButton_clicked()
{
    mControllerManager->setJust(0, 0);
}

//APPLY
void AdjustmentDialog::on_applyButton_released()
{
    mControllerManager->saveJust();
    mControllerManager->setPause(false);
    close();
}

//CANCEL
void AdjustmentDialog::on_cancelButton_clicked()
{
    mControllerManager->setJust(mPosX, mPosY);
    mControllerManager->setPause(false);
    close();
}
