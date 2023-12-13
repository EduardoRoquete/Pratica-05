#include <stdio.h>
#include <stdbool.h>

#define STATES 2
#define ALPHABET 2

// Tabela de transição do AFD
int transitionTable[STATES][ALPHABET] = {
    {0, 1},  // q0
    {1, 0}   // q1 (estado de aceitação)
};

// Função para verificar se uma string é aceita pelo AFD
bool isAccepted(char input[]) {
    int currentState = 0;

    for (int i = 0; input[i] != '\0'; i++) {
        char symbol = input[i] - '0';  // converter char para int (0 ou 1)
        currentState = transitionTable[currentState][symbol];
    }

    return currentState == 1;  // verificar se o estado final é um estado de aceitação
}

int main() {
    char input[100];
    printf("Digite a string de entrada (0's e 1's): ");
    scanf("%s", input);

    if (isAccepted(input)) {
        printf("A string é aceita.\n");
    } else {
        printf("A string não é aceita.\n");
    }

    return 0;
}
