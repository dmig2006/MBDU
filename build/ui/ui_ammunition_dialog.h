/********************************************************************************
** Form generated from reading UI file 'ammunition_dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AMMUNITION_DIALOG_H
#define UI_AMMUNITION_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_AmmunitionDialog
{
public:
    QLabel *ammunitionMeasurementUnit;
    QLineEdit *ammunitionInput;
    QPushButton *applyButton;
    QPushButton *cancelButton;

    void setupUi(QDialog *AmmunitionDialog)
    {
        if (AmmunitionDialog->objectName().isEmpty())
            AmmunitionDialog->setObjectName(QStringLiteral("AmmunitionDialog"));
        AmmunitionDialog->resize(270, 97);
        ammunitionMeasurementUnit = new QLabel(AmmunitionDialog);
        ammunitionMeasurementUnit->setObjectName(QStringLiteral("ammunitionMeasurementUnit"));
        ammunitionMeasurementUnit->setGeometry(QRect(75, 35, 70, 25));
        ammunitionInput = new QLineEdit(AmmunitionDialog);
        ammunitionInput->setObjectName(QStringLiteral("ammunitionInput"));
        ammunitionInput->setGeometry(QRect(10, 35, 60, 25));
        ammunitionInput->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        applyButton = new QPushButton(AmmunitionDialog);
        applyButton->setObjectName(QStringLiteral("applyButton"));
        applyButton->setGeometry(QRect(170, 10, 90, 30));
        cancelButton = new QPushButton(AmmunitionDialog);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));
        cancelButton->setGeometry(QRect(170, 50, 90, 30));

        retranslateUi(AmmunitionDialog);

        QMetaObject::connectSlotsByName(AmmunitionDialog);
    } // setupUi

    void retranslateUi(QDialog *AmmunitionDialog)
    {
        AmmunitionDialog->setWindowTitle(QApplication::translate("AmmunitionDialog", "Dialog", Q_NULLPTR));
        ammunitionMeasurementUnit->setText(QApplication::translate("AmmunitionDialog", "round(s)", Q_NULLPTR));
        ammunitionInput->setText(QString());
        applyButton->setText(QApplication::translate("AmmunitionDialog", "Apply", Q_NULLPTR));
        cancelButton->setText(QApplication::translate("AmmunitionDialog", "Cancel", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class AmmunitionDialog: public Ui_AmmunitionDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AMMUNITION_DIALOG_H
