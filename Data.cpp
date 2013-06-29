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

const void Data::currentDateTime(){
    time_t     now = time(0);
    struct tm  tstruct;
    char       buf[80];
    tstruct = *localtime(&now);
    strftime(buf, sizeof(buf), "%d", &tstruct);
    this->dia = atoi(buf);
    strftime(buf, sizeof(buf), "%m", &tstruct);
    this->mes = atoi(buf);
    strftime(buf, sizeof(buf), "%Y", &tstruct);
    this->ano = atoi(buf);
}

