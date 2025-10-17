#include <stdlib.h> 
#include <stdio.h> 
#include <stdbool.h> 
#include <string.h>
#include "student.h"
#include "report.h"
#include "teacher.h"


#define MAX 100 


void introduction(){
    printf("=====================================\n"); printf(" Bem-vindo ao Projeto Escola!\n"); printf(" Sistema de Cadastro Escolar\n"); printf("=====================================\n\n");
}

// void menuTeacher();
// void menuSubject();
// void menuReports();


void main(){
    introduction();

    student baseOfStudents[MAX]; // Variavel para armazena-los
    int CountStudents = 0;
    int countTeachers = 0; 
    int choice = -1;

    while(1){
        printf("Escolha o modulo");
        printf("\n0- Sair\n1- Aluno\n2- Professor\n3- Disciplina\n4- Relatorios\nOption:");
        scanf("%d", &choice);
        printf("\n");

        if(choice == 1 ){
            int choiceStudent = menuStudent();
            if(choiceStudent==1){
                bool studentOperation = CadastrarAluno(baseOfStudents, CountStudents);

                if(studentOperation== true ){
                    printf("\nAluno cadastrado com sucesso\n");
                    printf("Aluno:%s cadastrado\n\n", baseOfStudents[CountStudents].name);
                    CountStudents++;
                }else if(studentOperation == false){
                    printf("Estudante não cadastrado\n\n");
                }else{
                    printf("ERRO");
                }

            }else if (choiceStudent==2 ){
                bool result2 = atualizarAluno(baseOfStudents, CountStudents); 
                if(!result2)
                printf("erro\n");

            }else if(choiceStudent==3){
                bool result3 = exlcuirAluno(baseOfStudents,&CountStudents);
               if(!result3)
                printf("erro\n"); 
                

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
        }else if(choice == 0){
            printf("Até logo\n\n");
            break;
        }else {
            printf("opcção invalida\n");
        }
    }



}