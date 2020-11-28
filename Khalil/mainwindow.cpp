#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "modifwidget.h"
#include "addwidget.h"
#include "chefservice.h"
#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlQueryModel>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableView->setModel(chefservicetmp.afficher());

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_13_clicked()//ajout
{
    int id=ui->lineEdit_ID->text().toInt();
    QString nom=ui->lineEdit_Nom->text();
    QString prenom=ui->lineEdit_Prenom->text();/*
    Chefservice c(id,nom,prenom);
    bool test=c.ajouterChefSv();
    if(test)
    {
        ui->tableView->setModel(chefservicetmp.afficher());
    QMessageBox::information(nullptr,QObject::tr("chefservice ajoute"),QObject::tr("connection successful\n""click cancel"),QMessageBox::Cancel);
    }
    else
    {
    QMessageBox::information(nullptr,QObject::tr("database error"),QObject::tr("connection unsuccessful\n""click cancel"),QMessageBox::Cancel);
    }*/
    Chefservice c(id,nom,prenom);
    bool test = c.modifierChefSv(748);
    if(test)
    {
        ui->tableView->setModel(chefservicetmp.afficher());
    QMessageBox::information(nullptr,QObject::tr("chefservice ajoute"),QObject::tr("connection successful\n""click cancel"),QMessageBox::Cancel);
    }
    else
    {
    QMessageBox::information(nullptr,QObject::tr("database error"),QObject::tr("connection unsuccessful\n""click cancel"),QMessageBox::Cancel);
    }

}


void MainWindow::on_pushButton_clicked()//supression
{
int id = ui->lineEdit->text().toInt();
bool test=chefservicetmp.supprimerChefSv(id);
if (test)
{
    QMessageBox::information(nullptr,QObject::tr("OK"),
                             QObject::tr("suppression effectuee\n"
                                         "click cancel to exite"),QMessageBox::Cancel);
}
else {
    QMessageBox::critical(nullptr,QObject::tr("not ok"),
            QObject::tr("suppression non effectuee\n"
                        "click cancel to exit"),QMessageBox::Cancel);
}
    ui->tableView->setModel(chefservicetmp.afficher());
}

void MainWindow::on_pushButton_3_clicked()//recherche
{
    int id = ui->lineEdit->text().toInt();
    ui->tableView->setModel(chefservicetmp.rechercheChefSv(id));
}

void MainWindow::on_tableView_doubleClicked(const QModelIndex &index)
{
QString ress=QVariant(index.data()).toString();
ui->lineEdit->clear();
ui->tabWidget->setCurrentIndex(2);

}

void MainWindow::on_pushButton_4_clicked()
{
    AddWidget addw;
    addw.setModal(true);
    addw.exec();
}

void MainWindow::on_pushButton_2_clicked()//widget modifier
{
    ModifWidget modw;
    modw.setModal(true);
    modw.exec();
}
