/********************************************************************************
** Form generated from reading UI file 'virtual_keyboard.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VIRTUAL_KEYBOARD_H
#define UI_VIRTUAL_KEYBOARD_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_VirtualKeyboard
{
public:
    QPushButton *key_1;
    QPushButton *key_5;
    QPushButton *key_9;
    QPushButton *key_left;
    QPushButton *key_enter;
    QPushButton *key_2;
    QPushButton *key_3;
    QPushButton *key_4;
    QPushButton *key_6;
    QPushButton *key_8;
    QPushButton *key_7;
    QPushButton *key_backspace;
    QPushButton *key_up;
    QPushButton *key_plus;
    QPushButton *key_reside;
    QPushButton *key_0;
    QPushButton *key_down;
    QPushButton *key_minus;
    QPushButton *key_esc;
    QPushButton *key_right;

    void setupUi(QDialog *VirtualKeyboard)
    {
        if (VirtualKeyboard->objectName().isEmpty())
            VirtualKeyboard->setObjectName(QStringLiteral("VirtualKeyboard"));
        VirtualKeyboard->resize(518, 400);
        key_1 = new QPushButton(VirtualKeyboard);
        key_1->setObjectName(QStringLiteral("key_1"));
        key_1->setGeometry(QRect(11, 11, 71, 81));
        QFont font;
        font.setPointSize(14);
        key_1->setFont(font);
        key_1->setStyleSheet(QLatin1String("QPushButton\n"
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
        key_5 = new QPushButton(VirtualKeyboard);
        key_5->setObjectName(QStringLiteral("key_5"));
        key_5->setGeometry(QRect(12, 110, 71, 81));
        key_5->setFont(font);
        key_5->setStyleSheet(QLatin1String("QPushButton\n"
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
        key_9 = new QPushButton(VirtualKeyboard);
        key_9->setObjectName(QStringLiteral("key_9"));
        key_9->setGeometry(QRect(12, 207, 71, 81));
        key_9->setFont(font);
        key_9->setStyleSheet(QLatin1String("QPushButton\n"
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
        key_left = new QPushButton(VirtualKeyboard);
        key_left->setObjectName(QStringLiteral("key_left"));
        key_left->setGeometry(QRect(12, 307, 71, 81));
        QFont font1;
        font1.setPointSize(22);
        key_left->setFont(font1);
        key_left->setStyleSheet(QLatin1String("QPushButton\n"
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
        key_enter = new QPushButton(VirtualKeyboard);
        key_enter->setObjectName(QStringLiteral("key_enter"));
        key_enter->setGeometry(QRect(374, 15, 131, 81));
        key_enter->setFont(font);
        key_enter->setStyleSheet(QLatin1String("QPushButton\n"
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
        key_2 = new QPushButton(VirtualKeyboard);
        key_2->setObjectName(QStringLiteral("key_2"));
        key_2->setGeometry(QRect(100, 12, 71, 81));
        key_2->setFont(font);
        key_2->setStyleSheet(QLatin1String("QPushButton\n"
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
        key_3 = new QPushButton(VirtualKeyboard);
        key_3->setObjectName(QStringLiteral("key_3"));
        key_3->setGeometry(QRect(192, 13, 71, 81));
        key_3->setFont(font);
        key_3->setStyleSheet(QLatin1String("QPushButton\n"
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
        key_4 = new QPushButton(VirtualKeyboard);
        key_4->setObjectName(QStringLiteral("key_4"));
        key_4->setGeometry(QRect(282, 14, 71, 81));
        key_4->setFont(font);
        key_4->setStyleSheet(QLatin1String("QPushButton\n"
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
        key_6 = new QPushButton(VirtualKeyboard);
        key_6->setObjectName(QStringLiteral("key_6"));
        key_6->setGeometry(QRect(103, 110, 71, 81));
        key_6->setFont(font);
        key_6->setStyleSheet(QLatin1String("QPushButton\n"
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
        key_8 = new QPushButton(VirtualKeyboard);
        key_8->setObjectName(QStringLiteral("key_8"));
        key_8->setGeometry(QRect(285, 111, 71, 81));
        key_8->setFont(font);
        key_8->setStyleSheet(QLatin1String("QPushButton\n"
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
        key_7 = new QPushButton(VirtualKeyboard);
        key_7->setObjectName(QStringLiteral("key_7"));
        key_7->setGeometry(QRect(195, 111, 71, 81));
        key_7->setFont(font);
        key_7->setStyleSheet(QLatin1String("QPushButton\n"
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
        key_backspace = new QPushButton(VirtualKeyboard);
        key_backspace->setObjectName(QStringLiteral("key_backspace"));
        key_backspace->setGeometry(QRect(377, 111, 131, 81));
        key_backspace->setFont(font);
        key_backspace->setStyleSheet(QLatin1String("QPushButton\n"
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
        key_up = new QPushButton(VirtualKeyboard);
        key_up->setObjectName(QStringLiteral("key_up"));
        key_up->setGeometry(QRect(103, 208, 71, 81));
        key_up->setFont(font1);
        key_up->setStyleSheet(QLatin1String("QPushButton\n"
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
        key_plus = new QPushButton(VirtualKeyboard);
        key_plus->setObjectName(QStringLiteral("key_plus"));
        key_plus->setGeometry(QRect(285, 209, 71, 81));
        key_plus->setFont(font1);
        key_plus->setStyleSheet(QLatin1String("QPushButton\n"
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
        key_reside = new QPushButton(VirtualKeyboard);
        key_reside->setObjectName(QStringLiteral("key_reside"));
        key_reside->setGeometry(QRect(377, 209, 131, 81));
        key_reside->setFont(font1);
        key_reside->setStyleSheet(QLatin1String("QPushButton\n"
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
        key_0 = new QPushButton(VirtualKeyboard);
        key_0->setObjectName(QStringLiteral("key_0"));
        key_0->setGeometry(QRect(195, 209, 71, 81));
        key_0->setFont(font);
        key_0->setStyleSheet(QLatin1String("QPushButton\n"
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
        key_down = new QPushButton(VirtualKeyboard);
        key_down->setObjectName(QStringLiteral("key_down"));
        key_down->setGeometry(QRect(103, 308, 71, 81));
        key_down->setFont(font1);
        key_down->setStyleSheet(QLatin1String("QPushButton\n"
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
        key_minus = new QPushButton(VirtualKeyboard);
        key_minus->setObjectName(QStringLiteral("key_minus"));
        key_minus->setGeometry(QRect(285, 309, 71, 81));
        key_minus->setFont(font1);
        key_minus->setStyleSheet(QLatin1String("QPushButton\n"
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
        key_esc = new QPushButton(VirtualKeyboard);
        key_esc->setObjectName(QStringLiteral("key_esc"));
        key_esc->setGeometry(QRect(377, 309, 131, 81));
        key_esc->setFont(font);
        key_esc->setStyleSheet(QLatin1String("QPushButton\n"
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
        key_right = new QPushButton(VirtualKeyboard);
        key_right->setObjectName(QStringLiteral("key_right"));
        key_right->setGeometry(QRect(195, 309, 71, 81));
        key_right->setFont(font1);
        key_right->setStyleSheet(QLatin1String("QPushButton\n"
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

        retranslateUi(VirtualKeyboard);

        QMetaObject::connectSlotsByName(VirtualKeyboard);
    } // setupUi

    void retranslateUi(QDialog *VirtualKeyboard)
    {
        VirtualKeyboard->setWindowTitle(QApplication::translate("VirtualKeyboard", "Dialog", Q_NULLPTR));
        key_1->setText(QApplication::translate("VirtualKeyboard", "1", Q_NULLPTR));
        key_5->setText(QApplication::translate("VirtualKeyboard", "5", Q_NULLPTR));
        key_9->setText(QApplication::translate("VirtualKeyboard", "9", Q_NULLPTR));
        key_left->setText(QApplication::translate("VirtualKeyboard", "\342\206\220", Q_NULLPTR));
        key_enter->setText(QApplication::translate("VirtualKeyboard", "ENTER", Q_NULLPTR));
        key_2->setText(QApplication::translate("VirtualKeyboard", "2", Q_NULLPTR));
        key_3->setText(QApplication::translate("VirtualKeyboard", "3", Q_NULLPTR));
        key_4->setText(QApplication::translate("VirtualKeyboard", "4", Q_NULLPTR));
        key_6->setText(QApplication::translate("VirtualKeyboard", "6", Q_NULLPTR));
        key_8->setText(QApplication::translate("VirtualKeyboard", "8", Q_NULLPTR));
        key_7->setText(QApplication::translate("VirtualKeyboard", "7", Q_NULLPTR));
        key_backspace->setText(QApplication::translate("VirtualKeyboard", "BACKSPACE", Q_NULLPTR));
        key_up->setText(QApplication::translate("VirtualKeyboard", "\342\206\221", Q_NULLPTR));
        key_plus->setText(QApplication::translate("VirtualKeyboard", "+", Q_NULLPTR));
        key_reside->setText(QApplication::translate("VirtualKeyboard", ".", Q_NULLPTR));
        key_0->setText(QApplication::translate("VirtualKeyboard", "0", Q_NULLPTR));
        key_down->setText(QApplication::translate("VirtualKeyboard", "\342\206\223", Q_NULLPTR));
        key_minus->setText(QApplication::translate("VirtualKeyboard", "-", Q_NULLPTR));
        key_esc->setText(QApplication::translate("VirtualKeyboard", "ESC", Q_NULLPTR));
        key_right->setText(QApplication::translate("VirtualKeyboard", "\342\206\222", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class VirtualKeyboard: public Ui_VirtualKeyboard {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VIRTUAL_KEYBOARD_H
