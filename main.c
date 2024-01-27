//quarto[i].calendario.jan[i - 1].status

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct Dia
{
    int status; 
} Dia;

typedef struct Quartos
{
    struct Dia status[12][31]; // Array para cada dia do mês
    int numero_quarto;
    int tipo;
    float valor;
    int qchecking;
} Quartos;

typedef struct Cliente
{
    int ano;
    int dia;
    int mes;
    char nome[50];
    char cpf[15];
    char telefone[15];
    char rg[7];
    char rua[30];
    char cidade[30];
    char email[50];
} Cliente;

typedef struct Reserva
{

    char nome[50];
    char cpf[15];
    char telefone[15];
    int nmr_quarto;
    int mes;
    int d_inicial;
    int d_final;
    int status_pagamento;
    float valor_reserva;
    int cod_reserva;

} Reserva;

int menu_principal()
{ // menu 0
    int op;
    printf("1 - Informacoes dos quartos\n2 - Informacoes do cliente\n0 - Sair\n");
    setbuf(stdin, NULL);
    scanf("%d", &op);
    return op;
}

Quartos cadastrar_quartos(Quartos quarto)
{
    int stts;
    printf("\nInforme as informacoes do quarto:");
    printf("\nNumero: ");
    setbuf(stdin, NULL);
    scanf("%d", &quarto.numero_quarto);

    printf("\nValor: ");
    setbuf(stdin, NULL);
    scanf("%f", &quarto.valor);

    printf("\nTipo: ");
    printf("\n\t0 - casal\n\t1 - solteiro\n\t2 - suite.\n");
    setbuf(stdin, NULL);
    scanf("%d", &quarto.tipo);
    printf("Informe o status do quarto(1-vago 2-ocupado): ");
    scanf("%d", &stts);

    for (int mes = 0; mes < 12; mes++)
    {
        for (int dia = 0; dia < 31; dia++)
        {
            quarto.status[mes][dia].status = stts;
        }
    }

    return quarto;
}

void imprimir_quartos(Quartos quarto)
{
    printf("Numero: %d\n", quarto.numero_quarto);
    printf("Valor: %.2f\n", quarto.valor);
    printf("Tipo: %d\n", quarto.tipo);
    for (int mes = 0; mes < 12; mes++)
    {
        for (int dia = 0; dia < 31; dia++)
        {
            printf("Status do mes %d no dia %d = %d\n", mes + 1, dia + 1, quarto.status[mes][dia].status);
        }
        printf("\n");
    }
}

void buscar_por_numero(Quartos *quarto, int contq)
{
    int i = 0;
    int id;

    printf("Informe o numero do quarto que deseja consultar: \n");
    setbuf(stdin, NULL);
    scanf("%d", &id);
    for (i = 0; i < contq; i++)
    {
        if (quarto[i].numero_quarto == id)
        {
            imprimir_quartos(quarto[i]);
        }
    }
}

void buscar_por_tipo(Quartos *quarto, int contq)
{
    int i = 0;
    int tip;

    printf("Informe o tipo de quarto que deseja consultar: \n");
    printf("\n\t0 - casal\n\t1 - solteiro\n\t2 - suite.\n");
    setbuf(stdin, NULL);
    scanf("%d", &tip);

    for (i = 0; i < contq; i++)
    {
        if (quarto[i].tipo == tip)
        {
            imprimir_quartos(quarto[i]);
        }
    }
}

void menu_busca_quartos(Quartos *quarto, int contq)
{
    int op;
    printf("\n\t=====================\n");
    printf("\n\t1 - Buscar por numero\n\t2 - Buscar por status\n\t3 - Buscar por tipo\n\t4 - Buscar por preco\n\n");
    printf("\n\t=====================\n");
    scanf("%d", &op);
    switch (op)
    {
    case 1:
        buscar_por_numero(quarto, contq);
        break;
    }
}

void editar_quarto(Quartos *quarto, int contq)
{

    int i = 0;
    int id;

    printf("Informe o numero do quarto que deseja realizar a alteracao do valor: \n");
    scanf("%d", &id);

    for (i = 0; i < contq; i++)
    {
        if (quarto[i].numero_quarto == id)
        {
            printf("Informe o novo valor do quarto: \n");
            scanf("%f", &(quarto[i].valor));
        }
    }
}

