/***************************************************************************
*                                                                          *
*                mainwindow.cpp for 03_databases                           *
*                Created on  : Mon Apr 03 2017 11:34                       *
*                Made by : Qt training <training@qt.io>                    *
*                                                                          *
***************************************************************************/

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QStandardItemModel>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    m_model(new QStandardItemModel(this))
{
    ui->setupUi(this);
    ui->tableView->setModel(m_model);
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    m_database = QSqlDatabase::addDatabase("QSQLITE");
    m_database.setDatabaseName("employees.db");
    if (!m_database.open())
        qDebug() << m_database.open() << m_database.lastError().databaseText();

    if (!m_database.tables().contains("Employees")) {
        QSqlQuery query("CREATE TABLE Employees (Employee varchar(255), Address varchar(255), Salary varchar(255))");
        query.exec();
    }
    else {
        QSqlQuery query("SELECT * FROM Employees");
        query.exec();
        QSqlRecord record;
        while (query.next()) {
            record = query.record();
            QList<QStandardItem *> items;
            items << new QStandardItem(record.value("Employee").toString()) << new QStandardItem(record.value("Address").toString()) << new QStandardItem(record.value("Salary").toString());
            m_model->appendRow(items);
        }
    }
}

MainWindow::~MainWindow()
{
    m_database.close();

    QList <QStandardItem *> row;
    for (int i = 0; i < m_model->rowCount(); ++i) {
        row = m_model->takeRow(i);
        for (QStandardItem *item : row) {
            delete item;
        }
    }
    delete ui;
}

void MainWindow::on_pushButton_pressed()
{
    QList<QStandardItem *> items;
    items << new QStandardItem(ui->lineEdit->text()) << new QStandardItem(ui->lineEdit_2->text()) << new QStandardItem(ui->lineEdit_3->text());
    m_model->appendRow(items);
    QSqlQuery query;
    query.prepare("INSERT INTO Employees (Employee, Address, Salary) VALUES (:employee, :address, :salary)");
    query.bindValue(":employee", ui->lineEdit->text());
    query.bindValue(":address", ui->lineEdit_2->text());
    query.bindValue(":salary", ui->lineEdit_3->text());
    query.exec();
}
