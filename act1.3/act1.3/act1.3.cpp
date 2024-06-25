// act1.3.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
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
            string mes, dia, hora, minutos, segundos, ip, razon;
            getline(stream, mes, delimitador);
            if (mes == "Jan") {
                r.mes = 1;
            }
            else {
                if (mes == "Feb") {
                    r.mes = 2;
                }
                else {
                    if (mes == "Mar") {
                        r.mes = 3;
                    }
                    else {
                        if (mes == "Apr")
                        {
                            r.mes = 4;
                        }
                        else {
                            if (mes == "May") {
                                r.mes = 5;
                            }
                            else {
                                if (mes == "Jun") {
                                    r.mes = 6;
                                }
                                else {
                                    if (mes == "Jul") {
                                        r.mes = 7;
                                    }
                                    else {
                                        if (mes == "Aug") {
                                            r.mes = 8;
                                        }
                                        else {
                                            if (mes == "Sep") {
                                                r.mes = 9;
                                            }
                                            else {
                                                if (mes == "Oct") {
                                                    r.mes = 10;
                                                }
                                                else {
                                                    if (mes == "Nov") {
                                                        r.mes = 11;
                                                    }
                                                    else
                                                    {
                                                        r.mes = 12;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
            getline(stream, dia, delimitador);
            r.dia = stoi(dia);
            getline(stream, hora, ':');
            r.hora = stoi(hora);
            getline(stream, minutos, ':');
            r.minutos = stoi(minutos);
            getline(stream, segundos, delimitador);
            r.segundos = stoi(segundos);
            getline(stream, ip, delimitador);
            r.ip = ip;
            getline(stream, razon, delimitador2);
            r.razon = razon;
            vect.push_back(r);
        }
        return false;
    }
}

//Ordena dias de menor a mayor
void ordenaDia(vector<Registro>& vect, int& cantDatos, vector<string>& vect2) {
    int start = 0;
    int finish = 0;
    int indice = 0;
    int ini = 0;
    start = vect[0].mes;
    finish = vect[cantDatos - 1].mes;
    for (int i = start; i < finish; i++) {
        while (vect[indice].mes == i) {
            indice++;
        }
        Funciones::ordenaBurbujaDia(vect, vect2, ini, indice);
        ini = indice;
        indice++;
    }
    if (vect[indice].mes == finish) {
        Funciones::ordenaBurbujaDia(vect, vect2, ini, vect.size());
    }
}

//Ordena horas de menor a mayor
void ordenaHora(vector<Registro>& vect, int& cantDatos, vector<string>& vect2) {
    int start = 0;
    int start2 = 0;
    int ini = 0;
    for (int i = 0; i < vect.size(); i++) {
        start = vect[i].dia;
        start2 = vect[i].mes;
        if (vect[i].mes == vect[cantDatos - 1].mes && vect[i].dia == vect[cantDatos - 1].dia) {
            Funciones::ordenaBurbujaHora(vect, vect2, ini, vect.size());
        }
        else {
            while (vect[i].dia == start && vect[i].mes == start2) {
                i++;
            }
            Funciones::ordenaBurbujaHora(vect, vect2, ini, i);
            ini = i;
        }

    }
}

//Ordena minutos de menor a mayor 
void ordenaMinutos(vector<Registro>& vect, int& cantDatos, vector<string>& vect2) {
    int start = 0;
    int start2 = 0;
    int start3 = 0;
    int ini = 0;
    for (int i = 0; i < vect.size(); i++) {
        start = vect[i].hora;
        start2 = vect[i].dia;
        start3 = vect[i].mes;
        if (vect[i].mes == vect[cantDatos - 1].mes && vect[i].dia == vect[cantDatos - 1].dia && vect[i].hora == vect[cantDatos - 1].hora) {
            Funciones::ordenaIntercambioMinutos(vect, vect2, ini, vect.size());
        }
        else {
            while (vect[i].hora == start && vect[i].dia == start2 && vect[i].mes == start3) {
                i++;
            }
            Funciones::ordenaIntercambioMinutos(vect, vect2, ini, i);
            ini = i;
            i--;
        }

    }
}

//Ordena los segundos de menor a mayor
void ordenaSegundos(vector<Registro>& vect, int& cantDatos, vector<string>& vect2) {
    int start = 0;
    int start2 = 0;
    int start3 = 0;
    int start4 = 0;
    int ini = 0;
    for (int i = 0; i < vect.size(); i++) {
        start = vect[i].minutos;
        start2 = vect[i].hora;
        start3 = vect[i].dia;
        start4 = vect[i].mes;
        if (vect[i].mes == vect[cantDatos - 1].mes && vect[i].dia == vect[cantDatos - 1].dia && vect[i].hora == vect[cantDatos - 1].hora && vect[i].minutos == vect[cantDatos - 1].minutos) {
            Funciones::ordenaIntercambioSegundos(vect, vect2, ini, vect.size());
        }
        else {
            while (vect[i].minutos == start && vect[i].hora == start2 && vect[i].dia == start3 && vect[i].mes == start4) {
                i++;
            }
            Funciones::ordenaIntercambioSegundos(vect, vect2, ini, i);
            ini = i;
            i--;
        }

    }
}

//Ordena los datos llamando a cada funcion
int ordenarDatos(vector<Registro>& vect, int& cantDatos, vector<string>& vect2) {
    Funciones::ordenaBurbujaMes(vect, vect2); //Ordena meses de menor a mayor
    ordenaDia(vect, cantDatos, vect2); //Ordena dias de menor a mayor
    ordenaHora(vect, cantDatos, vect2); //Ordena horas de menor a mayor
    ordenaMinutos(vect, cantDatos, vect2); //Ordena minutos de menor a mayor 
    ordenaSegundos(vect, cantDatos, vect2); //Ordena los segundos de menor a mayor
    return 20;
}

//Cambia mes de string a un valor numerico
int cambiarMes(string mes) {
    if (mes == "enero") {
        return 1;
    }
    else {
        if (mes == "febrero") {
            return 2;
        }
        else {
            if (mes == "marzo") {
                return 3;
            }
            else {
                if (mes == "abril")
                {
                    return 4;
                }
                else {
                    if (mes == "mayo") {
                        return 5;
                    }
                    else {
                        if (mes == "junio") {
                            return 6;
                        }
                        else {
                            if (mes == "julio") {
                                return 7;
                            }
                            else {
                                if (mes == "agosto") {
                                    return 8;
                                }
                                else {
                                    if (mes == "septiembre") {
                                        return 9;
                                    }
                                    else {
                                        if (mes == "octubre") {
                                            return 10;
                                        }
                                        else {
                                            if (mes == "noviembre") {
                                                return 11;
                                            }
                                            else
                                            {
                                                if (mes == "diciembre") {
                                                    return 12;
                                                }
                                                else {
                                                    cout << "Error, valor ingresado invalido" << endl;
                                                    return -1;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

//Para consultar informacion de un rango de fechas en especifico
void consultaInfo(vector<Registro>& vect, vector<string>& vect2) {
    string mes1, mes2;
    int nmes1 = -1;
    int nmes2 = -1;
    int dia1 = 0;
    int dia2 = 0;
    cout << "Consulta informacion de rango de fechas" << endl;
    cout << "Desde: " << endl;
    //Los whiles verifican que la informacion ingresada sea valida
    while (nmes1 == -1) {
        cout << "Mes (en minusculas y completo): ";
        cin >> mes1;
        nmes1 = cambiarMes(mes1);
    }
    while (dia1 > 31 || dia1 < 1) {
        cout << "Dia (1-31): ";
        cin >> dia1;
    }
    cout << "Hasta: " << endl;
    while (nmes2 == -1) {
        cout << "Mes (en minusculas y completo): ";
        cin >> mes2;
        nmes2 = cambiarMes(mes2);
    }
    while (dia2 > 31 || dia2 < 1) {
        cout << "Dia (1-31): ";
        cin >> dia2;
    }
    if (nmes1 == nmes2 && dia1 == dia2) {
        int indiceDe = Funciones::busqSecuencial(vect, nmes1, dia1);
        if (indiceDe == -1) {
            cout << endl;
            cout << "No se encontro la fecha o las fechas ingresadas" << endl;
            cout << endl;
        }
        else {
            int indiceDe2 = Funciones::busquedaEspecifico(vect, indiceDe, nmes1, dia1);
            for (int i = indiceDe; i <= indiceDe2; i++) {
                cout << vect2[i] << endl;
            }
        }
    }
    else {
        if (nmes1 > nmes2) {
            int indiceDe = Funciones::busqSecuencial(vect, nmes2, dia2);
            int indiceHa = Funciones::busqSecuencial(vect, nmes1, dia1);
            if (indiceDe == -1 || indiceHa == -1) {
                cout << endl;
                cout << "No se encontro la fecha o las fechas ingresadas" << endl;
                cout << endl;
            }
            else {
                cout << endl;
                cout << "Datos mal ingresados" << endl;
                cout << "Debia ser: " << endl;
                cout << "Desde: " << mes2 << ", " << dia2 << " (menor) " << "Hasta: " << mes1 << ", " << dia1 << " (mayor)." << endl;
                cout << "Pero aqui esta el resultado: " << endl;
                cout << endl;
                sleep_for(nanoseconds(3000000000));
                dia1 = dia1;
                int indiceHa2 = Funciones::busquedaEspecifico(vect, indiceHa, nmes1, dia1);
                for (int i = indiceDe; i <= indiceHa2; i++) {
                    if (vect[i].mes == nmes1 && vect[i].dia > dia1)
                    {
                        break;
                    }
                    else {
                        cout << vect2[i] << endl;

                    }
                }
            }
        }
        else if (nmes1 < nmes2) {

            int indiceDe = Funciones::busqSecuencial(vect, nmes1, dia1);
            int indiceHa = Funciones::busqSecuencial(vect, nmes2, dia2);
            if (indiceDe == -1 || indiceHa == -1) {
                cout << endl;
                cout << "No se encontro la fecha o las fechas ingresadas" << endl;
                cout << endl;
            }
            else {
                dia2 =dia2;
                int indiceHa2 = Funciones::busquedaEspecifico(vect, indiceHa, nmes2, dia2);
                for (int i = indiceDe; i <= indiceHa2; i++) {
                    if (vect[i].mes == nmes2 && vect[i].dia > dia2)
                    {
                        break;
                    }
                    else {
                        cout << vect2[i] << endl;

                    }
                     
                }
            }
        }
        else if (nmes1 == nmes2 && dia1 > dia2) {
            int indiceDe = Funciones::busqSecuencial(vect, nmes1, dia2);
            int indiceHa = Funciones::busqSecuencial(vect, nmes1, dia1);
            if (indiceDe == -1) {
                cout << endl;
                cout << "No se encontro la fecha o las fechas ingresadas" << endl;
                cout << endl;
            }
            else {
                cout << endl;
                cout << "Datos mal ingresados" << endl;
                cout << "Debia ser: " << endl;
                cout << "Desde: " << mes2 << ", " << dia2 << " (menor) " << "Hasta: " << mes1 << ", " << dia1 << " (mayor)." << endl;
                cout << "Pero aqui esta el resultado: " << endl;
                cout << endl;
                sleep_for(nanoseconds(3000000000));
                dia1 = dia1;
                int indiceHa2 = Funciones::busquedaEspecifico(vect, indiceHa, nmes1, dia1);
                for (int i = indiceDe; i <= indiceHa2; i++) {
                    if (vect[i].mes == nmes1 && vect[i].dia > dia1)
                    {
                        break;
                    }
                    else {
                        cout << vect2[i] << endl;

                    }
                }
            }
        }
        else if (nmes1 == nmes2 && dia1 < dia2) {
            int indiceDe = Funciones::busqSecuencial(vect, nmes1, dia1);
            int indiceHa = Funciones::busqSecuencial(vect, nmes1, dia2);
            if (indiceDe == -1 || indiceHa == -1) {
                cout << endl;
                cout << "No se encontro la fecha o las fechas ingresadas" << endl;
                cout << endl;
            }
            else {
                int indiceHa2 = Funciones::busquedaEspecifico(vect, indiceHa, nmes1, dia2);
                for (int i = indiceDe; i <= indiceHa2; i++) {
                    if (vect[i].mes == nmes1 && vect[i].dia > dia2)
                    {
                        break;
                    }
                    else {
                        cout << vect2[i] << endl;

                    }
                }
            }
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
                cout << "2. Consultar informacion de un rango de fechas" << endl;
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


