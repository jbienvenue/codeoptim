SRC = $(wildcard *.cpp)
BASE = $(SRC:.cpp=)
PERF = $(addsuffix .perf,$(BASE))
ALL = $(addsuffix .perfs,$(BASE))

.PRECIOUS: %.exe %.exe0 %.exe3 %.perf %.perf0 %.perf3

all: $(ALL)


perf: $(PERF)

force:

#%.perfs: $(patsubst x%, $($@:.perfs=)%,x.perf0 x.perf3 x.perf)
%.perfs: %.perf0 %.perf3 %.perf
	@echo ""

%.perf3: %.exe3 force
	./$< $(@getconf LEVEL3_CACHE_SIZE) > $@
	@echo "Perf for $*"
	@cat $@

%.exe3: %.cpp
	gcc -O3 $< -o $@ -lstdc++

%.perf0: %.exe0 force
	./$< $(@getconf LEVEL3_CACHE_SIZE) > $@
	@echo "Perf for $*"
	@cat $@

%.exe0: %.cpp
	gcc -O0 $< -o $@ -lstdc++

%.perf: %.exe force
	./$< $(@getconf LEVEL3_CACHE_SIZE) > $@
	@echo "Perf for $*"
	@cat $@

%.exe: %.cpp
	@bash compile.sh $< $@

