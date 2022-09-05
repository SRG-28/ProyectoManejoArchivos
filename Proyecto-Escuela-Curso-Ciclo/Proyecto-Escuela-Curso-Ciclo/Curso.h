#pragma once
#include"Ciclo.h"

class Curso{
  private:
	string codCurso;
	string nomCurso;
	Ciclo* cicl;
  public:
    Curso();
	Curso(string, string, Ciclo*);

	virtual ~Curso();

	string getCodigoCurso();
	void setCodigoCurso(string);
	string getNombreCurso();
	void setNombreCurso(string);
	Ciclo* getCiclo();
	void setCiclo(Ciclo* cic);
	
	string toString();
	friend ostream& operator << (ostream&, Curso&);

	void guardaCurso(ofstream&);
	void leeCurso(ifstream&);

};