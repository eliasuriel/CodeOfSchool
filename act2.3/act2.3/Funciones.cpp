#include "Funciones.h"

void Funciones::ordenaIntercambioIP1(vector<Registro>& vect, vector<string>& vect2)
{
	int i, j;/* se realizan n-1 pasadas, a[o] ... a[n-2] */
	Registro aux;
	string aux2;
	for (i = 0; i <= vect.size() - 2; i++)/* coloca mínimo de a[i+1]...a[n-1] en a[i] */
		for (j = i + 1; j <= vect.size() - 1; j++)
			if (vect[i].ip1 > vect[j].ip1)
			{
				aux = vect[i];
				vect[i] = vect[j];
				vect[j] = aux;
				aux2 = vect2[i];
				vect2[i] = vect2[j];
				vect2[j] = aux2;
			}
}

void Funciones::ordenaIntercambioIP2(vector<Registro>& vect, vector<string>& vect2, int ini, int fin)
{
	int i, j;/* se realizan n-1 pasadas, a[o] ... a[n-2] */
	Registro aux;
	string aux2;
	for (i = ini; i <= fin - 2; i++)/* coloca mínimo de a[i+1]...a[n-1] en a[i] */
		for (j = i + 1; j <= fin - 1; j++)
			if (vect[i].ip2 > vect[j].ip2)
			{
				aux = vect[i];
				vect[i] = vect[j];
				vect[j] = aux;
				aux2 = vect2[i];
				vect2[i] = vect2[j];
				vect2[j] = aux2;
			}
}

void Funciones::ordenaIntercambioIP3(vector<Registro>& vect, vector<string>& vect2, int ini, int fin)
{
	int i, j;/* se realizan n-1 pasadas, a[o] ... a[n-2] */
	Registro aux;
	string aux2;
	for (i = ini; i <= fin - 2; i++)/* coloca mínimo de a[i+1]...a[n-1] en a[i] */
		for (j = i + 1; j <= fin - 1; j++)
			if (vect[i].ip3 > vect[j].ip3)
			{
				aux = vect[i];
				vect[i] = vect[j];
				vect[j] = aux;
				aux2 = vect2[i];
				vect2[i] = vect2[j];
				vect2[j] = aux2;
			}
}

void Funciones::ordenaIntercambioIP4(vector<Registro>& vect, vector<string>& vect2, int ini, int fin)
{
	int i, j;/* se realizan n-1 pasadas, a[o] ... a[n-2] */
	Registro aux;
	string aux2;
	for (i = ini; i <= fin - 2; i++)/* coloca mínimo de a[i+1]...a[n-1] en a[i] */
		for (j = i + 1; j <= fin - 1; j++)
			if (vect[i].ip4 > vect[j].ip4)
			{
				aux = vect[i];
				vect[i] = vect[j];
				vect[j] = aux;
				aux2 = vect2[i];
				vect2[i] = vect2[j];
				vect2[j] = aux2;
			}
}

int Funciones::busqBinaria(vector<Registro>& vect, int ip1, int ip2, int ip3, int ip4, int ip5)
{
	int central, bajo, alto, valorCentral, valorCentral2;
	bajo = 0;
	alto = (vect.size()) - 1;
	while (bajo <= alto) {
		central = (bajo + alto) / 2;
		valorCentral = vect[central].ip1;
		if (ip1 == valorCentral) {
			central = busquedaEspecifico(vect, bajo, alto, ip1, ip2, ip3, ip4, ip5);
			return central;
		}
		else if (ip1 < valorCentral) {
			alto = central - 1;
		}
		else {
			bajo = central + 1;
		}
	}
	return -1;
}

int Funciones::busquedaEspecifico(vector<Registro>& vect, int bajo, int alto, int ip1, int ip2, int ip3, int ip4, int ip5)
{
	int ind = bajo;
	for (int i = bajo; i <= alto; i++) {
		if (vect[i].ip5 == ip5 && vect[i].ip4 == ip4 && vect[i].ip3 == ip3 && vect[i].ip2 == ip2 && vect[i].ip1 == ip1) {
			return ind;
		}
		ind++;
	}
	return -1;
}