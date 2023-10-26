#ifndef RN_H// include guard
#define RN_H 
#include <iostream>
#include <iostream>
#include <string>
using namespace std;

class Nodo {
    int codpais;
    int codciud;
    int valor; // codrest
    string nombre;
    Nodo* padre;
    Nodo* Hizq;
    Nodo* Hder;
    int color;

    friend class ArbolRN;
};

typedef Nodo* NodoPtr;

class ArbolRN {
private:

    NodoPtr TNULL;

    void initializeNULLNode(NodoPtr nodo, NodoPtr padre) {
        nodo->valor = 0;
        nodo->padre = padre;
        nodo->Hizq = NULL;
        nodo->Hder = NULL;
        nodo->color = 0;
    }

    // Preorder
    void preOrden(NodoPtr nodo) {
        if (nodo != TNULL) {
            cout << nodo->valor << " ";
            preOrden(nodo->Hizq);
            preOrden(nodo->Hder);
        }
    }

    // Inorder
    void inOrden(NodoPtr nodo) {
        if (nodo != TNULL) {
            inOrden(nodo->Hizq);
            cout << nodo->valor << " ";
            inOrden(nodo->Hder);
        }
    }

    // Post order
    void postOrden(NodoPtr nodo) {
        if (nodo != TNULL) {
            postOrden(nodo->Hizq);
            postOrden(nodo->Hder);
            cout << nodo->valor << " ";
        }
    }

    NodoPtr Busqueda(NodoPtr nodo, int numbuscado) {
        if (nodo == TNULL || numbuscado == nodo->valor) {
            return nodo;
        }

        if (numbuscado < nodo->valor) {
            return Busqueda(nodo->Hizq, numbuscado);
        }
        return Busqueda(nodo->Hder, numbuscado);
    }

    /* // For balancing the tree after deletion
     void deleteFix(NodePtr x) {
       NodePtr s;
       while (x != root && x->color == 0) {
         if (x == x->parent->left) {
           s = x->parent->right;
           if (s->color == 1) {
             s->color = 0;
             x->parent->color = 1;
             leftRotate(x->parent);
             s = x->parent->right;
           }

           if (s->left->color == 0 && s->right->color == 0) {
             s->color = 1;
             x = x->parent;
           } else {
             if (s->right->color == 0) {
               s->left->color = 0;
               s->color = 1;
               rightRotate(s);
               s = x->parent->right;
             }

             s->color = x->parent->color;
             x->parent->color = 0;
             s->right->color = 0;
             leftRotate(x->parent);
             x = root;
           }
         } else {
           s = x->parent->left;
           if (s->color == 1) {
             s->color = 0;
             x->parent->color = 1;
             rightRotate(x->parent);
             s = x->parent->left;
           }

           if (s->right->color == 0 && s->right->color == 0) {
             s->color = 1;
             x = x->parent;
           } else {
             if (s->left->color == 0) {
               s->right->color = 0;
               s->color = 1;
               leftRotate(s);
               s = x->parent->left;
             }

             s->color = x->parent->color;
             x->parent->color = 0;
             s->left->color = 0;
             rightRotate(x->parent);
             x = root;
           }
         }
       }
       x->color = 0;
     }*/

    void rbModificar(NodoPtr uRaiz, NodoPtr vValor) {
        if (Raiz->padre == NULL) {
            Raiz = vValor;
        }
        else if (uRaiz == uRaiz->padre->Hizq) {
            uRaiz->padre->Hizq = vValor;
        }
        else {
            uRaiz->padre->Hder = vValor;
        }
        vValor->padre = uRaiz->padre;
    }

    /*void deleteNodeHelper(NodePtr node, int key) {
      NodePtr z = TNULL;
      NodePtr x, y;
      while (node != TNULL) {
        if (node->data == key) {
          z = node;
        }

        if (node->data <= key) {
          node = node->right;
        } else {
          node = node->left;
        }
      }

      if (z == TNULL) {
        cout << "Key not found in the tree" << endl;
        return;
      }

      y = z;
      int y_original_color = y->color;
      if (z->left == TNULL) {
        x = z->right;
        rbTransplant(z, z->right);
      } else if (z->right == TNULL) {
        x = z->left;
        rbTransplant(z, z->left);
      } else {
        y = minimum(z->right);
        y_original_color = y->color;
        x = y->right;
        if (y->parent == z) {
          x->parent = y;
        } else {
          rbTransplant(y, y->right);
          y->right = z->right;
          y->right->parent = y;
        }

        rbTransplant(z, y);
        y->left = z->left;
        y->left->parent = y;
        y->color = z->color;
      }
      delete z;
      if (y_original_color == 0) {
        deleteFix(x);
      }
    }*/

    // Balanceo despues de inserción
    void insertarBalanceado(NodoPtr NodoEva) {
        NodoPtr uValor;
        while (NodoEva->padre->color == 1) {
            if (NodoEva->padre == NodoEva->padre->padre->Hder) {
                uValor = NodoEva->padre->padre->Hizq;
                if (uValor->color == 1) {
                    uValor->color = 0;
                    NodoEva->padre->color = 0;
                    NodoEva->padre->padre->color = 1;
                    NodoEva = NodoEva->padre->padre;
                }
                else {
                    if (NodoEva == NodoEva->padre->Hizq) {
                        NodoEva = NodoEva->padre;
                        RotacionDerecha(NodoEva);
                    }
                    NodoEva->padre->color = 0;
                    NodoEva->padre->padre->color = 1;
                    RotacionIzquierda(NodoEva->padre->padre);
                }
            }
            else {
                uValor = NodoEva->padre->padre->Hder;

                if (uValor->color == 1) {
                    uValor->color = 0;
                    NodoEva->padre->color = 0;
                    NodoEva->padre->padre->color = 1;
                    NodoEva = NodoEva->padre->padre;
                }
                else {
                    if (NodoEva == NodoEva->padre->Hder) {
                        NodoEva = NodoEva->padre;
                        RotacionIzquierda(NodoEva);
                    }
                    NodoEva->padre->color = 0;
                    NodoEva->padre->padre->color = 1;
                    RotacionDerecha(NodoEva->padre->padre);
                }
            }
            if (NodoEva == Raiz) {
                break;
            }
        }
        Raiz->color = 0;
    }

