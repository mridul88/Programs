#include <D:\documents\project\leda\LEDA-6.2-free-FC8_i386-g++-4.1.2\incl\LEDA>

int main()
{
  leda::string s="17 18 19 20 21 22 23 24 25 26";
  leda::string_istream input(s); 
  //defines the string_istream input 
  //and connects it to the string s
 
  int num;
  while (!input.eof()) {  
          //while not end of input is reached
    input >> num; 
          //extract next number from input
    std::cout << num << std::endl;
  }
 
  return 0;
}  
