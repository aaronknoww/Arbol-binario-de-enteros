#pragma once
class Arbolbin
{
public:
	Arbolbin();
	bool insertar(int);
	void mostrarArbol();
	bool buscar(int);
	void preOrden();
	void inOrden();
	void postOrden();
	bool borrarNodo(int);
private:
	class NodoArbol
	{
	public:
		int dato_;
		NodoArbol* der;
		NodoArbol* izq;
		NodoArbol(int dato) : dato_(dato), der(nullptr), izq(nullptr) { }
	
	};

	NodoArbol* p_raiz; // este es el puntero raiz del arbol
	
	// Funciones auxiliares de la clase, no disponibles para el usuario.
	bool inserAux(NodoArbol *&, int);
	void mostrarAux(NodoArbol *&, int );
	bool buscaAux(NodoArbol *&,int&);
	void preAux(NodoArbol*&);
	void inaux(NodoArbol*&);
	void postAux(NodoArbol *&);
	bool seekDestroy(NodoArbol*,int); //Busca el nodo que se va a eliminar y si lo encuentra lo borra y regresa un valor de true.
	NodoArbol* masIzq(NodoArbol*); // Para encontrar el nodo mas a la izquierda posible.
	bool eliminarNodo(NodoArbol*);
	bool borrarKnown(NodoArbol*&,int);
};

