SSC0502 - Laboratório de Introdução à Ciência da Computação I
Prof.Dr. Danilo Hernane Spatti spatti@icmc.usp.br
Monitor: Karoliny Oliveira karolinyoliveira@usp.br
Projeto 1
> Descrição do Problema
O objetivo deste projeto é criar o sistema de gestão dos usuários
do Uaibank, em C, utilizando alocação dinâmica de memória para
armazenar as informações dos usuários e passá-los para um arquivo
externo. O sistema deverá permitir as seguintes operações:
1. Inserção de um novo usuário:
1
<nome>, <idade>, <saldo atual>
2. Inserção de vários usuários:
2
<qtde usuarios>
<nome>, <idade>, <saldo atual> (de cada usuário)
3. Busca de um usuário por id:
3
<id>
4. Transferências entre usuários:
4
<id de origem> <id de destino> <quantia>
4. Remoção de um usuário por id:
5
<id>
O sistema deve fornecer uma interface de linha de comando para
o usuário interagir com as funcionalidades mencionadas anteriormente.
Esse usuário será formado por id, nome, idade e saldo atual. Vale
ressaltar que é dever do programador gerar identificadores únicos para
cada usuário.
Alguns exemplos de entrada e saída esperados do sistema
encontram-se a seguir:
1
Joel Gamer, 13, 1000000.00
2
2
Silvia Santos, 30, 12.50
Manuella da Silva, 21, 123.89
3
1
5
1
3
1
Usuário inserido com id 1.
Usuários inseridos com id 2 e 3.
Usuário 1 tem saldo de R$1000000.00.
Usuário 1 removido com sucesso.
Erro: Usuário 1 não encontrado.
O arquivo gerado por essas transações estará, ao final da
execução de todos os comandos da seguinte forma:
example.txt
Silvia Santos, 30, 12.50
Manuella da Silva, 21, 123.89
Importante! Para correta execução dos critérios exigidos pelo
banco Uaibank o sistema seguirá algumas regras:
1. O campo nome deverá ter no máximo 100 caracteres;
2. A saída padrão deverá conter informações sobre o resultado de
cada uma das transações solicitadas.
3. O arquivo final deverá ter o mesmo formato definido neste
documento, bem como a listagem de usuários esperada na ordem correta.
4. O único campo que deverá ter valores únicos é o id.
5. Nenhum usuário poderá ter saldo negativo.
> Instruções
O trabalho será dividido em duas partes:
1. Modelagem do Problema
Nessa etapa é esperado que os alunos elaborem um documento
contendo um fluxograma explicando como irão desenvolver o projeto e
pseudocódigos das funcionalidades descritas anteriormente.
A entrega deverá ser feita no dia 18/05 via e-disciplinas.
2. Implementação
Nessa etapa o(s) arquivo(s) .c deverão ser enviados via Moodle
respeitando as regras e usando os recursos da linguagem comentados em
aula pelo professor. A data limite para entrega dessa parte é o dia
06/07.
> Método de Avaliação
Para a primeira parte do trabalho o objetivo será avaliar os
seguintes aspectos:
1. Corretude das estruturas de dados utilizadas;
2. Representação correta de todas as funcionalidades solicitadas
no enunciado;
3. Clareza do enunciado.
Na segunda parte, o trabalho será avaliado levando em
consideração:
1. Realização dos objetivos;
2. Representação correta da entrada e saída de dados;
3. Uso de comentários e estrutura do código (ex.: indentação,
legibilidade);
4. Número de acertos nos casos de testes propostos.
