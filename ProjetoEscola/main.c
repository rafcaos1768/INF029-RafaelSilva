#include <stdlib.h> 
#include <stdio.h> 
#include <stdbool.h> 
#define MAX 100 

typedef struct student {
  char name[100];
  char gender;
  int age; 
  char id[100];
  char birthdate[100];
  int registration;
  int status;
} student;


void introduction(){
    printf("=====================================\n"); printf(" Bem-vindo ao Projeto Escola!\n"); printf(" Sistema de Cadastro Escolar\n"); printf("=====================================\n\n");
}



/*ALUNO*/
int menuStudent(){
    int choice; 
    printf("=== Informe a operação desejada==\n");
    printf("1-Cadastrar\n2-Atualizar\n3-Excluir\n4-voltar");
    scanf("%d", &choice);

    return choice; 
}

bool CadastrarAluno(student baseOfStudents[], int qtd){
    printf("digite o nome do aluno\n"); 
    scanf("%s", baseOfStudents[qtd].name);

    printf("digite a idade do aluno\n");
    scanf("%d", &baseOfStudents[qtd].age);

    printf("digite o CPF do aluno\n");
    scanf("%s", baseOfStudents[qtd].id);

    printf("digite o aniversario do aluno\n");
    scanf("%s", baseOfStudents[qtd].birthdate);

    printf("digite a matricula do alunoz\n");
    scanf("%d", &baseOfStudents[qtd].registration);

    return true; 
}

bool exlcuirAluno(student baseOfStudents[]){


}

//buscar aluno 
// void menuTeacher();
// void menuSubject();
// void menuReports();



void main(){
    introduction();

    student baseOfStudents[MAX];
    int CountStudents = 0;
    int choice = -1;

    while(1){
        printf("Escolha o modulo");
        printf("\n0- Sair\n1- Aluno\n2- Professor\n3- Disciplina\n4-Relatorios\n");
        scanf("%d", &choice);

        if(choice == 1 ){
            int choiceStudent = menuStudent();
            if(choiceStudent==1){
                bool studentOperation = CadastrarAluno(baseOfStudents, CountStudents);

                if(studentOperation== true ){
                    printf("\nAluno cadastrado com sucesso\n");
                }else{
                    printf("ERRO");
                }
              } else if (choice ==  2 ){

              }else if(choice==3){


              }

        }else if (choice == 2){
            // menuTeacher();
        }else if (choice == 3){
            // menuSubject();
        }else if(choice == 4){
            // menuReports();
        }else if(choice==0 ){
           printf("até logo!");
           break;
        }else{
             printf("opção invalida!");
        }
    }



}