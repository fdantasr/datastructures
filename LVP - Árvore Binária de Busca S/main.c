#include <stdio.h>
#include <stdlib.h>

typedef struct sNoA {
    int chave;
    struct sNoA *esq;
    struct sNoA *dir;
} TNoA;

TNoA* cria(void) {
    return NULL;
}

TNoA* rodaDireita(TNoA* x) {
    TNoA* y = x->esq;
    x->esq = y->dir;
    y->dir = x;
    return y;
}

TNoA* rodaEsquerda(TNoA* x) {
    TNoA* y = x->dir;
    x->dir = y->esq;
    y->esq = x;
    return y;
}

TNoA* splay(TNoA* root, int chave) {
    if (!root || root->chave == chave) 
        return root;
    
    if (chave < root->chave) {
        if (!root->esq) return root;
        root->esq = splay(root->esq, chave);
        return rodaDireita(root);
    } else {
        if (!root->dir) return root;
        root->dir = splay(root->dir, chave);
        return rodaEsquerda(root);
    }
}

TNoA* insere(TNoA* root, int chave) {
    if (!root) {
        root = (TNoA*)malloc(sizeof(TNoA));
        root->chave = chave;
        root->esq = root->dir = NULL;
        return root;
    }
    
    root = splay(root, chave);
    TNoA* newNode = (TNoA*)malloc(sizeof(TNoA));
    newNode->chave = chave;

    if (chave < root->chave) {
        newNode->dir = root;
        newNode->esq = root->esq;
        root->esq = NULL;
    } else if (chave > root->chave) {
        newNode->esq = root;
        newNode->dir = root->dir;
        root->dir = NULL;
    } else {
        // se chave for igual, apenas retorna a raiz
        return root;
    }
    return newNode;
}

void imprime(TNoA* nodo, int nivel) {
    if (nodo) {
        imprime(nodo->dir, nivel + 1);
        for (int i = 0; i < nivel; i++)
            printf("    ");
        printf("%d\n", nodo->chave);
        imprime(nodo->esq, nivel + 1);
    }
}

int main(void) {
    TNoA* raiz = cria();
    int qt, value;

    printf("Digite a quantidade de valores a serem inseridos: ");
    scanf("%i", &qt);

    for (int i = 0; i < qt; i++) {
        printf("Digite o valor a ser inserido: ");
        scanf("%i", &value);
        raiz = insere(raiz, value);
    }

    imprime(raiz, 0);
    return 0;
}

