#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> 
#include <string.h>
#include "validator.h"

bool validateName(char name[]){
    char *copyname= malloc(strlen(name)); strcpy(copyname, name);   
    int tamName = strlen(name);
    
    if (tamName < 2 || tamName > 50) {
        printf("Nome deve ter entre 2 e 50 caracteres.\n");
        return false;
    }

    for (int i = 0; i < tamName; i++) {
        if (!((name[i] >= 'A' && name[i] <= 'Z') || 
            (name[i] >= 'a' && name[i] <= 'z') || 
            name[i] == ' ')) {
            printf("Nome deve conter apenas letras e espaços.\n");
            return false;
        }
    }

    free(copyname);
    return true;

}


bool validateGender(char gender){
    if(gender != 'm' && gender!= 'M' && gender != 'F' && gender!= 'f'){
        printf("Genero não válido\n");
        return false;
    }

    return true;
}

bool validateBirthday(char birthOrigin[]){
    int index =0; 
    char * part; 
    char *birth = malloc(strlen(birthOrigin));
    strcpy(birth,birthOrigin); 
    int dd, mm, aa; 

    if(strlen(birth) != 10){
        printf("Padrão invalido. Siga o padrão da data de nascimento\n");
        free(birth);
        return false;
    }else{    
        while(index < 10){
           if((birth[index] >= 'A' && birth[index] <= 'Z') || (birth[index] >+ 'a' && birth[index] <= 'z') ){
            return false;
           }
           index ++; 
        }  
        part = strtok(birth, "/");
        dd = atoi(part);

        part = strtok(NULL, "/");
        mm = atoi(part);

        part = strtok(NULL, "/");
        aa = atoi(part);
        
        free(birth);
        return true; 
    }    
    free(birth);
    return false; // caso raro 

}

bool validateCPF(char CPF[]){
    int digit = strlen(CPF);
    char *cpf = malloc(strlen(CPF)); strcpy(cpf,CPF); // o primeiro é o destino e o segundo a origem 
    // int digits[3]; 

    if(digit != 14){
        printf("Padrão invalido! Siga o padrão de CPF\n");
        return false; 
    }else{
        for(int i=0; i < 14 ; i++){
            if(i==3 || i== 7 ){
                if(cpf[i] != '.' ){
                    printf("Padrão invalido ! Siga o padrão de CPF MMMM\n");
                    free(cpf);
                    return false; 
                }
            }else if(i==11){
                 if(cpf[i] != '-' ){
                    printf("Padrão invalido ! Siga o padrão de CPFNNN\n");
                    free(cpf);
                    return false; 
                }
            }else if (cpf[i] < '0' || cpf[i] > '9'){
               printf("Digite apenas números!\n");
                free(cpf);
                return false;  
            }
            
        }
         // char cpf2; strcpy(CPF,cpf2);  
    }
    free(cpf);
    return true; 
    
}

void trimRight(char *str) {
    int len = strlen(str);
    while (len > 0 && (str[len - 1] == ' ' || str[len - 1] == '\t' || str[len - 1] == '\n')) {
        str[len - 1] = '\0';
        len--;
    }
}
