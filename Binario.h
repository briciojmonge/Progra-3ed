#ifndef Bin_H
#define Bin_H
#include <iostream>
#include <string>
using namespace std;
class NodoBinario {
public:

    NodoBinario(string nom, int codpa) {
        Hizq = nullptr;
        Hder = nullptr;
        nombre = nom;
        siguiente = nullptr;
        anterior = nullptr;
        codpais = codpa;
        FB = 0;
    }

    NodoBinario(string nom, int codpa, int codciud) {
        Hizq = nullptr;
        Hder = nullptr;
        nombre = nom;
        siguiente = nullptr;
        anterior = nullptr;
        codpais = codpa;
        codciudad = codciud;
        FB = 0;
    }
    NodoBinario(string nom, int codpa, int codciud, int codr, int codm, int codp, int pre, int kcl) {
        Hizq = nullptr;
        Hder = nullptr;
        nombre = nom;
        siguiente = nullptr;
        anterior = nullptr;
        codpais = codpa;
        codciudad = codciud;
        codres = codr;
        codprod = codp;
        precio = pre;
        kcal = kcl;
        FB = 0;
    }


    string nombre;
    int codpais;
    int codciudad;
    int codprod;
    int codmenu;
    int codres;
    int precio;
    int kcal;
    int FB;
    NodoBinario* Hizq, * Hder, * siguiente, * anterior;

    void InsertaBinariopais(int codpa, string nom);
    void PreordenR(NodoBinario* R);
    void InordenR(NodoBinario* R);
    void PostordenR(NodoBinario* R);



    friend class Pila;
    friend class Binario;
};

typedef NodoBinario* pnodo;
typedef NodoBinario* pNodoBinario;

class Binario {
public:
    pNodoBinario raiz;

    Binario() { raiz = NULL; }

    void InsertaNodo(string nom, int codpa);
    void PreordenI();
    void InordenI();
    void PostordenI();


    //_________________________hasta aqui arboles normales_____________________
    bool Hh;

    void Borrar(NodoBinario* nodoB, bool);
    void BorrarBalanceado(NodoBinario* r, bool hh, int eliminar);
    void Equilibrar1(NodoBinario* n, bool hh);
    void Equilibrar2(NodoBinario* n, bool hh);
    void InsertarBalanceadociud(pNodoBinario& ra, bool Hh, string nom, int codciud, int codpa);
    void InsertarBalanceadoProd(pNodoBinario& ra, bool Hh, string nom, int codpa, int codciud, int codr, int codm, int codp, int pre, int kcl);
    void RotacionDobleIzquierda(NodoBinario* n1, NodoBinario* n2);
    void RotacionDobleDerecha(NodoBinario* n1, NodoBinario* n2);
    void RotacionSimpleIzquierda(NodoBinario* n1, NodoBinario* n2);
    void RotacionSimpleDerecha(NodoBinario* n1, NodoBinario* n2);
    // _________________________________AVL___________________________________
//___________________________________________________________________________________
    void setCiud(int codpais, int codciud, string nombre);
    bool ValidarCodCiud(NodoBinario*& R, int cod);
    void crearavlciud(Binario& P);
    bool ValidarCodPais(NodoBinario*& R, int cod);
    void setPais(int codpais, string nombre);
    void crearlistapaises();
    void buscarPais(NodoBinario* R, int codigo);
    void buscarCiud(NodoBinario* R, int codigo);
    void ModificarPais(NodoBinario* R, int codigo);
    void ModificarCiud(NodoBinario* R, int codigo);
    bool ValidarCodProd(NodoBinario*& R, int cod);
    void buscarProd(NodoBinario* R, int codigo);
    void ModificarProd(NodoBinario* R, int codigo);
    void setProd(int codpais, int codciud, int codres, int codmen, int codp, int calorias, int precio, string nombre);
    void crearavlprods();
    int buscarPreccio(NodoBinario* R, int codigo);
    string buscarnombreP(NodoBinario* R, int codigo);
};

/*void Binario::Borrar(NodoBinario* D, bool Hh)
{
    NodoBinario* q = NULL;
    if (D->Hder != nullptr) {
        Borrar(D->Hder, Hh);
        if (Hh) {
            Equilibrar2(D, Hh);
        }
        else {
            q->valor = D->valor;
            q = D;
            D = D->Hizq;
            Hh = true;
        }
    }
}

void Binario::BorrarBalanceado(NodoBinario* raiz, bool Hh, int x)
{
    NodoBinario* q = NULL;
    if (raiz != nullptr) {
        if (x < raiz->codpais) {
            BorrarBalanceado(raiz->Hizq, Hh, x);
            if (Hh) {
                Equilibrar1(raiz, Hh);
            }
        }
        else {
            if (x > raiz->codpais) {
                BorrarBalanceado(raiz->Hder, Hh, x);
                if (Hh) {
                    Equilibrar2(raiz, Hh);
                }
            }
            else {
                q = raiz;
            }
        }

        if (q->Hder == nullptr) {
            raiz = q->Hizq;
            Hh = true;
        }
        else {
            if (q->Hizq == nullptr) {
                raiz = q->Hder;
                Hh = true;
            }
            else {
                Borrar(q->Hizq, Hh);
            }
            if (Hh) {
                Equilibrar1(raiz, Hh);
            }
        }
    }
}*/

