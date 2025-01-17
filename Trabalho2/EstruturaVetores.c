#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 10

#include "EstruturaVetores.h"

int * vetorPrincipal[TAM]; // cada bloco aponta para uma estrutura 


/*
Objetivo: criar estrutura auxiliar na posição 'posicao'.
com tamanho 'tamanho'

Rertono (int)
    SUCESSO - criado com sucesso
    JA_TEM_ESTRUTURA_AUXILIAR - já tem estrutura na posição
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
    SEM_ESPACO_DE_MEMORIA - Sem espaço de memória
    TAMANHO_INVALIDO - o tamanho deve ser maior ou igual a 1
*/
int criarEstruturaAuxiliar(int posicao, int tamanho)
{   
    int retorno = 0;
    if(vetorPrincipal[posicao -1] != NULL){
        retorno = JA_TEM_ESTRUTURA_AUXILIAR; // a posicao pode já existir estrutura auxiliar
        return retorno;
    }
    if(posicao < 1 || posicao > 10){
        retorno =  POSICAO_INVALIDA; // se posição é um valor válido {entre 1 e 10}
        return retorno; 
    }
    if(tamanho < 1){
        retorno = TAMANHO_INVALIDO; // o tamanho nao pode ser menor que 1
        return retorno; 
    }
    int *estrutura = (int *)malloc(tamanho * sizeof(int)); //Declara uma estrutura e multiplica o tamanho por bytes para guardar o espaço 
    if (estrutura == NULL) { // se o retorno da estrutura for NULL signifca que ele não conseguiu apontar para um espaço disponivel
        retorno = SEM_ESPACO_DE_MEMORIA; // Sem memória disponível
        return retorno; 
    }

    // Associar a estrutura ao vetor principal
    vetorPrincipal[posicao-1] = estrutura;// ja eh um ponteiro por isso nao passa o endereco

     for (int i = 0; i < tamanho; i++) {
        vetorPrincipal[posicao-1][i] = 9687485 ;
    } //inicilizar estrutura com 9687485 para manipular

    retorno = SUCESSO;   
    return retorno;

    
}



/*
Objetivo: inserir número 'valor' em estrutura auxiliar da posição 'posicao'
Rertono (int)
    SUCESSO - inserido com sucesso
    SEM_ESPACO - não tem espaço
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
CONSTANTES
*/
int inserirNumeroEmEstrutura(int posicao, int valor)
{   
    int i=0;
    int espacoLivre =-1; //identificar o local livre
    int tamanho =0; 

    int retorno = 0;
    int existeEstruturaAuxiliar = 0;
    int temEspaco = 0;
    int posicao_invalida = 0;

    // while (vetorPrincipal[posicao-1][tamanho] != NULL) {
    //     tamanho++;
        
    // }

    if (posicao < 1 || posicao > 10){
        return  POSICAO_INVALIDA;
    }


    if(vetorPrincipal[posicao-1] != NULL) existeEstruturaAuxiliar = 1; // verifica se a posicação selecionada está associada
    

    if (existeEstruturaAuxiliar)
    { 
        for( i;; i++){
            if(vetorPrincipal[posicao-1][i]==9687485){
                temEspaco =1;
                espacoLivre = i; 
                break;
            } else if(vetorPrincipal[posicao-1][i] == '\0'){ //utilizando essa metodologia que estranhamente da certo 
                temEspaco = 0;
                break;
            }
            
        }
        
        if (temEspaco)
        {
            vetorPrincipal[posicao-1][espacoLivre]= valor; //prestar atencao pois nao tava adicionando no espaco livre
            retorno = SUCESSO;
            return retorno; 
        }
        else
        {
            return SEM_ESPACO;
        }
    }
    else
    {
        return SEM_ESTRUTURA_AUXILIAR;
    }


    return retorno;
}



