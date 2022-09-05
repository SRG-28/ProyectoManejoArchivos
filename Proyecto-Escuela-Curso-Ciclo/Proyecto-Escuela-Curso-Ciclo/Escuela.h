#pragma once
#include"Ciclo.h"
#include"Curso.h"
#include"Lista.h"

class Escuela {
   private:
	   string codigoE;
	   string nombreE;
	   Lista<Curso>* listCur;
	   Lista<Ciclo>* listCic;
   public:
	   Escuela(string = "", string = "", Lista<Curso>* = NULL, Lista<Ciclo>* = NULL);
	   virtual ~Escuela();
	   void setCodE(string);
	   void setNomE(string);
	   void setListCursos(Lista<Curso>*);
	   void setListCiclos(Lista<Ciclo>*);
	   string getCodEsc();
	   string getNomEsc();
	   Lista<Curso>* getListCursos();
	   Lista<Ciclo>* getListCiclos();
	   string toString();
	   friend ostream& operator << (ostream&, const Escuela&);
	   void salvarEscuela();   // Guardar en HD a la info de la Escuela.
	   void cargarEscuela();   // Recuperar del HD la info de la Escuela.
	   
	   void ingresaCiclo(Ciclo* cic);
	   void guardarCiclos();
	   void recuperarCiclos();
	   void verCiclos();
	   void modificarCiclo(int lug);
	   void eliminarCiclo(int lug);

	   void ingresarCurso(Curso* cur);
	   void guardarCursos();
	   void recuperarCursos();
	   void verCursos();
	   void modificarCurso(int lug);
	   void eliminarCurso(int lug);
	   ;
};
