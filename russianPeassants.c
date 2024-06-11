#include <stdio.h>

const unsigned char pesos[] = {4, 3, 2, 1};
const unsigned int amostras[] = {100, 80, 60, 40};

// Função para realizar a multiplicação pelo Algoritmo de Multiplicação do Camponês Russo
unsigned int russian_peasant_multiplication(unsigned int a, unsigned int b) {
    unsigned int result = 0;

    while (b > 0) {
        if (b & 1) {
            result += a; // Se o bit menos significativo de b for 1, adiciona a ao resultado
        }
        a <<= 1;  // Multiplica a por 2
        b >>= 1;  // Divide b por 2
    }

    return result;
}

// Função para calcular a média ponderada
unsigned int calcular_media_ponderada(const unsigned char* pesos, const unsigned int* amostras, unsigned char tamanho) {
    unsigned int soma_ponderada = 0;
    unsigned int soma_pesos = 0;

    for (unsigned char i = 0; i < tamanho; i++) {
        soma_ponderada += russian_peasant_multiplication(pesos[i], amostras[i]);
        soma_pesos += pesos[i];
    }

    if (soma_pesos == 0) {
        return 0;  // Evita divisão por zero
    }

    return soma_ponderada / soma_pesos;
}

int main(void) {
    unsigned char tamanho = sizeof(pesos) / sizeof(pesos[0]);
    unsigned int media_ponderada = calcular_media_ponderada(pesos, amostras, tamanho);

    // Exibir o valor da média ponderada
    printf("Media Ponderada: %u\n", media_ponderada);

    return 0;
}
