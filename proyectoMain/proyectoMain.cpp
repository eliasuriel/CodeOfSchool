#include <iostream>
#include <fstream>
#include <string>
using namespace std;
#include "Compra.h"
#include "Producto.h"
#include "Cliente.h"
#include "Pago.h"

// Realizada por Marisol Rodriguez Mejia
void registrarProductos(Producto listaPro[], int &cantPro) {
    int idPro;
    string nombrePro;
    float precio;
    cantPro = 0; //inicializar a 0 para poder acumular
    ifstream archivo; //para la lectura del archivo (flujo de entrada)
    archivo.open("Productos.txt");
    while(archivo >> idPro >> nombrePro >> precio ){
        listaPro[cantPro].setIdPro(idPro);
        listaPro[cantPro].setNombrePro(nombrePro);
        listaPro[cantPro].setPrecio(precio);
        cantPro++;
    }
    archivo.close();
}
// Realizada por Marisol Rodriguez Mejia
void mostrarProductos(Producto listaPro[], int cantPro) {
    cout << "\nPRODUCTOS DISPONIBLES\n" << endl;
    cout << "Id - Nombre:  Precio\n---------------------" << endl;
    for (int i = 0; i < cantPro; i++){
        listaPro[i].imprimirProducto();
    }
}
// Realizada por Marisol Rodriguez Mejia
int buscarProducto(Producto listaPro[], int cantPro, int idProABuscar) {
    for (int i = 0; i < cantPro; i++){
        if (listaPro[i].getIdPro() == idProABuscar){
            return i;
        }
    }
    return -1;
}
// Realizada por Elías Uriel Velázquez Rojas
void eliminarCompras(Producto listaPro[], Compra listaCompra[], int cantPro, int &cantCompra, Cliente cliente, Pago pago, float &add, float &aux){

    int idProCompra;
    int k;
    int idProduc;
    do{
        cout<<"\t>>Que compra desea eliminar...de 1 hasta "<<cantCompra<<": ";
        cin >> k;
        k = k-1;
        if(k>(cantCompra-1)||k<0)
        cout<<">> Ingrese una posicion valida"<<endl;
        idProduc = listaCompra[k].getProducto().getIdPro();

    }while(k>(cantCompra-1)||k<0);
    for(int i=k;i<cantCompra;i++)
    {
        listaCompra[i]=listaCompra[i+1];
        }
        //aux = listaCompra[k].getProducto().getPrecio();
        aux = listaPro[idProduc-1].getPrecio();
        add = add- aux;
     cantCompra--;
}
// Realizada por Elías Uriel Velázquez Rojas
void registrarPago(Pago pago, Cliente cl,Compra listaCompra[], int cantCompra, float &add){
    string numTarjeta, venceAnio, cvv, decis, calle;
    int dc, mc, numc, direct2,venceMes;
    float precio;
    int diac,mesc;
    Pago tarj;
    string direct;

    cout << "Numero de tarjeta (12 digitos): ";
    cin >> numTarjeta;
    pago.setNumTarjeta(numTarjeta);
    cout << "Numero de mes en que vence: ";
    cin >> venceMes;
    while(venceMes>=13){
        cout <<"Mes no existente , introduzca de nuevo el mes: ";
        cin >> venceMes;
    }
    pago.setVenceMes(venceMes);
    cout << "Anio en que vence: ";
    cin >> venceAnio;
    pago.setVenceAnio(venceAnio);
    cout << "CVV (4 digitos): ";
    cin >> cvv;
    pago.setCvv(cvv);
    cout << "Numero de dia actual (1 - 31): ";
    cin >> diac;
    while(diac>=32){
        cout <<"Dia no existente , introduzca de nuevo el dia: ";
        cin >> diac;
    }
    pago.setDiaCompra(diac);
    cout << "Numero de mes actual (1 - 12): ";
    cin >> mesc;
    while(mesc>=13){
        cout <<"Mes no existente , introduzca de nuevo el mes: ";
        cin >> mesc;
    }
    pago.setMesCompra(mesc);
    cout << "Ingresa tu calle: ";
    cin >> calle;
    cl.setCalle(calle);
    cout << "\nIngresa tu numero de casa: ";
    cin >> numc;
    cl.setNumCasa(numc);
    cout << "-----------------------------------" << endl;
    cl.imprimirCliente();
    cout << "\nProductos a comprar:" << endl;
    for(int i = 0; i < cantCompra; i++){
        listaCompra[i].getProducto().imprimirProducto();
    }
    cout << endl;
    cout << "TOTAL $"<< add << ".00" << endl;
    cout << "Confirmar pago? Si/No: ";
    cin >> decis;
    if (decis == "SI" || decis=="si"|| decis=="Si"){
        dc = pago.getDiaCompra();
        mc = pago.getMesCompra();
        direct = cl.getCalle();
        direct2 = cl.getNumCasa();
        cout << "\n---Metodo de Pago---" << endl ;
        cout << "Numero de tarjeta: " << pago.getNumTarjeta() << "\nVence: "<<pago.getVenceMes()<<"/"<<pago.getVenceAnio() <<"\nCVV: "<< pago.getCvv() << endl;
        cout << endl;
        cout << "Fecha de entrega: "<< dc << "/"<< mc << endl;
        cout << "\nDireccion: "<< direct << " #" << direct2 <<endl;
        cout << "\nMonto: " << endl;
        cout << "$"<< add << ".00" << endl;
        cout << "\nPAGO COMPLETADO\n\n";
    }
}
// Realizada por Marisol Rodriguez Mejia
void crearCompra(Producto listaPro[], Compra listaCompra[], int cantPro, int &cantCompra, Cliente cliente, Pago pago, float &add){
    int idProCompra;
    int num;
    do{
        cout << "\nTeclea el id del producto: ";
        cin >> idProCompra;
        num = buscarProducto(listaPro, cantPro, idProCompra);
        } while(num == -1);
    cantCompra++;
    int j = cantCompra - 1;
    listaCompra[j].setProducto(listaPro[num]);
    listaCompra[j].setCliente(cliente);
    add = add + listaPro[num].getPrecio();
    //pago.setTotal(add);
}
int buscarCompras( Compra listaCompra[], int cantPro,int idProCompra){
    for (int i=0; i < cantPro;i++){
        if(listaCompra[i].getProducto().getIdPro()== idProCompra){
            cout << i;
            return i;

        }
    }
    return -1;
}
// Realizada por Elías Uriel Velázquez Rojas
void imprimirCompras(Cliente cl,Compra listaCompra[], int cantCompra, float &add){
    cout << "Compras de " << cl.getNombreC() << " " << cl.getApellido() << "\n" << endl;
    for(int i = 0; i < cantCompra; i++){
        cout <<"Compra #"<< i+1 <<" "<< " Id-",listaCompra[i].getProducto().imprimirProducto();
    }
    cout << "\nTotal de la/las compras ";
    cout << "$"<< add << ".00" << endl;
}
// Realizada por Elías Uriel Velázquez Rojas y Marisol Rodriguez Mejia
int main() {
    Producto listaPro[20];
    Compra listaCompra[20];
    int cantPro = 0;
    int cantCompra = 0;
    int pro;
    float add = 0;
    float aux = 0;
    Pago pag;
    Cliente cliente;
    char opcion;
    string resp, nom, appel, dire;
    int k;
    registrarProductos(listaPro, cantPro);
    
    cout <<"\nHOLA, BIENVENIDO A LAS COMPRAS QUE TE SALVARAN <3"<< endl;
    Cliente cl1;
    cout << "\nIngresa tu nombre: ";
    cin >> nom;
    cout << "\nIngresa tu apellido: ";
    cin >> appel;

    cl1.setNombreC(nom);
    cl1.setApellido(appel);

    do {
        cout << endl;
        cout << "---- Opciones disponibles ----\n" << endl;
        cout << "1) Consultar productos  " << endl;
        cout << "2) Realizar compras   " << endl;// 1 clase
        cout << "3) Consultar compras y/o cancelar compra" << endl;//2clases
        cout << "4) Hacer pago "<< endl;
        cout << "5) Terminar de comprar" << endl;

        cout << "\nOpcion elegida: ";
        cin >> opcion;
        
    switch (opcion) {
            case '1':
                mostrarProductos(listaPro, cantPro);
                cout << endl;
                break;
            case '2':
                crearCompra(listaPro, listaCompra, cantPro, cantCompra, cliente, pag, add);
                cout << endl;
                
                break;
            case '3': 
                imprimirCompras(cl1,listaCompra, cantCompra,add);
                cout << endl;
                cout << "Gusta cancelar alguna compra? Si/No: ";
                cin >> resp;
                if (resp == "SI" || resp=="si"|| resp=="Si"){
                    eliminarCompras(listaPro, listaCompra, cantPro, cantCompra, cliente, pag, add,aux);
                    cout << endl;
                }
                else{
                    cout << "Compras conservadas"<< endl;
                }
                break;
            
            case '4':
                cout <<"\nPago en proceso...\n" << endl;
                registrarPago(pag,cl1,listaCompra, cantCompra,add);
                break;
           
            case '5':
                cout << "\nGracias por comprar :)\n" << endl;
                break;
            
            default:
                cout << "Opcion invalida, seleccione alguna opcion del 1 al 5."<<endl;
        }
    } while (opcion != '5');
    return 0;
}