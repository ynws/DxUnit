cd /var/jenkins_home/workspace/DxUnit/
mkdir build
cd build

export GTEST=/usr/src/googletest-release-1.8.0
export GTLIB=${GTEST}/build/gtest
export GMLIB=${GTEST}/build/googlemock

echo "################################################################################"
echo "## build lib"
echo "################################################################################"
g++ -std=c++11 -O2 -fno-exceptions -W -Wall -c ../MainLib/*.cpp \
    -DLINUX -fprofile-arcs -ftest-coverage
ar r libstatic.a *.o

echo "################################################################################"
echo "## build test"
echo "################################################################################"
g++ -std=c++11 -O2 -fno-exceptions -W -Wall ../UnitTest/*.cpp \
    -DLINUX -fprofile-arcs -ftest-coverage -I../MainLib libstatic.a \
    -I${GTEST}/googletest/include ${GMLIB}/gtest/libgtest.a ${GMLIB}/gtest/libgtest_main.a \
    -lpthread -o test

echo "################################################################################"
echo "## test"
echo "################################################################################"
./test --gtest_output=xml:testresult.xml
gcovr -r ~/workspace/DxUnit/MainLib --xml --output=Coverage.xml .