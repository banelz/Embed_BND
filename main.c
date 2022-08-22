#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <math.h>


//Runs if base does not include letters i.e base <= 9
void convertLess(int base, int deci){
    
    //local variables
    int store, counter = 1;
    char array[255], temp;
    
    //populating decimal to base equivalent array.
    while (base <= deci)
    {
        store = deci%base;                  //radix = remainder * base , first value stored at index 1 instead of 0.
        sprintf(&temp, "%d", store);        //formats and temporarily stores digit
        array[counter] = temp;              //stores digit to char array
        deci /= base;                       //new decimal to be used for next
        counter++;                          //increments counter, also used as final digit pointer.
    }

    sprintf(&temp, "%d", deci);             //formats and temporarily stores last digit.
    array[counter] = temp;                  //stores last digit to char array

    /*Inverts and prints char array i.e new base equivalent value*/
    for (int i = counter+1; i > 0; i--){
        printf("%c", array[i]);
    }         
    printf("\n");

}

//Runs if base is larger than 10 i.e includes letters
void convertMore(int base, int deci){
    //local variables
    int store, counter = 1;
    char array[255], temp;
    
    //populating decimal to base equivalent array.
    while (base <= deci)
    {
        store = deci%base;                  //radix = remainder * base , first value stored at index 1 instead of 0.
        sprintf(&temp, "%d", store);        //formats and temporarily stores digit
        array[counter] = temp;              //stores digit to char array
        deci /= base;                       //new decimal to be used for next
        counter++;                          //increments counter, also used as final digit pointer.
    }

    sprintf(&temp, "%d", deci);             //formats and temporarily stores last digit.
    array[counter] = temp;                  //stores last digit to char array

    /*Inverts and prints char array i.e new base equivalent value*/
    for (int i = counter+1; i > 0; i--){
        printf("%c", array[i]);
    }
    printf("\n");

}

////////////////////*       Main Method        *///////////////////

int main(){
    //instance variables
    int radix,decimal;
    float result;
    char *dictionary[6] = {"A", "B", "C", "D", "E", "F"};



    //prints code header.
    printf("%s", "*****************************\n");
    printf("%s", "DECIMALTORADIX-iconverter\n");
    printf("%s", "Writtenby: Mastiche Banele Banda\n");
    printf("%s", "Date: 08-2022\n");
    printf("%s", "*****************************\n");

    //initial loop  (runs once):
    printf("%s", "Enter a decimal number:   ");
    scanf("%d", &decimal);

    //try: while loop if decimal >= 0. else catch and terminate;
    while(decimal >= 0){
        printf("The number you have entered is %d\n", decimal);
        printf("%s", "Enter a radix for the converter between 2 and 16: ");
        scanf("%d", &radix);
        printf("The radix you have entered is %d\n", radix);

        /* start coding here(run methods)*/
        //if larger than 9 convertMore(int int)
        if (radix > 10){convertMore(radix, decimal);}
        else if(radix < 10){convertLess(radix, decimal);}
        else if(radix = 10){}
        

        printf("The log2 of the number is %f\n", log2f(decimal));
        int result = decimal/2;
        printf("The integer result of the number divided by 2 is %d\n", result);

        
        //restarts loop
        printf("%s", "Enter a decimal number:   ");
        scanf("%d", &decimal);
    } 
    
    //catch if decimal < 0;
    printf("%s","EXIT");
    return 0;

}

