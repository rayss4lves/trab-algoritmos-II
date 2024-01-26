//quarto[i].calendario.jan[i - 1].status

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Quartos
{
    int numero_quarto;
    int status;
    int tipo;
    float valor;
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

    printf("\nStatus: ");
    printf("\n\t1 - vago\n\t2 - ocupado:\n");
    setbuf(stdin, NULL);
    scanf("%d", &quarto.status);

    return quarto;
}

void imprimir_quartos(Quartos quarto)
{
    printf("Numero: %d\n", quarto.numero_quarto);
    printf("Valor: %.2f\n", quarto.valor);
    printf("Tipo: %d\n", quarto.tipo);
    printf("Status: %d\n", quarto.status);
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

void buscar_por_status(Quartos *quarto, int contq)
{
    int i = 0;
    int status;

    printf("Informe o status do quarto que deseja consultar: \n");
    printf("\n\t1 - vago1\n\t2 - ocupado:\n");
    setbuf(stdin, NULL);
    scanf("%d", &status);

    for (i = 0; i < contq; i++)
    {
        if (quarto[i].status == status)
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

void buscar_por_preco(Quartos *quarto, int contq)
{
    int i = 0;
    float preco;

    printf("Informe o preco do quarto que deseja consultar: \n");
    setbuf(stdin, NULL);
    scanf("%f", &preco);

    for (i = 0; i < contq; i++)
    {
        if (quarto[i].valor == preco)
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
    case 2:
        buscar_por_status(quarto, contq);
        break;
    case 3:
        buscar_por_tipo(quarto, contq);
        break;
    case 4:
        buscar_por_preco(quarto, contq);
        break;
    default:
        printf("Opcao invalida!");
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
            fprintf(arquivo_quarto, "%d %.2f %d %d\n", quarto[*contq].numero_quarto, quarto[*contq].valor, quarto[*contq].tipo, quarto[*contq].status);
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

int main()
{
    int op;
    int tam = 50;
    int contq = 0;
    int contc = 0; // Inicializar a contagem de quartos
    Quartos *quartos;
    Cliente *clientes;

    FILE *arquivo_quartos;
    FILE *arquivo_clientes;

    quartos = (Quartos *)calloc(tam, sizeof(Quartos));
    clientes = (Cliente *)calloc(tam, sizeof(Cliente));

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
        default:
            printf("Opcao invalida!");
            break;
        }
    } while (op != 0);

    free(quartos);
    free(clientes);
    return 0;
}

