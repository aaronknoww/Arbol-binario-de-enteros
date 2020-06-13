#include "Arbolbin.h"
#include <stdlib.h>
#include <iostream>

using namespace std;

Arbolbin::Arbolbin()
{
	p_raiz = nullptr;
	return;
}

bool Arbolbin::insertar(int dat)
{
	return inserAux(p_raiz, dat);
	
}

bool Arbolbin::inserAux(NodoArbol* &nodo, int elem)
{
	if (nodo != nullptr)
	{
		if (nodo->dato_ > elem)//moverse a la izquierda en el arbol
			inserAux(nodo->izq, elem);
		else if (nodo->dato_ < elem) //moverse a la derecha en el arbol
			inserAux(nodo->der, elem);
		else// si el dato es igual entonces no se puede insterar
			return(false);
	}
	else
	{
		nodo = new NodoArbol(elem);
		return true;
			
	}
}

void Arbolbin::mostrarArbol()
{
	int cont = 0;
	mostrarAux(p_raiz, cont);
	return;
}
void Arbolbin::mostrarAux(NodoArbol*& raiz, int cont)// Funcion privada no disponible para el usuario
{
	if (raiz != nullptr)// Verifica que el arbol no este vacio. 
	{
		mostrarAux(raiz->der, cont+1); // Se imprime primero la parte dercha del arbol 
		for (int e = 0; e<cont; e++)// El contador es para saber cuantos espacios imprimir
			cout << "   ";
		cout << raiz->dato_<<endl;
		mostrarAux(raiz->izq, cont+1); // Imprimir parte izquirda del arbol
		
	}
	else
	{
		return; // Si esta vacio el arbol no se imprime nada
	}
}

bool Arbolbin::buscar(int elem)
{
	return buscaAux(p_raiz, elem);
}
bool Arbolbin::buscaAux(NodoArbol *& raiz, int &elem)//funcion privada y auxiliar no disponible al usuario
{
	if (raiz == nullptr)// Para saber si el arbol esta vacio
		return false;
	else if (raiz->dato_ == elem)// Indica que el dato buscado por el usuario si se encontro
		return true;
	else if (raiz->dato_ > elem)// estas ultimas linas son para saber por que lado se debe buscar 
		buscaAux(raiz->izq, elem);//moverse por la izquierda
	else
		buscaAux(raiz->der, elem);//moverse por la derecha
		
}


void Arbolbin::preOrden()
{
	preAux(p_raiz);
	return;
}

void Arbolbin::preAux(NodoArbol*& raiz)
{
	if (raiz == nullptr)
		return;
	else
	{
		cout << raiz->dato_ << " - ";
		preAux(raiz->izq);
		preAux(raiz->der);
		return;
	}

	return;
}

void Arbolbin::inOrden()
{
	inaux(p_raiz);
	return;
}

void Arbolbin::inaux(NodoArbol*& raiz)
{
	if (raiz == nullptr)
		return;
	else
	{
		inaux(raiz->izq);
		cout<<raiz->dato_<<" - ";
		inaux(raiz->der);
		return;
	}
}
void Arbolbin::postOrden()
{
	postAux(p_raiz);
	return;
}

void Arbolbin::postAux(NodoArbol*& raiz)
{
	if (raiz == nullptr)
		return;
	else
	{
		postAux(raiz->izq);
		postAux(raiz->der);
		cout << raiz->dato_ << " - ";
		return;
	}

}


bool Arbolbin::borrarNodo(int elem)
{
	return borrarKnown(p_raiz, elem);
}

