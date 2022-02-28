/********************************************************************************
** Form generated from reading UI file 'adjustment_dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADJUSTMENT_DIALOG_H
#define UI_ADJUSTMENT_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_AdjustmentDialog
{
public:
    QPushButton *leftButton;
    QFrame *line_3;
    QFrame *line_2;
    QFrame *line_4;
    QPushButton *cancelButton;
    QFrame *line;
    QPushButton *centerButton;
    QPushButton *rightButton;
    QPushButton *applyButton;
    QPushButton *downButton;
    QPushButton *upButton;

    void setupUi(QDialog *AdjustmentDialog)
    {
        if (AdjustmentDialog->objectName().isEmpty())
            AdjustmentDialog->setObjectName(QStringLiteral("AdjustmentDialog"));
        AdjustmentDialog->resize(488, 185);
        leftButton = new QPushButton(AdjustmentDialog);
        leftButton->setObjectName(QStringLiteral("leftButton"));
        leftButton->setGeometry(QRect(10, 80, 90, 30));
        QFont font;
        font.setPointSize(18);
        leftButton->setFont(font);
        line_3 = new QFrame(AdjustmentDialog);
        line_3->setObjectName(QStringLiteral("line_3"));
        line_3->setGeometry(QRect(175, 55, 3, 20));
        line_3->setFrameShape(QFrame::VLine);
        line_3->setFrameShadow(QFrame::Sunken);
        line_2 = new QFrame(AdjustmentDialog);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setGeometry(QRect(105, 95, 20, 3));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);
        line_4 = new QFrame(AdjustmentDialog);
        line_4->setObjectName(QStringLiteral("line_4"));
        line_4->setGeometry(QRect(175, 115, 3, 20));
        line_4->setFrameShape(QFrame::VLine);
        line_4->setFrameShadow(QFrame::Sunken);
        cancelButton = new QPushButton(AdjustmentDialog);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));
        cancelButton->setGeometry(QRect(380, 60, 90, 30));
        line = new QFrame(AdjustmentDialog);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(225, 95, 20, 3));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        centerButton = new QPushButton(AdjustmentDialog);
        centerButton->setObjectName(QStringLiteral("centerButton"));
        centerButton->setGeometry(QRect(130, 80, 90, 30));
        rightButton = new QPushButton(AdjustmentDialog);
        rightButton->setObjectName(QStringLiteral("rightButton"));
        rightButton->setGeometry(QRect(250, 80, 90, 30));
        rightButton->setFont(font);
        applyButton = new QPushButton(AdjustmentDialog);
        applyButton->setObjectName(QStringLiteral("applyButton"));
        applyButton->setGeometry(QRect(380, 20, 90, 30));
        downButton = new QPushButton(AdjustmentDialog);
        downButton->setObjectName(QStringLiteral("downButton"));
        downButton->setGeometry(QRect(130, 140, 90, 30));
        QFont font1;
        font1.setPointSize(18);
        font1.setBold(false);
        font1.setWeight(50);
        downButton->setFont(font1);
        upButton = new QPushButton(AdjustmentDialog);
        upButton->setObjectName(QStringLiteral("upButton"));
        upButton->setGeometry(QRect(130, 20, 90, 30));
        upButton->setFont(font);

        retranslateUi(AdjustmentDialog);

        QMetaObject::connectSlotsByName(AdjustmentDialog);
    } // setupUi

    void retranslateUi(QDialog *AdjustmentDialog)
    {
        AdjustmentDialog->setWindowTitle(QApplication::translate("AdjustmentDialog", "Dialog", Q_NULLPTR));
        leftButton->setText(QApplication::translate("AdjustmentDialog", "\342\206\220", Q_NULLPTR));
        cancelButton->setText(QApplication::translate("AdjustmentDialog", "Cancel", Q_NULLPTR));
        centerButton->setText(QApplication::translate("AdjustmentDialog", "Center", Q_NULLPTR));
        rightButton->setText(QApplication::translate("AdjustmentDialog", "\342\206\222", Q_NULLPTR));
        applyButton->setText(QApplication::translate("AdjustmentDialog", "Apply", Q_NULLPTR));
        downButton->setText(QApplication::translate("AdjustmentDialog", "\342\206\223", Q_NULLPTR));
        upButton->setText(QApplication::translate("AdjustmentDialog", "\342\206\221", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class AdjustmentDialog: public Ui_AdjustmentDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADJUSTMENT_DIALOG_H
