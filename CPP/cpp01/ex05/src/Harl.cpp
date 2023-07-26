/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fragarci <fragarci@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 18:08:52 by fragarci          #+#    #+#             */
/*   Updated: 2023/07/13 18:56:16 by fragarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Harl.hpp"

Harl::Harl() {}
Harl::~Harl() {}

void	Harl::debug(void)
{
	std::cout << "Greetings, friend. I'm Cave Johnson, CEO of Aperture Science - you might know us as a vital participant in the 1968 Senate Hearings on missing astronauts. And you've most likely used one of the many products we invented. But that other people have somehow managed to steal from us. Black Mesa can eat my bankrupt--" << std::endl;
}

void	Harl::info(void)
{
		std::cout << "Welcome, gentlemen, to the Aperture Hollow 'Science Jungle'. Tramps, hillbillies, drifters: you're here because you followed the hobo signs. So, who is ready to scrounge around for some science? Now, you already met one another on the boxcar over here, so grab a bowl of slumgullion and a glass of sterno, and let me introduce myself. I'm Michigan Slim Cave Johnson. I'm the hobo king." << std::endl;
}

void	Harl::warning(void)
{
		std::cout << "All right, I've been thinking. When life gives you lemons? Don't make lemonade. Make life take the lemons back! Get mad! 'I don't want your damn lemons! What am I supposed to do with these?' Demand to see life's manager! Make life rue the day it thought it could give Cave Johnson lemons! Do you know who I am? I'm the man who's going to burn your house down! With the lemons! I'm going to get my engineers to invent a combustible lemon that burns your house down!" << std::endl;
}

void	Harl::error(void)
{
		std::cout << "Cave Johnson here. I seeeee you. I seeee your little feet. I'm gonna cut off your hair and put it on your feet and eat your little hair. What? Oh, and feet. Um yum yum yum yum!" << std::endl;
}

void	Harl::complain(std::string level)
{
	t_action actions[] = { &Harl::debug, &Harl::info, &Harl::warning, &Harl::error };
	std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	int index = 0;
	while (levels[index].compare(level) && index < 4)
		index++;
	if (index < 4)
		(this->*actions[index])();
}
