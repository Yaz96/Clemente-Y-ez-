#include <iostream>
#include <string>
#include <fstream>

using namespace std;

#include "Reserva.h"
<<<<<<< Updated upstream
=======
#include "Cancha.h"
<<<<<<< Updated upstream
>>>>>>> Stashed changes
#include "Aparato.h"
#include "Cancha.h"

<<<<<<< Updated upstream
//Declaracion de arrgelos principales.
Servicio *ASrv[20];
Reserva Res[50];
//Varibales de apoyo.
ifstream iArc;
ofstream archReservas;
Reserva NuevaRes;
string S, D;
int TM, C, M, H, iCont;
double Co;
char TS, CI;
bool I;

//--------------------------------------------Hacer una reservacion-----------------------------------------------
void HacerReserv(){
   Hora horaFin, horaIn; //Esta variable se utiliza en la validacion de la hora 
    string validacion2; //Esta variable se utiliza en la validacion de los minutos disponibles 
//________________Validacion de los datos_____
    cout<<"iD del cliente: ";
    cin>>D;
    cout<<endl;

    I=false;
// Validacion de la clave de servicio ___________
    do{        
    cout<<"Clave del servicio ";
    cin>>S;
    cout<<endl;
    for(int iA=0; iA<20; iA++){
        if(ASrv[iA]->getClave==S){
            iA=C;
            I=true;
        }
    }
    }while(!I);
    I=false;

//Validacion de los minutos disponibles_________
    do{ 
    cout<<"Minutos a reservar ";
    cin>>TM;
    if(ASrv[C]->getTiempoMax()<=TM)
        I=true;
    else{
    cout<<"Este tiempo sobrepasa el maximo de tiempo permitido, ¿Quieres reservar el servicio menos tiempo? ";
    cin>>validacion2;
    cout<<endl;
    if (validacion2!=si)
    return
}
    }while(!I);

//Validacion de la hora en la que se quiere reservar____

do{ 
    I=true;
    cout<<"Hora de la reservacion ";
    cin>>H>>M;
    horaIn.setHora(H);
    horaIn.setMinu(M);
    horaFin=horaIn+TM;
    
    for(int iA=0;iA<30;iA++){
        if(!(Res[iA].getHoraIni()>horaFin||Res[iA].calculaHorafinReseracion()<horaIn))
      {  I=false;
        cout<<"Esta hora ya esta ocupada";
        return;}
    }
} while( !I );
 

//Despliegue del costo del servicio 

 for(int iA=0; iA<20 ; iA++){
     if(ASrv[iA]->getClave==S){
     cout<<"Costo del servicio "<< ASrv[iA].calculaCosto(TM)
     }
 }

//_______Escritura de la reservacion_____ 
archReservas.open("Reserva.txt");

archReservas<<S<<" "<< H<<" "<<M<<" "<<TM<<" "<<D<<endl;
archReservas.close();
NuevaRes().setcveServicio(S);
 NuevaRes().setidCliente(D;
 NuevaRes().setDuracion(TM);
 NuevaRes().setHoraIni(horaIn);
for(int iA=0; iA<50;iA++){
    if(Res[iA].idCliente==0){
        Res[iA]=NuevaRes;
        return;
    }
}
}



//--------------------------------------Consulta reservaciones de una hora especifica.------------------------
    void ConsReservHoraSp(){
        cout<<"Ingresa la hora con minutos separados por un espacio que deseas buscar ";
        cin>>H>>M;
        Hora horaSuj(H,M);

        for(int iA=0; iA<30; iA++){ 
        if(Res[iA].getHoraIni== horaSuj){ //En este par de for y if con iA se comparan las horas de las reservaciones para obtener cual tiene la misma hora
            for(int iB=0, iB<20;iB++){ //una vez que encontremos una reservacion con esa hora buscaremos que servicio tiene la misma clave que esa reservacion para despues imprimir la info
                if(ASrv[iB]->getClave()==Res[iA].getClave())
                ASrv[iB]->muestra();
            }
        }
        }
    }
   

//-----------------------------------------Consultar las reservaciones por servicio.------------------------------
void ConsReservServDado(){
        I=false;
    cout<<"Cual es el ID del servicio que deseas buscar: ";
    cin>>D;

    for(int iA=0;iA<20; iA++){ 
    if(ASrvc[iA]->getClave()==D){ //Este if con el for compara la clave que dio el usuario con las claves almacenadas para averiguar el servicio
    TM=iA;
    I=true; 
        }
    }

    if(I){ //este if compara el validador que usé (I) y si es true quiere decir que sí encontro el servicio y desplegara su informacion sino desplegara que no se encontro y se sale de la funcion
        ASrvc[TM]->muestra();
    }
    else {
        cout<<"No se encontro el servicio"; 
        return
         }
    for(int iA=0; iA<30; iA++){
        if(Res[iA].getClave()== D ){
cout<<"Hora de inicio "<<Res[iA].getHoraIni()<<'\n'<< "Hora de finalizado: "<< Res[iA].calculaHorafinReseracion();
        }
    }

    }

//-------------------------------------------Consultar lista de reservaciones----------------------------------------
void ConLiRes()//Opcion 2
{
    iCont = 0;
   do
   {
       //Imprimi los datos desados para la reserva.
        cout << "Clave de servicio: " << Res[iCont].getcveServicio() << '\n' << "Clave del cliente: " <<
        Res[iCont].getidCliente() << '\n' << "Hora de incio: " << Res[iCont].getHoraIni() << '\n' << "Hora final: " <<
        Res[iCont].getHoraIni() + Res[iCont].getDuracion() << '\n' << "Costo: "; 

        for (int i = 0; i < 20; i++)//Recorre todo el arreglo de servicio.
        {
            //Compara la clave de servicio del archivo de reserva.txt con el de servicios.txt guardados en los arreglos
            //para ver si es cancha o si es aparato.
            if (Res[iCont].getcveServicio() == ASrv[i] -> getClave())
            {
                //llama la funcion de calcula costo respectiva..
                cout << ASrv[i] -> calculaCosto(Res[iCont].getDuracion());
                break;//Termina el ciclo de for para que no haga cilos de mas.
            }
        }
        //Solo para que se vea ordenado.
        cout << '\n' << endl;

        iCont++;//Para cambiar de resercaiones y se repita el proceso.

    }while (Res[iCont].getidCliente() != 0);//Esto es para que no imprima todas las reservaciones vacias.
}
//-----------------------------------------------Consultar lista de servicio-----------------------------------
void ConDeLiServ()//Opcion 1
{
    for (int i = 0; i < 20; i++)//Recorre todo el archivo de servicio.
    {
        ASrv[i] -> muestra(); //El arreglo de apuntadores llama la funcion muestra respectiva
                              //segun sea cancha o reserva.
        cout << endl;//Para que se vea ordenado
    }
}
//------------------------------------------------------Menu----------------------------------------------------
int Menu()
{
    int iRes;
    //Opciones del menu.
    cout << "Esocge el numero opcion que desees"<< endl;
    cout << "1. Consultar la lista de Servicio" << '\n' <<
    "2. Consultar la lista de reserva" << '\n' << 
    "3. Consultar las reservaciones de un servicio dado" << '\n'
    << "4. Consultar las reservaciones de una hora especificada" <<
    '\n' << "5. Hacer una reservacion." << '\n' << "0 Terminar" << endl;
    cin >> iRes;
    
    return iRes;//Se regresa las opciones
}
//----------------------------------------------Carga de archivo Reserva----------------------------------------
void vCargaArchivoRe()
{
    iArc.open("Reserva.txt");//Abrimos el archivo Reserva.

    iCont = 0;//Ayuda en 0

    //Servicio >> Hora >> Minutos >> Tiempo en Minutos >> idCliente
    while(iArc >> S >> H >> M >> TM >> C)//Correra mientras reciba los datos.
    {
        Hora hm(H,M);//Declarmaos variable tipo hora.
        
        Reserva aRes(S, C, TM, hm);//Servicio, Cliente, TiempoMinutos, Hora.

        Res[iCont] = aRes;//Guardamos en el arreglo la variable declarada.

        iCont++;//Contador mas uno.
    }
    iArc.close();
}
//------------------------------------------------Carga de archivo Servicio----------------------------------------
void vCargaArchivoSe()
{
    iArc.open("Servicios.txt");//Abrimos el archivo Servicios.

    iCont = 0;//Ayuda para el arreglo.

    //Servicio >> Tiempo Maximos >>Tipo de Servicio >> costo.
    while (iArc >> S >> TM >> TS >> Co)//Correra mientras reciba los primero 4 datos.
    {
        if (TS == 'C' || TS == 'B' || TS == 'E') //Condicion para comprobar si es cancha o aparato.
        {   
            iArc >> CI;

            if (CI == 'F')//Se guarda false si no hay coach
                I = false;
            if (CI == 'T')//Se guarda true si hay coach
                I = true;

            getline(iArc, D);//Guardar descripcion o deporte en variable.

            //Servicio, TImepo Max, TipoServicio. costo, instructor, descirpcion. 
            ASrv[iCont] = new Aparato(S, TM, TS, Co, I, D);//lo guardamos en el arreglo.
        }
        else 
        {
            iArc >> M;//Guardamos la cantidad maxima en M

            getline(iArc, D);//Guardar descripcion o deporte en variable.

            //Servicio, TImepo Max, TipoServicio. costo, CantidadMax, descripcion. 
            ASrv[iCont] = new Cancha(S, TM, TS, Co, M, D);//lo guardamos en el arreglo.
        }
        iCont++;//Contador mas uno.
    }

    iArc.close();
}
//------------------------------------------------ Main ----------------------------------------//
int main()
{   
    int iR;

    //Cargar archivos por default.
    vCargaArchivoSe();//Archivos de Servicio.
    vCargaArchivoRe();//Archivo de Reserva.

    do 
    {
        iR = Menu();

        switch(iR)
        {
            case 1://Consultar lista de Servicio.
                ConDeLiServ();
                break;
            case 2://Consultar lista de Reservaciones.
                ConLiRes();
                break;
            case 3://Consultar las reservaciones por servicio.
            ConsReservServDado();
                //Llama la funciones como quieras.(Borrar comentario)
                break;
            case 4://Consulta reservaciones de una hora especifica.
            ConsReservHoraSp();
                //Llama la funciones como quieras.(Borrar comentario)
                break;
            case 5://Hacer una reservacion.
                HacerReserv();

                break;
        };

    }while(iR != 0);

    //Terminado el programa, se libera la memoria.
    delete [] &ASrv;

}