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
    Cliente(const Cliente& orig);
    virtual ~Cliente();
    typedef Cliente* listacli;
    Cliente *prox; // variavel para manipulacao da lista
    static void salvar(listacli *p_l, int napa); //metodo para salvar os dados em um .bin
    static int carregar(listacli *p_l); //metodo para carregar os dados de um .bin
    Cliente* pesquisar(); //metodo que devolve um ponteiro para o registro pesquisado ou nulo caso nao encontrado
private:
    std::string nome;
    std::string telefone;
    std::string endereco;
    Apolice::listanapa apolices; //lista ligada com as apolices do cliente
    int napa; //numero de apolices para recuperar no carregamento
};

#endif	/* CLIENTE_H */

