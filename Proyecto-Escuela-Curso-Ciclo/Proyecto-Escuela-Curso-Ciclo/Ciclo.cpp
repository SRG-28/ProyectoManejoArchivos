#include"Ciclo.h"

Ciclo::Ciclo(int anio, int numCiclo, Fecha* fechaInicio, Fecha* fechaFinaliza){
	this->anio = anio;
	this->numCiclo = numCiclo;
	this->fecIni = fechaInicio;
	this->fecFin = fechaFinaliza;
}

Ciclo::Ciclo(Ciclo& c) {
	anio = c.anio;
	numCiclo = c.numCiclo;
	fecIni = c.fecIni;
	fecFin = c.fecFin;
}

Ciclo::~Ciclo() {
}

int Ciclo::getAnio() { return anio; }
void Ciclo::setAnio(int anio) { this->anio = anio; }
int Ciclo::getNumCiclo() { return numCiclo; }
void Ciclo::setNumCiclo(int numCiclo) { this->numCiclo = numCiclo; }
Fecha* Ciclo::getFechaInicio() { return fecIni; }
void Ciclo::setFechaInicio(Fecha* fechaInicio) { this->fecIni = fechaInicio; }
Fecha* Ciclo::getFechaFinaliza() { return fecFin; }
void Ciclo::setFechaFinaliza(Fecha* fechaFinaliza) { this->fecFin = fechaFinaliza; }

string Ciclo::toString()
{
	stringstream s;
	s  << "---------Datos del ciclo--------" << endl
	   << "Anio: " << getAnio() << endl
	   << "Ciclo: " << getNumCiclo() << endl;
	if (fecIni != NULL && fecFin != NULL) {
		s << "Fecha inicio de ciclo: " << getFechaInicio() << endl
		  << "Fecha final  de ciclo: " << getFechaFinaliza() << endl;
	}
	return s.str();
}

Ciclo& Ciclo::operator = (Ciclo& c) {
	if (this != &c) {
		this->anio = c.anio;
		this->numCiclo = c.numCiclo;
		this->fecIni = new Fecha(c.fecIni->getDia(), c.fecIni->getMes(), c.fecIni->getAnio());
		this->fecFin = new Fecha(c.fecFin->getDia(), c.fecFin->getMes(), c.fecFin->getAnio());
	}
	return *this;
}

ostream& operator<<(ostream& out, Ciclo& aux){
	return  out << "---------Datos del ciclo--------" << endl
		<< "Anio: " << aux.getAnio() << endl
		<< "Ciclo: " << aux.getNumCiclo() << endl
		<< "Fecha de inicio de ciclo: " << *aux.getFechaInicio() << endl
		<< "Fecha final de ciclo: " << *aux.getFechaFinaliza() << endl;
}

void Ciclo::leeCiclo(ifstream& entrada){
	Fecha f1;
	Fecha f2;
	string Anio;
	string NumCiclo;

	getline(entrada, Anio);
	getline(entrada, NumCiclo);
	f1.leeFecha(entrada);
	fecIni = new Fecha(f1.getDia(), f1.getMes(), f1.getAnio());
	f2.leeFecha(entrada);
	fecFin = new Fecha(f2.getDia(), f2.getMes(), f2.getAnio());
	// Hay que pasar a entero los string que se leen.
	anio = atoi(Anio.c_str());
	numCiclo = atoi(NumCiclo.c_str());
}
 
void Ciclo::guardaCiclo(ofstream& sali){
		sali << this->getAnio() << '\n';
		sali << this->getNumCiclo() << '\n';
		this->getFechaInicio()->guardaFecha(sali) ;
		this->getFechaFinaliza()->guardaFecha(sali) ;
}
	