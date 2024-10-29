#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
char nome[101];
int idade_correta;
float saldo_correto;
int id;
} usuario;

int main() {

    system("chcp 65001");
    system("cls");

    usuario usuarios; //variavel do tipo estrutura de usuario
    int i, j, h, id = 0;
    char opcao; //para ler o menu
    int busca_Id; //cria uma variavel para buscar o id
    int id_origem, id_destino; //ids envolvidos na transferencia
    float transferencia; //valor a ser tranferido
    int encontrouOrigem = 0, encontrouDestino = 0; //enquanto nao encontra os ids, essas variaveis sao iguais a zero
    long int posicaoOrigem, posicaoDestino; //tipo de arquivo retornado quando se quer a posicao do valor buscado em relacao ao inicio do arquivo
    float saldoOrigem_inicial, saldoDestino_inicial, saldoOrigem, saldoDestino; //saldos envolvidos na transferencia antes e depois para fazer as verificacoes necessarias
    char nomeOrigem[101], nomeDestino[101]; //utilizados na transferencia
    int idadeOrigem, idadeDestino; //utilizados na transferencia
    int idade;
    float saldo;
    char nome[101]; //vetor de tamanho 100 contando o \0
    char linha [200]; //cria uma variável linha que conteria todas as informações do usuário
    int id_para_apagar; //utilizado na opcao 5 para verificacao
    int encontrou = 0; // utilizado na opcao 3 para busca de usuarios
    long int posicao; //utilizada na opcao 5
    int resultado; //utilizada na opcao 1 e 2 para verificar o nome cadastrado
    int quant1 = 0; //quantidade de usuario cadastrados na opcao 2
    char *saldoOrigem_string[40], *saldoDestino_string[40], *saldoOrigem_inicial_string[40], *saldoDestino_inicial_string[40]; //utilizada na opcao 4

    FILE *arq; //cria o arquivo txt
    arq = fopen("example.txt", "w");
    if (arq == NULL) {//verifica se a abertura do arquivo deu certo
        printf("Erro na criação do arquivo!");
        return 1;
    }
    fclose(arq); //fecha o arquivo

    do {
        // o usuário deve escolher uma opção do menu
        printf("\nMenu:\n\n1. Inserção de um novo usuário.\n2. Inserção de vários usuários.\n3. Busca de um usuário por id.\n4. Transferência entre usuários.\n5. Remoção de um usuário por id.\n6. Sair.\n\nSelecione uma opção:");
        printf("\n");
        opcao = getch(); //recebe apenas um caractere
        printf("%c", opcao); //mostra para o usuario a opcao escolhida

        switch(opcao){

            case '1':
                arq = fopen("example.txt", "a"); //abre o arquivo no início da função no modo append
                if (arq == NULL) { //verifica se a abertura deu certo
                    printf("Erro na abertura do arquivo!");
                    return 1;
                }

                id = id + 1; //id gerado automaticamente
                usuarios.id = id; //atribui ao id da estrutura
                printf("\n\nDigite o nome do usuário (máximo de 100 caracteres):\n");
                setbuf(stdin, NULL); gets(nome); //limpa o buffer da string

                for (int j = 0; j < strlen(nome); j++) {//verifica se tem caracteres invalidos no nome
                    resultado = isalpha(nome[j]);
                    if (resultado == 0 && nome[j] != ' ') {
                    printf("\nErro! Nome inválido! Digite o nome novamente (máximo de 100 caracteres):\n");
                    setbuf(stdin, NULL); gets(nome); //limpa o buffer da string
                    j = -1; // Reinicia a verificação do início
                    }
                }
                strcpy(usuarios.nome, nome);//atribui a variavel nome a estrutura

                printf("\nDigite a idade do usuário:\n");
                scanf("%d", &idade);
                while (idade < 0) {//verifica se a idade e negativa
                    printf("\nErro! A idade não pode ser negativa. Insira a idade novamente!\n");
                    scanf("%d", &idade);
                }
                while (idade > 200) {//verifica se a idade e muito grande
                    printf("\nErro! A idade inválida. Insira a idade novamente!\n");
                    scanf("%d", &idade);
                }

                usuarios.idade_correta = idade; //atribui idade na estrutura

                printf("\nDigite o saldo do usuário (até 23 dígitos considerando centavos):\n");
                scanf("%f", &saldo);
                while (saldo < 0) {//verifica se o saldo e negativo
                    printf("\nErro! O saldo não pode ser negativo. Insira o saldo novamente! (até 23 dígitos considerando centavos)\n");
                    scanf("%f", &saldo);
                }
                usuarios.saldo_correto = saldo; //atribui saldo na estrutura

                printf("\nUsuário inserido com id %d.\n", usuarios.id);

                //gravacao dos dados no arquivo
                fprintf(arq, "%d, ", usuarios.id);
                fprintf(arq, "%s, ", usuarios.nome);
                fprintf(arq, "%d, ", usuarios.idade_correta);
                fprintf(arq, "%20.2f.\n",usuarios.saldo_correto); //padronizacao do tamanho do saldo (necessaria na opcao 4)
                fclose(arq);
                break;

            case '2':
                arq = fopen("example.txt", "a");//abre o arquivo no início da função no modo append
                if (arq == NULL) {//verifica se a abertura deu certo
                    printf("Erro na abertura do arquivo!");
                return 1;
                }
                printf("\nDeseja cadastrar quantos usuários?\n");
                scanf("%d", &quant1); //quantidade de usuarios a serem cadastrados
                usuario *usuarios = (usuario *)malloc(quant1*sizeof(usuario)); //alocacao dinamica

                for (h = 0; h < quant1; h++){
                    id = id + 1; //id incrementado automaticamente
                    usuarios->id = id; //simbolo da estrutura muda com alocacao dinamica e passa a ser a seta em vez de ponto
                    printf("\n\nDigite o nome do usuário (máximo de 100 caracteres):\n");
                    setbuf(stdin, NULL); gets(nome); //limpeza do buffer da string
                    for (int j = 0; j < strlen(nome); j++) {//verifica se tem caracteres invalidos no nome
                        resultado = isalpha(nome[j]);
                        if (resultado == 0 && nome[j] != ' ') {
                            printf("Erro! Nome inválido! Digite o nome novamente (máximo de 100 caracteres):");
                             setbuf(stdin, NULL); gets(nome);
                            j = -1; // Reinicia a verificação do início
                        }
                    }
                strcpy(usuarios->nome, nome); //copia a string para a estrutura

                printf("\nDigite a idade do usuário:\n");
                scanf("%d", &idade);
                while (idade < 0) { //verificacao de idade negativa
                    printf("\nErro! A idade não pode ser negativa. Insira a idade novamente!\n");
                    scanf("%d", &idade);
                }
                while (idade > 200) {//verifica se a idade e muito grande
                    printf("\nErro! A idade inválida. Insira a idade novamente!\n");
                    scanf("%d", &idade);
                }
                usuarios->idade_correta = idade;

                printf("\nDigite o saldo do usuário (até 23 dígitos considerando centavos):\n");
                scanf("%f", &saldo);
                while (saldo < 0) { //verificacao do saldo negativo
                    printf("\nErro! O saldo não pode ser negativo. Insira o saldo novamente! (até 23 dígitos considerando centavos)\n");
                    scanf("%f", &saldo);
                }
                usuarios->saldo_correto = saldo;

                printf("\nUsuário inserido com id %d.\n", usuarios->id);

                //gravacao no arquivo
                fprintf(arq, "%d, ", usuarios->id);
                fprintf(arq, "%s, ", usuarios->nome);
                fprintf(arq, "%d, ", usuarios->idade_correta);
                fprintf(arq, "%20.2f.\n",usuarios->saldo_correto); //padronizacao do tamanho do saldo (necessaria na opcao 4)
                }
                free(usuarios); //alocao dinamica precisa liberar o espaco da memoria utilizada
                fclose(arq);
                break;

            case '3':

                encontrou = 0; //variavel igual a 0 ate encontrar o id em questao
                printf("\nDigite o ID do usuário que deseja buscar: ");
                scanf("%d", &busca_Id);

                arq = fopen("example.txt", "r");
                if (arq == NULL) {
                    printf("Erro na abertura do arquivo!");
                    return 1;
                }

                while (fgets(linha, sizeof(linha), arq) != NULL) {//percorre o arquivo linha por linha a procura do id em questao
                    sscanf(linha, "%d", &id);//extrai o id da linha do arquivo
                    if (id == busca_Id) {//se o id do usuario for o mesmo do procurado, encontrou = 1
                        encontrou = 1;
                        sscanf(linha, "%*d, %[^,], %d, %f", nome, &idade, &saldo);//essa funcao extrai nome, idade e saldo do usuario

                        printf("\nUsuário encontrado:\n");
                        printf("%d, %s, %d, %.2f.\n", id, nome, idade, saldo);//imprime as informacoes do usuario
                        break;//quando encontrar, nao precisa mais percorrer o arquivo, pois os ids sao sempre diferentes
                    }
                }

                if (encontrou == 0) {//se encontrou = 0 ainda depois da repeticao
                    printf("\nUsuário não encontrado.\n");//nao existe usuario com esse id
                }
                fclose(arq);

                break;

            case '4':
                encontrouDestino = 0; //variavel igual a 0 ate encontrar o id em questao
                encontrouOrigem = 0;

                do {
                    printf("\nInforme o ID do usuário de origem:\n");
                    scanf("%d", &id_origem);
                    printf("\nInforme o ID do usuário de destino:\n");
                    scanf("%d", &id_destino);

                    if (id_origem == id_destino) { //verifica se os ids sao distintos
                        printf("\nErro! O usuário de origem e de destino têm que ser diferentes! Insira os usuários novamente.\n");
                    }
                } while (id_origem == id_destino);


                arq = fopen("example.txt", "r+"); // abre o arquivo no modo leitura e escrita

                if (arq == NULL) {//verifica se a abertura deu certo
                    printf("Erro ao abrir o arquivo.\n");
                    return 1;
                }

                while (fgets(linha, sizeof(linha), arq) != NULL) {//mesma logica da opcao 3, buscar o usuario por linha
                    sscanf(linha, "%d, %[^,], %d, %f.\n",  &id, nome, &idade, &saldo);


                    if (id == id_origem) {//procura se existe o usuario de origem e qual é o seu saldo
                        encontrouOrigem = 1; //se encontrou o id, o resultado muda de 0 para 1
                        posicaoOrigem = ftell(arq) - strlen(linha) - 1; //​​obtem a posição atual do indicador de posição dentro de um arquivo e  retorna o valor do tipo long int, que representa a posição atual em relação ao início do arquivo
                        saldoOrigem_inicial = saldo;
                        strcpy(nomeOrigem, nome);
                        idadeOrigem = idade;
                    }
                    if (id == id_destino) {//procura se existe o usuario de destino e qual é o seu saldo

                        encontrouDestino = 1;//se encontrou o id, o resultado muda de 0 para 1
                        posicaoDestino = ftell(arq) - strlen(linha) - 1; //​​obtem a posição atual do indicador de posição dentro de um arquivo e  retorna o valor do tipo long int, que representa a posição atual em relação ao início do arquivo
                        saldoDestino_inicial = saldo;
                        strcpy(nomeDestino, nome);
                        idadeDestino = idade;
                    }

                    if (encontrouOrigem == 1 && encontrouDestino == 1) {//os usuarios de origem e de destino devem existir
                        break;
                    }
                }

                if (encontrouOrigem == 0 || encontrouDestino == 0) {//se pelo menos um dos usuarios nao existir
                    if (encontrouOrigem == 0) {//se o de origem nao existir
                        printf("Usuário de origem não encontrado.\n");
                    }
                    if (encontrouDestino == 0) {//se o de destino nao existir
                        printf("Usuário de destino não encontrado.\n");
                    }
                    break;
                    }

                do {
                    printf("\nInforme o valor a ser transferido:\n");
                    scanf("%f", &transferencia);

                    if (transferencia <= 0) { //verificacoes sobre os valores de transferencia
                        printf("Erro! Não é possível realizar essa transferência. Insira o valor novamente.\n");
                    }
                    if (saldoOrigem_inicial < transferencia) {
                        printf("Erro! O valor da transferência não pode ser maior que o saldo do usuário. Insira o valor novamente.\n");
                    }

                } while ((transferencia <= 0) || (saldoOrigem_inicial < transferencia));

                saldoOrigem = saldoOrigem_inicial - transferencia; //atualizacao dos saldos
                saldoDestino = saldoDestino_inicial + transferencia;

                printf("\n\nTransferência realizada com sucesso!\n\n");
                printf("\nSaldo do usuário %d é: %.2f\n", id_origem, saldoOrigem);
                printf("\nSaldo do usuário %d é: %.2f\n\n", id_destino, saldoDestino);

                //recebe a variavel float e transforma em string com tamanho padrao
                snprintf(saldoOrigem_string, sizeof(saldoOrigem_string), "%20.2f", saldoOrigem);
                snprintf(saldoDestino_string, sizeof(saldoDestino_string), "%20.2f", saldoDestino);
                snprintf(saldoOrigem_inicial_string, sizeof(saldoOrigem_inicial_string), "%20.2f", saldoOrigem_inicial);
                snprintf(saldoDestino_inicial_string, sizeof(saldoDestino_inicial_string), "%20.2f", saldoDestino_inicial);

                //padronizacao da linha
                snprintf(linha, sizeof(linha), "%d, %s, %d, %20.2f.", id_origem, nomeOrigem, idadeOrigem, saldoOrigem);
                fseek(arq, posicaoOrigem - (strlen(saldoOrigem_string) - strlen(saldoOrigem_inicial_string)), SEEK_SET); //ajusta a posicao da linha
                fprintf(arq, "%s", linha);

                snprintf(linha, sizeof(linha), "%d, %s, %d, %20.2f.", id_destino, nomeDestino, idadeDestino, saldoDestino);
                fseek(arq, posicaoDestino - (strlen(saldoDestino_string) - strlen(saldoDestino_inicial_string)), SEEK_SET);
                fprintf(arq, "%s", linha); //grava a string no arquivo
                fclose(arq);
                break;

            case '5':
                encontrou = 0; // a variavel inicia em 0 e muda para 1 quando o id e encontrado
                printf("\nDigite o ID do usuário que deseja remover:\n");
                scanf("%d", &id_para_apagar); //recebe o id que o usuario quer apagar

                arq = fopen("example.txt", "r+");
                if (arq == NULL) {
                    printf("Erro na abertura do arquivo!");
                    return 1;
                }

                FILE *temporario = fopen("temporario.txt", "w");//cria um arquivo temporario que recebe todas as linhas, menos a do usuario que foi apagado
                if (temporario == NULL) {
                    printf("Erro na criação do arquivo temporário!");
                    fclose(arq);
                    return 1;
                }

                while (fgets(linha, sizeof(linha), arq) != NULL) {
                    sscanf(linha, "%d, %*[^,], %*d, %*f.", &id);

                    if (id != id_para_apagar) {
                        fputs(linha, temporario); //escreve a linha em questao no arquivo temporario (usuarios que nao serao apagados)
                    }
                    else {
                        encontrou = 1;
                        posicao = ftell(arq); //grava a posicao do id a ser apagado
                        printf("\nUsuário removido com sucesso!\n");
                    }
                }
                fclose(arq);
                fclose(temporario);

                if (encontrou == 0) { //usuario nao existe ou ja foi apagado
                    printf("\nUsuário não existe!\n");
                }

                arq = fopen("example.txt", "w"); //abre no modo escrever
                if (arq == NULL) {
                    printf("Erro na abertura do arquivo!\n");
                    return 1;
                }

                temporario = fopen("temporario.txt", "r"); //abre no modo leitura
                if (temporario == NULL) {
                    printf("Erro na abertura do arquivo temporário!\n");
                    fclose(temporario);
                    return 1;
                }

                while (fgets(linha, sizeof(linha), temporario) != NULL) { //reescreve o arquivo example.txt
                    fputs(linha, arq); //le a linha do arquivo temporario e escreve no arquivo final
                }

                fclose(arq);
                fclose(temporario);
                remove("temporario.txt");

                break;

            case '6': //opcao para sair do menu, apenas retorna 0

            return 0;
            break;

        }
    }while (opcao != 6);
}
