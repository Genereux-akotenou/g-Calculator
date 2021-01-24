#ifndef MAINAPP_H
#define MAINAPP_H

#include <QMainWindow>
#include <QLabel>
#include <QPushButton>
#include <QVector>
#include "specialfloat.h"

class MainApp : public QMainWindow
{
    Q_OBJECT
    public:
        MainApp(QWidget *parent = nullptr);
    public slots:
        void appliquerButton(int nbr);

    private : signals:

    private:
        //variable de fonctionnalite de base
        void extractInput(QString signe);
        void setNewInput(QPushButton *btn);
        QLabel *champAffichage;//display result here and take input here too
        QLabel *suiteOperation;//display calc liste here at the top
        QPushButton *actionPlus;
        QPushButton *actionMoin;
        QPushButton *actionDivi;
        QPushButton *actionMult;
        QPushButton *actionEgal;
        QPushButton *actionDele;
        QPushButton *un;
        QPushButton *deux;
        QPushButton *trois;
        QPushButton *quatre;
        QPushButton *cinq;
        QPushButton *six;
        QPushButton *sept;
        QPushButton *huit;
        QPushButton *neuf;
        QPushButton *zero;
        QPushButton *point;
        QString ERROR = "ERREUR DE SYNTAXE !";
        QString RESULT = "0.00";
        bool isEqualPressed = false;
        bool wantToTestMyApp = false;
        QVector<SpecialFloat> cal = {};
        //QVector<float> cal = {};
        QVector<QString> ope;
        //variables calc_v2.0 fonctionnalite evoluee
        QPushButton *actionSQRT;
        QPushButton *actionEXPO;
        QPushButton *actionRecLN;
        QPushButton *actionLogar;
        QPushButton *actionLOG;
        QPushButton *actionSIN;
        QPushButton *actionCOS;
        QPushButton *actionTAN;
        bool isFunctionUsed = false;

};

#endif // MAINGEOAPPAPP_H
