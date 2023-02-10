/*
Name: Wyatt Haley
Class: Data Structures
File name: driver.cpp
*/

#include "linkedstack.h"
#include <algorithm>

int getMenuChoice();
int precedence(char c);
std::string toPostfix(std::string infixExp);
float calcPostfixValue(std::string postfixExp);

int main(int argc, const char* argv[]){
    
    int menuChoice = 0;
    int choice = 0;
    std::string infixExp = "";
    std::string postfixExp = "";
    
    // prompt menu for user
    do{
        menuChoice = getMenuChoice();
        switch (menuChoice){
            case 0:
                break;
            case 1:
                std::cout << "Please enter an infix expression:" << std::endl;
                std::getline(std::cin >> std::ws, infixExp);
                infixExp.erase(remove(infixExp.begin(), infixExp.end(), ' '), infixExp.end()); // remove all whitespace from infix expression
                std::cout << "You entered the following infix expression: " << infixExp << std::endl;
                postfixExp = toPostfix(infixExp); // turn infix to postfix
                std::cout << "The postfix expression is: " << postfixExp << std::endl; // print postfix
                std::cout << "The result of this expression is: " << calcPostfixValue(postfixExp) << std::endl; // calculate and print expression result
                postfixExp = ""; // reset postfix expression
                break;
            default:
                break;  
        }
    } while (menuChoice != 0);

    return 0;
}

// getMenuChoice displays the main menu and receives and returns the chosen option
int getMenuChoice(){
	int choice;
	do {
        std::cout << std::endl << "infix to postfix application" << std::endl;
        std::cout << "================================" <<std::endl;
        std::cout.width(8); std::cout << std::left << "1.";
		std::cout.width(8); std::cout << std::left << "Convert an infix expression to postfix and determine result" << std::endl;
        std::cout.width(8); std::cout << std::left << "0.";
        std::cout.width(8); std::cout << std::left << "EXIT" << std::endl;
		std::cin >> choice;
	}while(choice !=0 && choice !=1);
	return choice;
}

// precedence assigns an integer value to operators based on precedence so that precedence can be compared in other functions
int precedence(char c){
    if(c == '*' || c == '/'){
        return 2;
    }
    else if(c == '+' || c == '-'){
        return 1;
    }
    else{
        return -1;
    }
}

// toPostfix takes an infix expression and returns the postfix version of that expression
std::string toPostfix(std::string infixExp){
    LinkedStack<char> operatorStack;
    std::string postfixExp = "";
    for(int i=0; i < infixExp.length(); i++){
        if(infixExp[i] > 47 && infixExp[i] < 58){ // if scanned character is 0-9 add to postfix expression
            postfixExp = postfixExp + infixExp[i];
        }
        else if(infixExp[i] == '('){ // if scanned character is open paranthesis, push to stack
            operatorStack.push(infixExp[i]);
        }
        else if(infixExp[i] == ')'){ // if scanned character is closed paranthesis, pop stack until open paranthesis
            while(operatorStack.peek() != '('){
                postfixExp = postfixExp + operatorStack.peek();
                operatorStack.pop();
            }
            operatorStack.pop();
        }
        // if scanned character is operator, check for precedence and push to stack
        else if(infixExp[i] == '+' || infixExp[i] == '-' || infixExp[i] == '*' || infixExp[i] == '/'){
            while(precedence(infixExp[i]) <= precedence(operatorStack.peek())){
                postfixExp += operatorStack.peek();
                operatorStack.pop();
            }
            operatorStack.push(infixExp[i]);
        }
    }
    while(!operatorStack.isEmpty()){ // pop remaining stack
        if(operatorStack.peek() == '('){
            operatorStack.pop();
        }
        else if(operatorStack.peek() == ')'){
            operatorStack.pop();
        }
        else{
        postfixExp = postfixExp + operatorStack.peek();
        operatorStack.pop();
        }
    }
    return postfixExp;
}

// calcPostfixValue takes a postfix expression and returns the result of that expression
float calcPostfixValue(std::string postfixExp){
    LinkedStack<double> resultStack;

    for(int i=0; i<postfixExp.length(); i++){ // iterate through the string that was passed in as argument
        if(postfixExp[i] >= '0' && postfixExp[i] <= '9'){ // 
            resultStack.push(postfixExp[i] - '0'); // push postfixExp[i] as int value, not character value
        }
        else{
            float operand1 = resultStack.peek();
            resultStack.pop();
            float operand2 = resultStack.peek();
            resultStack.pop();

            switch (postfixExp[i]) {
                case '+':
                    resultStack.push(operand2+operand1);
                    break;
                case '-':
                    resultStack.push(operand2-operand1);
                    break;
                case '*':
                    resultStack.push(operand2*operand1);
                    break;
                case '/':
                    resultStack.push(operand2/operand1);
                    break;
                default:
                    break;
            }
        }
    }
    return resultStack.peek();
}
