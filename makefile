

nashville: main.o UI.o game.o corridor1.o Item.o medbay.o character.o room.o utilityFunctions.o 
	g++ -std=c++11 main.o game.o UI.o corridor1.o Item.o medbay.o character.o room.o utilityFunctions.o -o nashville

main.o: main.cpp
	g++ -std=c++11 -c main.cpp

UI.o: UI.cpp UI.hpp
	g++ -std=c++11 -c UI.cpp

character.o: character.cpp character.hpp
	g++ -std=c++11 -c character.cpp

game.o: game.cpp game.hpp
	g++ -std=c++11 -c game.cpp

Item.o: Item.cpp Item.hpp
	g++ -std=c++11 -c Item.cpp

medbay.o: medbay.cpp medbay.hpp
	g++ -std=c++11 -c medbay.cpp

room.o: room.cpp room.hpp
	g++ -std=c++11 -c room.cpp

utilityFunctions.o: utilityFunctions.cpp utilityFunctions.hpp
	g++ -std=c++11 -c utilityFunctions.cpp

corridor1.o: corridor1.cpp corridor1.hpp
	g++ -std=c++11 -c corrdior1.cpp


clean:
	rm *.o nashville
