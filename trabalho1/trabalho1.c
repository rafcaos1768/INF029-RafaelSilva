// #################################################
//  Instituto Federal da Bahia
//  Salvador - BA
//  Curso de Análise e Desenvolvimento de Sistemas http://ads.ifba.edu.br
//  Disciplina: INF029 - Laboratório de Programação
//  Professor: Renato Novais - renato@ifba.edu.br

//  ----- Orientações gerais -----
//  Descrição: esse arquivo deve conter as questões do trabalho do aluno.
//  O aluno deve preencher seus dados abaixo, e implementar as questões do trabalho

//  ----- Dados do Aluno -----
//  Nome:Rafael Pimentel Dunda Silva
//  email:rafaeldunda12@hotmail.com
//  Matrícula:20232160032
//  Semestre:2

//  Copyright © 2016 Renato Novais. All rights reserved.
// Última atualização: 07/05/2021 - 19/08/2016 - 17/10/2025

// #################################################

#include <stdio.h>
#include "trabalho1.h" 
#include <stdlib.h>
#include <string.h>
#include <stdbool.h> 

DataQuebrada quebraData(char data[]);

/*
## função utilizada para testes  ##

 somar = somar dois valores
@objetivo
    Somar dois valores x e y e retonar o resultado da soma
@entrada
    dois inteiros x e y
@saida
    resultado da soma (x + y)
 */
int somar(int x, int y)
{
    int soma;
    soma = x + y;
    return soma;
}

/*
## função utilizada para testes  ##

 fatorial = fatorial de um número
@objetivo
    calcular o fatorial de um número
@entrada
    um inteiro x
@saida
    fatorial de x -> x!
 */
int fatorial(int x)
{ //função utilizada para testes
  int i, fat = 1;
    
  for (i = x; i > 1; i--)
    fat = fat * i;
    
  return fat;
}

int teste(int a)
{
    int val;
    if (a == 2)
        val = 3;
    else
        val = 4;

    return val;
}

/*
 Q1 = validar data
@objetivo
    Validar uma data
@entrada
    uma string data. Formatos que devem ser aceitos: dd/mm/aaaa, onde dd = dia, mm = mês, e aaaa, igual ao ano. dd em mm podem ter apenas um digito, e aaaa podem ter apenas dois digitos.
@saida
    0 -> se data inválida
    1 -> se data válida
 @restrições
    Não utilizar funções próprias de string (ex: strtok)   
    pode utilizar strlen para pegar o tamanho da string
 */

int q1(char data[])
{
  int datavalida = 1;//considerando como verdadeiro 
  char ddstring[10], mmstring[10], aaaastring[10]; 
  int dd,mm,aaaa; 
  int tamdata = strlen(data); int counter = 0; 

  if(tamdata < 6 || tamdata > 10){
      
    return 0; 
  }   // verifica o tamanho pensando no maior e menor caso 

 //Transferindo os caracteres para as strings
  int found= 0; int i=0,k=0,j=0; 
  while(counter < tamdata ){
      
    if(data[counter] != '/'){ // verifica se é barra 
      if(found == 0){
        ddstring[i] = data[counter];
        i++;
      } else if(found == 1){
        mmstring[k] = data[counter];
        k++;
      } else if(found == 2){
        aaaastring[j] = data[counter]; 
        j++; 
      }
    }else {
      found++; 
    }
    
    counter ++; 

  } 
  //Adicionando no final para terminar a string 
  ddstring[i] = '\0';
  mmstring[k] = '\0';
  aaaastring[j] = '\0';

  //Transformando as strings em numero 
  dd = atoi(ddstring);
  mm = atoi(mmstring); 
  aaaa = atoi(aaaastring); 

  //Aplicando lógica das datas 
  
  //verificando se os numeros são validos 

  if(dd > 31 || dd < 1 || mm > 12 || mm < 1  || aaaa < 1 || aaaa > 2500 ){
    datavalida = 0; 
  }else
  {
    // Verificando se eh ano bisexto 
  bool ehbisexto = false; 
  
  if(aaaa%4 == 0){
      
    if(aaaa%100 != 0 ){
        ehbisexto = true;
        
    } else {
        if((aaaa%400) == 0){
            ehbisexto = true;
        }
    }
  }

  //Fora isso eh um dia normal 
  if(!ehbisexto){
    if(dd > 28 ){
      datavalida = 0; 
    }
  }
  }


  if (datavalida)
      return 1;
  else
      return 0;
}