/*
Objetivo: excluir o numero 'valor' da estrutura auxiliar no final da estrutura.
ex: suponha os valores [3, 8, 7, 9,  ,  ]. Após excluir, a estrutura deve ficar da seguinte forma [3, 8, 7,  ,  ,  ].
Obs. Esta é uma exclusão lógica

Rertono (int)
    SUCESSO - excluido com sucesso
    ESTRUTURA_AUXILIAR_VAZIA - estrutura vazia
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/

int excluirNumeroDoFinaldaEstrutura(int posicao)
{     
    int retorno = SUCESSO;
    int tamanho =0;
    int naoEstaVazio=0;
   
    if (posicao < 1 || posicao > 10)
    return  POSICAO_INVALIDA;

    if(vetorPrincipal[posicao-1] == NULL) return SEM_ESTRUTURA_AUXILIAR;
 


    if(vetorPrincipal[posicao-1][0]!=9687485){
        naoEstaVazio = 1; //VERIFICA SE ESTA VAZIO 
    }


    if(naoEstaVazio){
        for(int i = 0;; i++){ //percorre o vetor ate o final e excloi logicamente o ultimo numero 
            if(vetorPrincipal[posicao-1][i] == 9687485 || vetorPrincipal[posicao-1][i] == '\0'){
                vetorPrincipal[posicao-1][i-1] = 9687485;
                retorno = SUCESSO;
                return retorno;
            }
        }

    } else {
        return ESTRUTURA_AUXILIAR_VAZIA; 
    }
    
    return POSICAO_INVALIDA; 
   
}

/*
Objetivo: excluir o numero 'valor' da estrutura auxiliar da posição 'posicao'.
Caso seja excluido, os números posteriores devem ser movidos para as posições anteriores
ex: suponha os valores [3, 8, 7, 9,  ,  ] onde deve ser excluido o valor 8. A estrutura deve ficar da seguinte forma [3, 7, 9,  ,  ,  ]
Obs. Esta é uma exclusão lógica
Rertono (int)
    SUCESSO - excluido com sucesso 'valor' da estrutura na posição 'posicao'
    ESTRUTURA_AUXILIAR_VAZIA - estrutura vazia
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    NUMERO_INEXISTENTE - Número não existe
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar

*/
int excluirNumeroEspecificoDeEstrutura(int posicao, int valor)
{
    int tamanho =0 ; 
    int retorno = SUCESSO;
    int numeroExiste = 0 ; 
    int encontrei = -1; 

    if (posicao < 1 || posicao > 10)
    return  POSICAO_INVALIDA;

    if(vetorPrincipal[posicao-1] == NULL ) return SEM_ESTRUTURA_AUXILIAR; 

    if(vetorPrincipal[posicao-1][0] == 9687485) return ESTRUTURA_AUXILIAR_VAZIA;

    for(int j = 0; ; j++) { // encontrar o tamanho do vetor 
        if(vetorPrincipal[posicao-1][j] == 9687485 || vetorPrincipal[posicao-1][j] == '\0'){
            break;
        } else {
            tamanho ++; 
        }
    }

    for(int i = 0 ; i < tamanho; i++){//Encontrar o valor na estrutura  
        if(vetorPrincipal[posicao-1][i]== valor){
            numeroExiste = 1; 
            encontrei = i; //recebe aonde encontrou o valor
        } 
    }

    if(numeroExiste){

        for (int k = encontrei; vetorPrincipal[posicao-1][k] != 9687485; k++) {
            vetorPrincipal[posicao-1][k] = vetorPrincipal[posicao-1][k + 1];
        }   

    } else {
        return NUMERO_INEXISTENTE; 
    }
   
    

    return retorno;
}