Cliente cadastrar_informacoes_clientes(Cliente cliente)
{
    printf("\nInforme as suas informacoes:");
    printf("\nNome: ");
    setbuf(stdin, NULL);
    scanf("%[^\n]", cliente.nome);

    printf("\nData de nascimento(dd/mm/aaaa) separado por espaco: ");
    setbuf(stdin, NULL);
    scanf("%d %d %d", &cliente.dia, &cliente.mes, &cliente.ano);

    printf("\nTelefone: ");
    setbuf(stdin, NULL);
    scanf("%[^\n]", cliente.telefone);

    printf("\nCPF ");
    setbuf(stdin, NULL);
    scanf("%[^\n]", cliente.cpf);

    printf("\nRG: ");
    setbuf(stdin, NULL);
    scanf("%[^\n]", cliente.rg);

    printf("\nRua: ");
    setbuf(stdin, NULL);
    scanf("%[^\n]", cliente.rua);

    printf("\nCidade: ");
    setbuf(stdin, NULL);
    scanf("%[^\n]", cliente.cidade);

    printf("\nE-mal: ");
    setbuf(stdin, NULL);
    scanf("%[^\n]", cliente.email);

    return cliente;
}

void mostrar_cliente(Cliente cliente)
{
    printf("\nNome: %s\n", cliente.nome);
    printf("Data de nascimento: %d/%d/%d\n", cliente.dia, cliente.mes, cliente.ano);
    printf("Telefone: %s\n", cliente.telefone);
    printf("CPF: %s\n", cliente.cpf);
    printf("RG: %s\n", cliente.rg);
    printf("Rua: %s\n", cliente.rua);
    printf("Cidade: %s\n\n", cliente.cidade);
}

void buscar_por_cpf(Cliente *cliente, int *contc, int tam)
{

    int i = 0;
    char cpf[12];
    int encontrou = 0;

    printf("Informe o numero de cpf que deseja consultar: \n");
    setbuf(stdin, NULL);
    scanf("%[^\n]", cpf);

    for (i = 0; i < *contc; i++)
    {
        if (strcmp(cliente[i].cpf, cpf) == 0)
        {
            mostrar_cliente(cliente[i]);
            encontrou = 1;
        }
    }
    if (encontrou != 1)
    {
        if (*contc < tam)
        {
            cliente[*contc] = cadastrar_informacoes_clientes(cliente[*contc]);
        }
    }
}

void buscar_por_rg(Cliente *cliente, int *contc, int tam)
{

    int i = 0;
    char rg[7];
    int encontrou = 0;

    printf("Informe o numero de rg que deseja consultar: \n");
    setbuf(stdin, NULL);
    scanf("%[^\n]", rg);

    for (i = 0; i < *contc; i++)
    {
        if (strcmp(cliente[i].rg, rg) == 0)
        {
            mostrar_cliente(cliente[i]);
            encontrou = 1;
        }
    }
    if (encontrou != 1)
    {
        if (*contc < tam)
        {
            cliente[*contc] = cadastrar_informacoes_clientes(cliente[*contc]);
        }
    }
}

void menu_editar_cliente(Cliente *cliente, int *contc, int tam)
{

    int op;
    int i = 0;
    char cpf[12];
    int encontrou = 0;

    printf("Informe o CPF do cliente que deseja editar informacoes: \n");
    setbuf(stdin, NULL);
    scanf("%[^\n]", cpf);

    for (i = 0; i < *contc; i++)
    {
        if (strcmp(cliente[i].cpf, cpf) == 0)
        {
            printf("\n\t=====================\n");
            printf("\n\tQual informacao deseja editar:\n");
            printf("\n\t1 - Nome\n\t2- Data de aniversario\n\t 3- Telefone\n\t4 - CPF\n\t5 - RG\n\t6 - Endereco\n\t7 - email\n\n");
            printf("\n\t=====================\n");
            scanf("%d", &op);
            switch (op)
            {
            case 1:
                printf("Informe o novo nome do cliente: \n");
                setbuf(stdin, NULL);
                scanf("%[^\n]", cliente[i].nome);
                break;
            case 2:
                printf("Informe a nova data de aniversario: \n");
                setbuf(stdin, NULL);
                scanf("%d%d%d", &(cliente[i].dia), &(cliente[i].mes), &(cliente[i].ano));
                break;
            case 3:
                printf("Informe o numero de telefone: \n");
                setbuf(stdin, NULL);
                scanf("%[^\n]", cliente[i].telefone);
                break;
            case 4:
                printf("Informe o novo cpf: \n");
                setbuf(stdin, NULL);
                scanf("%[^\n]", cliente[i].cpf);
                break;
            case 5:
                printf("Informe o novo rg: \n");
                setbuf(stdin, NULL);
                scanf("%[^\n]", cliente[i].rg);
                break;
            case 6:
                printf("Informe o novo endereco (Rua e Cidade): \n");
                setbuf(stdin, NULL);
                scanf("%[^\n]%[^\n]", cliente[i].rua, cliente[i].cidade);
                break;
            case 7:
                printf("Informe o novo email: \n");
                setbuf(stdin, NULL);
                scanf("%[^\n]", cliente[i].email);
                break;
            default:
                printf("Opcao invalida!");
                break;
            }
            encontrou = 1;
        }
    }

    if (encontrou != 1)
    {
        if (*contc < tam)
        {
            cliente[*contc] = cadastrar_informacoes_clientes(cliente[*contc]);
        }
    }
}

