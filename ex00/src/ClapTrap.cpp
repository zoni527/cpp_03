/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvarila <jvarila@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 18:13:23 by jvarila           #+#    #+#             */
/*   Updated: 2025/06/10 11:18:50 by jvarila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>
#include <climits>

#define BPURPLE		"\033[1;35m\001"
#define BHIPURPLE	"\033[1;95m\001"
#define RESET		"\033[0m\002"

const std::string	clap_trap_str = BPURPLE "ClapTrap" RESET;

// ------------------------------------------------------------ member functions

void ClapTrap:: attack( std::string const &target ) {

	if ( _energy_points == 0 ) {
		std::cout
			<< clap_trap_str + " " << _name << " is out of energy, can't attack "
			<< target << std::endl;
		return;
	}

	--_energy_points;
	std::cout
		<< clap_trap_str + " " << _name << " attacks " << target
		<< ", causing " << _attack_damage << " points of damage!" << std::endl;
}

void ClapTrap:: takeDamage( unsigned int amount ) {

	if ( amount >= _hit_points ) {
		_hit_points = 0;
		std::cout
			<< clap_trap_str + " " << _name << " has taken " << amount
			<< " points of damage and is now dead, RIP" << std::endl;
		return;
	}

	_hit_points -= amount;
	std::cout
		<< clap_trap_str + " " << _name << " has taken " << amount
		<< " points of damage and now has " << _hit_points << " hit points"
		<< std::endl;
}

void ClapTrap:: beRepaired( unsigned int amount ) {

	if ( _hit_points > UINT_MAX - amount ) {
		_hit_points = UINT_MAX;
		std::cout
			<< clap_trap_str + " " << _name << " has been repaired by " << amount
			<< " hit points and it now has UINT_MAX points of health" << std::endl;
		return;
	}

	_hit_points += amount;
	std::cout
		<< clap_trap_str + " " << _name << " has been repaired by " << amount
		<< " hit points and it now has " << _hit_points << " points of health"
		<< std::endl;
}

void ClapTrap:: printInfo( void ) {
	std::cout << "Name:		" << _name << "\n";
	std::cout << "Hit points:	" << _hit_points << "\n";
	std::cout << "Energy points:	" << _energy_points << "\n";
	std::cout << "Attack damage:	" << _attack_damage << "\n";
	std::cout << std::endl;
}

// ---------------------------------------------------------------- constructors

ClapTrap:: ClapTrap( void ) : _name( BHIPURPLE "sane_default" RESET ) {
	std::cout << clap_trap_str + " default constructor called\n";
	std::cout
		<< "A " + clap_trap_str + " named " << _name << " has spawned into the map"
		<< std::endl;
}

ClapTrap:: ClapTrap( std::string const &name ) : _name( BHIPURPLE + name + RESET ) {
	std::cout << clap_trap_str + " string constructor called\n";
	std::cout
		<< "A " + clap_trap_str + " named " << _name << " has spawned into the map"
		<< std::endl;
}

ClapTrap:: ClapTrap( ClapTrap const &src ) : _name( BHIPURPLE + src._name + RESET ) {
	std::cout << clap_trap_str + " copy constructor called\n";
	std::cout
		<< "A " + clap_trap_str + " named " << _name << " has spawned into the map"
		<< std::endl;
}

// ------------------------------------------------------------------ destructor

ClapTrap:: ~ClapTrap( void ) {
	std::cout << clap_trap_str + " destructor called\n";
	std::cout
		<< "A " + clap_trap_str + " named " << _name << " has left the map" << std::endl;
}

// --------------------------------------------------- member operator overloads

ClapTrap &ClapTrap:: operator = ( ClapTrap const &src ) {

	std::cout << clap_trap_str + " assignment operator called" << std::endl;
	if ( this == &src )
		return *this;
	_name = src._name;
	_hit_points = src._hit_points;
	_energy_points = src._energy_points;
	_attack_damage = src._attack_damage;
	return *this;
}
