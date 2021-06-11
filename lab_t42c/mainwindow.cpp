#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    m_db = QSqlDatabase::addDatabase("QSQLITE"); //соединение объекта базы данных
                                    // с СУБД
    m_db.setDatabaseName("myDB2");  //определение имени базы данных
    query = new QSqlQuery(m_db); // создание объекта для запроса
    if(!m_db.open()) // проверка на ошибку при открытии или создании базы данных
        throw "can't open database";
    if(!m_db.tables().contains("Person")) // если в базе не существует таблица  Person,
    { //то создание таблицы  Person и заполнение данными
        query->clear(); // очистка запроса
  query->exec("CREATE TABLE Person(ID INTEGER PRIMARY KEY, Name VARCHAR, Year INTEGER, Genre VARCHAR, Length INTEGER);");  // исполнение запроса на добавление записи
        query->clear();
        query->exec("INSERT INTO Person (ID,Name,Year,Genre,Length) VALUES (1,'Interstellar', 2016, 'sci-fi', 135);");
        query->clear();
        query->exec("INSERT INTO Person (ID,Name,Year,Genre,Length) VALUES (2,'Truman Show', 1998, 'comedy', 100);");
    }
    model = new QSqlTableModel(this,m_db); // создание
                              // редактируемой модели базы данных
    model->setTable("Person"); // создание модели таблицы  Person

    model->select(); // заполнение модели данными
    model->setEditStrategy(QSqlTableModel::OnFieldChange); // выбор стратегии
                    //  сохранения изменений в базе данных
                    //- сохранение происходит при переходе к другому полю
    ui->tableView->setModel(model); // соединение модели
                    // и ее табличного представления в форме
}

MainWindow::~MainWindow()
{
    delete ui;
    delete query;
    delete model;
}

void MainWindow::on_pushButtonadd_clicked()
{
    if(ui->lineEditid->text().isEmpty()||ui->lineEditname->text().isEmpty()||ui->lineEdityear->text().isEmpty()||ui->lineEditgenre->text().isEmpty()||ui->lineEditlength->text().isEmpty())
        return;
    QString id = ui->lineEditid->text();
    QString name = ui->lineEditname->text();
    QString year = ui->lineEdityear->text();
    QString genre = ui->lineEditgenre->text();
    QString length = ui->lineEditlength->text();
    QString buf = tr("INSERT INTO Person (Id,Name,Year,Genre,Length) VALUES (")+id+tr(",'")+name+tr("',")+year+tr(",'")+genre+tr("',")+length+tr(");");
    query->clear();
    query->exec(buf);
    model->select();

}


void MainWindow::on_pushButton_clicked()
{
    model->setFilter("");
    model->select();
    ui->tableView->setModel(model);

}


void MainWindow::on_pushButtonrem_clicked()
{
    QString id = ui->lineEditid2->text();
    QString name = ui->lineEditid2->text();
    QString year = ui->lineEditid2->text();
    QString genre = ui->lineEditid2->text();
    QString length = ui->lineEditid2->text();
    QString buf = tr("DELETE FROM Person WHERE id=")+id+tr(";");
    query->clear();
    query->exec(buf);
    model->select();
}

void MainWindow::on_pushButton_3_clicked()
{
    model->setFilter("Length>100");
    model->select();
    ui->tableView->setModel(model);
}

void MainWindow::on_pushButton_2_clicked()
{
    model->setFilter("Length<100");
    model->select();
    ui->tableView->setModel(model);
}


void MainWindow::on_pushButtonYear_clicked()
{
    if(ui->checkBox->isChecked())
    {
        model->setFilter("Year<2000");
        model->select();
        ui->tableView->setModel(model);
    }

    else
    {
        model->setFilter("");
        model->select();
        ui->tableView->setModel(model);
    }
}
