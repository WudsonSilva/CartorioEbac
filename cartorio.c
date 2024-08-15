#include <stdio.h>  // Biblioteca para entrada e saída padrão (como printf e scanf)
#include <stdlib.h> // Biblioteca para alocação de memória, controle de processos, conversões, etc.
#include <locale.h> // Biblioteca para definir configurações regionais, como idioma
#include <string.h> // Biblioteca para manipulação de strings

int registro() // Função para registrar usuários
{
    // Declaração de variáveis para armazenar os dados do usuário
    char arquivo[40];
    char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40];
    
    // Coleta o CPF do usuário
    printf("Digite o CPF que deseja cadastrar: ");
    scanf("%s", cpf); // Lê o CPF como uma string
    
    // Copia o CPF para a variável 'arquivo', que será o nome do arquivo
    strcpy(arquivo, cpf);
    
    // Cria um arquivo com o nome do CPF e abre em modo de escrita
    FILE *file;
    file = fopen(arquivo, "w"); // "w" significa que o arquivo será escrito
    
    // Escreve o CPF no arquivo
    fprintf(file, "%s", cpf);
    fclose(file); // Fecha o arquivo para salvar as alterações
    
    // Reabre o arquivo em modo de adição para continuar escrevendo
    file = fopen(arquivo, "a"); // "a" significa que o conteúdo será adicionado ao final
    fprintf(file, ", "); // Adiciona uma vírgula para separar os dados
    fclose(file); // Fecha o arquivo
    
    // Coleta o nome do usuário
    printf("Digite o nome que deseja cadastrar: ");
    scanf("%s", nome); // Lê o nome como uma string
    
    // Abre o arquivo novamente para adicionar o nome
    file = fopen(arquivo, "a");
    fprintf(file, "%s ", nome); // Adiciona o nome seguido de um espaço
    fclose(file); // Fecha o arquivo
    
    // Coleta o sobrenome do usuário
    printf("Digite o sobrenome que deseja cadastrar: ");
    scanf("%s", sobrenome); // Lê o sobrenome como uma string
    
    // Abre o arquivo novamente para adicionar o sobrenome
    file = fopen(arquivo, "a");
    fprintf(file, "%s, ", sobrenome); // Adiciona o sobrenome seguido de uma vírgula
    fclose(file); // Fecha o arquivo
    
    // Coleta o cargo do usuário
    printf("Digite o cargo que deseja cadastrar: ");
    scanf("%s", cargo); // Lê o cargo como uma string
    
    // Abre o arquivo novamente para adicionar o cargo
    file = fopen(arquivo, "a");
    fprintf(file, "%s.", cargo); // Adiciona o cargo seguido de um ponto final
    fclose(file); // Fecha o arquivo
    
    system("pause"); // Pausa o sistema para que o usuário possa ver a saída
    return 0; // Retorna 0 para indicar que a função terminou com sucesso
}

int consulta() // Função para consultar usuários
{
    setlocale(LC_ALL, "Portuguese"); // Define a linguagem para exibir acentuação corretamente
    
    // Declaração de variáveis para o CPF e para o conteúdo do arquivo
    char cpf[40];
    char conteudo[200];
    
    // Coleta o CPF que será consultado
    printf("Digite o CPF que deseja consultar: ");
    scanf("%s", cpf); // Lê o CPF como uma string
    
    // Abre o arquivo correspondente ao CPF em modo de leitura
    FILE *file;
    file = fopen(cpf, "r"); // "r" significa que o arquivo será lido
    
    // Verifica se o arquivo foi aberto com sucesso
    if(file == NULL)
    {
        printf("ERRO: Arquivo não localizado. \n"); // Exibe mensagem de erro se o arquivo não existir
    }
    else
    {
        // Lê o conteúdo do arquivo e o exibe na tela
        while(fgets(conteudo, 200, file) != NULL)
        {
            printf("Essas são as informações do usuário: ");
            printf("%s", conteudo); // Exibe o conteúdo do arquivo
            printf("\n\n");
        }
        fclose(file); // Fecha o arquivo após a leitura
    }
    
    system("pause"); // Pausa o sistema para que o usuário possa ver a saída
    return 0; // Retorna 0 para indicar que a função terminou com sucesso
}

int delete() // Função para deletar usuários
{
    // Declaração de variável para o CPF
    char cpf[40];
    
    // Coleta o CPF do usuário que será deletado
    printf("Digite o CPF do usuário que deseja deletar: ");
    scanf("%s", cpf); // Lê o CPF como uma string
    
    // Tenta remover o arquivo correspondente ao CPF
    if (remove(cpf) == 0) // Se a remoção for bem-sucedida
    {
        printf("O usuário foi deletado com sucesso.\n");
    }
    else // Se a remoção falhar (por exemplo, se o arquivo não existir)
    {
        printf("ERRO: O arquivo não existe.\n");
    }
    
    system("pause"); // Pausa o sistema para que o usuário possa ver a saída
    return 0; // Retorna 0 para indicar que a função terminou com sucesso
}

int main() // Função principal que exibe o menu e processa a seleção do usuário
{
    int opcao = 0; // Declaração da variável que armazenará a opção escolhida pelo usuário
    int laco = 1; // Variável para controlar o loop do menu
    
    while(laco == 1) // Loop principal que exibe o menu repetidamente
    {
        system("cls"); // Limpa a tela do console
        
        setlocale(LC_ALL, "Portuguese"); // Define a linguagem para exibir acentuação corretamente
        
        // Exibe o menu de opções
        printf("### Cartório Silva ###\n\n"); // Título do menu
        printf("Escolha uma das opções no menu: \n\n");
        printf("\t1 - Registrar nomes\n");
        printf("\t2 - Consultar nomes\n");
        printf("\t3 - Deletar nomes\n");
        printf("\t4 - Sair do sistema\n\n"); // Adiciona a opção de sair
        printf("Opção: "); // Prompt para o usuário escolher uma opção
        
        // Lê a escolha do usuário
        scanf("%d", &opcao);
        
        system("cls"); // Limpa a tela do console
        
        // Processa a escolha do usuário
        switch(opcao)
        {
            case 1: // Se a opção for 1, chama a função de registro
                registro();
                break;
            
            case 2: // Se a opção for 2, chama a função de consulta
                consulta();
                break;
            
            case 3: // Se a opção for 3, chama a função de deletar
                delete();
                break;
            
            case 4: // Se a opção for 4, sai do loop e encerra o programa
                laco = 0;
                printf("Saindo do programa...\n");
                break;
            
            default: // Se a escolha não for válida, exibe uma mensagem de erro
                printf("ERRO: Esta opção não está disponível.\n");
                system("pause"); // Pausa o sistema para que o usuário possa ver a mensagem
                break;
        }
    }
    
    return 0; // Retorna 0 para indicar que o programa terminou com sucesso
}

