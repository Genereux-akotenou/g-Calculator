#include "mainapp.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QGroupBox>
#include <QApplication>
#include <QSignalMapper>
#include <QChar>
#include <QIcon>
#include "specialfloat.h"
#include <cmath>

MainApp::MainApp(QWidget *parent) : QMainWindow(parent)
{
    setFixedSize(360, 238);
    setWindowIcon(QIcon(QCoreApplication::applicationDirPath() + "/assets/icon.png"));
    QWidget *central = new QWidget;
    setCentralWidget(central);
    champAffichage = new QLabel;
    suiteOperation = new QLabel;
    //champAffichage->setStyleSheet("QLabel {background: whitesmoke;}");
    //suiteOperation->setStyleSheet("QLabel {background: whitesmoke;}");
    suiteOperation->setMaximumHeight(10);
    suiteOperation->setFont(QFont("Sans Comic MS",9,25,false));
    actionDele = new QPushButton;//("DEL")
    actionDele->setIcon(QIcon(QCoreApplication::applicationDirPath() + "/assets/del1.png"));
    actionDele->setFixedHeight(35);
    QGridLayout *layout0 = new QGridLayout;
    QVBoxLayout *layout1 = new QVBoxLayout;
    layout1->addWidget(suiteOperation);
    layout1->addWidget(champAffichage);

    QHBoxLayout *layout2 = new QHBoxLayout;
    QHBoxLayout *layout3 = new QHBoxLayout;
    QHBoxLayout *layout4 = new QHBoxLayout;
    QHBoxLayout *layout5 = new QHBoxLayout;
    QVBoxLayout *layout6 = new QVBoxLayout;
    QHBoxLayout *layout7 = new QHBoxLayout;
    QHBoxLayout *layout8 = new QHBoxLayout;

    //********************fonctionnalite avancées**********************//
    actionSQRT = new QPushButton("√");
    actionEXPO = new QPushButton("x²");
    actionRecLN = new QPushButton("e²");
    actionLogar = new QPushButton("ln");
    layout7->addWidget(actionSQRT);
    layout7->addWidget(actionEXPO);
    layout7->addWidget(actionRecLN);
    actionLOG = new QPushButton("log");
    actionSIN = new QPushButton("sin");
    actionCOS = new QPushButton("cos");
    actionTAN = new QPushButton("tan");
    layout8->addWidget(actionLOG);
    layout8->addWidget(actionSIN);
    layout8->addWidget(actionCOS);
    //*****************************************************************//

    un = new QPushButton("1");
    un->setShortcut(tr("1"));
    deux = new QPushButton("2");
    trois = new QPushButton("3");
    layout2->addWidget(un);
    layout2->addWidget(deux);
    layout2->addWidget(trois);
    quatre = new QPushButton("4");
    cinq = new QPushButton("5");
    six = new QPushButton("6");
    layout3->addWidget(quatre);
    layout3->addWidget(cinq);
    layout3->addWidget(six);
    sept = new QPushButton("7");
    huit = new QPushButton("8");
    neuf = new QPushButton("9");
    layout4->addWidget(sept);
    layout4->addWidget(huit);
    layout4->addWidget(neuf);
    zero = new QPushButton("0");
    actionEgal = new QPushButton("=");
    point = new QPushButton(".");
    layout5->addWidget(zero);
    layout5->addWidget(point);
    layout5->addWidget(actionEgal);
    actionPlus = new QPushButton("+");
    actionMoin = new QPushButton("-");
    actionDivi = new QPushButton("/");
    actionMult = new QPushButton("X");
    layout6->addWidget(actionDele);
    layout6->addWidget(actionLogar);
    layout6->addWidget(actionTAN);
    layout6->addWidget(actionPlus);
    layout6->addWidget(actionMoin);
    layout6->addWidget(actionDivi);
    layout6->addWidget(actionMult);

    central->setLayout(layout0);
    layout0->addLayout(layout1, 0, 0);
    layout0->addLayout(layout7, 1, 0);
    layout0->addLayout(layout8, 2, 0);
    layout0->addLayout(layout2, 3, 0);
    layout0->addLayout(layout3, 4, 0);
    layout0->addLayout(layout4, 5, 0);
    layout0->addLayout(layout5, 6, 0);
    layout0->addLayout(layout6, 0, 1, 7, 1);



    //creeons un mmape pour nous 17 slots de maniere a les regrouper en 1
    QSignalMapper *mapper = new QSignalMapper;
    //step1
    mapper->setMapping(un, 1);
    mapper->setMapping(deux, 2);
    mapper->setMapping(trois, 3);
    mapper->setMapping(quatre, 4);
    mapper->setMapping(cinq, 5);
    mapper->setMapping(six, 6);
    mapper->setMapping(sept, 7);
    mapper->setMapping(huit, 8);
    mapper->setMapping(neuf, 9);
    mapper->setMapping(zero, 10);
    mapper->setMapping(point, 11);
    mapper->setMapping(actionPlus, 12);
    mapper->setMapping(actionMoin, 13);
    mapper->setMapping(actionDivi, 14);
    mapper->setMapping(actionMult, 15);
    mapper->setMapping(actionDele, 16);
    mapper->setMapping(actionEgal, 17);

    mapper->setMapping(actionSQRT, 18);
    mapper->setMapping(actionEXPO, 19);
    mapper->setMapping(actionRecLN, 20);
    mapper->setMapping(actionLogar, 21);
    mapper->setMapping(actionLOG, 22);
    mapper->setMapping(actionSIN, 23);
    mapper->setMapping(actionCOS, 24);
    mapper->setMapping(actionTAN, 25);
    //step2
    connect(mapper, SIGNAL(mapped(int)), this, SLOT(appliquerButton(int)));
    //step3
    QObject::connect(un, SIGNAL(clicked()), mapper, SLOT(map()));
    QObject::connect(deux, SIGNAL(clicked()), mapper, SLOT(map()));
    QObject::connect(trois, SIGNAL(clicked()), mapper, SLOT(map()));
    QObject::connect(quatre, SIGNAL(clicked()), mapper, SLOT(map()));
    QObject::connect(cinq, SIGNAL(clicked()), mapper, SLOT(map()));
    QObject::connect(six, SIGNAL(clicked()), mapper, SLOT(map()));
    QObject::connect(sept, SIGNAL(clicked()), mapper, SLOT(map()));
    QObject::connect(huit, SIGNAL(clicked()), mapper, SLOT(map()));
    QObject::connect(neuf, SIGNAL(clicked()), mapper, SLOT(map()));
    QObject::connect(zero, SIGNAL(clicked()), mapper, SLOT(map()));
    QObject::connect(point, SIGNAL(clicked()), mapper, SLOT(map()));
    QObject::connect(actionPlus, SIGNAL(clicked()), mapper, SLOT(map()));
    QObject::connect(actionMoin, SIGNAL(clicked()), mapper, SLOT(map()));
    QObject::connect(actionDivi, SIGNAL(clicked()), mapper, SLOT(map()));
    QObject::connect(actionMult, SIGNAL(clicked()), mapper, SLOT(map()));
    QObject::connect(actionEgal, SIGNAL(clicked()), mapper, SLOT(map()));
    QObject::connect(actionDele, SIGNAL(clicked()), mapper, SLOT(map()));
    QObject::connect(actionSQRT, SIGNAL(clicked()), mapper, SLOT(map()));
    QObject::connect(actionEXPO, SIGNAL(clicked()), mapper, SLOT(map()));
    QObject::connect(actionRecLN, SIGNAL(clicked()), mapper, SLOT(map()));
    QObject::connect(actionLogar, SIGNAL(clicked()), mapper, SLOT(map()));
    QObject::connect(actionLOG, SIGNAL(clicked()), mapper, SLOT(map()));
    QObject::connect(actionSIN, SIGNAL(clicked()), mapper, SLOT(map()));
    QObject::connect(actionCOS, SIGNAL(clicked()), mapper, SLOT(map()));
    QObject::connect(actionTAN, SIGNAL(clicked()), mapper, SLOT(map()));
}


