/* 
 * File:   Orcamento.h
 * Author: thiagojesus
 *
 * Created on June 28, 2013, 6:47 PM
 */

#ifndef ORCAMENTO_H
#define	ORCAMENTO_H

class Orcamento {
public:
    Orcamento();
    Orcamento(const Orcamento& orig);
    virtual ~Orcamento();
private:
    std::string tipo;
    float valorRessarc;
};

#endif	/* ORCAMENTO_H */

