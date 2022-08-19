#include <stdio.h>
#include <string.h>
typedef struct agenda
{
    char nome[101];
    char numero[12];
} Agenda;
void ordenar(){

}

int main(){
    Agenda contato[10];
    int quant= 0;
    int opcao = -1;
    while (opcao != 5){
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
            int ID = scanf("%d", &ID);
            if (ID >= quant){
                printf("CONTATO NAO ENCOTRADO!!!\n\n");
                printf("--------------------------------\n\n");
            }
            else{
                printf("Digite o Novo Nome: \n\n\t");
                scanf(" %s", contato[ID].nome);
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