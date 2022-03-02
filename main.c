#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LINE_RANGE 300

int main(int argc,char **argv){
    if((strcmp(argv[1],"-h") || strcmp(argv[1],"--help")) && (argc == 2)){ // usage info
        printf(
            "Usage:  ./grepinfo [FILE] [WORD] \n"
            "Example: ./grepinfo elonmusk.txt starlink\n\n");
        return EXIT_SUCCESS;
    }

	FILE *fp;  // .txt dosyasinin icerigini okumak icin
    FILE *fpOutput;   // output dosyasina yazmak icin
    char str[LINE_RANGE];
    int i=1,wordCounter=0;


    fp = fopen(argv[1],"r");
    fpOutput = fopen("outputfile.txt","w");
    if(fp == NULL ||  fpOutput == NULL){
        printf("\nError! Can not read file.\n");
        return(-1);
    }
    while(1){
        if(fgets(str,LINE_RANGE,fp) != NULL ){
            if(strstr(str,argv[2]) != NULL){
                fprintf(fpOutput,"%d- ",i);
                fputs(str,fpOutput);
                wordCounter++;
            }
            i++;
        }
        else{
            break;
        }
    }
    fclose(fp);
    fclose(fpOutput);
    printf("\n\nAranan kelime %d defa geciyor.",wordCounter);
    return EXIT_SUCCESS;
}
