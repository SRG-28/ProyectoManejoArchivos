#pragma once
//----------------------------------------------NODO-------------------------------------------------
template <class T>
class nodo {
  private:
	nodo * sig;
	T* objetoPtr;
  public:
	nodo(T*, nodo*);
	virtual ~nodo();
	T* getObjetoPtr();
	nodo* getSiguiente();
	void setObjetoPtr(T*);
	void setSiguiente(nodo*);
};

template<class T>
nodo<T>::nodo(T* ptr, nodo* nod) :
	objetoPtr(ptr), sig(nod)
{}

template<class T>
nodo<T>::~nodo(){
	delete objetoPtr;
}

template<class T>
T* nodo<T>::getObjetoPtr(){
	return objetoPtr;
}

template<class T>
nodo<T>* nodo<T>::getSiguiente(){
	return sig;
}

template<class T>
void nodo<T>::setObjetoPtr(T* ptr){
	objetoPtr = ptr;
}

template<class T>
void nodo<T>::setSiguiente(nodo* nod){
	sig = nod;
}

//-----------------------LISTA-----------------
template <class T>
class Lista{
  private:
	nodo<T>* primero;
  public:
	Lista();
	virtual ~Lista();
	nodo<T>* getPrimero();
	void limpiaLista();

	T* retornaElemento(int);
	bool insertaObjeto(T*);
	string verLista();
	void grabaLista(ofstream&);
	Lista<T>* leeLista(ifstream&);
};

template <class T>
Lista<T>::Lista(){
	primero = NULL;
}

template <class T>
Lista<T>::~Lista(){
	this->limpiaLista();
}

template<class T>
void Lista<T>::limpiaLista() {
	nodo<T>* actual = NULL;
	while (primero != NULL)
	{
		actual = primero;
		primero = actual->getSiguiente();  // Había un error...
		delete actual;
	}
}

template <class T>
T* Lista<T>::retornaElemento(int pos)
{
	int cont = 1;
	nodo<T>* p = primero;
	while (p != NULL && cont < pos)
	{
		p = p->getSiguiente();
		cont++;
	}
	if (cont == pos) {
		return p->getObjetoPtr();
	}
	return NULL;

}
template<class T>
nodo<T>* Lista<T>::getPrimero()
{
	return primero;
}


template <class T>
bool Lista<T>::insertaObjeto(T* objeto)
{
	nodo<T>* actual;
	nodo<T>* nuevo = new nodo<T>(objeto, NULL);
	if (primero == NULL)
	{
		primero = nuevo;
	}
	else {
		actual = primero;
		while (actual->getSiguiente() != NULL)
		{
			actual = actual->getSiguiente();
		}
		actual->setSiguiente(nuevo);
	}

	return true;
}


template <class T>
string Lista<T>::verLista()
{
	nodo<T>* p = primero;
	int cont = 1;
	stringstream s;

	if (p == NULL)
	{
		s << "No hay elementos en la lista..." << endl;
	}
	else {
		while (p != NULL)
		{
			s <<"No."<<cont<<endl<< *(p->getObjetoPtr()) << endl;
			p = p->getSiguiente();
			cont++;
		}
	}
	return s.str();
}
template<class T>
void Lista<T>::grabaLista(ofstream& sali) {

}

template<class T>
Lista<T>* Lista<T>::leeLista(ifstream& ent){
	return NULL;
}