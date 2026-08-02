/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 11:56:29 by omawele           #+#    #+#             */
/*   Updated: 2026/07/27 15:09:08 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <cstring>

int main( int ac, char **av)
{
    if (ac != 4)
    {
        std::cerr << "Error: Takes 3 arguments: filename, s1, s2\n";
        return 1;
    }
    
    std::fstream fileIN(av[1], std::ios::in);
    if (!fileIN.is_open())
    {
        std::cerr << "Error: Unable to open file!\n";
        return 1;
    }

    std::string newFile = av[1];
    newFile.append(".replace");
    
    std::fstream fileOUT(newFile.c_str(), std::ios::out);
    if (!fileOUT.is_open())
    {
        std::cerr << "Error: Unable to create file!\n";
        fileIN.close();
        return 1;
    }

    std::string line;
    std::string sub;
    std::string sub2;
    size_t find_s1;
    int len_end;
    while (getline(fileIN, line))
    {
        if (!fileIN.eof())
            line += '\n';  
        while ((find_s1 = line.find(av[2])) != std::string::npos)
        {
            sub = line.substr(0, find_s1) + av[3];    
            len_end = line.length() - (strlen(av[2]) + sub.length() - 1);
            sub2 = line.substr(find_s1 + strlen(av[2]), len_end);
            line = sub + sub2; 
        }
        fileOUT << line;
    }

    if (!fileIN.eof())
    {
        std::cerr << "Error: File reading failed!\n";
        fileIN.close();
        fileOUT.close();
        return 1;
    }
    
    fileIN.close();
    fileOUT.close();
    return 0;
}