    void MostrarRN(NodoPtr raiz, string indent, bool ultimo) {
        if (raiz != TNULL) {
            cout << indent;
            if (ultimo) {
                cout << "Derecha----";
                indent += "   ";
            }
            else {
                cout << "Izquierda----";
                indent += "|  ";
            }

            string sColor = raiz->color ? "Rojo" : "Negro";
            cout << raiz->nombre << "(" << sColor << ")" << endl;
            MostrarRN(raiz->Hizq, indent, false);
            MostrarRN(raiz->Hder, indent, true);
        }
    }

public:
    NodoPtr Raiz;
    bool ValidarCodRes(NodoPtr& R, int cod);
    void setRes(int codpais, int codciud, int codres, string nombre);
    void crearRn();
    void buscarRest(NodoPtr R, int codigo);
    void ModificarRest(NodoPtr R, int codigo);
    ArbolRN() {
        TNULL = new Nodo;
        TNULL->color = 0;
        TNULL->Hizq = NULL;
        TNULL->Hder = NULL;
        Raiz = TNULL;
    }

    void preordenM() {
        preOrden(this->Raiz);
    }

    void inordenM() {
        inOrden(this->Raiz);
    }

    void postorderM() {
        postOrden(this->Raiz);
    }

    NodoPtr BusquedaM(int numbuscado) {
        return Busqueda(this->Raiz, numbuscado);
    }

    NodoPtr minimo(NodoPtr nodo) {
        while (nodo->Hizq != TNULL) {
            nodo = nodo->Hizq;
        }
        return nodo;
    }

    NodoPtr maximo(NodoPtr nodo) {
        while (nodo->Hder != TNULL) {
            nodo = nodo->Hder;
        }
        return nodo;
    }

    NodoPtr successor(NodoPtr nodo) {
        if (nodo->Hder != TNULL) {
            return minimo(nodo->Hder);
        }

        NodoPtr y = nodo->padre;
        while (y != TNULL && nodo == y->Hder) {
            nodo = y;
            y = y->padre;
        }
        return y;
    }

    NodoPtr predecessor(NodoPtr nodo) { ////////////////////////////////AQUI
        if (nodo->Hizq != TNULL) {
            return maximo(nodo->Hizq);
        }

        NodoPtr y = nodo->padre;
        while (y != TNULL && nodo == y->Hizq) {
            nodo = y;
            y = y->padre;
        }

        return y;
    }

    void RotacionIzquierda(NodoPtr nodo) {
        NodoPtr y = nodo->Hder;
        nodo->Hder = y->Hizq;
        if (y->Hizq != TNULL) {
            y->Hizq->padre = nodo;
        }
        y->padre = nodo->padre;
        if (nodo->padre == NULL) {
            this->Raiz = y;
        }
        else if (nodo == nodo->padre->Hizq) {
            nodo->padre->Hizq = y;
        }
        else {
            nodo->padre->Hder = y;
        }
        y->Hizq = nodo;
        nodo->padre = y;
    }

    void RotacionDerecha(NodoPtr nodo) {
        NodoPtr y = nodo->Hizq;
        nodo->Hizq = y->Hder;
        if (y->Hder != TNULL) {
            y->Hder->padre = nodo;
        }
        y->padre = nodo->padre;
        if (nodo->padre == NULL) {
            this->Raiz = y;
        }
        else if (nodo == nodo->padre->Hder) {
            nodo->padre->Hder = y;
        }
        else {
            nodo->padre->Hizq = y;
        }
        y->Hder = nodo;
        nodo->padre = y;
    }

    // Insercion
    void insertar(int valornuevo, int codpa, int codci, string nom) {
        NodoPtr nodo = new Nodo;
        nodo->padre = NULL;
        nodo->valor = valornuevo;
        nodo->codpais = codpa;
        nodo->codciud = codci;
        nodo->nombre = nom;
        nodo->Hizq = TNULL;
        nodo->Hder = TNULL;
        nodo->color = 1;

        NodoPtr y = NULL;
        NodoPtr x = this->Raiz;

        while (x != TNULL) {
            y = x;
            if (nodo->valor < x->valor) {
                x = x->Hizq;
            }
            else {
                x = x->Hder;
            }
        }

        nodo->padre = y;
        if (y == NULL) {
            Raiz = nodo;
        }
        else if (nodo->valor < y->valor) {
            y->Hizq = nodo;
        }
        else {
            y->Hder = nodo;
        }

        if (nodo->padre == NULL) {
            nodo->color = 0;
            return;
        }

        if (nodo->padre->padre == NULL) {
            return;
        }

        insertarBalanceado(nodo);
    }

    NodoPtr getRaiz() {
        return this->Raiz;
    }

    /*  void deleteNode(int data) {
        deleteNodeHelper(this->root, data);
      }*/

    void MostrarRN() {
        if (Raiz) {
            MostrarRN(this->Raiz, "", true);
        }
    }
    friend class Binario;
};


#endif /* RN_H */