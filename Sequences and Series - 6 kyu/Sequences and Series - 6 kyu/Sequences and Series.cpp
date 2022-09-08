int getScore(int n) {
    return (((n * (n + 1)) / 2) * 50);
}

int main() {

    getScore(1);//, Equals(50));
    getScore(2);// , Equals(150));
    getScore(3);// , Equals(300));
    return 0;
}