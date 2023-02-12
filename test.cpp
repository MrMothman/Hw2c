#include<iostream>
#include<string>
#include<vector>



int main(int argc, char** argv){
  std::vector<std::vector<std::string>> test; 
  std::string table[9][9];
  for(int i = 0; i < 9; i++){
    for( int j = 0; j < 9; j++){
      std::cout<<table[i][j]<<std::endl;
    }
  }
  
  std::vector<std::string> test2;

  std::string butt = " butt";
  




  test2.push_back(butt);
  test.push_back(test2);
  if(test[0][0] == table[0][0])
    std::cout<<"yes"<<std::endl;
  else
    std::cout<<"no"<<std::endl;
  
  std::cout<<test[0][0];


}

