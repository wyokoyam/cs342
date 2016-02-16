//Blaise Yokoyama
//challenge 5

//we're trying to encode something here
//important to be able to put into bytes, then xor, then put back into hex for final encoded string

//figure out how to do bytes to hex

//use modulo to do every 3rd for ICE

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "crypto-utils.h"
#include "crypto-utils.c"
#include "base64.h"

// Compile with: gcc challenge5.c base64.c crypto-utils.c -g -o challenge5

static char* sInputStr1 = "Burning 'em, if you ain't quick and nimble I go crazy when I hear a cymbal";

static char* sOutputStr = "0b3637272a2b2e63622c2e69692a23693a2a3c6324202d623d63343c2a26226324272765272
a282b2f20430a652e2c652a3124333a653e2b2027630c692b20283165286326302e27282f";


int main(int argc, char *argv[]) {

/**
  int bytesLen1 = 0;
  char *bytes1 = hexStrToBytes(sInputStr1, &bytesLen1);
  if (!bytes1) {
    printf("Failure! Couldn't convert hex to bytes.\n");
    return 1;
  }
 **/

  char *string = (char) sInputStr1;
  int bytesLen = strlen(sInputStr1);
  char *cipher = (char) "ICE"; //unsure here
  char *result = malloc(sInputStr1);

  for(int x = 0; x<;x++){
  	result[x] = string[x] ^ cipher[(x+3)%3];
  }

  printf("%s \n", result);

  return 0;
}