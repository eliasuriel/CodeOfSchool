// Act 4.3.cpp : This file contains the 'main' function. Program execution begins and ends there.
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
#include <queue>
#include <thread>
using namespace std::this_thread;
using namespace std::chrono;

struct src {
    int src, repe;
};

struct Edge {
    int src, dest, repe;
};


class Graph
{
public:
    vector<vector<src>> adjList;
    Graph(vector<Edge> const& edges, int N)
    {

        adjList.resize(N);

        for (auto& edge : edges)
        {
            src eje = { edge.src, edge.repe };
            src eje2 = { edge.dest, edge.repe };
            adjList[edge.src].push_back(eje2);
            adjList[edge.dest].push_back(eje);
        }
    }
};

int ip2int(string ip) { //Regresa primer valor entero de IP
    int rst = 0;
    int a, b, c, d;
    char t = '.';
    stringstream ss(ip);
    ss >> a >> t >> b >> t >> c >> t >> d;
    rst = (a);
    return rst;
}

void BFS(Graph const& graph, src v, vector<bool>& discovered, int& cont1_99, int& cont100_199, int& cont200_299, int& cont300_399, int& cont400_499, int& cont500_599, int& cont600_699, int& cont700_799, int& cont800_899, int& cont900_999)
{
    queue<src> q;

    discovered[v.src] = true;
    q.push(v);
    while (!q.empty())
    {
        v = q.front();
        q.pop();
        if (v.src >= 1 and v.src < 100) {
            cont1_99 = cont1_99 + v.repe;
        }
        if (v.src >= 100 and v.src < 199) {
            cont100_199 = cont100_199 + v.repe;
        }
        if (v.src >= 200 and v.src < 299) {
            cont200_299 = cont200_299 + v.repe;
        }
        if (v.src >= 300 and v.src < 399) {
            cont300_399 = cont300_399 + v.repe;
        }
        if (v.src >= 400 and v.src < 499) {
            cont400_499 = cont400_499 + v.repe;
        }
        if (v.src >= 500 and v.src < 599) {
            cont500_599 = cont500_599 + v.repe;
        }
        if (v.src >= 600 and v.src < 699) {
            cont600_699 = cont600_699 + v.repe;
        }
        if (v.src >= 700 and v.src < 799) {
            cont700_799 = cont700_799 + v.repe;
        }
        if (v.src >= 800 and v.src < 899) {
            cont800_899 = cont800_899 + v.repe;
        }
        if (v.src >= 900 and v.src < 999) {
            cont900_999 = cont900_999 + v.repe;
        }

        // do for every edge (v -> u)
        for (src u : graph.adjList[v.src])
            if (!discovered[u.src])
            {
                discovered[u.src] = true;
                q.push(u);
            }
    }

}

