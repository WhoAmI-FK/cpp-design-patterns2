#include "Prototype.h"

int main()
{
	proto::Sheep* sheep0 = new proto::Sheep();
	sheep0->setHairColor("white");
	sheep0->setTail(5);
	sheep0->setWeight(90);
	sheep0->setHeight(1);
	sheep0->setAge(5);

	proto::Cow* cow0 = new proto::Cow();

	cow0->setHairColor("brown");
	cow0->setTail(20);
	cow0->setWeight(790);
	cow0->setHeight(2);
	cow0->setAge(8);

	proto::Animal* farm[3];
	farm[0] = sheep0->clone();
	farm[1] = cow0->clone();
	farm[1]->setWeight(1000);
	sheep0->shearing();
	farm[2] = sheep0->clone();


	delete sheep0;
	delete cow0;
	return 0;
}