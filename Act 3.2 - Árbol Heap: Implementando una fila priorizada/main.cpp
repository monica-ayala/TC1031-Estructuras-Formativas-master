/*
 * main.cpp
 *
 *  Created on: 10/08/2020
 *      Author: bvaldesa
 */
#include <iostream>
#include <sstream>
#include <cstring>
#include <string>
#include "heap.h"

using namespace std;

int main(int argc, char* argv[]) {
	Heap<int> heap(20);
	string ans;
	heap.push(8);

  ans =	"[8]";
	cout << " 1 " <<	(!ans.compare(heap.toString()) ? "success\n" : "fail\n");

	heap.push(20);
	heap.push(31);
	heap.push(5);
	heap.push(87);
	ans ="[5 8 31 20 87]";
	cout << " 2 " <<	(!ans.compare(heap.toString()) ? "success\n" : "fail\n");

	heap.pop();
	ans ="[8 20 31 87]";
	cout << " 3 " <<	(!ans.compare(heap.toString()) ? "success\n" : "fail\n");

	cout << " 4 " <<	((4 == heap.size()) ? "success\n" : "fail\n");

	heap.pop();
	ans ="[20 87 31]";
	cout << " 5 " <<	(!ans.compare(heap.toString()) ? "success\n" : "fail\n");

	cout << " 6 " <<	((3 == heap.size()) ? "success\n" : "fail\n");

	cout << " 7 " <<	((20 == heap.top()) ? "success\n" : "fail\n");

	cout << " 8 " <<	((0 == heap.empty()) ? "success\n" : "fail\n");

	heap.pop();

	cout << " 9 " <<	((31 == heap.top()) ? "success\n" : "fail\n");

	heap.pop();

	cout << " 10 " <<	((0 == heap.empty()) ? "success\n" : "fail\n");

/*
push
Un entero, el cual se desea agregar a la fila priorizada

pop
Saca de la fila priorizada el dato que tiene mayor prioridad

top
Regresa el valor del dato que esta con mayor prioridad en la fila priorizada

empty
Regresa un valor boleando diciendo si la fila priorizada esta vacía o tiene datos.

size
Un valor entero que represena la cantidad de datos de la fila priorizada

	BST<int> bst;
	string  ans;

	bst.add(10);

	cout << " 2 " <<	(1 == bst.height() ? "success\n" : "fail\n");

	bst.add(12);
	bst.add(8);
	bst.add(110);
	bst.add(112);
	bst.add(18);
	ans = "[10 8 12 110 18 112]\n[8 10 12 18 110 112]\n[8 18 112 110 12 10]\n[10 8 12 110 18 112]";
	cout << " 3 " <<	(!ans.compare(bst.visit()) ? "success\n" : "fail\n");

	cout << " 4 " <<	(4 == bst.height() ? "success\n" : "fail\n");

	ans = "[10 12 110]";
	cout << " 5 " <<	(!ans.compare(bst.ancestors(112)) ? "success\n" : "fail\n");

	ans = "[]";
	cout << " 6 " <<	(!ans.compare(bst.ancestors(1000)) ? "success\n" : "fail\n");

	cout << " 7 " <<	(4 == bst.whatlevelamI(18) ? "success\n" : "fail\n");

	cout << " 8 " <<	(2 == bst.whatlevelamI(8) ? "success\n" : "fail\n");
*/
}
