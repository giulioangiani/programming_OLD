#include "mainwindow.h"
#include "ui_mainwindow.h"

using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(conta()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::conta()
{
    string a = ui->aLineEdit->text().toStdString();
    string b = ui->bLineEdit->text().toStdString();
    int c = 0;

    char acstr[a.size() + 1];
    strcpy(acstr, a.c_str());

    char bcstr[b.size() + 1];
    strcpy(bcstr, b.c_str());

    for (int i = 0; i <= (int)a.size(); i++){
        if (acstr[i] == bcstr[0])
            c++;
    }

    ui->cLineEdit->setText(QString::number(c));
}
