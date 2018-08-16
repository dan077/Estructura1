#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

using namespace std;

struct nodo{
    int dato;
    struct nodo *ant,*sgt;
};

struct nodo *head = NULL,*aux;
void AgregarPorCabeza(int);
void AgregarPorCola(int);
void mostrar();
void mostrarInversa();
void buscar(int);
void eliminar(int);

void menu();

int main(){
    menu();
    system("pause");
    return 0;
}

void menu(){
     char opcion;
    int a;
    bool sw = true;
    while(sw){
        system("cls");
    	printf ("\n\n");
    	printf("\t\t?????????????????????????????????????????????????????????????????????????????\n");
    	printf("\t\t?                              MEN\243                                         ?\n");
    	printf("\t\t?????????????????????????????????????????????????????????????????????????????\n");
    	printf("\t\t?                                                                           ?\n");
    	printf("\t\t?     1 -> Ingresar por cabeza                                              ?\n");
    	printf("\t\t?                                                                           ?\n");
    	printf("\t\t?     2 -> Ingresar por cola                                                ?\n");
    	printf("\t\t?                                                                           ?\n");
    	printf("\t\t?     3 -> Mostrar                                                          ?\n");
    	printf("\t\t?                                                                           ?\n");
    	printf("\t\t?     4 -> Mostrar invertida                                                ?\n");
    	printf("\t\t?                                                                           ?\n");
    	printf("\t\t?     5 -> Buscar                                                           ?\n");
    	printf("\t\t?                                                                           ?\n");
    	printf("\t\t?     6 -> Eliminar                                                         ?\n");
    	printf("\t\t?                                                                           ?\n");
    	printf("\t\t?     7 -> Salir                                                            ?\n");
    	printf("\t\t?                                                                           ?\n");
    	printf("\t\t?????????????????????????????????????????????????????????????????????????????\n");
    	printf("\t\t?  Elija una opcion...                                                      ?\n");
    	printf("\t\t?????????????????????????????????????????????????????????????????????????????\n");
        opcion = getch();
        system("cls");
        switch(opcion){
            case '1':
                cout << "ingrese el dato: "; cin >> a; 
                AgregarPorCabeza(a);
                system("pause");
                break;
            case '2':
                cout << "ingrese el dato: "; cin >> a; 
                AgregarPorCola(a);
                system("pause");
                break;
            case '3':
                mostrar();
                system("pause");
                break;
            case '4':
                mostrarInversa();
                system("pause");
                break;    
            case '5':
                cout << "ingrese el dato a buscar: "; cin >> a; 
                buscar(a);
                system("pause");
                break;
            case '6':
                cout << "ingrese el dato a eliminar: "; cin >> a; 
                eliminar(a);
                system("pause");
                break;
            case '7':
                sw = false;
                break;
            default:
                cout << "Ingrese una opcion valida.\n";
                system("pause");   
        }
          
    }
  

}

void AgregarPorCabeza(int a){
    aux = (struct nodo*)malloc(sizeof(struct nodo));
    aux->dato = a;
    if(head == NULL){
        aux->ant = NULL;
        aux->sgt = NULL;
        head = aux;
    }
    else{
        head->ant = aux;
        aux->ant = NULL;
        aux->sgt = head;
        head = aux;
    }
}

void AgregarPorCola(int b){
    aux = (struct nodo*)malloc(sizeof(struct nodo));
    struct nodo * aux2 = head;
    aux->dato = b;
    if(head == NULL){
        aux->ant = NULL;
        aux->sgt = NULL;
        head = aux;
    }
    else{
        while(aux2->sgt != NULL){
            aux2 = aux2->sgt;
        }
        aux2->sgt = aux;
        aux->ant = aux2;
        aux->sgt = NULL;
        
    }
}

void buscar(int buscar){
    aux = head;
    int sw = 0;
    if(head != NULL){
        while(aux != NULL and sw == 0)
        {
            if(aux->dato == buscar)
            {
                sw++;
            }else{
                aux = aux->sgt;
            }
        
        }
        if(!sw)
        {
            cout << "No ";
        }
     
        cout << "Se ha encontrado en la lista.\n";
        
    }else{
        cout << "La lista esta vacia. \n";
    }
    
    
    
}
void eliminar(int eliminar){
    aux = head;
    struct nodo *auxAnt, *auxSgt;
    int sw = 0;
    
    if(head != NULL){
        if(head->dato == eliminar)
        {
            if(head->sgt != NULL){
                head = head->sgt;
                aux->sgt = NULL;
                free(aux);
            }else{
              head = NULL;  
            }
            
            cout << "El dato ha sido eliminado \n";
            
        }
        else{
            while(aux != NULL and sw == 0)
            {
                if(aux->dato == eliminar){
                    sw++;
                }
                else{
                    aux = aux->sgt;
                }
            }
            if(sw){
                if(aux->sgt == NULL){
                    auxAnt = aux->ant;
                    auxAnt->sgt = NULL;
                    free(aux);
                }else{
                    auxAnt = aux->ant;
                    auxSgt = aux->sgt;
                    
                    auxAnt->sgt = auxSgt;
                    auxSgt->ant = auxAnt;
                    
                    aux->ant = NULL;
                    aux->sgt = NULL;
                    free(aux);
                }
                cout << "El dato ha sido eliminado \n";
            }else{
                cout << "No se ha encontrado en la lista. \n";
            }
        }   
    }else{
        cout << "La lista esta Vacia. \n";
    }
}
void mostrar(){
    aux = head;
    if(head != NULL){
        while(aux != NULL){
            cout << "Dato: " << aux->dato << '\n';
            aux = aux->sgt;
        }
    }else{
        cout << "La lista esta vacia.\n";
    }

}

void mostrarInversa(){
    aux = head;
    if(head != NULL){
        while(aux->sgt != NULL)
        {
        aux = aux->sgt;
        }
        while(aux != NULL)
        {
            cout << "Dato: " << aux->dato << '\n';
            aux = aux->ant;
        }    
    }else{
        cout << "La lista esta vacia. \n";
    }
    
}

