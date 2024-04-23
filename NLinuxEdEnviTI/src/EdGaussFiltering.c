#include "EdStructures.h"
#include "EdUtilities.h"
#include "EdLibGaussFiltering.h"

int main(int argc, char **argv)
{
  EdIMAGE	    *image = NULL,*imres = NULL;
  int	        nlig = 0, ncol = 0;
  unsigned char	prof = 0;
  FILE	        *fichier = NULL, *fichres = NULL;
  int           ret;
  /* --- USAGE --- */
  if(argc != 3)
  {
    fprintf(stderr,"USAGE :  Mean Filtering image immoy \n");
    fprintf(stderr,"image : name of the image to filter \n");
    fprintf(stderr,"immoy : name of the result image \n");
    fprintf(stderr,"Scan of Image and 3 by 3 pixel neighbourhood of B&W image \n");
    exit(0);
  }
  /* --- Source Image --- */
  if(!(fichier = fopen(*++argv,"rb")))
  {
    fprintf(stderr,"Source Image %s Pb of Opening\n",*argv);
    exit(0);
  } 
  /* --- Result Image  --- */
  if(!(fichres = fopen(*++argv,"wb")))
  {
    fprintf(stderr,"Result Image %s Pb of Opening\n",*argv);
    exit(0);
  }  
  /* --- Reading of Image Header --- */
  if ((ret = Reading_ImageHeader(fichier, &ncol, &nlig, &prof)))
  {
    fprintf (stderr, "Problem of Reading Image Header \n");
    exit(0);
  }
  fprintf(stderr, "Size of the Image : %d lines x %d colums : Type : %d\n", 
    nlig,ncol, (int)prof);  
  if (prof != 1)
  {
    fprintf(stderr," the source image is not a B&W image \n");
    exit(0);
  }
  /* --- Creation of Images Header and Data --- */
  if (crea_IMAGE(image) == NULL)	/* creation of Image Header  */
  {
    fprintf(stderr,"Error of Memory Allocation  \n");
    exit (0);
  }
  ret = Creation_Image (image, nlig, ncol, prof); // Image Data
  if (!ret)
  {
    fprintf(stderr,"Error of Memory Allocation of Pixels  \n");
    exit (0);
  }
 
  if (crea_IMAGE(imres) == NULL) 
  {
    fprintf(stderr,"Error of Memory Allocation  \n");
    exit (0);
  }
  ret = Creation_Image (imres, nlig, ncol, prof);
  if (!ret)
  {
    fprintf(stderr,"Error of Memory Allocation of Pixels  \n");
    exit (0);
  }
 
/* --- Reading of Umage Data from file to Memory --- */
  ret = Reading_ImageData(fichier,image); // Image Pixel Data
  if (!ret)
  {
    fprintf(stderr,"Problem of Reading \n");
    exit(0);
  }
  
/* --- Example of Image Scan using 3 by 3 neighbourhood --- */
  ret = Gauss_Filtering (image, imres);
  if (ret)
  {
    fprintf(stderr,"Problem of Memory Allocation in Mean Filtering \n");
    exit(0);
  } 

/* --- Writing of the Image Result in File --- */
  // Header
  fprintf(fichres,"P5\n#creating by EdEnviTI\n%d %d\n255\n",
    (int)ncol, (int)nlig); 
  // Data 
  ret = Writing_ImageData(fichres, imres); // Image Pixel Data
  if (!ret)
  {
    fprintf(stderr,"Problem of Writing \n");
    exit(0);
  }

/* --- Free of Images --- */
  ret = Free_Image(image);
  if(ret == FALSE)
  {
    fprintf(stderr,"Problem of Free the Memory \n");
  }
  ret = Free_Image(imres);
  if(ret == FALSE)
  {
    fprintf(stderr,"Problem of Free the Memory \n");
  }
  
  fclose (fichier);
  fclose (fichres);
  	
  fprintf(stderr,"End of Mean Filtering Operator\n");
}
