#include "Hora.h"
class Reserva{
private:
 string claveServicio;
 int idCliente, duracion;
 Hora horaInicio;

public:
 Reserva();
 Reserva(string cveServ, int idCli, int durac, Hora horaInicio);

//metodos de acceso
 string getcveServicio();
 int getidCliente();
 int getDuracion();
 Hora getHoraIni();

//metodos de modificacion
 void setcveServicio(string CveS);
 void setidCliente(int ID);
 void setDuracion(int Durac);
 void setHoraIni(Hora hhini);

 // metodo para calcular la hora fin de la reservacion
 Hora calculaHorafinReservacion(); 
};  


//-------------------------------------------Default--------------------------------------------------

Reserva::Reserva(){
    claveServicio= "Sin clave.";
    idCliente= 0;
    duracion= 0;
    horaInicio.setHora(0);
    horaInicio.setMinu(0);
}

Reserva::Reserva(string cveServ, int idCli, int durac, Hora horaInicio){
    claveServicio=cveServ;
    idCliente=idCli;
    duracion=durac;
    this->horaInicio = horaInicio;//Usando sobrecarga de = de la clase Hora.
}

//---------------------------------------------Gets----------------------------------------------------

 string Reserva::getcveServicio(){
return claveServicio;
 }
 int Reserva::getidCliente(){
return idCliente;
 }
 int Reserva::getDuracion(){
return duracion;
 }
 Hora Reserva::getHoraIni(){
return horaInicio;
 }
 //----------------------------------------------Set-------------------------------------------------------

 void Reserva::setcveServicio(string CveS){
claveServicio=CveS;
 }

 void Reserva::setidCliente(int ID){
idCliente=ID;
 }
 void Reserva::setDuracion(int Durac){
duracion=Durac;
 }

 void Reserva::setHoraIni(Hora hhini){
horaInicio= hhini;
 }
 
 //----------------------------------------------Hora Final-------------------------------------------------------


Hora Reserva::calculaHorafinReservacion(){
Hora HoraFin = horaInicio + duracion;//Usando el sobrecarga de operador, se suma a la hora de inicio la duracion.

return HoraFin;
}

