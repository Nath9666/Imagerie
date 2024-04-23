gcc -o EdThreshold EdThreshold.c EdLibThreshold.c EdUtilities.c 
cc1.exe: fatal error: EdThreshold.c: No such file or directory
compilation terminated.
PS C:\Users\laura\OneDrive - Efrei\M1\S2\Introduction au Traitement d'images\NLinuxEdEnviTI\src> gcc -o ../bin/EdThreshold EdThreshold.c EdLibThreshold.c EdUtilities.c

PS C:\Users\laura\OneDrive - Efrei\M1\S2\Introduction au Traitement d'images\NLinuxEdEnviTI\src> cd ..
PS C:\Users\laura\OneDrive - Efrei\M1\S2\Introduction au Traitement d'images\NLinuxEdEnviTI> cd bin
PS C:\Users\laura\OneDrive - Efrei\M1\S2\Introduction au Traitement d'images\NLinuxEdEnviTI\bin> .\EdThreshold.exe ..\Images\Ampoules.gmp ..\ImRes\Ampoules50.pgm 50
Source Image ..\Images\Ampoules.gmp Pb of Opening