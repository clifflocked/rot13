#include <stdio.h>
#include <stdlib.h>

int main(int argc, char * argv[]) {
    if (argc == 1) {
      printf("Usage: %s WORD...\n", argv[0]);
      return 2;
    }

    for (int j = 1; j < argc; j++) { 
        int strlen = 0;

        for (int i = 0; argv[j][i] != '\0'; i++)
            strlen++;

        unsigned char * arg = (unsigned char *)calloc(1, strlen + 1);

        for (int i = 0; i <= strlen; i++)
            arg[i] = argv[j][i];

        for (int i = 0; arg[i] != '\0'; i++) {
            if (97 <= arg[i] && arg[i] <= 122) {
                arg[i] += 13;
        
                if (arg[i] > 122)
                    arg[i] -= 26;
            } else if (65 <= arg[i] && arg[i] <= 90) {
                arg[i] += 13;

                if (arg[i] > 90)
                    arg[i] -= 26;
            }

            putchar(arg[i]);
        }

        putchar(' ');

        free(arg);
    }

    putchar('\n');
}
