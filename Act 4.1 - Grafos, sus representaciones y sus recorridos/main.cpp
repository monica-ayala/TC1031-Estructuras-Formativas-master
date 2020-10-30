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
#include "bst.h"

using namespace std;

int main(int argc, char* argv[]) {
	BST<int> bst;
	string  ans;

	bst.add(7);
	ans =	"[7]\n[7]\n[7]\n[7]";
	cout << " 1 " <<	(!ans.compare(bst.visit()) ? "success\n" : "fail\n");

	cout << " 2 " <<	(1 == bst.height() ? "success\n" : "fail\n");

	bst.add(1);
	bst.add(2);
	bst.add(8);
	bst.add(12);
	bst.add(5);

	ans = "[7 1 2 5 8 12]\n[1 2 5 7 8 12]\n[5 2 1 12 8 7]\n[7 1 8 2 12 5]";
	cout << " 3 " <<	(!ans.compare(bst.visit()) ? "success\n" : "fail\n");

	cout << " 4 " <<	(4 == bst.height() ? "success\n" : "fail\n");

	ans = "[7 8]";
	cout << " 5 " <<	(!ans.compare(bst.ancestors(12)) ? "success\n" : "fail\n");

	ans = "[]";
	cout << " 6 " <<	(!ans.compare(bst.ancestors(4)) ? "success\n" : "fail\n");

	cout << " 7 " <<	(3 == bst.whatlevelamI(12) ? "success\n" : "fail\n");

	cout << " 8 " <<	(4 == bst.whatlevelamI(5) ? "success\n" : "fail\n");

}
