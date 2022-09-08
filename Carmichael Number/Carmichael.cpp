long long Carmichael(long long n)
{

    return 0;
}

int main() {
        
    long long answer;

        answer = Carmichael(1);// Equals(1));
        answer = Carmichael(9);// Equals(6));
        answer = Carmichael(8);// Equals(2));
  
        answer = Carmichael(983);// Equals(982));
        answer = Carmichael(1601);// Equals(1600));
        answer = Carmichael(65535);// Equals(256));
   
        answer = Carmichael(10000001);// Equals(909090));
        answer = Carmichael(9999999983);// Equals(714057792));
   
        answer = Carmichael(0);// Equals(0));
        answer = Carmichael(-1);// Equals(0));
    
        return 0;
    }
