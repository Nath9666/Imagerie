// ------------------------------------------------------------------
/**
 * @file EdHatThreshold.c
 *
 * @brief Example of simple Image Scan 
 * This file is the part "interface with the user" 
 * 
 * @author Patrick Bonnin
 * @email  patrick.bonnin@gmail.com
 * @date 2022.06.15 : creation.
 * @date 2022.06.15 : last modification.
 */
// ------------------------------------------------------------------
/* COPYRIGHT (C)	2022, P. Bonnin <patrick.bonnin@gmail.com>
 *
 * This  library  is  a free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public License
 * as  published by the Free Software Foundation; either version 2 of
 * the License, or (at your option) any later version.
 *
 * This  Library  is  distributed in the hope that it will be useful,
 * but  WITHOUT  ANY  WARRANTY;  without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULIAR PURPOSE.
 * See the GNU Lesser General Public License for more details.
 *
 * You  should  have received a copy of the GNU Lesser General Public 
 * License  along  with  this  library;  if  not,  write  to the Free 
 * Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 */
// ------------------------------------------------------------------
/* Modifications :
 * 2022.06.15 : creation
 */
// ------------------------------------------------------------------
#include "EdStructures.h"
#include "EdUtilities.h"
#include "EdLibHatThreshold.h"

int main(int argc, char **argv)
{
  EdIMAGE	*image = NULL,*imres = NULL;
  int	        nlig = 0, ncol = 0;
  unsigned char prof = 0;
  FILE	        *fichier = NULL, *fichres = NULL;
  int           ret;
  int iTh;
  unsigned char ThL, ThH;
  /* --- USAGE --- */
  if(argc != 5)
  {
    fprintf(stderr,"USAGE :  Threshold image imTh ThL ThH\n");
    
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
  /* --- Threshold Value --- */
  iTh = atoi(*++argv);
  ThL = (unsigned char)iTh;
  
  iTh = atoi(*++argv);
  ThH = (unsigned char)iTh;
  
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
  
/* --- Threshold --- */
  ret = HatThreshold (image, imres, ThL, ThH);
  if (ret)
  {
    fprintf(stderr,"Problem of Memory Allocation in Mean Filtering \n");
    exit(0);
  } 

/* --- Writing of the Image Result in File --- */
  // Header 
  fprintf(fichres,"P5\n#creating by EdEnviTI\n%d %d\n255\n",(int)ncol, (int)nlig);
  // data 
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
  	
  fprintf(stderr,"End of HatThreshold Operator\n");
}
