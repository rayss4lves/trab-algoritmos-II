#include <stdio.h>
#include <string.h>

#define EVENTOS 15
#define CARACTERES 10

// vamos pensar em registar até 15 eventos (de até 10 caracteres POR EVENTO)por dia no nosso calendario (poderia ser feito de forma dinâmica com alocação tbm)
typedef struct Calendario
{
    char jan[31][EVENTOS][CARACTERES];
    char fev[29][EVENTOS][CARACTERES];
    char mar[31][EVENTOS][CARACTERES];
    char abr[30][EVENTOS][CARACTERES];
    char mai[31][EVENTOS][CARACTERES];
    char jun[30][EVENTOS][CARACTERES];
    char jul[31][EVENTOS][CARACTERES];
    char ago[31][EVENTOS][CARACTERES];
    char set[30][EVENTOS][CARACTERES];
    char out[31][EVENTOS][CARACTERES];
    char nov[30][EVENTOS][CARACTERES];
    char dez[31][EVENTOS][CARACTERES];

} Calendario;

Calendario criar_calendario()
{
    Calendario c;
    int i, j;

    // preenche os meses com 31 dias em 0
    for (i = 0; i < 31; i++)
    {
        for (j = 0; j < 15; j++)
        {
            strcpy(c.jan[i][j], "0");
            strcpy(c.mar[i][j], "0");
            strcpy(c.mai[i][j], "0");
            strcpy(c.jul[i][j], "0");
            strcpy(c.ago[i][j], "0");
            strcpy(c.out[i][j], "0");
            strcpy(c.dez[i][j], "0");
        }
    }

    // preenchendo os meses com 30 dias com 0
    for (i = 0; i < 30; i++)
    {
        for (j = 0; j < 15; j++)
        {
            strcpy(c.abr[i][j], "0");
            strcpy(c.jun[i][j], "0");
            strcpy(c.set[i][j], "0");
            strcpy(c.nov[i][j], "0");
        }
    }

    // preenchendo fevereiro
    for (i = 0; i < 29; i++)
    {
        for (j = 0; j < 15; j++)
            strcpy(c.fev[i][j], "0");
    }

    return c;
}

