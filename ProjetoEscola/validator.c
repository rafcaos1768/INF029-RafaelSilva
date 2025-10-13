#include <stdio.h>
#include <stdbool.h> 
#include "validator.h"


bool validateGender(char gender){
    if(gender != 'm' && gender!= 'M' && gender != 'F' && gender!= 'f'){
        printf("Genero não válido\n");
        return false;
    }

    return true;
}