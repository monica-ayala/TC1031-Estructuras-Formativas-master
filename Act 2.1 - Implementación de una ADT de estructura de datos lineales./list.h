#ifndef LIST_H
#define LIST_H

#include <string>
#include <sstream>

template <class T> class List;

using namespace std;

template <class T>
class Link{
  private:
    //Atributos
    T	value;
    Link<T> *next;
    friend class List<T>;
    //Constructor
    Link(T);
    Link(T, Link<T>*);
    Link(const Link<T>&);
};

template <class T>
class List{
  public:
    List();
    ~List();
    void clear();
    string toString();
    void insertion(T val);
    int search(T val);
    void update(int index, T val);
    T deleteAt(int index);
  private:
    Link<T> *head;
    int size;
};

// Constructores de Link
template <class T>
Link<T>::Link(T val) : value(val), next(0) {}

template <class T>
Link<T>::Link(T val, Link* nxt) : value(val), next(nxt) {}

template <class T>
Link<T>::Link(const Link<T> &source) : value(source.value), next(source.next) {}

// Funciones de List

template <class T>
List<T>::List() : head(0), size(0) {}

template <class T>
List<T>::~List() {clear();}

template <class T>
void List<T>::clear() {
	Link<T> *p, *q;
	p = head;
	while (p != 0) {
		q = p->next;
		delete p;
		p = q;
	}
	head = 0;
	size = 0;
}

template <class T>
string List<T>::toString() {
	stringstream aux;
	Link<T> *p;
	p = head;
	aux << "[";
	while (p != 0) {
		aux << p->value;
		if (p->next != 0) {
			aux << ", ";
		}
		p = p->next;
	}
	aux << "]";
	return aux.str();
}

template <class T>
void List<T>::insertion(T val) {
  Link<T> *newLink, *p;
	newLink = new Link<T>(val);

	if (head == 0) {
    newLink->next = 0;
    head = newLink;
    size++;
		return;
	}
  
	p = head;
	while (p->next != 0) {
		p = p->next;
	}

	newLink->next = 0;
	p->next = newLink;
	size++;
}

template <class T>
int List<T>::search(T val) {
  Link<T> *p;
  int pos = 0;
  p = head;
  
  while (p != 0) {
    if(p->value == val){
      return pos;
    }
    pos++;
		p = p->next;
	}
  return -1;
}

template <class T>
void List<T>::update(int index, T val) {
  Link<T> *p;
  int pos = 0;
  p = head;
  while (p != 0){
    if (pos == index){
      p->value = val;
    }
    p = p->next;
    pos++;
  }
  
}

template <class T>
T List<T>::deleteAt(int index) {
  Link<T> *p, *q;
	int pos = 0;
  p = head;
  T val;

  if (index == 0){
    head = p->next;
    val = p->value;
    delete p;
    size--;
    return val;
  }

  else{
    while (p != 0){
      if(pos == index-1){
        q = p -> next;
        p-> next = q -> next;
        val = p->value;
        delete q;
        size--;
        return val;
        }
        pos++;
        p = p -> next;
      }
  }
  return val;
}

#endif
