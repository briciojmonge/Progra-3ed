#ifndef AA_H
#define AA_H 
#include <iostream>
#include <string>
using namespace std;
class node {
public:
    int count, level, codp, codc, codr, codm;
    string nom;
    node* right;
    node* left;
    node* parent;
};
node* root;

class ArbolAA
{
public:
    int lookup(string& key, int pais, int ciud, int res, int men);
    void skew(node*);
    bool split(node*);
    void rebal(node*);
    node* insert(node*, node*);
    void print(node*);
    int countnode(node*);
    bool contains(int& key);
    void crearAA();
    void setMen(int codpais, int codciud, int codres, int codmen, string nombre);
    void buscarMen(node*& R, int codigo);
    ArbolAA()
    {
        root = NULL;
    }
    friend class Binario;
};



int ArbolAA::lookup(string& key, int pais, int ciud, int res, int men)
{
    node* temp = new node;
    temp->nom = key;
    temp->codp = pais;
    temp->codc = ciud;
    temp->codr = res;
    temp->codm = men;
    temp->level = 1;
    temp->count = 0;
    temp->left = NULL;
    temp->right = NULL;
    temp->parent = NULL;
    temp = insert(root, temp);
    return temp->count;
}

void ArbolAA::skew(node* temp)
{
    node* ptr = temp->left;
    if (temp->parent->left == temp)
        temp->parent->left = ptr;
    else
        temp->parent->right = ptr;
    ptr->parent = temp->parent;
    temp->parent = ptr;
    temp->left = ptr->right;
    if (temp->left != NULL)
        temp->left->parent = temp;
    ptr->right = temp;
    temp->level = (temp->left ? temp->left->level + 1 : 1);
}

bool ArbolAA::split(node* temp)
{
    node* ptr = temp->right;
    if (ptr && ptr->right && (ptr->right->level == temp->level))
    {
        if (temp->parent->left == temp)
            temp->parent->left = ptr;
        else
            temp->parent->right = ptr;
        ptr->parent = temp->parent;
        temp->parent = ptr;
        temp->right = ptr->left;
        if (temp->right != NULL)
            temp->right->parent = temp;
        ptr->left = temp;
        ptr->level = temp->level + 1;
        return true;
    }
    return false;
}

void ArbolAA::rebal(node* temp)
{
    temp->left = NULL;
    temp->right = NULL;
    temp->level = 1;
    for (temp = temp->parent; temp != root; temp = temp->parent)
    {
        if (temp->level != (temp->left ? temp->left->level + 1 : 1))
        {
            skew(temp);
            if (temp->right == NULL)
                temp = temp->parent;
            else if (temp->level != temp->right->level)
                temp = temp->parent;
        }
        if (temp->parent != root)
        {
            if (split(temp->parent) == false)
                break;
        }
    }
}


node* ArbolAA::insert(node* temp, node* ins)
{
    if (root == NULL)
    {
        ins->count = 1;
        ins->parent = NULL;
        ins->left = NULL;
        ins->right = NULL;
        root = ins;
        return root;
    }
    if (ins->codm < temp->codm)
    {
        if (temp->left)
            return insert(temp->left, ins);
        temp->left = ins;
        ins->parent = temp;
        ins->count = 1;
        rebal(ins);
        return ins;
    }
    if (ins->codm > temp->codm)
    {
        if (temp->right)
            return insert(temp->right, ins);
        temp->right = ins;
        ins->parent = temp;
        ins->count = 1;
        rebal(ins);
        return ins;
    }
    temp->count++;
    delete ins;
    return temp;
}


void ArbolAA::print(node* temp)
{
    if (!temp)
        return;
    print(temp->left);
    cout << "Value: " << temp->nom << "  Count:" << temp->count;
    cout << "  Level: " << temp->level << endl;
    print(temp->right);
}


int ArbolAA::countnode(node* temp)
{
    if (!temp)
        return 0;
    int count = 1;
    count = count + countnode(temp->left);
    count = count + countnode(temp->right);
    return count;
}
#endif /* AA_H */