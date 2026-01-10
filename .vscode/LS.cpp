#include <iostream>
#include <vector>
using namespace std;
class Nodo{
    public:
    int dato;
    Nodo* next;

};
// INSERCION
void insertar(Nodo*& head, int valor){
    Nodo* nuevo = new Nodo();
    nuevo->dato = valor;
    nuevo ->next =nullptr;
    if(head == nullptr){
        head = nuevo;
        return;
    }
    Nodo* actual = head;
    while (actual -> next!= nullptr){
        actual = actual->next;
    }
    actual->next = nuevo;
}
//BUSQUEDA
bool buscar(Nodo* cabeza, int valor){
    Nodo* actual = cabeza;
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
    if(head->dato==valor){
        Nodo* aux = head;
        head= head->next;
        delete aux;
        cout <<"Elemento" <<valor<<" eliminado"<<endl;
        return;
    }
    Nodo* actual = head;
    Nodo* anterior = nullptr;
    while(actual != nullptr && actual->dato != valor){
        anterior = actual;
        actual = actual->next;
    }
    if(actual == nullptr){
        cout <<"Elemento " << valor<<" eliminar."<<endl;
        return;
    }
    anterior->next = actual->next; 
    delete actual; 

    cout << "Elemento " << valor << " eliminado" << endl;
}
void imprimirLista(Nodo* head){
    Nodo* aux = head;
    cout<<"Lista: ";
    while(aux != nullptr){
        cout<<"["<< aux->dato<<"]->";
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
        cout << "El valor " << buscar_este_numero << " SI existe en la lista." << endl;
    } else {
        cout << "El valor " << buscar_este_numero << " NO existe." << endl;
    }

 
    eliminar(lista, 20); 
    imprimirLista(lista);
    return 0;


}

