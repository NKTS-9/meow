#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
private:
    Ui::MainWindow *ui;
    
private slots:
    void on_pushButton_clicked();

    void on_pushButtonm_clicked();

    void on_pushButtonu_clicked();

    void on_pushButtond_clicked();

    void digits_numbers();

    void operations();

    void on_pushButtondot_clicked();

    void math_operations();
    void on_pushButton_6_clicked();

    void on_pushButtontg_clicked();
    void on_pushButtonfac_clicked();

    void on_pushButtonDB_clicked();
    void on_pushButton_2_clicked();
};

#endif // MAINWINDOW_H