/*
 Q2 = diferença entre duas datas
 @objetivo
    Calcular a diferença em anos, meses e dias entre duas datas
 @entrada
    uma string datainicial, uma string datafinal. 
 @saida
    Retorna um tipo DiasMesesAnos. No atributo retorno, deve ter os possíveis valores abaixo
    1 -> cálculo de diferença realizado com sucesso
    2 -> datainicial inválida
    3 -> datafinal inválida
    4 -> datainicial > datafinal
    Caso o cálculo esteja correto, os atributos qtdDias, qtdMeses e qtdAnos devem ser preenchidos com os valores correspondentes.
 */
DiasMesesAnos q2(char datainicial[], char datafinal[])
{
  
  DataQuebrada inicial = quebraData(datainicial); 
  DataQuebrada final = quebraData(datafinal); 

  //calcule os dados e armazene nas três variáveis a seguir
  DiasMesesAnos dma;


  // verifica se eh valido ou não 
  if (q1(datainicial) == 0){
    dma.retorno = 2;
    return dma;
  }else if (q1(datafinal) == 0){
    dma.retorno = 3;
    return dma;
  }else{
    //verifique se a data final não é menor que a data inicial
    if(final.iAno < inicial.iAno){
      dma.retorno = 4; 
      return dma; 
    } else if ((final.iAno > inicial.iAno) && (final.iMes < inicial.iMes )){
      dma.retorno = 4; 
      return dma; 
    } else if ((final.iAno > inicial.iAno) && (final.iMes > inicial.iMes ) && ( final.iDia < inicial.iDia)){
      dma.retorno = 4; 
      return dma;
    }

    //calcule a distancia entre as datas
    dma.qtdDias = final.iDia - inicial.iDia; 
    dma.qtdMeses = final.iMes - inicial.iMes; 
    dma.qtdAnos = final.iAno - inicial.iAno; 



    // caso a data final seja menor em dia ou mes 


    // int qtDi; 
    // if(inicial.iMes == 1 ||
    // inicial.iMes == 3 ||
    // inicial.iMes == 5 ||
    // inicial.iMes == 7 ||
    // inicial.iMes == 8 ||
    // inicial.iMes == 10 ||
    // inicial.iMes == 12){
      
    //   qtdD = 31 - inicial.iDia; 
    // }else if (inicial.iMes == 1 )
    




    //se tudo der certo
    dma.retorno = 1;
    return dma;
    
  }
    
}

/*
 Q3 = encontrar caracter em texto
 @objetivo
    Pesquisar quantas vezes um determinado caracter ocorre em um texto
 @entrada
    uma string texto, um caracter c e um inteiro que informa se é uma pesquisa Case Sensitive ou não. Se isCaseSensitive = 1, a pesquisa deve considerar diferenças entre maiúsculos e minúsculos.
        Se isCaseSensitive != 1, a pesquisa não deve  considerar diferenças entre maiúsculos e minúsculos.
 @saida
    Um número n >= 0.
 */
int q3(char *texto, char c, int isCaseSensitive)
{
  int qtdOcorrencias = 0;
  int tamanho = strlen(texto);
  char *textocopy = malloc(strlen(texto)+ 1); // trabalhar com uma copia 
  strcpy(textocopy,texto); 

  if(isCaseSensitive == 0){
    for( int i = 0; i < tamanho ; i++){
      if(textocopy[i] == c || textocopy[i] == c - 32 ){
        qtdOcorrencias ++; 
      }
    }

  } else {
    for(int i = 0; i < tamanho ; i++){
      if(textocopy[i] == c ){
        qtdOcorrencias ++; 
      }
    }
  }


  free(textocopy);
  return qtdOcorrencias;
}

