#!/bin/bash

# Set the base Advent of Code folder (change this to your actual path)
AOC_DIR="/home/ahmed-amamou/Desktop/CP/Advent of code 2024"

# Prompt the user for the day number
read -p "Enter the day of Advent of Code (1-25): " DAY

# Validate input (ensure it's a number between 1 and 25)
if ! [[ "$DAY" =~ ^[1-9]$|^1[0-9]$|^2[0-5]$ ]]; then
    echo "Invalid day. Please enter a number between 1 and 25."
    exit 1
fi

# Format day with space 
DAY_FOLDER="DAY$DAY"

# Create the folder for the day
DAY_DIR="$AOC_DIR/$DAY_FOLDER"
mkdir -p "$DAY_DIR"

# Define file names
PART1_FILE="$DAY_DIR/DAY $DAY - part1.py"
PART2_FILE="$DAY_DIR/DAY $DAY - part2.py"
INPUT_FILE="$DAY_DIR/DAY $DAY - input.txt"
OUTPUT_FILE="$DAY_DIR/DAY $DAY - output.txt"

# Create files
touch "$PART1_FILE" "$PART2_FILE" "$INPUT_FILE" "$OUTPUT_FILE"

# Add a basic template to part1 and part2
echo -e "# Advent of Code - DAY $DAY\n\ndef solve():\n    pass\n\nif __name__ == '__main__':\n    solve()" > "$PART1_FILE"

echo -e "# Advent of Code - DAY $DAY (Part 2)\n\ndef solve():\n    pass\n\nif __name__ == '__main__':\n    solve()" > "$PART2_FILE"

# Success message
echo "✅ Advent of Code DAY $DAY setup complete in '$DAY_DIR'"
