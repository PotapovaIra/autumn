#include <iostream>
#include <random>

class Delivery
{
protected:
	//int endurance;
	int avg_delivery;
	//int tips;
	bool has_license;
	//bool politeness;
public:
	virtual void name() const = 0;
	virtual void take_from_warehouse() = 0;
	virtual void deliver_to_customer() = 0;
	virtual void receive_tip() = 0;

	virtual ~Delivery() noexcept {};
};
//walker
//charachetristics: average time, polite,money,license
//actions : take from storage, take to a customer, get tips, job
class Walker : public Delivery
{
protected:
	int tips;
	bool politeness;
public:
	Walker(int time, int money, bool polite, bool license) {
		tips = money;
		avg_delivery = time;
		politeness = polite;
		has_license = license;
	}
	virtual void name() const override {
		std::cout << "Walker,average time: " << avg_delivery << " minutes, current money: " << tips << ", polite?: " << politeness << ", license?: " << has_license << std::endl;
	}
	virtual void take_from_warehouse() override {
		if (has_license) {
			std::cout << "Walker took food from warehouse" << std::endl;
		}
		else {
			std::cout << "Walker cannot take food from warehouse without a license" << std::endl;

		}
	}
	virtual void deliver_to_customer()  override {
		if (has_license) {
			std::cout << "Walker delivered food to customer" << std::endl;
		}
		else {
			std::cout << "Error,check your license" << std::endl;
		}
	}
	virtual void receive_tip() override {
		if (politeness && has_license) {
			tips += 25;
			std::cout << "Walker received a tip of 25$ and now owns " << tips << "$ for being polite ^-^" << std::endl;
		}
		else if (!has_license) {
			std::cout << "You are not my deliverer!Get out of my house" << std::endl;
		}
		else {
			std::cout << "Im not gonna pay you a cent, you are rude!" << std::endl;
		}
	}
};
//car
//charachetristics: average time, polite,money,license
//actions : take from storage, take to a customer, get tips, job
class Car : public Delivery
{
protected:
	int fuel;
	bool politeness;
	int tips;
public:
	Car(int fuel, int time, int money, bool polite, bool license) {
		this->fuel = fuel;
		tips = money;
		avg_delivery = time;
		politeness = polite;
		has_license = license;
	}
	void name() const override {
		std::cout << "Car,average time: " << avg_delivery << " minutes, current money: " << tips << ", polite?: " << politeness << ", license?: " << has_license <<" fuel:"<< fuel << std::endl;

	}
	void take_from_warehouse() override {
		if (has_license) {
			std::cout << "Car took food from warehouse" << std::endl;
		}
		else {
			std::cout << "Car cannot take food from warehouse without a license" << std::endl;

		}
	}
	void deliver_to_customer() override {
		if (has_license && fuel > 0) {
			std::cout << "Car delivered food to customer" << std::endl;
			fuel -= 0.5;
			for (int i = 0; i < 3; i++) {
				if (rand() % 2 == 1) {
					avg_delivery += 15;
					//std::cout << "Car got stuck in traffic and delivery time increased,your food will be in " << avg_delivery << " minutes" << std::endl;
				}
			}
			std::cout << "Car got stuck in traffic and delivery time increased,your food will be in " << avg_delivery << " minutes" << std::endl;
		}
		else {
			std::cout << "Error,check your license" << std::endl;
		}
	}
	virtual void receive_tip() override {
		if (politeness && has_license && avg_delivery <= 50) {
			tips += 25;
			std::cout << "Car deliverer received a tip of 25$ and now owns " << tips << "$ for being polite ^-^" << std::endl;
		}
		else if (!has_license) {
			std::cout << "You are not my deliverer!Get out of my house" << std::endl;
		}
		else if (avg_delivery > 50) {
			std::cout << "You are late! I wont pay you a cent!" << std::endl;
		}
		else {
			std::cout << "Im not gonna pay you a cent, you are rude!" << std::endl;
		}
	}
};
//robot
//charachetristics: average time,license,endurance
//actions : take from storage, take to a customer, get tips, job
class Robot : public Delivery
{
protected:
	int endurance;
public:
	Robot(int end, int time, bool license) {
		endurance = end;
		avg_delivery = time;
		has_license = license;
	}
	void name() const override {
		std::cout << "Robot,average time: " << avg_delivery << " minutes" << ", license?: " << has_license << std::endl;
	}
	virtual void take_from_warehouse() override {
		if (has_license) {
			std::cout << "Robot took food from warehouse" << std::endl;
		}
		else {
			std::cout << "Robot cannot take food from warehouse without a license" << std::endl;

		}
	}
	virtual void deliver_to_customer() override {
		if (endurance > 50 && has_license) {
			std::cout << "Robot delivered food to customer successfully;)" << std::endl;
		}
		else {
			std::cout << "Robot crashed into a wall and could not deliver food,we`re sorry!" << std::endl;
		}
	}
	virtual void receive_tip() override {
		std::cout << "Sorry, you`re a robot!" << std::endl;
	}
};

//FACTORY
class Factory
{
public:
	virtual Delivery* creation(int time, bool license) const = 0;
	virtual ~Factory() = default;
};

class WalkerFactory : public Factory
{
public:
	virtual Delivery* creation(int time, bool license) const override {
		return new Walker(time, 0, true, license);
	}
};
class CarFactory : public Factory
{
public:
	virtual Delivery* creation(int time, bool license) const override {
		return new Car(10, time, 0, true, license);
	}
};
class RobotFactory : public Factory
{
public:
	virtual Delivery* creation(int time, bool license) const override {
		return new Robot(100, time, license);
	}
};
