#include<iostream>
#include<fstream>
#include"grammer.h"
#include<string>



int main(int argc, char** argv){
  std::string testS;
  Grammer test(argv[1]);
  std::ifstream myFile(argv[2]);
  if(myFile.good())
    std::getline(myFile, testS);
  myFile.close();
  int state = test.isValid(testS);
  std::cout<<state<<std::endl;
}
