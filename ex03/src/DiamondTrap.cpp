/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvarila <jvarila@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 10:24:41 by jvarila           #+#    #+#             */
/*   Updated: 2025/06/11 11:31:37 by jvarila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
#include <iostream>

#define BYELLOW		"\033[1;33m\001"
#define BPURPLE		"\033[1;35m\001"
#define BHIYELLOW	"\033[1;93m\001"
#define RESET		"\033[0m\002"

const std::string	diamond_trap_str = BYELLOW "DiamondTrap" RESET;
const std::string	clap_trap_str = BPURPLE "ClapTrap" RESET;

// ------------------------------------------------------------ member functions

void DiamondTrap:: attack( std::string const &target ) {
	ScavTrap:: attack( target );
}

void DiamondTrap:: whoAmI( void ) {
	std::cout
		<< "My " + diamond_trap_str + " name is " + _name << "\n"
		<< "My " + clap_trap_str + " name is " + ClapTrap:: _name << std::endl;
}

// ---------------------------------------------------------------- constructors

DiamondTrap:: DiamondTrap( void )
: ClapTrap( BPURPLE "sane_default_clap_name" RESET, 100, 50, 30 ),
	_name( BHIYELLOW "sane_default" RESET ) {
	std::cout << diamond_trap_str + " default constructor called\n";
	std::cout
		<< "A " + diamond_trap_str + " named " << _name << " has spawned into the map"
		<< std::endl;
}

DiamondTrap:: DiamondTrap( std::string const &name )
: ClapTrap( BPURPLE + name + "_clap_name" + RESET, 100, 50, 30 ) {
	std::cout << diamond_trap_str + " string constructor called\n";
	std::cout
		<< "A " + diamond_trap_str + " named " << _name << " has spawned into the map"
		<< std::endl;
}

DiamondTrap:: DiamondTrap( DiamondTrap const &src )
: ClapTrap( src ), _name( src._name ) {
	ClapTrap:: _name = src.ClapTrap::_name;
	std::cout << diamond_trap_str + " copy constructor called\n";
	std::cout
		<< "A " + diamond_trap_str + " named " << _name << " has spawned into the map"
		<< std::endl;
}

// ------------------------------------------------------------------ destructor

DiamondTrap:: ~DiamondTrap( void ) {
	std::cout << diamond_trap_str + " destructor called\n";
	std::cout
		<< "A " + diamond_trap_str + " named " << _name << " has left the map" << std::endl;
}

// --------------------------------------------------- member operator overloads

DiamondTrap &DiamondTrap:: operator = ( DiamondTrap const &src ) {

	std::cout << diamond_trap_str + " assignment operator called" << std::endl;
	if ( this == &src )
		return *this;
	ClapTrap:: operator=( src );
	ClapTrap:: _name = src.ClapTrap::_name;
	return *this;
}
