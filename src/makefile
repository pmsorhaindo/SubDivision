CC=g++
CFLAGS=-c -Wall
LDFLAGS= -lSDL -lGL -lGLU -lGLEW
SOURCES=Cube.cpp Butterfly.cpp Catmull.cpp Edge.cpp Face.cpp GeometryOps.cpp QFace.cpp SetUpCube.cpp SubDivide.cpp Vertex.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=subdivision

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@