uhh="build/"
project_name="${PWD##*/}"
EPIC="${uhh}${project_name}"
cmake --build build && ./$EPIC
