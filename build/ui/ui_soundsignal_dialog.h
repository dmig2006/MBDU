/********************************************************************************
** Form generated from reading UI file 'soundsignal_dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SOUNDSIGNAL_DIALOG_H
#define UI_SOUNDSIGNAL_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>

QT_BEGIN_NAMESPACE

class Ui_SoundSignalDialog
{
public:
    QPushButton *apply_Button;
    QPushButton *test_Button;
    QPushButton *cancel_Button;
    QLabel *label_frequency_measurement_unit;
    QLabel *label_period_measurement_unit;
    QLabel *label_volume_measurement_unit;
    QLabel *label_duration_measurement_unit;
    QSlider *horizontalSlider;
    QLabel *period_label;
    QLabel *frequency_label;
    QSlider *horizontalSlider_2;
    QLabel *duration_label;
    QSlider *horizontalSlider_3;
    QSlider *horizontalSlider_4;
    QLineEdit *lineEdit;
    QPushButton *alert_Button;
    QLabel *alert_label;
    QLineEdit *lineEdit_2;
    QPushButton *battaries_Button;
    QLabel *battaries_label;
    QLabel *volume_label;

    void setupUi(QDialog *SoundSignalDialog)
    {
        if (SoundSignalDialog->objectName().isEmpty())
            SoundSignalDialog->setObjectName(QStringLiteral("SoundSignalDialog"));
        SoundSignalDialog->resize(610, 365);
        apply_Button = new QPushButton(SoundSignalDialog);
        apply_Button->setObjectName(QStringLiteral("apply_Button"));
        apply_Button->setGeometry(QRect(510, 20, 93, 27));
        test_Button = new QPushButton(SoundSignalDialog);
        test_Button->setObjectName(QStringLiteral("test_Button"));
        test_Button->setGeometry(QRect(510, 100, 93, 27));
        cancel_Button = new QPushButton(SoundSignalDialog);
        cancel_Button->setObjectName(QStringLiteral("cancel_Button"));
        cancel_Button->setGeometry(QRect(510, 60, 93, 27));
        label_frequency_measurement_unit = new QLabel(SoundSignalDialog);
        label_frequency_measurement_unit->setObjectName(QStringLiteral("label_frequency_measurement_unit"));
        label_frequency_measurement_unit->setGeometry(QRect(410, 140, 62, 17));
        label_period_measurement_unit = new QLabel(SoundSignalDialog);
        label_period_measurement_unit->setObjectName(QStringLiteral("label_period_measurement_unit"));
        label_period_measurement_unit->setGeometry(QRect(410, 50, 62, 17));
        label_volume_measurement_unit = new QLabel(SoundSignalDialog);
        label_volume_measurement_unit->setObjectName(QStringLiteral("label_volume_measurement_unit"));
        label_volume_measurement_unit->setGeometry(QRect(410, 320, 62, 17));
        label_duration_measurement_unit = new QLabel(SoundSignalDialog);
        label_duration_measurement_unit->setObjectName(QStringLiteral("label_duration_measurement_unit"));
        label_duration_measurement_unit->setGeometry(QRect(410, 240, 62, 17));
        horizontalSlider = new QSlider(SoundSignalDialog);
        horizontalSlider->setObjectName(QStringLiteral("horizontalSlider"));
        horizontalSlider->setGeometry(QRect(40, 50, 321, 20));
        horizontalSlider->setMinimum(1000);
        horizontalSlider->setMaximum(5000);
        horizontalSlider->setSingleStep(0);
        horizontalSlider->setValue(3000);
        horizontalSlider->setOrientation(Qt::Horizontal);
        period_label = new QLabel(SoundSignalDialog);
        period_label->setObjectName(QStringLiteral("period_label"));
        period_label->setGeometry(QRect(40, 20, 59, 17));
        frequency_label = new QLabel(SoundSignalDialog);
        frequency_label->setObjectName(QStringLiteral("frequency_label"));
        frequency_label->setGeometry(QRect(40, 110, 71, 17));
        horizontalSlider_2 = new QSlider(SoundSignalDialog);
        horizontalSlider_2->setObjectName(QStringLiteral("horizontalSlider_2"));
        horizontalSlider_2->setGeometry(QRect(40, 140, 321, 18));
        horizontalSlider_2->setMinimum(700);
        horizontalSlider_2->setMaximum(4700);
        horizontalSlider_2->setValue(4700);
        horizontalSlider_2->setOrientation(Qt::Horizontal);
        duration_label = new QLabel(SoundSignalDialog);
        duration_label->setObjectName(QStringLiteral("duration_label"));
        duration_label->setGeometry(QRect(40, 210, 59, 17));
        horizontalSlider_3 = new QSlider(SoundSignalDialog);
        horizontalSlider_3->setObjectName(QStringLiteral("horizontalSlider_3"));
        horizontalSlider_3->setGeometry(QRect(40, 240, 321, 18));
        horizontalSlider_3->setMinimum(1000);
        horizontalSlider_3->setMaximum(5000);
        horizontalSlider_3->setPageStep(1);
        horizontalSlider_3->setOrientation(Qt::Horizontal);
        horizontalSlider_4 = new QSlider(SoundSignalDialog);
        horizontalSlider_4->setObjectName(QStringLiteral("horizontalSlider_4"));
        horizontalSlider_4->setGeometry(QRect(40, 320, 321, 18));
        horizontalSlider_4->setMaximum(100);
        horizontalSlider_4->setPageStep(1);
        horizontalSlider_4->setValue(50);
        horizontalSlider_4->setOrientation(Qt::Horizontal);
        lineEdit = new QLineEdit(SoundSignalDialog);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setEnabled(true);
        lineEdit->setGeometry(QRect(510, 210, 91, 27));
        QPalette palette;
        QBrush brush(QColor(240, 235, 226, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Base, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush);
        QBrush brush1(QColor(255, 255, 255, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        lineEdit->setPalette(palette);
        lineEdit->setFocusPolicy(Qt::NoFocus);
        lineEdit->setAlignment(Qt::AlignCenter);
        lineEdit->setReadOnly(true);
        alert_Button = new QPushButton(SoundSignalDialog);
        alert_Button->setObjectName(QStringLiteral("alert_Button"));
        alert_Button->setGeometry(QRect(510, 170, 93, 27));
        alert_label = new QLabel(SoundSignalDialog);
        alert_label->setObjectName(QStringLiteral("alert_label"));
        alert_label->setGeometry(QRect(490, 150, 59, 17));
        lineEdit_2 = new QLineEdit(SoundSignalDialog);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setEnabled(true);
        lineEdit_2->setGeometry(QRect(510, 310, 91, 27));
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::Base, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        lineEdit_2->setPalette(palette1);
        lineEdit_2->setMouseTracking(true);
        lineEdit_2->setFocusPolicy(Qt::NoFocus);
        lineEdit_2->setAcceptDrops(true);
        lineEdit_2->setAlignment(Qt::AlignCenter);
        lineEdit_2->setReadOnly(true);
        battaries_Button = new QPushButton(SoundSignalDialog);
        battaries_Button->setObjectName(QStringLiteral("battaries_Button"));
        battaries_Button->setGeometry(QRect(510, 270, 93, 27));
        battaries_label = new QLabel(SoundSignalDialog);
        battaries_label->setObjectName(QStringLiteral("battaries_label"));
        battaries_label->setGeometry(QRect(490, 250, 59, 17));
        volume_label = new QLabel(SoundSignalDialog);
        volume_label->setObjectName(QStringLiteral("volume_label"));
        volume_label->setGeometry(QRect(40, 300, 59, 17));

        retranslateUi(SoundSignalDialog);

        QMetaObject::connectSlotsByName(SoundSignalDialog);
    } // setupUi

    void retranslateUi(QDialog *SoundSignalDialog)
    {
        SoundSignalDialog->setWindowTitle(QApplication::translate("SoundSignalDialog", "Dialog", Q_NULLPTR));
        apply_Button->setText(QApplication::translate("SoundSignalDialog", "Apply", Q_NULLPTR));
        test_Button->setText(QApplication::translate("SoundSignalDialog", "Test", Q_NULLPTR));
        cancel_Button->setText(QApplication::translate("SoundSignalDialog", "Cancel", Q_NULLPTR));
        label_frequency_measurement_unit->setText(QApplication::translate("SoundSignalDialog", "4700 Hz", Q_NULLPTR));
        label_period_measurement_unit->setText(QApplication::translate("SoundSignalDialog", "3 min", Q_NULLPTR));
        label_volume_measurement_unit->setText(QApplication::translate("SoundSignalDialog", "50 %", Q_NULLPTR));
        label_duration_measurement_unit->setText(QApplication::translate("SoundSignalDialog", "1 s", Q_NULLPTR));
        period_label->setText(QApplication::translate("SoundSignalDialog", "Period", Q_NULLPTR));
        frequency_label->setText(QApplication::translate("SoundSignalDialog", "Frequency", Q_NULLPTR));
        duration_label->setText(QApplication::translate("SoundSignalDialog", "Duration", Q_NULLPTR));
        lineEdit->setText(QApplication::translate("SoundSignalDialog", "On", Q_NULLPTR));
        alert_Button->setText(QApplication::translate("SoundSignalDialog", "ON/OFF", Q_NULLPTR));
        alert_label->setText(QApplication::translate("SoundSignalDialog", "Alert", Q_NULLPTR));
        lineEdit_2->setText(QApplication::translate("SoundSignalDialog", "On", Q_NULLPTR));
        battaries_Button->setText(QApplication::translate("SoundSignalDialog", "ON/OFF", Q_NULLPTR));
        battaries_label->setText(QApplication::translate("SoundSignalDialog", "Batteries", Q_NULLPTR));
        volume_label->setText(QApplication::translate("SoundSignalDialog", "Volume", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class SoundSignalDialog: public Ui_SoundSignalDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SOUNDSIGNAL_DIALOG_H
