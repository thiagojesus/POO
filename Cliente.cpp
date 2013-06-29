/* 
 * File:   Cliente.cpp
 * Author: thiagojesus
 * 
 * Created on June 28, 2013, 6:18 PM
 */

#include "Cliente.h"
#include <fstream>
#include "Lista.cpp"
#include <string>

Cliente::Cliente(){
    
}

Cliente::Cliente(int i) {
    std::cin.clear(); //esse método e o de baixo servem para limpar o buffer de entrada
    std::cin.ignore(INT_MAX,'\n');
    std::cout<<"Nome do cliente: ";
    getline(std::cin,this->nome);
    std::cout<<"Telefone: ";
    getline(std::cin,this->telefone);
    std::cout<<"Endereco: ";
    getline(std::cin,this->endereco);
    std::cout<<"CPF: ";
    getline(std::cin,this->cpf);
    std::cout<<"Email: ";
    getline(std::cin,this->email);
    this->napa = 0;
    inicLista(&(this->apolices));
}

Cliente::Cliente(const Cliente& orig) {
}

Cliente::~Cliente() {
}

void Cliente::salvar(listacli* p_l, int napa){
    std::fstream myfile;
    Cliente *aux;
    int i;
    aux = *p_l;
    myfile.open("cliente.bin",std::ios::out|std::ios::binary|std::ios::trunc);
    if(!myfile){
        std::cout<<"ERRO!";
    }else{
        myfile<<napa<<"\n";
        for(i=0;i<napa;i++){
            myfile<<aux->nome<<"\n"<<aux->endereco<<"\n"<<aux->telefone<<"\n"<<aux->cpf<<"\n"<<aux->email<<"\n"<<aux->napa;
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
    myfile.open("cliente.bin",std::ios::in|std::ios::binary);
    if(!myfile){
        //std::cout<<"ERRO!";
        return 0;
    }else{
        myfile>>ncli;
        for(i=0;i<ncli;i++){
            Cliente *aux = new Cliente();
            myfile.clear();
            myfile.ignore(INT_MAX,'\n');
            getline(myfile,aux->nome);
            getline(myfile,aux->endereco);
            getline(myfile,aux->telefone);
            getline(myfile,aux->cpf);
            getline(myfile,aux->email);
            myfile>>aux->napa;
            parou = local;
            local = Apolice::carregar(&(aux->apolices),(aux->napa),parou, &pacart);
            cadastrar(p_l,aux);
            }
        
        
    }
    
    myfile.close();
    if(remove("cliente.bin")!=0){
        perror("ERRO!");
    }
    
    myfile.close();
    if(remove("apolice.bin") !=0){
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
    getline(std::cin,pesq);
    Cliente *aux = *l;
    while(aux != NULL){
        if(aux->nome == pesq){
            deletar(l,aux);
        }
        aux = aux->prox;
    }
}

