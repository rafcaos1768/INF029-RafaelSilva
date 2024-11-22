
/*Faça uma funcao inverteData que receba uma data (ex:dd/mm/aaaa) e inverta essa
 data para aaaa/mm/dd. A funcao main deve imprimir a data original e a invertida após a chamada 
 da funcao inverteData. Considere que a string deve de data pode ter variacoes (exemplos:d/m/aa).
*/

#include <stdio.h> 
#include <stdlib.h> 

int quebraData(char data){
    char sDia[3]; //Delcara com um esoaco a mais para nao dar stack overflow 
    char SMes[3];
    char SAno[5]; 

    for(int i =0; data[i] != '/'; i++){ //atribuicao cate achar o '/'
        sDia[i] = data[i];
    }

    // utilizar o i para colocar o '\0' e indicar o fim da string 
    if(i == 1 || i == 2){
        sDia[i] = '\0'; 
    } else {
        return 0; //RETORNA UM VALOR INVALIDO 
    }

    //declar j para continuar aonde parou o '/'
    int j = i +1 

    for(;sMes[i] == '/', j++){ //Mesmo esquema de atribuição || Interesessante ressaltar que o for pode ser feito sem a parte de declarar variavel 
        sMes[i] = data[i];
    }

    if(j==1 || j==2 ){
        sMes[j] = '\0';
    }else {
        return 0; //RETORNA INVALIDO
    }

    int k = j+1; 

}

