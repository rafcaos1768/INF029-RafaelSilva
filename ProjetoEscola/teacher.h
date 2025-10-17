#ifndef teacher_H
#define teacher_H

typedef struct teacher {
  char name[100];
  char gender;
  char id[100];
  char birthdate[100];
  int registration;
  int status;
} teacher;

int menuTeacher();
bool CadastrarProfessor(teacher baseOfTeachers[], int qtd); //FEITO FALTA VALIDADORES
bool exlcuirProfessor(teacher baseOfTeachers[]);//FAZER
bool buscarProfessor(teacher baseOfTeachers[], int qtd);//FAZER

#endif