#pragma once
#include"Fecha.h"

class Ciclo{
  private:
	int anio;
	int numCiclo;
	Fecha* fecIni;
	Fecha* fecFin;
  public:
	Ciclo(int = 0, int = 0, Fecha* = NULL, Fecha* = NULL);
	Ciclo(Ciclo&);  // constructor copia..
	virtual ~Ciclo();
	int getAnio();
	void setAnio(int);
	int getNumCiclo();
	void setNumCiclo(int);
	Fecha* getFechaInicio();
	void setFechaInicio(Fecha*);
	Fecha* getFechaFinaliza();
	void setFechaFinaliza(Fecha*);
	string toString();
	Ciclo& operator = (Ciclo&);
	friend ostream& operator << (ostream&, Ciclo&);

	void leeCiclo(ifstream&);
	void guardaCiclo(ofstream& );
};