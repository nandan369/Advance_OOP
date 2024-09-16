# Variables
CXX = g++
OBJECTS = main.o trip.o
FLAGS = -Wall -std=c++20
SOURCE = $(wildcard *.cpp)
TARGET = expense_calculator

# Link object files to create the executable
$(TARGET): $(OBJECTS)
	$(CXX) $(FLAGS) $(OBJECTS) -o $(TARGET) 

# Compile .cpp into .o files
%.o: %.cpp
	$(CXX) -c $< -o$@

# Run target: Compile and run the executable
run: $(TARGET)
	./$(TARGET)

echo:
	echo $(SOURCE)

# Clean target: Remove the executable and object files
clean:
	rm -f $(OBJECTS) $(TARGET)
