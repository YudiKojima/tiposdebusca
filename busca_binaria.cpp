#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

int busca_binaria(int arr[100000], int key){
  int begin = 0;
  int end = 100000 - 1;

  while (begin <= end){ 
    int i = (begin + end) / 2; 

    if (arr[i] == key){ 
      return i;
    }

    if (arr[i] < key){ 
      begin = i + 1;
    }
    else{ 
      end = i;
    }
  }

  return -1;
}

int main(){

  int tam = 100000;
  int aux;
  int arr[tam];
  int key;
  int search;

  auto start = steady_clock::now();

  srand(time(NULL));

  for (int i = 0; i < tam; i++){
    arr[i] = rand() % tam + 1;
  }

  for (int fim = tam; fim >= 0; fim--){
    for (int i = 0; i <= fim; i++){
      if (arr[i] > arr[i + 1]){
        aux = arr[i];
        arr[i] = arr[i + 1];
        arr[i + 1] = aux;
      }
    }
  }

  /*for (int i = 0; i < tam; i++){
    cout << "[" << arr[i] << "]  ";
  }*/

  cout << "\n"<< endl;

  key = 60;
  cout << "--Busca Binaria-- "<<endl;
  cout << "Buscando: "<<key<<endl;

  search = busca_binaria(arr, key);

  cout << "\n"<< endl;

  auto end = steady_clock::now();
  auto elapsed = end - start;

  if (search != -1){
    cout << "Elemento encontrado no endereço: arr[" << search << "]. " << endl;
    cout << duration<double>{elapsed}.count() << "s" << endl;
  }
  else{
    cout << "Não encontrado!" << endl;
  }
  return 0;
}