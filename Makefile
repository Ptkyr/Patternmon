################################
#             PATHS            #
################################
# target location of intermediate .o files
OBJ_DIR = ./obj
# target location of dependency .d makefiles
DEP_DIR = ${OBJ_DIR}/dep

################################
#       COMPILER & FLAGS       #
################################
CXX = g++-11
CXXFLAGS = -std=c++20 -g -MMD -Wall -Wextra -pedantic -fsanitize=undefined,address \
		   -I pokemon -I routes -I info -I dex -I moves

################################
#   VARIABLES & SEARCH PATHS   #
################################
SOURCES = main.cc pokemon.cc species.cc pokdec.cc move.cc \
		  fire.cc water.cc grass.cc electric.cc normal.cc ice.cc \
		  fighting.cc poison.cc ground.cc flying.cc psychic.cc bug.cc \
		  rock.cc \
		  stats.cc \
		  route.cc \
		  pokedex.cc deximpl.cc basicdex.cc colourdex.cc
OBJECTS = ${SOURCES:.cc=.o}
DEPENDS = ${SOURCES:%.cc=${DEP_DIR}/%.d}
EXEC = ps

vpath %.cc pokemon
vpath %.h pokemon
vpath %.cc routes
vpath %.h routes
vpath %.cc info
vpath %.h info
vpath %.cc dex
vpath %.h dex
vpath %.cc moves
vpath %.h moves

################################
#             RULES            #
################################
${EXEC}: ${OBJECTS:%=${OBJ_DIR}/%}
# make executable using objects, $^ refers to dependencies, vpath %.o
	${CXX} ${CXXFLAGS} $^ -o ${EXEC}

-include ${DEPENDS}

${OBJ_DIR}/%.o: %.cc ${DEP_DIR}
# make objects and dependencies
	${CXX} -c ${CXXFLAGS} -MF ${DEP_DIR}/${<F:.cc=.d} $< -o $@

${DEP_DIR} : ${OBJ_DIR}
	@mkdir -p ${DEP_DIR}

${OBJ_DIR} :
	@mkdir -p ${OBJ_DIR}

.PHONY : clean

clean:
	rm -rf ${OBJ_DIR} ${EXEC}
