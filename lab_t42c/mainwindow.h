#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSql>

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();
    void on_pushButtonadd_clicked();
    void on_pushButtonrem_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

    void on_checkBox_stateChanged(int arg1);

    void on_checkBox_clicked();

    void on_checkBox_released();

    void on_checkBox_pressed();

    void on_pushButtonYear_clicked();

private:
    Ui::MainWindow *ui;
    QSqlDatabase m_db;
    QSqlQuery* query;
    QSqlTableModel* model;
};

#endif // MAINWINDOW_H
