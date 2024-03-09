#include "include/header.h"

// int main(int argc, char *argv[])
// {
//     FILE *fbuff = readf(fbuff, argv[1]); char buffer[buffmax]; unsigned int line = 1;
    

//     if(argc != 2) usage(argv[1]);

//     while (fgets(buffer, buffmax, fbuff))
//     {
//         printf("line%d: ", line++);


//     }

//     fclose(fbuff);

//     exit(0);
//     return 0;
// }



int main(void) {
    Flux file = optimizeFile("flux/main.fx", false);

    printf("\n\nfile : %s", file.buffer);

    writeFile("flux/main.opt.fx", file);
    free(file.buffer);
    return 0;
}

// #include <stdio.h>
// int main()
// {
//     int c;
//     while ((c = getchar()) != EOF)
//         putchar(c);
// }