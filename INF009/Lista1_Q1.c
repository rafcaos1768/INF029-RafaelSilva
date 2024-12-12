#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 
#define MAX 100

typedef struct ponto{
    float pontox;
    float pontoy;
}ponto;


float calcularValorEuclidiano(float ponto1, float ponto2){ //Calcular valor euclidiano de ponto 
    float valor = sqrt((ponto1 * ponto1) + (ponto2 * ponto2)); // pega a potencia de dois, soma e depois pega a raiz 
    return valor; 
 
}


int main(){
    FILE *input, *output; // Declara dois ponteiros para arquivos, input e output.
    char linha[MAX]; 
    ponto listaDePontos[MAX];
    input = fopen("L0Q1.in", "r"); //ABRE O ARQUIVO NO MODO LEITURA
    
    if (input == NULL) {//VERIFICANDO SE ABRIU CORRETAMENTE
        printf("Erro ao abrir o arquivo de entrada.\n");
        return 1;
    }

    output = fopen("L0Q1.out", "w");//ABRE O ARQUIVO NO MODO DE SAIDA
    if (output == NULL) {//Verifica se o arquivo de saída foi aberto corretamente.
        printf("Erro ao abrir o arquivo de saída.\n");
        fclose(input);  // Fecha o arquivo de entrada
        return 1;
    }

    while (fgets(linha, sizeof(linha), input) != NULL) {
        

    }    
}