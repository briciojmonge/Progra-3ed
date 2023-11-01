#ifndef Cliente_H
#define Cliente_H
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <cstdlib>
using namespace std;
class NodoCliente {
public:

    NodoCliente(string nom, int ced) {
        Hizq = nullptr;
        Hder = nullptr;
        nombre = nom;
        siguiente = nullptr;
        anterior = nullptr;
        cedula = ced;
        FB = 0;
    }
    string nombre;
    int cedula;
    int FB;
    NodoCliente* Hizq, * Hder, * siguiente, * anterior;

    void InsertaBinarioCliente(int ced, string nom);

    friend class Pila;
    friend class Cliente;
};

typedef NodoCliente* pnodoc;
typedef NodoCliente* pNodoCliente;

class Cliente {
public:
    pNodoCliente raiz;

    Cliente() { raiz = NULL; }

    void InsertaNodo(string nom, int cedula);
    void PreordenI();
    void InordenI();
    void PostordenI();

    bool ValidarCodCliente(NodoCliente*& R, int ced);
    void setCliente(int ced, string nombre);
    void crearlistaClientes();
    void buscarCliente(NodoCliente* R, int ced);
    void ModificarPais(NodoCliente* R, int codigo);
    void crearlistaAdmin();
};

class Pilo {
public:
    Pilo() { plista = nullptr; }

    void Push(pnodoc);
    void Mostrar();
    bool Vacia() { return plista == nullptr; }
    pnodoc Pop();
    int Size();

    pnodoc plista;
};
void Pilo::Push(pnodoc v)
{
    if (Vacia()) {
        plista = v;
    }
    else {
        NodoCliente* aux = plista;
        while (aux->siguiente) {
            aux = aux->siguiente;
        }
        aux->siguiente = v;
        v->anterior = aux;

    }
}

pnodoc Pilo::Pop()
{
    NodoCliente* borrar;
    NodoCliente* salida;
    if (Vacia()) {
        cout << "Pila Vacia" << endl;
        return nullptr;
    }
    else {
        borrar = plista;
        while (borrar->siguiente) {
            borrar = borrar->siguiente;
        }
        if (Size() > 1) {
            salida = borrar;
            borrar->anterior->siguiente = nullptr;
            borrar = nullptr;
            delete borrar;
        }
        else {
            salida = plista;
            plista = nullptr;
        }
    }
    return salida;
}

int Pilo::Size() {
    while (plista && plista->anterior) plista = plista->anterior;
    int cont = 0;
    NodoCliente* aux;
    aux = plista;
    while (aux) {
        cont++;
        aux = aux->siguiente;
    }
    return cont;
}

void Pilo::Mostrar() {
    if (Vacia()) {
        cout << "Vacia";
    }
    NodoCliente* aux = plista;
    while (aux) {
        cout << aux->nombre << " - ";
        aux = aux->siguiente;
    }
}

void Cliente::PreordenI() {
    NodoCliente* Act = raiz;
    Pilo p;
    while (p.Vacia() == false || (Act != nullptr)) {
        if (Act != nullptr) {
            cout << Act->nombre << " - ";
            p.Push(Act);
            Act = Act->Hizq;
        }
        else {
            Act = p.Pop();
            Act = Act->Hder;
        }
    }
}

void Cliente::InordenI() {
    NodoCliente* Act = raiz;
    Pilo p;
    bool band = true;
    while (band) {

        while (Act != nullptr) {
            p.Push(Act);
            Act = Act->Hizq;
        }
        if (!p.Vacia()) {
            Act = p.Pop();
            cout << Act->nombre << " - ";
            Act = Act->Hder;
        }
        if (p.Vacia() && Act == nullptr) {
            break;
        }
    }
}

void Cliente::PostordenI() {
    NodoCliente* Act = raiz;
    Pilo p;
    Pilo p2;
    while (!p.Vacia() || Act != nullptr) {
        if (Act != nullptr) {
            p2.Push(new NodoCliente(Act->nombre, Act->cedula));
            p.Push(Act);
            Act = Act->Hder;
        }
        else {
            Act = p.Pop();
            Act = Act->Hizq;
        }
    }
    while (!p2.Vacia()) {
        NodoCliente* salida = p2.Pop();
        cout << salida->nombre << " - ";
    }
}

