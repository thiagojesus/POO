/* 
 * File:   Cliente.cpp
 * Author: thiagojesus
 * 
 * Created on June 28, 2013, 6:18 PM
 */

#include "Cliente.h"
#include <fstream>
#include "Lista.cpp"
#define INT_MAX 100000
#include <string>

Cliente::Cliente(){
    inicLista(&(this->apolices));
}

Cliente::Cliente(int i) {
    std::cin.clear(); //esse método e o de baixo servem para limpar o buffer de entrada
    std::cin.ignore(INT_MAX,'\n');
    std::cout<<"Nome do cliente: ";
    std::getline(std::cin,this->nome);
    std::cout<<"\nTelefone: ";
    std::getline(std::cin,this->telefone);
    std::cout<<"\nEndereco: ";
    std::getline(std::cin,this->endereco);
    std::cout<<"\nCPF: ";
    std::getline(std::cin,this->cpf);
    std::cout<<"\nEmail: ";
    std::getline(std::cin,this->email);
    this->napa = 0;
    inicLista(&(this->apolices));
}

Cliente::Cliente(const Cliente& orig) {
}

Cliente::~Cliente() {
}

void Cliente::salvar(listacli* p_l, int ncli){
    std::fstream myfile;
    Cliente *aux;
    int i;
    aux = *p_l;
    myfile.open("cliente.txt",std::ios::out|std::ios::trunc);
    if(!myfile){
        std::cout<<"ERRO!";
    }else{
        myfile<<ncli<<"\n";
        for(i=0;i<ncli;i++){
            myfile<<aux->nome<<"\n"<<aux->endereco<<"\n"<<aux->telefone<<"\n"<<aux->cpf<<"\n"<<aux->email<<"\n"<<aux->napa<<"\n";
            Apolice::salvar(&(aux->apolices), aux->napa);
            aux = aux->prox;
        }
        std::cout<<"arquivo criado com sucesso\n";
        myfile.close();
    }
}

int Cliente::carregar(listacli* p_l){
    std::fstream myfile;
    int ncli = 0, i;
    long local=0, parou=0, pacart;
    myfile.open("cliente.txt",std::ios::in);
    if(!myfile){
        //std::cout<<"ERRO!";
        return 0;
    }else{
        myfile>>ncli;
        for(i=0;i<ncli;i++){
            Cliente *aux = new Cliente();
            myfile.clear();
            myfile.ignore(INT_MAX,'\n');
            std::getline(myfile,aux->nome);
            std::getline(myfile,aux->endereco);
            std::getline(myfile,aux->telefone);
            std::getline(myfile,aux->cpf);
            std::getline(myfile,aux->email);
            myfile>>aux->napa;
            parou = local;
            local = Apolice::carregar(&(aux->apolices),(aux->napa),parou);
            cadastrar(p_l,aux);
            }
        
        
    }
    
    myfile.close();
    if(remove("cliente.txt")!=0){
        perror("ERRO!");
    }
    
    myfile.close();
    if(remove("apolice.txt") !=0){
       perror("ERRO!"); 
    }
    
    if(remove("sinistro.txt") !=0){
        perror("ERRO!");
    }
    return ncli;
}

void Cliente::imprimir(){
    std::cout<<"nome: "<<this->nome<<"\nendereco: "<<this->endereco<<"\ntelefone: "<<this->telefone<<"\ncpf: "<<this->cpf<<"\nemail: "<<this->email<<std::endl;
}

void Cliente::pesquisar(listacli *l, std::string *nome){
    Cliente *aux = *l;
    while(aux != NULL){
        if(aux->nome == *nome){
            this->nome = aux->nome;
            this->endereco = aux->endereco;
            this->telefone = aux->telefone;
            this->apolices = aux->apolices;
            this->cpf = aux->cpf;
            this->email = aux->email;
            *nome = "0";
        }
        aux = aux->prox;
    }
}

void Cliente::pesquisar(std::string *tel, listacli* l){
 Cliente *aux = *l;
    while(aux != NULL){
        if(aux->cpf == *tel){
            this->nome = aux->nome;
            this->endereco = aux->endereco;
            this->telefone = aux->telefone;
            this->apolices = aux->apolices;
            this->cpf = aux->cpf;
            this->email = aux->email;
            *tel = "0";
        }
        aux = aux->prox;
    }    
}

void Cliente::excluir(listacli* l){
    std::string pesq;
    std::cout<<"Nome do cliente: ";
    std::cin.clear(); //esse método e o de baixo servem para limpar o buffer de entrada
    std::cin.ignore(INT_MAX,'\n');
    std::getline(std::cin,pesq);
    Cliente *aux = *l;
    while(aux != NULL){
        if(aux->nome == pesq){
            deletar(l,aux);
        }
        aux = aux->prox;
    }
}

void Cliente::setApolices(Apolice::listanapa apolices) {
    this->apolices = apolices;
}

Apolice::listanapa Cliente::getApolices() const {
    return apolices;
}

void Cliente::setNapa(int napa) {
    this->napa = napa;
}

int Cliente::getNapa() const {
    return napa;
}

void Cliente::novAp(Apolice *a){
    this->napa = this->napa + 1;
    cadastrar(&(this->apolices),a);
}

Cliente* Cliente::retPon(listacli* l, std::string* nome){
    Cliente *aux = *l;
    while(aux != NULL){
        if(aux->nome == *nome){
            *nome = "0";
            return aux;
        }
        aux = aux->prox;
    }
    return NULL;
}
