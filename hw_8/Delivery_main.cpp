#include "Delivery.cpp"
#include <vector>

int main()
{
	Factory* factory = 0;
	Delivery* delivery = 0;

	factory = new WalkerFactory;
	delivery = factory->creation(0, 5, 10, true, true);
	delivery->name();
	delivery->take_from_warehouse();
	delivery->deliver_to_customer();
	delivery->receive_tip();
	delete delivery;
	delete factory;

	factory = new ScooterFactory;
	delivery = factory->creation(3, 10, 5, false, true);
	delivery->name();
	delivery->take_from_warehouse();
	delivery->deliver_to_customer();
	delivery->receive_tip();
	delete delivery;
	delete factory;

	factory = new RobotFactory;
	delivery = factory->creation(70, 3, 15, true, false);
	delivery->name();
	delivery->take_from_warehouse();
	delivery->deliver_to_customer();
	delivery->receive_tip();
	delete delivery;
	delete factory;
	//WalkerFactory* walker_factory = new WalkerFactory;
	//ScooterFactory* scooter_factory = new ScooterFactory;
	//RobotFactory* robot_factory = new RobotFactory;
	//std::vector < Delivery* > v;

	//v.push_back(walker_factory->creation(30,12,40,1,0));
	//v.push_back(scooter_factory->creation(4, 12, 40, 0, 1));
	//v.push_back(robot_factory->creation(0, 12, 40, 0, 0));

	//for (auto i = 0U; i < v.size(); ++i)
	//{
	//	v[i]->name();
	//}

	//for (auto i = 0U; i < v.size(); ++i)
	//{
	//	delete v[i];
	//}

	//delete walker_factory;
	//delete scooter_factory;
	//delete robot_factory;
	return 0;
}