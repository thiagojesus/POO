/* 
 * File:   Apolice.cpp
 * Author: thiagojesus
 * 
 * Created on June 28, 2013, 6:26 PM
 */

#include "Apolice.h"
#include <fstream>
#include "Lista.cpp"
#include <string>

Apolice::Apolice() {
}

Apolice::Apolice(const Apolice& orig) {
}

Apolice::~Apolice() {
}

void Apolice::salvar(listanapa* p, int napa){
    std::fstream myfile;
    Apolice *aux;
    int cart, i;
    aux = *p;
    myfile.open("apolice.bin",std::ios::out|std::ios::app|std::ios::binary);
    if(!myfile){
        std::cout<<"ERRO!";
    }else{
        //myfile.seekg(parou);
        for(i=0;i<napa;i++){
            myfile<<aux->num<<"\n"<<aux->vigencia.GetDia()<<"\n"<<aux->vigencia.GetMes()<<"\n"<<aux->vigencia.GetAno();
            aux = aux->prox;
        }
        std::cout<<"arquivo criado com sucesso\n";
        myfile.close();
  
    }
}

long Apolice::carregar(listanapa* p, int napa, long parou, long* pacart){
  std::fstream myfile;
    int i=0, dia, mes, ano;
    long esta=0, carte=0;
    myfile.open("apolice.bin",std::ios::in|std::ios::binary);
    if(!myfile){
        std::cout<<"ERRO!";
    }else{
        myfile.seekg(parou);
        for(i =0; i<napa;i++){
            Apolice *aux = new Apolice();
            myfile>>aux->num;
            myfile>>dia>>mes>>ano;
            aux->vigencia.SetDia(dia);
            aux->vigencia.SetMes(mes);
            aux->vigencia.SetAno(ano);
            cadastrar(p,aux);
            }
        //std::cout<<"dados carregados\n";   
            
        esta = myfile.tellg();
        myfile.close();
        return esta;
    }  
}


void Apolice::novoSinistro(Sinistro::ListaSin *l, Sinistro *s)
{
    Sinistro *sa;
    sa = new Sinistro();
    cadastrar(l,sa);
}