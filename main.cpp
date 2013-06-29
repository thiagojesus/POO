/* 
 * File:   main.cpp
 * Author: Lucas, Pedro, Thiago, Vinnicius e Yanick
 *
 * Created on June 28, 2013, 6:16 PM
 */

#include <cstdlib>
#include "Lista.cpp"
#include "Cliente.h"
#include "Apolice.h"
#define INT_MAX 100000

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    Cliente::listacli lcliente; //lista de clientes
    Cliente *c; //ponteiro para instanciar os clientes
    Apolice *a; //ponteiro para instanciar as apolices
    int ncli; //numero de clientes
    int op; //opcao do menu
    string pesquisa; //string para guardar o termo de pesquisa
    inicLista(&lcliente);
    ncli = Cliente::carregar(&lcliente);
    do {
        cout << "Bem vindo ao Gerenciador da Seguradora\nDigite a opcao desejada:\n";
        cout << "1- Cadastro\n2- Pesquisa\n3- Vendas\n4- Exclusao\n5- Sair";
        cout << "\nSua opcao:";
        cin >> op;
        switch (op) {
            case 1: cout << "Cadastro\nDigite a opcao desejada:\n";
                cout << "1- Cliente\n2- Apolice\n3- Sinistro\n4- Condutor\n5- Voltar ao menu principal";
                cout << "\n Sua Opcao:";
                cin >> op;
                switch (op) {
                    case 1: c = new Cliente(1);
                        cadastrar(&lcliente, c);
                        ncli++;
                        break;
                    case 2: c = new Cliente();
                            std::cin.clear(); //esse método e o de baixo servem para limpar o buffer de entrada
                            std::cin.ignore(INT_MAX, '\n');
                            cout<<"Nome do cliente:";
                            getline(cin,pesquisa);
                            c->pesquisar(&lcliente,&pesquisa);
                            if(pesquisa == "0"){
                                a = new Apolice();
                                Apolice *b = c->getApolices();
                                cadastrar(&b,a);
                            }
                        break;
                    case 3: //TODO: buscar a apolice do cliente e criar um sinistro
                        break;
                    case 4: //TODO: buscar a apolice do cliente e criar um veiculo
                        break;
                    case 5: op = 0;
                        break;
                }
                break;
            case 2: cout << "Pesquisa\nDigite a opcao desejada:\n";
                cout << "1- Cliente\n2- Apolice\n3- Sinistro\n4- Condutor\n5- Voltar ao menu principal";
                cout << "\n Sua Opcao:";
                cin >> op;
                switch (op) {
                    case 1: cout << "Pesquisar cliente por:\n";
                        cout << "1- nome\n2- telefone\n3- voltar ao menu inicial";
                        cout << "\n Sua Opcao:";
                        cin >> op;
                        switch (op) {
                            case 1: std::cin.clear(); //esse método e o de baixo servem para limpar o buffer de entrada
                                std::cin.ignore(INT_MAX, '\n');
                                cout<<"Nome:";
                                getline(cin, pesquisa);
                                c = new Cliente();
                                c->pesquisar(&lcliente, &pesquisa);
                                if(pesquisa == "0"){
                                    c->imprimir();
                                }else{
                                    cout<<"Registro nao encontrado\n";
                                }
                                
                                c->~Cliente();
                                break;
                            case 2: std::cin.clear(); //esse método e o de baixo servem para limpar o buffer de entrada
                                std::cin.ignore(INT_MAX, '\n');
                                cout<<"CPF:";
                                getline(cin, pesquisa);
                                c = new Cliente();
                                c->pesquisar(&pesquisa, &lcliente);
                                if(pesquisa == "0"){
                                    c->imprimir();
                                }else{
                                    cout<<"Registro nao encontrado\n";
                                }
                                
                                c->~Cliente();
                                break;
                        }
                        break;
                    case 2: //TODO: pesquisar apolice
                        break;
                    case 3: //TODO pesquisar sinistro
                        break;
                    case 4: //TODO: pesquisar condutor
                        break;
                    case 5: op = 0;
                        break;
                }
                break;
            case 3: cout << "Vendas\nDigite a opcao desejada:\n";
                cout << "1- Orcamento\n2- Fechar venda\n3- Voltar ao menu principal";
                cout << "\n Sua Opcao:";
                cin >> op;
                switch (op) {
                    case 1: //orcar o seguro
                        break;
                    case 2: //gravar a apolice
                        break;
                    case 3: op = 0;
                        break;
                }
                break;
            case 4: cout << "Exclusao\nDigite a opcao desejada:\n";
                cout << "1- Cliente\n2- Apolice\n3- Sinistro\n4- Condutor\n5- Voltar ao menu principal";
                cout << "\n Sua Opcao:";
                cin >> op;
                switch (op) {
                    case 1: Cliente::excluir(&lcliente);
                        break;
                    case 2: //TODO: remover cliente, criar apolice, adicionar veiculos e condutores
                        break;
                    case 3: //TODO: remover a apolice do cliente e criar um sinistro
                        break;
                    case 4: //TODO: remover a apolice do cliente e criar um veiculo
                        break;
                    case 5: op = 0;
                        break;
                }
                break;
            case 5: if (ncli != 0) {
                    Cliente::salvar(&lcliente, ncli);
                }
                break;

        }
    } while (op != 5);
}

