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
    Veiculo(int i);
    Veiculo(const Veiculo& orig);
    enum TipoVeiculo {passeio, transporte};
    virtual ~Veiculo();
    void imprimir();
    void setMarca(std::string marca);
    std::string getMarca() const;
    void setTipo(int tipo);
    int getTipo() const;
    void setRENAVAM(std::string RENAVAM);
    std::string getRENAVAM() const;
    void setAno(int ano);
    int getAno() const;
    void setPlaca(std::string placa);
    std::string getPlaca() const;
private:
    std::string placa;
    int ano;
    std::string RENAVAM;
    int tipo;
    std::string marca;
};

#endif	/* VEICULO_H */

