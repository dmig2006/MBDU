#include "virtual_keyboard.h"
#include "ui_virtual_keyboard.h"

VirtualKeyboard::VirtualKeyboard(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::VirtualKeyboard)
{
    ui->setupUi(this);

    mThermo = 15;
    mPressure = 750;
    mRange = 100;
    mWindX = 0;
    mWindY = 0;

    prevThermo = 15;
    prevPressure = 750;
    prevRange = 100;
    prevWindX = 0;
    prevWindY = 0;

    is_ctrl_pressed = false;
    is_s_pressed = false;
    is_t_pressed = false;

    pos = 0;
}

VirtualKeyboard::~VirtualKeyboard()
{
    delete ui;
}

void VirtualKeyboard::delChar()
{
    str.remove(0,pos);
    pos = 0;
}

void VirtualKeyboard::getCorrections(QString pStr, int i)
{
    switch (i)
    {
    case 1:
//        strRange = pStr;
        mRange = pStr.toLong();
        break;

    case 2:
//        strThermo = pStr;
        mThermo = pStr.toLong();
        break;

    case 3:
//        strPressure = pStr;
        mPressure = pStr.toLong();
        break;

    case 4:
//        strWindX = pStr;
        mWindX = pStr.toLong();
        break;

    case 5:
//        strWindY = pStr;
        mWindY = pStr.toLong();
        break;

    default:
        break;
    }
}

void VirtualKeyboard::setTrackingZala(TrackingZala *pTrackingZala)
{
    mTrackingZala = pTrackingZala;
}

void VirtualKeyboard::setControllerManager(ControllerManager *pControllerManager)
{
    mControllerManager = pControllerManager;
}

void VirtualKeyboard::inversia_Keyboard(bool pFlag)
{
    if (pFlag)
    {
        ui -> key_0 -> setStyleSheet(COLOR_BUTTON_NORMA_ACTIVATE);
        ui -> key_1 -> setStyleSheet(COLOR_BUTTON_NORMA_ACTIVATE);
        ui -> key_2 -> setStyleSheet(COLOR_BUTTON_NORMA_ACTIVATE);
        ui -> key_3 -> setStyleSheet(COLOR_BUTTON_NORMA_ACTIVATE);
        ui -> key_4 -> setStyleSheet(COLOR_BUTTON_NORMA_ACTIVATE);
        ui -> key_5 -> setStyleSheet(COLOR_BUTTON_NORMA_ACTIVATE);
        ui -> key_6 -> setStyleSheet(COLOR_BUTTON_NORMA_ACTIVATE);
        ui -> key_7 -> setStyleSheet(COLOR_BUTTON_NORMA_ACTIVATE);
        ui -> key_8 -> setStyleSheet(COLOR_BUTTON_NORMA_ACTIVATE);
        ui -> key_9 -> setStyleSheet(COLOR_BUTTON_NORMA_ACTIVATE);
        ui -> key_up -> setStyleSheet(COLOR_BUTTON_NORMA_ACTIVATE);
        ui -> key_down -> setStyleSheet(COLOR_BUTTON_NORMA_ACTIVATE);
        ui -> key_left -> setStyleSheet(COLOR_BUTTON_NORMA_ACTIVATE);
        ui -> key_right -> setStyleSheet(COLOR_BUTTON_NORMA_ACTIVATE);
        ui -> key_plus -> setStyleSheet(COLOR_BUTTON_NORMA_ACTIVATE);
        ui -> key_minus -> setStyleSheet(COLOR_BUTTON_NORMA_ACTIVATE);
        ui -> key_enter -> setStyleSheet(COLOR_BUTTON_NORMA_ACTIVATE);
        ui -> key_esc -> setStyleSheet(COLOR_BUTTON_NORMA_ACTIVATE);
        ui -> key_backspace -> setStyleSheet(COLOR_BUTTON_NORMA_ACTIVATE);
        ui -> key_reside -> setStyleSheet(COLOR_BUTTON_NORMA_ACTIVATE);
    }
    else
    {
        ui -> key_0 -> setStyleSheet(COLOR_BUTTON_INVERSIA_ACTIVATE);
        ui -> key_1 -> setStyleSheet(COLOR_BUTTON_INVERSIA_ACTIVATE);
        ui -> key_2 -> setStyleSheet(COLOR_BUTTON_INVERSIA_ACTIVATE);
        ui -> key_3 -> setStyleSheet(COLOR_BUTTON_INVERSIA_ACTIVATE);
        ui -> key_4 -> setStyleSheet(COLOR_BUTTON_INVERSIA_ACTIVATE);
        ui -> key_5 -> setStyleSheet(COLOR_BUTTON_INVERSIA_ACTIVATE);
        ui -> key_6 -> setStyleSheet(COLOR_BUTTON_INVERSIA_ACTIVATE);
        ui -> key_7 -> setStyleSheet(COLOR_BUTTON_INVERSIA_ACTIVATE);
        ui -> key_8 -> setStyleSheet(COLOR_BUTTON_INVERSIA_ACTIVATE);
        ui -> key_9 -> setStyleSheet(COLOR_BUTTON_INVERSIA_ACTIVATE);
        ui -> key_up -> setStyleSheet(COLOR_BUTTON_INVERSIA_ACTIVATE);
        ui -> key_down -> setStyleSheet(COLOR_BUTTON_INVERSIA_ACTIVATE);
        ui -> key_left -> setStyleSheet(COLOR_BUTTON_INVERSIA_ACTIVATE);
        ui -> key_right -> setStyleSheet(COLOR_BUTTON_INVERSIA_ACTIVATE);
        ui -> key_plus -> setStyleSheet(COLOR_BUTTON_INVERSIA_ACTIVATE);
        ui -> key_minus -> setStyleSheet(COLOR_BUTTON_INVERSIA_ACTIVATE);
        ui -> key_enter -> setStyleSheet(COLOR_BUTTON_INVERSIA_ACTIVATE);
        ui -> key_esc -> setStyleSheet(COLOR_BUTTON_INVERSIA_ACTIVATE);
        ui -> key_backspace -> setStyleSheet(COLOR_BUTTON_INVERSIA_ACTIVATE);
        ui -> key_reside -> setStyleSheet(COLOR_BUTTON_INVERSIA_ACTIVATE);
    }
}

