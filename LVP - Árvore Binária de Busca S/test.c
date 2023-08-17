#include <stdio.h>
#include <stdlib.h>

typedef struct sNoA
{
    int chave;
    struct sNoA *esq;
    struct sNoA *dir;
} TNoA;

TNoA *cria(void)
{
    return NULL;
}

TNoA *rodaDireita(TNoA *x)
{
    TNoA *y = x->esq;
    x->esq = y->dir;
    y->dir = x;
    return y;
}

TNoA *rodaEsquerda(TNoA *x)
{
    TNoA *y = x->dir;
    x->dir = y->esq;
    y->esq = x;
    return y;
}

TNoA *splay(TNoA *root, int chave)
{
    if (!root || root->chave == chave)
        return root;

    // Zig-Zig (Left)
    if (chave < root->chave && root->esq && chave < root->esq->chave)
    {
        root->esq->esq = splay(root->esq->esq, chave);
        root = rodaDireita(root);
    }
    // Zig-Zag (Left-Right)
    else if (chave > root->chave && root->esq && chave > root->esq->chave)
    {
        root->esq->dir = splay(root->esq->dir, chave);
        if (root->esq->dir)
            root->esq = rodaEsquerda(root->esq);
    }
    // Zig-Zig (Right)
    else if (chave > root->chave && root->dir && chave > root->dir->chave)
    {
        root->dir->dir = splay(root->dir->dir, chave);
        root = rodaEsquerda(root);
    }
    // Zig-Zag (Right-Left)
    else if (chave < root->chave && root->dir && chave < root->dir->chave)
    {
        root->dir->esq = splay(root->dir->esq, chave);
        if (root->dir->esq)
            root->dir = rodaDireita(root->dir);
    }

    // Zig (Left or Right)
    if (chave < root->chave)
        root = rodaDireita(root);
    else
        root = rodaEsquerda(root);

    return root;
}


TNoA *busca(TNoA *root, int chave)
{
    return splay(root, chave);
}

TNoA *insere(TNoA *root, int chave)
{
    if (!root)
    {
        root = (TNoA *)malloc(sizeof(TNoA));
        root->chave = chave;
        root->esq = root->dir = NULL;
        return root;
    }

    root = splay(root, chave);

    if (root->chave == chave)
        return root; // A chave já existe, apenas retorna a raiz

    TNoA *newNode = (TNoA *)malloc(sizeof(TNoA));
    newNode->chave = chave;

    if (chave < root->chave)
    {
        newNode->dir = root;
        newNode->esq = root->esq;
        root->esq = NULL;
    }
    else
    {
        newNode->esq = root;
        newNode->dir = root->dir;
        root->dir = NULL;
    }

    return newNode; // O novo nó agora é a raiz
}


void imprime(TNoA *nodo, int level)
{
    if (nodo == NULL)
        return;

    imprime(nodo->dir, level + 1);

    for (int i = 0; i < level; i++)
        printf("    ");

    printf("%d\n", nodo->chave);

    imprime(nodo->esq, level + 1);
}

int main(void)
{
    TNoA *raiz = cria();
    int qt, value, x;

    printf("Digite a quantidade de valores a serem inseridos: ");
    scanf("%i", &qt);

    for (int i = 0; i < qt; i++)
    {
        scanf("%i", &value);
        raiz = insere(raiz, value);
    }

    imprime(raiz, 0);

    printf("Digite o valor a ser buscado: ");
    scanf("%i", &x);
    raiz = busca(raiz, x);

    if (raiz && raiz->chave == x)
        printf("Encontrado!\n");
    else
        printf("Nao encontrado\n");

    imprime(raiz, 0);

    return 0;
}
