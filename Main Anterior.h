#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <limits>
#include <unordered_map>
#include "AA.h"
#include "RN.h"
#include "binario.h"
#include "codigos_nombres.h"
#include "Cliente.h"


using namespace std;
//___________________________espacio de RN_________________________________________________________________________________________________
Binario AVLCiud, AVLProds;
Binario ABB;
ArbolRN RN;
ArbolAA AA;
Cliente ACl;
Cliente ACA;
//           supuestamente el cliente           


//____________________________Codigo de ABB Pais___________________________________________________________________
bool Binario::ValidarCodPais(NodoBinario*& R, int cod) {

    if (raiz == nullptr || R == nullptr) {
        return false;
    }
    else {
        if (R->codpais == cod) {
            return true;
        }
        if (cod > R->codpais) {
            ValidarCodPais(R->Hder, cod);
        }
        else {
            ValidarCodPais(R->Hizq, cod);
        }
    }
}
void Binario::setPais(int codpais, string nombre) {
    if (!ValidarCodPais(raiz, codpais)) {
        InsertaNodo(nombre, codpais);
        cout << "\n" << "Se ha ingresado " << nombre << " correctamente" << "\n";
    }
    else {
        cout << "\n" << "No se ha podido ingresar " << nombre << " porque ya esta el codigo dado" << "\n";
    }
}

void Binario::crearlistapaises() {
    string str;
    ifstream archivo;
    archivo.open("Paises.txt");
    while (getline(archivo, str)) {
        string pais;
        int codigo;
        codigo = stoi(codigos(str));
        pais = paises(str);
        setPais(codigo, pais);
    }
    archivo.close();
}



void Binario::buscarPais(NodoBinario* R, int codigo) {

    if (R == nullptr) {
        cout << "\n" << "No hay codigos para buscar.";
    }
    else {
        if (R->codpais == codigo) {
            cout << R->codpais << R->nombre;
        }
        buscarPais(R->Hizq, codigo);
        buscarPais(R->Hder, codigo);
    }
}


void Binario::ModificarPais(NodoBinario* R, int codigo) {

    int nuevocodigo;
    string nuevonombre;



    if (R == nullptr) {
        cout << "\n" << "No esta el codigo para modificar.";
    }
    else {
        if (R->codpais == codigo) {
            cout << "Ingrese el nuevo nombre: ";
            cin >> nuevonombre;


            R->nombre = nuevonombre;
        }
        ModificarPais(R->Hder, codigo);
        ModificarPais(R->Hizq, codigo);
    }
}
//___________________________codigo de AVl Ciudad______________________________________________________________________________
bool Binario::ValidarCodCiud(NodoBinario*& R, int cod) {

    if (raiz == nullptr || R == nullptr) {
        return false;
    }
    else {
        if (R->codciudad == cod) {
            return true;
        }
        if (cod > R->codciudad) {
            ValidarCodCiud(R->Hder, cod);
        }
        else {
            ValidarCodCiud(R->Hizq, cod);
        }
    }
}

void Binario::setCiud(int codpais, int codciud, string nombre) {
    if (!ValidarCodCiud(raiz, codciud)) {//cambiar esta linea
        InsertarBalanceadociud(raiz, Hh, nombre, codciud, codpais);
        cout << "\n" << "Se ha ingresado " << nombre << " correctamente" << "\n";
    }
    else { cout << "" "\n" << "No se ha podido ingresar " << nombre << " porque ya esta el codigo dado" << "\n"; }
}

void Binario::crearavlciud(Binario& P) {
    string str;
    ifstream archivo;
    archivo.open("Ciudades.txt");
    while (getline(archivo, str)) {
        string nombre;
        int codpais;
        int codciudad;
        string sinpais;
        codpais = stoi(codigos(str));
        sinpais = paises(str);
        codciudad = stoi(codigos(sinpais));
        nombre = paises(sinpais);
        setCiud(codpais, codciudad, nombre);
    }
    archivo.close();
}

void Binario::buscarCiud(NodoBinario* R, int codigo) {

    if (R == nullptr) {
        cout << "\n" << "No hay codigos para buscar.";
    }
    else {
        if (R->codciudad == codigo) {
            cout << R->codciudad << R->nombre;
        }
        buscarCiud(R->Hizq, codigo);
        buscarCiud(R->Hder, codigo);
    }
}

void Binario::ModificarCiud(NodoBinario* R, int codigo) {

    int nuevocodigo, codpaisnuevo;
    string nuevonombre;



    if (R == nullptr) {
        cout << "\n" << "No esta el codigo para modificar.";
    }
    else {
        if (R->codciudad == codigo) {
            cout << "Ingrese el nuevo nombre: ";
            cin >> nuevonombre;


            R->nombre = nuevonombre;
        }
        ModificarCiud(R->Hder, codigo);
        ModificarCiud(R->Hizq, codigo);
    }
}

