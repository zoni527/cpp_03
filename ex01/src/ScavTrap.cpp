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
: ClapTrap( C_B_HI_C "sane_default" C_RST ) {

	std::cout << scav_trap_str + "	default constructor called" << std::endl;
	_hit_points		= _max_hp	= SCAVTRAP_HIT_POINTS;
	_energy_points	= _max_ep	= SCAVTRAP_ENERGY_POINTS;
	_attack_damage	= SCAVTRAP_ATTACK_DAMAGE;
}

ScavTrap:: ScavTrap( std::string const &name )
: ClapTrap( C_B_HI_C + name + C_RST ) {

	std::cout << scav_trap_str + "	string constructor called" << std::endl;
	_hit_points		= _max_hp	= SCAVTRAP_HIT_POINTS;
	_energy_points	= _max_ep	= SCAVTRAP_ENERGY_POINTS;
	_attack_damage				= SCAVTRAP_ATTACK_DAMAGE;
}

ScavTrap:: ScavTrap( ScavTrap const &src )
: ClapTrap( C_B_HI_C + src._name + C_RST ) {

	std::cout << scav_trap_str + "	copy constructor called" << std::endl;
	if ( src._hit_points > SCAVTRAP_HIT_POINTS )
		_hit_points = SCAVTRAP_HIT_POINTS;
	else
		_hit_points = src._hit_points;
	if ( src._energy_points > SCAVTRAP_ENERGY_POINTS )
		_energy_points = SCAVTRAP_ENERGY_POINTS;
	else
		_energy_points = src._energy_points;
	_attack_damage = SCAVTRAP_ATTACK_DAMAGE;
	_max_hp = SCAVTRAP_HIT_POINTS;
	_max_ep = SCAVTRAP_ENERGY_POINTS;
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
