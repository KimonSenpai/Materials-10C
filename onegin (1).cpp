#include <iostream>
#include <sstream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <string>


//#define _DEBUG_


using std::vector;
using std::cout;
using std::string;


bool cmp(const string&, const string&);

void generate(const vector <string>&, vector <string>&, int);


int main()
{
    setlocale(LC_ALL, "Rus");
    srand(time(0));

    std::ifstream onegin;
    onegin.open("Onegin1.txt");

    // onegin.seekg(0, ios_base::end);
    // size_t length = (size_t)onegin.tellg() + 2;
    // onegin.seekg(0, ios_base::beg);
    // char* buf = new char[length];
    // onegin.read(buf, length);
    // onegin.close();
    // buf[length - 1] = '\0';
    
    
    // int64_t ind = 0;
    // vector <char*> end_of_line;
    //     while (buf[ind] != '\n') {
    //         ++ind;
    //     }

    //     end_of_line.push_back(buf + ind);
    //     int end_ind = ind;
    //     while (buf[ind] == ';' || buf[ind] == ',' 
    //     || buf[ind] == '!' || buf[ind] == ':' || buf[ind] == ')'
    //     || buf[ind] == '-' || buf[ind] == ' ') 
    //     {
    //         --*(end_of_line.end()-1);
    //         --ind;
    //     }


    //     if (buf[ind] == ']') {
    //         while (buf[ind] != '[') {
    //             --ind;
    //         }

    //         *(end_of_line.end()-1) = buf + ind - 1;
    //     }

    //     ind = end_ind + 1;
    // }
    
    vector<string> lines;
    while (!onegin.eof()) {
        string current;
        getline(onegin, current);

        if ( current.size() != 0 ) {
            if ( isalpha(current[0]) || isalpha(current[1]) ) {

                char last_ch = *(current.end()-1);

                while (last_ch == ';' || last_ch == ',' 
                  || last_ch == '!' || last_ch == ':' || last_ch == ')' || last_ch == '-' 
                  || last_ch == ' ' || last_ch == '.' || last_ch == '>' || last_ch == '<') 
                {
                    current.resize(current.end()-current.begin()-1);
                    last_ch = *(current.end()-1);
                }

                if (last_ch == ']') {
                    int a = current.find('[');
                    current.resize(a);
                    last_ch = *(current.end()-1);
                }

                if ( last_ch == 'e' || last_ch == 't' ) {
                    continue;
                }

                lines.push_back(current);

            }
        }
    }

    onegin.close();


    sort(lines.begin(), lines.end(), cmp);


    #ifdef _DEBUG_

    std::ofstream lines1;
    lines1.open("lines.txt");

    for(int i = 0; i < lines.size(); i++) {
        lines1 << lines[i] << '\n';
    }
    
    lines1.close();
    
    #endif


    vector <string> ans;

    generate(lines, ans, 0);
    generate(lines, ans, 1);
    generate(lines, ans, 1);
    generate(lines, ans, 2);
    generate(lines, ans, 1);


    // ofstream answer;
    // answer.open("ans.txt");
    // for(int i = 0; i < ans.size(); i++) {
    //     answer << ans[i] << '\n';
    // }
    // answer.close();

    for (auto line : ans) {
        cout << line << '\n';
    }

    return 0;
}


bool cmp(const string& left, const string& right) {

    std::stringstream st_left(left);
    string left_last_word;
    while (st_left >> left_last_word);
    reverse(left_last_word.begin(), left_last_word.end());


    std::stringstream st_right(right);
    string right_last_word;
    while (st_right >> right_last_word);
    reverse(right_last_word.begin(), right_last_word.end());


    return left_last_word < right_last_word;
}

void generate(const vector <string> &lines, vector <string> &ans, const int mode)
{
    string first_line;
    int first_line_ind = rand() % lines.size();
    first_line = lines[first_line_ind];


    string second_line;
    int second_line_ind = rand() % lines.size();
    while (second_line_ind == first_line_ind) {
        second_line_ind = rand() % lines.size();
    }
    second_line = lines[second_line_ind];
    

    string third_line;
    int third_line_ind;

    int r = rand() % 3 + 1;
    third_line_ind = first_line_ind + r;
    third_line = lines[third_line_ind]; 
    
    while (first_line[first_line.size()-1] != third_line[third_line.size()-1] 
      || (first_line[first_line.size()-2] != third_line[third_line.size()-2])) 
    {    
        if (third_line_ind == first_line_ind) {
            --third_line_ind;
            break;
        }

        --third_line_ind;
    } 
    
    third_line = lines[third_line_ind];
   

    string fourth_line;
    int fourth_line_ind;
    
    r = rand() % 3 + 1;
    fourth_line_ind = second_line_ind + r;
    fourth_line = lines[fourth_line_ind];

    while (second_line[second_line.size()-2] != fourth_line[fourth_line.size()-2] 
      || second_line[second_line.size()-1] != fourth_line[fourth_line.size()-1] ) 
    {
        if (fourth_line_ind == second_line_ind) {
            --fourth_line_ind;
            break;
        }

        --fourth_line_ind;
    }
    
    fourth_line = lines[fourth_line_ind];
    

    switch (mode) {
        case 0:

            ans.push_back(first_line);
            ans.push_back(second_line);
            ans.push_back(third_line);
            ans.push_back(fourth_line);
            
            break;

        case 1:

            ans.push_back(first_line);
            ans.push_back(third_line);

            break;

        case 2:

            ans.push_back(first_line);
            ans.push_back(second_line);
            ans.push_back(fourth_line);
            ans.push_back(third_line);

            break;
    }
    
    #ifdef _DEBUG_
    std::ofstream lines1;
    lines1.open("test1.txt");

    lines1 << second_line.substr(second_line.size()-2) << '\n' << fourth_line.substr(fourth_line.size()-2) << '\n' << second_line.substr(second_line.size()-4, 2) << '\n' << fourth_line.substr(fourth_line.size()-4, 2);
    lines1.close();
    #endif

}
