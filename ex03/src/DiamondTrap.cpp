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
: ClapTrap( C_B_HI_P "sane_default_clap_name" C_RST ) {

	std::cout << diamond_trap_str << "	default constructor called" << std::endl;
	_hit_points		= _max_hp	= FRAGTRAP_HIT_POINTS;
	_energy_points	= _max_ep	= SCAVTRAP_ENERGY_POINTS;
	_attack_damage	= FRAGTRAP_ATTACK_DAMAGE;
}

DiamondTrap:: DiamondTrap( std::string const &name )
: ClapTrap( C_B_HI_P + name + "_clap_name" + C_RST ) {

	std::cout << diamond_trap_str << "	string constructor called" << std::endl;
	_name			= C_B_HI_Y + name + C_RST;
	_hit_points		= _max_hp	= FRAGTRAP_HIT_POINTS;
	_energy_points	= _max_ep	= SCAVTRAP_ENERGY_POINTS;
	_attack_damage				= FRAGTRAP_ATTACK_DAMAGE;

}

DiamondTrap:: DiamondTrap( DiamondTrap const &src )
: ClapTrap( C_B_HI_P + src._name + "_clap_name" + C_RST ) {

	std::cout << diamond_trap_str << "	copy constructor called" << std::endl;
	_name = src._name;
	if ( src._hit_points > FRAGTRAP_HIT_POINTS )
		_hit_points = FRAGTRAP_HIT_POINTS;
	else
		_hit_points = src._hit_points;
	if ( src._energy_points > SCAVTRAP_ENERGY_POINTS )
		_energy_points = SCAVTRAP_ENERGY_POINTS;
	else
		_energy_points = src._energy_points;
	_attack_damage = FRAGTRAP_ATTACK_DAMAGE;
	_max_hp = FRAGTRAP_HIT_POINTS;
	_max_ep = SCAVTRAP_ENERGY_POINTS;
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
