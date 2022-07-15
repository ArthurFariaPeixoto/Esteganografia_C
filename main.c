#include<stdio.h>
#include<stdlib.h> // malloc

#define MAX_ELEMENTOS 10

struct pilha {
    char elementos[MAX_ELEMENTOS];
    int topo;
    int codigoInt[MAX_ELEMENTOS];

};

struct pilha *criar() {
    struct pilha *p;
    int i;
    p = malloc(sizeof(struct pilha));

    if (!p) {
        exit(1); // Erro ao alocar memoria
    }
    for(i=0; i<MAX_ELEMENTOS; i++){
        p->elementos[i]=NULL;
        p->codigoInt[i]=NULL;
    }
    p->topo = 0;
    return p;
}

void empilhar(struct pilha *p, char c) {
    int numero;
    numero = c;
    p->elementos[p->topo] = c; // Insere caractere no topo
    p->codigoInt[p->topo] = numero; // Insere numero no topo
    p->topo++; // Incrementa topo
}

char desempilhar(struct pilha *p) {
    p->topo--; // Decrementa topo
    return p->elementos[p->topo];
}

int tamanho_pilha(struct pilha *p) {
    return p->topo;
}

void destruir(struct pilha *p) {
    free(p);
}

int main() {
    struct pilha *minha_pilha;
    int tamanho=11, i;
    char frase[tamanho];

    minha_pilha = criar();

    for(i=0; i<tamanho; i++){
        scanf("%c", &frase[i]);
        empilhar(minha_pilha, frase[i]);
    }

    printf("Codigo escrito: %s\n", frase);
    for(i=0; i<tamanho; i++){
        printf("Letra: %c, codigo da letra: %d\n", frase[i], minha_pilha->codigoInt[i]);
    }

    printf("\nDesempilhando elementos \n");
    for (i = 0; i<tamanho; i++) {
        printf("%c ", desempilhar(minha_pilha));
    }
    destruir(minha_pilha);

    return 0;
}