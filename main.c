#include <stdio.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "Portuguese");

    // Dados das Cartas
    char nome1[50] = "Brasil";
    unsigned long int populacao1 = 213000000;
    float area1 = 8515767.0f;
    float pib1 = 1.9f; // trilhões
    int pontosTuristicos1 = 12;

    char nome2[50] = "Argentina";
    unsigned long int populacao2 = 45300000;
    float area2 = 2780000.0f;
    float pib2 = 0.5f;
    int pontosTuristicos2 = 9;

    // Densidade calculada
    float densidade1 = populacao1 / area1;
    float densidade2 = populacao2 / area2;

    int op1, op2;
    float valor1_carta1, valor2_carta1;
    float valor1_carta2, valor2_carta2;
    float soma_carta1, soma_carta2;

    // Função de exibição dinâmica de menu
    printf("=== SUPER TRUNFO - COMPARAÇÃO AVANÇADA ===\n\n");
    printf("Escolha o PRIMEIRO atributo:\n");
    printf("1 - População\n");
    printf("2 - Área (km²)\n");
    printf("3 - PIB (trilhões de R$)\n");
    printf("4 - Pontos Turísticos\n");
    printf("5 - Densidade Demográfica\n");
    printf("Digite sua escolha (1-5): ");
    scanf("%d", &op1);

    // Escolha do segundo atributo com menu dinâmico
    printf("\nEscolha o SEGUNDO atributo (diferente do primeiro):\n");
    for (int i = 1; i <= 5; i++) {
        if (i == op1) continue;
        switch (i) {
            case 1: printf("1 - População\n"); break;
            case 2: printf("2 - Área (km²)\n"); break;
            case 3: printf("3 - PIB (trilhões de R$)\n"); break;
            case 4: printf("4 - Pontos Turísticos\n"); break;
            case 5: printf("5 - Densidade Demográfica\n"); break;
        }
    }
    printf("Digite sua escolha (1-5): ");
    scanf("%d", &op2);

    // Verifica se os atributos são diferentes
    if (op1 == op2 || op1 < 1 || op1 > 5 || op2 < 1 || op2 > 5) {
        printf("\nErro: Você deve escolher dois atributos válidos e diferentes.\n");
        return 1;
    }

    // Obtem valores do PRIMEIRO atributo
    switch (op1) {
        case 1: valor1_carta1 = populacao1; valor1_carta2 = populacao2; break;
        case 2: valor1_carta1 = area1; valor1_carta2 = area2; break;
        case 3: valor1_carta1 = pib1; valor1_carta2 = pib2; break;
        case 4: valor1_carta1 = pontosTuristicos1; valor1_carta2 = pontosTuristicos2; break;
        case 5: valor1_carta1 = densidade1; valor1_carta2 = densidade2; break;
        default: printf("Erro no atributo 1\n"); return 1;
    }

    // Obtem valores do SEGUNDO atributo
    switch (op2) {
        case 1: valor2_carta1 = populacao1; valor2_carta2 = populacao2; break;
        case 2: valor2_carta1 = area1; valor2_carta2 = area2; break;
        case 3: valor2_carta1 = pib1; valor2_carta2 = pib2; break;
        case 4: valor2_carta1 = pontosTuristicos1; valor2_carta2 = pontosTuristicos2; break;
        case 5: valor2_carta1 = densidade1; valor2_carta2 = densidade2; break;
        default: printf("Erro no atributo 2\n"); return 1;
    }

    // Soma considerando regra especial para densidade (menor vence)
    soma_carta1 = (op1 == 5 ? (1.0 / valor1_carta1) : valor1_carta1) +
                  (op2 == 5 ? (1.0 / valor2_carta1) : valor2_carta1);

    soma_carta2 = (op1 == 5 ? (1.0 / valor1_carta2) : valor1_carta2) +
                  (op2 == 5 ? (1.0 / valor2_carta2) : valor2_carta2);

    // Resultado
    printf("\n=== RESULTADO DA COMPARAÇÃO ===\n");
    printf("%s: Atributo 1 = %.2f | Atributo 2 = %.2f | Soma = %.2f\n", nome1, valor1_carta1, valor2_carta1, soma_carta1);
    printf("%s: Atributo 1 = %.2f | Atributo 2 = %.2f | Soma = %.2f\n", nome2, valor1_carta2, valor2_carta2, soma_carta2);

    printf("\nVencedor: ");
    (soma_carta1 > soma_carta2) ? printf("%s venceu!\n", nome1) :
    (soma_carta2 > soma_carta1) ? printf("%s venceu!\n", nome2) :
    printf("Empate!\n");

    return 0;
}