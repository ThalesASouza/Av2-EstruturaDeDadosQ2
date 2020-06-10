#include "EstruturaLista.c"


int main(){
   Lista l;
   int opcao, res;
   char carta[100];
   char *noRemovido;



   do{
      system("cls");
      printf("\nInforme uma das opcoes abaixo:\n");
      printf("\n1-Inicializar deque"
             "\n2-Inserir um novo item no início"
             "\n3-Inserir um novo item no final"
             "\n4-Remover o item do início"
             "\n5-Remover o item do final"
             "\n6-Listar os dados do deque"
             "\n7-Verificar se deque está vazio"
             "\n8-Sair");

      printf("\n\nDigite sua opcao:");
      scanf("%d",&opcao);
      fflush(stdin);

      switch(opcao){

         case 1:inicializeList(&l);
                break;

         case 2:

            printf("Informe a carta que deseja inserir:");
            gets(carta);
            fflush(stdin);
            res = insereNoInicio(&l,carta);

            if(res == 0){
               printf("\nCarta nao inserida!\n");
            }else{
               printf("\nCarta %s inserida com sucesso!\n",carta);
            }

            break;

         case 3:

            printf("Informe a carta que deseja inserir:");
            gets(carta);
            fflush(stdin);
            res = insereNoFim(&l,carta);

            if(res == 0){
               printf("\nCarta nao inserida!\n");
            }else{
               printf("\nCarta %s inserida com sucesso!\n",carta);
            }

            break;

         case 4:

            noRemovido = removeNoInicio(&l);

            if(noRemovido == NULL){
               printf("\nDeque vazio.");
            }else{
               printf("\nCarta %s removida do deque\n",noRemovido);
            }

            break;

         case 5:

            noRemovido = removeNoFim(&l);

            if(noRemovido == NULL){
               printf("\nDeque vazio. %s",noRemovido);
            }else{
               printf("\nCarta %s removida do deque\n",noRemovido);
            }

            break;

         case 6:

            res = listar(&l);

            if(res == 0){
               printf("\nDeque vazio!\n");
            }

            break;

         case 7:
             res = isEmptyList(&l);

             if(res==1){
                printf("\nDeque vazio!\n");
             }else{
                 printf("\nDeque com dados!\n");
             }

             break;

         case 8:
                printf("Fim do programa!");
                break;

         default:
            printf("\nOpcao invalida!Tente novamente!\n");
      }
      printf("\nTECLE ENTER PARA CONTINUAR\n");
      getchar();
      fflush(stdin);
   }while(opcao!=8);


}
