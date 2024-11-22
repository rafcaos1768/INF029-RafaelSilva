
/*Faça uma funcao inverteData que receba uma data (ex:dd/mm/aaaa) e inverta essa
 data para aaaa/mm/dd. A funcao main deve imprimir a data original e a invertida após a chamada 
 da funcao inverteData. Considere que a string deve de data pode ter variacoes (exemplos:d/m/aa).
*/

#include <stdio.h> 
#include <stdlib.h> 

typedef struct TipoData{
    char dataInvertida[11];
    int validade;

} TipoData; 

// //Utilizar um retorno do tipoData para a função principal receber
// TipoData quebraData(char data){
//     TipoData mhData; //Necessario declarar o tipo minhadata para o retorno da função
//     char sDia[3]; //Delcara com um esoaco a mais para nao dar stack overflow 
//     char SMes[3];
//     char SAno[5]; 

//     for(int i =0; data[i] != '/'; i++){ //atribuicao cate achar o '/'
//         sDia[i] = data[i];
//     }

//     // utilizar o i para colocar o '\0' e indicar o fim da string 
//     if(i == 1 || i == 2){
//         sDia[i] = '\0'; 
//     } else {
//         return mhData.validade = 0; //RETORNA UM VALOR INVALIDO 
//     }

//     //declar j para continuar aonde parou o '/'
//     int j = i +1 
//     i = 0; //reiniciar variavel i

//     for(;data[j]!= '/'; j++){ //Mesmo esquema de atribuição || Interesessante ressaltar que o for pode ser feito sem a parte de declarar variavel 
//         sMes[i] = data[j];
//         i++;
//     }

//     if(i==1 || i==2 ){ // a variavel i eh utilizada pois ela mantem o controle do da variavel mes 
//         sMes[j] = '\0';
//     }else {
//         return mhData.validade = 0; //RETORNA INVALIDO
//     }

//     int k = j+1; 
//     i = 0;

//     for(; data[k]!= '/'; k++){
//         sAno[i]= data[k];
//         i++;
//     }
    
//     if(i== 2 || i == 4){
//         SAno[i]=='\0';
//     } else {
//         return mhData.validade = 0; //RETORNA INVALIDO
//     }

//     // for    

//     return mhData.validade = 1; // retorna valido 


// }

//Utilizar um retorno do tipoData para a função principal receber
TipoData quebraData(char data){
    TipoData mhData; //Necessario declarar o tipo minhadata para o retorno da função
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
        return mhData.validade = 0; //RETORNA UM VALOR INVALIDO 
    }

    //declar j para continuar aonde parou o '/'
    int j = i +1 
    i = 0; //reiniciar variavel i

    for(;data[j]; j++){ //Mesmo esquema de atribuição || Interesessante ressaltar que o for pode ser feito sem a parte de declarar variavel 
        sMes[i] = data[j];
        i++;
    }

    if(i==1 || i==2 ){ // a variavel i eh utilizada pois ela mantem o controle do da variavel mes 
        sMes[j] = '\0';
    }else {
        return mhData.validade = 0; //RETORNA INVALIDO
    }

    int k = j+1; 
    i = 0;

    for(; data[k]!= '/'; k++){
        sAno[i]= data[k];
        i++;
    }
    
    if(i== 2 || i == 4){
        SAno[i]=='\0';
    } else {
        return mhData.validade = 0; //RETORNA INVALIDO
    }


    ///////////////////////////////////////////////////
    //inverter string 
    for(int m=0; SMes[m] != '\0'; m++){
        mhData.dataInvertida[m]=sMes[m];
    }  

    mhData.dataInvertida [m]= '/';
    m ++; 

    for(int n=0; SMes[n] != '\0'; n++){
        mhData.dataInvertida[m]= 
    }

    return mhData.validade = 1; // retorna valido 


}







