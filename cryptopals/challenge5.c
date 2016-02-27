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
#include "base64.h"

// Compile with: gcc challenge5.c base64.c crypto-utils.c -g -o challenge5

static char* sInputStr1 = "Burning 'em, if you ain't quick and nimble\nI go crazy when I hear a cymbal";

static char* sOutputStr = "0b3637272a2b2e63622c2e69692a23693a2a3c6324202d623d63343c2a26226324272765272"
"a282b2f20430a652e2c652a3124333a653e2b2027630c692b20283165286326302e27282f";

char* encodeWithCipher( char *inputStr, char *cipher) {
    int strLen = strlen(inputStr);
    int cipherLen = strlen(cipher);

    char *result = ( char*) malloc (strLen + 1);

    for (int x=0; x<strLen; x++){
        result[x] = inputStr[x] ^ cipher[x % cipherLen];
    }
    result[strLen] = '\0'; //must include to signal the end of the string
    return result;
}

int main(int argc, char *argv[]) {

    int bytesLen = 0;
    char *bytes = hexStrToBytes(sOutputStr, &bytesLen);
    if (!bytes) {
        printf("Failure! Couldn't convert hex to bytes.\n");
        return 1;
    }

    char *cipher = (char*) "ICE"; //unsure here
    char *result = encodeWithCipher(sInputStr1, cipher);


    int errors = 0;
    //compare output string bytes to my encoded byte string
    for(int x = 0; x<bytesLen; x++){
        if(bytes[x] != result[x]){
        errors += 1;
        }
    }
    if(errors == 0){
        printf("%s\n", "Passed the test");
    }
    printf("%s \n", result);
    free(bytes);
    free(result);
    return 0;
}