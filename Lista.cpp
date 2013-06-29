/* 
 * File:   Lista.cpp
 * Author: thiagojesus
 * 
 * Created on June 18, 2012, 10:46 AM
 */
#include <iostream>
#include <fstream>


template<class mytype>
static void cadastrar(mytype** p, mytype* conteudo){
    mytype *aux;
    aux = *p;
    conteudo->prox = NULL;
    if(listaVazia(p)){
		*p=conteudo;
	}else{
		while(aux->prox!=NULL){
			aux=aux->prox;
		}
		aux->prox=conteudo;	
	}
}

template<typename mytype>
static int listaVazia(mytype** p_l){
	if (*p_l == NULL)
		return 1;
	return 0;
}

template<typename mytype>
static void inicLista(mytype *p_l){
	*p_l = NULL;
}

template<typename mytype>
static void deletar(mytype** p_l, mytype* p){
    mytype *aux, *del;
    aux = *p_l;
    if(aux== p){
        *p_l=aux->prox;
    }else{
        while(aux->prox != NULL){
            if(aux->prox==p){
                aux->prox = aux->prox->prox;
            }else{
                aux = aux->prox;
            }
        }
        
    }
    
    
}