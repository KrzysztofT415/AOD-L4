all: clean edmonds

edmonds:
	g++ -O3 -Wall -Wextra -std=c++17 -pedantic ./app/edmonds.cpp ./src/*.cpp -I./lib -I./inc -o edmonds

clean:
	rm -f edmonds test

test:
	g++ -O3 -Wall -Wextra -std=c++17 -pedantic ./app/test.cpp ./src/*.cpp -I./lib -I./inc -o test
	./test

bash:
	bash script.sh