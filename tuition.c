#include <stdio.h>
#include <math.h>

int main (void)
{
    float tuition;
    float base;
    int idno;
    float  hours;
    int state;
    float enghours;
    float scholarship;


    state = 0;

    printf("\nEnter your valid 8 - digit ID Number: ");
    scanf("%d",&idno);
while (idno > 0 || idno < 0 )
{
    while (idno < 10000000 || idno >= 20000000)
    {
        printf("Re-enter your student ID that MUST start with a 1 and is 8 digits long:\n");
        scanf("%d", &idno);
    }
        printf("\nEnter number of credit hours: ");
        scanf("%f", &hours);

        tuition = hours * 282.00;

        printf("\nIf out of state, enter 1. If no, enter 0: ");
        scanf("%d", &state);
    

    if (state == 1)
    {
        tuition +=( 557.30 * hours);
    }
    
    printf("\nCollege of Engineering hours: ");
    scanf("%f", &enghours);

    tuition += (enghours * 90.00);

    printf("\nScholarship money (if no scholarship granted, enter 0): $");
    scanf("%f", &scholarship);
    
    while (scholarship > tuition)
    {
        printf("\nScholarship cannot exceed tuition total.");
        printf("\nScholarship money: $");
        scanf("%f",&scholarship);
    }
    
    base = tuition; 

    tuition -= scholarship;

    printf("\n*****TUITION STATEMETMENT*****\n");
   
    printf("Student ID: %d", idno);
    printf("\nCredit Hours: %.2f\n", hours);
   
    printf("\n*****");
   
    printf("\nBase Tuition: $%.2f\n", base);
    printf("\nScholarships/Grants: $%.2f\n", scholarship);

    printf("\n*****");

    printf("\nTUITION GRAND TOTAL: $%.2f\n", tuition);
    
    return 0;
}

    printf("\n**PROGRAM OVAAAAA**\n");

    return 0;

}