void Cliente::ModificarPais(NodoCliente* R, int ced) {

    int nuevacedula;
    string nuevonombre;



    if (R == nullptr) {
        cout << "\n" << "No esta el codigo para modificar.";
    }
    else {
        if (R->cedula == ced) {
            cout << "Ingrese el nuevo código: ";
            cin >> nuevacedula;

            cout << "Ingrese el nuevo nombre: ";
            cin >> nuevonombre;

            R->cedula = nuevacedula;
            R->nombre = nuevonombre;
        }
        ModificarPais(R->Hder, ced);
        ModificarPais(R->Hizq, ced);
    }
}

void Cliente::buscarCliente(NodoCliente* R, int ced) {

    if (R == nullptr) {
        cout << "\n" << "No hay mas codigos para buscar en esta rama.";
    }
    else {
        if (R->cedula == ced) {
            cout << R->cedula << R->nombre;
        }
        buscarCliente(R->Hizq, ced);
        buscarCliente(R->Hder, ced);
    }
}

string Clientes(string linea) {
    char delimiter = ';';
    int pos = 0;
    string cliente = "";
    while (linea[pos] != delimiter) {
        pos++;
    }
    pos++;
    while (linea[pos]) {
        cliente += linea[pos];
        pos++;
    }
    return cliente;
}

int cedula(string linea) {
    char delimiter = ';';  // toma lo anterior al ; y retorna el codigo de país
    int pos = 0;
    string cod = "";
    while (linea[pos] != delimiter) {
        cod += linea[pos];
        pos++;
    }
    int numcod = stoi(cod);
    return numcod;
}

void Cliente::crearlistaClientes() {
    string str;
    ifstream archivo;
    archivo.open("Clientes.txt");
    while (getline(archivo, str)) {
        string nombre;
        int codigo;
        codigo = cedula(str);
        nombre = Clientes(str);
        setCliente(codigo, nombre);
    }
    archivo.close();
}
void Cliente::crearlistaAdmin() {
    string str;
    ifstream archivo;
    archivo.open("Administradores.txt");
    while (getline(archivo, str)) {
        string nombre;
        int codigo;
        codigo = cedula(str);
        nombre = Clientes(str);
        setCliente(codigo, nombre);
    }
    archivo.close();
}
void Cliente::setCliente(int ced, string nombre) {
    if (!ValidarCodCliente(raiz, ced)) {
        InsertaNodo(nombre, ced);
        cout << "\n" << "Se ha ingresado " << nombre << " correctamente" << "\n";
    }
    else {
        cout << "\n" << "No se ha podido ingresar " << nombre << " porque ya esta el codigo dado" << "\n";
    }
}

bool Cliente::ValidarCodCliente(NodoCliente*& R, int ced) {

    if (R == nullptr) {
        return false;
    }
    else {
        if (R->cedula == ced) {
            return true;
        }
        ValidarCodCliente(R->Hizq, ced);
        ValidarCodCliente(R->Hder, ced);
    }
}

void Cliente::InsertaNodo(string nom, int ced) {
    if (raiz == nullptr) {
        raiz = new NodoCliente(nom, ced);
    }
    else {
        raiz->InsertaBinarioCliente(ced, nom);
    }
}

void NodoCliente::InsertaBinarioCliente(int ced, string nom)
{

    if (ced < cedula) {
        if (Hizq == nullptr) {
            Hizq = new NodoCliente(nom, ced);
        }
        else {
            Hizq->InsertaBinarioCliente(ced, nom);
        }
    }
    else {
        if (Hder == nullptr) {
            Hder = new NodoCliente(nom, ced);
        }
        else {
            Hder->InsertaBinarioCliente(ced, nom);
        }
    }
}

#endif/* Cliente_H */
