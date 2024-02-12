SRC = $(wildcard *.cpp)
PERF = $(SRC:.cpp=.perf)

.PRECIOUS: %.exe .perf

all:
	@make $(PERF)

force:

%.perf: %.exe force
	./$< > $@
	@echo "Perf for $*"
	@cat $@

%.exe: %.cpp
	gcc -O3 $< -o $@ -lstdc++


%.perf0: %.exe0 force
	./$< > $@
	@echo "Perf for $*"
	@cat $@

%.exe0: %.cpp
	gcc -O0 $< -o $@ -lstdc++

