#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_STUDENTS 100

typedef struct
{
    char firstName[20];
    char lastName[20];
    char hostelName[20];
    char course[10];
    int roomNumber;
    char dateOfBirth[11];
    int yearOfStudy;
} Student;

Student students[MAX_STUDENTS];
static int sco = 0;
static int sc = 0;
struct list
{
    char *string;
    struct list *next;
};
typedef struct list MainMemory;

// linked list when the memory is increased (link list of 6 nodes)
/*
int sixlink(int n)
{
    FILE *fptr;
    char line[128];
    MainMemory *current, *head;

    head = current = NULL;
    fptr = fopen("test.txt", "r");

    while (fgets(line, sizeof(line), fptr))
    {
        if (sc == 6)
        {
            current->next = head;
        }
        if (n)
        {
            MainMemory *node = malloc(sizeof(MainMemory));
            node->string = strdup(line);
            node->next = NULL;
            sco++;

            if (head == NULL)
            {
                current = head = node;
            }
            else
            {
                current = current->next = node;
            }
        }
    }
    fclose(fptr);

    for (current = head; current; current = current->next)
    {
        printf("%s", current->string);
    }
    return 0;
}
*/
// linked list when the memory is increased (link list of 9 nodes)
/*
int nlink(int n)
{
    FILE *fptr;
    char line[128];
    MainMemory *current, *head;

    head = current = NULL;
    fptr = fopen("test.txt", "r");

    while (fgets(line, sizeof(line), fptr))
    {
        if (sc == 9)
        {
            current->next = head;
        }
        if (n)
        {
            MainMemory *node = malloc(sizeof(MainMemory));
            node->string = strdup(line);
            node->next = NULL;
            sco++;

            if (head == NULL)
            {
                current = head = node;
            }
            else
            {
                current = current->next = node;
            }
        }
    }
    fclose(fptr);

    for (current = head; current; current = current->next)
    {
        printf("%s", current->string);
    }
    return 0;
}
*/
// entering data in link list of 5 nodes

int listlinked(int n)
{
    FILE *fptr;
    char line[128];
    MainMemory *current, *head;

    head = current = NULL;
    fptr = fopen("test.txt", "r");

    while (fgets(line, sizeof(line), fptr))
    {
        if (sco == 5)
        {
            current->next = head;
        }
        if (n)
        {
            MainMemory *node = malloc(sizeof(MainMemory));
            node->string = strdup(line);
            node->next = NULL;
            sco++;

            if (head == NULL)
            {
                current = head = node;
            }
            else
            {
                current = current->next = node;
            }
        }
    }
    fclose(fptr);

    for (current = head; current; current = current->next)
    {
        printf("%s", current->string);
    }
    return 0;
}

// registration function

void registration(int student_id)
{
    FILE *fptr1, *fptr2, *fptr3, *fptr4, *fptr5;
    fptr1 = fopen("first.txt", "r");
    fptr2 = fopen("last.txt", "r");
    fptr3 = fopen("hostel.txt", "r");
    fptr4 = fopen("course.txt", "r");
    fptr5 = fopen("disk.txt", "a");

    if (fptr1 == NULL || fptr2 == NULL || fptr3 == NULL || fptr4 == NULL || fptr5 == NULL)
    {
        printf("The file is not opened. The program will now exit.");
        exit(0);
    }
    char first[20][100], last[20][100], hostel[5][10], course[5][10];
    for (int i = 0; i < 20; i++)
    {
        fscanf(fptr1, "%s", first[i]);
    }
    for (int i = 0; i < 20; i++)
    {

        fscanf(fptr2, "%s", last[i]);
    }
    for (int i = 0; i < 5; i++)
    {
        fscanf(fptr3, "%s", hostel[i]);
    }
    for (int i = 0; i < 5; i++)
    {

        fscanf(fptr4, "%s", course[i]);
    }

    srand(time(0));
    int arr1[100] = {0};
    int arr2[200] = {0};

    int a, b, c, d, e, f, g, date, month, year;
    a = rand() % 20;
    b = rand() % 20;
    c = rand() % 5;
    d = rand() % 5;
    e = rand() % 100;
    f = rand() % 8;
    g = rand() % 200;
    date = rand() % 28;
    month = rand() % 12;
    year = rand() % 8;
    while (arr1[e] != 0)
    {
        e = rand() % 100;
    }
    arr1[e]++;
    while (arr2[g] != 0)
    {
        g = rand() % 200;
    }
    arr2[g]++;
    fprintf(fptr5, "%d\t\t\t%s\t\t%s\t\t\t%s\t\t%s\t\t\t%d\t\t%d\t\t%d/%d/%d\n", e + 1, first[a], last[b], hostel[c], course[d], f + 2016, g + 1, date + 1, month + 1, year + 1998);
}

// search function
int search_l(int req_id)
{
    FILE *fptr;
    int n = 0;
    int i = 0;
    fptr = fopen("disk.txt", "r+");
    if (fptr == NULL)
    {
        printf("The file is not opened. The program will now exit.");
        exit(0);
    }
    char string[500];
    fgets(string, 500, fptr);
    n++;

    int flag = 0;
    char id[5];
    while (!flag)
    {
        i = 0;
        fgets(string, 500, fptr);
        n++;
        char test = string[i];

        while (test != '\t')
        {

            id[i++] = test;
            test = string[i];
        }
        id[i] = '\0';
        if (req_id == atoi(id))
        {
            puts(string);
            flag = 1;
        }
    }
    fclose(fptr);
    listlinked(n);
    //  sixlink(n);
     //  nlink(n);
    return n;
}