void Binario::Equilibrar1(NodoBinario* n, bool Hh) {
    NodoBinario* n1;
    switch (n->FB) {
    case -1: n->FB = 0;
        break;
    case 0: n->FB = 1;
        Hh = false;
        break;
    case 1: n1 = n->Hder;
        if (n1->FB >= 0) {
            if (n1->FB = 0) {
                Hh = false;
                RotacionSimpleDerecha(n, n1);
            }
            else {
                RotacionDobleDerecha(n, n1);
            }
        }
    }
}

void Binario::Equilibrar2(NodoBinario* n, bool Hh) {
    NodoBinario* n1;
    switch (n->FB) {
    case 1: n->FB = 0;
        break;
    case 0: n->FB = 1;
        Hh = false;
        break;
    case -1: n1 = n->Hizq;
        if (n1->FB <= 0) {
            if (n1->FB = 0) {
                Hh = false;
                RotacionSimpleIzquierda(n, n1);
            }
            else {
                RotacionDobleIzquierda(n, n1);
            }
        }
    }
}

void Binario::InsertarBalanceadociud(pNodoBinario& ra, bool Hh, string nom, int codciud, int codpa) {
    pNodoBinario n1;

    if (ra == nullptr) {
        //cout << "raiznula" << endl;
        ra = new NodoBinario(nom, codpa, codciud);
        //cout << ra->nombre << "q as" << endl;
        Hh = true;
    }
    else {
        //cout << "q as2" << endl;
        if (codciud < ra->codciudad) {
            InsertarBalanceadociud(ra->Hizq, Hh, nom, codciud, codpa);

            if (Hh) {
                switch (ra->FB) {
                case 1: ra->FB = 0;
                    Hh = false;
                    break;
                case 0: ra->FB = -1;
                    break;
                case -1: n1 = ra->Hizq;
                    if (n1->FB = -1) {
                        RotacionSimpleIzquierda(ra, n1);
                    }
                    else {
                        RotacionDobleIzquierda(ra, n1);
                    }
                    Hh = false;
                    break;
                }
            }
        }
        else {
            if (codciud > ra->codciudad) {
                InsertarBalanceadociud(ra->Hder, Hh, nom, codciud, codpa);

                if (Hh) {
                    switch (ra->FB) {
                    case -1: ra->FB = 0;
                        Hh = false;
                        break;
                    case 0: ra->FB = 1;
                        break;
                    case 1:n1 = ra->Hder;
                        if (n1->FB = 1) {
                            RotacionSimpleDerecha(ra, n1);
                        }
                        else {
                            RotacionDobleDerecha(ra, n1);
                        }
                        Hh = false;
                        break;
                    }
                }
            }
        }
    }
}

void Binario::InsertarBalanceadoProd(pNodoBinario& ra, bool Hh, string nom, int codpa, int codciud, int codr, int codm, int codp, int pre, int kcl) {
    pNodoBinario n1;

    if (ra == nullptr) {
        ra = new NodoBinario(nom, codpa, codciud, codr, codm, codp, pre, kcl);
        Hh = true;
    }
    else {
        if (codciud < ra->codprod) {
            InsertarBalanceadoProd(ra->Hizq, Hh, nom, codpa, codciud, codr, codm, codp, pre, kcl);
            if (Hh) {
                switch (ra->FB) {
                case 1: ra->FB = 0;
                    Hh = false;
                    break;
                case 0: ra->FB = -1;
                    break;
                case -1: n1 = ra->Hizq;
                    if (n1->FB = -1) {
                        RotacionSimpleIzquierda(ra, n1);
                    }
                    else {
                        RotacionDobleIzquierda(ra, n1);
                    }
                    Hh = false;
                    break;
                }
            }
        }
        else {
            if (codciud > ra->codprod) {
                InsertarBalanceadoProd(ra->Hder, Hh, nom, codpa, codciud, codr, codm, codp, pre, kcl);
                if (Hh) {
                    switch (ra->FB) {
                    case -1: ra->FB = 0;
                        Hh = false;
                        break;
                    case 0: ra->FB = 1;
                        break;
                    case 1:n1 = ra->Hder;
                        if (n1->FB = 1) {
                            RotacionSimpleDerecha(ra, n1);
                        }
                        else {
                            RotacionDobleDerecha(ra, n1);
                        }
                        Hh = false;
                        break;
                    }
                }
            }
        }
    }
}

