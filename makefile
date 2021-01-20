

timeImmemorial: main.o Dungeon.o Foyer.o FutureContinuous.o FuturePerfect.o Item.o Player.o SimpleFuture.o SimplePast.o SimplePresent.o Space.o utilityAdventure.o menuAdventure.o
	g++ -std=c++11 main.o Dungeon.o Foyer.o FutureContinuous.o FuturePerfect.o Item.o Player.o SimpleFuture.o SimplePast.o SimplePresent.o Space.o utilityAdventure.o menuAdventure.o -o timeImmemorial

main.o: main.cpp
	g++ -std=c++11 -c main.cpp

Dungeon.o: Dungeon.cpp Dungeon.hpp
	g++ -std=c++11 -c Dungeon.cpp

Foyer.o: Foyer.cpp Foyer.hpp
	g++ -std=c++11 -c Foyer.cpp

FutureContinuous.o: FutureContinuous.cpp FutureContinuous.hpp
	g++ -std=c++11 -c FutureContinuous.cpp

FuturePerfect.o: FuturePerfect.cpp FuturePerfect.hpp
	g++ -std=c++11 -c FuturePerfect.cpp

Item.o: Item.cpp Item.hpp
	g++ -std=c++11 -c Item.cpp

Player.o: Player.cpp Player.hpp
	g++ -std=c++11 -c Player.cpp

SimpleFuture.o: SimpleFuture.cpp SimpleFuture.hpp
	g++ -std=c++11 -c SimpleFuture.cpp

SimplePast.o: SimplePast.cpp SimplePast.hpp
	g++ -std=c++11 -c SimplePast.cpp

SimplePresent.o: SimplePresent.cpp SimplePresent.hpp
	g++ -std=c++11 -c SimplePresent.cpp

Space.o: Space.cpp Space.hpp
	g++ -std=c++11 -c Space.cpp

utilityAdventure.o: utilityAdventure.cpp utilityAdventure.hpp
	g++ -std=c++11 -c utilityAdventure.cpp

menuAdventure.o: menuAdventure.cpp menuAdventure.hpp
	g++ -std=c++11 -c menuAdventure.cpp

clean:
	rm *.o timeImmemorial

