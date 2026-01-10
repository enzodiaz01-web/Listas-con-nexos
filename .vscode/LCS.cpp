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
        nuevo->next = nuevo;
        return;
    }
    Nodo* aux = head;
    while (aux -> next!= head){
        aux = aux->next;
    }
    aux->next = nuevo;
    nuevo->next = head;
}
//BUSQUEDA
bool buscar(Nodo* head, int valor){
    if(head == nullptr) return false;
    Nodo* aux = head;
    do{
        if(aux->dato==valor){
            return true;
        }
        aux = aux->next;
    }while(aux != head);
    return false;
}
//ELIMINACION
void eliminar(Nodo*& head, int valor){
    if(head == nullptr) return;
    if(head->dato==valor){
        if(head->next==head){
            delete head;
            head=nullptr;
            cout <<"Elemento" <<valor<<" eliminado"<<endl;
            return;
        }
        Nodo* last = head;
        while(last->next!=head){
            last = last ->next;
        }
        Nodo* temp = head;
        head = head->next;
        last->next=head;
        delete temp;
        cout<<"Elemento " <<valor<<" eliminado"<<endl;
        return;

    }
    Nodo* aux = head->next;
    Nodo* anterior = head;
    while(aux != head && aux->dato != valor){
        anterior = aux;
        aux = aux->next;
    }
    if(aux == head){
        cout <<"Elemento " << valor<<" eliminar."<<endl;
        return;
    }
    anterior->next = aux->next; 
    delete aux; 
    cout << "Elemento " << valor << " eliminado" << endl;
}
void imprimirLista(Nodo* head){
    if(head==nullptr){
        cout<<"lista vacia"<<endl;
        return;
    } 
    Nodo* aux = head;
    cout<<"Lista: ";
    do{
        cout<<"["<< aux->dato<<"]->";
        aux = aux->next;
    }while(aux != head);
    cout<<"vuelve a head"<<endl;
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