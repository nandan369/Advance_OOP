# Variables
CXX = g++                    # The C++ compiler to use (g++)
OBJECTS = main.o randword.o       # Object files that will be generated
FLAGS = -Wall -std=c++20      # Compiler flags: -Wall enables all warnings, and -std=c++20 uses the C++20 standard
SOURCE = $(wildcard *.cpp)    # Finds all .cpp source files in the current directory
TARGET = hangman   # The name of the final executable

# Default target: Compile the project into an executable
all: $(TARGET)

# Target: Link the object files to create the executable
$(TARGET): $(OBJECTS)
	$(CXX) $(FLAGS) $(OBJECTS) -o $(TARGET)

# Pattern rule: Compile .cpp files into corresponding .o files
%.o: %.cpp
	$(CXX) -c $< -o $@

# Target: Compile and run the program
run: all
	./$(TARGET)

# Target: Display the list of source files (useful for debugging or checking sources)
echo:
	echo $(SOURCE)

# Target: Clean up by removing the object files and the executable
clean:
	rm -f $(OBJECTS) $(TARGET)
