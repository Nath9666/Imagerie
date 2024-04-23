# Editeur d'image

Dans ce projet nous utilisont des programme C pour manipuler des images en format PGM.

Si vous n'etes pas familier avec les commandes linux je vous invite à regarder [ce document](./CommandeLinux.md).

## Compilation

Vous pouvez compiler les programmes avec la commande suivante :

```bash
cd NLinuxEdEnviTI
./compile.sh
```

# Execution

Vous pouvez executer les programmes avec la commande suivante :

```bash
cd NLinuxEdEnviTI
./run.sh
```

## Simple Scan

```bash
cd NLinuxEdEnviTI\src
gcc -o ..\bin\EdSimpleScan EdSimpleScan.c EdLibSimpleScan.c EdUtilities.c 
```

```bash
cd NLinuxEdEnviTI\bin
.\EdSimpleScan.exe ..\Image\LennaHeadBruit.pgm ..\ImRes\LennaHeadBruitSimpleScan.pgm
```

## Thresholding

```bash
cd NLinuxEdEnviTI\src
gcc -o ..\bin\EdThreshold EdThreshold.c EdLibThreshold.c EdUtilities.c 
```

```bash
cd NLinuxEdEnviTI\bin
.\EdThreshold.exe ..\Image\LennaHeadBruit.pgm ..\ImRes\LennaHeadBruit50.pgm 50
```

## Mean Filtering

```bash
cd NLinuxEdEnviTI\src
gcc -o ..\bin\EdMeanFiltering .\EdMeanFiltering.c .\EdLibFiltering.c .\EdLibFiltering.h .\EdUtilities.c 
```

```bash
cd NLinuxEdEnviTI\bin
.\EdMeanFiltering.exe ..\Image\LennaHeadBruit.pgm ..\ImRes\LennaHeadBruitMean.pgm
```
