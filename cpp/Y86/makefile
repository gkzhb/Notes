cc = g++
prom = Y86.out
deps = $(shell find ./ -name "*.h")
src = $(shell find ./ -name "*.cpp")
obj = $(src:%.cpp=%.o)

$(prom): $(obj)
	$(cc) -o $(prom) $(obj) -g -pthread

%.o: %.cpp $(deps)
	$(cc) -c $< -o $@ -g -pthread

clean:
	rm -rf $(obj) $(prom)
