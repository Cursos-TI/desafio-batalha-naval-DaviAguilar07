#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

int main() {
    // Nível Novato - Posicionamento dos Navios
    // Sugestão: Declare uma matriz bidimensional para representar o tabuleiro (Ex: int tabuleiro[5][5];).
    // Sugestão: Posicione dois navios no tabuleiro, um verticalmente e outro horizontalmente.
    // Sugestão: Utilize `printf` para exibir as coordenadas de cada parte dos navios.
   
    // Tabuleiro 10x10 inicializado com zeros
    int matriz[10][10] = {0};

    int matriz2cone[5][5] = {5};//Cone-Habilidade
    int matriz3cruz[5][5] = {5};//Cruz-Habilidade
    int matriz4octaedro[5][5] = {5};//Octaedro-Habilidade

    // Quatro navios de tamanho 3
    int navio1[3] = {3, 3, 3}; // horizontal
    int navio2[3] = {3, 3, 3}; // vertical

    int navio3[3] = {3, 3, 3}; //diagonal1
    int navio4[3] = {3, 3, 3}; //diagonal2

     int habilidadecone[5] = {5, 5, 5, 5, 5}; //Habilidade-Cone
     int habilidadecruz[5] = {5, 5, 5, 5, 5}; //Habilidade-Cruz
     int habilidadeoctaedro[5] = {5, 5, 5, 5, 5}; //Habilidade-Octaedro


    // Coordenadas iniciais dos navios
    int linhaNavio1Horizontal = 2;
    int colunaNavio1Horizontal = 4;

    int linhaNavio2Vertical = 5;
    int colunaNavio2Vertical = 7;

    int linhanavio3diagonal = 3;
    int colunanavio3diagonal = 1;

    int linhanavio4diagonal = 5;
    int colunanavio4diagonal = 5;

    //Coordenadas das habiidades
    int linhahabilidadecone = 4;
    int colunahabilidadecone = 4;

    int linhahabilidadecruz = 6;
    int colunahabilidadecruz = 6;

    int linhahabilidadeoctaedro = 3;
    int colunahabilidadeoctaedro = 6;

    //Área de afetamento
    int valor1 = 1;




    // Posiciona navio horizontal
    for (int j = 0; j < 3; j++) {
        matriz[linhaNavio1Horizontal][colunaNavio1Horizontal + j] = navio1[j];
    }

    // Posiciona navio vertical
    for (int i = 0; i < 3; i++) {
        matriz[linhaNavio2Vertical + i][colunaNavio2Vertical] = navio2[i];
    }

    // Posiciona diagonal 1 
    for(int d = 0; d < 3; d++){
        matriz[linhanavio3diagonal + d][colunanavio3diagonal + d] = navio3[d];
    }//Essa diagonal vai para baixo e direita

    //Posiciona diagonal 2
    for(int a = 0; a < 3; a++){
        matriz[linhanavio4diagonal - a][colunanavio4diagonal + a] = navio4[a];
    }//Essa diagonal vai para cima e direita

    

    // Construção dinâmica das matrizes de habilidade
    // Cone
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            if(j >= 2 - i && j <= 2 + i) matriz2cone[i][j] = 1;
            else matriz2cone[i][j] = 0;
        }
    }

    // Cruz
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            if(i == 2 || j == 2) matriz3cruz[i][j] = 1;
            else matriz3cruz[i][j] = 0;
        }
    }

    // Octaedro
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            if(abs(i-2) + abs(j-2) <= 2) matriz4octaedro[i][j] = 1;
            else matriz4octaedro[i][j] = 0;
        }
    }

    // Função de sobreposição no tabuleiro
    int offset = 2; // centro da matriz 5x5
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            if(matriz2cone[i][j] == 1){
                int linha = linhahabilidadecone + (i - offset);
                int coluna = colunahabilidadecone + (j - offset);
                if(linha >= 0 && linha < 10 && coluna >= 0 && coluna < 10)
                    matriz[linha][coluna] = 5;
            }
            if(matriz3cruz[i][j] == 1){
                int linha = linhahabilidadecruz + (i - offset);
                int coluna = colunahabilidadecruz + (j - offset);
                if(linha >= 0 && linha < 10 && coluna >= 0 && coluna < 10)
                    matriz[linha][coluna] = 5;
            }
            if(matriz4octaedro[i][j] == 1){
                int linha = linhahabilidadeoctaedro + (i - offset);
                int coluna = colunahabilidadeoctaedro + (j - offset);
                if(linha >= 0 && linha < 10 && coluna >= 0 && coluna < 10)
                    matriz[linha][coluna] = 5;
            }
        }
    }

    //Exibe o tabuleiro
    printf("---A batalha naval---\n");
    printf("\n");
    printf("   A B C D E F G H I J\n"); //Cabeçalho do tabuleiro

     for (int i = 0; i < 10; i++) {
        printf("%2d ", i + 1); // imprime número da linha (1 a 10)
        for (int j = 0; j < 10; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
    
    // Nível Aventureiro - Expansão do Tabuleiro e Posicionamento Diagonal
    // Sugestão: Expanda o tabuleiro para uma matriz 10x10.
    // Sugestão: Posicione quatro navios no tabuleiro, incluindo dois na diagonal.
    // Sugestão: Exiba o tabuleiro completo no console, mostrando 0 para posições vazias e 3 para posições ocupadas.

    // Nível Mestre - Habilidades Especiais com Matrizes
    // Sugestão: Crie matrizes para representar habilidades especiais como cone, cruz, e octaedro.
    // Sugestão: Utilize estruturas de repetição aninhadas para preencher as áreas afetadas por essas habilidades no tabuleiro.
    // Sugestão: Exiba o tabuleiro com as áreas afetadas, utilizando 0 para áreas não afetadas e 1 para áreas atingidas.

    // Exemplos de exibição das habilidades:
    // Exemplo para habilidade em cone:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 1 1 1 1 1
    
    // Exemplo para habilidade em octaedro:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 0 0 1 0 0

    // Exemplo para habilidade em cruz:
    // 0 0 1 0 0
    // 1 1 1 1 1
    // 0 0 1 0 0

    return 0;
}
