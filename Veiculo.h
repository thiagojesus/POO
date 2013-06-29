/* 
 * File:   Veiculo.h
 * Author: thiagojesus
 *
 * Created on June 28, 2013, 6:40 PM
 */

#ifndef VEICULO_H
#define	VEICULO_H
#include <string>
#include <iostream>


class Veiculo {
public:
    Veiculo();
    Veiculo(const Veiculo& orig);
    enum TipoVeiculo {passeio, transporte};
    virtual ~Veiculo();
    void imprimir();
private:
    std::string placa;
    int ano;
    std::string RENAVAM;
    int tipo;
    std::string marca;
};

#endif	/* VEICULO_H */

