/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvarila <jvarila@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 09:51:02 by jvarila           #+#    #+#             */
/*   Updated: 2025/06/11 17:56:20 by jvarila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

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

private:

};

#endif
