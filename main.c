// o que precisa terminar de fazer:

/*
funções de editar e excluir do arquivo

Caso o quarto solicitado pelo cliente esteja
reservado, uma mensagem de erro deve ser mostrada e, em seguida, uma lista
quartos disponíveis devem ser exibidos. Se o cliente escolher outro quarto, a
função deve ser reiniciada e concluída, produzindo um código automáƟco de
reserva.

controle de fluxo financeiro( Permitir a consulta de todos os valores recebidos durante um
intervalo de tempo definido pelo usuário.)
*/

// o que precisa terminar de fazer:

/*
funções de editar e excluir do arquivo

Caso o quarto solicitado pelo cliente esteja
reservado, uma mensagem de erro deve ser mostrada e, em seguida, uma lista
quartos disponíveis devem ser exibidos. Se o cliente escolher outro quarto, a
função deve ser reiniciada e concluída, produzindo um código automáƟco de
reserva.

controle de fluxo financeiro( Permitir a consulta de todos os valores recebidos durante um
intervalo de tempo definido pelo usuário.)
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Aqui você pode ter diferentes valores para representar os estados (livre, ocupado, reservado, etc.)

typedef struct Quartos
{
    int status[12][31]; // Array para cada dia do mês
    int numero_quarto;
    int tipo;
    float valor;
    int qchecking;
    float arrecadacao[12][31];
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
    struct Cliente cliente;
    int nmr_quarto;
    int ano; // salvar automaticamente o ano com a time
    int mes;
    int d_inicial;
    int d_final;
    int status_pagamento;
    float valor_reserva;
    int cod_reserva;

} Reserva;

typedef struct Checkin
{
    int hora;
    int min;
    int dia;
    int mes;
    int ano;
} Checkin;

int menu_principal()
{ // menu 0
    int op;
    printf("\n1 - Informacoes dos quartos\n2 - Informacoes do cliente\n0 - Sair\n\nResposta: ");
    setbuf(stdin, NULL);
    scanf("%d", &op);
    return op;
}

Quartos cadastrar_quartos()
{
    Quartos quarto;

    int stts;
    printf("\nInforme as informacoes do quarto:");
    printf("\nNumero: ");
    setbuf(stdin, NULL);
    scanf("%d", &quarto.numero_quarto);

    printf("\nValor: ");
    setbuf(stdin, NULL);
    scanf("%f", &quarto.valor);

    printf("\nTipo: ");
    printf("\n\t1 - solteiro\n\t2 - casal\n\t3 - suite.\n");
    setbuf(stdin, NULL);
    scanf("%d", &quarto.tipo);

    printf("Informe o status do quarto: ");
    printf("\n\t1 - vago\n\t2 - ocupado: \n");
    setbuf(stdin, NULL);
    scanf("%d", &stts);

    for (int mes = 0; mes < 12; mes++)
    {
        for (int dia = 0; dia < 31; dia++)
        {
            quarto.status[mes][dia] = stts;
        }
    }

    return quarto;
}

void imprimir_quarto(Quartos quarto)
{
    printf("Numero: %d\n", quarto.numero_quarto);
    printf("Valor: %.2f\n", quarto.valor);
    printf("Tipo: %d\n", quarto.tipo);
    for (int mes = 0; mes < 12; mes++)
    {
        for (int dia = 0; dia < 31; dia++)
        {
            printf("Status do mes %d no dia %d = %d\n", mes + 1, dia + 1, quarto.status[mes][dia]);
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
            imprimir_quarto(quarto[i]);
        }
    }
}

void buscar_por_tipo(Quartos *quarto, int contq)
{
    int i = 0;
    int tip;

    printf("Informe o tipo de quarto que deseja consultar: \n");
    printf("\n\t1 - casal\n\t2 - solteiro\n\t3 - suite.\n");
    setbuf(stdin, NULL);
    scanf("%d", &tip);

    for (i = 0; i < contq; i++)
    {
        if (quarto[i].tipo == tip)
        {
            imprimir_quarto(quarto[i]);
        }
    }
}

void buscar_por_status(Quartos *quarto, int contq)
{
    int i = 0;
    int stts, j = 0, mes;

    printf("Informe o tipo de quarto que deseja consultar: \n");
    printf("\n\t1 - casal\n\t2 - solteiro\n\t3 - suite.\n");
    setbuf(stdin, NULL);
    scanf("%d", &stts);
    printf("Informe o mes: \n");
    setbuf(stdin, NULL);
    scanf("%d", &mes);

    for (i = 0; i < contq; i++)
    {
        for (j = 0; j < 31; j++)
        {
            if (quarto[i].status[mes - 1][j] == stts)
            {
                imprimir_quarto(quarto[i]);
            }
        }
    }
}

void buscar_por_preco(Quartos *quarto, int contq)
{
    int i = 0;
    float preco;

    printf("Informe o tipo de quarto que deseja consultar: \n");
    printf("\n\t1 - casal\n\t2 - solteiro\n\t3 - suite.\n");
    setbuf(stdin, NULL);
    scanf("%f", &preco);

    for (i = 0; i < contq; i++)
    {
        if (quarto[i].valor == preco)
        {
            imprimir_quarto(quarto[i]);
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
    case 2:
        buscar_por_preco(quarto, contq);
        break;
    case 3:
        buscar_por_status(quarto, contq);
        break;
    }
}

// edita apenas preço
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
            setbuf(stdin, NULL);
            scanf("%f", &(quarto[i].valor));
        }
    }
    for (i = 0; i < contq; i++)
    {
        if (quarto[i].numero_quarto == id)
        {
            printf("Informe o novo valor do quarto: \n");
            setbuf(stdin, NULL);
            scanf("%f", &(quarto[i].valor));
        }
    }
}

Cliente cadastrar_informacoes_clientes()
{
    Cliente cliente;

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
    printf("Email: %s\n", cliente.email);
    printf("CPF: %s\n", cliente.cpf);
    printf("RG: %s\n", cliente.rg);
    printf("Rua: %s\n", cliente.rua);
    printf("Cidade: %s\n\n", cliente.cidade);
}

void buscar_por_cpf(Cliente *cliente, int *contc, int tam)
{

    int i = 0;
    int cadastrado = 0;
    char cpf[12];

    printf("Informe o numero de cpf que deseja consultar: \n");
    setbuf(stdin, NULL);
    scanf("%[^\n]", cpf);

    for (i = 0; i < *contc; i++)
    {
        if (strcmp(cliente[i].cpf, cpf) == 0)
        {
            mostrar_cliente(cliente[i]);
            cadastrado = 1;
        }
    }

    if (cadastrado == 0 && *contc < tam)
    {

        printf("\nCliente nao encontrado, entao vamos cadastralo!");
        (*contc)++;
        cliente[*contc] = cadastrar_informacoes_clientes();
    }
}

void buscar_por_rg(Cliente *cliente, int *contc, int tam)
{
    int cadastrado = 0;

    int i = 0;
    char rg[7];

    printf("Informe o numero de rg que deseja consultar: \n");
    setbuf(stdin, NULL);
    scanf("%[^\n]", rg);

    for (i = 0; i < *contc; i++)
    {
        if (strcmp(cliente[i].rg, rg) == 0)
        {
            mostrar_cliente(cliente[i]);
            cadastrado = 1;
        }
    }

    if (cadastrado == 0 && *contc < tam)
    {
        printf("\nCliente nao encontrado, entao vamos cadastralo!");
        (*contc)++;
        cliente[*contc] = cadastrar_informacoes_clientes();
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

// mexe com arquivo
void menu_cliente(Cliente *cliente, int *contc, int tam)
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

        if (*contc < tam)
        {
            cliente[*contc] = cadastrar_informacoes_clientes(cliente[*contc]);

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
        printf("\nOpcao invalida!");
        break;
    }
}

void reserva_quartos(Quartos *quarto, int contq, Cliente *cliente, Reserva *reserva, int contc)
{

    int num, dia = 0;
    int mes, tip, i = 0, j = 0, k = 0;
    int d_inicial, d_final;
    char cpf[12];
    float valor = 0;

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
        scanf("%d %d", &d_inicial, &d_final);

        printf("Informe se o mes que voce deseja realizar a reserva\n\n");
        setbuf(stdin, NULL);
        scanf("%d", &mes);

        for (i = 0; i < contq; i++)
        {
            for (dia = d_inicial; dia <= d_final; dia++)
            {
                if (quarto[i].tipo == 1 && quarto[i].status[mes - 1][dia] == 1)
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
                if (quarto[i].numero_quarto == num && quarto[i].status[mes - 1][dia - 1] == 1)
                {
                    quarto[i].status[mes - 1][dia - 1] = 3; // 3 - reservado
                    valor += quarto[i].valor;
                    quarto[i].arrecadacao[mes - 1][dia - 1] = quarto[i].valor;
                }
                else if (quarto[i].status[mes - 1][dia - 1] == 3)
                {
                    printf("O quarto informado já está reservado!!");
                    break;
                }
            }
        }
        for (i = 0; i < contc; i++)
        {
            for (j = 0; j < 10; j++)
            {
                for (k = 0; k < contq; k++)
                {
                    if (strcmp(cliente[i].cpf, cpf) == 0)
                    {
                        if (quarto[k].numero_quarto == num)
                        {

                            reserva[j].cliente = *cliente;
                            reserva[j].nmr_quarto = num;
                            reserva[j].d_inicial = d_inicial;
                            reserva[j].d_final = d_final;
                            reserva[j].mes = mes;
                            reserva[j].status_pagamento = 0;
                            reserva[j].valor_reserva = valor;
                            reserva[j].cod_reserva = rand() % 100000000 + 1;
                        }
                    }
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
                if (quarto[i].tipo == 2 && quarto[i].status[mes - 1][dia - 1] == 1)
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
                if (quarto[i].numero_quarto == num && quarto[i].status[mes - 1][dia - 1] == 1)
                {
                    quarto[i].status[mes - 1][dia - 1] = 3; // 3 - reservado
                    valor += quarto[i].valor;
                }
                else if (quarto[i].status[mes - 1][dia - 1] == 3)
                {
                    printf("O quarto informado já está reservado!!");
                    break;
                }
            }
        }
        for (i = 0; i < contc; i++)
        {
            if (cliente[i].cpf == cpf)
            {
                reserva[i].cliente = *cliente;
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
                if (quarto[i].tipo == 3 && quarto[i].status[mes - 1][dia - 1] == 1)
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
                if (quarto[i].numero_quarto == num && quarto[i].status[mes - 1][dia - 1] == 1)
                {
                    quarto[i].status[mes - 1][dia - 1] = 3; // 3 - reservado
                    valor += quarto[i].valor;
                }
                else if (quarto[i].status[mes - 1][dia - 1] == 3)
                {
                    printf("O quarto informado já está reservado!!");
                    break;
                }
            }
        }
        for (i = 0; i < contc; i++)
        {
            if (cliente[i].cpf == cpf)
            {
                reserva[i].cliente = *cliente;
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

    printf("\nNome do cliente : %s", reserva.cliente.nome);
    printf("\nCPF: %s", reserva.cliente.cpf);
    printf("\nTelefone: %s", reserva.cliente.telefone);
    printf("\nNumero do quarto: %d", reserva.nmr_quarto);
    printf("\nDia de inicio: %d", reserva.d_inicial);
    printf("\nDia final: %d", reserva.d_final);
    printf("\nMes: %d", reserva.mes);
    printf("\nValor da reserva: %f", reserva.valor_reserva);
    printf("\nStatus: %d", reserva.status_pagamento);
    printf("\nTelefone: %d", reserva.cod_reserva);
}

void menu_listar_reservas(Reserva *reserva, int qreserva)
{
    int op, j = 0;
    char cpf[10];

    printf("-----Menu consultar reserva-----:\n");
    printf("\n\t1 - Consultar reserva por cpf\n\t2 - Consultar reserva por código de reserva\n\n: ");
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
            if (strcmp(reserva[j].cliente.cpf, cpf) == 0)
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
    printf("\n\t1 - Realizar reserva\n\t2 - Consultar reserva\n\n: ");
    setbuf(stdin, NULL);
    scanf("%d", &op);

    switch (op)
    {
    case 1:
        reserva_quartos(quarto, contq, cliente, reserva, contc);
        (*qreserva)++;
        break;

    case 2:
        menu_listar_reservas(reserva, *qreserva);
        break;

    default:
        printf("Opcao invalida!");
        break;
    }
}

void menu_quarto(Quartos *quarto, int *contq, FILE *arquivo_quarto, int tam)
{
    int op;
    int i = 0, j = 0;

    printf("-----Menu Quarto-----:\n");
    printf("\n\t1 - Cadastrar informacoes do quarto\n\t2 - Consultar informacoes do quarto\n\t3 - Editar informacoes\n\t4 - Remover\n\n: ");
    setbuf(stdin, NULL);
    scanf("%d", &op);

    switch (op)
    {
    case 1:

        if (*contq < tam)
        {
            quarto[*contq] = cadastrar_quartos(quarto[*contq]);

            fprintf(arquivo_quarto, "Numero do quarto: %d Valor: %.2f Tipo: %d \n", quarto[*contq].numero_quarto, quarto[*contq].valor, quarto[*contq].tipo);
            for (i = 0; i < 12; i++)
            {
                for (j = 0; j < 31; j++)
                {
                    fprintf(arquivo_quarto, "Status do mes %d no dia %d = %d\n", i + 1, j + 1, quarto[*contq].status[i][j]);
                }
            }

            *contq += 1;
        }
        else
        {
            printf("Limite de quartos atingido.\n");
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
        if (strcmp(reserva[i].cliente.cpf, cpf) == 0)
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
    int i = 0, j = 0, k = 0;
    char cpf[12], res[5];
    char op[5];

    int dia_f, dia_i, mes;

    for (i = 0; i < contc; i++)
    {
    }

    printf("Informe o seu cpf: \n");
    scanf(" %[^\n]", cpf);

    for (i = 0; i < contc; i++)
    {
        if (strcmp(reserva[i].cliente.cpf, cpf) == 0)
        {
            printf("nome: %s\n", reserva[i].cliente.nome);
            printf("CPF: %s\n", reserva[i].cliente.cpf);
            printf("Numero do quarto: %d\n", reserva[i].nmr_quarto);
            printf("Codigo de reserva: %d\n", reserva[i].cod_reserva);
            printf("Valor total: %.2f\n", reserva[i].valor_reserva);
            printf("Deseja realizar o checking? \n");
            scanf(" %[^\n]", op);
            if (strcmp(op, "sim") == 0)
            {
                qchecking += 1;
                mes = reserva[i].mes;
                dia_i = reserva[i].d_inicial;
                dia_f = reserva[i].d_final;

                for (k = 0; k < contq; k++)
                {
                    for (j = dia_i; j <= dia_f; j++)
                    {
                        quarto[k].status[mes - 1][j] = 2;
                    }
                }
            }
        }
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
    int i = 0, j = 0, k = 0;
    char cpf[12];
    int op, r;

    int dia_f, dia_i, mes;

    printf("Informe o seu cpf: \n");
    scanf(" %[^\n]", cpf);

    for (i = 0; i < contc; i++)
    {
        if (strcmp(reserva[i].cliente.cpf, cpf) == 0)
        {
            printf("nome: %s ", reserva[i].cliente.nome);
            printf("CPF: %s ", reserva[i].cliente.cpf);
            printf("Numero do quarto: %d ", reserva[i].nmr_quarto);
            printf("Codigo de reserva: %d ", reserva[i].cod_reserva);

            printf("Deseja realizar check-out? [1 - SIM / 0 - Nao]");
            scanf("%d", &op);
            if (op == 1)
            {
                mes = reserva[i].mes;
                dia_i = reserva[i].d_inicial;
                dia_f = reserva[i].d_final;

                for (k = 0; k < contq; k++)
                {
                    for (j = dia_i; j <= dia_f; j++)
                    {
                        quarto[k].status[mes - 1][j] = 1;
                    }
                }
            }
        }
    }
    printf("Já realizou pagamento? \n");
    scanf(" %d", &r);

    for (i = 0; i < contc; i++)
    {
        mes = reserva[i].mes;
        dia_i = reserva[i].d_inicial;
        dia_f = reserva[i].d_final;
    }

    if (r == 1)
    {
        realizar_pagamento(quarto, contq, reserva, contq);
    }
    else
    {
        printf("\n\tVolte sempre ao nosso Hotel!!\n");
    }
}

void consultar_valores(Quartos *quartos, int contq)
{

    int i = 0, k = 0, num;
    int dia_inicial, dia_final, mes;
    float soma = 0;

    printf("Informe o numero do quarto que deseja consultar o valor: \n");
    scanf("%d", &num);

    printf("Informe o mes que deseja realizar a busca: \n");
    scanf("%d", &mes);
    printf("Informe o dia final e o dia inicial que deseja buscar: \n");
    scanf("%d%d", &dia_inicial, &dia_final);
    for (i = 0; i < contq; i++)
    {
        if (quartos[i].numero_quarto == num)
        {
            for (k = 0; k < 31; k++)
            {
                soma = quartos[i].arrecadacao[mes - 1][k - 1] + soma;
            }
        }
    }

    printf("%.2f \n", soma);
}

/*
int main()
{
    int op;
    int tam = 50;
    int i;

    int qchecking = 0;
    int qreserva = 0;
    int contq = 0;
    int contc = 0;
    Quartos *quartos;
    Cliente *clientes;
    Reserva *reserva;
    Checkin *checkin;

    FILE *arquivo_quartos = fopen("quartos.txt", "a+");
    FILE *arq_q_temporario = fopen("tempQuarto.txt", "w");

    FILE *arquivo_clientes = fopen("cliente.txt", "r");
    if (arquivo_clientes == NULL)
        printf("Falhei");
    else
        printf("\nAchei");

    // FILE *valores = fopen("valores_arrecadado", "a+");
    quartos = (Quartos *)calloc(tam, sizeof(Quartos));
    clientes = (Cliente *)calloc(tam, sizeof(Cliente));
    reserva = (Reserva *)calloc(1000, sizeof(Reserva));
    checkin = (Checkin *)calloc(1000, sizeof(Checkin));

    char linha[100];  // Ajuste o tamanho conforme necessário

    // Lê uma linha por vez até o final do arquivo
    while (fgets(linha, sizeof(linha), arquivo_clientes) != NULL) {
        contc++;
    }
    printf("\nLinhas = %d", contc);

    Cliente aux;

    for (i = 0; i < contc; i++)
    {
        fscanf(arquivo_clientes, "%s %d %d %d %s %s %s %s %s %s",
               aux.nome,
               &aux.dia,
               &aux.mes,
               &aux.ano,
               aux.telefone,
               aux.cpf,
               aux.rg,
               aux.rua,
               aux.cidade,
               aux.email);

        clientes[i] = aux;
        mostrar_cliente(clientes[i]);
    }

    do
    {
        op = menu_principal();
        switch (op)
        {
        case 1:
            menu_quarto(quartos, &contq, arquivo_quartos, tam);
            break;
        case 2:
            menu_cliente(clientes, &contc, tam);
            break;
        case 3:
            menu_reserva(quartos, contq, clientes, reserva, contc, &qreserva);
            break;
        case 4:
            checking(quartos, contq, reserva, contc, &qchecking);
            break;
        case 5:
            checkout(quartos, contq, reserva, contc);
            break;
        case 6:
            consultar_valores(quartos, contq);
            break;
        default:
            printf("Opcao invalida!");
            break;
        }
    } while (op != 0);

    fclose(arquivo_quartos);
    fclose(arq_q_temporario);

    // passando os clientes da memória para o arquivo
    fclose(arquivo_clientes);
    arquivo_clientes = fopen("cliente.txt", "r");

    for (i = 0; i < contc; i++)

        fprintf(arquivo_clientes, "%s %d %d %d %s %s %s %s %s %s\n", clientes[i].nome, clientes[i].dia, clientes[i].mes, clientes[i].ano, clientes[i].telefone, clientes[i].cpf, clientes[i].rg, clientes[i].rua, clientes[i].cidade, clientes[i].email);

    fclose(arquivo_clientes);

    // fclose(valores);

    free(quartos);
    free(clientes);
    free(reserva);
    free(checkin);

    return 0;
}
*/
void salvar_clientes_binario(Cliente *clientes, int contc)
{
    FILE *arquivo_clientes = fopen("clientes.bin", "wb");

    if (arquivo_clientes == NULL)
    {
        perror("Erro ao abrir o arquivo para escrita binária");
        exit(1);
    }

    // Escreve todos os clientes no arquivo binário
    fwrite(clientes, sizeof(Cliente), contc, arquivo_clientes);

    fclose(arquivo_clientes);
}

int main()
{
    int contc = 0;
    Cliente *clientes;

    // Abrir arquivo binário para leitura
    FILE *arquivo_clientes = fopen("clientes.bin", "a+b");
    if (arquivo_clientes == NULL)
    {
        printf("Arquivo não encontrado ou falha ao abrir.\n");
    }
    else
    {
        // Contar o número de registros no arquivo binário
        fseek(arquivo_clientes, 0, SEEK_END);
        contc = ftell(arquivo_clientes) / sizeof(Cliente);
        rewind(arquivo_clientes);

        // Alocar memória para armazenar os clientes
        clientes = (Cliente *)malloc(contc * sizeof(Cliente));

        // Ler os clientes do arquivo binário
        fread(clientes, sizeof(Cliente), contc, arquivo_clientes);

        // Fechar o arquivo
        fclose(arquivo_clientes);

        // Exibir os clientes
        for (int i = 0; i < contc; i++)
        {
            printf("Cliente %d:\n", i + 1);
            mostrar_cliente(clientes[i]);
        }

        // Liberar memória
        free(clientes);
    }

    return 0;
}