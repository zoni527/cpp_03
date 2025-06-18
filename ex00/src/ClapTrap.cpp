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
#include "ansi_colors.hpp"
#include <iostream>
#include <climits>
const std::string	clap_trap_str = C_B_P "ClapTrap" C_RST;

// ------------------------------------------------------------ member functions

std::string ClapTrap:: getName( void ) const {
	return _name;
}

unsigned int ClapTrap:: getHP( void ) const {
	return _hit_points;
}

unsigned int ClapTrap:: getEP( void ) const {
	return _energy_points;
}

unsigned int ClapTrap:: getAD( void ) const {
	return _attack_damage;
}

void ClapTrap:: setName( std::string const &str ) {
	_name = str;
}

void ClapTrap:: setHP( unsigned int hp ) {
	_hit_points = hp;
}

void ClapTrap:: setEP( unsigned int ep ) {
	_energy_points = ep;
}

void ClapTrap:: setAD( unsigned int ad ) {
	_energy_points = ad;
}

void ClapTrap:: attack( std::string const &target ) {

	if ( _hit_points == 0 ) {
		std::cout
			<< clap_trap_str + "	" << _name << " is KO, can't attack "
			<< target << std::endl;
		return;
	}
	if ( _energy_points == 0 ) {
		std::cout
			<< clap_trap_str + "	" << _name << " is out of energy, can't attack "
			<< target << std::endl;
		return;
	}
	--_energy_points;
	std::cout
		<< clap_trap_str + "	" << _name << " attacks " << target
		<< ", causing " << _attack_damage << " points of damage! It now has "
		<< _energy_points << " energy points left" << std::endl;
}

void ClapTrap:: takeDamage( unsigned int amount ) {

	if ( _hit_points == 0 ) {
		std::cout
			<< clap_trap_str + "	" << _name << " is already KO, don't beat a dead horse!"
			<< std::endl;
		return;
	}
	if ( amount >= _hit_points ) {
		_hit_points = 0;
		std::cout
			<< clap_trap_str + "	" << _name << " has taken " << amount
			<< " points of damage and is now KO" << std::endl;
		return;
	}
	_hit_points -= amount;
	std::cout
		<< clap_trap_str + "	" << _name << " has taken " << amount
		<< " points of damage and now has " << _hit_points << " hit points left"
		<< std::endl;
}

void ClapTrap:: beRepaired( unsigned int amount ) {

	if ( amount > CLAPTRAP_HIT_POINTS || amount > CLAPTRAP_HIT_POINTS - _hit_points )
		_hit_points = CLAPTRAP_HIT_POINTS;
	else
		_hit_points += amount;
	std::cout
		<< clap_trap_str + "	" << _name << " has been repaired by " << amount
		<< " hit points and it now has " << _hit_points << " points of health"
		<< std::endl;
}

// ---------------------------------------------------------------- constructors

ClapTrap:: ClapTrap( void ) : _name( C_B_HI_P "sane_default" C_RST ) {
	std::cout << clap_trap_str + "	default constructor called" << std::endl;
}

ClapTrap:: ClapTrap( std::string const &name ) : _name( C_B_HI_P + name + C_RST ) {
	std::cout << clap_trap_str + "	string constructor called" << std::endl;
}

ClapTrap:: ClapTrap( ClapTrap const &src ) : _name( C_B_HI_P + src._name + C_RST ) {
	std::cout << clap_trap_str + "	copy constructor called" << std::endl;
}

// ------------------------------------------------------------------ destructor

ClapTrap:: ~ClapTrap( void ) {
	std::cout << clap_trap_str + "	destructor called" << std::endl;
}

// --------------------------------------------------- member operator overloads

ClapTrap &ClapTrap:: operator = ( ClapTrap const &src ) {

	std::cout << clap_trap_str + "	assignment operator called" << std::endl;
	if ( this == &src )
		return *this;
	_name = src._name;
	_hit_points = src._hit_points;
	_energy_points = src._energy_points;
	_attack_damage = src._attack_damage;
	return *this;
}
