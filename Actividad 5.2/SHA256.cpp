// SHA256.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Luis Alberto Alcántara Cabrales A01634185
//Elías Uriel Velázquez Rojas A01639716

#include <iostream>
using namespace std;
#include <vector>
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <string>
#include <bits.h>
#include <sstream>
#include <chrono>
#include <thread>
using namespace std::this_thread;
#include "HashTable.h"

int ip2int(string ip) { //Regresa primer valor entero de IP
    int rst = 0;
    int a, b, c, d;
    char t = '.';
    stringstream ss(ip);
    ss >> a >> t >> b >> t >> c >> t >> d;
    rst = (a);
    return rst;
}

int ip2int2(string ip) { //Regresa segundo valor entero de IP
    int rst = 0;
    int a, b, c, d;
    char t = '.';
    stringstream ss(ip);
    ss >> a >> t >> b >> t >> c >> t >> d;
    rst = (b);
    return rst;
}

int ip2int3(string ip) { //Regresa tercer valor entero de IP
    int rst = 0;
    int a, b, c, d;
    char t = '.';
    stringstream ss(ip);
    ss >> a >> t >> b >> t >> c >> t >> d;
    rst = (c);
    return rst;
}

int ip2int4(string ip) { //Regresa cuarto valor entero de IP
    int rst = 0;
    int a, b, c, d;
    char t = '.';
    stringstream ss(ip);
    ss >> a >> t >> b >> t >> c >> t >> d;
    rst = (d);
    return rst;
}

void HashF(string filename, celda arr[]) { //Llena el arbol
    string linea;
    int conteo = 0;
    celda ipA;
    char delimitador = ' ';
    char delimitador2 = '\13';
    int dirIpN = 0, dirIpP = 0;
    int dirIpN2 = 0, dirIpP2 = 0;
    int dirIpN3 = 0, dirIpP3 = 0;
    int dirIpN4 = 0, dirIpP4 = 0;
    string mes2 = "", dia2 = " ";
    string tiempo2 = " ", razon2 = " ";
    int n = 0;
    fstream archivo;
    archivo.open(filename);

    if (archivo.fail()) {
        cout << "Error al abrir archivo" << endl;
        return;
    }
    else {
        // Leemos todas las líneas
        while (getline(archivo, linea)) {
            stringstream stream(linea);  // Convertir la cadena a un stream
            string mes, dia, segundos, dirIP, razon, tiempo;
            // Extraer todos los valores de esa fila
            getline(stream, mes, delimitador);
            getline(stream, dia, delimitador);
            getline(stream, tiempo, delimitador);
            getline(stream, dirIP, delimitador);
            getline(stream, razon, delimitador2);
            //Se verifica si las IPs se repiten
            dirIpN = ip2int(dirIP);
            dirIpN2 = ip2int2(dirIP);
            dirIpN3 = ip2int3(dirIP);
            dirIpN4 = ip2int4(dirIP);
            if (dirIpP == 0 && dirIpP2 == 0 && dirIpP3 == 0 && dirIpP4 == 0) {
                dirIpP = dirIpN;
                dirIpP2 = dirIpN2;
                dirIpP3 = dirIpN3;
                dirIpP4 = dirIpN4;
            }
            if (dirIpN != dirIpP || dirIpN2 != dirIpP2 || dirIpN3 != dirIpP3 || dirIpN4 != dirIpP4 || archivo.eof()) {
                if (archivo.eof() && dirIpN == dirIpP && dirIpN2 == dirIpP2 && dirIpN3 == dirIpP3 && dirIpN4 == dirIpP4) {
                    n++;
                }
                if (n >= 2) {
                    ipA.accesos = n;
                    ipA.info = mes2 + " " + dia2 + " " + tiempo2 + " " + razon2 + " ";
                    ipA.ip = to_string(dirIpP) + "." + to_string(dirIpP2) + "." + to_string(dirIpP3) + "." + to_string(dirIpP4);
                    arr[conteo] = ipA;
                    conteo++;
                }
                n = 0;
            }
            n++;
            dirIpP = dirIpN;
            dirIpP2 = dirIpN2;
            dirIpP3 = dirIpN3;
            dirIpP4 = dirIpN4;
            mes2 = mes;
            dia2 = dia;
            tiempo2 = tiempo;
            razon2 = razon;
        }
    }
    archivo.close();
}

