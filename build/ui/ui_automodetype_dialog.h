/********************************************************************************
** Form generated from reading UI file 'automodetype_dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AUTOMODETYPE_DIALOG_H
#define UI_AUTOMODETYPE_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>

QT_BEGIN_NAMESPACE

class Ui_AutoModeTypeDialog
{
public:
    QPushButton *applyButton;
    QRadioButton *byHorizontalCoordinateRadioButton;
    QRadioButton *inSavingOrderRadioButton;
    QPushButton *cancelButton;

    void setupUi(QDialog *AutoModeTypeDialog)
    {
        if (AutoModeTypeDialog->objectName().isEmpty())
            AutoModeTypeDialog->setObjectName(QStringLiteral("AutoModeTypeDialog"));
        AutoModeTypeDialog->resize(368, 303);
        applyButton = new QPushButton(AutoModeTypeDialog);
        applyButton->setObjectName(QStringLiteral("applyButton"));
        applyButton->setGeometry(QRect(260, 10, 90, 30));
        byHorizontalCoordinateRadioButton = new QRadioButton(AutoModeTypeDialog);
        byHorizontalCoordinateRadioButton->setObjectName(QStringLiteral("byHorizontalCoordinateRadioButton"));
        byHorizontalCoordinateRadioButton->setGeometry(QRect(5, 45, 250, 25));
        byHorizontalCoordinateRadioButton->setAutoFillBackground(false);
        byHorizontalCoordinateRadioButton->setStyleSheet(QLatin1String("QRadioButton#byHorizontalCoordinateRadioButton\n"
"{\n"
"background:blue;\n"
"color:white;\n"
"}"));
        byHorizontalCoordinateRadioButton->setAutoRepeatDelay(300);
        inSavingOrderRadioButton = new QRadioButton(AutoModeTypeDialog);
        inSavingOrderRadioButton->setObjectName(QStringLiteral("inSavingOrderRadioButton"));
        inSavingOrderRadioButton->setGeometry(QRect(7, 13, 250, 25));
        inSavingOrderRadioButton->setStyleSheet(QLatin1String("QRadioButton::indikator\n"
"{\n"
"width: 10px;\n"
"height:10px\n"
"}\n"
"QRadioButton::indikator::unchecked\n"
"{\n"
"background:blue;\n"
"}\n"
"QRadioButton::indikator::checked\n"
"{\n"
"background:brown;\n"
"}"));
        inSavingOrderRadioButton->setChecked(true);
        cancelButton = new QPushButton(AutoModeTypeDialog);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));
        cancelButton->setGeometry(QRect(260, 50, 90, 30));

        retranslateUi(AutoModeTypeDialog);

        QMetaObject::connectSlotsByName(AutoModeTypeDialog);
    } // setupUi

    void retranslateUi(QDialog *AutoModeTypeDialog)
    {
        AutoModeTypeDialog->setWindowTitle(QApplication::translate("AutoModeTypeDialog", "Dialog", Q_NULLPTR));
        applyButton->setText(QApplication::translate("AutoModeTypeDialog", "Apply", Q_NULLPTR));
        byHorizontalCoordinateRadioButton->setText(QApplication::translate("AutoModeTypeDialog", "by horizontal coordinate", Q_NULLPTR));
        inSavingOrderRadioButton->setText(QApplication::translate("AutoModeTypeDialog", "in saving order", Q_NULLPTR));
        cancelButton->setText(QApplication::translate("AutoModeTypeDialog", "Cancel", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class AutoModeTypeDialog: public Ui_AutoModeTypeDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AUTOMODETYPE_DIALOG_H
