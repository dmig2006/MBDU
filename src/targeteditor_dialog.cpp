#include "targeteditor_dialog.h"
#include "ui_targeteditor_dialog.h"

TargetEditorDialog::TargetEditorDialog(QWidget *parent) :
    QDialog(parent), ui(new Ui::TargetEditorDialog)
{
    colorChange = QColor(0, 0, 0, 50);
    colorUnchange = QColor(255, 255, 255, 255);
    ui->setupUi(this);
    initList();
}

TargetEditorDialog::~TargetEditorDialog()
{
    delete ui;
}

void TargetEditorDialog::setControllerManager(ControllerManager *pControllerManager)
{
    mControllerManager = pControllerManager;
}

QListWidgetItem* TargetEditorDialog::ParsingAim(int row, Aim *pAim)
{
    QListWidgetItem *newItem = new QListWidgetItem;
    if (pAim->mState)
        newItem->setCheckState(Qt::Checked);
    else
        newItem->setCheckState(Qt::Unchecked);
    QString lId = QString::number(row + 1);
    QString lnumTarget = QString::number(pAim->mTarget);
    QString lActive;
    if (pAim->mActive)
        lActive = tr("active");
    else
        lActive = tr("inactive");
    float angle = static_cast<float>(pAim->mPositionX)
                   / DEGREE_TO_CENTIDEGREE;
    if (angle < 0.0)
        angle += 360.0;

    QString lnumPosX = QString::number(angle, 0, 2);
    QString lnumPosY = QString::number(-(float)pAim->mPositionY
                                       / DEGREE_TO_CENTIDEGREE, 0, 2);
    QString lnumRange = QString::number(pAim->mRange);
    newItem->setText(lId + tr(" Target ") + lnumTarget + ", " + lActive
                     + ", " + lnumPosX + QChar(0x00b0) + ", " + lnumPosY + QChar(0x00b0) + tr(", ")
                     + lnumRange + tr(" m"));
    return newItem;
}

void TargetEditorDialog::changeEvent(QEvent *event)
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

void TargetEditorDialog::closeEvent(QCloseEvent *event)
{
    mControllerManager->setPause(false);
    event->accept();
}

void TargetEditorDialog::paintEvent(QPaintEvent *)
{
    int size = currentAims.size();
    for (int i = 0; i < size; ++i)
        if(ui->listWidget->item(i)->checkState() == Qt::Checked)
            ui->listWidget->item(i)->setBackground(QBrush(colorChange));
        else
            ui->listWidget->item(i)->setBackground(QBrush(colorUnchange));
}

void TargetEditorDialog::initList()
{
    int size = AimList::getSingletonPtr()->size();
    for (int i = 0; i < size; ++i)
    {
        Aim *lAim = AimList::getSingletonPtr()->get(i);
        setItem(i, lAim);
        currentAims.push_back(lAim);
    }
    this->repaint();
}

void TargetEditorDialog::saveList()
{
    AimList::getSingletonPtr()->clear();
    int size = currentAims.size();
    for (int i = 0; i < size; ++i)
    {
        if (ui->listWidget->item(i)->checkState() == Qt::Checked)
            currentAims[i]->mState = true;
        else
            currentAims[i]->mState = false;
        AimList::getSingletonPtr()->push(currentAims[i]);
    }
    size = AimList::getSingletonPtr()->size();
    mControllerManager->setDisplayLastAim(AimList::getSingletonPtr()->get(size - 1));
}

void TargetEditorDialog::setItem(int row, Aim *pAim)
{
    if (pAim)
    {
        QListWidgetItem *newItem = ParsingAim(row, pAim);
        ui->listWidget->insertItem(row, newItem);
    }
}

void TargetEditorDialog::editItem(int row, Aim *pAim)
{
    if (pAim)
        ui->listWidget->item(row)->setText(ParsingAim(row,pAim)->text());
}

