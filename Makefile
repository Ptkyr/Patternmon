CXX = g++
CXXFLAGS = -std=c++14 -g -MMD -Wall -Wextra -fsanitize=undefined,address \
		   -I src -I src/headers
EXEC = ps
OBJECTS = main.o pokemon.o species.o pokdec.o move.o \
		  fire.o water.o grass.o electric.o
DEPENDS = ${OBJECTS:.o=.d}
VPATH=src:src/headers

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

.PHONY: clean r

clean:
	rm ${EXEC} ${OBJECTS} ${DEPENDS}

r:
	make clean; make
