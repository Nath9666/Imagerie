cd ./bin

# Define the variable
IMAGE_PATH="../Image/LennaHeadBruit.pgm"

# Get the base name of the image file
IMAGE_BASE=$(basename $IMAGE_PATH .pgm)

# Iterate over all programs in the directory
for PROGRAM in ./*.exe
do
    # Get the base name of the program
    PROGRAM_BASE=$(basename $PROGRAM .exe)
    
    # Run the program with the image path and output path
    ./${PROGRAM_BASE}.exe $IMAGE_PATH "../ImRes/${IMAGE_BASE}${PROGRAM_BASE}.pgm"
done