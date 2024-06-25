#include "Funciones.h"


//Ordena meses de menor a mayor:
void Funciones::ordenaBurbujaMes(vector<Registro>& vect, vector<string>& vect2)
{
	int i, j;
	for (i = 0; i < vect.size(); i++)
		for (j = i + 1; j < vect.size(); j++)
			if (vect[i].mes > vect[j].mes) {
				swap(&vect2[i], &vect2[j]);
				swap2(&vect[i], &vect[j]);
			}

}

//Ordena dias de menor a mayor:
void Funciones::ordenaBurbujaDia(vector<Registro>& vect, vector<string>& vect2, int ini, int fin)
{
	int i, j;
	for (i = ini; i < fin; i++)
		for (j = i + 1; j < fin; j++)
			if (vect[i].dia > vect[j].dia) {
				swap(&vect2[i], &vect2[j]);
				swap2(&vect[i], &vect[j]);
			}
}

//Ordena horas de menor a mayor:
void Funciones::ordenaBurbujaHora(vector<Registro>& vect, vector<string>& vect2, int ini, int fin)
{
	int i, j;
	for (i = ini; i < fin; i++)
		for (j = i + 1; j < fin; j++)
			if (vect[i].hora > vect[j].hora) {
				swap(&vect2[i], &vect2[j]);
				swap2(&vect[i], &vect[j]);
			}
}

//Ordena minutos de menor a mayor:
void Funciones::ordenaIntercambioMinutos(vector<Registro>& vect, vector<string>& vect2, int ini, int fin)
{
	int i, j;/* se realizan n-1 pasadas, a[o] ... a[n-2] */
	Registro aux;
	string aux2;
	for (i = ini; i <= fin - 2; i++)/* coloca mínimo de a[i+1]...a[n-1] en a[i] */
		for (j = i + 1; j <= fin - 1; j++)
			if (vect[i].minutos > vect[j].minutos)
			{
				aux = vect[i];
				vect[i] = vect[j];
				vect[j] = aux;
				aux2 = vect2[i];
				vect2[i] = vect2[j];
				vect2[j] = aux2;
			}
}

//Ordena los segundos de menor a mayor:
void Funciones::ordenaIntercambioSegundos(vector<Registro>& vect, vector<string>& vect2, int ini, int fin)
{
	int i, j;/* se realizan n-1 pasadas, a[o] ... a[n-2] */
	Registro aux;
	string aux2;
	for (i = ini; i <= fin - 2; i++)/* coloca mínimo de a[i+1]...a[n-1] en a[i] */
		for (j = i + 1; j <= fin - 1; j++)
			if (vect[i].segundos > vect[j].segundos)
			{
				aux = vect[i];
				vect[i] = vect[j];
				vect[j] = aux;
				aux2 = vect2[i];
				vect2[i] = vect2[j];
				vect2[j] = aux2;
			}
}

//Busca indice del mes y dia ingresados:
int Funciones::busqSecuencial(std::vector<Registro>& vect, int mes, int dia)
{
	for (int i = 0; i < vect.size(); i++)
		if (mes == vect[i].mes)
			for (int j = i; j < vect.size(); j++)
				if (dia == vect[j].dia)
					return j;
	return -1;
}

int Funciones::busquedaEspecifico(vector<Registro>& vect, int indice, int mes, int dia)
{
	int ind = indice;
	for (int i = indice; i < vect.size(); i++) {
		if (vect[i].dia == dia) {
			ind++;
		}
	}
	return ind - 1;
}

//Metodos auxiliares:

void Funciones::swap(string* val1, string* val2)
{
	string temp = *val1;
	*val1 = *val2;
	*val2 = temp;
}

void Funciones::swap2(Registro* val1, Registro* val2)
{
	Registro temp = *val1;
	*val1 = *val2;
	*val2 = temp;
}