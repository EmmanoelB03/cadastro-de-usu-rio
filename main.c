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
    int numCadastro = 0;

    do{ 
        printf("\nCADASTRO DO USUARIO %d: \n",numCadastro+1);

        cadastro(numCadastro);

        printf("\nDeseja fazer outro cadastro (s/n): ");

        opc = getchar();
        getchar();
        numCadastro++;
        

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

    if(!strcmp(dados.login, loginInformado) && !strcmp(dados.senha, senhaIndormada))
    {
        printf("\nQual dado voce quer atualizar\nn-Nome\ne-Endereco\nOpcao: ");
        opc = getchar();
        getchar();
        switch (opc)
        {
            case 'n':
                printf("\nInforme o novo nome: ");
                gets(dados.login);

                printf("\nSeu nome foi atualizado com sucesso!!!\nSeus dados:\nLogin - %s\nSenha - %s\nNome - %s\nEndereco - %s\nTelefone - %s\nDataNascimento - %d/%d/%d\n ",dados.login, dados.senha, dados.nome, dados.endereco, dados.telefone, dados.data.dia,dados.data.mes, dados.data.ano);

            break;
        
            case 'e':
                printf("\nInforme o novo endereco: ");
                gets(dados.endereco);

                printf("\nSeu endereco foi atualizado com sucesso!!!\nSeus dados:\nLogin - %s\nSenha - %s\nNome - %s\nEndereco - %s\nTelefone - %s\nDataNascimento - %02d/%02d/%d\n ",dados.login, dados.senha, dados.nome, dados.endereco, dados.telefone, dados.data.dia,dados.data.mes, dados.data.ano);

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
    int numCadastro = 0;

    novoUsuario();

    printf("\nDigite o numero de cadastro do usuario voce quer atualizar: ");

    scanf("%d", &numCadastro);
    getchar();

    //sedunda etapa(atualização)

    int len = sizeof(listaUsuarios)/sizeof(listaUsuarios[0]);

    if((numCadastro-1) >= 0 && (numCadastro-1) <= len && listaUsuarios[numCadastro-1].login[0] != '\0')
    {
        atualizarUser(listaUsuarios[numCadastro-1]);
    }
    else
    {
        printf("O usuario não exite!!!");
    }


    return 0 ;
}
