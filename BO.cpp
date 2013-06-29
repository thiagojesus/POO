/* 
 * File:   BO.cpp
 * Author: thiagojesus
 * 
 * Created on June 28, 2013, 6:38 PM
 */

#include "BO.h"

BO::BO() {
}

BO::BO(const BO& orig) {
}

BO::~BO() {
}

void BO::SetTipo(std::string tipo) {
    this->tipo = tipo;
}

std::string BO::GetTipo() const {
    return tipo;
}

void BO::SetNum(int num) {
    this->num = num;
}

int BO::GetNum() const {
    return num;
}

void BO::SetData(Data data) {
    this->data.SetDia(data.GetDia());
    this->data.SetMes(data.GetMes());
    this->data.SetAno(data.GetAno());
}

Data BO::GetData() const {
    return data;
}

