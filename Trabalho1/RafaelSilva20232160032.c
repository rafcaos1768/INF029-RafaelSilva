// #################################################
//  Instituto Federal da Bahia
//  Salvador - BA
//  Curso de Análise e Desenvolvimento de Sistemas http://ads.ifba.edu.br
//  Disciplina: INF029 - Laboratório de Programação
//  Professor: Renato Novais - renato@ifba.edu.br

//  ----- Orientações gerais -----
//  Descrição: esse arquivo deve conter as questões do trabalho do aluno.
//  Cada aluno deve renomear esse arquivo para Aluno<MATRICULA>.c
//  O aluno deve preencher seus dados abaixo, e implementar as questões do trabalho

//  ----- Dados do Aluno -----
//  Nome:
//  email:
//  Matrícula:
//  Semestre:

//  Copyright © 2016 Renato Novais. All rights reserved.
// Última atualização: 07/05/2021 - 19/08/2016

// #################################################
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "RafaelSilva20232160032.h" // Substitua pelo seu arquivo de header renomeado
#define MAX 100 //definindo minha constante 

DataQuebrada quebraData(char data[]);
int validarLogica(int dia, int mes, int ano);
int verificarDivisibilidade(int numero);

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
  int datavalida = 1;
  DataQuebrada Mhdata;
  //int tamanhoDaData = strlen(data) -1; //pegar o tamanho sem o /0
  
  Mhdata = quebraData(data); //quebrar a data e armazear em 
  
  if(Mhdata.valido == 0){
    return 0; //Barrar as datas com erros de sintese 
  } else {
    int verficarLogica = validarLogica(Mhdata.iDia, Mhdata.iMes, Mhdata.iAno);
    if (verficarLogica == 0){
      return 0;
    }
  }

 
    return 1;
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

  //calcule os dados e armazene nas três variáveis a seguir
  DiasMesesAnos dma;
  DataQuebrada datafinalq2; 
  DataQuebrada datainicialq2; 

  if (q1(datainicial) == 0){ //utiliza a q1 para ver se eh valida
    dma.retorno = 2;
    return dma;
  }else if (q1(datafinal) == 0){
    dma.retorno = 3;
    return dma;
  }else{
    //verifique se a data final não é menor que a data inicial
    datainicialq2 = quebraData(datainicial);
    datafinalq2 = quebraData (datafinal); 
      
    if (datainicialq2.iAno > datafinalq2.iAno) { 
      // Verifica se o ano da data inicial é maior que o ano da data final
      dma.retorno = 4;
     return dma; 
    } else if (datainicialq2.iAno == datafinalq2.iAno) { 
        // Se os anos são iguais, verifica o mês
        if (datainicialq2.iMes > datafinalq2.iMes) {
          dma.retorno = 4;
          return dma; 
        } else if (datainicialq2.iMes == datafinalq2.iMes) { 
            // Se os meses também são iguais, verifica o dia
            if (datainicialq2.iDia > datafinalq2.iDia) {
              dma.retorno = 4;
              return dma; 
            }
          }
      }

    // Continua a execução caso nenhuma condição de erro seja atendida
    //calcule a distancia entre as datas
    dma.qtdDias = datafinalq2.iDia - datainicialq2.iDia;
    dma.qtdMeses = datafinalq2.iMes - datainicialq2.iMes;
    dma.qtdAnos = datafinalq2.iAno - datainicialq2.iAno;


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
    int tamanhoDoTexto = strlen(texto) -1;

    if(isCaseSensitive == 1){ //deve considerar a diferença entre maiuscula ou minuscula
      for (int i=0; i < tamanhoDoTexto; i++){
        if(c == texto[i]){
          qtdOcorrencias ++; 
        }
      }

    } else { // eh caseSensitive 
        for (int i=0; i < tamanhoDoTexto; i++){
          if(c == texto[i] || (c >= 'A' && c <= 'Z' && c + 32 == texto[i]) || (c >= 'a' && c <= 'z' && c - 32 == texto[i])){
          qtdOcorrencias ++;  
          }
        }
      }



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
    int qtdOcorrencias = 0;

    int textoLen = strlen(strTexto);
    int buscaLen = strlen(strBusca);
    
    // Percorre o texto buscando ocorrências de strBusca
    for (int i = 0; i <= textoLen - buscaLen; i++) {
        // Verifica se a substring a partir de 'i' corresponde a strBusca
        if (strncmp(&strTexto[i], strBusca, buscaLen) == 0) {
            // Armazena a posição de início e fim da ocorrência
            posicoes[qtdOcorrencias * 2] = i + 1;  // Índice começa de 1
            posicoes[qtdOcorrencias * 2 + 1] = i + buscaLen;  // Índice final

            qtdOcorrencias++;  // Incrementa a contagem de ocorrências
        }
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
  int cont=0; 
  int invertido = 0;

  while (num != 0) {
      invertido = invertido * 10 + (num % 10);
      num /= 10;
  }

  num =invertido;
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

    int qtdOcorrencias =0;
    int digitos = verificarDivisibilidade(numerobase);
    int divisor = 1;
    
      while (numerobusca / divisor >= 1) {
        divisor *= 10;
    }

    // Percorre numerobase e verifica ocorrências de numerobusca
    while (numerobase >= numerobusca) {
        if (numerobase % divisor == numerobusca) {
            qtdOcorrencias++;
        }
        numerobase /= 10;
    }

    return qtdOcorrencias;
}




DataQuebrada quebraData(char data[]){
  DataQuebrada dq;
  char sDia[3];
	char sMes[3];
	char sAno[5];
	int i; 

	for (i = 0; data[i] != '/'; i++){ //atribui ate achar o 
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

int validarLogica(int dia, int mes, int ano){
    
  
   // Verificar datas irreais
    if (ano > 2024 || ano < 1900 || mes < 1 || mes > 12 || dia < 1 || dia > 31) {
        return 0;
    }
    
    // Verificar o mês de fevereiro considerando ano bissexto e não bissexto
    if (mes == 2) {
        int bissexto = (ano % 4 == 0 && (ano % 100 != 0 || ano % 400 == 0));
        if ((bissexto && dia > 29) || (!bissexto && dia > 28)) {
            return 0;
        }
    }

    // Verificar meses com 30 dias (abril, junho, setembro e novembro)
    if ((mes == 4 || mes == 6 || mes == 9 || mes == 11) && dia > 30) {
        return 0;
    }

    // Se todas as condições forem satisfeitas, a data é válida
    return 1;
}

int verificarDivisibilidade(int numero) {
    int teste = 0;
    int dezena = 10;
    
    while(teste != 1){
        if (numero / dezena == 0){
            teste =1;
            return dezena/10; 
        } 
        dezena *=10;
    }
}