/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvarila <jvarila@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 13:05:55 by jvarila           #+#    #+#             */
/*   Updated: 2025/06/10 13:09:28 by jvarila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

# define FRAGTRAP_HIT_POINTS	100
# define FRAGTRAP_ENERGY_POINTS	100
# define FRAGTRAP_ATTACK_DAMAGE	50

class FragTrap : public ClapTrap {

public:
// ------------------------------------------------------------ member functions
	void	attack( std::string const &target );
	void	highFivesGuys( void );
// ---------------------------------------------------------------- constructors
	FragTrap( void );
	FragTrap( std::string const &name );
	FragTrap( FragTrap const &src );
// ------------------------------------------------------------------ destructor
	~FragTrap( void );
// --------------------------------------------------- member operator overloads
	FragTrap &operator = ( FragTrap const &src );
};

#endif
