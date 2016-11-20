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
string S, D;
int TM, C, M, H, iCont;
double Co;
char TS, CI;
bool I;

//--------------------------------------------Hacer una reservacion-----------------------------------------------

    //Aqui escribe tu codigo(Borrar comentario)

//--------------------------------------Consulta reservaciones de una hora especifica.------------------------
    void ConsReservHoraSp(){
        



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
    for(int iA=0; iA<6; iA++){
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
            ConsReservHoraSp()
                //Llama la funciones como quieras.(Borrar comentario)
                break;
            case 5://Hacer una reservacion.
                //Llama la funciones como quieras.(Borrar comentario)
                break;
        };

    }while(iR != 0);

    //Terminado el programa, se libera la memoria.
    delete [] &ASrv;

}