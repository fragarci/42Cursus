#include "ScavTrap.hpp"

ScavTrap::ScavTrap(const ScavTrap &o) { *this = o; }

ScavTrap::ScavTrap(void) {}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{

}

ScavTrap::~ScavTrap()
{

}


ScavTrap& ScavTrap::operator=(const ScavTrap &o)
{

}
