#include <stdio.h>

#define NUM_ESTADOS 8
#define CIDADES_POR_ESTADO 4
#define TOTAL_CIDADES (NUM_ESTADOS * CIDADES_POR_ESTADO)

// Estrutura que representa uma cidade
typedef struct {
    char codigo[4];  // Código no formato A01, B02, etc.
    int populacao;
    float area;
    double pib;
    int pontosTuristicos;
} Cidade;

// Função para cadastrar as cidades
void cadastrarCidades(Cidade cidades[]) {
    char estados[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};
    int cidadeIndex = 0;

    printf("\n=== Cadastro de Cidades ===\n");

    for (int i = 0; i < NUM_ESTADOS; i++) {
        for (int j = 1; j <= CIDADES_POR_ESTADO; j++) {
            // Gerando código da cidade
            snprintf(cidades[cidadeIndex].codigo, sizeof(cidades[cidadeIndex].codigo), "%c%02d", estados[i], j);

            // Coletando dados da cidade
            printf("\nCadastro da cidade %s:\n", cidades[cidadeIndex].codigo);
            printf("População: ");
            scanf("%d", &cidades[cidadeIndex].populacao);
            printf("Área (km²): ");
            scanf("%f", &cidades[cidadeIndex].area);
            printf("PIB (em bilhões): ");
            scanf("%lf", &cidades[cidadeIndex].pib);
            printf("Número de pontos turísticos: ");
            scanf("%d", &cidades[cidadeIndex].pontosTuristicos);

            cidadeIndex++;
        }
    }
}

// Função para exibir todas as cidades cadastradas
void exibirCidades(Cidade cidades[]) {
    printf("\n=== Cartas Cadastradas ===\n");
    for (int i = 0; i < TOTAL_CIDADES; i++) {
        printf("\nCódigo: %s", cidades[i].codigo);
        printf("\nPopulação: %d habitantes", cidades[i].populacao);
        printf("\nÁrea: %.2f km²", cidades[i].area);
        printf("\nPIB: %.2lf bilhões", cidades[i].pib);
        printf("\nPontos turísticos: %d\n", cidades[i].pontosTuristicos);
    }
}

// Função principal
int main() {
    Cidade cidades[TOTAL_CIDADES];

    // Cadastrando as cidades
    cadastrarCidades(cidades);

    // Exibindo os dados das cidades cadastradas
    exibirCidades(cidades);

    return 0;
}
