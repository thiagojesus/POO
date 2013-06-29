/* 
 * File:   Veiculo.h
 * Author: thiagojesus
 *
 * Created on June 28, 2013, 6:40 PM
 */

#ifndef VEICULO_H
#define	VEICULO_H
#include <string>

class Veiculo {
public:
    Veiculo();
    Veiculo(const Veiculo& orig);
    enum TipoVeiculo {passeio, transporte};
    enum Marca {fiat, vw, ford, honda};
    virtual ~Veiculo();
private:
    std::string placa;
    int ano;
    std::string RENAVAM;
    int tipo;
    int marca;
};

#endif	/* VEICULO_H */