//_________________________________________codigo AVL Productos________________________________________________________________
bool Binario::ValidarCodProd(NodoBinario*& R, int cod) {

    if (raiz == nullptr || R == nullptr) {
        return false;
    }
    else {
        if (R->codprod == cod) {
            return true;
        }
        if (cod > R->codprod) {
            ValidarCodProd(R->Hder, cod);
        }
        else {
            ValidarCodProd(R->Hizq, cod);
        }
    }
}
void Binario::setProd(int codpais, int codciud, int codres, int codmen, int codp, int calorias, int precio, string nombre) {
    if (!ValidarCodProd(raiz, codp)) {
        InsertarBalanceadoProd(raiz, Hh, nombre, codpais, codciud, codres, codmen, codp, precio, calorias);
        cout << "\n" << "Se ha ingresado " << nombre << " correctamente" << "\n";
    }
    else { cout << "" "\n" << "No se ha podido ingresar " << nombre << " porque ya esta el codigo dado" << "\n"; }
}

void Binario::crearavlprods() {//falta AA
    string str;
    ifstream archivo;
    archivo.open("Productos.txt");
    while (getline(archivo, str)) {
        string nombre;
        int codpais;
        int codciudad;
        int codres, codm, codp, precio, cal;
        string sinpais, sinciud, sinres, sinmen, sinprod, sinnomprod;
        codpais = stoi(codigos(str));
        sinpais = paises(str);
        codciudad = stoi(codigos(sinpais));
        sinciud = paises(sinpais);
        codres = stoi(codigos(sinciud));
        sinres = paises(sinciud);
        codm = stoi(codigos(sinres));
        sinmen = paises(sinres);
        codp = stoi(codigos(sinmen));
        sinprod = paises(sinmen);
        nombre = codigos(sinprod);
        sinnomprod = paises(sinprod);
        cal = stoi(codigos(sinnomprod));
        precio = stoi(paises(sinnomprod));
        setProd(codpais, codciudad, codres, codm, codp, cal, precio, nombre);
    }
    archivo.close();
}
void Binario::buscarProd(NodoBinario* R, int codigo) {

    if (R == nullptr) {
        cout << "\n" << "No hay codigos para buscar.";
    }
    else {
        if (R->codprod == codigo) {
            cout << R->codprod << " Nombre: " << R->nombre << " precio: " << R->precio << " kilocalorias: " << R->kcal;
        }
        buscarProd(R->Hizq, codigo);
        buscarProd(R->Hder, codigo);
    }
}
int Binario::buscarPreccio(NodoBinario* R, int codigo) {

    if (R == nullptr) {
        cout << "\n" << "No hay codigos para buscar.";
    }
    else {
        if (R->codprod == codigo) {
            return R->precio;
        }
        if (codigo > R->codciudad) {
            buscarPreccio(R->Hder, codigo);
        }
        else {
            buscarPreccio(R->Hizq, codigo);
        }
    }
}
string Binario::buscarnombreP(NodoBinario* R, int codigo) {

    if (R == nullptr) {
        cout << "\n" << "No hay codigos para buscar.";
    }
    else {
        if (R->codprod == codigo) {
            return R->nombre;
        }
        if (codigo > R->codciudad) {
            buscarnombreP(R->Hder, codigo);
        }
        else {
            buscarnombreP(R->Hizq, codigo);
        }
    }
}
void Binario::ModificarProd(NodoBinario* R, int codigo) {

    string nuevonombre;
    int kilocal, precionuevo;
    int opcionmod;
    if (R == nullptr) {
        cout << "\n" << "No esta el codigo para modificar.";
    }
    else {
        if (R->codprod == codigo) {
            cout << "quiere modificar el nombre, precio, o las calorias?" << endl;
            cout << "nombre =1, precio = 2, calorias = 3";
            cin >> opcionmod;
            switch (opcionmod) {
            case 01:
                cout << "Ingrese el nuevo nombre: " << endl;
                cin >> nuevonombre;
                R->nombre = nuevonombre;

                system("pause>nul"); // Pausa
                break;
            case 02:
                cout << "Ingrese el nuevo precio:" << endl;
                cin >> precionuevo;
                R->precio = precionuevo;
                system("pause>nul"); // Pausa
                break;
            case 03:
                cout << "Ingrese la nueva cantidad de kilo calorias" << endl;
                cin >> kilocal;
                R->kcal = kilocal;
                system("pause>nul"); // Pausa
                break;
            }
        }
        ModificarProd(R->Hder, codigo);
        ModificarProd(R->Hizq, codigo);
    }
}

