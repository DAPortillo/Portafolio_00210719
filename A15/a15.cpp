#include <iostream>
#include <stdlib.h>
using namespace std;

struct nodo{
    int info;
    struct nodo *izq;
    struct nodo *der;
};
typedef struct nodo Nodo;
typedef struct nodo *Arbol;

Arbol crearArbol(int x){
    Arbol p = new Nodo;
    p->info=x;
    p->izq=NULL;
    p->der=NULL;
    return p;
}

void asignarIzq(Arbol a, int unDato){
    if(a==NULL){
        cout<<"Arbol vacio."<<endl;
    }
    else if(a->izq !=NULL){
        cout<<"subarbol izq no existe."<<endl;
    }
    else{
        a->izq=crearArbol(unDato);
    }
}

void asignarDer(Arbol a, int unDato){
    if(a==NULL){
        cout<<"Arbol vacio"<<endl;
    }
    else if(a->der !=NULL){
        cout<<"subarbol der no existe"<<endl;
    }
    else{
        a->izq = crearArbol(unDato);
    }
}

void agregarNodo(Arbol a){
    int numero=0;
    cout<<"Numero a agregar: ";
    cin>>numero;
    Arbol p =a;
    while(true){
        if(numero==p->info){
            cout<<"Error: "<<numero<<" ya existe"<<endl;
            return;
        }
        else if(numero<p->info){
            if(p->izq==NULL){
                break;
            }
            else{
                p = p->izq;
            }
        }
        else{
            if(p->der==NULL){
                break;
            }
            else{
                p=p->der;
            }
        }
    }
    if(numero<p->info){
        asignarIzq(p, numero);
    }
    else{
        asignarDer(p, numero);
    }
}

void preorden(Arbol a){
    int cont=0;
    if(a != NULL){
        cout<<" "<<a->info;
        preorden(a->izq);
        preorden(a->der);
        while(a->izq!=NULL){
            cont++;
        }
    }
    alturaArbol(Arbol a, cont);
}

void recorrerArbol(Arbol a){
    cout<<"Recorrido PRE orden: "; preorden(a); cout<<endl;
}

int alturaArbol(Arbol a){
    if(a==NULL){
        return 0;
    }
    else{
        int izquierda = alturaArbol(a->izq);
        int derecha = alturaArbol(a->der);
        if(izquierda <= derecha){
            return derecha+1;
        }
        else{
            return izquierda+1;
        }
    }
}

int main(){
    int variable =0;
    cout<<"Valor de la raiz: ";
    cin>>variable;
    
    Arbol arbol = crearArbol(variable);
    
    bool seguir=true;
    do{
        int opcion =0;
        cout<<"Menu"<<endl;
        cout<<"Recorrer preorden"<<endl;
        cout<<"Mostrar Profundidad"<<endl;
        cin>>opcion;
        switch(opcion){
            case 1: recorrerArbol(arbol);
            break;
            case 2: preorden(arbol);
            break;
            case 3: cout<<"Profundidad: "<<alturaArbol(arbol)-1<<endl;
            break;
            case 4: seguir=false;
            break;
            default: cout<<"Opcion Erronea"<<endl;
            break;
        }
    }while(seguir);
    
    return 0;
}
