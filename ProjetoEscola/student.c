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
        trimRight(baseOfStudents[qtd].name);
        baseOfStudents[qtd].name[strcspn(baseOfStudents[qtd].name, "\n")] = '\0'; // tira o Enter
        

        printf("digite o genero do aluno\n");
        scanf(" %c", &baseOfStudents[qtd].gender); //Usar scanf é problematico, ent dê um espaço antes do %c para eliminar o \n
        if(!validateGender(baseOfStudents[qtd].gender))   
        return false;
        getchar();

        printf("digite a data de nascimento do aluno (ex: dd/mm/aaaa\n");
        fgets(baseOfStudents[qtd].birthdate, sizeof(baseOfStudents[qtd].birthdate), stdin);
        trimRight(baseOfStudents[qtd].birthdate); //Remover possiveis \n no final do código
        baseOfStudents[qtd].birthdate[strcspn(baseOfStudents[qtd].birthdate, "\n")] = '\0'; // tira o Enter
        if(!validateBirthday(baseOfStudents[qtd].birthdate))   
        return false;

        printf("digite o CPF do aluno\n");
        fgets(baseOfStudents[qtd].id, sizeof(baseOfStudents[qtd].id), stdin);
        trimRight(baseOfStudents[qtd].id);
        baseOfStudents[qtd].id[strcspn(baseOfStudents[qtd].id, "\n")] = '\0';
        if(!validateCPF(baseOfStudents[qtd].id)){
            return false;
        }

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