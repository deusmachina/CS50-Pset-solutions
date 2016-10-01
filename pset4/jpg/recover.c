/**
 * recover.c
 *
 * Computer Science 50
 * Problem Set 4
 *
 * Recovers JPEGs from a forensic image.
 */

#include <stdio.h>
#include <stdint.h>
#include <string.h>
int main(int argc, char* argv[])
{
    FILE* file = fopen("card.raw", "r");
    unsigned char ch[512];
    if(file==NULL)
    {
        fclose(file);
        fprintf(stderr, "Could not open.\n");
        return 1;
    }
    
    char s[10];
    
    uint8_t jpg1[4] = {0xff, 0xd8, 0xff, 0xe0};
    uint8_t jpg2[4] = {0xff, 0xd8, 0xff, 0xe1};
    uint8_t jpg3[4] = {0xff, 0xd8, 0xff, 0xe2};
    uint8_t jpg4[4] = {0xff, 0xd8, 0xff, 0xe3};
    uint8_t jpg5[4] = {0xff, 0xd8, 0xff, 0xe4};
    uint8_t jpg6[4] = {0xff, 0xd8, 0xff, 0xe5};
    uint8_t jpg7[4] = {0xff, 0xd8, 0xff, 0xe6};
    uint8_t jpg8[4] = {0xff, 0xd8, 0xff, 0xe7};
    uint8_t jpg9[4] = {0xff, 0xd8, 0xff, 0xe8};
    uint8_t jpga[4] = {0xff, 0xd8, 0xff, 0xe9};
    uint8_t jpgb[4] = {0xff, 0xd8, 0xff, 0xea};
    uint8_t jpgc[4] = {0xff, 0xd8, 0xff, 0xeb};
    uint8_t jpgd[4] = {0xff, 0xd8, 0xff, 0xec};
    uint8_t jpge[4] = {0xff, 0xd8, 0xff, 0xed};
    uint8_t jpgf[4] = {0xff, 0xd8, 0xff, 0xee};
    uint8_t jpg0[4] = {0xff, 0xd8, 0xff, 0xef};
    
    int j=-1,flag=0;
    char tmp[4];
    
    while(fread(ch,512,1,file) > 0)
    {
        tmp[0]=ch[0];
        tmp[1]=ch[1];
        tmp[2]=ch[2];
        tmp[3]=ch[3];
        
        if((memcmp(jpg0, tmp, 4) == 0 ) ||(memcmp(jpg1, tmp, 4) == 0 ) ||(memcmp(jpg2, tmp, 4) == 0 ) ||(memcmp(jpg3, tmp, 4) == 0 ) ||(memcmp(jpg4, tmp, 4) == 0 ) ||(memcmp(jpg5, tmp, 4) == 0 ) ||(memcmp(jpg6, tmp, 4) == 0 ) ||(memcmp(jpg7, tmp, 4) == 0 ) ||(memcmp(jpg8, tmp, 4) == 0 ) ||(memcmp(jpg9, tmp, 4) == 0 ) ||(memcmp(jpga, tmp, 4) == 0 ) ||(memcmp(jpgb, tmp, 4) == 0 ) ||(memcmp(jpgc, tmp, 4) == 0 ) ||(memcmp(jpgd, tmp, 4) == 0 ) ||(memcmp(jpge, tmp, 4) == 0 ) ||(memcmp(jpgf, tmp, 4) == 0 )  )
        {
            j++;
            flag=1;
            sprintf(s,"%03i.jpg",j);
            FILE* img = fopen(s,"a");
            
            if(img == NULL)
            {
                fclose(file);
                fclose(img);
                fprintf(stderr, "could not create %s\n",s);
                return 2;
            }
            fwrite(ch,1,512,img);
            fclose(img);
        }
        else if(flag==1)
        {
            FILE* img = fopen(s,"a");
            if(img == NULL)
            {
                fclose(file);
                fprintf(stderr, "could not open %s\n",s);
                return 3;
            }
            fwrite(ch,1,512,img);
            fclose(img);
        }
    }
    fclose(file);
    return 0;
}
