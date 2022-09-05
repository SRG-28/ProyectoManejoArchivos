#include"Escuela.h"


int main() {
	cout << "--------------ESCUELA--------------" << endl;
	cout << "-----------------------------------" << endl;
	cout << "Creacion de Fecha...." << endl;
	Fecha* fec1 = new Fecha(02,02,2020);
	Fecha* fec2 = new Fecha(07,07,2020);
	Fecha* fec3 = new Fecha(12,07,2020);
	Fecha* fec4 = new Fecha(13,11,2020);
	Fecha* fec5 = new Fecha(15,11,2020);
	Fecha* fec6 = new Fecha(11,02,2021);

	system("pause");
	cout << "Creacion de Ciclos...." << endl;
	Ciclo* ci1 = new Ciclo(2020, 1, fec1, fec2);
	Ciclo* ci2 = new Ciclo(2020, 2, fec3, fec4);
	Ciclo* ci3 = new Ciclo(2020, 3, fec5, fec6);
	cout << endl;
	cout << "Creacion de Cursos...." << endl;
	Curso* cu1 = new Curso("EIF-200", "Fundamentos", ci1);
	Curso* cu2 = new Curso("EIF-201", "Programacion 1", ci2);
	Curso* cu3 = new Curso("EIF-202", "Programacion 2", ci1);
	Curso* cu4 = new Curso("EIF-204", "Estructuras Datos", ci2);
	Curso* cu5 = new Curso("EIF-207", "Programacion Web", ci3);
	Curso* cu6 = new Curso("MAT-405", "Matematica 1", NULL);
	cout << endl;
	cout << "Creacion de lista de Cursos...." << endl;
	    Lista<Curso>* listCur = new Lista<Curso>;
	cout << "Ingresando elementos a la Lista de Cursos..." << endl;
	listCur->insertaObjeto(cu1);
	listCur->insertaObjeto(cu2);
	listCur->insertaObjeto(cu3);
	listCur->insertaObjeto(cu4);
	listCur->insertaObjeto(cu5);
	listCur->insertaObjeto(cu6);
	cout<<endl;
	cout << "Creacion de lista de Ciclos...." << endl;
		Lista<Ciclo>* listCic = new Lista<Ciclo>;
	cout << "Ingresando elementos a la Lista de Ciclos.." << endl;
	listCic->insertaObjeto(ci1);
	listCic->insertaObjeto(ci2);
	listCic->insertaObjeto(ci3);

	cout << "Creacion de una Escuela...." << endl;
	Escuela* esc1 = new Escuela("ESINF", "Escuela de Informatica", listCur, listCic);

	cout << "-----------Despliegue de Ciclos------------------" << endl;
    esc1->guardarCiclos();
	esc1->recuperarCiclos();
	cout << endl << endl;
	cout<<esc1->getListCiclos()->verLista() << endl;
	cout << "--------------------------------------------------" << endl;
	system("pause");
	system("cls");
	cout << "-----------Despliegue de Cursos------------------" << endl;
	esc1->guardarCursos();
	esc1->recuperarCursos();
	cout << endl << endl;
	cout << esc1->getListCursos()->verLista() << endl;
	cout << "--------------------------------------------------" << endl;

	system("pause");
	return 0;
}