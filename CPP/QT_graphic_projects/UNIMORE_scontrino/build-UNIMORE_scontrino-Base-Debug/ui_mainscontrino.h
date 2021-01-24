/********************************************************************************
** Form generated from reading UI file 'mainscontrino.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINSCONTRINO_H
#define UI_MAINSCONTRINO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainScontrino
{
public:
    QWidget *centralwidget;
    QPushButton *calcolaBtn_1;
    QLineEdit *numero;
    QLabel *label;
    QPushButton *calcolaBtn_2;
    QPushButton *calcolaBtn_3;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainScontrino)
    {
        if (MainScontrino->objectName().isEmpty())
            MainScontrino->setObjectName(QString::fromUtf8("MainScontrino"));
        MainScontrino->resize(564, 333);
        centralwidget = new QWidget(MainScontrino);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        calcolaBtn_1 = new QPushButton(centralwidget);
        calcolaBtn_1->setObjectName(QString::fromUtf8("calcolaBtn_1"));
        calcolaBtn_1->setGeometry(QRect(70, 240, 89, 25));
        numero = new QLineEdit(centralwidget);
        numero->setObjectName(QString::fromUtf8("numero"));
        numero->setGeometry(QRect(270, 30, 113, 25));
        numero->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(180, 30, 67, 17));
        calcolaBtn_2 = new QPushButton(centralwidget);
        calcolaBtn_2->setObjectName(QString::fromUtf8("calcolaBtn_2"));
        calcolaBtn_2->setGeometry(QRect(250, 240, 89, 25));
        calcolaBtn_3 = new QPushButton(centralwidget);
        calcolaBtn_3->setObjectName(QString::fromUtf8("calcolaBtn_3"));
        calcolaBtn_3->setGeometry(QRect(430, 240, 89, 25));
        MainScontrino->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainScontrino);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 564, 22));
        MainScontrino->setMenuBar(menubar);
        statusbar = new QStatusBar(MainScontrino);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainScontrino->setStatusBar(statusbar);

        retranslateUi(MainScontrino);

        QMetaObject::connectSlotsByName(MainScontrino);
    } // setupUi

    void retranslateUi(QMainWindow *MainScontrino)
    {
        MainScontrino->setWindowTitle(QApplication::translate("MainScontrino", "MainScontrino", nullptr));
        calcolaBtn_1->setText(QApplication::translate("MainScontrino", "Quadrato", nullptr));
        numero->setText(QApplication::translate("MainScontrino", "0", nullptr));
        label->setText(QApplication::translate("MainScontrino", "Numero", nullptr));
        calcolaBtn_2->setText(QApplication::translate("MainScontrino", "Dimezza", nullptr));
        calcolaBtn_3->setText(QApplication::translate("MainScontrino", "Incrementa", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainScontrino: public Ui_MainScontrino {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINSCONTRINO_H
