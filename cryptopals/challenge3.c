//Blaise Yokoyama
//Challenge 3

//Trying to XOR a string with a single character

#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "crypto-utils.h"
#include "crypto-utils.c"
#include "base64.h"

// Compile with: gcc challenge3.c base64.c crypto-utils.c -g -o challenge3

static char* sInputStr1 = "1b37373331363f78151b7f2b783431333d78397828372d363c78373e783a393b3736";

int main(int argc, char *argv[]) {

  int bytesLen1 = 0;
  char *bytes1 = hexStrToBytes(sInputStr1, &bytesLen1);
  if (!bytes1) {
    printf("Failure! Couldn't convert hex to bytes.\n");
    return 1;
  }

  char *result = malloc(bytesLen1);

  //XOR against bytes, must convert all ascii values of hex possibilities to bytes
  //worried about memory here?
  //really unsure from here down

  int topScore = 0;
  for (int x = 0; x < 127; x++) {
    printf("%d = %c\n", x, x);
    for(int y = 0; y<bytesLen1; y++){
    	result[y] = bytes1[y] ^ (char) x;
    }
    printf("%s \n", result); 

    int score = 0;
    int i=0;
  	char str[]= *result;
  	char c;
  	while (str[i]){
    c=str[i];
    putchar (tolower(c));
    if(c == 101){
    	score += 12;
    }
    if(c == 116){
    	score += 9;
    }
    i++;
  	}

  	printf("%d\n", score);
    if(score > topScore){
    	topScore = score;
    	printf("%s\n", result);
    	printf("%f\n", topScore);
    	}
  	}
  	printf("%d\n", topScore);	
  return 0;
}
