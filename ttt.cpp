#include <iostream>
#include <vector>
void display(std::vector<std::string> num) {
  std::cout << " " << num[0] << " | " << num[1] << " | " << num[2] << std::endl;
  std::cout << "-----------" << std::endl;
  std::cout << " " << num[3] << " | " << num[4] << " | " << num[5] << std::endl;
  std::cout << "-----------" << std::endl;
  std::cout << " " << num[6] << " | " << num[7] << " | " << num[8] << std::endl;
}

int choose(std::string name, std::vector<std::string> num) {
  int index;
  std::cout << std::endl;
  display(num);
  std::cout << name << ", please choose a number: ";
  std::cin >> index;
  std::cout << "------------------------------";
  std::cout << std::endl;
  while (num[index-1] == "x" || num[index-1] == "o") {
    std::cout << "Invalid, try again: ";
    std::cin >> index;
  }

  return index;
}

bool check(std::vector<std::string> num) {
  for (int i = 0; i < 9; i++) {
    if (num[i] == num[i+3] && num[i+3] == num[i+6]) {
      return true;
    }
  }
  for (int i = 0; i < 9; i+=3) {
    if (num[i] == num[i+1] && num[i+1] == num[i+2]) {
      return true;
    }
  }
  if (num[0] == num[4] && num[4] == num[8]) {
    return true;
  }
  else if (num[2] == num[4] && num[4] == num[6]) {
    return true;
  }
  return false;
}

int main() {
  std::string player1_name;
  std::string player2_name;

  std::cout << "Player1, please enter your name: ";
  std::cin >> player1_name;
  std::cout << "Player2, please enter your name: ";
  std::cin >> player2_name;
  
  std::vector<std::string> num;
  num.push_back("1");
  num.push_back("2");
  num.push_back("3");
  num.push_back("4");
  num.push_back("5");
  num.push_back("6");
  num.push_back("7");
  num.push_back("8");
  num.push_back("9");
  // {"1", "2", "3", "4", "5", "6", "7", "8", "9"};
  std::string final_name;
  while (true) {

    num[choose(player1_name, num) - 1] = "x";
    if (check(num)) {
      final_name = player1_name;
      break;
    }

    num[choose(player2_name, num) - 1] = "o";
    if (check(num)) {
      final_name = player2_name;
      break;
    }
  }
  std::cout << std::endl;
  display(num);
  for (int i = 0; i < 3; i++) {
    std::cout << "\nCongratulations " << final_name << ", you win the game!\n";
  } 
  std::cout << "Thank you for playing!";
}