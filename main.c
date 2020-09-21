#include <stdio.h>
#include <math.h>
float countStep(float startInterval, float endInterval, float countParts);

void createTableWithFor(float startInterval,float endInterval, float step);
void createTableWithWhile(float startInterval,float endInterval, float step);
void createTableWithDoWhile(float startInterval,float endInterval, float step);

float countValue(float value);

void printTableResults(float value, float reply);
void printNone(float value);
void printBottomTable();


int main()
{
    float startInterval;
    float endInterval;
    float countParts;

    printf("Please, insert the begin and end of the gap and count parts\n");
    scanf("%f%f%f", &startInterval, &endInterval, &countParts);

    if ((startInterval < endInterval) && (countParts > 0))
    {
        float step = countStep(startInterval, endInterval, countParts);
        printf("This table using a cycle 'FOR'\n");
        createTableWithFor(startInterval, endInterval, step);
        printBottomTable();
        printf("This table using a cycle 'WHILE'\n");
        createTableWithWhile(startInterval, endInterval, step);
        printBottomTable();
        printf("This table using a cycle 'DOWHILE'\n");
        createTableWithDoWhile(startInterval, endInterval, step);
        printBottomTable();
    }
    else
    {
        printf("The program does not work with incorrect data");
    }
}

float countStep(float startInterval, float endInterval, float countParts)
{
    return (endInterval - startInterval)/countParts;
}

void createTableWithFor(float startInterval,float endInterval, float step)
{
    for (float value = startInterval; value <= endInterval; value += step)
    {
        if (value != 0)
        {
            float reply = countValue(value);
            printTableResults(value, reply);
        }
        else
        {
            printNone(value);
        }
    }
}

void createTableWithWhile(float startInterval,float endInterval, float step){
    float value = startInterval;
    while (value <= endInterval)
    {
        if (value != 0)
        {
            float reply = countValue(value);
            printTableResults(value, reply);
        }
        else
        {
            printNone(value);
        }
        value+=step;
    }
}

void createTableWithDoWhile(float startInterval,float endInterval, float step){
    float value = startInterval;
    do
    {
        if (value != 0)
        {
            float reply = countValue(value);
            printTableResults(value, reply);
        }
        else
        {
            printNone(value);
        }
        value+=step;
    }
    while (value <= endInterval);
}

float countValue(float value)
{
    return (sin(value)*sin(value))/value;
}

void printTableResults(float value, float reply)
{
    printf("+------------+------------+\n");
    printf("| %10.3f | %10.3f |\n", value, reply);
}

void printNone(float value)
{
    printf("+------------+------------+\n");

    printf("| %10.3f |    NONE    |\n", value);
}

void printBottomTable()
{
    printf("+------------+------------+\n");
}
