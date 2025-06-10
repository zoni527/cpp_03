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
		std::cout << "ClapTrap a; ->\n";
		ClapTrap a;
		std::cout << "\na.printInfo(); ->\n";
		a.printInfo();
	}
	print_test_name( "Test: string constructor" );
	{
		std::cout << "ClapTrap a( \"DerpyDerp\" ); ->\n";
		ClapTrap a( "DerpyDerp" );
		std::cout << "\na.printInfo(); ->\n";
		a.printInfo();
	}
	print_test_name( "Test: copy constructor" );
	{
		std::cout << "ClapTrap a( \"First\" ); ->\n";
		ClapTrap a( "First" );
		std::cout << "\na.printInfo(); ->\n";
		a.printInfo();
		std::cout << "ClapTrap b( a ); ->\n";
		ClapTrap b( a );
		std::cout << "\nb.printInfo(); ->\n";
		b.printInfo();
	}
	print_test_name( "Test: copy assignment operator" );
	{
		std::cout << "ClapTrap a( \"First\" ), b( \"Second\" ); ->\n";
		ClapTrap a( "First" ), b( "Second" );
		std::cout << "\na.printInfo(); ->\n";
		a.printInfo();
		std::cout << "\nb.printInfo(); ->\n";
		b.printInfo();
		std::cout << "\na = b; ->\n";
		a = b;
		std::cout << "\na.printInfo(); ->\n";
		a.printInfo();
		std::cout << "\nb.printInfo(); ->\n";
		b.printInfo();
	}
	print_test_name( "Test: attack" );
	{
		std::cout << "ClapTrap a; ->\n";
		ClapTrap a;
		std::cout << "\na.printInfo(); ->\n";
		a.printInfo();
		std::cout << "\na.attack( \"YOU\" ); ->\n";
		a.attack( "YOU" );
		std::cout << "\na.printInfo(); ->\n";
		a.printInfo();
	}
	print_test_name( "Test: takeDamage" );
	{
		std::cout << "ClapTrap a; ->\n";
		ClapTrap a;
		std::cout << "\na.printInfo(); ->\n";
		a.printInfo();
		std::cout << "\na.takeDamage( 5 ); ->\n";
		a.takeDamage( 5 );
		std::cout << "\na.printInfo() ->\n";
		a.printInfo();
		std::cout << "\na.takeDamage( -1 ); ->\n";
		a.takeDamage( -1 );
		std::cout << "\na.printInfo() ->\n";
		a.printInfo();
	}
	print_test_name( "Test: beRepaired" );
	{
		std::cout << "ClapTrap a; ->\n";
		ClapTrap a;
		std::cout << "\na.printInfo(); ->\n";
		a.printInfo();
		std::cout << "\na.beRepaired( 5 ); ->\n";
		a.beRepaired( 5 );
		std::cout << "\na.printInfo(); ->\n";
		a.printInfo();
		std::cout << "\na.beRepaired( -1 ); ->\n";
		a.beRepaired( -1 );
		std::cout << "\na.printInfo(); ->\n";
		a.printInfo();
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
