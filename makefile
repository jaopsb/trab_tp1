# Consts:
# IncludeDIR = *.h DIR
# CC = gcc or g++
# DB = gdb
# CFLAGS = comp line flags (-ansi = ansi law; -Wall, -Wextra = warnings; -I./ = *.h DIR)
# ObjDIR = *.o DIR
# LibDIR = lib DIR
# LibDIR -> enable when using, put $(LIBS) at end of gogo's command
LibDIREC=./lib/
LibDIR=./lib/ 
IncludeDIR=./include/
CcDIR=./src/
ObjDIR=./obj/Debug/src/
ObjDIRMain=./obj/Debug/
CC=g++
DB=gdb
CFLAGS=-ansi -Wall -Wextra -I$(IncludeDIR) -pthread

# Vars:
# -- ADAPT THIS IN YOUR PROGRAM --
headers = Acomodacao.h Banco_hotel.h Data.h sqlite3.h Usuario.h
mainObject = main
objects = main.o Acomodacao.o Banco_hotel.o Data.o sqlite3.o Usuario.o

# Set of *.h on which the *.cc depend
_DEPS = $(headers)
DEPS = $(patsubst %,$(IncludeDIR)%,$(_DEPS))

# Set of *.o
_OBJ = $(mainObject).o $(objects)
OBJ = $(patsubst %,$(ObjDIR)%,$(_OBJ))

# Gathers *.o
$(ObjDIR)%.o: $(CcDIR)%.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS) $(LIBS)

# Creates executable (Linux)
$(mainObject): $(OBJ)
	$(CC) -g -o $@ $^ $(CFLAGS) $(LIBS)

# Gets the files and organize in the lib include src/obj structure
.PHONY: prepareDIR
prepareDIR:
	mkdir -p $(LibDIREC)
	mkdir -p $(IncludeDIR)
	mkdir -p $(CcDIR)
	mkdir -p $(ObjDIR)
	mv *.h $(IncludeDIR); true
	mv *.cpp $(CcDIR); true

# Call for execution
.PHONY: execute
execute:
	./$(mainObject)

# Call for debugging
.PHONY: debug
debug:
	$(DB) ./$(mainObject)

# Call for *.o clean up
.PHONY: clean
clean:
	rm $(ObjDIR)*.o

# Call for help with this makefile's commands
.PHONY: help
help:
	@echo "\n\t Makefile\n"
	@echo " make............= compiles program"
	@echo " make prepareDIR.= prepares project in the "lib include src/obj" structure (use this if all files are with this makefile)"
	@echo " make execute....= executes succesfully compiled program"
	@echo " make debug......= (gdb) debugs succesfully compiled program"
	@echo " make clean......= removes objects from obj directory\n"
	@echo " For use with program, change variables -headers- and -objects- inside makefile\n\n"