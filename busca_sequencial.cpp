#include <iostream>
#include <chrono>
#include <iomanip>

using namespace std;
using namespace std::chrono;

int busca_sequencial(int arr[100000], int key){
  for (int i = 0; i < 100000; i++){
    if (arr[i] == key){
      return (i);
    }
  }
  return (-1);
}

int main(){

  int tam = 100000;
  int arr[tam];
  int key;
  int search;

  auto start = steady_clock::now();

  srand(time(NULL));

  for (int i = 0; i < tam; i++){
    arr[i] = rand() % tam + 1;
  }

  /*for (int i = 0; i < tam; i++){
    cout << "[" << arr[i] << "]  ";
  }*/

  cout << "\n"<< endl;

  key = 60;
  cout << "--Busca Sequencial-- "<<endl;
  cout << "Buscando: "<<key<<endl;

  search = busca_sequencial(arr, key);

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
}