// update funtion
void update(int req_id)
{
    FILE *file;
    int n = 0;
    int i = 0;
    file = fopen("disk.txt", "r+");
    if (file == NULL)
    {
        printf("The file is not opened. The program will now exit.");
        exit(0);
    }
    char line[500];
    char id[10];
    i = 0;
    while (fgets(line, sizeof(line), file))
    {
        char test = line[i];
        while (test != '\t')
        {
            id[i++] = test;
            test = line[i];
        }
        id[i] = '\0';
        if (req_id == atoi(id))
        {
            int spaceCount = 0;
            int position = 0;

            for (int i = 0; i < strlen(line); i++)
            {
                if (line[i] == ' ')
                {
                    spaceCount++;
                    if (spaceCount == 15)
                    {
                        position = i + 1;
                        break;
                    }
                }
            }
            srand(time(0));
            int r = rand() % 200 + 1;
            if (position > 0 && position + 3 <= strlen(line))
            {
                fseek(file, position, SEEK_CUR);
                fprintf(file, "%d", r);
            }
            break;
        }
    }
    listlinked(req_id);
    // sixlink(req_id);
     // nlink(req_id);
}

// delete function
void delete(int student_id, const char *diskname)
{
    char studentDetail[500];

    FILE *disk = fopen("disk.txt", "r");
    // Temporary file to write modified content
    FILE *output = fopen("temp.txt", "a");

    if (disk == NULL || output == NULL)
    {
        perror("File opening failed");
        exit(EXIT_FAILURE);
    }
    char buffer[500];
    int current_line = 0;
    // while (fgets(buffer, sizeof(string), disk) != NULL) {
    // current_line++;

    while ((fgets(buffer, 500, disk)) != NULL)
    {
        strcpy(studentDetail, buffer);
        current_line++;
        // first word of line is student_id in disk file
        char *token = strtok(buffer, "\t");
        if (atoi(token) != student_id)
        {
            // copying data of other students in temp file
            fputs(studentDetail, output);
        }
    }
    fclose(disk);
    fclose(output);

    // Replace the original file with modified content
    remove(diskname);
    rename("temp.txt", diskname);
}

// server function
void server(int operation_id, int student_id, FILE *disk)
{

    switch (operation_id)
    {
    case 0:
        registration(student_id);
        break;
    case 1:
        search_l(student_id);
        break;
    case 2:
        update(student_id);
        break;
    case 3:
    {
        const char *diskname = "disk.txt";
        delete (student_id, diskname);
        break;
    }
    default:
        printf("Invalid operation ID.\n");
        break;
    }
}

int main()
{
    FILE *fptr1, *fptr2, *fptr3, *fptr4, *fptr5;
    fptr1 = fopen("first.txt", "r");
    fptr2 = fopen("last.txt", "r");
    fptr3 = fopen("hostel.txt", "r");
    fptr4 = fopen("course.txt", "r");
    fptr5 = fopen("disk.txt", "w");

    if (fptr1 == NULL || fptr2 == NULL || fptr3 == NULL || fptr4 == NULL || fptr5 == NULL)
    {
        printf("The file is not opened. The program will now exit.");
        exit(0);
    }
    char first[20][100], last[20][100], hostel[5][10], course[5][10];
    for (int i = 0; i < 20; i++)
    {
        fscanf(fptr1, "%s", first[i]);
    }
    for (int i = 0; i < 20; i++)
    {

        fscanf(fptr2, "%s", last[i]);
    }
    for (int i = 0; i < 5; i++)
    {
        fscanf(fptr3, "%s", hostel[i]);
    }
    for (int i = 0; i < 20; i++)
    {

        fscanf(fptr4, "%s", course[i]);
    }
    // generating random outputs
    srand(time(0));
    int arr1[100] = {0};
    int arr2[200] = {0};

    for (int i = 0; i < 100; i++)
    {
        int a, b, c, d, e, f, g, date, month, year;
        a = rand() % 20;
        b = rand() % 20;
        c = rand() % 5;
        d = rand() % 5;
        e = rand() % 100;
        f = rand() % 8;
        g = rand() % 200;
        date = rand() % 28;
        month = rand() % 12;
        year = rand() % 8;
        while (arr1[e] != 0)
        {
            e = rand() % 100;
        }
        arr1[e]++;
        while (arr2[g] != 0)
        {
            g = rand() % 200;
        }
        arr2[g]++;
        fprintf(fptr5, "%d\t\t\t%s\t\t%s\t\t\t%s\t\t%s\t\t\t%d\t\t%d\t\t%d/%d/%d\n", e + 1, first[a], last[b], hostel[c], course[d], f + 2016, g + 1, date + 1, month + 1, year + 1998);
    }

    fclose(fptr1);
    fclose(fptr2);
    fclose(fptr3);
    fclose(fptr4);
    fclose(fptr5);

    FILE *fp;
    char line[100];
    int stud_id, op_id;
    char str[10];
    char *token;

    fp = fopen("waiting_queue.txt", "r");

    if (fp == NULL)
    {
        printf("File not found\n");
        return -1;
    }

    // clock function to measure the execution time
    clock_t begin = clock();
    while (fgets(line, sizeof(line), fp) != NULL)
    {
        token = strtok(line, "\t\t\t\t");
        stud_id = atoi(token);
        token = strtok(NULL, "\t\t\t\t");
        op_id = atoi(token);
        server(op_id, stud_id, fp);
    }
    clock_t end = clock();
    double elapsedTime = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("\n%lf\n", elapsedTime);

    fclose(fp);
}
