#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <conio.h>
#define listEmpty ((const unsigned char *)"The list is empty\n")
using namespace std;

struct nodo{
    int data;
    struct nodo *next;
};

struct nodo *head = NULL, *tail, *aux, *aux2;

void addToHead(int);
void addToTail(int);
void print();
void del(int);
void search(int);
void menu();
void see();

int main(){
    
    menu();
    return 0;
}

void addToHead(int data){
    aux = (struct nodo*)malloc(sizeof(struct nodo));
    aux->data = data;
   
    if(head == NULL){
        head = aux;
        head->next = head;
        tail = head;
    }
    else{
        aux->next = head;
        head = aux;    
        tail->next = head;
    }
}

void addToTail(int data){
    aux = (struct nodo*)malloc(sizeof(struct nodo));
    aux->data = data;
    if(head == NULL){
        head = aux;
        head->next = head;
        tail = head;
    }
    else{
       tail->next = aux;
       aux->next = head;
       tail = aux;
    }
}

void print(){
    aux = head;
    if(aux != NULL){
        do{
            cout << "Data found: " << aux->data << '\n';
            aux = aux->next;
        }while(aux != head);
    }
    else{
        cout << listEmpty;
    }
}

void del(int data){
    aux = head;
    int sw = 0;
    if(aux != NULL){        
        if(aux->data == data){
            if(aux == head){
                //como es un circulo , si se apunta a si mismo entonces solo hay un valor en la lista
                if(aux->next != head){
                    head = head->next;
                    tail->next = head;
                    aux->next = NULL;
                    free(aux);
                }
                else{
                    head = NULL;
                    tail = NULL;
                }
            }
            cout << "The data is been deleted succesfull\n";
        }
        else{
            do{
                if(aux->data == data){
                    sw = 1;
                }else{
                    aux2 = aux;
                    aux = aux->next; 
                }

            }while(aux != head and sw == 0);
                
            if(sw){
                if(aux == tail){
                    aux2->next = head;
                    tail = aux2;
                    aux->next = NULL;
                    free(aux);
                }
                else{
                    aux2->next = aux->next;
                    aux->next = NULL;
                    free(aux);
                }
                cout << "The data is been deleted succesfull";
            }
            else{
                cout << "--OOPS!-- The data to be deleted was not found\n";
            }
            }
        
    }
    else{
        cout << listEmpty;
    }
}

void search(int data){
    aux = head;
    int sw = 0;
    if(aux != NULL){
        do{
            if(aux->data == data){
                sw++;
            }
            else{
                aux = aux->next;
            }
        }while(aux != head and sw == 0);
        
        if(!sw){
            cout << "No ";
        }
        cout << "found in the list\n";
    }
    else{
        cout << listEmpty;
    }
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
    	printf("\t\t?     4 -> Buscar                                                           ?\n");
    	printf("\t\t?                                                                           ?\n");
    	printf("\t\t?     5 -> Eliminar                                                         ?\n");
     	printf("\t\t?                                                                           ?\n");
    	printf("\t\t?     6 -> Ver comportamiento de la lista                                   ?\n");
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
                addToHead(a);
                system("pause");
                break;
            case '2':
                cout << "ingrese el dato: "; cin >> a; 
                addToTail(a);
                system("pause");
                break;
            case '3':
                print();
                system("pause");
                break;
            case '4':
                cout << "ingrese el dato a buscar: "; cin >> a; 
                search(a);
                system("pause");
                break;
            case '5':
                cout << "ingrese el dato a eliminar: "; cin >> a; 
                del(a);
                system("pause");
                break;
            case '6':
                see();
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

void see(){
    aux = head;
    if(aux == NULL){
        cout << "NULL\n";
    }
    else{
        cout << "START: ";
        do{
            cout << aux->data << " => ";
            aux = aux->next;
        }while(aux != head);
        cout << " Repeat.\n";
    }
}


