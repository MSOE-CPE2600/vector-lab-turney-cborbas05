/* Filename: calc.c
 * Author: Cameron Borbas
 * Date: 10/30/2025
 * Description: Main file, takes user inputs and preforms
 *      requested function (List, clear, +, -, etc.)
 *      Updated for Lab 7 dynamic memory and file I/O
 * Makefile / gcc -o calc calc.c vectors.c
 */
 
#include <stdio.h>
#include <string.h>
#include "vectors.h"

void print_help(void) {
    printf("\n=== Vector Calculator Help ===\n");
    printf("Commands:\n");
    printf("  name = x y z           Create vector (spaces or commas ok)\n");
    printf("  name = v1 + v2         Add vectors\n");
    printf("  name = v1 - v2         Subtract vectors\n");
    printf("  name = v1 * num        Scalar multiply\n");
    printf("  name = num * v1        Scalar multiply\n\n");
    printf("  v1 + v2, v1 - v2       Show result of operation\n");
    printf("  v * num or num * v     Show scalar multiply\n\n");
    printf("  list                   List all stored vectors\n");
    printf("  clear                  Clear all vectors\n");
    printf("  load <file>            Load vectors from CSV file\n");
    printf("  save <file>            Save vectors to CSV file\n");
    printf("  help                   Show this help\n");
    printf("  quit                   Exit program\n");
    printf("==============================\n\n");
}


// Loop for replacing any inputted commas as spaces for ease of read
void character_remover(char *s) {
    for (int i = 0 ;i< *s; s++) {
        if (*s == ',') {
            *s = ' ';
        }
    }
}


// Taking inputted string and parsing the needed values
int parse_vector_values(char *s, double v[3]) {
    character_remover(s);
    return sscanf(s, "%lf %lf %lf", &v[0], &v[1], &v[2]) >= 1;
}


int main(int argc, char *argv[]) {
    if (argc > 1 && strcmp(argv[1], "-h") == 0) {
        print_help();
        return 0;
    }

    char line[128];
    printf("=== Mini Vector Calculator ===\nType 'help' for commands.\n");

    while (1) {
        printf("minimat> ");
        if (!fgets(line, sizeof(line), stdin)) {
            break;
        }

        line[strcspn(line, "\n")] = 0;
        character_remover(line);

        // Quit command
        if (strcmp(line, "quit") == 0) {
            printf("Shutting down. Thanks for using the\n");
            printf("Mini Vector Calculator!\n");
            printf("Here are the vectors you created:\n\n");
            list_vectors();

            // Release dynamic memory before exit
            clear_vectors();
            break;
        }

        // Print help menu
        if (strcmp(line, "help") == 0) {
            print_help();
            continue;
        }

        // Print vector list
        if (strcmp(line, "list") == 0) {
            list_vectors();
            continue;
        }

        if (strcmp(line, "ls") == 0) {
            list_vectors();
            continue;
        }

        // Clear vector list
        if (strcmp(line, "clear") == 0) {
            clear_vectors();
            continue;
        }

        // File load
        if (strncmp(line, "load ", 5) == 0) {
            load_vectors(line + 5);
            continue;
        }

        // File save
        if (strncmp(line, "save ", 5) == 0) {
            save_vectors(line + 5);
            continue;
        }

        char name[32], rest[96];
        if (sscanf(line, "%s = %[^\n]", name, rest) == 2) {
            double v[3] = {0};
            if (parse_vector_values(rest, v) &&
                !strchr(rest, '+') && !strchr(rest, '-') && !strchr(rest, '*')) {
                add_vector(name, v);
                printf("%s = %.3f %.3f %.3f\n", name, v[0], v[1], v[2]);
                continue;
            }

            char left[32];
            char right[32];
            char op;

            double a[3] = {0};
            double b[3] = {0};
            double r[3] = {0};
            double n;
            int f1, f2;

            if (sscanf(rest, "%s %c %s", left, &op, right) == 3) {
                f1 = get_vector(left, a);
                f2 = get_vector(right, b);

                if (f1 && f2 && op == '+') {
                    add_vectors(a, b, r); add_vector(name, r);
                }
                else if (f1 && f2 && op == '-') {
                    sub_vectors(a, b, r); add_vector(name, r);
                }
                else if (f1 && op == '*' && sscanf(right, "%lf", &n) == 1) {
                    scalar_mult_a(a, n, r); add_vector(name, r);
                }
                else if (f2 && op == '*' && sscanf(left, "%lf", &n) == 1) {
                    scalar_mult_b(b, n, r); add_vector(name, r);
                }
                else { printf("Error: invalid expression.\n"); print_help(); continue; }

                printf("%s = %.3f %.3f %.3f\n", name, r[0], r[1], r[2]);
                continue;
            }
        }

        printf("Invalid command.\n");
        print_help();
    }

    printf("Goodbye\n");
    return 0;
}
