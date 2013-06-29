/* 
 * File:   Condutor.cpp
 * Author: thiagojesus
 * 
 * Created on June 28, 2013, 6:21 PM
 */

#include "Condutor.h"
#include "Lista.cpp"

Condutor::Condutor() {  
      
}

Condutor::Condutor(int i) {
    
    std::cout<<"Informe os dados do Condutor."<<std::endl;

    std::cin.clear(); //esse método e o de baixo servem para limpar o buffer de entrada
    std::cin.ignore(INT_MAX,'\n');
    
    std::cout<<"\nNome: ";
    std::getline(std::cin,this->nome);
    
    std::cout<<"\nNumero da CNH: ";
    std::getline(std::cin,this->numCNH);
    
    std::cout<<"\nTelefone: ";
    std::getline(std::cin,this->telefone);
    
    std::cout<<"\nIdade: ";
    std::cin>>idade;
    
}

Condutor::Condutor(const Condutor& orig) {
}

Condutor::~Condutor() {
}

void Condutor::SetIdade(int idade) {
    this->idade = idade;
}

int Condutor::GetIdade() const {
    return idade;
}

void Condutor::SetTelefone(std::string telefone) {
    this->telefone = telefone;
}

std::string Condutor::GetTelefone() const {
    return telefone;
}

void Condutor::SetNumCNH(std::string numCNH) {
    this->numCNH = numCNH;
}

std::string Condutor::GetNumCNH() const {
    return numCNH;
}

void Condutor::SetNome(std::string nome) {
    this->nome = nome;
}

std::string Condutor::GetNome() const {
    return nome;
}

void Condutor::imprimir(){
    std::cout<<"nome: "<<this->nome<<"\nNumero do CNH: "<<this->numCNH<<"\nTelefone: "<<this->telefone<<"\nIdade: "<<this->idade<<std::endl;
}

void Condutor::pesquisar(ListaCond *l, std::string *nome){
    Condutor *aux = *l;
    while(aux != NULL){
        if(aux->nome == *nome){
            this->nome = aux->nome;
            this->numCNH = aux->numCNH;
            this->telefone = aux->telefone;
            this->idade = aux->idade;
             *nome = "0";
        }
        aux = aux->prox;
    }
}

void Condutor::excluir(ListaCond* l){
    std::string pesq;
    std::cout<<"Nome do cliente: ";
    std::cin.clear(); //esse método e o de baixo servem para limpar o buffer de entrada
    std::cin.ignore(INT_MAX,'\n');
    std::getline(std::cin,pesq);
    Condutor *aux = *l;
    while(aux != NULL){
        if(aux->nome == pesq){
            deletar(l,aux);
        }
        aux = aux->prox;
    }
}

Condutor * Condutor::bucar(std::string *nome, ListaCond *lCond){
    Condutor *aux = *lCond;
    while(aux != NULL){
        if(aux->nome == *nome){
            return aux;
             *nome = "0";
        }
        aux = aux->prox;
    }
}
