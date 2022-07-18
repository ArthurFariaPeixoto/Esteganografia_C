#include<stdio.h>
#include<stdlib.h> // malloc

#define MAX_ELEMENTOS 10

struct pilha {
    char elementos[MAX_ELEMENTOS];
    int topo;
    int codigoInt[MAX_ELEMENTOS];
    char codigoBinario[MAX_ELEMENTOS*8];
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
        p->codigoBinario[i] = NULL;
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

void imprimir(struct pilha *p, int opcao){
    int i;
    if(opcao==1){
        for(i=0; i<MAX_ELEMENTOS; i++){
            printf("Letra: %c, codigo da letra: %d\n", p->elementos[i], p->codigoInt[i]);
        }
    }
    else if(opcao==2){
        for(i=0; i<MAX_ELEMENTOS; i++){
            printf("Letra: %c, codigo da letra: %d, ", p->elementos[i], p->codigoInt[i]);
            printf("valor em binario da letra: %c\n", p->codigoBinario[i]);
        }
    }
}

void converterBinario(struct pilha *p){
    int num, aux,i;
    int binario[8];
    char binarioTexto[8];

    for(i=0;i<10;i++){
        num=p->codigoInt[i];
        for (aux = 7; aux >= 0; aux--) {

            if (num % 2 == 0) {
                binario[aux] = 0;
                num = num / 2;
            } else {
                binario[aux] = 1;
                num = num / 2;
            }
        }
        for (aux = 0; aux < 8; aux++) {
            binarioTexto[aux]= binario[aux]+'0';//preenche o vetor com os digitos binarios
            //printf("%d", binario[aux]);
        }
        printf("%s", binarioTexto);//imprime o valor do caractere em binario

    }
}

int main() {
    struct pilha *minha_pilha;
    int tamanho=10, i;
    char frase[tamanho+1];
    frase[tamanho]='\0';


    minha_pilha = criar();

    printf("Digite o codigo a ser inserido na imagem: ");
    for(i=0; i<tamanho; i++){
        scanf("%c", &frase[i]);
        empilhar(minha_pilha, frase[i]);
    }

    printf("\nPilha com %d posicoes\n", tamanho_pilha(minha_pilha));

    printf("\nCodigo escrito: %s\n", frase);
    imprimir(minha_pilha, 1);

    printf("\nCodigo a ser inserido na imagem: \n");
    converterBinario(minha_pilha);

//    printf("\n\nInformacoes finais:\n");
//    imprimir(minha_pilha, 2);

    printf("\n\nDesempilhando elementos \n");
    for (i = 0; i<tamanho; i++) {
        printf("%c ", desempilhar(minha_pilha));
    }
    destruir(minha_pilha);

    return 0;
}