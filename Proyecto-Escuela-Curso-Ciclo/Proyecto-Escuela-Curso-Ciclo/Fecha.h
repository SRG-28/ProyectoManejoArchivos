#pragma once
#include<iostream>
#include<string>
#include<sstream>
#include<fstream>
using namespace std;

class Fecha {
   private:
	   int d;
	   int m;
	   int a;
   public:
	   Fecha(int = 0, int = 0, int = 0);
	   Fecha(Fecha&);

	   virtual ~Fecha();

	   void setDia(int dia);
	   void setMes(int mes);
	   void setAnio(int anio);
	   int getDia();
	   int getMes();
	   int getAnio();

	   string toString();
	   friend ostream& operator <<(ostream&, Fecha&);
	   Fecha& operator = (Fecha&);

	   void leeFecha(ifstream&);
	   void guardaFecha(ofstream&);
};