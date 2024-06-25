#ifndef PRODUCTO_H
#define PRODUCTO_H
#include <string>

class Producto {
public:
    Producto();
    Producto(int, std::string, float);
    int getIdPro() const;
    void setIdPro(int id);
    std::string getNombrePro() const;
    void setNombrePro(std::string nom);
    float getPrecio() const;
    void setPrecio(float);
    void imprimirProducto();
private:
    int idPro;
    std::string nombrePro;
    float precio;
};
//Constructor por Default
Producto::Producto(){
    idPro = 0;
    nombrePro = "N/A";
    precio = 0.00;
}
//Constructor con parámetros
Producto::Producto(int id, std::string nom, float pre){
    idPro = id;
    nombrePro = nom;
    precio = pre;
}
//GETTERS Y SETTERS de los atributos
int Producto::getIdPro() const{
    return idPro;
}
void Producto::setIdPro(int id){
    idPro = id;
}
std::string Producto::getNombrePro() const{
    return nombrePro;
}
void Producto::setNombrePro(std::string nom){
    nombrePro = nom;
}
float Producto::getPrecio() const{
    return precio;
}
void Producto::setPrecio(float pre){
    precio = pre;
}
void Producto::imprimirProducto(){
    std::cout << idPro << " - " << nombrePro << ": $" << precio << ".00" << std::endl;
}
#endif