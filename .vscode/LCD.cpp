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
        head = nuevo;
        nuevo->next = nuevo;
        nuevo->back= head;
        return;
    }
    Nodo* aux = head;
    while (aux -> next!= head){
        aux = aux->next;
    }
    aux->next = nuevo;
    nuevo->next = head;
    nuevo->back = aux;
}
bool buscar(Nodo* head, int valor){
    if(head==nullptr) return false;
    Nodo* inicio = head;
    Nodo* final = head->back;
    do{
        if(inicio->dato == valor) return true;
        if(final->dato ==valor) return true;
        inicio= inicio->next;
        final=final->back;
    }while(inicio==final || inicio->back ==final);
    return false;
}
void eliminar(Nodo*& head, int valor){
    if(head==nullptr) return;
    Nodo* aux = head;
    bool search = false;
    do{
        if(aux->dato==valor){
            search=true;
            break;
        }
        aux = aux->next;
    }while(aux!=head);
    if(!search){
        cout<<"valor no encontrado"<<endl;
        return;
    }
    if(aux->next==aux){
        delete head;
        head=nullptr;
        return;
    }
    if(aux==head){
        head=head->next;
    }
    aux->back->next=aux->next;
    delete aux;
}
void imprimirLista(Nodo* head) {
    if (head == nullptr) {
        cout << "Lista vacia." << endl;
        return;
    }

    Nodo* temp = head;
    cout << "Lista: ";
    
    do {
        cout << "[" << temp->dato << "] <-> ";
        temp = temp->next;
    } while (temp != head);

    cout << "(vuelve a head)" << endl;
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