#ifndef student_H
#define student_H

typedef struct student {
  char name[100];
  char gender;
  char id[100];
  char birthdate[100];
  int registration;
  int status;
} student;

int menuStudent();
bool CadastrarAluno(student baseOfStudents[], int qtd); //FEITO FALTA VALIDADORES
bool exlcuirAluno(student baseOfStudents[]);//FAZER
bool buscarAluno(student baseOfStudents[], int qtd);//FAZER

#endif