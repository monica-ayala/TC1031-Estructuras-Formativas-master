
#ifndef QUADRATIC_H_
#define QUADRATIC_H_

using namespace std;

#include <sstream>

template <class Key, class Value>
class Quadratic {
private:
	unsigned int (*func) ( Key);
	unsigned int size;
	unsigned int count;

	Key *keys;
	Key initialValue;
	Value *values;

	long indexOf( Key) ;

public:
	Quadratic(unsigned int, Key, unsigned int (*f) ( Key)) ;

  bool put(Key, Value); //**
  Value get( Key); //**

	bool full() ;
	bool contains( Key) ;
	void clear();
	string toString() ;
  void ordenaSeleccion() ;
};

template <class Key, class Value>
Quadratic<Key, Value>::Quadratic(unsigned int sze, Key init, unsigned int (*f) ( Key)) {
	size = sze;
	keys = new Key[size];
    if (keys !=0){
        initialValue = init;
        for (unsigned int i = 0; i < size; i++) keys[i] = init;
    }
	
	values = new Value[size];
	if (values != 0) 
		for (int i = 0; i  < sze; i++) values[i] = 0;


	func = f;
	count = 0;
}

template <class Key, class Value>
bool Quadratic<Key, Value>::full()  {
	return (count > size);
}

template <class Key, class Value>
bool Quadratic<Key, Value>::put(Key k, Value v)  {
	unsigned int i, start;
	long pos;

	if (!full()) {
        
        pos = indexOf(k);
        if (pos != -1) {
            values[pos] = v;
            return true;
        }

        start = i = func(k) % size;
        for (int j = 0; j < size; j++) {
            if (keys[i] == initialValue) {
                keys[i] = k;
                values[i] = v;
                return true;
            }
            i = (start + j * j) % size;
        }
	}
	return false;
}


template <class Key, class Value>
Value Quadratic<Key, Value>::get( Key k)  {
	unsigned int i, start;
	long pos;

	pos = indexOf(k);
	if (pos != -1)  return values[pos];
}

template <class Key, class Value>
long Quadratic<Key, Value>::indexOf( Key k)  {
	unsigned int i, start;

	start = i = func(k) % size;
	
    for (int j = 0; j < size; j++){
        if (keys[i] == k) return i;
		i = (start + j *j) % size;
    }
	return -1;
}


template <class Key, class Value>
bool Quadratic<Key, Value>::contains( Key k)  {
	return (indexOf(k) != -1);
}

template <class Key, class Value>
void Quadratic<Key, Value>::clear() {
	count = 0;
	for (unsigned int i = 0; i < size; i++) 
		keys[i] = initialValue;
}


template <class Key, class Value>
string Quadratic<Key, Value>::toString()  {
	stringstream aux;
	for (int i = 0; i < size; i++)
		if (keys[i] != initialValue){
		    aux << "(" << i << " ";
		    aux << keys[i] << " : " << values[i] << ") ";
		}
	return aux.str();
}

#endif /* HASH_H_ */
