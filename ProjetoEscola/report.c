#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "report.h"
#define MAX 100

int menuReports(){
    int choice; 
    printf("=== Informe a operação desejada==\n");
    printf("1-Relatorio dos Alunos\n2- Relatorio dos Professores\n3- Relatorios das Disciplinas\n4-Sair\nOption:");
    scanf("%d", &choice);
    printf("\n");
    return choice; 
}

int menuReportsStudents(){
    int choice; 
    printf("=== Informe a operação desejada==\n");
    printf("1-Listar Alunos em ordem Alfabetica\n2- Relatorio dos Professores\n3- Relatorios das Disciplinas\n4-Sair\nOption:");
    scanf("%d", &choice);
    printf("\n");
    return choice; 
}

void listAllStudantsAlphabeticOrder(student baseOfStudents[], int qtd){
    int index = 0;
    char names[MAX][MAX];
    char temp[MAX];
    int i=0,j=0;

   
    //Fazer uma cópia de base of students para não mecher com a variavel 
    for(int k =0 ; k < qtd ; k++){
        strcpy(names[k],baseOfStudents[k].name);
    }


    //ordenar nomes em ordem alfabetica usando bubble sort 
     for (i; i < qtd -1 ; i++) {
        for (j; j < qtd - 1 - i; j++) {
            if (strcmp(names[j], names[j + 1]) > 0) {
                strcpy(temp, names[j]);
                strcpy(names[j], names[j + 1]);
                strcpy(names[j + 1], temp);
            }
        }
    }

    

    //impressao dos nomes
    printf("\nLista de alunos em ordem alfabetica :\n");
    while(index != qtd){
       printf("%s\n", names[index]);
        index++;
    }
}
