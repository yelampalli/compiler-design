#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define NUM_NON_TERMINALS 3
#define NUM_PRODUCTIONS 4

// Define the non-terminals and productions
char nonTerminals[NUM_NON_TERMINALS] = {'S', 'A', 'B'};
char productions[NUM_PRODUCTIONS][10] = {
    "S->A",
    "A->e",  // Production that derives an empty string
    "A->a",
    "B->b"
};

bool isAmbiguous(char nonTerminal, int rule) {
    for (int i = 0; i < NUM_PRODUCTIONS; i++) {
        if (productions[i][0] == nonTerminal && i != rule) {
            if (productions[i][3] == nonTerminal) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    bool ambiguous = false;

    for (int i = 0; i < NUM_NON_TERMINALS; i++) {
        for (int j = 0; j < NUM_PRODUCTIONS; j++) {
            if (productions[j][3] == nonTerminals[i] && isAmbiguous(nonTerminals[i], j)) {
                ambiguous = true;
                break;
            }
        }
        if (ambiguous) {
            break;
        }
    }

    if (ambiguous) {
        printf("The grammar is ambiguous.\n");
    } else {
        printf("The grammar is not ambiguous.\n");
    }

    return 0;
}
