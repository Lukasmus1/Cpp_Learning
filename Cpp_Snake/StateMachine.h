#pragma once
#include "States.h"


class StateMachine {
private:
    StateMachine() :
        state(States::MENU){}
    ~StateMachine() = default;
    States state;

public:
    StateMachine(const StateMachine&) = delete; // Forbid passing a copy as an argument e.g., func(StateMachine s)
    StateMachine& operator=(const StateMachine&) = delete; // Forbid copying the class e.g., c1 = c2

    static StateMachine& getInstance() {
        static StateMachine instance;
        return instance;
    }

    States getState() const;
    void switchState(States newState);
};
