#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

struct Lsimple{
	int dato;
	Lsimple *next;
};

Lsimple *Head = NULL, *Tail = NULL;

//-----------Funciones----------------//
//insertar por cabeza
void uph(Lsimple *&,Lsimple *&,int);
//insertar por cola
void upt(Lsimple *&,Lsimple *&,int);
//Borrar un elemento
void down(Lsimple *&,Lsimple *&, Lsimple*);
//buscar y retorna un elemento de la lista..
Lsimple *buscar(Lsimple *,int);
//ver la lista
void ver(Lsimple *);

int main(){
	uph(Head,Tail,5);
	uph(Head,Tail,4);
	uph(Head,Tail,3);
	uph(Head,Tail,8);
	upt(Head,Tail,1);
	upt(Head,Tail,0);
	//cout << Head->dato ;
	down(Head,Tail,buscar(Head,4));
    ver(Head);
	return 0;
}

void uph(Lsimple *&head ,Lsimple *&tail,int dato)
{
	//se crea el nodo.
	Lsimple *nuevo = (Lsimple*)malloc(sizeof(Lsimple));
	
	//asignamiento de datos.
	nuevo->dato = dato;
	
	if(head == NULL){
		//el ultimo elemento es el primero. en este caso el primer elemento es NULL.
		tail = nuevo;
		tail->next = NULL;
	}
	
	//asignamiento de punteros.
	nuevo->next = head;
	head = nuevo;
}

void upt(Lsimple *& head,Lsimple *& tail ,int dato){
	Lsimple *nuevo = (Lsimple*)malloc(sizeof(Lsimple));
	nuevo->dato = dato;
	nuevo->next = NULL;
	tail->next = nuevo;
	tail = nuevo;
}

Lsimple *buscar(Lsimple *head,int dato){
	while(head){
		if(head->dato == dato){
			return head;
		}
		head = head->next; 
	}
	return head;
}

void down(Lsimple *& head,Lsimple *& tail,Lsimple * borrar){
	if(borrar){
		//si se tiene que borrar la cabeza.
		if(borrar == head){
			if(head->next == NULL){
				head = NULL;
			}
			else{
				Lsimple *aux = head;
				head = head->next;
				free(aux);
			}
		}
		//si se tiene que borrar un valor intermedio.
		if(borrar != tail){
			Lsimple *aux = head;
			
			while(aux->next != borrar){
				aux = aux->next;
			} 
			
			aux->next = borrar->next;
			free(borrar);
		}
		//si se tiene que quitar la cola.
		else{
			Lsimple *aux = head;
			while(aux->next != borrar){
				aux = aux->next;
			}
			
			free(borrar);
			tail = aux;
			tail->next = NULL;
		}
	
	}
	
}
void ver(Lsimple *head){
	//se muestra hasta que sea null.
	while(head){
		cout << head->dato << " -> ";
		head = head->next;
	}
	cout << "NULL\n";
}
