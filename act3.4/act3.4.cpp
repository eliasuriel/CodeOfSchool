// Act 3.4.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Equipo:
// Luis Alberto Alcántara Cabrales A01634185
// José Antonio León Navarro A01639250
// Elias Uriel Velázquez Rojas A01639716

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
using namespace std::chrono;
#include "Tree.h"
#include "TreeNode.h"

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

void llenarArbol(string filename) { //Llena el arbol
    string linea;
    char delimitador = ' ';
    char delimitador2 = '\13';
    Tree tree;
    int dirIpN = 0, dirIpP = 0;
    int dirIpN2 = 0, dirIpP2 = 0;
    int dirIpN3 = 0, dirIpP3 = 0;
    int dirIpN4 = 0, dirIpP4 = 0;
    int n = 0;
    fstream archivo;
    archivo.open(filename);

    if (archivo.fail()) {
        cout << "Error al abrir archivo" << endl;
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
                bst ipA;
                ipA.accesos = n;
                ipA.dirIP = to_string(dirIpP) + "." + to_string(dirIpP2) + "." + to_string(dirIpP3) + "." + to_string(dirIpP4) + " ";
                tree.insertNode(ipA);
                n = 0;
            }
            n++;
            dirIpP = dirIpN;
            dirIpP2 = dirIpN2;
            dirIpP3 = dirIpN3;
            dirIpP4 = dirIpN4;
        }
    }
    archivo.close();
    tree.inorderTraversal();
}

int main()
{
    Tree miArbol;
    string filename;
    filename = "archivo nuevo.txt";
    llenarArbol(filename);// Crear lista
    return 0;
}


