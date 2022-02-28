/********************************************************************************
** Form generated from reading UI file 'burstlength_dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BURSTLENGTH_DIALOG_H
#define UI_BURSTLENGTH_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_BurstLengthDialog
{
public:
    QLabel *longBurstLengthLabel;
    QLineEdit *longBurstLengthInput;
    QLabel *shortBurstLengthLabel;
    QLabel *shortBurstLengthMeasurementUnit;
    QLabel *singleShotTimeLabel;
    QLineEdit *singleShotTimeInput;
    QLabel *singleShotTimeMeasurementUnit;
    QFrame *line;
    QLineEdit *shortBurstLengthInput;
    QLabel *longBurstLengthMeasurementUnit;
    QPushButton *cancelButton;
    QPushButton *applyButton;

    void setupUi(QDialog *BurstLengthDialog)
    {
        if (BurstLengthDialog->objectName().isEmpty())
            BurstLengthDialog->setObjectName(QStringLiteral("BurstLengthDialog"));
        BurstLengthDialog->resize(464, 125);
        longBurstLengthLabel = new QLabel(BurstLengthDialog);
        longBurstLengthLabel->setObjectName(QStringLiteral("longBurstLengthLabel"));
        longBurstLengthLabel->setGeometry(QRect(20, 40, 180, 25));
        longBurstLengthInput = new QLineEdit(BurstLengthDialog);
        longBurstLengthInput->setObjectName(QStringLiteral("longBurstLengthInput"));
        longBurstLengthInput->setGeometry(QRect(205, 40, 60, 25));
        longBurstLengthInput->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        shortBurstLengthLabel = new QLabel(BurstLengthDialog);
        shortBurstLengthLabel->setObjectName(QStringLiteral("shortBurstLengthLabel"));
        shortBurstLengthLabel->setGeometry(QRect(20, 10, 180, 25));
        shortBurstLengthMeasurementUnit = new QLabel(BurstLengthDialog);
        shortBurstLengthMeasurementUnit->setObjectName(QStringLiteral("shortBurstLengthMeasurementUnit"));
        shortBurstLengthMeasurementUnit->setGeometry(QRect(270, 10, 75, 25));
        singleShotTimeLabel = new QLabel(BurstLengthDialog);
        singleShotTimeLabel->setObjectName(QStringLiteral("singleShotTimeLabel"));
        singleShotTimeLabel->setGeometry(QRect(20, 85, 180, 25));
        singleShotTimeInput = new QLineEdit(BurstLengthDialog);
        singleShotTimeInput->setObjectName(QStringLiteral("singleShotTimeInput"));
        singleShotTimeInput->setGeometry(QRect(205, 85, 60, 25));
        singleShotTimeInput->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        singleShotTimeMeasurementUnit = new QLabel(BurstLengthDialog);
        singleShotTimeMeasurementUnit->setObjectName(QStringLiteral("singleShotTimeMeasurementUnit"));
        singleShotTimeMeasurementUnit->setGeometry(QRect(270, 85, 70, 25));
        line = new QFrame(BurstLengthDialog);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(20, 75, 330, 3));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        shortBurstLengthInput = new QLineEdit(BurstLengthDialog);
        shortBurstLengthInput->setObjectName(QStringLiteral("shortBurstLengthInput"));
        shortBurstLengthInput->setGeometry(QRect(205, 10, 60, 25));
        shortBurstLengthInput->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        longBurstLengthMeasurementUnit = new QLabel(BurstLengthDialog);
        longBurstLengthMeasurementUnit->setObjectName(QStringLiteral("longBurstLengthMeasurementUnit"));
        longBurstLengthMeasurementUnit->setGeometry(QRect(270, 40, 75, 25));
        cancelButton = new QPushButton(BurstLengthDialog);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));
        cancelButton->setGeometry(QRect(360, 50, 90, 30));
        applyButton = new QPushButton(BurstLengthDialog);
        applyButton->setObjectName(QStringLiteral("applyButton"));
        applyButton->setGeometry(QRect(360, 10, 90, 30));

        retranslateUi(BurstLengthDialog);

        QMetaObject::connectSlotsByName(BurstLengthDialog);
    } // setupUi

    void retranslateUi(QDialog *BurstLengthDialog)
    {
        BurstLengthDialog->setWindowTitle(QApplication::translate("BurstLengthDialog", "Dialog", Q_NULLPTR));
        longBurstLengthLabel->setText(QApplication::translate("BurstLengthDialog", "Long Burst Length:", Q_NULLPTR));
        shortBurstLengthLabel->setText(QApplication::translate("BurstLengthDialog", "Short Burst Length:", Q_NULLPTR));
        shortBurstLengthMeasurementUnit->setText(QApplication::translate("BurstLengthDialog", "round(s)", Q_NULLPTR));
        singleShotTimeLabel->setText(QApplication::translate("BurstLengthDialog", "Single Shot Time:", Q_NULLPTR));
        singleShotTimeMeasurementUnit->setText(QApplication::translate("BurstLengthDialog", "ms", Q_NULLPTR));
        shortBurstLengthInput->setText(QString());
        longBurstLengthMeasurementUnit->setText(QApplication::translate("BurstLengthDialog", "round(s)", Q_NULLPTR));
        cancelButton->setText(QApplication::translate("BurstLengthDialog", "Cancel", Q_NULLPTR));
        applyButton->setText(QApplication::translate("BurstLengthDialog", "Apply", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class BurstLengthDialog: public Ui_BurstLengthDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BURSTLENGTH_DIALOG_H
