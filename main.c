#include "tree.h"
#include <stdio.h>
#include <sys/time.h>

double wtime()
{
    struct timeval t;
    gettimeofday(&t, NULL);
    return (double)t.tv_sec + (double)t.tv_usec * 1E-6;
}

int main()
{
    FILE* stream;
    char* ewords;
    struct avltree* root = NULL;
    char words[50];
    stream = fopen("output.txt", "r");
    if (stream == NULL)
    {
        printf("Ошибка: не удалось открыть файл");
        return 0;
    }

    double time_start;
    double time_end;

    time_start = wtime();
    for (int i = 0; i < 100000; i++)
    {
        ewords = fgets(words, sizeof(words), stream);
        if (ewords == NULL)
        {
            break;
        }
        root = avltree_insert(root, words, i);
        // printf("%s\n", words);
    }
    time_end = wtime() - time_start;
    printf("insert = %lf\n", time_end);

    rewind(stream);

    time_start = wtime();
    for (int i = 0; i < 100000; i++)
    {
        ewords = fgets(words, sizeof(words), stream);
        if (ewords == NULL)
        {
            break;
        }
        avltree_lookup(root, words); //Без вывода
    }
    time_end = wtime() - time_start;
    printf("lookup = %lf\n", time_end);

    rewind(stream);

    time_start = wtime();
    for (int i = 0; i < 100000; i++)
    {
        ewords = fgets(words, sizeof(words), stream);
        if (ewords == NULL)
        {
            break;
        }
        deleteNode(root, words);
    }
    time_end = wtime() - time_start;
    printf("delete = %lf\n", time_end);
}