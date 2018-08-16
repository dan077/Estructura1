#include<iostream>
#include <stdlib.h>
using namespace std;

struct nodo{
	int dato;
	nodo *sgt;	
};

nodo *head = NULL,*tail = NULL;
//funciones que retornan
nodo* NewNodo(nodo*&);
nodo* buscar(nodo*&,int);
//funciones vacias.
void add4head(int ,nodo*&);
void mostrar(nodo*&);
void add4tail(int , nodo*& , nodo*& );
void borrar(nodo*&,int);
void rotarListaIzq(nodo*&,nodo*&);
void rotarListaDer(nodo*&,nodo*&);

int main(){
    
	//add4head(5,head);
//	add4head(7,head);
//	add4head(3,head);
	mostrar(head);
	add4tail(1,head,tail);
	//add4tail(2,head,tail);
	//add4tail(3,head,tail);
	rotarListaIzq(head,tail);
	//borrar(head,7);
	//borrar(head,5);
    mostrar(head);
    
    //nodo* busqueda = buscar(head,0);
    //busqueda? cout << "se encontro el dato: " << busqueda->dato << '\n' : cout << "No se encontro el dato" << '\n';



system ("pause");
return 0;
}
/*
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
}*/

nodo* NewNodo(nodo*& A_head){
	nodo *New;
	New = (struct nodo*)malloc(sizeof(nodo));//se crea el nuevo nodo
	//esto es igual si es por cabeza o por cola
	if(A_head == NULL){
		A_head = (struct nodo*)malloc(sizeof(nodo)); //se crea el nodo cabeza
        A_head->sgt = New;//
		New->sgt = A_head;
	}
	
	return New;
}

void add4head(int dato,nodo*& A_Head){
    //como no podia saber si era la primera ejecucion cree esta variable auxiliar para saber si antes de hacer la operacion era NULL o NO
    nodo* Aux = A_Head;
	nodo *New = NewNodo(A_Head);
	New->dato = dato;
	
	if(Aux){
	   New->sgt = A_Head->sgt;
	   A_Head->sgt = New;
    }

}

void add4tail(int dato, nodo*& A_Head, nodo*& Tail){
    /*
        este algoritmo puede temer mejoras obviamente quedaria de orden lineal si al crear el nodo le agrego inmediatamente
        la cola. pero el fin , es que pueda ser compatible cuando hay ingresos por cola y por cabeza.
        el algoritmo solo recorre la lista 1 solavez buscando la cola. es decir , en el peor de los casos
        se entra al ciclo 1 vez en todo el algoritmo.
    
    */
    nodo* aux = A_Head; //guardo si la cabeza era NULL
    nodo *New = NewNodo(A_Head);
    New->dato = dato;
    //si la lista es diferente de NULL y apenas se ha creado por primera vez un nodo
    //se procede a creear la cola.
    if(!aux){
        Tail = A_Head->sgt;
    }
    //si la cabeza tiene mas de un dato se agrega por cola .
    else{
        //Esto por si se habia agregado de primero un dato por cabeza (solucion a incompatibilidad).
        if(Tail == NULL){
            for(;aux->sgt != A_Head; aux = aux->sgt);
            Tail = aux;
        }
        Tail->sgt = New;
        New->sgt = A_Head;
        Tail = New;
    }
    
}

void mostrar(nodo*& A_Head){
    nodo *Aux;
	if(A_Head != NULL){
	    Aux = A_Head;
		Aux = Aux->sgt;
		cout << "[Cabeza]->";
		while(Aux != A_Head){
			cout << '[' << Aux->dato << "]->";
			Aux = Aux->sgt;
		}
		cout << "[Cabeza]\n";
	}
}

nodo* buscar(nodo*& A_Head, int dato){
    if(A_Head){
        nodo* aux = A_Head->sgt;
        while(aux != A_Head){
            if(aux->dato == dato){
                return aux;
            }
            aux = aux->sgt;
        }
        return NULL;
    }
}

void borrar(nodo*& A_Head,int dato){

    if(A_Head){
        nodo* aux =  A_Head->sgt;
        if(aux->sgt == A_Head and aux->sgt->dato == dato){
            aux->sgt = NULL;
            free(aux);
            free(A_Head);
            A_Head = NULL;
            //Tail = NULL (si es por cola)
        }
        else{
            nodo* anterior = A_Head;
            while(aux != head and aux->dato != dato){
                anterior = aux;
                aux = aux->sgt;
            }
            if(aux->dato == dato){
                anterior->sgt = aux->sgt;
                free(aux);
            }
            else{
                cout << "El Dato no se encontro\n";
            }
        }
    }
}

void rotarListaIzq(nodo*& A_Head, nodo*& A_Tail){
	if(A_Head){
		nodo* SegundoDato = A_Head->sgt->sgt;
		nodo* PrimerDato = A_Head->sgt;
		if(PrimerDato->sgt != A_Head){
			A_Head->sgt = SegundoDato;
			A_Tail->sgt = PrimerDato;
			PrimerDato->sgt = A_Head;
			A_Tail = PrimerDato;	
		}

	}

}

