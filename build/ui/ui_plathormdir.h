/********************************************************************************
** Form generated from reading UI file 'plathormdir.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PLATHORMDIR_H
#define UI_PLATHORMDIR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PlathormDir
{
public:

    void setupUi(QWidget *PlathormDir)
    {
        if (PlathormDir->objectName().isEmpty())
            PlathormDir->setObjectName(QStringLiteral("PlathormDir"));
        PlathormDir->resize(130, 110);

        retranslateUi(PlathormDir);

        QMetaObject::connectSlotsByName(PlathormDir);
    } // setupUi

    void retranslateUi(QWidget *PlathormDir)
    {
        PlathormDir->setWindowTitle(QApplication::translate("PlathormDir", "Form", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class PlathormDir: public Ui_PlathormDir {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PLATHORMDIR_H
