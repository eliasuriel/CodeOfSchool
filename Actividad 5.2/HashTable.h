#pragma once
#include <iostream>
#include <list>
using namespace std;

enum estado {
    vacio, ocupado, borrado
};

struct celda {
    int accesos;
    string ip;
    string info;
    estado miEstado = vacio;
};

class HashTable
{
private:
    list<celda>* table;
    int total_elements;

public:
    HashTable(int n) {
        total_elements = n;
        table = new list<celda>[total_elements];
    }

    void insertElement(celda ip) {
        table[ip.accesos].push_back(ip);
    }

    void buscarIP(string ip) { // O (n^2)
        int p = 0;
        for (int i = 0; i < total_elements; i++) {
            for (celda j : table[i]) {
                if (j.ip == ip) {
                    cout << "Index " << i << ": ";
                    cout << j.ip << " " << j.info;
                    cout << endl;
                    p++;
                }
            }
        }
        if (p == 0)
            cout << "IP no encontrada" << endl;
    }

    void printAll() { // O (n^2)
        for (int i = 0; i < total_elements; i++) {
            cout << "Index " << i << ": ";
            for (celda j : table[i])
                cout << j.ip << " -> ";

            cout << endl;
        }
    }
};

