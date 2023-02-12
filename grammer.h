#include<iostream>
#include<vector>
#include<algorithm>
#include<cctype>
#include<string>
#include<list>
#include<stdlib.h>
#include<fstream>


class Grammer{
  
  //variables
  private:
    int ruleNum, rulePlace;
    bool acceptEpsilon;
    std::ifstream myFile;
    std::vector<std::vector<std::string>> rules; 
    std::vector<std::string> innerRules;

  //variables
  public:
  
  //methods
  private:
    void addVariable(char& variable);
    void addRule(std::string& rule, bool isEpsilon);
    bool checkEpsilon(char test, std::string holder);
    void gatherRules();
    bool isTerminal(char value);
    void parser(std::string fileName);
    void stripBlank(std::string& line);
    void testArrow(std::list<char>& test);


  //methods
  public:
    Grammer(std::string fileName);
    void printGrammer();
    int isValid(std::string testString);

};

