#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <math.h>


#define Title  "DECIMALTORADIX-iconverter"
#define AUTHOR "Mastiche Banele Banda"
#define YEAR    2022

//Runs if base does not include letters i.e base <= 9
void convertLess(int base, int deci){
    
    //local variables
    int store, counter = 1;
    char array[255], temp;
    
    printf("The radix-%d value is ", base);
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
    char array[255], temp;                  //temp = temporary;
    int remainder = 0, counter = 1;         // used to build char array

    char dictionary[32] = {'A','B', 'C', 'D', 'E', 'F', '\0' };

    printf("The radix-%d value is ", base);       
    /*Builds array*/
    while (deci >= base){
        
        remainder = deci%base;
        //if current decimal value is a multiple of base i.e remainder zero. 
        if (remainder == 0){
            sprintf(&temp, "%d", remainder);
        }

        else if (remainder < 10){
            sprintf(&temp, "%d", remainder);        //integer digit.
        }

        else if (remainder >= 10){

            temp = dictionary[remainder - 10];      //letter digit.
        }

        /* updates parameters for the next converted digit.*/
       array[counter] = temp;                   //stores converted value
       counter++;                               //counter incriment
       deci /= base;                            //updates decimal for next digit, to be converted
    }

    //if less than radix digit entered
    if (deci < 10){
        sprintf(&temp,"%d" ,deci);
    }

    else if (deci >= 10){
        temp = dictionary[deci - 10];
    }

    array[counter] = temp;                      //adds last value to counter.

    /*printing converted values from array*/
    for (int i = counter; i > 0; i--){
        printf("%c", array[i]);
    }

    printf("\n");

}

////////////////////*       Main Method        *///////////////////

int main(){
    //instance variables
    int radix,decimal, div2Int;
    float logFloat, rem, div2Float;
    

    //prints code header.
    printf("%s", "*****************************\n");
    printf("%s\n",Title);
    printf("Writtenby: %s\n", AUTHOR);
    printf("Date: 08-%d\n", YEAR);
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
        else if(radix = 10){printf("The radix-%d value is %d", radix, decimal);}
        
        /* log2 of decimal*/
        logFloat = log2f(decimal);
        
        printf("The log2 of the number is %.2f\n", logFloat);

        //dividing decimal by 2.
        div2Int = decimal/2;
        printf("The integer result of the number divided by 2 is %d\n", div2Int);
        //remainder
        div2Float = (float)decimal;
        rem = (div2Float/2) - div2Int;
        printf("The remainder is %.2f\n", rem);

        
        //restarts loop
        printf("%s", "Enter a decimal number:   ");
        scanf("%d", &decimal);
    } 
    
    //catch if decimal < 0;
    printf("%s","EXIT");
    return 0;

}

