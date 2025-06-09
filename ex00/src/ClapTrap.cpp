/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvarila <jvarila@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 18:13:23 by jvarila           #+#    #+#             */
/*   Updated: 2025/06/09 19:39:11 by jvarila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>
#include <climits>

// ------------------------------------------------------------ member functions

void	ClapTrap:: attack( std::string const &target ) {

	if ( _energy_points == 0 ) {
		std::cout
			<< "ClapTrap " << _name << " is out of energy, can't attack "
			<< target << std::endl;
		return;
	}

	--_energy_points;
	std::cout
		<< "ClapTrap " << _name << " attacks " << target
		<< ", causing " << _attack_damage << " points of damage!" << std::endl;
}

void	ClapTrap:: takeDamage( unsigned int amount ) {

	if ( amount >= _hit_points ) {
		_hit_points = 0;
		std::cout
			<< "ClapTrap " << _name << " has taken " << amount
			<< " points of damage and is now dead, RIP" << std::endl;
		return;
	}

	_hit_points -= amount;
	std::cout
		<< "ClapTrap " << _name << " has taken " << amount
		<< " points of damage and now has " << _hit_points << " hit points"
		<< std::endl;
}

void	ClapTrap:: beRepaired( unsigned int amount ) {

	if ( _hit_points > UINT_MAX - amount ) {
		_hit_points = UINT_MAX;
		std::cout
			<< "ClapTrap " << _name << " has been repaired by " << amount
			<< " hit points and it now has INT_MAX points of health" << std::endl;
		return;
	}

	_hit_points += amount;
	std::cout
		<< "ClapTrap " << _name << " has been repaired by " << amount
		<< " hit points and it now has " << _hit_points << " points of health"
		<< std::endl;
}

// ---------------------------------------------------------------- constructors

ClapTrap:: ClapTrap( void ) : _name( "sane_default" ) {
	std::cout << "ClapTrap default constructor called\n";
	std::cout
		<< "A ClapTrap named " << _name << " has spawned into the map"
		<< std::endl;
}

ClapTrap:: ClapTrap( std::string const &name ) : _name( name ) {
	std::cout << "ClapTrap string constructor called\n";
	std::cout
		<< "A ClapTrap named " << _name << " has spawned into the map"
		<< std::endl;
}

ClapTrap:: ClapTrap( ClapTrap const &src ) : _name( src._name ) {
	std::cout << "ClapTrap copy constructor called\n";
	std::cout
		<< "A ClapTrap named " << _name << " has spawned into the map"
		<< std::endl;
}

// ------------------------------------------------------------------ destructor

ClapTrap:: ~ClapTrap( void ) {
	std::cout << "ClapTrap destructor called\n";
	std::cout
		<< "A ClapTrap named " << _name << " has left the map" << std::endl;
}

// --------------------------------------------------- member operator overloads

ClapTrap &ClapTrap:: operator = ( ClapTrap const &src ) {

	std::cout << "ClapTrap assignment operator called" << std::endl;
	if ( this == &src )
		return *this;
	_name = src._name;
	_hit_points = src._hit_points;
	_energy_points = src._energy_points;
	_attack_damage = src._attack_damage;
	return *this;
}
