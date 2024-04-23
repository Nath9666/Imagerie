# Compilation des Fichiers

# EdSimpleScan
gcc -o ./bin/EdSimpleScan ./src/EdSimpleScan.c ./src/EdLibSimpleScan.c ./src/EdUtilities.c
echo "Compilation EdSimpleScan terminee"

# EdScanVois3
gcc -o ./bin/EdScanVois3 ./src/EdScanVois3.c ./src/EdLibScanVois3.c ./src/EdUtilities.c
echo "Compilation EdScanVois3 terminee"

# EdThreshold
gcc -o ./bin/EdThreshold ./src/EdThreshold.c ./src/EdLibThreshold.c ./src/EdUtilities.c
echo "Compilation EdThreshold terminee"

# EdMeanFiltering
gcc -o ./bin/EdMeanFiltering ./src/EdMeanFiltering.c ./src/EdLibFiltering.c ./src/EdLibFiltering.h ./src/EdUtilities.c 
echo "Compilation EdMeanFiltering terminee"