void MainApp::appliquerButton(int nbr){
    switch (nbr) {
        case 1 :
            setNewInput(un);
            break;
        case 2 :
            setNewInput(deux);
            break;
        case 3 :
            setNewInput(trois);
            break;
        case 4 :
            setNewInput(quatre);
            break;
        case 5 :
            setNewInput(cinq);
            break;
        case 6 :
            setNewInput(six);
            break;
        case 7 :
            setNewInput(sept);
            break;
        case 8 :
            setNewInput(huit);
            break;
        case 9 :
            setNewInput(neuf);
            break;
        case 10 :
            setNewInput(zero);
            break;
        case 11 :
            setNewInput(point);
            break;
        case 12 :
            extractInput("+");
            break;
        case 13 :
            extractInput("-");
            break;
        case 14 :
            extractInput("/");
            break;
        case 15 :
            extractInput("*");
            break;
        case 16 :
            while(cal.size() != 0){
                cal.pop_back();
            }
            while(ope.size() != 0){
                ope.pop_back();
            }
            champAffichage->setText("");
            suiteOperation->setText("");
            //i can make it better. allow del one num on one click. not all on one click//
            break;
        case 17 :
            if(champAffichage->text().length() != 0){
                if(champAffichage->text().indexOf("√") >= 0 ){
                    cal.push_back(SpecialFloat(champAffichage->text().remove("√").toFloat(),"SQRT"));
                }
                else if(champAffichage->text().indexOf("x²") >= 0 ){
                    cal.push_back(SpecialFloat(champAffichage->text().remove("x²").toFloat(),"POW"));
                }
                else if(champAffichage->text().indexOf("e²") >= 0 ){
                    cal.push_back(SpecialFloat(champAffichage->text().remove("e²").toFloat(),"EXPO"));
                }
                else if(champAffichage->text().indexOf("ln") >= 0 ){
                    cal.push_back(SpecialFloat(champAffichage->text().remove("ln").toFloat(),"LN"));
                }
                else if(champAffichage->text().indexOf("log") >= 0 ){
                    cal.push_back(SpecialFloat(champAffichage->text().remove("log").toFloat(),"LOG"));
                }
                else if(champAffichage->text().indexOf("sin") >= 0 ){
                    cal.push_back(SpecialFloat(champAffichage->text().remove("sin").toFloat(),"SIN"));
                }
                else if(champAffichage->text().indexOf("cos") >= 0 ){
                    cal.push_back(SpecialFloat(champAffichage->text().remove("cos").toFloat(),"COS"));
                }
                else if(champAffichage->text().indexOf("tan") >= 0 ){
                    cal.push_back(SpecialFloat(champAffichage->text().remove("tan").toFloat(),"TAN"));
                }
                else{
                    cal.push_back(SpecialFloat(champAffichage->text().toFloat(),"BASIC"));
                }
                suiteOperation->setText(suiteOperation->text() + champAffichage->text());
                champAffichage->setText("");
            }
            if(cal.size() == 1){
                float resWhenOnCalc;
                if(cal[0].getNature() == "SQRT")
                    resWhenOnCalc = sqrt(cal[0].getNumber());
                else if(cal[0].getNature() == "POW")
                    resWhenOnCalc = (cal[0].getNumber() * cal[0].getNumber());
                else if(cal[0].getNature() == "EXPO")
                    resWhenOnCalc = exp(cal[0].getNumber());
                else if(cal[0].getNature() == "LN")
                    resWhenOnCalc = log(cal[0].getNumber());
                else if(cal[0].getNature() == "LOG")
                    resWhenOnCalc = log10(cal[0].getNumber());
                else if(cal[0].getNature() == "SIN")
                    resWhenOnCalc = sin(cal[0].getNumber());
                else if(cal[0].getNature() == "COS")
                    resWhenOnCalc = cos(cal[0].getNumber());
                else if(cal[0].getNature() == "TAN")
                    resWhenOnCalc = tan(cal[0].getNumber());
                else
                    resWhenOnCalc = cal[0].getNumber();
                cal.pop_front();

                RESULT = QString::number(resWhenOnCalc);
                if(RESULT=="inf" || RESULT=="-inf"){
                    RESULT = "ES-TU CON ?";
                    wantToTestMyApp = true;
                }
                if(RESULT=="nan")
                    RESULT = ERROR;
            }
            else if(cal.size() >= 2){
                float res;
                if(cal[0].getNature() == "BASIC")
                    res = cal[0].getNumber();
                else if(cal[0].getNature() == "SQRT")
                    res = sqrt(cal[0].getNumber());
                else if(cal[0].getNature() == "POW")
                    res = cal[0].getNumber() * cal[0].getNumber();
                else if(cal[0].getNature() == "EXPO")
                    res = exp(cal[0].getNumber());
                else if(cal[0].getNature() == "LN")
                    res = log(cal[0].getNumber());
                else if(cal[0].getNature() == "LOG")
                    res = log10(cal[0].getNumber());
                else if(cal[0].getNature() == "SIN")
                    res = sin(cal[0].getNumber());
                else if(cal[0].getNature() == "COS")
                    res = cos(cal[0].getNumber());
                else if(cal[0].getNature() == "TAN")
                    res = tan(cal[0].getNumber());
                cal.pop_front();
                while(cal.size() != 0){
                    //one brain on man. am so glade. SYS-20200117:2248:STA-777WELLDONE-FNSH
                    if(ope[0]=="+"){
                        if(cal[0].getNature() == "BASIC")
                            res += cal[0].getNumber();
                        else if(cal[0].getNature() == "SQRT")
                            res += sqrt(cal[0].getNumber());
                        else if(cal[0].getNature() == "POW")
                            res += (cal[0].getNumber() * cal[0].getNumber());
                        else if(cal[0].getNature() == "EXPO")
                            res += exp(cal[0].getNumber());
                        else if(cal[0].getNature() == "LN")
                            res += log(cal[0].getNumber());
                        else if(cal[0].getNature() == "LOG")
                            res += log10(cal[0].getNumber());
                        else if(cal[0].getNature() == "SIN")
                            res += sin(cal[0].getNumber());
                        else if(cal[0].getNature() == "COS")
                            res += cos(cal[0].getNumber());
                        else if(cal[0].getNature() == "TAN")
                            res += tan(cal[0].getNumber());
                    }
                    if(ope[0]=="-"){
                        if(cal[0].getNature() == "BASIC")
                            res -= cal[0].getNumber();
                        else if(cal[0].getNature() == "SQRT")
                            res -= sqrt(cal[0].getNumber());
                        else if(cal[0].getNature() == "POW")
                            res -= (cal[0].getNumber() * cal[0].getNumber());
                        else if(cal[0].getNature() == "EXPO")
                            res -= exp(cal[0].getNumber());
                        else if(cal[0].getNature() == "LN")
                            res -= log(cal[0].getNumber());
                        else if(cal[0].getNature() == "LOG")
                            res -= log10(cal[0].getNumber());
                        else if(cal[0].getNature() == "SIN")
                            res -= sin(cal[0].getNumber());
                        else if(cal[0].getNature() == "COS")
                            res -= cos(cal[0].getNumber());
                        else if(cal[0].getNature() == "TAN")
                            res -= tan(cal[0].getNumber());
                    }
                    if(ope[0]=="*"){
                        if(cal[0].getNature() == "BASIC")
                            res *= cal[0].getNumber();
                        else if(cal[0].getNature() == "SQRT")
                            res *= sqrt(cal[0].getNumber());
                        else if(cal[0].getNature() == "POW")
                            res *= (cal[0].getNumber() * cal[0].getNumber());
                        else if(cal[0].getNature() == "EXPO")
                            res *= exp(cal[0].getNumber());
                        else if(cal[0].getNature() == "LN")
                            res *= log(cal[0].getNumber());
                        else if(cal[0].getNature() == "LOG")
                            res *= log10(cal[0].getNumber());
                        else if(cal[0].getNature() == "SIN")
                            res *= sin(cal[0].getNumber());
                        else if(cal[0].getNature() == "COS")
                            res *= cos(cal[0].getNumber());
                        else if(cal[0].getNature() == "TAN")
                            res *= tan(cal[0].getNumber());
                    }
                    if(ope[0]=="/"){
                        if(cal[0].getNature() == "BASIC")
                            res /= cal[0].getNumber();
                        else if(cal[0].getNature() == "SQRT")
                            res /= sqrt(cal[0].getNumber());
                        else if(cal[0].getNature() == "POW")
                            res /= (cal[0].getNumber() * cal[0].getNumber());
                        else if(cal[0].getNature() == "EXPO")
                            res /= exp(cal[0].getNumber());
                        else if(cal[0].getNature() == "LN")
                            res /= log(cal[0].getNumber());
                        else if(cal[0].getNature() == "LOG")
                            res /= log10(cal[0].getNumber());
                        else if(cal[0].getNature() == "SIN")
                            res /= sin(cal[0].getNumber());
                        else if(cal[0].getNature() == "COS")
                            res /= cos(cal[0].getNumber());
                        else if(cal[0].getNature() == "TAN")
                            res /= tan(cal[0].getNumber());
                    }
                    ope.pop_front();
                    cal.pop_front();
                    //*********************************************************************//
                }
                RESULT = QString::number(res);
                if(RESULT=="inf" || RESULT=="-inf" || RESULT=="nan"){
                    RESULT = ERROR;
                    wantToTestMyApp = true;
                }
            }
            champAffichage->setText(RESULT);
            isEqualPressed = true;
            break;
        case 18 :
            champAffichage->setText("√");
            isFunctionUsed = true;
            break;
        case 19 :
            champAffichage->setText("x²");
            isFunctionUsed = true;
            break;
        case 20 :
            champAffichage->setText("e²");
            isFunctionUsed = true;
            break;
        case 21 :
            champAffichage->setText("ln");
            isFunctionUsed = true;
            break;
        case 22 :
            champAffichage->setText("log");
            isFunctionUsed = true;
            break;
        case 23 :
            champAffichage->setText("sin");
            isFunctionUsed = true;
            break;
        case 24 :
            champAffichage->setText("cos");
            isFunctionUsed = true;
            break;
        case 25 :
            champAffichage->setText("tan");
            isFunctionUsed = true;
            break;
    }
}

