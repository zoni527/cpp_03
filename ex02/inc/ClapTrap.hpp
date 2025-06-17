/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvarila <jvarila@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 17:59:34 by jvarila           #+#    #+#             */
/*   Updated: 2025/06/10 10:40:44 by jvarila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <string>

class ClapTrap {

public:
// ------------------------------------------------------------ member functions
	virtual void	attack( std::string const &target );
	void			takeDamage( unsigned int amount );
	void			beRepaired( unsigned int amount );
	void			printInfo( void );
// --------------------------------------------------------- public constructors
	ClapTrap( void );
	ClapTrap( std::string const &name );
	ClapTrap( ClapTrap const &src );
// ------------------------------------------------------------------ destructor
	virtual	~ClapTrap( void );
// --------------------------------------------------- member operator overloads
	ClapTrap &operator = ( ClapTrap const &src );

// Protected means that derived classes can access these members. If they were
// private the only way to access them would be through setters and getters.
protected:

	// Utility constructor
	ClapTrap(	std::string const &name,
				unsigned int hit_points,
				unsigned int energy_points,
				unsigned int attack_damage);

	std::string		_name;
	unsigned int	_hit_points		= 10;
	unsigned int	_energy_points	= 10;
	unsigned int	_attack_damage	= 0;
};

#endif
