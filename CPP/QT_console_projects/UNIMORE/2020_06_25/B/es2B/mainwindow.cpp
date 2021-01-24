#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(vai()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::vai()
{
    int a, b, piu, meno, per, div;

    switch (ui->comboBox->currentIndex()) {
        case 0:
            a = ui->aLineEdit->text().toFloat();
            b = ui->bLineEdit->text().toFloat();
            piu = a + b;
            ui->rLineEdit->setText(QString::number(piu));
            break;
        case 1:
            a = ui->aLineEdit->text().toFloat();
            b = ui->bLineEdit->text().toFloat();
            meno = a - b;
            ui->rLineEdit->setText(QString::number(meno));
            break;
        case 2:
            a = ui->aLineEdit->text().toFloat();
            b = ui->bLineEdit->text().toFloat();
            per = a * b;
            ui->rLineEdit->setText(QString::number(per));
            break;
        case 3:
            a = ui->aLineEdit->text().toFloat();
            b = ui->bLineEdit->text().toFloat();
            div = a / b;
            ui->rLineEdit->setText(QString::number(div));
            break;
        default:
            break;
    }
}

