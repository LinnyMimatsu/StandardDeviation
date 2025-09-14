/*
 * Name: Dom
 * Description: Read in a list of floating point numbers
 * of user-specified N
 * Calculate the standard deviation of the numbers.
 * Date: 09/13/25
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*Function declaration*/
int arrSize();
void standardDeviation(int arrSize);


/*main function*/
int main(void) {

    int size = arrSize();

    standardDeviation(size);

    return 0;
}

/*Asks the user to set the array size*/
int arrSize() {
    int arrSize;

    printf("Enter number of elements: ");
    scanf("%d", &arrSize);

    return arrSize;

}


/*Function calculates the average for the standard deviation and prints it
 * to the user
 */
void standardDeviation(int arrSize) {
    float avg = 0, stDeviation = 0;
    float* arr = (float*) calloc (arrSize, sizeof(float));

    for (int i = 0; i < arrSize; i++) {

        printf("Element %d: ", i + 1);
        scanf("%f", &arr[i]);

    }

    /*Calculates the average*/
    for (int i = 0; i < arrSize; i++) {
        avg += arr[i];
    }
    avg /= (float)arrSize;

    /*calculates the inside of the standard deviation*/
    for (int i = 0; i < arrSize; i++) {
    stDeviation += (float)pow(arr[i] - avg, 2);
    }

    /*calculates everything in the square root*/
    stDeviation = sqrt(stDeviation / (float)(arrSize - 1));


    printf("Standard Deviation: %.2f", stDeviation);

    /*cleans up the ram after the program is done running*/
    free(arr);
}