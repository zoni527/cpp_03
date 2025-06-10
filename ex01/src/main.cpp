/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvarila <jvarila@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 09:46:37 by jvarila           #+#    #+#             */
/*   Updated: 2025/06/09 11:56:15 by jvarila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include <iostream>

#define YELLOW	"\033[0;93m\001"
#define RESET	"\033[0m\002"

static std::string	n_chars( char c, size_t n );
static void			print_test_name( std::string str );

int main( void ) {

	print_test_name( "Test: default costructor" );
	{
		ScavTrap();
	}
	print_test_name( "Test: string constructor" );
	{
		ScavTrap( "DerpyDerp" );
	}
	print_test_name( "Test: copy constructor" );
	{
		ScavTrap one( "First" );
		std::cout << "\n";
		ScavTrap two( one );
	}
	print_test_name( "Test: copy assignment operator" );
	{
		ScavTrap one( "First" ), two( "Second" );
		std::cout << "\n";
		one = two;
	}
	print_test_name( "Test: attack" );
	{
		ScavTrap().attack( "YOU" );
	}
	print_test_name( "Test: takeDamage" );
	{
		ScavTrap().takeDamage( 5 );
		std::cout << "\n";
		ScavTrap().takeDamage( -1 );
	}
	print_test_name( "Test: beRepaired" );
	{
		ScavTrap().beRepaired( 5 );
		std::cout << "\n";
		ScavTrap().beRepaired( -1 );
	}
	print_test_name( "Test: guardGate" );
	{
		ScavTrap().guardGate();
	}
	std::cout << std::endl;
	return 0;
}

// ------------------------------------------------------------ static functions

static void print_test_name( std::string str ) {

	for ( char &c : str )
		c = std::toupper( c );

	size_t width = str.length() + 10;

	std::string separator = n_chars( '-', width );
	std::cout << "\n" YELLOW << separator << "\n";
	std::cout << "**** " << str << " ****";
	std::cout << "\n" << separator << RESET "\n";
	std::cout << std::endl;
}

static std::string n_chars( char c, size_t n ) {
	std::string str = "";
	while ( n-- )
		str += c;
	return str;
}
