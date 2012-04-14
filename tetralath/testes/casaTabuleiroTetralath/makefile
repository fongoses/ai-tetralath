CC=g++
CFLAGS=-c -Wall
LDFLAGS=
SOURCES=../../casaTabuleiroTetralath.cpp testes.cpp 
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=executavel

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@
