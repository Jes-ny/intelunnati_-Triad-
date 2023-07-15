#include <stdio.h>


// Define the states
enum State {
    Room0,
    Room1,
    Room2,
    Room3,
    Room4,
    Room5,
    Room6,
    Room7
};

// Define the inputs
enum Input {
    Zero,
    One
};

// Define the outputs
const char* locationStrings[] = {
    "Room0",
    "Room1",
    "Room2",
    "Room3",
    "Room4",
    "Room5",
    "Room6",
    "Room7"
};

// Define the state transition table
const enum State transitionTable[8][2] = {
    { Room1, Room0 },
    { Room2, Room1 },
    { Room3, Room2 },
    { Room4, Room3 },
    { Room5, Room4 },
    { Room6, Room5 },
    { Room7, Room6 },
    { Room0, Room7 }
};

// Define the output table
const char* outputTable[8][2] = {
    { "Room1", "Room0" },
    { "Room2", "Room1" },
    { "Room3", "Room2" },
    { "Room4", "Room3" },
    { "Room5", "Room4" },
    { "Room6", "Room5" },
    { "Room7", "Room6" },
    { "Room0", "Room7" }
};

// Function to execute the FSM based on the binary travel plans
void executeFSM(int* travelPlans, int numPlans) {
    enum State currentState = Room0;

    printf("Starting location: %s\n", locationStrings[currentState]);

    for (int i = 0; i < numPlans; i++) {
        enum Input input = travelPlans[i] == 0 ? Zero : One;
        enum State nextState = transitionTable[currentState][input];
        const char* output = outputTable[currentState][input];

        printf("Move %d: %s -> %s\n", i + 1, locationStrings[currentState], output);

        currentState = nextState;
    }

    printf("Final location: %s\n", locationStrings[currentState]);
}

int main() {
    int travelPlans[] = { 1, 0, 0, 0, 1 }; // Example travel plans
    int numPlans = sizeof(travelPlans) / sizeof(travelPlans[0]);

    executeFSM(travelPlans, numPlans);

    return 0;
}