#include"OthelloAI.hpp"

namespace liu
{
    class MyOthelloAI:public OthelloAI
    {
    
        public:
            std::pair<int, int> chooseMove(const OthelloGameState& state) override;
            int evaluate(std::unique_ptr<OthelloGameState> & state, char color);
            int search(std::unique_ptr<OthelloGameState> & state, int depth, char color);
    };
    
}