//---------------------------codigo de RN Restaurante__________________________________________________________________________

bool ArbolRN::ValidarCodRes(NodoPtr& R, int cod) {

    if (R == nullptr) {
        return false;
    }
    else {

        if (R->valor == cod) {
            return true;
        }
        if (cod > R->valor) {
            ValidarCodRes(R->Hder, cod);
        }
        else { ValidarCodRes(R->Hizq, cod); }
    }
}
void ArbolRN::setRes(int codpais, int codciud, int codres, string nombre) {
    if (!ValidarCodRes(Raiz, codres)) {
        insertar(codres, codpais, codciud, nombre);
        cout << "\n" << "Se ha ingresado " << nombre << " correctamente" << "\n";
    }
    else { cout << "" "\n" << "No se ha podido ingresar " << nombre << " porque ya esta el codigo dado" << "\n"; }
}
void ArbolRN::crearRn() {
    string str;
    ifstream archivo;
    archivo.open("Restaurantes.txt");
    while (getline(archivo, str)) {
        string nombre;
        int codpais;
        int codciudad, codres;
        string sinpais, sinciud;
        codpais = stoi(codigos(str));
        sinpais = paises(str);
        codciudad = stoi(codigos(sinpais));
        sinciud = paises(sinpais);
        codres = stoi(codigos(sinciud));
        nombre = paises(sinciud);
        setRes(codpais, codciudad, codres, nombre);
    }
    archivo.close();
}
void ArbolRN::buscarRest(NodoPtr R, int codigo) {

    if (R == nullptr) {
        cout << "\n" << "No hay codigos para buscar.";
    }
    else {
        if (R->valor == codigo) {
            cout << R->valor << R->nombre;
        }
        buscarRest(R->Hizq, codigo);
        buscarRest(R->Hder, codigo);
    }
}
void ArbolRN::ModificarRest(NodoPtr R, int codigo) {

    int nuevocodigo, codpaisnuevo, codresnuevo;
    string nuevonombre;



    if (R == nullptr) {
        cout << "\n" << "No esta el codigo para modificar.";
    }
    else {
        if (R->valor == codigo) {

            cout << "Ingrese el nuevo nombre: ";
            cin >> nuevonombre;

            R->nombre = nuevonombre;
        }
        ModificarRest(R->Hder, codigo);
        ModificarRest(R->Hizq, codigo);
    }
}
//               AA/
bool ArbolAA::contains(int& key) {
    node* current = root;

    while (current != nullptr)
    {
        if (key < current->codm)
        {
            current = current->left;
        }
        else if (key > current->codm)
        {
            current = current->right;
        }
        else
        {
            return true;
        }
    }
    return false;
}
void ArbolAA::crearAA() {
    string str;
    ifstream archivo;
    archivo.open("Menu.txt");
    while (getline(archivo, str)) {
        string nombre;
        int codpais;
        int codciudad;
        int codres, codm;
        string sinpais, sinciud, sinres;
        codpais = stoi(codigos(str));
        sinpais = paises(str);
        codciudad = stoi(codigos(sinpais));
        sinciud = paises(sinpais);
        codres = stoi(codigos(sinciud));
        sinres = paises(sinciud);
        codm = stoi(codigos(sinres));
        nombre = paises(sinres);
        setMen(codpais, codciudad, codres, codm, nombre);
    }
    archivo.close();
}
void ArbolAA::setMen(int codpais, int codciud, int codres, int codmen, string nombre) {
    if (!contains(codmen)) {
        lookup(nombre, codpais, codciud, codres, codmen);
        cout << "\n" << "Se ha ingresado " << nombre << " correctamente" << "\n";
    }
    else { cout << "" "\n" << "No se ha podido ingresar " << nombre << " porque ya esta el codigo dado" << "\n"; }
}
void ArbolAA::buscarMen(node*& R, int codigo) {

    if (R == nullptr) {
        cout << "\n" << "No hay codigos para buscar.";
    }
    else {
        if (R->codm = codigo) {
            cout << R->codm << " Nombre: " << R->nom << endl;
        }
        buscarMen(R->right, codigo);
        buscarMen(R->left, codigo);
    }
}
//__________________________________Cola de compras_______________________________________________________
class ColaEstatica {
private:
    int tamano;
    int frente, atras;
    int cola[5];

public:
    ColaEstatica() {
        tamano = 5;
        frente = atras = -1;
    }

    bool estaVacia() {
        return frente == -1;
    }

    bool estaLlena() {
        return (atras == tamano - 1 && frente == 0) || (atras + 1 == frente);
    }

