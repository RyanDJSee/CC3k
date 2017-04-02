CXX = g++-5
CXXFLAGS = -std=c++14 -Wall -MMD -Werror=vla
EXEC = main
OBJECTS = main.o observer.o subject.o game.o floor.o cell.o empty.o stair.o passage.o door.o wall.o character.o item.o pc.o enemy.o potion.o shade.o goblin.o drow.o vampire.o troll.o human.o dwarf.o halfling.o elf.o orc.o merchant.o dragon.o rh.o ba.o bd.o ph.o wa.o wd.o treasure.o subtype.o steptype.o info.o END.o NEXTFLOOR.o RESTART.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
.PHONY: clean
