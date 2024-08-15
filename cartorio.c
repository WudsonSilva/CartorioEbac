#include <stdio.h>  // Biblioteca para entrada e sa�da padr�o (como printf e scanf)
#include <stdlib.h> // Biblioteca para aloca��o de mem�ria, controle de processos, convers�es, etc.
#include <locale.h> // Biblioteca para definir configura��es regionais, como idioma
#include <string.h> // Biblioteca para manipula��o de strings

int registro() // Fun��o para registrar usu�rios
{
    // Declara��o de vari�veis para armazenar os dados do usu�rio
    char arquivo[40];
    char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40];
    
    // Coleta o CPF do usu�rio
    printf("Digite o CPF que deseja cadastrar: ");
    scanf("%s", cpf); // L� o CPF como uma string
    
    // Copia o CPF para a vari�vel 'arquivo', que ser� o nome do arquivo
    strcpy(arquivo, cpf);
    
    // Cria um arquivo com o nome do CPF e abre em modo de escrita
    FILE *file;
    file = fopen(arquivo, "w"); // "w" significa que o arquivo ser� escrito
    
    // Escreve o CPF no arquivo
    fprintf(file, "%s", cpf);
    fclose(file); // Fecha o arquivo para salvar as altera��es
    
    // Reabre o arquivo em modo de adi��o para continuar escrevendo
    file = fopen(arquivo, "a"); // "a" significa que o conte�do ser� adicionado ao final
    fprintf(file, ", "); // Adiciona uma v�rgula para separar os dados
    fclose(file); // Fecha o arquivo
    
    // Coleta o nome do usu�rio
    printf("Digite o nome que deseja cadastrar: ");
    scanf("%s", nome); // L� o nome como uma string
    
    // Abre o arquivo novamente para adicionar o nome
    file = fopen(arquivo, "a");
    fprintf(file, "%s ", nome); // Adiciona o nome seguido de um espa�o
    fclose(file); // Fecha o arquivo
    
    // Coleta o sobrenome do usu�rio
    printf("Digite o sobrenome que deseja cadastrar: ");
    scanf("%s", sobrenome); // L� o sobrenome como uma string
    
    // Abre o arquivo novamente para adicionar o sobrenome
    file = fopen(arquivo, "a");
    fprintf(file, "%s, ", sobrenome); // Adiciona o sobrenome seguido de uma v�rgula
    fclose(file); // Fecha o arquivo
    
    // Coleta o cargo do usu�rio
    printf("Digite o cargo que deseja cadastrar: ");
    scanf("%s", cargo); // L� o cargo como uma string
    
    // Abre o arquivo novamente para adicionar o cargo
    file = fopen(arquivo, "a");
    fprintf(file, "%s.", cargo); // Adiciona o cargo seguido de um ponto final
    fclose(file); // Fecha o arquivo
    
    system("pause"); // Pausa o sistema para que o usu�rio possa ver a sa�da
    return 0; // Retorna 0 para indicar que a fun��o terminou com sucesso
}

int consulta() // Fun��o para consultar usu�rios
{
    setlocale(LC_ALL, "Portuguese"); // Define a linguagem para exibir acentua��o corretamente
    
    // Declara��o de vari�veis para o CPF e para o conte�do do arquivo
    char cpf[40];
    char conteudo[200];
    
    // Coleta o CPF que ser� consultado
    printf("Digite o CPF que deseja consultar: ");
    scanf("%s", cpf); // L� o CPF como uma string
    
    // Abre o arquivo correspondente ao CPF em modo de leitura
    FILE *file;
    file = fopen(cpf, "r"); // "r" significa que o arquivo ser� lido
    
    // Verifica se o arquivo foi aberto com sucesso
    if(file == NULL)
    {
        printf("ERRO: Arquivo n�o localizado. \n"); // Exibe mensagem de erro se o arquivo n�o existir
    }
    else
    {
        // L� o conte�do do arquivo e o exibe na tela
        while(fgets(conteudo, 200, file) != NULL)
        {
            printf("Essas s�o as informa��es do usu�rio: ");
            printf("%s", conteudo); // Exibe o conte�do do arquivo
            printf("\n\n");
        }
        fclose(file); // Fecha o arquivo ap�s a leitura
    }
    
    system("pause"); // Pausa o sistema para que o usu�rio possa ver a sa�da
    return 0; // Retorna 0 para indicar que a fun��o terminou com sucesso
}

int delete() // Fun��o para deletar usu�rios
{
    // Declara��o de vari�vel para o CPF
    char cpf[40];
    
    // Coleta o CPF do usu�rio que ser� deletado
    printf("Digite o CPF do usu�rio que deseja deletar: ");
    scanf("%s", cpf); // L� o CPF como uma string
    
    // Tenta remover o arquivo correspondente ao CPF
    if (remove(cpf) == 0) // Se a remo��o for bem-sucedida
    {
        printf("O usu�rio foi deletado com sucesso.\n");
    }
    else // Se a remo��o falhar (por exemplo, se o arquivo n�o existir)
    {
        printf("ERRO: O arquivo n�o existe.\n");
    }
    
    system("pause"); // Pausa o sistema para que o usu�rio possa ver a sa�da
    return 0; // Retorna 0 para indicar que a fun��o terminou com sucesso
}

int main() // Fun��o principal que exibe o menu e processa a sele��o do usu�rio
{
    int opcao = 0; // Declara��o da vari�vel que armazenar� a op��o escolhida pelo usu�rio
    int laco = 1; // Vari�vel para controlar o loop do menu
    
    while(laco == 1) // Loop principal que exibe o menu repetidamente
    {
        system("cls"); // Limpa a tela do console
        
        setlocale(LC_ALL, "Portuguese"); // Define a linguagem para exibir acentua��o corretamente
        
        // Exibe o menu de op��es
        printf("### Cart�rio Silva ###\n\n"); // T�tulo do menu
        printf("Escolha uma das op��es no menu: \n\n");
        printf("\t1 - Registrar nomes\n");
        printf("\t2 - Consultar nomes\n");
        printf("\t3 - Deletar nomes\n");
        printf("\t4 - Sair do sistema\n\n"); // Adiciona a op��o de sair
        printf("Op��o: "); // Prompt para o usu�rio escolher uma op��o
        
        // L� a escolha do usu�rio
        scanf("%d", &opcao);
        
        system("cls"); // Limpa a tela do console
        
        // Processa a escolha do usu�rio
        switch(opcao)
        {
            case 1: // Se a op��o for 1, chama a fun��o de registro
                registro();
                break;
            
            case 2: // Se a op��o for 2, chama a fun��o de consulta
                consulta();
                break;
            
            case 3: // Se a op��o for 3, chama a fun��o de deletar
                delete();
                break;
            
            case 4: // Se a op��o for 4, sai do loop e encerra o programa
                laco = 0;
                printf("Saindo do programa...\n");
                break;
            
            default: // Se a escolha n�o for v�lida, exibe uma mensagem de erro
                printf("ERRO: Esta op��o n�o est� dispon�vel.\n");
                system("pause"); // Pausa o sistema para que o usu�rio possa ver a mensagem
                break;
        }
    }
    
    return 0; // Retorna 0 para indicar que o programa terminou com sucesso
}