    void agregar(int cedula) {
        if (estaLlena()) {
            std::cout << "La cola esta llena. No se pueden agregar mas cedulas." << std::endl;
        }
        else {
            if (frente == -1) {
                frente = 0;
            }
            atras = (atras + 1) % tamano;
            cola[atras] = cedula;
            std::cout << "Cedula " << cedula << " agregada a la cola." << std::endl;
        }
    }

    int eliminar() {
        if (estaVacia()) {
            std::cout << "La cola está vacía. No se pueden eliminar cedulas." << std::endl;
            return -1;
        }
        else {
            int cedula = cola[frente];
            if (frente == atras) {
                frente = atras = -1;
            }
            else {
                frente = (frente + 1) % tamano;
            }
            //std::cout << "Cedula " << cedula << " eliminada de la cola." << std::endl;
            return cedula;
        }
    }

    void buscar(int cedula) {
        if (estaVacia()) {
            std::cout << "La cola esta vacia. No se puede buscar ninguna cedula." << std::endl;
        }
        else {
            int indice = frente;
            while (true) {
                if (cola[indice] == cedula) {
                    std::cout << "Cedula " << cedula << " encontrada en la cola en la posicion " << indice << "." << std::endl;
                    return;
                }
                if (indice == atras) {
                    break;
                }
                indice = (indice + 1) % tamano;
            }
            std::cout << "Cedula " << cedula << " no encontrada en la cola." << std::endl;
        }
    }
};
//________________________________________Lista de facturas_______________________________________________________________________
struct Factura {
    int montoFactura;  // Cambiar el nombre del campo
    int cedula;
    string producto;
    int cantidadProducto;
    Factura* siguiente;

    Factura(int montoFactura, int cedula, string& producto, int cantidadProducto) {
        this->montoFactura = montoFactura;
        this->cedula = cedula;
        this->producto = producto;
        this->cantidadProducto = cantidadProducto;
        this->siguiente = NULL;
    }
};


class ListaFacturas {
private:
    Factura* cabeza;

public:
    ListaFacturas() {
        cabeza = NULL;
    }

    void agregarFactura(int numeroFactura, int cedula, string& producto, int cantidadProducto) {
        Factura* nuevaFactura = new Factura(numeroFactura, cedula, producto, cantidadProducto);
        nuevaFactura->siguiente = cabeza;
        cabeza = nuevaFactura;
    }

    void encontrarFacturaMayorMonto() {
        Factura* facturaMayor = NULL;
        int montoMayor = 0;

        Factura* actual = cabeza;
        while (actual != NULL) {
            int montoFactura = actual->montoFactura;
            if (montoFactura > montoMayor) {
                montoMayor = montoFactura;
                facturaMayor = actual;
            }
            actual = actual->siguiente;
        }

        if (facturaMayor != NULL) {
            std::cout << "Factura de mayor monto: Cedula " << facturaMayor->cedula
                << ", Monto de Factura: " << facturaMayor->montoFactura << std::endl;
        }
        else {
            std::cout << "La lista está vacía." << std::endl;
        }
    }

    void encontrarFacturaMenorMonto() {
        Factura* facturaMenor = NULL;
        int montoMenor = std::numeric_limits<int>::max();

        Factura* actual = cabeza;
        while (actual != NULL) {
            int montoFactura = actual->montoFactura;
            if (montoFactura < montoMenor) {
                montoMenor = montoFactura;
                facturaMenor = actual;
            }
            actual = actual->siguiente;
        }

        if (facturaMenor != NULL) {
            std::cout << "Factura de menor monto: Cedula " << facturaMenor->cedula
                << ", Monto de Factura: " << facturaMenor->montoFactura << std::endl;
        }
        else {
            std::cout << "La lista está vacía." << std::endl;
        }
    }


