/* 
 * File:   Condutor.cpp
 * Author: thiagojesus
 * 
 * Created on June 28, 2013, 6:21 PM
 */

#include "Condutor.h"

Condutor::Condutor() {
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

