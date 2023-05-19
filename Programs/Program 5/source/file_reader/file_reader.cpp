#ifndef FILE_READER_CPP
#define FILE_READER_CPP
#include "file_reader.h"
//#define DEBUG

/*
This code defines a function named create_movie_data_vector(), 
which returns a vector of movie_data objects.

The function reads data from a file named tv_DB.txt located in the ../data/ directory. 
If the file cannot be opened, an error message is printed and the program exits. 
The file is read line-by-line using the getline() function and parsed to extract various pieces of information 
such as the series name, years the series was aired, series category, series URL, and actor names.

After the data is parsed, it is stored in a movie_data object and added to the vector using the push_back() function.
The n_series variable is incremented each time a new series is added to the vector.

The code also includes some preprocessor directives #ifdef DEBUG which indicates 
that some lines are included only when the DEBUG flag is defined.

The code also defines several helper functions, such as get_series_name(), get_years(), index_of(),
get_subString(), and remove_blanks(). These functions help to extract the desired information 
from each line of the input file.

Finally, the function returns the vector of movie_data objects and closes the input file.
*/

// This function reads a file containing TV series data and returns a vector of movie_data objects
std::vector<movie_data> create_movie_data_vector()
{
    
// Initialize variables
    std::vector<movie_data> movie_data_vector;
    std::ifstream file_in("../data/tv_DB.txt",std::ios::in);

// Check if file can be opened
    if(!file_in){
        std::cout << "[ERROR][FILE_READER :: read_tv_file()] Unable to Read File"<<std::endl;
        exit(-1);
    }

// Initialize variables for parsing each line of the file
    const int MAX_LINE = 128;
    char line[MAX_LINE];
    char series_name[MAX_LINE];
    char series_category[MAX_LINE/2];
    char series_URL[MAX_LINE];
    char actor_name[MAX_LINE/2];
    int y_start, y_end;
    int n_series = 0;

// Loop through each line of the file and parse the data
    while(file_in.getline(line, MAX_LINE))
    {
// Create a new movie_data object to store the parsed data
        movie_data new_movie_data;

// If the line is empty, skip to the next line
        if(strlen(line) == 0)
            continue;

// Parse the series name and years from the line
        get_series_name(line,series_name);
        get_years(line, y_start, y_end);

// Parse the series category and URL from the next two lines
        file_in.getline(series_category, MAX_LINE/2);
        file_in.getline(series_URL, MAX_LINE);
        
// Assign the parsed data to the movie_data object
        new_movie_data.series_name = series_name;
        new_movie_data.year_start = y_start;
        new_movie_data.year_end = y_end;
        new_movie_data.series_category = series_category;
        new_movie_data.series_URL = series_URL;

// Parse the actor names from the remaining lines
        file_in.getline( line, MAX_LINE/2 );
        int n = -1;
        while( strlen(line) > 0 ) {
            new_movie_data.actor_vector.push_back(line);
            file_in.getline( line, MAX_LINE/2 );
            n++;
        }

// Assign an index to the movie_data object and add it to the vector
        new_movie_data.index = n_series;
        movie_data_vector.push_back(new_movie_data);
        
        n_series++;
    }

// Close the file and return the vector of movie_data objects
    file_in.close();
    return movie_data_vector;
}

// This function extracts the series name from a line of text
void get_series_name(char line[], char series_name[]){
    int start_year;
    start_year = index_of(line, '(');
    get_subString(line, 0, start_year-1, series_name);
}


void get_years( char line[], int & y_start, int & y_end )
{
    char tmp_string[8];
    char year_string[16];
    int year_start, year_end;

    year_start = index_of( line, '(' );
    year_end = index_of( line, ')' );

    get_subString( line, year_start+1, year_end-year_start-1, year_string);

    get_subString( year_string, 0, 4, tmp_string );
    y_start = atoi( tmp_string );

    get_subString( year_string, 5, 4, tmp_string ); // 7? not ’-’!
    y_end = atoi( tmp_string );

}

// This function returns the index of the first occurrence of character 'c' in string 's'.
int index_of(char s[], char c) {

// Initialize the index variable to 0    
    int i = 0; 

// While the current character is not a null terminator or 'c'
    while (s[i] != '\0' && s[i] != c) {

// Increment the index
        i++; 
    }

// Return the index of the first occurrence of 'c' or the length of the string if 'c' is not found.
    return i;
}

// This function extracts a substring from 's' and stores it in 'res', starting at index 'start' and ending at index 'start+end-1'.
void get_subString(char s[], int start, int end, char res[]) {
 // Declare a counter variable
    int i;
// Declare and initialize the index of the result substring to 0    
    int i_res = 0; 

    for (i = start; i < start + end; i++) { // Iterate through 's' from index 'start' to 'start+end-1'
        res[i_res++] = s[i]; // Copy each character of the substring into 'res'
    }

// Add a null terminator to the end of the result substring
    res[i_res] = '\0'; 

// Remove any trailing whitespace from the result substring
    remove_blanks(res); 
}

// This helper function removes any trailing whitespace (spaces or tabs) from a string.
void remove_blanks(char s[]) {

// Calculate the length of the string    
    int s_len = strlen(s);

// Iterate through the string from the end
    for (int i = s_len; i >= 0; i--) {

// If the current character is alphabetic, stop iterating
        if (isalpha(s[i])) { 
            break;
        }

// If the current character is a space, replace it with a null terminator
        if (s[i] == ' ') { // If the current character is a space, replace it with a null terminator
            s[i] = '\0';
        }
    }
}
#endif