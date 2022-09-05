#include"Escuela.h"

// Las listas pueden ser recibidas por parámetro o creadas dentro del constructor..
// En este caso son recibidas por parámetro....
Escuela::Escuela(string codE, string nomE, Lista<Curso>* listCu, Lista<Ciclo>* listCi) {
	codigoE = codE;
	nombreE = nomE;
	listCur = listCu;
	listCic = listCi;
}

Escuela::~Escuela() {
}

void Escuela::setCodE(string cE) { codigoE = cE; }
void Escuela::setNomE(string nE) { nombreE = nE; }
void Escuela::setListCursos(Lista<Curso>* LCu) { listCur = LCu; }
void Escuela::setListCiclos(Lista<Ciclo>* LCi) { listCic = LCi; }
string Escuela::getCodEsc() { return codigoE; }
string Escuela::getNomEsc() { return nombreE; }
Lista<Curso>* Escuela::getListCursos() { return listCur; }
Lista<Ciclo>* Escuela::getListCiclos() { return listCic; }

string Escuela::toString() {
	stringstream s;
	s << "----Informacion de la Escuela-----" << endl
		<< "Codigo de la Escuela..." << codigoE << endl
		<< "Nombre de la Escuela..." << nombreE << endl;
	if (listCur != NULL) 
		s << listCur->verLista() << endl;
	if (listCic != NULL)
		s << listCic->verLista() << endl;
	return s.str();
}

ostream& operator << (ostream& out, Escuela& esc) {
	return     out << "------------ESCUELA------------------" << endl
	               << "Codigo Escuela..." << esc.getCodEsc() << endl
		           << "Nombre Escuela..." << esc.getNomEsc() << endl;
	       if (esc.getListCursos() != NULL)
		       out << esc.getListCursos()->verLista() << endl;
		   if (esc.getListCiclos() != NULL)
			   out << esc.getListCiclos()->verLista() << endl;
}
void Escuela::salvarEscuela() {
	// Salvar Codigo y NOmbre..
	// Salvar Todos los cursos...
    // Salvar Todos los Ciclos...
	        this->guardarCiclos();

}

void Escuela::cargarEscuela() {
	// Recuperar Codigo y NOmbre..
	// Recuperar a Todos los cursos...
	// Recuperar a Todos los Ciclos...
	        this->recuperarCiclos();
}

void Escuela::guardarCiclos() {  // Grabar en el Archivo del HD.
	ofstream sali;
	Ciclo* cicAux;
    sali.open("../Ciclos.txt", ios::out);
	nodo<Ciclo>* actual = listCic->getPrimero();
	while (actual != NULL) {

		cicAux = actual->getObjetoPtr();
		cicAux->guardaCiclo(sali);
		
		actual = actual->getSiguiente();
	}
	sali.close();
	cout << "Ciclos guardados..." << endl;
}

void Escuela::recuperarCiclos() {  // Leer del Archivo en el (HD)..
	Ciclo c;
	Ciclo* p = NULL;
	ifstream entrada("../Ciclos.txt", ios::in);
	
	listCic->limpiaLista();
	int cont = 0;
	c.leeCiclo(entrada);  // Lectura previa
	while (!entrada.eof()){
		p = new Ciclo(c.getAnio(), c.getNumCiclo(), c.getFechaInicio(), c.getFechaFinaliza());
		listCic->insertaObjeto(p);
		cont++;
		c.leeCiclo(entrada);
	}
	entrada.close();
	cout << "Ciclos leidos..." << cont<<" registros."<<endl;
}


void Escuela::verCursos() {
	cout << listCur->verLista() << endl;
}

void Escuela::recuperarCursos() {
	Curso c;
	Curso* p = NULL;
	Ciclo* cPtr = NULL;
	ifstream entrada("../Cursos.txt", ios::in);

	this->listCur->limpiaLista();
	int cont = 0;
	
	c.leeCurso(entrada);  // Lectura previa
	while (!entrada.eof()) {
		p = new Curso(c.getCodigoCurso(), c.getNombreCurso(), c.getCiclo() );
		listCur->insertaObjeto(p);
		cont++;
		c.leeCurso(entrada);
	}
	entrada.close();
	cout << "Cursos leidos..." << cont << " registros." << endl;

}

void Escuela::guardarCursos() {  // Grabar en el Archivo del HD.
	ofstream sali;
	Curso* curAux;
	sali.open("../Cursos.txt", ios::out);
	nodo<Curso>* actual = listCur->getPrimero();
	while (actual != NULL) {

		curAux = actual->getObjetoPtr();
		curAux->guardaCurso(sali);

		actual = actual->getSiguiente();
	}
	sali.close();
	cout << "Cursos guardados..." << endl;
}

void Escuela::ingresaCiclo(Ciclo* cic) {
	listCic->insertaObjeto(cic);
}

void Escuela::ingresarCurso(Curso* cur) {
	listCur->insertaObjeto(cur);
}

void Escuela::verCiclos() {
	cout << listCic->verLista() << endl;
}
void Escuela::modificarCurso(int lug) {}
void Escuela::modificarCiclo(int lug) {}
void Escuela::eliminarCurso(int lug) {}
void Escuela::eliminarCiclo(int lug) {}