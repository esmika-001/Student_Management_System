#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

void request_generators_regular()
{
    srand(time(0));
    FILE *fptr;
    fptr = fopen("waiting_queue.txt", "w");
    if (fptr == NULL)
    {
        perror("Error opening file");
        return;
    }

    for (int i = 0; i < 50; i++)
    {
        clock_t begin = clock();
        sleep(1); // Wait using sleep function
        int studentID = rand() % 100 + 1;
        int op_ID = rand() % 4;
        char str[] = "regular";
        clock_t end = clock();
        double elapsedTime = (double)(end - begin) / CLOCKS_PER_SEC;
        fprintf(fptr, "%d\t\t\t\t %d\t\t\t\t %lf\t\t\t\t%s  \n", studentID, op_ID, elapsedTime, str);
    }

    fclose(fptr);
}

void request_generators_random()
{
    srand(time(0));
    FILE *fptr;
    fptr = fopen("waiting_queue.txt", "a");
    if (fptr == NULL)
    {
        printf("Error opening file");
        return;
    }

    for (int i = 0; i < 20; i++)
    {
        clock_t begin = clock();
        int sleepTime = rand() % 3 + 1;
        sleep(sleepTime); // Wait using sleep function
        int studentID = rand() % 100 + 1;
        int op_ID = rand() % 4;
        char str[] = "random";
        clock_t end = clock();
        double elapsedTime = (double)(end - begin) / CLOCKS_PER_SEC;
        fprintf(fptr, "%d\t\t\t\t %d\t\t\t\t %lf\t\t\t\t%s  \n", studentID, op_ID, elapsedTime, str);
    }

    fclose(fptr);
}

int main()
{

    clock_t start_regular, end_regular;
    double time_regular, throughput_regular;

    clock_t start_random, end_random;
    double time_random, throughput_random;

    start_regular = clock();

    request_generators_regular();

    FILE *fp1;
    long size_regular;

    fp1 = fopen("waiting_queue.txt", "r");

    if (fp1 == NULL)
    {
        printf("File not found\n");
        return -1;
    }

    fseek(fp1, 0, SEEK_END);

    // Getting the current position of the file pointer
    size_regular = ftell(fp1);

    // Moving the file pointer back to the beginning of the file
    fseek(fp1, 0, SEEK_SET);

    printf("The size of regular request is %ld bytes\n", size_regular);

    end_regular = clock();

    time_regular = (double)(end_regular - start_regular) / CLOCKS_PER_SEC;
    throughput_regular = size_regular / time_regular;

    printf("%lf\n", throughput_regular);
    start_random = clock();
    request_generators_random();

    long size_random;

    fseek(fp1, 0, SEEK_END);

    size_random = ftell(fp1);

    printf("The size of random request is %ld bytes\n", size_random);

    fclose(fp1);

    end_random = clock();

    time_random = (double)(end_random - start_random) / CLOCKS_PER_SEC;
    throughput_random = size_random / time_random;

    printf("%lf", throughput_random);
    return 0;
}
