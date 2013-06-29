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
    typedef Condutor* ListaCond;
    
    enum tipoSinistro {incendio, colisao, furto};
    Sinistro *prox;
    
    Sinistro();
    Sinistro(const Sinistro& orig);
    
    void incluirBO(BO *);
    void incluirTerceiro(Terceiro *);
    Sinistro* buscar(std::string &nome);
    virtual ~Sinistro();
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

