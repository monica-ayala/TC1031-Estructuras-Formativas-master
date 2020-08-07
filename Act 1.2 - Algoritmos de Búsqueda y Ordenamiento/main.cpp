/*
 * main.cpp
 *
 *  Created on: 10/08/2020
 *      Author: bvaldesa
 */
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <cstring>
#include <string>
#include "sorts.h"

using namespace std;

template <class T>
string arrayToString(const vector<T> &v) {
	stringstream aux;

	aux << "[" << v[0];
	for (int i = 1; i < v.size(); i++) {
		aux << ", " << v[i];
	}
	aux << "]";
	return aux.str();
}

template <class T>
string listToString(const list<T> &v) {
	typename list<T>::const_iterator itr;
	stringstream aux;

	itr = v.begin();
	aux << "[" << *itr++;
	for (; itr != v.end(); itr++) {
		aux << ", " << *itr;
	}
	aux << "]";
	return aux.str();
}

int main(int argc, char* argv[]) {

	int array1[] = {58, 92, 75, 5, 21, 92, 84, 91, 64, 54, 3, 28, 11, 61, 65, 4, 1, 8, 52, 78};
	vector<int> original1 (array1, array1 + sizeof(array1) / sizeof(int) );

	int array2[] = {120, 10, 5, 897, 333, 68};
	vector<int> original2 (array2, array2 + sizeof(array2) / sizeof(int) );

	vector<int> prueba;
	Sorts<int> sorts;
	string resp1 = "[1, 3, 4, 5, 8, 11, 21, 28, 52, 54, 58, 61, 64, 65, 75, 78, 84, 91, 92, 92]";
	string resp2 = "[5, 10, 68, 120, 333, 897]";

	prueba = original1;
	sorts.ordenaIntercambio(prueba);
	cout << arrayToString(prueba);
	cout << resp1;

	cout << " 1 " <<	(!resp1.compare(arrayToString(prueba)) ? "success\n" : "fail\n");

	prueba = original2;
	sorts.ordenaIntercambio(prueba);
	cout << " 2 " <<	(!resp2.compare(arrayToString(prueba)) ? "success\n" : "fail\n");

	prueba = original1;
	sorts.ordenaBurbuja(prueba);
	cout << " 3 " <<	(!resp1.compare(arrayToString(prueba)) ? "success\n" : "fail\n");

	prueba = original2;
	sorts.ordenaBurbuja(prueba);
	cout << " 4 " <<	(!resp2.compare(arrayToString(prueba)) ? "success\n" : "fail\n");

	prueba = original1;
	sorts.ordenaMerge(prueba);
	cout << " 5 " <<	(!resp1.compare(arrayToString(prueba)) ? "success\n" : "fail\n");

	prueba = original2;
	sorts.ordenaMerge(prueba);
	cout << " 6 " <<	(!resp2.compare(arrayToString(prueba)) ? "success\n" : "fail\n");

  cout << " 7 " <<	(6 == sorts.busqSecuencial(resp1, 11) ? "success\n" : "fail\n");

	cout << " 8 " <<	(-1 == sorts.busqSecuencial(resp2, 197) ? "success\n" : "fail\n");

	cout << " 9 " <<	(6 == sorts.busqBinaria(resp1, 11) ? "success\n" : "fail\n");

	cout << " 10" <<	(-1 == sorts.busqBinaria(resp2, 197) ? "success\n" : "fail\n");

}
