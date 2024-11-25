#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 


float calcularValorEuclidiano(float ponto1, float ponto2){ //Calcular valor euclidiano de ponto 
    float valor = sqrt((ponto1 * ponto1) + (ponto2 * ponto2)); 
    return valor; 
 
}