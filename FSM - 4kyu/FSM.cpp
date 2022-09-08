#include <string>
#include <vector>

std::string traverse_TCP_states(const std::vector<std::string>& events) {
    
    std::string currentState = "CLOSED";

    for (auto i : events) {
        if (i == "APP_PASSIVE_OPEN") {
            if (currentState == "CLOSED")currentState = "LISTEN";
            else return "ERROR";
        }
        else if (i == "APP_ACTIVE_OPEN") {
            if (currentState == "CLOSED") currentState = "SYN_SENT";
            else return "ERROR";
        }
        else if (i == "RCV_SYN") {
            if (currentState == "LISTEN") currentState = "SYN_RCVD";
            else if (currentState == "SYN_SENT") currentState = "SYN_RCVD";
            else return "ERROR";
        }
        else if (i == "APP_SEND") {
            if (currentState == "LISTEN") currentState = "SYN_SENT";
            else return "ERROR";
        }
        else if (i == "APP_CLOSE") {
            if (currentState == "LISTEN") currentState = "CLOSED";
            else if (currentState == "SYN_RCVD") currentState = "FIN_WAIT_1";
            else if (currentState == "SYN_SENT") currentState = "CLOSED";
            else if (currentState == "ESTABLISHED") currentState = "FIN_WAIT_1";
            else if (currentState == "CLOSE_WAIT") currentState = "LAST_ACK";
            else return "ERROR";
        }
        else if (i == "RCV_ACK") {
            if (currentState == "SYN_RCVD") currentState = "ESTABLISHED";
            else if (currentState == "FIN_WAIT_1") currentState = "FIN_WAIT_2";
            else if (currentState == "CLOSING") currentState = "TIME_WAIT";
            else if (currentState == "LAST_ACK") currentState = "CLOSED";
            else return "ERROR";
        }
        else if (i == "RCV_SYN") {
            if (currentState == "LISTEN") currentState = "SYN_RCVD";
            if (currentState == "SYN_SENT") currentState = "SYN_RCVD";
            else return "ERROR";
        }
        else if (i == "RCV_SYN_ACK") {
            if (currentState == "SYN_SENT") currentState = "ESTABLISHED";
            else return "ERROR";
        }
        else if (i == "RCV_FIN") {
            if (currentState == "ESTABLISHED") currentState = "CLOSE_WAIT";
            else if (currentState == "FIN_WAIT_1") currentState = "CLOSING";
            else if (currentState == "FIN_WAIT_2") currentState = "TIME_WAIT";
            else return "ERROR";
        }
        else if (i == "RCV_FIN_ACK") {
            if (currentState == "FIN_WAIT_1") currentState = "TIME_WAIT";
            else return "ERROR";
        }
        else if (i == "APP_TIMEOUT") {
            if (currentState == "TIME_WAIT") currentState = "CLOSED";
            else return "ERROR";
        }
        else return "ERROR";        
    }
    return currentState;
}




int main(){
        using vs = std::vector<std::string>;

        vs test1 = { "APP_ACTIVE_OPEN","RCV_SYN_ACK","RCV_FIN" };
        vs test2 = { "APP_PASSIVE_OPEN",  "RCV_SYN","RCV_ACK" };
        vs test3 = { "APP_ACTIVE_OPEN","RCV_SYN_ACK","RCV_FIN","APP_CLOSE" };
        vs test4 = { "APP_ACTIVE_OPEN" };
        vs test5 = { "APP_PASSIVE_OPEN","RCV_SYN","RCV_ACK","APP_CLOSE","APP_SEND" };

        traverse_TCP_states(test1);//quals("CLOSE_WAIT"));
        traverse_TCP_states(test2);// Equals("ESTABLISHED"));
        traverse_TCP_states(test3);// Equals("LAST_ACK"));
        traverse_TCP_states(test4);// Equals("SYN_SENT"));
        traverse_TCP_states(test5);// Equals("ERROR"));
}
