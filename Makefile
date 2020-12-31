
all: run

run: button.o display.o main.o mainMenu.o mainScene.o rocket.o thrustParticle.o usefulFunctions.o vector.o
	gcc -std=c89 -Wall button.o display.o main.o mainMenu.o mainScene.o rocket.o thrustParticle.o usefulFunctions.o vector.o -lGL -lglut -lGLU -lm


button.o: button.c
	gcc -std=c89 -Wall -c button.c -lGL -lglut -lGLU -lm

display.o: display.c
	gcc -std=c89 -Wall -c display.c -lGL -lglut -lGLU -lm

main.o: main.c
	gcc -std=c89 -Wall -c main.c -lGL -lglut -lGLU -lm

mainMenu.o: mainMenu.c
	gcc -std=c89 -Wall -c mainMenu.c -lGL -lglut -lGLU -lm

mainScene.o: mainScene.c
	gcc -std=c89 -Wall -c mainScene.c -lGL -lglut -lGLU -lm

rocket.o: rocket.c
	gcc -std=c89 -Wall -c rocket.c -lGL -lglut -lGLU -lm

thrustParticle.o: thrustParticle.c
	gcc -std=c89 -Wall -c thrustParticle.c -lGL -lglut -lGLU -lm

usefulFunctions.o: usefulFunctions.c
	gcc -std=c89 -Wall -c usefulFunctions.c -lGL -lglut -lGLU -lm

vector.o: vector.c
	gcc -std=c89 -Wall -c vector.c -lGL -lglut -lGLU -lm
