// Equipo:
// Luis Alberto Alcántara Cabrales A01634185
// José Antonio León Navarro A01639250
// Elias Uriel Velázquez Rojas A01639716

#include <iostream>
using namespace std;
#include <vector>
#include <fstream>
#include "Funciones.h"
#include <iostream>
#include <cstdlib>
#include <string>
#include <bits.h>
#include <sstream>
#include <chrono>
#include <thread>
using namespace std::this_thread;
using namespace std::chrono;

//Llena el vector con los valores del archivo
bool llenarVector(vector<Registro>& vect, int& cantDatos, vector<string>& vect2) {
    string linea;
    char delimitador = ' ';
    char delimitador2 = '\13';
    int i = 0, ncali = 0, ntemp = 0;
    fstream archivo;
    archivo.open("bitacora Bueno.txt");

    if (archivo.fail()) {
        cout << "Error al abrir archivo" << endl;
        return true;
    }
    else {
        while (getline(archivo, linea)) {
            Registro r;
            stringstream stream(linea);
            vect2.push_back(linea);
            cantDatos++;
            string mes, dia, hora, minutos, segundos, ip1, ip2, ip3, ip4, ip5, razon, tiempo;
            getline(stream, mes, delimitador);
            r.mes = mes;
            getline(stream, dia, delimitador);
            r.dia = stoi(dia);
            getline(stream, tiempo, delimitador);
            r.tiempo = tiempo;
            getline(stream, ip1, '.');
            r.ip1 = stoi(ip1);
            getline(stream, ip2, '.');
            r.ip2 = stoi(ip2);
            getline(stream, ip3, '.');
            r.ip3 = stoi(ip3);
            getline(stream, ip4, ':');
            r.ip4 = stoi(ip4);
            getline(stream, ip5, delimitador);
            r.ip5 = stoi(ip5);
            getline(stream, razon, delimitador2);
            r.razon = razon;
            vect.push_back(r);
        }
        return false;
    }
}

void ordenaIP2(vector<Registro>& vect, int& cantDatos, vector<string>& vect2) {
    int start = 0;
    int finish = 0;
    int indice = 0;
    int ini = 0;
    start = vect[0].ip1;
    finish = vect[cantDatos - 1].ip1;
    for (int i = start; i < finish; i++) {
        while (vect[indice].ip1 == i) {
            indice++;
        }
        Funciones::ordenaIntercambioIP2(vect, vect2, ini, indice);
        ini = indice;
        indice++;
    }
    if (vect[indice].ip1 == finish) {
        Funciones::ordenaIntercambioIP2(vect, vect2, ini, vect.size());
    }
}

void ordenaIP3(vector<Registro>& vect, int& cantDatos, vector<string>& vect2) {
    int start = 0;
    int start2 = 0;
    int ini = 0;
    for (int i = 0; i < vect.size(); i++) {
        start = vect[i].ip2;
        start2 = vect[i].ip1;
        if (vect[i].ip1 == vect[cantDatos - 1].ip1 && vect[i].ip2 == vect[cantDatos - 1].ip2) {
            Funciones::ordenaIntercambioIP3(vect, vect2, ini, vect.size());
        }
        else {
            while (vect[i].ip2 == start && vect[i].ip1 == start2) {
                i++;
            }
            Funciones::ordenaIntercambioIP3(vect, vect2, ini, i);
            ini = i;
            i--;
        }

    }
}

void ordenaIP4(vector<Registro>& vect, int& cantDatos, vector<string>& vect2) {
    int start = 0;
    int start2 = 0;
    int start3 = 0;
    int ini = 0;
    for (int i = 0; i < vect.size(); i++) {
        start = vect[i].ip3;
        start2 = vect[i].ip2;
        start3 = vect[i].ip1;
        if (vect[i].ip1 == vect[cantDatos - 1].ip1 && vect[i].ip2 == vect[cantDatos - 1].ip2 && vect[i].ip3 == vect[cantDatos - 1].ip3) {
            Funciones::ordenaIntercambioIP4(vect, vect2, ini, vect.size());
        }
        else {
            while (vect[i].ip3 == start && vect[i].ip2 == start2 && vect[i].ip1 == start3) {
                i++;
            }
            Funciones::ordenaIntercambioIP4(vect, vect2, ini, i);
            ini = i;
            i--;
        }

    }
}

