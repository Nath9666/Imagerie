cd ./bin

# Create the image Simple Scan
./EdSimpleScan.exe ../Image/LennaHeadBruit.pgm ../ImRes/LennaHeadBruitSimpleScan.pgm

# Create the image Scan Vois 3
./EdScanVois3.exe ../Image/LennaHeadBruit.pgm ../ImRes/LennaHeadBruitScanVois3.pgm

# Create the image Threshold
./EdThreshold.exe ../Image/LennaHeadBruit.pgm ../ImRes/LennaHeadBruitThreshold.pgm

# Create the image Mean Filtering
./EdMeanFiltering.exe ../Image/LennaHeadBruit.pgm ../ImRes/LennaHeadBruitMeanFiltering.pgm

# Create the image Gauss Filtering
./EdGaussFiltering.exe ../Image/LennaHeadBruit.pgm ../ImRes/LennaHeadBruitGaussFiltering.pgm

# Create the image Median Filtering
./EdMedianFiltering.exe ../Image/LennaHeadBruit.pgm ../ImRes/LennaHeadBruitMedianFiltering.pgm