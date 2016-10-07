#include <iostream>
#include <sstream>
#include <map>
#include <string>
#include <vector>

class Rank
{
public:
    static std::string nthRank(const std::string& st, std::vector<int>& we, int n)
    {
        std::cout << "beign" << std::endl;

        // first, get names into an array
        std::istringstream ss(st);
        std::string name;

        std::multimap<string, int> scoresNames; // multimap b/c duplicate scores are possible
        int index = 0;                          // index of current name
        while(std::getline(ss, name, ',')) {
            int weight = we.[index];
            std::transform(dname.begin(), name.end(), name.begin(), ::tolower); // convert to lowercase
            int score = getScore(name, weight);
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
        multimap<string, int>::iterator it;
        rank = 1;
        maxScore = scoresNames.rbegin()->first + 1; // score of first one, +1
        for(it = scoresNames.rbegin(); it != scoresNames.rend(); it++) {
            if(it.first < maxScore) {
                rank++;
                maxScore = it.first; // might need dereferencing??
            }
            it.first = rank;
        }
        string output = scoresNames.rbegin().second;
        for(it = scoresNames.rbegin(); it != scoresNames.rend(); it++) {
            rank = it.first;
            if(rank == n) {
                output += "," + it.second;
            }
        }
        if(output[0] == ",") {
            output = output.substr(1, output.size() - 1);
        }
        return output;
    }

    int getScore(string name, int weight)
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
void testequal(std::string ans, std::string sol)
{
    Assert::That(ans, Equals(sol));
}

void dotest(const std::string& st, std::vector<int>& we, int n, std::string expected)
{
    testequal(Rank::nthRank(st, we, n), expected);
}

Describe(nthRank_Tests){ 
    It(Fixed_Tests){ 
        std::cout << "this is a test" << std::endl;
        std::string st = "Addison,Jayden,Sofia,Michael,Andrew,Lily,Benjamin";
        std::vector<int> we = { 4, 2, 1, 4, 3, 1, 2 };
        std::string sol = "Benjamin";
        dotest(st, we, 4, sol);

        st = "Elijah,Chloe,Elizabeth,Matthew,Natalie,Jayden";
        we = { 1, 3, 5, 5, 3, 6 };
        sol = "Matthew";
        dotest(st, we, 2, sol);
    }
};
