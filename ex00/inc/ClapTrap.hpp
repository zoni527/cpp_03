/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvarila <jvarila@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 17:59:34 by jvarila           #+#    #+#             */
/*   Updated: 2025/06/09 18:13:01 by jvarila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <string>

class ClapTrap {

public:
// ------------------------------------------------------------ member functions
	void	attack( std::string const &target );
	void	takeDamage( unsigned int amount );
	void	beRepaired( unsigned int amount );
	void	printInfo( void );
// ---------------------------------------------------------------- constructors
	ClapTrap( void );
	ClapTrap( std::string const &name );
	ClapTrap( ClapTrap const &src );
// ------------------------------------------------------------------ destructor
	~ClapTrap( void );
// --------------------------------------------------- member operator overloads
	ClapTrap &operator = ( ClapTrap const &src );

private:
	std::string		_name;
	unsigned int	_hit_points		= 10;
	unsigned int	_energy_points	= 10;
	unsigned int	_attack_damage	= 0;
};

#endif
