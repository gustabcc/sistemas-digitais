#include <msp430.h>

const unsigned char pesos[] = {4, 3, 2, 1};
unsigned int amostras[] = {100, 80, 60, 40};

void configura_UART() {
    // ConfiguraÃ§Ã£o dos pinos da UART
    P1SEL |= BIT1 + BIT2;       // P1.1 = RXD, P1.2=TXD
    P1SEL2 |= BIT1 + BIT2;      // P1.1 = RXD, P1.2=TXD

    // ConfiguraÃ§Ã£o do mÃ³dulo UART
    UCA0CTL1 |= UCSSEL_2;       // SMCLK
    UCA0BR0 = 104;              // 1MHz/9600 = 104
    UCA0BR1 = 0;                // 1MHz/9600 = 104
    UCA0MCTL = UCBRS0;          // Modulation UCBRSx = 1

    UCA0CTL1 &= ~UCSWRST;       // Initialize USCI state machine
}

void envia_caractere_UART(unsigned char caractere) {
    while (!(IFG2 & UCA0TXIFG)); // Aguarda buffer de transmissÃ£o vazio
    UCA0TXBUF = caractere;       // Transmite caractere
}

void envia_string_UART(const char *string) {
    while (*string) {
        envia_caractere_UART(*string++);
    }
}

void main(void)
{
    WDTCTL = WDTPW | WDTHOLD;   // Stop watchdog timer

    configura_UART();           // ConfiguraÃ§Ã£o inicial da UART

    unsigned int resultado = 0;
    unsigned int soma_pesos = 0;
    unsigned int i;

    // Calcular a soma total dos pesos
    for (i = 0; i < sizeof(pesos) / sizeof(pesos[0]); i++) {
        soma_pesos += pesos[i];
    }

    // ImplementaÃ§Ã£o do algoritmo do camponÃªs russo para calcular a mÃ©dia ponderada
    for (i = 0; i < sizeof(pesos) / sizeof(pesos[0]); i++) {
        unsigned int a = pesos[i];
        unsigned int b = amostras[i];

        while (a > 0) {
            if (a % 2 != 0) {
                resultado += b;
            }
            a = a / 2;
            b = b * 2;
        }
    }

    // Calcular a mÃ©dia ponderada
    unsigned int media_ponderada = resultado / soma_pesos;

    // Converter a mÃ©dia ponderada em string para enviar via UART
    char buffer[16];  // Tamanho arbitrÃ¡rio para o buffer
    snprintf(buffer, sizeof(buffer), "%u\r\n", media_ponderada);  // Formata o resultado como string

    // Envia a string via UART
    envia_string_UART(buffer);

    while (1);  // Loop infinito
}
