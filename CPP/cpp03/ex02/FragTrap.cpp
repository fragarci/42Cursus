#include "FragTrap.hpp"

FragTrap::FragTrap(const FragTrap &o) : ClapTrap(o._name) { *this = o; }

FragTrap::FragTrap(void) {}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	this->_hit_points = 100;
	this->_energy_points = 100;
	this->_attack_damage = 30;
	std::cout << "[ FragTrap " << this->_name << " ] Has been created" << std::endl;
}

FragTrap::~FragTrap() { std::cout << "[ FragTrap " << this->_name << " ] Has been destroyed" << std::endl; }

void FragTrap::highFiveGuys(void)
{
	if (this->_hit_points <= 0)
		std::cout << "[ FragTrap " << this->_name << " ] The FragTrap you are trying to contact is DEAD, please, don't call us again ;3" << std::endl;
	else if (this->_energy_points <= 0)
		std::cout << "[ FragTrap " << this->_name << " ] No high five pwz, rlly tired rn swwy" << std::endl;
	else
		std::cout << "[ FragTrap " << this->_name << " ] HIGH FIVE BROOO" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap &o)
{
	if (this == &o)
		return (*this);
	this->_name = o._name;
	this->_hit_points = o._hit_points;
	this->_energy_points = o._energy_points;
	this->_attack_damage = o._attack_damage;
	return (*this);
}
