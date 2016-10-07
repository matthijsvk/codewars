#include <stdio.h>
#include <iostream>
#include <sstream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>

int main(int argc, char** argv)
{
    printf("hello world\n");
    //std::string st = "Addison,Jayden,Sofia,Michael,Andrew,Lily,Benjamin";
    //std::vector<int> we = { 4, 2, 1, 4, 3, 1, 2 };
    //std::string sol = "Benjamin";
    //dotest(st, we, 4, sol);

    //st = "Elijah,Chloe,Elizabeth,Matthew,Natalie,Jayden";
    //we = { 1, 3, 5, 5, 3, 6 };
    //sol = "Matthew";
    //dotest(st, we, 2, sol);
    return 0;
}

class Rank
{
public:
    static std::string nthRank(const std::string& st, std::vector<int>& we, int n)
    {
        std::cout << "beign" << std::endl;

        // first, get names into an array
        std::istringstream ss(st);
        std::string name;

        std::multimap<int, std::string, std::greater<int> > scoresNames; // multimap b/c duplicate scores are possible
        int index = 0;                          // index of current name
        while(std::getline(ss, name, ',')) {
            int weight = we[index];
            std::transform(name.begin(), name.end(), name.begin(), ::tolower); // convert to lowercase
            int score = Rank::getScore(name, weight);
            
            std::cout << score << std::endl;
            
            scoresNames.insert(make_pair(score, name)); // score as value so it gets sorted
            index++;
        }

        // if no names, return "No participants"
        if(scoresNames.empty()) {
            return "No participants";
        }

        // loop through list, replace int by rank. keep score, compare to next. if lower, rank +=1 and assign.
        //                                                                      If equal, set same rank and advance
        std::multimap<int, std::string, std::greater<int> >::iterator it;
        int rank = 1;
        int maxScore = scoresNames.rbegin()->first + 1; // score of first one, +1
        for(it = scoresNames.begin(); it != scoresNames.end(); it++) {
            if((*it).first < maxScore) {
                rank++;
                maxScore = (*it).first; // might need dereferencing??
            }
            (*it).first = rank;
        }
       std::string output = scoresNames.begin()->second;
        for(it = scoresNames.begin(); it != scoresNames.end(); it++) {
            rank = (*it).first;
            if(rank == n) {
                output += "," + (*it).second;
            }
        }
        if(output.at(0) == ',') {
            output = output.substr(1, output.size() - 1);
        }
        return output;
    }

    static int getScore(std::string name, int weight)
    {
        int score = 0;
        for(char& c : name) {
            score += c - '0' + 1; // sum every letter, +1 (each letter counts as extra 1 b/c length of name)
        }
        score *= weight; // multiply with corresponding weight
        return score;
    }
};

// TESTING
std::string testequal(std::string ans, std::string sol)
{
    if (ans == sol){return ans + " is equal to " + sol;}
    else { return ans + " is NOT equal to " + sol;}
}

void dotest(const std::string& st, std::vector<int>& we, int n, std::string expected)
{
    std::cout << testequal(Rank::nthRank(st, we, n), expected) << std::endl;
}

