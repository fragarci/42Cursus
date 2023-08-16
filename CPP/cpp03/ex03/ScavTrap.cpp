#include "ScavTrap.hpp"

ScavTrap::ScavTrap(const ScavTrap &o) : ClapTrap(o._name) { *this = o; }

ScavTrap::ScavTrap(void) {}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	this->_hit_points = 100;
	this->_energy_points = 50;
	this->_attack_damage = 20;
	std::cout << "[ ScavTrap " << this->_name << " ] Has been created" << std::endl;
}

ScavTrap::~ScavTrap() { std::cout << "[ ScavTrap " << this->_name << " ] Has been destroyed" << std::endl; }

void	ScavTrap::attack(const std::string &target)
{
	if (this->_hit_points <= 0)
		std::cout << "[ ScavTrap " << this->_name << " ] Beep Boop, I'm dead ~w~" << std::endl;
	else if (this->_energy_points <= 0)
		std::cout << "[ ScavTrap " << this->_name << " ] is eepy and needs a smol sleeb" << std::endl;
	else
		std::cout << "[ ScavTrap " << this->_name << " ]" <<
		" attacks " << target <<
		" causing " << this->_attack_damage <<
		" points of damage! Energy points remaining: " << --this->_energy_points << std::endl;
}

void ScavTrap::guardGate(void)
{
	if (this->_hit_points <= 0)
		std::cout << "[ ScavTrap " << this->_name << " ] Sowwy for the inconvenience but I'm dead *w*" << std::endl;
	else if (this->_energy_points <= 0)
		std::cout << "[ ScavTrap " << this->_name << " ] I'm sooo tired I can't guard the gate now sowwy >~<" << std::endl;
	else
		std::cout << "[ ScavTrap " << this->_name << " ] Is now in gate keeper mode" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap &o)
{
	if (this == &o)
		return (*this);
	this->_name = o._name;
	this->_hit_points = o._hit_points;
	this->_energy_points = o._energy_points;
	this->_attack_damage = o._attack_damage;
	return (*this);
}
