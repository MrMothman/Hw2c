#include"grammer.h"

Grammer::Grammer(std::string fileName)
{
  int ruleNum, rulePlace = 0;
  acceptEpsilon = false;
  myFile.open(fileName);
  parser(fileName);
  myFile.close();
}

void Grammer::addRule(std::string& rule, bool isEpsilon){
  if(isEpsilon){
    rule.append("_");
  }
  innerRules.push_back(rule);
}

void Grammer::addVariable(char& line){
  std::string transfer;
  transfer.append(1,line);
  innerRules.push_back(transfer);
  rulePlace++;
}

bool Grammer::checkEpsilon(char test, std::string holder){
  if((test == '|' || test == ';') && holder.empty()){
    acceptEpsilon = true;
    return true;
  }else
    return false;
}

void Grammer::gatherRules()
{
  
  std::string line, holder;
  
 
  std::getline(myFile, line);
  stripBlank(line);
  std::list<char> row(line.begin(), line.end());

  while(!row.empty()){
    
    if(rulePlace == 0){
      addVariable(row.front());
      row.pop_front();
      testArrow(row);
    }
        
    switch(row.front()){
      case ';':
        addRule(holder, checkEpsilon(row.front(), holder));
        holder.clear();
        rules.push_back(innerRules);
        innerRules.clear();
        rulePlace=0; 
        row.pop_front();
        ruleNum ++;
        break;

      case '|':
        addRule(holder, checkEpsilon(row.front(), holder));
        holder.clear();
        row.pop_front();
        rulePlace ++;
        break;

      default:
        holder.append(1,row.front());
        row.pop_front();
        break;
    }
  }

}

bool Grammer::isTerminal(char value){
  for(int i = 0; i < rules.size(); i++){
    if(value == rules[i][0][0])
      return false;
  }
  return true;

}

int Grammer::isValid(std::string testString){
  int pass, fail;
  pass = 0;
  fail = 1;
  int size = testString.size();
  std::string table[size][size];

  //algorithm starts
  //step one
  if(acceptEpsilon && testString.empty())
    return pass;
  else if(testString.empty())
    return fail;
  //step two
  //this is string length
  for(int i = 0; i < size; i++){
    //this is because I created rules table to take strings
    std::string transfer;
    transfer.append(1,testString[i]);
    //this is the amount of rules
    for(int j = 0; j < rules.size(); j++){
      //these are the amount of rules a variable points to
      for(int k = 1; k < rules[j].size(); k++){
        if(rules[j][k] == transfer){
          table[i][i] = rules[j][0];
        }
      }
    }
    transfer.clear();
  }

  //step three
  for(int l = 2; l <= size; l++){
    for(int i = 0; i < (size - l + 1); i++){
      int j = i + l - 1;
      for(int k = i; k <= j - 1; k++){
        for(int x = 0; x < rules.size(); x++) {
          for(int b = 1; b < rules[x].size(); b++){
            if(rules[x][b].size() != 2)
              continue;
            std::string firstElement, secondElement;
            firstElement.append(1,rules[x][b][0]);
            secondElement.append(1,rules[x][b][1]);
            if((table[i][k] == firstElement) && (table[k + 1][j] == secondElement)){
              table[i][j] = rules[x][0];
            }

          }
        }
      }
    }
  }
  if(table[0][size - 1] == rules[0][0])
    return pass;
  return fail;
}

void Grammer::parser(std::string fileName){
  if(myFile.is_open()){
    while(myFile.good()){
      gatherRules();
    }
  }else
    std::cout<<fileName<< " doesnt exsist";
}

void Grammer::printGrammer(){
  for(int i = 0; i < rules.size(); i++){
    for(int j = 0; j < rules[i].size(); j++){
      std::cout<<rules[i][j] << " ";
    }
      std::cout<<std::endl;
  }
}

void Grammer::stripBlank(std::string& line){
  line.erase(std::remove_if(line.begin(),line.end(),::isspace),line.end());
}

void Grammer::testArrow(std::list<char>& test){
  if(test.front() != '-'){
    std::cout<<"You have a formatting error";
    EXIT_FAILURE;
  }else 
    test.pop_front();

  if(test.front() != '>'){
    std::cout<<"You have a formatting error";
    EXIT_FAILURE;
  }else 
    test.pop_front();
}


