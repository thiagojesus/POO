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

void Terceiro::SetIdade(int idade) {
    this->idade = idade;
}

int Terceiro::GetIdade() const {
    return idade;
}

void Terceiro::SetEndereco(std::string endereco) {
    this->endereco = endereco;
}

std::string Terceiro::GetEndereco() const {
    return endereco;
}

void Terceiro::SetTelefone(std::string telefone) {
    this->telefone = telefone;
}

std::string Terceiro::GetTelefone() const {
    return telefone;
}

void Terceiro::SetNome(std::string nome) {
    this->nome = nome;
}

std::string Terceiro::GetNome() const {
    return nome;
}

void Terceiro::SetSeguradora(std::string seguradora) {
    this->seguradora = seguradora;
}

std::string Terceiro::GetSeguradora() const {
    return seguradora;
}

