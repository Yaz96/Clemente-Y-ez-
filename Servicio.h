class Servicio
{
public:
	Servicio();
	Servicio(String cl, int tM, char t);
	
protected:
	string clave;
	int tiempoMax;
	char tipo;
};
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