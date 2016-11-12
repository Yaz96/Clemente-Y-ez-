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
Hora calculaHorafinReseracion(); 

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
    horaInicio.setHora(horaInicio.getHora());
    horaInicio.setMinu(horaInicio.getMinu());
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


Hora Reserva::calculaHorafinReseracion(){
int numdHoras= (duracion/60), numdMinu= (numdHoras*60-duracion); //tomando en cuenta que el valor de duracion esta en minutos
                                                            // esta linea determina el numero de horas y el numero minutos
int hora=(horaInicio.getHora()+numdHoras), Minutos= (horaInicio.getMinu()+numdMinu);// esta linea determina la hora y los min que se desplegaran

if (hora>=24){
    hora=hora-24;
}

Hora HoraFin(hora,Minutos);
return HoraFin;
}

