//Calse abstracta.
class Servicio
{
public:
	//Defaults
	Servicio();
	Servicio(String cl, int tM, char t);
	//Gets
	virtual string getClave() = 0;//Clave
	virtual int getTiempoMax() = 0;//Tiempo MMaximo
	virtual char getTipo() = 0;//Tipo
	//Sets
	virtual void setClave(string cl) = 0;//Clave
	virtual void setTiempoMax() = 0;//Tiempo Maximo
	virtual void setTipo() = 0;//Tipo
	//Print
	virtual void muestra() = 0;
	//Calculo
	virtual double calculaCosto(int in, int tM) = 0; //Calcula el costo
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