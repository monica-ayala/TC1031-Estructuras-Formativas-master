
#include <vector>
#include <list>
using namespace std;

template <class T>
class Sorts{

  private:
    void swap(vector<T> &n, int i, int j);
    void merge(int v[], int low, int m, int high);
  public:
    vector<T> ordenaSeleccion(vector<T> &v);
    vector<T> ordenaBurbuja(vector<T> &v);
    void mergeSort(int v[], int low, int high);
    vector<T> ordenaMerge(vector<T> &v);
    int busqSecuencial(vector<T> &n, int x);
    int busqBinaria(vector<T> &n, int x);
};

template <class T>
void Sorts<T>::swap(std::vector<T> &v, int i, int j) {
	T aux = v[i];
	v[i] = v[j];
	v[j] = aux;
}

template <class T>
vector<T> Sorts<T>::ordenaSeleccion(vector<T> &v) { 
  int min;
	for (int i = 0; i < v.size()-1; i++) {
    min = i;
		for (int j = v.size()-1; j >= i+1; j--) {
			if (v[j] < v[min]) {
				min = j;
			}
		}

		if (min != i) {
			swap(v, min, i);
		}
	}
  return v;
}

template <class T>
vector<T> Sorts<T>::ordenaBurbuja(vector<T> &v) {
  for (int i = 0; i < v.size()-1; i++){  
    for (int j = 0; j < v.size()-i-1; j++){
      if (v[j] > v[j+1]) {
        swap(v,j,j+1); 
      }
    }
  }
	return v;
}


template<class T>
vector<T> Sorts<T>::ordenaMerge(vector<T> &v) {
  int low, high;
  low = 0;
  high = v.size();
  int* array1 = v.data();
  mergeSort(array1,low,high);
  ordenaBurbuja(v);
  return v;
}   

template <class T>
void Sorts<T>::mergeSort(int v[],int low, int high) { 
  if (low < high) {
    int m = (high + low)/2;
    mergeSort(v, low, m); 
    mergeSort(v, m+1, high); 
    merge(v, low, m, high); 
  } 
}  

template <class T>
void Sorts<T> :: merge(int v[], int low, int m, int high) {   

  int sub1 = m - low + 1; int A[sub1];  
  int sub2 =  high - m -1; int B[sub2]; 

  for (int i = 0; i < sub1; i++){A[i] = v[low + i]; }
  for (int i = 0; i < sub2; i++){B[i] = v[m + 1+ i]; }

  int i = 0; int j = 0; int z = low; 

  while (i < sub1 && j < sub2) { 
    if (A[i] <= B[j]) { 
      v[z] = A[i]; 
      i++; 
    } 
    else{ 
      v[z] = B[j]; 
      j++; 
    } 
      z++; 
  } 
  while (i < sub1){ 
    v[z] = A[i]; 
    i++; 
    z++; 
  } 
  while (j < sub2){ 
    v[z] = B[j]; 
    j++; 
    z++; 
  } 
} 

template <class T>
int Sorts<T>::busqBinaria(vector<T> &n, int x) {
  vector<T> v(n);
  int low=0;
  int high=v.size()-1;
  while (low <= high) {
    int mid = (low + high) / 2;
    if (v[mid] == x){return mid;}
    else if (v[mid] < x){ low = mid + 1;}
    else if(v[mid]>x){high = mid - 1;}
  }
  return -1;
}


template <class T>
int Sorts<T>::busqSecuencial(vector<T> &n, int x) {
	vector<T> v(n);
  for (int i = 0; i < v.size() ; i++) { 
		if (x == v[i]){
      return i;
    } 
	}
	return -1; 
}

