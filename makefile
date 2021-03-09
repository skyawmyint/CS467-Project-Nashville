

nashville: main.o UI.o game.o Item.o medbay.o character.o room.o corridor1.o corridor2.o corridor3.o communications.o electrical.o enginebay.o lifesupporto2.o mainframeroom.o navigation.o reactor.o storage.o utilityFunctions.o captainslodge.o escapepodroom.o cafeteria.o
	g++ -std=c++0x main.o game.o UI.o Item.o medbay.o character.o room.o corridor1.o corridor2.o corridor3.o communications.o electrical.o enginebay.o lifesupporto2.o mainframeroom.o navigation.o reactor.o storage.o utilityFunctions.o captainslodge.o escapepodroom.o cafeteria.o -o nashville

main.o: main.cpp
	g++ -std=c++0x -c main.cpp

UI.o: UI.cpp UI.hpp
	g++ -std=c++0x -c UI.cpp

character.o: character.cpp character.hpp
	g++ -std=c++0x -c character.cpp

game.o: game.cpp game.hpp
	g++ -std=c++0x -c game.cpp

Item.o: Item.cpp Item.hpp
	g++ -std=c++0x -c Item.cpp

medbay.o: medbay.cpp medbay.hpp
	g++ -std=c++0x -c medbay.cpp

room.o: room.cpp room.hpp
	g++ -std=c++0x -c room.cpp

utilityFunctions.o: utilityFunctions.cpp utilityFunctions.hpp
	g++ -std=c++0x -c utilityFunctions.cpp

corridor1.o: corridor1.cpp corridor1.hpp
	g++ -std=c++0x -c corridor1.cpp

corridor2.o: corridor2.cpp corridor2.hpp
	g++ -std=c++0x -c corridor2.cpp

corridor3.o: corridor3.cpp corridor3.hpp
	g++ -std=c++0x -c corridor3.cpp

communications.o: communications.cpp communications.hpp
	g++ -std=c++0x -c communications.cpp

electrical.o: electrical.cpp electrical.hpp
	g++ -std=c++0x -c electrical.cpp

enginebay.o: enginebay.cpp enginebay.hpp
	g++ -std=c++0x -c enginebay.cpp

lifesupporto2.o: lifesupporto2.cpp lifesupporto2.hpp
	g++ -std=c++0x -c lifesupporto2.cpp

mainframeroom.o: mainframeroom.cpp mainframeroom.hpp
	g++ -std=c++0x -c mainframeroom.cpp

navigation.o: navigation.cpp navigation.hpp
	g++ -std=c++0x -c navigation.cpp

reactor.o: reactor.cpp reactor.hpp
	g++ -std=c++0x -c reactor.cpp

storage.o: storage.cpp storage.hpp
	g++ -std=c++0x -c storage.cpp

captainslodge.o: captainslodge.cpp captainslodge.hpp
	g++ -std=c++0x -c captainslodge.cpp

escapepodroom.o: escapepodroom.cpp escapepodroom.hpp
	g++ -std=c++0x -c escapepodroom.cpp

cafeteria.o: cafeteria.cpp cafeteria.hpp
	g++ -std=c++0x -c cafeteria.cpp

clean:
	rm *.o *.txt nashville
