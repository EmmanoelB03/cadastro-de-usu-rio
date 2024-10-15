#include <stdio.h>
#include <string.h>

typedef struct dataNascimento dataNascimento;
typedef struct dadosUser dados;

struct dataNascimento
{
    int dia,mes,ano;
};


struct dadosUser
{
    char login[20];
    char senha[20];
    char nome[30];
    char endereco[50];
    char telefone[15];
    dataNascimento data;
}listaUsuarios[4] ;


void cadastro(int quantUsers)
{
  
    dados user;

    printf("Login com ate 20 digitos: ");
    gets(user.login);

    printf("\nSenha  com ate 20 digitos: ");
    gets(user.senha);

    printf("\nNome com ate 30 digitos: ");
    gets(user.nome);

    printf("\nEndereco com ate 50 digitos: ");
    gets(user.endereco);

    printf("\nTelefone com ate 15 digitos: ");
    gets(user.telefone);

    printf("\nDigite separadamente a data de nascimento, exemplo(12 12 2012): ");
    scanf("%d %d %d", &user.data.dia, &user.data.mes, &user.data.ano);       
    getchar();
    
    listaUsuarios[quantUsers] = user;

}

void novoUsuario()
{

    char opc = 'n';
    int quantUsers = 0;

    do{ 
        printf("CADASTRO DO USUARIO %d: \n",quantUsers+1);

        cadastro(quantUsers);

        printf("\nDeseja fazer outro cadastro (s/n): ");

        opc = getchar();
        getchar();
        quantUsers++;
        

    }while(opc == 's');

}

void atualizarUser(dados dados)
{

    char opc;
    char loginInformado[20];
    char senhaIndormada[20];

    printf("\nPara atualizar seus dados, precisamos que voce informe\n");
    printf("Login:");
    gets(loginInformado);
    printf("\nSenha:");
    gets(senhaIndormada);

    printf("%d", strcmp(dados.senha, senhaIndormada));
    //strcmp(dados.login, loginInformado);
    //strcmp(dados.senha, senhaIndormada);
    if(!strcmp(dados.login, loginInformado) && !strcmp(dados.senha, senhaIndormada))
    {
        printf("\nQual dado voce quer atualizar\nn-Nome\ne-Endereco\nOpcao: ");
        opc = getchar();

       switch (opc)
       {
        case 'n':
            printf("\nInforme o novo nome: ");
            gets(dados.login);
            printf("%s",dados.login);
        break;
       
        case 'e':
            printf("\nInforme o novo endereco: ");
            gets(dados.endereco);
            printf("%s",dados.endereco);
        break;

        default:
            printf("\nOpção invalida");
        break;
       }
    

    } 
    else
    {
        printf("\nDados invalidos!!!");
    }
       

    


}

int main()
{

    //cadastro inicial

    printf("\nDeseja fazer outro cadastro (s/n): ");

    novoUsuario();

    atualizarUser(listaUsuarios[0]);

    printf("\nUsuario 1: %s",listaUsuarios[0].nome);

    return 0 ;
}
