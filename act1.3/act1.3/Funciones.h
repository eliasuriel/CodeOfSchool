#pragma once
#include <iostream>
using namespace std;
#include <vector>

struct Registro {
    int mes = 0;
    int dia = 0;
    int hora = 0;
    int minutos = 0;
    int segundos = 0;
    string ip = "";
    string razon = "";
};

class Funciones
{
public:
    //Ordena meses de menor a mayor:
    static void ordenaBurbujaMes(vector <Registro>&, vector <string>&);
    //Ordena dias de menor a mayor:
    static void ordenaBurbujaDia(vector <Registro>&, vector <string>&, int, int);
    //Ordena horas de menor a mayor:
    static void ordenaBurbujaHora(vector <Registro>&, vector <string>&, int, int);
    //Ordena minutos de menor a mayor:
    static void ordenaIntercambioMinutos(vector <Registro>&, vector <string>&, int, int);
    //Ordena los segundos de menor a mayor:
    static void ordenaIntercambioSegundos(vector <Registro>&, vector <string>&, int, int);
    //Busca indice del mes y dia ingresados:
    static int busqSecuencial(vector <Registro>&, int, int);

    static int busquedaEspecifico(vector <Registro>&, int, int, int);
private:
    static void swap(string*, string*);
    static void swap2(Registro*, Registro*);
};

