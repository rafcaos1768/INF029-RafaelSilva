#include <stdlib.h> 
#include <stdio.h> 
#include <stdbool.h> 
#include <string.h>
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

//*FIM ALUNO */

//REPORTS 

int menuReports(){
    int choice; 
    printf("=== Informe a operação desejada==\n");
    printf("1-Relatorio dos Alunos\n2- Relatorio dos Professores\n3- Relatorios das Disciplinas\n4-Sair");
    scanf("%d", &choice);

    return choice; 
}

int menuReportsStudents(){
    int choice; 
    printf("=== Informe a operação desejada==\n");
    printf("1-Listar Alunos em ordem Alfabetica\n2- Relatorio dos Professores\n3- Relatorios das Disciplinas\n4-Sair");
    scanf("%d", &choice);

    return choice; 
}

void listAllStudantsAlphabeticOrder(student baseOfStudents[], int qtd){
    int index = 0;
    char names[MAX][MAX];
    char temp[MAX];
    int i,j;

    //ordenar nomes em ordem alfabetica usando bubble sort 
     for ( i = 0 ; i < qtd - 1; i++) {
        for (j = 0; j < qtd - 1 - i; j++) {
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

//END REPORTS 

void main(){
    introduction();

    student baseOfStudents[MAX]; // Variavel para armazena-los
    int CountStudents = 0; // quantidade de estudantes 
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
                    CountStudents++;
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
           
            int choiceReports=  menuReports();
            if(choiceReports==1){
                int choiceMenuReportsStudents = menuReportsStudents();
                if(choiceMenuReportsStudents==1){
                    listAllStudantsAlphabeticOrder(baseOfStudents, CountStudents);
                }
                
            }else if (choiceReports ==  2 ){

            }else if(choiceReports==3){


            }
           else if(choiceReports==0 ){ 
           printf("até logo!");
           break;
           }else{
            printf("opção invalida!");
           }
        }else{
            printf("Até logo");
            break;
        }    
    }



}