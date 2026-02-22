/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroberts <marvin@42.barcelona>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 15:46:50 by lroberts          #+#    #+#             */
/*   Updated: 2026/02/22 16:19:15 by lroberts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
# include <fstream>
# include <string>

// TODO need ot hand in your own tests

int replace_matched(std::string &file_content, const std::string &s1, const std::string &s2);
{
	std::string		result;
	if(s1.empty())
		return (1);
	
	while((found = content.find(s1, pos)) != std::string::npos)
	{
		result.append(file_content, pos, found - por);
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
	// Need to read the whole file into a string
	// replace every occurence of 1 with 2
	
	std::string		filename(argv[1]);
	std::string		s1(argv[1]);
	std::string		s2(argv[1]);

	std::ifstream	infile(filename.c_str());
	if (!infile)
	{
		std::cerr << "Error: could not open file '" << filename << "'" << std::endl;
		return (1);
	}
	
	std::string		file_content = 	infile.read();
	infile.close();

	replace_matched(file_content, s1, s2);

}



