#ifndef CHEFSERVICE_H
#define CHEFSERVICE_H
#include <QString>
#include <QSqlQueryModel>


class Chefservice
{
    int id;
    QString nom,prenom;


public:
    Chefservice();
    Chefservice(int,QString,QString);
    int getId(){return id;}
    QString getNom(){return nom;}
    QString getPrenom(){return prenom;}
    bool ajouterChefSv();
    bool supprimerChefSv(int);
    bool modifierChefSv(int);
    QSqlQueryModel * afficher();
    QSqlQueryModel * rechercheChefSv(int);


};

#endif // CHEFSERVICE_H
