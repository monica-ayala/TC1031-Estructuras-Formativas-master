#ifndef SPLAYTREE_H
#define SPLAYTREE_H

#include <string>
#include <sstream>
#include <iostream>

using namespace std;

template <class T> class SplayTree;

template <class T>
class Node{
    public:
        Node(T);
        Node(T, Node*, Node*, Node*);
        Node(T, Node*);

        Node* add(T);
        Node* remove(T);
        Node* find(T);
        int size();
        void print_tree(stringstream&) const;
        void preorder(stringstream&) const;
        void inorder(stringstream&) const;

        Node* rot_right(Node*);
        Node* rot_left(Node*);
        Node* splay(Node*, Node*);
        Node* succesor();
        friend class SplayTree<T>;

    private:
        T value;
        Node *left, *right, *parent;

};

template <class T>
class SplayTree{
    public:
        SplayTree();
        void add(T);
        bool find(T);
        void remove(T);
        int size();
        string inorder() const;
        string print_tree() const;
        string preorder() const;

    private:
        Node<T> *root;

};

//funciones Node

template <class T>
Node<T>::Node(T val) : value(val), left(0), right(0), parent(0) {}

template <class T>
Node<T>::Node(T val, Node<T> *le, Node<T> *ri, Node<T> *p): value(val), left(le), right(ri), parent(p) {}

template <class T>
Node<T>::Node(T val, Node<T> *p): value(val), left(0), right(0), parent(p) {}

template <class T>
Node<T>* Node<T>::add(T val){
    if(val>value)
        if(right != 0)
            return right -> add(val);
        else{
            right = new Node(val, this);
            return right;
        }
    else
        if(left != 0)
            return left -> add(val);
        else{
            left = new Node(val, this);
            return left;
        }
}

template <class T>
Node<T>* Node<T>::find(T val){
    if(value == val)
        return this;
    else if(val > value)
            if(right != 0)
                return right->find(val);    
            else
                return 0;
        else if(left !=0)
            return left->find(val);
            else 
                return 0;
}

