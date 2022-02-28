/********************************************************************************
** Form generated from reading UI file 'targeteditor_dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TARGETEDITOR_DIALOG_H
#define UI_TARGETEDITOR_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_TargetEditorDialog
{
public:
    QPushButton *activate_all_Button;
    QPushButton *remove_selected_Button;
    QPushButton *remove_all_Button;
    QListWidget *listWidget;
    QPushButton *choose_activate_Button;
    QPushButton *deactivate_selecte_Button;
    QPushButton *apply_Button;
    QPushButton *close_Button;
    QPushButton *deactive_all_Button;
    QPushButton *choose_no_activate_Button;
    QPushButton *activate_selected_Button;

    void setupUi(QDialog *TargetEditorDialog)
    {
        if (TargetEditorDialog->objectName().isEmpty())
            TargetEditorDialog->setObjectName(QStringLiteral("TargetEditorDialog"));
        TargetEditorDialog->resize(671, 509);
        activate_all_Button = new QPushButton(TargetEditorDialog);
        activate_all_Button->setObjectName(QStringLiteral("activate_all_Button"));
        activate_all_Button->setGeometry(QRect(450, 320, 211, 27));
        remove_selected_Button = new QPushButton(TargetEditorDialog);
        remove_selected_Button->setObjectName(QStringLiteral("remove_selected_Button"));
        remove_selected_Button->setGeometry(QRect(450, 420, 211, 27));
        remove_all_Button = new QPushButton(TargetEditorDialog);
        remove_all_Button->setObjectName(QStringLiteral("remove_all_Button"));
        remove_all_Button->setGeometry(QRect(450, 460, 211, 27));
        listWidget = new QListWidget(TargetEditorDialog);
        listWidget->setObjectName(QStringLiteral("listWidget"));
        listWidget->setGeometry(QRect(10, 10, 431, 481));
        listWidget->setFocusPolicy(Qt::NoFocus);
        listWidget->setContextMenuPolicy(Qt::NoContextMenu);
        listWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
        listWidget->setSelectionMode(QAbstractItemView::ExtendedSelection);
        listWidget->setUniformItemSizes(false);
        listWidget->setSelectionRectVisible(false);
        choose_activate_Button = new QPushButton(TargetEditorDialog);
        choose_activate_Button->setObjectName(QStringLiteral("choose_activate_Button"));
        choose_activate_Button->setGeometry(QRect(450, 120, 211, 27));
        deactivate_selecte_Button = new QPushButton(TargetEditorDialog);
        deactivate_selecte_Button->setObjectName(QStringLiteral("deactivate_selecte_Button"));
        deactivate_selecte_Button->setGeometry(QRect(450, 260, 211, 27));
        apply_Button = new QPushButton(TargetEditorDialog);
        apply_Button->setObjectName(QStringLiteral("apply_Button"));
        apply_Button->setGeometry(QRect(510, 20, 141, 27));
        close_Button = new QPushButton(TargetEditorDialog);
        close_Button->setObjectName(QStringLiteral("close_Button"));
        close_Button->setGeometry(QRect(510, 60, 141, 27));
        close_Button->setStyleSheet(QStringLiteral(""));
        deactive_all_Button = new QPushButton(TargetEditorDialog);
        deactive_all_Button->setObjectName(QStringLiteral("deactive_all_Button"));
        deactive_all_Button->setGeometry(QRect(450, 360, 211, 27));
        choose_no_activate_Button = new QPushButton(TargetEditorDialog);
        choose_no_activate_Button->setObjectName(QStringLiteral("choose_no_activate_Button"));
        choose_no_activate_Button->setGeometry(QRect(450, 160, 211, 27));
        activate_selected_Button = new QPushButton(TargetEditorDialog);
        activate_selected_Button->setObjectName(QStringLiteral("activate_selected_Button"));
        activate_selected_Button->setGeometry(QRect(450, 220, 211, 27));

        retranslateUi(TargetEditorDialog);

        QMetaObject::connectSlotsByName(TargetEditorDialog);
    } // setupUi

    void retranslateUi(QDialog *TargetEditorDialog)
    {
        TargetEditorDialog->setWindowTitle(QApplication::translate("TargetEditorDialog", "Dialog", Q_NULLPTR));
        activate_all_Button->setText(QApplication::translate("TargetEditorDialog", "Activate all", Q_NULLPTR));
        remove_selected_Button->setText(QApplication::translate("TargetEditorDialog", "Remove selected", Q_NULLPTR));
        remove_all_Button->setText(QApplication::translate("TargetEditorDialog", "Remove all", Q_NULLPTR));
        choose_activate_Button->setText(QApplication::translate("TargetEditorDialog", "Choose active", Q_NULLPTR));
        deactivate_selecte_Button->setText(QApplication::translate("TargetEditorDialog", "Deactivate selected", Q_NULLPTR));
        apply_Button->setText(QApplication::translate("TargetEditorDialog", "Apply", Q_NULLPTR));
        close_Button->setText(QApplication::translate("TargetEditorDialog", "Cancel", Q_NULLPTR));
        deactive_all_Button->setText(QApplication::translate("TargetEditorDialog", "Deactivate all", Q_NULLPTR));
        choose_no_activate_Button->setText(QApplication::translate("TargetEditorDialog", "Choose inactive", Q_NULLPTR));
        activate_selected_Button->setText(QApplication::translate("TargetEditorDialog", "Activate selected", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class TargetEditorDialog: public Ui_TargetEditorDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TARGETEDITOR_DIALOG_H
