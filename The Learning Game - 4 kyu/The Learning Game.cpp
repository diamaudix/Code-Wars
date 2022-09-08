class Machine {
public:
    unsigned int command(unsigned int cmd, unsigned int num);
    void response(bool res);
};

// TODO: Replace examples and use TDD development by writing your own tests

int main() {

    Machine machine;

    unsigned int cmd_to_learn = 78;
    unsigned int action_associated_to_cmd = 3;
    
    for (unsigned int i = 0; i < 20; ++i) {
        unsigned int result = machine.command(cmd_to_learn, i); // i is not random for simplicity
        machine.response(result == get_action(action_associated_to_cmd)(i));
    }

    unsigned int final_test_number = 56;
    machine.command(cmd_to_learn, final_test_number);// , Equals(get_action(action_associated_to_cmd)(final_test_number)));

    // one more example
    cmd_to_learn = 235;
    action_associated_to_cmd = 0;

    for (unsigned int i = 0; i < 20; ++i) {
        unsigned int result = machine.command(cmd_to_learn, i); // i is not random for simplicity
        machine.response(result == get_action(action_associated_to_cmd)(i));
    }

    final_test_number = 73;
    unsigned int finalResult = machine.command(cmd_to_learn, final_test_number); // , Equals(get_action(action_associated_to_cmd)(final_test_number)));
    return 0;
}