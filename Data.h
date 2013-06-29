/* 
 * File:   Data.h
 * Author: thiagojesus
 *
 * Created on June 28, 2013, 7:12 PM
 */

#ifndef DATA_H
#define	DATA_H
#include <string>
#include <stdio.h>
#include <time.h>

class Data {
public:
    Data();
    Data(int _dia, int _mes, int _ano);
    Data(const Data& orig);
    virtual ~Data();
    void SetAno(int ano);
    int GetAno() const;
    void SetMes(int mes);
    int GetMes() const;
    void SetDia(int dia);
    int GetDia() const;
    const void currentDateTime();
private:
    int dia;
    int mes;
    int ano;
};

#endif	/* DATA_H */

