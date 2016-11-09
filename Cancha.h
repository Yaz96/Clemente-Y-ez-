#include <iostream>
class Cancha:public Servicio
{
public:
	//Deafults 
	Cancha();
	Cancha(string cl, int tM, char t, double cos, int cant, string d);
	//Gets
	double getCostoXHr(); //Costo por Hora.
	int getCMP(); //Cantidad Maxima de personas.
	string getDeporte(); //Deporte
	//Set
	void setCostoXHr(double cos);  //Costo por Hora.
	void setCMP(int cant);// Cantidad Maxima de personas.
	void setDeporte(string d);//Deporte
	//print 
	void muestra();
	void calculaCosto(); //Calcular costo
private:
	double costoXHr;
	int cantMaxPers;
	string deporte;
};
//-------------------------------------------Default--------------------------------------------------
Cancha::Cancha() : Servicio()
{
	costoXHr = 0.0;
	cantMaxPers = 0;
	deportes = "Default basquet";
}
Cancha::Cancha(string cl, int tM, char t, double cos, int cant, string d) : Servicio(cl, tM, t)
{
	costoXHr = cos;
	cantMaxPers = cant;
	deporte = d;
}
//---------------------------------------------Gets----------------------------------------------------
double Cancha::getCostoXHr()
{
	return costoXHr;
}
int Cancha::getCMP()
{
	return cantMaxPers;
}
string Cancha::getDeporte()
{
	return deporte;
}
//----------------------------------------------Set-------------------------------------------------------
void Cancha::setCostoXHr(double cos)
{
	costoXHr = cos;
}
void Cancha::setCMP(int cant)
{
	cantMaxPers = cant;
}
void Cancha::setDeporte(string d)
{
	deporte = d;
}
//--------------------------------------------Print---------------------------------------------------------
void Cancha::muestra()
{
	cout << "Clave: " << clave << '\n' << "Tiempo Maximo: " << tiempoMax << '\n'
	<< "Tipo: " << tipo << '\n' << "Costo por Hora: " << costoXHr << '\n' << "Cantidad Maxima de Personas: " << cantMaxPers 
	<< '\n' << "Deporte: " << deporte << endl;
}
//----------------------------------------Calcula-costo-----------------------------------------------------
void Cancha::calculaCosto()
{
	//Preguntar al profe. calculaCosto que	recibe	como	parámetro	el	tiempo en	minutos que	se	quiere	rentar
//y	regresa	como	valor	de	retorno	el	costo	de	rentar	ese	servicio.	Este	método	debe	
//ser	abstracto.
}