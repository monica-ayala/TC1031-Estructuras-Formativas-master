class Funciones{
  private:
  public:
  Funciones();
  int sumaIterativa(int n);
  int sumaRecursiva(int n);
  int sumaDirecta(int n);
};

Funciones :: Funciones(){}
int Funciones :: sumaIterativa(int n){
  int suma = 0;
  for(int i = 0; i<=n;i++){
    suma = suma + i;
  }
  return suma;
}

int Funciones :: sumaRecursiva(int n){
  if (n==0){
    return 0;
  }
  else{
    return n + sumaRecursiva(n-1);
  }
}

int Funciones :: sumaDirecta(int n){return (n*(n+1))/2;}

