# include <iostream>
# include <string>
# include <sstream>

// Global Variables
int num1, num2;
char operation;
std::string input;

bool parseInput();

bool parseInput(){
    std::istringstream iss(input);
    if (iss >> num1 >> operation >> num2) {
        return true;
        input = "";
    }
    return false;
}

int main(void) {

    std::cout << "Hello, welcome to the calculator. Things to note: 1) this calculator does only addition, subtraction, multiplication, and division. Do not use parenthesis or exponent. 2) only include 2 numbers... for now. Good luck." << std:: endl;

    std::string equation;
    std::string history;
    std::string choose = "c";

    while (1){
        
        if (choose == "c"){
            
            choose = " ";

            std::cout << "Enter your calculation (*/+-): " << std::endl;
            std::getline(std::cin, input);
            parseInput();
            
            int num3;

            switch (operation){

                case '+':
                    num3 = num1 + num2;
                    break;
                
                case '-':
                    num3 = num1 - num2;
                    break;
                
                case '/':
                    num3 = num1 * num2;
                    break;

                case '*':
                    num3 = num1 / num2;
                    break;

            }
            equation = std::to_string(num1) + ' ' + operation + ' ' + std::to_string(num2) + " = " + std::to_string(num3);
            std::cout << equation << std::endl;
            history += equation + "\n";
        }

        else if(choose == "h"){
            
            choose = " ";

            std::cout << history;
        }

        else if(choose == "e"){
            break;
        }

        else{
            std::cout << "Sorry, that doesn't work. Maybe you put it in uppercase? Try again:";
            std::getline(std::cin, choose);
        }
        if(choose == " "){
            std::cout << "What next? h=history c=calculations e=exit:";
            std::getline(std::cin, choose);
        }
    }

    return 0;
}