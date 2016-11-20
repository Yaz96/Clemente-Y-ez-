#pragma once //Para que la clase solo sea incluido una vez cuando se compila.
#include "Servicio.h"
class Aparato:public Servicio{
private:
    double costoX15min;
    bool conInstructor;
    string descripcion; 

public:
    Aparato();
    Aparato(string cl, int tM, char t, double cost,bool conInst, string des);

    //Metodos de acceso
    double getcostoX15min();
    bool getConInstructor();
    string getDescripcion();
    //Metodos de modificacion
    void setcostoX15min(double Cost);
    void setConInstructor(bool Cond);
    void setDescripcion(string Desc);

    // Metodos Abstractos 
    void muestra();
    double calculaCosto (int tiem);
};
//-----------------------------------------Default---------------------------------------------------

Aparato::Aparato(): Servicio()
{
    costoX15min=0.0;
    conInstructor=false;
    descripcion="Sin_descripcion";

}

Aparato::Aparato( string cl, int tM, char t, double cost,bool conInst, string des): Servicio(cl, tM, t)
{
 costoX15min=cost;
 conInstructor =conInst;
 descripcion =des;
}
//-------------------------------------------------Acceso--------
double Aparato::getcostoX15min(){
return costoX15min;
}

bool Aparato::getConInstructor(){
return conInstructor;
}

string Aparato::getDescripcion(){
return descripcion;
}

//---------------------------------------------------Modificacion------

void Aparato::setcostoX15min(double Cost){
costoX15min=Cost;
}
void Aparato::setConInstructor(bool Cond){
conInstructor=Cond;
}
void Aparato::setDescripcion(string Desc){
descripcion=Desc;
}

//----------------------------------------------------Metodos Abstractos----

void Aparato::muestra(){
cout<<"Tipo de Reservacion: Aparato"<<'\n'<<"Clave: "<<clave<<'\n'<< "Tiempo Maximo: " << tiempoMax << '\n'
	<< "Tipo: " << tipo << '\n' << "Costo X 15min: " << costoX15min<< '\n'<<"Instructor: "<<conInstructor
    <<'\n'<<"Descripcion: "<<descripcion<<endl;
}

double Aparato::calculaCosto (int tiem){
    int sesiones= ceil(tiem/15);
double Precio=sesiones*costoX15min;
return Precio;
}