void menu_busca_clientes(Cliente *cliente, int *contc, int tam)
{

    int op;
    printf("\n\t=====================\n");
    printf("\n\t1 - Buscar por CPF\n\t2 - Buscar por RG\n\n");
    printf("\n\t=====================\n");
    scanf("%d", &op);
    switch (op)
    {
    case 1:
        buscar_por_cpf(cliente, contc, tam);
        break;
    case 2:
        buscar_por_rg(cliente, contc, tam);
        break;
    default:
        printf("Opcao invalida!");
        break;
    }
}

void menu_cliente(Cliente *cliente, int *contc, FILE *arquivo_cliente, int tam)
{
    int op;

    printf("\n\t------------------------\n");
    printf("\n\tMenu Cliente:\n");
    printf("\n\t1 - Cadastrar\n\t2 - Consultar Cliente\n\t3 - Editar informacoes do Cliente\n\t4 - Remover\n\n: ");
    printf("\n\t------------------------\n");
    setbuf(stdin, NULL);
    scanf("%d", &op);

    switch (op)
    {
    case 1:
        arquivo_cliente = fopen("Cliente.txt", "a+");
        if (arquivo_cliente == NULL)
        {
            printf("Não foi possivel abrir o arquivo.");
            return;
        }
        if (*contc < tam)
        {
            cliente[*contc] = cadastrar_informacoes_clientes(cliente[*contc]);
            fprintf(arquivo_cliente, "%s %d/%d/%d %s %s %s %s %s %s\n", cliente[*contc].nome, cliente[*contc].dia, cliente[*contc].mes, cliente[*contc].ano, cliente[*contc].telefone, cliente[*contc].cpf, cliente[*contc].rg, cliente[*contc].rua, cliente[*contc].cidade, cliente[*contc].email);
            fclose(arquivo_cliente);
            *contc += 1;
        }
        break;

    case 2:
        menu_busca_clientes(cliente, contc, tam);
        break;
    case 3:
        menu_editar_cliente(cliente, contc, tam);
        break;
    default:
        printf("Opcao invalida!");
        break;
    }
}

