CXX = g++
CXXFLAGS = -std=c++14 -g -MMD -Wall -Wextra -fsanitize=undefined,address \
		   -I src -I src/headers
EXEC = ps
OBJECTS = main.o pokemon.o species.o pokdec.o move.o \
		  fire.o water.o grass.o electric.o \
		  stats.o
DEPENDS = ${OBJECTS:.o=.d}
VPATH=src:src/headers

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

.PHONY: clean recomp

clean:
	rm ${EXEC} ${OBJECTS} ${DEPENDS}

recomp:
	make clean
	make
