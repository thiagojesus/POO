/* 
 * File:   Terceiro.cpp
 * Author: thiagojesus
 * 
 * Created on June 28, 2013, 6:35 PM
 */

#include <iostream>
#define INT_MAX 100000
#include "Terceiro.h"

Terceiro::Terceiro() {
    std::cout<<"Informe os dados do envolvido."<<std::endl;

    std::cin.clear(); //esse método e o de baixo servem para limpar o buffer de entrada
    std::cin.ignore(INT_MAX,'\n');
    std::cout<<"\nNome: ";
    std::getline(std::cin,this->nome);
    std::cout<<"\nEndereco: ";
    std::getline(std::cin,this->endereco);
    std::cout<<"\nTelefone: ";
    std::getline(std::cin,this->telefone);
    std::cout<<"\nSeguradora: ";
    std::getline(std::cin,this->seguradora);
    std::cout<<"\nIdade: ";
    std::cin>>idade;
 
}

Terceiro::Terceiro(const Terceiro& orig) {
}

Terceiro::~Terceiro() {
}

