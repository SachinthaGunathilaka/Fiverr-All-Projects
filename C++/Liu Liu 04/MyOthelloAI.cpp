#include<ics46/factory/DynamicFactory.hpp>
#include"MyOthelloAI.hpp"

ICS46_DYNAMIC_FACTORY_REGISTER(OthelloAI, liu::MyOthelloAI, "LiuRequired");

std::pair<int, int>liu::MyOthelloAI::chooseMove(const OthelloGameState& state){
    std::pair<int, int> bestMove;
    bestMove.first = -1;
    bestMove.second = -1;


    char color = state.isWhiteTurn() ? 'w' : 'b';
    int bestScore = -1000;
    for (int i = 0; i < state.board().height(); i++)
    {
        for (int j = 0; j < state.board().width(); j++)
        {
            if(state.isValidMove(i, j)){
                std::unique_ptr<OthelloGameState> temp_state = state.clone();
                temp_state->makeMove(i, j);
                // std::unique_ptr<OthelloGameState, std::default_delete<OthelloGameState>> temp_state = state.clone();

                int new_score = search(temp_state, 100, color);
                if(new_score >= bestScore){
                    bestMove.first = i;
                    bestMove.second = j;
                    bestScore = new_score;
                }                
            }
        }
        
    }
    
    return bestMove;
}

int liu::MyOthelloAI::evaluate(std::unique_ptr<OthelloGameState> & state, char color){

    if(color == 'w'){
        return state->whiteScore() - state->blackScore();
    }
    else{
        return state->blackScore() - state->whiteScore();
    }
    
}

int liu::MyOthelloAI::search(std::unique_ptr<OthelloGameState> & state, int depth, char color){

    int isMyTurn = 0;

    if((state->isBlackTurn() && color == 'b') && (state->isWhiteTurn() && color == 'w')){
        isMyTurn = 1;
    }
    if((depth == 0) || (state->isGameOver())){
        return evaluate(state, color);
    }

    if(isMyTurn){

        int bestVal = -10000;
        for (int i = 0; i < state->board().height(); i++)
        {
            for (int j = 0; j < state->board().width(); j++)
            {
                if(state->isValidMove(i, j)){
                    std::unique_ptr<OthelloGameState> temp_state = state->clone();
                    temp_state->makeMove(i, j);

                    int temp = search(temp_state, depth-1, color);
                    bestVal = std::max(bestVal, temp);

                    return bestVal;       
                }
            }
            
        }

        return bestVal;
    }

    else{
        int bestVal = 10000;
        for (int i = 0; i < state->board().height(); i++)
        {
            for (int j = 0; j < state->board().width(); j++)
            {
                if(state->isValidMove(i, j)){
                    std::unique_ptr<OthelloGameState> temp_state = state->clone();
                    temp_state->makeMove(i, j);

                    int temp = search(temp_state, depth-1, color);
                    bestVal = std::min(bestVal, temp);

                    return bestVal;       
                }
            }
            
        }
        return bestVal;

    }
        
}
