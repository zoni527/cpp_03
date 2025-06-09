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

#include "ClapTrap.hpp"
#include <iostream>

#define YELLOW	"\033[0;93m\001"
#define RESET	"\033[0m\002"

static std::string	n_chars( char c, size_t n );
static void			print_test_name( std::string str );

int main( void ) {

	print_test_name( "Test: default costructor" );
	{
		ClapTrap();
	}
	print_test_name( "Test: string constructor" );
	{
		ClapTrap( "DerpyDerp" );
	}
	print_test_name( "Test: copy constructor" );
	{
		ClapTrap one( "First" ), two( "Second" );
		one = two;
	}
	print_test_name( "Test: attack" );
	{
		ClapTrap().attack( "YOU" );
	}
	print_test_name( "Test: takeDamage" );
	{
		ClapTrap().takeDamage( 5 );
		std::cout << "\n";
		ClapTrap().takeDamage( -1 );
	}
	print_test_name( "Test: beRepaired" );
	{
		ClapTrap().beRepaired( 5 );
		std::cout << "\n";
		ClapTrap().beRepaired( -1 );
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
