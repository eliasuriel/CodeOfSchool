#pragma once
#include <iostream>
using namespace std;
#include <vector>

struct Registro { //Para establecer valores de la informacion
    string mes = "";
    int dia = 0;
    string tiempo = "";
    int ip1 = 0;
    int ip2 = 0;
    int ip3 = 0;
    int ip4 = 0;
    int ip5 = 0;
    string razon = "";
};

struct Registro2 { //Para establecer valores de la informacion
    int ip1 = 0;
    int ip2 = 0;
    int ip3 = 0;
    int ip4 = 0;
    int ip5 = 0;
};

class Funciones
{
public:
    static void ordenaIntercambioIP1(vector <Registro>&, vector <string>&);
    static void ordenaIntercambioIP2(vector <Registro>&, vector <string>&, int, int);
    static void ordenaIntercambioIP3(vector <Registro>&, vector <string>&, int, int);
    static void ordenaIntercambioIP4(vector <Registro>&, vector <string>&, int, int);
    static int busqBinaria(vector<Registro>&, int, int, int, int, int);
private:
    static int busquedaEspecifico(vector <Registro>&, int, int, int, int, int, int, int);
};

