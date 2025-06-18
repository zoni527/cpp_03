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
#include "ansi_colors.hpp"
#include <iostream>


const std::string	scav_trap_str = C_B_C "ScavTrap" C_RST;

// ------------------------------------------------------------ member functions

void	ScavTrap:: attack( std::string const &target ) {

	if ( _hit_points == 0 ) {
		std::cout
			<< scav_trap_str + "	" << _name << " is KO, can't attack "
			<< target << std::endl;
		return;
	}
	if ( _energy_points == 0 ) {
		std::cout
			<< scav_trap_str + "	" << _name << " is out of energy, can't attack "
			<< target << std::endl;
		return;
	}
	--_energy_points;
	std::cout
		<< scav_trap_str + "	" << _name << " attacks " << target
		<< ", causing " << _attack_damage << " points of damage! It has "
		<< _energy_points << " energy points left" << std::endl;
}

void	ScavTrap:: guardGate( void ) {
	std::cout
		<< scav_trap_str + "	" << _name << " is now in Gate keeper mode" << std::endl;
}

// ---------------------------------------------------------------- constructors

ScavTrap:: ScavTrap( void )
: ClapTrap(	C_B_HI_C "sane_default" C_RST,
			SCAVTRAP_HIT_POINTS,
			SCAVTRAP_ENERGY_POINTS,
			SCAVTRAP_ATTACK_DAMAGE) {
	std::cout << scav_trap_str + "	default constructor called" << std::endl;
}

ScavTrap:: ScavTrap( std::string const &name )
: ClapTrap(	C_B_HI_C + name + C_RST,
			SCAVTRAP_HIT_POINTS,
			SCAVTRAP_ENERGY_POINTS,
			SCAVTRAP_ATTACK_DAMAGE ) {
	std::cout << scav_trap_str + "	string constructor called" << std::endl;
}

ScavTrap:: ScavTrap( ScavTrap const &src )
: ClapTrap( src ) {
	std::cout << scav_trap_str + "	copy constructor called" << std::endl;
}

// ------------------------------------------------------------------ destructor

ScavTrap:: ~ScavTrap( void ) {
	std::cout << scav_trap_str + "	destructor called" << std::endl;
}

// --------------------------------------------------- member operator overloads

ScavTrap &ScavTrap:: operator = ( ScavTrap const &src ) {

	std::cout << scav_trap_str + "	assignment operator called" << std::endl;
	if ( this == &src )
		return *this;
	ClapTrap:: operator=( src );
	return *this;
}
