/* 
 * File:   BO.h
 * Author: thiagojesus
 *
 * Created on June 28, 2013, 6:38 PM
 */

#ifndef BO_H
#define	BO_H
#include <string>

class BO {
public:
    BO();
    BO(const BO& orig);
    virtual ~BO();
private:
    int num;
    std::string data;
    std::string tipo;
};

#endif	/* BO_H */

