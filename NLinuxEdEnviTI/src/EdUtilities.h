#ifndef _UT
#define _UT
int Reading_ImageHeader(FILE *fichier, int *pncol, 
  int *pnlig, unsigned char *pprof);
int Creation_Image (EdIMAGE *image, int nlig, int ncol, 
       unsigned char prof);
int Reading_ImageData(FILE *fichier,EdIMAGE *image);
int Writing_ImageData(FILE *fichier,EdIMAGE *image);
int Free_Image(EdIMAGE *image);
void Label_Conversion(EdIMAGE *imLbl, EdIMAGE *imCLbl);
void LUT_Edition(unsigned char palette[64][3]);
unsigned char  Level(int k);

#endif











