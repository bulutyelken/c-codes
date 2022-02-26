#include <stdio.h>
#include <stdlib.h>

//verilen arrayin uzunlugunu bulur
int LengthofString(char *word)
{
    if (*word == '\0')
        return 0;
    else
        return 1 + LengthofString(word + 1); // info: char* word=bulut ise, word+1=ulut olur. Yani char arrayine +1 eklemek baþtaki harfi siler.
}

//iki array alir arraylar aynýysa 1, deðilse 0 döndürür.
int compareArrays(char* array1,char* array2){
    int length = LengthofString(array1);
    for (int i = 0; i < length; i++)
    {
        if(array1[i]!=array2[i]){
            return 0;
        }
            //printf("\narray1[%d]:%c\narray2[%d]:%c\n",i,array1[i],i,array2[i]);
    }
    return 1;


}

//help
void usage(void)
{
  printf("Usage:\n"
            "Syntax is: [grepinfo <WORD> <FILE>\n"
            "Example: grepinfo starlink elonmusk.txt\n"




            "\n");
}


int main(int argc, char **argv){
    char usage1[2] = "-h";
    char usage2[6] = "--help";
    if(compareArrays(argv[1],usage1) || compareArrays(argv[1],usage2)){
        usage();
        return 0;
    }
    if(argc!=3){ //yanlis sayida parametre.
        printf("HATA! Yanlis miktarda parametre girdiniz, 2 parametre girmeniz bekleniyor.\n");
        return 0;
    }
    printf("\n");
    FILE *fpl;
    char c;
    char counter;
    char *p;
    fpl = fopen(argv[2],"r");
    char *aranan_kelime = argv[1];
    printf("Parametre sayisi = %d\n",argc);
    printf("Kelimenin uzunlugu = %d\n",LengthofString(aranan_kelime));
    int charsayisi=0;
    printf("\n\n");
    while (1)//2. parametrenin yani .txt dosyasinin uzunlugunu buluyor.
    {
        counter = fgetc(fpl);
        if(counter==EOF){
            break;
        }
        else {
            charsayisi++;
        }
    }
    char* array;
    fpl = fopen(argv[2],"r");
    int row = 1;
    char bulunan_kelime[100];
    while (1)
    {
        c = fgetc(fpl);
        if(c==EOF){
            row = -1;
            break;
        }

        for (int i = 0; i < LengthofString(aranan_kelime); i++)
        {
            if (aranan_kelime[i] == c)
            {
                bulunan_kelime[i]=c;
            }
        }
        printf("Arraylar eslesiyor mu ?: %d\n",compareArrays(aranan_kelime,bulunan_kelime));
        printf("bulunan kelime: %s\n",bulunan_kelime);
        printf("Aranan kelime = %s\n",aranan_kelime);

    }
        if(compareArrays(aranan_kelime,bulunan_kelime)){
            printf(bulunan_kelime);
        }
    printf("\n\nkarakter sayisi = %d",charsayisi);

    fclose(fpl);

    return 0;
}
