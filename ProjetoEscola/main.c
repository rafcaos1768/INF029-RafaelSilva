#include <stdlib.h> 

void introduction()
void menuStudent()
void menuTeacher()
void menuSubject()
void menuReports();


void main(){
    introduction();

    int choice = -1;
    while(choice!=0){
        printf("Escolha o modulo");
        printf("0- Sair\n1- Aluno\n2- Professor\n3- Disciplina\n 4-Relatorios ");
        scanf("%d", &choice);

        if(choice == 1 ){
            menuStudent();

        }else if (choice == 2){
            menuTeacher();
        }else if (choice == 3){
            menuSubject();
        }else if(choice == 4){
            menuReports();
        }else{
            printf("opção invalida!")
        }
    }



}