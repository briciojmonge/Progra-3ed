#ifndef codigos_nombres_H
#define codigos_nombres_H
#include <iostream>
#include <string>
using namespace std;
string codigos(string linea) {
    char delimiter = ';';  // toma lo anterior al ; y retorna el codigo de país
    int pos = 0;
    string cod = "";
    while (linea[pos] != delimiter) {
        cod += linea[pos];
        pos++;
    }
    return cod;
}

string paises(string linea) {
    char delimiter = ';';
    int pos = 0;
    string pais = "";
    while (linea[pos] != delimiter) {
        pos++;
    }
    pos++;
    while (linea[pos]) {
        pais += linea[pos];
        pos++;
    }
    return pais;
}
#endif /* codigos_nombres_H */