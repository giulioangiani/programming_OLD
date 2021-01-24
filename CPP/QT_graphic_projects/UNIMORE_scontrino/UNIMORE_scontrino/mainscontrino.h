#ifndef MAINSCONTRINO_H
#define MAINSCONTRINO_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainScontrino; }
QT_END_NAMESPACE

class MainScontrino : public QMainWindow
{
    Q_OBJECT

public:
    MainScontrino(QWidget *parent = nullptr);
    ~MainScontrino();

private slots:
    void on_calcolaBtn_clicked();

    void on_edi1_textEdited(const QString &arg1);

    void on_calcolaBtn_1_clicked();

    void on_calcolaBtn_2_clicked();

    void on_calcolaBtn_3_clicked();

private:
    Ui::MainScontrino *ui;
};
#endif // MAINSCONTRINO_H
