#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Calendario
{
    int jan[31];
    int fev[29];
    int mar[31];
    int abr[30];
    int mai[31];
    int jun[30];
    int jul[31];
    int ago[31];
    int set[30];
    int out[31];
    int nov[30];
    int dez[31];

} Calendario;

typedef struct Quartos
{
    Calendario calendario;
    int numero_quarto;
    int status;
    int tipo;
    float valor;
} Quartos;

int reserva_quartos(Quartos *quarto, int contq, Calendario *calendario)
{
    int num, i = 0, j = 0;
    int op;
    int d_inicial, d_final;
    for (i = 0; i < contq; i++)
    {
        if (quarto[i].status == 1)
        {
            imprimir_quartos(quarto[i]);
        }
    }

    printf("informe o quarto que deseja reservar: ");
    setbuf(stdin, NULL);
    scanf("%d", &num);
    printf("informe o dia de inicio e o de saida: ");
    setbuf(stdin, NULL);
    scanf("%d%d", &d_inicial, &d_final);

    printf("Informe se o mes que voce deseja realizar a reserva\n\n");
    printf("\n\t1 - JANEIRO\n\t2 - FEVEREIRO\n\t3 - MARCO\n\t4 - ABRIL\n\t5 - MAIO\n\t6 - JUNHO\n\t7 - JULHO\n\t8 - AGOSTO\n\t9 - SETEMBRO\n\t10 - OUTUBRO\n\t11 - NOVEMBRO\n\t12 - DEZEMBRO\n\n: ");
    setbuf(stdin, NULL);
    scanf("%d", &op);

    for (i = 0; i < contq; i++)
    {
        if (num == quarto[i].numero_quarto)
        {
            quarto[i].status = 3;
            switch (op)
            {
            case 1:
                if (d_inicial >= 1 && d_final <= 31)
                {
                    for (j = d_inicial; j <= d_final; j++)
                    {
                        quarto[i].calendario.jan[i - 1].status = 3;
                    }
                }
                break;
            case 2:
                if (d_inicial >= 1 && d_final <= 29)
                {
                    for (j = d_inicial; j <= d_final; j++)
                    {
                        quarto[i].calendario.fev[j - 1] = 3;
                    }
                }
                break;
            case 3:
                if (d_inicial >= 1 && d_final <= 31)
                {
                    for (j = d_inicial; j <= d_final; j++)
                    {
                        quarto[i].calendario.jan[j - 1] = 3;
                    }
                }
                break;
            case 4:
                if (d_inicial >= 1 && d_final <= 30)
                {
                    for (j = d_inicial; j <= d_final; j++)
                    {
                        quarto[i].calendario.jan[i - 1] = 3;
                    }
                }
                break;
            case 5:
                if (d_inicial >= 1 && d_final <= 31)
                {
                    for (j = d_inicial; j <= d_final; j++)
                    {
                        quarto[i].calendario.jan[j - 1] = 3;
                    }
                }
                break;
            case 6:
                if (d_inicial >= 1 && d_final <= 30)
                {
                    for (j = d_inicial; j <= d_final; j++)
                    {
                        quarto[i].calendario.jan[j - 1] = 3;
                    }
                }
                break;
            case 7:
                if (d_inicial >= 1 && d_final <= 31)
                {
                    for (j = d_inicial; j <= d_final; j++)
                    {
                        quarto[i].calendario.jan[j - 1] = 3;
                    }
                }
                break;
            case 8:
                if (d_inicial >= 1 && d_final <= 31)
                {
                    for (j = d_inicial; j <= d_final; j++)
                    {
                        quarto[i].calendario.jan[j - 1] = 3;
                    }
                }
                break;
            case 9:
                if (d_inicial >= 1 && d_final <= 30)
                {
                    for (j = d_inicial; j <= d_final; j++)
                    {
                        quarto[i].calendario.jan[j - 1] = 3;
                    }
                }
                break;

            case 10:
                if (d_inicial >= 1 && d_final <= 31)
                {
                    for (j = d_inicial; j <= d_final; j++)
                    {
                        quarto[i].calendario.jan[j - 1] = 3;
                    }
                }
                break;

            case 11:
                if (d_inicial >= 1 && d_final <= 30)
                {
                    for (j = d_inicial; j <= d_final; j++)
                    {
                        quarto[i].calendario.nov[j - 1] = 3;
                    }
                }
                break;
            case 12:
                if (d_inicial >= 1 && d_final <= 31)
                {
                    for (j = d_inicial; j <= d_final; j++)
                    {
                        quarto[i].calendario.dez[j - 1] = 3;
                    }
                }
                break;

            default:
                break;
            }
        }
    }

    return 1;
}

int main()
{
    int op;
    int tam = 50;
    // int qreserva = ;
    int contq = 0;
    int contc = 0; // Inicializar a contagem de quartos
    Quartos *quartos;
    Calendario *calendario;
    Cliente *clientes;
    // Reserva *reserva;

    FILE *arquivo_quartos;
    FILE *arquivo_clientes;

    quartos = (Quartos *)calloc(tam, sizeof(Quartos));
    clientes = (Cliente *)calloc(tam, sizeof(Cliente));
    calendario = (Calendario *)calloc(31, sizeof(Calendario));
    // reserva = (Reserva *)calloc(100, sizeof(Reserva));

    do
    {
        op = menu_principal();
        switch (op)
        {
        case 1:
            menu_quarto(quartos, &contq, arquivo_quartos, tam);
            break;
        case 2:
            menu_cliente(clientes, &contc, arquivo_clientes, tam);
            break;
        case 3:
            reserva_quartos(quartos, contq, meses);
            break;
        default:
            printf("Opcao invalida!");
            break;
        }
    } while (op != 0);

    free(quartos);
    free(meses);
    return 0;
}
