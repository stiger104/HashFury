#include "../googletest/include/gtest/gtest.h"
#include "hashblock.h"

#define BEGIN(a)            ((char*)&(a))
#define END(a)              ((char*)&((&(a))[1]))
using namespace std;

string xHash(uint256 n)
{
    cout << "Check X11 Hash: \n";
    uint256 res = HashX11(BEGIN(n), END(n));
    return res.GetHex();
}

TEST(test1, x11){
    EXPECT_EQ("f2c01298a651a1bf9e736738c6cd9b493e04c52507510cbed0640d7b0c6e8428", xHash(100));
}

GTEST_API_ int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}