void VirtualKeyboard::on_key_0_clicked()
{
//    qDebug() << "0";
    str = str + "0";
//    resStr = "0";
    emit newChar(str);
    pos++;
}

void VirtualKeyboard::on_key_1_clicked()
{
//    qDebug() << "1";
    str = str + "1";
//    resStr = "1";
    emit newChar(str);
    pos++;
}

void VirtualKeyboard::on_key_2_clicked()
{
//    qDebug() << "2";
    str = str + "2";
//    resStr = "2";
    emit newChar(str);
    pos++;
}

void VirtualKeyboard::on_key_3_clicked()
{
//    qDebug() << "3";
    str = str + "3";
//    resStr = "3";
    emit newChar(str);
    pos++;
}

void VirtualKeyboard::on_key_4_clicked()
{
//    qDebug() << "4";
    str = str + "4";
//    resStr = "4";
    emit newChar(str);
    pos++;
}

void VirtualKeyboard::on_key_5_clicked()
{
//    qDebug() << "5";
    str = str + "5";
//    resStr = "5";
    emit newChar(str);
    pos++;
}

void VirtualKeyboard::on_key_6_clicked()
{
//    qDebug() << "6";
    str = str + "6";
//    resStr = "6";
    emit newChar(str);
    pos++;
}

void VirtualKeyboard::on_key_7_clicked()
{
//    qDebug() << "7";
    str = str + "7";
//    resStr = "7";
    emit newChar(str);
    pos++;
}

void VirtualKeyboard::on_key_8_clicked()
{
//    qDebug() << "8";
    str = str + "8";
//    resStr = "8";
    emit newChar(str);
    pos++;
}

void VirtualKeyboard::on_key_9_clicked()
{
//    qDebug() << "9";
    str = str + "9";
//    resStr = "9";
    emit newChar(str);
    pos++;
}

void VirtualKeyboard::on_key_enter_clicked()
{
//    mData = str.toInt();
    prevRange = mRange;
    prevThermo = mThermo;
    prevPressure = mPressure;
    prevWindX = mWindX;
    prevWindY = mWindY;

    emit newDataCorrection(mRange, mThermo, mPressure,
                           mWindX, mWindY);
//    emit newDataCorrection(mData);
    str.remove(0,pos);
    pos = 0;
    close();
}

void VirtualKeyboard::on_key_plus_clicked()
{
//    qDebug() << "+";
    str = "+" + str;
//    resStr = "+";
    emit newChar(str);
    pos++;
}

void VirtualKeyboard::on_key_minus_clicked()
{
//    qDebug() << "-";
    str = "-" + str;
//    resStr = "-";
    emit newChar(str);
    pos++;
}

void VirtualKeyboard::on_key_reside_clicked()
{
//    qDebug() << ".";
    str = str + ".";
    emit newChar(str);
//    resStr = ".";
    pos++;
}

void VirtualKeyboard::on_key_backspace_clicked()
{
//    qDebug() << "reside";
    str.remove(pos-1,1);
    emit newChar(str);
}

void VirtualKeyboard::on_key_esc_clicked()
{
//    qDebug() << "ESC";
    emit newDataCorrection(prevRange, prevThermo, prevPressure,
                           prevWindX, prevWindY);
    close();
}

void VirtualKeyboard::on_key_left_clicked()
{
    if (!(mControllerManager -> enabled_as))
        mTrackingZala -> leftMove();
}

void VirtualKeyboard::on_key_down_clicked()
{
    if (!(mControllerManager -> enabled_as))
        mTrackingZala -> downMove();
}

void VirtualKeyboard::on_key_right_clicked()
{
    if (!(mControllerManager -> enabled_as))
        mTrackingZala -> rightMove();
}

void VirtualKeyboard::on_key_up_clicked()
{
    if (!(mControllerManager -> enabled_as))
        mTrackingZala -> upMove();
}

void VirtualKeyboard::keyPressEvent(QKeyEvent *event)
{
    if (event->modifiers() == Qt::ControlModifier)
    {
        is_ctrl_pressed = true;
        if (is_s_pressed && is_t_pressed)
        {
            emit newExit();
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
            if (is_ctrl_pressed && is_t_pressed)
            {
                emit newExit();
            }
            break;
        case Qt::Key_T:
            is_t_pressed = true;
            if (is_ctrl_pressed && is_s_pressed)
            {
                emit newExit();
            }
            break;
    }
}
