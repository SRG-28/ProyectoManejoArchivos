#include"Fecha.h"

Fecha::Fecha(int dd, int mm, int aa):d(dd),m(mm),a(aa) {}
Fecha::Fecha(Fecha& fec) {
	d = fec.d;
	m = fec.m;
	a = fec.a;
}
Fecha::~Fecha() {}
void Fecha::setDia(int dia)   { d = dia; }
void Fecha::setMes(int mes)   { m = mes; }
void Fecha::setAnio(int anio) { a = anio; }
int Fecha::getDia() { return d; }
int Fecha::getMes() { return m; }
int Fecha::getAnio() { return a; }
string Fecha::toString() {
	stringstream s;
	s << "==> " << d << "/" << m << "/" << a << endl;
	return s.str();
}

Fecha& Fecha::operator = (Fecha& fec) {
	d = fec.d;
	m = fec.m;
	a = fec.a;
	return *this;
}

ostream& operator <<(ostream& out, Fecha& fec) {
	return out << "fecha = " << fec.d << "/" << fec.m << "/" << fec.a << endl;
}

void Fecha::leeFecha(ifstream& entrada) {
	string dd;
	string mm;
	string aa;

	getline(entrada, dd);
	getline(entrada, mm);
	getline(entrada, aa);
	
	// Hay que pasar a entero los string que se leen en el archivo fechas.
	d = atoi(dd.c_str());
	m = atoi(mm.c_str());
	a = atoi(aa.c_str());
}

void Fecha::guardaFecha(ofstream& sali) {
	sali << this->getDia()  << '\n';
	sali << this->getMes()  << '\n';
	sali << this->getAnio() << '\n';
}