/* 
 * File:   Sinistro.h
 * Author: thiagojesus
 *
 * Created on June 28, 2013, 6:30 PM
 */

#ifndef SINISTRO_H
#define	SINISTRO_H
#include "Data.h"
#include "BO.h"
#include <string>

class Sinistro {
public:
    Sinistro();
    Sinistro(const Sinistro& orig);
    virtual ~Sinistro();
private:
    int num;
    Data data;
    std::string local;
    BO bo;
    enum TipoSinistro {incendio, colisao, furto};
};

#endif	/* SINISTRO_H */

