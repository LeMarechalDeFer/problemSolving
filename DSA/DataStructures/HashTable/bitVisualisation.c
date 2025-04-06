#include <stdio.h>

// Fonction pour afficher un nombre en binaire (32 bits)
void print_bits(unsigned int n) {
    for (int i = 31; i >= 0; i--) {
        printf("%c", (n & (1U << i)) ? '1' : '0');
        if (i % 8 == 0) printf(" ");
    }
    printf("\n");
}

unsigned long djb2_with_visual(const char* str) {
    unsigned long hash = 5381;
    int c;
    int i = 0;

    printf("Initial hash (5381):\n");
    print_bits(hash);
    printf("Decimal: %lu\n\n", hash);

    while ((c = *str++)) {
        printf("=== Character %d: '%c' (ASCII %d) ===\n", i++, c, c);
        printf("Before:\n");
        print_bits(hash);
        printf("Decimal: %lu\n", hash);

        unsigned long h32 = hash << 5;
        printf("Step 1 - hash << 5:\n");
        print_bits(h32);
        printf("Decimal: %lu\n", h32);

        unsigned long h33 = h32 + hash;
        printf("Step 2 - hash * 33 (hash << 5 + hash):\n");
        print_bits(h33);
        printf("Decimal: %lu\n", h33);

        hash = h33 + c;
        printf("Step 3 - Add char:\n");
        print_bits(hash);
        printf("Decimal: %lu\n", hash);
        printf("----------------------------\n\n");
    }

    printf("Final hash:\n");
    print_bits(hash);
    printf("Decimal: %lu\n", hash);
    return hash;
}

int main() {
    const char* input = "abc";
    printf("Hashing the string: \"%s\"\n\n", input);
    djb2_with_visual(input);
    return 0;
}
