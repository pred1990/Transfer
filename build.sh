echo \#\#\# Starting to build...

if [ ! -d "build/" ]; then
  mkdir build/
fi
clang++ Main.cpp Validate.cpp Util.cpp NetworkLnx.cpp -o build/Transfer -std=c++11 -pedantic -Wall
chmod 755 build/Transfer

echo \#\#\# ...build finished!
