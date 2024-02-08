#include "Delivery.cpp"
#include <vector>

int main()
{
	Factory* factory = 0;
	Delivery* delivery = 0;

	factory = new WalkerFactory;
	delivery = factory->creation(5, true);
	delivery->name();
	delivery->take_from_warehouse();
	delivery->deliver_to_customer();
	delivery->receive_tip();
	delete delivery;
	delete factory;

	factory = new CarFactory;
	delivery = factory->creation(30, true);
	delivery->name();
	delivery->take_from_warehouse();
	delivery->deliver_to_customer();
	delivery->receive_tip();
	delete delivery;
	delete factory;

	factory = new RobotFactory;
	delivery = factory->creation(15, true);
	delivery->name();
	delivery->take_from_warehouse();
	delivery->deliver_to_customer();
	delivery->receive_tip();
	delete delivery;
	delete factory;

	return 0;
}
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
	//return 0;
//}