void MainApp::extractInput(QString signe){
    if(wantToTestMyApp){
        champAffichage->setText("0");
        suiteOperation->setText("");
        wantToTestMyApp = false;
    }
    if(champAffichage->text().length() == 0){
        RESULT = ERROR;
        wantToTestMyApp = true;
    }
    else{
        if(!isEqualPressed)
            suiteOperation->setText(suiteOperation->text() + champAffichage->text() + " " + signe + " ");
        else{
            suiteOperation->setText("");
            suiteOperation->setText(suiteOperation->text() + champAffichage->text() + " " + signe + " ");
            isEqualPressed = false;
        }
        if(champAffichage->text().indexOf("√") >= 0 ){
            cal.push_back(SpecialFloat(champAffichage->text().remove("√").toFloat(),"SQRT"));
            ope.push_back(signe);
            champAffichage->setText("");
        }
        else if(champAffichage->text().indexOf("x²") >= 0 ){
            cal.push_back(SpecialFloat(champAffichage->text().remove("x²").toFloat(),"POW"));
            ope.push_back(signe);
            champAffichage->setText("");
        }
        else if(champAffichage->text().indexOf("e²") >= 0 ){
            cal.push_back(SpecialFloat(champAffichage->text().remove("e²").toFloat(),"EXPO"));
            ope.push_back(signe);
            champAffichage->setText("");
        }
        else if(champAffichage->text().indexOf("ln") >= 0 ){
            cal.push_back(SpecialFloat(champAffichage->text().remove("ln").toFloat(),"LN"));
            ope.push_back(signe);
            champAffichage->setText("");
        }
        else if(champAffichage->text().indexOf("log") >= 0 ){
            cal.push_back(SpecialFloat(champAffichage->text().remove("log").toFloat(),"LOG"));
            ope.push_back(signe);
            champAffichage->setText("");
        }
        else if(champAffichage->text().indexOf("sin") >= 0 ){
            cal.push_back(SpecialFloat(champAffichage->text().remove("sin").toFloat(),"SIN"));
            ope.push_back(signe);
            champAffichage->setText("");
        }
        else if(champAffichage->text().indexOf("cos") >= 0 ){
            cal.push_back(SpecialFloat(champAffichage->text().remove("cos").toFloat(),"COS"));
            ope.push_back(signe);
            champAffichage->setText("");
        }
        else if(champAffichage->text().indexOf("tan") >= 0 ){
            cal.push_back(SpecialFloat(champAffichage->text().remove("tan").toFloat(),"TAN"));
            ope.push_back(signe);
            champAffichage->setText("");
        }
        else{
            cal.push_back(SpecialFloat(champAffichage->text().toFloat(),"BASIC"));
            ope.push_back(signe);
            champAffichage->setText("");
        }
    }
}

void MainApp::setNewInput(QPushButton *btn){
    if(btn != point){
        if(wantToTestMyApp){
            champAffichage->setText("");
            suiteOperation->setText("");
            wantToTestMyApp = false;
        }
        if(isEqualPressed){
            suiteOperation->setText("");
            isEqualPressed = false;
        }
        if(isEqualPressed && !champAffichage->text().contains(QRegExp("[√-x²-e²-ln-log-sin-cos-tan]"))){
            champAffichage->setText("");
        }
        champAffichage->setText(champAffichage->text() + btn->text());
    }
    else{
        if(wantToTestMyApp){
            champAffichage->setText("0");
            suiteOperation->setText("");
            wantToTestMyApp = false;
        }
        if(champAffichage->text().length()==0){
            champAffichage->setText("0");
        }
        if(isEqualPressed){
            suiteOperation->setText("");
            champAffichage->setText("");
            isEqualPressed = false;
        }
        champAffichage->setText(champAffichage->text() + point->text());
    }
}
