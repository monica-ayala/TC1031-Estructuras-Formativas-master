#ifndef BST_H_
#define BST_H_

#include <string>
#include <sstream>
#include <iostream>

using namespace std;

template <class T> class BST;

template <class T>
class Node {
private:
	T value;
	Node *left, *right;
	Node<T>* succesor();

public:
	Node(T);
	Node(T, Node<T>*, Node<T>*);
  void add(T);
  bool find(T);

	void inorder(std::stringstream&) const;
	void preorder(std::stringstream&) const;
	void postorder(std::stringstream&) const;
	void levelbylevel(std::stringstream&, int) const;
	void ancestors(T, std::stringstream&) const;
	int height(int) const;
	int whatlevelamI(T) const;

	friend class BST<T>;
};

template <class T>
class BST {
private:
	Node<T> *root;

public:
	BST();
  string inorder() const;
  void add(T);
  bool find(T) const;
	std::string visit() const;
	int height() const;
	std::string ancestors(T);
	int whatlevelamI(T) const;
};

// functions of Node

template <class T>
Node<T>::Node(T val) : value(val), left(0), right(0) {}

template <class T>
Node<T>::Node(T val, Node<T> *le, Node<T> *ri) : value(val), left(le), right(ri) {}

template <class T>
Node<T>* Node<T>::succesor() {
	Node<T> *le, *ri;

	le = left;
	ri = right;

	if (left == 0) {
		if (right != 0) {
			right = 0;
		}
		return ri;
	}

	if (left->right == 0) {
		left = left->left;
		le->left = 0;
		return le;
	}

	Node<T> *parent, *child;
	parent = left;
	child = left->right;
	while (child->right != 0) {
		parent = child;
		child = child->right;
	}
	parent->right = child->left;
	child->left = 0;
	return child;
}

template <class T>
void Node<T>::add(T val) {
	if (val < value) {
		if (left != 0) {
			left->add(val);
		} else {
			left = new Node<T>(val);
		}
	} else {
		if (right != 0) {
			right->add(val);
		} else {
			right = new Node<T>(val);
		}
	}
}

template <class T>
bool Node<T>::find(T val) {
	if (val == value) {
		return true;
	} else if (val < value) {
		return (left != 0 && left->find(val));
	} else if (val > value) {
		return (right != 0 && right->find(val));
	}
}

template <class T>
void Node<T>::inorder(std::stringstream &aux) const {
	if (left != 0) {
		left->inorder(aux);
	}
	if (aux.tellp() != 1) {
		aux << " ";
	}
	aux << value;
	if (right != 0) {
		right->inorder(aux);
	}
}

template <class T>
void Node<T>::preorder(std::stringstream &aux) const {
	aux << value;
	if (left != 0) {
		aux << " ";
		left->preorder(aux);
	}
	if (right != 0) {
		aux << " ";
		right->preorder(aux);
	}
}

template <class T>
void Node<T>::postorder(std::stringstream &aux) const{
  if (left != 0) {
		left->postorder(aux);
		aux << " ";
	}
	if (right != 0) {
		right->postorder(aux);
		aux << " ";
	}
	aux << value;
}

template <class T>
void Node<T>::levelbylevel(std::stringstream &aux, int l) const{
  if (l == 1){
		aux << value;
	}
	l--;
	
	if(left != 0){
		if(l==1){
			aux<<" ";
		}
		left->levelbylevel(aux, l);
	}
	if(right != 0){
		if(l==1){
			aux<<" ";
		}
		right->levelbylevel(aux, l);
	}
}

template <class T>
void Node<T>::ancestors(T val, std::stringstream &aux) const{
  if (val>value){
		if (right->value!=val){
			if(right!=0){
				aux << value << " ";
				right->ancestors(val,aux);
			} else aux = std::stringstream("[");
		} else aux << value;
	}
	if(val<value){
		if (left->value!=val){
			if(left!=0){
				aux << value << " ";
				left->ancestors(val,aux);
			} else aux = std::stringstream("[");
		} else aux << value;
	}
}

template <class T>
int Node<T>::height(int a) const{
  int b = a;
	if (left != 0) {
			a = left->height(a+1);
		} 
	if (right != 0) {
			b = right->height(b+1);
		} 
	if (a>b){
		return a;
	} else return b;
}

template <class T>
int Node<T>::whatlevelamI(T val) const {
    if (val == value) return 1;
    if (val < value) {
        if (left != 0) return left->whatlevelamI(val) + 1;
    } else {
        if (right != 0) return right->whatlevelamI(val) + 1;
    }
    return -1;
}

// functions of BTS
template <class T>
BST<T>::BST() : root(0) {}

template<class T>
void BST<T>::add(T val) {
	if (root != 0) {
		if (!root->find(val)) {
			root->add(val);
		}
	} else {
		root = new Node<T>(val);
	}
}

template <class T>
bool BST<T>::find(T val) const {
	if (root != 0) {
		return root->find(val);
	} else {
		return false;
	}
}

template <class T>
string BST<T>::inorder() const {
    stringstream aux;
    aux << "[";
    if (!(root == 0)) root->inorder(aux);
    aux << "]";
    return aux.str();
}

template <class T>
std::string BST<T>::visit() const{
  std::stringstream aux;

	aux << "[";
	if (!(root == 0)){
		root->preorder(aux);
	}
	aux << "]"<<endl;

	aux << inorder() << endl;
  
	aux << "[";
	if (!(root == 0)) {
		root->postorder(aux);
	}
	aux << "]"<<endl;

	aux << "[";
	if (!(root == 0)) {	
		int h = root -> height(1);
		int l = 1;
		while(h>=l){
			root -> levelbylevel(aux,l);
			l++;
		}
	}
	aux << "]";


	return aux.str();
}

template <class T>
int BST<T>::height() const{
	if (!(root == 0)){
		 return root -> height(1);
	}
}

template <class T>
std::string BST<T>::ancestors(T val){
	std::stringstream aux;
	aux << "[";
	if (!(root == 0)&&root->find(val)){
		root -> ancestors(val,aux);
	}
	aux << "]";
	return aux.str();
}

template <class T>
int BST<T>::whatlevelamI(T val) const{
  int level = root -> whatlevelamI(val);
  return level;
}
#endif /* BST_H_ */