void reserva_quartos(Quartos *quarto, int contq, Cliente *cliente, Reserva *reserva, int contc)
{

    int num, dia = 0;
    int mes, tip, i = 0, j = 0;
    int d_inicial, d_final;
    char cpf[12];

    srand(time(NULL));
    printf("\n\t=====================================\n\n");
    printf("Informe o tipo de quarto que deseja:\n");
    printf("\n\t1 - Solteiro\n\t2 - Casal\n\t3 - Suite: \n");
    printf("\n\t=====================================\n\n");
    scanf("%d", &tip);

    switch (tip)
    {
    case 1:

        printf("informe o dia de inicio e o de saida: ");
        setbuf(stdin, NULL);
        scanf("%d%d", &d_inicial, &d_final);

        printf("Informe se o mes que voce deseja realizar a reserva\n\n");
        setbuf(stdin, NULL);
        scanf("%d", &mes);

        for (i = 0; i < contq; i++)
        {
            for (dia = d_inicial; dia <= d_final; dia++)
            {
                if (quarto[i].tipo == 1 && quarto[i].status[mes][dia].status == 1)
                {
                    printf("Numero: %d\n", quarto[i].numero_quarto);
                    printf("Valor: %.2f\n", quarto[i].valor);
                    break;
                }
            }
        }

        printf("informe o quarto que deseja reservar: ");
        scanf("%d", &num);
        fflush(stdin);
        printf("Informe o seu cpf: ");
        scanf("%[^\n]", cpf);
        for (int i = 0; i < contq; i++)
        {
            for (dia = d_inicial; dia <= d_final; dia++)
            {
                if (quarto[i].numero_quarto == num && quarto[i].status[mes][dia].status == 1)
                    quarto[i].status[mes][dia].status = 3; // 3 - reservado
                else if (quarto[i].status[mes][dia].status == 3)
                {
                    printf("O quarto informado já está reservado!!");
                    break;
                }
            }
        }
        for (i = 0; i < contc; i++)
        {
            for (j = 0; j < contc; j++)
            {
                if (cliente[i].cpf == cpf)
                {
                    strcpy(reserva[j].nome, cliente[i].nome);
                    strcpy(reserva[j].cpf, cliente[i].cpf);
                    strcpy(reserva[j].telefone, cliente[i].telefone);
                    reserva[j].nmr_quarto = quarto[num].numero_quarto;
                    reserva[j].d_inicial = d_inicial;
                    reserva[j].d_final = d_final;
                    reserva[i].mes = mes;
                    reserva[j].status_pagamento = 0;
                    reserva[j].valor_reserva = quarto[num].valor;
                    reserva[j].cod_reserva = rand() % 100000000 + 1;
                }
            }
        }

        break;
    case 2:

        printf("informe o dia de inicio e o de saida: ");
        setbuf(stdin, NULL);
        scanf("%d%d", &d_inicial, &d_final);

        printf("Informe se o mes que voce deseja realizar a reserva\n\n");
        setbuf(stdin, NULL);
        scanf("%d", &mes);

        for (i = 0; i < contq; i++)
        {
            for (dia = d_inicial; dia <= d_final; dia++)
            {
                if (quarto[i].tipo == 2 && quarto[i].status[mes][dia].status == 1)
                {
                    printf("Numero: %d\n", quarto[i].numero_quarto);
                    printf("Valor: %.2f\n", quarto[i].valor);
                    break;
                }
            }
        }

        printf("informe o quarto que deseja reservar: ");
        scanf("%d", &num);
        fflush(stdin);
        printf("Informe o seu cpf: ");
        scanf("%[^\n]", cpf);
        for (int i = 0; i < contq; i++)
        {
            for (dia = d_inicial; dia <= d_final; dia++)
            {
                if (quarto[i].numero_quarto == num && quarto[i].status[mes][dia].status == 1)
                    quarto[i].status[mes][dia].status = 3; // 3 - reservado
                else if (quarto[i].status[mes][dia].status == 3)
                {
                    printf("O quarto informado já está reservado!!");
                    reserva_quartos(quarto, contq, cliente, reserva, contc);
                    break;
                }
            }
        }
        for (i = 0; i < contc; i++)
        {
            if (cliente[i].cpf == cpf)
            {
                strcpy(reserva[i].nome, cliente[i].nome);
                strcpy(reserva[i].cpf, cliente[i].cpf);
                strcpy(reserva[i].telefone, cliente[i].telefone);
                reserva[i].nmr_quarto = quarto[i].numero_quarto;
                reserva[i].d_inicial = d_inicial;
                reserva[i].d_final = d_final;
                reserva[i].status_pagamento = 0;
                reserva[i].valor_reserva = quarto[i].valor;
                reserva[i].cod_reserva = rand() % 100000000 + 1;
            }
        }
        break;

    case 3:

        printf("informe o dia de inicio e o de saida: ");
        setbuf(stdin, NULL);
        scanf("%d%d", &d_inicial, &d_final);

        printf("Informe se o mes que voce deseja realizar a reserva\n\n");
        setbuf(stdin, NULL);
        scanf("%d", &mes);

        for (i = 0; i < contq; i++)
        {
            for (dia = d_inicial; dia <= d_final; dia++)
            {
                if (quarto[i].tipo == 3 && quarto[i].status[mes][dia].status == 1)
                {
                    printf("Numero: %d\n", quarto[i].numero_quarto);
                    printf("Valor: %.2f\n", quarto[i].valor);
                    break;
                }
            }
        }

        printf("informe o quarto que deseja reservar: ");
        scanf("%d", &num);
        fflush(stdin);
        printf("Informe o seu cpf: ");
        scanf("%[^\n]", cpf);
        for (int i = 0; i < contq; i++)
        {
            for (dia = d_inicial; dia <= d_final; dia++)
            {
                if (quarto[i].numero_quarto == num && quarto[i].status[mes][dia].status == 1)
                    quarto[i].status[mes][dia].status = 3; // 3 - reservado
                else if (quarto[i].status[mes][dia].status == 3)
                {
                    printf("O quarto informado já está reservado!!");
                    reserva_quartos(quarto, contq, cliente, reserva, contc);
                    break;
                }
            }
        }
        for (i = 0; i < contc; i++)
        {
            if (cliente[i].cpf == cpf)
            {
                strcpy(reserva[i].nome, cliente[i].nome);
                strcpy(reserva[i].cpf, cliente[i].cpf);
                strcpy(reserva[i].telefone, cliente[i].telefone);
                reserva[i].nmr_quarto = quarto[i].numero_quarto;
                reserva[i].d_inicial = d_inicial;
                reserva[i].d_final = d_final;
                reserva[i].status_pagamento = 0;
                reserva[i].valor_reserva = quarto[i].valor;
                reserva[i].cod_reserva = rand() % 100000000 + 1;
            }
        }
        break;
    }
}

