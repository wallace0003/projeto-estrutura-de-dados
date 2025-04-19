#include "estruturas.h"
#include <stdio.h>


int main(){
    LDE *lista = criar_lista();
    int num;
    for(int i = 0; i < 10; i++){
        scanf("%d", &num);
        inserir(lista, num);
        mostrar(lista);
    }

    for(int i = 0; i < 10; i++){
        scanf("%d", &num);
        remover(lista, num);
        mostrar(lista);
    }
    
    return 0;
}
