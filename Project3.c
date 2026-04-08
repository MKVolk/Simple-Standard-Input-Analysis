/*
* Program Name: "COP 2220 Project 3: Text analyzer"
*
* Description: A program that loads and analizes strings from standard input 
*
* Author: Markos Calderon
*
* Date: November 10, 2024
*/

#include<stdio.h>
#include<ctype.h>
#include<string.h>

#define ROW 40
#define COL 80

void ArrayLoader(char array[ROW][COL], int* linesPtr);  //Loads User Input into a 2D array
int WordCounter(char array[ROW][COL],int lines);        //Analizes a 2D array and counts the number of words
int VowelCounter(char array[ROW][COL],int lines);       //Analizes a 2D array and counts the number of vowels
void ArrayPrinter(char array[ROW][COL], int lines, int words, int vowels);//Prints the results of the analysis

int main (void){
   //Declare Variables and Arrays
   char strArray[ROW][COL];
   int lines = 0; //Integer that will store the number of lines
   int words = 0; //Variable that stores the count of words
   int vowels = 0; //Stores the number of vowels
   
   ArrayLoader(strArray, &lines);
   words = WordCounter(strArray, lines);
   vowels = VowelCounter(strArray, lines);
   ArrayPrinter(strArray, lines, words, vowels);
   return 0;
}

/*
* Function Name: ArrayLoader
*
* Input Parameters: 
*       array: Character pointer type array (2D array)
*       linesPtr: Integer type pointer
*
* Description: Reads standard input into the given 2D array and updates an integer with the number of lines read
*
* Return Value: Void Type Nothing
*/
void ArrayLoader(char array[ROW][COL], int* linesPtr){
   printf("Enter in your text or EOF to quit:\n");
   for(int i=0; i < ROW; i++){
      if( (fgets(array[i], COL, stdin)) != NULL ){
         *linesPtr += 1;
      }
      int len = strlen(array[i]);
      if(len > 0 && array[i][len-1] == '\n'){
        array[i][len-1] = '\0';
      }
      if(strstr(array[i], "EOF") != NULL){ //There was no way to include ctrl+D in ZyLabs :(
        *linesPtr -= 1;
        break;
      }
   }
   return;
}

/*
* Function Name: WordCounter
*
* Input Parameters: 
*       array: Character pointer type array (2D array)
*       lines: Integer type variable
*
* Description: Scans every row of a 2D array until finding a string terminator, returns the number of words identified
*
* Return Value: Integer type number
*/
int WordCounter(char array[ROW][COL],int lines){
   int count=0;
   char lastC;
   int len=0;
   for(int i=0; i < lines; i++){
      len=strlen(array[i]);
      if(len > 0){
        lastC = array[i][0];
      }
      for(int j=0; j<=len; j++){
        if((array[i][j]==' ' || array[i][j]=='\0') && lastC != ' '){
            count++;
        }
        lastC = array[i][j];
      }
   }
   return count;
}

/*
* Function Name: VowelCounter
*
* Input Parameters: 
*       array: Character pointer type array (2D array)
*       lines: Integer type variable
*
* Description: Scans every row of a 2D array until finding a string terminator, returns the number of vowels identified
*
* Return Value: Integer type number
*/
int VowelCounter(char array[ROW][COL],int lines){
   int vowels = 0;
   char tmp = 0;
   for(int i = 0;  i < lines; i++){
      for(int j = 0; j<COL; j++){
         tmp = tolower(array[i][j]);
         if(tmp == '\0'){
            break;
         }
         if((tmp=='a')||(tmp=='e')||(tmp=='i')||(tmp=='o')||(tmp=='u')){
            vowels++;
         }
      }
   }
   return vowels;
}

/*
* Function Name: ArrayPrinter
*
* Input Parameters: 
*       array: Character pointer type array (2D array)
*       lines: Integer type variable
*       words: Integer type variable
*       vowels: Integer type variable
*
* Description: Prints a custom message about the number of words and vowels given, and some commented debugging code
*
* Return Value: Void type nothing
*/
void ArrayPrinter(char array[ROW][COL], int lines, int words, int vowels){
   
    printf("%d words and %d vowels\n", words, vowels);
   
   /* 
   //Debugging
   printf("\nWords: %d Vowels: %d\n", words, vowels);
   printf("Loaded Lines: %d\n", lines);
   for(int i = 0; i < lines; i++){
      printf("%s \n", array[i]);
   }*/
    return;
}
