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
#include "ansi_colors.hpp"
#include <iostream>

const std::string	diamond_trap_str = C_B_Y "DiamondTrap" C_RST;
const std::string	clap_trap_str = C_B_P "ClapTrap" C_RST;

// ------------------------------------------------------------ member functions

void DiamondTrap:: attack( std::string const &target ) {
	ScavTrap:: attack( target );
}

void DiamondTrap:: whoAmI( void ) {
	std::cout
		<< "My " + diamond_trap_str + " name is " + _name << "" << std::endl
		<< "My " + clap_trap_str + " name is " + ClapTrap:: _name << std::endl;
}

// ---------------------------------------------------------------- constructors

DiamondTrap:: DiamondTrap( void )
:	ClapTrap(	C_B_HI_P "sane_default_clap_name" C_RST,
				FRAGTRAP_HIT_POINTS,
				SCAVTRAP_ENERGY_POINTS,
				FRAGTRAP_ATTACK_DAMAGE ),
	_name( C_B_HI_Y "sane_default" C_RST ) {
	std::cout << diamond_trap_str + "	default constructor called" << std::endl;
}

DiamondTrap:: DiamondTrap( std::string const &name )
: ClapTrap( C_B_HI_P + name + "_clap_name" + C_RST, 100, 50, 30 ),
_name( C_B_HI_Y + name + C_RST ) {
	std::cout << diamond_trap_str + "	string constructor called" << std::endl;
}

DiamondTrap:: DiamondTrap( DiamondTrap const &src )
:	ClapTrap(	src._name, 
				FRAGTRAP_HIT_POINTS,
				SCAVTRAP_ENERGY_POINTS,
				FRAGTRAP_ATTACK_DAMAGE ) {
	ClapTrap:: _name = src.ClapTrap::_name;
	std::cout << diamond_trap_str + "	copy constructor called" << std::endl;
}

// ------------------------------------------------------------------ destructor

DiamondTrap:: ~DiamondTrap( void ) {
	std::cout << diamond_trap_str + "	destructor called" << std::endl;
}

// --------------------------------------------------- member operator overloads

DiamondTrap &DiamondTrap:: operator = ( DiamondTrap const &src ) {

	std::cout << diamond_trap_str + "	assignment operator called" << std::endl;
	if ( this == &src )
		return *this;
	ClapTrap:: operator=( src );
	ClapTrap:: _name = src.ClapTrap::_name;
	return *this;
}
