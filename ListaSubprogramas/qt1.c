#include <stdio.h>

// Passagem por referencia: trabalha direto nos enderecos originais.
// Se os dois parametros apontarem para a mesma variavel,
// a mudanca em *a afeta *b na hora.
void por_referencia(int *a, int *b) {
    *a += 10;
    *b += 20;
}

// Simulacao de passagem por valor-resultado:
// faz copias locais no inicio, trabalha nelas,
// e so escreve de volta no final.
// Se os dois parametros apontarem para a mesma variavel,
// o segundo resultado vai sobrescrever o primeiro.
void por_valor_resultado(int *a, int *b) {
    int copia_a = *a;
    int copia_b = *b;

    copia_a += 10;
    copia_b += 20;

    *a = copia_a;
    *b = copia_b;
}

int main() {
    int x;

    // chamando com a mesma variavel nos dois parametros
    // aqui a diferenca entre os dois metodos aparece

    x = 5;
    printf("Por referencia (chamando com a mesma variavel):\n");
    printf("Antes:  x = %d\n", x);
    por_referencia(&x, &x);
    printf("Depois: x = %d\n\n", x);
    // *a += 10 -> x vira 15
    // *b += 20 -> x (que eh o mesmo) vira 35

    x = 5;
    printf("Por valor-resultado (chamando com a mesma variavel):\n");
    printf("Antes:  x = %d\n", x);
    por_valor_resultado(&x, &x);
    printf("Depois: x = %d\n", x);
    // copia_a = 5, copia_b = 5
    // copia_a += 10 -> 15, copia_b += 20 -> 25
    // *a = 15, depois *b = 25 -> x fica 25

    return 0;
}