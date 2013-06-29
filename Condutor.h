/* 
 * File:   Condutor.h
 * Author: thiagojesus
 *
 * Created on June 28, 2013, 6:21 PM
 */

#ifndef CONDUTOR_H
#define	CONDUTOR_H
#include <string>
#include<iostream>
#define INT_MAX 100000


class Condutor {
public:
    typedef Condutor* ListaCond ;
    Condutor *prox;
    Condutor();
    Condutor(int i);
    Condutor(const Condutor& orig);
    virtual ~Condutor();
    
    Condutor *bucar(std::string *nome, ListaCond *lCond);
    
    void SetIdade(int idade);
    int GetIdade() const;
    
    void SetTelefone(std::string telefone);
    std::string GetTelefone() const;
    
    void SetNumCNH(std::string numCNH);
    std::string GetNumCNH() const;
    
    void SetNome(std::string nome);
    std::string GetNome() const;
    
    void imprimir();
    void pesquisar(ListaCond *l, std::string *nome); //metodo que busca um cliente por nome
   static void excluir(ListaCond *l); //metodo que exclui um cliente da lista
    
private:
    std::string nome;
    std::string numCNH;
    std::string telefone;
    int idade;
};

#endif	/* CONDUTOR_H */