/*
 Q4 = encontrar palavra em texto
 @objetivo
    Pesquisar todas as ocorrências de uma palavra em um texto
 @entrada
    uma string texto base (strTexto), uma string strBusca e um vetor de inteiros (posicoes) que irá guardar as posições de início e fim de cada ocorrência da palavra (strBusca) no texto base (texto).
 @saida
    Um número n >= 0 correspondente a quantidade de ocorrências encontradas.
    O vetor posicoes deve ser preenchido com cada entrada e saída correspondente. Por exemplo, se tiver uma única ocorrência, a posição 0 do vetor deve ser preenchido com o índice de início do texto, e na posição 1, deve ser preenchido com o índice de fim da ocorrencias. Se tiver duas ocorrências, a segunda ocorrência será amazenado nas posições 2 e 3, e assim consecutivamente. Suponha a string "Instituto Federal da Bahia", e palavra de busca "dera". Como há uma ocorrência da palavra de busca no texto, deve-se armazenar no vetor, da seguinte forma:
        posicoes[0] = 13;
        posicoes[1] = 16;
        Observe que o índice da posição no texto deve começar ser contado a partir de 1.
        O retorno da função, n, nesse caso seria 1;

 */
int q4(char *strTexto, char *strBusca, int posicoes[30])
{
  int qtdOcorrencias = 0; int i = 0; 
  char * textocopy = malloc(strlen(strTexto)+1); 
  strcpy(textocopy, strTexto); 
  int tamamnhoBusca = strlen(strBusca); //chave para indicar que eh a palavra
  int indexposicao = 0; int acheium = 0; 

  while(textocopy[i] != '\0'){

    if(textocopy[i] == -61){
      acheium ++; //caso encontre palavras acentuadas 
    }

    if(textocopy[i] == strBusca[0]){
      char * copybusca = malloc(strlen(strBusca) + 1); //criar uma variavel para fazer uma comparacao temporaria 
      strcpy(copybusca, strBusca);
      int chave =1;
      for(; chave < tamamnhoBusca; chave++ ){
      if(textocopy[i+chave] != copybusca[chave]){
        break; 
      }
      }
      chave --; // diminuir em um por causa do for 
     if(chave == tamamnhoBusca -1){ // se for igual, siginifica que achamos a palavra. último índice válido da palavra é tamanho - 1
     posicoes[indexposicao] = i+1 - acheium;               // salva início //professor optou por salvar a posicao com o numero real 
     indexposicao ++; 
     posicoes[indexposicao] = i + chave+1 - acheium;       // salva fim
     indexposicao++; 
     qtdOcorrencias++;
      }


      free(copybusca);
    }

    
    i++;
  }

 
  return qtdOcorrencias;
}

/*
 Q5 = inverte número
 @objetivo
    Inverter número inteiro
 @entrada
    uma int num.
 @saida
    Número invertido
 */

int q5(int num)
{
  int n = num;
  int invertido = 0;

  if(n < 0)
      n = -n; // ignora sinal

  while(n > 0){
      int dig = n % 10;   // pega o último dígito
      invertido = invertido * 10 + dig; 
      n /= 10;
  }

  if(num < 0){
      invertido *= - invertido; // devolve o sinal
  }

  num = invertido; 
  return num;
}

/*
 Q6 = ocorrência de um número em outro
 @objetivo
    Verificar quantidade de vezes da ocorrência de um número em outro
 @entrada
    Um número base (numerobase) e um número de busca (numerobusca).
 @saida
    Quantidade de vezes que número de busca ocorre em número base
 */

