/* 
 * File:   Terceiro.h
 * Author: thiagojesus
 *
 * Created on June 28, 2013, 6:35 PM
 */

#ifndef TERCEIRO_H
#define	TERCEIRO_H
#include <string>

class Terceiro {
public:
    Terceiro();
    Terceiro(const Terceiro& orig);
    virtual ~Terceiro();
    void SetIdade(int idade);
    int GetIdade() const;
    void SetEndereco(std::string endereco);
    std::string GetEndereco() const;
    void SetTelefone(std::string telefone);
    std::string GetTelefone() const;
    void SetNome(std::string nome);
    std::string GetNome() const;
    void SetSeguradora(std::string seguradora);
    std::string GetSeguradora() const;
    
private:
    std::string seguradora;
    std::string nome;
    std::string telefone;
    std::string endereco;
    int idade;
};

#endif	/* TERCEIRO_H */

