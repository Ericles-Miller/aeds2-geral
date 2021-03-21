#include <conio.h>
#include <stdio.h>
void main(){
float vet[5] = {1.1,2.2,3.3,4.4,5.5};
float *f;
int i;
f = vet;//
printf("contador/valor/valor/endereco/endereco");
for(i = 0 ; i <= 4 ; i++)//comando de repetição que acessa os endereços do vetor
    {
        printf("\ni = %d",i);//imprimi o valor do contador
        printf(" vet[%d] = %.1f",i, vet[i]);// imprime o conteudo denro do vetor por exemplo 1.1
        printf(" *(f + %d) = %.1f",i, *(f+i));//imprime o endereço de memoria das posiçoes do vetor
        printf(" &vet[%d] = %X",i, &vet[i]); // imprime a posiçao do estáno vetor

        printf(" (f + %d) = %X",i, f+i);// imprime o endereço de memória do vetor
    }
}
