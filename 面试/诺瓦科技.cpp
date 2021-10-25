#include<stdio.h>

enum class State
{
    Idel,
    Run,
    End
};

State run(State state){
    State nextState=State::Idel;
    switch (state)
    {
    case State::Idel:
        puts("Start");
        nextState=State::Run;
    case State::Run:
        puts("Run");
        nextState=State::Run;
    case State::End:
        puts("End");
        nextState=State::Idel;
    default:
        puts("Error");
        nextState=State::Idel;
    }
    return nextState;
}

int main(){
    State state=State::Idel;
    while(state != State::Idel){
        state=run(state);
    }
    return 0;
}