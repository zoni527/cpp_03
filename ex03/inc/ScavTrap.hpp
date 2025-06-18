/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvarila <jvarila@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 09:51:02 by jvarila           #+#    #+#             */
/*   Updated: 2025/06/10 10:21:35 by jvarila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

# define SCAVTRAP_HIT_POINTS	100
# define SCAVTRAP_ENERGY_POINTS	50
# define SCAVTRAP_ATTACK_DAMAGE	20

class ScavTrap : virtual public ClapTrap {

public:
// ------------------------------------------------------------ member functions
	void	attack( std::string const &target );
	void	guardGate( void );
// ---------------------------------------------------------------- constructors
	ScavTrap( void );
	ScavTrap( std::string const &name );
	ScavTrap( ScavTrap const &src );
// ------------------------------------------------------------------ destructor
	~ScavTrap( void );
// --------------------------------------------------- member operator overloads
	ScavTrap &operator = ( ScavTrap const &src );
};

#endif
