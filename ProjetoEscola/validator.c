#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> 
#include <string.h>
#include "validator.h"


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
        printf("Padrão invalido. Siga o padrão da data de nascimento1\n");
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
        
        
        return true; 
    }    
    
    return false; // caso raro 

}