/* 
 * File:   BO.h
 * Author: thiagojesus
 *
 * Created on June 28, 2013, 6:38 PM
 */

#ifndef BO_H
#define	BO_H
#include <string>
#include "Data.h"

class BO {
public:
    BO();
    BO(const BO& orig);
    virtual ~BO();
    void SetTipo(std::string tipo);
    std::string GetTipo() const;
    void SetNum(int num);
    int GetNum() const;
    void SetData(Data data);
    Data GetData() const;
private:
    int num;
    Data data;
    std::string tipo;
};

#endif	/* BO_H */

