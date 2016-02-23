//Blaise Yokoyama
//Challenge 2

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "crypto-utils.h"
#include "base64.h"

// Compile with: gcc challenge2.c base64.c crypto-utils.c -g -o challenge2

static char* sInputStr1 = "1c0111001f010100061a024b53535009181c";
static char* sInputStr2 = "686974207468652062756c6c277320657965";

static char* sOutputStr = "746865206b696420646f6e277420706c6179";


int main(int argc, char *argv[]) {

    int bytesLen1 = 0;
    char *bytes1 = hexStrToBytes(sInputStr1, &bytesLen1);
    if (!bytes1) {
        printf("Failure! Couldn't convert hex to bytes.\n");
        return 1;
    }

    int bytesLen2 = 0;
    char *bytes2 = hexStrToBytes(sInputStr2, &bytesLen2);
    if (!bytes2) {
        printf("Failure! Couldn't convert hex to bytes.\n");
        return 1;
    }	

    char *result = malloc(bytesLen1);

    for(int x = 0; x<bytesLen1;x++){
        result[x] = bytes1[x] ^ bytes2[x];
    }

    printf("%s \n", result);

    return 0;
}
