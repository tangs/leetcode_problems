#!/usr/bin/env bash

name=$1
srcPath="../src/$name"
testPath="../tests/$name"

hppPath="$srcPath/solution.hpp"
testFilePath="$testPath/test.cc"
cmakeFilePath="$testPath/CMakeLists.txt"

[ -d "$srcPath" ] && echo "directory $srcPath exists." && exit 0
echo "name: ${name}, src path: ${srcPath}, hpp path: ${hppPath}"
echo "test file path: ${testFilePath}, cmake file path: ${cmakeFilePath}"

mkdir -p "$srcPath"
mkdir -p "$testPath"

touch "$srcPath/solution.hpp"

cd "$testPath" || (echo "enter $testPath fail." && exit 2)
cp -rf ../template/test.cc.tmp test.cc
cp -rf ../template/CMakeLists.txt.tmp CMakeLists.txt
sed -i "" "s/problem_name/$name/g" CMakeLists.txt
echo "add_subdirectory($name)" >> ../CMakeLists.txt
cd - || exit 3
