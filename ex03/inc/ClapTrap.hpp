/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvarila <jvarila@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 17:59:34 by jvarila           #+#    #+#             */
/*   Updated: 2025/06/17 15:50:20 by jvarila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <string>

# define CLAPTRAP_HIT_POINTS	10
# define CLAPTRAP_ENERGY_POINTS	10
# define CLAPTRAP_ATTACK_DAMAGE	0

class ClapTrap {

public:
// ------------------------------------------------------------ member functions
	virtual void	attack( std::string const &target );
	void			takeDamage( unsigned int amount );
	void			beRepaired( unsigned int amount );

	std::string		getName( void )	const;
	unsigned int	getHP( void )	const;
	unsigned int	getEP( void )	const;
	unsigned int	getAD( void )	const;

	void			setName( std::string const &str );
	void			setHP( unsigned int hp );
	void			setEP( unsigned int ep );
	void			setAD( unsigned int ad );
// ---------------------------------------------------------------- constructors
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
	unsigned int	_hit_points		= CLAPTRAP_HIT_POINTS;
	unsigned int	_energy_points	= CLAPTRAP_ENERGY_POINTS;
	unsigned int	_attack_damage	= CLAPTRAP_ATTACK_DAMAGE;
	unsigned int	_max_hp;
	unsigned int	_max_ep;
};

#endif
