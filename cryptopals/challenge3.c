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

    static double frequencyTable[26] = 
    {      
      8.617, 1.492,2.782,4.253,12.702,2.228,2.015,6.094,6.966,
      .153,.772,4.025,2.406,6.749, 7.507,1.929,.095,5.987,
      6.327,9.056,2.758,.0978,2.36,.15,1.974,.074
    }


  double topScore = 0;
  char bestString = malloc(result);
  for (int x = 0; x < 128; x++) {
    //printf("%d = %c\n", x, x);
    char* letterCount = 128;
    for(int y = 0; y<bytesLen1; y++){
    	result[y] = bytes1[y] ^ (char) x;
      result[y] = tolower(result[y]);
      letterCount[result[y]] = letterCount[result[y]] + 1;
      }
    
    double score = 100;
    for(int x = 0; x < 26; x++){
      //for 97-122 (a-z)
      score = score - fabs((letterCount[x+97]/bytesLen1)*100 - frequencyTable[x]);
      }
    if(score>topScore){
      topScore = score;
      bestString = result
    }
    printf("%s \n", result, score);
    }
    //printf("%s \n", result);


    


  }
  return 0;
}