int cadastrar_evento(Calendario *calendario, int mes, int dia, char evento[], int total_eventos)
{
    int cadastrei = 0;
    int id_evento = 0;

    switch (mes)
    {
    case 1:
        if (dia > 0 && dia < 31)
        {
            id_evento = 0;
            while (id_evento < total_eventos && cadastrei == 0)
            {
                if (calendario->jan[dia - 1][id_evento][0] == '0')
                {
                    strcpy(calendario->jan[dia - 1][id_evento], evento);
                    cadastrei = 1;
                }
                id_evento +=1;
            }
        }
        else
            cadastrei = 0;
        break;

    case 2:
        if (dia > 0 && dia < 29)
        {
            id_evento = 0;
            while (id_evento < total_eventos && cadastrei == 0)
            {
                if (calendario->fev[dia - 1][id_evento][0] == '0')
                {
                    strcpy(calendario->fev[dia - 1][id_evento], evento);
                    cadastrei = 1;
                }
                id_evento +=1;
            }
        }
        break;

    case 3:
        if (dia > 0 && dia < 31)
        {
            id_evento = 0;
            while (id_evento < total_eventos && cadastrei == 0)
            {
                if (calendario->mar[dia - 1][id_evento][0] == '0')
                {
                    strcpy(calendario->mar[dia - 1][id_evento], evento);
                    cadastrei = 1;
                }
                id_evento +=1;
            }
        }
        break;

    case 4:
        if (dia > 0 && dia < 30)
        {
            id_evento = 0;
            while (id_evento < total_eventos && cadastrei == 0)
            {
                if (calendario->abr[dia - 1][id_evento][0] == '0')
                {
                    strcpy(calendario->abr[dia - 1][id_evento], evento);
                    cadastrei = 1;
                }
                id_evento +=1;
            }
        }
        break;

    case 5:
        if (dia > 0 && dia < 31)
        {
            id_evento = 0;
            while (id_evento < total_eventos && cadastrei == 0)
            {
                if (calendario->mai[dia - 1][id_evento][0] == '0')
                {
                    strcpy(calendario->mai[dia - 1][id_evento], evento);
                    cadastrei = 1;
                }
                id_evento +=1;
            }
        }
        break;

    case 6:
        if (dia > 0 && dia < 30)
        {
            id_evento = 0;
            while (id_evento < total_eventos && cadastrei == 0)
            {
                if (calendario->jun[dia - 1][id_evento][0] == '0')
                {
                    strcpy(calendario->jun[dia - 1][id_evento], evento);
                    cadastrei = 1;
                }
                id_evento +=1;
            }
        }
        break;

    case 7:
        if (dia > 0 && dia < 31)
        {
            id_evento = 0;
            while (id_evento < total_eventos && cadastrei == 0)
            {
                if (calendario->jul[dia - 1][id_evento][0] == '0')
                {
                    strcpy(calendario->jul[dia - 1][id_evento], evento);
                    cadastrei = 1;
                }
                id_evento +=1;
            }
        }
        break;

    case 8:
        if (dia > 0 && dia < 31)
        {
            id_evento = 0;
            while (id_evento < total_eventos && cadastrei == 0)
            {
                if (calendario->ago[dia - 1][id_evento][0] == '0')
                {
                    strcpy(calendario->ago[dia - 1][id_evento], evento);
                    cadastrei = 1;
                }
                id_evento +=1;
            }
        }
        break;

    case 9:
        if (dia > 0 && dia < 30)
        {
            id_evento = 0;
            while (id_evento < total_eventos && cadastrei == 0)
            {
                if (calendario->set[dia - 1][id_evento][0] == '0')
                {
                    strcpy(calendario->set[dia - 1][id_evento], evento);
                    cadastrei = 1;
                }
                id_evento +=1;
            }
        }
        break;

    case 10:
        if (dia > 0 && dia < 31)
        {
            id_evento = 0;
            while (id_evento < total_eventos && cadastrei == 0)
            {
                if (calendario->out[dia - 1][id_evento][0] == '0')
                {
                    strcpy(calendario->out[dia - 1][id_evento], evento);
                    cadastrei = 1;
                }
                id_evento +=1;
            }
        }
        break;

    case 11:
        if (dia > 0 && dia < 30)
        {
            id_evento = 0;
            while (id_evento < total_eventos && cadastrei == 0)
            {
                if (calendario->nov[dia - 1][id_evento][0] == '0')
                {
                    strcpy(calendario->nov[dia - 1][id_evento], evento);
                    cadastrei = 1;
                }
                id_evento +=1;
            }
        }
        break;

    case 12:
        if (dia > 0 && dia < 31)
        {
            id_evento = 0;
            while (id_evento < total_eventos && cadastrei == 0)
            {
                if (calendario->dez[dia - 1][id_evento][0] == '0')
                {
                    strcpy(calendario->dez[dia - 1][id_evento], evento);
                    cadastrei = 1;
                }
            }
            id_evento +=1;
        }
        break;

    default:
        cadastrei = 0;
        break;

        
    }
    return cadastrei;
}