// se posição é um valor válido {entre 1 e 10}
int ehPosicaoValida(int posicao)
{
    int retorno = 0;
    if (posicao < 1 || posicao > 10)
    {
        retorno = POSICAO_INVALIDA;
    }
    else
        retorno = SUCESSO;

    return retorno;
}
/*
Objetivo: retorna os números da estrutura auxiliar da posição 'posicao (1..10)'.
os números devem ser armazenados em vetorAux

Retorno (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int getDadosEstruturaAuxiliar(int posicao, int vetorAux[])
{
    int tamanho = 0; 
    int retorno = SUCESSO;

    if (posicao < 1 || posicao > 10)
    return  POSICAO_INVALIDA;

    if(vetorPrincipal[posicao -1] == NULL) return SEM_ESTRUTURA_AUXILIAR; 

    for(int j = 0; ; j++) { // encontrar o tamanho do vetor 
        if(vetorPrincipal[posicao-1][j] == 9687485 || vetorPrincipal[posicao-1][j] == '\0'){
            break;
        } else {
            tamanho ++; 
        }
    }

    for(int i = 0 ; i < tamanho ; i ++){
        vetorAux[i] = vetorPrincipal[posicao -1][i]; 
    }

    return retorno;
}

/*
Objetivo: retorna os números ordenados da estrutura auxiliar da posição 'posicao (1..10)'.
os números devem ser armazenados em vetorAux

Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao (1..10)'
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int getDadosOrdenadosEstruturaAuxiliar(int posicao, int vetorAux[])
{

    int retorno = 0;

    
    return retorno;
}

/*
Objetivo: retorna os números de todas as estruturas auxiliares.
os números devem ser armazenados em vetorAux

Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    TODAS_ESTRUTURAS_AUXILIARES_VAZIAS - todas as estruturas auxiliares estão vazias
*/
int getDadosDeTodasEstruturasAuxiliares(int vetorAux[])
{

    int retorno = 0;
    return retorno;
}

/*
Objetivo: retorna os números ordenados de todas as estruturas auxiliares.
os números devem ser armazenados em vetorAux

Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    TODAS_ESTRUTURAS_AUXILIARES_VAZIAS - todas as estruturas auxiliares estão vazias
*/
int getDadosOrdenadosDeTodasEstruturasAuxiliares(int vetorAux[])
{

    int retorno = 0;
    return retorno;
}

/*
Objetivo: modificar o tamanho da estrutura auxiliar da posição 'posicao' para o novo tamanho 'novoTamanho' + tamanho atual
Suponha o tamanho inicial = x, e novo tamanho = n. O tamanho resultante deve ser x + n. Sendo que x + n deve ser sempre >= 1

Rertono (int)
    SUCESSO - foi modificado corretamente o tamanho da estrutura auxiliar
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
    NOVO_TAMANHO_INVALIDO - novo tamanho não pode ser negativo
    SEM_ESPACO_DE_MEMORIA - erro na alocação do novo valor
*/
int modificarTamanhoEstruturaAuxiliar(int posicao, int novoTamanho)
{

    int retorno = 0;
    return retorno;
}

/*
Objetivo: retorna a quantidade de elementos preenchidos da estrutura auxiliar da posição 'posicao'.

Retorno (int)
    POSICAO_INVALIDA - posição inválida
    SEM_ESTRUTURA_AUXILIAR - sem estrutura auxiliar
    ESTRUTURA_AUXILIAR_VAZIA - estrutura auxiliar vazia
    Um número int > 0 correpondente a quantidade de elementos preenchidos da estrutura
*/
int getQuantidadeElementosEstruturaAuxiliar(int posicao)
{

    int retorno = 0;

    return retorno;
}

/*
Objetivo: montar a lista encadeada com cabeçote com todos os números presentes em todas as estruturas.

Retorno (No*)
    NULL, caso não tenha nenhum número nas listas
    No*, ponteiro para o início da lista com cabeçote
*/
No *montarListaEncadeadaComCabecote()
{

    return NULL;
}

/*
Objetivo: retorna os números da lista enceada com cabeçote armazenando em vetorAux.
Retorno void
*/
void getDadosListaEncadeadaComCabecote(No *inicio, int vetorAux[])
{
}

/*
Objetivo: Destruir a lista encadeada com cabeçote a partir de início.
O ponteiro inicio deve ficar com NULL.

Retorno 
    void.
*/
void destruirListaEncadeadaComCabecote(No **inicio)
{
}

/*
Objetivo: inicializa o programa. deve ser chamado ao inicio do programa 

*/

void inicializar()
{
}

/*
Objetivo: finaliza o programa. deve ser chamado ao final do programa 
para poder liberar todos os espaços de memória das estruturas auxiliares.

*/

void finalizar()
{
}
