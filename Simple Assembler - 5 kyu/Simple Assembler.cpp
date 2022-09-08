#include <string>
#include <unordered_map>

static int& getReg(std::unordered_map<std::string, int>& regs, std::string name)
{

}

std::unordered_map<std::string, int> assembler(const std::vector<std::string>& program)
{
	// your code here
}


#include <string>
#include <unordered_map>

int main(){
        std::vector<std::string> program{ "mov a 5", "inc a", "dec a", "dec a",
          "jnz a -1", "inc a" };
        //std::unordered_map<std::string, int> out{ { "a", 1 } };
        assembler(program); // , Equals(out));
        return 0;
}
