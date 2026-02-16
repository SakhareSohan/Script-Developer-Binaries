#!/bin/zsh
set -euo pipefail

if [[ "$#" -ne 2 ]]; then
    echo "Usage: c run <file.c|file.cpp>"
    exit 1
fi

if [[ "$1" != "run" ]]; then
    echo "Error: only 'run' command is supported"
    exit 1
fi

SOURCE="$2"

if [[ ! -f "$SOURCE" ]]; then
    echo "Error: file not found: $SOURCE"
    exit 1
fi

EXT="${SOURCE##*.}"
OUTPUT="${SOURCE%.*}"

COMMON_FLAGS=(
    -Wall
    -Wextra
    -Werror
    -pedantic
    -O0
)

if [[ "$EXT" == "c" ]]; then
    COMPILER=clang
    STD=-std=c17
elif [[ "$EXT" == "cpp" ]]; then
    COMPILER=clang++
    STD=-std=c++20
else
    echo "Error: unsupported file type: .$EXT"
    exit 1
fi

CMD=(
    "$COMPILER"
    "$STD"
    "${COMMON_FLAGS[@]}"
    "$SOURCE"
    -o
    "$OUTPUT"
)

echo "Compiling:"
echo "${CMD[@]}"
"${CMD[@]}"

echo "Executing:"
./"$OUTPUT"

echo "Cleaning up binary:"
rm -- "$OUTPUT"
