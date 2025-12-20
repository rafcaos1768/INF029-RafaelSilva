#include <stdio.h>
#include <stdlib.h>
#define TAM 10

#include "trabalho2.h"

estrutura vetorPrincipal[TAM];


/*
Objetivo: criar estrutura auxiliar na posição 'posicao'.
com tamanho 'tamanho'

Rertono (int)
    SUCESSO - criado com sucesso
    JA_TEM_ESTRUTURA_AUXILIAR - já tem estrutura na posição
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
    SEM_ESPACO_DE_MEMORIA - Sem espaço de memória
    TAMANHO_INVALIDO - o tamanh
o deve ser maior ou igual a 1
*/
int criarEstruturaAuxiliar(int posicao, int tamanho)
{
    int retorno = 0;
    // a posicao pode já existir estrutura auxiliar
    if(vetorPrincipal[posicao].lista!= NULL){
        retorno = JA_TEM_ESTRUTURA_AUXILIAR;
        return retorno;
    }

    // se posição é um valor válido {entre 1 e 10}
    if(posicao > 10 || posicao < 1){  
        retorno = POSICAO_INVALIDA;
        return retorno;
    }
    // o tamanho nao pode ser menor que 1
    if(tamanho < 1){
        retorno = TAMANHO_INVALIDO;
        return retorno;
    }

    vetorPrincipal[posicao].lista = malloc(sizeof(tamanho));//aloca espaco de acordo com o tamanho 
    vetorPrincipal[posicao].tam = tamanho; //recebe o tamanho para usos futuros 
    vetorPrincipal[posicao].espaco = 0; //espaco ocupado

    // o tamanho ser muito grande
    if(vetorPrincipal[posicao].lista== NULL){
        retorno = SEM_ESPACO_DE_MEMORIA;  
        return retorno; 
    }
   
   
    // deu tudo certo, crie
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
    int retorno = 0;
    // int existeEstruturaAuxiliar = 0;
    // int temEspaco = 0;
    // int posicao_invalida = 0;


    //verificações
    if (posicao > 10 || posicao < 1){
        retorno = POSICAO_INVALIDA;
        return retorno; 
    }else
    {
        // testar se existe a estrutura auxiliar
        if (vetorPrincipal[posicao].lista != NULL)
        {
            if (vetorPrincipal[posicao].espaco >= vetorPrincipal[posicao].tam)
            {  
                retorno = SEM_ESPACO;
                return retorno; 
            }
        }
        else
        {
            
            retorno = SEM_ESTRUTURA_AUXILIAR;
            return retorno; 
        }
    }

    vetorPrincipal[posicao].lista[vetorPrincipal[posicao].espaco] = valor; 
    vetorPrincipal[posicao].espaco ++; 

    //deu tudo certo 
    retorno = SUCESSO; 
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
    // int ultimoDig = vetorPrincipal[posicao].espaco -vetorPrincipal[posicao].tam; 

     if (posicao > 10 || posicao < 1){
        retorno = POSICAO_INVALIDA;
        return retorno; 
    }else{
        if(vetorPrincipal[posicao].lista == NULL){
            retorno = SEM_ESTRUTURA_AUXILIAR;
            return retorno; 
        } 

        if(vetorPrincipal[posicao].espaco == 0){
            retorno = ESTRUTURA_AUXILIAR_VAZIA;
            return retorno; 
        }
    }


    vetorPrincipal[posicao].espaco --; 

    return retorno;
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
    int retorno = SUCESSO;
    int resultadoDaBusca =-1; 

    if (posicao > 10 || posicao < 1){
        retorno = POSICAO_INVALIDA;
        return retorno; 
    }else {

        if(vetorPrincipal[posicao].lista == NULL){
            retorno =  SEM_ESTRUTURA_AUXILIAR;
            return retorno; 
        }else{

            if(vetorPrincipal[posicao].espaco == 0){
                retorno = ESTRUTURA_AUXILIAR_VAZIA;
                return retorno; 
            }else{
                resultadoDaBusca = buscarNumero(valor,posicao); 
                if( resultadoDaBusca == -1){
                    retorno = NUMERO_INEXISTENTE;
                    return retorno; 
                }
            }
        }
        
    }

    for (int i = resultadoDaBusca; i < vetorPrincipal[posicao].espaco - 1; i++) {
        vetorPrincipal[posicao].lista[i] = vetorPrincipal[posicao].lista[i + 1];
    } 

    vetorPrincipal[posicao].espaco--;


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

    int retorno = SUCESSO;

    if(posicao > 10 || posicao < 1){
        retorno = POSICAO_INVALIDA; 
        return retorno;

    }else{
        if(vetorPrincipal[posicao].lista == NULL){
            retorno =  SEM_ESTRUTURA_AUXILIAR;
            return retorno; 
        }
    }

    for(int i = 0; i < vetorPrincipal[posicao].espaco ; i++){
        vetorAux[i] = vetorPrincipal[posicao].lista[i];
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
   int retorno = SUCESSO;

   
    if(posicao > 10 || posicao < 1){
        retorno = POSICAO_INVALIDA; 
        return retorno;

    }else{
        if(vetorPrincipal[posicao].lista == NULL){
            retorno =  SEM_ESTRUTURA_AUXILIAR;
            return retorno; 
        }
    }
    
    for(int i = 0; i < vetorPrincipal[posicao].espaco ; i++){
        vetorAux[i] = vetorPrincipal[posicao].lista[i];
    }

   for(int k = 0; k < vetorPrincipal[posicao].espaco - 1; k++){
        for( int j = k +1; j < vetorPrincipal[posicao].espaco; j++){
            if(vetorAux[k] > vetorAux[j]){
                int aux = vetorAux[j];
                vetorAux[j]= vetorAux[k];
                vetorAux[k] = aux;
            }
        }
   }

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

    int retorno = SUCESSO;
    int naoEstaVazio = 0; int contador = 0; int contadorVetorAux = 0; 

     for(int i = 0; i < 10; i++){
        if(vetorPrincipal[i].espaco != 0){
           naoEstaVazio = 1;
           break; 
        }
    }

    if(naoEstaVazio == 0){
        retorno = TODAS_ESTRUTURAS_AUXILIARES_VAZIAS; 
        return retorno; 
    }

      

    for(int count = 0; count<10 ; count ++){
        for(int control = 0; control < vetorPrincipal[count].espaco; control ++){
            vetorAux[contadorVetorAux] = vetorPrincipal[count].lista[control];
            contadorVetorAux ++;
        }
    }

    




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

    int retorno = SUCESSO;
    int naoEstaVazio = 0; int contadorVetorAux = 0; 

    //verificar se alguma não está vazia
    for(int i = 0; i < 10; i++){
        if(vetorPrincipal[i].espaco != 0){
           naoEstaVazio = 1;
           break; 
        }
    }

    if(naoEstaVazio == 0){
        retorno = TODAS_ESTRUTURAS_AUXILIARES_VAZIAS; 
        return retorno; 
    }

    for(int count = 0; count<10 ; count ++){
        for(int control = 0; control < vetorPrincipal[count].espaco; control ++){
            vetorAux[contadorVetorAux] = vetorPrincipal[count].lista[control];
            contadorVetorAux ++;
        }
    }

    

    //ordenação 
    for(int k = 0; k < contadorVetorAux - 1; k++){
        for( int j = k +1; j < contadorVetorAux; j++){
            if(vetorAux[k] > vetorAux[j]){
                int aux = vetorAux[j];
                vetorAux[j]= vetorAux[k];
                vetorAux[k] = aux;
            }
        }
   }



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

    int retorno = SUCESSO;
    int newTam  = novoTamanho + vetorPrincipal[posicao].tam;

 // se posição é um valor válido {entre 1 e 10}
    if(posicao > 10 || posicao < 1){  
        retorno = POSICAO_INVALIDA;
        return retorno;
    }

    if(newTam < 1){
        retorno = NOVO_TAMANHO_INVALIDO;
        return retorno;
    }

    if(vetorPrincipal[posicao].lista == NULL){
        retorno = SEM_ESTRUTURA_AUXILIAR;
        return retorno; 
    }
   
    vetorPrincipal[posicao].lista = realloc(vetorPrincipal[posicao].lista, newTam * sizeof(int) );

    //verificar se o novo tamanho alocado retorna a NULL
    if(vetorPrincipal[posicao].lista == NULL){
        retorno = SEM_ESPACO_DE_MEMORIA; 
        return retorno; 
    }


    vetorPrincipal[posicao].tam = newTam; 
    if(vetorPrincipal[posicao].espaco > newTam){
        vetorPrincipal[posicao].espaco =  newTam;
    }
   


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

    // se posição é um valor válido {entre 1 e 10}
    if(posicao > 10 || posicao < 1){  
        retorno = POSICAO_INVALIDA;
        return retorno;
    }

    if(vetorPrincipal[posicao].lista == NULL){
        retorno = SEM_ESTRUTURA_AUXILIAR;
        return retorno; 
    }

    if(vetorPrincipal[posicao].lista == NULL){
        retorno = SEM_ESTRUTURA_AUXILIAR;
        return retorno; 
    }

    
    retorno = vetorPrincipal[posicao].espaco; 
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
    No *cabecote = NULL;
    No *ultimo = NULL;
    int encontrou = 0;

    // cria o nó cabeçote
    cabecote = (No *) malloc(sizeof(No));
    if (cabecote == NULL) return NULL;

    cabecote->prox = NULL;
    ultimo = cabecote;

    // percorre todas as estruturas
    for (int i = 0; i < TAM; i++) {
        if (vetorPrincipal[i].lista != NULL) {
            for (int j = 0; j < vetorPrincipal[i].tam; j++) {

                No *novo = (No *) malloc(sizeof(No));
                if (novo == NULL) {
                    destruirListaEncadeadaComCabecote(&cabecote);
                    return NULL;
                }

                novo->conteudo = vetorPrincipal[i].lista[j];
                novo->prox = NULL;

                ultimo->prox = novo;
                ultimo = novo;

                encontrou = 1;
            }
        }
    }

    if (!encontrou) {
        free(cabecote);
        return NULL;
    }

    return cabecote;
}

/*
Objetivo: retorna os números da lista enceada com cabeçote armazenando em vetorAux.
Retorno void
*/
void getDadosListaEncadeadaComCabecote(No *inicio, int vetorAux[])
{
    // if (inicio == NULL) return;

    // int i = 0;
    // No *aux = inicio->prox;

    // while (aux != NULL) {
    //     vetorAux[i] = aux->conteudo;
    //     printf("cont %d\n", aux-> conteudo);
    //     aux = aux->prox;
    //     i++;
    // }
}

/*
Objetivo: Destruir a lista encadeada com cabeçote a partir de início.
O ponteiro inicio deve ficar com NULL.

Retorno 
    void.
*/
void destruirListaEncadeadaComCabecote(No **inicio)
{
     if (inicio == NULL || *inicio == NULL) return;

    No *aux = *inicio;
    No *temp;

    while (aux != NULL) {
        temp = aux;
        aux = aux->prox;
        free(temp);
    }

    *inicio = NULL;
}

/*
Objetivo: inicializa o programa. deve ser chamado ao inicio do programa 

*/

void inicializar()
{
    for(int i = 0; i < 10 ; i++){
        vetorPrincipal[i].lista = NULL; 
    }
}

/*
Objetivo: finaliza o programa. deve ser chamado ao final do programa 
para poder liberar todos os espaços de memória das estruturas auxiliares.

*/

void finalizar()
{
     for(int i = 0; i < 10 ; i++){
        if(vetorPrincipal[i].lista !=NULL){
            free(vetorPrincipal[i].lista);
        }
        
    }

}

int buscarNumero(int valor, int posicao){

    int encontrado = -1; 
    for(int i = 0; i < vetorPrincipal[posicao].tam ; i++){
        if(vetorPrincipal[posicao].lista[i] == valor){
            encontrado = i; 
            break; 
        }
    }

    return encontrado;
}