#include <string>
#include <iostream>
using std::string;

class Node {
private:
    char data = '\0';
    Node* next = nullptr;
public:
    void setData(char c) {
        data = c;
    }
    void setNextNode(Node* n) {
        next = n;
    }
    Node* getNextNode() {
        return next;
    }
    char getData() {
        return data;
    }
};

class LinkedStack {
private: 

    Node* newNode(char data);

public:
    Node* top;

    LinkedStack() {
        top = new Node();      
        top->setData('\0');
        top->setNextNode(nullptr);
    }

    bool isEmpty() {
        return top->getData() == '\0';
    }
    Node* getTop() { return top; }

    void push(char newData);
    char pop();
    char peek();
    void display();

};
Node* LinkedStack::newNode(char data)
{
    Node* stackNode = new Node();
    stackNode->setData(data);
    return stackNode;
}
void LinkedStack::push(char newData)
{
    Node* stackNode = newNode(newData);
    stackNode->setNextNode(top);
    top = stackNode;
}
char LinkedStack::pop()
{
    if (isEmpty()) {
        std::cout << "Stack Underflow" << std::endl;
        return '\0';
    }

    Node* temp = top;
    top = top->getNextNode();

    return temp->getData();


}
char LinkedStack::peek()
{
    if (isEmpty()) {
        std::cout << "Peeking at an empty stack" << std::endl;
        return '\0';
    }

    return top->getData();
}
void LinkedStack::display()
{
    if (isEmpty()) {
        std::cout << "Empty Stack" << std::endl;
        return;
    }
    Node* temp = getTop();
    std::cout << "Current Stack: ";
    while (temp) {
        std::cout << temp->getData();
        temp = temp->getNextNode();
    }
    std::cout << std::endl;
}
class InfixToPostFix {
private:
    LinkedStack operators;
    string infix, postfix;
public:
   
    InfixToPostFix(string i) : infix(i) { }

    void setInfix(string i) {
        infix = i;
        postfix = "";
    }

    bool isOperand(char c); // in this case, digits;
    bool isOperator(char c);
    bool isParenthesis(char c);
    int getPriority(char c); // must be operand;
    string evaluate();
    


};

bool InfixToPostFix::isOperand(char c) {
    return (c <= 57 && c>=48);
}
bool InfixToPostFix::isOperator(char c) {
    return (c == '+' || c == '*' || c == '-' || c == '/' || c == '^');
}
int InfixToPostFix::getPriority(char c) {
    switch (c) {
    case('('): return 0;
    case('+'): return 1;
    case('-'): return 1;
    case('*'): return 2;
    case('/'): return 2;
    case('^'): return 3;
    default: return 0;
    }
}


string InfixToPostFix::evaluate() {
    if (infix == "") return "Nothing to Evaluate";

    for (size_t i = 0; i < infix.size(); i++) {
        std::cout << "Current character ["<<i<<"]: '" << infix[i] << "' Of Phrase : " << infix << std::endl;
        
        if (isOperand(infix[i])) {
            postfix.push_back(infix[i]);
            std::cout << "AFTER ADDING: Current PostFix expression: = " << postfix << std::endl;
            //std::cout << "Solution: 562-9371-^+54-1-^*+95/2/+71/7/-" << std::endl;
            //std::cout << "Solution: 562-9*+371-54-1-^^+95/2/+71/7/-" << std::endl;
            std::cout << "Solution: 33*71+/" << std::endl;
            
        }
        else if (infix[i] == '(') {
            operators.push('(');
            
        }
        else if (infix[i] == ')') {
            while (operators.peek() != '(') {
                postfix.push_back(operators.pop());
                std::cout << "Current PostFix expression: = " << postfix << std::endl;
            }
            operators.pop();
        }
        else if (isOperator(infix[i])) {
            std::cout << "Infix [i] = '" << infix[i] << "' Is priority? " << getPriority(infix[i]) << std::endl;
            operators.display();
            /* std::cout << "Peek Before = " << operators.peek() << std::endl;
             operators.push(infix[i]);
             std::cout << "Peek After = " << operators.peek() << std::endl;*/

            if (operators.isEmpty()) operators.push(infix[i]);
            else {
                int incomingPriority = getPriority(infix[i]);
                char topChar = operators.peek();
                int topPriority = getPriority(topChar);

                if (incomingPriority > topPriority) {
                    operators.push(infix[i]);
                }
                else {
                    while ( !operators.isEmpty() && incomingPriority <= topPriority) { // can be changed to <=
                        postfix.push_back(operators.pop());
                        topChar = operators.peek();
                        topPriority = getPriority(topChar);
                    
                    }
                    operators.push(infix[i]);
                }

                
            }
        }
        
        else std::cout << "Unknown character found: " << infix[i] << std::endl;
        operators.display();
    }
    while (!operators.isEmpty()) {
        char temp = operators.pop();
        if(temp != '\0') postfix.push_back(temp);
        operators.display();
        std::cout << "Current PostFix expression: = " << postfix << std::endl;
    }
    return postfix;
}

