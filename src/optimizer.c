#include "../include/header.h"

char *readFile(char *fileName)
{
    FILE *file = fopen(fileName, "r");
    char *rawfile;
    size_t n = 0;
    int c;

    if (file == NULL)
        return NULL; // could not open file
    fseek(file, 0, SEEK_END);
    long f_size = ftell(file);
    fseek(file, 0, SEEK_SET);
    rawfile = malloc(f_size);

    while ((c = fgetc(file)) != EOF)
    {
        rawfile[n++] = (char)c;
    }

    rawfile[n] = '\0';

    return rawfile;
}

void writeFile(char *filename, Flux file) {
    FILE *fptr;

    // use appropriate location if you are using MacOS or Linux
    fptr = fopen(filename, "w");
    printf("\n\ncontent: %s", file.buffer);
    if (fptr == NULL)
    {
        printf("Error!");
        exit(1);
    }


    fprintf(fptr, "%s", file.buffer);
    fclose(fptr);

    return;
}
    

Flux optimizeFile(char *filename, bool whitespace) {
    FILE *file = fopen(filename, "r");
    char *rawfile;
    size_t n = 0; int c;
    Flux err = {NULL, 0};

    if (file == NULL) {
        return err; // could not open file
    }
    fseek(file, 0, SEEK_END);
    long f_size = ftell(file);
    fseek(file, 0, SEEK_SET);
    rawfile = malloc(f_size);
    

    if(whitespace) {
        while ((c = fgetc(file)) != EOF)
        {
            // printf("[%c %d]", (char)c,c);
            //  32: space
            //  10: newline
            //  11: vt
            if (c > 32 && c < 126)
                rawfile[n++] = (char)c;
            else
            {
                int x = (int)rawfile[n - 1];
                if (x > 32)
                {
                    rawfile[n++] = (char)32;
                }
            }
        }
    } else {
        while ((c = fgetc(file)) != EOF)
        {
            if (c > 32 && c < 126)
                rawfile[n++] = (char)c;
        }
    }
    
    //printf("%d %d ????", f_size, n);

    rawfile[n++] = '\0';

    for (size_t i = n; i < f_size; i++)
    {
        //printf("index: %d", i);
        rawfile[i] = (int) 0;
    }
    
    char *optimized = realloc(rawfile, (n) * sizeof(int));


    if (optimized == NULL) return err;

    // for (size_t i = 0; i < n; i++)
    // {
    //     printf("%d:%d ", i, optimized[i]);
    // }

    Flux f = { optimized, n};
    return f;
}
