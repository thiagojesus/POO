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
        cout<<"Bem vindo ao Gerenciador da Seguradora\nDigite a opcao desejada:\n";
    cout<<"1- Cadastro\n2- Pesquisa\n3- Vendas\n4- Exclusao\n5- Sair";
    cout<<"\nSua opcao:";
    cin>>op;
    switch(op){
        case 1: cout<<"Cadastro\nDigite a opcao desejada:\n";
                cout<<"1- Cliente\n2- Apolice\n3- Sinistro\n4- Condutor\n5- Voltar ao menu principal";
                cout<<"\n Sua Opcao:";
                cin>>op;
                switch(op){
                    case 1: //TODO: criar um cliente, suas apolices, veiculos e condutores
                        break;
                    case 2: //TODO: buscar cliente, criar apolice, adicionar veiculos e condutores
                        break;
                    case 3: //TODO: buscar a apolice do cliente e criar um sinistro
                        break;
                    case 4: //TODO: buscar a apolice do cliente e criar um veiculo
                        break;
                    case 5: op=0;
                        break;
                }
            break;
        case 2: cout<<"Pesquisa\nDigite a opcao desejada:\n";
                cout<<"1- Cliente\n2- Apolice\n3- Sinistro\n4- Condutor\n5- Voltar ao menu principal";
                cout<<"\n Sua Opcao:";
                cin>>op;
        case 5:
            if(ncli !=0){
                Cliente::salvar(&lcliente,ncli);
            }
            break;
    }
    }while(op!=5);
}

