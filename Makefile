CPP=g++
LD=g++



CPPFLAGS=-std=c++14
LDFLAGS=-std=c++14
LIBS=-SDL2/SDL -SDL2/SDL_image -SDL2/SDL_timer

all: Zack&RobinVSHumans

Zack&RobinVSHumans: main.o sfml_renderer.o text_renderer.o circle.o rectangle.o line.o dessin.o
	$(LD) $(LDFLAGS)  main.o sfml_renderer.o text_renderer.o circle.o rectangle.o line.o dessin.o -o displayshapes $(LIBS)


main.o: main.cpp rectangle.hpp line.hpp circle.hpp point.hpp sfml_renderer.hpp
	$(CPP) $(CPPFLAGS) -c main.cpp


circle.o: circle.cpp circle.hpp forme.hpp
	$(CPP) $(CPPFLAGS) -c circle.cpp

rectangle.o: rectangle.cpp rectangle.hpp forme.hpp
	$(CPP) $(CPPFLAGS) -c rectangle.cpp

line.o: line.cpp line.hpp forme.hpp
	$(CPP) $(CPPFLAGS) -c line.cpp

sfml_renderer.o: sfml_renderer.cpp circle.hpp rectangle.hpp line.hpp point.hpp sfml_renderer.hpp
	$(CPP) $(CPPFLAGS) -c sfml_renderer.cpp

text_renderer.o: text_renderer.cpp circle.hpp rectangle.hpp line.hpp point.hpp text_renderer.hpp
	$(CPP) $(CPPFLAGS) -c text_renderer.cpp

dessin.o: dessin.cpp forme.hpp text_renderer.hpp sfml_renderer.hpp
	$(CPP) $(CPPFLAGS) -c dessin.cpp

clean:
	rm -f *.o Zack&RobinVSHumans