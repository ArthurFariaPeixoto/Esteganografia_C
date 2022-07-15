#include<stdio.h>
#include<stdlib.h> // malloc

#define MAX_ELEMENTOS 11

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
        p->topo = NULL;
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

void imprimir(struct pilha *p){
    int i;
    for(i=0; i<MAX_ELEMENTOS; i++){
        printf("Letra: %c, codigo da letra: %d\n", p->elementos[i], p->codigoInt[i]);
    }
}

int main() {
    struct pilha *minha_pilha;
    int tamanho=11, i;
    char frase[12];
    frase[11]='\0';
    minha_pilha = criar();
    printf("Digite o codigo a ser inserido na imagem: ");
    for(i=0; i<tamanho; i++){
        scanf("%c", &frase[i]);
        empilhar(minha_pilha, frase[i]);
    }
    printf("\nPilha com %d posicoes\n", tamanho_pilha(minha_pilha));

    printf("\nCodigo escrito: %s\n", frase);
    imprimir(minha_pilha);

    printf("\nDesempilhando elementos \n");
    for (i = 0; i<tamanho; i++) {
        printf("%c ", desempilhar(minha_pilha));
    }
    destruir(minha_pilha);

    return 0;
}