void TargetEditorDialog::colorInversia(bool pFlag)
{
    if (pFlag)
    {
        ui -> apply_Button -> setStyleSheet(COLOR_BUTTON_NORMA_ACTIVATE);
        ui -> close_Button -> setStyleSheet(COLOR_BUTTON_NORMA_ACTIVATE);
        ui -> choose_activate_Button -> setStyleSheet(COLOR_BUTTON_NORMA_ACTIVATE);
        ui -> choose_no_activate_Button -> setStyleSheet(COLOR_BUTTON_NORMA_ACTIVATE);
        ui -> activate_selected_Button -> setStyleSheet(COLOR_BUTTON_NORMA_ACTIVATE);
        ui -> deactivate_selecte_Button -> setStyleSheet(COLOR_BUTTON_NORMA_ACTIVATE);
        ui -> activate_all_Button -> setStyleSheet(COLOR_BUTTON_NORMA_ACTIVATE);
        ui -> deactive_all_Button -> setStyleSheet(COLOR_BUTTON_NORMA_ACTIVATE);
        ui -> remove_selected_Button -> setStyleSheet(COLOR_BUTTON_NORMA_ACTIVATE);
        ui -> remove_all_Button -> setStyleSheet(COLOR_BUTTON_NORMA_ACTIVATE);

        ui -> listWidget -> setStyleSheet(COLOR_LIST_WIDGET_NORMA);
    }
    else
    {
        ui -> apply_Button -> setStyleSheet(COLOR_BUTTON_INVERSIA_ACTIVATE);
        ui -> close_Button -> setStyleSheet(COLOR_BUTTON_INVERSIA_ACTIVATE);
        ui -> choose_activate_Button -> setStyleSheet(COLOR_BUTTON_INVERSIA_ACTIVATE);
        ui -> choose_no_activate_Button -> setStyleSheet(COLOR_BUTTON_INVERSIA_ACTIVATE);
        ui -> activate_selected_Button -> setStyleSheet(COLOR_BUTTON_INVERSIA_ACTIVATE);
        ui -> deactivate_selecte_Button -> setStyleSheet(COLOR_BUTTON_INVERSIA_ACTIVATE);
        ui -> activate_all_Button -> setStyleSheet(COLOR_BUTTON_INVERSIA_ACTIVATE);
        ui -> deactive_all_Button -> setStyleSheet(COLOR_BUTTON_INVERSIA_ACTIVATE);
        ui -> remove_selected_Button -> setStyleSheet(COLOR_BUTTON_INVERSIA_ACTIVATE);
        ui -> remove_all_Button -> setStyleSheet(COLOR_BUTTON_INVERSIA_ACTIVATE);

        ui -> listWidget -> setStyleSheet(COLOR_LIST_WIDGET_INVERSIA);
    }
}

void TargetEditorDialog::on_apply_Button_clicked()
{
    saveList();
    currentAims.clear();
    mControllerManager->setPause(false);
    close();
}

void TargetEditorDialog::on_close_Button_clicked()
{
    mControllerManager->setPause(false);
    close();
}

void TargetEditorDialog::on_choose_activate_Button_clicked()
{
    int size = currentAims.size();
    for (int i = 0; i < size; ++i)
    {
        if (currentAims[i]->mActive)
            ui->listWidget->item(i)->setCheckState(Qt::Checked);
        if (!currentAims[i]->mActive)
            ui->listWidget->item(i)->setCheckState(Qt::Unchecked);
    }
    update();
}

void TargetEditorDialog::on_choose_no_activate_Button_clicked()
{
    int size = currentAims.size();
    for (int i = 0; i < size; ++i)
    {
        if (currentAims[i]->mActive)
            ui->listWidget->item(i)->setCheckState(Qt::Unchecked);
        if (!currentAims[i]->mActive)
            ui->listWidget->item(i)->setCheckState(Qt::Checked);
    }
    update();
}

void TargetEditorDialog::on_activate_selected_Button_clicked()
{
    int size = currentAims.size();
    for (int i = 0; i < size; ++i)
        if(ui->listWidget->item(i)->checkState() == Qt::Checked){
            currentAims[i]->mActive = true;
            editItem(i, currentAims[i]);
        }
    update();
}

void TargetEditorDialog::on_activate_all_Button_clicked()
{
    int size = currentAims.size();
    for (int i = 0; i < size; ++i)
    {
        currentAims[i]->mActive = true;
        editItem(i, currentAims[i]);
    }
    update();
}

void TargetEditorDialog::on_deactive_all_Button_clicked()
{
    int size = currentAims.size();
    for (int i = 0; i < size; ++i)
    {
        currentAims[i]->mActive = false;
        editItem(i, currentAims[i]);
    }
    update();
}

void TargetEditorDialog::on_remove_selected_Button_clicked()
{
    int size = currentAims.size();
    QList<Aim*> tempList;
    for (int i = 0; i < size; ++i)
        if (ui->listWidget->item(i)->checkState() == Qt::Unchecked)
            tempList.push_back(currentAims[i]);
    ui->listWidget->clear();
    currentAims.clear();
    currentAims = tempList;
    size = currentAims.size();
    for (int i = 0; i < size; ++i)
        setItem(i, currentAims.at(i));
    update();
}

void TargetEditorDialog::on_remove_all_Button_clicked()
{
    ui->listWidget->clear();
    currentAims.clear();
    update();
}

void TargetEditorDialog::on_deactivate_selecte_Button_clicked()
{
    int size = currentAims.size();
    for (int i = 0; i < size; ++i)
        if (ui->listWidget->item(i)->checkState() == Qt::Checked)
        {
            currentAims[i]->mActive = false;
            editItem(i, currentAims[i]);
        }
    update();
}

void TargetEditorDialog::on_listWidget_clicked()
{
    int size = currentAims.size();
    for (int i = 0; i < size; ++i)
        if(ui->listWidget->item(i)->isSelected())
        {
            if (ui->listWidget->item(i)->checkState() == Qt::Unchecked)
            {
                ui->listWidget->item(i)->setCheckState(Qt::Checked);
                currentAims[i]->mState = true;
            }
            else
            {
                ui->listWidget->item(i)->setCheckState(Qt::Unchecked);
                currentAims[i]->mState = false;
            }
        }
    update();
}