void mostrar_todos_eventos_mes(Calendario *calendario, int mes, int total_eventos)
{
    int id_evento = 0;
    int dia;

    switch (mes)
    {
    case 1:

        for (dia = 1; dia < 32; dia++)
        {
            id_evento = 0;
            while (id_evento < total_eventos)
            {
                if (calendario->jan[dia - 1][id_evento][0] != '0')
                {
                    printf("\nDia %d -> %s", dia, calendario->jan[dia - 1][id_evento]);
                }
                id_evento +=1;
            }
        }
        break;

    case 2:
        for (dia = 1; dia < 30; dia++)
        {
            id_evento = 0;
            while (id_evento < total_eventos)
            {
                if (calendario->fev[dia - 1][id_evento][0] != '0')
                {
                    printf("\nDia %d -> %s", dia, calendario->fev[dia - 1][id_evento]);
                }
                id_evento +=1;
            }
        }
        break;

    case 3:
        for (dia = 1; dia < 32; dia++)
        {
            id_evento = 0;
            while (id_evento < total_eventos)
            {
                if (calendario->mar[dia - 1][id_evento][0] != '0')
                {
                    printf("\nDia %d -> %s", dia, calendario->mar[dia - 1][id_evento]);
                }
                id_evento +=1;
            }
        }
        break;

    case 4:
        for (dia = 1; dia < 31; dia++)
        {
            id_evento = 0;
            while (id_evento < total_eventos)
            {
                if (calendario->abr[dia - 1][id_evento][0] != '0')
                {
                    printf("\nDia %d -> %s", dia, calendario->abr[dia - 1][id_evento]);
                }
                id_evento +=1;
            }
        }
        break;

    case 5:
        for (dia = 1; dia < 32; dia++)
        {
            id_evento = 0;
            while (id_evento < total_eventos)
            {
                if (calendario->mai[dia - 1][id_evento][0] != '0')
                {
                    printf("\nDia %d -> %s", dia, calendario->mai[dia - 1][id_evento]);
                }
                id_evento +=1;
            }
        }
        break;

    case 6:
        for (dia = 1; dia < 31; dia++)
        {
            id_evento = 0;
            while (id_evento < total_eventos)
            {
                if (calendario->jun[dia - 1][id_evento][0] != '0')
                {
                    printf("\nDia %d -> %s", dia, calendario->jun[dia - 1][id_evento]);
                }
                id_evento +=1;
            }
        }
        break;

    case 7:
        for (dia = 1; dia < 32; dia++)
        {
            id_evento = 0;
            while (id_evento < total_eventos)
            {
                if (calendario->jul[dia - 1][id_evento][0] != '0')
                {
                    printf("\nDia %d -> %s", dia, calendario->jul[dia - 1][id_evento]);
                }
                id_evento +=1;
            }
        }
        break;

    case 8:
        for (dia = 1; dia < 32; dia++)
        {
            id_evento = 0;
            while (id_evento < total_eventos)
            {
                if (calendario->ago[dia - 1][id_evento][0] != '0')
                {
                    printf("\nDia %d -> %s", dia, calendario->ago[dia - 1][id_evento]);
                }
                id_evento +=1;
            }
            
        }
        break;

    case 9:
        for (dia = 1; dia < 31; dia++)
        {
            id_evento = 0;
            while (id_evento < total_eventos)
            {
                if (calendario->set[dia - 1][id_evento][0] != '0')
                {
                    printf("\nDia %d -> %s", dia, calendario->set[dia - 1][id_evento]);
                }
                id_evento +=1;
            }
        }
        break;

    case 10:
        for (dia = 1; dia < 32; dia++)
        {
            id_evento = 0;
            while (id_evento < total_eventos)
            {
                if (calendario->out[dia - 1][id_evento][0] != '0')
                {
                    printf("\nDia %d -> %s", dia, calendario->out[dia - 1][id_evento]);
                }
                id_evento +=1;
            }
            
        }
        break;

    case 11:
        for (dia = 1; dia < 31; dia++)
        {
            id_evento = 0;
            while (id_evento < total_eventos)
            {
                if (calendario->nov[dia - 1][id_evento][0] != '0')
                {
                    printf("\nDia %d -> %s", dia, calendario->nov[dia - 1][id_evento]);
                }
                id_evento +=1;
            }
           
        }
        break;

    case 12:
        for (dia = 1; dia < 32; dia++)
        {
            id_evento = 0;
            while (id_evento < total_eventos)
            {
                if (calendario->dez[dia - 1][id_evento][0] != '0')
                {
                    printf("\nDia %d -> %s", dia, calendario->dez[dia - 1][id_evento]);
                }
                id_evento +=1;
            }
            
        }

        break;

    default:
        printf("\nMes invalido!");
        break;
    }
}

int menu()
{
    int opc;

    printf("\n\n[1] - Cadastrar Evento\n[2] - Remover evento\n[3] - Buscar evento em um mês\n[4] - Mostrar todos os eventos de um mês\n[5] - Mostrar todos os eventos no calendario\n[0] - Sair\n\nDigite: ");
    setbuf(stdin, NULL);
    scanf("%d", &opc);

    return opc;
}

int main()
{
    int opc = 1, mes, dia;
    char evento[10];
    Calendario calendario = criar_calendario();

    while (opc != 0)
    {
        opc = menu();

        switch (opc)
        {

        case 1:
            printf("\nMes do evento: [1,2,3,4,5..12]: ");
            setbuf(stdin, NULL);
            scanf("%d", &mes);

            printf("\nDia do vento do evento: ");
            setbuf(stdin, NULL);
            scanf("%d", &dia);

            printf("\nEvento: ");
            setbuf(stdin, NULL);
            scanf("%[^\n]", evento);

            if (cadastrar_evento(&calendario, mes, dia, evento, EVENTOS))
            {
                printf("\n\nCadastro realizado com sucesso!\n");
            }
            else
                printf("\n\nFalha ao cadastrar!\n");

            break;

        case 4:
            printf("\nMes do evento: [1,2,3,4,5..12]: ");
            setbuf(stdin, NULL);
            scanf("%d", &mes);

            mostrar_todos_eventos_mes(&calendario, mes, EVENTOS);

        default:
            break;
        }
    }

    return 0;
}