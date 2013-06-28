/* 
 * File:   Veiculo.h
 * Author: thiagojesus
 *
 * Created on June 28, 2013, 6:40 PM
 */

#ifndef VEICULO_H
#define	VEICULO_H

class Veiculo {
public:
    Veiculo();
    Veiculo(const Veiculo& orig);
    virtual ~Veiculo();
private:
    std::string placa;
    int ano;
    std::string RENAVAM;
    enum TipoVeiculo {passeio, transporte};
    enum Marca {fiat, vw, ford, honda};
};

#endif	/* VEICULO_H */

