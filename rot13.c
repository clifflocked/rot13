#include <stdio.h>
#include <stdlib.h>

int main(int argc, char * argv[]) {
  if (argc == 1) {
    printf("Usage: %s WORD...\n");
    return 2;
  }

  for (int j = 1; j < argc; j++) { 
  int strlen = 0;
  for (int i = 0; argv[1][i] != '\0'; i++)
    strlen++;

    unsigned char * arg = malloc(strlen + 1);

    for (int i = 0; i <= strlen; i++)
      arg[i] = argv[1][i];

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

      printf("%c", arg[i]);
    }

    putchar(' ');

    free(arg);
  }

  putchar('\n');
}
