cd ./bin

# Create the image Simple Scan
./EdSimpleScan.exe ../Image/LenaHead.pgm ../ImRes/LennaHeadBruitSimpleScan.pgm

# Create the image Scan Vois 3
./EdScanVois3.exe ../Image/LenaHead.pgm ../ImRes/LennaHeadBruitScanVois3.pgm

# Create the image Threshold
./EdThreshold.exe ../Image/LenaHead.pgm ../ImRes/LennaHeadBruitThreshold.pgm

# Create the image Mean Filtering
./EdMeanFiltering.exe ../Image/LenaHead.pgm ../ImRes/LennaHeadBruitMeanFiltering.pgm

# Create the image Gauss Filtering
./EdGaussFiltering.exe ../Image/LenaHead.pgm ../ImRes/LennaHeadBruitGaussFiltering.pgm

# Create the image Median Filtering
./EdMedianFiltering.exe ../Image/LenaHead.pgm ../ImRes/LennaHeadBruitMedianFiltering.pgm