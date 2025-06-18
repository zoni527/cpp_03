/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvarila <jvarila@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 13:10:04 by jvarila           #+#    #+#             */
/*   Updated: 2025/06/10 13:12:58 by jvarila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ansi_colors.hpp"
#include <iostream>

const std::string	frag_trap_str = C_B_R "FragTrap" C_RST;

// ------------------------------------------------------------ member functions

void	FragTrap:: attack( std::string const &target ) {

	if ( _hit_points == 0 ) {
		std::cout
			<< frag_trap_str + "	" << _name << " is KO, can't attack "
			<< target << std::endl;
		return;
	}
	if ( _energy_points == 0 ) {
		std::cout
			<< frag_trap_str + "	" << _name << " is out of energy, can't attack "
			<< target << std::endl;
		return;
	}
	--_energy_points;
	std::cout
		<< frag_trap_str + "	" << _name << " attacks " << target
		<< ", causing " << _attack_damage << " points of damage!" << std::endl;
}

void	FragTrap:: highFivesGuys( void ) {
	std::cout
		<< frag_trap_str + "	" << _name << " sends you a positive high fives request"
		<< std::endl;
}

// ---------------------------------------------------------------- constructors

FragTrap:: FragTrap( void )
: ClapTrap( C_B_HI_R "sane_default" C_RST ) {

	std::cout << frag_trap_str << "	default constructor called" << std::endl;
	_hit_points		= _max_hp	= FRAGTRAP_HIT_POINTS;
	_energy_points	= _max_ep	= FRAGTRAP_ENERGY_POINTS;
	_attack_damage	= FRAGTRAP_ATTACK_DAMAGE;
}

FragTrap:: FragTrap( std::string const &name )
: ClapTrap( C_B_HI_R + name + C_RST ) {

	std::cout << frag_trap_str << "	string constructor called" << std::endl;
	_name			= C_B_HI_R + name + C_RST;
	_hit_points		= _max_hp	= FRAGTRAP_HIT_POINTS;
	_energy_points	= _max_ep	= FRAGTRAP_ENERGY_POINTS;
	_attack_damage				= FRAGTRAP_ATTACK_DAMAGE;

}

FragTrap:: FragTrap( FragTrap const &src )
: ClapTrap( C_B_HI_R + src._name + C_RST ) {

	std::cout << frag_trap_str << "	copy constructor called" << std::endl;
	if ( src._hit_points > FRAGTRAP_HIT_POINTS )
		_hit_points = FRAGTRAP_HIT_POINTS;
	else
		_hit_points = src._hit_points;
	if ( src._energy_points > FRAGTRAP_ENERGY_POINTS )
		_energy_points = FRAGTRAP_ENERGY_POINTS;
	else
		_energy_points = src._energy_points;
	_attack_damage = FRAGTRAP_ATTACK_DAMAGE;
	_max_hp = FRAGTRAP_HIT_POINTS;
	_max_ep = FRAGTRAP_ENERGY_POINTS;
}

// ------------------------------------------------------------------ destructor

FragTrap:: ~FragTrap( void ) {
	std::cout << frag_trap_str << "	destructor called" << std::endl;
}

// --------------------------------------------------- member operator overloads

FragTrap &FragTrap:: operator = ( FragTrap const &src ) {

	std::cout << frag_trap_str << "	assignment operator called" << std::endl;
	if ( this == &src )
		return *this;
	ClapTrap:: operator=( src );
	return *this;
}
