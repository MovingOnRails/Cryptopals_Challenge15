#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>

#include "./main.c"

int main(){
    //------------------------------------------------------------------------------------------
    printf("------------------------------------------\n");
    unsigned char* validPadding = "ICE ICE BABY\x04\x04\x04\x04\0";
    int tmp = 0;
    unsigned char* result = NULL;
    bool test1 = validatePadding(validPadding,&result,&tmp);
    assert(test1 == true);
    for(int i=0;i<tmp;i++){
        printf("%c",result[i]);
    }
    printf("\n");
    free(result);
    //------------------------------------------------------------------------------------------
    unsigned char* invalidPadding1 = "ICE ICE BABY\x05\x05\x05\x05\0";
    bool test2 = validatePadding(invalidPadding1,NULL,&tmp);
    assert(test2 == false);
    //------------------------------------------------------------------------------------------
    unsigned char* invalidPadding2 = "ICE ICE BABY\x01\x02\x03\x04\0";
    bool test3 = validatePadding(invalidPadding2,NULL,&tmp);
    assert(test2 == false);
    //------------------------------------------------------------------------------------------
    printf("------------------------------------------\n");
    unsigned char* validPadding2 = "ICE ICE BAB\x05\x05\x05\x05\x05\0";
    result = NULL;
    bool test4 = validatePadding(validPadding2,&result,&tmp);
    assert(test4 == true);
    for(int i=0;i<tmp;i++){
        printf("%c",result[i]);
    }
    printf("\n");
    //------------------------------------------------------------------------------------------
    printf("------------------------------------------\n");
    unsigned char* validPadding3 = "ICE ICE BA\x06\x06\x06\x06\x06\x06\0";
    result = NULL;
    bool test5 = validatePadding(validPadding3,&result,&tmp);
    assert(test5 == true);
    for(int i=0;i<tmp;i++){
        printf("%c",result[i]);
    }
    printf("\n");
    //------------------------------------------------------------------------------------------
    printf("------------------------------------------\n");
    unsigned char* validPadding4 = "I\15\15\15\15\15\15\15\15\15\15\15\15\15\15\15\0";
    result = NULL;
    bool test6 = validatePadding(validPadding4,&result,&tmp);
    assert(test6 == true);
    for(int i=0;i<tmp;i++){
        printf("%c",result[i]);
    }
    printf("\n");
    //------------------------------------------------------------------------------------------
    printf("------------------------------------------\n");
    unsigned char* validPadding5 = "ICE ICE BABYYYYY\16\16\16\16\16\16\16\16\16\16\16\16\16\16\16\16\0";
    result = NULL;
    bool test7 = validatePadding(validPadding5,&result,&tmp);
    assert(test7 == true);
    for(int i=0;i<tmp;i++){
        printf("%c",result[i]);
    }
    printf("\n");
    //------------------------------------------------------------------------------------------
    printf("------------------------------------------\n");
    unsigned char* validPadding6 = "ICE ICE BABYYYYY\15\15\15\15\15\15\15\15\15\15\15\15\15\15\15\15\0";
    result = NULL;
    bool test8 = validatePadding(validPadding6,&result,&tmp);
    assert(test8 == true);
    for(int i=0;i<tmp;i++){
        printf("%c",result[i]);
    }
    printf("\n");
    //------------------------------------------------------------------------------------------
    
    return 0;
}