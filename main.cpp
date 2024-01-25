//
// Created by Josel on 24/01/2024.
//
#include <iostream>
#include "AVL.h"
using namespace std;

int main(){
    AVL<int> arbol;

    arbol.insert(4);
    arbol.insert(2);
    arbol.insert(6);
    arbol.insert(1);
    arbol.insert(3);
    arbol.insert(5);
    arbol.insert(7);
    Node<int>* padre = arbol.parent(7);
    if (padre != nullptr)
        cout << "El padre de 7 es: " << padre->value << endl;
    else
        cout << "No tiene padre" << endl;
    Node<int>* mas_bajo_comun = arbol.lowestCommon(5,7);
    if (mas_bajo_comun != nullptr)
        cout << "El mas bajo comun es: " << mas_bajo_comun->value << endl;
    else
        cout << "No hay mas bajo comun" << endl;

    Node<int>* sucesor = arbol.Sucessor(2);
    if (mas_bajo_comun != nullptr)
        cout << "El sucesor es: " << sucesor->value << endl;
    else
        cout << "No hay sucesor" << endl;

    Node<int>* predecesor= arbol.Predecessor(6);
    if (predecesor != nullptr)
        cout << "El predecesor es: " << predecesor->value << endl;
    else
        cout << "No hay" << endl;




    int valor = 3;
    cout << boolalpha << arbol.search(valor) << endl ;
    cout << arbol.remove(valor) << endl;
    cout << boolalpha << arbol.search(valor) << endl;
    //cout << "¿El valor " << valor << " esta en el arbol? " << (arbol.search(valor) ? "Sí" : "No") << endl;
    vector<int> inOrderResult = arbol.inOrder();
    vector<int>prueba = arbol.PostOrder();
    vector<int>prueba1 = arbol.PreOrden();

    cout << "Inorden: ";
    for (int elem : inOrderResult) {
        cout << elem << " ";
    }
    cout << endl;
    cout << "Postorden: ";
    for (int elem : prueba) {
        cout << elem << " ";
    }
    cout << endl;
    cout << "Preorden: ";
    for (int elem : prueba1) {
        cout << elem << " ";
    }
    cout << endl;
    cout << "BFS:";
    arbol.BFS();
    return 0;

}