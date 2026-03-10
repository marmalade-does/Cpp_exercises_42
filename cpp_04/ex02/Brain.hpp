/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroberts <marvin@42.barcelona>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 18:25:10 by lroberts          #+#    #+#             */
/*   Updated: 2026/03/09 18:28:20 by lroberts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <string>
# include <iostream>


/**
 * @note cat and dog HAS-a brain, ∴ use composition, not inheretence
 * @remark important that the brain is deep copied in the copy operators etc.
 */
class Brain
{
public:
	Brain(void);
	Brain(const Brain &src);
	Brain &operator=(const Brain &rhs);
	
	~Brain(void);

	std::string			getIdea(int index) const;
	void				setIdea(int index, const std::string &idea);

private:
	std::string _ideas[100];
};

#endif
