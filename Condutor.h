/* 
 * File:   Condutor.h
 * Author: thiagojesus
 *
 * Created on June 28, 2013, 6:21 PM
 */

#ifndef CONDUTOR_H
#define	CONDUTOR_H

class Condutor {
public:
    Condutor();
    Condutor(const Condutor& orig);
    virtual ~Condutor();
private:
    std::string numCNH;
    int idade;
};

#endif	/* CONDUTOR_H */

