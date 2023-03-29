#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

class no_b
{
public:
  int data;
  no_b *left;
  no_b *right;

  no_b(int val)
  {
    data = val;
    left = NULL;
    right = NULL;
  }
};

// inserir um valor na arvore
no_b *insertNode_b(int v, no_b *&node)
{
  if (node == NULL)
  {
    node = new no_b(v);
  }
  else
  {
    if (v < node->data)
    {
      node->left = insertNode_b(v, node->left);
    }
    else
    {
      node->right = insertNode_b(v, node->right);
    }
  }
  return node;
}

// busca na arvore binaria
no_b *searchNode_b(int v, no_b *node)
{
  if (node == NULL)
  {
    return NULL;
  }
  if (v == node->data)
  {
    return node;
  }
  if (v < node->data)
  {
    return searchNode_b(v, node->left);
  }
  return searchNode_b(v, node->right);
}

int main()
{
  // tamanho dos vetores de dados a serem inseridos e de dados a serem buscados
  int tam1 = 100000;
  int tam2 = 100000;
  int key;
  int search;

  auto start = steady_clock::now();

  // inserção de numeros aleatorios nos vetores
  int arr1[tam1];
  for (int i = 0; i < tam1; i++)
  {
    arr1[i] = rand();
    /*cout<<"[ "<<arr1[i]<<" ]";*/
  }

  int arr2[tam2];
  for (int i = 0; i < tam2; i++)
  {
    arr2[i] = rand();
  }

  no_b *arvore_b_b = NULL;

  // inserindo o vetor aleatorio na arvore
  for (int i = 0; i < tam1; i++)
  {
    insertNode_b(arr1[i], arvore_b_b);
  }

  cout << "\n"<< endl;

  key = 0;
  cout<<"--Arvore Binaria de Busca--"<<endl;

  cout << "\n"<< endl;

  auto end = steady_clock::now();
  auto elapsed = end - start;

  for (int i = 0; i < tam2; i++)
  {
    if (search = searchNode_b(arr2[i], arvore_b_b) != NULL)
    {
      key++;
    }
  }
  if (search != -1){
    cout << "Quantidade encontrada: "<< key << endl;
    cout << duration<double>{elapsed}.count() << "s" << endl;
  }
}
