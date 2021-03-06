/* 
 * File:   Cliente.h
 * Author: thiagojesus
 *
 * Created on June 28, 2013, 6:18 PM
 */

#ifndef CLIENTE_H
#define	CLIENTE_H
#include "Apolice.h"
#include <string>

class Cliente {
public:
    Cliente();
    Cliente(int i);
    Cliente(const Cliente& orig);
    virtual ~Cliente();
    typedef Cliente* listacli;
    Cliente *prox; // variavel para manipulacao da lista
    static void salvar(listacli *p_l, int ncli); //metodo para salvar os dados em um .bin
    static int carregar(listacli *p_l); //metodo para carregar os dados de um .bin
    void imprimir(); //imprime um cliente
    void pesquisar(listacli *l, std::string *nome); //metodo que busca um cliente por nome
    void pesquisar(std::string *tel, listacli *l); //metodo que busca um cliente por telefone
    static void excluir(listacli *l);
    void setApolices(Apolice::listanapa apolices);
    Apolice::listanapa getApolices() const;
    void setNapa(int napa);
    int getNapa() const; //metodo que exclui um cliente da lista
    void novAp(Apolice *a);
    static Cliente * retPon(listacli *l, std::string *nome);
private:
    std::string nome;
    std::string telefone;
    std::string endereco;
    std::string cpf;
    std::string email;
    Apolice::listanapa apolices; //lista ligada com as apolices do cliente
    int napa; //numero de apolices para recuperar no carregamento
};

#endif	/* CLIENTE_H */

