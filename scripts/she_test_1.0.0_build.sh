#!/bin/bash
project="she_ini"
project_length=${#project}
# Get pwd string
path=$(pwd)
# Get last project_length chars
suffix="${path: -$project_length}"
if [ "$suffix" = "$project" ]; then
    echo "ok"
else
    echo "Path error.Please ensure that the last few strings after using pwd are "$project
    exit 1  # stop
fi

# Check dir third_party
echo "Check third_party exist?"
if [ -d "./third_party" ];
then
    echo "third_party."
else
    echo "Create third_party."
    mkdir third_party
fi

# get source code
git clone https://github.com/shecannotsee/she_test.git ./third_party/she_test/

cd third_party
mv she_test she_test-src
mkdir she_test
cd she_test
install_path=$(pwd)
cd ..

# build
cd she_test-src
git checkout 1.0.0 || \
  { echo "git checkout failed."; exit 1; }
mkdir build
cd build
cmake -DCMAKE_INSTALL_PREFIX="$install_path" \
  -Dbuild_release=ON \
  -Dbuild_tests=OFF \
  -Dbuild_shared_libs=ON \
  .. || \
  { echo "cmake failed."; exit 1; }
make -j8 || \
  { echo "Build failed."; exit 1; }
make install || \
  { echo "Install failed."; exit 1; }
