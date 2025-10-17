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
        getchar();//ESSENCIAL PARA LIMPAR O BUFFER DE MEMORIA

        printf("digite o nome do aluno\n"); 
        fgets(baseOfStudents[qtd].name, sizeof(baseOfStudents[qtd].name), stdin);
        trimRight(baseOfStudents[qtd].name);
        baseOfStudents[qtd].name[strcspn(baseOfStudents[qtd].name, "\n")] = '\0'; // tira o Enter
        if(!validateName(baseOfStudents[qtd].name))   
        return false;
        

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

bool atualizarAluno(student baseOfStudents[], int qtd){
    //Processo de atualizar nao atualiza matricula ou cpf 
    int choice;
    printf("Digite a matricula do estudante que você quer atualizar: ");
    scanf("%d", &choice);

    int idx = KdAluno(baseOfStudents, qtd, choice);

    if (idx == -1) {
        printf("Aluno nao encontrado!\n");
        return false;
    }
    
    getchar();
    printf("Atualizando dados de %s\n", baseOfStudents[idx].name);
    printf("Digite o novo nome: ");
    fgets(baseOfStudents[idx].name, sizeof(baseOfStudents[idx].name), stdin);
    trimRight(baseOfStudents[idx].name);
    baseOfStudents[idx].name[strcspn(baseOfStudents[idx].name, "\n")] = '\0'; // tira o Enter
    if(!validateName(baseOfStudents[idx].name))   
    return false;
    
    printf("digite o novo genero do aluno\n");
    scanf(" %c", &baseOfStudents[idx].gender); //Usar scanf é problematico, ent dê um espaço antes do %c para eliminar o \n
    if(!validateGender(baseOfStudents[idx].gender))   
    return false;
    getchar();

    printf("digite a nova data de nascimento do aluno (ex: dd/mm/aaaa\n");
    fgets(baseOfStudents[idx].birthdate, sizeof(baseOfStudents[idx].birthdate), stdin);
    trimRight(baseOfStudents[idx].birthdate); //Remover possiveis \n no final do código
    baseOfStudents[idx].birthdate[strcspn(baseOfStudents[idx].birthdate, "\n")] = '\0'; // tira o Enter
    if(!validateBirthday(baseOfStudents[idx].birthdate))   
    return false;

    printf("Aluno atualizado com sucesso!\n");
    return true;

}

bool exlcuirAluno(student baseOfStudents[], int * qtd){
    int choice;
    printf("Digite a matricula do estudante que deseja excluir: ");
    scanf("%d", &choice);

    int idx = KdAluno(baseOfStudents, *qtd, choice);

    if (idx == -1) {
        printf("Aluno nao encontrado!\n");
        return false;
    }

    // Desloca os elementos para “remover” o aluno
    for (int i = idx; i < *qtd - 1; i++) {
        baseOfStudents[i] = baseOfStudents[i + 1];
    }

    (*qtd)--; // reduz a quantidade de alunos
    printf("Aluno excluido com sucesso!\n");
    return true;

}

int KdAluno(student baseOfStudents[], int qtd, int registration) {
    for (int i = 0; i < qtd; i++) {
        if (baseOfStudents[i].registration == registration) {
            return i; // retorna o índice do aluno
        }
    }
    return -1; // aluno não encontrado
}

// student buscarAluno(student baseOfStudents[], int qtd, int registration){

//     for (int i = 0; i < qtd; i++) {
//        if(baseOfStudents[i].registration == registration ){
//         return baseOfStudents[i].registration; 
//        }
//     }

//     printf("Aluno nao encontrado!\n");
//     return vazio;
// }