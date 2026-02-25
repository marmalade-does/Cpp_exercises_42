/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroberts <marvin@42.barcelona>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 15:46:50 by lroberts          #+#    #+#             */
/*   Updated: 2026/02/23 12:00:00 by lroberts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

std::string replaceAll(const std::string &content, const std::string &s1,
	const std::string &s2)
{
	std::string	result;
	size_t		pos = 0;
	size_t		found;

	if (s1.empty())
		return (content);
	while ((found = content.find(s1, pos)) != std::string::npos)
	{
		result.append(content, pos, found - pos);
		result.append(s2);
		pos = found + s1.length();
	}
	result.append(content, pos, content.length() - pos);
	return (result);
}

int main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cout << "Usage: ./sed <filename> <s1> <s2>" << std::endl;
		return (1);
	}

	std::string		filename(argv[1]);
	std::string		s1(argv[2]);
	std::string		s2(argv[3]);

	if (s1.empty())
	{
		std::cerr << "Error: s1 cannot be empty" << std::endl;
		return (1);
	}

	std::ifstream	infile(filename.c_str());
	if (!infile)
	{
		std::cerr << "Error: could not open file '" << filename << "'" << std::endl;
		return (1);
	}

	std::string		line;
	std::string		file_content;
	bool			first = true;
	while (std::getline(infile, line))
	{
		if (!first)
			file_content += "\n";
		file_content += line;
		first = false;
	}
	infile.close();

	std::string		result = replaceAll(file_content, s1, s2);

	std::ofstream	outfile((filename + ".replace").c_str());
	if (!outfile)
	{
		std::cerr << "Error: could not create output file" << std::endl;
		return (1);
	}
	outfile << result;
	outfile.close();

	return (0);
}
