/* 
 * File:   Sinistro.h
 * Author: thiagojesus
 *
 * Created on June 28, 2013, 6:30 PM
 */

#ifndef SINISTRO_H
#define	SINISTRO_H

class Sinistro {
public:
    Sinistro();
    Sinistro(const Sinistro& orig);
    virtual ~Sinistro();
private:
    int num;
    std::string data;
    std::string local;
    enum TipoSinistro {incendio, colisao, furto};
};

#endif	/* SINISTRO_H */

