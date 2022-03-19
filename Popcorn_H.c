/* DS IN C OPEN ENDED MINI PROJECT DONE BY :
1SI20CS099 SAMEER KUMAR KALYANSHETTI
1SI20CS114 SUDESH S KINI
1SI20CS101 SATHVIK K R */




#include <stdio.h>

#include <stdlib.h>

#include <string.h>

#include<ctype.h>

typedef struct node
{
    int info;
    char d[5];
    struct node *next;
} NODE;

int i, j;
int t[4];
float price = 150;
int flag;

NODE *inslast(NODE *first, int data)
{
    NODE *temp, *newnode;
    newnode = (NODE *)malloc(sizeof(NODE));
    newnode->info = data;
    strcpy(newnode->d, "|");
    newnode->next = NULL;
    if (first == NULL)
    {
        first = newnode;
    }
    else
    {
        temp = first;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newnode;
    }
    return first;
}

void display(NODE *first)
{

    NODE *temp;
    temp = first;
    while (temp != NULL)
    {
        for (i = 0; i < 10; i++)
        {
            for (j = 0; j < 10; j++)
            {
                printf("\t%s_%d_%s     ", temp->d, temp->info, temp->d);
                temp = temp->next;
            }
            printf("\n\n");
        }
    }
}

void bill(int t[], int n)
{
    int k;

    printf("\n\n\t\t\t\t\t\t\tPirates of the Caribbean : Salazar's Revenge (ENGLISH)\t\t@ 6 PM\n\n\n");

    printf("\n\t\t\t\t\t\t\tSeat numbers:\n\n");
    printf("\t\t\t\t\t\t\t");
    for (k = 0; k < n; k++)
        printf("\t%d\t", t[k]);
    printf("\n\n\t\t\t\t\t\t\tAmount  : \t\t %d x %.2f : %.2f\n", n, price, n * price);
    printf("\n\t\t\t\t\t\t\t\t\t\t\t\t + gst(10%c)\n\n",37);
    printf("\n\n\t\t\t\t\t\t\tPayable amount : %.2f\n\n", n * price + .1 * (n * price));
    printf("\n\n\t\t\t\t\t\t\tBooking confirmation has been sent your mail.\n");

    printf("\n\n\t\t\t\t\t\t\t\t....Enjoy the movie....\n\n\n");
}

NODE *update(NODE *first, int t[], int n)
{
    int c;
    NODE *temp;

    temp = first;

    while (temp != NULL)
    {
        for (c = 0; c < n; c++)
        {
            if (temp->info == t[c])
            {
                temp->info = '\0';
                strcpy(temp->d, "X");
            }
        }

        temp = temp->next;
    }

    return first;
}

int check(NODE *first, int t[], int n)
{
    int g = 0;
    // int g,sp;

    NODE *temp;
    temp = first;
    while (g < n)

    {
        temp = first;
        while (temp != NULL)
        {
            if (temp->info == t[g])
            {
                g++;
                break;
            }
            else if (temp->next != NULL)
            {
                temp = temp->next;
            }
            else
                return 1;
        }
    }
    // Alternate code....
    /*

         while (temp != NULL)
           {

               for (g = 0; g < n; g++)
               {
                   temp = first;
                   for (sp = 1; sp < t[g]; sp++)
                   {
                       temp = temp->next;
                   }
                   if (temp->info != sp)
                       return 1;
               }
           }
    */
    return 0;
}


NODE *cancel(NODE *first, int s)
{

    int pos = 1;
    NODE *temp;
    temp = first;
    while (pos < s)
    {
        temp = temp->next;
        pos++;
    }
    if (strcmp(temp->d, "X") == 0)
    {

        temp->info = pos;
        strcpy(temp->d, "|");
        flag = 1;
    }
    else
    {

        printf("\n\n\n\t\t\t\t\t\t\tInvalid seat number...\tEntered seat number is not booked...\n\n\n");
        flag = 0;
    }
    return first;
}

