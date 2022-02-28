#ifndef TARGETEDITOR_H
#define TARGETEDITOR_H

#include <QMutex>
#include <QDialog>
#include <QListWidgetItem>
#include <QCloseEvent>
#include <QChar>

#include "aimlist.h"
#include "controllermanager.h"

namespace Ui {
    class TargetEditorDialog;
}

class TargetEditorDialog : public QDialog
{
    Q_OBJECT

    Ui::TargetEditorDialog *ui;
    ControllerManager *mControllerManager;
    QList<Aim*> currentAims;
    QColor colorChange;
    QColor colorUnchange;

    void initList();
    void saveList();
    void addItem(Aim *pAim);
    void setItem(int row, Aim *pAim);
    void editItem(int row, Aim *pAim);


public:
    TargetEditorDialog(QWidget *parent = 0);
    ~TargetEditorDialog();
    void setControllerManager(ControllerManager *pControllerManager);
    QListWidgetItem* ParsingAim(int row, Aim *pAim);
    void colorInversia(bool pFlag);

protected:
    void changeEvent(QEvent *event);
    void closeEvent(QCloseEvent *event);
    void paintEvent(QPaintEvent *);

Q_SLOT
    void on_apply_Button_clicked();
Q_SLOT
    void on_close_Button_clicked();

private slots:
    void on_choose_activate_Button_clicked();
    void on_choose_no_activate_Button_clicked();
    void on_activate_selected_Button_clicked();
    void on_activate_all_Button_clicked();
    void on_deactive_all_Button_clicked();
    void on_remove_selected_Button_clicked();
    void on_remove_all_Button_clicked();
    void on_deactivate_selecte_Button_clicked();
    void on_listWidget_clicked(/*const QModelIndex &index*/);
};

#endif // TARGETEDITOR_H
