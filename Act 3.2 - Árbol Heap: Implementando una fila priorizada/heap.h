#ifndef HEAP_H_
#define HEAP_H_

#include <iostream>

using namespace std;

template <class T>
class Heap {
private:
	T *data;
	int sizeList;
	int count;
	int parent(int pos);
	int left(int pos);
	int right(int pos);
	void swap(int i, int j);
  void heapify(int pos);

public:
	Heap(int sze);
	string toString();

//funciones de tarea
  void push(T);
	T pop();
  T top();
  bool empty();
  int size();
	
};

template <class T>
int Heap<T>::parent(int pos){
	return (pos - 1) / 2;
}

template <class T>
int Heap<T>::left(int pos){
	return ((2 * pos) + 1);
}

template <class T>
int Heap<T>::right(int pos){
	return ((2 * pos) + 2);
}

template <class T>
void Heap<T>::swap(int i, int j){
	T aux = data[i];
	data[i] = data[j];
	data[j] = aux;
}
template <class T>
void Heap<T>::heapify(int pos){
	int le = left(pos);
	int ri = right(pos);
	int min = pos;
	if (le <= count && data[le] < data[min]) {
		min = le;
	}
	if (ri <= count && data[ri] < data[min]) {
		min = ri;
	}
	if (min != pos) {
		swap(pos, min);
		heapify(min);
	}
}

template <class T>
Heap<T>::Heap(int sze){
	sizeList = sze;
	data = new T[sizeList];
	count = 0;
}

template <class T>
string Heap<T>::toString(){
	stringstream aux;
	aux << "[";	for (int i = 0; i < count; i++) {
		if (i != 0) {
			aux << " ";
		} aux << data[i];
	} aux << "]";
	return aux.str();
}

template <class T>
bool Heap<T>::empty(){
	return (count == 0);
}

template <class T>
void Heap<T>::push(T val){
	if (!(count == sizeList)) {
		int pos;
		pos = count;
		count++;
		while (pos > 0 && val < data[parent(pos)]) {
			data[pos] = data[parent(pos)];
			pos = parent(pos);
		}
		data[pos] = val;
	}
}

template <class T>
T Heap<T>::pop(){
	if (!empty()){
		T aux = data[0];

		data[0] = data[--count];
		heapify(0);
		return aux;
	}
	return -1;
}

template <class T>
T Heap<T>::top(){
    if (!empty()) return data[0];
	return -1;  
}

template <class T>
int Heap<T>::size(){
	return count;
}

#endif /* HASH_H_ */