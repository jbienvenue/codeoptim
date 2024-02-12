SRC = $(wildcard *.cpp)
PERF = $(SRC:.cpp=.perf)

.PRECIOUS: .exe .perf

all:
	$(PERF)

force:

%.perf: %.exe force
	./$< > $@
	@echo "Perf for $*"
	@cat $@

%.exe: %.cpp
	gcc -O3 $< -o $@ -lstdc++

