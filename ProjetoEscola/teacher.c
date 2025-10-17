#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "teacher.h"
#include "report.h"
#include "validator.h"
#define TAM_PROFESSOR 100

int menuTeacher(){
    int choice; 
    printf("=== Informe a operação desejada==\n");
    printf("1-Cadastrar\n2-Atualizar\n3-Excluir\n4-voltar\nOption:");
    scanf("%d", &choice);
    printf("\n");
    return choice; 
}

bool CadastrarAluno(student baseOfTeachers[], int qtd){
    if (qtd == TAM_ALUNO) {
        printf("Lista de alunos cheia!\n\n");
    }else{ 
        system("clear");
        getchar();//ESSENCIAL PARA LIMPAR O BUFFER DE MEMORIA

        printf("digite o nome do aluno\n"); 
        fgets(baseOfTeachers[qtd].name, sizeof(baseOfTeachers[qtd].name), stdin);
        trimRight(baseOfTeachers[qtd].name);
        baseOfTeachers[qtd].name[strcspn(baseOfTeachers[qtd].name, "\n")] = '\0'; // tira o Enter
        if(!validateName(baseOfTeachers[qtd].name))   
        return false;
        

        printf("digite o genero do aluno\n");
        scanf(" %c", &baseOfTeachers[qtd].gender); //Usar scanf é problematico, ent dê um espaço antes do %c para eliminar o \n
        if(!validateGender(baseOfTeachers[qtd].gender))   
        return false;
        getchar();

        printf("digite a data de nascimento do aluno (ex: dd/mm/aaaa\n");
        fgets(baseOfTeachers[qtd].birthdate, sizeof(baseOfTeachers[qtd].birthdate), stdin);
        trimRight(baseOfTeachers[qtd].birthdate); //Remover possiveis \n no final do código
        baseOfTeachers[qtd].birthdate[strcspn(baseOfTeachers[qtd].birthdate, "\n")] = '\0'; // tira o Enter
        if(!validateBirthday(baseOfTeachers[qtd].birthdate))   
        return false;

        printf("digite o CPF do aluno\n");
        fgets(baseOfTeachers[qtd].id, sizeof(baseOfTeachers[qtd].id), stdin);
        trimRight(baseOfTeachers[qtd].id);
        baseOfTeachers[qtd].id[strcspn(baseOfTeachers[qtd].id, "\n")] = '\0';
        if(!validateCPF(baseOfTeachers[qtd].id)){
            return false;
        }

        printf("digite a matricula do aluno\n");
        scanf("%d", &baseOfTeachers[qtd].registration);
        getchar();
        printf("\n");
        return true; 
    }    
}

bool exlcuirAluno(student baseOfTeachers[]){


}

bool buscarAluno(student baseOfTeachers[], int qtd){
    
}