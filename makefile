CC=gcc

introduction: src/1-introduction.c
	$(CC) -o bin/1-introduction src/1-introduction.c

2TachesSporadiques: src/2-taches-sporadiques.c
	$(CC) -o bin/2-taches-sporadiques src/2-taches-sporadiques.c

3TachesSporadiques: src/3-taches-sporadiques.c
	$(CC) -o bin/3-taches-sporadiques src/3-taches-sporadiques.c

4TachesSporadiques: src/4-taches-sporadiques.c
	$(CC) -o bin/4-taches-sporadiques src/4-taches-sporadiques.c -lpthread

5TachesSporadiques: src/5-taches-sporadiques.c
	$(CC) -o bin/5-taches-sporadiques src/5-taches-sporadiques.c -lpthread

6TachesPeriodiques: src/6-taches-periodiques.c
	$(CC) -o bin/6-taches-periodiques src/6-taches-periodiques.c

7TachesPeriodiques: src/7-taches-periodiques.c
	$(CC) -o bin/7-taches-periodiques src/7-taches-periodiques.c -lrt

8TachesPeriodiques: src/8-taches-periodiques.c
	$(CC) -o bin/8-taches-periodiques src/8-taches-periodiques.c -lrt

11ProgrammationPreemptive: src/11-programmation-preemptive.c
	$(CC) -o bin/11-programmation-preemptive src/11-programmation-preemptive.c -lrt

14ProgrammationPreemptive: src/14-programmation-preemptive.c
	$(CC) -o bin/14-programmation-preemptive src/14-programmation-preemptive.c -lrt

all: introduction 2TachesSporadiques 3TachesSporadiques 4TachesSporadiques 5TachesSporadiques 6TachesPeriodiques 7TachesPeriodiques 8TachesPeriodiques 11ProgrammationPreemptive 14ProgrammationPreemptive