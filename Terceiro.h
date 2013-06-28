/* 
 * File:   Terceiro.h
 * Author: thiagojesus
 *
 * Created on June 28, 2013, 6:35 PM
 */

#ifndef TERCEIRO_H
#define	TERCEIRO_H

class Terceiro {
public:
    Terceiro();
    Terceiro(const Terceiro& orig);
    virtual ~Terceiro();
private:
    std::string seguradora;
    std::string nome;
    std::string telefone;
    std::string endereco;
    int idade;
};

#endif	/* TERCEIRO_H */

