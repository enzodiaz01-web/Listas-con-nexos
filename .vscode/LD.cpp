#include <iostream>
#include <vector>
using namespace std;
class Nodo{
    public:
    int dato;
    Nodo* next;
    Nodo*back;
};
void insertar(Nodo*& head, int valor){
    Nodo* nuevo = new Nodo();
    nuevo->dato = valor;
    nuevo ->next =nullptr;

    if(head == nullptr){
        nuevo->back=nullptr;
        head = nuevo;
        return;
    }
    Nodo* actual = head;
    while (actual -> next!= nullptr){
        actual = actual->next;
    }
    actual->next = nuevo;
    nuevo->back = actual;
}

//BUSQUEDA
bool buscar(Nodo* head, int valor){
    Nodo* actual = head;
    while(actual != nullptr){
        if(actual->dato==valor){
            return true;
        }
        actual = actual->next;
    }
    return false;
}
//ELIMINACION
void eliminar(Nodo*& head, int valor){
    if(head == nullptr) return;
    Nodo* aux = head;
    while(aux!=nullptr && aux->dato!=valor){
        aux=aux->next;
    }if (aux == nullptr) return;
    if(aux->back!=nullptr){
        aux->back->next=aux->next;
    }else{
        head=aux->next;
    }
    if(aux->next!=nullptr){
        aux->next->back=aux->back;
    }
    delete aux;
}
void imprimirLista(Nodo* head){
    Nodo* aux = head;
    cout<<"Lista: ";
    while(aux != nullptr){
        cout<<"["<< aux->dato<<"]<->";
        aux = aux->next;
    }
    cout<<"Null"<<endl;
}
int main(){
    Nodo* lista= nullptr;
    insertar(lista,10);
    insertar(lista,20);
    insertar(lista,30);
    insertar(lista,40);

    imprimirLista(lista);
    int buscar_este_numero= 10;
    if(buscar(lista,buscar_este_numero)){
        cout << "El valor " << buscar_este_numero << " SI existe en la lista doble." << endl;
    } else {
        cout << "El valor " << buscar_este_numero << " NO existe." << endl;
    }

 
    eliminar(lista, 20); 
    imprimirLista(lista);
    return 0;


}