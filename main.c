#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

bool validatePadding(unsigned char string[], unsigned char** result, int* numberOfBytesWritten){
    int stringLength = strlen(string);

    int BLOCK_SIZE = 16;
    int paddingLength = 0;
    if(stringLength % BLOCK_SIZE != 0){
        return false;
    }

    int numberOfPaddingBytes = string[stringLength-1];
    int bytesRead = 0;
    for(int i=0;i<numberOfPaddingBytes;i++){
        if(string[stringLength-i-1] == numberOfPaddingBytes){
            bytesRead++;
        }
    }

    
    if(bytesRead == numberOfPaddingBytes){
        (*numberOfBytesWritten) = stringLength-numberOfPaddingBytes;
        unsigned char* tmpResult = calloc(*numberOfBytesWritten,sizeof(unsigned char));
        for(int i=0;i<stringLength-numberOfPaddingBytes;i++){
            tmpResult[i] = string[i];
        }
        (*result) = tmpResult;
    }
    
    return bytesRead == numberOfPaddingBytes;
}
