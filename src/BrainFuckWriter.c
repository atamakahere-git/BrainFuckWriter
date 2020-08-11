#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int nearestTen(int);
int isPlus(int);
int main()
{
    printf("Enter a string : ");
    char str[3000];
    gets(str);
    int arr[3000], count = 0;
    for (int i=0; str[i]!='\0'; i++) {
        arr[i] = str[i];
        count++;
    }
    FILE *fileptr;
    fileptr = fopen("output.bf", "w");
    fputs("Code written by BrainFuck Writer\n", fileptr);
    fputs(">++++++++++ \n", fileptr); // Setting loop counter to 10
    fputc('[', fileptr); //Loop start
    fputc('\n', fileptr);
    for (int i = 0; i <= count; i++) { // Setiing values to nearest 10th multiple corresponding ASCII for each letter
        fputc('\t', fileptr);
        int plus = nearestTen(arr[i]);
        fputc('>', fileptr);
        for (int j = 0; j < plus; j++) {
            fputc('+', fileptr);
        }
        fputc('\n', fileptr);
    }
    fputc('\t', fileptr);
    for (int i=0; i<=count; i++) { // Travelin gback to cell #1
        fputc('<', fileptr);
    }
    fputc('-', fileptr); // Decrementing loop counter
    fputc('\n', fileptr);
    fputc(']', fileptr); //Loop end
    fputc('\n', fileptr);
    for (int i = 0; i< count; i++) { // Modifying values to exact ASCII
        fputc('>', fileptr);
        if (isPlus(arr[i])) {
            for (int j=0; j< (arr[i]%10); j++) {
                fputc('+', fileptr);
            }
        }
        else {
            for (int j=0; j < 10-(arr[i]%10); j++) {
                fputc('-', fileptr);
            }
        }
        fputc('\n', fileptr);
    }
    for (int i=0; i < count; i++) { // Moving back to 1st cell
        fputc('<', fileptr);
    }
    fputc('\n', fileptr);
    for (int i=0; i < count; i++) { // Printing each letter one by one
        fputc('>', fileptr);
        fputc('.', fileptr);
    }
    fclose(fileptr);
    return 0;
}

int nearestTen(int num) {
    // this function returns the nearest 10th value
    if (num%10 > 5) {
        int numslash = num/10;
        return numslash+1;
    }
    else {
        return (num/10);
    }
}
int isPlus(int num) {
    // this function returns boolean , is the number is greater than nearest 10th or not ?
    if (num%10 > 5)
        return 0;
    return 1;

}