int ordenarDatos(vector<Registro>& vect, int& cantDatos, vector<string>& vect2) {
    Funciones::ordenaIntercambioIP1(vect, vect2);
    ordenaIP2(vect, cantDatos, vect2);
    ordenaIP3(vect, cantDatos, vect2);
    ordenaIP4(vect, cantDatos, vect2);
    return 20;
}

void consultaInfo(vector<Registro>& vect, vector<string>& vect2) {
    int ip;
    int indice1, indice2;
    Registro2 direcIP1, direcIP2;
    cout << "Consulta informacion de rango de IPs" << endl;
    cout << endl;
    cout << "Información importante: " << endl;
    cout << "Una IP esta compuesta por 5 valores (###.##.###.###:####) separados por puntos y dos puntos (colon)" << endl;
    cout << "###(valor 1).##(valor 2).###(valor 3).###(valor 4):####(valor 5)" << endl;
    cout << endl;
    cout << "Ingrese rango de IPs: " << endl;
    cout << "Desde: " << endl;
    for (int i = 0; i < 5; i++) {
        cout << "Valor " << i + 1 << " de IP 1: ";
        cin >> ip;
        if (i == 0) {
            direcIP1.ip1 = ip;
        }
        else if (i == 1) {
            direcIP1.ip2 = ip;
        }
        else if (i == 2) {
            direcIP1.ip3 = ip;
        }
        else if (i == 3) {
            direcIP1.ip4 = ip;
        }
        else {
            direcIP1.ip5 = ip;
        }
    }
    cout << "IP ingresado -> " << direcIP1.ip1 << "." << direcIP1.ip2 << "." << direcIP1.ip3 << "." << direcIP1.ip4 << ":" << direcIP1.ip5 << endl;
    cout << "Hasta: " << endl;
    for (int i = 0; i < 5; i++) {
        cout << "Valor " << i + 1 << " de IP 1: ";
        cin >> ip;
        if (i == 0) {
            direcIP2.ip1 = ip;
        }
        else if (i == 1) {
            direcIP2.ip2 = ip;
        }
        else if (i == 2) {
            direcIP2.ip3 = ip;
        }
        else if (i == 3) {
            direcIP2.ip4 = ip;
        }
        else {
            direcIP2.ip5 = ip;
        }
    }
    cout << "IP ingresado -> " << direcIP2.ip1 << "." << direcIP2.ip2 << "." << direcIP2.ip3 << "." << direcIP2.ip4 << ":" << direcIP2.ip5 << endl;
    indice1 = Funciones::busqBinaria(vect, direcIP1.ip1, direcIP1.ip2, direcIP1.ip3, direcIP1.ip4, direcIP1.ip5);
    indice2 = Funciones::busqBinaria(vect, direcIP2.ip1, direcIP2.ip2, direcIP2.ip3, direcIP2.ip4, direcIP2.ip5);
    if (indice1 == -1 || indice2 == -1) {
        cout << endl;
        cout << "No se encontro la IP o las IPs ingresadas" << endl;
    }
    else {
        if (direcIP1.ip1 > direcIP2.ip1) {
            cout << endl;
            cout << "Datos mal ingresados" << endl;
            cout << "Debia ser: " << endl;
            cout << "Desde: ";
            cout << direcIP2.ip1 << "." << direcIP2.ip2 << "." << direcIP2.ip3 << "." << direcIP2.ip4 << ":" << direcIP2.ip5 << endl;
            cout << "Hasta: " << endl;
            cout << direcIP1.ip1 << "." << direcIP1.ip2 << "." << direcIP1.ip3 << "." << direcIP1.ip4 << ":" << direcIP1.ip5 << endl;
            cout << "Pero aqui esta el resultado: " << endl;
            cout << endl;
            sleep_for(nanoseconds(3000000000));
            for (int i = indice2; i <= indice1; i++)
                cout << vect2[i] << endl;
        }
        else if (direcIP1.ip1 == direcIP2.ip1 && direcIP1.ip2 > direcIP2.ip2) {
            cout << endl;
            cout << "Datos mal ingresados" << endl;
            cout << "Debia ser: " << endl;
            cout << "Desde: ";
            cout << direcIP2.ip1 << "." << direcIP2.ip2 << "." << direcIP2.ip3 << "." << direcIP2.ip4 << ":" << direcIP2.ip5 << endl;
            cout << "Hasta: " << endl;
            cout << direcIP1.ip1 << "." << direcIP1.ip2 << "." << direcIP1.ip3 << "." << direcIP1.ip4 << ":" << direcIP1.ip5 << endl;
            cout << "Pero aqui esta el resultado: " << endl;
            cout << endl;
            sleep_for(nanoseconds(3000000000));
            for (int i = indice2; i <= indice1; i++)
                cout << vect2[i] << endl;
        }
        else if (direcIP1.ip1 == direcIP2.ip1 && direcIP1.ip2 == direcIP2.ip2 && direcIP1.ip3 > direcIP2.ip3) {
            cout << endl;
            for (int i = indice2; i <= indice1; i++)
                cout << vect2[i] << endl;
        }
        else if (direcIP1.ip1 == direcIP2.ip1 && direcIP1.ip2 == direcIP2.ip2 && direcIP1.ip3 == direcIP2.ip3 && direcIP1.ip4 > direcIP2.ip4) {
            cout << endl;
            for (int i = indice2; i <= indice1; i++)
                cout << vect2[i] << endl;
        }
        else if (direcIP1.ip1 == direcIP2.ip1 && direcIP1.ip2 == direcIP2.ip2 && direcIP1.ip3 == direcIP2.ip3 && direcIP1.ip4 == direcIP2.ip4 && direcIP1.ip5 > direcIP2.ip5) {
            cout << endl;
            for (int i = indice2; i <= indice1; i++)
                cout << vect2[i] << endl;
        }
        else if (direcIP1.ip1 == direcIP2.ip1 && direcIP1.ip2 == direcIP2.ip2 && direcIP1.ip3 == direcIP2.ip3 && direcIP1.ip4 == direcIP2.ip4 && direcIP1.ip5 == direcIP2.ip5) {
            cout << endl;
            cout << vect2[indice1] << endl;
        }
        else {
            cout << endl;
            for (int i = indice1; i <= indice2; i++)
                cout << vect2[i] << endl;
        }
    }
}

