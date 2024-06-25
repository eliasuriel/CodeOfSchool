#ifndef CLIENTE_H
#define CLIENTE_H
#include <string>

class Cliente{
public:
    Cliente();
    Cliente(std::string,std::string,std::string,int,int);
    std::string getNombreC() const;
    void setNombreC(std::string);
    std::string getApellido() const;
    void setApellido(std::string);
    std::string getCalle() const;
    void setCalle(std::string);
    int getNumCasa() const;
    void setNumCasa(int);
    int getIdC() const;
    void setIdC(int);
    void imprimirCliente();
private:
    std::string nombreC;
    std::string apellido;
    std::string calle;
    int idC;
    int numcasa;
};
Cliente::Cliente(){
    nombreC = "";
    apellido = "";
    calle = "";
    idC = 0;
    numcasa=0;
}
Cliente::Cliente(std::string nom, std::string ape, std::string cal, int id,int num){
    nombreC = nom;
    apellido = ape;
    calle = cal;
    idC = id;
    numcasa=num;
}
void Cliente::setNombreC(std::string nom){
    nombreC = nom;
}
std::string Cliente::getNombreC() const{
    return nombreC;
}
void Cliente::setApellido(std::string ape){
    apellido = ape;
}
std::string Cliente::getApellido() const{
    return apellido;
}
void Cliente::setCalle(std::string cal){
    calle = cal;
}
std::string Cliente::getCalle() const{
    return calle;
}

void Cliente::setNumCasa(int num){
    numcasa = num;
}
int Cliente::getNumCasa() const{
    return numcasa;
}
void Cliente::setIdC(int id){
    idC = id;
}
int Cliente::getIdC() const{
    return idC;
}
void Cliente::imprimirCliente(){
    cout << "Nombre de cliente: " << nombreC << " " << apellido << endl;
    cout << "Calle " << calle << " Numero de casa "<< numcasa << endl;
}
#endif