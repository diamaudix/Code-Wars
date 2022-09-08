#include <cstring>


int** SolvePuzzle(int* clues) {
	return 0;
}

int main() {

    static int clues[][16] = {
    { 2, 2, 1, 3,
      2, 2, 3, 1,
      1, 2, 2, 3,
      3, 2, 1, 3 },
    { 0, 0, 1, 2,
      0, 2, 0, 0,
      0, 3, 0, 0,
      0, 1, 0, 0 },
    };

    int outcomes[][4][4] = {
    { { 1, 3, 4, 2 },
      { 4, 2, 1, 3 },
      { 3, 4, 2, 1 },
      { 2, 1, 3, 4 } },
    { { 2, 1, 4, 3 },
      { 3, 4, 1, 2 },
      { 4, 2, 3, 1 },
      { 1, 3, 2, 4 } },
    };
    SolvePuzzle(clues[0]); // , outcomes[0]));
    SolvePuzzle(clues[1]); // , outcomes[1]));
    return 0;
}

