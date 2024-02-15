#include <stdio.h>

int getNum(void);

int main(void)
{

    int numbersArray[10] = {};
    int highestNumber = 0;
    int index;
    for (int i = 0; i <= sizeof(numbersArray) / sizeof(numbersArray[0]); i++)
    {
        printf("Type a number and hit Enter: ");

        int inputNumber = getNum();
        numbersArray[i] = inputNumber;

        if (inputNumber > highestNumber)
        {
            highestNumber = inputNumber;
            index = i;
        }
        else
        {
            continue;
        }
    }

    // for(int i = 0; i <= sizeof(numbersArray) / sizeof(numbersArray[0]); i++) {
    // printf("%d \n", numbersArray[i]);
    // }

    printf("The highest value is %d at index %d \n", highestNumber, index);
    return 0;
}

#pragma warning(disable : 4996) // required by Visual Studio

/* This is a function to get user input*/
int getNum(void)
{
    /* the array is 121 bytes in size; we'll see in a later lecture how we can
    improve this code */
    char record[121] = {0}; /* record stores the string */
    int number = 0;
    /* NOTE to student: brace this function consistent with your others */
    /* use fgets() to get a string from the keyboard */
    fgets(record, 121, stdin);
    /* extract the number from the string; sscanf() returns a number
     * corresponding with the number of items it found in the string */
    if (sscanf(record, "%d", &number) != 1)
    {
        /* if the user did not enter a number recognizable by
         * the system, set number to -1 */
        number = -1;
    }
    return number;
}