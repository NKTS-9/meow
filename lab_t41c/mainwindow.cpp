#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>
#include <math.h>

double num_first;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->pushButton0,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton1,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton2,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton3,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton4,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton5,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton6,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton7,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton8,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton9,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_plusminus,SIGNAL(clicked()),this,SLOT(operations()));
    connect(ui->pushButton_pl,SIGNAL(clicked()),this,SLOT(math_operations()));
    connect(ui->pushButton_min,SIGNAL(clicked()),this,SLOT(math_operations()));
    connect(ui->pushButton_umn,SIGNAL(clicked()),this,SLOT(math_operations()));
    connect(ui->pushButton_del,SIGNAL(clicked()),this,SLOT(math_operations()));
    connect(ui->pushButtonxn,SIGNAL(clicked()),this,SLOT(math_operations()));

    ui->pushButton_pl->setCheckable(true);
    ui->pushButton_min->setCheckable(true);
    ui->pushButton_umn->setCheckable(true);
    ui->pushButton_del->setCheckable(true);
    ui->pushButtonxn->setCheckable(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    double a;
    a = ui->lineEdit_a->text().toDouble();
    double b;
    b = ui->lineEdit_b->text().toDouble();
    double s = a + b;
    QString sss;
    sss.setNum(s);
    ui->lineEdit_s->setText(sss);


}


void MainWindow::on_pushButtonm_clicked()
{
    double a;
    a = ui->lineEdit_a->text().toDouble();
    double b;
    b = ui->lineEdit_b->text().toDouble();
    double m = a - b;
    QString mmm;
    mmm.setNum(m);
    ui->lineEdit_s->setText(mmm);
}

void MainWindow::on_pushButtonu_clicked()
{
    double a;
    a = ui->lineEdit_a->text().toDouble();
    double b;
    b = ui->lineEdit_b->text().toDouble();
    double u = a * b;
    QString uuu;
    uuu.setNum(u);
    ui->lineEdit_s->setText(uuu);
}

void MainWindow::on_pushButtond_clicked()
{
    double a;
    a = ui->lineEdit_a->text().toDouble();
    double b;
    b = ui->lineEdit_b->text().toDouble();
    double d = a / b;
    QString ddd;
    ddd.setNum(d);
    ui->lineEdit_s->setText(ddd);
}

void MainWindow::digits_numbers()
{
    QPushButton *button = (QPushButton *)sender();

    double all_numbers;
    QString new_label;

    all_numbers = (ui->result->text() + button->text()).toDouble();
    new_label = QString::number(all_numbers, 'g', 15);

    ui->result->setText(new_label);
}

void MainWindow::on_pushButtondot_clicked()
{
    if(!(ui->result->text().contains('.')))
        ui->result->setText(ui->result->text() + ".");
}

void MainWindow::operations()
{
    QPushButton *button = (QPushButton *)sender();
    double all_numbers;
    QString new_label;

    if(button->text() == "+/-") {
    all_numbers = (ui->result->text()).toDouble();
    all_numbers = all_numbers * -1;
    new_label = QString::number(all_numbers, 'g', 15);

    ui->result->setText(new_label);
    }
}

void MainWindow::math_operations()
{
     QPushButton *button = (QPushButton *)sender();

     num_first = ui->result->text().toDouble();

     ui->result->setText("");

     button->setChecked(true);

}
void MainWindow::on_pushButton_6_clicked()
{
    double labelNumber, num_second;
    QString new_label;
    num_second = ui->result->text().toDouble();
    if(ui->pushButton_pl->isChecked()) {
        labelNumber = num_first + num_second;
        new_label = QString::number(labelNumber, 'g', 15);
        ui->result->setText(new_label);
        ui->pushButton_pl->setChecked(false);
    } else if(ui->pushButton_min->isChecked()) {
        labelNumber = num_first - num_second;
        new_label = QString::number(labelNumber, 'g', 15);
        ui->result->setText(new_label);
        ui->pushButton_min->setChecked(false);
    } else if(ui->pushButton_umn->isChecked()) {
        labelNumber = num_first * num_second;
        new_label = QString::number(labelNumber, 'g', 15);
        ui->result->setText(new_label);
        ui->pushButton_umn->setChecked(false);
    } else if(ui->pushButton_del->isChecked()) {
        if (num_second == 0) {
        ui->result->setText("error");
        } else {
        labelNumber = num_first / num_second;
        new_label = QString::number(labelNumber, 'g', 15);
        ui->result->setText(new_label);
        ui->pushButton_del->setChecked(false);
        }
    }
    else if(ui->pushButtonxn->isChecked()) {
            labelNumber = pow(num_first, num_second);
            new_label = QString::number(labelNumber, 'g', 15);
            ui->result->setText(new_label);
            ui->pushButtonxn->setChecked(false);
}
}


void MainWindow::on_pushButtontg_clicked()
{
    double all_numbers;
    QString res;
    all_numbers = (ui->result->text()).toDouble();
    res = QString::number(tan(all_numbers));
    ui->result->setText(res);
}

void MainWindow::on_pushButtonfac_clicked()
{
    double all_numbers;
    QString resu;
    all_numbers = (ui->result->text()).toDouble();
    int n = all_numbers;
    for  (int i = 1; i < n; i++) {
    all_numbers = all_numbers * i;
    }
    resu = QString::number(all_numbers, 'g', 15);
    ui->result->setText(resu);
}


void MainWindow::on_pushButtonDB_clicked()
{
    double all_numbers;
    QString rer;
    all_numbers = (ui->result->text()).toDouble();
    rer = QString::number(10 * (log10(all_numbers)));
    ui->result->setText(rer);
}

void MainWindow::on_pushButton_2_clicked()
{
    ui->pushButton_pl->setChecked(false);
     ui->pushButton_min->setChecked(false);
     ui->pushButton_umn->setChecked(false);
     ui->pushButton_del->setChecked(false);

    ui->result->setText("0");
}
