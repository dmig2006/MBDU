/********************************************************************************
** Form generated from reading UI file 'optwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OPTWIDGET_H
#define UI_OPTWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_OptWidget
{
public:
    QLabel *label;

    void setupUi(QWidget *OptWidget)
    {
        if (OptWidget->objectName().isEmpty())
            OptWidget->setObjectName(QStringLiteral("OptWidget"));
        OptWidget->resize(400, 300);
        OptWidget->setCursor(QCursor(Qt::CrossCursor));
        label = new QLabel(OptWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 10, 140, 20));

        retranslateUi(OptWidget);

        QMetaObject::connectSlotsByName(OptWidget);
    } // setupUi

    void retranslateUi(QWidget *OptWidget)
    {
        OptWidget->setWindowTitle(QApplication::translate("OptWidget", "Form", Q_NULLPTR));
        label->setText(QApplication::translate("OptWidget", "Target type: HUMAN", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class OptWidget: public Ui_OptWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OPTWIDGET_H
