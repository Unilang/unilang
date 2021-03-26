// this example should print out "Hello, World!", four times
#include <iostream>
#include "BrainTree.h"

class Action : public BrainTree::Node
{
public:
    Status update() override
    {
        std::cout << "Hello, World!" << std::endl;
        return Node::Status::Success;
    }
};

void CreatingBehaviorTreeManually()
{
    BrainTree::BehaviorTree tree;
    auto sequence = std::make_shared<BrainTree::Sequence>();
    auto sayHello = std::make_shared<Action>();
    auto sayHelloAgain = std::make_shared<Action>();
    sequence->addChild(sayHello);
    sequence->addChild(sayHelloAgain);
    tree.setRoot(sequence);
    tree.update();
}

void CreatingBehaviorTreeUsingBuilders()
{
    auto tree = BrainTree::Builder()
        .composite<BrainTree::Sequence>()
            .leaf<Action>()
            .leaf<Action>()
        .end()
        .build();
    tree->update();
}

int main()
{
    CreatingBehaviorTreeManually();
    CreatingBehaviorTreeUsingBuilders();
    return 0;
}