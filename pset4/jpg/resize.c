#include <stdio.h>
#include <stdlib.h>

#include "bmp.h"

int main(int argc , char* argv[])
{
    if(argc != 4)
    {
        printf("Usage: ./resize n infile outfile\n");
        return 1;
    }
    
    int n =atoi(argv[1]);
    if(n > 100 || n <= 0)
    {
        printf("Enter positive integer <=100\n");
        return 2;
    }
    
    char* infile=argv[2];
    char* outfile=argv[3];
    
    // open input file 
    FILE* inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        printf("Could not open %s.\n", infile);
        return 3;
    }

    // open output file
    FILE* outptr = fopen(outfile, "w");
    if (outptr == NULL)
    {
        fclose(inptr);
        fprintf(stderr, "Could not create %s.\n", outfile);
        return 4;
    }
    
     // read infile's BITMAPFILEHEADER
    BITMAPFILEHEADER bf;
    fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptr);

    // read infile's BITMAPINFOHEADER
    BITMAPINFOHEADER bi;
    fread(&bi, sizeof(BITMAPINFOHEADER), 1, inptr);

    // ensure infile is (likely) a 24-bit uncompressed BMP 4.0
    if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 || 
        bi.biBitCount != 24 || bi.biCompression != 0)
    {
        fclose(outptr);
        fclose(inptr);
        fprintf(stderr, "Unsupported file format.\n");
        return 5;
    }
    
    BITMAPINFOHEADER boi = bi;
    BITMAPFILEHEADER bof = bf;
    
    boi.biWidth=boi.biWidth*n; 
    boi.biHeight=boi.biHeight*n;
    
    int padding =  (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
    int outpad =   (4 - (boi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
    
    //google the formulas for bfsize and bisize
    bof.bfSize = 54 + boi.biWidth * abs(boi.biHeight) * 3 + abs(boi.biHeight) *  outpad;
	boi.biSizeImage = ((((boi.biWidth * boi.biBitCount) + 31) & ~31) / 8) * abs(boi.biHeight);
    
    fwrite( &bof , sizeof(BITMAPFILEHEADER) , 1 ,outptr);
    fwrite( &boi , sizeof(BITMAPINFOHEADER) , 1 , outptr);
    
     // iterate over infile's scanlines
    
    for (int i = 0, biHeight = abs(bi.biHeight); i < biHeight; i++)
    {
        // iterate over pixels in scanline
        for(int q=0; q<n ; q++)
        {
            for (int j = 0; j < bi.biWidth; j++)
            {
                // temporary storage
                RGBTRIPLE triple ;
            
                // read RGB triple from infile
                fread(&triple, sizeof(RGBTRIPLE), 1, inptr);
                
                // write RGB triple to outfile
                for(int o=0;o<n;o++)    
                    fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);

            }

            // skip over padding, if any
            fseek(inptr, padding, SEEK_CUR);
            
            // then add it back (to demonstrate how)
            for (int k = 0; k < outpad; k++)
            {
                fputc(0x00, outptr);
            }
            
            fseek(inptr , -(bi.biWidth*3+padding) , SEEK_CUR);
            
        }
        fseek(inptr, bi.biWidth*3+padding, SEEK_CUR);
    }
    
    fclose(inptr);
    fclose(outptr);
    return 0;
}