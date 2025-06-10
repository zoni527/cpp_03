/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvarila <jvarila@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 10:01:05 by jvarila           #+#    #+#             */
/*   Updated: 2025/06/10 11:14:34 by jvarila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include <iostream>

#define BCYAN	"\033[1;36m\001"
#define HIBBLUE	"\033[1;94m\001"
#define RESET	"\033[0m\002"

const std::string	scav_trap_str = BCYAN "ScavTrap" RESET;

// ------------------------------------------------------------ member functions

void	ScavTrap:: attack( std::string const &target ) {

	if ( _energy_points == 0 ) {
		std::cout
			<< scav_trap_str + " " << _name << " is out of energy, can't attack "
			<< target << std::endl;
		return;
	}

	--_energy_points;
	std::cout
		<< scav_trap_str + " " << _name << " attacks " << target
		<< ", causing " << _attack_damage << " points of damage!" << std::endl;
}

void	ScavTrap:: guardGate( void ) {
	std::cout
		<< scav_trap_str + " " << _name << " is now in Gate keeper mode" << std::endl;
}

// ---------------------------------------------------------------- constructors

ScavTrap:: ScavTrap( void )
: ClapTrap( HIBBLUE "sane_default" RESET, 100, 50, 20) {
	std::cout << scav_trap_str + " default constructor called\n";
	std::cout
		<< "A " + scav_trap_str + " named " << _name << " has spawned into the map"
		<< std::endl;
}

ScavTrap:: ScavTrap( std::string const &name )
: ClapTrap( HIBBLUE + name + RESET, 100, 50, 20 ) {
	std::cout << scav_trap_str + " string constructor called\n";
	std::cout
		<< "A " + scav_trap_str + " named " << _name << " has spawned into the map"
		<< std::endl;
}

ScavTrap:: ScavTrap( ScavTrap const &src )
: ClapTrap( src ) {
	std::cout << scav_trap_str + " copy constructor called\n";
	std::cout
		<< "A " + scav_trap_str + " named " << _name << " has spawned into the map"
		<< std::endl;
}

// ------------------------------------------------------------------ destructor

ScavTrap:: ~ScavTrap( void ) {
	std::cout << scav_trap_str + " destructor called\n";
	std::cout
		<< "A " + scav_trap_str + " named " << _name << " has left the map" << std::endl;
}

// --------------------------------------------------- member operator overloads

ScavTrap &ScavTrap:: operator = ( ScavTrap const &src ) {

	std::cout << scav_trap_str + " assignment operator called" << std::endl;
	if ( this == &src )
		return *this;
	ClapTrap:: operator=( src );
	return *this;
}
