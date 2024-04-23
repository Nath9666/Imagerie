#include "EdStructures.h"
#include "EdUtilities.h"

int SimpleScan(EdIMAGE *image, EdIMAGE *imres)
{
  EdPOINT       *point = NULL; /* current point */
  unsigned char uc; /* example of pixel read and write ... */
  

  if(crea_POINT(point) == NULL)          /* Memory Allocation of point */
  {
     fprintf(stderr,"Error of Memory Allocation \n");
     system("PAUSE"); // Windows Only
     return 1; 
  }

  /* --- Video Scan of the image, except the Border :
         Smooting by Mean Filtering  --- */	
  for(POINT_Y(point) = 0; POINT_Y(point) < NLIG(image); 
           POINT_Y(point)++)
  for(POINT_X(point) = 0; POINT_X(point) < NCOL(image); 
           POINT_X(point)++)
  {
    uc = PIXEL(image, point);
    PIXEL(imres, point) = uc;
  }/* --- End of the Image Video Scan --- */
  /* --- Memory Free  --- */
  free((void *)point);
  return 0;
} /* --- End of the Operator --- */   
