#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "student.h"
#include "report.h"
#include "validator.h"

int menuStudent(){
    int choice; 
    printf("=== Informe a operação desejada==\n");
    printf("1-Cadastrar\n2-Atualizar\n3-Excluir\n4-voltar\nOption:");
    scanf("%d", &choice);
    printf("\n");
    return choice; 
}

bool CadastrarAluno(student baseOfStudents[], int qtd){
    printf("digite o nome do aluno\n"); 
    scanf("%s", baseOfStudents[qtd].name);

    printf("digite o genero do aluno\n");
    scanf("%c", &baseOfStudents[qtd].gender);
    if(!validateGender(baseOfStudents[qtd].gender))   
    return false;

    printf("digite a idade do aluno\n");
    scanf("%d", &baseOfStudents[qtd].age);

    printf("digite o CPF do aluno\n");
    scanf("%s", baseOfStudents[qtd].id);

    printf("digite o aniversario do aluno\n");
    scanf("%s", baseOfStudents[qtd].birthdate);

    printf("digite a matricula do aluno\n");
    scanf("%d", &baseOfStudents[qtd].registration);
    printf("\n");
    return true; 
}

bool exlcuirAluno(student baseOfStudents[]){


}

bool buscarAluno(student baseOfStudents[], int qtd){
    
}