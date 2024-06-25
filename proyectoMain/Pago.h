#ifndef PAGO_H
#define PAGO_H
#include <string>
#include <iostream>
class Pago {
public:
    Pago();
    Pago(float,std::string,int,std::string,std::string,int,int);
    float getTotal() const;
    void setTotal(float);
    int getDiaCompra() const;
    void setDiaCompra(int);
    int getMesCompra() const;
    void setMesCompra(int);
    std::string getNumTarjeta() const;
    void setNumTarjeta(std::string);
    int getVenceMes() const;
    void setVenceMes(int);
    std::string getVenceAnio() const;
    void setVenceAnio(std::string);
    std::string getCvv() const;
    void setCvv(std::string);
    void imprimirTotal();
    

private:
    float total;
    std::string numTarjeta;
    int venceMes;
    std::string venceAnio;
    std::string cvv;
    int diacompra;
    int mescompra;
    

};
Pago::Pago(){
    total = 0.00;
    numTarjeta = "XXX XXXXX XXXX";
    venceMes = 0;
    venceAnio = "-";
    cvv = "**";
    diacompra=0;
    mescompra=0;
}
Pago::Pago(float tot, std::string numt, int vencem, std::string vencea, std::string codigo, int diac, int mesc){

    total = tot;
    numTarjeta = numt;
    venceMes = vencem;
    venceAnio = vencea;
    cvv = codigo;
    diacompra=diac;
    mescompra=mesc;
}
void Pago::setDiaCompra(int diac){
    diacompra = diac;
}
int Pago::getDiaCompra() const{
    return diacompra;
}
void Pago::setMesCompra(int mesc){
    mescompra = mesc;
}
int Pago::getMesCompra() const{
    return mescompra;
}

void Pago::setTotal(float tot){
    total = tot;
}
float Pago::getTotal() const{
    return total;
}
void Pago::setNumTarjeta(std::string numt){
    numTarjeta = numt;
}
std::string Pago::getNumTarjeta() const{
    return numTarjeta;
}
void Pago::setVenceMes(int vencem){
    venceMes = vencem;
}
int Pago::getVenceMes() const{
    return venceMes;
}
void Pago::setVenceAnio(std::string vencea){
    venceAnio = vencea;
}
std::string Pago::getVenceAnio() const{
    return venceAnio;
}
void Pago::setCvv(std::string codigo){
    cvv = codigo;
}
std::string Pago::getCvv() const{
    return cvv;
}
void Pago::imprimirTotal(){
    cout << "Total de la compra: $" << total << endl;
}


#endif