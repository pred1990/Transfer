echo Starting to build...

if [ ! -d "build/" ]; then
  mkdir build/
fi
clang++  Main.cpp -o build/Transfer
chmod 755 build/Transfer

echo ... build finished!
