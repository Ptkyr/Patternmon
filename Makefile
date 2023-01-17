CXX = g++-11
CXXFLAGS = -std=c++20 -g -MMD -Wall -Wextra -pedantic -Wshadow \
		   -Wsign-conversion -Wformat=2 \
		   -fno-omit-frame-pointer -fsanitize=undefined,address \
		   -I pokemon -I pokemon/headers -I routes -I info \
		   -I dex -I moves -I trainer -I battle
SOURCES = main.cc pokemon.cc species.cc pokdec.cc move.cc \
		  fire.cc water.cc grass.cc electric.cc normal.cc ice.cc \
		  fighting.cc poison.cc ground.cc flying.cc psychic.cc bug.cc \
		  rock.cc ghost.cc dragon.cc dark.cc steel.cc fairy.cc \
		  stats.cc types.cc \
		  route.cc \
		  pokedex.cc deximpl.cc basicdex.cc colourdex.cc \
		  trainer.cc player.cc cynthia.cc \
		  battle.cc singles.cc
OBJECTS = ${SOURCES:.cc=.o}
OBJ_DIR = ./obj
DEP_DIR = ${OBJ_DIR}/dep
DEPENDS = ${SOURCES:%.cc=${DEP_DIR}/%.d}
EXEC = ps

vpath %.cc pokemon
vpath %.h pokemon/headers
vpath %.cc %.h routes
vpath %.cc %.h info
vpath %.cc %.h dex
vpath %.cc %.h moves
vpath %.cc %.h trainer
vpath %.cc %.h battle

################# RULES ##################
${EXEC}: ${OBJECTS:%=${OBJ_DIR}/%}
# make executable using objects, $^ refers to dependencies, vpath %.o
	${CXX} ${CXXFLAGS} $^ -o ${EXEC}

-include ${DEPENDS}

${OBJ_DIR}/%.o: %.cc ${DEP_DIR}
# make objects and dependencies
	${CXX} -c ${CXXFLAGS} -MF ${DEP_DIR}/${<F:.cc=.d} $< -o $@

${DEP_DIR}: ${OBJ_DIR}
	@mkdir -p ${DEP_DIR}

${OBJ_DIR}:
	@mkdir -p ${OBJ_DIR}

.PHONY : clean

clean:
	rm -rf ${OBJ_DIR} ${EXEC}
