#pragma once //Para que el archivo solo sea incluido una vez cuando se compila.
class Servicio
{
public:
	//Defaults
	Servicio();
	Servicio(string cl, int tM, char t);
	//Gets
	string getClave();//Clave
	int getTiempoMax();//Tiempo MMaximo
	char getTipo();//Tipo
	//Sets
	void setClave(string cl);//Clave
	void setTiempoMax(int tM);//Tiempo Maximo
	void setTipo(char t);//Tipo
	//Print
	virtual void muestra() = 0;
	//Calculo
	virtual double calculaCosto(int tM) = 0; //Calcula el costo
protected:
	string clave;
	int tiempoMax;
	char tipo;
};
//--------------------------------------------------------------------------------Default-----------------------------------------------------------------------------
Servicio::Servicio()
{
	clave = "Default";
	tiempoMax = 0;
	tipo = 'D';
}
Servicio::Servicio(string cl, int tM, char t)
{
	clave = cl;
	tiempoMax = tM;
	tipo = t;
}
//-----------------------------------------------------------------------------------Gets----------------------------------------------------------------------------
string Servicio::getClave()
{
	return clave;
}	
int Servicio::getTiempoMax()
{
	return tiempoMax;
}
char Servicio::getTipo()
{
	return tipo;
}
//------------------------------------------------------------------------------------Sets-------------------------------------------------------------------------------
void Servicio::setClave(string cl)
{
	clave = cl;
}
void Servicio::setTiempoMax(int tM)
{
	tiempoMax = tM;
}
void Servicio::setTipo(char t)
{
	tipo = t;
}