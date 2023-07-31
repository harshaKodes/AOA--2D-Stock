CXX=clang++
CXXFLAGS=-g -std=c++11 -Wall -pedantic
JFLAGS = -g
JC = javac
JVM= java
MAIN = stock
all: BuySellSingle-bforce.cpp BuySellSingle-bforce.o
		$(CXX) -o task1 BuySellSingle-bforce.cpp
		./task1
Task1: BuySellSingle-bforce.cpp BuySellSingle-bforce.o
		$(CXX) -o task1 BuySellSingle-bforce.cpp
		./task1
Task2: BuySellSingle-greedy.cpp BuySellSingle-greedy.o
		$(CXX) -o task2 BuySellSingle-greedy.cpp
		./task2
Task3A: BuySellSingle-dp_rec_mem.cpp BuySellSingle-dp_rec_mem.o
		$(CXX) -o task3A BuySellSingle-dp_rec_mem.cpp
		./task3A
Task3B: BuySellSingle-dp_itr_btm.cpp BuySellSingle-dp_itr_btm.o
		$(CXX) -o task3B BuySellSingle-dp_itr_btm.cpp
		./task3B

Task4:
	javac Task4.java
	java Task4

Task5:
	javac Task5.java
	java Task5

Task6A:
	javac Task6A.java
	java Task6A

Task6B:
	javac Task6B.java
	java Task6B

Task7: BuySellCooldown-bforce.cpp BuySellCooldown-bforce.o
		$(CXX) -o task7 BuySellCooldown-bforce.cpp
		./task7

Task9A: BuySellCooldown-dp_mem.cpp BuySellCooldown-dp_mem.o
		$(CXX) -o task9A BuySellCooldown-dp_mem.cpp
		./task9A