#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "student.h"
#include "report.h"
#include "validator.h"
#define TAM_ALUNO 100

int menuStudent(){
    int choice; 
    printf("=== Informe a operação desejada==\n");
    printf("1-Cadastrar\n2-Atualizar\n3-Excluir\n4-voltar\nOption:");
    scanf("%d", &choice);
    printf("\n");
    return choice; 
}

bool CadastrarAluno(student baseOfStudents[], int qtd){
    if (qtd == TAM_ALUNO) {
        printf("Lista de alunos cheia!\n\n");
    }else{ 
        system("clear");
        getchar();//ESSENCIAL PARA LIMPAR O BUFFER DE MEMORIA
        printf("digite o nome do aluno\n"); 
        fgets(baseOfStudents[qtd].name, sizeof(baseOfStudents[qtd].name), stdin);
        baseOfStudents[qtd].name[strcspn(baseOfStudents[qtd].name, "\n")] = '\0'; // tira o Enter
        

        printf("digite o genero do aluno\n");
        scanf("%c", &baseOfStudents[qtd].gender);
        if(!validateGender(baseOfStudents[qtd].gender))   
        return false;
        getchar();

        printf("digite a idade do aluno\n");
        scanf("%d", &baseOfStudents[qtd].age);
        getchar();

        printf("digite o CPF do aluno\n");
        scanf("%s", baseOfStudents[qtd].id);
        getchar();

        printf("digite o aniversario do aluno\n");
        scanf("%s", baseOfStudents[qtd].birthdate);
        getchar();

        printf("digite a matricula do aluno\n");
        scanf("%d", &baseOfStudents[qtd].registration);
        getchar();
        printf("\n");
        return true; 
    }    
}

bool exlcuirAluno(student baseOfStudents[]){


}

bool buscarAluno(student baseOfStudents[], int qtd){
    
}