bool Arbolbin::borrarKnown(NodoArbol*&borrar, int elem)
{
	NodoArbol* anterior = nullptr;
	NodoArbol* inicio = borrar;
	
	if (borrar == nullptr)
		return false;
	else if (buscaAux(borrar, elem))// solo para saber si el nodo existe
	{
		while (borrar->dato_ != elem)// Aqui se encuentra el nodo que se quiere borrar
		{
			if (borrar->dato_>elem)
			{
				anterior = borrar;//Tener el nodo anterior antes de avanzar en el arbol.
				borrar = borrar->izq;// avanza una posision en el arbol por el hijo izquierdo.
			}
			else
			{
				anterior = borrar;
				borrar = borrar->der;//avanza una posision en el arbol por la derecha
			}
		}

		if (borrar->izq && borrar->der)
		{
					
			NodoArbol* izquierda = anterior = borrar;
			izquierda = izquierda->der;
			while (izquierda->izq != nullptr)
			{
				anterior = izquierda;
				izquierda = izquierda->izq;
			}
			if (borrar==anterior)
			{
				borrar->dato_ = izquierda->dato_;
				borrar->der = izquierda->der;
				delete izquierda;
				izquierda = nullptr;
				borrar = inicio;
				return true;

			}
			else
			{
				borrar->dato_ = izquierda->dato_;
				anterior->izq = nullptr;
				delete izquierda;
				izquierda = nullptr;
				borrar = inicio;
				return true;
			}
			

			
			
			
		}
		else if (borrar->izq)//Saber si tiene hijo izq.
		{
			if (anterior == nullptr)// Para saber si es el primer nodo del arbol
			{
				anterior = borrar;
				borrar = borrar->izq;
				delete anterior;
				anterior = nullptr;
				return true;
			}
			else
			{// ver que pasa en el caso de un codo
				if (anterior->der == borrar)//Anterior debe de conectarce por el hijo izquierdo
					anterior->der = borrar->izq;
				else
					anterior->izq = borrar->izq;//Conectar el anterior por el nodo derecho
				
				anterior = borrar;
				borrar = inicio; // Inicio tine la direccion del priemer nodo del arbol.
				anterior->izq = nullptr;
				delete anterior;
				anterior = nullptr;
				return true;

			}

		}
		else if (borrar->der)//Saber si tiene hijo derecho.
		{
			if (anterior == nullptr)// Para saber si es el primer nodo del arbol
			{
				anterior = borrar;
				borrar = borrar->der;
				delete anterior;
				anterior = nullptr;
				return true;
			}
			else//NOTA: hay que analizar si el nodo es hijo izquierdo o derecho.<--------------------
			{
				if (anterior->izq == borrar)//Anterior debe de conectarce por el hijo izquierdo
					anterior->izq = borrar->der; 
				else
					anterior->der= borrar->der;//Conectar el anterior por el nodo derecho

					anterior = borrar;
					borrar = inicio; // Inicio tine la direccion del priemer nodo del arbol.
					anterior->der = nullptr;
					delete anterior;
					anterior = nullptr;
					return true;

			}
				

		}
		else// borrar un nodo hoja
		{
			borrar = anterior;
			if (borrar->izq)// Para saber si el nodo que se va eliminar es hijo izquierdo de un nodo anterior.
			{ 
				anterior=anterior->izq;
				borrar->izq = nullptr;
				borrar = inicio;
				delete anterior;
				anterior = nullptr;
				return true;
			}
			else if(borrar->der)// Para saber si el nodo que se va eliminar es hijo derecho de un nodo anterior.
			{
				anterior = anterior->der;
				borrar->der = nullptr;
				borrar = inicio;
				delete anterior;
				anterior = nullptr;
				return true;
			}
			else // Entonces es el arbol solo tiene una hoja
			{
				delete borrar;
				borrar = nullptr;
				return true;
				/*delete inicio;
				inicio = nullptr;
				*/
			}
		}
	}
	return false;

	

}






//FUNCION DE BORRAR CON RECURSIVIDAD COMENTADA DEBIDO AQUE NECESITA CORRECCIONES PARA SU FUNCIONAMIENTO.
/*
bool Arbolbin::seekDestroy(NodoArbol* raiz, int elem)
{

	if (raiz == nullptr)// Para saber si el arbol esta vacio
		return false;
	else if (raiz->dato_ == elem)// Indica que el dato buscado por el usuario si se encontro
		return eliminarNodo(raiz);
	else if (raiz->dato_ > elem)// estas ultimas linas son para saber por que lado se debe buscar
		seekDestroy(raiz->izq, elem);//moverse por la izquierda
	else
		seekDestroy(raiz->der, elem);//moverse por la derecha

}
bool Arbolbin::eliminarNodo(NodoArbol* borrarNodo)// Aqui se recibe el nodo que se va eliminar.
{
	if (borrarNodo->izq && borrarNodo->der) //Borrar cuando el nodo tiene 2 hijos.
	{
		NodoArbol* remplazo = masIzq(borrarNodo->der);//Para poder moverse al hijo derecho y luego obtener el nodo de remplazo.
		borrarNodo->dato_ = remplazo->dato_;// Se remplaza el dato clave y tambien se deberia de cambiar todo lo relacionado a esa clave.
		eliminarNodo(remplazo);
	}
	else if (borrarNodo->izq)// Para saber si el nodo tiene un hijo izquierdo.
	{
		NodoArbol* siguiente = borrarNodo->izq; // Para poder liberar la memoria heap del nodo eliminado.
		borrarNodo->izq = borrarNodo->izq; // Toma el valor y a lo que apunta el nodo siguiente.
		delete siguiente; //liberar heap memory.
		siguiente = nullptr;
		return true;
	}
	else if (borrarNodo->der)// Para borrar el hijo derecho.
	{
		NodoArbol* siguiente = borrarNodo->der; // Para poder liberar la memoria heap del nodo eliminado.
		borrarNodo = borrarNodo->der; // Toma el valor y a lo que apunta el nodo siguiente.
		delete siguiente; //liberar heap memory.
		siguiente = nullptr;
		return true;
	}
	else
	{

		//delete borrarNodo; se encuentra apuntando al nodo que se debe de borrar.
		return true;
	}
	return false;
}
Arbolbin::NodoArbol* Arbolbin::masIzq(NodoArbol* nodoa)
{
	if (nodoa == nullptr)
		return nullptr;
	else if (nodoa->izq)
		return masIzq(nodoa->izq);
	else
		return nodoa;
}
*/

// typename Dictionary<K, D>::TreeNode*& Dictionary<K, D>::_find(
