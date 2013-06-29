/* 
 * File:   Terceiro.cpp
 * Author: thiagojesus
 * 
 * Created on June 28, 2013, 6:35 PM
 */

#include <iostream>

#include "Terceiro.h"

Terceiro::Terceiro() {
    std::cout<<"Informe os dados do envolvido."<<std::endl;
    std::cout<<"Informe o nome: ";
    std::cin>>nome>>std::endl;
    std::cout<<"Informe o idade: ";
    std::cin>>idade>>std::endl;
    std::cout<<"Informe o telefone: ";
    std::cin>>telefone>>std::endl;
    std::cout<<"Informe o endereco: ";
    std::cin>>endereco>>std::endl;
    std::cout<<"Informe a seguradora: ";
    std::cin>>seguradora>>std::endl;
}

Terceiro::Terceiro(const Terceiro& orig) {
}

Terceiro::~Terceiro() {
}

