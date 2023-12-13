#include <stdio.h>
#include <stdbool.h>

#define STATES 4
#define ALPHABET 2

// Tabela de transição do AFD
int transitionTable[STATES][ALPHABET] = {
    {1, 0},  // q0
    {1, 2},  // q1
    {1, 3},  // q2
    {1, 3}   // q3 (estado de aceitação)
};

// Função para verificar se uma string é aceita pelo AFD
bool isAccepted(char input[]) {
    int currentState = 0;

    for (int i = 0; input[i] != '\0'; i++) {
        char symbol = input[i] - 'a';  // converter char para int (0 ou 1)
        currentState = transitionTable[currentState][symbol];
    }

    return currentState == 3;  // verificar se o estado final é um estado de aceitação
}

int main() {
    char input[100];
    printf("Digite a string de entrada (a's e b's): ");
    scanf("%s", input);

    if (isAccepted(input)) {
        printf("A string é aceita.\n");
    } else {
        printf("A string não é aceita.\n");
    }

    return 0;
}
