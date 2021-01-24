#include "specialfloat.h"

SpecialFloat::SpecialFloat(float nbr, QString nat)
{
    m_number = nbr;
    m_nature = nat;
}

float SpecialFloat::getNumber() const{
    return m_number;
}

QString SpecialFloat::getNature() const{
    return m_nature;
}

void SpecialFloat::setNumber(float nbr){
    m_number = nbr;
}

void SpecialFloat::setNature(QString nat){
    m_nature = nat;
}