void listar_reservas(Reserva reserva)
{

    printf("\nNome: %s", reserva.nome);
    printf("\nCPF: %s", reserva.cpf);
    printf("\nTelefone: %s", reserva.telefone);
    printf("\nNumero do quarto: %d", reserva.nmr_quarto);
    printf("\nDia de inicio: %d", reserva.d_inicial);
    printf("\nDia final: %d", reserva.d_final);
    printf("\nMes: %d", reserva.mes);
    printf("\nValor da reserva: %f", reserva.valor_reserva);
    printf("\nTelefone: %d", reserva.status_pagamento);
    printf("\nTelefone: %d", reserva.cod_reserva);
}

void menu_listar_reservas(Reserva *reserva, int qreserva)
{
    int op, j = 0;
    char cpf[10];

    printf("-----Menu Reseserva-----:\n");
    printf("\n\t1 - Realizar reserva\n\t2 - Consultar reserva\n\t3 - Excluir reserva\n\n: ");
    setbuf(stdin, NULL);
    scanf("%d", &op);
    switch (op)
    {
    case 1:
        printf("Informe o seu cpf: \n");
        setbuf(stdin, NULL);
        scanf("%[^\n]", cpf);
        for (j = 0; j < qreserva; j++)
        {
            if (strcmp(reserva[j].cpf, cpf) == 0)
            {
                listar_reservas(reserva[j]);
            }
        }
        break;

    default:
        break;
    }
}

void menu_reserva(Quartos *quarto, int contq, Cliente *cliente, Reserva *reserva, int contc, int *qreserva)
{

    int op;

    printf("-----Menu Reseserva-----:\n");
    printf("\n\t1 - Realizar reserva\n\t2 - Consultar reserva\n\t3 - Excluir reserva\n\n: ");
    setbuf(stdin, NULL);
    scanf("%d", &op);

    switch (op)
    {
    case 1:
        reserva_quartos(quarto, contq, cliente, reserva, contc);
        (*qreserva)++;
        break;

    case 2:
        menu_listar_reservas(reserva, qreserva);
        break;
    case 3:

        break;
    default:
        printf("Opcao invalida!");
        break;
    }
}

void menu_quarto(Quartos *quarto, int *contq, FILE *arquivo_quarto, int tam)
{
    int op;

    printf("-----Menu Quarto-----:\n");
    printf("\n\t1 - Cadastrar informacoes do quarto\n\t2 - Consultar informacoes do quarto\n\t3 - Editar informacoes\n\t4 - Remover\n\n: ");
    setbuf(stdin, NULL);
    scanf("%d", &op);

    switch (op)
    {
    case 1:
        arquivo_quarto = fopen("Quartos.txt", "a+");
        if (arquivo_quarto == NULL)
        {
            printf("Não foi possivel abrir o arquivo.");
            return;
        }
        if (*contq < tam)
        {
            quarto[*contq] = cadastrar_quartos(quarto[*contq]);
            fprintf(arquivo_quarto, "%d %.2f %d \n", quarto[*contq].numero_quarto, quarto[*contq].valor, quarto[*contq].tipo);
            fclose(arquivo_quarto);
            *contq += 1;
        }
        break;

    case 2:
        menu_busca_quartos(quarto, *contq);
        break;
    case 3:
        editar_quarto(quarto, *contq);
        break;
    default:
        printf("Opcao invalida!");
        break;
    }
}

