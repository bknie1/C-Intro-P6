#include <stdio.h>
#include <math.h>

#define MIN_SCORE 1
#define MAX_SCORE 100
#define MIN_STUDENTS 1
#define MAX_STUDENTS 25
#define MIN_ID 1
#define MAX_ID 99999999

/*
    module      :   gradesknieriem.c
    Description :   Student Grades Calculator
    Author      :   Brandon Knieriem
    Rev History :

    Date        Comment
    ----        -------
    10/4        Program creation.
    10/6        Added comments so I can remember what I did.

    Notes:
    ------

 */

/*Declaration of Variables*/
int u = NULL, i = NULL, n = NULL; // User Input, ID, Number of Students
int studentid[MAX_STUDENTS] = {0};
float studentscore[MAX_STUDENTS] = {0};

/*Declaration of Functions*/
int fnReadStudentScore(int id[], float score[]);                            // Prototype variable name does not matter! It only cares about the type of input.
void fnPrintStudentScore(int studentid[], float studentscore[], int n);     // See?
void fnPrintTotalsCore(float y[], int n);
void fnPrintClassAverage(float score[], int n);
void fnFindStudent(int id[], float score[], int n);
void fnSortArray(int id[], float score[], int n);


int main(void)
{
    do
    {
        printf("\n      STUDENT GRADES\n");
        printf("NOTE: MIN SCORE = 1, MAX SCORE = 100, MIN STUDENTS = 1, MAX STUDENTS = 25\n\n");
        printf("1.  Read Student Score\n");
        printf("2.  Print Student Scores\n");
        printf("3.  Print Total Score\n");
        printf("4.  Print Class Average\n");
        printf("5.  Find Student\n");
        printf("6.  Quit\n\n");

        printf("Select: ");
        scanf("%i", &u);

        if (u == 1 || u == 2 || u == 3 || u == 4 || u == 5)
        {
            switch(u)
            {
                case 1 :                                          // Read Student Score
                {
                printf("        READ STUDENT SCORE\n\n");
                n = fnReadStudentScore(studentid, studentscore);  // The call tells the function what's being transferred in. You must use the appropriate variable name here!
                break;
                }

                case 2 :                                          // Print Student Score
                {
                printf("        PRINT STUDENT SCORE\n\n");
                fnPrintStudentScore(studentid, studentscore, n);
                fnSortArray(studentid, studentscore, n);
                break;
                }

                case 3 :                                          // Print Total Score
                {
                printf("        PRINT TOTAL SCORE\n\n");
                fnPrintTotalScore(studentscore, n);
                break;
                }

                case 4 :                                          // Print Class Average
                {
                printf("        PRINT CLASS AVERAGE\n\n");
                fnPrintClassAverage(studentscore, n);
                break;
                }

                case 5 :                                          // Find Student
                {
                printf("        FIND STUDENT\n\n");
                fnFindStudent(studentid, studentscore, n);
                break;
                }

                case 6 :                                         // Closing Program
                {
                printf("\n     CLOSING PROGRAM ...\n\n");
                break;
                }

                default :                                       // Invalid Input Error
                {
                printf("ERROR: Invalid input.\n\n");
                break;
                }
            }
        }
    }
    while (u != 6); // Exits program if user selects '6'.

    return 0;
}

int fnReadStudentScore(int id[], float score[]) // You don't have to use the actual variable name here. The names used here are only used in the function.
{
    int i = 0;       // ID
    float s = 0.00;  // Score
    int n = 0;       // Number of Students in Class
    int c = 0;       // Counter

    printf("Class size: ");
    scanf("%i", &n);

    if(n >= MIN_STUDENTS && n <= MAX_STUDENTS)
    {
        for(c = 0; c < n; ++c)
        {
            printf("\nPlease assign a Student ID (Max: 8 digits): ");
            scanf("%i", &id[i]);

            if (id[i] >= MIN_ID && id[i] <= MAX_ID)
            {
                printf("\nPlease enter a score for Student #%i: ", id[i]);
                scanf("%f", &s);
                if (s >= MIN_SCORE && s <= MAX_SCORE)
                {
                    score[i] = s;
                    i += 1;
                }
                else
                {
                    printf("\nERROR: Invalid score. Score must be greater than 0. \n\n");
                }
            }
            else
            {
                printf("\nERROR: Invalid ID #.\n\n");
            }
        }
    }
    else
    {
        printf("\nERROR: Invalid class size.\n\n");
    }
    return n; // Returns the # of students to the main program.
}

void fnPrintStudentScore(int id[], float score[], int n)
{
    for (i = 0; i < n; ++i)
    {
        if (score[i] >= MIN_SCORE && score[i] <= MAX_SCORE) // Only prints valid scores.
        {
            printf("    ID #: %i        ", id[i]);
            printf("Score: %.2f\n", score[i]);
        }
    }
}

void fnPrintTotalScore(float score[], int n)
{
    float total = 0;

    for(i = 0; i < n; ++i)
    {
        if (score[i] >= MIN_SCORE && score[i] <= MAX_SCORE) // Only adds valid scores.
        {
        total += score[i];
        }
    }
    printf("The class total is: %10.2f\n\n", total);
}

void fnPrintClassAverage(float score[], int n)
{
    float total = 0, average = 0;
    int a = 0;
    for(i = 0; i < n; ++i)
    {
        if (score[i] >= MIN_SCORE && score[i] <= MAX_SCORE) // Only adds valid scores.
        {
        total += score[i];
        ++a;
        }
    }
    average = total / a;

    printf("Score Total: %.2f\n", total);
    printf("Scores Recorded: %i\n", a);
    printf("Class Average: %.2f\n", average);
}

void fnFindStudent(int id[], float score[], int n)
{
    int i = 0; // ID #
    int c = 0; // Counter

    printf("Search Student ID #: ");
    scanf("%i", &i);
    if (i >= MIN_ID && i <= MAX_ID)
    {
        for(c = 0; c < n; ++c)
        {
            if (i == id[c])
            {
                printf("\nStudent ID #: %i      Score: %.2f\n\n", id[c], score[c]);
                break;
            }
        }
    }
    else
    {
        printf("\nERROR: Invalid ID #.\n\n");
    }
}

void fnSortArray(int id[], float score[], int n)
{
    int e = 0, i = 0, d = 0, tid = 0;
    float ts = 0;

    e = n;

    for (i = 1; i < e; i++)                // i = 1, continues while the integer's array location is less than the # of elements, i + 1 to move up in the array.
    {
        d = i;                                  // d copies the integer locations.
        while ( d > 0 && id[d] < id[d-1])       // Runs until d hits 0. If d is smaller than what it's being compared to it gets swapped. Otherwise it retrieves the next number.
        {
            tid = id[d];                          // Copies the array content to a temp variable.
            id[d] = id[d-1];
            id[d-1] = tid;

            ts = score[d];
            score[d] = score[d-1];
            score[d-1] = ts;

            d--;
        }
    }
    printf("\n\n    Sorted List: \n");

    for (i = 0; i < n; i++)
    {
        printf("    ID #: %i        ", id[i]);
        printf("Score: %.2f\n", score[i]);
    }
}
