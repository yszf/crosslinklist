#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "scene.h"

#ifdef _WIN32
#include "vld.h"
#define SRandom srand
#define Random rand
#else
#define SRandom srandom
#define Random random
#endif



int main() {
    int i = 0;
    Scene scene;

	SRandom((unsigned)time(NULL));
    printf("\nbegin add object=============\n");
    for (i = 0; i < 10; ++i) {
		int x = Random() % 50;
		int y = Random() % 50;
        scene.Add(i + 1, x, y);
    }

	scene.PrintList();
	cout << endl;
	for (i = 0; i < 10; ++i) {
		scene.PrintAOI(i + 1);
	}


    printf("\nbegin move object=============\n");
    for (i = 0; i < 100; ++i) {
        int x = Random() % 50;
        int y = Random() % 50;
        scene.Move(i % 10, x, y);
    }

	scene.PrintList();
	cout << endl;
	for (i = 0; i < 10; ++i) {
		scene.PrintAOI(i + 1);
	}

    printf("\nbegin leave object=============\n");
    for (i = 0; i < 10; ++i) {
        scene.Leave(i + 1);
    }

    return 0;
}
