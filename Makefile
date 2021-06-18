# also need to add -lMyRootStuff to L81 or root-config

C++ = g++
C_FLAGS = -g 

# -fPIC for rivet...
ROOTCFLAGS=$(shell root-config --cflags) #-fPIC
ROOTLIBS=$(shell root-config --libs)

SOURCES = TBrowser.cpp root-mkhtml.cpp

all : libMyRootStuff.so $(SOURCES:.cpp=)

clean:
	rm $(SOURCES:.cpp=)
	rm libMyRootStuff.so
	rm ${ROOTSYS}/lib/*MyRootStuff*
	rm ${ROOTSYS}/include/*MyRootStuff*

libMyRootStuff.so: MyRootStuff.cpp MyRootStuff.h
	$(C++) $(ROOTCFLAGS) $(C_FLAGS) -c MyRootStuff.cpp  -shared -o libMyRootStuff.so
	cp libMyRootStuff.so ${ROOTSYS}/lib/
	cp MyRootStuff.h ${ROOTSYS}/include/



%: %.cpp 
	$(C++) $(ROOTCFLAGS) $(C_FLAGS) $<  -o $@  $(ROOTLIBS) 
	cp $@ ${ROOTSYS}/bin/