//Guarda datos ordenados en nuevo archivo
void guardarEnArchivo(vector<string>& vect2) {
    ofstream file;
    file.open("archivo nuevo.txt");
    for (int i = 0; i < vect2.size(); i++) {
        file << vect2[i] << endl; //Guarda cada elemento string del vector como linea en nuevo archivo
    }
    file.close();
}

int main()
{
    vector <Registro> vect;
    vector <string> vect2;
    int cantDatos = 0;
    bool error = false;

    error = llenarVector(vect, cantDatos, vect2); //Llena vector con datos del archivo

    if (error == false) { //Checa si se recibio datos del archivo para continuar
        int stop = 0;
        int opcionTres = 0;
        while (stop != 4) {
            if (opcionTres == 20) { //No permite usar otras opciones si no se han ordenado los datos
                cout << "--- Bienvenid@ al sistema de informacion ---" << endl;
                cout << endl;
                cout << "1. Ordenar datos del archivo" << endl;
                cout << "2. Consultar informacion de un rango de IPs" << endl;
                cout << "3. Guardar informacion ordenada en nuevo archivo" << endl;
                cout << "4. Salir" << endl;
            }
            else {
                cout << "--- Bienvenid@ al sistema de informacion ---" << endl;
                cout << endl;
                cout << "1. Ordenar datos del archivo" << endl;
                cout << "4. Salir" << endl;
                cout << endl;
                cout << "*Para poder ver las demas opciones debe ordenar los datos primero*" << endl;
            }
            cout << endl;
            cout << "Ingrese opcion a consultar: ";
            cin >> stop;
            if (stop == 1) {
                cout << endl;
                cout << "Ordenando..." << endl;
                opcionTres = ordenarDatos(vect, cantDatos, vect2);
                cout << "Datos ordenados con exito" << endl;
                cout << endl;
            }
            else if (stop == 2) {
                consultaInfo(vect, vect2);
                cout << endl;
            }
            else if (stop == 3) {
                guardarEnArchivo(vect2);
                cout << endl;
                cout << "Datos guardados en nuevo archivo llamado archivo nuevo.txt" << endl;
                cout << endl;
            }
            else if (stop == 4) {
                cout << endl;
                cout << "Sesion terminada" << endl;
            }
            else {
                cout << endl;
                cout << "Opcion ingresada invalida" << endl;
                cout << endl;
            }
        }
    }
    else {
        cout << "Error, no se puede completar el programa" << endl;
    }
}

