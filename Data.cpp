/* 
 * File:   Data.cpp
 * Author: thiagojesus
 * 
 * Created on June 28, 2013, 7:12 PM
 */

#include "Data.h"

Data::Data() {
}

Data::Data(const Data& orig) {
}

Data::~Data() {
}

void Data::SetAno(int ano) {
    this->ano = ano;
}

int Data::GetAno() const {
    return ano;
}

void Data::SetMes(int mes) {
    this->mes = mes;
}

int Data::GetMes() const {
    return mes;
}

void Data::SetDia(int dia) {
    this->dia = dia;
}

int Data::GetDia() const {
    return dia;
}

Data::Data(int _dia, int _mes, int _ano){
    this->dia = _dia;
    this->mes = _mes;
    this->ano = _ano;
}

