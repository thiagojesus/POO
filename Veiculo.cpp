/* 
 * File:   Veiculo.cpp
 * Author: thiagojesus
 * 
 * Created on June 28, 2013, 6:40 PM
 */

#include "Veiculo.h"
#define INT_MAX 100000

Veiculo::Veiculo() {
        
    std::cout<<"Informe os dados do veiculo."<<std::endl;

    std::cin.clear(); //esse método e o de baixo servem para limpar o buffer de entrada
    std::cin.ignore(INT_MAX,'\n');
    std::cout<<"\nPlaca: ";
    std::getline(std::cin,this->placa);
    std::cout<<"\nRenavam: ";
    std::getline(std::cin,this->RENAVAM);
    std::cout<<"\nMarca: ";
    std::getline(std::cin,this->marca);
    std::cout<<"\nTipo: ";
    std::cin>>tipo;
  
    std::cout<<"\nAno: ";     
    std::cin>>ano;
    
}

Veiculo::Veiculo(const Veiculo& orig) {
}

Veiculo::~Veiculo() {
}

void Veiculo::imprimir(){
    std::cout<<"Placa: "<<this->placa<<"\nRENAVAM: "<<this->RENAVAM<<"\nAno: "<<this->ano<<"\nTipo: "<<this->tipo<<"\nMarca: "<<this->marca<<std::endl;
}
