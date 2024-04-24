cd ./bin

# Define the variable
IMAGE_PATH="../Image/LennaHeadBruit.pgm"

IMAGE_PATH_Selection="../Image/Secateur.pgm"

# Get the base name of the image file
IMAGE_BASE=$(basename $IMAGE_PATH .pgm)

# Iterate over all programs in the directory
for PROGRAM in ./*.exe
do
    # Get the base name of the program
    PROGRAM_BASE=$(basename $PROGRAM .exe)

    # Check if the program is EdSelection.exe
    if [ "$PROGRAM_BASE" == "EdSelection" ]; then
        # Use IMAGE_PATH_Selection for EdSelection.exe
        INPUT_PATH = $IMAGE_PATH_Selection
    else
        # Use IMAGE_PATH for other programs
        INPUT_PATH = $IMAGE_PATH
    fi
    
    # Run the program with the image path and output path
    ./${PROGRAM_BASE}.exe $INPUT_PATH "../ImRes/${IMAGE_BASE}${PROGRAM_BASE}.pgm"
done