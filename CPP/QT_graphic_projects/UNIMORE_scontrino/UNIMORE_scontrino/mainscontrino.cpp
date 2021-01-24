#include <iostream>
#include <QMessageBox>
#include "mainscontrino.h"
#include "ui_mainscontrino.h"

MainScontrino::MainScontrino(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainScontrino)
{
    ui->setupUi(this);
}

MainScontrino::~MainScontrino()
{
    delete ui;
}

void MainScontrino::on_calcolaBtn_1_clicked()
{
   int n = ui->numero->text().toInt();
   n = n*n;
   ui->numero->setText(QString::number(n));
}

void MainScontrino::on_calcolaBtn_2_clicked()
{
  int n = ui->numero->text().toInt();
  n = n/2;
  ui->numero->setText(QString::number(n));
}

void MainScontrino::on_calcolaBtn_3_clicked()
{
  int n = ui->numero->text().toInt();
  n = n+1;
  ui->numero->setText(QString::number(n));
}
