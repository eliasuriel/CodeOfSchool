#ifndef COMPRA_H
#define COMPRA_H
#include "Cliente.h"
#include "Producto.h"
#include "Pago.h"
#include <string>

class Compra {
public:
    Compra();
    Compra(Cliente, Producto, int, std::string, std::string, Pago);
    Cliente getCliente() const;
    void setCliente(Cliente);
    Producto getProducto() const;
    void setProducto(Producto);
    int getCantidad() const;
    void setCantidad(int);
    std::string getFechaC() const;
    void setFechaC(std::string);
    std::string getFechaE() const;
    void setFechaE(std::string);
    Pago getPago() const;
    void setPago(Pago);
    void imprime();
    void registraCompra(int);
   
private:
    Cliente cliente;
    Producto producto;
    int cantidad;
    std::string fechaCompra;
    std::string fechaEntrega;
    Pago pago;
};

//Constructor por Default
Compra::Compra(){
    cantidad = 0;
    fechaCompra = "02/11/20";
    fechaEntrega = "08/11/20";
}
//Constructor con parámetros
Compra::Compra(Cliente client, Producto pro, int cant, std::string fechaC, std::string fechaE, Pago pag){
    cliente = client;
    producto = pro;
    fechaCompra = fechaC;
    fechaEntrega = fechaE;
    pago = pag;
}
//GETTERS Y SETTERS de los atributos
Cliente Compra::getCliente() const{
    return cliente;
}
void Compra::setCliente(Cliente client){
    cliente = client;
}
Producto Compra::getProducto() const{
    return producto;
}
void Compra::setProducto(Producto pro){
    producto = pro;
}
int Compra::getCantidad() const{
    return cantidad;
}
void Compra::setCantidad(int cant){
    cantidad = cant;
}
std::string Compra::getFechaC() const{
    return fechaCompra;
}
void Compra::setFechaC(std::string fechaC){
    fechaCompra = fechaC;
}
std::string Compra::getFechaE() const{
    return fechaEntrega;
}
void Compra::setFechaE(std::string fechaE){
    fechaEntrega = fechaE;
}
void Compra::registraCompra(int com){
    if(com > 0){
        cantidad = cantidad + com;
    }

}
#endif