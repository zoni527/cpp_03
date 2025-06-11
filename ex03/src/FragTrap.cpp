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
#include <iostream>

#define BRED	"\033[1;31m\001"
#define HIBRED	"\033[1;91m\001"
#define RESET	"\033[0m\002"

const std::string	frag_trap_str = BRED "FragTrap" RESET;

// ------------------------------------------------------------ member functions

void	FragTrap:: attack( std::string const &target ) {

	if ( _energy_points == 0 ) {
		std::cout
			<< frag_trap_str + " " << _name << " is out of energy, can't attack "
			<< target << std::endl;
		return;
	}

	--_energy_points;
	std::cout
		<< frag_trap_str + " " << _name << " attacks " << target
		<< ", causing " << _attack_damage << " points of damage!" << std::endl;
}

void	FragTrap:: highFivesGuys( void ) {
	std::cout
		<< frag_trap_str + " " << _name << " sends you a positive high fives request"
		<< std::endl;
}

// ---------------------------------------------------------------- constructors

FragTrap:: FragTrap( void )
: ClapTrap( HIBRED "sane_default" RESET, 100, 100, 30 ) {
	std::cout << frag_trap_str + " default constructor called" << std::endl;
}

FragTrap:: FragTrap( std::string const &name )
: ClapTrap( HIBRED + name + RESET, 100, 100, 30 ) {
	std::cout << frag_trap_str + " string constructor called" << std::endl;
}

FragTrap:: FragTrap( FragTrap const &src )
: ClapTrap( src ) {
	std::cout << frag_trap_str + " copy constructor called" << std::endl;
}

// ------------------------------------------------------------------ destructor

FragTrap:: ~FragTrap( void ) {
	std::cout << frag_trap_str + " destructor called" << std::endl;
}

// --------------------------------------------------- member operator overloads

FragTrap &FragTrap:: operator = ( FragTrap const &src ) {

	std::cout << frag_trap_str + " assignment operator called" << std::endl;
	if ( this == &src )
		return *this;
	ClapTrap:: operator=( src );
	return *this;
}
