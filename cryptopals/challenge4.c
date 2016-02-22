//Blaise Yokoyama
//Challenge 4

//make function that takes in a hex string --> to bytes --> xor against charcter --> score decryption 

//keep track of best character

//use fscanf()

#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "crypto-utils.h"
#include "crypto-utils.c"
#include "base64.h"
#include <math.h>

// Compile with: gcc challenge4.c base64.c crypto-utils.c -g -o challenge4

#define numLines 327
#define strLen 62 //includes \n \0


int main(int argc, char *argv[]) {

//for every string input in the file, run it through this program
//scan through the file and use that string for each of these
	//score the output if you have time, then only grab the best one

  FILE* inputFile = fopen("4.txt", "r");
  FILE* outputMessages = fopen("outputMessages.txt", "w+");

  for(int i = 0; i < numLines; i++){
    char* line = ( char*) malloc(strLen);

    for(int x=0; x<strLen; x++){
        if (line[strLen-x] == '\n'){
            line[strLen-x] = '\0';
        }
    }
    char* message = decode(line);
    fputs(message, outputMessages);
    fputs("/n", outputMessages);
  }

  return 0
}

char* decode(char* hexStr){
  int bytesLen1 = 0;
    char *bytes1 = hexStrToBytes(strInput, &bytesLen1);
    if (!bytes1) {
      printf("Failure! Couldn't convert hex to bytes.\n");
      return 1;
    }
    char *result = malloc(bytesLen1);

      static double frequencyTable[26] = 
      {      
        8.617, 1.492,2.782,4.253,12.702,2.228,2.015,6.094,6.966,
        .153,.772,4.025,2.406,6.749, 7.507,1.929,.095,5.987,
        6.327,9.056,2.758,.0978,2.36,.15,1.974,.074
      };

    double topScore = 0;
    char* bestString = malloc(bytesLen1*2);
    char* bestKey = malloc(sizeof(char));// please please hold the key
    for (int x = 0; x < 128; x++) {
      char* letterCount = malloc(sizeof(char)*128);
      for(int y = 0; y<bytesLen1; y++){
        result[y] = bytes1[y] ^ (char) x;
        result[y] = tolower(result[y]);
        letterCount[result[y]] = letterCount[result[y]] + 1;
        }
      char key = (char)x; //hold this key here, for reference towards the bottom
      
      double score = 100;
      for(int x = 0; x < 26; x++){
        //for 97-122 (a-z)
        score = score - fabs(((double)letterCount[x+97]/(double)bytesLen1)*100.0 - frequencyTable[x]);
        }

      int spaceTotal = 0;
      int punctTotal = 0;
      for(int x = 0; x < 128; x++){
        if(ispunct(x)){
          punctTotal = punctTotal + letterCount[x];
        }
        if(isspace(x)){
          spaceTotal = spaceTotal + letterCount[x];
        }
      }

      double punctScore = ((double)punctTotal)/((double)bytesLen1)*100.0;
      double spaceScore = ((double)spaceTotal)/((double)bytesLen1)*100.0;

      //will exclude strings that have too much punctuation
      if(punctScore>25.0){
        score = -1;
      }
      //will exclude strings that have too much white space
      score = score - fabs(spaceScore - (1.0/6.0)*100.0);

      //will keep track of the top scoring string
      if(score>topScore){
        topScore = score;
        bestKey = key;
        for(int s = 0; s < bytesLen1; s++){
          bestString[s] = result[s];
        }
        bestString[s+1] = '\0';
      }
      }
      // for(int i = 0; i < bytesLen1; i++){
      //     printf("%c", bestString[i]);
      //   }
      printf("\n");
      printf("%c \n", bestKey); //should print out the key that was used for the best string
    return *bestString;
  }