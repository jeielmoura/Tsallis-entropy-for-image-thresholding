INCLUDEPATH=code/include/
SOURCEPATH=code/source/
BUILDPATH=code/build/

LIBPATH=-I$(INCLUDEPATH)
COMPILER=g++
STD=-std=c++14

EXE=Tsallis

all: createFolder interval.o img.o prefixSum.o core.o pso.o main.o
	$(COMPILER) $(STD) $(BUILDPATH)*.o `pkg-config --libs opencv` -o Tsallis
	
createFolder:
	mkdir $(BUILDPATH)

interval.o: $(INCLUDEPATH)interval.hpp $(SOURCEPATH)interval.cpp
	$(COMPILER) -c $(STD) $(INCLUDEPATH)interval.hpp -o $(BUILDPATH)interval.hpp.gch
	$(COMPILER) -c $(STD) $(LIBPATH) $(SOURCEPATH)interval.cpp -o $(BUILDPATH)interval.o

img.o: $(INCLUDEPATH)img.hpp $(SOURCEPATH)img.cpp
	$(COMPILER) -c $(STD) `pkg-config --cflags opencv` $(INCLUDEPATH)img.hpp -o $(BUILDPATH)img.hpp.gch
	$(COMPILER) -c $(STD) `pkg-config --cflags opencv` $(LIBPATH) $(SOURCEPATH)img.cpp -o $(BUILDPATH)img.o

prefixSum.o: $(INCLUDEPATH)prefixSum.hpp $(SOURCEPATH)prefixSum.cpp
	$(COMPILER) -c $(STD) $(INCLUDEPATH)prefixSum.hpp -o $(BUILDPATH)prefixSum.hpp.gch
	$(COMPILER) -c $(STD) $(LIBPATH) $(SOURCEPATH)prefixSum.cpp -o $(BUILDPATH)prefixSum.o

core.o: $(INCLUDEPATH)core.hpp $(SOURCEPATH)core.cpp
	$(COMPILER) -c $(STD) $(INCLUDEPATH)core.hpp -o $(BUILDPATH)core.hpp.gch
	$(COMPILER) -c $(STD) $(LIBPATH) $(SOURCEPATH)core.cpp -o $(BUILDPATH)core.o

pso.o: $(SOURCEPATH)pso.cpp $(INCLUDEPATH)pso.hpp
	$(COMPILER) -c $(STD) $(INCLUDEPATH)pso.hpp -o $(BUILDPATH)pso.hpp.gch
	$(COMPILER) -c $(STD) $(LIBPATH) $(SOURCEPATH)pso.cpp -o $(BUILDPATH)pso.o

main.o: $(SOURCEPATH)main.cpp
	$(COMPILER) -c $(STD) $(LIBPATH) $(SOURCEPATH)main.cpp -o $(BUILDPATH)main.o

recompile: main.o
	$(COMPILER) $(STD) $(BUILDPATH)*.o `pkg-config --libs opencv` -o $(EXE)	

clear:
	rm -rf $(BUILDPATH)
	rm -f $(EXE)