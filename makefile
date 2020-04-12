
proj: projectDriver.o doublyLinkedList.o hash.o dictionary.o
		g++ -std=c++11 -o proj projectDriver.o doublyLinkedList.o hash.o dictionary.o

doublyLinkedList.o: doublyLinkedList.cpp
		g++ -std=c++11 -c -g doublyLinkedList.cpp

hash.o: hash.cpp
		g++ -std=c++11 -c -g hash.cpp
		
dictionary.o: dictionary.cpp
		g++ -std=c++11 -c -g dictionary.cpp

projectDriver.o: projectDriver.cpp
		g++ -std=c++11 -c -g projectDriver.cpp

clean:
				rm *.o proj