void Binario::RotacionDobleIzquierda(NodoBinario* n, NodoBinario* n1) {
    NodoBinario* n2;
    n2 = n1->Hder;
    n->Hizq = n2->Hder;
    n2->Hder = n;
    n1->Hder = n2->Hizq;
    n2->Hizq = n1;

    if (n2->FB == 1) {
        n1->FB = -1;
    }
    else {
        n1->FB = 0;
    }
    if (n2->FB == -1) {
        n->FB = 1;
    }
    else {
        n->FB = 0;
    }
    n2->FB = 0;
    n = n2;
}

void Binario::RotacionDobleDerecha(NodoBinario* n, NodoBinario* n1) {
    NodoBinario* n2;
    n2 = n1->Hizq;
    n->Hder = n2->Hizq;
    n2->Hizq = n;
    n1->Hizq = n2->Hder;
    n2->Hder = n1;

    if (n2->FB == 1) {
        n->FB = -1;
    }
    else {
        n->FB = 0;
    }
    if (n2->FB == -1) {
        n1->FB = 1;
    }
    else {
        n1->FB = 0;
    }
    n2->FB = 0;
    n = n2;
}

void Binario::RotacionSimpleDerecha(NodoBinario* n, NodoBinario* n1) {
    n->Hder = n1->Hizq;
    n1->Hizq = n;

    if (n1->FB == 1) {
        n->FB = 0;
        n1->FB = 0;
    }
    else {
        n->FB = 1;
        n1->FB = -1;
    }
    n = n1;
}

void Binario::RotacionSimpleIzquierda(NodoBinario* n, NodoBinario* n1) {
    n->Hizq = n1->Hder;
    n1->Hder = n;

    if (n1->FB == -1) {
        n->FB = 0;
        n1->FB = 0;
    }
    else {
        n->FB = -1;
        n1->FB = -1;
    }
    n = n1;
}
class Pila {
public:
    Pila() { plista = nullptr; }

    void Push(pnodo);
    void Mostrar();
    bool Vacia() { return plista == nullptr; }
    pnodo Pop();
    int Size();

    pnodo plista;
};
void Pila::Push(pnodo v)
{
    if (Vacia()) {
        plista = v;
    }
    else {
        NodoBinario* aux = plista;
        while (aux->siguiente) {
            aux = aux->siguiente;
        }
        aux->siguiente = v;
        v->anterior = aux;

    }
}

pnodo Pila::Pop()
{
    NodoBinario* borrar;
    NodoBinario* salida;
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

int Pila::Size() {
    while (plista && plista->anterior) plista = plista->anterior;
    int cont = 0;
    NodoBinario* aux;
    aux = plista;
    while (aux) {
        cont++;
        aux = aux->siguiente;
    }
    return cont;
}

void Pila::Mostrar() {
    if (Vacia()) {
        cout << "Vacia";
    }
    NodoBinario* aux = plista;
    while (aux) {
        cout << aux->nombre << " - ";
        aux = aux->siguiente;
    }
}

void NodoBinario::InsertaBinariopais(int codpa, string nom)
{

    if (codpa < codpais) {
        if (Hizq == nullptr) {
            Hizq = new NodoBinario(nom, codpa);
        }
        else {
            Hizq->InsertaBinariopais(codpa, nom);
        }
    }
    else {
        if (Hder == nullptr) {
            Hder = new NodoBinario(nom, codpa);
        }
        else {
            Hder->InsertaBinariopais(codpa, nom);
        }
    }
}

void Binario::InsertaNodo(string nom, int codpa) {
    if (raiz == nullptr) {
        raiz = new NodoBinario(nom, codpa);
    }
    else {
        raiz->InsertaBinariopais(codpa, nom);
    }
}

void Binario::PreordenI() {
    NodoBinario* Act = raiz;
    Pila p;
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

void Binario::InordenI() {
    NodoBinario* Act = raiz;
    Pila p;
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

void Binario::PostordenI() {
    NodoBinario* Act = raiz;
    Pila p;
    Pila p2;
    while (!p.Vacia() || Act != nullptr) {
        if (Act != nullptr) {
            p2.Push(new NodoBinario(Act->nombre, Act->codpais, Act->codciudad));
            p.Push(Act);
            Act = Act->Hder;
        }
        else {
            Act = p.Pop();
            Act = Act->Hizq;
        }
    }
    while (!p2.Vacia()) {
        NodoBinario* salida = p2.Pop();
        cout << salida->nombre << " - ";
    }
}

void NodoBinario::PreordenR(NodoBinario* R) {

    if (R == nullptr) {
        return;
    }
    else {
        cout << R->nombre << " - ";
        PreordenR(R->Hizq);
        PreordenR(R->Hder);
    }
}

void NodoBinario::InordenR(NodoBinario* R) {

    if (R == nullptr) {
        return;
    }
    else {
        InordenR(R->Hizq);
        cout << R->nombre << " - ";
        InordenR(R->Hder);
    }
}

void NodoBinario::PostordenR(NodoBinario* R) {

    if (R == nullptr) {
        return;
    }
    else {
        PostordenR(R->Hizq);
        PostordenR(R->Hder);
        cout << R->nombre << " - ";
    }
}
#endif /* Bin_H */
