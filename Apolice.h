/* 
 * File:   Apolice.h
 * Author: thiagojesus
 *
 * Created on June 28, 2013, 6:26 PM
 */

#ifndef APOLICE_H
#define	APOLICE_H
#include "Data.h"
#include "Sinistro.h"
#include "Condutor.h"
#include "Veiculo.h"

class Apolice {
public:
    Apolice();
    Apolice(int i);
    Apolice(const Apolice& orig);
    virtual ~Apolice();
    typedef Apolice* listanapa;
    void novoSinistro(Sinistro::ListaSin *l); 
    void novoCondutor(Condutor::ListaCond *c);
    Apolice* prox; //ponteiro para manipulacao da lista
    static void salvar(listanapa *p, int napa); //metodo que salva os dados em um txt
    static long carregar(listanapa *p, int napa, long parou); //metodo que recupera os dados de um txt
    static int excluir(listanapa *p);
    static Apolice* pesquisar(listanapa *l, int n);
    Condutor::ListaCond getLCond() const;
    Sinistro::ListaSin getLSin() const;
private:
    int num;
    Data vigencia;
    Veiculo *v;
    bool situacaoPagto;//TRUE para em dia
    enum Classificacao {classe1, classe2};
    Sinistro::ListaSin lSin;
    int nsin;
    Condutor::ListaCond lCond; 
    int ncond;
};

#endif	/* APOLICE_H */

