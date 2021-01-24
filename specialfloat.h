#ifndef SPECIALFLOAT_H
#define SPECIALFLOAT_H

#include <QString>

class SpecialFloat
{
    /*
     *=>j'utilisait un vecteur de float pour recuperer les entrées des utilisateurs
     *=>avec la version 2.0 qui incluait qlq fonctions comme sqrt j'ai donc opter pour --
     *=>cette classe contenant le vecteur et le type d'operation soit BASIC pour un simple --
     *=>calcul, SQRT pour la racine carré, POW, SIN, TAN, COS, EXP, LOG pour ce que vous devinez.
    */
    public:
        //constructeur
        SpecialFloat(float nbr = 0, QString nat = "BASIC");
        //accesseur
        float getNumber() const;
        QString getNature() const;
        //mutateur
        void setNumber(float nbr);
        void setNature(QString nat);
    private:
        float m_number;
        QString m_nature;
};

#endif // SPECIALFLOAT_H
