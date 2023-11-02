#include <iostream>

class Delivery
{
protected:
	int endurance;
	int avg_delivery;
	int tips;
	bool has_license;
	bool politeness;
public:
	virtual void name() const = 0;
	virtual void take_from_warehouse() = 0;
	virtual void deliver_to_customer() = 0;
	virtual void receive_tip() = 0;

	virtual ~Delivery() {};
};
//walker
//charachetristics: average time, polite,money,license
//actions : take from storage, take to a customer, get tips, job
class Walker : public Delivery
{
public:
	Walker(int time,int money,bool polite,bool license) {
		tips = money;
		avg_delivery = time;
		politeness = polite;
		has_license = license;
	}
	virtual void name() const override {
		std::cout << "Walker" << std::endl;
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
			std::cout << "Walker received a tip of "<<tips<<"$ for being polite ^-^" <<  std::endl;
		}
		else if (!has_license) {
			std::cout<<"You are not my deliverer!Get out of my house" << std::endl;
		}
		else {
			std::cout << "Im not gonna pay you a cent, you are rude!" << std::endl;
		}
	}
};
//scooter
//charachetristics: average time, polite,money,license
//actions : take from storage, take to a customer, get tips, job
class Scooter : public Delivery
{
public:
	Scooter(int time, bool polite, bool license) {
		avg_delivery = time;
		politeness = polite;
		has_license = license;
	}
	void name() const override {
		std::cout << "Scooter" << std::endl;

	}
	void take_from_warehouse() override {
		if (has_license) {
			std::cout << "Scooter took food from warehouse" << std::endl;
		}
		else {
			std::cout << "Scooter cannot take food from warehouse without a license" << std::endl;

		}
	}
	virtual void deliver_to_customer()  override {
		if (has_license){
			std::cout << "Scooter delivered food to customer" << std::endl;
		}
		else {
			std::cout << "Error,check your license" << std::endl;
		}
	}
	virtual void receive_tip() override {
		if (politeness && has_license) {
			tips += 25;
			std::cout << "Walker received a tip of " << tips << "$ for being polite ^-^" << std::endl;
		}
		else if (!has_license) {
			std::cout << "You are not my deliverer!Get out of my house" << std::endl;
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
public:
	Robot(int end,int time, bool license) {
		endurance = end;
		avg_delivery = time;
		has_license = license;
	}
	void name() const override {
		std::cout << "Robot" << std::endl;
	}
	virtual void take_from_warehouse() override {
		if (has_license) {
			std::cout << "Robot took food from warehouse" << std::endl;
		}
		else {
			std::cout << "Robot cannot take food from warehouse without a license" << std::endl;

		}
	}
	virtual void deliver_to_customer() override{
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
	virtual Delivery* creation(int end, int money, int time, bool polite, bool license) const = 0;
	virtual ~Factory() = default;
};

class WalkerFactory : public Factory
{
public:
	virtual Delivery* creation(int end, int money, int time, bool polite, bool license) const override {
		return new Walker(time,money,polite,license);
	}
};
class ScooterFactory : public Factory
{
public:
	virtual Delivery* creation(int end, int money, int time, bool polite, bool license) const override {
		return new Scooter(time, polite, license);
	}
};
class RobotFactory : public Factory
{
public:
	virtual Delivery* creation(int end, int money, int time, bool polite, bool license) const override {
		return new Robot(end, time, license);
	}
};
