#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *numeroPorExtenso(int num) {
    char *unidades[] = {
        "", "um", "dois", "três", "quatro", "cinco", "seis", "sete", "oito", "nove"
    };
    char *dezAteVinte[] = {
        "dez", "onze", "doze", "treze", "catorze", "quinze", "dezesseis", "dezessete", "dezoito", "dezenove"
    };
    char *dezenas[] = {
        "", "", "vinte", "trinta", "quarenta", "cinquenta", "sessenta", "setenta", "oitenta", "noventa"
    };
    char *centenas[] = {
        "", "cem", "duzentos", "trezentos", "quatrocentos", "quinhentos", "seiscentos", "setecentos", "oitocentos", "novecentos"
    };

    if (num == 0) {
        return "zero";
    }

    char extenso[1000] = "";

    if (num >= 1000000000) {
        strcat(extenso, numeroPorExtenso(num / 1000000000));
        strcat(extenso, " bilhões");
        num %= 1000000000;
        if (num > 0) {
            strcat(extenso, " e ");
        }
    }

    if (num >= 1000000) {
        strcat(extenso, numeroPorExtenso(num / 1000000));
        strcat(extenso, " milhões");
        num %= 1000000;
        if (num > 0) {
            strcat(extenso, " e ");
        }
    }

    if (num >= 1000) {
        if (num / 1000 != 1)
            strcat(extenso, numeroPorExtenso(num / 1000));
        strcat(extenso, " mil");
        num %= 1000;
        if (num > 0) {
            strcat(extenso, " e ");
        }
    }

    if (num >= 100) {
        strcat(extenso, centenas[num / 100]);
        num %= 100;
        if (num > 0) {
            strcat(extenso, " e ");
        }
    }

    if (num >= 20) {
        strcat(extenso, dezenas[num / 10]);
        num %= 10;
        if (num > 0) {
            strcat(extenso, " e ");
        }
    }

    if (num >= 10) {
        strcat(extenso, dezAteVinte[num - 10]);
    } else if (num > 0) {
        strcat(extenso, unidades[num]);
    }

    char *resultado = malloc(strlen(extenso) + 1);
    strcpy(resultado, extenso);
    return resultado;
}

void separarParteInteiraEDecimal(double numero, int *parteInteira, int *parteDecimal) {
    *parteInteira = (int)numero;
    *parteDecimal = (int)((numero - *parteInteira) * 100);
}

int main() {
    double numero;
    printf("Digite um numero: ");
    scanf("%lf", &numero);

    if (numero < 0 || numero > 999999999999) {
        printf("Numero fora do intervalo permitido.\n");
        return 1;
    }

    int parteInteira, parteDecimal;
    separarParteInteiraEDecimal(numero, &parteInteira, &parteDecimal);

    char *extensoInteiro = numeroPorExtenso(parteInteira);
    char *extensoDecimal = numeroPorExtenso(parteDecimal);

    printf("O numero %.2lf por extenso é: %s", numero, extensoInteiro);
    if (parteDecimal > 0) {
        printf(" e %s centavos", extensoDecimal);
    }
    printf("\n");

    free(extensoInteiro);
    free(extensoDecimal);
    return 0;
}