string to_postfix(std::string infix) {

    InfixToPostFix converter(infix);
    string postFix = converter.evaluate();
    std::cout << "Attempt:          " << postFix<<std::endl;
    return postFix;
}

int main() {

    std::string answer = "";


    //answer = to_postfix("5+(6-2)*(9+3^(7-1))^(5-4-1)+9/5/2-7/1/7"); // Equals("562-9371-^+54-1-^*+95/2/+71/7/-"))
   // answer = to_postfix("5+(6-2)*9+3^(7-1)^(5-4-1)+9/5/2-7/1/7"); // Equals("562-9*+371-54-1-^^+95/2/+71/7/-"))
    
    answer = to_postfix("3*3/(7+1)"); // Equals("33*71+/"));
    std::cout << "Current Solution: 33*71+/" << std::endl;
    answer = to_postfix("2+7*5"); // Equals("275*+"));
    std::cout << "Current Solution: 275*+" << std::endl;
    
    answer = to_postfix("1+(2/(3-(4*(5^(3-1)))))+2"); // Equals("1234531-^*-/+2+"));
    std::cout << "Current Solution: 1234531-^*-/+2+" << std::endl;
    answer = to_postfix("(2+7)*5"); // Equals("27+5*"));
    std::cout << "Current Solution: 27+5*" << std::endl;
    answer = to_postfix("2+7*5"); // Equals("275*+"));
    std::cout << "Current Solution: 275*+" << std::endl;
    
    answer = to_postfix("5+(6-2)*9+3^(7-1)"); // Equals("562-9*+371-^+"));
    std::cout << "Current Solution: 562-9*+371-^+" << std::endl;
    answer = to_postfix("(5-4-1)+9/5/2-7/1/7"); // Equals("54-1-95/2/+71/7/-"));
    std::cout << "Current Solution: 54-1-95/2/+71/7/-" << std::endl;

}





























//#include <string>
//using std::string;
//struct Node {
//    
//private:
//    char data;
//    Node* next;
//
//public:
//    Node() {
//        next = nullptr;
//        data = '\0';
//    }
//    Node(char c) {
//        next = nullptr;
//        data = c;
//    }  //only digits 0-9;
//    void setData(char d) {
//        data = d;
//    }
//    void setNextNode(Node** n) {
//        this->next = *n;
//    }
//    char getData() {
//        return data;
//    }
//    Node* getNextNode() {
//        return next;
//    }
//};
//
//class LinkedStack {
//private:
//    Node* top;
//public:
//    LinkedStack() {
//        top = nullptr;
//    }
//
//    bool isEmpty(Node* root) {
//        bool temp = (top == nullptr);
//        return temp;
//        //return top == nullptr;
//    }
//    void push(char c);
//    Node* pop();
//    char peek();
//    void print();
//};
//
//void LinkedStack::push(char c){
//    Node node(c);
//    Node* n = &node;
//    if(!isEmpty(top)) n->setNextNode(top->getNextNode());
//    top->setNextNode(n);
//    bool poo = true;
//}
//Node* LinkedStack::pop() {
//    if (this->isEmpty(top)) return nullptr;
//    return top->getNextNode();
//}
//char LinkedStack::peek(){
//    if (this->isEmpty(top)) return '\0';
//    Node* n = top->getNextNode();
//    return n->getData();
//}
//void LinkedStack::print(){
//}
//
//class InfixToPostFix {
//private:
//    LinkedStack operators;
//    string infix, postfix;
//public:
//    InfixToPostFix() { infix = ""; postfix = ""; }
//    InfixToPostFix(string i) : infix(i) { postfix = ""; }
//
//    void setInfix(string i) {
//        infix = i;
//        postfix = "";
//    }
//    bool isOperand(char c); // in this case, digits;
//    bool isOperator(char c);
//    bool isParenthesis(char c);
//    int getPriority(char c); // must be operand;
//    string evaluate(); 
//    
//
//};
//
//bool InfixToPostFix::isOperand(char c) {
//    return true;
//}
//bool InfixToPostFix::isOperator(char c) {
//    return true;
//}
//bool InfixToPostFix::isParenthesis(char c) {
//    return true;
//}
//int InfixToPostFix::getPriority(char c) {
//    return 0;
//}
//
//string InfixToPostFix::evaluate() {
//    if (infix == "") return "Nothing to Evaluate";
//
//    for (size_t i = 0; i < infix.size(); i++) {
//        Node* stackNode = newNode(infix[i]);
//        
//        operators.push(infix[i]);
//    }
//
//}
//
//string to_postfix(std::string infix) {
//    
//    InfixToPostFix converter(infix);
//    string postFix = converter.evaluate();
//    return postFix;
//}
//
//
//int main() {
//
//    std::string answer = "";
//
//    answer = to_postfix("2+7*5"); // Equals("275*+"));
//    answer = to_postfix("3*3/(7+1)"); // Equals("33*71+/"));
//    answer = to_postfix("5+(6-2)*9+3^(7-1)"); // Equals("562-9*+371-^+"));
//    answer = to_postfix("(5-4-1)+9/5/2-7/1/7"); // Equals("54-1-95/2/+71/7/-"));
//
//}