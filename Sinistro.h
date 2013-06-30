/* 
 * File:   Sinistro.h
 * Author: thiagojesus
 *
 * Created on June 28, 2013, 6:30 PM
 */

#ifndef SINISTRO_H
#define	SINISTRO_H
#include <iostream>
#include "Data.h"
#include "BO.h"
#include "Condutor.h"
#include "Terceiro.h"
#include <string>

class Sinistro {
public:
    typedef Sinistro* ListaSin;
    
    enum tipoSinistro {incendio, colisao, furto};
    Sinistro *prox;
    
    Sinistro();
    Sinistro(const Sinistro& orig);
    Sinistro(int i);
    void incluirBO(BO *);
    void incluirTerceiro(Terceiro *);
    Sinistro* buscar(std::string &nome);
    virtual ~Sinistro();
    static void salvar(ListaSin *p, int nsin); //metodo que salva os dados em um txt
    static long carregar(ListaSin *p, int nsin, long parou); //metodo que recupera os dados de um txt
private:
    int id;
    Data data;
    std::string local;
    BO bo;
    int tipoSinistro;
    Condutor *cond; //ponteiro para o condutor expecificado 
    Terceiro envolvido; //dados do envolvido no sinstro.
};

#endif	/* SINISTRO_H */

