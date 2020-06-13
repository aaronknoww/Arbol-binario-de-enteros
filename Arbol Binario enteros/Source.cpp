#include <iostream>
#include <stdlib.h>
#include "Arbolbin.h"

using namespace std;

int main()
{
	
	Arbolbin arbol;
	/*
	arbol.insertar(8);
	arbol.insertar(3);
	arbol.insertar(1);
	arbol.insertar(6);
	arbol.insertar(4);
	arbol.insertar(7);
	arbol.insertar(8);
	arbol.insertar(10);
	arbol.insertar(14);
	arbol.insertar(13);
	*/

	/*
	arbol.insertar(10);
	arbol.insertar(5);
	arbol.insertar(3);
	arbol.insertar(2);
	arbol.insertar(7);
	arbol.insertar(6);
	arbol.insertar(8);
	*/

	
	arbol.insertar(10);
	arbol.insertar(5);
	arbol.insertar(7);
	arbol.insertar(8);
	arbol.insertar(9);
	arbol.insertar(4);
	arbol.insertar(6);
	arbol.insertar(10);
	arbol.insertar(15);
	arbol.insertar(13);
	arbol.insertar(12);
	arbol.insertar(17);
	arbol.insertar(16);
	arbol.insertar(18);
	
	

	arbol.mostrarArbol();

	if (arbol.buscar(7))
		cout<<"\n\n	Si se encontro el nodo";
	else
		cout<<"\n\n	Valiste pura merga";
	
	cout << "\n";
	arbol.preOrden();
	cout << "\n";
	arbol.inOrden();
	cout << "\n";
	arbol.postOrden();
	
	cout << "\n\n";
	arbol.borrarNodo(15);
	arbol.mostrarArbol();
	cout << "\n";
	arbol.inOrden();


	system("pause > null");
	return 0;
}