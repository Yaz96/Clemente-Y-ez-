class Servicio
{
public:
	//Defaults
	Servicio();
	Servicio(String cl, int tM, char t);
	//Gets
	string getClave();//Clave
	int getTiempoMax();//Tiempo MMaximo
	char getTipo();//Tipo
	//Sets
	void setClave(string cl);//Clave
	void setTiempoMax();//Tiempo Maximo
	void setTipo();//Tipo
	//Print
	virtual void muestra();
	//Calculo
	virtual double calculaCosto(int in, int tM); //Calcula el costo
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
	char = "D";
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
	return Clave;
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
//--------------------------------------------------------------------------------------Print------------------------------------------------------------------------
void Servicio::muestra()
{
	cout << "Clave: " << clave << '\n' << "Tiempo Maximo: " << tiempoMax << '\n'
	<< "Tipo: " << tipo << endl;
}
//---------------------------------------------------------------------------------Calcula-costo--------------------------------------------------------------------
double calculaCosto(int tM)
{	
	//Preguntar al profe.
}