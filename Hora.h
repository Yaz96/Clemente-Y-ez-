//Rodrigo modifico esto para prueba.
class Hora
{
private:
    int hh, mm;
    
public:
    Hora();
    Hora(int h, int m);
    int getHora();
    int getMinu();
    void setHora(int h);
    void setMinu(int m);
    void print();
    bool operator==(Hora horados);

};

Hora::Hora(){
    hh=0;
    mm= 0;
}

Hora::Hora(int h, int m){
    hh=h;
    mm=m;
}

int Hora::getHora(){
    return hh;
}
int Hora::getMinu(){
    return mm;
}
void Hora::setHora(int h){
    hh=h;
}
void Hora::setMinu(int m){
    mm=m;
}

void Hora::print(){
    if(hh<10){
        cout<<"0";
    }
    cout<<hh<<":";
    if(mm<10)
        cout<<"0";
    cout<<mm;
}

bool Hora::operator==(Hora horados){
    if(hh==horados.getHora()&& mm==horados.getMinu())
    return true;
    else
        return false;
}






