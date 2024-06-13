#include <stdio.h>
#include <string.h>
#include <math.h>
// FunÃ§Ã£o para converter um nÃºmero decimal para BCD
void decimal_para_bcd(int decimal, int tamanho, char *binario) {
    int bcd_array[tamanho];
    for (int i = tamanho - 1; i >= 0; i--) {
        bcd_array[i] = decimal % 10;   // Obter o dÃ­gito da unidade
        decimal /= 10;                 // Dividir para obter o prÃ³ximo dÃ­gito
    }

    for (int i = tamanho-1; i >= 0; i--)
    {
        switch (bcd_array[i]) {
            case 0:
                binario[i * 5 + 0] = ' ';  
                binario[i * 5 + 1] = '0'; 
                binario[i * 5 + 2] = '0'; 
                binario[i * 5 + 3] = '0'; 
                binario[i * 5 + 4] = '0'; 
                break; // 0000
            case 1:
                binario[i * 5 + 0] = ' ';  
                binario[i * 5 + 1] = '0'; 
                binario[i * 5 + 2] = '0'; 
                binario[i * 5 + 3] = '0'; 
                binario[i * 5 + 4] = '1'; 
                break; // 0001
            case 2:
                binario[i * 5 + 0] = ' ';  
                binario[i * 5 + 1] = '0'; 
                binario[i * 5 + 2] = '0'; 
                binario[i * 5 + 3] = '1'; 
                binario[i * 5 + 4] = '0'; 
                break; // 0010
            case 3:
                binario[i * 5 + 0] = ' ';  
                binario[i * 5 + 1] = '0'; 
                binario[i * 5 + 2] = '0'; 
                binario[i * 5 + 3] = '1'; 
                binario[i * 5 + 4] = '1'; 
                break; // 0011
            case 4:
                binario[i * 5 + 0] = ' ';  
                binario[i * 5 + 1] = '0'; 
                binario[i * 5 + 2] = '1'; 
                binario[i * 5 + 3] = '0'; 
                binario[i * 5 + 4] = '0'; 
                break; // 0100
            case 5:
                binario[i * 5 + 0] = ' ';  
                binario[i * 5 + 1] = '0'; 
                binario[i * 5 + 2] = '1'; 
                binario[i * 5 + 3] = '0'; 
                binario[i * 5 + 4] = '1'; 
                break; // 0101
            case 6:
                binario[i * 5 + 0] = ' ';  
                binario[i * 5 + 1] = '0'; 
                binario[i * 5 + 2] = '1'; 
                binario[i * 5 + 3] = '1'; 
                binario[i * 5 + 4] = '0'; 
                break; // 0110
            case 7:
                binario[i * 5 + 0] = ' ';  
                binario[i * 5 + 1] = '0'; 
                binario[i * 5 + 2] = '1'; 
                binario[i * 5 + 3] = '1'; 
                binario[i * 5 + 4] = '1'; 
                break; // 0111
            case 8:
                binario[i * 5 + 0] = ' ';  
                binario[i * 5 + 1] = '1'; 
                binario[i * 5 + 2] = '0'; 
                binario[i * 5 + 3] = '0'; 
                binario[i * 5 + 4] = '0'; 
                break; // 1000
            case 9:
                binario[i * 5 + 0] = ' ';  
                binario[i * 5 + 1] = '1'; 
                binario[i * 5 + 2] = '0'; 
                binario[i * 5 + 3] = '0'; 
                binario[i * 5 + 4] = '1'; 
                break; // 1001
            default: 
                printf("DÃ­gito BCD invÃ¡lido!\n");
        }
    }
    
    
}

int binarioToDecimal(char in_binario[], int tan_binario) {
    int decimal = 0;

    for (int i = tan_binario - 1; i >= 0; i--)
    {
        if (in_binario[i] == '1')
        {
            decimal += pow(2, tan_binario - 1 - i);
        }
        
    }
    return decimal;
}



int main() {
    char in_binario[20] = "";
    char str[20];
    int tan_binario;
    int numero_decimal;
    int tan_dec;
    

    printf("Digite um numero em binario: ");
    scanf("%s", &in_binario);

    tan_binario = strlen(in_binario);

    numero_decimal = binarioToDecimal(in_binario, tan_binario);

    sprintf(str,"%d", numero_decimal);
    tan_dec = strlen(str);

    char binario[tan_dec * 5];

    // Converter o nÃºmero decimal para BCD
    decimal_para_bcd(numero_decimal, tan_dec, binario);

    binario[tan_dec * 5] = '\0';

    // Imprimir a representaÃ§Ã£o BCD
    printf("Numero em BCD: %s\n", binario);
    printf("Numero em decimal: %d", numero_decimal);

    printf("\n");

    return 0;
}