#include "StateMachine.h"

States StateMachine::getState() const {
    return state;
}

void StateMachine::switchState(States newState) {
    state = newState;
}
