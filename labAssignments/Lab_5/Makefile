#SOURCES = main.cpp ScreenSaver.cpp
OBJECTS = main.o screenSaver.o
EXECUTABLE = screenSaver

# Add compiler flags
CPPFLAGS = -I"C:\Users\nanda\OneDrive\Documents\libraries_SFML\SFML-2.6.1\include" -DSFML_STATIC

run: $(EXECUTABLE)
	./$(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	g++ -o $(EXECUTABLE) $(OBJECTS) -L"C:\Users\nanda\OneDrive\Documents\libraries_SFML\SFML-2.6.1\lib" -lsfml-graphics-s -lsfml-window-s -lsfml-system-s -lopengl32 -lfreetype -lwinmm -lgdi32 -mwindows -lsfml-main

%.o: %.cpp %.h
	g++ $(CPPFLAGS) -c $< 

clean:
	rm *.o $(EXECUTABLE)