void insert(celda ip, int cant, celda arr[]) {

    int indice = ip.accesos;
    bool ocupado_bool = false;

    while (ocupado_bool == false) {
        if (arr[indice].miEstado == vacio || arr[indice].miEstado == borrado) {
            ocupado_bool = true;
            arr[indice].ip = ip.ip;
            arr[indice].info = ip.info;
            arr[indice].miEstado = ocupado;
        }
        else {
            indice = (indice + 1)%10;
        }
    }
}

void mostrar(int cant, celda arr[]) {
    for (int n = 0; n < cant; n++) { // O (n)
        cout << n << " " << arr[n].ip << endl;
    }
}

void findKey(string ip, int cant, celda arr[]) {
    int p = 0;
    for (int n = 0; n < cant; n++) { // O (n)
        if (arr[n].ip == ip) {
            cout << "Index " << n << ": " << arr[n].ip << " " << arr[n].info << endl;
            p++;
        }
    }
    if (p == 0)
        cout << "IP no encontrada" << endl;
}

int main()
{
    int cantidad = 10;
    celda arr[10];
    string filename;
    filename = "bitacora Bueno.txt";
    HashTable ht(10);
    celda array[10];
    int listo = 0;
    string IP ;
    int opcion = 0;
    int c;

    while (opcion != 4) {
        cout << "Actividad Integral sobre el uso de codigos hash" << endl;
        if (listo == 0) {
            cout << "*Para ver mas opciones, primero ingresa valores o datos a las tablas*" << endl;
            cout << endl;
            cout << "1. Insertar elementos de archivo en tablas de Hash" << endl;
            cout << "4. Salir" << endl;
        }
        else
        {
            cout << endl;
            cout << "1. Insertar elementos de archivo en tablas de Hash" << endl;
            cout << "2. Ver Hash Tables" << endl;
            cout << "3. Buscar IP en tablas" << endl;
            cout << "4. Salir" << endl;
        }
        cout << endl;
        cout << "Escribe la opcion deseada: ";
        cin >> opcion;
        if (opcion == 1) {
            if (listo == 1) {
                cout << endl;
                cout << "Ya no puedes insertar mas elementos a las tablas" << endl;
                cout << endl;
            }
            else {
                cout << endl;
                cout << "--- Insertar elementos del archivo en tablas de Hash ---" << endl;
                cout << endl;
                cout << "Agregando elementos en tabla ..." << endl;
                for (int i = 0; i < cantidad; i++) { // O (n)
                    arr[i].miEstado = vacio;
                    arr[i].ip = "";
                    arr[i].info = "";
                    arr[i].accesos = 0;
                }

                for (int i = 0; i < cantidad; i++) { // O (n)
                    array[i].miEstado = vacio;
                    array[i].ip = "";
                    array[i].info = "";
                    array[i].accesos = 0;
                }

                HashF(filename, arr);

                for (int i = 0; i < cantidad; i++) { // O (n)
                    insert(arr[i], cantidad, array);
                }

                for (int i = 0; i < 10; i++) // O (n)
                    ht.insertElement(arr[i]);

                sleep_for(1s);
                cout << endl;
                cout << "Hash tables generados correctamente" << endl;
                listo++;
                cout << endl;
            }
        }
        else if (opcion == 2) {
            cout << endl;
            cout << "-*- Hash Tables -*-" << endl;
            cout << endl;
            cout << "<< Hash Table Chain >>" << endl;
            cout << endl;
            ht.printAll();
            cout << endl;
            cout << "<< Hash Table Prueba lineal >>" << endl;
            cout << endl;
            mostrar(cantidad, array);
            cout << endl;
        }
        else if (opcion == 3) {
            cout << endl;
            cout << "Introduce correctamente la IP a buscar (sin el puerto, sin :xxxx): " << endl;
            cout << "SI -> 1.6.378.65, NO -> 1.6.378.65:6772" << endl;
            cout << ">>> ";
            cin >> IP;
            cout << endl;
            cout << "<< Hash Table Chain >>" << endl;
            cout << endl;
            ht.buscarIP(IP);
            cout << endl;
            cout << "<< Hash Table Prueba lineal >>" << endl;
            cout << endl;
            findKey(IP, cantidad, array);
            cout << endl;
        }
        else if (opcion == 4) {
            cout << endl;
            cout << "Saliendo..." << endl;
            break;
        }
        else{
            cout << "\nEnter correct option\n";
            cout << endl;
        }
    }
    return 0;
}