void llenarArbol(string filename, int& cont1_99, int& cont100_199, int& cont200_299, int& cont300_399, int& cont400_499, int& cont500_599, int& cont600_699, int& cont700_799, int& cont800_899, int& cont900_999) { //Llena el arbol
    string linea;
    char delimitador = ' ';
    char delimitador2 = '\13';
    int dirIpN = 0, dirIpP = 0;
    int n = 0;
    int contador = 1;

    fstream archivo;
    vector<Edge> edges;
    vector<int> repeticiones;
    archivo.open(filename);

    if (archivo.fail()) {
        cout << "Error al abrir archivo" << endl;
    }
    else {
        repeticiones.push_back(0);
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
            if (dirIpP == 0) {
                dirIpP = dirIpN;
            }
            if (dirIpN != dirIpP || archivo.eof()) {
                if (archivo.eof() && dirIpN == dirIpP) {
                    n++;
                }
                if (dirIpP == 1) {
                    repeticiones.push_back(n);
                    contador++;
                    n = 0;
                }
                else if (dirIpP >= 1 && dirIpP < 100) {
                    //va al 1
                    edges.push_back({ 1,dirIpP, n });
                    repeticiones.push_back(n);
                    contador++;
                    n = 0;

                }
                else if (dirIpP >= 100 && dirIpP < 200) {
                    //va al 10
                    edges.push_back({ 10,dirIpP, n });
                    repeticiones.push_back(n);
                    contador++;
                    n = 0;

                }
                else if (dirIpP >= 200 && dirIpP < 300) {
                    //va al 20
                    edges.push_back({ 20,dirIpP, n });
                    repeticiones.push_back(n);
                    contador++;
                    n = 0;

                }
                else if (dirIpP >= 300 && dirIpP < 400) {
                    //va al 30
                    edges.push_back({ 30,dirIpP, n });
                    repeticiones.push_back(n);
                    contador++;
                    n = 0;

                }
                else if (dirIpP >= 400 && dirIpP < 500) {
                    //va al 40
                    edges.push_back({ 40,dirIpP, n });
                    repeticiones.push_back(n);
                    contador++;
                    n = 0;

                }
                else if (dirIpP >= 500 && dirIpP < 600) {
                    //va al 50
                    edges.push_back({ 50,dirIpP, n });
                    repeticiones.push_back(n);
                    contador++;
                    n = 0;

                }
                else if (dirIpP >= 600 && dirIpP < 700) {
                    //va al 60
                    edges.push_back({ 60,dirIpP, n });
                    repeticiones.push_back(n);
                    contador++;
                    n = 0;

                }
                else if (dirIpP >= 700 && dirIpP < 800) {
                    //va al 70
                    edges.push_back({ 70,dirIpP, n });
                    repeticiones.push_back(n);
                    contador++;
                    n = 0;

                }
                else if (dirIpP >= 800 && dirIpP < 900) {
                    //va al 80
                    edges.push_back({ 80,dirIpP, n });
                    repeticiones.push_back(n);
                    contador++;
                    n = 0;

                }
                else if (dirIpP >= 900 && dirIpP < 1000) {
                    //va al 90
                    edges.push_back({ 90,dirIpP, n });
                    repeticiones.push_back(n);
                    contador++;
                    n = 0;

                }
            }
            n++;
            dirIpP = dirIpN;
        }
        edges.push_back({ 90,dirIpP, n });
        repeticiones.push_back(n);
        n = 0;
    }


    int max = 0;
    int V = contador + 1;
    Graph graph(edges, V);
    vector<bool> discoveredB(V, false);
    src eje;
    for (int i = 0; i < V; i++) {
        if (discoveredB[i] == false) {
            eje = { i, repeticiones[i] };
            BFS(graph, eje, discoveredB, cont1_99, cont100_199, cont200_299, cont300_399, cont400_499, cont500_599, cont600_699, cont700_799, cont800_899, cont900_999);
        }
    }
    archivo.close();

}

int main()
{
    string filename;
    filename = "archivo nuevo.txt";
    int cont1_99 = 0;
    int cont100_199 = 0;
    int cont200_299 = 0;
    int cont300_399 = 0;
    int cont400_499 = 0;
    int cont500_599 = 0;
    int cont600_699 = 0;
    int cont700_799 = 0;
    int cont800_899 = 0;
    int cont900_999 = 0;
    llenarArbol(filename, cont1_99, cont100_199, cont200_299, cont300_399, cont400_499, cont500_599, cont600_699, cont700_799, cont800_899, cont900_999);// Crear lista

    int max = 0;
    int arreglo[10] = { cont1_99,cont100_199,cont200_299 ,cont300_399 ,cont400_499 ,cont500_599 ,cont600_699 ,cont700_799 ,cont800_899,cont900_999 };
    for (int i = 0; i < 10; i++)
    {
        if (max < arreglo[i]) {
            max = arreglo[i];
        }
    }
    cout << "Fan out " << endl;
    for (int j = 0; j < 10; j++)
    {
        cout << arreglo[j] << endl;
    }
    cout << "El mayor fan out fue " << max << endl;
    cout << endl;

    if (max == cont1_99) {
        cout << "El nodo con mayor fan out es el 1, siendo el boot master" << endl;
    }
    if (max == cont100_199) {
        cout << "El nodo con mayor fan out es el 10, siendo el boot master " << endl;
    }
    if (max == cont200_299) {
        cout << "El nodo con mayor fan out es el 20, siendo el boot master " << endl;
    }
    if (max == cont300_399) {
        cout << "El nodo con mayor fan out es el 30, siendo el boot master " << endl;
    }
    if (max == cont400_499) {
        cout << "El nodo con mayor fan out es el 40, siendo el boot master " << endl;
    }
    if (max == cont500_599) {
        cout << "El nodo con mayor fan out es el 50, siendo el boot master " << endl;
    }
    if (max == cont600_699) {
        cout << "El nodo con mayor fan out es el 60, siendo el boot master " << endl;
    }
    if (max == cont700_799) {
        cout << "El nodo con mayor fan out es el 70, siendo el boot master " << endl;
    }
    if (max == cont800_899) {
        cout << "El nodo con mayor fan out es el 80, siendo el boot master " << endl;
    }
    if (max == cont900_999) {
        cout << "El nodo con mayor fan out es el 90, siendo el boot master " << endl;
    }

    return 0;
}
