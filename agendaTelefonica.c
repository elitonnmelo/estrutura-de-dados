#include <stdio.h>
#include <string.h>
typedef struct
{
    char nome[101];
    char numero[12];

} Agenda;
void ordenar( Agenda l[], int *quant){
    for (int i = 0 ; i < *quant - 1; i++){
        for (int j = 0; j <*quant - 1 -i; j++){
            if ( strcmp( l[j].nome, l[j + 1].nome) > 0){
                Agenda aux = l[j];
                l[j] = l[j+1];
                l[j+1] = aux;
                break;
            }
        }
    }

}
void ordenarSelection(Agenda l[], int *quant){
    for (int i = 0; i < *quant-1; i++){
        int menor = i;
        for (int j = i; j < *quant; j++){
           if ( strcmp( l[j].nome, l[menor].nome) > 0){
               menor = j;
           }
        }
        Agenda aux = l[i];
        l[i] = l[menor];
        l[menor] = aux;
        
    }
    
    
}
void ordenarInsert(Agenda l[], int *quant){
    int i,j;
    for ( i = 0; i < *quant; i++){
        Agenda aux = l[i];
        for (j = i-1; j <=0 && strcmp( l[j].nome, aux[i].nome) > 0 ; j--){
            l[j+1] = l[j];
            
        }
        l[j+1] = aux;
        
    }
    
    
}

int main(){
    Agenda contato[10];
    int quant= 0;
    int opcao = -1;
    while (opcao != 5){
        opcao = -1;
        printf("O QUE DESEJA FAZER AGORA? \n\t");
        printf("[0] Adicionar Conato\n\t");
        printf("[1] Remover Comtato\n\t");
        printf("[2] Exibir Agenda\n\t");
        printf("[3] Renomear Conato\n\t");
        printf("[4] Procurar contato\n\t");
        printf("[5] Sair\n");
        scanf("%d", &opcao);
        if(opcao == 0){
            printf("[0] Adicionar Conato\n\n");
            printf("Nome do Conato: ");
            scanf("%s", contato[quant].nome);
            printf("Numero do Conato: ");
            scanf(" %s", contato[quant].numero);
            quant++;
            printf("--------------------------------\n\n");
            //ordenar(contato, &quant);
            //ordenarInsert(contato, &quant);
            ordenarSelection(contato, &quant);
        }
        else if(opcao == 1){
            printf("[1] REMOVER CONTATO\n\n");
            printf("Digite o Indice do Contato: \n\n\t");
            int id;
            scanf("%d", &id);
            contato[id] = contato[quant - 1];
            //contato[id].numero = contato[quant - 1].numero;
            quant--;
            printf("--------------------------------\n\n");
        }
        else if (opcao == 2){
            printf("[2] EXIBIR AGENDA\n\n\t");
            if (quant < 1 ){
                printf("AGENDA VAZIA !!!\n\n");
            }
            else{
                printf("Total de contatos: [%d]\n", quant );
                for (int  i = 0; i < quant; i++){
                    printf("Indice [%d]\n\t", i);
                    printf("Nome: %s \n\t", contato[i].nome);
                    printf("Numero: %s \n\t", contato[i].numero);
                    printf("--------------------------------\n\n");
                }
            }
            
            
        }
        else if ( opcao == 3){
            printf("[3] RENOMEAR CONTATO\n\n");
            printf("Digite o Indice do Contato: ");
            int n;
            scanf("%d", &n);
            if (n > quant){
                printf("CONTATO NAO ENCOTRADO!!!\n\n");
                printf("--------------------------------\n\n");
            }
            else{
                printf("Digite o Novo Nome: \n\n\t");
                scanf(" %s", contato[n].nome);
                //strcpy(contato[n].nome, nick);
                printf("--------------------------------\n\n");
    
            }
            
            

        }
        else if ( opcao == 4 ){
            printf("[4] Procurar Contato \n\n");
            printf("Digite o nome que deseja pesquisar: \t");
            char pesq[101];
            scanf(" %s", pesq);
            int flag = 0;
            for (int i = 0; i < quant; i++){
                if ( strcmp(contato[i].nome, pesq) == 0){
                    printf("Contato encontrado!\n\n\t");
                    printf("Indice [%d]\n\t", i);
                    printf("Nome: %s \n\t", contato[i].nome);
                    printf("Numero: %s \n\t", contato[i].numero);
                    printf("--------------------------------\n\n");
                    flag = 1;
                    break;
                    
                }

            }
            if (flag == 0){
                printf("Contato nao encotrado\n\n");
                printf("--------------------------------\n\n");
            }
        }
        else if (opcao == 5){
            printf("SAINDO....\n");
            printf("...\n");
            printf("..\n");
            printf(".\n");
            printf("--------------------------------\n\n");
            
        }
        else {
            printf("OPCAO INVALIDA TENTE NOVAMENTE! \n\n");
            printf("--------------------------------\n\n");
        }

    }
    

}