/*
 * revtac.cc
 * combination of unix commands rev and tac
 */

#include <string>
#include <fstream>
#include <iostream>

/*
 * getContent
 * input: takes in an instream (either cin or a file stream)
 * output: returns string of content from the instream
 */
std::string getContent(std::istream& stream) {
  std::string line;
  std::string content;
  while (std::getline(stream, line)) {
    content.append(line+"\n");
  }
    //remove last new line
    content.erase(content.size() - 1);
    std::reverse(content.begin(), content.end());
    return content;
}

/*
 * main
 * input: number of command line arguments and array of command line args
 */
int main(int argc, char** argv){
  if (argc > 1){
    for (int i = argc; i > 1; i--) {
      std::ifstream file;
      if (strcmp(argv[i - 1], "-") == 0) {
        std::cout << getContent(std::cin) << std::endl;
      } else {
        file.open(argv[i - 1]);
        if (file.is_open()){
          std::cout << getContent(file) << std::endl;
          file.close();
        } else {
          std::cout << "revtac: "<< argv[i - 1] << ": No such file or directory";
        }
      }
    }
  } else {
    std::string line;
    while (std::getline(std::cin, line)){
      std::reverse(line.begin(), line.end());
      std::cout << line << std::endl;
    }
  }

  return 0;
}
