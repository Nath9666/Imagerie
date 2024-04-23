#include "EdStructures.h"
#include "EdUtilities.h"

int Gauss_Filtering(EdIMAGE *image, EdIMAGE *imres)
{
  // current and neighbour (voisin in French) point creation 
  EdPOINT	*point = NULL, *pointv = NULL;
  // index of lines and columns of the 3X3 neighbourhood
  int	i,j; 

  int Gauss; // mean value of the 3X3 neighbourhood                            


  if(crea_POINT(point) == NULL)          /* Memory Allocation of point */
  {
     fprintf(stderr,"Error of Memory Allocation \n");
     system("PAUSE"); // Windows Only
     return 1;
  }
  if(crea_POINT(pointv) == NULL)
  {
     fprintf(stderr,"Error of Memory Allocation \n");
     system("PAUSE"); // Windows Only
     return 1;
  }
  /* --- Initialisation of Image Borders : Copy of the Original Image  --- */
  for(POINT_X(point) = 0; POINT_X(point) < NCOL(image);
           POINT_X(point)++)
  {
    POINT_Y(point) = 0;                  /* first line */
    PIXEL(imres, point) = PIXEL(imres, point);

    POINT_Y(point) = NLIG(image) - 1;    /* last line */
    PIXEL(imres, point) = PIXEL(imres, point);
  } /*--- End of copy of first and last lines --- */

  for(POINT_Y(point) = 0; POINT_Y(point) < NLIG(image);
           POINT_Y(point)++)
  {
    POINT_X(point) = 0;                  /* first column */
    PIXEL(imres, point) = 0;

    POINT_X(point) = NCOL(image) - 1;    /* last column */
    PIXEL(imres, point) = 0;
  } /*--- End of copy of first and last columns --- */

  /* --- Video Scan of the image, except the Border :
         Smooting by Mean Filtering  --- */
  for(POINT_Y(point) = 1; POINT_Y(point) < NLIG(image) - 1;
           POINT_Y(point)++)
  for(POINT_X(point) = 1; POINT_X(point) < NCOL(image) - 1;
           POINT_X(point)++)
  {
    /* --- ... Initialisation  ... */
    Gauss = 0;
    /* ---  Video Scan of the 3x3 neighbourhood --- */
    for(j = 0; j < 3; j++)
    for(i = 0; i < 3; i++)
    {
      /* Computation of the Image Coordinates of the Neighbour point */
      POINT_X(pointv) = POINT_X(point) + i - 1;
      POINT_Y(pointv) = POINT_Y(point) + j - 1;

      Gauss += PIXEL(image, pointv);
    } /* --- End of the Neighbourhood Video Scan --- */
    Gauss += PIXEL(image, point);
    Gauss /= 10;

    PIXEL(imres, point) = (unsigned char) Gauss;
  }/* --- End of the Image Video Scan --- */
  /* --- Memory Free  --- */
  free((void *)pointv);
  free((void *)point);
  return 0;
} /* --- End of the Operator --- */