    void encontrarProductoMasComprado() {
        std::unordered_map<std::string, int> productoCantidad;
        Factura* actual = cabeza;

        while (actual != nullptr) {
            productoCantidad[actual->producto] += actual->cantidadProducto;
            actual = actual->siguiente;
        }

        std::string productoMasComprado;
        int cantidadMasComprada = 0;

        for (const auto& entry : productoCantidad) {
            if (entry.second > cantidadMasComprada) {
                productoMasComprado = entry.first;
                cantidadMasComprada = entry.second;
            }
        }

        if (!productoMasComprado.empty()) {
            std::cout << "Producto más comprado: " << productoMasComprado << std::endl;
        }
        else {
            std::cout << "La lista está vacía." << std::endl;
        }
    }
    void encontrarFacturasPorCedula(int cedulaBuscada) {
        Factura* actual = cabeza;
        bool found = false;

        while (actual != NULL) {
            if (actual->cedula == cedulaBuscada) {
                found = true;
                std::cout << "-----------------------" << std::endl;
                std::cout << "Monto de la Factura: " << actual->montoFactura << std::endl;
                std::cout << "Cédula: " << actual->cedula << std::endl;
                std::cout << "Producto: " << actual->producto << std::endl;
                std::cout << "Cantidad de Producto: " << actual->cantidadProducto << std::endl;
                std::cout << "-----------------------" << std::endl;
            }
            actual = actual->siguiente;
        }

        if (!found) {
            std::cout << "No se encontraron facturas para la cédula " << cedulaBuscada << std::endl;
        }
    }
};
void crearbase() {
    ABB.crearlistapaises();
    AVLCiud.crearavlciud(ABB);
    RN.crearRn();
    AA.crearAA();
    AVLProds.crearavlprods();
    ACl.crearlistaClientes();
    ACA.crearlistaAdmin();
}
//_______________________________________________________
/* int main() {
    int opcion;
    bool repetir = true;
    Binario AVLCiud, AVLProds;
    Binario ABB;
    ArbolRN RN;
    ArbolAA AA;
    Cliente ACl;
    ColaEstatica colacompra;
    ListaFacturas LF;
    int codpais;
    int codciud;
    int codres;
    int codmen, codprod, kilocal, precioprod;
    int cantidad;
    int opcionescompra, opcompra2;
    int cedula;
    int precio2, precio1;
    int opcionextra;
    string nombre;

    do {


        system("cls");

        // Texto del men? que se ver?
        cout << "\n\nMenu de Opciones" << endl;
        cout << "0. Crear base de datos" << endl;
        cout << "01. Insertar Pais" << endl;
        cout << "02. Insertar Ciudad" << endl;
        cout << "03. Buscar Pais" << endl;
        cout << "04. Buscar Ciudad" << endl;
        cout << "05. Modificar Pais" << endl;
        cout << "06. Modificar Ciudad" << endl;
        cout << "07. Insertar Restauante" << endl;
        cout << "10. Buscar Restaurante" << endl;
        cout << "11. Modificar Restaurante" << endl;
        cout << "12. Insertar Menu" << endl;
        cout << "13. Buscar Menu" << endl;
        cout << "14. Insertar Producto" << endl;
        cout << "15. Buscar Producto" << endl;
        cout << "16. Insertar cliente" << endl;
        cout << "17. Buscar Cliente" << endl;
        cout << "18. Insertar Cliente en Fila" << endl;
        cout << "19. Atender Cliente" << endl;
        cout << "20. Mayor monto de compra" << endl;
        cout << "21. Menor monto de compra" << endl;
        cout << "22. Producto más comprado" << endl;
        cout << "23. Reporte Paises" << endl;
        cout << "24. Reporte Ciudades" << endl;
        cout << "25. Reporte Restaurantes" << endl;
        cout << "26. Reporte Menús" << endl;
        cout << "27. Reporte Productos" << endl;
        cout << "28. Reporte Clientes" << endl;
        cout << "29. Reporte compras de clientes" << endl;
        cout << "30. Consultar precio de un producto" << endl;
        cout << "99. Mostrar arboles" << endl;
        cout << "111. SALIR" << endl;

        cout << "\nIngrese una opcion: ";
        std::cin >> opcion;

        switch (opcion) {
        case 0:
            ABB.crearlistapaises();
            AVLCiud.crearavlciud(ABB);
            RN.crearRn();
            AA.crearAA();
            AVLProds.crearavlprods();
            ACl.crearlistaClientes();

            system("pause>nul"); // Pausa
            break;
        case 01:
            cout << "\n" << "Inserte el codigo del pais: ";
            std::cin >> codpais;
            cout << "\n" << "Inserte el nombre del pais: ";
            std::cin >> nombre;
            if (!ABB.ValidarCodPais(ABB.raiz, codpais)) {
                ABB.setPais(codpais, nombre);
            }
            else {
                cout << "No se puede ingresar por que hay un codigo que no existe o el codigo dado ya existe.";
            }

            system("pause>nul"); // Pausa
            break;

        case 02:
            cout << "\n" << "Inserte el codigo del pais: ";
            std::cin >> codpais;
            cout << "\n" << "Inserte el codigo de la ciudad: ";
            std::cin >> codciud;
            cout << "\n" << "Inserte el nombre de la ciudad: ";
            std::cin >> nombre;
            if (ABB.ValidarCodPais(ABB.raiz, codpais) && !AVLCiud.ValidarCodCiud(AVLCiud.raiz, codciud)) {
                AVLCiud.setCiud(codpais, codciud, nombre);
            }
            else {
                cout << "No se puede ingresar por que hay un codigo que no existe o el codigo dado ya existe.";
            }

            system("pause>nul"); // Pausa
            break;
        case 03:
            cout << "\n" << "Inserte el codigo del pais que desea buscar: ";
            std::cin >> codpais;
            ABB.buscarPais(ABB.raiz, codpais);

            system("pause>nul"); // Pausa                
            break;
        case 04:
            cout << "\n" << "Inserte el codigo de la ciudad que desea buscar: ";
            std::cin >> codpais;
            AVLCiud.buscarCiud(AVLCiud.raiz, codpais);

            system("pause>nul"); // Pausa                
            break;
        case 05:
            cout << "inserte el codigo del pa?s" << endl;
            std::cin >> codpais;
            if (ABB.ValidarCodPais(ABB.raiz, codpais)) {
                ABB.ModificarPais(ABB.raiz, codpais);
                cout << "el pa?s se modific? correctamente";
            }
            else {
                cout << "el codigo es invalido";
            }
            system("pause>nul"); // Pausa                
            break;
        case 06:
            cout << "inserte el codigo del pa?s" << endl;
            std::cin >> codpais;
            cout << "inserte el codigo de la ciudad" << endl;
            std::cin >> codciud;
            if (ABB.ValidarCodPais(ABB.raiz, codpais) && AVLCiud.ValidarCodCiud(AVLCiud.raiz, codciud)) {
                AVLCiud.ModificarCiud(AVLCiud.raiz, codciud);
                cout << "la ciudad se modific? correctamente";
            }
            else {
                cout << "el codigo es invalido";
            }
            system("pause>nul"); // Pausa                
            break;
        case 07:
            cout << "\n" << "Inserte el codigo del pais: ";
            std::cin >> codpais;
            cout << "\n" << "Inserte el codigo de la ciudad: ";
            std::cin >> codciud;
            cout << "\n" << "Inserte el codigo del restaurante: ";
            std::cin >> codres;
            cout << "\n" << "Inserte el nombre del restaurante: ";
            std::cin >> nombre;
            if (ABB.ValidarCodPais(ABB.raiz, codpais) && AVLCiud.ValidarCodCiud(AVLCiud.raiz, codciud) && !RN.ValidarCodRes(RN.Raiz, codres)) {
                RN.setRes(codpais, codciud, codres, nombre);
            }
            else {
                cout << "No se puede ingresar por que hay un codigo que no existe o el codigo dado ya existe.";
            }
            system("pause>nul"); // Pausa                
            break;
        case 10:
            cout << "\n" << "Inserte el codigo del restaurante que desea buscar: ";
            std::cin >> codpais;
            RN.buscarRest(RN.Raiz, codpais);

            system("pause>nul"); // Pausa                
            break;
        case 11:
            cout << "inserte el codigo del pa?s" << endl;
            std::cin >> codpais;
            cout << "inserte el codigo de la ciudad" << endl;
            std::cin >> codciud;
            cout << "\n" << "Inserte el codigo del restaurante: ";
            std::cin >> codres;
            if (ABB.ValidarCodPais(ABB.raiz, codpais) && AVLCiud.ValidarCodCiud(AVLCiud.raiz, codciud) && RN.ValidarCodRes(RN.Raiz, codres)) {
                RN.ModificarRest(RN.Raiz, codres);
                cout << "la ciudad se modific? correctamente";
            }
            else {
                cout << "el codigo es invalido";
            }
            system("pause>nul"); // Pausa                
            break;
        case 12:
            cout << "\n" << "Inserte el codigo del pais: ";
            std::cin >> codpais;
            cout << "\n" << "Inserte el codigo de la ciudad: ";
            std::cin >> codciud;
            cout << "\n" << "Inserte el codigo del restaurante: ";
            std::cin >> codres;
            cout << "\n" << "Inserte el codigo del menu:  ";
            std::cin >> codmen;
            cout << "\n" << "Inserte el nombre del Menu: ";
            std::cin >> nombre;
            if (ABB.ValidarCodPais(ABB.raiz, codpais) && AVLCiud.ValidarCodCiud(AVLCiud.raiz, codciud) && RN.ValidarCodRes(RN.Raiz, codres) && !AA.contains(codmen)) {
                AA.setMen(codpais, codciud, codres, codmen, nombre);
            }
            else {
                cout << "No se puede ingresar por que hay un codigo que no existe o el codigo dado ya existe.";
            }
            system("pause>nul"); // Pausa                
            break;
        case 13:
            cout << "\n" << "Inserte el codigo del Menu que desea buscar:  ";
            std::cin >> codmen;
            AA.buscarMen(root, codmen);

            system("pause>nul"); // Pausa                
            break;
        case 14:
            cout << "\n" << "Inserte el codigo del pais: ";
            std::cin >> codpais;
            cout << "\n" << "Inserte el codigo de la ciudad: ";
            std::cin >> codciud;
            cout << "\n" << "Inserte el codigo del restaurante: ";
            std::cin >> codres;
            cout << "\n" << "Inserte el codigo del menu:  ";
            std::cin >> codmen;
            cout << "\n" << "Inserte el codigo del Producto:  ";
            std::cin >> codprod;
            cout << "\n" << "Inserte el nombre del Prducto: ";
            std::cin >> nombre;
            cout << "\n" << "Inserte el precio del producto: ";
            std::cin >> precioprod;
            cout << "\n" << "Inserte las kilo calorias del producto:  ";
            std::cin >> kilocal;
            if (ABB.ValidarCodPais(ABB.raiz, codpais) && AVLCiud.ValidarCodCiud(AVLCiud.raiz, codciud) && RN.ValidarCodRes(RN.Raiz, codres) && AA.contains(codmen) && !AVLProds.ValidarCodProd(AVLProds.raiz, codprod)) {
                AVLProds.setProd(codpais, codciud, codres, codmen, codprod, kilocal, precioprod, nombre);
            }
            else {
                cout << "No se puede ingresar por que hay un codigo que no existe o el codigo dado ya existe.";
            }
            system("pause>nul"); // Pausa                
            break;
        case 15:
            cout << "\n" << "Inserte el codigo del Producto que desea buscar:   ";
            std::cin >> codprod;
            AVLProds.buscarProd(AVLProds.raiz, codprod);

            system("pause>nul"); // Pausa                
            break;
        case 16:
            cout << "\n" << "Inserte la cedula del cliente: ";
            std::cin >> codpais;
            cout << "\n" << "Inserte el nombre del cliente:  ";
            std::cin >> nombre;
            if (!ACl.ValidarCodCliente(ACl.raiz, codpais)) {
                ACl.setCliente(codpais, nombre);
            }
            else {
                cout << "No se puede ingresar por que hay un codigo que no existe o el codigo dado ya existe.";
            }

            system("pause>nul"); // Pausa
            break;
        case 17:
            cout << "\n" << "Inserte el codigo del cliente que desea buscar:  ";
            std::cin >> codpais;
            ACl.buscarCliente(ACl.raiz, codpais);

            system("pause>nul"); // Pausa                
            break;
        case 18:
            cout << "\n" << "Ingrese la cedula del cliente; ";
            std::cin >> codpais;
            if (ACl.ValidarCodCliente(ACl.raiz, codpais)) {
                colacompra.agregar(codpais);
            }
            else {
                cout << "La cédula del cliente está incorrecta";
            }
            system("pause>nul"); // Pausa                
            break;
        case 19:
            cedula = colacompra.eliminar();
            cout << "\n" << "Digite el codigo de su pais: ";
            std::cin >> codpais;
            cout << "\n" << "Digite el codigo de su ciudad: ";
            std::cin >> codciud;
            cout << "\n" << "Digite el codigo de su restaurante: ";
            cin >> codres;
            cout << "\n" << "Digite el codigo del menú: ";
            std::cin >> codmen;
            cout << "\n" << " Digite el codigo de producto a comprar : ";
            std::cin >> codprod;
            // cout << ABB.ValidarCodPais(ABB.raiz, codpais) << AVLCiud.ValidarCodCiud(AVLCiud.raiz, codciud) << RN.ValidarCodRes(RN.Raiz, codres) << AA.contains(codmen) << AVLProds.ValidarCodProd(AVLProds.raiz, codprod);
            if (ABB.ValidarCodPais(ABB.raiz, codpais) && AVLCiud.ValidarCodCiud(AVLCiud.raiz, codciud) && RN.ValidarCodRes(RN.Raiz, codres) && AA.contains(codmen) && AVLProds.ValidarCodProd(AVLProds.raiz, codprod)) {
                cout << "\n" << "Cuantas unidades del producto desea? ";
                cin >> cantidad;
                precioprod = AVLProds.buscarPreccio(AVLProds.raiz, codprod);
                cout << "Desea saber el precio con descuento si paga con tarjeta? 1 para sí ";
                cin >> opcionextra;
                if (opcionextra == 1) {
                    cout << "Se aplica un descuento del 3% a la orden total " << endl;
                    int preciofinal = (precioprod * cantidad) - ((precioprod * cantidad) * 0.03);
                    cout << "El precio con el descuento aplicado es: " << preciofinal << ", y el precio al pagar sin tarjeta es: " << (precioprod * cantidad) - ((precioprod * cantidad) * 0.01) << endl;
                }
                cout << "\n" << "Es para comer en el local o para llevar? " << "\n" << "1 es para comer en el local,y  2 para llevar  ";
                cin >> opcionescompra;
                switch (opcionescompra)
                {
                case 1:
                    cout << "Ha escogido: comer en el local  ";
                    cout << "\n" << "Desea pagar en efectivo o tarjeta: " << "\n" << "1 es para efectivo y 2 para tarjeta  ";
                    cin >> opcompra2;
                    // precioprod = AVLProds.buscarPreccio(AVLProds.raiz, codprod);
                    nombre = AVLProds.buscarnombreP(AVLProds.raiz, codprod);
                    switch (opcompra2)
                    {
                    case 1:
                        precio1 = (precioprod * cantidad) - ((precioprod * cantidad) * 0.01);
                        LF.agregarFactura(precio1, cedula, nombre, cantidad);
                        system("pause>nul"); // Pausa                
                        break;
                    case 2:
                        precio2 = (precioprod * cantidad) - ((precioprod * cantidad) * 0.03);
                        LF.agregarFactura(precio2, cedula, nombre, cantidad);
                        system("pause>nul"); // Pausa                
                        break;
                    default:
                        cout << "la opcion escogida no es valida";
                        system("pause>nul"); // Pausa                
                        break;
                    }
                case 2:
                    cout << "Ha escogido: comida para llevar  ";
                    cout << "\n" << "Desea pagar en efectivo o tarjeta: " << "\n" << "1 es para efectivo y 2 para tarjeta  ";
                    cin >> opcompra2;
                    // precioprod = AVLProds.buscarPreccio(AVLProds.raiz, codprod);
                    nombre = AVLProds.buscarnombreP(AVLProds.raiz, codprod);
                    switch (opcompra2)
                    {
                    case 1:
                        precio1 = (precioprod * cantidad) - ((precioprod * cantidad) * 0.04);
                        LF.agregarFactura(precio1, cedula, nombre, cantidad);
                        system("pause>nul"); // Pausa                
                        break;
                    case 2:
                        precio2 = (precioprod * cantidad) - ((precioprod * cantidad) * 0.06);
                        LF.agregarFactura(precio2, cedula, nombre, cantidad);
                        system("pause>nul"); // Pausa                
                        break;
                    default:
                        cout << "la opcion escogida no es valida";
                        system("pause>nul"); // Pausa                
                        break;
                    }
                default:
                    cout << "la opcion escogida no es valida";
                    break;
                }
            }
            else { cout << "Alguno de los codigos proporcionados es incorrecto"; }

            system("pause>nul"); // Pausa                
            break;
        case 20:
            LF.encontrarFacturaMayorMonto();
            system("pause>nul"); // Pausa                
            break;
        case 21:
            LF.encontrarFacturaMenorMonto();
            system("pause>nul"); // Pausa                
            break;
        case 22:
            LF.encontrarProductoMasComprado();
            system("pause>nul"); // Pausa                
            break;
        case 23:
            ABB.PreordenI();
            system("pause>nul"); // Pausa
            break;
        case 24:
            AVLCiud.PreordenI();
            system("pause>nul"); // Pausa
            break;
        case 25:
            RN.MostrarRN();
            system("pause>nul"); // Pausa
            break;
        case 26:
            AA.print(root);
            system("pause>nul"); // Pausa
            break;
        case 27:
            AVLProds.PreordenI();
            system("pause>nul"); // Pausa
            break;
        case 28:
            ACl.PreordenI();
            system("pause>nul"); // Pausa
            break;
        case 29:
            cout << "Inserte la cedula del cliente:  " << endl;
            cin >> cedula;
            LF.encontrarFacturasPorCedula(cedula);
            system("pause>nul"); // Pausa
            break;
        case 30:
            cout << "Inserte el codigo del producto del cual quiere saber el precio: ";
            cin >> codprod;
            cout << (AVLProds.buscarPreccio(AVLProds.raiz, codprod));
            system("pause>nul"); // Pausa
            break;
        case 99:
            ABB.PreordenI();
            cout << endl;
            AVLCiud.PreordenI();
            cout << endl;
            RN.MostrarRN();
            cout << endl;
            AVLProds.PreordenI();
            system("pause>nul"); // Pausa                
            break;
        case 111:
            repetir = false;
            break;
        default:
            cout << "No tenemos esa opcion." << endl;
            break;
        }
    } while (repetir);
    std::cin.get();

    return (EXIT_SUCCESS);
}*/