int q6(int numerobase, int numerobusca)
{
  int qtdOcorrencias = 0;
  int n = numerobase; int multiplicador = 1; 
  int vetor[100]; int i = 0; 


    // descobre quantos dígitos o número tem
    while (multiplicador <= n){
        multiplicador *= 10;
    }
    
    multiplicador /= 10;//retirar um digito para comecar do comeco 
    
    // colocar todos os digitos em um vetor e fazer comparação 
    
    if(numerobusca < 10){
        while(multiplicador > 0){
            vetor[i] = n/multiplicador;
            if(vetor[i] == numerobusca){
                qtdOcorrencias ++; 
            }
            n = n - (vetor[i] * multiplicador);
            multiplicador/= 10;
            i++; // caminhar vetor 
        }
        
    }else{
        // ainda não tenho ideia de como fazer com mais de um digito 
    }
    
    return qtdOcorrencias;
}

/*
 Q7 = jogo busca palavras
 @objetivo
    Verificar se existe uma string em uma matriz de caracteres em todas as direções e sentidos possíves
 @entrada
    Uma matriz de caracteres e uma string de busca (palavra).
 @saida
    1 se achou 0 se não achou
 */

 int q7(char matriz[8][10], char palavra[5])
 {
    int achou = 0;
  int i = 0, j = 0;

  int tam = 0;
  while (palavra[tam] != '\0') {
      tam++;
  }

  // direções
  int direcoes[8][2] = {
      {0, 1},    // direita
      {0, -1},   // esquerda
      {1, 0},    // baixo
      {-1, 0},   // cima
      {1, 1},    // diagonal para baixo direita
      {-1, -1},  // diagonal para cima esquerda
      {1, -1},   // diagonal para baixo esquerda
      {-1, 1}    // diagonal para cima direita
  };

  // percorrer a matriz
  for (i = 0; i < 8; i++) {
      for (j = 0; j < 10; j++) {

          // primeira letra bateu
          if (matriz[i][j] == palavra[0]) {

              int d = 0;
              for (d = 0; d < 8; d++) {

                  int dx = direcoes[d][0];
                  int dy = direcoes[d][1];

                  int x = i;
                  int y = j;
                  int k = 1;

                  // verificar as outras letras
                  while (k < tam) {

                      x = x + dx;
                      y = y + dy;

                      // passou dos limites
                      if (x < 0 || x >= 8 || y < 0 || y >= 10) {
                          break;
                      }

                      if (matriz[x][y] != palavra[k]) {
                          break;
                      }

                      k++;
                  }

                  // achou a palavra inteira
                  if (k == tam) {
                      return 1;
                  }
              }
          }
      }
  }

  return achou;
 }



DataQuebrada quebraData(char data[]){
  DataQuebrada dq;
  char sDia[3];
	char sMes[3];
	char sAno[5];
	int i; 

	for (i = 0; data[i] != '/'; i++){
		sDia[i] = data[i];	
	}
	if(i == 1 || i == 2){ // testa se tem 1 ou dois digitos
		sDia[i] = '\0';  // coloca o barra zero no final
	}else {
		dq.valido = 0;
    return dq;
  }  
	

	int j = i + 1; //anda 1 cada para pular a barra
	i = 0;

	for (; data[j] != '/'; j++){
		sMes[i] = data[j];
		i++;
	}

	if(i == 1 || i == 2){ // testa se tem 1 ou dois digitos
		sMes[i] = '\0';  // coloca o barra zero no final
	}else {
		dq.valido = 0;
    return dq;
  }
	

	j = j + 1; //anda 1 cada para pular a barra
	i = 0;
	
	for(; data[j] != '\0'; j++){
	 	sAno[i] = data[j];
	 	i++;
	}

	if(i == 2 || i == 4){ // testa se tem 2 ou 4 digitos
		sAno[i] = '\0';  // coloca o barra zero no final
	}else {
		dq.valido = 0;
    return dq;
  }

  dq.iDia = atoi(sDia);
  dq.iMes = atoi(sMes);
  dq.iAno = atoi(sAno); 

	dq.valido = 1;
    
  return dq;
}

