/*
 * FILE : f4.cpp
 * PROJECT : SENG1000 - Focus #4
 * PROGRAMMER :
 * FIRST VERSION : 2024-02-14
 * DESCRIPTION :
 * The functions in this file are used to …
 */

#include <stdio.h>

int getNum(void);

int main(void)
{

    int numbersArray[10] = {}; // Initialize array here
    int highestNumber = 0;     // Stores the current highest number
    int index;                 // Stores the index of the highest number

    printf("Type a number and hit Enter\n "); // Request for user input

    /* Loop based to fill array and check for highest number and number index */
    for (int i = 0; i <= sizeof(numbersArray) / sizeof(numbersArray[0]) - 1; i++)
    {
        int inputNumber = getNum();
        numbersArray[i] = inputNumber; // Fill the array with current input number

        /*Checks if current input number is higher than the current
        highest number*/
        if (inputNumber > highestNumber)
        {
            highestNumber = inputNumber; // Saves highest number if true
            index = i;
        }
        else
        {
            continue; // Continues with the loop if false
        }
    }

    printf("The highest value is %d at index %d \n", highestNumber, index); // print the result

    return 0;
}

#pragma warning(disable : 4996) // required by Visual Studio

//
// FUNCTION : getNum
// DESCRIPTION :
// This function gets the user input
// PARAMETERS :
// void
// RETURNS :
// int: user input
//
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