int main()
{
    int data, k, b = 100, n, choice, s,h=0,l;
    system("COLOR 70");
    char person[20];
    char mail[20];


    NODE *first = NULL;

    for (i = 1; i <= 100; i++)
    {
        data = i;
        first = inslast(first, data);
    }
    printf("\n\t\t\t\t\t\t\t\t**************************\n");
    printf("\t\t\t\t\t\t\t\t     POPCORN - HORIZON\n");
    printf("\t\t\t\t\t\t\t\t**************************\n\n\n");
    printf("\n\n\t\t\t\t\t\t\tCURRENT SHOW :\n");

    printf("\n\n\t\t\t\t\t\t\tPirates of the Caribbean : Salazar's Revenge (ENGLISH)\t\t@ 6 PM\n\n\n");
name:
    printf("\n\n\t\t\t\t\t\t\tEnter your name:");


    scanf("%s",person);
    printf("\n\n\t\t\t\t\t\t\tEnter your mail id:");
    scanf("%s",mail);

    while (1)
    {

        printf("\n\n\t\t\t\t\t\t\t1.DISPLAY AVAILABLE TICKETS\n\n\t\t\t\t\t\t\t2.BOOK TICKETS\n\n\t\t\t\t\t\t\t3.CANCEL TICKETS\n\n\t\t\t\t\t\t\t4.EXIT\n\n");
        printf("\n\t\t\t\t\t\t\tEnter your choice:");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("\n\n\n\t\t\t\t\t\t   ----------------------------------------------\n");
            printf("\t\t\t\t\t\t\t\t   AVAILABLE TICKETS\n");
            printf("\t\t\t\t\t\t   ----------------------------------------------\n\n\n");

            display(first);
            printf("\n\t\t\t\t\t\t\tAvailable tickets: %d\n", b);
            break;

        case 2:

            printf("\n\n\n\t\t\t\t\t\t   ----------------------------------------------\n");
            printf("\t\t\t\t\t\t\t\t   BOOKING SECTION\n");
            printf("\t\t\t\t\t\t   ----------------------------------------------\n\n\n");

            if(h==1)
            {

                printf("\n\n\t\t\t\t\t\t\tEnter your name:");


                scanf("%s",person);
                printf("\n\n\t\t\t\t\t\t\tEnter your mail id:");
                scanf("%s",mail);

            }
            display(first);
            printf("\n\n\t\t\t\t\t\t\tAvailable tickets: %d\n", b);
u:
            printf("\n\n\n\t\t\t\t\t\t\tEnter number of tickets you wish to book(MAX 5 tickets per person):");
            scanf("%d", &n);
            if (n > 5)
            {
                printf("\n\n\n\t\t\t\t\t\t\tExceeding max number of seats per person allowed to book.\n");
                goto u;
            }
GO:
            printf("\n\n\t\t\t\t\t\t\tEnter the seat numbers to book tickets:");
            for (k = 0; k < n; k++)
            {
                scanf("%d", &t[k]);

                if (t[k] > 100 || t[k] < 1)
                {
                    printf("\n\t\t\t\t\t\t\tInvalid seat number");
                    printf("\n\t\t\t\t\t\t\tTry again.\n");
                    goto GO;
                }
            }

            if (check(first, t, n) > 0)
            {
                printf("\n\n\t\t\t\t\t\t\tSome of the entered seats are already booked..\n\n\t\t\t\t\t\t\tPlease select available seats...\n\n");
                goto GO;
            }
            printf("\n\n\t\t\t\t\t\t\tTickets with seat numbers:\n");
            printf("\n\t\t\t\t\t\t\t");
            for (k = 0; k < n; k++)
                printf("\t%d\t", t[k]);
            printf("\n\t\t\t\t\t\t\t booked successfully...\n\n\t\t\t\t\t\t\tPlease proceed with payment to confirm your booking.\n");
            printf("\n\n\t\t\t\t\t\t\tPress ENTER to proceed with the payment\n\n\n");
            fflush(stdin);
            printf("\n\n\n\t\t\t\t\t\t   ----------------------------------------------\n");
            printf("\t\t\t\t\t\t\t\t   BILLING SECTION\n");
            printf("\t\t\t\t\t\t   ----------------------------------------------\n\n\n");
            for(l=0; person[l]!='\0'; l++)
                person[l]=toupper(person[l]);
            printf("\n\n\t\t\t\t\t\t\tTickets are booked under the name of %s\n\n\n\n",person);
            bill(t, n);
            first = update(first, t, n);

            display(first);
            b = b - n;
            h=1;
            break;

        case 3:
            system("COLOR 74");
            printf("\n\n\n\t\t\t\t\t\t   ----------------------------------------------\n");
            printf("\t\t\t\t\t\t\t\t   CANCELATION SECTION\n");
            printf("\t\t\t\t\t\t   ----------------------------------------------\n\n\n");
            printf("\n\t\t\t\t\t\t\tEnter the seat number you wish to cancel the booking for:");
            scanf("%d", &s);
            if (s <= 0 || s > 100)
            {

                printf("\n\n\n\t\t\t\t\t\t\tInvalid seat number\n\n\n");
            }
            else
            {
                first = cancel(first, s);
                if (flag == 1)
                    b = b + 1;
            }

            system("COLOR 70");
            break;


        case 4:
system("COLOR 02");
            printf("\n\t\t\t\t\t\t   ----------------------------------------------\n");
            printf("\t\t\t\t\t\t\t     TEAM :  RUN TIME TERROR\n");
            printf("\t\t\t\t\t\t   ----------------------------------------------\n\n\n");
            printf("\n\t\t\t\t\t\t\tDATA STRUCTURE OPEN ENDED PROJECT\n\n\n\t\t\t\t\t\t\t1SI20CS099 SAMEER KUMAR KALYANSHETTI\n\n\t\t\t\t\t\t\t1SI20CS114 SUDESH S KINI\n\n\t\t\t\t\t\t\t1SI20CS101 SATHVIK K R\n\n");
            exit(0);
        default:
            printf("\n\t\t\t\t\t\t\tInvalid choice\n");
        }
    }
    return 0;
}
