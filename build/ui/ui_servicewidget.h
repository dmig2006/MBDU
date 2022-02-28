/********************************************************************************
** Form generated from reading UI file 'servicewidget.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SERVICEWIDGET_H
#define UI_SERVICEWIDGET_H

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

class Ui_serviceWidget
{
public:
    QPushButton *exitButton;
    QPushButton *adjustmentButton;
    QPushButton *modeButton;
    QPushButton *soundButton;
    QFrame *line_2;
    QPushButton *applyBurstLength;
    QLabel *ammunitionValue;
    QLineEdit *ammunitionInput;
    QLabel *shortUnitLabel;
    QLabel *longUnitLabel;
    QLineEdit *shortBurstLengthInput;
    QLineEdit *longBurstLengthInput;
    QLabel *shortLabel;
    QLabel *longLabel;
    QPushButton *applyAmmunition;
    QFrame *line_3;
    QLabel *singleFireLabel;
    QLineEdit *singleShotTimeInput;
    QLabel *singleFireUnitLabel;
    QLabel *burstlengthTitleLabel;
    QLabel *ammunitionTitleLabel;
    QFrame *line_4;
    QFrame *line_5;
    QLabel *compressionTitle;
    QPushButton *h264Button;
    QLabel *compressionValueLabel;
    QPushButton *mjpegButton;
    QFrame *line;
    QFrame *line_6;
    QFrame *line_7;
    QLabel *formatVideoTitleLabel;

    void setupUi(QDialog *serviceWidget)
    {
        if (serviceWidget->objectName().isEmpty())
            serviceWidget->setObjectName(QStringLiteral("serviceWidget"));
        serviceWidget->resize(500, 630);
        exitButton = new QPushButton(serviceWidget);
        exitButton->setObjectName(QStringLiteral("exitButton"));
        exitButton->setGeometry(QRect(10, 570, 231, 51));
        QFont font;
        font.setPointSize(14);
        exitButton->setFont(font);
        exitButton->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"	background-color: #D4D4D4;\n"
"    color:#610404;\n"
"    border: 2px outset #a0a0a0;\n"
"    border-radius: 4px;\n"
"}\n"
"    QPushButton:pressed\n"
"{\n"
"	background-color: #D4D4D4;\n"
"    color:#610404;\n"
"    border: 2px inset #a0a0a0;\n"
"    border-radius: 4px;\n"
"}"));
        adjustmentButton = new QPushButton(serviceWidget);
        adjustmentButton->setObjectName(QStringLiteral("adjustmentButton"));
        adjustmentButton->setGeometry(QRect(260, 570, 231, 51));
        adjustmentButton->setFont(font);
        adjustmentButton->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"	background-color: #D4D4D4;\n"
"    color:#610404;\n"
"    border: 2px outset #a0a0a0;\n"
"    border-radius: 4px;\n"
"}\n"
"    QPushButton:pressed\n"
"{\n"
"	background-color: #D4D4D4;\n"
"    color:#610404;\n"
"    border: 2px inset #a0a0a0;\n"
"    border-radius: 4px;\n"
"}"));
        modeButton = new QPushButton(serviceWidget);
        modeButton->setObjectName(QStringLiteral("modeButton"));
        modeButton->setGeometry(QRect(10, 500, 231, 51));
        modeButton->setFont(font);
        modeButton->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"	background-color: #D4D4D4;\n"
"    color:#610404;\n"
"    border: 2px outset #a0a0a0;\n"
"    border-radius: 4px;\n"
"}\n"
"    QPushButton:pressed\n"
"{\n"
"	background-color: #D4D4D4;\n"
"    color:#610404;\n"
"    border: 2px inset #a0a0a0;\n"
"    border-radius: 4px;\n"
"}"));
        soundButton = new QPushButton(serviceWidget);
        soundButton->setObjectName(QStringLiteral("soundButton"));
        soundButton->setGeometry(QRect(258, 500, 231, 51));
        soundButton->setFont(font);
        soundButton->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"	background-color: #D4D4D4;\n"
"    color:#610404;\n"
"    border: 2px outset #a0a0a0;\n"
"    border-radius: 4px;\n"
"}\n"
"    QPushButton:pressed\n"
"{\n"
"	background-color: #D4D4D4;\n"
"    color:#610404;\n"
"    border: 2px inset #a0a0a0;\n"
"    border-radius: 4px;\n"
"}"));
        line_2 = new QFrame(serviceWidget);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setGeometry(QRect(10, 385, 481, 3));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);
        applyBurstLength = new QPushButton(serviceWidget);
        applyBurstLength->setObjectName(QStringLiteral("applyBurstLength"));
        applyBurstLength->setGeometry(QRect(386, 290, 101, 51));
        applyBurstLength->setFont(font);
        applyBurstLength->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"	background-color: #D4D4D4;\n"
"    color:#610404;\n"
"    border: 2px outset #a0a0a0;\n"
"    border-radius: 4px;\n"
"}\n"
"    QPushButton:pressed\n"
"{\n"
"	background-color: #D4D4D4;\n"
"    color:#610404;\n"
"    border: 2px inset #a0a0a0;\n"
"    border-radius: 4px;\n"
"}"));
        ammunitionValue = new QLabel(serviceWidget);
        ammunitionValue->setObjectName(QStringLiteral("ammunitionValue"));
        ammunitionValue->setGeometry(QRect(80, 80, 90, 20));
        QFont font1;
        font1.setPointSize(12);
        ammunitionValue->setFont(font1);
        ammunitionValue->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        ammunitionInput = new QLineEdit(serviceWidget);
        ammunitionInput->setObjectName(QStringLiteral("ammunitionInput"));
        ammunitionInput->setGeometry(QRect(10, 70, 61, 41));
        ammunitionInput->setFont(font1);
        ammunitionInput->setFocusPolicy(Qt::ClickFocus);
        ammunitionInput->setLayoutDirection(Qt::LeftToRight);
        ammunitionInput->setStyleSheet(QStringLiteral(""));
        shortUnitLabel = new QLabel(serviceWidget);
        shortUnitLabel->setObjectName(QStringLiteral("shortUnitLabel"));
        shortUnitLabel->setGeometry(QRect(290, 273, 91, 20));
        shortUnitLabel->setFont(font1);
        shortUnitLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        longUnitLabel = new QLabel(serviceWidget);
        longUnitLabel->setObjectName(QStringLiteral("longUnitLabel"));
        longUnitLabel->setGeometry(QRect(290, 335, 91, 20));
        longUnitLabel->setFont(font1);
        longUnitLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        shortBurstLengthInput = new QLineEdit(serviceWidget);
        shortBurstLengthInput->setObjectName(QStringLiteral("shortBurstLengthInput"));
        shortBurstLengthInput->setGeometry(QRect(220, 263, 61, 41));
        shortBurstLengthInput->setFont(font1);
        shortBurstLengthInput->setFocusPolicy(Qt::ClickFocus);
        shortBurstLengthInput->setLayoutDirection(Qt::LeftToRight);
        shortBurstLengthInput->setStyleSheet(QStringLiteral(""));
        longBurstLengthInput = new QLineEdit(serviceWidget);
        longBurstLengthInput->setObjectName(QStringLiteral("longBurstLengthInput"));
        longBurstLengthInput->setGeometry(QRect(220, 325, 61, 41));
        longBurstLengthInput->setFont(font1);
        longBurstLengthInput->setFocusPolicy(Qt::ClickFocus);
        longBurstLengthInput->setLayoutDirection(Qt::LeftToRight);
        longBurstLengthInput->setStyleSheet(QStringLiteral(""));
        shortLabel = new QLabel(serviceWidget);
        shortLabel->setObjectName(QStringLiteral("shortLabel"));
        shortLabel->setGeometry(QRect(4, 275, 211, 20));
        shortLabel->setFont(font1);
        shortLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        longLabel = new QLabel(serviceWidget);
        longLabel->setObjectName(QStringLiteral("longLabel"));
        longLabel->setGeometry(QRect(4, 335, 211, 20));
        longLabel->setFont(font1);
        applyAmmunition = new QPushButton(serviceWidget);
        applyAmmunition->setObjectName(QStringLiteral("applyAmmunition"));
        applyAmmunition->setGeometry(QRect(10, 120, 171, 51));
        applyAmmunition->setFont(font);
        applyAmmunition->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"	background-color: #D4D4D4;\n"
"    color:#610404;\n"
"    border: 2px outset #a0a0a0;\n"
"    border-radius: 4px;\n"
"}\n"
"    QPushButton:pressed\n"
"{\n"
"	background-color: #D4D4D4;\n"
"    color:#610404;\n"
"    border: 2px inset #a0a0a0;\n"
"    border-radius: 4px;\n"
"}"));
        line_3 = new QFrame(serviceWidget);
        line_3->setObjectName(QStringLiteral("line_3"));
        line_3->setGeometry(QRect(10, 250, 481, 3));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);
        singleFireLabel = new QLabel(serviceWidget);
        singleFireLabel->setObjectName(QStringLiteral("singleFireLabel"));
        singleFireLabel->setGeometry(QRect(4, 405, 211, 20));
        singleFireLabel->setFont(font1);
        singleShotTimeInput = new QLineEdit(serviceWidget);
        singleShotTimeInput->setObjectName(QStringLiteral("singleShotTimeInput"));
        singleShotTimeInput->setGeometry(QRect(220, 395, 61, 41));
        singleShotTimeInput->setFont(font1);
        singleShotTimeInput->setFocusPolicy(Qt::ClickFocus);
        singleShotTimeInput->setLayoutDirection(Qt::LeftToRight);
        singleShotTimeInput->setStyleSheet(QStringLiteral(""));
        singleFireUnitLabel = new QLabel(serviceWidget);
        singleFireUnitLabel->setObjectName(QStringLiteral("singleFireUnitLabel"));
        singleFireUnitLabel->setGeometry(QRect(290, 405, 91, 20));
        singleFireUnitLabel->setFont(font1);
        burstlengthTitleLabel = new QLabel(serviceWidget);
        burstlengthTitleLabel->setObjectName(QStringLiteral("burstlengthTitleLabel"));
        burstlengthTitleLabel->setGeometry(QRect(130, 220, 231, 20));
        burstlengthTitleLabel->setFont(font1);
        ammunitionTitleLabel = new QLabel(serviceWidget);
        ammunitionTitleLabel->setObjectName(QStringLiteral("ammunitionTitleLabel"));
        ammunitionTitleLabel->setGeometry(QRect(90, 20, 81, 20));
        ammunitionTitleLabel->setFont(font1);
        line_4 = new QFrame(serviceWidget);
        line_4->setObjectName(QStringLiteral("line_4"));
        line_4->setGeometry(QRect(10, 180, 220, 3));
        line_4->setFrameShape(QFrame::HLine);
        line_4->setFrameShadow(QFrame::Sunken);
        line_5 = new QFrame(serviceWidget);
        line_5->setObjectName(QStringLiteral("line_5"));
        line_5->setGeometry(QRect(10, 50, 220, 3));
        line_5->setFrameShape(QFrame::HLine);
        line_5->setFrameShadow(QFrame::Sunken);
        compressionTitle = new QLabel(serviceWidget);
        compressionTitle->setObjectName(QStringLiteral("compressionTitle"));
        compressionTitle->setGeometry(QRect(400, 90, 71, 20));
        compressionTitle->setFont(font1);
        compressionTitle->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        h264Button = new QPushButton(serviceWidget);
        h264Button->setObjectName(QStringLiteral("h264Button"));
        h264Button->setGeometry(QRect(280, 120, 91, 51));
        h264Button->setFont(font1);
        compressionValueLabel = new QLabel(serviceWidget);
        compressionValueLabel->setObjectName(QStringLiteral("compressionValueLabel"));
        compressionValueLabel->setGeometry(QRect(400, 130, 71, 20));
        compressionValueLabel->setFont(font1);
        compressionValueLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        mjpegButton = new QPushButton(serviceWidget);
        mjpegButton->setObjectName(QStringLiteral("mjpegButton"));
        mjpegButton->setGeometry(QRect(280, 60, 91, 51));
        mjpegButton->setFont(font1);
        line = new QFrame(serviceWidget);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(237, 50, 3, 131));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);
        line_6 = new QFrame(serviceWidget);
        line_6->setObjectName(QStringLiteral("line_6"));
        line_6->setGeometry(QRect(250, 180, 240, 3));
        line_6->setFrameShape(QFrame::HLine);
        line_6->setFrameShadow(QFrame::Sunken);
        line_7 = new QFrame(serviceWidget);
        line_7->setObjectName(QStringLiteral("line_7"));
        line_7->setGeometry(QRect(250, 50, 240, 3));
        line_7->setFrameShape(QFrame::HLine);
        line_7->setFrameShadow(QFrame::Sunken);
        formatVideoTitleLabel = new QLabel(serviceWidget);
        formatVideoTitleLabel->setObjectName(QStringLiteral("formatVideoTitleLabel"));
        formatVideoTitleLabel->setGeometry(QRect(320, 20, 151, 20));
        formatVideoTitleLabel->setFont(font1);

        retranslateUi(serviceWidget);

        QMetaObject::connectSlotsByName(serviceWidget);
    } // setupUi

    void retranslateUi(QDialog *serviceWidget)
    {
        serviceWidget->setWindowTitle(QApplication::translate("serviceWidget", "Dialog", Q_NULLPTR));
        exitButton->setText(QApplication::translate("serviceWidget", "\320\222\321\213\321\205\320\276\320\264", Q_NULLPTR));
        adjustmentButton->setText(QApplication::translate("serviceWidget", "\320\256\321\201\321\202\320\270\321\200\320\276\320\262\320\272\320\260", Q_NULLPTR));
        modeButton->setText(QApplication::translate("serviceWidget", "\320\240\320\260\320\261\320\276\321\207\320\270\320\271 \321\200\320\265\320\266\320\270\320\274", Q_NULLPTR));
        soundButton->setText(QApplication::translate("serviceWidget", "\320\236\320\277\320\276\320\262\320\265\321\211\320\265\320\275\320\270\320\265", Q_NULLPTR));
        applyBurstLength->setText(QApplication::translate("serviceWidget", "\320\237\321\200\320\270\320\275\321\217\321\202\321\214", Q_NULLPTR));
        ammunitionValue->setText(QApplication::translate("serviceWidget", "\320\237\320\260\321\202\321\200\320\276\320\275\320\276\320\262", Q_NULLPTR));
        ammunitionInput->setText(QString());
        shortUnitLabel->setText(QApplication::translate("serviceWidget", "\320\222\321\213\321\201\321\202\321\200\320\265\320\273\320\276\320\262", Q_NULLPTR));
        longUnitLabel->setText(QApplication::translate("serviceWidget", "\320\222\321\213\321\201\321\202\321\200\320\265\320\273\320\276\320\262", Q_NULLPTR));
        shortBurstLengthInput->setText(QString());
        longBurstLengthInput->setText(QString());
        shortLabel->setText(QApplication::translate("serviceWidget", "\320\224\320\273\320\270\320\275\320\260 \320\272\320\276\321\200\320\276\321\202\320\272\320\276\320\271 \320\276\321\207\320\265\321\200\320\265\320\264\320\270", Q_NULLPTR));
        longLabel->setText(QApplication::translate("serviceWidget", "\320\224\320\273\320\270\320\275\320\260 \320\264\320\273\320\270\320\275\320\276\320\271 \320\276\321\207\320\265\321\200\320\265\320\264\320\270", Q_NULLPTR));
        applyAmmunition->setText(QApplication::translate("serviceWidget", "\320\237\321\200\320\270\320\275\321\217\321\202\321\214", Q_NULLPTR));
        singleFireLabel->setText(QApplication::translate("serviceWidget", "\320\224\320\273\320\270\321\202\320\265\320\273\321\214\320\275\320\276\321\201\321\202\321\214 \320\262\321\213\321\201\321\202\321\200\320\265\320\273\320\260", Q_NULLPTR));
        singleShotTimeInput->setText(QString());
        singleFireUnitLabel->setText(QApplication::translate("serviceWidget", "\320\274\321\201", Q_NULLPTR));
        burstlengthTitleLabel->setText(QApplication::translate("serviceWidget", "\320\243\321\201\321\202\320\260\320\275\320\276\320\262\320\272\320\260 \320\264\320\273\320\270\320\275\321\213 \320\276\321\207\320\265\321\200\320\265\320\264\320\270", Q_NULLPTR));
        ammunitionTitleLabel->setText(QApplication::translate("serviceWidget", "\320\221\320\276\320\265\320\267\320\260\320\277\320\260\321\201", Q_NULLPTR));
        compressionTitle->setText(QApplication::translate("serviceWidget", "\320\241\320\266\320\260\321\202\320\270\320\265", Q_NULLPTR));
        h264Button->setText(QApplication::translate("serviceWidget", "H264", Q_NULLPTR));
        compressionValueLabel->setText(QApplication::translate("serviceWidget", "20%", Q_NULLPTR));
        mjpegButton->setText(QApplication::translate("serviceWidget", "MJPEG", Q_NULLPTR));
        formatVideoTitleLabel->setText(QApplication::translate("serviceWidget", "\320\244\320\276\321\200\320\274\320\260\321\202 \320\262\320\270\320\264\320\265\320\276", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class serviceWidget: public Ui_serviceWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SERVICEWIDGET_H
