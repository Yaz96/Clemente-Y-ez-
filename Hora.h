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
    Hora operator+(int m);//Sumarle minutos a una hora.
    bool operator==(Hora h2);//Comaparar dos horas.
    bool operator>=(Hora h2);//Mayor igual que, entre horas.
    bool operator<=(Hora h2);//Menor igual que, entre horas.
    friend istream& operator>>(istream &is, Hora &h2);//Mayor Mayor, de horas.
    friend ostream& operator<<(ostream &os, Hora &h2);//Menor menor, de horas.

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
Hora Hora::operator+(int m)//Suma con minutos del usuario. (+)
{
    int iRelojAy1, iHrAy1, iMnAy1, iCont = 0;
    Hora rRelojSu;
    //Convertir las horas en puros minutos.
    iRelojAy1 = (hh * 60) + mm + m;
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
bool Hora::operator>=(Hora h2)//Checa que la hora sea mayor o igual a la recivida. (>=)
{
    if (((hh * 60) + mm) >= ((h2.getHora() * 60) + h2.getMinu()))//Comvierto los dos a minutos totales y los comparo.
        return true;
    else 
        return false;
}
bool Hora::operator<=(Hora h2)//Checa que la hora sea menor o igual a la recivida. (<=)
{
    if (((hh * 60) + mm) <= ((h2.getHora() * 60) + h2.getMinu()))//Comvierto los dos a minutos totales y los comparo. 
        return true;
    else 
        return false;
}
istream& operator>>(istream &is, Hora &h2)//Mayor Mayor de hora. (>>)
{
    is >> h2.hh;
    is >> h2.mm;
    return is;
}

ostream& operator<<(ostream &os, Hora &h2)//Menor, Menor de hora. (<<)
{
    int h = h2.hh, m = h2.mm;

    if (h < 10)//Cuando la hora sea < 10 poner un 0 antes.
        os << "0" << h;
    else
        os << h;

    os << ":";

    if (m < 10)//Cuando los minutos sean < 10 poner un 0 antes.
        os << "0" << m;
    else
        os << m;
    return os;
}
