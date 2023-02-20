
#include <string>

namespace someNamespace {
    class TestClass {
    public:
        // constructor
        TestClass();
        // destructor
        ~TestClass();

        std::string someFunctionReturningString();

    private:
        bool somePrivateMember;
    };

}