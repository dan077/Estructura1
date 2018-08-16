/*
El siguiente algoritmo simula el juego de josephus.

El problema es el siguiente: se tiene un  nodo que almacena la informacion de un soldado,(nombre y un entero).
 Se inicia eliminando el tercer nodo, antes de eliminarlo se extrae el numero entero almacenado en el,
 apartir del nodo siguiente se cuentan el numero de nodos igual al numero de extraído anteriormente,
 el nodo es eliminado tambien,continuar asi hasta que queden dos nodos, 
  esos seran los soldados sobrevivientes  y se deben imprimir.

    |  Nombre   |    Codigo   |
    |Daniel Vega|  2017214084 |

*/
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <conio.h>
#define LVACIA cout << "Por Favor registre soldados.\n"

using namespace std;
struct nodo{
	char nombre[15];
	int numero;
	nodo *ant,*sgt;
};

nodo *head = NULL,*aux,*aux2;

void Add(char*,int);
void imprimir();
void josephus();
void inicio();
void ingresarSoldado();
void decorador(char*,int);
nodo* eliminar(nodo*&);

int main(){

    inicio();
    
    system("pause");
    return 0;
    
}

void ingresarSoldado(){
    SetConsoleTitle("Registrar Soldado");
    fflush(stdin);
    char nombre[100];
    int numero;
    int contador = 0;
    cout << "\t\t\tRegistrar Soldado\n";

    do{
        contador = 0;
        cout << "Nombre: " ;
        gets(nombre);
        for(;nombre[contador] != '\0';contador++);
        if(contador > 15){
            cout << "El nombre es muy largo , no exeda los 15 caracteres.\n";
            memset(nombre,'\0',15);
            
        } 
    }while(contador > 15);
    fflush(stdin);
    do{
        
        cout << "Numero: ";
        cin >> numero;
        if(numero < 1){
            cout << "Por favor ingrese un numero mayor o igual que 1\n";
        }
    }while(numero < 1);
    Add(nombre,numero);
}

void inicio(){
    char opcion;
    int a;
    bool sw = true;
    while(sw){
        SetConsoleTitle("INICIO");
        system("cls");
    	printf ("\n\n");
    	printf("\t\t?????????????????????????????????????????????????????????????????????????????\n");
    	printf("\t\t?                                JOSEPHUS                                   ?\n");
    	printf("\t\t?????????????????????????????????????????????????????????????????????????????\n");
    	printf("\t\t?                                                                           ?\n");
    	printf("\t\t?     1 -> Registrar soldado                                                ?\n");
     	printf("\t\t?                                                                           ?\n");
    	printf("\t\t?     2 -> Ver ejercito                                                     ?\n");
    	printf("\t\t?                                                                           ?\n");
    	printf("\t\t?     3 -> Iniciar Simulacion                                               ?\n");
    	printf("\t\t?                                                                           ?\n");
    	printf("\t\t?     4 -> Salir                                                            ?\n");
    	printf("\t\t?                                                                           ?\n");
    	printf("\t\t?????????????????????????????????????????????????????????????????????????????\n");
    	printf("\t\t?  Elija una opcion...                                                      ?\n");
    	printf("\t\t?????????????????????????????????????????????????????????????????????????????\n");
        opcion = getch();
        system("cls");
        switch(opcion){
            case '1':
                ingresarSoldado();
                break;
            case '2':	
            	cout << "\t\t--------------------------------\n";
            	cout << "\t\t|\t    EJERCITO\t       |\n";
            	cout << "\t\t--------------------------------\n";
                imprimir();
                system("pause");
                break;
            case '3':
                josephus();
                system("pause");
                break;
            case '4':
                exit(0);

            default:
                cout << "Ingrese una opcion valida.\n";
                system("pause");   
        }
}
}

void Add(char* nombre,int numero){
	aux = (nodo*)malloc(sizeof(nodo));
	
	strcpy(aux->nombre,nombre);
	aux->numero = numero;
	
	if(head == NULL){
		aux->ant = aux;
		aux->sgt = aux;
		head = aux;
	}
	else{
		//La cola
		aux2 = head->ant;
		
		//intermedios
		aux->sgt = head;
		head->ant = aux;
		
		//extremos
		aux->ant = aux2;
		aux2->sgt = aux;

		head = aux; 
	}
}

void decorador(char* texto,int cantidad){
    char decorador[15];
    strcpy(decorador,texto);
    int cant = 0;
    for(;decorador[cant] != '\0';cant++);
    
    for(;cant < cantidad; cant++){
        decorador[cant] = ' ';
    }
    cout <<"\t| " << decorador << " | ";
}

void imprimir(){
    SetConsoleTitle("Mostrar soldados");
	aux = head ;	
	cout << "\t\t--------------------------------\n";
	cout << "\t\t|\tNombre\t  |  Numero    |\n";
	cout << "\t\t--------------------------------\n";
	if(head != NULL){
		do{
		    fflush(stdin);
		    cout << "\t";
			decorador(aux->nombre,15);
			cout << "\t" << aux->numero << "      |\n";
			cout << "\t\t--------------------------------\n";
			aux = aux->sgt;
		}while(aux != head);
	}else{
		LVACIA;
	}
}

nodo* eliminar(nodo*& muerto){
	aux2 = head->ant;
	nodo *retorno = muerto->sgt,*anterior ,*siguiente;
	
	
	if(muerto == head){
		head = head->sgt;
		head->ant = aux2;
		aux2->sgt = head;
		free(muerto);	
	}
	else if(muerto == aux2){
	    anterior = aux2->ant;
        siguiente = aux2->sgt;
	    //el penultimo nodo pasa a ser la cola.
		anterior->sgt = head;
		//la cola se convierte en el penultimo nodo.
		head->ant = anterior;
		free(muerto);
	}
	else{
	    anterior = muerto->ant ; siguiente = muerto->sgt;
	    anterior->sgt = siguiente;
	    siguiente->ant = anterior;
	    free(muerto);
    }
	return retorno;
}

void josephus(){
    SetConsoleTitle("Simulacion");
    if(head!= NULL){
        if(head->sgt == head or head->sgt->sgt == head){
            cout << "Al haber ";
            if(head->sgt->sgt == head and head->sgt != head){
                cout << "2 soldados";
            }
            else{
                cout << "1 soldado";
            }
            cout << " no fue necesario que hubieran muertos.\n -!Alerta!- El ejercito de joshepus se ha rendido.\n";
            
        }
        else{
            int getNum;
            getNum = 3;
            aux = head;
        	while(head->sgt->sgt != head){
        	    for(;getNum > 1;aux = aux->sgt,getNum--);
        	    getNum = aux->numero;
        	    cout << "\nHa muerto : " << aux->nombre;
        	    if(head->sgt->sgt->sgt != head){
        	        cout << " Continua la simulacion con el numero: " << aux->numero << "\n";
                }
        	    aux2 = eliminar(aux);
        	    aux = aux2;
            }
            cout << "\n\nLos ultimos dos soldados deciden rendirse.\n";
            cout << "\nFin de la simulacion...\n";
            cout << "\t\t--------------------------------\n";
        	cout << "\t\t|\t SOBREVIVIENTES \t|\n";
        	cout << "\t\t--------------------------------\n";
            
            imprimir();    
        }
         
    }
    else{
        LVACIA;
    }
   
}
