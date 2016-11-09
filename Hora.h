// falta de terminar los operadores >= y <=
class Hora
{
public:
    //Defaults
    Hora(); //Sin parametros.
    Hora(int h, int m); //Con parametros.
    //Gets
    int getHora(); //de hora.
    int getMinu();//de minutos.
    //Sets
    void setHora(int h); //de hora.
    void setMinu(int m);// de minutos
    //Print
    void print();
    //Sobrecargas
    Reloj operator+(int m); //Sumarle minutos a una hora.
    bool operator==(Hora h2); //Comaparar dos horas.

private:
    int hh, mm;
};
//--------------------------------------------Defaults--------------------------------------------------
Hora::Hora(){
    hh=0;
    mm= 0;
}

Hora::Hora(int h, int m){
    hh=h;
    mm=m;
}
//----------------------------------------------Gets-----------------------------------------------------
int Hora::getHora(){
    return hh;
}
int Hora::getMinu(){
    return mm;
}
//-----------------------------------------------Sets------------------------------------------------------
void Hora::setHora(int h){
    hh=h;
}
void Hora::setMinu(int m){
    mm=m;
}
//----------------------------------------------Print-------------------------------------------------------
void Hora::print(){
    if(hh<10){
        cout<<"0";
    }
    cout<<hh<<":";
    if(mm<10)
        cout<<"0";
    cout<<mm;
}
//-------------------------------------------Sobrecargas-----------------------------------------------------
Hora Hora::operator+(int m)//Suma con minutos del usuario.  (+)
{
    int iRelojAy1, iHrAy1, iMnAy1, iCont = 0;
    Reloj rRelojSu;
    //Convertir las horas en puros minutos.
    iRelojAy1 = (hora * 60) + minu + m;
    iHrAy1 = iRelojAy1 / 60;
    iMnAy1 = iRelojAy1 % 60;
    
    //Para evitar que la hora se pase de 24
    if (iRelojAy1 > 1380)
    {
        for (int i = 24; i < iHrAy1; i++)
        {
            iCont++;
        }
        rRelojSu.setHora(iCont);
    }
    else
    {
        if (iHrAy1 == 24)
        {
            iHrAy1 = 0;
        }
        rRelojSu.setHora(iHrAy1);
    }
    rRelojSu.setMinu(iMnAy1);
    return rRelojSu;//Regresa una hora.
}
bool Hora::operator==(Hora h2)//Compara que dos horas sean iguales. (==)
{
    if(hh==h2.getHora()&& mm==h2.getMinu())
    return true;
    else
        return false;
}
