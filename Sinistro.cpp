/* 
 * File:   Sinistro.cpp
 * Author: thiagojesus
 * 
 * Created on June 28, 2013, 6:30 PM
 */

#include "Sinistro.h"
#define INT_MAX 100000

Sinistro::Sinistro() {
    std::cout<<"Informe os dados do Sinistro."<<std::endl;

    std::cin.clear(); //esse método e o de baixo servem para limpar o buffer de entrada
    std::cin.ignore(INT_MAX,'\n');
    std::cout<<"\nLocal: ";
    std::getline(std::cin,this->local);
    
    std::cout<<"\nNumero do sinistro: ";
    std::cin>>id;
    
    std::cout<<"\nTipo do sinistro:\n(1)Incendio\n(2)Colisao\n(3)Furto";
    std::cin>>tipoSinistro;
    
    data.currentDateTime();
    
    std::string texto;
    int num;
    
    int tipo;
    std::cout<<"\nHouve terceiros envolvidos?\n(1)Sim\n(2)Nao";
    std::cin>>tipo;
    if(tipo == 1)
    {
        std::cout<<"Informe os dados do envolvido."<<std::endl;

        std::cin.clear(); //esse método e o de baixo servem para limpar o buffer de entrada
        std::cin.ignore(INT_MAX,'\n');
        
        std::cout<<"\nNome: ";
        std::getline(std::cin, texto);
        envolvido.SetNome(texto);
        
        std::cout<<"\nEndereco: ";
        std::getline(std::cin, texto);
        envolvido.SetEndereco(texto);
        
        std::cout<<"\nTelefone: ";
        std::getline(std::cin, texto);
        envolvido.SetTelefone(texto);
        
        std::cout<<"\nSeguradora: ";
        std::getline(std::cin, texto);
        envolvido.SetSeguradora(texto);        
        
        std::cout<<"\nIdade: ";
        std::cin>>num;
        envolvido.SetIdade(num);
    }
    
    std::cout<<"Informe os dados do BO."<<std::endl;
    
    std::cout<<"\nNumero: ";
    std::cin>>num;
    bo.SetNum(num);
 
    std::cin.clear(); //esse método e o de baixo servem para limpar o buffer de entrada
    std::cin.ignore(INT_MAX,'\n');
    
    std::cout<<"\nTipo: ";
    std::getline(std::cin, texto);
    bo.SetTipo(texto);
    
    Data d;
    std::cout<<"\nData (DD MM AAAA): ";
    std::cin>>num;
    d.SetDia(num);
    
    std::cin>>num;
    d.SetMes(num);
    
    std::cin>>num;
    d.SetAno(num);
    bo.SetData(d);
    
    
}

Sinistro::Sinistro(const Sinistro& orig) {
}

Sinistro::~Sinistro() {
}

