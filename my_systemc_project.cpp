#include <systemc.h>

SC_MODULE(HelloWorld) {
    SC_CTOR(HelloWorld) {
        SC_THREAD(say_hello);
    }

    void say_hello() {
        cout << "Hello, SystemC!" << endl;
    }
};

int sc_main(int argc, char* argv[]) {
    HelloWorld hello("HELLO");
    sc_start();
    return 0;
}
