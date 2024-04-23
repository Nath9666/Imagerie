# Compilation des Fichiers
if [ ! -d "./bin" ]; then
    mkdir bin
fi

if [ ! -d "./ImRes" ]; then
    mkdir ImRes
fi

# EdSimpleScan
if [ ! -f ./bin/EdSimpleScan ]; then
    gcc -o ./bin/EdSimpleScan ./src/EdSimpleScan.c ./src/EdLibSimpleScan.c ./src/EdUtilities.c
    echo "Compilation EdSimpleScan terminée"
else
    echo "EdSimpleScan existe déjà, pas besoin de compiler"
fi

# EdScanVois3
if [ ! -f ./bin/EdScanVois3 ]; then
    gcc -o ./bin/EdScanVois3 ./src/EdScanVois3.c ./src/EdLibScanVois3.c ./src/EdUtilities.c
    echo "Compilation EdScanVois3 terminée"
else
    echo "EdScanVois3 existe déjà, pas besoin de compiler"
fi


# EdThreshold
if [ ! -f ./bin/EdThreshold ]; then
    gcc -o ./bin/EdThreshold ./src/EdThreshold.c ./src/EdLibThreshold.c ./src/EdUtilities.c
    echo "Compilation EdThreshold terminée"
else
    echo "EdThreshold existe déjà, pas besoin de compiler"
fi

# EdMeanFiltering
if [ ! -f ./bin/EdMeanFiltering ]; then
    gcc -o ./bin/EdMeanFiltering ./src/EdMeanFiltering.c ./src/EdLibFiltering.c ./src/EdLibFiltering.h ./src/EdUtilities.c 
    echo "Compilation EdMeanFiltering terminée"
else
    echo "EdMeanFiltering existe déjà, pas besoin de compiler"
fi

# EdGaussFiltering
if [ ! -f ./bin/EdGaussFiltering ]; then
    gcc -o ./bin/EdGaussFiltering ./src/EdGaussFiltering.c ./src/EdLibGaussFiltering.c ./src/EdLibGaussFiltering.h ./src/EdUtilities.c
    echo "Compilation EdGaussFiltering terminée"
else
    echo "EdGaussFiltering existe déjà, pas besoin de compiler"
fi

# EdMedianFiltering
if [ ! -f ./bin/EdMedianFiltering ]; then
    gcc -o ./bin/EdMedianFiltering ./src/EdMedianFiltering.c ./src/EdMedianLibFiltering.c ./src/EdMedianLibFiltering.h ./src/EdUtilities.c
    echo "Compilation EdMedianFiltering terminée"
else
    echo "EdMedianFiltering existe déjà, pas besoin de compiler"
fi