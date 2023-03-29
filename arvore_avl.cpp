#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

class no_avl
{
    public:
    int data;
    no_avl* left;
    no_avl* right;
    int height;

    no_avl(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
        height = 1;
    }
};

int height(no_avl *n)
{
    if (n == NULL)
    {
        return 0;
    }
    return n->height;
}

int max(int a, int b)
{
    return (a > b) ? a : b;
}

no_avl *rightRotate(no_avl *y)
{
    no_avl *x = y->left;
    no_avl *t2 = x->right;

    x->right = y;
    y->left = t2;

    y->height = max(height(y->left), height(y->right) + 1);
    x->height = max(height(x->left), height(x->right) + 1);

    return x;
}

no_avl *leftRotate(no_avl *x)
{
    no_avl *y = x->right;
    no_avl *t2 = y->left;

    y->left = x;
    x->right = t2;

    x->height = max(height(x->left), height(x->right) + 1);
    y->height = max(height(y->left), height(y->right) + 1);

    return y;
}

int getBalance(no_avl *n)
{
    if (n == NULL)
        return 0;
    return height(n->left) - height(n->right);
}

no_avl *insertNode_avl(no_avl *node, int data)
{
    if (node == NULL)
        return (new no_avl(data));

    if (data < node->data)
        node->left = insertNode_avl(node->left, data);
    else if (data > node->data)
        node->right = insertNode_avl(node->right, data);
    else
        return node;

    node->height = 1 + max(height(node->left), height(node->right));

    int balance = getBalance(node);

    if (balance > 1 && data < node->left->data)
        return rightRotate(node);

    if (balance < -1 && data > node->right->data)
        return leftRotate(node);

    if (balance > 1 && data > node->left->data)
    {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    if (balance < -1 && data < node->right->data)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

no_avl *searchNode_avl(int v, no_avl *node)
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
        return searchNode_avl(v, node->left);
    }
    return searchNode_avl(v, node->right);
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
        /*cout << "[ " << arr1[i] << " ]";*/
    }

    int arr2[tam2];
    for (int i = 0; i < tam2; i++)
    {
        arr2[i] = rand();
    }

    no_avl *arvore_avl = NULL;

    // inserindo o vetor aleatorio na arvore
    for (int i = 0; i < tam1; i++)
    {
        arvore_avl = insertNode_avl(arvore_avl, arr1[i]);
    }

    cout << "\n"
         << endl;

    key = 0;
    cout<<"--Arvore AVL--"<<endl;

    cout << "\n"
         << endl;

    auto end = steady_clock::now();
    auto elapsed = end - start;

    for (int i = 0; i < tam2; i++)
    {
        if (search = searchNode_avl(arr2[i], arvore_avl) != NULL)
        {
            key++;
        }
    }
    if (search != -1)
    {
        cout << "Quantidade encontrada: " << key << endl;
        cout << duration<double>{elapsed}.count() << "s" << endl;
    }
}