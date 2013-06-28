/* 
 * File:   Cliente.h
 * Author: thiagojesus
 *
 * Created on June 28, 2013, 6:18 PM
 */

#ifndef CLIENTE_H
#define	CLIENTE_H

class Cliente {
public:
    Cliente();
    Cliente(const Cliente& orig);
    virtual ~Cliente();
private:
    std::string nome;
    std::string telefone;
    std::string endereco;
};

#endif	/* CLIENTE_H */

