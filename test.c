#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main(){

    setlocale(LC_ALL, "Portuguese_Brazil");

    struct pedido{

        char data_venda[50];
        char nome_cliente[50];

    };

    struct produto{

        char nome_produto[50];
        float preco_uni;
        int qtd;

    };

    struct pedido cadastro[9999];
    struct produto cadastro1[9999];

    int op, pos_pedido = 0, out = 1, pos_produto = 0, qtd_produtos[9999], pos = 0, num_pos[9999], conta2 = 0, conta3 = 0;
    float soma_geral, soma_produto[9999], soma_pedido[9999];

    do{

    system("cls");

    out = 1;

    printf("\n--------------------");
    printf("\n|  Menu - Pedidos  |");
    printf("\n--------------------");
    printf("\n1. Cadastrar");
    printf("\n2. Listar");
    printf("\n3. Total dos pedidos");
    printf("\n0. Sair");
    printf("\n--------------------");
    printf("\nOpção: ");
    scanf("%d", &op);

    switch(op){
        case 1: {

            system("cls");

            out = 1;

            printf("\n========================");
            printf("\n|  CADASTRAR - PEDIDO  |");
            printf("\n========================");

            fflush(stdin);

            printf("\nData da venda: ");
            scanf("%[^\n]s", cadastro[pos_pedido].data_venda);

            printf("\nNome do cliente: ");
            scanf(" %[^\n]s", cadastro[pos_pedido].nome_cliente);

            while(out == 1){

                printf("\nNome do produto: ");
                scanf(" %[^\n]s", cadastro1[pos].nome_produto);

                printf("\nPreço unitário do produto (R$): ");
                scanf("%f", &cadastro1[pos].preco_uni);

                printf("\nQuantidade do produto: ");
                scanf("%d", &cadastro1[pos].qtd);

                printf("\nDeseja cadastrar mais um pedido [1 - SIM | 0 - N?O] ? ");
                scanf("%d", &out);
                printf("-------------------------------------------------------\n");

                soma_produto[pos] = (cadastro1[pos].preco_uni * cadastro1[pos].qtd);

                soma_pedido[pos_pedido] = soma_pedido[pos_pedido] + soma_produto[pos];

                pos++;

                pos_produto++;

                qtd_produtos[pos_pedido] = pos_produto;

            }

        pos_produto = 0;

        soma_geral = soma_geral + soma_pedido[pos_pedido];

        pos_pedido++;

        qtd_produtos[pos_pedido] = 0;

        system("pause");

        }break;


        case 2:{

            system("cls");

            printf("\n======================");
            printf("\n|  LISTAR - PEDIDOS  |");
            printf("\n======================");

                conta2 = 0;
                conta3 = 0;

                for(int conta = 0; conta < (pos_pedido); conta++){
                    printf("\n      PEDIDO %d", conta + 1);
                    printf("\n- Data da venda: %s\n- Nome do cliente: %s",
                    cadastro[conta].data_venda,
                    cadastro[conta].nome_cliente);

                    for(conta2 = 0; conta2 < qtd_produtos[conta]; conta2++){
                        printf("\n- Nome do produto: %s\n- Preço unitário (R$): %.2f\n- Quantidade: %d",
                        cadastro1[conta3].nome_produto,
                        cadastro1[conta3].preco_uni,
                        cadastro1[conta3].qtd);

                        printf("\n------------------------------");

                        conta3++;

                    }
                    printf("\nVALOR TOTAL PEDIDO %d: R$ %.2f\n\n", conta + 1, soma_pedido[conta]);
                }

        system("pause");

        }break;

        case 3: {

            system("cls");

            printf("\nVALOR TOTAL DOS PEDIDOS: %.2f\n", soma_geral);

            system("pause");

        }break;

    }

}while(op > 0);


    return 0;

}
