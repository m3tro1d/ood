#include "Ducks/CDuck.h"
#include "Ducks/CMallardDuck.h"
#include <iostream>

void PlayWithDuck(CDuck& duck);

int main()
{
	CMallardDuck mallardDuck;
	PlayWithDuck(mallardDuck);

	// CRedheadDuck redheadDuck;
	// PlayWithDuck(redheadDuck);
	//
	// CRubberDuck rubberDuck;
	// PlayWithDuck(rubberDuck);
	//
	// CDecoyDuck decoyDuck;
	// PlayWithDuck(decoyDuck);
	//
	// CModelDuck modelDuck;
	// PlayWithDuck(modelDuck);
	// modelDuck.SetFlyBehavior(std::make_unique<CFlyWithWings>());
	// PlayWithDuck(modelDuck);

	return EXIT_SUCCESS;
}

void DrawDuck(CDuck const& duck)
{
	duck.Display();
}

void PlayWithDuck(CDuck& duck)
{
	DrawDuck(duck);
	duck.Quack();
	duck.Fly();
	duck.Dance();
	duck.Fly();
	std::cout << std::endl;
}
