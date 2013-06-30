/* 
 * File:   Sinistro.cpp
 * Author: thiagojesus
 * 
 * Created on June 28, 2013, 6:30 PM
 */

#include "Sinistro.h"
#include "Lista.cpp"
#define INT_MAX 100000

Sinistro::Sinistro() {
    std::cout<<"Informe os dados do Sinistro."<<std::endl;

    std::cin.clear(); //esse método e o de baixo servem para limpar o buffer de entrada
    std::cin.ignore(INT_MAX,'\n');
    std::cout<<"\nLocal: ";
    std::getline(std::cin,this->local);
    
    std::cout<<"\nNumero do sinistro: ";
    std::cin>>id;
    
    std::cout<<"\nTipo do sinistro:\n(1)Incendio\n(2)Colisao\n(3)Furto";
    std::cin>>tipoSinistro;
    
    data.currentDateTime();
    
    std::string texto;
    int num;
    
    int tipo;
    std::cout<<"\nHouve terceiros envolvidos?\n(1)Sim\n(2)Nao";
    std::cin>>tipo;
    if(tipo == 1)
    {
        std::cout<<"Informe os dados do envolvido."<<std::endl;

        std::cin.clear(); //esse método e o de baixo servem para limpar o buffer de entrada
        std::cin.ignore(INT_MAX,'\n');
        
        std::cout<<"\nNome: ";
        std::getline(std::cin, texto);
        envolvido.SetNome(texto);
        
        std::cout<<"\nEndereco: ";
        std::getline(std::cin, texto);
        envolvido.SetEndereco(texto);
        
        std::cout<<"\nTelefone: ";
        std::getline(std::cin, texto);
        envolvido.SetTelefone(texto);
        
        std::cout<<"\nSeguradora: ";
        std::getline(std::cin, texto);
        envolvido.SetSeguradora(texto);        
        
        std::cout<<"\nIdade: ";
        std::cin>>num;
        envolvido.SetIdade(num);
    }
    
    std::cout<<"Informe os dados do BO."<<std::endl;
    
    std::cout<<"\nNumero: ";
    std::cin>>num;
    bo.SetNum(num);
 
    std::cin.clear(); //esse método e o de baixo servem para limpar o buffer de entrada
    std::cin.ignore(INT_MAX,'\n');
    
    std::cout<<"\nTipo: ";
    std::getline(std::cin, texto);
    bo.SetTipo(texto);
    
    Data d;
    std::cout<<"\nData (DD MM AAAA): ";
    std::cin>>num;
    d.SetDia(num);
    
    std::cin>>num;
    d.SetMes(num);
    
    std::cin>>num;
    d.SetAno(num);
    bo.SetData(d);
    
    
}

Sinistro::Sinistro(const Sinistro& orig) {
}

Sinistro::Sinistro(int i){
    
}

Sinistro::~Sinistro() {
}

void Sinistro::salvar(ListaSin* p, int nsin){
    std::fstream myfile;
    Sinistro *aux;
    int cart, i;
    aux = *p;
    myfile.open("sinistro.txt",std::ios::out|std::ios::app);
    if(!myfile){
        std::cout<<"ERRO!";
    }else{
        //myfile.seekg(parou);
        for(i=0;i<nsin;i++){
            myfile<<aux->id<<"\n"<<aux->data.GetDia()<<"\n"<<aux->data.GetMes()<<"\n"<<aux->data.GetAno()<<"\n"<<aux->local<<"\n"<<aux->bo.GetTipo()<<"\n"<<aux->bo.GetNum()<<"\n"<<aux->bo.GetData().GetDia()<<"\n"<<aux->bo.GetData().GetMes()<<"\n"<<aux->bo.GetData().GetAno()<<"\n"<<aux->tipoSinistro<<"\n"<<aux->envolvido.GetNome()<<"\n"<<aux->envolvido.GetSeguradora()<<"\n"<<aux->envolvido.GetEndereco()<<"\n"<<aux->envolvido.GetTelefone()<<"\n"<<aux->envolvido.GetIdade()<<"\n";
            aux = aux->prox;
        }
        std::cout<<"arquivo criado com sucesso\n";
        myfile.close();
  
    }
}

long Sinistro::carregar(ListaSin* p, int nsin, long parou){
    std::fstream myfile;
    std::string tipo;
    int i=0, dia, mes, ano, bnum;
    Data *d;
    long esta=0, carte=0, sin=0, cond=0;
    myfile.open("sinistro.txt",std::ios::in);
    if(!myfile){
        std::cout<<"ERRO!";
    }else{
        myfile.seekg(parou);
        for(i =0; i<nsin;i++){
            Sinistro *aux = new Sinistro(1);
            myfile>>aux->id;
            myfile>>dia>>mes>>ano;
            aux->data.SetDia(dia);
            aux->data.SetMes(mes);
            aux->data.SetAno(ano);
            myfile.clear(); //esse método e o de baixo servem para limpar o buffer de entrada
            myfile.ignore(INT_MAX,'\n');
            getline(myfile,aux->local);
            getline(myfile,tipo);
            aux->bo.SetTipo(tipo);
            myfile>>bnum;
            aux->bo.SetNum(bnum);
            myfile>>dia>>mes>>ano;
            d = new Data(dia,mes,ano);
            aux->bo.SetData(*d);
            myfile>>aux->tipoSinistro;
            myfile.clear(); //esse método e o de baixo servem para limpar o buffer de entrada
            myfile.ignore(INT_MAX,'\n');
            getline(myfile,tipo);
            aux->envolvido.SetNome(tipo);
            getline(myfile,tipo);
            aux->envolvido.SetSeguradora(tipo);
            getline(myfile,tipo);
            aux->envolvido.SetEndereco(tipo);
            getline(myfile,tipo);
            aux->envolvido.SetTelefone(tipo);
            myfile>>bnum;
            aux->envolvido.SetIdade(bnum);
            cadastrar(p,aux);
            }
        //std::cout<<"dados carregados\n";   
            
        esta = myfile.tellg();
        myfile.close();
        return esta;
    }  
}

void Sinistro::excluir(ListaSin* p, int _id){
    Sinistro *aux = *p;
    while(aux != NULL){
        if(aux->id == _id){
            deletar(p,aux);
        }
        aux = aux->prox;
    }
}

