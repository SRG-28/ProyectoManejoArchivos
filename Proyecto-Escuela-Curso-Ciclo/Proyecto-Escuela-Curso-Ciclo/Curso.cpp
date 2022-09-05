#include "Curso.h"

Curso::Curso() {
	codCurso = "";
	nomCurso = "";
	cicl = new Ciclo(0,0, new Fecha, new Fecha);
}

Curso::Curso(string cod, string nom, Ciclo* cic){
	codCurso = cod;
	nomCurso = nom;
	if (cic == NULL)
		cicl = cicl = new Ciclo(0, 0, new Fecha, new Fecha);
	else
	    cicl = new Ciclo(cic->getAnio(), cic->getNumCiclo(), cic->getFechaInicio(), cic->getFechaFinaliza());
}

Curso::~Curso() {
	     delete cicl;
}

string Curso::getCodigoCurso() { return codCurso; }
void Curso::setCodigoCurso(string codigoCurso) { this->codCurso = codigoCurso; }
string Curso::getNombreCurso() { return nomCurso; }
void Curso::setNombreCurso(string nombreCurso) { this->nomCurso = nombreCurso; }
Ciclo* Curso::getCiclo() { return cicl; }
void Curso::setCiclo(Ciclo* cic) { cicl = cic; }

string Curso::toString(){
	stringstream s;
	 s << "-------------DATOS DEL CURSO-------------" << endl
	   << "Codigo: " << getCodigoCurso() << endl
	   << "Nombre: " << getNombreCurso() << endl;
	 if (cicl->getAnio() != 0)
	 s << cicl->toString() << endl << endl;
	 return s.str();
}

ostream& operator<<(ostream& out, Curso& aux){
 return out << "---------------DATOS-DEL-CURSO-------------" << endl
	    << "Codigo: " << aux.getCodigoCurso() << endl
	    << "Nombre: " << aux.getNombreCurso() << endl
	    << "Anio:   " << aux.getCiclo()->getAnio() << endl
	    << "Numero de ciclo: " << aux.getCiclo()->getNumCiclo() << endl
	    << "Fecha de Incio:  " << *aux.getCiclo()->getFechaInicio() << endl
	    << "Fecha de Finalizacion: " << *aux.getCiclo()->getFechaFinaliza() << endl;
}

void Curso::guardaCurso(ofstream& sali) {
	// string,   string, int,  int,       string,   string
	// codCurso,nomCurso,anio,numCiclo,fechaIncial,fechaFinal

	sali << this->getCodigoCurso() << '\n';
	sali << this->getNombreCurso() << '\n';
	sali << cicl->getAnio() << '\n';
	sali << cicl->getNumCiclo() << '\n';
	sali << cicl->getFechaInicio()->getDia()   << '\n';
	sali << cicl->getFechaInicio()->getMes()   << '\n';
	sali << cicl->getFechaInicio()->getAnio()  << '\n';
	sali << cicl->getFechaFinaliza()->getDia() << '\n';
	sali << cicl->getFechaFinaliza()->getMes() << '\n';
	sali << cicl->getFechaFinaliza()->getAnio()<< '\n';
}

void Curso::leeCurso(ifstream& entrada) {
	Fecha f1;
	Fecha f2;
	string Anio;
	string NumCiclo;
	Fecha* FechaInicio;
	Fecha* FechaFinaliza;

	getline(entrada, codCurso);
	getline(entrada, nomCurso);
	getline(entrada, Anio);
	getline(entrada, NumCiclo);
	f1.leeFecha(entrada);
	FechaInicio = new Fecha(f1.getDia(), f1.getMes(), f1.getAnio());
	f2.leeFecha(entrada);
	FechaFinaliza = new Fecha(f2.getDia(), f2.getMes(), f2.getAnio());
	// Hay que pasar a entero los string que se leen.
	int anio = atoi(Anio.c_str());
	int numCiclo = atoi(NumCiclo.c_str());
	cicl = new Ciclo(anio, numCiclo, FechaInicio, FechaFinaliza);
}