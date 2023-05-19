#ifndef FILE_READER_H
#define FILE_READER_H
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>

// This struct represents the data associated with a TV series.
struct movie_data
{
    std::string series_name;
    int year_start;
    int year_end;
    std::string series_category;
    std::string series_URL;
    std::vector<std::string> actor_vector;
    int index;
};

// This function creates a vector of movie_data structs by reading data from a file.
std::vector<movie_data> create_movie_data_vector();

// This function extracts the name of a TV series from a given string.
void get_series_name(char [], char []);

// This function returns the index of a given character in a given string.
int index_of(char [], char);

// This function extracts the start and end years of a TV series from a given string.
void get_years(char [], int& , int& );

// This function extracts a substring from a given string.
void get_subString(char [], int , int , char []);

// This function removes any blank spaces from a given string.
void remove_blanks( char []);
#endif