template <class T>
Node<T>* Node<T>::succesor(){
    Node<T> *le, *ri;

    if(left==0) return 0;

	le = left;
	ri = right;

    if(right == 0) {
        left = le->left;
        right = le->right;
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
Node<T>* Node<T>::remove(T val) {
	Node<T> *succ, *old;
	if (val < value) {
		if (left != 0) {
			if (left->value == val) {
				old = left;
				if(old->left != 0 && old->right != 0){ // dos hijos sucesor
					succ = left->succesor();
					if (succ != 0) {
						succ->left = old->left;
						succ->right = old->right;
						succ->parent = old->parent;
						if(succ->left)
							succ->left->parent = succ;
						if(succ->right)
							succ->right->parent = succ;
					}
					left = succ;
				} else if (old->right != 0){ // solo hijo der
					old->right->parent = left->parent;
					left = old->right;

				} else if (old->left != 0){ // solo hijo izq
					old->left->parent = left->parent;
					left = old->left;
				} else {  // hoja
					left = 0;
				}
				delete old;
				return this;
			} else {
				return left->remove(val);
			}
		}
	} else if (val > value) {
		if (right != 0) {
			if (right->value == val) {
				old = right;
				if(old->left != 0 && old->right != 0){ // dos hijos sucesor
					succ = right->succesor();
					if (succ != 0) {
						succ->left = old->left;
						succ->right = old->right;
						succ->parent = old->parent;
						if(succ->left)
							succ->left->parent = succ;
						if(succ->right)
							succ->right->parent = succ;
					}
					right = succ;
				} else if (old->right != 0){ // solo hijo der
					old->right->parent = right->parent;
					right = old->right;

				} else if (old->left != 0){ // solo hijo izq
					old->left->parent = right->parent;
					right = old->left;
				} else {  // hoja
					right = 0;
				}
				delete old;
				return this;
			} else {
				return right->remove(val);
			}
		}
	}
	return this; // to avoid warning
}


template <class T>
int Node<T>::size(){
    int l = 0, r = 0;
    if (left != 0) l = left->size() + 1;
    if (right != 0) r = right->size() + 1;
    if ((right != 0) && (left != 0)) r-=1;
    if (left == 0 && right == 0) return 1;
    return r + l;

}

template <class T>
Node<T>* Node<T>::rot_right(Node<T>* y){
    Node<T> *x = y->left;
    
    y->left = x->right;
    if(x->right) y->left->parent = y;

    x->right = y;
    x->parent = y->parent;
    y->parent = x;

    if (x->parent)
        if ((x->parent->right) && (x->parent->value < x->value))
            x->parent->right = x;
        else
            x->parent->left = x;

    return x;
}

template <class T>
Node<T>* Node<T>::rot_left(Node<T>* x){
    Node<T> *y = x->right;

    x->right = y->left;
    if(x->right) x->right->parent = x;

    y->left = x;
    y->parent = x->parent;
    x->parent = y;

    if(y->parent)
        if((y->parent->left)&&(y->parent->value > y->value))
            y->parent->left = y;
        else
            y->parent->left = y;

    return y;
}

template <class T>
Node<T>* Node<T>::splay(Node<T> *rt, Node<T> *x){
    while(x->parent != 0){

        if(rt->value == x->parent->value)
            if(x->parent->left && x->parent->left->value == x->value)
                rot_right(rt);   //Zag
            else
                rot_left(rt);  //Zig
        else{
            Node<T>*p = x->parent; 
			Node<T>*g = p->parent;
                //Zig-Zig
            if((g->left) && (p->left) &&
                (g->left->value == p->value) && (p->left->value == x->value)){
                rot_right(g);
                rot_right(p);
            }   //Zag-Zag 
            else if((g->right) && (p->right) &&
                    (g->right->value == p->value) && (p->right->value == x->value)){
                    rot_left(g);
                    rot_left(p);
            }   //Zag-Zig
            else if((g->left) && (p->right) && 
                    (g->left->value == p->value) && (p->right->value == x->value)){
                    rot_left(p);
                    rot_right(g);
            }   //Zig-Zag
            else{
                rot_right(p);
                rot_left(g);    
            }
        }

    }
    return x;
}

template <class T>
void Node<T>::print_tree(stringstream &aux) const {
	if (parent != 0){
		aux << "\n node " << value;
		aux << " parent " << parent->value;
	}else
		aux << "\n root " << value;
	if (left != 0)
		aux << " left " << left->value;
	if (right != 0)
		aux << " right " << right->value;
	aux << "\n";

	if (left != 0)  left->print_tree(aux);
	if (right != 0) right->print_tree(aux);
}


template <class T>
void Node<T>::preorder(stringstream &aux) const {
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
void Node<T>::inorder(stringstream &aux) const {
	if (left != 0) left->inorder(aux);

	if (aux.tellp() != 1) aux << " ";

	aux << value;

	if (right != 0) right->inorder(aux);
}

//funciones SplayTree 

template <class T>
SplayTree<T>::SplayTree() : root(0) {}

template <class T>
void SplayTree<T>::add(T val){
    if(root==0)
        root = new Node<T>(val);
    else{
        Node<T> *added = root -> add(val);
        root = root->splay(root, added);
    }
}

template <class T>
bool SplayTree<T>::find(T val){
    if(root!=0){
        Node<T> *found = root->find(val);
        if(found != 0) root = root->splay(root, found);
        else return -false;
        return true;
    }
    return false;
}


template <class T>
void SplayTree<T>::remove(T val) {
	if (root != 0) {
		if (val == root->value) {
			Node<T> *succ = root->succesor();
			if (succ != 0) {
					succ->left = root->left;
					succ->right = root->right;
					succ->parent = 0;
					if(succ->left)
						succ->left->parent = succ;
					if(succ->right)
						succ->right->parent = succ;
			}
			delete root;
			root = succ;
		} else {
			Node<T>* p = root->remove(val);
			root = root->splay(root,p);
		}
	}
}

template <class T>
int SplayTree<T>::size(){
    if(root!=0) return root->size();
    return 0;
}

template <class T>
string SplayTree<T>::inorder() const {
    stringstream aux;

    aux << "[";
    if (root!=0)   root->inorder(aux);

    aux << "]";
    return aux.str();
}

template <class T>
string SplayTree<T>::print_tree() const {
    stringstream aux;

    aux << "\n ================================ ";
        
    if (root!=0)   root->print_tree(aux);

    aux << " ================================ \n";
    return aux.str();
}



template <class T>
string SplayTree<T>::preorder() const {
    stringstream aux;

    aux << "[";
    if (root!=0)   root->preorder(aux);

    aux << "]";
    return aux.str();
}

#endif