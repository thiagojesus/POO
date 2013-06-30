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
    std::cout<<"Numero da apolice: ";
    std::cin>>this->num;
    this->vigencia.currentDateTime();
    int ano = this->vigencia.GetAno();
    ano++;
    this->vigencia.SetAno(ano);
    this->v = new Veiculo();
    this->situacaoPagto = false;
    this->nsin = 0;
    this->ncond = 0;
    inicLista(&(this->lCond));
    inicLista(&(this->lSin));
}

Apolice::Apolice(int i){
    
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
            myfile<<aux->num<<"\n"<<aux->vigencia.GetDia()<<"\n"<<aux->vigencia.GetMes()<<"\n"<<aux->vigencia.GetAno()<<"\n"<<aux->situacaoPagto<<"\n"<<aux->nsin<<"\n"<<aux->ncond<<"\n";
            Sinistro::salvar(&(aux->lSin),aux->nsin);
            aux = aux->prox;
        }
        std::cout<<"arquivo criado com sucesso\n";
        myfile.close();
  
    }
}

long Apolice::carregar(listanapa* p, int napa, long parou){
  std::fstream myfile;
    int i=0, dia, mes, ano;
    long esta=0, carte=0, sin=0, cond=0;
    myfile.open("apolice.bin",std::ios::in|std::ios::binary);
    if(!myfile){
        std::cout<<"ERRO!";
    }else{
        myfile.seekg(parou);
        for(i =0; i<napa;i++){
            Apolice *aux = new Apolice(1);
            myfile>>aux->num;
            myfile>>dia>>mes>>ano;
            aux->vigencia.SetDia(dia);
            aux->vigencia.SetMes(mes);
            aux->vigencia.SetAno(ano);
            myfile>>aux->situacaoPagto;
            myfile>>aux->nsin;
            myfile>>aux->ncond;
            sin = Sinistro::carregar(&(aux->lSin),aux->nsin,sin);
            cadastrar(p,aux);
            }
        //std::cout<<"dados carregados\n";   
            
        esta = myfile.tellg();
        myfile.close();
        return esta;
    }  
}


void Apolice::novoSinistro(Sinistro::ListaSin *l)
{
    Sinistro *sa;
    sa = new Sinistro();
    cadastrar(l,sa);
    this->nsin++;
}

void Apolice::novoCondutor(Condutor::ListaCond* c){
    Condutor *ca;
    ca = new Condutor();
    this->ncond++;
}