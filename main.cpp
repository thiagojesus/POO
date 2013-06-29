/* 
 * File:   main.cpp
 * Author: thiagojesus
 *
 * Created on June 28, 2013, 6:16 PM
 */

#include <cstdlib>
#include "Lista.cpp"
#include "Cliente.h"
#include "Apolice.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    Cliente::listacli lcliente; //lista de clientes
    int ncli; //numero de clientes
    int op; //opcao do menu
    inicLista(&lcliente);
    ncli = Cliente::carregar(&lcliente);
    do{
        cout<<"Bem vindo ao Gerenciador da Clinica de Vacinas\nDigite a opcao desejada:\n";
    cout<<"1- Cadastro\n2- Pesquisa\n3- Vendas\n4- Exclusao\n5- Sair";
    cout<<"\nSua opcao:";
    cin>>op;
    switch(op){
        case 1: 
            break;
        case 5:
            if(ncli !=0){
                Cliente::salvar(&lcliente,ncli);
            }
            break;
    }
    }while(op!=5);
}

