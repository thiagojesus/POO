/* 
 * File:   Apolice.h
 * Author: thiagojesus
 *
 * Created on June 28, 2013, 6:26 PM
 */

#ifndef APOLICE_H
#define	APOLICE_H

class Apolice {
public:
    Apolice();
    Apolice(const Apolice& orig);
    virtual ~Apolice();
private:
    int num;
    std::string vigencia;
    enum Classificacao {classe1, classe2};
};

#endif	/* APOLICE_H */

