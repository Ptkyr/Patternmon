CXX = g++
CXXFLAGS = -std=c++14 -g -MMD -Wall -Wextra -pedantic -fsanitize=undefined,address \
		   -I pokemon -I routes -I info -I dex -I moves
EXEC = ps
OBJECTS = main.o pokemon.o species.o pokdec.o move.o \
		  fire.o water.o grass.o electric.o normal.o \
		  stats.o \
		  route.o pokedex.o
DEPENDS = ${OBJECTS:.o=.d}

VPATH=pokemon:routes:info:dex:moves
OBJDIR=obj
DEPDIR=dep

### Rules ###
${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

.PHONY: clean recomp tidy

clean:
	rm -rf ${OBJECTS} ${DEPENDS} ${OBJDIR} ${DEPDIR}

recomp:
	make clean
	make

tidy:
	mkdir -p ${OBJDIR}
	mkdir -p ${DEPDIR}
	mv *.o ${OBJDIR}
	mv *.d ${DEPDIR}
