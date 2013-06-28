/* 
 * File:   Data.h
 * Author: thiagojesus
 *
 * Created on June 28, 2013, 7:12 PM
 */

#ifndef DATA_H
#define	DATA_H

class Data {
public:
    Data();
    Data(int _dia, int _mes, int _ano);
    Data(const Data& orig);
    virtual ~Data();
private:
    int dia;
    int mes;
    int ano;
};

#endif	/* DATA_H */