void realizar_pagamento(Quartos *quarto, int contq, Reserva *reserva, int contc)
{
    int i = 0, j = 0;
    char cpf[12];
    char situacao[5];

    printf("Informe o seu cpf: \n");
    scanf(" %[^\n]", cpf);

    for (i = 0; i < contc; i++)
    {
        if (strcmp(reserva[i].cpf, cpf) == 0)
        {
            printf("valor do pagamento: %.2f \n", reserva[i].valor_reserva);
            printf("Pagamento concluído? \n");
            scanf(" %[^\n]", situacao);
            if (strcmp(situacao, "sim") == 0)
            {
                printf("\n\tPagamento realizado com sucesso!!!\n");
                for (j = 0; j < contq; j++)
                {
                    if (reserva[i].nmr_quarto == quarto[j].numero_quarto)
                    {
                        reserva[i].status_pagamento = 1;
                    }
                }
            }
            else
            {
                printf("\n\tDeseja realizar o pagamento novamente? \n");
            }
        }
    }
}

void checking(Quartos *quarto, int contq, Reserva *reserva, int contc, int *qchecking)
{
    int i = 0;
    char cpf[12], res[5];
    char op[5];

    printf("Informe o seu cpf: \n");
    scanf(" %[^\n]", cpf);

    for (i = 0; i < contc; i++)
    {
        if (strcmp(reserva[i].cpf, cpf) == 0)
        {
            printf("nome: %s ", reserva[i].nome);
            printf("CPF: %s ", reserva[i].cpf);
            printf("Numero do quarto: %d ", reserva[i].nmr_quarto);
            printf("Codigo de reserva: %d ", reserva[i].cod_reserva);
            printf("Valor total: %.2f ", reserva[i].valor_reserva);
        }
    }

    printf("Deseja realizar o checking? \n");
    scanf(" %[^\n]", op);
    if (strcmp(op, "sim") == 0)
    {
        qchecking += 1;
    }
    else
    {
        printf("\n\tSeja bem-vindo ao Hotel!!\n");
    }

    printf("Deseja realizar pagamento neste momento? \n");
    scanf(" %[^\n]", res);
    if (strcmp(res, "sim") == 0)
    {
        realizar_pagamento(quarto, contq, reserva, contc);
    }
    else
    {
        printf("\n\tSeja bem-vindo ao Hotel!!\n");
    }
}

void checkout(Quartos *quarto, int contq, Reserva *reserva, int contc)
{
    int i = 0;
    char cpf[12], r[5];

    int dia_f, dia_i, mes;

    printf("Informe o seu cpf: \n");
    scanf(" %[^\n]", cpf);

    for (i = 0; i < contc; i++)
    {
        if (strcmp(reserva[i].cpf, cpf) == 0)
        {
            printf("nome: %s ", reserva[i].nome);
            printf("CPF: %s ", reserva[i].cpf);
            printf("Numero do quarto: %d ", reserva[i].nmr_quarto);
            printf("Codigo de reserva: %d ", reserva[i].cod_reserva);
        }
    }
    printf("Já realizou pagamento? \n");
    scanf(" %[^\n]", r);

    for (i = 0; i < contc; i++)
    {
        mes = reserva[i].mes;
        dia_i = reserva[i].d_inicial;
        dia_f = reserva[i].d_final;
    }

    if (strcmp(r, "nao") == 0)
    {
        realizar_pagamento(quarto, contq, reserva, contq);
    }
    else
    {
        printf("\n\tVolte sempre ao nosso Hotel!!\n");
        for (i = dia_i; i < dia_f; i++)
        {
            quarto[i].status[mes][i].status = 1;
        }
    }
}

int main()
{
    int op;
    int tam = 50;
    // int d_inicial = 0, d_final;
    int qchecking = 0;
    int qreserva = 0;
    int contq = 0;
    int contc = 0; // Inicializar a contagem de quartos
    Quartos *quartos;
    Cliente *clientes;
    Reserva *reserva;

    FILE *arquivo_quartos;
    FILE *arquivo_clientes;

    quartos = (Quartos *)calloc(tam, sizeof(Quartos));
    clientes = (Cliente *)calloc(tam, sizeof(Cliente));
    // status = (Dia *)calloc(31, sizeof(Dia));
    reserva = (Reserva *)calloc(100, sizeof(Reserva));

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
            menu_reserva(quartos, contq, clientes, reserva, contc, &qreserva);
            break;
        case 4:
            checking(quartos, contq, reserva, contc, &qchecking);
            break;
        case 5:
            checkout(quartos, contq, reserva, contc);
        default:
            printf("Opcao invalida!");
            break;
        }
    } while (op != 0);

    free(quartos);
    free(clientes);
    free(reserva);

    return 0;
}

